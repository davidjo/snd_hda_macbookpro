
static void setup_reset_and_clear_ssm3(struct hda_codec *codec)
{

        // so now really dont know why I skipped all this - maybe because they
        // almost entirely reads??
        // - except it does clear all the pin configs
        // plus does a DBL init

        int retval;


        dev_info(hda_codec_dev(codec), "command nid start setup_node_alpha_reset_and_clear\n");

        retval = snd_hda_codec_read_check(codec, 0x00, 0, AC_VERB_PARAMETERS, 0x00000000, 0x10138409, 1); // 0x000f0000
        retval = snd_hda_codec_read_check(codec, 0x00, 0, AC_VERB_PARAMETERS, 0x00000002, 0x00100100, 2); // 0x000f0002
        retval = snd_hda_codec_read_check(codec, 0x00, 0, AC_VERB_PARAMETERS, 0x00000000, 0x10138409, 3); // 0x000f0000
        retval = snd_hda_codec_read_check(codec, 0x00, 0, AC_VERB_PARAMETERS, 0x00000002, 0x00100100, 4); // 0x000f0002
        retval = snd_hda_codec_read_check(codec, 0x00, 0, AC_VERB_PARAMETERS, 0x00000004, 0x00010001, 5); // 0x000f0004

        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_PARAMETERS, 0x00000004, 0x00020046, 6); // 0x001f0004
        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000101, 7); // 0x001f0005
        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_SUBSYSTEM_ID, 0x00000000, 0x106b3300, 8); // 0x001f2000

        retval = snd_hda_codec_read_check(codec, 0x00, 0, AC_VERB_PARAMETERS, 0x00000000, 0x10138409, 9); // 0x000f0000
        retval = snd_hda_codec_read_check(codec, 0x00, 0, AC_VERB_PARAMETERS, 0x00000002, 0x00100100, 10); // 0x000f0002

        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_PARAMETERS, 0x0000000f, 0xe0000019, 11); // 0x001f000f

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_DBL_CODEC_RESET, 0x00000000); // 0x001fff00
        snd_hda_double_reset(codec);

        retval = snd_hda_codec_read_check(codec, 0x00, 0, AC_VERB_PARAMETERS, 0x00000000, 0x10138409, 13); // 0x000f0000
        retval = snd_hda_codec_read_check(codec, 0x00, 0, AC_VERB_PARAMETERS, 0x00000002, 0x00100100, 14); // 0x000f0002

        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000101, 15); // 0x001f0005
        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_PARAMETERS, 0x0000000f, 0xe0000019, 16); // 0x001f000f
        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x001a017f, 17); // 0x001f000a
//      snd_hda:     pcm params           1 bits: 16bit 24bit 32bit rates: 8kHz 11.025kHz 16kHz 22.05kHz 32kHz 44.1kHz 48kHz 96kHz
        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000001, 18); // 0x001f000b
//      snd_hda:     stream format params 1 pcm
        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 19); // 0x001f0012
//      snd_hda:     amp capabilities 1 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 20); // 0x001f000d
//      snd_hda:     amp capabilities 1 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_SUBSYSTEM_ID, 0x00000000, 0x106b3300, 22); // 0x001f2000
        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_PARAMETERS, 0x00000008, 0x00010000, 23); // 0x001f0008

        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_GPIO_DIRECTION, 0x00000000, 0x00000000, 24); // 0x001f1700
//      snd_hda:     gpio direction 1 0x00 in in in in in in in in

        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_PARAMETERS, 0x00000011, 0xc0000008, 25); // 0x001f0011
//      snd_hda:     gpio params 1 [('GPIO', 8), ('GPIO_WAKE', 1), ('GPO', 0), ('GPI', 0), ('GPIO_UNSOL', 1)]

}

static void init_read_all_nodes_ssm3(struct hda_codec *codec)
{
        int retval;


        // get node count
        // note that there are 4 so called VirtualWidgets which are indexed after the 0x46 count from
        // the vendor node at 0x47
        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_PARAMETERS, 0x00000004, 0x00020046, 26); // 0x001f0004


        // so apple reads parameters from all nodes
        // but setting pin nodes SET_PIN_WIDGET_CONTROL to 0

        // this appears to be a loop of calls to AppleHDAWidgetCS8409::initForNodeID for each node
        // this calls AppleHDAWidget::initForNodeID(unsigned short, OSObject*, OSObject*)  for each node
        // and specifically deals with the BEEP node

        retval = snd_hda_codec_read_check(codec, 0x02, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 27); // 0x002f0005
        retval = snd_hda_codec_read_check(codec, 0x02, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 28); // 0x002f0009
//      snd_hda:     2 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x02, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 29); // 0x002f000f
        retval = snd_hda_codec_read_check(codec, 0x02, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 30); // 0x002f000a
//      snd_hda:     pcm params           2 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x02, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 31); // 0x002f000b
//      snd_hda:     stream format params 2 
        retval = snd_hda_codec_read_check(codec, 0x02, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 32); // 0x002f0012
//      snd_hda:     amp capabilities 2 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x02, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 33); // 0x002f000d
//      snd_hda:     amp capabilities 2 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x02, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 34); // 0x002f0009
//      snd_hda:     2 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0

        retval = snd_hda_codec_read_check(codec, 0x03, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 36); // 0x003f0005
        retval = snd_hda_codec_read_check(codec, 0x03, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 37); // 0x003f0009
//      snd_hda:     3 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x03, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 38); // 0x003f000f
        retval = snd_hda_codec_read_check(codec, 0x03, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 39); // 0x003f000a
//      snd_hda:     pcm params           3 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x03, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 40); // 0x003f000b
//      snd_hda:     stream format params 3 
        retval = snd_hda_codec_read_check(codec, 0x03, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 41); // 0x003f0012
//      snd_hda:     amp capabilities 3 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x03, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 42); // 0x003f000d
//      snd_hda:     amp capabilities 3 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x03, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 43); // 0x003f0009
//      snd_hda:     3 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0

        retval = snd_hda_codec_read_check(codec, 0x04, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 45); // 0x004f0005
        retval = snd_hda_codec_read_check(codec, 0x04, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 46); // 0x004f0009
//      snd_hda:     4 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x04, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 47); // 0x004f000f
        retval = snd_hda_codec_read_check(codec, 0x04, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 48); // 0x004f000a
//      snd_hda:     pcm params           4 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x04, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 49); // 0x004f000b
//      snd_hda:     stream format params 4 
        retval = snd_hda_codec_read_check(codec, 0x04, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 50); // 0x004f0012
//      snd_hda:     amp capabilities 4 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x04, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 51); // 0x004f000d
//      snd_hda:     amp capabilities 4 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x04, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 52); // 0x004f0009
//      snd_hda:     4 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0

        retval = snd_hda_codec_read_check(codec, 0x05, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 54); // 0x005f0005
        retval = snd_hda_codec_read_check(codec, 0x05, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 55); // 0x005f0009
//      snd_hda:     5 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x05, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 56); // 0x005f000f
        retval = snd_hda_codec_read_check(codec, 0x05, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 57); // 0x005f000a
//      snd_hda:     pcm params           5 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x05, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 58); // 0x005f000b
//      snd_hda:     stream format params 5 
        retval = snd_hda_codec_read_check(codec, 0x05, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 59); // 0x005f0012
//      snd_hda:     amp capabilities 5 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x05, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 60); // 0x005f000d
//      snd_hda:     amp capabilities 5 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x05, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 61); // 0x005f0009
//      snd_hda:     5 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x06, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 63); // 0x006f0005
        retval = snd_hda_codec_read_check(codec, 0x06, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 64); // 0x006f0009
//      snd_hda:     6 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x06, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 65); // 0x006f000f
        retval = snd_hda_codec_read_check(codec, 0x06, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 66); // 0x006f000a
//      snd_hda:     pcm params           6 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x06, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 67); // 0x006f000b
//      snd_hda:     stream format params 6 
        retval = snd_hda_codec_read_check(codec, 0x06, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 68); // 0x006f0012
//      snd_hda:     amp capabilities 6 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x06, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 69); // 0x006f000d
//      snd_hda:     amp capabilities 6 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x06, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 70); // 0x006f0009
//      snd_hda:     6 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x07, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 72); // 0x007f0005
        retval = snd_hda_codec_read_check(codec, 0x07, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 73); // 0x007f0009
//      snd_hda:     7 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x07, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 74); // 0x007f000f
        retval = snd_hda_codec_read_check(codec, 0x07, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 75); // 0x007f000a
//      snd_hda:     pcm params           7 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x07, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 76); // 0x007f000b
//      snd_hda:     stream format params 7 
        retval = snd_hda_codec_read_check(codec, 0x07, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 77); // 0x007f0012
//      snd_hda:     amp capabilities 7 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x07, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 78); // 0x007f000d
//      snd_hda:     amp capabilities 7 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x07, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 79); // 0x007f0009
//      snd_hda:     7 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x08, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 81); // 0x008f0005
        retval = snd_hda_codec_read_check(codec, 0x08, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 82); // 0x008f0009
//      snd_hda:     8 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x08, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 83); // 0x008f000f
        retval = snd_hda_codec_read_check(codec, 0x08, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 84); // 0x008f000a
//      snd_hda:     pcm params           8 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x08, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 85); // 0x008f000b
//      snd_hda:     stream format params 8 
        retval = snd_hda_codec_read_check(codec, 0x08, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 86); // 0x008f0012
//      snd_hda:     amp capabilities 8 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x08, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 87); // 0x008f000d
//      snd_hda:     amp capabilities 8 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x08, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 88); // 0x008f0009
//      snd_hda:     8 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x09, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 90); // 0x009f0005
        retval = snd_hda_codec_read_check(codec, 0x09, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 91); // 0x009f0009
//      snd_hda:     9 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x09, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 92); // 0x009f000f
        retval = snd_hda_codec_read_check(codec, 0x09, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 93); // 0x009f000a
//      snd_hda:     pcm params           9 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x09, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 94); // 0x009f000b
//      snd_hda:     stream format params 9 
        retval = snd_hda_codec_read_check(codec, 0x09, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 95); // 0x009f0012
//      snd_hda:     amp capabilities 9 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x09, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 96); // 0x009f000d
//      snd_hda:     amp capabilities 9 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x09, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 97); // 0x009f0009
//      snd_hda:     9 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x0a, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 99); // 0x00af0005
        retval = snd_hda_codec_read_check(codec, 0x0a, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 100); // 0x00af0009
//      snd_hda:     10 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x0a, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 101); // 0x00af000f
        retval = snd_hda_codec_read_check(codec, 0x0a, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 102); // 0x00af000a
//      snd_hda:     pcm params           10 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x0a, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 103); // 0x00af000b
//      snd_hda:     stream format params 10 
        retval = snd_hda_codec_read_check(codec, 0x0a, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 104); // 0x00af0012
//      snd_hda:     amp capabilities 10 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x0a, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 105); // 0x00af000d
//      snd_hda:     amp capabilities 10 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x0a, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 106); // 0x00af0009
//      snd_hda:     10 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x0b, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 108); // 0x00bf0005
        retval = snd_hda_codec_read_check(codec, 0x0b, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 109); // 0x00bf0009
//      snd_hda:     11 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x0b, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 110); // 0x00bf000f
        retval = snd_hda_codec_read_check(codec, 0x0b, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 111); // 0x00bf000a
//      snd_hda:     pcm params           11 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x0b, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 112); // 0x00bf000b
//      snd_hda:     stream format params 11 
        retval = snd_hda_codec_read_check(codec, 0x0b, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 113); // 0x00bf0012
//      snd_hda:     amp capabilities 11 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x0b, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 114); // 0x00bf000d
//      snd_hda:     amp capabilities 11 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x0b, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 115); // 0x00bf0009
//      snd_hda:     11 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x0c, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 117); // 0x00cf0005
        retval = snd_hda_codec_read_check(codec, 0x0c, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 118); // 0x00cf0009
//      snd_hda:     12 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x0c, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 119); // 0x00cf000f
        retval = snd_hda_codec_read_check(codec, 0x0c, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 120); // 0x00cf000a
//      snd_hda:     pcm params           12 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x0c, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 121); // 0x00cf000b
//      snd_hda:     stream format params 12 
        retval = snd_hda_codec_read_check(codec, 0x0c, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 122); // 0x00cf0012
//      snd_hda:     amp capabilities 12 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x0c, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 123); // 0x00cf000d
//      snd_hda:     amp capabilities 12 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x0c, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 124); // 0x00cf0009
//      snd_hda:     12 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x0d, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 126); // 0x00df0005
        retval = snd_hda_codec_read_check(codec, 0x0d, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 127); // 0x00df0009
//      snd_hda:     13 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x0d, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 128); // 0x00df000f
        retval = snd_hda_codec_read_check(codec, 0x0d, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 129); // 0x00df000a
//      snd_hda:     pcm params           13 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x0d, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 130); // 0x00df000b
//      snd_hda:     stream format params 13 
        retval = snd_hda_codec_read_check(codec, 0x0d, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 131); // 0x00df0012
//      snd_hda:     amp capabilities 13 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x0d, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 132); // 0x00df000d
//      snd_hda:     amp capabilities 13 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x0d, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 133); // 0x00df0009
//      snd_hda:     13 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x0e, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 135); // 0x00ef0005
        retval = snd_hda_codec_read_check(codec, 0x0e, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 136); // 0x00ef0009
//      snd_hda:     14 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x0e, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 137); // 0x00ef000f
        retval = snd_hda_codec_read_check(codec, 0x0e, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 138); // 0x00ef000a
//      snd_hda:     pcm params           14 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x0e, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 139); // 0x00ef000b
//      snd_hda:     stream format params 14 
        retval = snd_hda_codec_read_check(codec, 0x0e, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 140); // 0x00ef0012
//      snd_hda:     amp capabilities 14 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x0e, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 141); // 0x00ef000d
//      snd_hda:     amp capabilities 14 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x0e, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 142); // 0x00ef0009
//      snd_hda:     14 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x0f, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 144); // 0x00ff0005
        retval = snd_hda_codec_read_check(codec, 0x0f, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 145); // 0x00ff0009
//      snd_hda:     15 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x0f, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 146); // 0x00ff000f
        retval = snd_hda_codec_read_check(codec, 0x0f, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 147); // 0x00ff000a
//      snd_hda:     pcm params           15 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x0f, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 148); // 0x00ff000b
//      snd_hda:     stream format params 15 
        retval = snd_hda_codec_read_check(codec, 0x0f, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 149); // 0x00ff0012
//      snd_hda:     amp capabilities 15 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x0f, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 150); // 0x00ff000d
//      snd_hda:     amp capabilities 15 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x0f, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 151); // 0x00ff0009
//      snd_hda:     15 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x10, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 153); // 0x010f0005
        retval = snd_hda_codec_read_check(codec, 0x10, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 154); // 0x010f0009
//      snd_hda:     16 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x10, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 155); // 0x010f000f
        retval = snd_hda_codec_read_check(codec, 0x10, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 156); // 0x010f000a
//      snd_hda:     pcm params           16 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x10, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 157); // 0x010f000b
//      snd_hda:     stream format params 16 
        retval = snd_hda_codec_read_check(codec, 0x10, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 158); // 0x010f0012
//      snd_hda:     amp capabilities 16 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x10, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 159); // 0x010f000d
//      snd_hda:     amp capabilities 16 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x10, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 160); // 0x010f0009
//      snd_hda:     16 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x11, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 162); // 0x011f0005
        retval = snd_hda_codec_read_check(codec, 0x11, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 163); // 0x011f0009
//      snd_hda:     17 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x11, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 164); // 0x011f000f
        retval = snd_hda_codec_read_check(codec, 0x11, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 165); // 0x011f000a
//      snd_hda:     pcm params           17 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x11, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 166); // 0x011f000b
//      snd_hda:     stream format params 17 
        retval = snd_hda_codec_read_check(codec, 0x11, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 167); // 0x011f0012
//      snd_hda:     amp capabilities 17 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x11, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 168); // 0x011f000d
//      snd_hda:     amp capabilities 17 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x11, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00060001, 169); // 0x011f0009
//      snd_hda:     17 AC_WID_AUD_OUT ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 6 0
        retval = snd_hda_codec_read_check(codec, 0x12, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 171); // 0x012f0005
        retval = snd_hda_codec_read_check(codec, 0x12, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 172); // 0x012f0009
//      snd_hda:     18 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x12, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 173); // 0x012f000f
        retval = snd_hda_codec_read_check(codec, 0x12, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 174); // 0x012f000a
//      snd_hda:     pcm params           18 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x12, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 175); // 0x012f000b
//      snd_hda:     stream format params 18 
        retval = snd_hda_codec_read_check(codec, 0x12, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 176); // 0x012f0012
//      snd_hda:     amp capabilities 18 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x12, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 177); // 0x012f000d
//      snd_hda:     amp capabilities 18 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x12, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 178); // 0x012f0009
//      snd_hda:     18 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x12, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 179); // 0x012f000e
        retval = snd_hda_codec_read_check(codec, 0x12, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000034, 180); // 0x012f0200
//      snd_hda:     connection list 18 <- 52
        retval = snd_hda_codec_read_check(codec, 0x13, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 182); // 0x013f0005
        retval = snd_hda_codec_read_check(codec, 0x13, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 183); // 0x013f0009
//      snd_hda:     19 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x13, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 184); // 0x013f000f
        retval = snd_hda_codec_read_check(codec, 0x13, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 185); // 0x013f000a
//      snd_hda:     pcm params           19 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x13, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 186); // 0x013f000b
//      snd_hda:     stream format params 19 
        retval = snd_hda_codec_read_check(codec, 0x13, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 187); // 0x013f0012
//      snd_hda:     amp capabilities 19 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x13, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 188); // 0x013f000d
//      snd_hda:     amp capabilities 19 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x13, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 189); // 0x013f0009
//      snd_hda:     19 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x13, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 190); // 0x013f000e
        retval = snd_hda_codec_read_check(codec, 0x13, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000035, 191); // 0x013f0200
//      snd_hda:     connection list 19 <- 53
        retval = snd_hda_codec_read_check(codec, 0x14, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 193); // 0x014f0005
        retval = snd_hda_codec_read_check(codec, 0x14, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 194); // 0x014f0009
//      snd_hda:     20 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x14, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 195); // 0x014f000f
        retval = snd_hda_codec_read_check(codec, 0x14, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 196); // 0x014f000a
//      snd_hda:     pcm params           20 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x14, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 197); // 0x014f000b
//      snd_hda:     stream format params 20 
        retval = snd_hda_codec_read_check(codec, 0x14, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 198); // 0x014f0012
//      snd_hda:     amp capabilities 20 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x14, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 199); // 0x014f000d
//      snd_hda:     amp capabilities 20 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x14, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 200); // 0x014f0009
//      snd_hda:     20 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x14, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 201); // 0x014f000e
        retval = snd_hda_codec_read_check(codec, 0x14, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000036, 202); // 0x014f0200
//      snd_hda:     connection list 20 <- 54
        retval = snd_hda_codec_read_check(codec, 0x15, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 204); // 0x015f0005
        retval = snd_hda_codec_read_check(codec, 0x15, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 205); // 0x015f0009
//      snd_hda:     21 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x15, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 206); // 0x015f000f
        retval = snd_hda_codec_read_check(codec, 0x15, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 207); // 0x015f000a
//      snd_hda:     pcm params           21 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x15, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 208); // 0x015f000b
//      snd_hda:     stream format params 21 
        retval = snd_hda_codec_read_check(codec, 0x15, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 209); // 0x015f0012
//      snd_hda:     amp capabilities 21 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x15, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 210); // 0x015f000d
//      snd_hda:     amp capabilities 21 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x15, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 211); // 0x015f0009
//      snd_hda:     21 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x15, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 212); // 0x015f000e
        retval = snd_hda_codec_read_check(codec, 0x15, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000037, 213); // 0x015f0200
//      snd_hda:     connection list 21 <- 55
        retval = snd_hda_codec_read_check(codec, 0x16, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 215); // 0x016f0005
        retval = snd_hda_codec_read_check(codec, 0x16, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 216); // 0x016f0009
//      snd_hda:     22 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x16, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 217); // 0x016f000f
        retval = snd_hda_codec_read_check(codec, 0x16, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 218); // 0x016f000a
//      snd_hda:     pcm params           22 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x16, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 219); // 0x016f000b
//      snd_hda:     stream format params 22 
        retval = snd_hda_codec_read_check(codec, 0x16, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 220); // 0x016f0012
//      snd_hda:     amp capabilities 22 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x16, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 221); // 0x016f000d
//      snd_hda:     amp capabilities 22 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x16, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 222); // 0x016f0009
//      snd_hda:     22 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x16, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 223); // 0x016f000e
        retval = snd_hda_codec_read_check(codec, 0x16, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000038, 224); // 0x016f0200
//      snd_hda:     connection list 22 <- 56
        retval = snd_hda_codec_read_check(codec, 0x17, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 226); // 0x017f0005
        retval = snd_hda_codec_read_check(codec, 0x17, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 227); // 0x017f0009
//      snd_hda:     23 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x17, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 228); // 0x017f000f
        retval = snd_hda_codec_read_check(codec, 0x17, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 229); // 0x017f000a
//      snd_hda:     pcm params           23 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x17, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 230); // 0x017f000b
//      snd_hda:     stream format params 23 
        retval = snd_hda_codec_read_check(codec, 0x17, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 231); // 0x017f0012
//      snd_hda:     amp capabilities 23 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x17, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 232); // 0x017f000d
//      snd_hda:     amp capabilities 23 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x17, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 233); // 0x017f0009
//      snd_hda:     23 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x17, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 234); // 0x017f000e
        retval = snd_hda_codec_read_check(codec, 0x17, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000039, 235); // 0x017f0200
//      snd_hda:     connection list 23 <- 57
        retval = snd_hda_codec_read_check(codec, 0x18, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 237); // 0x018f0005
        retval = snd_hda_codec_read_check(codec, 0x18, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 238); // 0x018f0009
//      snd_hda:     24 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x18, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 239); // 0x018f000f
        retval = snd_hda_codec_read_check(codec, 0x18, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 240); // 0x018f000a
//      snd_hda:     pcm params           24 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x18, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 241); // 0x018f000b
//      snd_hda:     stream format params 24 
        retval = snd_hda_codec_read_check(codec, 0x18, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 242); // 0x018f0012
//      snd_hda:     amp capabilities 24 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x18, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 243); // 0x018f000d
//      snd_hda:     amp capabilities 24 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x18, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 244); // 0x018f0009
//      snd_hda:     24 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x18, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 245); // 0x018f000e
        retval = snd_hda_codec_read_check(codec, 0x18, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x0000003a, 246); // 0x018f0200
//      snd_hda:     connection list 24 <- 58
        retval = snd_hda_codec_read_check(codec, 0x19, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 248); // 0x019f0005
        retval = snd_hda_codec_read_check(codec, 0x19, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 249); // 0x019f0009
//      snd_hda:     25 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x19, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 250); // 0x019f000f
        retval = snd_hda_codec_read_check(codec, 0x19, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 251); // 0x019f000a
//      snd_hda:     pcm params           25 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x19, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 252); // 0x019f000b
//      snd_hda:     stream format params 25 
        retval = snd_hda_codec_read_check(codec, 0x19, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 253); // 0x019f0012
//      snd_hda:     amp capabilities 25 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x19, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 254); // 0x019f000d
//      snd_hda:     amp capabilities 25 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x19, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 255); // 0x019f0009
//      snd_hda:     25 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x19, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 256); // 0x019f000e
        retval = snd_hda_codec_read_check(codec, 0x19, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x0000003b, 257); // 0x019f0200
//      snd_hda:     connection list 25 <- 59
        retval = snd_hda_codec_read_check(codec, 0x1a, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 259); // 0x01af0005
        retval = snd_hda_codec_read_check(codec, 0x1a, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 260); // 0x01af0009
//      snd_hda:     26 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x1a, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 261); // 0x01af000f
        retval = snd_hda_codec_read_check(codec, 0x1a, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 262); // 0x01af000a
//      snd_hda:     pcm params           26 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x1a, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 263); // 0x01af000b
//      snd_hda:     stream format params 26 
        retval = snd_hda_codec_read_check(codec, 0x1a, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 264); // 0x01af0012
//      snd_hda:     amp capabilities 26 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x1a, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 265); // 0x01af000d
//      snd_hda:     amp capabilities 26 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x1a, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 266); // 0x01af0009
//      snd_hda:     26 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x1a, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 267); // 0x01af000e
        retval = snd_hda_codec_read_check(codec, 0x1a, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x0000003c, 268); // 0x01af0200
//      snd_hda:     connection list 26 <- 60
        retval = snd_hda_codec_read_check(codec, 0x1b, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 270); // 0x01bf0005
        retval = snd_hda_codec_read_check(codec, 0x1b, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 271); // 0x01bf0009
//      snd_hda:     27 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x1b, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 272); // 0x01bf000f
        retval = snd_hda_codec_read_check(codec, 0x1b, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 273); // 0x01bf000a
//      snd_hda:     pcm params           27 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x1b, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 274); // 0x01bf000b
//      snd_hda:     stream format params 27 
        retval = snd_hda_codec_read_check(codec, 0x1b, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 275); // 0x01bf0012
//      snd_hda:     amp capabilities 27 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x1b, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 276); // 0x01bf000d
//      snd_hda:     amp capabilities 27 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x1b, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 277); // 0x01bf0009
//      snd_hda:     27 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x1b, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 278); // 0x01bf000e
        retval = snd_hda_codec_read_check(codec, 0x1b, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x0000003d, 279); // 0x01bf0200
//      snd_hda:     connection list 27 <- 61
        retval = snd_hda_codec_read_check(codec, 0x1c, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 281); // 0x01cf0005
        retval = snd_hda_codec_read_check(codec, 0x1c, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 282); // 0x01cf0009
//      snd_hda:     28 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x1c, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 283); // 0x01cf000f
        retval = snd_hda_codec_read_check(codec, 0x1c, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 284); // 0x01cf000a
//      snd_hda:     pcm params           28 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x1c, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 285); // 0x01cf000b
//      snd_hda:     stream format params 28 
        retval = snd_hda_codec_read_check(codec, 0x1c, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 286); // 0x01cf0012
//      snd_hda:     amp capabilities 28 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x1c, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 287); // 0x01cf000d
//      snd_hda:     amp capabilities 28 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x1c, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 288); // 0x01cf0009
//      snd_hda:     28 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x1c, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 289); // 0x01cf000e
        retval = snd_hda_codec_read_check(codec, 0x1c, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x0000003e, 290); // 0x01cf0200
//      snd_hda:     connection list 28 <- 62
        retval = snd_hda_codec_read_check(codec, 0x1d, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 292); // 0x01df0005
        retval = snd_hda_codec_read_check(codec, 0x1d, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 293); // 0x01df0009
//      snd_hda:     29 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x1d, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 294); // 0x01df000f
        retval = snd_hda_codec_read_check(codec, 0x1d, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 295); // 0x01df000a
//      snd_hda:     pcm params           29 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x1d, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 296); // 0x01df000b
//      snd_hda:     stream format params 29 
        retval = snd_hda_codec_read_check(codec, 0x1d, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 297); // 0x01df0012
//      snd_hda:     amp capabilities 29 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x1d, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 298); // 0x01df000d
//      snd_hda:     amp capabilities 29 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x1d, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 299); // 0x01df0009
//      snd_hda:     29 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x1d, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 300); // 0x01df000e
        retval = snd_hda_codec_read_check(codec, 0x1d, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x0000003f, 301); // 0x01df0200
//      snd_hda:     connection list 29 <- 63
        retval = snd_hda_codec_read_check(codec, 0x1e, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 303); // 0x01ef0005
        retval = snd_hda_codec_read_check(codec, 0x1e, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 304); // 0x01ef0009
//      snd_hda:     30 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x1e, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 305); // 0x01ef000f
        retval = snd_hda_codec_read_check(codec, 0x1e, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 306); // 0x01ef000a
//      snd_hda:     pcm params           30 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x1e, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 307); // 0x01ef000b
//      snd_hda:     stream format params 30 
        retval = snd_hda_codec_read_check(codec, 0x1e, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 308); // 0x01ef0012
//      snd_hda:     amp capabilities 30 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x1e, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 309); // 0x01ef000d
//      snd_hda:     amp capabilities 30 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x1e, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 310); // 0x01ef0009
//      snd_hda:     30 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x1e, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 311); // 0x01ef000e
        retval = snd_hda_codec_read_check(codec, 0x1e, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000040, 312); // 0x01ef0200
//      snd_hda:     connection list 30 <- 64
        retval = snd_hda_codec_read_check(codec, 0x1f, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 314); // 0x01ff0005
        retval = snd_hda_codec_read_check(codec, 0x1f, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 315); // 0x01ff0009
//      snd_hda:     31 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x1f, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 316); // 0x01ff000f
        retval = snd_hda_codec_read_check(codec, 0x1f, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 317); // 0x01ff000a
//      snd_hda:     pcm params           31 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x1f, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 318); // 0x01ff000b
//      snd_hda:     stream format params 31 
        retval = snd_hda_codec_read_check(codec, 0x1f, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 319); // 0x01ff0012
//      snd_hda:     amp capabilities 31 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x1f, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 320); // 0x01ff000d
//      snd_hda:     amp capabilities 31 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x1f, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 321); // 0x01ff0009
//      snd_hda:     31 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x1f, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 322); // 0x01ff000e
        retval = snd_hda_codec_read_check(codec, 0x1f, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000041, 323); // 0x01ff0200
//      snd_hda:     connection list 31 <- 65
        retval = snd_hda_codec_read_check(codec, 0x20, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 325); // 0x020f0005
        retval = snd_hda_codec_read_check(codec, 0x20, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 326); // 0x020f0009
//      snd_hda:     32 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x20, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 327); // 0x020f000f
        retval = snd_hda_codec_read_check(codec, 0x20, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 328); // 0x020f000a
//      snd_hda:     pcm params           32 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x20, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 329); // 0x020f000b
//      snd_hda:     stream format params 32 
        retval = snd_hda_codec_read_check(codec, 0x20, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 330); // 0x020f0012
//      snd_hda:     amp capabilities 32 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x20, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 331); // 0x020f000d
//      snd_hda:     amp capabilities 32 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x20, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 332); // 0x020f0009
//      snd_hda:     32 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x20, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 333); // 0x020f000e
        retval = snd_hda_codec_read_check(codec, 0x20, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000042, 334); // 0x020f0200
//      snd_hda:     connection list 32 <- 66
        retval = snd_hda_codec_read_check(codec, 0x21, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 336); // 0x021f0005
        retval = snd_hda_codec_read_check(codec, 0x21, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 337); // 0x021f0009
//      snd_hda:     33 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x21, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 338); // 0x021f000f
        retval = snd_hda_codec_read_check(codec, 0x21, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 339); // 0x021f000a
//      snd_hda:     pcm params           33 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x21, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 340); // 0x021f000b
//      snd_hda:     stream format params 33 
        retval = snd_hda_codec_read_check(codec, 0x21, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 341); // 0x021f0012
//      snd_hda:     amp capabilities 33 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x21, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 342); // 0x021f000d
//      snd_hda:     amp capabilities 33 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x21, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00160101, 343); // 0x021f0009
//      snd_hda:     33 AC_WID_AUD_IN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 6 1
        retval = snd_hda_codec_read_check(codec, 0x21, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 344); // 0x021f000e
        retval = snd_hda_codec_read_check(codec, 0x21, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000043, 345); // 0x021f0200
//      snd_hda:     connection list 33 <- 67
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 347); // 0x022f0005
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_PARAMETERS, 0x00000009, 0x0018051b, 348); // 0x022f0009
//      snd_hda:     34 AC_WID_AUD_IN ['AC_WCAP_STEREO', 'AC_WCAP_CONN_LIST', 'AC_WCAP_POWER', 'AC_WCAP_TYPE', 'AC_WCAP_DELAY', 'AC_WCAP_FORMAT_OVRD', 'AC_WCAP_AMP_OVRD', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_IN_AMP'] 0 8 1
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x80000009, 349); // 0x022f000f
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x001e01f5, 350); // 0x022f000a
//      snd_hda:     pcm params           34 bits: 16bit 20bit 24bit 32bit rates: 8kHz 16kHz 32kHz 44.1kHz 48kHz 88.2kHz 96kHz
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000001, 351); // 0x022f000b
//      snd_hda:     stream format params 34 pcm
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 352); // 0x022f0012
//      snd_hda:     amp capabilities 34 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x80033f33, 353); // 0x022f000d
//      snd_hda:     amp capabilities 34 input  0x80033f33 offset 0x33 numsteps 0x3f stepsize 0x03 mute 1
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_PARAMETERS, 0x00000009, 0x0018051b, 354); // 0x022f0009
//      snd_hda:     34 AC_WID_AUD_IN ['AC_WCAP_STEREO', 'AC_WCAP_CONN_LIST', 'AC_WCAP_POWER', 'AC_WCAP_TYPE', 'AC_WCAP_DELAY', 'AC_WCAP_FORMAT_OVRD', 'AC_WCAP_AMP_OVRD', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_IN_AMP'] 0 8 1

        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x02270500
        hda_set_node_power_state(codec, 0x22, AC_PWRST_D0);

        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x001e01f5, 356); // 0x022f000a
//      snd_hda:     pcm params           34 bits: 16bit 20bit 24bit 32bit rates: 8kHz 16kHz 32kHz 44.1kHz 48kHz 88.2kHz 96kHz
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000001, 357); // 0x022f000b
//      snd_hda:     stream format params 34 pcm
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x80033f33, 358); // 0x022f000d
//      snd_hda:     amp capabilities 34 input  0x80033f33 offset 0x33 numsteps 0x3f stepsize 0x03 mute 1
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 359); // 0x022f000e
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000044, 360); // 0x022f0200
//      snd_hda:     connection list 34 <- 68
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x80000009, 361); // 0x022f000f

        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x02270503
        hda_set_node_power_state(codec, 0x22, AC_PWRST_D3);

        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 364); // 0x023f0005
        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_PARAMETERS, 0x00000009, 0x0018051b, 365); // 0x023f0009
//      snd_hda:     35 AC_WID_AUD_IN ['AC_WCAP_STEREO', 'AC_WCAP_CONN_LIST', 'AC_WCAP_POWER', 'AC_WCAP_TYPE', 'AC_WCAP_DELAY', 'AC_WCAP_FORMAT_OVRD', 'AC_WCAP_AMP_OVRD', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_IN_AMP'] 0 8 1
        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x80000009, 366); // 0x023f000f
        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x001e01f5, 367); // 0x023f000a
//      snd_hda:     pcm params           35 bits: 16bit 20bit 24bit 32bit rates: 8kHz 16kHz 32kHz 44.1kHz 48kHz 88.2kHz 96kHz
        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000001, 368); // 0x023f000b
//      snd_hda:     stream format params 35 pcm
        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 369); // 0x023f0012
//      snd_hda:     amp capabilities 35 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x80033f33, 370); // 0x023f000d
//      snd_hda:     amp capabilities 35 input  0x80033f33 offset 0x33 numsteps 0x3f stepsize 0x03 mute 1
        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_PARAMETERS, 0x00000009, 0x0018051b, 371); // 0x023f0009
