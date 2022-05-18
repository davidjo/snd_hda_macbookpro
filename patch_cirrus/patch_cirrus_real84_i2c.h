
// this contains functions converted to use proper i2c calls

// re-define this here so can turn this off for this file specifically
#define mycodec_i2c_local_info mycodec_i2c_info

static void cs42l83_headset_button_detect_interrupts_off(struct hda_codec *codec)
{
        //int retval;

	mycodec_i2c_local_info(codec, "cs42l83_headset_button_detect_interrupts_off\n");

        // this could be AppleHDAMikeyInternalCS8409::disableButtonDetection
        // - this calls 0x1b7c and 0x1b7a

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        // register 0x1b7c - this is undocumented for 42l42 (reserved) - maybe more interrupt mask registers
        //                   sort of assuming it shows which interrupts have occurred
        //                   value 0x00
        // register 0x1b7a - Detect Interrupt Mask 2
        //                   changed from 0xff (default) to 0xff (all masked)

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7c00 i2c data 0x7c00
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7a00 i2c data 0x7aff
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x7aff i2c data 0x00ff
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x7aff i2c data 0x00ff

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1b7c, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1b7a, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b7a, 0x00ff, 1); // snd_hda

        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b7a, 0x00ff, 1); // snd_hda

}

static void cs42l83_headset_set_hpout_clamp_disable(struct hda_codec *codec)
{
        //int retval;

	mycodec_i2c_local_info(codec, "cs42l83_headset_set_hpout_clamp_disable\n");

        // AppleHDATDM_CS42L83::setHPOutClamp

        // register 0x1f06 - DAC Control 2
        //                   changed from 0x2 (default) to 0x06

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1f lo 0x0600 i2c data 0x0602
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1f lo 0x0606 i2c data 0x0006

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1f06, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1f06, 0x0006, 1); // snd_hda

}

static void cs42l83_complete_jack_detect(struct hda_codec *codec)
{

	mycodec_i2c_local_info(codec, "cs42l83_complete_jack_detect\n");

        // in AppleHDAMikeyInternalCS8409::completeJackDetectUR

        // similar calls also appear in AppleHDATDM_CS42L83::enterStandby - but these are explicit calls in completeJackDetectUR

        // so this appears to change 0x1b75 from 0x9f to 0xb5
        // according to docs this is 0x80 LATCH_TO_VP set
        // and HS_DETECT_LEVEL from 0x1f (default) to 0x35

        // register 0x1b75 - Mic Detect Control 1
        //                   changed from 0x9f ((0x80 LATCH_TO_VP set, HS_DETECT_LEVEL 1f) to 0xb5 (0x80 LATCH_TO_VP set, HS_DETECT_LEVEL 0x35)

        // maybe readMikey with 0x6 1st arg doesnt do anything??

        // register 0x1b74 - Miscellaneous Detect Control
        //                   changed from 0x3 (default) to 0x1 (Output HiZ, powered Down)

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7500 i2c data 0x759f
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x75b5 i2c data 0x00b5
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7400 i2c data 0x7403
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x7401 i2c data 0x0001

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1b75, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b75, 0x00b5, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1b74, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b74, 0x0001, 1); // snd_hda

}

static void cs42l83_power_hs_bias_on(struct hda_codec *codec)
{

	mycodec_i2c_local_info(codec, "cs42l83_power_hs_bias_on\n");

        // AppleHDAMikeyInternalCS8409::powerHSBIAS

        // readMikey analysis for AppleHDATDM_CS42L83::readMikey
        // if 1st arg is equal or above 0x70 we send eg 0x1b70 (0x1b for our case)
        // if 1st arg is below 0x70 we do special things
        //     subtract 8 from it compare in range 0 to 5
        //     (so 8 becomes 0, 9 becomes 1, 10 becomes 2, 11 becomes 3)
        //     0x111f is loaded by default
        //      8 0 is 0x111f
        //      9 1 is 0x1120
        //     10 2 is 0x1121
        //     11 3 is 0x1124

        // writeMikey analysis for AppleHDATDM_CS42L83::writeMikey
        // if 1st arg is equal or above 0x70 we send eg 0x1b70 (0x1b for our case)
        // if 1st arg is below 0x70 we do special things
        //     subtract 6 from it compare in range 0 to 7
        //     (so 8 becomes 2, 9 becomes 3, 10 becomes 4)
        //     0x111f is loaded by default
        //      8 2 is 0x111f
        //      9 3 is 0x1120
        //     10 4 is 0x1121
        //     11 5 is 0x1124

        // register 0x1b74 - Miscellaneous Detect Control
        //                   value 0x1 (Output HiZ, powered Down)
        // register 0x1120 - Headset Detect Control 2
        //                   changed from 0x0 (default) to 0x8 (manual disabled, hs bias closed, auto time 10 microsecs)
        // register 0x1b74 - Miscellaneous Detect Control
        //                   set to 0x7 (Output 2.7V, powered Down) - headset interface functional
        // register 0x1120 - Headset Detect Control 2
        //                   changed from 0x8  to 0x0 (default)

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7400 i2c data 0x7401
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x11 lo 0x2000 i2c data 0x2000
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x2008 i2c data 0x0008
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x7407 i2c data 0x0007
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x11 lo 0x2000 i2c data 0x2008
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x2000 i2c data 0x0000

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1b74, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1120, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1120, 0x0008, 1); // snd_hda

        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b74, 0x0007, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1120, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1120, 0x0000, 1); // snd_hda

}

static void cs42l83_enable_hs_auto_int_on(struct hda_codec *codec)
{

	mycodec_i2c_local_info(codec, "cs42l83_enable_hs_auto_int_on\n");

        // AppleHDATDM_CS42L83::enableHSDetAutoInt(bool)
        // this involves a read then write

        // register 0x131b - Codec Interrupt Mask
        //                   changed from 0x3 (default) to 0x1
        //                   this is enabling auto headset detection (well HSDET_AUTO_DONE)

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x1b00 i2c data 0x1b03
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x13 lo 0x1b01 i2c data 0x0001

        cs_8409_vendor_i2cRead(codec, 0x90, 0x131b, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x131b, 0x0001, 1); // snd_hda

}

static void cs42l83_unplug_interrupt_setup(struct hda_codec *codec)
{
        int retval;
        int newval;

	mycodec_i2c_local_info(codec, "cs42l83_unplug_interrupt_setup\n");

        // in AppleHDAMikeyInternalCS8409::completeJackDetectUR

        // interrupt clearing seems to be triggered by reading registers in this routine (hence the name)

        // register 0x1b7b - this is undocumented for 42l42 but labelled in fig 4-45 as Interrupt
        //                   Detect Interrupt 1 Status
        //                   value 0x00
        // register 0x1b79 - Detect Interrupt Mask 1
        //                   changed from 0xa0 to 0xc0
        //                   this masks TIP_SENSE_PLUG and unmasks TIP_SENSE_UNPLUG

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7b00 i2c data 0x7b00
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7900 i2c data 0x79a0
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x79c0 i2c data 0x00c0

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1b7b, 1); // snd_hda

        retval = cs_8409_vendor_i2cRead(codec, 0x90, 0x1b79, 1); // snd_hda

        newval = (retval & 0x9f) | 0x40;

        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b79, newval, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b79, 0x00c0, 1); // snd_hda

}

static void cs42l83_set_hpout_pulldown_off(struct hda_codec *codec)
{
        //int retval;

	mycodec_i2c_local_info(codec, "cs42l83_set_hpout_pulldown_off\n");

        // AppleHDATDM_CS42L83::setHPOutPulldown

        // register 0x1f06 - DAC Control 2
        //                   changed from 0x6 to 0x86 (no HPOUT_PULL_DOWN)

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1f lo 0x0600 i2c data 0x0606
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1f lo 0x0686 i2c data 0x0086

        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1f06, 1); // snd_hda
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1f06, 0x0086, 1); // snd_hda

        cs_8409_vendor_i2cWriteMask(codec, 0x90, 0x1f06, 0xf0, 0x80, 1); // snd_hda

}

static void cs42l83_headset_detect_on(struct hda_codec *codec)
{

	mycodec_i2c_local_info(codec, "cs42l83_headset_detect_on\n");

        // this is AppleHDAMikeyInternalCS8409::enableHSDetection
        // this calls readMikey/writeMikey with either 0x8 arg or 0x9 arg
        // I think 0x8 arg is one used in the log

        // readMikey analysis for AppleHDATDM_CS42L83::readMikey
        // if 1st arg is equal or above 0x70 we send eg 0x1b70 (0x1b for our case)
        // if 1st arg is below 0x70 we do special things
        //     subtract 7 from it compare in range 0 to 5
        //     (so 8 becomes 1, 9 becomes 2)
        //     0x111f is loaded by default
        //     1 is 0x1120

        // writeMikey analysis for AppleHDATDM_CS42L83::writeMikey
        // if 1st arg is equal or above 0x70 we send eg 0x1b70 (0x1b for our case)
        // if 1st arg is below 0x70 we do special things
        //     subtract 5 from it compare in range 0 to 7
        //     (so 8 becomes 3, 9 becomes 4)
        //     0x111f is loaded by default
        //     3 is 0x1120

        // register 0x111f - Headset Detect Control 1
        //                   changed from 0x77 (default) to 0x72
        // register 0x1120 - Headset Detect Control 2
        //                   changed from 0x00 (default) to 0xc2
        //                   0xc0 headset detection automatic, 0x2 HSDET_AUTO_TIME 50 microsecs

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x11 lo 0x1f00 i2c data 0x1f77
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x1f72 i2c data 0x0072
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x11 lo 0x2000 i2c data 0x2000
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x11 lo 0x2000 i2c data 0x2000
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x20c2 i2c data 0x00c2

        cs_8409_vendor_i2cRead(codec, 0x90, 0x111f, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x111f, 0x0072, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1120, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1120, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1120, 0x00c2, 1); // snd_hda

}

