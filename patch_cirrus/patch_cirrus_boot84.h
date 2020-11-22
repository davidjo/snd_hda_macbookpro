
static void setup_reset_and_clear(struct hda_codec *codec)
{

        // so now really dont know why I skipped all this - maybe because they
        // almost entirely reads??
        // - except it does clear all the pin configs
        // plus does a DBL init

        int retval;


        mycodec_info(codec, "command nid start setup_node_reset_and_clear\n");

        retval = snd_hda_codec_read_check(codec, 0x00, 0, AC_VERB_PARAMETERS, 0x00000000, 0x10138409, 1); // 0x000f0000
        retval = snd_hda_codec_read_check(codec, 0x00, 0, AC_VERB_PARAMETERS, 0x00000002, 0x00100100, 2); // 0x000f0002
        retval = snd_hda_codec_read_check(codec, 0x00, 0, AC_VERB_PARAMETERS, 0x00000000, 0x10138409, 3); // 0x000f0000
        retval = snd_hda_codec_read_check(codec, 0x00, 0, AC_VERB_PARAMETERS, 0x00000002, 0x00100100, 4); // 0x000f0002
        retval = snd_hda_codec_read_check(codec, 0x00, 0, AC_VERB_PARAMETERS, 0x00000004, 0x00010001, 5); // 0x000f0004

        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_PARAMETERS, 0x00000004, 0x00020046, 6); // 0x001f0004
        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000101, 7); // 0x001f0005
        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_SUBSYSTEM_ID, 0x00000000, 0x106b3900, 8); // 0x001f2000

        retval = snd_hda_codec_read_check(codec, 0x00, 0, AC_VERB_PARAMETERS, 0x00000000, 0x10138409, 9); // 0x000f0000
        retval = snd_hda_codec_read_check(codec, 0x00, 0, AC_VERB_PARAMETERS, 0x00000002, 0x00100100, 10); // 0x000f0002

        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_PARAMETERS, 0x0000000f, 0xe0000019, 11); // 0x001f000f


        // AppleHDACodecGeneric::start(IOService*)


        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_DBL_CODEC_RESET, 0x00000000); // 0x001fff00
        snd_hda_double_reset(codec);

        retval = snd_hda_codec_read_check(codec, 0x00, 0, AC_VERB_PARAMETERS, 0x00000000, 0x10138409, 13); // 0x000f0000
        retval = snd_hda_codec_read_check(codec, 0x00, 0, AC_VERB_PARAMETERS, 0x00000002, 0x00100100, 14); // 0x000f0002


        // AppleHDANode::initForNodeID(unsigned short, OSObject*, OSObject*)

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


        // AppleHDAFunctionGroup::initForNodeID??

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_SUBSYSTEM_ID, 0x00000000, 0x106b3900, 22); // 0x001f2000
        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_PARAMETERS, 0x00000008, 0x00010000, 23); // 0x001f0008

        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_GPIO_DIRECTION, 0x00000000, 0x00000000, 24); // 0x001f1700
//      snd_hda:     gpio direction 1 0x00 in in in in in in in in

        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_PARAMETERS, 0x00000011, 0xc0000008, 25); // 0x001f0011
//      snd_hda:     gpio params 1 [('GPIO', 8), ('GPIO_WAKE', 1), ('GPO', 0), ('GPI', 0), ('GPIO_UNSOL', 1)]

        mycodec_info(codec, "command nid start setup_node_reset_and_clear end\n");

}

static void init_read_all_nodes(struct hda_codec *codec)
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

static void read_vendor_node(struct hda_codec *codec)
{
        int retval;

        // I think this is also part of the node init loop

        // this may involve calls to AppleHDAWidgetCS8409::initForNodeID for each node
        // and AppleHDAWidget::initForNodeID(unsigned short, OSObject*, OSObject*)  for each node

        retval = snd_hda_codec_read_check(codec, CS8409_VENDOR_NID, 0, AC_VERB_PARAMETERS, 0x00000005, 0x00000000, 797); // 0x047f0005
        retval = snd_hda_codec_read_check(codec, CS8409_VENDOR_NID, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00f002c1, 798); // 0x047f0009
//      snd_hda:     71 AC_WID_VENDOR ['AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_UNSOL_CAP', 'AC_WCAP_DELAY', 'AC_WCAP_PROC_WID', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_DIGITAL'] 0 0 15

        // new addition June 2019
        retval = snd_hda_codec_read_check(codec, CS8409_VENDOR_NID, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 799); // 0x047f000f
        retval = snd_hda_codec_read_check(codec, CS8409_VENDOR_NID, 0, AC_VERB_PARAMETERS, 0x00000012, 0x00000000, 800); // 0x047f0012
//      snd_hda:     amp capabilities 71 output 0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0
        retval = snd_hda_codec_read_check(codec, CS8409_VENDOR_NID, 0, AC_VERB_PARAMETERS, 0x0000000d, 0x00000000, 801); // 0x047f000d
//      snd_hda:     amp capabilities 71 input  0x00000000 offset 0x00 numsteps 0x00 stepsize 0x00 mute 0

        retval = snd_hda_codec_read_check(codec, CS8409_VENDOR_NID, 0, AC_VERB_PARAMETERS, 0x00000009, 0x00f002c1, 802); // 0x047f0009
//      snd_hda:     71 AC_WID_VENDOR ['AC_WCAP_STEREO', 'AC_WCAP_TYPE', 'AC_WCAP_UNSOL_CAP', 'AC_WCAP_DELAY', 'AC_WCAP_PROC_WID', 'AC_WCAP_CHAN_CNT_EXT', 'AC_WCAP_DIGITAL'] 0 0 15

}