//      snd_hda:     35 AC_WID_AUD_IN ['AC_WCAP_STEREO', 'AC_WCAP_CONN_LIST', 'AC_WCAP_POWER', 'AC_WCAP_TYPE', 'AC_WCAP_DELAY', 'AC_WCAP_FORMAT_OVRD', 'AC_WCAP_AMP_OVRD', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_IN_AMP'] 0 8 1

        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x02370500
        hda_set_node_power_state(codec, 0x23, AC_PWRST_D0);

        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x001e01f5, 373); // 0x023f000a
//      snd_hda:     pcm params           35 bits: 16bit 20bit 24bit 32bit rates: 8kHz 16kHz 32kHz 44.1kHz 48kHz 88.2kHz 96kHz
        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000001, 374); // 0x023f000b
//      snd_hda:     stream format params 35 pcm
        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x80033f33, 375); // 0x023f000d
//      snd_hda:     amp capabilities 35 input  0x80033f33 offset 0x33 numsteps 0x3f stepsize 0x03 mute 1
        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 376); // 0x023f000e
        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000045, 377); // 0x023f0200
//      snd_hda:     connection list 35 <- 69
        retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x80000009, 378); // 0x023f000f

        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x02370503
        hda_set_node_power_state(codec, 0x23, AC_PWRST_D3);

        retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 381); // 0x024f0005
        retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 382); // 0x024f0009
//      snd_hda:     36 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 383); // 0x024f000f
        retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 384); // 0x024f0012
//      snd_hda:     amp capabilities 36 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 385); // 0x024f000d
//      snd_hda:     amp capabilities 36 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 386); // 0x024f0009
//      snd_hda:     36 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x90100110, 387); // 0x024f1c00
//      snd_hda:     pin config default 0x90100110 port conn 2 location 0x10 loc ext 1 loc geom 0 default device 1 conn type 0 color 0 misc 1 def assoc 1 seq 0
//      snd_hda:     pin config default 0x90100110 port conn Fixed loc ext Int loc geom N/A default device Speaker conn type Unknown color Unknown misc Jack Detect Override def assoc 1 seq 0
        retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000010, 388); // 0x024f000c
//      snd_hda:     36 ['AC_PINCAP_OUT'] []
        retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 389); // 0x024f000e
        retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000002, 390); // 0x024f0200
//      snd_hda:     connection list 36 <- 2
        retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 391); // 0x024f0700
        snd_hda_codec_write(codec, 0x24, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x02470700
//      snd_hda:     36 []

        retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 394); // 0x025f0005
        retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 395); // 0x025f0009
//      snd_hda:     37 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 396); // 0x025f000f
        retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 397); // 0x025f0012
//      snd_hda:     amp capabilities 37 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 398); // 0x025f000d
//      snd_hda:     amp capabilities 37 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 399); // 0x025f0009
//      snd_hda:     37 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x90100111, 400); // 0x025f1c00
//      snd_hda:     pin config default 0x90100111 port conn 2 location 0x10 loc ext 1 loc geom 0 default device 1 conn type 0 color 0 misc 1 def assoc 1 seq 1
//      snd_hda:     pin config default 0x90100111 port conn Fixed loc ext Int loc geom N/A default device Speaker conn type Unknown color Unknown misc Jack Detect Override def assoc 1 seq 1
        retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000010, 401); // 0x025f000c
//      snd_hda:     37 ['AC_PINCAP_OUT'] []
        retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 402); // 0x025f000e
        retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000003, 403); // 0x025f0200
//      snd_hda:     connection list 37 <- 3
        retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 404); // 0x025f0700
        snd_hda_codec_write(codec, 0x25, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x02570700
//      snd_hda:     37 []

        retval = snd_hda_codec_read_check(codec, 0x26, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 407); // 0x026f0005
        retval = snd_hda_codec_read_check(codec, 0x26, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 408); // 0x026f0009
//      snd_hda:     38 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x26, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 409); // 0x026f000f
        retval = snd_hda_codec_read_check(codec, 0x26, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 410); // 0x026f0012
//      snd_hda:     amp capabilities 38 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x26, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 411); // 0x026f000d
//      snd_hda:     amp capabilities 38 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x26, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 412); // 0x026f0009
//      snd_hda:     38 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x26, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 413); // 0x026f1c00
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x26, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000010, 414); // 0x026f000c
//      snd_hda:     38 ['AC_PINCAP_OUT'] []
        retval = snd_hda_codec_read_check(codec, 0x26, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 415); // 0x026f000e
        retval = snd_hda_codec_read_check(codec, 0x26, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000004, 416); // 0x026f0200
//      snd_hda:     connection list 38 <- 4
        retval = snd_hda_codec_read_check(codec, 0x26, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 417); // 0x026f0700
        snd_hda_codec_write(codec, 0x26, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x02670700
//      snd_hda:     38 []

        retval = snd_hda_codec_read_check(codec, 0x27, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 420); // 0x027f0005
        retval = snd_hda_codec_read_check(codec, 0x27, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 421); // 0x027f0009
//      snd_hda:     39 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x27, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 422); // 0x027f000f
        retval = snd_hda_codec_read_check(codec, 0x27, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 423); // 0x027f0012
//      snd_hda:     amp capabilities 39 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x27, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 424); // 0x027f000d
//      snd_hda:     amp capabilities 39 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x27, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 425); // 0x027f0009
//      snd_hda:     39 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x27, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 426); // 0x027f1c00
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x27, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000010, 427); // 0x027f000c
//      snd_hda:     39 ['AC_PINCAP_OUT'] []
        retval = snd_hda_codec_read_check(codec, 0x27, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 428); // 0x027f000e
        retval = snd_hda_codec_read_check(codec, 0x27, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000005, 429); // 0x027f0200
//      snd_hda:     connection list 39 <- 5
        retval = snd_hda_codec_read_check(codec, 0x27, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 430); // 0x027f0700
        snd_hda_codec_write(codec, 0x27, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x02770700
//      snd_hda:     39 []

        retval = snd_hda_codec_read_check(codec, 0x28, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 433); // 0x028f0005
        retval = snd_hda_codec_read_check(codec, 0x28, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 434); // 0x028f0009
//      snd_hda:     40 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x28, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 435); // 0x028f000f
        retval = snd_hda_codec_read_check(codec, 0x28, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 436); // 0x028f0012
//      snd_hda:     amp capabilities 40 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x28, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 437); // 0x028f000d
//      snd_hda:     amp capabilities 40 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x28, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 438); // 0x028f0009
//      snd_hda:     40 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x28, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 439); // 0x028f1c00
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x28, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000010, 440); // 0x028f000c
//      snd_hda:     40 ['AC_PINCAP_OUT'] []
        retval = snd_hda_codec_read_check(codec, 0x28, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 441); // 0x028f000e
        retval = snd_hda_codec_read_check(codec, 0x28, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000006, 442); // 0x028f0200
//      snd_hda:     connection list 40 <- 6
        retval = snd_hda_codec_read_check(codec, 0x28, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 443); // 0x028f0700
        snd_hda_codec_write(codec, 0x28, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x02870700
//      snd_hda:     40 []

        retval = snd_hda_codec_read_check(codec, 0x29, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 446); // 0x029f0005
        retval = snd_hda_codec_read_check(codec, 0x29, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 447); // 0x029f0009
//      snd_hda:     41 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x29, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 448); // 0x029f000f
        retval = snd_hda_codec_read_check(codec, 0x29, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 449); // 0x029f0012
//      snd_hda:     amp capabilities 41 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x29, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 450); // 0x029f000d
//      snd_hda:     amp capabilities 41 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x29, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 451); // 0x029f0009
//      snd_hda:     41 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x29, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 452); // 0x029f1c00
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x29, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000010, 453); // 0x029f000c
//      snd_hda:     41 ['AC_PINCAP_OUT'] []
        retval = snd_hda_codec_read_check(codec, 0x29, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 454); // 0x029f000e
        retval = snd_hda_codec_read_check(codec, 0x29, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000007, 455); // 0x029f0200
//      snd_hda:     connection list 41 <- 7
        retval = snd_hda_codec_read_check(codec, 0x29, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 456); // 0x029f0700
        snd_hda_codec_write(codec, 0x29, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x02970700
//      snd_hda:     41 []

        retval = snd_hda_codec_read_check(codec, 0x2a, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 459); // 0x02af0005
        retval = snd_hda_codec_read_check(codec, 0x2a, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 460); // 0x02af0009
//      snd_hda:     42 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x2a, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 461); // 0x02af000f
        retval = snd_hda_codec_read_check(codec, 0x2a, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 462); // 0x02af0012
//      snd_hda:     amp capabilities 42 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x2a, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 463); // 0x02af000d
//      snd_hda:     amp capabilities 42 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x2a, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 464); // 0x02af0009
//      snd_hda:     42 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x2a, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 465); // 0x02af1c00
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x2a, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000010, 466); // 0x02af000c
//      snd_hda:     42 ['AC_PINCAP_OUT'] []
        retval = snd_hda_codec_read_check(codec, 0x2a, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 467); // 0x02af000e
        retval = snd_hda_codec_read_check(codec, 0x2a, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000008, 468); // 0x02af0200
//      snd_hda:     connection list 42 <- 8
        retval = snd_hda_codec_read_check(codec, 0x2a, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 469); // 0x02af0700
        snd_hda_codec_write(codec, 0x2a, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x02a70700
//      snd_hda:     42 []

        retval = snd_hda_codec_read_check(codec, 0x2b, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 472); // 0x02bf0005
        retval = snd_hda_codec_read_check(codec, 0x2b, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 473); // 0x02bf0009
//      snd_hda:     43 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x2b, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 474); // 0x02bf000f
        retval = snd_hda_codec_read_check(codec, 0x2b, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 475); // 0x02bf0012
//      snd_hda:     amp capabilities 43 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x2b, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 476); // 0x02bf000d
//      snd_hda:     amp capabilities 43 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x2b, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 477); // 0x02bf0009
//      snd_hda:     43 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x2b, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 478); // 0x02bf1c00
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x2b, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000010, 479); // 0x02bf000c
//      snd_hda:     43 ['AC_PINCAP_OUT'] []
        retval = snd_hda_codec_read_check(codec, 0x2b, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 480); // 0x02bf000e
        retval = snd_hda_codec_read_check(codec, 0x2b, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000009, 481); // 0x02bf0200
//      snd_hda:     connection list 43 <- 9
        retval = snd_hda_codec_read_check(codec, 0x2b, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 482); // 0x02bf0700
        snd_hda_codec_write(codec, 0x2b, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x02b70700
//      snd_hda:     43 []

        retval = snd_hda_codec_read_check(codec, 0x2c, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 485); // 0x02cf0005
        retval = snd_hda_codec_read_check(codec, 0x2c, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 486); // 0x02cf0009
//      snd_hda:     44 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x2c, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 487); // 0x02cf000f
        retval = snd_hda_codec_read_check(codec, 0x2c, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 488); // 0x02cf0012
//      snd_hda:     amp capabilities 44 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x2c, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 489); // 0x02cf000d
//      snd_hda:     amp capabilities 44 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x2c, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 490); // 0x02cf0009
//      snd_hda:     44 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x2c, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x002b4020, 491); // 0x02cf1c00
//      snd_hda:     pin config default 0x002b4020 port conn 0 location 0x0 loc ext 0 loc geom 0 default device 2 conn type 11 color 4 misc 0 def assoc 2 seq 0
//      snd_hda:     pin config default 0x002b4020 port conn Jack loc ext Ext loc geom N/A default device HP Out conn type Combination color Green misc undef def assoc 2 seq 0
        retval = snd_hda_codec_read_check(codec, 0x2c, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000010, 492); // 0x02cf000c
//      snd_hda:     44 ['AC_PINCAP_OUT'] []
        retval = snd_hda_codec_read_check(codec, 0x2c, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 493); // 0x02cf000e
        retval = snd_hda_codec_read_check(codec, 0x2c, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x0000000a, 494); // 0x02cf0200
//      snd_hda:     connection list 44 <- 10
        retval = snd_hda_codec_read_check(codec, 0x2c, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 495); // 0x02cf0700
        snd_hda_codec_write(codec, 0x2c, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x02c70700
//      snd_hda:     44 []

        retval = snd_hda_codec_read_check(codec, 0x2d, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 498); // 0x02df0005
        retval = snd_hda_codec_read_check(codec, 0x2d, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 499); // 0x02df0009
//      snd_hda:     45 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x2d, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 500); // 0x02df000f
        retval = snd_hda_codec_read_check(codec, 0x2d, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 501); // 0x02df0012
//      snd_hda:     amp capabilities 45 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x2d, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 502); // 0x02df000d
//      snd_hda:     amp capabilities 45 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x2d, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 503); // 0x02df0009
//      snd_hda:     45 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x2d, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 504); // 0x02df1c00
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x2d, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000010, 505); // 0x02df000c
//      snd_hda:     45 ['AC_PINCAP_OUT'] []
        retval = snd_hda_codec_read_check(codec, 0x2d, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 506); // 0x02df000e
        retval = snd_hda_codec_read_check(codec, 0x2d, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x0000000b, 507); // 0x02df0200
//      snd_hda:     connection list 45 <- 11
        retval = snd_hda_codec_read_check(codec, 0x2d, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 508); // 0x02df0700
        snd_hda_codec_write(codec, 0x2d, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x02d70700
//      snd_hda:     45 []

        retval = snd_hda_codec_read_check(codec, 0x2e, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 511); // 0x02ef0005
        retval = snd_hda_codec_read_check(codec, 0x2e, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 512); // 0x02ef0009
//      snd_hda:     46 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x2e, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 513); // 0x02ef000f
        retval = snd_hda_codec_read_check(codec, 0x2e, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 514); // 0x02ef0012
//      snd_hda:     amp capabilities 46 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x2e, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 515); // 0x02ef000d
//      snd_hda:     amp capabilities 46 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x2e, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 516); // 0x02ef0009
//      snd_hda:     46 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x2e, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 517); // 0x02ef1c00
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x2e, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000010, 518); // 0x02ef000c
//      snd_hda:     46 ['AC_PINCAP_OUT'] []
        retval = snd_hda_codec_read_check(codec, 0x2e, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 519); // 0x02ef000e
        retval = snd_hda_codec_read_check(codec, 0x2e, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x0000000c, 520); // 0x02ef0200
//      snd_hda:     connection list 46 <- 12
        retval = snd_hda_codec_read_check(codec, 0x2e, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 521); // 0x02ef0700
        snd_hda_codec_write(codec, 0x2e, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x02e70700
//      snd_hda:     46 []

        retval = snd_hda_codec_read_check(codec, 0x2f, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 524); // 0x02ff0005
        retval = snd_hda_codec_read_check(codec, 0x2f, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 525); // 0x02ff0009
//      snd_hda:     47 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x2f, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 526); // 0x02ff000f
        retval = snd_hda_codec_read_check(codec, 0x2f, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 527); // 0x02ff0012
//      snd_hda:     amp capabilities 47 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x2f, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 528); // 0x02ff000d
//      snd_hda:     amp capabilities 47 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x2f, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 529); // 0x02ff0009
//      snd_hda:     47 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x2f, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 530); // 0x02ff1c00
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x2f, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000010, 531); // 0x02ff000c
//      snd_hda:     47 ['AC_PINCAP_OUT'] []
        retval = snd_hda_codec_read_check(codec, 0x2f, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 532); // 0x02ff000e
        retval = snd_hda_codec_read_check(codec, 0x2f, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x0000000d, 533); // 0x02ff0200
//      snd_hda:     connection list 47 <- 13
        retval = snd_hda_codec_read_check(codec, 0x2f, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 534); // 0x02ff0700
        snd_hda_codec_write(codec, 0x2f, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x02f70700
//      snd_hda:     47 []

        retval = snd_hda_codec_read_check(codec, 0x30, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 537); // 0x030f0005
        retval = snd_hda_codec_read_check(codec, 0x30, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 538); // 0x030f0009
//      snd_hda:     48 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x30, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 539); // 0x030f000f
        retval = snd_hda_codec_read_check(codec, 0x30, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 540); // 0x030f0012
//      snd_hda:     amp capabilities 48 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x30, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 541); // 0x030f000d
//      snd_hda:     amp capabilities 48 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x30, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 542); // 0x030f0009
//      snd_hda:     48 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x30, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 543); // 0x030f1c00
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x30, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000010, 544); // 0x030f000c
//      snd_hda:     48 ['AC_PINCAP_OUT'] []
        retval = snd_hda_codec_read_check(codec, 0x30, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 545); // 0x030f000e
        retval = snd_hda_codec_read_check(codec, 0x30, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x0000000e, 546); // 0x030f0200
//      snd_hda:     connection list 48 <- 14
        retval = snd_hda_codec_read_check(codec, 0x30, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 547); // 0x030f0700
        snd_hda_codec_write(codec, 0x30, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x03070700
//      snd_hda:     48 []

        retval = snd_hda_codec_read_check(codec, 0x31, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 550); // 0x031f0005
        retval = snd_hda_codec_read_check(codec, 0x31, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 551); // 0x031f0009
//      snd_hda:     49 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x31, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 552); // 0x031f000f
        retval = snd_hda_codec_read_check(codec, 0x31, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 553); // 0x031f0012
//      snd_hda:     amp capabilities 49 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x31, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 554); // 0x031f000d
//      snd_hda:     amp capabilities 49 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x31, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 555); // 0x031f0009
//      snd_hda:     49 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x31, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 556); // 0x031f1c00
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x31, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000010, 557); // 0x031f000c
//      snd_hda:     49 ['AC_PINCAP_OUT'] []
        retval = snd_hda_codec_read_check(codec, 0x31, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 558); // 0x031f000e
        retval = snd_hda_codec_read_check(codec, 0x31, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x0000000f, 559); // 0x031f0200
//      snd_hda:     connection list 49 <- 15
        retval = snd_hda_codec_read_check(codec, 0x31, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 560); // 0x031f0700
        snd_hda_codec_write(codec, 0x31, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x03170700
//      snd_hda:     49 []

        retval = snd_hda_codec_read_check(codec, 0x32, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 563); // 0x032f0005
        retval = snd_hda_codec_read_check(codec, 0x32, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 564); // 0x032f0009
//      snd_hda:     50 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x32, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 565); // 0x032f000f
        retval = snd_hda_codec_read_check(codec, 0x32, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 566); // 0x032f0012
//      snd_hda:     amp capabilities 50 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x32, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 567); // 0x032f000d
//      snd_hda:     amp capabilities 50 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x32, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 568); // 0x032f0009
//      snd_hda:     50 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x32, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 569); // 0x032f1c00
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x32, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000010, 570); // 0x032f000c
//      snd_hda:     50 ['AC_PINCAP_OUT'] []
        retval = snd_hda_codec_read_check(codec, 0x32, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 571); // 0x032f000e
        retval = snd_hda_codec_read_check(codec, 0x32, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000010, 572); // 0x032f0200
//      snd_hda:     connection list 50 <- 16
        retval = snd_hda_codec_read_check(codec, 0x32, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 573); // 0x032f0700
        snd_hda_codec_write(codec, 0x32, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x03270700
//      snd_hda:     50 []

        retval = snd_hda_codec_read_check(codec, 0x33, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 576); // 0x033f0005
        retval = snd_hda_codec_read_check(codec, 0x33, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 577); // 0x033f0009
//      snd_hda:     51 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x33, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 578); // 0x033f000f
        retval = snd_hda_codec_read_check(codec, 0x33, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 579); // 0x033f0012
//      snd_hda:     amp capabilities 51 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x33, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 580); // 0x033f000d
//      snd_hda:     amp capabilities 51 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x33, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400101, 581); // 0x033f0009
//      snd_hda:     51 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_CONN_LIST'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x33, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 582); // 0x033f1c00
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x33, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000010, 583); // 0x033f000c
//      snd_hda:     51 ['AC_PINCAP_OUT'] []
        retval = snd_hda_codec_read_check(codec, 0x33, 0, AC_VERB_PARAMETERS, 0x0000000e, 0x00000001, 584); // 0x033f000e
        retval = snd_hda_codec_read_check(codec, 0x33, 0, AC_VERB_GET_CONNECT_LIST, 0x00000000, 0x00000011, 585); // 0x033f0200
//      snd_hda:     connection list 51 <- 17
        retval = snd_hda_codec_read_check(codec, 0x33, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 586); // 0x033f0700
        snd_hda_codec_write(codec, 0x33, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x03370700
//      snd_hda:     51 []

        retval = snd_hda_codec_read_check(codec, 0x34, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 589); // 0x034f0005
        retval = snd_hda_codec_read_check(codec, 0x34, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 590); // 0x034f0009
//      snd_hda:     52 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x34, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 591); // 0x034f000f
        retval = snd_hda_codec_read_check(codec, 0x34, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 592); // 0x034f0012
//      snd_hda:     amp capabilities 52 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x34, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 593); // 0x034f000d
//      snd_hda:     amp capabilities 52 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x34, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 594); // 0x034f0009
//      snd_hda:     52 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x34, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 595); // 0x034f1c00
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x34, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000020, 596); // 0x034f000c
//      snd_hda:     52 ['AC_PINCAP_IN'] []
        retval = snd_hda_codec_read_check(codec, 0x34, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 597); // 0x034f0700
        snd_hda_codec_write(codec, 0x34, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x03470700
//      snd_hda:     52 []

        retval = snd_hda_codec_read_check(codec, 0x35, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 600); // 0x035f0005
        retval = snd_hda_codec_read_check(codec, 0x35, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 601); // 0x035f0009
//      snd_hda:     53 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x35, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 602); // 0x035f000f
        retval = snd_hda_codec_read_check(codec, 0x35, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 603); // 0x035f0012
//      snd_hda:     amp capabilities 53 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x35, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 604); // 0x035f000d
//      snd_hda:     amp capabilities 53 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x35, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 605); // 0x035f0009
//      snd_hda:     53 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x35, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 606); // 0x035f1c00
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x35, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000020, 607); // 0x035f000c
//      snd_hda:     53 ['AC_PINCAP_IN'] []
        retval = snd_hda_codec_read_check(codec, 0x35, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 608); // 0x035f0700
        snd_hda_codec_write(codec, 0x35, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x03570700
//      snd_hda:     53 []

        retval = snd_hda_codec_read_check(codec, 0x36, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 611); // 0x036f0005
        retval = snd_hda_codec_read_check(codec, 0x36, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 612); // 0x036f0009
//      snd_hda:     54 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x36, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 613); // 0x036f000f
        retval = snd_hda_codec_read_check(codec, 0x36, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 614); // 0x036f0012
//      snd_hda:     amp capabilities 54 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x36, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 615); // 0x036f000d
//      snd_hda:     amp capabilities 54 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x36, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 616); // 0x036f0009
//      snd_hda:     54 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x36, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 617); // 0x036f1c00
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x36, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000020, 618); // 0x036f000c
//      snd_hda:     54 ['AC_PINCAP_IN'] []
        retval = snd_hda_codec_read_check(codec, 0x36, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 619); // 0x036f0700
        snd_hda_codec_write(codec, 0x36, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x03670700
//      snd_hda:     54 []

        retval = snd_hda_codec_read_check(codec, 0x37, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 622); // 0x037f0005
        retval = snd_hda_codec_read_check(codec, 0x37, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 623); // 0x037f0009
//      snd_hda:     55 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x37, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 624); // 0x037f000f
        retval = snd_hda_codec_read_check(codec, 0x37, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 625); // 0x037f0012
//      snd_hda:     amp capabilities 55 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x37, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 626); // 0x037f000d
//      snd_hda:     amp capabilities 55 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x37, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 627); // 0x037f0009
//      snd_hda:     55 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x37, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 628); // 0x037f1c00
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x37, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000020, 629); // 0x037f000c
//      snd_hda:     55 ['AC_PINCAP_IN'] []
        retval = snd_hda_codec_read_check(codec, 0x37, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 630); // 0x037f0700
        snd_hda_codec_write(codec, 0x37, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x03770700
//      snd_hda:     55 []

        retval = snd_hda_codec_read_check(codec, 0x38, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 633); // 0x038f0005
        retval = snd_hda_codec_read_check(codec, 0x38, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 634); // 0x038f0009
//      snd_hda:     56 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x38, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 635); // 0x038f000f
        retval = snd_hda_codec_read_check(codec, 0x38, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 636); // 0x038f0012
//      snd_hda:     amp capabilities 56 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x38, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 637); // 0x038f000d
//      snd_hda:     amp capabilities 56 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x38, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 638); // 0x038f0009
//      snd_hda:     56 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x38, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 639); // 0x038f1c00
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x38, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000020, 640); // 0x038f000c
//      snd_hda:     56 ['AC_PINCAP_IN'] []
        retval = snd_hda_codec_read_check(codec, 0x38, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 641); // 0x038f0700
        snd_hda_codec_write(codec, 0x38, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x03870700
//      snd_hda:     56 []

        retval = snd_hda_codec_read_check(codec, 0x39, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 644); // 0x039f0005
        retval = snd_hda_codec_read_check(codec, 0x39, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 645); // 0x039f0009
//      snd_hda:     57 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x39, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 646); // 0x039f000f
        retval = snd_hda_codec_read_check(codec, 0x39, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 647); // 0x039f0012
//      snd_hda:     amp capabilities 57 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x39, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 648); // 0x039f000d
//      snd_hda:     amp capabilities 57 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x39, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 649); // 0x039f0009
//      snd_hda:     57 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x39, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 650); // 0x039f1c00
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x39, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000020, 651); // 0x039f000c
//      snd_hda:     57 ['AC_PINCAP_IN'] []
        retval = snd_hda_codec_read_check(codec, 0x39, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 652); // 0x039f0700
        snd_hda_codec_write(codec, 0x39, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x03970700
//      snd_hda:     57 []

        retval = snd_hda_codec_read_check(codec, 0x3a, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 655); // 0x03af0005
        retval = snd_hda_codec_read_check(codec, 0x3a, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 656); // 0x03af0009
//      snd_hda:     58 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x3a, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 657); // 0x03af000f
        retval = snd_hda_codec_read_check(codec, 0x3a, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 658); // 0x03af0012
//      snd_hda:     amp capabilities 58 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x3a, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 659); // 0x03af000d
//      snd_hda:     amp capabilities 58 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x3a, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 660); // 0x03af0009
//      snd_hda:     58 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x3a, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 661); // 0x03af1c00
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x3a, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000020, 662); // 0x03af000c
//      snd_hda:     58 ['AC_PINCAP_IN'] []
        retval = snd_hda_codec_read_check(codec, 0x3a, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 663); // 0x03af0700
        snd_hda_codec_write(codec, 0x3a, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x03a70700
//      snd_hda:     58 []

        retval = snd_hda_codec_read_check(codec, 0x3b, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 666); // 0x03bf0005
        retval = snd_hda_codec_read_check(codec, 0x3b, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 667); // 0x03bf0009
//      snd_hda:     59 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x3b, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 668); // 0x03bf000f
        retval = snd_hda_codec_read_check(codec, 0x3b, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 669); // 0x03bf0012
//      snd_hda:     amp capabilities 59 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x3b, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 670); // 0x03bf000d
//      snd_hda:     amp capabilities 59 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x3b, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 671); // 0x03bf0009
//      snd_hda:     59 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x3b, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 672); // 0x03bf1c00
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x3b, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000020, 673); // 0x03bf000c
//      snd_hda:     59 ['AC_PINCAP_IN'] []
        retval = snd_hda_codec_read_check(codec, 0x3b, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 674); // 0x03bf0700
        snd_hda_codec_write(codec, 0x3b, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x03b70700
//      snd_hda:     59 []

        retval = snd_hda_codec_read_check(codec, 0x3c, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 677); // 0x03cf0005
        retval = snd_hda_codec_read_check(codec, 0x3c, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 678); // 0x03cf0009
//      snd_hda:     60 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x3c, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 679); // 0x03cf000f
        retval = snd_hda_codec_read_check(codec, 0x3c, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 680); // 0x03cf0012
//      snd_hda:     amp capabilities 60 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x3c, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 681); // 0x03cf000d
//      snd_hda:     amp capabilities 60 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x3c, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 682); // 0x03cf0009
//      snd_hda:     60 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x3c, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x00ab9030, 683); // 0x03cf1c00
//      snd_hda:     pin config default 0x00ab9030 port conn 0 location 0x0 loc ext 0 loc geom 0 default device 10 conn type 11 color 9 misc 0 def assoc 3 seq 0
//      snd_hda:     pin config default 0x00ab9030 port conn Jack loc ext Ext loc geom N/A default device Mic In conn type Combination color Pink misc undef def assoc 3 seq 0
        retval = snd_hda_codec_read_check(codec, 0x3c, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000020, 684); // 0x03cf000c
//      snd_hda:     60 ['AC_PINCAP_IN'] []
        retval = snd_hda_codec_read_check(codec, 0x3c, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 685); // 0x03cf0700
        snd_hda_codec_write(codec, 0x3c, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x03c70700
//      snd_hda:     60 []

        retval = snd_hda_codec_read_check(codec, 0x3d, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 688); // 0x03df0005
        retval = snd_hda_codec_read_check(codec, 0x3d, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 689); // 0x03df0009
//      snd_hda:     61 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x3d, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 690); // 0x03df000f
        retval = snd_hda_codec_read_check(codec, 0x3d, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 691); // 0x03df0012
//      snd_hda:     amp capabilities 61 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x3d, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 692); // 0x03df000d
//      snd_hda:     amp capabilities 61 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x3d, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 693); // 0x03df0009
//      snd_hda:     61 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x3d, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 694); // 0x03df1c00
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x3d, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000020, 695); // 0x03df000c
//      snd_hda:     61 ['AC_PINCAP_IN'] []
        retval = snd_hda_codec_read_check(codec, 0x3d, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 696); // 0x03df0700
        snd_hda_codec_write(codec, 0x3d, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x03d70700
//      snd_hda:     61 []

        retval = snd_hda_codec_read_check(codec, 0x3e, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 699); // 0x03ef0005
        retval = snd_hda_codec_read_check(codec, 0x3e, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 700); // 0x03ef0009
//      snd_hda:     62 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x3e, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 701); // 0x03ef000f
        retval = snd_hda_codec_read_check(codec, 0x3e, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 702); // 0x03ef0012
//      snd_hda:     amp capabilities 62 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x3e, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 703); // 0x03ef000d
//      snd_hda:     amp capabilities 62 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x3e, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 704); // 0x03ef0009
//      snd_hda:     62 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x3e, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 705); // 0x03ef1c00
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x3e, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000020, 706); // 0x03ef000c
//      snd_hda:     62 ['AC_PINCAP_IN'] []
        retval = snd_hda_codec_read_check(codec, 0x3e, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 707); // 0x03ef0700
        snd_hda_codec_write(codec, 0x3e, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x03e70700
//      snd_hda:     62 []

        retval = snd_hda_codec_read_check(codec, 0x3f, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 710); // 0x03ff0005
        retval = snd_hda_codec_read_check(codec, 0x3f, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 711); // 0x03ff0009
//      snd_hda:     63 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x3f, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 712); // 0x03ff000f
        retval = snd_hda_codec_read_check(codec, 0x3f, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 713); // 0x03ff0012
//      snd_hda:     amp capabilities 63 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x3f, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 714); // 0x03ff000d
//      snd_hda:     amp capabilities 63 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x3f, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 715); // 0x03ff0009
//      snd_hda:     63 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x3f, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 716); // 0x03ff1c00
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x3f, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000020, 717); // 0x03ff000c
//      snd_hda:     63 ['AC_PINCAP_IN'] []
        retval = snd_hda_codec_read_check(codec, 0x3f, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 718); // 0x03ff0700
        snd_hda_codec_write(codec, 0x3f, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x03f70700
//      snd_hda:     63 []

        retval = snd_hda_codec_read_check(codec, 0x40, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 721); // 0x040f0005
        retval = snd_hda_codec_read_check(codec, 0x40, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 722); // 0x040f0009
//      snd_hda:     64 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x40, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 723); // 0x040f000f
        retval = snd_hda_codec_read_check(codec, 0x40, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 724); // 0x040f0012
//      snd_hda:     amp capabilities 64 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x40, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 725); // 0x040f000d
//      snd_hda:     amp capabilities 64 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x40, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 726); // 0x040f0009
//      snd_hda:     64 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x40, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 727); // 0x040f1c00
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x40, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000020, 728); // 0x040f000c
//      snd_hda:     64 ['AC_PINCAP_IN'] []
        retval = snd_hda_codec_read_check(codec, 0x40, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 729); // 0x040f0700
        snd_hda_codec_write(codec, 0x40, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x04070700
//      snd_hda:     64 []

        retval = snd_hda_codec_read_check(codec, 0x41, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 732); // 0x041f0005
        retval = snd_hda_codec_read_check(codec, 0x41, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 733); // 0x041f0009
//      snd_hda:     65 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x41, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 734); // 0x041f000f
        retval = snd_hda_codec_read_check(codec, 0x41, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 735); // 0x041f0012
//      snd_hda:     amp capabilities 65 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x41, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 736); // 0x041f000d
//      snd_hda:     amp capabilities 65 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x41, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 737); // 0x041f0009
//      snd_hda:     65 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x41, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 738); // 0x041f1c00
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x41, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000020, 739); // 0x041f000c
//      snd_hda:     65 ['AC_PINCAP_IN'] []
        retval = snd_hda_codec_read_check(codec, 0x41, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 740); // 0x041f0700
        snd_hda_codec_write(codec, 0x41, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x04170700
//      snd_hda:     65 []

        retval = snd_hda_codec_read_check(codec, 0x42, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 743); // 0x042f0005
        retval = snd_hda_codec_read_check(codec, 0x42, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 744); // 0x042f0009
//      snd_hda:     66 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x42, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 745); // 0x042f000f
        retval = snd_hda_codec_read_check(codec, 0x42, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 746); // 0x042f0012
//      snd_hda:     amp capabilities 66 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x42, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 747); // 0x042f000d
//      snd_hda:     amp capabilities 66 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x42, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 748); // 0x042f0009
//      snd_hda:     66 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x42, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 749); // 0x042f1c00
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x42, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000020, 750); // 0x042f000c
//      snd_hda:     66 ['AC_PINCAP_IN'] []
        retval = snd_hda_codec_read_check(codec, 0x42, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 751); // 0x042f0700
        snd_hda_codec_write(codec, 0x42, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x04270700
//      snd_hda:     66 []

        retval = snd_hda_codec_read_check(codec, 0x43, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 754); // 0x043f0005
        retval = snd_hda_codec_read_check(codec, 0x43, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 755); // 0x043f0009
//      snd_hda:     67 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x43, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 756); // 0x043f000f
        retval = snd_hda_codec_read_check(codec, 0x43, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 757); // 0x043f0012
//      snd_hda:     amp capabilities 67 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x43, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 758); // 0x043f000d
//      snd_hda:     amp capabilities 67 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x43, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00400001, 759); // 0x043f0009
//      snd_hda:     67 AC_WID_PIN ['AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_STEREO', 'AC_WCAP_TYPE'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x43, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 760); // 0x043f1c00
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x43, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000020, 761); // 0x043f000c
//      snd_hda:     67 ['AC_PINCAP_IN'] []
        retval = snd_hda_codec_read_check(codec, 0x43, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 762); // 0x043f0700
        snd_hda_codec_write(codec, 0x43, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x04370700
//      snd_hda:     67 []

        retval = snd_hda_codec_read_check(codec, 0x44, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 765); // 0x044f0005
        retval = snd_hda_codec_read_check(codec, 0x44, 0, AC_VERB_PARAMETERS, 0x00000009, 0x0040000b, 766); // 0x044f0009
//      snd_hda:     68 AC_WID_PIN ['AC_WCAP_STEREO', 'AC_WCAP_AMP_OVRD', 'AC_WCAP_TYPE', 'AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_IN_AMP'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x44, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 767); // 0x044f000f
        retval = snd_hda_codec_read_check(codec, 0x44, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 768); // 0x044f0012
//      snd_hda:     amp capabilities 68 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x44, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00270200, 769); // 0x044f000d
//      snd_hda:     amp capabilities 68 input  0x00270200 offset 0x00 numsteps 0x02 stepsize 0x27 mute 0
        retval = snd_hda_codec_read_check(codec, 0x44, 0, AC_VERB_PARAMETERS, 0x00000009, 0x0040000b, 770); // 0x044f0009
//      snd_hda:     68 AC_WID_PIN ['AC_WCAP_STEREO', 'AC_WCAP_AMP_OVRD', 'AC_WCAP_TYPE', 'AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_IN_AMP'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x44, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0xa0a60100, 771); // 0x044f1c00
//      snd_hda:     pin config default 0xa0a60100 port conn 2 location 0x20 loc ext 2 loc geom 0 default device 10 conn type 6 color 0 misc 1 def assoc 0 seq 0
//      snd_hda:     pin config default 0xa0a60100 port conn Fixed loc ext Sep loc geom N/A default device Mic In conn type Other Digital color Unknown misc Jack Detect Override def assoc 0 seq 0
        retval = snd_hda_codec_read_check(codec, 0x44, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000020, 772); // 0x044f000c
//      snd_hda:     68 ['AC_PINCAP_IN'] []
        retval = snd_hda_codec_read_check(codec, 0x44, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00270200, 773); // 0x044f000d
//      snd_hda:     amp capabilities 68 input  0x00270200 offset 0x00 numsteps 0x02 stepsize 0x27 mute 0
        retval = snd_hda_codec_read_check(codec, 0x44, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 774); // 0x044f0700
        snd_hda_codec_write(codec, 0x44, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x04470700
//      snd_hda:     68 []

        retval = snd_hda_codec_read_check(codec, 0x45, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 777); // 0x045f0005
        retval = snd_hda_codec_read_check(codec, 0x45, 0, AC_VERB_PARAMETERS, 0x00000009, 0x0040000b, 778); // 0x045f0009
//      snd_hda:     69 AC_WID_PIN ['AC_WCAP_STEREO', 'AC_WCAP_AMP_OVRD', 'AC_WCAP_TYPE', 'AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_IN_AMP'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x45, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 779); // 0x045f000f
        retval = snd_hda_codec_read_check(codec, 0x45, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 780); // 0x045f0012
//      snd_hda:     amp capabilities 69 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x45, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00270200, 781); // 0x045f000d
//      snd_hda:     amp capabilities 69 input  0x00270200 offset 0x00 numsteps 0x02 stepsize 0x27 mute 0
        retval = snd_hda_codec_read_check(codec, 0x45, 0, AC_VERB_PARAMETERS, 0x00000009, 0x0040000b, 782); // 0x045f0009
//      snd_hda:     69 AC_WID_PIN ['AC_WCAP_STEREO', 'AC_WCAP_AMP_OVRD', 'AC_WCAP_TYPE', 'AC_WCAP_DELAY', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_IN_AMP'] 0 0 4
        retval = snd_hda_codec_read_check(codec, 0x45, 0, AC_VERB_GET_CONFIG_DEFAULT, 0x00000000, 0x400000f0, 783); // 0x045f1c00
//      snd_hda:     pin config default 0x400000f0 port conn 1 location 0x0 loc ext 0 loc geom 0 default device 0 conn type 0 color 0 misc 0 def assoc 15 seq 0
//      snd_hda:     pin config default 0x400000f0 port conn NO CONN loc ext Ext loc geom N/A default device Line Out conn type Unknown color Unknown misc undef def assoc 15 seq 0
        retval = snd_hda_codec_read_check(codec, 0x45, 0, AC_VERB_PARAMETERS, 0x0000000c, 0x00000020, 784); // 0x045f000c
//      snd_hda:     69 ['AC_PINCAP_IN'] []
        retval = snd_hda_codec_read_check(codec, 0x45, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00270200, 785); // 0x045f000d
//      snd_hda:     amp capabilities 69 input  0x00270200 offset 0x00 numsteps 0x02 stepsize 0x27 mute 0
        retval = snd_hda_codec_read_check(codec, 0x45, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 786); // 0x045f0700
        snd_hda_codec_write(codec, 0x45, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x04570700
//      snd_hda:     69 []

        retval = snd_hda_codec_read_check(codec, 0x46, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 789); // 0x046f0005
        retval = snd_hda_codec_read_check(codec, 0x46, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00700200, 790); // 0x046f0009
//      snd_hda:     70 AC_WID_BEEP ['AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_DELAY', 'AC_WCAP_DIGITAL', 'AC_WCAP_TYPE'] 0 0 7
        retval = snd_hda_codec_read_check(codec, 0x46, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 791); // 0x046f000f
        retval = snd_hda_codec_read_check(codec, 0x46, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 792); // 0x046f0012
//      snd_hda:     amp capabilities 70 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x46, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 793); // 0x046f000d
//      snd_hda:     amp capabilities 70 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x46, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00700200, 794); // 0x046f0009
//      snd_hda:     70 AC_WID_BEEP ['AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_DELAY', 'AC_WCAP_DIGITAL', 'AC_WCAP_TYPE'] 0 0 7

        snd_hda_codec_write(codec, 0x46, 0, AC_VERB_SET_BEEP_CONTROL, 0x00000000); // 0x04670a00

}

static void read_vendor_node_ssm3(struct hda_codec *codec)
{
        int retval;

        // I think this is also part of the node init loop

        // this may involve calls to AppleHDAWidgetCS8409::initForNodeID for each node
        // and AppleHDAWidget::initForNodeID(unsigned short, OSObject*, OSObject*)  for each node

        retval = snd_hda_codec_read_check(codec, CS8409_VENDOR_NID, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 797); // 0x047f0005
        retval = snd_hda_codec_read_check(codec, CS8409_VENDOR_NID, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00f002c1, 798); // 0x047f0009
//      snd_hda:     71 AC_WID_VENDOR ['AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_UNSOL_CAP', 'AC_WCAP_DELAY', 'AC_WCAP_PROC_WID', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_DIGITAL'] 0 0 15

        retval = snd_hda_codec_read_check(codec, CS8409_VENDOR_NID, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 799); // 0x047f000f
        retval = snd_hda_codec_read_check(codec, CS8409_VENDOR_NID, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 800); // 0x047f0012
//      snd_hda:     amp capabilities 71 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, CS8409_VENDOR_NID, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 801); // 0x047f000d
//      snd_hda:     amp capabilities 71 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, CS8409_VENDOR_NID, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00f002c1, 802); // 0x047f0009
//      snd_hda:     71 AC_WID_VENDOR ['AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_UNSOL_CAP', 'AC_WCAP_DELAY', 'AC_WCAP_PROC_WID', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_DIGITAL'] 0 0 15

}

static void read_coefs_all_ssm3(struct hda_codec *codec);

static void init_read_coefs_ssm3(struct hda_codec *codec)
{

        int retval;

        // get number of coefs in bits 15:8 - here 0x0000ff00 ie 255
        retval = snd_hda_codec_read_check(codec, CS8409_VENDOR_NID, 0, AC_VERB_PARAMETERS, 0x00000010, 0x0000ff00, 803); // 0x047f0010


        // this is after the read_all_nodes loop

        read_coefs_all_ssm3(codec);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}

static void read_coefs_all_ssm3(struct hda_codec *codec)
{

        // leave these in as check of state

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 804 ); //   coef read 804
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000000, 808 ); //   coef read 808
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0002, 0x0000, 0x00000080, 812 ); //   coef read 812
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0003, 0x0000, 0x0000801f, 816 ); //   coef read 816
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0004, 0x0000, 0x0000083f, 820 ); //   coef read 820
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0005, 0x0000, 0x00000000, 824 ); //   coef read 824
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0006, 0x0000, 0x00008000, 828 ); //   coef read 828
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0007, 0x0000, 0x000028ff, 832 ); //   coef read 832
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0008, 0x0000, 0x00000000, 836 ); //   coef read 836
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0009, 0x0000, 0x00000013, 840 ); //   coef read 840
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x000a, 0x0000, 0x00000000, 844 ); //   coef read 844
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x000b, 0x0000, 0x00000000, 848 ); //   coef read 848
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x000c, 0x0000, 0x0000cccc, 852 ); //   coef read 852
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x000d, 0x0000, 0x0000cccc, 856 ); //   coef read 856
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x000e, 0x0000, 0x00000000, 860 ); //   coef read 860
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x000f, 0x0000, 0x0000aaaa, 864 ); //   coef read 864
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0010, 0x0000, 0x0000cccc, 868 ); //   coef read 868
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0011, 0x0000, 0x00000000, 872 ); //   coef read 872
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0012, 0x0000, 0x0000cccc, 876 ); //   coef read 876
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0013, 0x0000, 0x0000cccc, 880 ); //   coef read 880
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0014, 0x0000, 0x00000000, 884 ); //   coef read 884
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0015, 0x0000, 0x0000aaaa, 888 ); //   coef read 888
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0016, 0x0000, 0x0000cccc, 892 ); //   coef read 892
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0017, 0x0000, 0x00000000, 896 ); //   coef read 896
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0018, 0x0000, 0x00000000, 900 ); //   coef read 900
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00000400, 904 ); //   coef read 904
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001a, 0x0000, 0x00000420, 908 ); //   coef read 908
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001b, 0x0000, 0x00008c20, 912 ); //   coef read 912
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001c, 0x0000, 0x00008000, 916 ); //   coef read 916
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001d, 0x0000, 0x00008c40, 920 ); //   coef read 920
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001e, 0x0000, 0x00008000, 924 ); //   coef read 924
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001f, 0x0000, 0x00008c60, 928 ); //   coef read 928
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0020, 0x0000, 0x00008000, 932 ); //   coef read 932
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0021, 0x0000, 0x00008000, 936 ); //   coef read 936
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0022, 0x0000, 0x00008000, 940 ); //   coef read 940
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0023, 0x0000, 0x00008000, 944 ); //   coef read 944
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0024, 0x0000, 0x00008000, 948 ); //   coef read 948
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0025, 0x0000, 0x00008000, 952 ); //   coef read 952
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0026, 0x0000, 0x00008000, 956 ); //   coef read 956
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0027, 0x0000, 0x00008000, 960 ); //   coef read 960
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0028, 0x0000, 0x00008000, 964 ); //   coef read 964
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0029, 0x0000, 0x00008000, 968 ); //   coef read 968
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002a, 0x0000, 0x00008000, 972 ); //   coef read 972
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002b, 0x0000, 0x00008000, 976 ); //   coef read 976
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002c, 0x0000, 0x00008000, 980 ); //   coef read 980
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002d, 0x0000, 0x00008000, 984 ); //   coef read 984
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002e, 0x0000, 0x00008000, 988 ); //   coef read 988
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002f, 0x0000, 0x00008000, 992 ); //   coef read 992
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0030, 0x0000, 0x00008000, 996 ); //   coef read 996
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0031, 0x0000, 0x00008000, 1000 ); //   coef read 1000
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0032, 0x0000, 0x00008000, 1004 ); //   coef read 1004
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0033, 0x0000, 0x00008000, 1008 ); //   coef read 1008
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0034, 0x0000, 0x00008000, 1012 ); //   coef read 1012
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0035, 0x0000, 0x00008000, 1016 ); //   coef read 1016
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0036, 0x0000, 0x00008000, 1020 ); //   coef read 1020
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0037, 0x0000, 0x00008000, 1024 ); //   coef read 1024
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0038, 0x0000, 0x00008000, 1028 ); //   coef read 1028
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0039, 0x0000, 0x00008000, 1032 ); //   coef read 1032
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003a, 0x0000, 0x00008000, 1036 ); //   coef read 1036
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003b, 0x0000, 0x00008000, 1040 ); //   coef read 1040
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003c, 0x0000, 0x00008000, 1044 ); //   coef read 1044
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003d, 0x0000, 0x00008000, 1048 ); //   coef read 1048
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003e, 0x0000, 0x00008000, 1052 ); //   coef read 1052
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003f, 0x0000, 0x00008000, 1056 ); //   coef read 1056
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0040, 0x0000, 0x00008000, 1060 ); //   coef read 1060
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0041, 0x0000, 0x00008000, 1064 ); //   coef read 1064
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0042, 0x0000, 0x00008000, 1068 ); //   coef read 1068
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0043, 0x0000, 0x00008000, 1072 ); //   coef read 1072
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0044, 0x0000, 0x00008000, 1076 ); //   coef read 1076
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0045, 0x0000, 0x00008000, 1080 ); //   coef read 1080
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0046, 0x0000, 0x00008000, 1084 ); //   coef read 1084
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0047, 0x0000, 0x00008000, 1088 ); //   coef read 1088
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0048, 0x0000, 0x00008000, 1092 ); //   coef read 1092
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0049, 0x0000, 0x00008000, 1096 ); //   coef read 1096
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004a, 0x0000, 0x00008000, 1100 ); //   coef read 1100
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004b, 0x0000, 0x00008000, 1104 ); //   coef read 1104
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004c, 0x0000, 0x00008000, 1108 ); //   coef read 1108
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004d, 0x0000, 0x00008000, 1112 ); //   coef read 1112
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004e, 0x0000, 0x00008000, 1116 ); //   coef read 1116
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004f, 0x0000, 0x00008000, 1120 ); //   coef read 1120
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0050, 0x0000, 0x00008000, 1124 ); //   coef read 1124
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0051, 0x0000, 0x00008000, 1128 ); //   coef read 1128
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0052, 0x0000, 0x00008000, 1132 ); //   coef read 1132
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0053, 0x0000, 0x00008000, 1136 ); //   coef read 1136
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0054, 0x0000, 0x00008000, 1140 ); //   coef read 1140
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0055, 0x0000, 0x00008000, 1144 ); //   coef read 1144
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0056, 0x0000, 0x00008000, 1148 ); //   coef read 1148
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0057, 0x0000, 0x00008000, 1152 ); //   coef read 1152
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0058, 0x0000, 0x00000400, 1156 ); //   coef read 1156
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0059, 0x0000, 0x0000002e, 1160 ); //   coef read 1160
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005a, 0x0000, 0x00000000, 1164 ); //   coef read 1164
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005b, 0x0000, 0x00000010, 1168 ); //   coef read 1168
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000020, 1172 ); //   coef read 1172
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005d, 0x0000, 0x00000380, 1176 ); //   coef read 1176
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00001000, 1180 ); //   coef read 1180
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005f, 0x0000, 0x00001600, 1184 ); //   coef read 1184
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0060, 0x0000, 0x00000000, 1188 ); //   coef read 1188
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0061, 0x0000, 0x00000000, 1192 ); //   coef read 1192
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0062, 0x0000, 0x00000000, 1196 ); //   coef read 1196
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0063, 0x0000, 0x00000000, 1200 ); //   coef read 1200
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0064, 0x0000, 0x00000000, 1204 ); //   coef read 1204
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0065, 0x0000, 0x00000000, 1208 ); //   coef read 1208
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0066, 0x0000, 0x00000000, 1212 ); //   coef read 1212
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0067, 0x0000, 0x00000000, 1216 ); //   coef read 1216
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0068, 0x0000, 0x00000000, 1220 ); //   coef read 1220
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0069, 0x0000, 0x00000000, 1224 ); //   coef read 1224
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x006a, 0x0000, 0x00000000, 1228 ); //   coef read 1228
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x006b, 0x0000, 0x00000000, 1232 ); //   coef read 1232
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x006c, 0x0000, 0x00000000, 1236 ); //   coef read 1236
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x006d, 0x0000, 0x00000000, 1240 ); //   coef read 1240
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x006e, 0x0000, 0x00000000, 1244 ); //   coef read 1244
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x006f, 0x0000, 0x00000000, 1248 ); //   coef read 1248
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0070, 0x0000, 0x00000000, 1252 ); //   coef read 1252
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x00000000, 1256 ); //   coef read 1256
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0072, 0x0000, 0x00000000, 1260 ); //   coef read 1260
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0073, 0x0000, 0x00000000, 1264 ); //   coef read 1264
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0074, 0x0000, 0x00000000, 1268 ); //   coef read 1268
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0075, 0x0000, 0x00000001, 1272 ); //   coef read 1272
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0076, 0x0000, 0x00000009, 1276 ); //   coef read 1276
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0077, 0x0000, 0x00000000, 1280 ); //   coef read 1280
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0078, 0x0000, 0x00000000, 1284 ); //   coef read 1284
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0079, 0x0000, 0x00000000, 1288 ); //   coef read 1288
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x007a, 0x0000, 0x00000000, 1292 ); //   coef read 1292
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x007b, 0x0000, 0x00000000, 1296 ); //   coef read 1296
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x007c, 0x0000, 0x00000000, 1300 ); //   coef read 1300
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x007d, 0x0000, 0x00000000, 1304 ); //   coef read 1304
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x007e, 0x0000, 0x00000000, 1308 ); //   coef read 1308
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x007f, 0x0000, 0x00000000, 1312 ); //   coef read 1312
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0080, 0x0000, 0x00000000, 1316 ); //   coef read 1316
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0081, 0x0000, 0x00000000, 1320 ); //   coef read 1320
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0082, 0x0000, 0x0000ff00, 1324 ); //   coef read 1324

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}