static void cs42l83_headset_detect_off(struct hda_codec *codec)
{
        int retval;
        int newval;

	mycodec_i2c_local_info(codec, "cs42l83_headset_detect_off\n");

        // AppleHDAMikeyInternalCS8409::enableHSDetection

        // register 0x111f - Headset Detect Control 1
        //                   changed from 0x72 to 0x72
        // register 0x1120 - Headset Detect Control 2
        //                   changed from 0xc2 (default) to 0x82
        //                   0x80 headset detection disabled, 0x2 HSDET_AUTO_TIME 50 microsecs

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x11 lo 0x1f00 i2c data 0x1f72
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x1f72 i2c data 0x0072
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x11 lo 0x2000 i2c data 0x20c2
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x2082 i2c data 0x0082

        cs_8409_vendor_i2cRead(codec, 0x90, 0x111f, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x111f, 0x0072, 1); // snd_hda

        retval = cs_8409_vendor_i2cRead(codec, 0x90, 0x1120, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1120, 0x0082, 1); // snd_hda

}

static void cs42l83_headset_detect_onoff(struct hda_codec *codec, int onstate)
{
        int retval;
        int newval;

	mycodec_i2c_local_info(codec, "cs42l83_headset_detect_onoff\n");

        // AppleHDAMikeyInternalCS8409::enableHSDetection

        // register 0x111f - Headset Detect Control 1
        //                   changed from 0x72 to 0x72
        // register 0x1120 - Headset Detect Control 2
        //                   changed from 0xc2 (default) to 0x82
        //                   0x80 headset detection disabled, 0x2 HSDET_AUTO_TIME 50 microsecs

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x11 lo 0x1f00 i2c data 0x1f72
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x1f72 i2c data 0x0072
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x11 lo 0x2000 i2c data 0x20c2
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x2082 i2c data 0x0082

        cs_8409_vendor_i2cRead(codec, 0x90, 0x111f, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x111f, 0x0072, 1); // snd_hda

        if (onstate)
        {
                retval = cs_8409_vendor_i2cRead(codec, 0x90, 0x1120, 1); // snd_hda

                if (0xc0 >= retval)
                {
                        newval = (retval & 0x3f) | 0x80;
                        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1120, 0x0082, 1); // snd_hda
                }
        }

        retval = cs_8409_vendor_i2cRead(codec, 0x90, 0x1120, 1); // snd_hda

        if (onstate)
                newval = (retval & 0x3c) | 0x80;
        else
                newval = retval | 0xc0;

        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1120, 0x0082, 1); // snd_hda
}

static void cs42l83_enable_hs_auto_int_off(struct hda_codec *codec)
{
        int retval;
        int newval;

	mycodec_i2c_local_info(codec, "cs42l83_enable_hs_auto_int_off\n");

        // from AppleHDAMikeyInternalCS8409::handleJackDisconnectUR

        // AppleHDATDM_CS42L83::enableHSDetAutoInt

        // register 0x131b - Codec Interrupt Mask
        //                   changed from 0x3 (default) to 0x3
        //                   this is disabling auto headset detection (well HSDET_AUTO_DONE)
 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x1b00 i2c data 0x1b03
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x13 lo 0x1b03 i2c data 0x0003

        retval = cs_8409_vendor_i2cRead(codec, 0x90, 0x131b, 1); // snd_hda

        newval = (retval & 0xfd) | 0x02;

        cs_8409_vendor_i2cWrite(codec, 0x90, 0x131b, 0x0003, 1); // snd_hda

}

static int cs42l83_headset_type(struct hda_codec *codec)
{
        int retval_type;

	mycodec_i2c_local_info(codec, "cs42l83_headset_type\n");

        // this is readMikey function 0xb
  
        // register 0x1124 - Headset Detect Status
        //                   value 0x06 - 0x4 undocumented, headset type 0x02 (3)

        // types are 0x00 (1), 0x01 (2), 0x02 (3) and 0x3 (4)
        // type 1 Pin 1 Left, Pin 2 Right, Pin 3 Gnd, Pin 4 Mic
        // type 2 Pin 1 Left, Pin 2 Right, Pin 3 Mic, Pin 4 Gnd
        // type 3 Pin 1 Left, Pin 2 Right, Pin 3 Gnd, Pin 4 Gnd
        // type 4 Optical!!

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x11 lo 0x2400 i2c data 0x2406

        retval_type = cs_8409_vendor_i2cRead(codec, 0x90, 0x1124, 1); // snd_hda

        return retval_type;
}

static void cs42l83_set_hpout_pulldown_on(struct hda_codec *codec)
{
        //int retval;

	mycodec_i2c_local_info(codec, "cs42l83_set_hpout_pulldown_on\n");

        // AppleHDATDM_CS42L83::setHPOutPulldown(bool)

        // register 0x1f06 - DAC Control 2
        //                   changed from 0x86 to 0x06 (HPOUT_PULL_DOWN on)

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1f lo 0x0600 i2c data 0x0686
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1f lo 0x0606 i2c data 0x0006

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1f06, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1f06, 0x0006, 1); // snd_hda

}


static void cs42l83_set_hpout_pulldown_onoff(struct hda_codec *codec, int onstate)
{
        //int retval;

	mycodec_i2c_local_info(codec, "cs42l83_set_hpout_pulldown_onoff\n");

        // AppleHDATDM_CS42L83::setHPOutPulldown(bool)

        // register 0x1f06 - DAC Control 2
        //                   changed from 0x86 to 0x06 (HPOUT_PULL_DOWN on)

        // register 0x1f06 - DAC Control 2
        //                   changed from 0x6 to 0x86 (no HPOUT_PULL_DOWN)

        if (onstate)
        {

//              snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1f lo 0x0600 i2c data 0x0686
//              snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1f lo 0x0606 i2c data 0x0006

                //cs_8409_vendor_i2cRead(codec, 0x90, 0x1f06, 1); // snd_hda
                //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1f06, 0x0006, 1); // snd_hda

                cs_8409_vendor_i2cWriteMask(codec, 0x90, 0x1f06, 0xf0, 0x00, 1); // snd_hda
        }
        else
        {
//              snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1f lo 0x0600 i2c data 0x0606
//              snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1f lo 0x0686 i2c data 0x0086

                //cs_8409_vendor_i2cRead(codec, 0x90, 0x1f06, 1); // snd_hda
                //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1f06, 0x0086, 1); // snd_hda

                cs_8409_vendor_i2cWriteMask(codec, 0x90, 0x1f06, 0xf0, 0x80, 1); // snd_hda
        }

}


static void cs42l83_set_hpout_clamp_enable(struct hda_codec *codec)
{
        //int retval;

	mycodec_i2c_local_info(codec, "cs42l83_set_hpout_clamp_enable\n");

        // AppleHDATDM_CS42L83::setHPOutClamp

        // register 0x1f06 - DAC Control 2
        //                   changed from 0x06 to 0x02 (default)

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1f lo 0x0600 i2c data 0x0606
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1f lo 0x0602 i2c data 0x0002

        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1f06, 1); // snd_hda
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1f06, 0x0002, 1); // snd_hda

        cs_8409_vendor_i2cWriteMask(codec, 0x90, 0x1f06, 0x04, 0x00, 1); // snd_hda
}

static void cs42l83_headset_mike_detect_off(struct hda_codec *codec)
{
        int retval;
        int newval;

	mycodec_i2c_local_info(codec, "cs42l83_headset_mike_detect_off\n");

        // in AppleHDAMikeyInternalCS8409::handleTypeDetectUR

        // register 0x1b74 - Miscellaneous Detect Control
        //                   changed from 0x7 to 0x7 (Output 2.7V, mic detect powered Down) - headset interface functional

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7400 i2c data 0x7407
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x7407 i2c data 0x0007

        retval = cs_8409_vendor_i2cRead(codec, 0x90, 0x1b74, 1); // snd_hda

        // this sets the detect mode to 0b00 (default, inactive)
        newval = (retval & 0xe7);

        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b74, 0x0007, 1); // snd_hda

}

