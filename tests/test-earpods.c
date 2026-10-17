#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <linux/input-event-codes.h>
#include "patch_cirrus_earpods.h"
#define SND_JACK_BTN_0 0x4000
#define SND_JACK_BTN_1 0x2000
#define SND_JACK_BTN_2 0x1000
#define myprintk(...) ((void)0)
struct snd_jack { int live; unsigned int input_state;
    void *private_data; void (*private_free)(struct snd_jack *); } endpoint;
struct cs8409_apple_spec {
    struct snd_jack *earpods_jack;
    unsigned int earpods_held;
    int jack_present, have_buttons, headset_phase;
};
struct hda_codec { struct cs8409_apple_spec *spec; void *card; };
static unsigned int actions, reports, keycalls, failkey, allocfail, frees, generic_frees;
static unsigned int reported[4096], keys[3];
static int snd_jack_new(void *card, const char *name, int bits, struct snd_jack **out, bool ctl, bool phantom)
{
    (void)card;
    assert(!__builtin_strcmp(name, "EarPods Remote"));
    assert(bits == (SND_JACK_BTN_0|SND_JACK_BTN_1|SND_JACK_BTN_2));
    assert(!ctl && !phantom);
    if (allocfail) return -12;
    endpoint.live=1; endpoint.input_state=0; *out=&endpoint; return 0;
}
static int snd_jack_set_key(struct snd_jack *jack, int bit, int key)
{
    assert(jack->live); assert(keycalls<3);
    assert(bit == (SND_JACK_BTN_0 >> keycalls));
    keys[keycalls++]=(unsigned int)key;
    return keycalls == failkey ? -22 : 0;
}
static void snd_jack_report(struct snd_jack *jack, unsigned int mask)
{
    assert(jack && jack->live);
    assert(reports < sizeof(reported)/sizeof(*reported));
    if(mask) { assert(jack->input_state==0); actions++; }
    jack->input_state=mask; reported[reports++]=mask;
}
static void snd_device_free(void *card, struct snd_jack *jack)
{ (void)card; assert(jack->live); assert(!jack->input_state); if (jack->private_free) jack->private_free(jack); jack->live=0; frees++; }
static void snd_hda_gen_free(struct hda_codec *codec)
{ codec->spec=NULL; generic_frees++; }
#include "driver_under_test.h"
#include "recordings.h"