static void read_virtual_widgets_ssm3(struct hda_codec *codec)
{
       // setup the virtual widgets

        unsigned int retval;

        dev_info(hda_codec_dev(codec), "command nid start read_virtual_widgets\n");

        // copied to outer routine
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        // moved to outer routine
        //snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301

        retval = snd_hda_codec_read_check(codec, 0x48, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 1335); // 0x048f0005
        retval = snd_hda_codec_read_check(codec, 0x48, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00000000, 1336); // 0x048f0009
//      snd_hda:     72 AC_WID_AUD_OUT ['AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_DELAY', 'AC_WCAP_TYPE'] 0 0 0
        retval = snd_hda_codec_read_check(codec, 0x48, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 1337); // 0x048f000f
        retval = snd_hda_codec_read_check(codec, 0x48, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 1338); // 0x048f000a
//      snd_hda:     pcm params           72 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x48, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 1339); // 0x048f000b
//      snd_hda:     stream format params 72 
        retval = snd_hda_codec_read_check(codec, 0x48, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 1340); // 0x048f0012
//      snd_hda:     amp capabilities 72 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x48, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 1341); // 0x048f000d
//      snd_hda:     amp capabilities 72 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x48, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00000000, 1342); // 0x048f0009
//      snd_hda:     72 AC_WID_AUD_OUT ['AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_DELAY', 'AC_WCAP_TYPE'] 0 0 0
        retval = snd_hda_codec_read_check(codec, 0x49, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 1344); // 0x049f0005
        retval = snd_hda_codec_read_check(codec, 0x49, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00000000, 1345); // 0x049f0009
//      snd_hda:     73 AC_WID_AUD_OUT ['AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_DELAY', 'AC_WCAP_TYPE'] 0 0 0
        retval = snd_hda_codec_read_check(codec, 0x49, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 1346); // 0x049f000f
        retval = snd_hda_codec_read_check(codec, 0x49, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 1347); // 0x049f000a
//      snd_hda:     pcm params           73 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x49, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 1348); // 0x049f000b
//      snd_hda:     stream format params 73 
        retval = snd_hda_codec_read_check(codec, 0x49, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 1349); // 0x049f0012
//      snd_hda:     amp capabilities 73 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x49, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 1350); // 0x049f000d
//      snd_hda:     amp capabilities 73 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x49, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00000000, 1351); // 0x049f0009
//      snd_hda:     73 AC_WID_AUD_OUT ['AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_DELAY', 'AC_WCAP_TYPE'] 0 0 0
        retval = snd_hda_codec_read_check(codec, 0x4a, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 1353); // 0x04af0005
        retval = snd_hda_codec_read_check(codec, 0x4a, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00000000, 1354); // 0x04af0009
//      snd_hda:     74 AC_WID_AUD_OUT ['AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_DELAY', 'AC_WCAP_TYPE'] 0 0 0
        retval = snd_hda_codec_read_check(codec, 0x4a, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 1355); // 0x04af000f
        retval = snd_hda_codec_read_check(codec, 0x4a, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 1356); // 0x04af000a
//      snd_hda:     pcm params           74 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x4a, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 1357); // 0x04af000b
//      snd_hda:     stream format params 74 
        retval = snd_hda_codec_read_check(codec, 0x4a, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 1358); // 0x04af0012
//      snd_hda:     amp capabilities 74 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x4a, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 1359); // 0x04af000d
//      snd_hda:     amp capabilities 74 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x4a, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00000000, 1360); // 0x04af0009
//      snd_hda:     74 AC_WID_AUD_OUT ['AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_DELAY', 'AC_WCAP_TYPE'] 0 0 0
        retval = snd_hda_codec_read_check(codec, 0x4b, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 1362); // 0x04bf0005
        retval = snd_hda_codec_read_check(codec, 0x4b, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00000000, 1363); // 0x04bf0009
//      snd_hda:     75 AC_WID_AUD_OUT ['AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_DELAY', 'AC_WCAP_TYPE'] 0 0 0
        retval = snd_hda_codec_read_check(codec, 0x4b, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 1364); // 0x04bf000f
        retval = snd_hda_codec_read_check(codec, 0x4b, 0, AC_VERB_PARAMETERS, 0x0000000a, 0x00000000, 1365); // 0x04bf000a
//      snd_hda:     pcm params           75 bits:  rates: 
        retval = snd_hda_codec_read_check(codec, 0x4b, 0, AC_VERB_PARAMETERS, 0x0000000b, 0x00000000, 1366); // 0x04bf000b
//      snd_hda:     stream format params 75 
        retval = snd_hda_codec_read_check(codec, 0x4b, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 1367); // 0x04bf0012
//      snd_hda:     amp capabilities 75 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x4b, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 1368); // 0x04bf000d
//      snd_hda:     amp capabilities 75 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, 0x4b, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00000000, 1369); // 0x04bf0009
//      snd_hda:     75 AC_WID_AUD_OUT ['AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_DELAY', 'AC_WCAP_TYPE'] 0 0 0


        dev_info(hda_codec_dev(codec), "command nid end   read_virtual_widgets\n");

}

static void init_for_node_id_ssm3(struct hda_codec *codec)
{

        int retval;

        //int retwake;
        //int retunsol;

        // all in AppleHDAFunctionGroupCS4208::initForNodeID


        dev_info(hda_codec_dev(codec), "command nid init_for_node_id\n");

        // these 2 items seem to enable the i2c clock - but we havent enabled i2c yet!!
        // whats the difference??
        // Im certain this is enabling the i2c clock
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1371 ); //   coef read 1371
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1375 ); //   coef write 1375

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000000, 1379 ); //   coef read 1379
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000000, 1383 ); //   coef write 1383
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0017, 0x0000, 0x00000000, 1387 ); //   coef write 1387
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0018, 0x0000, 0x00000000, 1391 ); //   coef write 1391
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0002, 0x0000, 0x00000000, 1395 ); //   coef write 1395

        // this is done as a loop over a fixed number of indexes (0x57)
        // the loop terminates when a non-signed value is returned ie the word sign bit (0x8000) is not set
        // or finish all 0x57

        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0019, 0x8000, 0x00000000, 1399 ); //   coef write 1399
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001a, 0x8000, 0x00000000, 1403 ); //   coef write 1403
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001b, 0x8000, 0x00000000, 1407 ); //   coef write 1407
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001c, 0x8000, 0x00000000, 1411 ); //   coef write 1411
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001d, 0x8000, 0x00000000, 1415 ); //   coef write 1415
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001e, 0x8000, 0x00000000, 1419 ); //   coef write 1419
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001f, 0x8000, 0x00000000, 1423 ); //   coef write 1423
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0020, 0x8000, 0x00000000, 1427 ); //   coef write 1427
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0021, 0x8000, 0x00000000, 1431 ); //   coef write 1431
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0022, 0x8000, 0x00000000, 1435 ); //   coef write 1435
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0023, 0x8000, 0x00000000, 1439 ); //   coef write 1439
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0024, 0x8000, 0x00000000, 1443 ); //   coef write 1443
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0025, 0x8000, 0x00000000, 1447 ); //   coef write 1447
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0026, 0x8000, 0x00000000, 1451 ); //   coef write 1451
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0027, 0x8000, 0x00000000, 1455 ); //   coef write 1455
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0028, 0x8000, 0x00000000, 1459 ); //   coef write 1459
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0029, 0x8000, 0x00000000, 1463 ); //   coef write 1463
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x002a, 0x8000, 0x00000000, 1467 ); //   coef write 1467
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x002b, 0x8000, 0x00000000, 1471 ); //   coef write 1471
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x002c, 0x8000, 0x00000000, 1475 ); //   coef write 1475
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x002d, 0x8000, 0x00000000, 1479 ); //   coef write 1479
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x002e, 0x8000, 0x00000000, 1483 ); //   coef write 1483
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x002f, 0x8000, 0x00000000, 1487 ); //   coef write 1487
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0030, 0x8000, 0x00000000, 1491 ); //   coef write 1491
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0031, 0x8000, 0x00000000, 1495 ); //   coef write 1495
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0032, 0x8000, 0x00000000, 1499 ); //   coef write 1499
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0033, 0x8000, 0x00000000, 1503 ); //   coef write 1503
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0034, 0x8000, 0x00000000, 1507 ); //   coef write 1507
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0035, 0x8000, 0x00000000, 1511 ); //   coef write 1511
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0036, 0x8000, 0x00000000, 1515 ); //   coef write 1515
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0037, 0x8000, 0x00000000, 1519 ); //   coef write 1519
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0038, 0x8000, 0x00000000, 1523 ); //   coef write 1523
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0039, 0x8000, 0x00000000, 1527 ); //   coef write 1527
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x003a, 0x8000, 0x00000000, 1531 ); //   coef write 1531
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x003b, 0x8000, 0x00000000, 1535 ); //   coef write 1535
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x003c, 0x8000, 0x00000000, 1539 ); //   coef write 1539
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x003d, 0x8000, 0x00000000, 1543 ); //   coef write 1543
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x003e, 0x8000, 0x00000000, 1547 ); //   coef write 1547
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x003f, 0x8000, 0x00000000, 1551 ); //   coef write 1551
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0040, 0x8000, 0x00000000, 1555 ); //   coef write 1555
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0041, 0x8000, 0x00000000, 1559 ); //   coef write 1559
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0042, 0x8000, 0x00000000, 1563 ); //   coef write 1563
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0043, 0x8000, 0x00000000, 1567 ); //   coef write 1567
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0044, 0x8000, 0x00000000, 1571 ); //   coef write 1571
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0045, 0x8000, 0x00000000, 1575 ); //   coef write 1575
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0046, 0x8000, 0x00000000, 1579 ); //   coef write 1579
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0047, 0x8000, 0x00000000, 1583 ); //   coef write 1583
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0048, 0x8000, 0x00000000, 1587 ); //   coef write 1587
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0049, 0x8000, 0x00000000, 1591 ); //   coef write 1591
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x004a, 0x8000, 0x00000000, 1595 ); //   coef write 1595
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x004b, 0x8000, 0x00000000, 1599 ); //   coef write 1599
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x004c, 0x8000, 0x00000000, 1603 ); //   coef write 1603
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x004d, 0x8000, 0x00000000, 1607 ); //   coef write 1607
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x004e, 0x8000, 0x00000000, 1611 ); //   coef write 1611
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x004f, 0x8000, 0x00000000, 1615 ); //   coef write 1615
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0050, 0x8000, 0x00000000, 1619 ); //   coef write 1619
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0051, 0x8000, 0x00000000, 1623 ); //   coef write 1623
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0052, 0x8000, 0x00000000, 1627 ); //   coef write 1627
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0053, 0x8000, 0x00000000, 1631 ); //   coef write 1631
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0054, 0x8000, 0x00000000, 1635 ); //   coef write 1635
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0055, 0x8000, 0x00000000, 1639 ); //   coef write 1639
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0056, 0x8000, 0x00000000, 1643 ); //   coef write 1643
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0057, 0x8000, 0x00000000, 1647 ); //   coef write 1647

        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x000a, 0x0000, 0x00000000, 1651 ); //   coef write 1651
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0082, 0x0000, 0x00000000, 1655 ); //   coef write 1655
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006b, 0x001f, 0x00000000, 1659 ); //   coef write 1659
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006c, 0x001f, 0x00000000, 1663 ); //   coef write 1663
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0082, 0x0000, 0x00000000, 1667 ); //   coef write 1667

        // this is determineSpeakerID
        // this does not make sense - this just checks a GPIO pin??

        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_MASK, 0x00000008); // 0x00171608
//      snd_hda:     gpio enable 1 0x08

        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_GPIO_DATA, 0x00000000, 0x00000008, 1672); // 0x001f1500
//      snd_hda:     gpio data 1 0x08

        // curious this gpio processing is duplicated in SSM3515

        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_MASK, 0x0000000c); // 0x0017160c
//      snd_hda:     gpio enable 1 0x0c

        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_GPIO_DATA, 0x00000000, 0x0000000c, 1674); // 0x001f1500
//      snd_hda:     gpio data 1 0x0c

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}

// this function seems to be completely missing
//static void setup_jack_pin_config_ssm3(struct hda_codec *codec)

static void enable_i2c_ssm3(struct hda_codec *codec)
{
        //int retval;

        // AppleBusControllerCS8409::init

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301

//      snd_hda: # AppleHDAFunctionGroupCS8409::enableI2C: 
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1689 ); // AppleHDAFunctionGroupCS8409::enableI2C  coef read 1689
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1693 ); // AppleHDAFunctionGroupCS8409::enableI2C  coef write 1693

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0002, 0x0000, 0x00000000, 1697 ); // AppleHDAFunctionGroupCS8409::enableI2C  coef read 1697
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0002, 0x0080, 0x00000000, 1701 ); // AppleHDAFunctionGroupCS8409::enableI2C  coef write 1701
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0002, 0x0000, 0x00000080, 1705 ); // AppleHDAFunctionGroupCS8409::enableI2C  coef read 1705
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005b, 0x0000, 0x00000010, 1709 ); // AppleHDAFunctionGroupCS8409::enableI2C  coef read 1709
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005b, 0x0010, 0x00000000, 1713 ); // AppleHDAFunctionGroupCS8409::enableI2C  coef write 1713

//      snd_hda: # AppleHDAFunctionGroupCS8409::enableI2CClock:
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1717 ); // AppleHDAFunctionGroupCS8409::enableI2C  coef read 1717
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1721 ); // AppleHDAFunctionGroupCS8409::enableI2C  coef write 1721

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}


static void enable_GPIforUR_ssm3(struct hda_codec *codec)
{
        int retval;

        // AppleHDAFunctionGroup::enableGPIforUR
        // possibly from AppleHDAFunctionGroupCS8409::setCodecSpecificXML


        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        // BIG CHANGE - 0x05 for max 0x0d here for SSM3s

        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_MASK, 0x0000000d); // 0x0017160d
//      snd_hda:     gpio enable 1 0x0d

        // this is AppleHDAFunctionGroup::setGPIODirection in AppleHDAFunctionGroup::enableGPIforUR
        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DIRECTION, 0x00000000); // 0x00171700
//      snd_hda:     gpio direction 1 0x00 in in in in in in in in

        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_GPIO_WAKE_MASK, 0x00000000, 0x00000000, 1733); // 0x001f1800
//      snd_hda:     gpio wake enable 1 0x00
        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_WAKE_MASK, 0x00000001); // 0x00171801
//      snd_hda:     gpio wake enable 1 0x01
        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_GPIO_UNSOLICITED_RSP_MASK, 0x00000000, 0x00000000, 1735); // 0x001f1900
//      snd_hda:     gpio unsol enable 1 0x00
        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_UNSOLICITED_RSP_MASK, 0x00000001); // 0x00171901
//      snd_hda:     gpio unsol enable 1 0x01

        // likely last runVerb of AppleHDAFunctionGroupCS8409::enableGPIforUR
        snd_hda_codec_write(codec, codec->core.afg, 0, 0x7f0, 0x000000b7);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}

static void external_control_GPIO_clear_2_ssm3(struct hda_codec *codec);
static void external_control_GPIO_set_2_ssm3(struct hda_codec *codec);

static void external_control_GPIO_ssm3(struct hda_codec *codec)
{
        // very unsure about this but this could be setting up the GPIO for the headphone jack
        // based on proximity to headphone/mic setup


        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301

        // this clearing then setting gpio bit 2
        // note the gpio mask value here is 0xf cf. the MAX system 0x7

        external_control_GPIO_clear_2_ssm3(codec);

        external_control_GPIO_set_2_ssm3(codec);

}


static void external_control_GPIO_clear_2_ssm3(struct hda_codec *codec)
{

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        // plausibly AppleHDAFunctionGroupExternalControl_GPIO::publicSetExternalControlState(bool)

        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DIRECTION, 0x00000002); // 0x00171702
//      snd_hda:     gpio direction 1 0x02 in in in in in in out in

        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DATA, 0x00000000); // 0x00171500
//      snd_hda:     gpio data 1 0x00

        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_MASK, 0x0000000f); // 0x0017160f
//      snd_hda:     gpio enable 1 0x0f

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}

static void external_control_GPIO_set_2_ssm3(struct hda_codec *codec)
{

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        // plausibly AppleHDAFunctionGroupExternalControl_GPIO::publicSetExternalControlState(bool)

        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DIRECTION, 0x00000002); // 0x00171702
//      snd_hda:     gpio direction 1 0x02 in in in in in in out in

        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DATA, 0x00000002); // 0x00171502
//      snd_hda:     gpio data 1 0x02

        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_MASK, 0x0000000f); // 0x0017160f
//      snd_hda:     gpio enable 1 0x0f

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}