static void read_coefs_all(struct hda_codec *codec);

static void init_read_coefs(struct hda_codec *codec)
{

        int retval;


        // in AppleHDAWidget::initForNodeID(unsigned short, OSObject*, OSObject*)

        // get number of coefs in bits 15:8 - here 0x0000ff00 ie 255
        retval = snd_hda_codec_read_check(codec, CS8409_VENDOR_NID, 0, AC_VERB_PARAMETERS, 0x00000010, 0x0000ff00, 803); // 0x047f0010


        // this is after the read_all_nodes loop

        read_coefs_all(codec);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003);
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}

static void read_coefs_all(struct hda_codec *codec)
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
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0059, 0x0000, 0x00000074, 1160 ); //   coef read 1160
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005a, 0x0000, 0x0000007f, 1164 ); //   coef read 1164
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005b, 0x0000, 0x00000010, 1168 ); //   coef read 1168
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005c, 0x0000, 0x00000020, 1172 ); //   coef read 1172
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005d, 0x0000, 0x00002d7f, 1176 ); //   coef read 1176
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005e, 0x0000, 0x00002d7f, 1180 ); //   coef read 1180
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

static void read_virtual_widgets(struct hda_codec *codec)
{
       // setup the virtual widgets

        unsigned int retval;

        mycodec_info(codec, "command nid start read_virtual_widgets\n");

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
        retval = snd_hda_codec_read_check(codec, 0x4a, 0, AC_VERB_PARAMETERS, 0x0000000f, 0x00000000, 1364); // 0x04bf000f
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


        mycodec_info(codec, "command nid end   read_virtual_widgets\n");

}

static void setup_jack_pin_config(struct hda_codec *codec)
{

        //int retval;
        struct cs_spec *spec = codec->spec;

        // this is likely some call of setPinConfigDefault
	// 0x45 -> 0x23 (macbook pro) is the line in path - so why does it say its a mike??

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        snd_hda_codec_write(codec, spec->linein_nid, 0, AC_VERB_SET_CONFIG_DEFAULT_BYTES_0, 0x00000001); // 0x04571c01
        snd_hda_codec_write(codec, spec->linein_nid, 0, AC_VERB_SET_CONFIG_DEFAULT_BYTES_1, 0x00000001); // 0x04571d01
        snd_hda_codec_write(codec, spec->linein_nid, 0, AC_VERB_SET_CONFIG_DEFAULT_BYTES_2, 0x000000a0); // 0x04571ea0
        snd_hda_codec_write(codec, spec->linein_nid, 0, AC_VERB_SET_CONFIG_DEFAULT_BYTES_3, 0x00000090); // 0x04571f90
//      snd_hda:     pin config 0x90a00101 port conn 2 location 0x10 loc ext 1 loc geom 0 default device 10 conn type 0 color 0 misc 1 def assoc 0 seq 1
//      snd_hda:     pin config 0x90a00101 port conn Fixed loc ext Int loc geom N/A default device Mic In conn type Unknown color Unknown misc Jack Detect Override def assoc 0 seq 1

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}

static void enable_i2c(struct hda_codec *codec)
{
        //int retval;

        // AppleBusControllerCS8409::init

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301

//      snd_hda: # AppleHDAFunctionGroupCS8409::enableI2CClock: 
        // codes from windows cs4208_38.inf file
        // 0x9008 = PLL1_EN(0x1000),I2C_EN(0x8)
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1691 ); // AppleHDAFunctionGroupCS8409::enableI2C  coef read 1691
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1695 ); // AppleHDAFunctionGroupCS8409::enableI2C  coef write 1695

        // 0x0002 0x0080 +GPIO_I2C (0x80) not used ASP1_BUS_IDLE = 0x200 ASP2_BUS_IDLE = 0x800 (0b1010) ASP1/2_BUS_IDLE = 10
        // 0x005b undocumented
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0002, 0x0000, 0x00000000, 1699 ); // AppleHDAFunctionGroupCS8409::enableI2C  coef read 1699
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0002, 0x0080, 0x00000000, 1703 ); // AppleHDAFunctionGroupCS8409::enableI2C  coef write 1703
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0002, 0x0000, 0x00000080, 1707 ); // AppleHDAFunctionGroupCS8409::enableI2C  coef read 1707
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x005b, 0x0000, 0x00000010, 1711 ); // AppleHDAFunctionGroupCS8409::enableI2C  coef read 1711
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005b, 0x0010, 0x00000000, 1715 ); // AppleHDAFunctionGroupCS8409::enableI2C  coef write 1715

//      snd_hda: # AppleHDAFunctionGroupCS8409::enableI2CClock: 
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1719 ); // AppleHDAFunctionGroupCS8409::enableI2C  coef read 1719
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 1723 ); // AppleHDAFunctionGroupCS8409::enableI2C  coef write 1723

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}