static void cs42l83_power_hs_bias_off(struct hda_codec *codec)
{

	mycodec_i2c_local_info(codec, "cs42l83_power_hs_bias_off\n");

        // multiple calls to this
        // AppleHDAMikeyInternalCS8409::handleTypeDetectUR
        // AppleHDAMikeyInternalCS8409::completeJackDetectUR
        // AppleHDAMikeyInternalCS8409::handleJackDisconnectUR
        // AppleHDAMikeyInternalCS8409::setupButtonDetection

        //  AppleHDAMikeyInternalCS8409::powerHSBIAS(unsigned int)

        // register 0x1b74 - Miscellaneous Detect Control
        //                   value 0x7 (Output 2.7V, mic level detect powered Down) - headset interface functional
        // register 0x1120 - Headset Detect Control 2
        //                   changed from 0x82 (automatic disabled, auto time 50 microsecs) to 0x8a (automatic disabled, hs bias closed, auto time 50 microsecs)
        // register 0x1b74 - Miscellaneous Detect Control
        //                   set 0x3 (default) (Output weak ground, mic level detect powered Down)
        // register 0x1120 - Headset Detect Control 2
        //                   changed from 0x8a to 0x82 ((automatic disabled, auto time 50 microsecs)

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7400 i2c data 0x7407

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x11 lo 0x2000 i2c data 0x2082
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x208a i2c data 0x008a

//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x7403 i2c data 0x0003

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x11 lo 0x2000 i2c data 0x208a
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x2082 i2c data 0x0082

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1b74, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1120, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1120, 0x008a, 1); // snd_hda


        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b74, 0x0003, 1); // snd_hda

        //IOSleep(0x28);
        msleep(0x28);

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1120, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1120, 0x0082, 1); // snd_hda

        //IOSleep(0x14);
        msleep(0x14);
}


static void cs42l83_enable_hsbias_auto_clamp_on(struct hda_codec *codec)
{

        //int updval;
        //int retval;

	mycodec_i2c_local_info(codec, "cs42l83_enable_hsbias_auto_clamp_on\n");

	// in AppleHDAMikeyInternalCS4208::handleTypeDetectUR

        //  AppleHDAMikeyInternalCS8409::enableHSBIASautoclamp

        // register 0x1b70 - HSBIAS Sense and Hi-Z Autocontrol
        //                   changed from 0x03 to 0x03 (HS Sense Bias trip 52 microamps

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7000 i2c data 0x7003
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x7003 i2c data 0x0003

        // explicit coding
        cs_8409_vendor_i2cRead(codec, 0x90, 0x1b70, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b70, 0x0003, 1); // snd_hda

        // bit coding
        //updval = cs_8409_vendor_i2cRead(codec, 0x90, 0x1b70, 1); // snd_hda
        //updval &= 0x3f;
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b70, updval, 1); // snd_hda

}

static void cs42l83_enable_hsbias_auto_clamp_off(struct hda_codec *codec)
{

        int updval;
        int retval;

	mycodec_i2c_local_info(codec, "cs42l83_enable_hsbias_auto_clamp_off\n");

	// in AppleHDAMikeyInternalCS4208::handleTypeDetectUR

        // in AppleHDAMikeyInternalCS8409::setupButtonDetection

        //  AppleHDAMikeyInternalCS8409::enableHSBIASautoclamp

        // register 0x1b70 - HSBIAS Sense and Hi-Z Autocontrol
        //                   changed from 0x03 to 0x03 (HS Sense Bias trip 52 microamps
        //                   set to 0x46 (Tip Sense Enable (0x40) HS Sense Bias trip 93 microamps (0x03 -> 0x06) )

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7000 i2c data 0x7003
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x7003 i2c data 0x0003
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x7046 i2c data 0x0046

        // explicit coding
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1b70, 1); // snd_hda
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b70, 0x0003, 1); // snd_hda

        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b70, 0x0046, 1); // snd_hda

        // bit coding
        retval = cs_8409_vendor_i2cRead(codec, 0x90, 0x1b70, 1); // snd_hda
        updval = retval & 0x3f;
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b70, updval, 1); // snd_hda

        updval = (retval & 0xb8) | 0x46;
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b70, updval, 1); // snd_hda

}


static void cs42l83_enable_hsbias_auto_clamp_off0(struct hda_codec *codec)
{

        //int retval;

        mycodec_i2c_local_info(codec, "cs42l83_enable_hsbias_auto_clamp_off0\n");

        // in AppleHDAMikeyInternalCS4208::handleTypeDetectUR

        // in AppleHDAMikeyInternalCS8409::setupButtonDetection

        //  AppleHDAMikeyInternalCS8409::enableHSBIASautoclamp

        // register 0x1b70 - HSBIAS Sense and Hi-Z Autocontrol
        //                   changed from 0x03 to 0x03 (HS Sense Bias trip 52 microamps
        //                   set to 0x46 (Tip Sense Enable (0x40) HS Sense Bias trip 93 microamps (0x03 -> 0x06) )

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7000 i2c data 0x7003
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x7003 i2c data 0x0003
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x7046 i2c data 0x0046

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1b70, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b70, 0x0003, 1); // snd_hda

        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b70, 0x0046, 1); // snd_hda

}

static void cs42l83_setup_button_detect(struct hda_codec *codec)
{

	mycodec_i2c_local_info(codec, "cs42l83_setup_button_detect\n");

        // AppleHDAMikeyInternalCS8409::setupButtonDetection

        // register 0x1b7c - Detect Interrupt Status 1
        //                   value 0x00 
        // register 0x1b7a - Detect Interrupt Mask 2
        //                   value 0xff all masked
        // register 0x1b7a - Detect Interrupt Mask 2
        //                   set to 0xe7 (this appears to be a difference from the 42l42 doc
        //                                - for the 42l42 0xe7 0x10 and 0x08 are reserved bits - maybe mike button bits)
        // register 0x1b76 - Mic Detect Control 2
        //                   changed from 0x2f (default) to 0x3f (again undocumented bit)
        // register 0x1b74 - Miscellaneous Detect Control
        //                   changed from 0x3 (default) to 0x3 (0x02 hsbias ctl weak ground, 0x01 mic lvl detect powered down)
        // register 0x1b78 - Detect Status 2
        // register 0x1b74 - Miscellaneous Detect Control
        //                   changed from 0x3 (default) to 0x1b (0x18 normal mode, 0x2 weak ground, 0x01 mic lvl detect powered down)
        // register 0x1b74 - Miscellaneous Detect Control
        //                   changed from 0x1b to 0x9b (0x80 undocumented)

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7c00 i2c data 0x7c00
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7a00 i2c data 0x7aff
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x7ae7 i2c data 0x00e7
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7600 i2c data 0x762f
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x763f i2c data 0x003f
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7400 i2c data 0x7403
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x7403 i2c data 0x0003
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7800 i2c data 0x78d0
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7400 i2c data 0x7403
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x741b i2c data 0x001b
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7400 i2c data 0x741b
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x749b i2c data 0x009b

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1b7c, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1b7a, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b7a, 0x00e7, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1b76, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b76, 0x003f, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1b74, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b74, 0x0003, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1b78, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1b74, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b74, 0x001b, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1b74, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b74, 0x009b, 1); // snd_hda

}

static void cs42l83_power_hs_bias_button_on(struct hda_codec *codec)
{

	mycodec_i2c_local_info(codec, "cs42l83_power_hs_bias_button_on\n");

        // in AppleHDAMikeyInternalCS8409::setupButtonDetection

        // AppleHDAMikeyInternalCS8409::powerHSBIAS

        // register 0x1b74 - Miscellaneous Detect Control
        // in AppleHDAMikeyInternalCS8409::setupButtonDetection
        //                   value 0x9b (0x80 undocumented, 0x18 normal mode, 0x2 weak ground, 0x1 mic DC level detect powered down)
        // register 0x1120 - Headset Detect Control 2
        //                   changed from 0x82 (automatic disabled, auto time 50 microsecs) to 0x8a (automatic disabled, hs bias closed, auto time 50 microsecs)
        // register 0x1b74 - Miscellaneous Detect Control
        //                   set 0x9f (0x80 undocumented, 0x18 normal mode, 0x6 2.7V headset interface functional, 0x1 mic DC level detect powered down)
        // register 0x1120 - Headset Detect Control 2
        //                   changed from 0x8a to 0x82 ((automatic disabled, auto time 50 microsecs)

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7400 i2c data 0x749b
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x11 lo 0x2000 i2c data 0x2082
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x208a i2c data 0x008a
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x749f i2c data 0x009f
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x11 lo 0x2000 i2c data 0x208a
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x2082 i2c data 0x0082

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1b74, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1120, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1120, 0x008a, 1); // snd_hda

        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b74, 0x009f, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1120, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1120, 0x0082, 1); // snd_hda

}

static void cs42l83_enable_hsbias_auto_clamp_off1(struct hda_codec *codec)
{

        //int retval;

	mycodec_i2c_local_info(codec, "cs42l83_enable_hsbias_auto_clamp_off1\n");

        // in AppleHDAMikeyInternalCS8409::setupButtonDetection

        //  AppleHDAMikeyInternalCS8409::enableHSBIASautoclamp

        // register 0x1b70 - HSBIAS Sense and Hi-Z Autocontrol
        //                   changed from 0x46 to 0x06
        //                   then set to 0x46 (Tip Sense Enable (0x40) HS Sense Bias trip 93 microamps (0x06 -> 0x06) )

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7000 i2c data 0x7046
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x7006 i2c data 0x0006
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x7046 i2c data 0x0046

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1b70, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b70, 0x0006, 1); // snd_hda

        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b70, 0x0046, 1); // snd_hda

}