static void putative_setup_mic_ssm3(struct hda_codec *codec)
{



        // these are i2c calls
        // so it seems Apple is using SET_COEF_INDEX, SET_PROC_COEF to write to the local i2c bus
        // writing to coef index 0x59 for the i2c address, reading from 0x5c for i2c status
        // and writing to 0x5d for i2c register, data writes (8 bit each in the 16 bit coef data with register in hi byte)
        // and writing/reading to 0x5e for i2c register, data reads - the write is register with lo byte 0x00
        // and read is data for i2c register (i2c register returned) with data in lo byte

        // based on info from bugs 195671 and 110561
        // and that writing to coef index 0x59 seems to be the i2c address hence the i2c address is 0x90
        // this is likely setting up the headphone/mic jack ic CS42L83A


        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0100 i2c data 0x0100
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1301, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1767 ); // i2cPagedRead  coef read 1767
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1771 ); // i2cPagedRead  coef write 1771
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 1775 ); // i2cPagedRead  coef write 1775
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 1779 ); // i2cPagedRead  coef write 1779
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1783 ); // i2cPagedRead  coef read 1783
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0100, 0x00000000, 1787 ); // i2cPagedRead  coef write 1787
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1791 ); // i2cPagedRead  coef read 1791
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1795 ); // i2cPagedRead  coef read 1795
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000100, 1799 ); // i2cPagedRead  coef read 1799
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1803 ); // i2cPagedRead  coef read 1803
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1807 ); // i2cPagedRead  coef write 1807
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0200 i2c data 0x0200
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1302, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1818 ); // i2cPagedRead  coef read 1818
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1822 ); // i2cPagedRead  coef write 1822
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 1826 ); // i2cPagedRead  coef write 1826
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 1830 ); // i2cPagedRead  coef write 1830
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1834 ); // i2cPagedRead  coef read 1834
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0200, 0x00000000, 1838 ); // i2cPagedRead  coef write 1838
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1842 ); // i2cPagedRead  coef read 1842
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1846 ); // i2cPagedRead  coef read 1846
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000200, 1850 ); // i2cPagedRead  coef read 1850
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1854 ); // i2cPagedRead  coef read 1854
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1858 ); // i2cPagedRead  coef write 1858
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0300 i2c data 0x030c
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1303, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1869 ); // i2cPagedRead  coef read 1869
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1873 ); // i2cPagedRead  coef write 1873
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 1877 ); // i2cPagedRead  coef write 1877
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 1881 ); // i2cPagedRead  coef write 1881
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1885 ); // i2cPagedRead  coef read 1885
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0300, 0x00000000, 1889 ); // i2cPagedRead  coef write 1889
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1893 ); // i2cPagedRead  coef read 1893
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1897 ); // i2cPagedRead  coef read 1897
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x0000030c, 1901 ); // i2cPagedRead  coef read 1901
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1905 ); // i2cPagedRead  coef read 1905
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1909 ); // i2cPagedRead  coef write 1909
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0400 i2c data 0x0400
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1304, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1920 ); // i2cPagedRead  coef read 1920
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1924 ); // i2cPagedRead  coef write 1924
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 1928 ); // i2cPagedRead  coef write 1928
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 1932 ); // i2cPagedRead  coef write 1932
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1936 ); // i2cPagedRead  coef read 1936
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0400, 0x00000000, 1940 ); // i2cPagedRead  coef write 1940
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1944 ); // i2cPagedRead  coef read 1944
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1948 ); // i2cPagedRead  coef read 1948
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000400, 1952 ); // i2cPagedRead  coef read 1952
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1956 ); // i2cPagedRead  coef read 1956
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1960 ); // i2cPagedRead  coef write 1960
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0500 i2c data 0x0500
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1305, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1971 ); // i2cPagedRead  coef read 1971
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1975 ); // i2cPagedRead  coef write 1975
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 1979 ); // i2cPagedRead  coef write 1979
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 1983 ); // i2cPagedRead  coef write 1983
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1987 ); // i2cPagedRead  coef read 1987
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0500, 0x00000000, 1991 ); // i2cPagedRead  coef write 1991
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1995 ); // i2cPagedRead  coef read 1995
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1999 ); // i2cPagedRead  coef read 1999
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000500, 2003 ); // i2cPagedRead  coef read 2003
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2007 ); // i2cPagedRead  coef read 2007
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2011 ); // i2cPagedRead  coef write 2011
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0b00 i2c data 0x0b60
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x130b, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2022 ); // i2cPagedRead  coef read 2022
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2026 ); // i2cPagedRead  coef write 2026
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2030 ); // i2cPagedRead  coef write 2030
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 2034 ); // i2cPagedRead  coef write 2034
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2038 ); // i2cPagedRead  coef read 2038
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0b00, 0x00000000, 2042 ); // i2cPagedRead  coef write 2042
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2046 ); // i2cPagedRead  coef read 2046
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2050 ); // i2cPagedRead  coef read 2050
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000b60, 2054 ); // i2cPagedRead  coef read 2054
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2058 ); // i2cPagedRead  coef read 2058
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2062 ); // i2cPagedRead  coef write 2062
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0d00 i2c data 0x0d01
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x130d, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2073 ); // i2cPagedRead  coef read 2073
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2077 ); // i2cPagedRead  coef write 2077
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2081 ); // i2cPagedRead  coef write 2081
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 2085 ); // i2cPagedRead  coef write 2085
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2089 ); // i2cPagedRead  coef read 2089
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0d00, 0x00000000, 2093 ); // i2cPagedRead  coef write 2093
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2097 ); // i2cPagedRead  coef read 2097
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2101 ); // i2cPagedRead  coef read 2101
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000d01, 2105 ); // i2cPagedRead  coef read 2105
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2109 ); // i2cPagedRead  coef read 2109
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2113 ); // i2cPagedRead  coef write 2113
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0e00 i2c data 0x0e00
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x130e, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2124 ); // i2cPagedRead  coef read 2124
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2128 ); // i2cPagedRead  coef write 2128
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2132 ); // i2cPagedRead  coef write 2132
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 2136 ); // i2cPagedRead  coef write 2136
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2140 ); // i2cPagedRead  coef read 2140
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0e00, 0x00000000, 2144 ); // i2cPagedRead  coef write 2144
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2148 ); // i2cPagedRead  coef read 2148
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2152 ); // i2cPagedRead  coef read 2152
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000e00, 2156 ); // i2cPagedRead  coef read 2156
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2160 ); // i2cPagedRead  coef read 2160
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2164 ); // i2cPagedRead  coef write 2164
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0800 i2c data 0x0801
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1308, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2175 ); // i2cPagedRead  coef read 2175
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2179 ); // i2cPagedRead  coef write 2179
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2183 ); // i2cPagedRead  coef write 2183
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 2187 ); // i2cPagedRead  coef write 2187
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2191 ); // i2cPagedRead  coef read 2191
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0800, 0x00000000, 2195 ); // i2cPagedRead  coef write 2195
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2199 ); // i2cPagedRead  coef read 2199
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2203 ); // i2cPagedRead  coef read 2203
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000801, 2207 ); // i2cPagedRead  coef read 2207
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2211 ); // i2cPagedRead  coef read 2211
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2215 ); // i2cPagedRead  coef write 2215
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0f00 i2c data 0x0f00
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x130f, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2226 ); // i2cPagedRead  coef read 2226
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2230 ); // i2cPagedRead  coef write 2230
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2234 ); // i2cPagedRead  coef write 2234
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 2238 ); // i2cPagedRead  coef write 2238
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2242 ); // i2cPagedRead  coef read 2242
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0f00, 0x00000000, 2246 ); // i2cPagedRead  coef write 2246
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2250 ); // i2cPagedRead  coef read 2250
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2254 ); // i2cPagedRead  coef read 2254
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000f00, 2258 ); // i2cPagedRead  coef read 2258
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2262 ); // i2cPagedRead  coef read 2262
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2266 ); // i2cPagedRead  coef write 2266
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}

static void external_control_GPIO2_clear_2_ssm3(struct hda_codec *codec)
{

        // plausibly AppleHDAFunctionGroupExternalControl_GPIO::publicSetExternalControlState(bool)

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DIRECTION, 0x00000002); // 0x00171702
//      snd_hda:     gpio direction 1 0x02 in in in in in in out in

        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DATA, 0x00000000); // 0x00171500
//      snd_hda:     gpio data 1 0x00

        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_MASK, 0x0000000f); // 0x0017160f
//      snd_hda:     gpio enable 1 0x0f

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}

static void external_control_GPIO2_set_2_ssm3(struct hda_codec *codec)
{

        // plausibly AppleHDAFunctionGroupExternalControl_GPIO::publicSetExternalControlState(bool)

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DIRECTION, 0x00000002); // 0x00171702
//      snd_hda:     gpio direction 1 0x02 in in in in in in out in

        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DATA, 0x00000002); // 0x00171502
//      snd_hda:     gpio data 1 0x02

        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_MASK, 0x0000000f); // 0x0017160f
//      snd_hda:     gpio enable 1 0x0f

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}

static void putative_setup_mic2_ssm3(struct hda_codec *codec)
{

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x10 lo 0x0100 i2c data 0x0142
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2297 ); // i2cPagedRead  coef read 2297
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2301 ); // i2cPagedRead  coef write 2301
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2305 ); // i2cPagedRead  coef write 2305
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0010, 0x00000000, 2309 ); // i2cPagedRead  coef write 2309
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2313 ); // i2cPagedRead  coef read 2313
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0100, 0x00000000, 2317 ); // i2cPagedRead  coef write 2317
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2321 ); // i2cPagedRead  coef read 2321
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2325 ); // i2cPagedRead  coef read 2325
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000142, 2329 ); // i2cPagedRead  coef read 2329
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2333 ); // i2cPagedRead  coef read 2333
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2337 ); // i2cPagedRead  coef write 2337
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x10 lo 0x0500 i2c data 0x05b0
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1005, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2348 ); // i2cPagedRead  coef read 2348
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2352 ); // i2cPagedRead  coef write 2352
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2356 ); // i2cPagedRead  coef write 2356
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0010, 0x00000000, 2360 ); // i2cPagedRead  coef write 2360
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2364 ); // i2cPagedRead  coef read 2364
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0500, 0x00000000, 2368 ); // i2cPagedRead  coef write 2368
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2372 ); // i2cPagedRead  coef read 2372
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2376 ); // i2cPagedRead  coef read 2376
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x000005b0, 2380 ); // i2cPagedRead  coef read 2380
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2384 ); // i2cPagedRead  coef read 2384
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2388 ); // i2cPagedRead  coef write 2388
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x11 lo 0x0300 i2c data 0x0320
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1103, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2399 ); // i2cPagedRead  coef read 2399
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2403 ); // i2cPagedRead  coef write 2403
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2407 ); // i2cPagedRead  coef write 2407
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0011, 0x00000000, 2411 ); // i2cPagedRead  coef write 2411
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2415 ); // i2cPagedRead  coef read 2415
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0300, 0x00000000, 2419 ); // i2cPagedRead  coef write 2419
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2423 ); // i2cPagedRead  coef read 2423
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2427 ); // i2cPagedRead  coef read 2427
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000320, 2431 ); // i2cPagedRead  coef read 2431
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2435 ); // i2cPagedRead  coef read 2435
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2439 ); // i2cPagedRead  coef write 2439
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x0322 i2c data 0x0022
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1103, 0x0022, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2450 ); // i2cPagedWrite  coef read 2450
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2454 ); // i2cPagedWrite  coef write 2454
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2458 ); // i2cPagedWrite  coef write 2458
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0011, 0x00000000, 2462 ); // i2cPagedWrite  coef write 2462
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2466 ); // i2cPagedWrite  coef read 2466
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2470 ); // i2cPagedWrite  coef read 2470
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0322, 0x00000000, 2474 ); // i2cPagedWrite  coef write 2474
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2478 ); // i2cPagedWrite  coef read 2478
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2482 ); // i2cPagedWrite  coef read 2482
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2486 ); // i2cPagedWrite  coef read 2486
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2490 ); // i2cPagedWrite  coef write 2490
//      snd_hda i2cPagedWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x2901 i2c data 0x0001
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1129, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2501 ); // i2cPagedWrite  coef read 2501
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2505 ); // i2cPagedWrite  coef write 2505
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2509 ); // i2cPagedWrite  coef write 2509
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0011, 0x00000000, 2513 ); // i2cPagedWrite  coef write 2513
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2517 ); // i2cPagedWrite  coef read 2517
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2521 ); // i2cPagedWrite  coef read 2521
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2901, 0x00000000, 2525 ); // i2cPagedWrite  coef write 2525
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2529 ); // i2cPagedWrite  coef read 2529
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2533 ); // i2cPagedWrite  coef read 2533
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2537 ); // i2cPagedWrite  coef read 2537
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2541 ); // i2cPagedWrite  coef write 2541
//      snd_hda i2cPagedWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x13 lo 0x200f i2c data 0x000f
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1320, 0x000f, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2552 ); // i2cPagedWrite  coef read 2552
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2556 ); // i2cPagedWrite  coef write 2556
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2560 ); // i2cPagedWrite  coef write 2560
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 2564 ); // i2cPagedWrite  coef write 2564
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2568 ); // i2cPagedWrite  coef read 2568
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2572 ); // i2cPagedWrite  coef read 2572
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x200f, 0x00000000, 2576 ); // i2cPagedWrite  coef write 2576
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2580 ); // i2cPagedWrite  coef read 2580
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2584 ); // i2cPagedWrite  coef read 2584
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2588 ); // i2cPagedWrite  coef read 2588
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2592 ); // i2cPagedWrite  coef write 2592
//      snd_hda i2cPagedWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x1b00 i2c data 0x1b03
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x131b, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2603 ); // i2cPagedRead  coef read 2603
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2607 ); // i2cPagedRead  coef write 2607
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2611 ); // i2cPagedRead  coef write 2611
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 2615 ); // i2cPagedRead  coef write 2615
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2619 ); // i2cPagedRead  coef read 2619
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x1b00, 0x00000000, 2623 ); // i2cPagedRead  coef write 2623
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2627 ); // i2cPagedRead  coef read 2627
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2631 ); // i2cPagedRead  coef read 2631
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00001b03, 2635 ); // i2cPagedRead  coef read 2635
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2639 ); // i2cPagedRead  coef read 2639
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2643 ); // i2cPagedRead  coef write 2643
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x13 lo 0x1b03 i2c data 0x0003
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x131b, 0x0003, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2654 ); // i2cPagedWrite  coef read 2654
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2658 ); // i2cPagedWrite  coef write 2658
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2662 ); // i2cPagedWrite  coef write 2662
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 2666 ); // i2cPagedWrite  coef write 2666
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2670 ); // i2cPagedWrite  coef read 2670
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2674 ); // i2cPagedWrite  coef read 2674
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1b03, 0x00000000, 2678 ); // i2cPagedWrite  coef write 2678
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2682 ); // i2cPagedWrite  coef read 2682
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2686 ); // i2cPagedWrite  coef read 2686
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2690 ); // i2cPagedWrite  coef read 2690
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2694 ); // i2cPagedWrite  coef write 2694
//      snd_hda i2cPagedWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x23 lo 0x023f i2c data 0x003f
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x2302, 0x003f, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2705 ); // i2cPagedWrite  coef read 2705
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2709 ); // i2cPagedWrite  coef write 2709
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2713 ); // i2cPagedWrite  coef write 2713
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0023, 0x00000000, 2717 ); // i2cPagedWrite  coef write 2717
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2721 ); // i2cPagedWrite  coef read 2721
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2725 ); // i2cPagedWrite  coef read 2725
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x023f, 0x00000000, 2729 ); // i2cPagedWrite  coef write 2729
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2733 ); // i2cPagedWrite  coef read 2733
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2737 ); // i2cPagedWrite  coef read 2737
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2741 ); // i2cPagedWrite  coef read 2741
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2745 ); // i2cPagedWrite  coef write 2745
//      snd_hda i2cPagedWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1f lo 0x0100 i2c data 0x0000
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1f01, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2756 ); // i2cPagedWrite  coef read 2756
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2760 ); // i2cPagedWrite  coef write 2760
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2764 ); // i2cPagedWrite  coef write 2764
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x001f, 0x00000000, 2768 ); // i2cPagedWrite  coef write 2768
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2772 ); // i2cPagedWrite  coef read 2772
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2776 ); // i2cPagedWrite  coef read 2776
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0100, 0x00000000, 2780 ); // i2cPagedWrite  coef write 2780
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2784 ); // i2cPagedWrite  coef read 2784
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2788 ); // i2cPagedWrite  coef read 2788
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2792 ); // i2cPagedWrite  coef read 2792
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2796 ); // i2cPagedWrite  coef write 2796
//      snd_hda i2cPagedWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x21a6 i2c data 0x00a6
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1121, 0x00a6, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2807 ); // i2cPagedWrite  coef read 2807
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2811 ); // i2cPagedWrite  coef write 2811
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2815 ); // i2cPagedWrite  coef write 2815
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0011, 0x00000000, 2819 ); // i2cPagedWrite  coef write 2819
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2823 ); // i2cPagedWrite  coef read 2823
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2827 ); // i2cPagedWrite  coef read 2827
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x21a6, 0x00000000, 2831 ); // i2cPagedWrite  coef write 2831
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2835 ); // i2cPagedWrite  coef read 2835
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2839 ); // i2cPagedWrite  coef read 2839
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2843 ); // i2cPagedWrite  coef read 2843
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2847 ); // i2cPagedWrite  coef write 2847
//      snd_hda i2cPagedWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x13 lo 0x1600 i2c data 0x0000
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1316, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2858 ); // i2cPagedWrite  coef read 2858
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2862 ); // i2cPagedWrite  coef write 2862
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2866 ); // i2cPagedWrite  coef write 2866
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 2870 ); // i2cPagedWrite  coef write 2870
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2874 ); // i2cPagedWrite  coef read 2874
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2878 ); // i2cPagedWrite  coef read 2878
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1600, 0x00000000, 2882 ); // i2cPagedWrite  coef write 2882
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2886 ); // i2cPagedWrite  coef read 2886
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2890 ); // i2cPagedWrite  coef read 2890
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2894 ); // i2cPagedWrite  coef read 2894
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2898 ); // i2cPagedWrite  coef write 2898
//      snd_hda i2cPagedWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x13 lo 0x1700 i2c data 0x0000
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1317, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2909 ); // i2cPagedWrite  coef read 2909
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2913 ); // i2cPagedWrite  coef write 2913
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2917 ); // i2cPagedWrite  coef write 2917
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 2921 ); // i2cPagedWrite  coef write 2921
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2925 ); // i2cPagedWrite  coef read 2925
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2929 ); // i2cPagedWrite  coef read 2929
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1700, 0x00000000, 2933 ); // i2cPagedWrite  coef write 2933
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2937 ); // i2cPagedWrite  coef read 2937
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2941 ); // i2cPagedWrite  coef read 2941
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2945 ); // i2cPagedWrite  coef read 2945
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 2949 ); // i2cPagedWrite  coef write 2949
//      snd_hda i2cPagedWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x13 lo 0x1800 i2c data 0x0000
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1318, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 2960 ); // i2cPagedWrite  coef read 2960
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 2964 ); // i2cPagedWrite  coef write 2964
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 2968 ); // i2cPagedWrite  coef write 2968
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 2972 ); // i2cPagedWrite  coef write 2972
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2976 ); // i2cPagedWrite  coef read 2976
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2980 ); // i2cPagedWrite  coef read 2980
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1800, 0x00000000, 2984 ); // i2cPagedWrite  coef write 2984
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2988 ); // i2cPagedWrite  coef read 2988
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 2992 ); // i2cPagedWrite  coef read 2992
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 2996 ); // i2cPagedWrite  coef read 2996
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3000 ); // i2cPagedWrite  coef write 3000
//      snd_hda i2cPagedWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x13 lo 0x1900 i2c data 0x0000
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1319, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3011 ); // i2cPagedWrite  coef read 3011
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3015 ); // i2cPagedWrite  coef write 3015
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3019 ); // i2cPagedWrite  coef write 3019
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 3023 ); // i2cPagedWrite  coef write 3023
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3027 ); // i2cPagedWrite  coef read 3027
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3031 ); // i2cPagedWrite  coef read 3031
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1900, 0x00000000, 3035 ); // i2cPagedWrite  coef write 3035
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3039 ); // i2cPagedWrite  coef read 3039
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3043 ); // i2cPagedWrite  coef read 3043
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3047 ); // i2cPagedWrite  coef read 3047
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3051 ); // i2cPagedWrite  coef write 3051
//      snd_hda i2cPagedWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x13 lo 0x1a00 i2c data 0x0000
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x131a, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3062 ); // i2cPagedWrite  coef read 3062
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3066 ); // i2cPagedWrite  coef write 3066
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3070 ); // i2cPagedWrite  coef write 3070
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 3074 ); // i2cPagedWrite  coef write 3074
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3078 ); // i2cPagedWrite  coef read 3078
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3082 ); // i2cPagedWrite  coef read 3082
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1a00, 0x00000000, 3086 ); // i2cPagedWrite  coef write 3086
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3090 ); // i2cPagedWrite  coef read 3090
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3094 ); // i2cPagedWrite  coef read 3094
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3098 ); // i2cPagedWrite  coef read 3098
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3102 ); // i2cPagedWrite  coef write 3102
//      snd_hda i2cPagedWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x1c00 i2c data 0x1c7f
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x131c, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3113 ); // i2cPagedRead  coef read 3113
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3117 ); // i2cPagedRead  coef write 3117
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3121 ); // i2cPagedRead  coef write 3121
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 3125 ); // i2cPagedRead  coef write 3125
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3129 ); // i2cPagedRead  coef read 3129
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x1c00, 0x00000000, 3133 ); // i2cPagedRead  coef write 3133
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3137 ); // i2cPagedRead  coef read 3137
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3141 ); // i2cPagedRead  coef read 3141
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00001c7f, 3145 ); // i2cPagedRead  coef read 3145
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3149 ); // i2cPagedRead  coef read 3149
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3153 ); // i2cPagedRead  coef write 3153
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x13 lo 0x1c1a i2c data 0x001a
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x131c, 0x001a, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3164 ); // i2cPagedWrite  coef read 3164
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3168 ); // i2cPagedWrite  coef write 3168
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3172 ); // i2cPagedWrite  coef write 3172
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 3176 ); // i2cPagedWrite  coef write 3176
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3180 ); // i2cPagedWrite  coef read 3180
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3184 ); // i2cPagedWrite  coef read 3184
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1c1a, 0x00000000, 3188 ); // i2cPagedWrite  coef write 3188
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3192 ); // i2cPagedWrite  coef read 3192
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3196 ); // i2cPagedWrite  coef read 3196
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3200 ); // i2cPagedWrite  coef read 3200
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3204 ); // i2cPagedWrite  coef write 3204
//      snd_hda i2cPagedWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x13 lo 0x1e00 i2c data 0x0000
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x131e, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3215 ); // i2cPagedWrite  coef read 3215
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3219 ); // i2cPagedWrite  coef write 3219
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3223 ); // i2cPagedWrite  coef write 3223
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 3227 ); // i2cPagedWrite  coef write 3227
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3231 ); // i2cPagedWrite  coef read 3231
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3235 ); // i2cPagedWrite  coef read 3235
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1e00, 0x00000000, 3239 ); // i2cPagedWrite  coef write 3239
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3243 ); // i2cPagedWrite  coef read 3243
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3247 ); // i2cPagedWrite  coef read 3247
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3251 ); // i2cPagedWrite  coef read 3251
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3255 ); // i2cPagedWrite  coef write 3255
//      snd_hda i2cPagedWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x13 lo 0x1f00 i2c data 0x0000
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x131f, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3266 ); // i2cPagedWrite  coef read 3266
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3270 ); // i2cPagedWrite  coef write 3270
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3274 ); // i2cPagedWrite  coef write 3274
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 3278 ); // i2cPagedWrite  coef write 3278
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3282 ); // i2cPagedWrite  coef read 3282
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3286 ); // i2cPagedWrite  coef read 3286
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x1f00, 0x00000000, 3290 ); // i2cPagedWrite  coef write 3290
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3294 ); // i2cPagedWrite  coef read 3294
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3298 ); // i2cPagedWrite  coef read 3298
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3302 ); // i2cPagedWrite  coef read 3302
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3306 ); // i2cPagedWrite  coef write 3306
//      snd_hda i2cPagedWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0100 i2c data 0x0100
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1301, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3317 ); // i2cPagedRead  coef read 3317
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3321 ); // i2cPagedRead  coef write 3321
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3325 ); // i2cPagedRead  coef write 3325
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 3329 ); // i2cPagedRead  coef write 3329
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3333 ); // i2cPagedRead  coef read 3333
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0100, 0x00000000, 3337 ); // i2cPagedRead  coef write 3337
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3341 ); // i2cPagedRead  coef read 3341
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3345 ); // i2cPagedRead  coef read 3345
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000100, 3349 ); // i2cPagedRead  coef read 3349
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3353 ); // i2cPagedRead  coef read 3353
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3357 ); // i2cPagedRead  coef write 3357
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0200 i2c data 0x0200
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1302, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3368 ); // i2cPagedRead  coef read 3368
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3372 ); // i2cPagedRead  coef write 3372
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3376 ); // i2cPagedRead  coef write 3376
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 3380 ); // i2cPagedRead  coef write 3380
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3384 ); // i2cPagedRead  coef read 3384
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0200, 0x00000000, 3388 ); // i2cPagedRead  coef write 3388
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3392 ); // i2cPagedRead  coef read 3392
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3396 ); // i2cPagedRead  coef read 3396
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000200, 3400 ); // i2cPagedRead  coef read 3400
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3404 ); // i2cPagedRead  coef read 3404
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3408 ); // i2cPagedRead  coef write 3408
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0300 i2c data 0x030c
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1303, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3419 ); // i2cPagedRead  coef read 3419
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3423 ); // i2cPagedRead  coef write 3423
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3427 ); // i2cPagedRead  coef write 3427
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 3431 ); // i2cPagedRead  coef write 3431
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3435 ); // i2cPagedRead  coef read 3435
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0300, 0x00000000, 3439 ); // i2cPagedRead  coef write 3439
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3443 ); // i2cPagedRead  coef read 3443
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3447 ); // i2cPagedRead  coef read 3447
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x0000030c, 3451 ); // i2cPagedRead  coef read 3451
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3455 ); // i2cPagedRead  coef read 3455
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3459 ); // i2cPagedRead  coef write 3459
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0400 i2c data 0x0400
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1304, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3470 ); // i2cPagedRead  coef read 3470
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3474 ); // i2cPagedRead  coef write 3474
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3478 ); // i2cPagedRead  coef write 3478
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 3482 ); // i2cPagedRead  coef write 3482
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3486 ); // i2cPagedRead  coef read 3486
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0400, 0x00000000, 3490 ); // i2cPagedRead  coef write 3490
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3494 ); // i2cPagedRead  coef read 3494
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3498 ); // i2cPagedRead  coef read 3498
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000400, 3502 ); // i2cPagedRead  coef read 3502
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3506 ); // i2cPagedRead  coef read 3506
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3510 ); // i2cPagedRead  coef write 3510
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0500 i2c data 0x0500
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1305, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3521 ); // i2cPagedRead  coef read 3521
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3525 ); // i2cPagedRead  coef write 3525
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3529 ); // i2cPagedRead  coef write 3529
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 3533 ); // i2cPagedRead  coef write 3533
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3537 ); // i2cPagedRead  coef read 3537
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0500, 0x00000000, 3541 ); // i2cPagedRead  coef write 3541
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3545 ); // i2cPagedRead  coef read 3545
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3549 ); // i2cPagedRead  coef read 3549
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000500, 3553 ); // i2cPagedRead  coef read 3553
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3557 ); // i2cPagedRead  coef read 3557
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3561 ); // i2cPagedRead  coef write 3561
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0b00 i2c data 0x0b60
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x130b, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3572 ); // i2cPagedRead  coef read 3572
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3576 ); // i2cPagedRead  coef write 3576
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3580 ); // i2cPagedRead  coef write 3580
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 3584 ); // i2cPagedRead  coef write 3584
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3588 ); // i2cPagedRead  coef read 3588
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0b00, 0x00000000, 3592 ); // i2cPagedRead  coef write 3592
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3596 ); // i2cPagedRead  coef read 3596
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3600 ); // i2cPagedRead  coef read 3600
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000b60, 3604 ); // i2cPagedRead  coef read 3604
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3608 ); // i2cPagedRead  coef read 3608
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3612 ); // i2cPagedRead  coef write 3612
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0d00 i2c data 0x0d01
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x130d, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3623 ); // i2cPagedRead  coef read 3623
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3627 ); // i2cPagedRead  coef write 3627
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3631 ); // i2cPagedRead  coef write 3631
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 3635 ); // i2cPagedRead  coef write 3635
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3639 ); // i2cPagedRead  coef read 3639
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0d00, 0x00000000, 3643 ); // i2cPagedRead  coef write 3643
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3647 ); // i2cPagedRead  coef read 3647
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3651 ); // i2cPagedRead  coef read 3651
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000d01, 3655 ); // i2cPagedRead  coef read 3655
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3659 ); // i2cPagedRead  coef read 3659
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3663 ); // i2cPagedRead  coef write 3663
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0e00 i2c data 0x0e00
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x130e, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3674 ); // i2cPagedRead  coef read 3674
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3678 ); // i2cPagedRead  coef write 3678
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3682 ); // i2cPagedRead  coef write 3682
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 3686 ); // i2cPagedRead  coef write 3686
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3690 ); // i2cPagedRead  coef read 3690
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0e00, 0x00000000, 3694 ); // i2cPagedRead  coef write 3694
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3698 ); // i2cPagedRead  coef read 3698
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3702 ); // i2cPagedRead  coef read 3702
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000e00, 3706 ); // i2cPagedRead  coef read 3706
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3710 ); // i2cPagedRead  coef read 3710
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3714 ); // i2cPagedRead  coef write 3714
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0800 i2c data 0x0801
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1308, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3725 ); // i2cPagedRead  coef read 3725
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3729 ); // i2cPagedRead  coef write 3729
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3733 ); // i2cPagedRead  coef write 3733
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 3737 ); // i2cPagedRead  coef write 3737
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3741 ); // i2cPagedRead  coef read 3741
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0800, 0x00000000, 3745 ); // i2cPagedRead  coef write 3745
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3749 ); // i2cPagedRead  coef read 3749
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3753 ); // i2cPagedRead  coef read 3753
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000801, 3757 ); // i2cPagedRead  coef read 3757
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3761 ); // i2cPagedRead  coef read 3761
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3765 ); // i2cPagedRead  coef write 3765
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0f00 i2c data 0x0f00
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x130f, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3776 ); // i2cPagedRead  coef read 3776
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3780 ); // i2cPagedRead  coef write 3780
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3784 ); // i2cPagedRead  coef write 3784
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0013, 0x00000000, 3788 ); // i2cPagedRead  coef write 3788
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3792 ); // i2cPagedRead  coef read 3792
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0f00, 0x00000000, 3796 ); // i2cPagedRead  coef write 3796
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3800 ); // i2cPagedRead  coef read 3800
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3804 ); // i2cPagedRead  coef read 3804
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000f00, 3808 ); // i2cPagedRead  coef read 3808
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3812 ); // i2cPagedRead  coef read 3812
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3816 ); // i2cPagedRead  coef write 3816
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x11 lo 0x0100 i2c data 0x01ff
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1101, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3827 ); // i2cPagedRead  coef read 3827
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3831 ); // i2cPagedRead  coef write 3831
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3835 ); // i2cPagedRead  coef write 3835
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0011, 0x00000000, 3839 ); // i2cPagedRead  coef write 3839
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3843 ); // i2cPagedRead  coef read 3843
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0100, 0x00000000, 3847 ); // i2cPagedRead  coef write 3847
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3851 ); // i2cPagedRead  coef read 3851
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3855 ); // i2cPagedRead  coef read 3855
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x000001ff, 3859 ); // i2cPagedRead  coef read 3859
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3863 ); // i2cPagedRead  coef read 3863
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3867 ); // i2cPagedRead  coef write 3867
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x01fe i2c data 0x00fe
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1101, 0x00fe, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3878 ); // i2cPagedWrite  coef read 3878
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3882 ); // i2cPagedWrite  coef write 3882
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3886 ); // i2cPagedWrite  coef write 3886
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0011, 0x00000000, 3890 ); // i2cPagedWrite  coef write 3890
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3894 ); // i2cPagedWrite  coef read 3894
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3898 ); // i2cPagedWrite  coef read 3898
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x01fe, 0x00000000, 3902 ); // i2cPagedWrite  coef write 3902
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3906 ); // i2cPagedWrite  coef read 3906
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3910 ); // i2cPagedWrite  coef read 3910
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3914 ); // i2cPagedWrite  coef read 3914
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3918 ); // i2cPagedWrite  coef write 3918
//      snd_hda i2cPagedWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7500 i2c data 0x751f
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1b75, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3929 ); // i2cPagedRead  coef read 3929
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3933 ); // i2cPagedRead  coef write 3933
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3937 ); // i2cPagedRead  coef write 3937
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x001b, 0x00000000, 3941 ); // i2cPagedRead  coef write 3941
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3945 ); // i2cPagedRead  coef read 3945
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x7500, 0x00000000, 3949 ); // i2cPagedRead  coef write 3949
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3953 ); // i2cPagedRead  coef read 3953
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3957 ); // i2cPagedRead  coef read 3957
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x0000751f, 3961 ); // i2cPagedRead  coef read 3961
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 3965 ); // i2cPagedRead  coef read 3965
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 3969 ); // i2cPagedRead  coef write 3969
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x759f i2c data 0x009f
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b75, 0x009f, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 3980 ); // i2cPagedWrite  coef read 3980
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 3984 ); // i2cPagedWrite  coef write 3984
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 3988 ); // i2cPagedWrite  coef write 3988
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x001b, 0x00000000, 3992 ); // i2cPagedWrite  coef write 3992
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 3996 ); // i2cPagedWrite  coef read 3996
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4000 ); // i2cPagedWrite  coef read 4000
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x759f, 0x00000000, 4004 ); // i2cPagedWrite  coef write 4004
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4008 ); // i2cPagedWrite  coef read 4008
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4012 ); // i2cPagedWrite  coef read 4012
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 4016 ); // i2cPagedWrite  coef read 4016
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 4020 ); // i2cPagedWrite  coef write 4020
//      snd_hda i2cPagedWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x28 i2c            reg 0x0083 i2c data 0x0083   reg anal: PowerControl            : PowerDown SoftwareReset BVSenseOn AutoPwrOffEnabled
        //cs_8409_vendor_i2cWrite(codec, 0x28, 0x0000, 0x0083, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 4031 ); // i2cWrite  coef read 4031
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 4035 ); // i2cWrite  coef write 4035
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0028, 0x00000000, 4039 ); // i2cWrite  coef write 4039
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0083, 0x00000000, 4043 ); // i2cWrite  coef write 4043
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4047 ); // i2cWrite  coef read 4047
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4051 ); // i2cWrite  coef read 4051
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 4055 ); // i2cWrite  coef read 4055
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 4059 ); // i2cWrite  coef write 4059
//      snd_hda i2cWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2a i2c            reg 0x0083 i2c data 0x0083   reg anal: PowerControl            : PowerDown SoftwareReset BVSenseOn AutoPwrOffEnabled
        //cs_8409_vendor_i2cWrite(codec, 0x2a, 0x0000, 0x0083, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 4070 ); // i2cWrite  coef read 4070
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 4074 ); // i2cWrite  coef write 4074
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002a, 0x00000000, 4078 ); // i2cWrite  coef write 4078
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0083, 0x00000000, 4082 ); // i2cWrite  coef write 4082
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4086 ); // i2cWrite  coef read 4086
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4090 ); // i2cWrite  coef read 4090
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 4094 ); // i2cWrite  coef read 4094
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 4098 ); // i2cWrite  coef write 4098
//      snd_hda i2cWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2c i2c            reg 0x0083 i2c data 0x0083   reg anal: PowerControl            : PowerDown SoftwareReset BVSenseOn AutoPwrOffEnabled
        //cs_8409_vendor_i2cWrite(codec, 0x2c, 0x0000, 0x0083, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 4109 ); // i2cWrite  coef read 4109
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 4113 ); // i2cWrite  coef write 4113
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002c, 0x00000000, 4117 ); // i2cWrite  coef write 4117
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0083, 0x00000000, 4121 ); // i2cWrite  coef write 4121
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4125 ); // i2cWrite  coef read 4125
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4129 ); // i2cWrite  coef read 4129
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 4133 ); // i2cWrite  coef read 4133
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 4137 ); // i2cWrite  coef write 4137
//      snd_hda i2cWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2e i2c            reg 0x0083 i2c data 0x0083   reg anal: PowerControl            : PowerDown SoftwareReset BVSenseOn AutoPwrOffEnabled
        //cs_8409_vendor_i2cWrite(codec, 0x2e, 0x0000, 0x0083, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 4148 ); // i2cWrite  coef read 4148
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 4152 ); // i2cWrite  coef write 4152
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002e, 0x00000000, 4156 ); // i2cWrite  coef write 4156
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0083, 0x00000000, 4160 ); // i2cWrite  coef write 4160
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4164 ); // i2cWrite  coef read 4164
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4168 ); // i2cWrite  coef read 4168
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 4172 ); // i2cWrite  coef read 4172
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 4176 ); // i2cWrite  coef write 4176
//      snd_hda i2cWrite end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}