static void init_for_node_vendor(struct hda_codec *codec)
{
        //int retval;
        int coef_idx = 0x1a;
        //int coef_ret = 0;

        // this is AppleHDAFunctionGroupCS8409::initForNodeID

        mycodec_info(codec, "command init_for_node_vendor start\n");

        // these 2 items seem to enable the i2c clock - but we havent enabled i2c yet!!
        // whats the difference??
        // Im certain this is enabling the i2c clock
        // codes from windows cs4208_38.inf file
        // 0x9008 = PLL1_EN(0x1000),I2C_EN(0x8)
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009008, 1371 ); //   coef read 1371
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9008, 0x00000000, 1375 ); //   coef write 1375

        // clear these coefs
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000000, 1379 ); //   coef read 1379
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000000, 1383 ); //   coef write 1383
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0017, 0x0000, 0x00000000, 1387 ); //   coef write 1387
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0018, 0x0000, 0x00000000, 1391 ); //   coef write 1391
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0002, 0x0000, 0x00000000, 1395 ); //   coef write 1395

        //coef_ret = cs_8409_vendor_coef_set(codec, 0x19, 0x8000);
        cs_8409_vendor_coef_set(codec, 0x19, 0x8000);

        //if (coef_ret == -1) error;

        while (coef_idx <= 0x57)
        {
                //coef_ret = cs_8409_vendor_coef_set(codec, coef_idx, 0x8000);
                cs_8409_vendor_coef_set(codec, coef_idx, 0x8000);

                //if (coef_ret == -1) error;

                coef_idx++;
        }

        // 0x82 0x0000 ASP1/2_xxx_EN = 0, DMIC1/2_SCL_EN = 0
        // others not documented cs4208_38.inf
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x000a, 0x0000, 0x00000000, 1651 ); //   coef write 1651
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0082, 0x0000, 0x00000000, 1655 ); //   coef write 1655
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006b, 0x001f, 0x00000000, 1659 ); //   coef write 1659
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006c, 0x001f, 0x00000000, 1663 ); //   coef write 1663
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0082, 0x0000, 0x00000000, 1667 ); //   coef write 1667


        mycodec_info(codec, "command init_for_node_vendor end\n");

}

static void determine_speaker_id(struct hda_codec *codec)
{
        int retval;

        // this is determineSpeakerID
        // this does not make sense - this just checks a GPIO pin??

        mycodec_info(codec, "command determine_speaker_id start\n");

        // this is call AppleHDAFunctionGroup::setGPIOEnable in determineSpeakerID

        if (codec->core.subsystem_id == 0x106b3900)
        {
                //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_MASK, 0x00000008); // 0x00171608
//              snd_hda:     gpio enable 1 0x08

                //retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_GPIO_DATA, 0x00000000, 0x00000000, 1672); // 0x001f1500
//              snd_hda:     gpio data 1 0x00

                //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_MASK, 0x0000000c); // 0x0017160c
//              snd_hda:     gpio enable 1 0x0c

                //retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_GPIO_DATA, 0x00000000, 0x00000000, 1674); // 0x001f1500
//              snd_hda:     gpio data 1 0x00

                snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_MASK, 0x00000008); // 0x00171608

                retval = snd_hda_codec_read(codec, codec->core.afg, 0, AC_VERB_GET_GPIO_DATA, 0x00000000); // 0x001f1500

                mycodec_info(codec, "command determine_speaker_id gpio data 0x%08x\n", retval);

                snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_MASK, 0x0000000c); // 0x0017160c

                retval = snd_hda_codec_read(codec, codec->core.afg, 0, AC_VERB_GET_GPIO_DATA, 0x00000000); // 0x001f1500

                mycodec_info(codec, "command determine_speaker_id gpio data 0x%08x\n", retval);

	}
	else
        {
                //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_MASK, 0x00000004); // 0x00171604
//              snd_hda:     gpio enable 1 0x04

                //retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_GPIO_DATA, 0x00000000, 0x00000004, 1672); // 0x001f1500
//              snd_hda:     gpio data 1 0x04

                snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_MASK, 0x04); // 0x00171604

                retval = snd_hda_codec_read(codec, codec->core.afg, 0, AC_VERB_GET_GPIO_DATA, 0x00000000); // 0x001f1500

                mycodec_info(codec, "command determine_speaker_id gpio data 0x%08x\n", retval);

	}

        mycodec_info(codec, "command determine_speaker_id end\n");

}


static void enable_GPIforUR(struct hda_codec *codec, int mask)
{
        int retval;


        // AppleHDAFunctionGroupCS8409::enableGPIforUR

        mycodec_info(codec, "command enable_GPIforUR start\n");

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);


        // this is AppleHDAFunctionGroup::setGPIOEnable in AppleHDAFunctionGroup::enableGPIforUR
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_MASK, 0x00000005); // 0x00171605
//      snd_hda:     gpio enable 1 0x05

        // this is AppleHDAFunctionGroup::setGPIODirection in AppleHDAFunctionGroup::enableGPIforUR
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DIRECTION, 0x00000000); // 0x00171700
//      snd_hda:     gpio direction 1 0x00 in in in in in in in in


        //retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_GPIO_WAKE_MASK, 0x00000000, 0x00000000, 1735); // 0x001f1800
//      snd_hda:     gpio wake enable 1 0x00
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_WAKE_MASK, 0x00000001); // 0x00171801
//      snd_hda:     gpio wake enable 1 0x01
        //retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_GPIO_UNSOLICITED_RSP_MASK, 0x00000000, 0x00000000, 1737); // 0x001f1900