static struct cs8409_apple_spec state;
static struct hda_codec codec;
static void fresh(void)
{
    state=(struct cs8409_apple_spec){.jack_present=1,.have_buttons=1,.headset_phase=3};
    codec=(struct hda_codec){.spec=&state};
    endpoint=(struct snd_jack){0};
    actions=reports=keycalls=failkey=allocfail=frees=generic_frees=0;
    assert(cs_8409_earpods_create(&codec)==0);
    assert(keys[0]==KEY_VOLUMEUP && keys[1]==KEY_VOLUMEDOWN && keys[2]==KEY_PLAYPAUSE);
    assert(cs_8409_earpods_create(&codec)==0 && keycalls==3);
    reports=0;
}
static void event(unsigned int mask)
{
    unsigned int before=reports;
    cs_8409_headset_button_event(&codec,(int)mask);
    assert(endpoint.input_state==0); /* checked after every physical event */
    if(reports!=before) {
        assert(reports==before+2);
        assert(reported[before] && !reported[before+1]);
    }
}
static void recording(const unsigned int *seq, unsigned int report)
{
    fresh();
    for(unsigned int i=0;i<6;i++) event(seq[i]);
    assert(actions==3 && reports==6 && state.earpods_held==0);
    for(unsigned int i=0;i<6;i+=2) assert(reported[i]==report && reported[i+1]==0);
}
int main(void)
{
    const unsigned int down[]={0x20000,0x10000,0x100};
    const unsigned int up[]={0x100000,0x100000,0x200};
    recording(volume_plus,SND_JACK_BTN_0);
    recording(volume_minus,SND_JACK_BTN_1);
    recording(center,SND_JACK_BTN_2);
    puts("PASS: all nine labeled recorded presses, direction/key mapping and paired releases");
    for(unsigned int b=0;b<3;b++) {
        fresh(); event(down[b]);
        for(unsigned int i=0;i<10000;i++) event(down[b]);
        assert(actions==1); event(up[b]); event(up[b]); assert(state.earpods_held==0);
        for(unsigned int i=0;i<100;i++) {event(down[b]);event(up[b]);}
        assert(actions==101 && !state.earpods_held);
        fresh(); event(down[b]); event(b==2 ? 0x100000 : 0x200); event(down[b]);
        assert(actions==1); event(up[b]); event(down[b]); assert(actions==2);
        fresh(); event(down[b]); event(0x80000000); event(down[b]); assert(actions==1);
        /* Ambiguous/detection/power notifications cannot re-arm a hold. */
        const unsigned int during[]={0x800,0x1000,0x2,0x1,0x30000,0x100100};
        for(unsigned int i=0;i<sizeof(during)/sizeof(*during);i++) {
            fresh();event(down[b]);event(during[i]);event(down[b]);assert(actions==1);
            event(up[b]);event(down[b]);assert(actions==2);
        }
    }
    puts("PASS: single/held/duplicate presses, wrong and duplicate releases, rapid taps, no repeat or stuck input");
    const unsigned int bad[]={0,0x80000000,0x30000,0x100100,0x120000,0x80020000,0x1100,0x140800,0x600000};
    for(unsigned int i=0;i<sizeof(bad)/sizeof(*bad);i++) {
        fresh(); event(bad[i]); assert(!actions);
    }
    fresh();event(0x30000);event(0x20000);assert(!actions);event(0x100000);event(0x20000);assert(actions==1);
    fresh(); event(0x20000);event(0x100);event(0x20000);assert(actions==1);
    event(0x200);event(0x100);assert(actions==2);
    puts("PASS: unknown masks, coalesced/ambiguous signals, detection and conflicting buttons");
    for(unsigned int b=0;b<3;b++) {
        fresh();event(down[b]);event(0x200000);assert(!state.earpods_held && actions==1);
        state.jack_present=0;event(down[b]);assert(actions==1);
        state.jack_present=1;event(0x400000);event(down[b]);assert(actions==2);
        assert(cs_8409_apple_suspend(&codec)==0 && !state.earpods_held && !endpoint.input_state);
        cs_8409_apple_free(&codec); assert(!endpoint.live && !codec.spec && frees==1 && generic_frees==1);
    }
    /* Simulate ALSA card-wide order: jack freed before codec/spec. */
    fresh();event(0x20000);snd_device_free(codec.card,state.earpods_jack);
    assert(!state.earpods_jack && !state.earpods_held && !endpoint.live);
    event(0x20000);assert(actions==1);
    cs_8409_apple_free(&codec);assert(!codec.spec && frees==1 && generic_frees==1);
    fresh();state.headset_phase=0;event(0x20000);assert(!actions);
    state.headset_phase=3;state.have_buttons=0;event(0x100);assert(!actions);
    state.have_buttons=1;state.jack_present=2;event(0x10000);assert(!actions);
    state.jack_present=1;state.earpods_jack=NULL;event(0x10000);assert(!actions);
    puts("PASS: unplug-during-press, reconnect, suspend, both teardown orders, initialization and readiness guards");
    for(unsigned int failure=0;failure<4;failure++) {
        fresh();cs_8409_apple_free(&codec);
        state=(struct cs8409_apple_spec){0};codec.spec=&state;
        keycalls=0;frees=0;allocfail=failure==0;failkey=failure;
        assert(cs_8409_earpods_create(&codec)<0);
        assert(!state.earpods_jack && !endpoint.live && frees==(failure!=0));
    }
    puts("PASS: endpoint allocation and each key-registration failure clean up safely");
    return 0;
}