static void putative_gpio_mic3_ssm3(struct hda_codec *codec)
{
        int retval;

        // CHANGE - this does not appear for max version

        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_GPIO_DATA, 0x00000000, 0x0000000f, 4182); // 0x001f1500
//      snd_hda:     gpio data 1 0x0f

}


static void putative_setup_mic3_ssm3(struct hda_codec *codec)
{

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7500 i2c data 0x759f
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1b75, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 4190 ); // i2cPagedRead  coef read 4190
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 4194 ); // i2cPagedRead  coef write 4194
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 4198 ); // i2cPagedRead  coef write 4198
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x001b, 0x00000000, 4202 ); // i2cPagedRead  coef write 4202
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4206 ); // i2cPagedRead  coef read 4206
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x7500, 0x00000000, 4210 ); // i2cPagedRead  coef write 4210
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4214 ); // i2cPagedRead  coef read 4214
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4218 ); // i2cPagedRead  coef read 4218
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x0000759f, 4222 ); // i2cPagedRead  coef read 4222
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 4226 ); // i2cPagedRead  coef read 4226
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 4230 ); // i2cPagedRead  coef write 4230
//      snd_hda i2cPagedRead end

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x759f i2c data 0x009f
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b75, 0x009f, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 4237 ); // i2cPagedWrite  coef read 4237
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 4241 ); // i2cPagedWrite  coef write 4241
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 4245 ); // i2cPagedWrite  coef write 4245
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x001b, 0x00000000, 4249 ); // i2cPagedWrite  coef write 4249
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4253 ); // i2cPagedWrite  coef read 4253
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4257 ); // i2cPagedWrite  coef read 4257
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x759f, 0x00000000, 4261 ); // i2cPagedWrite  coef write 4261
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4265 ); // i2cPagedWrite  coef read 4265
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4269 ); // i2cPagedWrite  coef read 4269
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 4273 ); // i2cPagedWrite  coef read 4273
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 4277 ); // i2cPagedWrite  coef write 4277
//      snd_hda i2cPagedWrite end

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7300 i2c data 0x7302
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1b73, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 4284 ); // i2cPagedRead  coef read 4284
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 4288 ); // i2cPagedRead  coef write 4288
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 4292 ); // i2cPagedRead  coef write 4292
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x001b, 0x00000000, 4296 ); // i2cPagedRead  coef write 4296
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4300 ); // i2cPagedRead  coef read 4300
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x7300, 0x00000000, 4304 ); // i2cPagedRead  coef write 4304
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4308 ); // i2cPagedRead  coef read 4308
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4312 ); // i2cPagedRead  coef read 4312
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00007302, 4316 ); // i2cPagedRead  coef read 4316
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 4320 ); // i2cPagedRead  coef read 4320
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 4324 ); // i2cPagedRead  coef write 4324
//      snd_hda i2cPagedRead end

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x73c0 i2c data 0x00c0
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b73, 0x00c0, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 4331 ); // i2cPagedWrite  coef read 4331
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 4335 ); // i2cPagedWrite  coef write 4335
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 4339 ); // i2cPagedWrite  coef write 4339
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x001b, 0x00000000, 4343 ); // i2cPagedWrite  coef write 4343
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4347 ); // i2cPagedWrite  coef read 4347
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4351 ); // i2cPagedWrite  coef read 4351
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x73c0, 0x00000000, 4355 ); // i2cPagedWrite  coef write 4355
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4359 ); // i2cPagedWrite  coef read 4359
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4363 ); // i2cPagedWrite  coef read 4363
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 4367 ); // i2cPagedWrite  coef read 4367
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 4371 ); // i2cPagedWrite  coef write 4371
//      snd_hda i2cPagedWrite end

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7b00 i2c data 0x7b60
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1b7b, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 4378 ); // i2cPagedRead  coef read 4378
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 4382 ); // i2cPagedRead  coef write 4382
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 4386 ); // i2cPagedRead  coef write 4386
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x001b, 0x00000000, 4390 ); // i2cPagedRead  coef write 4390
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4394 ); // i2cPagedRead  coef read 4394
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x7b00, 0x00000000, 4398 ); // i2cPagedRead  coef write 4398
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4402 ); // i2cPagedRead  coef read 4402
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4406 ); // i2cPagedRead  coef read 4406
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00007b60, 4410 ); // i2cPagedRead  coef read 4410
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 4414 ); // i2cPagedRead  coef read 4414
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 4418 ); // i2cPagedRead  coef write 4418
//      snd_hda i2cPagedRead end

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7900 i2c data 0x79e0
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1b79, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 4425 ); // i2cPagedRead  coef read 4425
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 4429 ); // i2cPagedRead  coef write 4429
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 4433 ); // i2cPagedRead  coef write 4433
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x001b, 0x00000000, 4437 ); // i2cPagedRead  coef write 4437
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4441 ); // i2cPagedRead  coef read 4441
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x7900, 0x00000000, 4445 ); // i2cPagedRead  coef write 4445
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4449 ); // i2cPagedRead  coef read 4449
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4453 ); // i2cPagedRead  coef read 4453
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x000079e0, 4457 ); // i2cPagedRead  coef read 4457
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 4461 ); // i2cPagedRead  coef read 4461
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 4465 ); // i2cPagedRead  coef write 4465
//      snd_hda i2cPagedRead end

//      snd_hda: # i2cPagedWrite: 
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x79a0 i2c data 0x00a0
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b79, 0x00a0, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 4472 ); // i2cPagedWrite  coef read 4472
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 4476 ); // i2cPagedWrite  coef write 4476
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 4480 ); // i2cPagedWrite  coef write 4480
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x001b, 0x00000000, 4484 ); // i2cPagedWrite  coef write 4484
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4488 ); // i2cPagedWrite  coef read 4488
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4492 ); // i2cPagedWrite  coef read 4492
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x79a0, 0x00000000, 4496 ); // i2cPagedWrite  coef write 4496
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4500 ); // i2cPagedWrite  coef read 4500
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4504 ); // i2cPagedWrite  coef read 4504
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 4508 ); // i2cPagedWrite  coef read 4508
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 4512 ); // i2cPagedWrite  coef write 4512
//      snd_hda i2cPagedWrite end


        // I now think the OSX logs may not be exactly ordered - so this may be a bunch from the above calls
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7700 i2c data 0x7716
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1b77, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 4561 ); // i2cPagedRead  coef read 4561
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 4565 ); // i2cPagedRead  coef write 4565
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 4569 ); // i2cPagedRead  coef write 4569
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x001b, 0x00000000, 4573 ); // i2cPagedRead  coef write 4573
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4577 ); // i2cPagedRead  coef read 4577
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x7700, 0x00000000, 4581 ); // i2cPagedRead  coef write 4581
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4585 ); // i2cPagedRead  coef read 4585
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4589 ); // i2cPagedRead  coef read 4589
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00007716, 4593 ); // i2cPagedRead  coef read 4593
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 4597 ); // i2cPagedRead  coef read 4597
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 4601 ); // i2cPagedRead  coef write 4601
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}


// dont see this yet
//static void setup_amps_reset_ssm3(struct hda_codec *codec)

static void setup_jack_nids_ssm3(struct hda_codec *codec)
{
        //int retval;

        //int retgain1;
        //int retgain2; 

        // BIG CHANGE - this only works on nids 0x22, 0x44 - dont see 0x23, 0x45
        
        // these I think are the line in/headphone socket nids

        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004031); // 0x02224031
//      snd_hda:     stream format 34 [('CHAN', 2), ('RATE', 44100), ('BITS', 24), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 4621); // 0x022f0500
        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x02270500
        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000030, 4624); // 0x022f0500
        hda_set_node_power_state(codec, 0x22, AC_PWRST_D0);

        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x02270600
//      snd_hda:     conv stream channel map 34 [('CHAN', 0), ('STREAMID', 0)]

        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x02270503
        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 4627); // 0x022f0500
        hda_set_node_power_state(codec, 0x22, AC_PWRST_D3);

        // so the following is being done with node 0x22 powered down!!

//      snd_hda: # AppleHDAWidgetCS8409::setConnectionSelect: 
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0009, 0x0000, 0x00000013, 4629 ); // AppleHDAWidgetCS8409::setConnectionSelect  coef read 4629
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0009, 0x0033, 0x00000000, 4633 ); // AppleHDAWidgetCS8409::setConnectionSelect  coef write 4633
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_CONNECT_SEL, 0x00000000); // 0x02270100

}

static void setup_jack_vol1_ssm3(struct hda_codec *codec)
{
        int retval;

        //int retgain1;
        //int retgain2;

        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x000000b3, 4638); // 0x022b2000
//      snd_hda:     amp gain/mute 34 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 34 0x00b3 mute 1 gain 0x33 51
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x000060a7); // 0x022360a7
//      snd_hda:     amp gain/mute 34 0x60a7 mute 1 gain 0x27 39 index 0x00 left 1 right 0 output 0 input 1 left   input
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x000000b3, 4640); // 0x022b0000
//      snd_hda:     amp gain/mute 34 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 34 0x00b3 mute 1 gain 0x33 51
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x000050a7); // 0x022350a7
//      snd_hda:     amp gain/mute 34 0x50a7 mute 1 gain 0x27 39 index 0x00 left 0 right 1 output 0 input 1  right  input

        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x000000a7, 4642); // 0x022b2000
//      snd_hda:     amp gain/mute 34 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 34 0x00a7 mute 1 gain 0x27 39
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x000060a7); // 0x022360a7
//      snd_hda:     amp gain/mute 34 0x60a7 mute 1 gain 0x27 39 index 0x00 left 1 right 0 output 0 input 1 left   input
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x000000a7, 4644); // 0x022b0000
//      snd_hda:     amp gain/mute 34 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 34 0x00a7 mute 1 gain 0x27 39
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x000050a7); // 0x022350a7
//      snd_hda:     amp gain/mute 34 0x50a7 mute 1 gain 0x27 39 index 0x00 left 0 right 1 output 0 input 1  right  input

        // this is working on node 0x44

        retval = snd_hda_codec_read_check(codec, 0x44, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x00000000, 4646); // 0x044b2000
//      snd_hda:     amp gain/mute 68 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 68 0x0000 mute 0 gain 0x0 0
        snd_hda_codec_write(codec, 0x44, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00006000); // 0x04436000
//      snd_hda:     amp gain/mute 68 0x6000 mute 0 gain 0x0 0 index 0x00 left 1 right 0 output 0 input 1 left   input
        retval = snd_hda_codec_read_check(codec, 0x44, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x00000000, 4648); // 0x044b0000
//      snd_hda:     amp gain/mute 68 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 68 0x0000 mute 0 gain 0x0 0
        snd_hda_codec_write(codec, 0x44, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00005000); // 0x04435000
//      snd_hda:     amp gain/mute 68 0x5000 mute 0 gain 0x0 0 index 0x00 left 0 right 1 output 0 input 1  right  input

}

static void setup_jack_nids1_ssm3(struct hda_codec *codec)
{
        int retval;

        //int retgain1;
        //int retgain2;


        // I think this is for node 0x44

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0082, 0x0000, 0x00000000, 4650 ); //   coef read 4650
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0082, 0x0001, 0x00000000, 4654 ); //   coef write 4654

        retval = snd_hda_codec_read_check(codec, 0x44, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 4658); // 0x044f0700
        snd_hda_codec_write(codec, 0x44, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000020); // 0x04470720
//      snd_hda:     68 ['AC_PINCTL_IN_EN']

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        // and redo the stream format???
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004031); // 0x02224031
//      snd_hda:     stream format 34 [('CHAN', 2), ('RATE', 44100), ('BITS', 24), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

}

static void setup_jack_vol2_ssm3(struct hda_codec *codec)
{
        int retval;

        //int retgain1;
        //int retgain2;


        // this is not making sense - redo node 0x22

        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x000000a7, 4677); // 0x022b2000
//      snd_hda:     amp gain/mute 34 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 34 0x00a7 mute 1 gain 0x27 39
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x000060b3); // 0x022360b3
//      snd_hda:     amp gain/mute 34 0x60b3 mute 1 gain 0x33 51 index 0x00 left 1 right 0 output 0 input 1 left   input
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x000000a7, 4679); // 0x022b0000
//      snd_hda:     amp gain/mute 34 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 34 0x00a7 mute 1 gain 0x27 39
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x000050b3); // 0x022350b3
//      snd_hda:     amp gain/mute 34 0x50b3 mute 1 gain 0x33 51 index 0x00 left 0 right 1 output 0 input 1  right  input

        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x000000b3, 4682); // 0x022b2000
//      snd_hda:     amp gain/mute 34 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 34 0x00b3 mute 1 gain 0x33 51
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00006033); // 0x02236033
//      snd_hda:     amp gain/mute 34 0x6033 mute 0 gain 0x33 51 index 0x00 left 1 right 0 output 0 input 1 left   input
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x000000b3, 4684); // 0x022b0000
//      snd_hda:     amp gain/mute 34 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 34 0x00b3 mute 1 gain 0x33 51
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00005033); // 0x02235033
//      snd_hda:     amp gain/mute 34 0x5033 mute 0 gain 0x33 51 index 0x00 left 0 right 1 output 0 input 1  right  input

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

}

static void setup_TDM_282a_ssm3(struct hda_codec *codec)
{
        int retval;

        // so this seems to be where we see the same code as in unmute and volup
        // - note that code structure is similar but detail differences exist
        // eg 0x083f below is 0x08ff in the unmute/volup stage

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        // why is this here??
        // this sets the input nid 0x02 (but not 0x03)

        // this seems to be setup for node 0x02 chain - which seems to use node 0x24 and amps 0x28 and 0x2a


        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004033); // 0x00224033
//      snd_hda:     stream format 2 [('CHAN', 4), ('RATE', 44100), ('BITS', 24), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00270600
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]


        // so apple seems to convert all input audio to 4 channel, 44.1 kHz, 24 bits per channel with higher level processing
        // (as seen from node 0x2, 0x3 setups)
        // the digital data is streamed over the PCI bus to the 8409 HDA where its converted to a digital TDM stream over
        // the interal i2c bus to the amplifiers
        // the following seems to be setting up the TDM conversion by coef writes to the vendor node

//      snd_hda: # AppleHDATDMBusManagerCS8409::setupTDMPath:
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000000, 4696 ); //   coef read 4696
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000000, 4700 ); //   coef write 4700

//      snd_hda: # AppleHDATDMBusManagerCS8409::setSampleRate: 
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0001, 0x0200, 0x00000000, 4705 ); // coef write mask 4705
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0005, 0x0001, 0x00000000, 4711 ); // coef write mask 4711
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0004, 0x08ff, 0x0000083f, 4717 ); // coef write mask 4717
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0001, 0x0200, 0xundef, 0x00000000, 4705 ); // coef write mask 4705
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0005, 0x0001, 0xundef, 0x00000000, 4711 ); // coef write mask 4711
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0004, 0x08ff, 0xundef, 0x0000083f, 4717 ); // coef write mask 4717

//      snd_hda: # AppleHDATDMBusManagerCS8409::setupTDMPath: 
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00008000, 4724 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 4724
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0019, 0x0800, 0x00000000, 4728 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 4728
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001a, 0x0000, 0x00008000, 4732 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 4732
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001a, 0x0820, 0x00000000, 4736 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 4736

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 4740 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 4740
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0xb000, 0x00000000, 4744 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 4744
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0004, 0x0000, 0x000008ff, 4748 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 4748
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0004, 0x08ff, 0x00000000, 4752 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 4752
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 4756 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 4756

        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0003, 0x8000, 0x0000801f, 4760 ); // coef write mask 4760
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0005, 0x0001, 0x00000001, 4766 ); // coef write mask 4766
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0082, 0x5401, 0x00000001, 4772 ); // coef write mask 4772
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0002, 0x0280, 0x00000080, 4778 ); // coef write mask 4778
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0003, 0x8000, 0xundef, 0x0000801f, 4760 ); // coef write mask 4760
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0005, 0x0001, 0xundef, 0x00000001, 4766 ); // coef write mask 4766
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0082, 0x5401, 0xundef, 0x00000001, 4772 ); // coef write mask 4772
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0002, 0x0280, 0xundef, 0x00000080, 4778 ); // coef write mask 4778

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000200, 4784 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 4784
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, 0x0220, 0x00000000, 4788 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 4788

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: AppleHDATDMBusManagerCS8409::tdmInUse:
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00000800, 4792 ); //   coef read 4792

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: 
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006b, 0x001f, 0x00000000, 4797 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 4797
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x00000000, 4801 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef read 4801
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x400f, 0x00000000, 4805 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 4805

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00b6 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  write verb 4808

        // enable output node 0x24

        retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 4812); // 0x024f0700
        snd_hda_codec_write(codec, 0x24, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000040); // 0x02470740
//      snd_hda:     36 ['AC_PINCTL_OUT_EN']

}


static void setup_amps_282a_ssm3(struct hda_codec *codec)
{
        //int retval;

        // this just seems to set some Interrupt registers - very different from max


//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x28 i2c            reg 0x0500 i2c data 0x0000   reg anal: SAIControl2             : ChipSlot 1 SlotByTDMRReg 24 bit Audio
        //cs_8409_vendor_i2cWrite(codec, 0x28, 0x0005, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 4816 ); // i2cWrite  coef read 4816
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 4820 ); // i2cWrite  coef write 4820
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0028, 0x00000000, 4824 ); // i2cWrite  coef write 4824
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0500, 0x00000000, 4828 ); // i2cWrite  coef write 4828
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4832 ); // i2cWrite  coef read 4832
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4836 ); // i2cWrite  coef read 4836
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 4840 ); // i2cWrite  coef read 4840
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 4844 ); // i2cWrite  coef write 4844
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x28 i2c            reg 0x0111 i2c data 0x0011   reg anal: GainEdgeControl         : 12.6V FSGainMap LowEMI
        //cs_8409_vendor_i2cWrite(codec, 0x28, 0x0001, 0x0011, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 4851 ); // i2cWrite  coef read 4851
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 4855 ); // i2cWrite  coef write 4855
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0028, 0x00000000, 4859 ); // i2cWrite  coef write 4859
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0111, 0x00000000, 4863 ); // i2cWrite  coef write 4863
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4867 ); // i2cWrite  coef read 4867
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4871 ); // i2cWrite  coef read 4871
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 4875 ); // i2cWrite  coef read 4875
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 4879 ); // i2cWrite  coef write 4879
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x28 i2c            reg 0x0348 i2c data 0x0048   reg anal: DACVolume               : -3.0dB
        //cs_8409_vendor_i2cWrite(codec, 0x28, 0x0003, 0x0048, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 4886 ); // i2cWrite  coef read 4886
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 4890 ); // i2cWrite  coef write 4890
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0028, 0x00000000, 4894 ); // i2cWrite  coef write 4894
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0348, 0x00000000, 4898 ); // i2cWrite  coef write 4898
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4902 ); // i2cWrite  coef read 4902
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4906 ); // i2cWrite  coef read 4906
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 4910 ); // i2cWrite  coef read 4910
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 4914 ); // i2cWrite  coef write 4914
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x28 i2c            reg 0x0451 i2c data 0x0051   reg anal: SAIControl1             : TDMPCMMode 24 BClks per Chip Delay1 PulsedSync Falling
        //cs_8409_vendor_i2cWrite(codec, 0x28, 0x0004, 0x0051, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 4921 ); // i2cWrite  coef read 4921
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 4925 ); // i2cWrite  coef write 4925
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0028, 0x00000000, 4929 ); // i2cWrite  coef write 4929
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0451, 0x00000000, 4933 ); // i2cWrite  coef write 4933
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4937 ); // i2cWrite  coef read 4937
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4941 ); // i2cWrite  coef read 4941
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 4945 ); // i2cWrite  coef read 4945
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 4949 ); // i2cWrite  coef write 4949
//      snd_hda i2cWrite end

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x28 i2c            reg 0x0200 i2c data 0x0232   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cRead(codec, 0x28, 0x0002, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 4956 ); // i2cRead  coef read 4956
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 4960 ); // i2cRead  coef write 4960
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0028, 0x00000000, 4964 ); // i2cRead  coef write 4964
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0200, 0x00000000, 4968 ); // i2cRead  coef write 4968
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4972 ); // i2cRead  coef read 4972
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 4976 ); // i2cRead  coef read 4976
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000232, 4980 ); // i2cRead  coef read 4980
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 4984 ); // i2cRead  coef read 4984
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 4988 ); // i2cRead  coef write 4988
//      snd_hda i2cRead end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x28 i2c            reg 0x0232 i2c data 0x0032   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cWrite(codec, 0x28, 0x0002, 0x0032, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 4995 ); // i2cWrite  coef read 4995
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 4999 ); // i2cWrite  coef write 4999
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0028, 0x00000000, 5003 ); // i2cWrite  coef write 5003
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0232, 0x00000000, 5007 ); // i2cWrite  coef write 5007
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5011 ); // i2cWrite  coef read 5011
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5015 ); // i2cWrite  coef read 5015
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5019 ); // i2cWrite  coef read 5019
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5023 ); // i2cWrite  coef write 5023
//      snd_hda i2cWrite end

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x28 i2c            reg 0x0200 i2c data 0x0232   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cRead(codec, 0x28, 0x0002, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5030 ); // i2cRead  coef read 5030
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5034 ); // i2cRead  coef write 5034
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0028, 0x00000000, 5038 ); // i2cRead  coef write 5038
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0200, 0x00000000, 5042 ); // i2cRead  coef write 5042
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5046 ); // i2cRead  coef read 5046
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5050 ); // i2cRead  coef read 5050
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000232, 5054 ); // i2cRead  coef read 5054
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5058 ); // i2cRead  coef read 5058
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5062 ); // i2cRead  coef write 5062
//      snd_hda i2cRead end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x28 i2c            reg 0x0232 i2c data 0x0032   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cWrite(codec, 0x28, 0x0002, 0x0032, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5069 ); // i2cWrite  coef read 5069
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5073 ); // i2cWrite  coef write 5073
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0028, 0x00000000, 5077 ); // i2cWrite  coef write 5077
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0232, 0x00000000, 5081 ); // i2cWrite  coef write 5081
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5085 ); // i2cWrite  coef read 5085
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5089 ); // i2cWrite  coef read 5089
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5093 ); // i2cWrite  coef read 5093
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5097 ); // i2cWrite  coef write 5097
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2a i2c            reg 0x0501 i2c data 0x0001   reg anal: SAIControl2             : ChipSlot 2 SlotByTDMRReg 24 bit Audio
        //cs_8409_vendor_i2cWrite(codec, 0x2a, 0x0005, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5104 ); // i2cWrite  coef read 5104
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5108 ); // i2cWrite  coef write 5108
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002a, 0x00000000, 5112 ); // i2cWrite  coef write 5112
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0501, 0x00000000, 5116 ); // i2cWrite  coef write 5116
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5120 ); // i2cWrite  coef read 5120
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5124 ); // i2cWrite  coef read 5124
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5128 ); // i2cWrite  coef read 5128
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5132 ); // i2cWrite  coef write 5132
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2a i2c            reg 0x0111 i2c data 0x0011   reg anal: GainEdgeControl         : 12.6V FSGainMap LowEMI
        //cs_8409_vendor_i2cWrite(codec, 0x2a, 0x0001, 0x0011, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5139 ); // i2cWrite  coef read 5139
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5143 ); // i2cWrite  coef write 5143
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002a, 0x00000000, 5147 ); // i2cWrite  coef write 5147
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0111, 0x00000000, 5151 ); // i2cWrite  coef write 5151
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5155 ); // i2cWrite  coef read 5155
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5159 ); // i2cWrite  coef read 5159
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5163 ); // i2cWrite  coef read 5163
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5167 ); // i2cWrite  coef write 5167
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2a i2c            reg 0x0348 i2c data 0x0048   reg anal: DACVolume               : -3.0dB
        //cs_8409_vendor_i2cWrite(codec, 0x2a, 0x0003, 0x0048, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5174 ); // i2cWrite  coef read 5174
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5178 ); // i2cWrite  coef write 5178
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002a, 0x00000000, 5182 ); // i2cWrite  coef write 5182
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0348, 0x00000000, 5186 ); // i2cWrite  coef write 5186
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5190 ); // i2cWrite  coef read 5190
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5194 ); // i2cWrite  coef read 5194
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5198 ); // i2cWrite  coef read 5198
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5202 ); // i2cWrite  coef write 5202
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2a i2c            reg 0x0451 i2c data 0x0051   reg anal: SAIControl1             : TDMPCMMode 24 BClks per Chip Delay1 PulsedSync Falling
        //cs_8409_vendor_i2cWrite(codec, 0x2a, 0x0004, 0x0051, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5209 ); // i2cWrite  coef read 5209
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5213 ); // i2cWrite  coef write 5213
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002a, 0x00000000, 5217 ); // i2cWrite  coef write 5217
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0451, 0x00000000, 5221 ); // i2cWrite  coef write 5221
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5225 ); // i2cWrite  coef read 5225
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5229 ); // i2cWrite  coef read 5229
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5233 ); // i2cWrite  coef read 5233
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5237 ); // i2cWrite  coef write 5237
//      snd_hda i2cWrite end

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x2a i2c            reg 0x0200 i2c data 0x0232   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cRead(codec, 0x2a, 0x0002, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5244 ); // i2cRead  coef read 5244
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5248 ); // i2cRead  coef write 5248
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002a, 0x00000000, 5252 ); // i2cRead  coef write 5252
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0200, 0x00000000, 5256 ); // i2cRead  coef write 5256
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5260 ); // i2cRead  coef read 5260
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5264 ); // i2cRead  coef read 5264
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000232, 5268 ); // i2cRead  coef read 5268
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5272 ); // i2cRead  coef read 5272
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5276 ); // i2cRead  coef write 5276
//      snd_hda i2cRead end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2a i2c            reg 0x0232 i2c data 0x0032   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cWrite(codec, 0x2a, 0x0002, 0x0032, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5283 ); // i2cWrite  coef read 5283
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5287 ); // i2cWrite  coef write 5287
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002a, 0x00000000, 5291 ); // i2cWrite  coef write 5291
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0232, 0x00000000, 5295 ); // i2cWrite  coef write 5295
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5299 ); // i2cWrite  coef read 5299
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5303 ); // i2cWrite  coef read 5303
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5307 ); // i2cWrite  coef read 5307
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5311 ); // i2cWrite  coef write 5311
//      snd_hda i2cWrite end

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x2a i2c            reg 0x0200 i2c data 0x0232   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cRead(codec, 0x2a, 0x0002, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5318 ); // i2cRead  coef read 5318
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5322 ); // i2cRead  coef write 5322
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002a, 0x00000000, 5326 ); // i2cRead  coef write 5326
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0200, 0x00000000, 5330 ); // i2cRead  coef write 5330
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5334 ); // i2cRead  coef read 5334
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5338 ); // i2cRead  coef read 5338
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000232, 5342 ); // i2cRead  coef read 5342
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5346 ); // i2cRead  coef read 5346
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5350 ); // i2cRead  coef write 5350
//      snd_hda i2cRead end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2a i2c            reg 0x0232 i2c data 0x0032   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cWrite(codec, 0x2a, 0x0002, 0x0032, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5357 ); // i2cWrite  coef read 5357
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5361 ); // i2cWrite  coef write 5361
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002a, 0x00000000, 5365 ); // i2cWrite  coef write 5365
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0232, 0x00000000, 5369 ); // i2cWrite  coef write 5369
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5373 ); // i2cWrite  coef read 5373
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5377 ); // i2cWrite  coef read 5377
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5381 ); // i2cWrite  coef read 5381
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5385 ); // i2cWrite  coef write 5385
//      snd_hda i2cWrite end

}

static void setup_TDM_2c2e_ssm3(struct hda_codec *codec)
{
        int retval;

        // so this seems to be where we see the same code as in unmute and volup
        // this seems to be setup for node 0x03 chain - which seems to use node 0x25 and amps 0x2e and 0x2c


        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004033); // 0x00324033
//      snd_hda:     stream format 3 [('CHAN', 4), ('RATE', 44100), ('BITS', 24), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000002); // 0x00370602
//      snd_hda:     conv stream channel map 3 [('CHAN', 2), ('STREAMID', 0)]

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001b, 0x0000, 0x00008000, 5395 ); //   coef read 5395
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001b, 0x0840, 0x00000000, 5399 ); //   coef write 5399
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001c, 0x0000, 0x00008000, 5403 ); //   coef read 5403
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001c, 0x0860, 0x00000000, 5407 ); //   coef write 5407

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: AppleHDATDMBusManagerCS8409::tdmInUse:
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00000800, 5411 ); //   coef read 5411

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: 
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006b, 0x001f, 0x00000000, 5416 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 5416
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x0000400f, 5420 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef read 5420
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x400f, 0x00000000, 5424 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 5424

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00b6 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  write verb 5427


        // enable output on node 0x25

        retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 5431); // 0x025f0700
        snd_hda_codec_write(codec, 0x25, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000040); // 0x02570740
//      snd_hda:     37 ['AC_PINCTL_OUT_EN']

}


static void setup_amps_2c2e_ssm3(struct hda_codec *codec)
{
        //int retval;


//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2c i2c            reg 0x0502 i2c data 0x0002   reg anal: SAIControl2             : ChipSlot 3 SlotByTDMRReg 24 bit Audio
        //cs_8409_vendor_i2cWrite(codec, 0x2c, 0x0005, 0x0002, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5435 ); // i2cWrite  coef read 5435
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5439 ); // i2cWrite  coef write 5439
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002c, 0x00000000, 5443 ); // i2cWrite  coef write 5443
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0502, 0x00000000, 5447 ); // i2cWrite  coef write 5447
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5451 ); // i2cWrite  coef read 5451
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5455 ); // i2cWrite  coef read 5455
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5459 ); // i2cWrite  coef read 5459
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5463 ); // i2cWrite  coef write 5463
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2c i2c            reg 0x0111 i2c data 0x0011   reg anal: GainEdgeControl         : 12.6V FSGainMap LowEMI
        //cs_8409_vendor_i2cWrite(codec, 0x2c, 0x0001, 0x0011, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5470 ); // i2cWrite  coef read 5470
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5474 ); // i2cWrite  coef write 5474
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002c, 0x00000000, 5478 ); // i2cWrite  coef write 5478
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0111, 0x00000000, 5482 ); // i2cWrite  coef write 5482
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5486 ); // i2cWrite  coef read 5486
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5490 ); // i2cWrite  coef read 5490
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5494 ); // i2cWrite  coef read 5494
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5498 ); // i2cWrite  coef write 5498
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2c i2c            reg 0x0348 i2c data 0x0048   reg anal: DACVolume               : -3.0dB
        //cs_8409_vendor_i2cWrite(codec, 0x2c, 0x0003, 0x0048, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5505 ); // i2cWrite  coef read 5505
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5509 ); // i2cWrite  coef write 5509
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002c, 0x00000000, 5513 ); // i2cWrite  coef write 5513
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0348, 0x00000000, 5517 ); // i2cWrite  coef write 5517
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5521 ); // i2cWrite  coef read 5521
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5525 ); // i2cWrite  coef read 5525
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5529 ); // i2cWrite  coef read 5529
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5533 ); // i2cWrite  coef write 5533
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2c i2c            reg 0x0451 i2c data 0x0051   reg anal: SAIControl1             : TDMPCMMode 24 BClks per Chip Delay1 PulsedSync Falling
        //cs_8409_vendor_i2cWrite(codec, 0x2c, 0x0004, 0x0051, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5540 ); // i2cWrite  coef read 5540
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5544 ); // i2cWrite  coef write 5544
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002c, 0x00000000, 5548 ); // i2cWrite  coef write 5548
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0451, 0x00000000, 5552 ); // i2cWrite  coef write 5552
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5556 ); // i2cWrite  coef read 5556
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5560 ); // i2cWrite  coef read 5560
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5564 ); // i2cWrite  coef read 5564
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5568 ); // i2cWrite  coef write 5568
//      snd_hda i2cWrite end

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x2c i2c            reg 0x0200 i2c data 0x0232   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cRead(codec, 0x2c, 0x0002, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5575 ); // i2cRead  coef read 5575
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5579 ); // i2cRead  coef write 5579
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002c, 0x00000000, 5583 ); // i2cRead  coef write 5583
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0200, 0x00000000, 5587 ); // i2cRead  coef write 5587
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5591 ); // i2cRead  coef read 5591
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5595 ); // i2cRead  coef read 5595
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000232, 5599 ); // i2cRead  coef read 5599
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5603 ); // i2cRead  coef read 5603
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5607 ); // i2cRead  coef write 5607
//      snd_hda i2cRead end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2c i2c            reg 0x0232 i2c data 0x0032   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cWrite(codec, 0x2c, 0x0002, 0x0032, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5614 ); // i2cWrite  coef read 5614
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5618 ); // i2cWrite  coef write 5618
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002c, 0x00000000, 5622 ); // i2cWrite  coef write 5622
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0232, 0x00000000, 5626 ); // i2cWrite  coef write 5626
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5630 ); // i2cWrite  coef read 5630
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5634 ); // i2cWrite  coef read 5634
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5638 ); // i2cWrite  coef read 5638
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5642 ); // i2cWrite  coef write 5642
//      snd_hda i2cWrite end

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x2c i2c            reg 0x0200 i2c data 0x0232   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cRead(codec, 0x2c, 0x0002, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5649 ); // i2cRead  coef read 5649
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5653 ); // i2cRead  coef write 5653
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002c, 0x00000000, 5657 ); // i2cRead  coef write 5657
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0200, 0x00000000, 5661 ); // i2cRead  coef write 5661
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5665 ); // i2cRead  coef read 5665
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5669 ); // i2cRead  coef read 5669
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000232, 5673 ); // i2cRead  coef read 5673
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5677 ); // i2cRead  coef read 5677
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5681 ); // i2cRead  coef write 5681
//      snd_hda i2cRead end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2c i2c            reg 0x0232 i2c data 0x0032   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cWrite(codec, 0x2c, 0x0002, 0x0032, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5688 ); // i2cWrite  coef read 5688
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5692 ); // i2cWrite  coef write 5692
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002c, 0x00000000, 5696 ); // i2cWrite  coef write 5696
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0232, 0x00000000, 5700 ); // i2cWrite  coef write 5700
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5704 ); // i2cWrite  coef read 5704
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5708 ); // i2cWrite  coef read 5708
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5712 ); // i2cWrite  coef read 5712
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5716 ); // i2cWrite  coef write 5716
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2e i2c            reg 0x0503 i2c data 0x0003   reg anal: SAIControl2             : ChipSlot 4 SlotByTDMRReg 24 bit Audio
        //cs_8409_vendor_i2cWrite(codec, 0x2e, 0x0005, 0x0003, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5723 ); // i2cWrite  coef read 5723
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5727 ); // i2cWrite  coef write 5727
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002e, 0x00000000, 5731 ); // i2cWrite  coef write 5731
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0503, 0x00000000, 5735 ); // i2cWrite  coef write 5735
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5739 ); // i2cWrite  coef read 5739
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5743 ); // i2cWrite  coef read 5743
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5747 ); // i2cWrite  coef read 5747
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5751 ); // i2cWrite  coef write 5751
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2e i2c            reg 0x0111 i2c data 0x0011   reg anal: GainEdgeControl         : 12.6V FSGainMap LowEMI
        //cs_8409_vendor_i2cWrite(codec, 0x2e, 0x0001, 0x0011, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5758 ); // i2cWrite  coef read 5758
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5762 ); // i2cWrite  coef write 5762
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002e, 0x00000000, 5766 ); // i2cWrite  coef write 5766
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0111, 0x00000000, 5770 ); // i2cWrite  coef write 5770
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5774 ); // i2cWrite  coef read 5774
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5778 ); // i2cWrite  coef read 5778
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5782 ); // i2cWrite  coef read 5782
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5786 ); // i2cWrite  coef write 5786
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2e i2c            reg 0x0348 i2c data 0x0048   reg anal: DACVolume               : -3.0dB
        //cs_8409_vendor_i2cWrite(codec, 0x2e, 0x0003, 0x0048, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5793 ); // i2cWrite  coef read 5793
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5797 ); // i2cWrite  coef write 5797
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002e, 0x00000000, 5801 ); // i2cWrite  coef write 5801
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0348, 0x00000000, 5805 ); // i2cWrite  coef write 5805
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5809 ); // i2cWrite  coef read 5809
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5813 ); // i2cWrite  coef read 5813
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5817 ); // i2cWrite  coef read 5817
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5821 ); // i2cWrite  coef write 5821
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2e i2c            reg 0x0451 i2c data 0x0051   reg anal: SAIControl1             : TDMPCMMode 24 BClks per Chip Delay1 PulsedSync Falling
        //cs_8409_vendor_i2cWrite(codec, 0x2e, 0x0004, 0x0051, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5828 ); // i2cWrite  coef read 5828
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5832 ); // i2cWrite  coef write 5832
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002e, 0x00000000, 5836 ); // i2cWrite  coef write 5836
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0451, 0x00000000, 5840 ); // i2cWrite  coef write 5840
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5844 ); // i2cWrite  coef read 5844
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5848 ); // i2cWrite  coef read 5848
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5852 ); // i2cWrite  coef read 5852
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5856 ); // i2cWrite  coef write 5856
//      snd_hda i2cWrite end

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x2e i2c            reg 0x0200 i2c data 0x0232   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cRead(codec, 0x2e, 0x0002, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5863 ); // i2cRead  coef read 5863
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5867 ); // i2cRead  coef write 5867
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002e, 0x00000000, 5871 ); // i2cRead  coef write 5871
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0200, 0x00000000, 5875 ); // i2cRead  coef write 5875
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5879 ); // i2cRead  coef read 5879
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5883 ); // i2cRead  coef read 5883
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000232, 5887 ); // i2cRead  coef read 5887
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5891 ); // i2cRead  coef read 5891
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5895 ); // i2cRead  coef write 5895
//      snd_hda i2cRead end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2e i2c            reg 0x0232 i2c data 0x0032   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cWrite(codec, 0x2e, 0x0002, 0x0032, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5902 ); // i2cWrite  coef read 5902
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5906 ); // i2cWrite  coef write 5906
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002e, 0x00000000, 5910 ); // i2cWrite  coef write 5910
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0232, 0x00000000, 5914 ); // i2cWrite  coef write 5914
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5918 ); // i2cWrite  coef read 5918
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5922 ); // i2cWrite  coef read 5922
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5926 ); // i2cWrite  coef read 5926
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5930 ); // i2cWrite  coef write 5930
//      snd_hda i2cWrite end

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x2e i2c            reg 0x0200 i2c data 0x0232   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cRead(codec, 0x2e, 0x0002, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5937 ); // i2cRead  coef read 5937
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5941 ); // i2cRead  coef write 5941
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002e, 0x00000000, 5945 ); // i2cRead  coef write 5945
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0200, 0x00000000, 5949 ); // i2cRead  coef write 5949
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5953 ); // i2cRead  coef read 5953
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5957 ); // i2cRead  coef read 5957
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000232, 5961 ); // i2cRead  coef read 5961
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 5965 ); // i2cRead  coef read 5965
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 5969 ); // i2cRead  coef write 5969
//      snd_hda i2cRead end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2e i2c            reg 0x0232 i2c data 0x0032   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cWrite(codec, 0x2e, 0x0002, 0x0032, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 5976 ); // i2cWrite  coef read 5976
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 5980 ); // i2cWrite  coef write 5980
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002e, 0x00000000, 5984 ); // i2cWrite  coef write 5984
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0232, 0x00000000, 5988 ); // i2cWrite  coef write 5988
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5992 ); // i2cWrite  coef read 5992
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 5996 ); // i2cWrite  coef read 5996
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 6000 ); // i2cWrite  coef read 6000
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6004 ); // i2cWrite  coef write 6004
//      snd_hda i2cWrite end

}