//      snd_hda:     gpio unsol enable 1 0x00
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_UNSOLICITED_RSP_MASK, 0x00000001); // 0x00171901
//      snd_hda:     gpio unsol enable 1 0x01


        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_MASK, mask); // 0x00171605

        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DIRECTION, 0x00000000); // 0x00171700

        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_GPIO_WAKE_MASK, 0x00000000, 0x00000000, 1735); // 0x001f1800

        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_WAKE_MASK, 0x00000001); // 0x00171801

        retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_GPIO_UNSOLICITED_RSP_MASK, 0x00000000, 0x00000000, 1737); // 0x001f1900

        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_UNSOLICITED_RSP_MASK, 0x00000001); // 0x00171901


        // likely last runVerb of AppleHDAFunctionGroupCS8409::enableGPIforUR
        snd_hda_codec_write(codec, codec->core.afg, 0, 0x7f0, 0x000000b7);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        mycodec_info(codec, "command enable_GPIforUR end\n");

}

        // this may be more likely
        // only issue is that AppleHDATDM_Codec::resetDevice seems to have other functions that seem likely to send i2c data
        // note the setExternalControlForDefaultDeviceTypeAndTag function sends the GPIO updates as noted above
        // but AppleHDATDM_CS42L83::resetDevice contains the 0x1301 to 0x130f sequence
        // AppleHDATDM_CS42L83::init
        //         AppleHDATDM_CS42L83::resetDevice
        //                 AppleHDATDM_Codec::resetDevice
        //                        AppleHDAFunctionGroup::externalControlExistsForDefaultDeviceTypeAndTag(0xf(%rsi), 0x35(%rdx))
        //                        AppleHDAFunctionGroup::setExternalControlForDefaultDeviceTypeAndTag(1(%rsi), 0xf(%rdx), 0x35(%rcx))
        //                                AppleHDAFunctionGroupExternalControl::setExternalControlState(unk(%rsi), unk(%rdx))
        //                        AppleHDAFunctionGroup::setExternalControlForDefaultDeviceTypeAndTag(0(%rsi), 0xf(%rdx), 0x35(%rcx))
        //                                AppleHDAFunctionGroupExternalControl::setExternalControlState(unk(%rsi), unk(%rdx))

        //                                AppleHDAFunctionGroupExternalControl::setExternalControlState
        //                                calls AppleHDAFunctionGroupExternalControl::publicSetExternalControlState
        //                                this appears to be virtual - the definition just asserts
        //                                good candidate is AppleHDAFunctionGroupExternalControl_GPIO::publicSetExternalControlState
        //                                AppleHDAFunctionGroupExternalControl_GPIO::publicSetExternalControlState
        //                                is the function which does the external_control_GPIO_clear0 or external_control_GPIO_set1
        //                                functions below

        //         followed by i2c calls for 0x1301 to 0x130f
        // we have a 2nd set of GPIO clear/set calls which cant figure out where they get called
        // followed by i2c calls 0x1001
        // followed by i2c calls 0x1005
        // followed by AppleHDATDM_CS42L83::_initHW()


static void cs42l83_external_control_GPIO_clear_2(struct hda_codec *codec,int mask);
static void cs42l83_external_control_GPIO_set_2(struct hda_codec *codec,int mask);

static void cs42l83_external_control_GPIO(struct hda_codec *codec,int mask)
{

        // from AppleHDATDM_Codec::resetDevice

        // I think this is resetting the device by pulling some line low then high
        // GPIO 2 is for the cs42l83

        // note that AppleHDAFunctionGroupExternalControl::setExternalControlState
        // has an IOSleep() as the first call depending on a value - if non-zero time to sleep
        // if 0 IOSleep() call ignored 

        mycodec_info(codec, "command cs42l83_external_control_GPIO start\n");

        // this clearing then setting gpio bit 2

        //usleep_range(2000,4000);

        cs42l83_external_control_GPIO_clear_2(codec,mask);

        //usleep_range(2000,4000);

        cs42l83_external_control_GPIO_set_2(codec,mask);


        mycodec_info(codec, "command cs42l83_external_control_GPIO end\n");

}


static void cs42l83_external_control_GPIO_clear_2(struct hda_codec *codec,int mask)
{

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        // plausibly AppleHDAFunctionGroupExternalControl_GPIO::publicSetExternalControlState(bool)

        // AppleHDAFunctionGroup::setGPIODirection
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DIRECTION, 0x00000002); // 0x00171702
//      snd_hda:     gpio direction 1 0x02 in in in in in in out in
        // AppleHDAFunctionGroup::setGPIOData
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DATA, 0x00000000); // 0x00171500
//      snd_hda:     gpio data 1 0x00
        // AppleHDAFunctionGroup::setGPIOEnable
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_MASK, 0x00000007); // 0x00171607
//      snd_hda:     gpio enable 1 0x07


        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DIRECTION, 0x00000002); // 0x00171702
        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DATA, 0x00000000); // 0x00171500
        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_MASK, mask); // 0x00171607

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}

static void cs42l83_external_control_GPIO_set_2(struct hda_codec *codec,int mask)
{

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        // plausibly AppleHDAFunctionGroupExternalControl_GPIO::publicSetExternalControlState(bool)

        // AppleHDAFunctionGroup::setGPIODirection
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DIRECTION, 0x00000002); // 0x00171702
//      snd_hda:     gpio direction 1 0x02 in in in in in in out in
        // AppleHDAFunctionGroup::setGPIOData
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DATA, 0x00000002); // 0x00171502
//      snd_hda:     gpio data 1 0x02
        // AppleHDAFunctionGroup::setGPIOEnable
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_MASK, 0x00000007); // 0x00171607
//      snd_hda:     gpio enable 1 0x07


        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DIRECTION, 0x00000002); // 0x00171702
        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DATA, 0x00000002); // 0x00171502
        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_MASK, mask); // 0x00171607

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}