static int cs42l83_handle_button_detect(struct hda_codec *codec)
{
        int ret_ignore;
        int ret_mask;
        int ret_sense;
        int ret_state1 = 0;
        int ret_state2 = 0;
        int ret_detect1 = 0;
        int ret_detect2 = 0;

	mycodec_i2c_local_info(codec, "cs42l83_handle_button_detect\n");

        // AppleHDAMikeyInternalCS8409::handleButtonDetectUR

        // register 0x1b7a - Detect Interrupt Mask 2
        //                   value 0xe7 (0x18 unmasked - undocumented - maybe mike buttons - rest masked)
        // register 0x1b7c - this is undocumented for 42l42 (reserved)
        //                   Detect Interrupt 2 Status
        //                   value 0x00 (none ie inverse of 0xe7 state of 0x1b7a)
        // register 0x1b7a - Detect Interrupt Mask 2
        //                   changed from 0xe7 to 0xff
        // register 0x1b77 - Detect Status 1
        //                   value 0x92 0x80 HP plugged bias 0x12
        // register 0x1b78 - Detect Status 2
        //                   value 0x40 (undocumented - maybe this indicates we have buttons)
        // register 0x1b74 - Miscellaneous Detect Control
        //                   changed from 0x9f to 0x1f

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7a00 i2c data 0x7ae7
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7c00 i2c data 0x7c00
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7a00 i2c data 0x7ae7
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x7aff i2c data 0x00ff
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7700 i2c data 0x7792
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7800 i2c data 0x7840
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7800 i2c data 0x7840
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7400 i2c data 0x749f
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x741f i2c data 0x001f

        ret_mask = cs_8409_vendor_i2cRead(codec, 0x90, 0x1b7a, 1); // snd_hda

        //if ((ret_mask & 0xe7) != 0xe7)
        if ((~ret_mask & 0x18) != 0x18)
        {
                printk("snd_hda_intel: cs42l83_handle_button_detect invalid mask 0x%08x\n",ret_mask);
                return 0;
        }

        // dont get this - return is 0 - we have no interrupts signalled in the unmasked section??
        // the cs42l42 documentation mentions shadow registers which says reading this register
        // loads the shadow register contents to register 0x1b7c - but dont see such a 2nd read here??
        // maybe we are just clearing any bad initial state??
        ret_ignore = cs_8409_vendor_i2cRead(codec, 0x90, 0x1b7c, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1b7a, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b7a, 0x00ff, 1); // snd_hda

        // this is headphone sense - not clear what we do if dont sense headphones
        ret_sense = cs_8409_vendor_i2cRead(codec, 0x90, 0x1b77, 1); // snd_hda

        ret_state1 = cs_8409_vendor_i2cRead(codec, 0x90, 0x1b78, 1); // snd_hda
        ret_state2 = cs_8409_vendor_i2cRead(codec, 0x90, 0x1b78, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1b74, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b74, 0x001f, 1); // snd_hda

        // possible coding from assembler - do not rely on!!
        //ret_detect1 = (ret_state >> 2) & 0x7;
        //ret_detect2 = (ret_state + ret_state) & 0x6;
        //ret_state1 = (((ret_state1 >> 0x7) | ret_detect2) >> 4) & 0x7;

        // this seems to be returning 0x40 - which is undocumented
        // for the moment going to assume 0x40 means we have buttons
        return ((ret_sense & 0xff) << 16) | ((ret_state2 & 0xff) << 8) | (ret_state1 & 0xff);
}

static int cs42l83_mike_connected(struct hda_codec *codec)
{
	int ret_connect = 0;
	int retval = 0;

	mycodec_i2c_local_info(codec, "cs42l83_mike_connected\n");

        // from AppleHDAMikeyInternalCS8409::handleButtonDetectUR

        // from AppleHDAMikeyInternal::configureHeadset(unsigned char, unsigned char, unsigned char)

        // AppleHDAMikeyInternalCS8409::microphoneConnected(bool*)

        // register 0x1b74 - Miscellaneous Detect Control
        //                   changed from 0x1f to 0x1e
        // register 0x1b75 - Mic Detect Control 1
        //                   changed from 0xb5 to 0xb5 (0x80 LATCH_TO_VP set, HS_DETECT_LEVEL 0x35)
        // register 0x1b78 - Detect Status 2
        //                   value 0x42 (0x40 unknown 0x2 hsbias_in true)
        // register 0x1b74 - Miscellaneous Detect Control
        //                   set to 0x1f

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7400 i2c data 0x741f
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x741e i2c data 0x001e
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7500 i2c data 0x75b5
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x75b5 i2c data 0x00b5
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7800 i2c data 0x7842
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x741f i2c data 0x001f

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1b74, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b74, 0x001e, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1b75, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b75, 0x00b5, 1); // snd_hda

        // this is returning a different value - now get 0x42
        // assuming 0x40 indicates we have buttons
        // and 0x02 seems to be indication we have a mike (from code analysis)
        ret_connect = cs_8409_vendor_i2cRead(codec, 0x90, 0x1b78, 1); // snd_hda

        // this converts 0x2 to a bool response ie 0x0 or 0x1
        retval = ((ret_connect > 1) & 0x01);

        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b74, 0x001f, 1); // snd_hda

        return ret_connect;
}


static void cs42l83_configure_int_mclk(struct hda_codec *codec)
{

	mycodec_i2c_local_info(codec, "cs42l83_configure_int_mclk\n");

        // in AppleHDATDM_CS42L83::enable

        // AppleHDATDM_CS42L83::_configureIntMClk

        // configuring clocks in the CS42L83 is extremely complex
        // multiple divisors/multipliers
        // only some registers decoded here

        // register 0x1007 - Serial Port SRC Control
        //                   changed from 0x10 to 0x10 - bypass equalizer

        // register 0x1009 - MCLK Control
        // ....

        // register 0x1208 - ASP Frame Configuration
        //                   set to 0x00

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x10 lo 0x0700 i2c data 0x0710
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x10 lo 0x0710 i2c data 0x0010
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x10 lo 0x0902 i2c data 0x0002
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x12 lo 0x0c02 i2c data 0x0002
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x15 lo 0x02ff i2c data 0x00ff
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x15 lo 0x039c i2c data 0x009c
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x15 lo 0x0470 i2c data 0x0070
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x15 lo 0x052e i2c data 0x002e
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x15 lo 0x1b03 i2c data 0x0003
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x15 lo 0x0a5d i2c data 0x005d
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x15 lo 0x0810 i2c data 0x0010
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x15 lo 0x0101 i2c data 0x0001
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x12 lo 0x05ff i2c data 0x00ff
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x12 lo 0x0600 i2c data 0x0000
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x12 lo 0x0100 i2c data 0x0100
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x12 lo 0x0100 i2c data 0x0000
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x12 lo 0x0800 i2c data 0x0000

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1007, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1007, 0x0010, 1); // snd_hda

        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1009, 0x0002, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x120c, 0x0002, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1502, 0x00ff, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1503, 0x009c, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1504, 0x0070, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1505, 0x002e, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x151b, 0x0003, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x150a, 0x005d, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1508, 0x0010, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1501, 0x0001, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1205, 0x00ff, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1206, 0x0000, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1201, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1201, 0x0000, 1); // snd_hda

        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1208, 0x0000, 1); // snd_hda

}

static void cs42l83_headset_power_on_on_nouse(struct hda_codec *codec)
{
        // this function replaced by cs42l83_power_onoff

	mycodec_i2c_local_info(codec, "cs42l83_headset_power_on_on_nouse\n");

        // AppleHDATDM_CS42L83::powerOn


//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x12 lo 0x0700 i2c data 0x0720
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x12 lo 0x0720 i2c data 0x0020
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x15 lo 0x0101 i2c data 0x0001
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x0701 i2c data 0x0001

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1207, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1207, 0x0020, 1); // snd_hda

        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1501, 0x0001, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1107, 0x0001, 1); // snd_hda

}

static void cs42l83_power_onoff(struct hda_codec *codec, bool onflag)
{

	mycodec_i2c_local_info(codec, "cs42l83_power_onoff\n");

        // in AppleHDATDM_CS42L83::enable

        // AppleHDATDM_CS42L83::powerOn

        // bool arg switches order of 0x1107/0x1501 - on (0x1207) 0x1501/0x1107 - off 0x1107/0x1501

        if (onflag)
        {
                // register 0x1207 - ASP Clock Configuration 1
                //                   changed from 0x00 to 0x20 - ASP_LCPOL_OUT inverted
                // register 0x1501 - PLL Control 1
                //                   set to 0x01 - powered on
                // register 0x1107 - Oscillator Switch Control
                //                   set to 0x01 - SCLK is present and the internal MCLK is sourced from the SCLK pin

//              snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x12 lo 0x0700 i2c data 0x0700
//              snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x12 lo 0x0720 i2c data 0x0020
//              snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x15 lo 0x0101 i2c data 0x0001
//              snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x0701 i2c data 0x0001

                cs_8409_vendor_i2cRead(codec, 0x90, 0x1207, 1); // snd_hda
                cs_8409_vendor_i2cWrite(codec, 0x90, 0x1207, 0x0020, 1); // snd_hda

                cs_8409_vendor_i2cWrite(codec, 0x90, 0x1501, 0x0001, 1); // snd_hda
                cs_8409_vendor_i2cWrite(codec, 0x90, 0x1107, 0x0001, 1); // snd_hda
        }
        else
        {
                // register 0x1107 - Oscillator Switch Control
                //                   set to 0x00 (power down, in transition)
                // register 0x1501 - PLL Control 1
                //                   set to 0x00 (powered off)

//              snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x0700 i2c data 0x0000
//              snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x15 lo 0x0100 i2c data 0x0000

                cs_8409_vendor_i2cWrite(codec, 0x90, 0x1107, 0x0000, 1); // snd_hda
                cs_8409_vendor_i2cWrite(codec, 0x90, 0x1501, 0x0000, 1); // snd_hda
        }
}