static void sync_converters_ssm3(struct hda_codec *codec)
{
        int retval;


//      snd_hda: # AppleHDAFunctionGroupCS8409::syncConverters: 
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301

        // remove normal channel mapping

//      snd_hda: # AppleHDAFunctionGroupCS8409::syncConverters: 
        retval = snd_hda_codec_read_check(codec, 0x02, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000000, 6010); // 0x002f0600
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00270600
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0001, 0x00000000, 6012 ); // coef write mask 6012
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0001, 0xundef, 0x00000000, 6012 ); // coef write mask 6012

//      snd_hda: # AppleHDAFunctionGroupCS8409::syncConverters: 
        retval = snd_hda_codec_read_check(codec, 0x03, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000002, 6018); // 0x003f0600
//      snd_hda:     conv stream channel map 3 [('CHAN', 2), ('STREAMID', 0)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00370600
//      snd_hda:     conv stream channel map 3 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0003, 0x00000001, 6020 ); // coef write mask 6020
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0003, 0xundef, 0x00000001, 6020 ); // coef write mask 6020


        // and reset back to normal channel mapping

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00270600
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000002); // 0x00370602
//      snd_hda:     conv stream channel map 3 [('CHAN', 2), ('STREAMID', 0)]

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}

static void sync_converters1_ssm3(struct hda_codec *codec)
{
        int retval;

        // this has some differences from the above
        // is this for disabling?? desyncing doesnt seem to be the right name


        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301

//      snd_hda: # AppleHDAFunctionGroupCS8409::syncConverters: 
        retval = snd_hda_codec_read_check(codec, 0x02, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000000, 6036); // 0x002f0600
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00270600
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0002, 0x00000003, 6038 ); // coef write mask 6038
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0002, 0xundef, 0x00000003, 6038 ); // coef write mask 6038

//      snd_hda: # AppleHDAFunctionGroupCS8409::syncConverters: 
        retval = snd_hda_codec_read_check(codec, 0x03, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000000, 6044); // 0x003f0600
//      snd_hda:     conv stream channel map 3 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00370600
//      snd_hda:     conv stream channel map 3 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0000, 0x00000002, 6046 ); // coef write mask 6046
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0000, 0xundef, 0x00000002, 6046 ); // coef write mask 6046

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0017, 0x0000, 0x00000000, 6052 ); //   coef read 6052
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0018, 0x0000, 0x00000000, 6056 ); //   coef read 6056

        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0001, 0x0220, 0x00000220, 6060 ); // coef write mask 6060
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0001, 0x0220, 0xundef, 0x00000220, 6060 ); // coef write mask 6060

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00270600
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00370600
//      snd_hda:     conv stream channel map 3 [('CHAN', 0), ('STREAMID', 0)]

}


static void amps_disable_282a_ssm3(struct hda_codec *codec)
{
        //int retval;

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x28 i2c            reg 0x0001 i2c data 0x0001   reg anal: PowerControl            : PowerDown BVSenseOn
        //cs_8409_vendor_i2cWrite(codec, 0x28, 0x0000, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6070 ); // i2cWrite  coef read 6070
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6074 ); // i2cWrite  coef write 6074
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0028, 0x00000000, 6078 ); // i2cWrite  coef write 6078
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0001, 0x00000000, 6082 ); // i2cWrite  coef write 6082
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6086 ); // i2cWrite  coef read 6086
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6090 ); // i2cWrite  coef read 6090
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 6094 ); // i2cWrite  coef read 6094
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6098 ); // i2cWrite  coef write 6098
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2a i2c            reg 0x0001 i2c data 0x0001   reg anal: PowerControl            : PowerDown BVSenseOn
        //cs_8409_vendor_i2cWrite(codec, 0x2a, 0x0000, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6105 ); // i2cWrite  coef read 6105
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6109 ); // i2cWrite  coef write 6109
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002a, 0x00000000, 6113 ); // i2cWrite  coef write 6113
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0001, 0x00000000, 6117 ); // i2cWrite  coef write 6117
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6121 ); // i2cWrite  coef read 6121
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6125 ); // i2cWrite  coef read 6125
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 6129 ); // i2cWrite  coef read 6129
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6133 ); // i2cWrite  coef write 6133
//      snd_hda i2cWrite end

}

static void putative_tdm_disable_282a_ssm3(struct hda_codec *codec)
{
        int retval;

        // this could be disabling the TDM

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00000800, 6139 ); //   coef read 6139
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0019, 0x8800, 0x00000000, 6143 ); //   coef write 6143

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001a, 0x0000, 0x00000820, 6147 ); //   coef read 6147
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001a, 0x8820, 0x00000000, 6151 ); //   coef write 6151

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: AppleHDATDMBusManagerCS8409::tdmInUse:
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00008800, 6155 ); //   coef read 6155
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001a, 0x0000, 0x00008820, 6159 ); //   coef read 6159
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001b, 0x0000, 0x00000840, 6163 ); //   coef read 6163

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: 
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006b, 0x001f, 0x00000000, 6168 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 6168
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x0000400f, 6172 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef read 6172
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x400f, 0x00000000, 6176 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 6176

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00b6 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  write verb 6179


        // set to defaults and disable output

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00270600
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_STREAM_FORMAT, 0x00000000); // 0x00220000
//      snd_hda:     stream format 2 [('CHAN', 1), ('RATE', 48000), ('BITS', 8), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000040, 6185); // 0x024f0700
        snd_hda_codec_write(codec, 0x24, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x02470700
//      snd_hda:     36 []

}


static void amps_disable_2c2e_ssm3(struct hda_codec *codec)
{
        //int retval;


//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2c i2c            reg 0x0001 i2c data 0x0001   reg anal: PowerControl            : PowerDown BVSenseOn
        //cs_8409_vendor_i2cWrite(codec, 0x2c, 0x0000, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6189 ); // i2cWrite  coef read 6189
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6193 ); // i2cWrite  coef write 6193
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002c, 0x00000000, 6197 ); // i2cWrite  coef write 6197
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0001, 0x00000000, 6201 ); // i2cWrite  coef write 6201
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6205 ); // i2cWrite  coef read 6205
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6209 ); // i2cWrite  coef read 6209
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 6213 ); // i2cWrite  coef read 6213
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6217 ); // i2cWrite  coef write 6217
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2e i2c            reg 0x0001 i2c data 0x0001   reg anal: PowerControl            : PowerDown BVSenseOn
        //cs_8409_vendor_i2cWrite(codec, 0x2e, 0x0000, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6224 ); // i2cWrite  coef read 6224
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6228 ); // i2cWrite  coef write 6228
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002e, 0x00000000, 6232 ); // i2cWrite  coef write 6232
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0001, 0x00000000, 6236 ); // i2cWrite  coef write 6236
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6240 ); // i2cWrite  coef read 6240
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6244 ); // i2cWrite  coef read 6244
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 6248 ); // i2cWrite  coef read 6248
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6252 ); // i2cWrite  coef write 6252
//      snd_hda i2cWrite end

}

static void putative_tdm_disable_2c2e_ssm3(struct hda_codec *codec)
{
        int retval;

        // this could be disabling the TDM

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001b, 0x0000, 0x00000840, 6258 ); //   coef read 6258
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001b, 0x8840, 0x00000000, 6262 ); //   coef write 6262
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001c, 0x0000, 0x00000860, 6266 ); //   coef read 6266
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001c, 0x8860, 0x00000000, 6270 ); //   coef write 6270

        // AppleHDATDMBusManagerCS8409::setupTDMPath or AppleHDATDMBusManagerCS8409::disableTDMPath
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0082, 0x0001, 0x00005401, 6274 ); // coef write mask 6274
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0082, 0x0001, 0xundef, 0x00005401, 6274 ); // coef write mask 6274

        // AppleHDATDMBusManagerCS8409::setupTDMPath or AppleHDATDMBusManagerCS8409::disableTDMPath
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000220, 6280 ); //   coef read 6280
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, 0x0200, 0x00000000, 6284 ); //   coef write 6284

        // AppleHDATDMBusManagerCS8409::setupTDMPath or disableTDMPath calls AppleHDATDMBusManagerCS8409::configureTDMUR
        // AppleHDATDMBusManagerCS8409::configureTDMUR only place calls this
        // this is AppleHDATDMBusManagerCS8409::tdmInUse
        // which reads from 0x19 to 0x57 in a loop if the snd_hda_coef_item returns 0 till the read value
        // does not have the word sign bit set (ie 0x8000) or finish all 0x57

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00008800, 6288 ); //   coef read 6288
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001a, 0x0000, 0x00008820, 6292 ); //   coef read 6292
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001b, 0x0000, 0x00008840, 6296 ); //   coef read 6296
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001c, 0x0000, 0x00008860, 6300 ); //   coef read 6300
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001d, 0x0000, 0x00008000, 6304 ); //   coef read 6304
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001e, 0x0000, 0x00008000, 6308 ); //   coef read 6308
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001f, 0x0000, 0x00008000, 6312 ); //   coef read 6312
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0020, 0x0000, 0x00008000, 6316 ); //   coef read 6316
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0021, 0x0000, 0x00008000, 6320 ); //   coef read 6320
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0022, 0x0000, 0x00008000, 6324 ); //   coef read 6324
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0023, 0x0000, 0x00008000, 6328 ); //   coef read 6328
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0024, 0x0000, 0x00008000, 6332 ); //   coef read 6332
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0025, 0x0000, 0x00008000, 6336 ); //   coef read 6336
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0026, 0x0000, 0x00008000, 6340 ); //   coef read 6340
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0027, 0x0000, 0x00008000, 6344 ); //   coef read 6344
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0028, 0x0000, 0x00008000, 6348 ); //   coef read 6348
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0029, 0x0000, 0x00008000, 6352 ); //   coef read 6352
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002a, 0x0000, 0x00008000, 6356 ); //   coef read 6356
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002b, 0x0000, 0x00008000, 6360 ); //   coef read 6360
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002c, 0x0000, 0x00008000, 6364 ); //   coef read 6364
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002d, 0x0000, 0x00008000, 6368 ); //   coef read 6368
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002e, 0x0000, 0x00008000, 6372 ); //   coef read 6372
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002f, 0x0000, 0x00008000, 6376 ); //   coef read 6376
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0030, 0x0000, 0x00008000, 6380 ); //   coef read 6380
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0031, 0x0000, 0x00008000, 6384 ); //   coef read 6384
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0032, 0x0000, 0x00008000, 6388 ); //   coef read 6388
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0033, 0x0000, 0x00008000, 6392 ); //   coef read 6392
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0034, 0x0000, 0x00008000, 6396 ); //   coef read 6396
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0035, 0x0000, 0x00008000, 6400 ); //   coef read 6400
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0036, 0x0000, 0x00008000, 6404 ); //   coef read 6404
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0037, 0x0000, 0x00008000, 6408 ); //   coef read 6408
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0038, 0x0000, 0x00008000, 6412 ); //   coef read 6412
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0039, 0x0000, 0x00008000, 6416 ); //   coef read 6416
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003a, 0x0000, 0x00008000, 6420 ); //   coef read 6420
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003b, 0x0000, 0x00008000, 6424 ); //   coef read 6424
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003c, 0x0000, 0x00008000, 6428 ); //   coef read 6428
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003d, 0x0000, 0x00008000, 6432 ); //   coef read 6432
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003e, 0x0000, 0x00008000, 6436 ); //   coef read 6436
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003f, 0x0000, 0x00008000, 6440 ); //   coef read 6440
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0040, 0x0000, 0x00008000, 6444 ); //   coef read 6444
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0041, 0x0000, 0x00008000, 6448 ); //   coef read 6448
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0042, 0x0000, 0x00008000, 6452 ); //   coef read 6452
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0043, 0x0000, 0x00008000, 6456 ); //   coef read 6456
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0044, 0x0000, 0x00008000, 6460 ); //   coef read 6460
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0045, 0x0000, 0x00008000, 6464 ); //   coef read 6464
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0046, 0x0000, 0x00008000, 6468 ); //   coef read 6468
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0047, 0x0000, 0x00008000, 6472 ); //   coef read 6472
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0048, 0x0000, 0x00008000, 6476 ); //   coef read 6476
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0049, 0x0000, 0x00008000, 6480 ); //   coef read 6480
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004a, 0x0000, 0x00008000, 6484 ); //   coef read 6484
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004b, 0x0000, 0x00008000, 6488 ); //   coef read 6488
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004c, 0x0000, 0x00008000, 6492 ); //   coef read 6492
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004d, 0x0000, 0x00008000, 6496 ); //   coef read 6496
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004e, 0x0000, 0x00008000, 6500 ); //   coef read 6500
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004f, 0x0000, 0x00008000, 6504 ); //   coef read 6504
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0050, 0x0000, 0x00008000, 6508 ); //   coef read 6508
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0051, 0x0000, 0x00008000, 6512 ); //   coef read 6512
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0052, 0x0000, 0x00008000, 6516 ); //   coef read 6516
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0053, 0x0000, 0x00008000, 6520 ); //   coef read 6520
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0054, 0x0000, 0x00008000, 6524 ); //   coef read 6524
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0055, 0x0000, 0x00008000, 6528 ); //   coef read 6528
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0056, 0x0000, 0x00008000, 6532 ); //   coef read 6532
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0057, 0x0000, 0x00008000, 6536 ); //   coef read 6536

        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x00000000, 6541 ); //   coef write 6541

        // this is new - setting to 0
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00000000);


        // set to defaults and disable output

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00370600
//      snd_hda:     conv stream channel map 3 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_STREAM_FORMAT, 0x00000000); // 0x00320000
//      snd_hda:     stream format 3 [('CHAN', 1), ('RATE', 48000), ('BITS', 8), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000040, 6550); // 0x025f0700
        snd_hda_codec_write(codec, 0x25, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x02570700
//      snd_hda:     37 []

}

static void putative_enable2_TDM_282a_ssm3(struct hda_codec *codec)
{
        //int retval;


        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004033); // 0x00224033
//      snd_hda:     stream format 2 [('CHAN', 4), ('RATE', 44100), ('BITS', 24), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000200, 6555 ); //   coef read 6555
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, 0x0200, 0x00000000, 6559 ); //   coef write 6559

//      snd_hda: # AppleHDATDMBusManagerCS8409::setSampleRate: 
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0001, 0x0200, 0x00000200, 6564 ); // coef write mask 6564
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0005, 0x0001, 0x00000001, 6570 ); // coef write mask 6570
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0004, 0x08ff, 0x000008ff, 6576 ); // coef write mask 6576
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0001, 0x0200, 0xundef, 0x00000200, 6564 ); // coef write mask 6564
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0005, 0x0001, 0xundef, 0x00000001, 6570 ); // coef write mask 6570
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0004, 0x08ff, 0xundef, 0x000008ff, 6576 ); // coef write mask 6576

//      snd_hda: # AppleHDATDMBusManagerCS8409::setupTDMPath: 
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00008800, 6583 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 6583
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0019, 0x0800, 0x00000000, 6587 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 6587
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001a, 0x0000, 0x00008820, 6591 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 6591
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001a, 0x0820, 0x00000000, 6595 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 6595

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6599 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 6599
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0xb000, 0x00000000, 6603 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 6603
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0004, 0x0000, 0x000008ff, 6607 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 6607
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0004, 0x08ff, 0x00000000, 6611 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 6611
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6615 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 6615

        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0003, 0x8000, 0x00008000, 6619 ); // coef write mask 6619
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0005, 0x0001, 0x00000001, 6625 ); // coef write mask 6625
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0082, 0x5401, 0x00000001, 6631 ); // coef write mask 6631
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0002, 0x0280, 0x00000280, 6637 ); // coef write mask 6637
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0003, 0x8000, 0xundef, 0x00008000, 6619 ); // coef write mask 6619
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0005, 0x0001, 0xundef, 0x00000001, 6625 ); // coef write mask 6625
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0082, 0x5401, 0xundef, 0x00000001, 6631 ); // coef write mask 6631
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0002, 0x0280, 0xundef, 0x00000280, 6637 ); // coef write mask 6637

        // AppleHDATDMBusManagerCS8409::setupTDMPath or AppleHDATDMBusManagerCS8409::disableTDMPath
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000200, 6643 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 6643
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, 0x0220, 0x00000000, 6647 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 6647

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: AppleHDATDMBusManagerCS8409::tdmInUse:
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00000800, 6651 ); //   coef read 6651

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: 
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006b, 0x001f, 0x00000000, 6656 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 6656
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x00000000, 6660 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef read 6660
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x400f, 0x00000000, 6664 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 6664

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00b6 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  write verb 6667

}


static void amps_disable2_282a_ssm3(struct hda_codec *codec)
{
        //int retval;

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x28 i2c            reg 0x0001 i2c data 0x0001   reg anal: PowerControl            : PowerDown BVSenseOn
        //cs_8409_vendor_i2cWrite(codec, 0x28, 0x0000, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6673 ); // i2cWrite  coef read 6673
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6677 ); // i2cWrite  coef write 6677
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0028, 0x00000000, 6681 ); // i2cWrite  coef write 6681
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0001, 0x00000000, 6685 ); // i2cWrite  coef write 6685
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6689 ); // i2cWrite  coef read 6689
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6693 ); // i2cWrite  coef read 6693
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 6697 ); // i2cWrite  coef read 6697
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6701 ); // i2cWrite  coef write 6701
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2a i2c            reg 0x0001 i2c data 0x0001   reg anal: PowerControl            : PowerDown BVSenseOn
        //cs_8409_vendor_i2cWrite(codec, 0x2a, 0x0000, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6708 ); // i2cWrite  coef read 6708
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6712 ); // i2cWrite  coef write 6712
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002a, 0x00000000, 6716 ); // i2cWrite  coef write 6716
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0001, 0x00000000, 6720 ); // i2cWrite  coef write 6720
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6724 ); // i2cWrite  coef read 6724
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6728 ); // i2cWrite  coef read 6728
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 6732 ); // i2cWrite  coef read 6732
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6736 ); // i2cWrite  coef write 6736
//      snd_hda i2cWrite end

}

static void putative_enable2_TDM_2c2e_ssm3(struct hda_codec *codec)
{

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004033); // 0x00324033
//      snd_hda:     stream format 3 [('CHAN', 4), ('RATE', 44100), ('BITS', 24), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001b, 0x0000, 0x00008840, 6745 ); //   coef read 6745
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001b, 0x0840, 0x00000000, 6749 ); //   coef write 6749
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001c, 0x0000, 0x00008860, 6753 ); //   coef read 6753
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001c, 0x0860, 0x00000000, 6757 ); //   coef write 6757

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: AppleHDATDMBusManagerCS8409::tdmInUse:
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00000800, 6761 ); //   coef read 6761

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: 
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006b, 0x001f, 0x00000000, 6766 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 6766
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x0000400f, 6770 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef read 6770
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x400f, 0x00000000, 6774 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 6774

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00b6 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  write verb 6777

}

static void amps_disable2_2c2e_ssm3(struct hda_codec *codec)
{
        //int retval;

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2c i2c            reg 0x0001 i2c data 0x0001   reg anal: PowerControl            : PowerDown BVSenseOn
        //cs_8409_vendor_i2cWrite(codec, 0x2c, 0x0000, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6783 ); // i2cWrite  coef read 6783
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6787 ); // i2cWrite  coef write 6787
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002c, 0x00000000, 6791 ); // i2cWrite  coef write 6791
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0001, 0x00000000, 6795 ); // i2cWrite  coef write 6795
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6799 ); // i2cWrite  coef read 6799
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6803 ); // i2cWrite  coef read 6803
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 6807 ); // i2cWrite  coef read 6807
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6811 ); // i2cWrite  coef write 6811
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2e i2c            reg 0x0001 i2c data 0x0001   reg anal: PowerControl            : PowerDown BVSenseOn
        //cs_8409_vendor_i2cWrite(codec, 0x2e, 0x0000, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6818 ); // i2cWrite  coef read 6818
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6822 ); // i2cWrite  coef write 6822
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002e, 0x00000000, 6826 ); // i2cWrite  coef write 6826
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0001, 0x00000000, 6830 ); // i2cWrite  coef write 6830
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6834 ); // i2cWrite  coef read 6834
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6838 ); // i2cWrite  coef read 6838
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 6842 ); // i2cWrite  coef read 6842
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6846 ); // i2cWrite  coef write 6846
//      snd_hda i2cWrite end

}

static void sync_converters2_ssm3(struct hda_codec *codec)
{
        int retval;

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301

//      snd_hda: # AppleHDAFunctionGroupCS8409::syncConverters: 
        retval = snd_hda_codec_read_check(codec, 0x02, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000000, 6852); // 0x002f0600
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00270600
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0001, 0x00000000, 6854 ); // coef write mask 6854
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0001, 0xundef, 0x00000000, 6854 ); // coef write mask 6854

//      snd_hda: # AppleHDAFunctionGroupCS8409::syncConverters: 
        retval = snd_hda_codec_read_check(codec, 0x03, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000000, 6860); // 0x003f0600
//      snd_hda:     conv stream channel map 3 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00370600
//      snd_hda:     conv stream channel map 3 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0003, 0x00000001, 6862 ); // coef write mask 6862
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0003, 0xundef, 0x00000001, 6862 ); // coef write mask 6862

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00270600
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00370600
//      snd_hda:     conv stream channel map 3 [('CHAN', 0), ('STREAMID', 0)]
}


static void setup_TDM2_282a_ssm3(struct hda_codec *codec)
{
        int retval;

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004033); // 0x00224033
//      snd_hda:     stream format 2 [('CHAN', 4), ('RATE', 44100), ('BITS', 24), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000010); // 0x00270610
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 1)]


        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00000800, 6876 ); //   coef read 6876
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0019, 0x0800, 0x00000000, 6880 ); //   coef write 6880
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001a, 0x0000, 0x00000820, 6884 ); //   coef read 6884
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001a, 0x0820, 0x00000000, 6888 ); //   coef write 6888

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: AppleHDATDMBusManagerCS8409::tdmInUse:
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00000800, 6892 ); //   coef read 6892
//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: 
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006b, 0x001f, 0x00000000, 6897 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 6897
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x0000400f, 6901 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef read 6901
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x400f, 0x00000000, 6905 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 6905

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00b6 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  write verb 6908

        retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 6912); // 0x024f0700
        snd_hda_codec_write(codec, 0x24, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000040); // 0x02470740
//      snd_hda:     36 ['AC_PINCTL_OUT_EN']

}

static void amps_enable2_282a_ssm3(struct hda_codec *codec)
{
        //int retval;

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x28 i2c            reg 0x0500 i2c data 0x0000   reg anal: SAIControl2             : ChipSlot 1 SlotByTDMRReg 24 bit Audio
        //cs_8409_vendor_i2cWrite(codec, 0x28, 0x0005, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6916 ); // i2cWrite  coef read 6916
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6920 ); // i2cWrite  coef write 6920
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0028, 0x00000000, 6924 ); // i2cWrite  coef write 6924
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0500, 0x00000000, 6928 ); // i2cWrite  coef write 6928
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6932 ); // i2cWrite  coef read 6932
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6936 ); // i2cWrite  coef read 6936
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 6940 ); // i2cWrite  coef read 6940
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6944 ); // i2cWrite  coef write 6944
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x28 i2c            reg 0x0111 i2c data 0x0011   reg anal: GainEdgeControl         : 12.6V FSGainMap LowEMI
        //cs_8409_vendor_i2cWrite(codec, 0x28, 0x0001, 0x0011, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6951 ); // i2cWrite  coef read 6951
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6955 ); // i2cWrite  coef write 6955
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0028, 0x00000000, 6959 ); // i2cWrite  coef write 6959
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0111, 0x00000000, 6963 ); // i2cWrite  coef write 6963
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6967 ); // i2cWrite  coef read 6967
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 6971 ); // i2cWrite  coef read 6971
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 6975 ); // i2cWrite  coef read 6975
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 6979 ); // i2cWrite  coef write 6979
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x28 i2c            reg 0x0348 i2c data 0x0048   reg anal: DACVolume               : -3.0dB
        //cs_8409_vendor_i2cWrite(codec, 0x28, 0x0003, 0x0048, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 6986 ); // i2cWrite  coef read 6986
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 6990 ); // i2cWrite  coef write 6990
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0028, 0x00000000, 6994 ); // i2cWrite  coef write 6994
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0348, 0x00000000, 6998 ); // i2cWrite  coef write 6998
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7002 ); // i2cWrite  coef read 7002
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7006 ); // i2cWrite  coef read 7006
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7010 ); // i2cWrite  coef read 7010
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7014 ); // i2cWrite  coef write 7014
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x28 i2c            reg 0x0451 i2c data 0x0051   reg anal: SAIControl1             : TDMPCMMode 24 BClks per Chip Delay1 PulsedSync Falling
        //cs_8409_vendor_i2cWrite(codec, 0x28, 0x0004, 0x0051, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7021 ); // i2cWrite  coef read 7021
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7025 ); // i2cWrite  coef write 7025
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0028, 0x00000000, 7029 ); // i2cWrite  coef write 7029
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0451, 0x00000000, 7033 ); // i2cWrite  coef write 7033
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7037 ); // i2cWrite  coef read 7037
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7041 ); // i2cWrite  coef read 7041
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7045 ); // i2cWrite  coef read 7045
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7049 ); // i2cWrite  coef write 7049
//      snd_hda i2cWrite end

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x28 i2c            reg 0x0200 i2c data 0x0232   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cRead(codec, 0x28, 0x0002, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7056 ); // i2cRead  coef read 7056
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7060 ); // i2cRead  coef write 7060
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0028, 0x00000000, 7064 ); // i2cRead  coef write 7064
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0200, 0x00000000, 7068 ); // i2cRead  coef write 7068
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7072 ); // i2cRead  coef read 7072
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7076 ); // i2cRead  coef read 7076
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000232, 7080 ); // i2cRead  coef read 7080
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7084 ); // i2cRead  coef read 7084
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7088 ); // i2cRead  coef write 7088
//      snd_hda i2cRead end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x28 i2c            reg 0x0232 i2c data 0x0032   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cWrite(codec, 0x28, 0x0002, 0x0032, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7095 ); // i2cWrite  coef read 7095
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7099 ); // i2cWrite  coef write 7099
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0028, 0x00000000, 7103 ); // i2cWrite  coef write 7103
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0232, 0x00000000, 7107 ); // i2cWrite  coef write 7107
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7111 ); // i2cWrite  coef read 7111
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7115 ); // i2cWrite  coef read 7115
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7119 ); // i2cWrite  coef read 7119
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7123 ); // i2cWrite  coef write 7123
//      snd_hda i2cWrite end

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x28 i2c            reg 0x0200 i2c data 0x0232   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cRead(codec, 0x28, 0x0002, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7130 ); // i2cRead  coef read 7130
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7134 ); // i2cRead  coef write 7134
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0028, 0x00000000, 7138 ); // i2cRead  coef write 7138
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0200, 0x00000000, 7142 ); // i2cRead  coef write 7142
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7146 ); // i2cRead  coef read 7146
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7150 ); // i2cRead  coef read 7150
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000232, 7154 ); // i2cRead  coef read 7154
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7158 ); // i2cRead  coef read 7158
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7162 ); // i2cRead  coef write 7162
//      snd_hda i2cRead end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x28 i2c            reg 0x0232 i2c data 0x0032   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cWrite(codec, 0x28, 0x0002, 0x0032, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7169 ); // i2cWrite  coef read 7169
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7173 ); // i2cWrite  coef write 7173
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0028, 0x00000000, 7177 ); // i2cWrite  coef write 7177
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0232, 0x00000000, 7181 ); // i2cWrite  coef write 7181
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7185 ); // i2cWrite  coef read 7185
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7189 ); // i2cWrite  coef read 7189
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7193 ); // i2cWrite  coef read 7193
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7197 ); // i2cWrite  coef write 7197
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2a i2c            reg 0x0501 i2c data 0x0001   reg anal: SAIControl2             : ChipSlot 2 SlotByTDMRReg 24 bit Audio
        //cs_8409_vendor_i2cWrite(codec, 0x2a, 0x0005, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7204 ); // i2cWrite  coef read 7204
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7208 ); // i2cWrite  coef write 7208
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002a, 0x00000000, 7212 ); // i2cWrite  coef write 7212
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0501, 0x00000000, 7216 ); // i2cWrite  coef write 7216
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7220 ); // i2cWrite  coef read 7220
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7224 ); // i2cWrite  coef read 7224
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7228 ); // i2cWrite  coef read 7228
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7232 ); // i2cWrite  coef write 7232
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2a i2c            reg 0x0111 i2c data 0x0011   reg anal: GainEdgeControl         : 12.6V FSGainMap LowEMI
        //cs_8409_vendor_i2cWrite(codec, 0x2a, 0x0001, 0x0011, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7239 ); // i2cWrite  coef read 7239
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7243 ); // i2cWrite  coef write 7243
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002a, 0x00000000, 7247 ); // i2cWrite  coef write 7247
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0111, 0x00000000, 7251 ); // i2cWrite  coef write 7251
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7255 ); // i2cWrite  coef read 7255
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7259 ); // i2cWrite  coef read 7259
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7263 ); // i2cWrite  coef read 7263
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7267 ); // i2cWrite  coef write 7267
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2a i2c            reg 0x0348 i2c data 0x0048   reg anal: DACVolume               : -3.0dB
        //cs_8409_vendor_i2cWrite(codec, 0x2a, 0x0003, 0x0048, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7274 ); // i2cWrite  coef read 7274
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7278 ); // i2cWrite  coef write 7278
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002a, 0x00000000, 7282 ); // i2cWrite  coef write 7282
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0348, 0x00000000, 7286 ); // i2cWrite  coef write 7286
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7290 ); // i2cWrite  coef read 7290
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7294 ); // i2cWrite  coef read 7294
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7298 ); // i2cWrite  coef read 7298
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7302 ); // i2cWrite  coef write 7302
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2a i2c            reg 0x0451 i2c data 0x0051   reg anal: SAIControl1             : TDMPCMMode 24 BClks per Chip Delay1 PulsedSync Falling
        //cs_8409_vendor_i2cWrite(codec, 0x2a, 0x0004, 0x0051, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7309 ); // i2cWrite  coef read 7309
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7313 ); // i2cWrite  coef write 7313
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002a, 0x00000000, 7317 ); // i2cWrite  coef write 7317
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0451, 0x00000000, 7321 ); // i2cWrite  coef write 7321
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7325 ); // i2cWrite  coef read 7325
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7329 ); // i2cWrite  coef read 7329
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7333 ); // i2cWrite  coef read 7333
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7337 ); // i2cWrite  coef write 7337
//      snd_hda i2cWrite end

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x2a i2c            reg 0x0200 i2c data 0x0232   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cRead(codec, 0x2a, 0x0002, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7344 ); // i2cRead  coef read 7344
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7348 ); // i2cRead  coef write 7348
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002a, 0x00000000, 7352 ); // i2cRead  coef write 7352
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0200, 0x00000000, 7356 ); // i2cRead  coef write 7356
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7360 ); // i2cRead  coef read 7360
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7364 ); // i2cRead  coef read 7364
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000232, 7368 ); // i2cRead  coef read 7368
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7372 ); // i2cRead  coef read 7372
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7376 ); // i2cRead  coef write 7376
//      snd_hda i2cRead end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2a i2c            reg 0x0232 i2c data 0x0032   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cWrite(codec, 0x2a, 0x0002, 0x0032, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7383 ); // i2cWrite  coef read 7383
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7387 ); // i2cWrite  coef write 7387
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002a, 0x00000000, 7391 ); // i2cWrite  coef write 7391
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0232, 0x00000000, 7395 ); // i2cWrite  coef write 7395
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7399 ); // i2cWrite  coef read 7399
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7403 ); // i2cWrite  coef read 7403
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7407 ); // i2cWrite  coef read 7407
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7411 ); // i2cWrite  coef write 7411
//      snd_hda i2cWrite end

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x2a i2c            reg 0x0200 i2c data 0x0232   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cRead(codec, 0x2a, 0x0002, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7418 ); // i2cRead  coef read 7418
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7422 ); // i2cRead  coef write 7422
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002a, 0x00000000, 7426 ); // i2cRead  coef write 7426
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0200, 0x00000000, 7430 ); // i2cRead  coef write 7430
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7434 ); // i2cRead  coef read 7434
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7438 ); // i2cRead  coef read 7438
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000232, 7442 ); // i2cRead  coef read 7442
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7446 ); // i2cRead  coef read 7446
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7450 ); // i2cRead  coef write 7450
//      snd_hda i2cRead end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2a i2c            reg 0x0232 i2c data 0x0032   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cWrite(codec, 0x2a, 0x0002, 0x0032, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7457 ); // i2cWrite  coef read 7457
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7461 ); // i2cWrite  coef write 7461
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002a, 0x00000000, 7465 ); // i2cWrite  coef write 7465
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0232, 0x00000000, 7469 ); // i2cWrite  coef write 7469
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7473 ); // i2cWrite  coef read 7473
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7477 ); // i2cWrite  coef read 7477
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7481 ); // i2cWrite  coef read 7481
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7485 ); // i2cWrite  coef write 7485
//      snd_hda i2cWrite end

}