static void cs42l83_reset(struct hda_codec *codec)
{
        //      AppleHDATDM_CS42L83::resetDevice()

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

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0100 i2c data 0x0100
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0200 i2c data 0x0200
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0300 i2c data 0x030c
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0400 i2c data 0x0400
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0500 i2c data 0x0500
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0b00 i2c data 0x0b60
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0d00 i2c data 0x0d01
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0e00 i2c data 0x0e00
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0800 i2c data 0x0801
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0f00 i2c data 0x0f00

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1301, 1); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0x90, 0x1302, 1); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0x90, 0x1303, 1); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0x90, 0x1304, 1); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0x90, 0x1305, 1); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0x90, 0x130b, 1); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0x90, 0x130d, 1); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0x90, 0x130e, 1); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0x90, 0x1308, 1); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0x90, 0x130f, 1); // snd_hda

        mycodec_info(codec, "command cs42l83_reset end\n");
}

static int cs42l83_device_id(struct hda_codec *codec)
{
        int retval_dev;
        int retval_rev;
        int ret_id;

        // in AppleHDATDM_CS42L83::init

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x10 lo 0x0100 i2c data 0x0142
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x10 lo 0x0500 i2c data 0x05b0

        retval_dev = cs_8409_vendor_i2cRead(codec, 0x90, 0x1001, 1); // snd_hda
        retval_rev = cs_8409_vendor_i2cRead(codec, 0x90, 0x1005, 1); // snd_hda

        ret_id = ((retval_dev & 0xff) << 16) | (retval_rev & 0xff);

        mycodec_info(codec, "command cs42l83_device_id end\n");

        return ret_id;
}

static void cs42l83_inithw(struct hda_codec *codec)
{

        // AppleHDATDM_CS42L83::_initHW() called from AppleHDATDM_CS42L83::init

        // this triggers the 1st UNSOL response

        mycodec_info(codec, "command cs42l83_inithw start\n");


//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x11 lo 0x0300 i2c data 0x0320
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x0322 i2c data 0x0022
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x2901 i2c data 0x0001
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x13 lo 0x200f i2c data 0x000f
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x1b00 i2c data 0x1b03
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x13 lo 0x1b03 i2c data 0x0003
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x23 lo 0x023f i2c data 0x003f
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1f lo 0x0100 i2c data 0x0000
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x21a6 i2c data 0x00a6
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x13 lo 0x1600 i2c data 0x0000
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x13 lo 0x1700 i2c data 0x0000
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x13 lo 0x1800 i2c data 0x0000
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x13 lo 0x1900 i2c data 0x0000
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x13 lo 0x1a00 i2c data 0x0000
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x1c00 i2c data 0x1c7f
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x13 lo 0x1c1a i2c data 0x001a
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x13 lo 0x1e00 i2c data 0x0000
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x13 lo 0x1f00 i2c data 0x0000
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0100 i2c data 0x0100
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0200 i2c data 0x0200
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0300 i2c data 0x030c
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0400 i2c data 0x0400
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0500 i2c data 0x0500
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0b00 i2c data 0x0b60
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0d00 i2c data 0x0d01
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0e00 i2c data 0x0e00
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0800 i2c data 0x0801
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0f00 i2c data 0x0f00
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x11 lo 0x0100 i2c data 0x01ff
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x01fe i2c data 0x00fe
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7500 i2c data 0x751f
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x759f i2c data 0x009f


        cs_8409_vendor_i2cRead(codec, 0x90, 0x1103, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1103, 0x0022, 1); // snd_hda

        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1129, 0x0001, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1320, 0x000f, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x131b, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x131b, 0x0003, 1); // snd_hda

        cs_8409_vendor_i2cWrite(codec, 0x90, 0x2302, 0x003f, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1f01, 0x0000, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1121, 0x00a6, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1316, 0x0000, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1317, 0x0000, 1); // snd_hda

        // this triggers an UNSOL response with interrupt cleared state
        // this writes to SRC Interrupt Mask unmasking all interrupts

        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1318, 0x0000, 1); // snd_hda


        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1319, 0x0000, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x131a, 0x0000, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x131c, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x131c, 0x001a, 1); // snd_hda

        cs_8409_vendor_i2cWrite(codec, 0x90, 0x131e, 0x0000, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x131f, 0x0000, 1); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0x90, 0x1301, 1); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0x90, 0x1302, 1); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0x90, 0x1303, 1); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0x90, 0x1304, 1); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0x90, 0x1305, 1); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0x90, 0x130b, 1); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0x90, 0x130d, 1); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0x90, 0x130e, 1); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0x90, 0x1308, 1); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0x90, 0x130f, 1); // snd_hda

        // the following is setting the power register

        // register 0x1101 - Power Down Control 1
        //                   0xff powered down 0x00 powered up
        //                   changed from 0xff to 0xfe (Codec power up)

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1101, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1101, 0x00fe, 1); // snd_hda

        // the following is setting the mic detect register

        // register 0x1b75 - Mic Detect Control 1
        //                   changed from 0x1f ((0x80 LATCH_TO_VP unset, HS_DETECT_LEVEL 1f) to 0x9f (0x80 LATCH_TO_VP set, HS_DETECT_LEVEL 0x1f)

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1b75, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b75, 0x009f, 1); // snd_hda


        mycodec_info(codec, "command cs42l83_inithw end\n");
}