static void cs42l83_configure_serial_port(struct hda_codec *codec)
{

	mycodec_i2c_local_info(codec, "cs42l83_configure_serial_port\n");

        // in AppleHDATDM_CS42L83::enable

        // AppleHDATDM_CS42L83::_configureSerialPort

        // register 0x2505 - Serial Port Transmit Isochronous Control
        //                   changed from 0x04 to 0x05 (NFS mode, 48k isochronous stream)
        // register 0x2502 - Serial Port Receive Isochronous Control
        //                   changed from 0x04 to 0x05 (NFS mode, 48k isochronous stream)
        // register 0x2503 - Serial Port Receive Sample Rate
        //                   changed from 0x8c to 0x8a (48 kHz to 44.1 kHz)
        // register 0x2506 - Serial Port Transmit Sample Rate
        //                   changed from 0xcc to 0xca (48 kHz to 44.1 kHz)
        // register 0x1208 - ASP Frame Configuration
        //                   changed from 0x00 to 0x02 (ASP_STP from high to low, ASP frame start 1.0 delay)

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x25 lo 0x0500 i2c data 0x0504
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x25 lo 0x0505 i2c data 0x0005
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x25 lo 0x0200 i2c data 0x0204
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x25 lo 0x0205 i2c data 0x0005
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x25 lo 0x0300 i2c data 0x038c
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x25 lo 0x038a i2c data 0x008a
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x25 lo 0x0600 i2c data 0x06cc
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x25 lo 0x06ca i2c data 0x00ca
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x12 lo 0x0800 i2c data 0x0800
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x12 lo 0x0802 i2c data 0x0002

        cs_8409_vendor_i2cRead(codec, 0x90, 0x2505, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x2505, 0x0005, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x2502, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x2502, 0x0005, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x2503, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x2503, 0x008a, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x2506, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x2506, 0x00ca, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1208, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1208, 0x0002, 1); // snd_hda

}

static void cs42l83_output_set_input_sample_rate(struct hda_codec *codec)
{
	// changed name from cs42l83_set_sample_rate
	// NOTA BENE - it says output sample rate because its the sample rate for digital data
	//             coming into the cs42l83 and being converted to analog output
	//             - so the register is labelled the Input sample rate!!
        int ret_fs_rate;

	mycodec_i2c_local_info(codec, "cs42l83_output_set_input_sample_rate\n");

        // in AppleHDATDM_CS42L83::enable

        // AppleHDATDM_CS42L83::_setSampleRate

        // register 0x2601 - SRC Input Sample Rate
        //                   changed from 0x40 to 0x4a (0x0a is 44.1 kHz)
        // register 0x2503 - Serial Port Receive Sample Rate
        //                   changed from 0x8a to 0x8a (0x0a is 44.1 kHz)
        // register 0x120a - Input ASRC Clock Select
        //                   changed from 0x00 to 0x00 (0x00 6 MHz)
        // register 0x1209 - FS Rate Enable
        //                   changed from 0x00 to 0x01 (0x01 Enable IASRC 96K and lower rates)

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x26 lo 0x0100 i2c data 0x0140
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x26 lo 0x014a i2c data 0x004a
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x25 lo 0x0300 i2c data 0x038a
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x25 lo 0x038a i2c data 0x008a
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x12 lo 0x0a00 i2c data 0x0a00
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x12 lo 0x0a00 i2c data 0x0000
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x12 lo 0x0900 i2c data 0x0900
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x12 lo 0x0901 i2c data 0x0001

        cs_8409_vendor_i2cRead(codec, 0x90, 0x2601, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x2601, 0x004a, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x2503, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x2503, 0x008a, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x120a, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x120a, 0x0000, 1); // snd_hda

	// correctly implement this to mask in the right bit as per docs
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1209, 1); // snd_hda
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1209, 0x0001, 1); // snd_hda
        ret_fs_rate = cs_8409_vendor_i2cRead(codec, 0x90, 0x1209, 1); // snd_hda
        ret_fs_rate |= 0x1;
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1209, ret_fs_rate, 1); // snd_hda

}

static void cs42l83_setup_audio_output(struct hda_codec *codec)
{

	mycodec_i2c_local_info(codec, "cs42l83_setup_audio_output\n");

        // in AppleHDATDM_CS42L83::enable

        // AppleHDATDM_CS42L83::_setupAudioOutput

        // register 0x1f06 - DAC Control 2
        //                   set to 0x2 (default) DAC HPF enable
        // register 0x2001 - HP Control
        //                   changed from 0x0d (default) to 0x0d
        // register 0x2a04 - ASP Receive DAI0 Channel 1 Bit Start LSB
        //                   set to 0x00
        // register 0x2a07 - ASP Receive DAI0 Channel 2 Bit Start LSB
        //                   set to 0x20 (is this 32 bits?? - maybe)
        // register 0x2301 - Mixer Channel A Input Volume
        //                   set to 0x00 (0 dB - positive values negative dB as usual 0x3f mute (default))
        // register 0x2303 - Mixer Channel B Input Volume
        //                   set to 0x00 (0 dB - positive values negative dB as usual 0x3f mute (default))
        // register 0x2a02 - ASP Receive DAI0 Channel 1 Phase and Resolution
        //                   set to 0x02 (24 bits per sample)
        //                   (0x00 8 bits, 0x01 16 bits, 0x03 32 bits (default))
        // register 0x2a05 - ASP Receive DAI0 Channel 2 Phase and Resolution
        //                   set to 0x02 (24 bits per sample)
        //                   (0x00 8 bits, 0x01 16 bits, 0x03 32 bits (default))
        // register 0x100b - Slow Start Enable
        //                   changed from 0x70 (default) to 0x00 (disabled)

//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1f lo 0x0602 i2c data 0x0002
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x20 lo 0x0100 i2c data 0x010d
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x20 lo 0x010d i2c data 0x000d
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x2a lo 0x0400 i2c data 0x0000
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x2a lo 0x0720 i2c data 0x0020
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x23 lo 0x0100 i2c data 0x0000
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x23 lo 0x0300 i2c data 0x0000
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x2a lo 0x0202 i2c data 0x0002
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x2a lo 0x0502 i2c data 0x0002
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x10 lo 0x0b00 i2c data 0x0b70
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x10 lo 0x0b00 i2c data 0x0000

        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1f06, 0x0002, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x2001, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x2001, 0x000d, 1); // snd_hda

        cs_8409_vendor_i2cWrite(codec, 0x90, 0x2a04, 0x0000, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x2a07, 0x0020, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x2301, 0x0000, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x2303, 0x0000, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x2a02, 0x0002, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x2a05, 0x0002, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x100b, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x100b, 0x0000, 1); // snd_hda

}


static void cs42l83_headset_rcv_enable_on(struct hda_codec *codec)
{
        int retval;

        // this function has been replaced by cs42l83_buffers_onoff

	mycodec_i2c_local_info(codec, "cs42l83_headset_rcv_enable_on\n");

        // AppleHDATDM_CS42L83::enable

//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x2a lo 0x010c i2c data 0x000c

        cs_8409_vendor_i2cWrite(codec, 0x90, 0x2a01, 0x000c, 1); // snd_hda

}

static void cs42l83_buffers_onoff(struct hda_codec *codec, bool onflag)
{

	mycodec_i2c_local_info(codec, "cs42l83_buffers_onoff\n");

        // in AppleHDATDM_CS42L83::enable

        // yet again this has a bool arg which is enable/disable

        if (onflag)
        {
                // register 0x2a01 - ASP Receive Enable
                //                   set to 0x0c (populate channel buffers for 1 and 2)

//              snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x2a lo 0x010c i2c data 0x000c

                cs_8409_vendor_i2cWrite(codec, 0x90, 0x2a01, 0x000c, 1); // snd_hda
        }
        else
        {
                // register 0x2a01 - ASP Receive Enable
                //                   set to 0x00 (channel buffers not populated)

//              snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x2a lo 0x0100 i2c data 0x0000

                cs_8409_vendor_i2cWrite(codec, 0x90, 0x2a01, 0x0000, 1); // snd_hda
        }
}

static void cs42l83_set_power_state_on_nouse(struct hda_codec *codec, int dummy)
{

	mycodec_i2c_local_info(codec, "cs42l83_set_power_state_on_nouse\n");

        // AppleHDATDM_CS42L83::setPowerState

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x11 lo 0x0100 i2c data 0x01fe
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x019e i2c data 0x009e
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0b00 i2c data 0x0b60
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0b00 i2c data 0x0b60
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0b00 i2c data 0x0b24
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x11 lo 0x0100 i2c data 0x019e
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x0196 i2c data 0x0096

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1101, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1101, 0x009e, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x130b, 1); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0x90, 0x130b, 1); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0x90, 0x130b, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1101, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1101, 0x0096, 1); // snd_hda

}