static void setup_TDM2_2c2e_ssm3(struct hda_codec *codec)
{
        int retval;

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004033); // 0x00324033
//      snd_hda:     stream format 3 [('CHAN', 4), ('RATE', 44100), ('BITS', 24), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000012); // 0x00370612
//      snd_hda:     conv stream channel map 3 [('CHAN', 2), ('STREAMID', 1)]

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001b, 0x0000, 0x00000840, 7495 ); //   coef read 7495
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001b, 0x0840, 0x00000000, 7499 ); //   coef write 7499
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001c, 0x0000, 0x00000860, 7503 ); //   coef read 7503
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001c, 0x0860, 0x00000000, 7507 ); //   coef write 7507

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: AppleHDATDMBusManagerCS8409::tdmInUse:
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00000800, 7511 ); //   coef read 7511
//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: 
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006b, 0x001f, 0x00000000, 7516 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 7516
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x0000400f, 7520 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef read 7520
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x400f, 0x00000000, 7524 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 7524

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00b6 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  write verb 7527

        retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 7531); // 0x025f0700
        snd_hda_codec_write(codec, 0x25, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000040); // 0x02570740
//      snd_hda:     37 ['AC_PINCTL_OUT_EN']

}


static void amps_enable2_2c2e_ssm3(struct hda_codec *codec)
{
        //int retval;

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2c i2c            reg 0x0502 i2c data 0x0002   reg anal: SAIControl2             : ChipSlot 3 SlotByTDMRReg 24 bit Audio
        //cs_8409_vendor_i2cWrite(codec, 0x2c, 0x0005, 0x0002, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7535 ); // i2cWrite  coef read 7535
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7539 ); // i2cWrite  coef write 7539
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002c, 0x00000000, 7543 ); // i2cWrite  coef write 7543
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0502, 0x00000000, 7547 ); // i2cWrite  coef write 7547
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7551 ); // i2cWrite  coef read 7551
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7555 ); // i2cWrite  coef read 7555
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7559 ); // i2cWrite  coef read 7559
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7563 ); // i2cWrite  coef write 7563
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2c i2c            reg 0x0111 i2c data 0x0011   reg anal: GainEdgeControl         : 12.6V FSGainMap LowEMI
        //cs_8409_vendor_i2cWrite(codec, 0x2c, 0x0001, 0x0011, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7570 ); // i2cWrite  coef read 7570
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7574 ); // i2cWrite  coef write 7574
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002c, 0x00000000, 7578 ); // i2cWrite  coef write 7578
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0111, 0x00000000, 7582 ); // i2cWrite  coef write 7582
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7586 ); // i2cWrite  coef read 7586
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7590 ); // i2cWrite  coef read 7590
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7594 ); // i2cWrite  coef read 7594
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7598 ); // i2cWrite  coef write 7598
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2c i2c            reg 0x0348 i2c data 0x0048   reg anal: DACVolume               : -3.0dB
        //cs_8409_vendor_i2cWrite(codec, 0x2c, 0x0003, 0x0048, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7605 ); // i2cWrite  coef read 7605
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7609 ); // i2cWrite  coef write 7609
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002c, 0x00000000, 7613 ); // i2cWrite  coef write 7613
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0348, 0x00000000, 7617 ); // i2cWrite  coef write 7617
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7621 ); // i2cWrite  coef read 7621
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7625 ); // i2cWrite  coef read 7625
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7629 ); // i2cWrite  coef read 7629
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7633 ); // i2cWrite  coef write 7633
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2c i2c            reg 0x0451 i2c data 0x0051   reg anal: SAIControl1             : TDMPCMMode 24 BClks per Chip Delay1 PulsedSync Falling
        //cs_8409_vendor_i2cWrite(codec, 0x2c, 0x0004, 0x0051, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7640 ); // i2cWrite  coef read 7640
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7644 ); // i2cWrite  coef write 7644
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002c, 0x00000000, 7648 ); // i2cWrite  coef write 7648
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0451, 0x00000000, 7652 ); // i2cWrite  coef write 7652
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7656 ); // i2cWrite  coef read 7656
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7660 ); // i2cWrite  coef read 7660
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7664 ); // i2cWrite  coef read 7664
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7668 ); // i2cWrite  coef write 7668
//      snd_hda i2cWrite end

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x2c i2c            reg 0x0200 i2c data 0x0232   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cRead(codec, 0x2c, 0x0002, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7675 ); // i2cRead  coef read 7675
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7679 ); // i2cRead  coef write 7679
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002c, 0x00000000, 7683 ); // i2cRead  coef write 7683
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0200, 0x00000000, 7687 ); // i2cRead  coef write 7687
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7691 ); // i2cRead  coef read 7691
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7695 ); // i2cRead  coef read 7695
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000232, 7699 ); // i2cRead  coef read 7699
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7703 ); // i2cRead  coef read 7703
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7707 ); // i2cRead  coef write 7707
//      snd_hda i2cRead end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2c i2c            reg 0x0232 i2c data 0x0032   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cWrite(codec, 0x2c, 0x0002, 0x0032, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7714 ); // i2cWrite  coef read 7714
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7718 ); // i2cWrite  coef write 7718
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002c, 0x00000000, 7722 ); // i2cWrite  coef write 7722
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0232, 0x00000000, 7726 ); // i2cWrite  coef write 7726
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7730 ); // i2cWrite  coef read 7730
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7734 ); // i2cWrite  coef read 7734
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7738 ); // i2cWrite  coef read 7738
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7742 ); // i2cWrite  coef write 7742
//      snd_hda i2cWrite end

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x2c i2c            reg 0x0200 i2c data 0x0232   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cRead(codec, 0x2c, 0x0002, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7749 ); // i2cRead  coef read 7749
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7753 ); // i2cRead  coef write 7753
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002c, 0x00000000, 7757 ); // i2cRead  coef write 7757
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0200, 0x00000000, 7761 ); // i2cRead  coef write 7761
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7765 ); // i2cRead  coef read 7765
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7769 ); // i2cRead  coef read 7769
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000232, 7773 ); // i2cRead  coef read 7773
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7777 ); // i2cRead  coef read 7777
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7781 ); // i2cRead  coef write 7781
//      snd_hda i2cRead end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2c i2c            reg 0x0232 i2c data 0x0032   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cWrite(codec, 0x2c, 0x0002, 0x0032, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7788 ); // i2cWrite  coef read 7788
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7792 ); // i2cWrite  coef write 7792
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002c, 0x00000000, 7796 ); // i2cWrite  coef write 7796
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0232, 0x00000000, 7800 ); // i2cWrite  coef write 7800
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7804 ); // i2cWrite  coef read 7804
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7808 ); // i2cWrite  coef read 7808
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7812 ); // i2cWrite  coef read 7812
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7816 ); // i2cWrite  coef write 7816
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2e i2c            reg 0x0503 i2c data 0x0003   reg anal: SAIControl2             : ChipSlot 4 SlotByTDMRReg 24 bit Audio
        //cs_8409_vendor_i2cWrite(codec, 0x2e, 0x0005, 0x0003, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7823 ); // i2cWrite  coef read 7823
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7827 ); // i2cWrite  coef write 7827
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002e, 0x00000000, 7831 ); // i2cWrite  coef write 7831
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0503, 0x00000000, 7835 ); // i2cWrite  coef write 7835
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7839 ); // i2cWrite  coef read 7839
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7843 ); // i2cWrite  coef read 7843
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7847 ); // i2cWrite  coef read 7847
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7851 ); // i2cWrite  coef write 7851
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2e i2c            reg 0x0111 i2c data 0x0011   reg anal: GainEdgeControl         : 12.6V FSGainMap LowEMI
        //cs_8409_vendor_i2cWrite(codec, 0x2e, 0x0001, 0x0011, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7858 ); // i2cWrite  coef read 7858
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7862 ); // i2cWrite  coef write 7862
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002e, 0x00000000, 7866 ); // i2cWrite  coef write 7866
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0111, 0x00000000, 7870 ); // i2cWrite  coef write 7870
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7874 ); // i2cWrite  coef read 7874
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7878 ); // i2cWrite  coef read 7878
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7882 ); // i2cWrite  coef read 7882
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7886 ); // i2cWrite  coef write 7886
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2e i2c            reg 0x0348 i2c data 0x0048   reg anal: DACVolume               : -3.0dB
        //cs_8409_vendor_i2cWrite(codec, 0x2e, 0x0003, 0x0048, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7893 ); // i2cWrite  coef read 7893
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7897 ); // i2cWrite  coef write 7897
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002e, 0x00000000, 7901 ); // i2cWrite  coef write 7901
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0348, 0x00000000, 7905 ); // i2cWrite  coef write 7905
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7909 ); // i2cWrite  coef read 7909
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7913 ); // i2cWrite  coef read 7913
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7917 ); // i2cWrite  coef read 7917
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7921 ); // i2cWrite  coef write 7921
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2e i2c            reg 0x0451 i2c data 0x0051   reg anal: SAIControl1             : TDMPCMMode 24 BClks per Chip Delay1 PulsedSync Falling
        //cs_8409_vendor_i2cWrite(codec, 0x2e, 0x0004, 0x0051, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7928 ); // i2cWrite  coef read 7928
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7932 ); // i2cWrite  coef write 7932
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002e, 0x00000000, 7936 ); // i2cWrite  coef write 7936
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0451, 0x00000000, 7940 ); // i2cWrite  coef write 7940
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7944 ); // i2cWrite  coef read 7944
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7948 ); // i2cWrite  coef read 7948
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7952 ); // i2cWrite  coef read 7952
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7956 ); // i2cWrite  coef write 7956
//      snd_hda i2cWrite end

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x2e i2c            reg 0x0200 i2c data 0x0232   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cRead(codec, 0x2e, 0x0002, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 7963 ); // i2cRead  coef read 7963
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 7967 ); // i2cRead  coef write 7967
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002e, 0x00000000, 7971 ); // i2cRead  coef write 7971
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0200, 0x00000000, 7975 ); // i2cRead  coef write 7975
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7979 ); // i2cRead  coef read 7979
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 7983 ); // i2cRead  coef read 7983
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000232, 7987 ); // i2cRead  coef read 7987
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 7991 ); // i2cRead  coef read 7991
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 7995 ); // i2cRead  coef write 7995
//      snd_hda i2cRead end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2e i2c            reg 0x0232 i2c data 0x0032   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cWrite(codec, 0x2e, 0x0002, 0x0032, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 8002 ); // i2cWrite  coef read 8002
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 8006 ); // i2cWrite  coef write 8006
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002e, 0x00000000, 8010 ); // i2cWrite  coef write 8010
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0232, 0x00000000, 8014 ); // i2cWrite  coef write 8014
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8018 ); // i2cWrite  coef read 8018
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8022 ); // i2cWrite  coef read 8022
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 8026 ); // i2cWrite  coef read 8026
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 8030 ); // i2cWrite  coef write 8030
//      snd_hda i2cWrite end

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x2e i2c            reg 0x0200 i2c data 0x0232   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cRead(codec, 0x2e, 0x0002, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 8037 ); // i2cRead  coef read 8037
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 8041 ); // i2cRead  coef write 8041
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002e, 0x00000000, 8045 ); // i2cRead  coef write 8045
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0200, 0x00000000, 8049 ); // i2cRead  coef write 8049
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8053 ); // i2cRead  coef read 8053
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8057 ); // i2cRead  coef read 8057
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000232, 8061 ); // i2cRead  coef read 8061
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 8065 ); // i2cRead  coef read 8065
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 8069 ); // i2cRead  coef write 8069
//      snd_hda i2cRead end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2e i2c            reg 0x0232 i2c data 0x0032   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cWrite(codec, 0x2e, 0x0002, 0x0032, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 8076 ); // i2cWrite  coef read 8076
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 8080 ); // i2cWrite  coef write 8080
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002e, 0x00000000, 8084 ); // i2cWrite  coef write 8084
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0232, 0x00000000, 8088 ); // i2cWrite  coef write 8088
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8092 ); // i2cWrite  coef read 8092
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8096 ); // i2cWrite  coef read 8096
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 8100 ); // i2cWrite  coef read 8100
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 8104 ); // i2cWrite  coef write 8104
//      snd_hda i2cWrite end

}


static void sync_converters3_ssm3(struct hda_codec *codec)
{
        int retval;

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301

//      snd_hda: # AppleHDAFunctionGroupCS8409::syncConverters: 
        retval = snd_hda_codec_read_check(codec, 0x02, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000010, 8110); // 0x002f0600
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 1)]

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00270600
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0003, 0x00000003, 8112 ); // coef write mask 8112
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0003, 0xundef, 0x00000003, 8112 ); // coef write mask 8112

//      snd_hda: # AppleHDAFunctionGroupCS8409::syncConverters: 
        retval = snd_hda_codec_read_check(codec, 0x03, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000012, 8118); // 0x003f0600
//      snd_hda:     conv stream channel map 3 [('CHAN', 2), ('STREAMID', 1)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00370600
//      snd_hda:     conv stream channel map 3 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0003, 0x00000003, 8120 ); // coef write mask 8120
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0003, 0xundef, 0x00000003, 8120 ); // coef write mask 8120

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000010); // 0x00270610
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 1)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000012); // 0x00370612
//      snd_hda:     conv stream channel map 3 [('CHAN', 2), ('STREAMID', 1)]

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500

}


static void sync_converters4_ssm3(struct hda_codec *codec)
{
        int retval;

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301

//      snd_hda: # AppleHDAFunctionGroupCS8409::syncConverters: 
        retval = snd_hda_codec_read_check(codec, 0x02, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000000, 8149); // 0x002f0600
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00270600
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0002, 0x00000003, 8151 ); // coef write mask 8151
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0002, 0xundef, 0x00000003, 8151 ); // coef write mask 8151

//      snd_hda: # AppleHDAFunctionGroupCS8409::syncConverters: 
        retval = snd_hda_codec_read_check(codec, 0x03, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000000, 8157); // 0x003f0600
//      snd_hda:     conv stream channel map 3 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00370600
//      snd_hda:     conv stream channel map 3 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0000, 0x00000002, 8159 ); // coef write mask 8159
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0000, 0xundef, 0x00000002, 8159 ); // coef write mask 8159

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0017, 0x0000, 0x00000000, 8165 ); //   coef read 8165
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0018, 0x0000, 0x00000000, 8169 ); //   coef read 8169

        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0001, 0x0220, 0x00000220, 8173 ); // coef write mask 8173
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0001, 0x0220, 0xundef, 0x00000220, 8173 ); // coef write mask 8173

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00270600
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00370600
//      snd_hda:     conv stream channel map 3 [('CHAN', 0), ('STREAMID', 0)]

}

static void amps_disable3_282a_ssm3(struct hda_codec *codec)
{
        //int retval;

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x28 i2c            reg 0x0001 i2c data 0x0001   reg anal: PowerControl            : PowerDown BVSenseOn
        //cs_8409_vendor_i2cWrite(codec, 0x28, 0x0000, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 8183 ); // i2cWrite  coef read 8183
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 8187 ); // i2cWrite  coef write 8187
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0028, 0x00000000, 8191 ); // i2cWrite  coef write 8191
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0001, 0x00000000, 8195 ); // i2cWrite  coef write 8195
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8199 ); // i2cWrite  coef read 8199
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8203 ); // i2cWrite  coef read 8203
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 8207 ); // i2cWrite  coef read 8207
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 8211 ); // i2cWrite  coef write 8211
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2a i2c            reg 0x0001 i2c data 0x0001   reg anal: PowerControl            : PowerDown BVSenseOn
        //cs_8409_vendor_i2cWrite(codec, 0x2a, 0x0000, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 8218 ); // i2cWrite  coef read 8218
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 8222 ); // i2cWrite  coef write 8222
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002a, 0x00000000, 8226 ); // i2cWrite  coef write 8226
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0001, 0x00000000, 8230 ); // i2cWrite  coef write 8230
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8234 ); // i2cWrite  coef read 8234
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8238 ); // i2cWrite  coef read 8238
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 8242 ); // i2cWrite  coef read 8242
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 8246 ); // i2cWrite  coef write 8246
//      snd_hda i2cWrite end

}


static void putative_disable3_TDM_282a_ssm3(struct hda_codec *codec)
{
        int retval;

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00000800, 8252 ); //   coef read 8252
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0019, 0x8800, 0x00000000, 8256 ); //   coef write 8256
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001a, 0x0000, 0x00000820, 8260 ); //   coef read 8260
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001a, 0x8820, 0x00000000, 8264 ); //   coef write 8264

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: AppleHDATDMBusManagerCS8409::tdmInUse:
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00008800, 8268 ); //   coef read 8268
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001a, 0x0000, 0x00008820, 8272 ); //   coef read 8272
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001b, 0x0000, 0x00000840, 8276 ); //   coef read 8276

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: 
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006b, 0x001f, 0x00000000, 8281 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 8281
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x0000400f, 8285 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef read 8285
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x400f, 0x00000000, 8289 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 8289

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00b6 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  write verb 8292

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00270600
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_STREAM_FORMAT, 0x00000000); // 0x00220000
//      snd_hda:     stream format 2 [('CHAN', 1), ('RATE', 48000), ('BITS', 8), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000040, 8298); // 0x024f0700
        snd_hda_codec_write(codec, 0x24, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x02470700
//      snd_hda:     36 []

}

static void amps_disable3_2c2e_ssm3(struct hda_codec *codec)
{
        //int retval;


//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2c i2c            reg 0x0001 i2c data 0x0001   reg anal: PowerControl            : PowerDown BVSenseOn
        //cs_8409_vendor_i2cWrite(codec, 0x2c, 0x0000, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 8302 ); // i2cWrite  coef read 8302
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 8306 ); // i2cWrite  coef write 8306
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002c, 0x00000000, 8310 ); // i2cWrite  coef write 8310
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0001, 0x00000000, 8314 ); // i2cWrite  coef write 8314
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8318 ); // i2cWrite  coef read 8318
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8322 ); // i2cWrite  coef read 8322
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 8326 ); // i2cWrite  coef read 8326
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 8330 ); // i2cWrite  coef write 8330
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2e i2c            reg 0x0001 i2c data 0x0001   reg anal: PowerControl            : PowerDown BVSenseOn
        //cs_8409_vendor_i2cWrite(codec, 0x2e, 0x0000, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 8337 ); // i2cWrite  coef read 8337
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 8341 ); // i2cWrite  coef write 8341
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002e, 0x00000000, 8345 ); // i2cWrite  coef write 8345
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0001, 0x00000000, 8349 ); // i2cWrite  coef write 8349
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8353 ); // i2cWrite  coef read 8353
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8357 ); // i2cWrite  coef read 8357
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 8361 ); // i2cWrite  coef read 8361
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 8365 ); // i2cWrite  coef write 8365
//      snd_hda i2cWrite end

}

static void putative_disable3_TDM_2c2e_ssm3(struct hda_codec *codec)
{
        int retval;

        // this could be disabling the TDM

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001b, 0x0000, 0x00000840, 8371 ); //   coef read 8371
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001b, 0x8840, 0x00000000, 8375 ); //   coef write 8375
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001c, 0x0000, 0x00000860, 8379 ); //   coef read 8379
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001c, 0x8860, 0x00000000, 8383 ); //   coef write 8383

        // AppleHDATDMBusManagerCS8409::setupTDMPath or AppleHDATDMBusManagerCS8409::disableTDMPath
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0082, 0x0001, 0x00005401, 8387 ); // coef write mask 8387
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0082, 0x0001, 0xundef, 0x00005401, 8387 ); // coef write mask 8387

        // AppleHDATDMBusManagerCS8409::setupTDMPath or AppleHDATDMBusManagerCS8409::disableTDMPath
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000220, 8393 ); //   coef read 8393
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, 0x0200, 0x00000000, 8397 ); //   coef write 8397

        // AppleHDATDMBusManagerCS8409::setupTDMPath or disableTDMPath calls AppleHDATDMBusManagerCS8409::configureTDMUR
        // AppleHDATDMBusManagerCS8409::configureTDMUR only place calls this
        // this is AppleHDATDMBusManagerCS8409::tdmInUse
        // which reads from 0x19 to 0x57 in a loop if the snd_hda_coef_item returns 0 till the read value
        // does not have the word sign bit set (ie 0x8000) or finish all 0x57

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00008800, 8401 ); //   coef read 8401
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001a, 0x0000, 0x00008820, 8405 ); //   coef read 8405
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001b, 0x0000, 0x00008840, 8409 ); //   coef read 8409
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001c, 0x0000, 0x00008860, 8413 ); //   coef read 8413
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001d, 0x0000, 0x00008000, 8417 ); //   coef read 8417
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001e, 0x0000, 0x00008000, 8421 ); //   coef read 8421
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001f, 0x0000, 0x00008000, 8425 ); //   coef read 8425
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0020, 0x0000, 0x00008000, 8429 ); //   coef read 8429
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0021, 0x0000, 0x00008000, 8433 ); //   coef read 8433
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0022, 0x0000, 0x00008000, 8437 ); //   coef read 8437
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0023, 0x0000, 0x00008000, 8441 ); //   coef read 8441
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0024, 0x0000, 0x00008000, 8445 ); //   coef read 8445
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0025, 0x0000, 0x00008000, 8449 ); //   coef read 8449
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0026, 0x0000, 0x00008000, 8453 ); //   coef read 8453
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0027, 0x0000, 0x00008000, 8457 ); //   coef read 8457
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0028, 0x0000, 0x00008000, 8461 ); //   coef read 8461
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0029, 0x0000, 0x00008000, 8465 ); //   coef read 8465
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002a, 0x0000, 0x00008000, 8469 ); //   coef read 8469
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002b, 0x0000, 0x00008000, 8473 ); //   coef read 8473
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002c, 0x0000, 0x00008000, 8477 ); //   coef read 8477
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002d, 0x0000, 0x00008000, 8481 ); //   coef read 8481
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002e, 0x0000, 0x00008000, 8485 ); //   coef read 8485
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002f, 0x0000, 0x00008000, 8489 ); //   coef read 8489
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0030, 0x0000, 0x00008000, 8493 ); //   coef read 8493
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0031, 0x0000, 0x00008000, 8497 ); //   coef read 8497
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0032, 0x0000, 0x00008000, 8501 ); //   coef read 8501
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0033, 0x0000, 0x00008000, 8505 ); //   coef read 8505
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0034, 0x0000, 0x00008000, 8509 ); //   coef read 8509
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0035, 0x0000, 0x00008000, 8513 ); //   coef read 8513
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0036, 0x0000, 0x00008000, 8517 ); //   coef read 8517
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0037, 0x0000, 0x00008000, 8521 ); //   coef read 8521
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0038, 0x0000, 0x00008000, 8525 ); //   coef read 8525
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0039, 0x0000, 0x00008000, 8529 ); //   coef read 8529
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003a, 0x0000, 0x00008000, 8533 ); //   coef read 8533
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003b, 0x0000, 0x00008000, 8537 ); //   coef read 8537
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003c, 0x0000, 0x00008000, 8541 ); //   coef read 8541
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003d, 0x0000, 0x00008000, 8545 ); //   coef read 8545
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003e, 0x0000, 0x00008000, 8549 ); //   coef read 8549
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x003f, 0x0000, 0x00008000, 8553 ); //   coef read 8553
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0040, 0x0000, 0x00008000, 8557 ); //   coef read 8557
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0041, 0x0000, 0x00008000, 8561 ); //   coef read 8561
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0042, 0x0000, 0x00008000, 8565 ); //   coef read 8565
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0043, 0x0000, 0x00008000, 8569 ); //   coef read 8569
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0044, 0x0000, 0x00008000, 8573 ); //   coef read 8573
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0045, 0x0000, 0x00008000, 8577 ); //   coef read 8577
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0046, 0x0000, 0x00008000, 8581 ); //   coef read 8581
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0047, 0x0000, 0x00008000, 8585 ); //   coef read 8585
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0048, 0x0000, 0x00008000, 8589 ); //   coef read 8589
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0049, 0x0000, 0x00008000, 8593 ); //   coef read 8593
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004a, 0x0000, 0x00008000, 8597 ); //   coef read 8597
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004b, 0x0000, 0x00008000, 8601 ); //   coef read 8601
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004c, 0x0000, 0x00008000, 8605 ); //   coef read 8605
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004d, 0x0000, 0x00008000, 8609 ); //   coef read 8609
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004e, 0x0000, 0x00008000, 8613 ); //   coef read 8613
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004f, 0x0000, 0x00008000, 8617 ); //   coef read 8617
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0050, 0x0000, 0x00008000, 8621 ); //   coef read 8621
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0051, 0x0000, 0x00008000, 8625 ); //   coef read 8625
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0052, 0x0000, 0x00008000, 8629 ); //   coef read 8629
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0053, 0x0000, 0x00008000, 8633 ); //   coef read 8633
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0054, 0x0000, 0x00008000, 8637 ); //   coef read 8637
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0055, 0x0000, 0x00008000, 8641 ); //   coef read 8641
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0056, 0x0000, 0x00008000, 8645 ); //   coef read 8645
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0057, 0x0000, 0x00008000, 8649 ); //   coef read 8649

        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x00000000, 8654 ); //   coef write 8654

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00000000);


        // set to defaults and disable output

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00370600
//      snd_hda:     conv stream channel map 3 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_STREAM_FORMAT, 0x00000000); // 0x00320000
//      snd_hda:     stream format 3 [('CHAN', 1), ('RATE', 48000), ('BITS', 8), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000040, 8663); // 0x025f0700
        snd_hda_codec_write(codec, 0x25, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x02570700
//      snd_hda:     37 []

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}


static void setup_mic_vol2_ssm3(struct hda_codec *codec)
{
        int retval;

        // nodes 0x44 is connected to 0x22 which is labelled as mic input

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x00000033, 8672); // 0x022b2000
//      snd_hda:     amp gain/mute 34 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 34 0x0033 mute 0 gain 0x33 51
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00006033); // 0x02236033
//      snd_hda:     amp gain/mute 34 0x6033 mute 0 gain 0x33 51 index 0x00 left 1 right 0 output 0 input 1 left   input
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x00000033, 8674); // 0x022b0000
//      snd_hda:     amp gain/mute 34 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 34 0x0033 mute 0 gain 0x33 51
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00005033); // 0x02235033
//      snd_hda:     amp gain/mute 34 0x5033 mute 0 gain 0x33 51 index 0x00 left 0 right 1 output 0 input 1  right  input

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}


static void setup_mic_vol3_ssm3(struct hda_codec *codec)
{
        int retval;

        // nodes 0x44, 0x45 which are connected to 0x22, 0x23 are labelled as mic inputs

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x00000033, 8683); // 0x022b2000
//      snd_hda:     amp gain/mute 34 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 34 0x0033 mute 0 gain 0x33 51
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00006033); // 0x02236033
//      snd_hda:     amp gain/mute 34 0x6033 mute 0 gain 0x33 51 index 0x00 left 1 right 0 output 0 input 1 left   input
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x00000033, 8685); // 0x022b0000
//      snd_hda:     amp gain/mute 34 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 34 0x0033 mute 0 gain 0x33 51
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00005033); // 0x02235033
//      snd_hda:     amp gain/mute 34 0x5033 mute 0 gain 0x33 51 index 0x00 left 0 right 1 output 0 input 1  right  input

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}

        // whats with these multiple power ups/down
        // it appears OSXs logs are not guaranteed to be ordered - so these maybe delayed from some above calls
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503

        // so these may also be delayed outputs - which explains their weird positioning
        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 8724); // 0x022f0500


static void read_gpio_status1_ssm3(struct hda_codec *codec)
{
        int retval;

        // should these be done powered down??
        // lets check power state here
        // why the 3 calls

        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_GPIO_DATA, 0x00000000, 0x0000000f, 8727); // 0x001f1500
//      snd_hda:     gpio data 1 0x0f
}

static void read_gpio_status2_ssm3(struct hda_codec *codec)
{
        int retval;
        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_GPIO_DATA, 0x00000000, 0x0000000f, 8728); // 0x001f1500
//      snd_hda:     gpio data 1 0x0f
}

static void read_gpio_status3_ssm3(struct hda_codec *codec)
{
        int retval;
        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_GPIO_DATA, 0x00000000, 0x0000000f, 8729); // 0x001f1500
//      snd_hda:     gpio data 1 0x0f
}

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);


static void setup_mic3_ssm3(struct hda_codec *codec)
{

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7700 i2c data 0x7716
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1b77, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 8744 ); // i2cPagedRead  coef read 8744
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 8748 ); // i2cPagedRead  coef write 8748
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 8752 ); // i2cPagedRead  coef write 8752
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x001b, 0x00000000, 8756 ); // i2cPagedRead  coef write 8756
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8760 ); // i2cPagedRead  coef read 8760
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x7700, 0x00000000, 8764 ); // i2cPagedRead  coef write 8764
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8768 ); // i2cPagedRead  coef read 8768
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8772 ); // i2cPagedRead  coef read 8772
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00007716, 8776 ); // i2cPagedRead  coef read 8776
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 8780 ); // i2cPagedRead  coef read 8780
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 8784 ); // i2cPagedRead  coef write 8784
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}

static void setup_mic_vol4_ssm3(struct hda_codec *codec)
{
        int retval;

        //int retgain1;
        //int retgain2;

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x00000033, 8796); // 0x022b2000
//      snd_hda:     amp gain/mute 34 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 34 0x0033 mute 0 gain 0x33 51
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00006033); // 0x02236033
//      snd_hda:     amp gain/mute 34 0x6033 mute 0 gain 0x33 51 index 0x00 left 1 right 0 output 0 input 1 left   input
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x00000033, 8798); // 0x022b0000
//      snd_hda:     amp gain/mute 34 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 34 0x0033 mute 0 gain 0x33 51
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00005033); // 0x02235033
//      snd_hda:     amp gain/mute 34 0x5033 mute 0 gain 0x33 51 index 0x00 left 0 right 1 output 0 input 1  right  input

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}

static void setup_mic_vol5_ssm3(struct hda_codec *codec)
{
        int retval;

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x00000033, 8807); // 0x022b2000
//      snd_hda:     amp gain/mute 34 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 34 0x0033 mute 0 gain 0x33 51
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00006033); // 0x02236033
//      snd_hda:     amp gain/mute 34 0x6033 mute 0 gain 0x33 51 index 0x00 left 1 right 0 output 0 input 1 left   input
        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x00000033, 8809); // 0x022b0000
//      snd_hda:     amp gain/mute 34 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 34 0x0033 mute 0 gain 0x33 51
        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00005033); // 0x02235033
//      snd_hda:     amp gain/mute 34 0x5033 mute 0 gain 0x33 51 index 0x00 left 0 right 1 output 0 input 1  right  input

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}

        // more likely delayed log prints
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503


static void setup_mic4_ssm3(struct hda_codec *codec)
{

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7700 i2c data 0x7716
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1b77, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 8853 ); // i2cPagedRead  coef read 8853
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 8857 ); // i2cPagedRead  coef write 8857
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 8861 ); // i2cPagedRead  coef write 8861
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x001b, 0x00000000, 8865 ); // i2cPagedRead  coef write 8865
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8869 ); // i2cPagedRead  coef read 8869
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x7700, 0x00000000, 8873 ); // i2cPagedRead  coef write 8873
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8877 ); // i2cPagedRead  coef read 8877
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8881 ); // i2cPagedRead  coef read 8881
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00007716, 8885 ); // i2cPagedRead  coef read 8885
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 8889 ); // i2cPagedRead  coef read 8889
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 8893 ); // i2cPagedRead  coef write 8893
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}


static void setup_mic5_ssm3(struct hda_codec *codec)
{

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7700 i2c data 0x7716
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1b77, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 8904 ); // i2cPagedRead  coef read 8904
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 8908 ); // i2cPagedRead  coef write 8908
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 8912 ); // i2cPagedRead  coef write 8912
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x001b, 0x00000000, 8916 ); // i2cPagedRead  coef write 8916
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8920 ); // i2cPagedRead  coef read 8920
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x7700, 0x00000000, 8924 ); // i2cPagedRead  coef write 8924
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8928 ); // i2cPagedRead  coef read 8928
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 8932 ); // i2cPagedRead  coef read 8932
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00007716, 8936 ); // i2cPagedRead  coef read 8936
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 8940 ); // i2cPagedRead  coef read 8940
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 8944 ); // i2cPagedRead  coef write 8944
//      snd_hda i2cPagedRead end

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}

        // likely delayed outputs
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503

        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 8957); // 0x022f0500