static void setup_gpio_set_20(struct hda_codec *codec);

static void setup_amps_reset_i2c_max(struct hda_codec *codec)
{
        // based on info from bugs 195671 and 110561
        // and that writing to coef index 0x59 seems to be the i2c address hence the i2c address following are
        // the amps 62, 64, 72, 74
        // also the data being sent does correpond to the registers of the MAX98372 from data sheet
        // which is supposedly similar to the actual MAX98706
        // all analysis of the i2cWrite data is based on the MAX98372 data sheet

        setup_gpio_set_20(codec);

//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x5101 i2c data 0x0001   reg anal: SoftwareReset           : Reset
        cs_8409_vendor_i2cWrite(codec, 0x64, 0x0051, 0x0001, 0); // snd_hda

        setup_gpio_set_20(codec);

//      snd_hda i2cWrite      i2c address 0x62 i2c            reg 0x5101 i2c data 0x0001   reg anal: SoftwareReset           : Reset
        cs_8409_vendor_i2cWrite(codec, 0x62, 0x0051, 0x0001, 0); // snd_hda

        setup_gpio_set_20(codec);

//      snd_hda i2cWrite      i2c address 0x74 i2c            reg 0x5101 i2c data 0x0001   reg anal: SoftwareReset           : Reset
        cs_8409_vendor_i2cWrite(codec, 0x74, 0x0051, 0x0001, 0); // snd_hda

        setup_gpio_set_20(codec);

//      snd_hda i2cWrite      i2c address 0x72 i2c            reg 0x5101 i2c data 0x0001   reg anal: SoftwareReset           : Reset
        cs_8409_vendor_i2cWrite(codec, 0x72, 0x0051, 0x0001, 0); // snd_hda

}

static void setup_gpio_set_20(struct hda_codec *codec)
{

        // plausibly AppleHDAFunctionGroupExternalControl_GPIO::publicSetExternalControlState(bool)

        // I think this may be associated with the amps
        // - this is a difference between the MBP 13,1 and SSM amps and 14,3 and MAX amps
        // its either applying power to the amps or taking them out of reset
        // (note that unlike GPIO 2 there doesnt seem to be a clear 20)

        mycodec_info(codec, "command setup_gpio_set_20 start\n");

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DIRECTION, 0x00000022); // 0x00171722
//      snd_hda:     gpio direction 1 0x22 in in out in in in out in
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DATA, 0x00000022); // 0x00171522
//      snd_hda:     gpio data 1 0x22
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_MASK, 0x00000027); // 0x00171627
//      snd_hda:     gpio enable 1 0x27


        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DIRECTION, 0x00000022); // 0x00171722
        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DATA, 0x00000022); // 0x00171522
        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_MASK, 0x00000027); // 0x00171627

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        mycodec_info(codec, "command setup_gpio_set_20 end\n");
}


static void setup_amps_reset_i2c_ssm3(struct hda_codec *codec)
{

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x28 i2c            reg 0x0083 i2c data 0x0083   reg anal: PowerControl            : PowerDown SoftwareReset BVSenseOn AutoPwrOffEnabled
//      snd_hda i2cWrite      i2c address 0x2a i2c            reg 0x0083 i2c data 0x0083   reg anal: PowerControl            : PowerDown SoftwareReset BVSenseOn AutoPwrOffEnabled
//      snd_hda i2cWrite      i2c address 0x2c i2c            reg 0x0083 i2c data 0x0083   reg anal: PowerControl            : PowerDown SoftwareReset BVSenseOn AutoPwrOffEnabled
//      snd_hda i2cWrite      i2c address 0x2e i2c            reg 0x0083 i2c data 0x0083   reg anal: PowerControl            : PowerDown SoftwareReset BVSenseOn AutoPwrOffEnabled

        cs_8409_vendor_i2cWrite(codec, 0x28, 0x0000, 0x0083, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x2a, 0x0000, 0x0083, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x2c, 0x0000, 0x0083, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x2e, 0x0000, 0x0083, 1); // snd_hda

}


static void setup_gpio_set_10(struct hda_codec *codec);