static void cs42l83_headset_enable_on(struct hda_codec *codec)
{

	mycodec_i2c_local_info(codec, "cs42l83_headset_enable_on\n");

	// looks as tho this is only enabling the headphone component
	// - doesnt seem to be needed for the headset mike to work
	// (unless it just happens the headphone component is always enabled so
	//  dont see it for the headset mike)

        // AppleHDATDM_CS42L83::setPowerState
        // AppleHDATDM_CS42L83::enableHeadphones

//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x10 lo 0x7e99 i2c data 0x0099
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x0830 i2c data 0x0030
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x21 lo 0x0200 i2c data 0x0000
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x10 lo 0x7e00 i2c data 0x0000
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x20 lo 0x0100 i2c data 0x010d
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x20 lo 0x0101 i2c data 0x0001

        cs_8409_vendor_i2cWrite(codec, 0x90, 0x107e, 0x0099, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b08, 0x0030, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x2102, 0x0000, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x107e, 0x0000, 1); // snd_hda

        //cs_8409_vendor_i2cRead(codec, 0x90, 0x2001, 1); // snd_hda
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x2001, 0x0001, 1); // snd_hda

        cs_8409_vendor_i2cWriteMask(codec, 0x90, 0x2001, 0x0c, 0x00, 1); // snd_hda

}


static void cs42l83_plugin_interrupt_setup(struct hda_codec *codec)
{
        int retval;
        int newval;

	mycodec_i2c_local_info(codec, "cs42l83_plugin_interrupt_setup\n");

        // in AppleHDAMikeyInternalCS8409::handleJackDisconnectUR

        // this enables the headphone plugin sense interrupt

        // register 0x1b7b - this is undocumented for 42l42 but labelled in fig 4-45 as Interrupt
        //                   now think this shows which interrupt of 0x1b79 was triggered
        //                   reading this clears any interrupt which will send a UR
        //                   value 0x00
        // register 0x1b79 - Detect Interrupt Mask 1
        //                   changed from 0xe0 (default) to 0xa0 - unmasks TIP_SENSE_PLUG
        //                   changed from 0xc0 (TIP_SENSE_UNPLUG unmasked) to 0xa0 (TIP_SENSE_UNPLUG masked TIP_SENSE_PLUG unmasked)

        // so reading 0x1b7b seems to lead to 2 UNSOL events
        // one with interrupt set followed by one with interrupt cleared

        mycodec_info(codec, "command cs42l83_plugin_interrupt_setup start\n");
 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7b00 i2c data 0x7b00
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7900 i2c data 0x79c0
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x79a0 i2c data 0x00a0

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1b7b, 1); // snd_hda

        retval = cs_8409_vendor_i2cRead(codec, 0x90, 0x1b79, 1); // snd_hda

        newval = (retval & 0x9f) | 0x20;

        myprintk_dbg("snd_hda_intel: cs42l83_plugin_interrupt_setup 0x%04x 0x%04x: 0x%04x (0x%04x 0x%04x 0x%04x)",0x90,0x1b79,newval,0x00a0,retval,0x00c0);

        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b79, 0x00a0, 1); // snd_hda

        mycodec_info(codec, "command cs42l83_plugin_interrupt_setup end\n");
}

static void cs42l83_headset_detect2_off(struct hda_codec *codec)
{
        int retval;
        int newval;

	mycodec_i2c_local_info(codec, "cs42l83_headset_detect2_off\n");

        // in AppleHDAMikeyInternalCS8409::handleJackDisconnectUR

        // register 0x1b7c - Detect Interrupt 2 Status
        //                   value 0x00 (none ie inverse of 0xff state of 0x1b7a)
        // register 0x1b7a - Detect Interrupt Mask 2
        //                   changed from 0xff to 0xff (all masked)
        // register 0x1b74 - Miscellaneous Detect Control
        //                   changed from 0x3 (default) to 0x3
 
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7c00 i2c data 0x7c00
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7a00 i2c data 0x7aff
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x7aff i2c data 0x00ff
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7400 i2c data 0x7403
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x7403 i2c data 0x0003

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1b7c, 1); // snd_hda

        retval = cs_8409_vendor_i2cRead(codec, 0x90, 0x1b7a, 1); // snd_hda

        newval = (retval | 0x38);

        myprintk_dbg("snd_hda_intel: cs42l83_headset_detect2_off 0x%04x 0x%04x: 0x%04x (0x%04x 0x%04x 0x%04x)",0x90,0x1b7a,newval,0x00ff,retval,0x00ff);

        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b7a, 0x00ff, 1); // snd_hda


        retval = cs_8409_vendor_i2cRead(codec, 0x90, 0x1b74, 1); // snd_hda

        newval = (retval & 0xe7);

        myprintk_dbg("snd_hda_intel: cs42l83_headset_detect2_off 0x%04x 0x%04x: 0x%04x (0x%04x 0x%04x 0x%04x)",0x90,0x1b7c,newval,0x00a0,retval,0x00c0);

        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b74, 0x0003, 1); // snd_hda

}

static void cs42l83_enable_hsbias_auto_clamp_off3(struct hda_codec *codec)
{

        //int retval;

	mycodec_i2c_local_info(codec, "cs42l83_enable_hsbias_auto_clamp_off3\n");

        // in AppleHDAMikeyInternalCS8409::handleJackDisconnectUR

        //  AppleHDAMikeyInternalCS8409::enableHSBIASautoclamp

        // register 0x1b70 - HSBIAS Sense and Hi-Z Autocontrol
        //                   changed from 0xc6 to 0x06 
        //                   then set to 0x46 (Tip Sense Enable (0x40) HS Sense Bias trip 93 microamps (0x06 ->0x06) )

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7000 i2c data 0x70c6
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x7006 i2c data 0x0006
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x7046 i2c data 0x0046

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1b70, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b70, 0x0006, 1); // snd_hda

        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b70, 0x0046, 1); // snd_hda

}

static void cs42l83_disable_button_interrupts(struct hda_codec *codec)
{

	mycodec_i2c_local_info(codec, "cs42l83_disable_button_interrupts\n");

        // AppleHDAMikeyInternalCS8409::setupButtonDetection

        // register 0x1b7c - Detect Interrupt Status 1
        //                   value 0x04
        // register 0x1b7a - Detect Interrupt Mask 2
        //                   value 0xfc 
        // register 0x1b7a - Detect Interrupt Mask 2
        //                   set to 0xff
        // register 0x1b7a - Detect Interrupt Mask 2
        //                   set to 0xff

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7c00 i2c data 0x7c04
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7a00 i2c data 0x7afc
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x7aff i2c data 0x00ff
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x7aff i2c data 0x00ff

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1b7c, 1); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0x90, 0x1b7a, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b7a, 0x00ff, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b7a, 0x00ff, 1); // snd_hda

}

static void cs42l83_unplug_headset_detect_off(struct hda_codec *codec)
{

	mycodec_i2c_local_info(codec, "cs42l83_unplug_headset_detect_off\n");

        // this is AppleHDAMikeyInternalCS8409::enableHSDetection
        // this calls readMikey/writeMikey with 0x8 arg and 0x9 arg

        // register 0x111f - Headset Detect Control 1
        //                   changed from 0x72 to 0x72
        // register 0x1120 - Headset Detect Control 2
        //                   changed from 0x82 to 0x82
        //                   0x80 headset detection automatic, disabled, 0x2 HSDET_AUTO_TIME 50 microsecs

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x11 lo 0x1f00 i2c data 0x1f72
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x1f72 i2c data 0x0072
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x11 lo 0x2000 i2c data 0x2082
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x2082 i2c data 0x0082

        cs_8409_vendor_i2cRead(codec, 0x90, 0x111f, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x111f, 0x0072, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1120, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1120, 0x0082, 1); // snd_hda

}
 
static void cs42l83_headset_switch_control(struct hda_codec *codec)
{

	mycodec_i2c_local_info(codec, "cs42l83_headset_switch_control\n");

        // from AppleHDAMikeyInternalCS8409::handleJackDisconnectUR

        // this is likely writeMikey 0x9, 0xa making it plausibly AppleHDAMikeyInternalCS8409::configureForUSHeadset

        // register 0x1120 - Headset Detect Control 2
        //                   changed from 0x82 to 0x42
        //                   0x40 headset detection manual, 0x2 HSDET_AUTO_TIME 50 microsecs

        // I think this is writeMikey with 0xa arg

        // register 0x1121 - Headset Switch Control
        //                   set to 0xa6

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x11 lo 0x2000 i2c data 0x2082
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x2042 i2c data 0x0042
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x21a6 i2c data 0x00a6

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1120, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1120, 0x0042, 1); // snd_hda

        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1121, 0x00a6, 1); // snd_hda

}
 