static void setup_mic_vol6_ssm3(struct hda_codec *codec)
{

        //int retval;

        //int retgain1;
        //int retgain2;

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004031); // 0x02224031
//      snd_hda:     stream format 34 [('CHAN', 2), ('RATE', 44100), ('BITS', 24), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        // why this random set here?
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}

        // likely delayed outputs
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503


// cant decide if to have this at end or beginning
// I think end is better - also means dont have extra forward function definitions

static void setup_node_alpha_ssm3(struct hda_codec *codec)
{

        // so now really dont know whay I skipped all this - maybe because they
        // almost entirely reads??
        // - except it does clear all the pin configs
        // plus does a DBL init

        //int retval;

        setup_reset_and_clear_ssm3(codec);

        init_read_all_nodes_ssm3(codec);

        read_vendor_node_ssm3(codec);

        init_read_coefs_ssm3(codec);

        read_virtual_widgets_ssm3(codec);

        init_for_node_id_ssm3(codec);

        enable_i2c_ssm3(codec);

        enable_GPIforUR_ssm3(codec);

        external_control_GPIO_ssm3(codec);

        putative_setup_mic_ssm3(codec);

        external_control_GPIO2_clear_2_ssm3(codec);

        external_control_GPIO2_set_2_ssm3(codec);

        putative_setup_mic2_ssm3(codec);

        putative_gpio_mic3_ssm3(codec);

        putative_setup_mic3_ssm3(codec);

        setup_jack_nids_ssm3(codec);

        setup_jack_vol1_ssm3(codec);

        setup_jack_nids1_ssm3(codec);

        setup_jack_vol2_ssm3(codec);


        setup_TDM_282a_ssm3(codec);

        setup_amps_282a_ssm3(codec);

        setup_TDM_2c2e_ssm3(codec);

        setup_amps_2c2e_ssm3(codec);

        sync_converters_ssm3(codec);


        sync_converters1_ssm3(codec);

        amps_disable_282a_ssm3(codec);

        putative_tdm_disable_282a_ssm3(codec);

        amps_disable_2c2e_ssm3(codec);

        putative_tdm_disable_2c2e_ssm3(codec);


        putative_enable2_TDM_282a_ssm3(codec);

        amps_disable2_282a_ssm3(codec);

        putative_enable2_TDM_2c2e_ssm3(codec);

        amps_disable2_2c2e_ssm3(codec);

        sync_converters2_ssm3(codec);


        setup_TDM2_282a_ssm3(codec);

        amps_enable2_282a_ssm3(codec);

        setup_TDM2_2c2e_ssm3(codec);

        amps_enable2_2c2e_ssm3(codec);

        sync_converters3_ssm3(codec);


        sync_converters4_ssm3(codec);

        amps_disable3_282a_ssm3(codec);

        putative_disable3_TDM_282a_ssm3(codec);

        amps_disable3_2c2e_ssm3(codec);

        putative_disable3_TDM_2c2e_ssm3(codec);


        setup_mic_vol2_ssm3(codec);

        setup_mic_vol3_ssm3(codec);

        read_gpio_status1_ssm3(codec);

        read_gpio_status2_ssm3(codec);

        read_gpio_status3_ssm3(codec);

        setup_mic3_ssm3(codec);

        setup_mic_vol4_ssm3(codec);

        setup_mic_vol5_ssm3(codec);

        setup_mic4_ssm3(codec);

        setup_mic5_ssm3(codec);

        setup_mic_vol6_ssm3(codec);

}

static void play_start_ssm3(struct hda_codec *codec)
{
        int retval;

        retval = snd_hda_codec_read_check(codec, 0x00, 0, AC_VERB_PARAMETERS, 0x00000000, 0x10138409, 1); // 0x000f0000

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

}

static void play_mic_fixup_ssm3(struct hda_codec *codec)
{
        //int retval;

        // dont get why this is in the middle of audio play

//      snd_hda: # i2cPagedRead: 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7700 i2c data 0x7716
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1b77, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 15 ); // i2cPagedRead  coef read 15
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 19 ); // i2cPagedRead  coef write 19
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0090, 0x00000000, 23 ); // i2cPagedRead  coef write 23
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x001b, 0x00000000, 27 ); // i2cPagedRead  coef write 27
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 31 ); // i2cPagedRead  coef read 31
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x7700, 0x00000000, 35 ); // i2cPagedRead  coef write 35
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 39 ); // i2cPagedRead  coef read 39
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 43 ); // i2cPagedRead  coef read 43
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00007716, 47 ); // i2cPagedRead  coef read 47
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 51 ); // i2cPagedRead  coef read 51
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 55 ); // i2cPagedRead  coef write 55
//      snd_hda i2cPagedRead end

}

static void play_setup_TDM_282a_ssm3(struct hda_codec *codec)
{
        int retval;

        // this seems to be setup for node 0x02 chain - which seems to use node 0x24 and amps 0x28 and 0x2a

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004033); // 0x00224033
//      snd_hda:     stream format 2 [('CHAN', 4), ('RATE', 44100), ('BITS', 24), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000010); // 0x00270610
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 1)]

//      snd_hda: # AppleHDATDMBusManagerCS8409::setupTDMPath:
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000200, 64 ); //   coef read 64
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, 0x0200, 0x00000000, 68 ); //   coef write 68

//      snd_hda: # AppleHDATDMBusManagerCS8409::setSampleRate: 
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0001, 0x0200, 0x00000200, 73 ); // coef write mask 73
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0005, 0x0001, 0x00000001, 79 ); // coef write mask 79
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0004, 0x08ff, 0x000008ff, 85 ); // coef write mask 85
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0001, 0x0200, 0xundef, 0x00000200, 73 ); // coef write mask 73
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0005, 0x0001, 0xundef, 0x00000001, 79 ); // coef write mask 79
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0004, 0x08ff, 0xundef, 0x000008ff, 85 ); // coef write mask 85

//      snd_hda: # AppleHDATDMBusManagerCS8409::setupTDMPath: 
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00008800, 92 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 92
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0019, 0x0800, 0x00000000, 96 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 96
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001a, 0x0000, 0x00008820, 100 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 100
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001a, 0x0820, 0x00000000, 104 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 104

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 108 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 108
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0xb000, 0x00000000, 112 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 112
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0004, 0x0000, 0x000008ff, 116 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 116
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0004, 0x08ff, 0x00000000, 120 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 120
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 124 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 124

        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0003, 0x8000, 0x00008000, 128 ); // coef write mask 128
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0005, 0x0001, 0x00000001, 134 ); // coef write mask 134
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0082, 0x5401, 0x00000001, 140 ); // coef write mask 140
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0002, 0x0280, 0x00000280, 146 ); // coef write mask 146
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0003, 0x8000, 0xundef, 0x00008000, 128 ); // coef write mask 128
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0005, 0x0001, 0xundef, 0x00000001, 134 ); // coef write mask 134
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0082, 0x5401, 0xundef, 0x00000001, 140 ); // coef write mask 140
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0002, 0x0280, 0xundef, 0x00000280, 146 ); // coef write mask 146

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000200, 152 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 152
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, 0x0220, 0x00000000, 156 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 156

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: AppleHDATDMBusManagerCS8409::tdmInUse:
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00000800, 160 ); //   coef read 160

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: 
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006b, 0x001f, 0x00000000, 165 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 165
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x00000000, 169 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef read 169
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x400f, 0x00000000, 173 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 173

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00b6 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  write verb 176


        // enable output node 0x24

        retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 180); // 0x024f0700
        snd_hda_codec_write(codec, 0x24, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000040); // 0x02470740
//      snd_hda:     36 ['AC_PINCTL_OUT_EN']

}


static void play_setup_amps_282a_ssm3(struct hda_codec *codec)
{
        //int retval;


//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x28 i2c            reg 0x0500 i2c data 0x0000   reg anal: SAIControl2             : ChipSlot 1 SlotByTDMRReg 24 bit Audio
        //cs_8409_vendor_i2cWrite(codec, 0x28, 0x0005, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 184 ); // i2cWrite  coef read 184
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 188 ); // i2cWrite  coef write 188
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0028, 0x00000000, 192 ); // i2cWrite  coef write 192
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0500, 0x00000000, 196 ); // i2cWrite  coef write 196
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 200 ); // i2cWrite  coef read 200
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 204 ); // i2cWrite  coef read 204
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 208 ); // i2cWrite  coef read 208
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 212 ); // i2cWrite  coef write 212
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x28 i2c            reg 0x0111 i2c data 0x0011   reg anal: GainEdgeControl         : 12.6V FSGainMap LowEMI
        //cs_8409_vendor_i2cWrite(codec, 0x28, 0x0001, 0x0011, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 219 ); // i2cWrite  coef read 219
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 223 ); // i2cWrite  coef write 223
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0028, 0x00000000, 227 ); // i2cWrite  coef write 227
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0111, 0x00000000, 231 ); // i2cWrite  coef write 231
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 235 ); // i2cWrite  coef read 235
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 239 ); // i2cWrite  coef read 239
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 243 ); // i2cWrite  coef read 243
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 247 ); // i2cWrite  coef write 247
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x28 i2c            reg 0x0348 i2c data 0x0048   reg anal: DACVolume               : -3.0dB
        //cs_8409_vendor_i2cWrite(codec, 0x28, 0x0003, 0x0048, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 254 ); // i2cWrite  coef read 254
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 258 ); // i2cWrite  coef write 258
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0028, 0x00000000, 262 ); // i2cWrite  coef write 262
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0348, 0x00000000, 266 ); // i2cWrite  coef write 266
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 270 ); // i2cWrite  coef read 270
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 274 ); // i2cWrite  coef read 274
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 278 ); // i2cWrite  coef read 278
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 282 ); // i2cWrite  coef write 282
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x28 i2c            reg 0x0451 i2c data 0x0051   reg anal: SAIControl1             : TDMPCMMode 24 BClks per Chip Delay1 PulsedSync Falling
        //cs_8409_vendor_i2cWrite(codec, 0x28, 0x0004, 0x0051, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 289 ); // i2cWrite  coef read 289
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 293 ); // i2cWrite  coef write 293
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0028, 0x00000000, 297 ); // i2cWrite  coef write 297
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0451, 0x00000000, 301 ); // i2cWrite  coef write 301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 305 ); // i2cWrite  coef read 305
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 309 ); // i2cWrite  coef read 309
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 313 ); // i2cWrite  coef read 313
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 317 ); // i2cWrite  coef write 317
//      snd_hda i2cWrite end

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x28 i2c            reg 0x0200 i2c data 0x0232   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cRead(codec, 0x28, 0x0002, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 324 ); // i2cRead  coef read 324
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 328 ); // i2cRead  coef write 328
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0028, 0x00000000, 332 ); // i2cRead  coef write 332
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0200, 0x00000000, 336 ); // i2cRead  coef write 336
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 340 ); // i2cRead  coef read 340
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 344 ); // i2cRead  coef read 344
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000232, 348 ); // i2cRead  coef read 348
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 352 ); // i2cRead  coef read 352
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 356 ); // i2cRead  coef write 356
//      snd_hda i2cRead end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x28 i2c            reg 0x0232 i2c data 0x0032   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cWrite(codec, 0x28, 0x0002, 0x0032, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 363 ); // i2cWrite  coef read 363
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 367 ); // i2cWrite  coef write 367
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0028, 0x00000000, 371 ); // i2cWrite  coef write 371
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0232, 0x00000000, 375 ); // i2cWrite  coef write 375
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 379 ); // i2cWrite  coef read 379
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 383 ); // i2cWrite  coef read 383
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 387 ); // i2cWrite  coef read 387
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 391 ); // i2cWrite  coef write 391
//      snd_hda i2cWrite end

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x28 i2c            reg 0x0200 i2c data 0x0232   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cRead(codec, 0x28, 0x0002, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 398 ); // i2cRead  coef read 398
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 402 ); // i2cRead  coef write 402
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0028, 0x00000000, 406 ); // i2cRead  coef write 406
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0200, 0x00000000, 410 ); // i2cRead  coef write 410
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 414 ); // i2cRead  coef read 414
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 418 ); // i2cRead  coef read 418
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000232, 422 ); // i2cRead  coef read 422
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 426 ); // i2cRead  coef read 426
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 430 ); // i2cRead  coef write 430
//      snd_hda i2cRead end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x28 i2c            reg 0x0232 i2c data 0x0032   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cWrite(codec, 0x28, 0x0002, 0x0032, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 437 ); // i2cWrite  coef read 437
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 441 ); // i2cWrite  coef write 441
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0028, 0x00000000, 445 ); // i2cWrite  coef write 445
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0232, 0x00000000, 449 ); // i2cWrite  coef write 449
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 453 ); // i2cWrite  coef read 453
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 457 ); // i2cWrite  coef read 457
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 461 ); // i2cWrite  coef read 461
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 465 ); // i2cWrite  coef write 465
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x28 i2c            reg 0x0000 i2c data 0x0000   reg anal: PowerControl            : PowerOn BVSenseOn
        //cs_8409_vendor_i2cWrite(codec, 0x28, 0x0000, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 472 ); // i2cWrite  coef read 472
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 476 ); // i2cWrite  coef write 476
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x0028, 0x00000000, 480 ); // i2cWrite  coef write 480
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0000, 0x00000000, 484 ); // i2cWrite  coef write 484
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 488 ); // i2cWrite  coef read 488
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 492 ); // i2cWrite  coef read 492
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 496 ); // i2cWrite  coef read 496
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 500 ); // i2cWrite  coef write 500
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2a i2c            reg 0x0501 i2c data 0x0001   reg anal: SAIControl2             : ChipSlot 2 SlotByTDMRReg 24 bit Audio
        //cs_8409_vendor_i2cWrite(codec, 0x2a, 0x0005, 0x0001, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 507 ); // i2cWrite  coef read 507
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 511 ); // i2cWrite  coef write 511
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002a, 0x00000000, 515 ); // i2cWrite  coef write 515
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0501, 0x00000000, 519 ); // i2cWrite  coef write 519
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 523 ); // i2cWrite  coef read 523
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 527 ); // i2cWrite  coef read 527
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 531 ); // i2cWrite  coef read 531
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 535 ); // i2cWrite  coef write 535
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2a i2c            reg 0x0111 i2c data 0x0011   reg anal: GainEdgeControl         : 12.6V FSGainMap LowEMI
        //cs_8409_vendor_i2cWrite(codec, 0x2a, 0x0001, 0x0011, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 542 ); // i2cWrite  coef read 542
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 546 ); // i2cWrite  coef write 546
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002a, 0x00000000, 550 ); // i2cWrite  coef write 550
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0111, 0x00000000, 554 ); // i2cWrite  coef write 554
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 558 ); // i2cWrite  coef read 558
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 562 ); // i2cWrite  coef read 562
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 566 ); // i2cWrite  coef read 566
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 570 ); // i2cWrite  coef write 570
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2a i2c            reg 0x0348 i2c data 0x0048   reg anal: DACVolume               : -3.0dB
        //cs_8409_vendor_i2cWrite(codec, 0x2a, 0x0003, 0x0048, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 577 ); // i2cWrite  coef read 577
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 581 ); // i2cWrite  coef write 581
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002a, 0x00000000, 585 ); // i2cWrite  coef write 585
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0348, 0x00000000, 589 ); // i2cWrite  coef write 589
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 593 ); // i2cWrite  coef read 593
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 597 ); // i2cWrite  coef read 597
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 601 ); // i2cWrite  coef read 601
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 605 ); // i2cWrite  coef write 605
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2a i2c            reg 0x0451 i2c data 0x0051   reg anal: SAIControl1             : TDMPCMMode 24 BClks per Chip Delay1 PulsedSync Falling
        //cs_8409_vendor_i2cWrite(codec, 0x2a, 0x0004, 0x0051, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 612 ); // i2cWrite  coef read 612
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 616 ); // i2cWrite  coef write 616
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002a, 0x00000000, 620 ); // i2cWrite  coef write 620
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0451, 0x00000000, 624 ); // i2cWrite  coef write 624
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 628 ); // i2cWrite  coef read 628
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 632 ); // i2cWrite  coef read 632
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 636 ); // i2cWrite  coef read 636
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 640 ); // i2cWrite  coef write 640
//      snd_hda i2cWrite end

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x2a i2c            reg 0x0200 i2c data 0x0232   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cRead(codec, 0x2a, 0x0002, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 647 ); // i2cRead  coef read 647
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 651 ); // i2cRead  coef write 651
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002a, 0x00000000, 655 ); // i2cRead  coef write 655
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0200, 0x00000000, 659 ); // i2cRead  coef write 659
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 663 ); // i2cRead  coef read 663
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 667 ); // i2cRead  coef read 667
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000232, 671 ); // i2cRead  coef read 671
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 675 ); // i2cRead  coef read 675
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 679 ); // i2cRead  coef write 679
//      snd_hda i2cRead end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2a i2c            reg 0x0232 i2c data 0x0032   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cWrite(codec, 0x2a, 0x0002, 0x0032, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 686 ); // i2cWrite  coef read 686
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 690 ); // i2cWrite  coef write 690
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002a, 0x00000000, 694 ); // i2cWrite  coef write 694
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0232, 0x00000000, 698 ); // i2cWrite  coef write 698
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 702 ); // i2cWrite  coef read 702
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 706 ); // i2cWrite  coef read 706
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 710 ); // i2cWrite  coef read 710
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 714 ); // i2cWrite  coef write 714
//      snd_hda i2cWrite end

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x2a i2c            reg 0x0200 i2c data 0x0232   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cRead(codec, 0x2a, 0x0002, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 721 ); // i2cRead  coef read 721
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 725 ); // i2cRead  coef write 725
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002a, 0x00000000, 729 ); // i2cRead  coef write 729
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0200, 0x00000000, 733 ); // i2cRead  coef write 733
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 737 ); // i2cRead  coef read 737
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 741 ); // i2cRead  coef read 741
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000232, 745 ); // i2cRead  coef read 745
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 749 ); // i2cRead  coef read 749
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 753 ); // i2cRead  coef write 753
//      snd_hda i2cRead end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2a i2c            reg 0x0232 i2c data 0x0032   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cWrite(codec, 0x2a, 0x0002, 0x0032, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 760 ); // i2cWrite  coef read 760
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 764 ); // i2cWrite  coef write 764
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002a, 0x00000000, 768 ); // i2cWrite  coef write 768
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0232, 0x00000000, 772 ); // i2cWrite  coef write 772
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 776 ); // i2cWrite  coef read 776
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 780 ); // i2cWrite  coef read 780
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 784 ); // i2cWrite  coef read 784
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 788 ); // i2cWrite  coef write 788
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2a i2c            reg 0x0000 i2c data 0x0000   reg anal: PowerControl            : PowerOn BVSenseOn
        //cs_8409_vendor_i2cWrite(codec, 0x2a, 0x0000, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 795 ); // i2cWrite  coef read 795
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 799 ); // i2cWrite  coef write 799
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002a, 0x00000000, 803 ); // i2cWrite  coef write 803
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0000, 0x00000000, 807 ); // i2cWrite  coef write 807
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 811 ); // i2cWrite  coef read 811
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 815 ); // i2cWrite  coef read 815
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 819 ); // i2cWrite  coef read 819
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 823 ); // i2cWrite  coef write 823
//      snd_hda i2cWrite end

}

static void play_setup_TDM_2c2e_ssm3(struct hda_codec *codec)
{
        int retval;

        // this seems to be setup for node 0x03 chain - which seems to use node 0x25 and amps 0x2c and 0x2e

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004033); // 0x00324033
//      snd_hda:     stream format 3 [('CHAN', 4), ('RATE', 44100), ('BITS', 24), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000012); // 0x00370612
//      snd_hda:     conv stream channel map 3 [('CHAN', 2), ('STREAMID', 1)]

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001b, 0x0000, 0x00008840, 833 ); //   coef read 833
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001b, 0x0840, 0x00000000, 837 ); //   coef write 837
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001c, 0x0000, 0x00008860, 841 ); //   coef read 841
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001c, 0x0860, 0x00000000, 845 ); //   coef write 845

        // the following actually reads from 0x19 to 0x57 in a loop if the snd_hda_coef_item returns 0 till the read value
        // does not have the word sign bit set (ie 0x8000) or finish all 0x57

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: AppleHDATDMBusManagerCS8409::tdmInUse:
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00000800, 849 ); //   coef read 849

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: 
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006b, 0x001f, 0x00000000, 854 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 854
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x0000400f, 858 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef read 858
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x400f, 0x00000000, 862 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 862

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00b6 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  write verb 865


        // enable output on node 0x25

        retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 869); // 0x025f0700
        snd_hda_codec_write(codec, 0x25, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000040); // 0x02570740
//      snd_hda:     37 ['AC_PINCTL_OUT_EN']

}

static void play_setup_amps_2c2e_ssm3(struct hda_codec *codec)
{
        //int retval;

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2c i2c            reg 0x0502 i2c data 0x0002   reg anal: SAIControl2             : ChipSlot 3 SlotByTDMRReg 24 bit Audio
        //cs_8409_vendor_i2cWrite(codec, 0x2c, 0x0005, 0x0002, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 873 ); // i2cWrite  coef read 873
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 877 ); // i2cWrite  coef write 877
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002c, 0x00000000, 881 ); // i2cWrite  coef write 881
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0502, 0x00000000, 885 ); // i2cWrite  coef write 885
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 889 ); // i2cWrite  coef read 889
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 893 ); // i2cWrite  coef read 893
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 897 ); // i2cWrite  coef read 897
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 901 ); // i2cWrite  coef write 901
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2c i2c            reg 0x0111 i2c data 0x0011   reg anal: GainEdgeControl         : 12.6V FSGainMap LowEMI
        //cs_8409_vendor_i2cWrite(codec, 0x2c, 0x0001, 0x0011, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 908 ); // i2cWrite  coef read 908
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 912 ); // i2cWrite  coef write 912
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002c, 0x00000000, 916 ); // i2cWrite  coef write 916
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0111, 0x00000000, 920 ); // i2cWrite  coef write 920
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 924 ); // i2cWrite  coef read 924
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 928 ); // i2cWrite  coef read 928
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 932 ); // i2cWrite  coef read 932
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 936 ); // i2cWrite  coef write 936
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2c i2c            reg 0x0348 i2c data 0x0048   reg anal: DACVolume               : -3.0dB
        //cs_8409_vendor_i2cWrite(codec, 0x2c, 0x0003, 0x0048, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 943 ); // i2cWrite  coef read 943
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 947 ); // i2cWrite  coef write 947
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002c, 0x00000000, 951 ); // i2cWrite  coef write 951
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0348, 0x00000000, 955 ); // i2cWrite  coef write 955
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 959 ); // i2cWrite  coef read 959
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 963 ); // i2cWrite  coef read 963
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 967 ); // i2cWrite  coef read 967
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 971 ); // i2cWrite  coef write 971
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2c i2c            reg 0x0451 i2c data 0x0051   reg anal: SAIControl1             : TDMPCMMode 24 BClks per Chip Delay1 PulsedSync Falling
        //cs_8409_vendor_i2cWrite(codec, 0x2c, 0x0004, 0x0051, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 978 ); // i2cWrite  coef read 978
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 982 ); // i2cWrite  coef write 982
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002c, 0x00000000, 986 ); // i2cWrite  coef write 986
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0451, 0x00000000, 990 ); // i2cWrite  coef write 990
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 994 ); // i2cWrite  coef read 994
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 998 ); // i2cWrite  coef read 998
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1002 ); // i2cWrite  coef read 1002
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1006 ); // i2cWrite  coef write 1006
//      snd_hda i2cWrite end

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x2c i2c            reg 0x0200 i2c data 0x0232   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cRead(codec, 0x2c, 0x0002, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1013 ); // i2cRead  coef read 1013
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1017 ); // i2cRead  coef write 1017
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002c, 0x00000000, 1021 ); // i2cRead  coef write 1021
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0200, 0x00000000, 1025 ); // i2cRead  coef write 1025
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1029 ); // i2cRead  coef read 1029
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1033 ); // i2cRead  coef read 1033
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000232, 1037 ); // i2cRead  coef read 1037
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1041 ); // i2cRead  coef read 1041
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1045 ); // i2cRead  coef write 1045
//      snd_hda i2cRead end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2c i2c            reg 0x0232 i2c data 0x0032   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cWrite(codec, 0x2c, 0x0002, 0x0032, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1052 ); // i2cWrite  coef read 1052
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1056 ); // i2cWrite  coef write 1056
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002c, 0x00000000, 1060 ); // i2cWrite  coef write 1060
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0232, 0x00000000, 1064 ); // i2cWrite  coef write 1064
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1068 ); // i2cWrite  coef read 1068
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1072 ); // i2cWrite  coef read 1072
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1076 ); // i2cWrite  coef read 1076
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1080 ); // i2cWrite  coef write 1080
//      snd_hda i2cWrite end

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x2c i2c            reg 0x0200 i2c data 0x0232   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cRead(codec, 0x2c, 0x0002, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1087 ); // i2cRead  coef read 1087
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1091 ); // i2cRead  coef write 1091
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002c, 0x00000000, 1095 ); // i2cRead  coef write 1095
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0200, 0x00000000, 1099 ); // i2cRead  coef write 1099
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1103 ); // i2cRead  coef read 1103
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1107 ); // i2cRead  coef read 1107
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000232, 1111 ); // i2cRead  coef read 1111
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1115 ); // i2cRead  coef read 1115
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1119 ); // i2cRead  coef write 1119
//      snd_hda i2cRead end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2c i2c            reg 0x0232 i2c data 0x0032   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cWrite(codec, 0x2c, 0x0002, 0x0032, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1126 ); // i2cWrite  coef read 1126
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1130 ); // i2cWrite  coef write 1130
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002c, 0x00000000, 1134 ); // i2cWrite  coef write 1134
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0232, 0x00000000, 1138 ); // i2cWrite  coef write 1138
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1142 ); // i2cWrite  coef read 1142
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1146 ); // i2cWrite  coef read 1146
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1150 ); // i2cWrite  coef read 1150
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1154 ); // i2cWrite  coef write 1154
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2c i2c            reg 0x0000 i2c data 0x0000   reg anal: PowerControl            : PowerOn BVSenseOn
        //cs_8409_vendor_i2cWrite(codec, 0x2c, 0x0000, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1161 ); // i2cWrite  coef read 1161
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1165 ); // i2cWrite  coef write 1165
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002c, 0x00000000, 1169 ); // i2cWrite  coef write 1169
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0000, 0x00000000, 1173 ); // i2cWrite  coef write 1173
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1177 ); // i2cWrite  coef read 1177
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1181 ); // i2cWrite  coef read 1181
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1185 ); // i2cWrite  coef read 1185
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1189 ); // i2cWrite  coef write 1189
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2e i2c            reg 0x0503 i2c data 0x0003   reg anal: SAIControl2             : ChipSlot 4 SlotByTDMRReg 24 bit Audio
        //cs_8409_vendor_i2cWrite(codec, 0x2e, 0x0005, 0x0003, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1196 ); // i2cWrite  coef read 1196
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1200 ); // i2cWrite  coef write 1200
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002e, 0x00000000, 1204 ); // i2cWrite  coef write 1204
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0503, 0x00000000, 1208 ); // i2cWrite  coef write 1208
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1212 ); // i2cWrite  coef read 1212
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1216 ); // i2cWrite  coef read 1216
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1220 ); // i2cWrite  coef read 1220
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1224 ); // i2cWrite  coef write 1224
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2e i2c            reg 0x0111 i2c data 0x0011   reg anal: GainEdgeControl         : 12.6V FSGainMap LowEMI
        //cs_8409_vendor_i2cWrite(codec, 0x2e, 0x0001, 0x0011, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1231 ); // i2cWrite  coef read 1231
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1235 ); // i2cWrite  coef write 1235
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002e, 0x00000000, 1239 ); // i2cWrite  coef write 1239
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0111, 0x00000000, 1243 ); // i2cWrite  coef write 1243
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1247 ); // i2cWrite  coef read 1247
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1251 ); // i2cWrite  coef read 1251
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1255 ); // i2cWrite  coef read 1255
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1259 ); // i2cWrite  coef write 1259
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2e i2c            reg 0x0348 i2c data 0x0048   reg anal: DACVolume               : -3.0dB
        //cs_8409_vendor_i2cWrite(codec, 0x2e, 0x0003, 0x0048, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1266 ); // i2cWrite  coef read 1266
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1270 ); // i2cWrite  coef write 1270
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002e, 0x00000000, 1274 ); // i2cWrite  coef write 1274
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0348, 0x00000000, 1278 ); // i2cWrite  coef write 1278
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1282 ); // i2cWrite  coef read 1282
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1286 ); // i2cWrite  coef read 1286
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1290 ); // i2cWrite  coef read 1290
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1294 ); // i2cWrite  coef write 1294
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2e i2c            reg 0x0451 i2c data 0x0051   reg anal: SAIControl1             : TDMPCMMode 24 BClks per Chip Delay1 PulsedSync Falling
        //cs_8409_vendor_i2cWrite(codec, 0x2e, 0x0004, 0x0051, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1301 ); // i2cWrite  coef read 1301
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1305 ); // i2cWrite  coef write 1305
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002e, 0x00000000, 1309 ); // i2cWrite  coef write 1309
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0451, 0x00000000, 1313 ); // i2cWrite  coef write 1313
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1317 ); // i2cWrite  coef read 1317
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1321 ); // i2cWrite  coef read 1321
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1325 ); // i2cWrite  coef read 1325
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1329 ); // i2cWrite  coef write 1329
//      snd_hda i2cWrite end

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x2e i2c            reg 0x0200 i2c data 0x0232   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cRead(codec, 0x2e, 0x0002, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1336 ); // i2cRead  coef read 1336
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1340 ); // i2cRead  coef write 1340
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002e, 0x00000000, 1344 ); // i2cRead  coef write 1344
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0200, 0x00000000, 1348 ); // i2cRead  coef write 1348
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1352 ); // i2cRead  coef read 1352
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1356 ); // i2cRead  coef read 1356
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000232, 1360 ); // i2cRead  coef read 1360
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1364 ); // i2cRead  coef read 1364
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1368 ); // i2cRead  coef write 1368
//      snd_hda i2cRead end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2e i2c            reg 0x0232 i2c data 0x0032   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cWrite(codec, 0x2e, 0x0002, 0x0032, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1375 ); // i2cWrite  coef read 1375
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1379 ); // i2cWrite  coef write 1379
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002e, 0x00000000, 1383 ); // i2cWrite  coef write 1383
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0232, 0x00000000, 1387 ); // i2cWrite  coef write 1387
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1391 ); // i2cWrite  coef read 1391
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1395 ); // i2cWrite  coef read 1395
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1399 ); // i2cWrite  coef read 1399
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1403 ); // i2cWrite  coef write 1403
//      snd_hda i2cWrite end

//      snd_hda: # i2cRead: 
//      snd_hda i2cRead       i2c address 0x2e i2c            reg 0x0200 i2c data 0x0232   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cRead(codec, 0x2e, 0x0002, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1410 ); // i2cRead  coef read 1410
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1414 ); // i2cRead  coef write 1414
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002e, 0x00000000, 1418 ); // i2cRead  coef write 1418
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005e, 0x0200, 0x00000000, 1422 ); // i2cRead  coef write 1422
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1426 ); // i2cRead  coef read 1426
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1430 ); // i2cRead  coef read 1430
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00000232, 1434 ); // i2cRead  coef read 1434
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1438 ); // i2cRead  coef read 1438
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1442 ); // i2cRead  coef write 1442
//      snd_hda i2cRead end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2e i2c            reg 0x0232 i2c data 0x0032   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
        //cs_8409_vendor_i2cWrite(codec, 0x2e, 0x0002, 0x0032, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1449 ); // i2cWrite  coef read 1449
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1453 ); // i2cWrite  coef write 1453
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002e, 0x00000000, 1457 ); // i2cWrite  coef write 1457
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0232, 0x00000000, 1461 ); // i2cWrite  coef write 1461
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1465 ); // i2cWrite  coef read 1465
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1469 ); // i2cWrite  coef read 1469
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1473 ); // i2cWrite  coef read 1473
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1477 ); // i2cWrite  coef write 1477
//      snd_hda i2cWrite end

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2e i2c            reg 0x0000 i2c data 0x0000   reg anal: PowerControl            : PowerOn BVSenseOn
        //cs_8409_vendor_i2cWrite(codec, 0x2e, 0x0000, 0x0000, 1); // snd_hda
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 1484 ); // i2cWrite  coef read 1484
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1488 ); // i2cWrite  coef write 1488
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0059, 0x002e, 0x00000000, 1492 ); // i2cWrite  coef write 1492
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x0000, 0x00000000, 1496 ); // i2cWrite  coef write 1496
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1500 ); // i2cWrite  coef read 1500
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000038, 1504 ); // i2cWrite  coef read 1504
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1508 ); // i2cWrite  coef read 1508
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1512 ); // i2cWrite  coef write 1512
//      snd_hda i2cWrite end

}

static void play_sync_converters_ssm3(struct hda_codec *codec)
{
        int retval;

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301

//      snd_hda: # AppleHDAFunctionGroupCS8409::syncConverters: 
        retval = snd_hda_codec_read_check(codec, 0x02, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000010, 1518); // 0x002f0600
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 1)]

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00270600
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0001, 0x00000000, 1520 ); // coef write mask 1520
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0001, 0xundef, 0x00000000, 1520 ); // coef write mask 1520

//      snd_hda: # AppleHDAFunctionGroupCS8409::syncConverters: 
        retval = snd_hda_codec_read_check(codec, 0x03, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000012, 1526); // 0x003f0600
//      snd_hda:     conv stream channel map 3 [('CHAN', 2), ('STREAMID', 1)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00370600
//      snd_hda:     conv stream channel map 3 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0003, 0x00000001, 1528 ); // coef write mask 1528
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0003, 0xundef, 0x00000001, 1528 ); // coef write mask 1528

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000010); // 0x00270610
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 1)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000012); // 0x00370612
//      snd_hda:     conv stream channel map 3 [('CHAN', 2), ('STREAMID', 1)]

        retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 1541); // 0x022f0500

}


static void cs_8409_play_ssm3(struct hda_codec *codec)
{
        //int retval1;
        //int retval2;

        printk("snd_hda_intel: command nid start cs_8409_play_ssm3");


        play_start_ssm3(codec);

        play_mic_fixup_ssm3(codec);

        play_setup_TDM_282a_ssm3(codec);

        play_setup_amps_282a_ssm3(codec);

        play_setup_TDM_2c2e_ssm3(codec);

        play_setup_amps_2c2e_ssm3(codec);

        play_sync_converters_ssm3(codec);

        // dont think its power - only node 0x22 is power capable
        //retval1 = snd_hda_codec_read(codec, 0x02, 0, AC_VERB_GET_POWER_STATE, 0);
        //retval2 = snd_hda_codec_read(codec, 0x03, 0, AC_VERB_GET_POWER_STATE, 0);
        //printk("snd_hda_intel: command nid BAD nodes 0x02 0x03 power %d %d", retval1, retval2);

        printk("snd_hda_intel: command nid cs_8409_play_ssm3 end");

}