static void setup_amps_reset_i2c_tas576(struct hda_codec *codec)
{
        // the Texas TAS5764 is undocumented - the nearest seems to be the TAS5760md
        // which has some similarities but some discrepancies
        // for the moment using the TAS5760md registers where they seem to be similar
        // based on info that writing to coef index 0x59 seems to be the i2c address hence the amps i2c address following are
        // 0xd8, 0xda, 0xdc, 0xde

        setup_gpio_set_10(codec);

//      snd_hda i2cWrite      i2c address 0xd8 i2c            reg 0x01fc i2c data 0x00fc   reg anal: Power Control           : Not Sleep, Spkr Amp Shutdown
//      snd_hda i2cWrite      i2c address 0xd8 i2c            reg 0x0204 i2c data 0x0004   reg anal: Digital Control         : I2S format
//      snd_hda i2cWrite      i2c address 0xd8 i2c            reg 0x0380 i2c data 0x0080   reg anal: Volume Control          : Fade
//      snd_hda i2cWrite      i2c address 0xd8 i2c            reg 0x04cf i2c data 0x00cf   reg anal: Left Chan Vol Control   : 0dB
//      snd_hda i2cWrite      i2c address 0xd8 i2c            reg 0x0651 i2c data 0x0051   reg anal: Analog Control          : PWM Rate x16
//      snd_hda i2cWrite      i2c address 0xd8 i2c            reg 0x0800 i2c data 0x0000   reg anal: Fault Config & Error
//      snd_hda i2cWrite      i2c address 0xd8 i2c            reg 0x10ff i2c data 0x00ff   reg anal: Digital Clipper
//      snd_hda i2cWrite      i2c address 0xd8 i2c            reg 0x11fc i2c data 0x00fc   reg anal: Undocumented
//      snd_hda i2cWrite      i2c address 0xd8 i2c            reg 0x1300 i2c data 0x0000   reg anal: Undocumented
//      snd_hda i2cWrite      i2c address 0xd8 i2c            reg 0x1402 i2c data 0x0002   reg anal: Undocumented

        cs_8409_vendor_i2cWrite(codec, 0xd8, 0x0001, 0x00fc, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xd8, 0x0002, 0x0004, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xd8, 0x0003, 0x0080, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xd8, 0x0004, 0x00cf, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xd8, 0x0006, 0x0051, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xd8, 0x0008, 0x0000, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xd8, 0x0010, 0x00ff, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xd8, 0x0011, 0x00fc, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xd8, 0x0013, 0x0000, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xd8, 0x0014, 0x0002, 0); // snd_hda

        setup_gpio_set_10(codec);

//      snd_hda i2cWrite      i2c address 0xda i2c            reg 0x01fc i2c data 0x00fc   reg anal: Power Control           : Not Sleep, Spkr Amp Shutdown
//      snd_hda i2cWrite      i2c address 0xda i2c            reg 0x0204 i2c data 0x0004   reg anal: Digital Control         : I2S format
//      snd_hda i2cWrite      i2c address 0xda i2c            reg 0x0380 i2c data 0x0080   reg anal: Volume Control          : Fade
//      snd_hda i2cWrite      i2c address 0xda i2c            reg 0x04cf i2c data 0x00cf   reg anal: Left Chan Vol Control   : 0dB
//      snd_hda i2cWrite      i2c address 0xda i2c            reg 0x0651 i2c data 0x0051   reg anal: Analog Control          : PWM Rate x16
//      snd_hda i2cWrite      i2c address 0xda i2c            reg 0x0800 i2c data 0x0000   reg anal: Fault Config & Error
//      snd_hda i2cWrite      i2c address 0xda i2c            reg 0x10ff i2c data 0x00ff   reg anal: Digital Clipper
//      snd_hda i2cWrite      i2c address 0xda i2c            reg 0x11fc i2c data 0x00fc   reg anal: Undocumented
//      snd_hda i2cWrite      i2c address 0xda i2c            reg 0x1300 i2c data 0x0000   reg anal: Undocumented
//      snd_hda i2cWrite      i2c address 0xda i2c            reg 0x1402 i2c data 0x0002   reg anal: Undocumented

        cs_8409_vendor_i2cWrite(codec, 0xda, 0x0001, 0x00fc, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xda, 0x0002, 0x0004, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xda, 0x0003, 0x0080, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xda, 0x0004, 0x00cf, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xda, 0x0006, 0x0051, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xda, 0x0008, 0x0000, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xda, 0x0010, 0x00ff, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xda, 0x0011, 0x00fc, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xda, 0x0013, 0x0000, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xda, 0x0014, 0x0002, 0); // snd_hda

        setup_gpio_set_10(codec);

//      snd_hda i2cWrite      i2c address 0xdc i2c            reg 0x01fc i2c data 0x00fc   reg anal: Power Control           : Not Sleep, Spkr Amp Shutdown
//      snd_hda i2cWrite      i2c address 0xdc i2c            reg 0x0204 i2c data 0x0004   reg anal: Digital Control         : I2S format
//      snd_hda i2cWrite      i2c address 0xdc i2c            reg 0x0380 i2c data 0x0080   reg anal: Volume Control          : Fade
//      snd_hda i2cWrite      i2c address 0xdc i2c            reg 0x04cf i2c data 0x00cf   reg anal: Left Chan Vol Control   : 0dB
//      snd_hda i2cWrite      i2c address 0xdc i2c            reg 0x0651 i2c data 0x0051   reg anal: Analog Control          : PWM Rate x16
//      snd_hda i2cWrite      i2c address 0xdc i2c            reg 0x0800 i2c data 0x0000   reg anal: Fault Config & Error
//      snd_hda i2cWrite      i2c address 0xdc i2c            reg 0x10ff i2c data 0x00ff   reg anal: Digital Clipper
//      snd_hda i2cWrite      i2c address 0xdc i2c            reg 0x11fc i2c data 0x00fc   reg anal: Undocumented
//      snd_hda i2cWrite      i2c address 0xdc i2c            reg 0x1300 i2c data 0x0000   reg anal: Undocumented
//      snd_hda i2cWrite      i2c address 0xdc i2c            reg 0x1402 i2c data 0x0002   reg anal: Undocumented

        cs_8409_vendor_i2cWrite(codec, 0xdc, 0x0001, 0x00fc, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xdc, 0x0002, 0x0004, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xdc, 0x0003, 0x0080, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xdc, 0x0004, 0x00cf, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xdc, 0x0006, 0x0051, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xdc, 0x0008, 0x0000, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xdc, 0x0010, 0x00ff, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xdc, 0x0011, 0x00fc, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xdc, 0x0013, 0x0000, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xdc, 0x0014, 0x0002, 0); // snd_hda

        setup_gpio_set_10(codec);

//      snd_hda i2cWrite      i2c address 0xde i2c            reg 0x01fc i2c data 0x00fc   reg anal: Power Control           : Not Sleep, Spkr Amp Shutdown
//      snd_hda i2cWrite      i2c address 0xde i2c            reg 0x0204 i2c data 0x0004   reg anal: Digital Control         : I2S format
//      snd_hda i2cWrite      i2c address 0xde i2c            reg 0x0380 i2c data 0x0080   reg anal: Volume Control          : Fade
//      snd_hda i2cWrite      i2c address 0xde i2c            reg 0x04cf i2c data 0x00cf   reg anal: Left Chan Vol Control   : 0dB
//      snd_hda i2cWrite      i2c address 0xde i2c            reg 0x0651 i2c data 0x0051   reg anal: Analog Control          : PWM Rate x16
//      snd_hda i2cWrite      i2c address 0xde i2c            reg 0x0800 i2c data 0x0000   reg anal: Fault Config & Error
//      snd_hda i2cWrite      i2c address 0xde i2c            reg 0x10ff i2c data 0x00ff   reg anal: Digital Clipper
//      snd_hda i2cWrite      i2c address 0xde i2c            reg 0x11fc i2c data 0x00fc   reg anal: Undocumented
//      snd_hda i2cWrite      i2c address 0xde i2c            reg 0x1300 i2c data 0x0000   reg anal: Undocumented
//      snd_hda i2cWrite      i2c address 0xde i2c            reg 0x1402 i2c data 0x0002   reg anal: Undocumented

        cs_8409_vendor_i2cWrite(codec, 0xde, 0x0001, 0x00fc, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xde, 0x0002, 0x0004, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xde, 0x0003, 0x0080, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xde, 0x0004, 0x00cf, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xde, 0x0006, 0x0051, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xde, 0x0008, 0x0000, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xde, 0x0010, 0x00ff, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xde, 0x0011, 0x00fc, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xde, 0x0013, 0x0000, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xde, 0x0014, 0x0002, 0); // snd_hda

}