static void cs42l83_headset_enable_off(struct hda_codec *codec)
{

	mycodec_i2c_local_info(codec, "cs42l83_headset_enable_off\n");

        // in AppleHDATDM_CS42L83::enable - 0x22cb
        // from AppleHDATDM_CS42L83::_powerOffCodecOutput
        // AppleHDATDM_CS42L83::enableHeadphones(bool)

        // register 0x2001 - HP Control
        //                   changed from 0x01 to 0x0d
        //          0x107e - undocumented Global
        //                   set to 0x99
        //          0x1b08 - undocumented Headset Interface
        //                   set to 0x10
        //          0x2102 - Class H?? DPn Port Control??
        //                   set to 0x20
        //          0x107e - undocumented Global
        //                   set to 0x00

        myprintk("snd_hda_intel: cs42l83_headset_enable_off start\n");

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x20 lo 0x0100 i2c data 0x0101
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x20 lo 0x010d i2c data 0x000d
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x10 lo 0x7e99 i2c data 0x0099
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x0810 i2c data 0x0010
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x21 lo 0x0220 i2c data 0x0020
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x10 lo 0x7e00 i2c data 0x0000

        //cs_8409_vendor_i2cRead(codec, 0x90, 0x2001, 1); // snd_hda
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x2001, 0x000d, 1); // snd_hda

        cs_8409_vendor_i2cWriteMask(codec, 0x90, 0x2001, 0x0c, 0x0c, 1); // snd_hda

        cs_8409_vendor_i2cWrite(codec, 0x90, 0x107e, 0x0099, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b08, 0x0010, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x2102, 0x0020, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x107e, 0x0000, 1); // snd_hda

        myprintk("snd_hda_intel: cs42l83_headset_enable_off end\n");

}


static void cs42l83_power_off_codec_output(struct hda_codec *codec)
{

	mycodec_i2c_local_info(codec, "cs42l83_power_off_codec_output\n");

        // in AppleHDATDM_CS42L83::enable or AppleHDATDM_CS42L83::setPowerState
        // AppleHDATDM_CS42L83::_powerOffCodecOutput

        // register 0x1101 - Power Down Control 1
        //                   0xff powered down 0x00 powered up
        //                   changed from 0x96 to 0x9e (0x40 ASP Input, 0x20 Mixer, 0x08 HPOut, 0x1 codec powered to
        //                                              0x40 ASP Input, 0x20 Mixer, 0x1 codec powered)
        // register 0x1101 - Power Down Control 1       
        //                   changed from 0x9e (0x40 ASP Input, 0x20 Mixer, 0x1 codec powered) to 0xfe (default - 0x1 codec powered))

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x11 lo 0x0100 i2c data 0x0196
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x019e i2c data 0x009e
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x11 lo 0x0100 i2c data 0x019e
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x01fe i2c data 0x00fe

        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1101, 1); // snd_hda
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1101, 0x009e, 1); // snd_hda

        cs_8409_vendor_i2cWriteMask(codec, 0x90, 0x1101, 0x08, 0x08, 1); // snd_hda

        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1101, 1); // snd_hda
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1101, 0x00fe, 1); // snd_hda

        cs_8409_vendor_i2cWriteMask(codec, 0x90, 0x1101, 0x60, 0x60, 1); // snd_hda
}

static void cs42l83_power_off_codec_input(struct hda_codec *codec)
{

	mycodec_i2c_local_info(codec, "cs42l83_power_off_codec_input\n");

        // in AppleHDATDM_CS42L83::enable or AppleHDATDM_CS42L83::setPowerState
        // AppleHDATDM_CS42L83::_powerOffCodecInput

	// note there is a call to AppleHDATDM_CS42L83::enableExtMicrophone(0) in this routine
	// ah - thats the 0x1d03 mute/unmute volume register

        // register 0x1101 - Power Down Control 1
        //                   0xff powered down 0x00 powered up
        //                   changed from 0x12 to 0x16 (0x80 ASP Output, 0x40 ASP Input, 0x20 Mixer, 0x08 HPOut, 0x4 ADC, 0x1 codec powered to
        //                                              0x80 ASP Output, 0x40 ASP Input, 0x20 Mixer, 0x08 HPout, 0x1 codec powered)
        // register 0x1101 - Power Down Control 1
        //                   changed from 0x16 (0x80 ASP Output, 0x40 ASP Input, 0x20 Mixer, 0x08 HPOut, 0x1 codec powered) to
        //                                0x96 (0x40 ASP Input, 0x20 Mixer, 0x08 HPOut, 0x1 codec powered)

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x11 lo 0x0100 i2c data 0x0112
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x0116 i2c data 0x0016
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x11 lo 0x0100 i2c data 0x0116
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x0196 i2c data 0x0096

        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1101, 1); // snd_hda
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1101, 0x0016, 1); // snd_hda

        cs_8409_vendor_i2cWriteMask(codec, 0x90, 0x1101, 0x04, 0x04, 1); // snd_hda

        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1101, 1); // snd_hda
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1101, 0x0096, 1); // snd_hda

        cs_8409_vendor_i2cWriteMask(codec, 0x90, 0x1101, 0x80, 0x80, 1); // snd_hda
}

static void cs42l83_headset_rcv_enable_off(struct hda_codec *codec)
{
        // this function has been replaced by cs42l83_buffers_onoff

	mycodec_i2c_local_info(codec, "cs42l83_headset_rcv_enable_off\n");

        // in AppleHDATDM_CS42L83::enable
        // this is only place we have a 0x2a01

        // yet again this has a bool arg which is enable/disable

        // register 0x2a01 - ASP Receive Enable
        //                   set to 0x00 (channel buffers not populated)

//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x2a lo 0x0100 i2c data 0x0000

        cs_8409_vendor_i2cWrite(codec, 0x90, 0x2a01, 0x0000, 1); // snd_hda

}

static void cs42l83_headset_power_off(struct hda_codec *codec)
{
        // this function replaced by cs42l83_power_onoff

	mycodec_i2c_local_info(codec, "cs42l83_headset_power_off\n");

        // in AppleHDATDM_CS42L83::enable

        // AppleHDATDM_CS42L83::powerOn
        // likely power off - bool arg switches order of 0x1107/0x1501 - on (0x2a10) 0x1501/0x1107 - off 0x1107/0x1501

        // register 0x1107 - Oscillator Switch Control
        //                   set to 0x00 (power down, in transition)
        // register 0x1501 - PLL Control 1
        //                   set to 0x00 (powered off)


//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x0700 i2c data 0x0000
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x15 lo 0x0100 i2c data 0x0000

        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1107, 0x0000, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1501, 0x0000, 1); // snd_hda

}

//static void cs42l83_line_or_mike_set_sample_rate(struct hda_codec *codec)
static void cs42l83_input_set_output_sample_rate(struct hda_codec *codec)
{
	// changed name from cs42l83_line_or_mike_set_sample_rate
	// NOTA BENE - it says input sample rate because its the sample rate for data
	//             from analog inputs converted to digital and going out of the cs42l83
	//             - so the register is labelled the Output sample rate!!

        int ret_fs_rate;

	mycodec_i2c_local_info(codec, "cs42l83_input_set_output_sample_rate\n");

        // in AppleHDATDM_CS42L83::enable

        // AppleHDATDM_CS42L83::_setSampleRate

        // is this for line or mike??

        // register 0x2609 - SRC Output Sample Rate
        //                   changed from 0x40 to 0x4a (0x0a is 44.1 kHz)
        // register 0x2506 - Serial Port Transmit Sample Rate
        //                   changed from 0xca to 0xca (0x0a is 44.1 kHz)
        // register 0x120b - Output ASRC Clock Select
        //                   changed from 0x00 to 0x00 (0x00 6 MHz)
        // register 0x1209 - FS Rate Enable
        //                   changed from 0x00 to 0x03 (0x01 Enable IASRC 96K and lower rates, 0x02 Enable OASRC96K and lower rates)

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x26 lo 0x0900 i2c data 0x0940
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x26 lo 0x094a i2c data 0x004a
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x25 lo 0x0600 i2c data 0x06ca
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x25 lo 0x06ca i2c data 0x00ca
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x12 lo 0x0b00 i2c data 0x0b00
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x12 lo 0x0b00 i2c data 0x0000
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x12 lo 0x0900 i2c data 0x0901
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x12 lo 0x0903 i2c data 0x0003

        cs_8409_vendor_i2cRead(codec, 0x90, 0x2609, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x2609, 0x004a, 1); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0x90, 0x2506, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x2506, 0x00ca, 1); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0x90, 0x120b, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x120b, 0x0000, 1); // snd_hda

	// correctly implement this to mask in the right bit as per docs
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1209, 1); // snd_hda
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1209, 0x0003, 1); // snd_hda
        ret_fs_rate = cs_8409_vendor_i2cRead(codec, 0x90, 0x1209, 1); // snd_hda
        ret_fs_rate |= 0x2;
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1209, ret_fs_rate, 1); // snd_hda

}

static void cs42l83_mike_setup_audio_input(struct hda_codec *codec)
{

	mycodec_i2c_local_info(codec, "cs42l83_mike_setup_audio_input\n");

        // in AppleHDATDM_CS42L83::enable

        // AppleHDATDM_CS42L83::_setupAudioInput

        // register 0x2903 - ASP Transmit Channel Phase and Resolution
        // register 0x2905 - ASP Transmit Channel 1 Bit Start LSB
        // register 0x290b - ASP Transmit Channel 2 Bit Start LSB

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x29 lo 0x0300 i2c data 0x030f
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x29 lo 0x030a i2c data 0x000a
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x29 lo 0x0500 i2c data 0x0000
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x29 lo 0x0b20 i2c data 0x0020

        cs_8409_vendor_i2cRead(codec, 0x90, 0x2903, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x2903, 0x000a, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x2905, 0x0000, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x290b, 0x0020, 1); // snd_hda

}

