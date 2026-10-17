#!/usr/bin/env python3
"""Exercise actual interrupt dispatch with recorded healthy/failed reconnects.

Hardware routines are stubs: this checks branch selection, not hardware recovery.
The live source is read only. Exit 1 means the recorded regression remains.
"""
import argparse
from pathlib import Path
import re
import subprocess
import tempfile

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--source-root', type=Path,
                    default=Path(__file__).resolve().parents[1])
args = parser.parse_args()
source = (args.source_root / 'patch_cirrus/patch_cirrus_real84.h').read_text()
def function(name):
    marker = name + '(struct hda_codec *codec'
    match = re.search(r'^static (?:void|int) ' + re.escape(marker) + r'[^;]*?\n\{', source, re.M)
    if not match:
        raise RuntimeError('Definition missing: ' + name)
    pos, depth = match.end(), 1
    while depth:
        depth += (source[pos] == '{') - (source[pos] == '}')
        pos += 1
    return source[match.start():pos]

dispatch = function('cs_8409_interrupt_action')
collector = function('cs_8409_read_status_and_clear_interrupt')
defines = '\n'.join(re.findall(r'^#define (?:TIP_SENSE_\w+|BUTTON\w*|HSDET_AUTO_DONE|PDN_DONE|MIKE_CONNECT) .*$', source, re.M))
code = r'''
#include <stdio.h>
#include <string.h>
#include "patch_cirrus_earpods.h"
enum path { NONE, PLUG, UNPLUG, TYPE, DETECT };
struct cs8409_apple_spec { int have_mike, jack_present, have_buttons, headset_phase; unsigned int earpods_held; };
struct hda_codec { struct cs8409_apple_spec *spec; };
static enum path chosen;
static int sense, marks, continues, reports, media;
static const int *samples;
static unsigned int sample_index, sample_count;
static int stuck;
static int read_gpio_status_check(struct hda_codec *c) {
    (void)c; return stuck || sample_index < sample_count ? 0 : 1;
}
static int cs42l83_read_status_and_clear_interrupt(struct hda_codec *c) {
    (void)c;
    unsigned int i = sample_index++;
    return i < sample_count ? samples[i] : 0;
}
#define mycodec_info(...) ((void)0)
#define codec_info(...) ((void)0)
#define msleep(...) ((void)0)
#define dev_info(...) ((void)0)
#define hda_codec_dev(c) (c)
static int cs42l83_headphone_sense(struct hda_codec *c) { (void)c; return sense; }
static void cs_8409_headset_button_event(struct hda_codec *c, int status) {
    struct cs8409_apple_spec *s = c->spec;
    media += !!earpods_decode(&s->earpods_held, status,
        s->jack_present == 1 && s->have_buttons && s->headset_phase >= 2);
}
static void cs_8409_headset_plugin_event(struct hda_codec *c) { (void)c; chosen = PLUG; }
static void cs_8409_headset_unplug_event(struct hda_codec *c) { (void)c; chosen = UNPLUG; }
static void cs_8409_headset_type_detect_event(struct hda_codec *c) { (void)c; chosen = TYPE; }
static void cs_8409_headset_button_detect_event(struct hda_codec *c) { (void)c; chosen = DETECT; }
static void cs_8409_cs42l83_mark_jack(struct hda_codec *c) { (void)c; ++marks; }
static void cs_8409_plugin_event_continued(struct hda_codec *c) { (void)c; ++continues; }
static void cs_8409_cs42l83_jack_report_sync(struct hda_codec *c) { (void)c; ++reports; }
'''
code += '\n' + defines + '\n' + collector + '\n' + dispatch + '\n'
code += r'''
int main(void) {
    struct cs8409_apple_spec initial = {0};
    struct hda_codec collector_codec = { &initial };
    const int healthy[] = {0x140a00};
    const int failed_sequence[] = {0xfe0200, 0x140800, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    samples = healthy; sample_index = 0; sample_count = 1; stuck = 0;
    unsigned int normal = cs_8409_read_status_and_clear_interrupt(&collector_codec);
    samples = failed_sequence; sample_index = 0; sample_count = 12; stuck = 1;
    unsigned int failure = cs_8409_read_status_and_clear_interrupt(&collector_codec);
    if (normal != 0x140a00 || failure != 0xfe0a00) {
        fprintf(stderr, "Collector no longer matches recorded raw sequences\n");
        return 2;
    }
    printf("PASS: actual collector preserves both recorded raw sequences\n");
    normal &= ~0xc0e703U;
    failure &= ~0xc0e703U;
    struct test { const char *name; unsigned int status; int sense; enum path want; };
    const struct test tests[] = {
        { "normal plug", 0x400000, 0x7796, PLUG },
        { "real unplug", 0x200000, 0x7716, UNPLUG },
        { "headset type", 0x2, 0x7796, TYPE },
        { "recorded healthy detection", normal, 0x7796, DETECT },
        { "recorded failed detection, still plugged", failure, 0x7796, DETECT },
        { "mixed removal, physically unplugged", failure, 0x7716, UNPLUG },
        { "presence read failed", failure, -1, UNPLUG },
        { "wrong I2C register echo", failure, 0x0196, UNPLUG },
        { "missing I2C register echo", failure, 0x96, UNPLUG },
    };
    int failed = 0;
    for (unsigned int i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i) {
        struct cs8409_apple_spec spec = { .have_mike = 1, .jack_present = 1,
            .have_buttons = 1, .headset_phase = 3 };
        struct hda_codec codec = { &spec };
        chosen = NONE; marks = continues = reports = media = 0;
        sense = tests[i].sense;
        cs_8409_interrupt_action(&codec, tests[i].status);
        int ok = chosen == tests[i].want && media == 0;
        if (tests[i].want == DETECT)
            ok &= marks == 1 && continues == 1 && reports == 1;
        printf("%s: %s (selected=%d expected=%d media=%d)\n",
               ok ? "PASS" : "FAIL", tests[i].name, chosen, tests[i].want, media);
        failed += !ok;
    }
    return failed ? 1 : 0;
}
'''
with tempfile.TemporaryDirectory(prefix='aud01-reconnect-') as directory:
    root = Path(directory)
    (root / 'replay.c').write_text(code)
    binary = root / 'replay'
    subprocess.run(['gcc', '-std=c11', '-Wall', '-Wextra',
                    '-Wno-unused-function', '-Wno-unused-variable',
                    '-Wno-unused-but-set-variable',
                    '-I' + str(args.source_root / 'patch_cirrus'),
                    str(root / 'replay.c'), '-o', str(binary)], check=True)
    raise SystemExit(subprocess.run([str(binary)]).returncode)