static void setup_gpio_set_10(struct hda_codec *codec)
{

        // plausibly AppleHDAFunctionGroupExternalControl_GPIO::publicSetExternalControlState(bool)

        // I think this may be associated with the amps
        // its either applying power to the amps or taking them out of reset
        // (note that unlike GPIO 2 there doesnt seem to be a clear 10)

	// note that this seems to be following the MAX style setup

        mycodec_info(codec, "command setup_gpio_set_10 start\n");

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DIRECTION, 0x00000012); // 0x00171712
//      snd_hda:     gpio direction 1 0x12 in in in out in in out in
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DATA, 0x00000012); // 0x00171512
//      snd_hda:     gpio data 1 0x12
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_MASK, 0x0000001f); // 0x0017161f
//      snd_hda:     gpio enable 1 0x1f


        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DIRECTION, 0x00000012); // 0x00171712
        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DATA, 0x00000012); // 0x00171512
        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_MASK, 0x0000001f); // 0x0017161f

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        mycodec_info(codec, "command setup_gpio_set_10 end\n");
}


static void cs42l83_mic_detect(struct hda_codec *codec)
{
        int retval;
        int newval;

        int detect_standby = 0;

        // likely from AppleHDAMikeyInternalCS8409::setupJackDetection
	// which does call enterStandby with 0 arg

        // enterStandby is only function that issues 0x75 but it doesnt look right
        // mic detect is register name

        // AppleHDATDM_CS42L83::enterStandby

        // so this appears to change 0x1b75 from 0x9f to 0x9f

        // register 0x1b75 - Mic Detect Control 1
        //                   changed from 0x9f ((0x80 LATCH_TO_VP set, HS_DETECT_LEVEL 1f) to 0x9f ((0x80 LATCH_TO_VP set, HS_DETECT_LEVEL 1f)


        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301

        // curious - these functions not separated by power down/ups
        // ah - the log may not be ordered - they are output as a bunch at the end!!

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7500 i2c data 0x759f
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x759f i2c data 0x009f

        retval = cs_8409_vendor_i2cRead(codec, 0x90, 0x1b75, 1); // snd_hda

        if (detect_standby)
                newval = (retval & 0x7f);
        else
                newval = (retval | 0x80);

        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b75, 0x009f, 1); // snd_hda

        mycodec_info(codec, "command cs42l83_mic_detect end\n");
}

static void cs42l83_tip_sense(struct hda_codec *codec)
{
        int retval;
        int newval1;
        int newval2;
        int newval;
        int flag = 0;

        // likely in AppleHDAMikeyInternalCS8409::setupJackDetection
	// - only 0x73 readMikey/writeMikey calls seen

        // register 0x1b73 - Tip Sense Control 2
        //                   changed from 0x02 (default) to 0xc0 (short detect)

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7300 i2c data 0x7302
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x73c0 i2c data 0x00c0

        retval = cs_8409_vendor_i2cRead(codec, 0x90, 0x1b73, 1); // snd_hda

        newval1 = (retval & 0x1c);

        if (flag)
                newval = (newval1 | 0xe0);
	else
                newval = (newval1 | 0xc0);


        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b73, 0x00c0, 1); // snd_hda

        mycodec_info(codec, "command cs42l83_tip_sense end\n");
}