static void cs42l83_mike_enable(struct hda_codec *codec)
{

	mycodec_i2c_local_info(codec, "cs42l83_mike_enable\n");

        // in AppleHDATDM_CS42L83::enable

        // register 0x2902 - ASP Transmit Channel Enable
        //                   set to 0x03 (ASP Transmit Channel 1 enable (0x01), ASP Transmit Channel 2 enable (0x02))
        // register 0x2901 - ASP Transmit Size and Enable
        //                   set to 0x01 (Enabled)

//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x29 lo 0x0203 i2c data 0x0003
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x29 lo 0x0101 i2c data 0x0001

        cs_8409_vendor_i2cWrite(codec, 0x90, 0x2902, 0x0003, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x2901, 0x0001, 1); // snd_hda

}


static void cs42l83_mike_disable(struct hda_codec *codec)
{

	mycodec_i2c_local_info(codec, "cs42l83_mike_disable\n");

        // in AppleHDATDM_CS42L83::enable

        // register 0x2901 - ASP Transmit Size and Enable
        //                   set to 0x00 (Disabled)
        // register 0x2902 - ASP Transmit Channel Enable
        //                   set to 0x00 (disabled)

//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x29 lo 0x0100 i2c data 0x0000
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x29 lo 0x0200 i2c data 0x0000

        cs_8409_vendor_i2cWrite(codec, 0x90, 0x2901, 0x0000, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x2902, 0x0000, 1); // snd_hda

}

//static void cs42l83_line_or_mike_set_sample_rate1(struct hda_codec *codec)
static void cs42l83_input_set_output_sample_rate1(struct hda_codec *codec)
{
	// changed name from cs42l83_line_or_mike_set_sample_rate1
	// NOTA BENE - it says input sample rate because its the sample rate for data
	//             from analog inputs converted to digital and going out of the cs42l83
	//             - so the register is labelled the Output sample rate!!
	// NOTA BENE - NOT fixed to do bit op for 0x1209 register!!!

	mycodec_i2c_local_info(codec, "cs42l83_input_set_output_sample_rate1\n");

        // in AppleHDATDM_CS42L83::enable

        // AppleHDATDM_CS42L83::_setSampleRate

        // is this for line or mike??

        // register 0x2609 - SRC Output Sample Rate
        //                   changed from 0x4a to 0x4a (0x0a is 44.1 kHz)
        // register 0x2506 - Serial Port Transmit Sample Rate
        //                   changed from 0xca to 0xca (0x0a is 44.1 kHz)
        // register 0x120b - Output ASRC Clock Select
        //                   changed from 0x00 to 0x00 (0x00 6 MHz)
        // register 0x1209 - FS Rate Enable
        //                   changed from 0x00 to 0x01 (0x01 Enable IASRC 96K and lower rates)

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x26 lo 0x0900 i2c data 0x094a
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x26 lo 0x094a i2c data 0x004a
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x25 lo 0x0600 i2c data 0x06ca
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x25 lo 0x06ca i2c data 0x00ca
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x12 lo 0x0b00 i2c data 0x0b00
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x12 lo 0x0b00 i2c data 0x0000
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x12 lo 0x0900 i2c data 0x0903
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x12 lo 0x0903 i2c data 0x0003

        cs_8409_vendor_i2cRead(codec, 0x90, 0x2609, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x2609, 0x004a, 1); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0x90, 0x2506, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x2506, 0x00ca, 1); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0x90, 0x120b, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x120b, 0x0000, 1); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0x90, 0x1209, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1209, 0x0003, 1); // snd_hda

}

static void cs42l83_line_or_mike_setup_audio_input(struct hda_codec *codec)
{

	mycodec_i2c_local_info(codec, "cs42l83_line_or_mike_setup_audio_input\n");

        // in AppleHDATDM_CS42L83::enable

        // AppleHDATDM_CS42L83::_setupAudioInput

        // register 0x2903 - ASP Transmit Channel Phase and Resolution
        // register 0x2905 - ASP Transmit Channel 1 Bit Start LSB
        // register 0x290b - ASP Transmit Channel 2 Bit Start LSB

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x29 lo 0x0300 i2c data 0x030a
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x29 lo 0x030a i2c data 0x000a
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x29 lo 0x0500 i2c data 0x0000
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x29 lo 0x0b20 i2c data 0x0020

        cs_8409_vendor_i2cRead(codec, 0x90, 0x2903, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x2903, 0x000a, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x2905, 0x0000, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x290b, 0x0020, 1); // snd_hda

}

static void cs42l83_line_or_mike_enable_nouse(struct hda_codec *codec)
{

	mycodec_i2c_local_info(codec, "cs42l83_line_or_mike_enable_nouse\n");

        // in AppleHDATDM_CS42L83::enable

        // register 0x2902 - ASP Transmit Channel Enable
        //                   set to 0x03 (ASP Transmit Channel 1 enable (0x01), ASP Transmit Channel 2 enable (0x02))
        // register 0x2901 - ASP Transmit Size and Enable
        //                   set to 0x01 (Enabled)

//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x29 lo 0x0203 i2c data 0x0003
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x29 lo 0x0101 i2c data 0x0001

        cs_8409_vendor_i2cWrite(codec, 0x90, 0x2902, 0x0003, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x2901, 0x0001, 1); // snd_hda

}

static void cs42l83_headset_mike_pin_enable(struct hda_codec *codec)
{
        int retval = 0;

	mycodec_i2c_local_info(codec, "cs42l83_headset_mike_pin_enable\n");

        // why twice??

        retval = snd_hda_codec_read_check(codec, 0x3c, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000020, 14146); // 0x03cf0700

        retval = snd_hda_codec_read_check(codec, 0x3c, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000020, 14147); // 0x03cf0700

        snd_hda_codec_write(codec, 0x3c, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000020); // 0x03c70720
//      snd_hda:     60 ['AC_PINCTL_IN_EN']

        snd_hda_codec_write(codec, 0x3c, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000020); // 0x03c70720
//      snd_hda:     60 ['AC_PINCTL_IN_EN']

}

static void cs42l83_configure_headset_button_interrupts(struct hda_codec *codec)
{
        //int retval;

	mycodec_i2c_local_info(codec, "cs42l83_configure_headset_button_interrupts\n");

        // from AppleHDAMikeyInternalCS8409::handleButtonDetectUR(unsigned int)

        // AppleHDAMikeyInternalCS8409::configureHeadset
        // - this calls 0x1b7c and 0x1b7a

        // register 0x1b7c - Detect Interrupt Status 1
        //                   value 0x00 
        // register 0x1b7a - Detect Interrupt Mask 2
        //                   changed from 0xff to 0xdc (0x23 unmasked, 0x18 masked - undocumented - maybe mike buttons - rest unmasked)

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7c00 i2c data 0x7c40
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7a00 i2c data 0x7aff
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x7adc i2c data 0x00dc

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1b7c, 1); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0x90, 0x1b7a, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b7a, 0x00dc, 1); // snd_hda

}

static void cs42l83_enable_hsbias_auto_clamp_off2(struct hda_codec *codec)
{

        //int retval;

	mycodec_i2c_local_info(codec, "cs42l83_enable_hsbias_auto_clamp_off2\n");

        // in AppleHDAMikeyInternalCS8409::setupButtonDetection

        //  AppleHDAMikeyInternalCS8409::enableHSBIASautoclamp

        // register 0x1b70 - HSBIAS Sense and Hi-Z Autocontrol
        //                   changed from 0x46 to 0x06
        //                   then set to 0x46 (Tip Sense Enable (0x40) HS Sense Bias trip 93 microamps (0x06 ->0x06) )

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7000 i2c data 0x7046
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x7006 i2c data 0x0006
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x7046 i2c data 0x0046

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1b70, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b70, 0x0006, 1); // snd_hda

        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b70, 0x0046, 1); // snd_hda

}

static void cs42l83_hsbias_sense_on(struct hda_codec *codec)
{

        int updval;
        //int retval;

        mycodec_i2c_local_info(codec, "cs42l83_hsbias_sense_on\n");

        // in AppleHDAMikeyInternalCS8409::handleButtonDetectUR

        // register 0x1b70 - HSBIAS Sense and Hi-Z Autocontrol
        //                   changed from 0x46 to 0xc6
        //                   set to 0xc6 (HS Bias Sense Enable (0x80) Tip Sense Enable (0x40) HS Sense Bias trip 93 microamps (0x06 ->0x06) )

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7000 i2c data 0x7046
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x1b lo 0x70c6 i2c data 0x00c6

        // explicit coding
        //cs_8409_vendor_i2cRead(codec, 0x90, 0x1b70, 1); // snd_hda
        //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b70, 0x00c6, 1); // snd_hda

        // bit coding
        updval = cs_8409_vendor_i2cRead(codec, 0x90, 0x1b70, 1); // snd_hda
        updval |= 0x80;
        cs_8409_vendor_i2cWrite(codec, 0x90, 0x1b70, updval, 1); // snd_hda

}


static void cs42l83_headset_mike_adc_unmutevol(struct hda_codec *codec, int unmute)
{

	mycodec_i2c_local_info(codec, "cs42l83_headset_mike_adc_unmutevol\n");

	// in AppleHDATDM_CS42L83::enableExtMicrophone

	if (unmute)
		cs_8409_vendor_i2cWrite(codec, 0x90, 0x1d03, 0x0000, 1); // snd_hda
	else
		cs_8409_vendor_i2cWrite(codec, 0x90, 0x1d03, 0x0080, 1); // snd_hda
}

