
static int tdm_in_use(struct hda_codec *codec, int where_flag)
{
        int coef_ret = 0;
        int coef_idx = 0;

        // re-implementation of AppleHDATDMBusManagerCS8409::tdmInUse
        mycodec_info(codec, "command tdmInUse start %d\n", where_flag);

        // note on OSX the coef get functions returns a status value with read value stored in passed address
        // on linux it seems -1 is an error return

        coef_ret = cs_8409_vendor_coef_get(codec, 0x19);

        //if (coef_ret == -1) error;

        coef_idx = 0x1a;

        do {

                if ((short)coef_ret >= 0) {
                        mycodec_info(codec, "command tdmInUse 1 end %d\n", where_flag);
                        return 1;
                }

                coef_ret = cs_8409_vendor_coef_get(codec, coef_idx);

                //if (coef_ret == -1) error;

                coef_idx++;

        } while (coef_idx <= 0x57);

        mycodec_info(codec, "command tdmInUse 0 end %d\n", where_flag);

        return 0;

}


static int cs42l83_headphone_sense(struct hda_codec *codec)
{
        int retval = 0;

        // AppleHDATDM_Codec::getHeadphonePinSense(bool*, unsigned int*)

        // register 0x1b77 - Detect Status 1
        //                   value 0x96 0x80 HP plugged bias 0x16

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7700 i2c data 0x7796

        retval = cs_8409_vendor_i2cRead(codec, 0x90, 0x1b77, 1); // snd_hda

        mycodec_info(codec, "cs42l83_headphone_sense - 0x%04x\n", retval);

        return retval;
}

static int read_gpio_status_check(struct hda_codec *codec)
{
        int retval;

        // should these be done powered down??
        // lets check power state here

        retval = snd_hda_codec_read(codec, codec->core.afg, 0, AC_VERB_GET_GPIO_DATA, 0x00000000); // 0x001f1500

        mycodec_info(codec, "command read_gpio_status_check %x\n", retval);

        return retval;
}


static void cs_8409_intmike_format_setup_format33_nouse(struct hda_codec *codec)
{
        int retval;
        int ret_coef9 = 0;
        int new_coef9 = 0;

        struct cs_spec *spec = codec->spec;

        // 0x44 -> 0x22 is internal (I think) mike input (macbook pro)

        snd_hda_codec_write(codec, spec->intmike_adc_nid, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004033); // 0x02224033
        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004033); // 0x02224033
//      snd_hda:     stream format 34 [('CHAN', 4), ('RATE', 44100), ('BITS', 24), ('RATE_MUL', 1), ('RATE_DIV', 1)]

}

static void cs_8409_intmike_format_setup_format_nouse(struct hda_codec *codec)
{
        int retval;

        struct cs_spec *spec = codec->spec;

        snd_hda_codec_write(codec, spec->intmike_adc_nid, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004031); // 0x02224031
        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004031); // 0x02224031
//      snd_hda:     stream format 34 [('CHAN', 2), ('RATE', 44100), ('BITS', 24), ('RATE_MUL', 1), ('RATE_DIV', 1)]

}

static void cs_8409_intmike_format_setup_enable(struct hda_codec *codec, int hda_format, int powered_down)
{
        int retval;
        int ret_coef9 = 0;
        int new_coef9 = 0;

        struct cs_spec *spec = codec->spec;

        // 0x44 -> 0x22 is internal (I think) mike input (macbook pro)

        // now updated to not write the Apple format but use my format setting routines
        // (remember we have limited the allowed formats to acceptable ones)
        // note that apparently we can set the format with the nid powered down but for setting the
        // stream id the nid has to be powered up
        // this seems to be used a lot in plugin/unplug headset in a powered down state
        // - but when capturing no power changes done

        // for some very strange reason we setup a 4 channel format after unplug of headset with mike
        // - otherwise its 2 channel - pass the format to allow for this
        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004033); // 0x02224033
//      snd_hda:     stream format 34 [('CHAN', 4), ('RATE', 44100), ('BITS', 24), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_STREAM_FORMAT, hda_format); // 0x02224033

        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 10515); // 0x022f0500
        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x02270500
        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000030, 10518); // 0x022f0500
        //if (powered_down) hda_set_node_power_state(codec, 0x22, AC_PWRST_D0);
        if (powered_down) hda_set_node_power_state(codec, spec->intmike_adc_nid, AC_PWRST_D0);

        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000010); // 0x02270610
//      snd_hda:     conv stream channel map 34 [('CHAN', 0), ('STREAMID', 1)]


        // using the stored stream parameters update nid 0x22 stream parameters
        // we have limited the allowed formats so should only have working formats here
        //cs_8409_really_update_stream_format(codec, 0x22, 1, 1, 0);
        cs_8409_really_update_stream_format(codec, spec->intmike_adc_nid, 1, 1, 0);


        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x02270503
        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 10521); // 0x022f0500
        //if (powered_down) hda_set_node_power_state(codec, 0x22, AC_PWRST_D3);
        if (powered_down) hda_set_node_power_state(codec, spec->intmike_adc_nid, AC_PWRST_D3);

//      snd_hda: # AppleHDAWidgetCS8409::setConnectionSelect: 
        ret_coef9 = snd_hda_coef_item_check(codec, 0, CS8409_VENDOR_NID, 0x0009, 0x0000, 0x000000b3, 0 ); // AppleHDAWidgetCS8409::setConnectionSelect  coef read 10523
        //new_coef9 = (ret_coef9 | 0x20); // note most of the time it just seems to copy the value because bit 0x20 already set on input
        //                                // only on boot does this get set
        new_coef9 = (ret_coef9 | spec->reg9_intmike_dmic_mo); // note most of the time it just seems to copy the value because bit 0x20 already set on input
                                                              // only on boot does this get set
        myprintk_dbg("snd_hda_intel: masked cs_8409_intmike_format_setup_enable coef 0x09 update 0x%04x 0x%04x \n", ret_coef9, new_coef9);
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0009, 0x00b3, 0x00000000, 10527 ); // AppleHDAWidgetCS8409::setConnectionSelect  coef write 10527
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0009, new_coef9, 0x00000000, 0 ); // AppleHDAWidgetCS8409::setConnectionSelect  coef write 10527

        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_CONNECT_SEL, 0x00000000); // 0x02270100
        snd_hda_codec_write(codec, spec->intmike_adc_nid, 0, AC_VERB_SET_CONNECT_SEL, 0x00000000); // 0x02270100

}


static void cs_8409_volume_set(struct hda_codec *codec, hda_nid_t nid, int volume)
{
        int retgain;
        int newgain;

        retgain = snd_hda_codec_read(codec, nid, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000); // 0x022b2000

        newgain = (retgain & 0x80) | (volume & 0x7f) | 0x6000;

        snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_AMP_GAIN_MUTE, newgain); // 0x02236027

        retgain = snd_hda_codec_read(codec, nid, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000); // 0x022b0000

        newgain = (retgain & 0x80) | (volume & 0x7f) | 0x5000;

        snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_AMP_GAIN_MUTE, newgain); // 0x02235027

}

static void cs_8409_volume_mute(struct hda_codec *codec, hda_nid_t nid)
{
        int retgain;
        int newgain;

        retgain = snd_hda_codec_read(codec, nid, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000); // 0x022b2000

        newgain = (retgain & 0x7f) | 0x80 | 0x6000;

        snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_AMP_GAIN_MUTE, newgain); // 0x02236000

        retgain = snd_hda_codec_read(codec, nid, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000); // 0x022b0000

        newgain = (retgain & 0x7f) | 0x80 | 0x5000;

        snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_AMP_GAIN_MUTE, newgain); // 0x02235027

}

static void cs_8409_volume_unmute(struct hda_codec *codec, hda_nid_t nid)
{
        int retgain;
        int newgain;

        retgain = snd_hda_codec_read(codec, nid, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000); // 0x022b2000

        newgain = (retgain & 0x7f) | 0x6000;

        snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_AMP_GAIN_MUTE, newgain); // 0x02236000

        retgain = snd_hda_codec_read(codec, nid, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000); // 0x022b0000

        newgain = (retgain & 0x7f) | 0x5000;

        snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_AMP_GAIN_MUTE, newgain); // 0x02235027

}

static void cs_8409_intmike_volume_set(struct hda_codec *codec, int volume)
{
        struct cs_spec *spec = codec->spec;
        cs_8409_volume_set(codec, spec->intmike_adc_nid, volume);
}

static void cs_8409_linein_volume_set(struct hda_codec *codec, int volume)
{
        struct cs_spec *spec = codec->spec;
        cs_8409_volume_set(codec, spec->linein_amp_nid, volume);
}

static void cs_8409_intmike_volume_unmute(struct hda_codec *codec)
{
        struct cs_spec *spec = codec->spec;
        cs_8409_volume_unmute(codec, spec->intmike_adc_nid);
}

static void cs_8409_linein_volume_unmute(struct hda_codec *codec)
{
        struct cs_spec *spec = codec->spec;
        cs_8409_volume_unmute(codec, spec->linein_amp_nid);
}

static void cs_8409_intmike_volume_mute(struct hda_codec *codec)
{
        struct cs_spec *spec = codec->spec;
        cs_8409_volume_mute(codec, spec->intmike_adc_nid);
}

static void cs_8409_linein_volume_mute(struct hda_codec *codec)
{
        struct cs_spec *spec = codec->spec;
        cs_8409_volume_mute(codec, spec->linein_amp_nid);
}

static void cs_8409_intmike_volume_setup_new(struct hda_codec *codec, int volume)
{
        struct cs_spec *spec = codec->spec;

        cs_8409_volume_set(codec, spec->intmike_adc_nid, volume);

        cs_8409_volume_mute(codec, spec->intmike_adc_nid);

        cs_8409_volume_set(codec, spec->intmike_nid, 0x00);

}

static void cs_8409_linein_volume_setup_new(struct hda_codec *codec, int volume)
{
        struct cs_spec *spec = codec->spec;

        cs_8409_volume_set(codec, spec->linein_amp_nid, volume);

        cs_8409_volume_mute(codec, spec->linein_amp_nid);

        cs_8409_volume_set(codec, spec->linein_nid, 0x00);

}


static void cs_8409_intmike_volume_setup(struct hda_codec *codec, int volume)
{
        int retgain;
        int newgain;

        struct cs_spec *spec = codec->spec;

        // plausibly AppleHDAWidget::setWidgetAmplifierGain

        //retgain = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x00000033, 0); // 0x022b2000
        retgain = snd_hda_codec_read_check(codec, spec->intmike_adc_nid, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x00000033, 0); // 0x022b2000
//      snd_hda:     amp gain/mute 34 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 34 0x0033 mute 0 gain 0x33 51

        newgain = (retgain & 0x80) | (volume & 0x7f) | 0x6000;

        snd_hda_codec_write(codec, spec->intmike_adc_nid, 0, AC_VERB_SET_AMP_GAIN_MUTE, newgain); // 0x02236027

        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00006027); // 0x02236027
//      snd_hda:     amp gain/mute 34 0x6027 mute 0 gain 0x27 39 index 0x00 left 1 right 0 output 0 input 1 left   input

        //retgain = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x00000033, 0); // 0x022b0000
        retgain = snd_hda_codec_read_check(codec, spec->intmike_adc_nid, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x00000033, 0); // 0x022b0000
//      snd_hda:     amp gain/mute 34 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 34 0x0033 mute 0 gain 0x33 51

        newgain = (retgain & 0x80) | (volume & 0x7f) | 0x5000;

        snd_hda_codec_write(codec, spec->intmike_adc_nid, 0, AC_VERB_SET_AMP_GAIN_MUTE, newgain); // 0x02235027

        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00005027); // 0x02235027
//      snd_hda:     amp gain/mute 34 0x5027 mute 0 gain 0x27 39 index 0x00 left 0 right 1 output 0 input 1  right  input


        // mute
        // plausibly AppleHDAWidget::setWidgetAmplifierMute

        //retgain = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x00000027, 0); // 0x022b2000
        retgain = snd_hda_codec_read_check(codec, spec->intmike_adc_nid, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x00000027, 0); // 0x022b2000
//      snd_hda:     amp gain/mute 34 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 34 0x0027 mute 0 gain 0x27 39

        newgain = (retgain & 0x7f) | 0x80 | 0x6000;

        snd_hda_codec_write(codec, spec->intmike_adc_nid, 0, AC_VERB_SET_AMP_GAIN_MUTE, newgain); // 0x022360a7

        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x000060a7); // 0x022360a7
//      snd_hda:     amp gain/mute 34 0x60a7 mute 1 gain 0x27 39 index 0x00 left 1 right 0 output 0 input 1 left   input

        //retgain = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x00000027, 0); // 0x022b0000
        retgain = snd_hda_codec_read_check(codec, spec->intmike_adc_nid, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x00000027, 0); // 0x022b0000
//      snd_hda:     amp gain/mute 34 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 34 0x0027 mute 0 gain 0x27 39

        newgain = (retgain & 0x7f) | 0x80 | 0x5000;

        snd_hda_codec_write(codec, spec->intmike_adc_nid, 0, AC_VERB_SET_AMP_GAIN_MUTE, newgain); // 0x022350a7

        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x000050a7); // 0x022350a7
//      snd_hda:     amp gain/mute 34 0x50a7 mute 1 gain 0x27 39 index 0x00 left 0 right 1 output 0 input 1  right  input


        // this is working on node 0x44 macbook pro
        // plausibly AppleHDAWidget::setWidgetAmplifierGain

        //retgain = snd_hda_codec_read_check(codec, 0x44, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x00000000, 0); // 0x044b2000
        retgain = snd_hda_codec_read_check(codec, spec->intmike_nid, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x00000000, 0); // 0x044b2000
//      snd_hda:     amp gain/mute 68 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 68 0x0000 mute 0 gain 0x0 0

        newgain = (retgain & 0x80) | (volume & 0x7f) | 0x6000;

        snd_hda_codec_write(codec, spec->intmike_nid, 0, AC_VERB_SET_AMP_GAIN_MUTE, newgain); // 0x04436000

        //snd_hda_codec_write(codec, 0x44, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00006000); // 0x04436000
//      snd_hda:     amp gain/mute 68 0x6000 mute 0 gain 0x0 0 index 0x00 left 1 right 0 output 0 input 1 left   input

        //retgain = snd_hda_codec_read_check(codec, 0x44, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x00000000, 0); // 0x044b0000
        retgain = snd_hda_codec_read_check(codec, spec->intmike_nid, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x00000000, 0); // 0x044b0000
//      snd_hda:     amp gain/mute 68 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 68 0x0000 mute 0 gain 0x0 0

        newgain = (retgain & 0x80) | (volume & 0x7f) | 0x5000;

        snd_hda_codec_write(codec, spec->intmike_nid, 0, AC_VERB_SET_AMP_GAIN_MUTE, newgain); // 0x04435000

        //snd_hda_codec_write(codec, 0x44, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00005000); // 0x04435000
//      snd_hda:     amp gain/mute 68 0x5000 mute 0 gain 0x0 0 index 0x00 left 0 right 1 output 0 input 1  right  input

}

static void cs_8409_linein_volume_setup(struct hda_codec *codec, int volume)
{
        int retgain;
        int newgain;

        struct cs_spec *spec = codec->spec;

        // so as far as I can see the 1st section sets the gain and the second section sets the mute
        // it appears we do masked updates 

        //volume = 0x27;

        // plausibly AppleHDAWidget::setWidgetAmplifierGain

        //retgain = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x000000b3, 0); // 0x023b2000
        retgain = snd_hda_codec_read_check(codec, spec->linein_amp_nid, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x000000b3, 0); // 0x023b2000
//      snd_hda:     amp gain/mute 35 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 35 0x00b3 mute 1 gain 0x33 51

        newgain = (retgain & 0x80) | (volume & 0x7f) | 0x6000;

        snd_hda_codec_write(codec, spec->linein_amp_nid, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x000060a7); // 0x023360a7

        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x000060a7); // 0x023360a7
//      snd_hda:     amp gain/mute 35 0x60a7 mute 1 gain 0x27 39 index 0x00 left 1 right 0 output 0 input 1 left   input

        //retgain = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x000000b3, 0); // 0x023b0000
        retgain = snd_hda_codec_read_check(codec, spec->linein_amp_nid, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x000000b3, 0); // 0x023b0000
//      snd_hda:     amp gain/mute 35 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 35 0x00b3 mute 1 gain 0x33 51

        newgain = (retgain & 0x80) | (volume & 0x7f) | 0x5000;

        snd_hda_codec_write(codec, spec->linein_amp_nid, 0, AC_VERB_SET_AMP_GAIN_MUTE, newgain); // 0x023350a7

        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x000050a7); // 0x023350a7
//      snd_hda:     amp gain/mute 35 0x50a7 mute 1 gain 0x27 39 index 0x00 left 0 right 1 output 0 input 1  right  input

        // mute
        // plausibly AppleHDAWidget::setWidgetAmplifierMute

        //retgain = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x000000a7, 0); // 0x023b2000
        retgain = snd_hda_codec_read_check(codec, spec->linein_amp_nid, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x000000a7, 0); // 0x023b2000
//      snd_hda:     amp gain/mute 35 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 35 0x00a7 mute 1 gain 0x27 39

        newgain = (retgain & 0x7f) | 0x80 | 0x6000;

        snd_hda_codec_write(codec, spec->linein_amp_nid, 0, AC_VERB_SET_AMP_GAIN_MUTE, newgain); // 0x023360a7

        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x000060a7); // 0x023360a7
//      snd_hda:     amp gain/mute 35 0x60a7 mute 1 gain 0x27 39 index 0x00 left 1 right 0 output 0 input 1 left   input

        //retgain = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x000000a7, 0); // 0x023b0000
        retgain = snd_hda_codec_read_check(codec, spec->linein_amp_nid, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x000000a7, 0); // 0x023b0000
//      snd_hda:     amp gain/mute 35 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 35 0x00a7 mute 1 gain 0x27 39

        newgain = (retgain & 0x7f) | 0x80 | 0x5000;

        snd_hda_codec_write(codec, spec->linein_amp_nid, 0, AC_VERB_SET_AMP_GAIN_MUTE, newgain); // 0x023350a7

        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x000050a7); // 0x023350a7
//      snd_hda:     amp gain/mute 35 0x50a7 mute 1 gain 0x27 39 index 0x00 left 0 right 1 output 0 input 1  right  input

        // this is working on node 0x45 macbook pro

        // plausibly AppleHDAWidget::setWidgetAmplifierGain

        //retgain = snd_hda_codec_read_check(codec, 0x45, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x00000000, 0); // 0x045b2000
        retgain = snd_hda_codec_read_check(codec, spec->linein_nid, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x00000000, 0); // 0x045b2000
//      snd_hda:     amp gain/mute 69 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 69 0x0000 mute 0 gain 0x0 0

        snd_hda_codec_write(codec, spec->linein_nid, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00006000); // 0x04536000

        //snd_hda_codec_write(codec, 0x45, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00006000); // 0x04536000
//      snd_hda:     amp gain/mute 69 0x6000 mute 0 gain 0x0 0 index 0x00 left 1 right 0 output 0 input 1 left   input

        //retgain = snd_hda_codec_read_check(codec, 0x45, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x00000000, 0); // 0x045b0000
        retgain = snd_hda_codec_read_check(codec, spec->linein_nid, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x00000000, 0); // 0x045b0000
//      snd_hda:     amp gain/mute 69 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 69 0x0000 mute 0 gain 0x0 0

        snd_hda_codec_write(codec, spec->linein_nid, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00005000); // 0x04535000

        //snd_hda_codec_write(codec, 0x45, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00005000); // 0x04535000
//      snd_hda:     amp gain/mute 69 0x5000 mute 0 gain 0x0 0 index 0x00 left 0 right 1 output 0 input 1  right  input

}


static void cs_8409_intmike_stream_on_nid(struct hda_codec *codec)
{
        int retval;
        int reg_coef82 = 0;
        int new_coef82 = 0;

        struct cs_spec *spec = codec->spec;

        reg_coef82 = snd_hda_coef_item_check(codec, 0, CS8409_VENDOR_NID, 0x0082, 0x0000, 0x00005400, 0 ); //   coef read 10544

        //new_coef82 = (reg_coef82 | 0x1);
        new_coef82 = (reg_coef82 | spec->reg82_intmike_dmic_scl);
        myprintk_dbg("snd_hda_intel: masked cs_8409_intmike_stream_on_nid coef 0x82 update 0x%04x 0x%04x \n", reg_coef82, new_coef82);

        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0082, 0x5401, 0x00000000, 10548 ); //   coef write 10548
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0082, new_coef82, 0x00000000, 0 ); //   coef write 10548

        //retval = snd_hda_codec_read_check(codec, 0x44, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 0); // 0x044f0700
        retval = snd_hda_codec_read_check(codec, spec->intmike_nid, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 0); // 0x044f0700

        snd_hda_codec_write(codec, spec->intmike_nid, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000020); // 0x04470720

        //snd_hda_codec_write(codec, 0x44, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000020); // 0x04470720
//      snd_hda:     68 ['AC_PINCTL_IN_EN']

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}


static void cs_8409_intmike_format_setup_disable(struct hda_codec *codec)
{
        int retval;
        int reg_coef82 = 0;
        int new_coef82 = 0;

        struct cs_spec *spec = codec->spec;


        // set to defaults and disable input
        // note here we really reset to 0 format in addition to stream id 0/channel id 0

        // note this means the cached stream data in the hda_cvt_setup struct will now be inconsistent
        // we need to ensure any further stream format re-update MUST be a forced update
        // still not clear if should be calling eg __snd_hda_codec_cleanup_stream


        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 12217); // 0x022f0500
        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x02270500
        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000030, 12220); // 0x022f0500
        hda_set_node_power_state(codec, spec->intmike_adc_nid, AC_PWRST_D0);

        snd_hda_codec_write(codec, spec->intmike_adc_nid, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x02270600

        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x02270600
//      snd_hda:     conv stream channel map 34 [('CHAN', 0), ('STREAMID', 0)]

        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x02270503
        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 12223); // 0x022f0500
        hda_set_node_power_state(codec, spec->intmike_adc_nid, AC_PWRST_D3);

        snd_hda_codec_write(codec, spec->intmike_adc_nid, 0, AC_VERB_SET_STREAM_FORMAT, 0x00000000); // 0x02220000

        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_STREAM_FORMAT, 0x00000000); // 0x02220000
//      snd_hda:     stream format 34 [('CHAN', 1), ('RATE', 48000), ('BITS', 8), ('RATE_MUL', 1), ('RATE_DIV', 1)]


        // AppleHDAWidgetCS8409::configurePinForIO(bool)??
        reg_coef82 = snd_hda_coef_item_check(codec, 0, CS8409_VENDOR_NID, 0x0082, 0x0000, 0x0000a801, 0 ); //   coef read 12226

        //new_coef82 = (reg_coef82 & 0xfffffffe);
        new_coef82 = (reg_coef82 & ~spec->reg82_intmike_dmic_scl);
        myprintk_dbg("snd_hda_intel: masked cs_8409_intmike_format_setup_disable coef 0x82 update 0x%04x 0x%04x \n", reg_coef82, new_coef82);

        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0082, 0xa800, 0x00000000, 12230 ); //   coef write 12230
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0082, new_coef82, 0x00000000, 0 ); //   coef write 12230

        //retval = snd_hda_codec_read_check(codec, 0x44, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000020, 0); // 0x044f0700
        retval = snd_hda_codec_read_check(codec, spec->intmike_nid, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000020, 0); // 0x044f0700

        snd_hda_codec_write(codec, spec->intmike_nid, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x04470700

        //snd_hda_codec_write(codec, 0x44, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x04470700
//      snd_hda:     68 []

}


static void cs_8409_linein_format_setup_disable(struct hda_codec *codec)
{
        int retval;
        int reg_coef82 = 0;
        int new_coef82 = 0;

        struct cs_spec *spec = codec->spec;

        // 0x45 -> 0x23 is line input (macbook pro)


        // set to defaults and disable input
        // note here we really reset to 0 format in addition to stream id 0/channel id 0

        // note this means the cached stream data in the hda_cvt_setup struct will now be inconsistent
        // we need to ensure any further stream format re-update MUST be a forced update
        // still not clear if should be calling eg __snd_hda_codec_cleanup_stream


        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 12248); // 0x023f0500
        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x02370500
        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000030, 12251); // 0x023f0500
        hda_set_node_power_state(codec, spec->linein_amp_nid, AC_PWRST_D0);

        snd_hda_codec_write(codec, spec->linein_amp_nid, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x02370600

        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x02370600
//      snd_hda:     conv stream channel map 35 [('CHAN', 0), ('STREAMID', 0)]

        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x02370503
        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 12254); // 0x023f0500
        hda_set_node_power_state(codec, spec->linein_amp_nid, AC_PWRST_D3);

        snd_hda_codec_write(codec, spec->linein_amp_nid, 0, AC_VERB_SET_STREAM_FORMAT, 0x00000000); // 0x02320000

        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_STREAM_FORMAT, 0x00000000); // 0x02320000
//      snd_hda:     stream format 35 [('CHAN', 1), ('RATE', 48000), ('BITS', 8), ('RATE_MUL', 1), ('RATE_DIV', 1)]


        reg_coef82 = snd_hda_coef_item_check(codec, 0, CS8409_VENDOR_NID, 0x0082, 0x0000, 0x0000a800, 0 ); //   coef read 12257

        //new_coef82 = (reg_coef82 & 0xfffffffd);
        new_coef82 = (reg_coef82 & ~spec->reg82_linein_dmic_scl);
        myprintk_dbg("snd_hda_intel: masked cs_8409_linein_format_setup_disable coef 0x82 update 0x%04x 0x%04x \n", reg_coef82, new_coef82);

        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0082, 0xa800, 0x00000000, 12261 ); //   coef write 12261
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0082, new_coef82, 0x00000000, 0 ); //   coef write 12261

        //retval = snd_hda_codec_read_check(codec, 0x45, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 0); // 0x045f0700
        retval = snd_hda_codec_read_check(codec, spec->linein_nid, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 0); // 0x045f0700

        snd_hda_codec_write(codec, spec->linein_nid, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x04570700

        //snd_hda_codec_write(codec, 0x45, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x04570700
//      snd_hda:     69 []

}


static void cs_8409_intmike_stream_conn_off(struct hda_codec *codec)
{
        int retval;

        struct cs_spec *spec = codec->spec;

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301

        // 0x44 -> 0x22 is internal (I think) mike input (macbook pro)

        retval = snd_hda_codec_read_check(codec, spec->intmike_adc_nid, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000000, 0); // 0x022f0600

        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000000, 0); // 0x022f0600
//      snd_hda:     conv stream channel map 34 [('CHAN', 0), ('STREAMID', 0)]

        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 12160); // 0x022f0500
        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x02270500
        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000030, 12163); // 0x022f0500
        hda_set_node_power_state(codec, spec->intmike_adc_nid, AC_PWRST_D0);

        snd_hda_codec_write(codec, spec->intmike_adc_nid, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x02270600

        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x02270600
//      snd_hda:     conv stream channel map 34 [('CHAN', 0), ('STREAMID', 0)]

        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x02270503
        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 12166); // 0x022f0500
        hda_set_node_power_state(codec, spec->intmike_adc_nid, AC_PWRST_D3);

        // this seems to be updating the coef index associated with setConnectionSelect
        // unable to figure where this is coming from currently
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0009, 0x0033, 0xffff, 0x00000033, 0, 12168 ); // coef write mask 12168
        snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0009, 0x0000, 0x0000, 0x00000033, 0x0033, 0 ); // coef write mask 12168

}

static void cs_8409_linein_stream_conn_off(struct hda_codec *codec)
{
        int retval;

        struct cs_spec *spec = codec->spec;

        // Im thinking of a bugfix here to turn off bit 0x80 of index 0x0009

        // 0x45 -> 0x23 is line input (macbook pro)

        retval = snd_hda_codec_read_check(codec, spec->linein_amp_nid, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000000, 0); // 0x023f0600

        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000000, 0); // 0x023f0600
//      snd_hda:     conv stream channel map 35 [('CHAN', 0), ('STREAMID', 0)]

        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 12175); // 0x023f0500
        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x02370500
        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000030, 12178); // 0x023f0500
        hda_set_node_power_state(codec, spec->linein_amp_nid, AC_PWRST_D0);

        snd_hda_codec_write(codec, spec->linein_amp_nid, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x02370600

        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x02370600
//      snd_hda:     conv stream channel map 35 [('CHAN', 0), ('STREAMID', 0)]

        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x02370503
        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 12181); // 0x023f0500
        hda_set_node_power_state(codec, spec->linein_amp_nid, AC_PWRST_D3);

        // this seems to be updating the coef index associated with setConnectionSelect
        // unable to figure where this is coming from currently
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0009, 0x0033, 0xffff, 0x00000033, 0, 12183 ); // coef write mask 12183
        snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0009, 0x0000, 0x0000, 0x00000033, 0x0033, 0 ); // coef write mask 12183
        // possible correct mask to use
        //snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0009, 0x0000, 0x0080, 0x00000033, 0, 0 ); // coef write mask 12183

}

static void cs_8409_intmike_stream_off_nid(struct hda_codec *codec)
{
        int retval;

        struct cs_spec *spec = codec->spec;

        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 12189); // 0x022f0500
        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x02270500
        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000030, 12192); // 0x022f0500
        hda_set_node_power_state(codec, spec->intmike_adc_nid, AC_PWRST_D0);

        snd_hda_codec_write(codec, spec->intmike_adc_nid, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x02270600

        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x02270600
//      snd_hda:     conv stream channel map 34 [('CHAN', 0), ('STREAMID', 0)]

        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x02270503
        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 12195); // 0x022f0500
        hda_set_node_power_state(codec, spec->intmike_adc_nid, AC_PWRST_D3);

}

static void cs_8409_linein_stream_off_nid(struct hda_codec *codec)
{
        int retval;

        struct cs_spec *spec = codec->spec;

        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 12197); // 0x023f0500
        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x02370500
        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000030, 12200); // 0x023f0500
        hda_set_node_power_state(codec, spec->linein_amp_nid, AC_PWRST_D0);

        snd_hda_codec_write(codec, spec->linein_amp_nid, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x02370600

        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x02370600
//      snd_hda:     conv stream channel map 35 [('CHAN', 0), ('STREAMID', 0)]

        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x02370503
        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 12203); // 0x023f0500
        hda_set_node_power_state(codec, spec->linein_amp_nid, AC_PWRST_D3);

}


static void cs_8409_intmike_volume_mute_nouse(struct hda_codec *codec)
{
        int retval;

        struct cs_spec *spec = codec->spec;

        // nodes 0x44 is connected to 0x22 which is labelled mic input (macbook pro)

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        retval = snd_hda_codec_read_check(codec, spec->intmike_adc_nid, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x000000a7, 0); // 0x022b2000
        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x000000a7, 0); // 0x022b2000
//      snd_hda:     amp gain/mute 34 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 34 0x00a7 mute 1 gain 0x27 39
        snd_hda_codec_write(codec, spec->intmike_adc_nid, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x000060b3); // 0x022360b3
        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x000060b3); // 0x022360b3
//      snd_hda:     amp gain/mute 34 0x60b3 mute 1 gain 0x33 51 index 0x00 left 1 right 0 output 0 input 1 left   input
        retval = snd_hda_codec_read_check(codec, spec->intmike_adc_nid, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x000000a7, 0); // 0x022b0000
        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x000000a7, 0); // 0x022b0000
//      snd_hda:     amp gain/mute 34 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 34 0x00a7 mute 1 gain 0x27 39
        snd_hda_codec_write(codec, spec->intmike_adc_nid, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x000050b3); // 0x022350b3
        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x000050b3); // 0x022350b3
//      snd_hda:     amp gain/mute 34 0x50b3 mute 1 gain 0x33 51 index 0x00 left 0 right 1 output 0 input 1  right  input

}

static void cs_8409_linein_volume_mute_nouse(struct hda_codec *codec)
{
        int retval;

        struct cs_spec *spec = codec->spec;

        // nodes 0x45 which are connected to 0x23 is labelled as line input (macbook pro)

        retval = snd_hda_codec_read_check(codec, spec->linein_amp_nid, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x000000a7, 0); // 0x023b2000
        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x000000a7, 0); // 0x023b2000
//      snd_hda:     amp gain/mute 35 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 35 0x00a7 mute 1 gain 0x27 39
        snd_hda_codec_write(codec, spec->linein_amp_nid, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x000060b3); // 0x023360b3
        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x000060b3); // 0x023360b3
//      snd_hda:     amp gain/mute 35 0x60b3 mute 1 gain 0x33 51 index 0x00 left 1 right 0 output 0 input 1 left   input
        retval = snd_hda_codec_read_check(codec, spec->linein_amp_nid, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x000000a7, 0); // 0x023b0000
        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x000000a7, 0); // 0x023b0000
//      snd_hda:     amp gain/mute 35 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 35 0x00a7 mute 1 gain 0x27 39
        snd_hda_codec_write(codec, spec->linein_amp_nid, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x000050b3); // 0x023350b3
        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x000050b3); // 0x023350b3
//      snd_hda:     amp gain/mute 35 0x50b3 mute 1 gain 0x33 51 index 0x00 left 0 right 1 output 0 input 1  right  input

}

static void cs_8409_intmike_volume_unmute_nouse(struct hda_codec *codec)
{
        int retval;

        struct cs_spec *spec = codec->spec;

        // nodes 0x44 is connected to 0x22 which is labelled mic input (macbook pro)

        retval = snd_hda_codec_read_check(codec, spec->intmike_adc_nid, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x000000b3, 0); // 0x022b2000
        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x000000b3, 0); // 0x022b2000
//      snd_hda:     amp gain/mute 34 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 34 0x00b3 mute 1 gain 0x33 51
        snd_hda_codec_write(codec, spec->intmike_adc_nid, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00006033); // 0x02236033
        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00006033); // 0x02236033
//      snd_hda:     amp gain/mute 34 0x6033 mute 0 gain 0x33 51 index 0x00 left 1 right 0 output 0 input 1 left   input
        retval = snd_hda_codec_read_check(codec, spec->intmike_adc_nid, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x000000b3, 0); // 0x022b0000
        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x000000b3, 0); // 0x022b0000
//      snd_hda:     amp gain/mute 34 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 34 0x00b3 mute 1 gain 0x33 51
        snd_hda_codec_write(codec, spec->intmike_adc_nid, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00005033); // 0x02235033
        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00005033); // 0x02235033
//      snd_hda:     amp gain/mute 34 0x5033 mute 0 gain 0x33 51 index 0x00 left 0 right 1 output 0 input 1  right  input

}
 
static void cs_8409_linein_volume_unmute_nouse(struct hda_codec *codec)
{
        int retval;

        struct cs_spec *spec = codec->spec;

        // nodes 0x45 which are connected to 0x23 is labelled as line input (macbook pro)

        retval = snd_hda_codec_read_check(codec, spec->linein_amp_nid, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x000000b3, 0); // 0x023b2000
        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00002000, 0x000000b3, 0); // 0x023b2000
//      snd_hda:     amp gain/mute 35 0x2000 index 0x00 left/right 1 left output/input 0 input
//      snd_hda:     amp gain/mute 35 0x00b3 mute 1 gain 0x33 51
        snd_hda_codec_write(codec, spec->linein_amp_nid, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00006033); // 0x02336033
        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00006033); // 0x02336033
//      snd_hda:     amp gain/mute 35 0x6033 mute 0 gain 0x33 51 index 0x00 left 1 right 0 output 0 input 1 left   input
        retval = snd_hda_codec_read_check(codec, spec->linein_amp_nid, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x000000b3, 0); // 0x023b0000
        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_AMP_GAIN_MUTE, 0x00000000, 0x000000b3, 0); // 0x023b0000
//      snd_hda:     amp gain/mute 35 0x0000 index 0x00 left/right 0 right output/input 0 input
//      snd_hda:     amp gain/mute 35 0x00b3 mute 1 gain 0x33 51
        snd_hda_codec_write(codec, spec->linein_amp_nid, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00005033); // 0x02335033
        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_AMP_GAIN_MUTE, 0x00005033); // 0x02335033
//      snd_hda:     amp gain/mute 35 0x5033 mute 0 gain 0x33 51 index 0x00 left 0 right 1 output 0 input 1  right  input

}


static void cs_8409_setup_TDM_sample_rate(struct hda_codec *codec)
{

        // codes from windows cs4208_38.inf file
        // 0x0001 undocumented (0x0066 = ASP1/2_EN = 1, ASP1/2_STP = 1 ie ASP1_EN = 0x40, ASP2_EN = 0x20, ASP1_STP = 0x4, ASP2_STP = 0x2)
        // 0x0005 0x0001 SCDIV 1:4 (0x005a = ASP1: MCEN = 0, FSD = 010 (0x40), SCPOL_IN/OUT = 1 (0x10), SCDIV = 1:4 ie 0x0-0xf)
        // 0x0004 0x08ff SC_SRCSEL? = PLL1, LCPR = 0xff (0x28FF = (ASP1: MC/SC_SRCSEL = PLL1, LCPR = FFh), 0x2801 = (ASP1: MC/SC_SRCSEL = PLL1, LCPR = 01h))

//      snd_hda: # AppleHDATDMBusManagerCS8409::setSampleRate:
        //snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0001, 0x0200, 0xffff, 0x00000200, 0, 25 ); // coef write mask 25

        //snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0005, 0x0001, 0xffff, 0x00000001, 0, 31 ); // coef write mask 31
        //snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0004, 0x08ff, 0xffff, 0x000008ff, 0, 37 ); // coef write mask 37

        // we need to use proper masked versions here - in particular for register 1 which seems to be some form of enable control
        // for the subsystems and bits 0x7f need to pass thro here
        snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0001, 0x0200, 0x0380, 0x00000200, 0, 0 ); // coef write mask 25

        snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0005, 0x0001, 0x0007, 0x00000001, 0, 0 ); // coef write mask 31
        snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0004, 0x08ff, 0x01ff, 0x000008ff, 0, 0 ); // coef write mask 37
}

static void cs_8409_setup_TDM_proper_amps12(struct hda_codec *codec)
{
        int ret_coef0 = 0;
        int new_coef0 = 0;
        int ret_coef1 = 0;
        int new_coef1 = 0;
        int ret_coef71 = 0;
        int new_coef71 = 0;

        // codes from windows cs4208_38.inf file
        // 0x0019 0x0800 = (ASP1.A: TX.LAP = 0, TX.LSZ = 24 bits, TX.LCS = 0)
        // 0x001a 0x0820 = (ASP1.A: TX.RAP = 0, TX.RSZ = 24 bits, TX.RCS = 32)

//      snd_hda: # AppleHDATDMBusManagerCS8409::setupTDMPath: 
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00008800, 0 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 44
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0019, 0x0800, 0x00000000, 0 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 48
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001a, 0x0000, 0x00008820, 0 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 52
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001a, 0x0820, 0x00000000, 0 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 56

        // codes from windows cs4208_38.inf file
        // 0x0000 0xb000 = PLL2_EN (0x2000) PLL1_EN (0x1000) I2C disabled
        // 0x0004 0x08ff SC_SRCSEL? = PLL1, LCPR = 0xff (0x28FF = (ASP1: MC/SC_SRCSEL = PLL1, LCPR = FFh), 0x2801 = (ASP1: MC/SC_SRCSEL = PLL1, LCPR = 01h))
        // 0x0000 0x9000 = PLL1_EN (0x1000) I2C disabled

        ret_coef0 = snd_hda_coef_item_check(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 0 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 60
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0xb000, 0x00000000, 0 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 64
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0004, 0x0000, 0x000008ff, 0 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 68
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0004, 0x08ff, 0x00000000, 0 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 72
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 76 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 76
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0xb000, 0x00000000, 76 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 76
        // it seems we re-write what we read just above here - if never plugin headphones its 0x9000
        // after headphone plugin its 0xb0000 - even after unplugging headphones!!
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, ret_coef0, 0x00000000, 0 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 76

        // codes from windows cs4208_38.inf file
        // 0x0003 0x8000 = (ASP1: LCHI = 00h)
        // 0x0005 0x0001 = SCDIV = 1:4 (0x005A = (ASP1: MCEN = 0, FSD = 010 (0x40), SCPOL_IN/OUT = 1 (0x10), SCDIV = 1:4))

//      snd_hda: # AppleHDATDMBusManagerCS8409::setupTDMPath: 
        snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0003, 0x8000, 0xffff, 0x00008000, 0, 0 ); // coef write mask 80
        snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0005, 0x0001, 0xffff, 0x00000001, 0, 0 ); // coef write mask 86

        // codes from windows cs4208_38.inf file
        // 0x0082 0x5401 = ASP1_xxx_EN (0x4000) ASP1_xxx_EN (0x1000) ASP1_xxx_EN (0x400) DMIC1_SCL_EN = 1 (0xFC01 = (ASP1/2_xxx_EN = 1, ASP1/2_MCLK_EN = 0, DMIC1_SCL_EN = 1))

//      snd_hda: # AppleHDATDMBusManagerCS8409::setupTDMPath: 
        //snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0082, 0x5401, 0xffff, 0x00000001, 0, 92 ); // coef write mask 92
        snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0082, 0x5400, 0x0000, 0x00000001, 0x5401, 0 ); // coef write mask 92

        // codes from windows cs4208_38.inf file
        // 0x0002 0x0280 = ASP2_BUS_IDLE (0x02) GPIO_I2C (0x0A80 = (ASP1/2_BUS_IDLE = 10, +GPIO_I2C))

        // no evidence this is anything other than 0x0280 yet
        snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0002, 0x0280, 0xffff, 0x00000280, 0, 0 ); // coef write mask 98

        ret_coef1 = snd_hda_coef_item_check(codec, 0, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000200, 0 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 104

        new_coef1 = (ret_coef1 & 0xffff) | 0x20;
        myprintk_dbg("snd_hda_intel: masked cs_8409_setup_TDM_proper_amps12 coef 0x01 update 0x%04x 0x%04x \n", ret_coef1, new_coef1);

        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, 0x0220, 0x00000000, 108 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 108
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, new_coef1, 0x00000000, 0 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 108

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: AppleHDATDMBusManagerCS8409::tdmInUse:
        //snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00000800, 112 ); //   coef read 112

        tdm_in_use(codec, 1);

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: 
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006b, 0x001f, 0x00000000, 0 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 117

        ret_coef71 = snd_hda_coef_item_check(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x00000000, 0 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef read 121

        new_coef71 = (ret_coef71 & 0xffff) | 0x400f;
        myprintk_dbg("snd_hda_intel: masked cs_8409_setup_TDM_proper_amps12 coef 0x71 update 0x%04x 0x%04x \n", ret_coef71, new_coef71);

        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x400f, 0x00000000, 125 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 125
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, new_coef71, 0x00000000, 0 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 125

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00b6 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  write verb 128
}

static void cs_8409_setup_TDM_amps12(struct hda_codec *codec, int setrate, int nullformat)
{
        int retval;
        int ret_coef1 = 0;
        int new_coef1 = 0;

        // this seems to be setup for node 0x02 chain - which seems to use node 0x24 and amps 0x64 and 0x62 (or 0x28 0x2a)

        //snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004033); // 0x00224033
//      snd_hda:     stream format 2 [('CHAN', 4), ('RATE', 44100), ('BITS', 24), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        //snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000010); // 0x00270610
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 1)]

        if (nullformat)
        {
                // note that 0x4033 is Apples fixed format - but this is for boot stage when we have
                // not defined any format yet so just use it - we overwrite below when actually play
                snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004033); // 0x00224033
                snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00270600
        }
        else
        {
                // using the stored stream parameters update nid 0x2 stream parameters
                // we have limited the allowed formats so should only have working formats here
                cs_8409_really_update_stream_format(codec, 0x02, 1, 2, 0);
        }


//      snd_hda: # AppleHDATDMBusManagerCS8409::setupTDMPath:
        ret_coef1 = snd_hda_coef_item_check(codec, 0, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000200, 0 ); //   coef read 16

        new_coef1 = (ret_coef1 & 0xffff); // not clear what this is setting - no difference between read and write
                                          // however if used in different places the actual value may be different
        myprintk_dbg("snd_hda_intel: masked cs_8409_setup_TDM_amps12 coef 0x01 update 0x%04x 0x%04x \n", ret_coef1, new_coef1);

        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, 0x0200, 0x00000000, 20 ); //   coef write 20
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, new_coef1, 0x00000000, 0 ); //   coef write 20

        if (setrate)
                cs_8409_setup_TDM_sample_rate(codec);


        cs_8409_setup_TDM_proper_amps12(codec);


        // enable output node 0x24

        //retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 132); // 0x024f0700
        retval = snd_hda_codec_read(codec, 0x24, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000); // 0x024f0700
        snd_hda_codec_write(codec, 0x24, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000040); // 0x02470740
//      snd_hda:     36 ['AC_PINCTL_OUT_EN']

}


static void play_setup_TDM_amps12(struct hda_codec *codec, int setrate)
{
        cs_8409_setup_TDM_amps12(codec, setrate, 0);
}


static void cs_8409_setup_amp_max(struct hda_codec *codec, int amp_address, int amp_volume, int channel);

static void cs_8409_setup_amp_ssm3(struct hda_codec *codec, int amp_address, int amp_volume, int channel);

static void cs_8409_setup_amp_tas576(struct hda_codec *codec, int amp_address, int amp_volume, int channel, int amp_enable);

static void cs_8409_setup_amp_tas576_amp0(struct hda_codec *codec, int amp_volume, int amp_enable);
static void cs_8409_setup_amp_tas576_amp1(struct hda_codec *codec, int amp_volume, int amp_enable);
static void cs_8409_setup_amp_tas576_amp2(struct hda_codec *codec, int amp_volume, int amp_enable);
static void cs_8409_setup_amp_tas576_amp3(struct hda_codec *codec, int amp_volume, int amp_enable);

static void cs_8409_setup_amps12(struct hda_codec *codec, int amps_enable)
{
        if (codec->core.subsystem_id == 0x106b3900) {
                // use reduced volume - from 0x01 to 0x30 - now passing as argument
                cs_8409_setup_amp_max(codec, 0x64, 0x30, 0x00);
                cs_8409_setup_amp_max(codec, 0x62, 0x30, 0x01);
                //cs_8409_setup_amp_max(codec, 0x64, 0x01, 0x00);
                //cs_8409_setup_amp_max(codec, 0x62, 0x01, 0x01);
        }
        else if (codec->core.subsystem_id == 0x106b3300 || codec->core.subsystem_id == 0x106b3600) {
                //setup_node_alpha_ssm3(codec);
                // use reduced volume - from 0x48 to 0x80 - same reduction as for MAXs -24dB
                cs_8409_setup_amp_ssm3(codec, 0x28, 0x80, 0x00);
                cs_8409_setup_amp_ssm3(codec, 0x2a, 0x80, 0x01);
                //cs_8409_setup_amp_ssm3(codec, 0x28, 0x48, 0x00);
                //cs_8409_setup_amp_ssm3(codec, 0x2a, 0x48, 0x01);
        }
        else if (codec->core.subsystem_id == 0x106b1000) {
                // NOTE that the TAS57642 amps setup during boot seems to skip the actual speaker power on
                //      hence the addition of the amps_enable parameter
                // use reduced volume - from 0xcf to 0x9f - same reduction as for MAXs -24dB (0.5dB steps)
                //cs_8409_setup_amp_tas576_amp0(codec, 0x9f, amps_enable);
                //cs_8409_setup_amp_tas576_amp1(codec, 0x9f, amps_enable);
                cs_8409_setup_amp_tas576(codec, 0xd8, 0x9f, 0x00, amps_enable);
                cs_8409_setup_amp_tas576(codec, 0xda, 0x9f, 0x01, amps_enable);
                //cs_8409_setup_amp_tas576(codec, 0xd8, 0xcf, 0x00, amps_enable);
                //cs_8409_setup_amp_tas576(codec, 0xda, 0xcf, 0x01, amps_enable);
        }
        else {
                dev_info(hda_codec_dev(codec), "UNKNOWN subsystem id 0x%08x",codec->core.subsystem_id);
        }
}

static void play_setup_amps12(struct hda_codec *codec)
{
        cs_8409_setup_amps12(codec, 1);
}


static void cs_8409_setup_TDM_proper_amps34(struct hda_codec *codec)
{
        int ret_coef71 = 0;
        int new_coef71 = 0;

        // codes from windows cs4208_38.inf file
        // 0x001b 0x0840 = (ASP1.B: TX.LAP = 0, TX.LSZ = 24 bits, TX.LCS = 64)
        // 0x001c 0x0860 = (ASP1.B: TX.RAP = 0, TX.RSZ = 24 bits, TX.RCS = 96)

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001b, 0x0000, 0x00008840, 0 ); //   coef read 1407
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001b, 0x0840, 0x00000000, 0 ); //   coef write 1411
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001c, 0x0000, 0x00008860, 0 ); //   coef read 1415
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001c, 0x0860, 0x00000000, 0 ); //   coef write 1419

        // the following actually reads from 0x19 to 0x57 in a loop if the snd_hda_coef_item returns 0 till the read value
        // does not have the word sign bit set (ie 0x8000) or finish all 0x57

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: AppleHDATDMBusManagerCS8409::tdmInUse:
        //snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00000800, 1423 ); //   coef read 1423

        tdm_in_use(codec, 2);

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: 
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006b, 0x001f, 0x00000000, 0 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 1428

        ret_coef71 = snd_hda_coef_item_check(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x0000400f, 0 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef read 1432

        new_coef71 = (ret_coef71 & 0xffff) | 0x400f;
        myprintk_dbg("snd_hda_intel: masked cs_8409_setup_TDM_proper_amps34 coef 0x71 update 0x%04x 0x%04x \n", ret_coef71, new_coef71);

        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x400f, 0x00000000, 1436 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 1436
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, new_coef71, 0x00000000, 0 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 1436

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00b6 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  write verb 1439

}

static void cs_8409_setup_TDM_amps34(struct hda_codec *codec, int nullformat)
{
        int retval;

        // this seems to be setup for node 0x03 chain - which seems to use node 0x25 and amps 0x74 and 0x72 (or 0x2c and 0x2e)

        //snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004033); // 0x00324033
//      snd_hda:     stream format 3 [('CHAN', 4), ('RATE', 44100), ('BITS', 24), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        //snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000012); // 0x00370612
//      snd_hda:     conv stream channel map 3 [('CHAN', 2), ('STREAMID', 1)]

        if (nullformat)
        {
                // note that 0x4033 is Apples fixed format - but this is for boot stage when we have
                // not defined any format yet so just use it - we overwrite below when actually play
                // note this updates the channel but not stream id????
                snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004033); // 0x00224033
                snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000002); // 0x00270602
        }
        else
        {
                // using the stored stream parameters update nid 0x3 stream parameters
                // we have limited the allowed formats so should only have working formats here
                cs_8409_really_update_stream_format(codec, 0x03, 1, 2, 2);
        }

        cs_8409_setup_TDM_proper_amps34(codec);


        // enable output on node 0x25

        //retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 1443); // 0x025f0700
        retval = snd_hda_codec_read(codec, 0x25, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000); // 0x025f0700
        snd_hda_codec_write(codec, 0x25, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000040); // 0x02570740
//      snd_hda:     37 ['AC_PINCTL_OUT_EN']

}


static void play_setup_TDM_amps34(struct hda_codec *codec)
{
        cs_8409_setup_TDM_amps34(codec, 0);
}

static void cs_8409_setup_amps34(struct hda_codec *codec, int amps_enable)
{
        if (codec->core.subsystem_id == 0x106b3900) {
                // use reduced volume - from 0x01 to 0x30 - now passing as argument
                cs_8409_setup_amp_max(codec, 0x74, 0x30, 0x02);
                cs_8409_setup_amp_max(codec, 0x72, 0x30, 0x03);
                //cs_8409_setup_amp_max(codec, 0x74, 0x01, 0x02);
                //cs_8409_setup_amp_max(codec, 0x72, 0x01, 0x03);
        }
        else if (codec->core.subsystem_id == 0x106b3300 || codec->core.subsystem_id == 0x106b3600) {
                //setup_node_alpha_ssm3(codec);
                // use reduced volume - from 0x48 to 0x80 - same reduction as for MAXs -24dB
                cs_8409_setup_amp_ssm3(codec, 0x2c, 0x80, 0x02);
                cs_8409_setup_amp_ssm3(codec, 0x2e, 0x80, 0x03);
                //cs_8409_setup_amp_ssm3(codec, 0x2c, 0x48, 0x02);
                //cs_8409_setup_amp_ssm3(codec, 0x2e, 0x48, 0x03);
        }
        else if (codec->core.subsystem_id == 0x106b1000) {
                // NOTE that the TAS57642 amps setup during boot seems to skip the actual speaker power on
                //      hence the addition of the amps_enable parameter
                // use reduced volume - from 0xcf to 0x9f - same reduction as for MAXs -24dB (0.5dB steps)
                //cs_8409_setup_amp_tas576_amp2(codec, 0x9f, amps_enable);
                //cs_8409_setup_amp_tas576_amp3(codec, 0x9f, amps_enable);
                cs_8409_setup_amp_tas576(codec, 0xdc, 0x9f, 0x02, amps_enable);
                cs_8409_setup_amp_tas576(codec, 0xde, 0x9f, 0x03, amps_enable);
                //cs_8409_setup_amp_tas576(codec, 0xdc, 0xcf, 0x02, amps_enable);
                //cs_8409_setup_amp_tas576(codec, 0xde, 0xcf, 0x03, amps_enable);
        }
        else {
                dev_info(hda_codec_dev(codec), "UNKNOWN subsystem id 0x%08x",codec->core.subsystem_id);
        }
}

static void play_setup_amps34(struct hda_codec *codec)
{
        cs_8409_setup_amps34(codec, 1);
}

static void cs_8409_sync_converters_on(struct hda_codec *codec, int nullformat)
{
        int retval;

        struct hda_cvt_setup p2;
        struct hda_cvt_setup p3;

        // this stops streaming on nodes 0x2 and 0x3 by switching to stream index 0
        // then updates vendor node coef index 0x0017 twice
        // first with 0x1 for node 0x2 and then with 0x2 for node 0x3
        // giving a final 0x3
        // then sets up ready for streaming again

        // so coef index 0x17 is likely turning on the TDM stream

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301

        // remove normal channel mapping

//      snd_hda: # AppleHDAFunctionGroupCS8409::syncConverters:
        //retval = snd_hda_codec_read_check(codec, 0x02, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000010, 2714); // 0x002f0600
        //retval = snd_hda_codec_read(codec, 0x02, 0, AC_VERB_GET_CONV, 0x00000000); // 0x002f0600
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 1)]

        //snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00270600
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]

        cs_8409_save_and_clear_stream_format(codec, 0x02, &p2);


        snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0001, 0xffff, 0x00000000, 0, 0 ); // coef write mask 2716


//      snd_hda: # AppleHDAFunctionGroupCS8409::syncConverters:
        //retval = snd_hda_codec_read_check(codec, 0x03, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000012, 2722); // 0x003f0600
        //retval = snd_hda_codec_read(codec, 0x03, 0, AC_VERB_GET_CONV, 0x00000000); // 0x003f0600
//      snd_hda:     conv stream channel map 3 [('CHAN', 2), ('STREAMID', 1)]

        //snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00370600
//      snd_hda:     conv stream channel map 3 [('CHAN', 0), ('STREAMID', 0)]

        cs_8409_save_and_clear_stream_format(codec, 0x03, &p3);


        snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0003, 0xffff, 0x00000001, 0, 0 ); // coef write mask 2724


        // and reset back to normal channel mapping

        //snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000010); // 0x00270610
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 1)]

        //snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000012); // 0x00370612
//      snd_hda:     conv stream channel map 3 [('CHAN', 2), ('STREAMID', 1)]

        if (nullformat)
        {
                snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00270600
                snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000002); // 0x00270602
        }
        else
        {
                cs_8409_update_from_save_stream_format(codec, 0x02, &p2, 1, 0);
                cs_8409_update_from_save_stream_format(codec, 0x03, &p3, 1, 0);
        }
}


static void play_sync_converters_on(struct hda_codec *codec)
{
        cs_8409_sync_converters_on(codec, 0);
}



static void cs_8409_setup_amp_max(struct hda_codec *codec, int amp_address, int amp_volume, int channel)
{
        //int retval;

        // NOTA BENE - reduced volume from 0x01 to 0x30 - seems to fit with linux levels much better
        // this is semi arbitrary - just hears about OK - not based on rational analysis of amp gains


        // HPFDCBlocker new as of June 2019

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x1c01 i2c data 0x0001   reg anal: DigitalFilter           : HPFDCBlocker
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x1008 i2c data 0x0008   reg anal: PCMClockSetup           : 256 Bclks
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x14e4 i2c data 0x00e4   reg anal: PCMModeConfig           : 32 bits TDM mode 2
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x1501 i2c data 0x0001   reg anal: PCMRXEnablesA
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x1600 i2c data 0x0000   reg anal: PCMRXEnablesB
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x1800 i2c data 0x0000   reg anal: MonoMixChannelSource
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x2d01 i2c data 0x0001   reg anal: DigitalVolCtrl
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x2e05 i2c data 0x0005   reg anal: PathGain
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x4a21 i2c data 0x0021   reg anal: SpeakerEnable           : AmpEnabled
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x4d07 i2c data 0x0007   reg anal: RestartBehavior
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x5534 i2c data 0x0034   reg anal: LimiterAttackRelease
//      snd_hda i2cRead       i2c address 0x64 i2c            reg 0x1100 i2c data 0x1107   reg anal: PCMSampleSetup          : 44.1kHz
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x1107 i2c data 0x0007   reg anal: PCMSampleSetup          : 44.1kHz
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x093f i2c data 0x003f   reg anal: InterruptClears0
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x0a7f i2c data 0x007f   reg anal: InterruptClears1
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x0f0e i2c data 0x000e   reg anal: IRQClear1
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x5001 i2c data 0x0001   reg anal: GlobalEnable            : Enable

        cs_8409_vendor_i2cWrite(codec, amp_address, 0x001c, 0x0001, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0010, 0x0008, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0014, 0x00e4, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0015, (1<<channel), 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0016, 0x0000, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0018, channel, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0019, 0x0000, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x002d, amp_volume, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x002e, 0x0005, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x004a, 0x0021, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x004d, 0x0007, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0055, 0x0034, 0); // snd_hda
        cs_8409_vendor_i2cRead(codec, amp_address, 0x0011, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0011, 0x0007, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0009, 0x003f, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x000a, 0x007f, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x000f, 0x000e, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0050, 0x0001, 0); // snd_hda

}

static void cs_8409_setup_amp_ssm3(struct hda_codec *codec, int amp_address, int amp_volume, int channel)
{
        //int retval;

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x28 i2c            reg 0x0500 i2c data 0x0000   reg anal: SAIControl2             : ChipSlot 1 SlotByTDMRReg 24 bit Audio
//      snd_hda i2cWrite      i2c address 0x28 i2c            reg 0x0111 i2c data 0x0011   reg anal: GainEdgeControl         : 12.6V FSGainMap LowEMI
//      snd_hda i2cWrite      i2c address 0x28 i2c            reg 0x0348 i2c data 0x0048   reg anal: DACVolume               : -3.0dB
//      snd_hda i2cWrite      i2c address 0x28 i2c            reg 0x0451 i2c data 0x0051   reg anal: SAIControl1             : TDMPCMMode 24 BClks per Chip Delay1 PulsedSync Falling
//      snd_hda i2cRead       i2c address 0x28 i2c            reg 0x0200 i2c data 0x0232   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
//      snd_hda i2cWrite      i2c address 0x28 i2c            reg 0x0232 i2c data 0x0032   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
//      snd_hda i2cRead       i2c address 0x28 i2c            reg 0x0200 i2c data 0x0232   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
//      snd_hda i2cWrite      i2c address 0x28 i2c            reg 0x0232 i2c data 0x0032   reg anal: DACControl              : 32-48kHz SampleRate DACLowPower DACHighPass DACSoftVol
//      snd_hda i2cWrite      i2c address 0x28 i2c            reg 0x0000 i2c data 0x0000   reg anal: PowerControl            : PowerOn BVSenseOn

        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0005, channel, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0001, 0x0011, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0003, amp_volume, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0004, 0x0051, 1); // snd_hda
        cs_8409_vendor_i2cRead(codec, amp_address, 0x0002, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0002, 0x0032, 1); // snd_hda
        cs_8409_vendor_i2cRead(codec, amp_address, 0x0002, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0002, 0x0032, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0000, 0x0000, 1); // snd_hda

}

static void cs_8409_setup_amp_tas576(struct hda_codec *codec, int amp_address, int amp_volume, int channel, int amp_enable)
{
        //int retval;

        // this data from the TAS5760md spec sheet (closest one I can find)
        // there are a number of inconsistencies
        // first - the MAX/SSM amps are mono amps but the TAS5760md seems to be a stereo amp 
        // (there is a PBTL mode which can use both amps to drive a single speaker which
        //  may be whats going on - now this can be set in hardware but its does not appear to be done in software)
        // - note that the HDA node setup seems to be 4 channel audio as 2 left channels (node 0x02) and 2 right channels (0x03)
        // hence 4 mono amps required
        // some regs seem valid - others not
	// reg 0x01 does seem to be the power control and is used to enable/disable the amps and values are consistent
	// reg 0x04 is labelled the Left Volume but there are no reg 0x05 Right Volume setup calls at all
        // reg 0x03 is labelled Volume Control and the Fade may be right
        // but the low order mute bits dont make sense - simply seems to index the amps ie 0,1,2,3
        // - which according to tas5760 docs would be no mute, mute left, mute right, mute all
        // what makes more sense is that its indexing the individual channels of the 4 channel TDM stream
        // so yes I think this is being used in PBTL mode to drive a single speaker with reg 0x04 being
        // the volume control and reg 0x03 low order bits determining which channel to use

        // NOTE that the TAS57642 amps setup during boot seems to skip the actual speaker power on
        //      hence the addition of the amp_enable parameter


//      snd_hda i2cRead       i2c address 0xd8 i2c            reg 0x0200 i2c data 0x0204   reg anal: Digital Control
//      snd_hda i2cWrite      i2c address 0xd8 i2c            reg 0x0244 i2c data 0x0044   reg anal: Digital Control         : I2S format, Undocumented
//      snd_hda i2cRead       i2c address 0xd8 i2c            reg 0x0300 i2c data 0x0380   reg anal: Volume Control
//      snd_hda i2cWrite      i2c address 0xd8 i2c            reg 0x0380 i2c data 0x0080   reg anal: Volume Control          : Fade, Muted??
//      snd_hda i2cRead       i2c address 0xd8 i2c            reg 0x0600 i2c data 0x0651   reg anal: Analog Control
//      snd_hda i2cWrite      i2c address 0xd8 i2c            reg 0x0655 i2c data 0x0055   reg anal: Analog Control          : PWM Rate x16, Gain 22.6dB
//      snd_hda i2cRead       i2c address 0xd8 i2c            reg 0x0800 i2c data 0x0808   reg anal: Fault Config & Error
//      snd_hda i2cWrite      i2c address 0xd8 i2c            reg 0x0818 i2c data 0x0018   reg anal: Fault Config & Error    : Threshold 75%, Clock Error??
//      snd_hda i2cWrite      i2c address 0xd8 i2c            reg 0x04cf i2c data 0x00cf   reg anal: Left Chan Vol Control   : 0dB
//      snd_hda i2cRead       i2c address 0xd8 i2c            reg 0x1300 i2c data 0x1300   reg anal: Undocumented
//      snd_hda i2cWrite      i2c address 0xd8 i2c            reg 0x1300 i2c data 0x0000   reg anal: Undocumented
//      snd_hda i2cRead       i2c address 0xd8 i2c            reg 0x0200 i2c data 0x0244   reg anal: Digital Control
//      snd_hda i2cWrite      i2c address 0xd8 i2c            reg 0x0244 i2c data 0x0044   reg anal: Digital Control         : I2S format, Undocumented

        // here we have read/write pairs suggesting this is done as masked i2c writes
        // but we have no idea what the masks are

        cs_8409_vendor_i2cRead(codec, amp_address, 0x0002, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0002, 0x0044, 0); // snd_hda
        cs_8409_vendor_i2cRead(codec, amp_address, 0x0003, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0003, 0x0080|channel, 0); // snd_hda
        cs_8409_vendor_i2cRead(codec, amp_address, 0x0006, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0006, 0x0055, 0); // snd_hda
        cs_8409_vendor_i2cRead(codec, amp_address, 0x0008, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0008, 0x0018, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0004, amp_volume, 0); // snd_hda
        cs_8409_vendor_i2cRead(codec, amp_address, 0x0013, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0013, 0x0000, 0); // snd_hda
        cs_8409_vendor_i2cRead(codec, amp_address, 0x0002, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0002, 0x0044, 0); // snd_hda


//      snd_hda i2cRead       i2c address 0xd8 i2c            reg 0x0100 i2c data 0x01fc   reg anal: Power Control
//      snd_hda i2cWrite      i2c address 0xd8 i2c            reg 0x01fd i2c data 0x00fd   reg anal: Power Control           : Not sleep, Spkr Amp On

        if (amp_enable)
        {
                cs_8409_vendor_i2cRead(codec, amp_address, 0x0001, 0); // snd_hda
                cs_8409_vendor_i2cWrite(codec, amp_address, 0x0001, 0x00fd, 0); // snd_hda
        }
}

static void cs_8409_setup_amp_tas576_amp0(struct hda_codec *codec, int amp_volume, int amp_enable)
{
        //int retval;

//      snd_hda i2cRead       i2c address 0xd8 i2c            reg 0x0200 i2c data 0x0204   reg anal: Digital Control
//      snd_hda i2cWrite      i2c address 0xd8 i2c            reg 0x0244 i2c data 0x0044   reg anal: Digital Control         : I2S format, Undocumented
//      snd_hda i2cRead       i2c address 0xd8 i2c            reg 0x0300 i2c data 0x0380   reg anal: Volume Control
//      snd_hda i2cWrite      i2c address 0xd8 i2c            reg 0x0380 i2c data 0x0080   reg anal: Volume Control          : Fade, Not Muted??
//      snd_hda i2cRead       i2c address 0xd8 i2c            reg 0x0600 i2c data 0x0651   reg anal: Analog Control
//      snd_hda i2cWrite      i2c address 0xd8 i2c            reg 0x0655 i2c data 0x0055   reg anal: Analog Control          : PWM Rate x16, Gain 22.6dB
//      snd_hda i2cRead       i2c address 0xd8 i2c            reg 0x0800 i2c data 0x0808   reg anal: Fault Config & Error
//      snd_hda i2cWrite      i2c address 0xd8 i2c            reg 0x0818 i2c data 0x0018   reg anal: Fault Config & Error    : Threshold 75%, Clock Error??
//      snd_hda i2cWrite      i2c address 0xd8 i2c            reg 0x04cf i2c data 0x00cf   reg anal: Left Chan Vol Control   : 0dB
//      snd_hda i2cRead       i2c address 0xd8 i2c            reg 0x1300 i2c data 0x1300   reg anal: Undocumented
//      snd_hda i2cWrite      i2c address 0xd8 i2c            reg 0x1300 i2c data 0x0000   reg anal: Undocumented
//      snd_hda i2cRead       i2c address 0xd8 i2c            reg 0x0200 i2c data 0x0244   reg anal: Digital Control
//      snd_hda i2cWrite      i2c address 0xd8 i2c            reg 0x0244 i2c data 0x0044   reg anal: Digital Control         : I2S format, Undocumented

        cs_8409_vendor_i2cRead(codec, 0xd8, 0x0002, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xd8, 0x0002, 0x0044, 0); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0xd8, 0x0003, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xd8, 0x0003, 0x0080, 0); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0xd8, 0x0006, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xd8, 0x0006, 0x0055, 0); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0xd8, 0x0008, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xd8, 0x0008, 0x0018, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xd8, 0x0004, 0x00cf, 0); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0xd8, 0x0013, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xd8, 0x0013, 0x0000, 0); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0xd8, 0x0002, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xd8, 0x0002, 0x0044, 0); // snd_hda


//      snd_hda i2cRead       i2c address 0xd8 i2c            reg 0x0100 i2c data 0x01fc   reg anal: Power Control
//      snd_hda i2cWrite      i2c address 0xd8 i2c            reg 0x01fd i2c data 0x00fd   reg anal: Power Control           : Not sleep, Spkr Amp On

        if (amp_enable)
        {
                cs_8409_vendor_i2cRead(codec, 0xd8, 0x0001, 0); // snd_hda
                cs_8409_vendor_i2cWrite(codec, 0xd8, 0x0001, 0x00fd, 0); // snd_hda
        }

}

static void cs_8409_setup_amp_tas576_amp1(struct hda_codec *codec, int amp_volume, int amp_enable)
{
        //int retval;

//      snd_hda i2cRead       i2c address 0xda i2c            reg 0x0200 i2c data 0x0204   reg anal: Digital Control
//      snd_hda i2cWrite      i2c address 0xda i2c            reg 0x0244 i2c data 0x0044   reg anal: Digital Control         : I2S format, Undocumented
//      snd_hda i2cRead       i2c address 0xda i2c            reg 0x0300 i2c data 0x0380   reg anal: Volume Control
//      snd_hda i2cWrite      i2c address 0xda i2c            reg 0x0380 i2c data 0x0081   reg anal: Volume Control          : Fade, Left Muted??
//      snd_hda i2cRead       i2c address 0xda i2c            reg 0x0600 i2c data 0x0651   reg anal: Analog Control
//      snd_hda i2cWrite      i2c address 0xda i2c            reg 0x0655 i2c data 0x0055   reg anal: Analog Control          : PWM Rate x16, Gain 22.6dB
//      snd_hda i2cRead       i2c address 0xda i2c            reg 0x0800 i2c data 0x0808   reg anal: Fault Config & Error
//      snd_hda i2cWrite      i2c address 0xda i2c            reg 0x0818 i2c data 0x0018   reg anal: Fault Config & Error    : Threshold 75%, Clock Error??
//      snd_hda i2cWrite      i2c address 0xda i2c            reg 0x04cf i2c data 0x00cf   reg anal: Left Chan Vol Control   : 0dB
//      snd_hda i2cRead       i2c address 0xda i2c            reg 0x1300 i2c data 0x1300   reg anal: Undocumented
//      snd_hda i2cWrite      i2c address 0xda i2c            reg 0x1300 i2c data 0x0000   reg anal: Undocumented
//      snd_hda i2cRead       i2c address 0xda i2c            reg 0x0200 i2c data 0x0244   reg anal: Digital Control
//      snd_hda i2cWrite      i2c address 0xda i2c            reg 0x0244 i2c data 0x0044   reg anal: Digital Control         : I2S format, Undocumented

        cs_8409_vendor_i2cRead(codec, 0xda, 0x0002, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xda, 0x0002, 0x0044, 0); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0xda, 0x0003, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xda, 0x0003, 0x0081, 0); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0xda, 0x0006, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xda, 0x0006, 0x0055, 0); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0xda, 0x0008, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xda, 0x0008, 0x0018, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xda, 0x0004, 0x00cf, 0); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0xda, 0x0013, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xda, 0x0013, 0x0000, 0); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0xda, 0x0002, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xda, 0x0002, 0x0044, 0); // snd_hda

//      snd_hda i2cRead       i2c address 0xda i2c            reg 0x0100 i2c data 0x01fc   reg anal: Power Control
//      snd_hda i2cWrite      i2c address 0xda i2c            reg 0x01fd i2c data 0x00fd   reg anal: Power Control           : Not sleep, Spkr Amp On

        if (amp_enable)
        {
                cs_8409_vendor_i2cRead(codec, 0xda, 0x0001, 0); // snd_hda
                cs_8409_vendor_i2cWrite(codec, 0xda, 0x0001, 0x00fd, 0); // snd_hda
        }

}

static void cs_8409_setup_amp_tas576_amp2(struct hda_codec *codec, int amp_volume, int amp_enable)
{
        //int retval;

//      snd_hda i2cRead       i2c address 0xdc i2c            reg 0x0200 i2c data 0x0204   reg anal: Digital Control
//      snd_hda i2cWrite      i2c address 0xdc i2c            reg 0x0244 i2c data 0x0044   reg anal: Digital Control         : I2S format, Undocumented
//      snd_hda i2cRead       i2c address 0xdc i2c            reg 0x0300 i2c data 0x0380   reg anal: Volume Control
//      snd_hda i2cWrite      i2c address 0xdc i2c            reg 0x0380 i2c data 0x0082   reg anal: Volume Control          : Fade, Right Muted??
//      snd_hda i2cRead       i2c address 0xdc i2c            reg 0x0600 i2c data 0x0651   reg anal: Analog Control
//      snd_hda i2cWrite      i2c address 0xdc i2c            reg 0x0655 i2c data 0x0055   reg anal: Analog Control          : PWM Rate x16, Gain 22.6dB
//      snd_hda i2cRead       i2c address 0xdc i2c            reg 0x0800 i2c data 0x0808   reg anal: Fault Config & Error
//      snd_hda i2cWrite      i2c address 0xdc i2c            reg 0x0818 i2c data 0x0018   reg anal: Fault Config & Error    : Threshold 75%, Clock Error??
//      snd_hda i2cWrite      i2c address 0xdc i2c            reg 0x04cf i2c data 0x00cf   reg anal: Left Chan Vol Control   : 0dB
//      snd_hda i2cRead       i2c address 0xdc i2c            reg 0x1300 i2c data 0x1300   reg anal: Undocumented
//      snd_hda i2cWrite      i2c address 0xdc i2c            reg 0x1300 i2c data 0x0000   reg anal: Undocumented
//      snd_hda i2cRead       i2c address 0xdc i2c            reg 0x0200 i2c data 0x0244   reg anal: Digital Control
//      snd_hda i2cWrite      i2c address 0xdc i2c            reg 0x0244 i2c data 0x0044   reg anal: Digital Control         : I2S format, Undocumented

        cs_8409_vendor_i2cRead(codec, 0xdc, 0x0002, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xdc, 0x0002, 0x0044, 0); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0xdc, 0x0003, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xdc, 0x0003, 0x0082, 0); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0xdc, 0x0006, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xdc, 0x0006, 0x0055, 0); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0xdc, 0x0008, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xdc, 0x0008, 0x0018, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xdc, 0x0004, 0x00cf, 0); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0xdc, 0x0013, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xdc, 0x0013, 0x0000, 0); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0xdc, 0x0002, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xdc, 0x0002, 0x0044, 0); // snd_hda

//      snd_hda i2cRead       i2c address 0xdc i2c            reg 0x0100 i2c data 0x01fc   reg anal: Power Control
//      snd_hda i2cWrite      i2c address 0xdc i2c            reg 0x01fd i2c data 0x00fd   reg anal: Power Control           : Not sleep, Spkr Amp On

        if (amp_enable)
        {
                cs_8409_vendor_i2cRead(codec, 0xdc, 0x0001, 0); // snd_hda
                cs_8409_vendor_i2cWrite(codec, 0xdc, 0x0001, 0x00fd, 0); // snd_hda
        }

}

static void cs_8409_setup_amp_tas576_amp3(struct hda_codec *codec, int amp_volume, int amp_enable)
{
        //int retval;

//      snd_hda i2cRead       i2c address 0xde i2c            reg 0x0200 i2c data 0x0204   reg anal: Digital Control
//      snd_hda i2cWrite      i2c address 0xde i2c            reg 0x0244 i2c data 0x0044   reg anal: Digital Control         : I2S format, Undocumented
//      snd_hda i2cRead       i2c address 0xde i2c            reg 0x0300 i2c data 0x0380   reg anal: Volume Control
//      snd_hda i2cWrite      i2c address 0xde i2c            reg 0x0380 i2c data 0x0083   reg anal: Volume Control          : Fade, Left and Right Muted??
//      snd_hda i2cRead       i2c address 0xde i2c            reg 0x0600 i2c data 0x0651   reg anal: Analog Control
//      snd_hda i2cWrite      i2c address 0xde i2c            reg 0x0655 i2c data 0x0055   reg anal: Analog Control          : PWM Rate x16, Gain 22.6dB
//      snd_hda i2cRead       i2c address 0xde i2c            reg 0x0800 i2c data 0x0808   reg anal: Fault Config & Error
//      snd_hda i2cWrite      i2c address 0xde i2c            reg 0x0818 i2c data 0x0018   reg anal: Fault Config & Error    : Threshold 75%, Clock Error??
//      snd_hda i2cWrite      i2c address 0xde i2c            reg 0x04cf i2c data 0x00cf   reg anal: Left Chan Vol Control   : 0dB
//      snd_hda i2cRead       i2c address 0xde i2c            reg 0x1300 i2c data 0x1300   reg anal: Undocumented
//      snd_hda i2cWrite      i2c address 0xde i2c            reg 0x1300 i2c data 0x0000   reg anal: Undocumented
//      snd_hda i2cRead       i2c address 0xde i2c            reg 0x0200 i2c data 0x0244   reg anal: Digital Control
//      snd_hda i2cWrite      i2c address 0xde i2c            reg 0x0244 i2c data 0x0044   reg anal: Digital Control         : I2S format, Undocumented

        cs_8409_vendor_i2cRead(codec, 0xde, 0x0002, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xde, 0x0002, 0x0044, 0); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0xde, 0x0003, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xde, 0x0003, 0x0083, 0); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0xde, 0x0006, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xde, 0x0006, 0x0055, 0); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0xde, 0x0008, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xde, 0x0008, 0x0018, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xde, 0x0004, 0x00cf, 0); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0xde, 0x0013, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xde, 0x0013, 0x0000, 0); // snd_hda
        cs_8409_vendor_i2cRead(codec, 0xde, 0x0002, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xde, 0x0002, 0x0044, 0); // snd_hda

//      snd_hda i2cRead       i2c address 0xde i2c            reg 0x0100 i2c data 0x01fc   reg anal: Power Control
//      snd_hda i2cWrite      i2c address 0xde i2c            reg 0x01fd i2c data 0x00fd   reg anal: Power Control           : Not sleep, Spkr Amp On

        if (amp_enable)
        {
                cs_8409_vendor_i2cRead(codec, 0xde, 0x0001, 0); // snd_hda
                cs_8409_vendor_i2cWrite(codec, 0xde, 0x0001, 0x00fd, 0); // snd_hda
        }

}


static void cs_8409_sync_converters_off(struct hda_codec *codec, int nullformat)
{
        int retval;

        struct hda_cvt_setup p2;
        struct hda_cvt_setup p3;

        // this stops streaming on nodes 0x2 and 0x3 by switching to stream index 0
        // then updates vendor node coef index 0x0017 twice
        // first with 0x2 for node 0x1 and then with 0x0 for node 0x2
        // giving a final 0x0
        // then sets up ready for streaming again

        // so coef index 0x17 is likely turning off the TDM stream

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301

        // remove normal channel mapping

//      snd_hda: # AppleHDAFunctionGroupCS8409::syncConverters:
        //retval = snd_hda_codec_read_check(codec, 0x02, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000010, 4); // 0x002f0600
        //retval = snd_hda_codec_read(codec, 0x02, 0, AC_VERB_GET_CONV, 0x00000000); // 0x002f0600
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 1)]

        //snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00270600
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]

        cs_8409_save_and_clear_stream_format(codec, 0x02, &p2);

        snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0002, 0xffff, 0x00000003, 0, 0 ); // coef write mask 6

//      snd_hda: # AppleHDAFunctionGroupCS8409::syncConverters:
        //retval = snd_hda_codec_read_check(codec, 0x03, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000012, 12); // 0x003f0600
        //retval = snd_hda_codec_read(codec, 0x03, 0, AC_VERB_GET_CONV, 0x00000000); // 0x003f0600
//      snd_hda:     conv stream channel map 3 [('CHAN', 2), ('STREAMID', 1)]

        //snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00370600
//      snd_hda:     conv stream channel map 3 [('CHAN', 0), ('STREAMID', 0)]

        cs_8409_save_and_clear_stream_format(codec, 0x03, &p3);

        snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0000, 0xffff, 0x00000002, 0, 0 ); // coef write mask 14

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0017, 0x0000, 0x00000000, 0 ); //   coef read 20
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0018, 0x0000, 0x00000000, 0 ); //   coef read 24

        snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0001, 0x0220, 0xffff, 0x00000220, 0, 0 ); // coef write mask 28

        // and reset back to normal channel mapping

        //snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000010); // 0x00270610
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 1)]

        //snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000012); // 0x00370612
//      snd_hda:     conv stream channel map 3 [('CHAN', 2), ('STREAMID', 1)]

        if (nullformat)
        {
                snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00270600
                snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00370602
        }
        else
        {
               cs_8409_update_from_save_stream_format(codec, 0x02, &p2, 1, 0);
               cs_8409_update_from_save_stream_format(codec, 0x03, &p3, 1, 0);
        }
}


static void playstop_sync_converters_off(struct hda_codec *codec)
{
        cs_8409_sync_converters_off(codec, 0);
}


static void cs_8409_disable_amp_max(struct hda_codec *codec, int amp_address);

static void cs_8409_disable_amp_ssm3(struct hda_codec *codec, int amp_address);

static void cs_8409_disable_amp_tas576(struct hda_codec *codec, int amp_address);

static void cs_8409_disable_amp_tas576_amp0(struct hda_codec *codec);
static void cs_8409_disable_amp_tas576_amp1(struct hda_codec *codec);
static void cs_8409_disable_amp_tas576_amp2(struct hda_codec *codec);
static void cs_8409_disable_amp_tas576_amp3(struct hda_codec *codec);

static void cs_8409_disable_amps12(struct hda_codec *codec)
{
        if (codec->core.subsystem_id == 0x106b3900) {
                cs_8409_disable_amp_max(codec, 0x64);
                cs_8409_disable_amp_max(codec, 0x62);
        }
        else if (codec->core.subsystem_id == 0x106b3300 || codec->core.subsystem_id == 0x106b3600) {
                //setup_node_alpha_ssm3(codec);
                cs_8409_disable_amp_ssm3(codec, 0x28);
                cs_8409_disable_amp_ssm3(codec, 0x2a);
        }
        else if (codec->core.subsystem_id == 0x106b1000) {
                //cs_8409_disable_amp_tas576(codec, 0xd8);
                //cs_8409_disable_amp_tas576(codec, 0xda);
                cs_8409_disable_amp_tas576_amp0(codec);
                cs_8409_disable_amp_tas576_amp1(codec);
        }
        else {
                dev_info(hda_codec_dev(codec), "UNKNOWN subsystem id 0x%08x",codec->core.subsystem_id);
        }
}

static void playstop_disable_amps12(struct hda_codec *codec)
{
        cs_8409_disable_amps12(codec);
}

static void cs_8409_disable_TDM_proper_amps12(struct hda_codec *codec)
{
        //int retval;
        int ret_coef71 = 0;
        int new_coef71 = 0;

        // this seems to be setup for node 0x02 chain - which seems to use node 0x24 and amps 0x64 and 0x62 (or 0x28 and 0x2a)

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR:
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00000800, 0 ); //   coef read 341
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0019, 0x8800, 0x00000000, 0 ); //   coef write 345
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001a, 0x0000, 0x00000820, 0 ); //   coef read 349
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001a, 0x8820, 0x00000000, 0 ); //   coef write 353

        //      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: AppleHDATDMBusManagerCS8409::tdmInUse:
        //snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00008800, 357 ); //   coef read 357
        //snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001a, 0x0000, 0x00008820, 361 ); //   coef read 361
        //snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001b, 0x0000, 0x00000840, 365 ); //   coef read 365

        tdm_in_use(codec, 30);

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR:
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006b, 0x001f, 0x00000000, 0 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 370

        ret_coef71 = snd_hda_coef_item_check(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x0000400f, 0 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef read 374

        new_coef71 = (ret_coef71 & 0xffff);
        myprintk_dbg("snd_hda_intel: masked cs_8409_disable_TDM_proper_amps12 coef 0x71 update 0x%04x 0x%04x \n", ret_coef71, new_coef71);

        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x400f, 0x00000000, 378 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 378
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, new_coef71, 0x00000000, 0 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 378

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00b6 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  write verb 381
}


static void cs_8409_disable_TDM_amps12(struct hda_codec *codec)
{
        int retval;

        cs_8409_disable_TDM_proper_amps12(codec);


        // set to defaults and disable output
        // note here we really reset to 0 format in addition to stream id 0/channel id 0

        // note this means the cached stream data in the hda_cvt_setup struct will now be inconsistent
        // we need to ensure any further stream format re-update MUST be a forced update
        // still not clear if should be calling eg __snd_hda_codec_cleanup_stream

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00270600
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_STREAM_FORMAT, 0x00000000); // 0x00220000
//      snd_hda:     stream format 2 [('CHAN', 1), ('RATE', 48000), ('BITS', 8), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        //retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000040, 387); // 0x024f0700
        retval = snd_hda_codec_read(codec, 0x24, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000); // 0x024f0700
        snd_hda_codec_write(codec, 0x24, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x02470700
//      snd_hda:     36 []

}

static void playstop_disable_TDM_amps12(struct hda_codec *codec)
{
        cs_8409_disable_TDM_amps12(codec);
}

static void cs_8409_disable_amps34(struct hda_codec *codec)
{
        if (codec->core.subsystem_id == 0x106b3900) {
                cs_8409_disable_amp_max(codec, 0x74);
                cs_8409_disable_amp_max(codec, 0x72);
        }
        else if (codec->core.subsystem_id == 0x106b3300 || codec->core.subsystem_id == 0x106b3600) {
                //setup_node_alpha_ssm3(codec);
                cs_8409_disable_amp_ssm3(codec, 0x2c);
                cs_8409_disable_amp_ssm3(codec, 0x2e);
        }
        else if (codec->core.subsystem_id == 0x106b1000) {
                //cs_8409_disable_amp_tas576(codec, 0xdc);
                //cs_8409_disable_amp_tas576(codec, 0xde);
                cs_8409_disable_amp_tas576_amp2(codec);
                cs_8409_disable_amp_tas576_amp3(codec);
        }
        else {
                dev_info(hda_codec_dev(codec), "UNKNOWN subsystem id 0x%08x",codec->core.subsystem_id);
        }
}

static void playstop_disable_amps34(struct hda_codec *codec)
{
        cs_8409_disable_amps34(codec);
}


static void cs_8409_disable_TDM_proper_amps34(struct hda_codec *codec)
{
        //int retval;
        int ret_coef1 = 0;
        int new_coef1 = 0;

        // AppleHDATDMBusManagerCS8409::disableTDMPath
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001b, 0x0000, 0x00000840, 0 ); //   coef read 694
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001b, 0x8840, 0x00000000, 0 ); //   coef write 698
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001c, 0x0000, 0x00000860, 0 ); //   coef read 702
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001c, 0x8860, 0x00000000, 0 ); //   coef write 706

        // AppleHDATDMBusManagerCS8409::disableTDMPath
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0082, 0x0001, 0xffff, 0x00005401, 0, 710 ); // coef write mask 710
        snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0082, 0x0000, 0x5400, 0x00005401, 0x0001, 0 ); // coef write mask 710

        // AppleHDATDMBusManagerCS8409::disableTDMPath
        ret_coef1 = snd_hda_coef_item_check(codec, 0, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000220, 0 ); //   coef read 716

        new_coef1 = (ret_coef1 & 0xffdf); // clear out 0x20 bit
        myprintk_dbg("snd_hda_intel: masked cs_8409_disable_TDM_proper_amps34 coef 0x01 update 0x%04x 0x%04x \n", ret_coef1, new_coef1);

        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, 0x0200, 0x00000000, 720 ); //   coef write 720
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, new_coef1, 0x00000000, 0 ); //   coef write 720

        // AppleHDATDMBusManagerCS8409::setupTDMPath or disableTDMPath calls AppleHDATDMBusManagerCS8409::configureTDMUR
        // AppleHDATDMBusManagerCS8409::configureTDMUR only place calls this
        // this is AppleHDATDMBusManagerCS8409::tdmInUse
        // which reads from 0x19 to 0x57 in a loop if the snd_hda_coef_item returns 0 till the read value
        // does not have the word sign bit set (ie 0x8000) or finish all 0x57

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: AppleHDATDMBusManagerCS8409::tdmInUse:
        //snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00008800, 724 ); //   coef read 724
        //snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001a, 0x0000, 0x00008820, 728 ); //   coef read 728
        // ....
        //snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0056, 0x0000, 0x00008000, 968 ); //   coef read 968
        //snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0057, 0x0000, 0x00008000, 972 ); //   coef read 972

        tdm_in_use(codec, 40);


        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x00000000, 0 ); //   coef write 977

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00000000);

}

static void cs_8409_disable_TDM_amps34(struct hda_codec *codec)
{
        int retval;

        cs_8409_disable_TDM_proper_amps34(codec);


        // set to defaults and disable output
        // note here we really reset to 0 format in addition to stream id 0/channel id 0

        // note this means the cached stream data in the hda_cvt_setup struct will now be inconsistent
        // we need to ensure any further stream format re-update MUST be a forced update
        // still not clear if should be calling eg __snd_hda_codec_cleanup_stream

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00370600
//      snd_hda:     conv stream channel map 3 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_STREAM_FORMAT, 0x00000000); // 0x00320000
//      snd_hda:     stream format 3 [('CHAN', 1), ('RATE', 48000), ('BITS', 8), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        //retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000040, 986); // 0x025f0700
        retval = snd_hda_codec_read(codec, 0x25, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000); // 0x025f0700
        snd_hda_codec_write(codec, 0x25, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x02570700
//      snd_hda:     37 []

}

static void playstop_disable_TDM_amps34(struct hda_codec *codec)
{
        cs_8409_disable_TDM_amps34(codec);
}


static void cs_8409_disable_amp_max(struct hda_codec *codec, int amp_address)
{
        //int retval;

        // interrupt read/state read new as of June 2019

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x64 i2c            reg 0x5000 i2c data 0x0000   reg anal: GlobalEnable            : Disable
//      snd_hda i2cRead       i2c address 0x64 i2c            reg 0x0300 i2c data 0x0300   reg anal: InterruptState0
//      snd_hda i2cRead       i2c address 0x64 i2c            reg 0x0400 i2c data 0x0400   reg anal: InterruptState1
//      snd_hda i2cRead       i2c address 0x64 i2c            reg 0x0c00 i2c data 0x0c00   reg anal: State1

        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0050, 0x0000, 0); // snd_hda
        cs_8409_vendor_i2cRead(codec, amp_address, 0x0003, 0); // snd_hda
        cs_8409_vendor_i2cRead(codec, amp_address, 0x0004, 0); // snd_hda
        cs_8409_vendor_i2cRead(codec, amp_address, 0x000c, 0); // snd_hda

}


static void cs_8409_disable_amp_ssm3(struct hda_codec *codec, int amp_address)
{
        //int retval;

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2c i2c            reg 0x0001 i2c data 0x0001   reg anal: PowerControl            : PowerDown BVSenseOn

        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0000, 0x0001, 1); // snd_hda

}

static void cs_8409_disable_amp_tas576(struct hda_codec *codec, int amp_address)
{
        //int retval;

//      snd_hda: # i2cWrite: 
//      snd_hda i2cRead       i2c address 0xd8 i2c            reg 0x0100 i2c data 0x01fc   reg anal: Power Control
//      snd_hda i2cWrite      i2c address 0xd8 i2c            reg 0x01fc i2c data 0x00fc   reg anal: Power Control           : Not sleep, Spkr Amp Shutdown

        cs_8409_vendor_i2cRead(codec, amp_address, 0x0001, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0001, 0x00fc, 0); // snd_hda

}

static void cs_8409_disable_amp_tas576_amp0(struct hda_codec *codec)
{
        //int retval;

//      snd_hda: # i2cWrite: 
//      snd_hda i2cRead       i2c address 0xd8 i2c            reg 0x0100 i2c data 0x01fc   reg anal: Power Control
//      snd_hda i2cWrite      i2c address 0xd8 i2c            reg 0x01fc i2c data 0x00fc   reg anal: Power Control           : Not sleep, Spkr Amp Shutdown

        cs_8409_vendor_i2cRead(codec, 0xd8, 0x0001, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xd8, 0x0001, 0x00fc, 0); // snd_hda

}

static void cs_8409_disable_amp_tas576_amp1(struct hda_codec *codec)
{
        //int retval;

//      snd_hda: # i2cWrite: 
//      snd_hda i2cRead       i2c address 0xda i2c            reg 0x0100 i2c data 0x01fc   reg anal: Power Control
//      snd_hda i2cWrite      i2c address 0xda i2c            reg 0x01fc i2c data 0x00fc   reg anal: Power Control           : Not sleep, Spkr Amp Shutdown

        cs_8409_vendor_i2cRead(codec, 0xda, 0x0001, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xda, 0x0001, 0x00fc, 0); // snd_hda

}

static void cs_8409_disable_amp_tas576_amp2(struct hda_codec *codec)
{
        //int retval;

//      snd_hda: # i2cWrite: 
//      snd_hda i2cRead       i2c address 0xdc i2c            reg 0x0100 i2c data 0x01fc   reg anal: Power Control
//      snd_hda i2cWrite      i2c address 0xdc i2c            reg 0x01fc i2c data 0x00fc   reg anal: Power Control           : Not sleep, Spkr Amp Shutdown

        cs_8409_vendor_i2cRead(codec, 0xdc, 0x0001, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xdc, 0x0001, 0x00fc, 0); // snd_hda

}

static void cs_8409_disable_amp_tas576_amp3(struct hda_codec *codec)
{
        //int retval;

//      snd_hda: # i2cWrite: 
//      snd_hda i2cRead       i2c address 0xde i2c            reg 0x0100 i2c data 0x01fc   reg anal: Power Control
//      snd_hda i2cWrite      i2c address 0xde i2c            reg 0x01fc i2c data 0x00fc   reg anal: Power Control           : Not sleep, Spkr Amp Shutdown

        cs_8409_vendor_i2cRead(codec, 0xde, 0x0001, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, 0xde, 0x0001, 0x00fc, 0); // snd_hda

}



static void playstop_disable_amp_max(struct hda_codec *codec, int amp_address)
{
        cs_8409_disable_amp_max(codec, amp_address);
}


static void cs_8409_inputs_power_nids_on(struct hda_codec *codec)
{
        int retval;

        struct cs_spec *spec = codec->spec;

        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 2785); // 0x022f0500
        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 2786); // 0x023f0500

        hda_set_node_power_state(codec, spec->intmike_adc_nid, AC_PWRST_D0);
        hda_set_node_power_state(codec, spec->linein_amp_nid, AC_PWRST_D0);

}

static void cs_8409_inputs_power_nids_off(struct hda_codec *codec)
{
        int retval;

        struct cs_spec *spec = codec->spec;

        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 10741); // 0x022f0500
        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 10742); // 0x023f0500

        hda_set_node_power_state(codec, spec->intmike_adc_nid, AC_PWRST_D3);
        hda_set_node_power_state(codec, spec->linein_amp_nid, AC_PWRST_D3);

}

static void cs_8409_plugin_handle_detect(struct hda_codec *codec);

static void cs_8409_headset_amp_format_setup_disable(struct hda_codec *codec, int full);

static void cs43l83_headset_amp_format_setup(struct hda_codec *codec, int set_stream_id, int full);

static void cs_8409_perform_external_device_unsolicited_responses(struct hda_codec *codec);

static void cs_8409_plugin_complete_detect(struct hda_codec *codec);

static void cs42l83_headset_play_setup_on(struct hda_codec *codec);

static void cs42l83_headset_mike_format_setup_enable(struct hda_codec *codec, int nullformat, int full);

static void cs_8409_headset_mike_buttons_enable(struct hda_codec *codec);


static int cs_8409_boot_setup_real(struct hda_codec *codec)
{
        int headset_on_boot = 0, retval;

        struct cs_spec *spec = codec->spec;

        //hda_nid_t beep_nid = spec->beep_nid;

        mycodec_info(codec, "command cs_8409_boot_setup_real start\n");


        setup_reset_and_clear(codec);

        // read parameters from all nodes - excluding VirtualWidgets

        // the loop over node counts calls AppleHDAWidgetFactory::createAppleHDAWidget(DevIdStruct*)
        // which Im assuming calls the initForNodeID functions

        init_read_all_nodes(codec);

        read_vendor_node(codec);


        init_read_coefs(codec);


        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301

        read_virtual_widgets(codec);

        init_for_node_vendor(codec);

        // this is determineSpeakerID
        // this does not make sense - this just checks GPIO pin(s)??

        determine_speaker_id(codec);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);


        // why is this commented??
        //setup_jack_pin_config(codec);

        enable_i2c(codec);

        if (codec->core.subsystem_id == 0x106b3900) {
                enable_GPIforUR(codec, 0x5);
        }
        else if (codec->core.subsystem_id == 0x106b3300 || codec->core.subsystem_id == 0x106b3600) {
                enable_GPIforUR(codec, 0xd);
        }
        else if (codec->core.subsystem_id == 0x106b1000) {
                enable_GPIforUR(codec, 0xd);
        }
        else {
                dev_info(hda_codec_dev(codec), "UNKNOWN subsystem id 0x%08x",codec->core.subsystem_id);
        }


        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301


        if (codec->core.subsystem_id == 0x106b3900) {
                cs42l83_external_control_GPIO(codec, 0x7);
        }
        else if (codec->core.subsystem_id == 0x106b3300 || codec->core.subsystem_id == 0x106b3600) {
                cs42l83_external_control_GPIO(codec, 0xf);
        }
        else if (codec->core.subsystem_id == 0x106b1000) {
                cs42l83_external_control_GPIO(codec, 0xf);
        }
        else {
                dev_info(hda_codec_dev(codec), "UNKNOWN subsystem id 0x%08x",codec->core.subsystem_id);
        }

        // we have confirmed that the disabling all the cs42l83 setup does not affect the amps

        cs42l83_reset(codec);

        //cs42l83_external_control_GPIO2_clear_2(codec);
        //cs42l83_external_control_GPIO2_set_2(codec);

        if (codec->core.subsystem_id == 0x106b3900) {
                cs42l83_external_control_GPIO(codec, 0x7);
        }
        else if (codec->core.subsystem_id == 0x106b3300 || codec->core.subsystem_id == 0x106b3600) {
                cs42l83_external_control_GPIO(codec, 0xf);
        }
        else if (codec->core.subsystem_id == 0x106b1000) {
                cs42l83_external_control_GPIO(codec, 0xf);
        }
        else {
                dev_info(hda_codec_dev(codec), "UNKNOWN subsystem id 0x%08x",codec->core.subsystem_id);
        }

        cs42l83_device_id(codec);

        cs42l83_inithw(codec);


        if (codec->core.subsystem_id == 0x106b3900) {
                //setup_amps_reset(codec);
                setup_amps_reset_i2c_max(codec);
        }
        else if (codec->core.subsystem_id == 0x106b3300 || codec->core.subsystem_id == 0x106b3600) {
                //setup_amps_reset_i2c_ssm3
                setup_amps_reset_i2c_ssm3(codec);
        }
        else if (codec->core.subsystem_id == 0x106b1000) {
                //setup_amps_reset(codec);
                setup_amps_reset_i2c_tas576(codec);
        }
        else {
                dev_info(hda_codec_dev(codec), "UNKNOWN subsystem id 0x%08x",codec->core.subsystem_id);
        }


        //read_gpio_status(codec);

        retval = read_gpio_status_check(codec);


        cs42l83_mic_detect(codec);

        // apparently the imacs use an inverted circuit for physical sensing of jack being plugged in
        if (codec->core.subsystem_id == 0x106b1000)
                cs42l83_tip_sense(codec, 1);
        else
                cs42l83_tip_sense(codec, 0);

        cs42l83_plugin_interrupt_setup(codec);


        // should check here if have headphones plugged in
        // likely additional code here if we did boot with headphones plugged in
        //cs42l83_headphone_sense_data(codec);
        retval = cs42l83_headphone_sense(codec);
        mycodec_info(codec, "cs_8409_boot_setup_real headphone sense 0x%x\n", retval);

        if ((retval & 0x80))
        {
                dev_info(hda_codec_dev(codec), "cs_8409_boot_setup_real headphone already plugged in!!\n");
                // store for after init
                headset_on_boot = 1;
        }


        //setup_intmike_nid(codec);
        //cs_8409_intmike_format_setup_format(codec);
        cs_8409_intmike_format_setup_enable(codec, 0x4031, 1);
        cs_8409_intmike_volume_setup(codec, 0x27);
        cs_8409_intmike_stream_on_nid(codec);

        //setup_intmike_format_resetup(codec);
        //cs_8409_intmike_format_setup_format_nouse(codec);
        //cs_8409_really_update_stream_format(codec, 0x22, 1, 0, 0);
        cs_8409_really_update_stream_format(codec, spec->intmike_adc_nid, 1, 0, 0);

        //setup_linein_nid(codec);
        cs_8409_linein_volume_setup(codec, 0x27);
        cs_8409_linein_format_setup_disable(codec);

        //setup_intmike_stream_conn_off_nid(codec);
        cs_8409_intmike_stream_conn_off(codec);

        //setup_linein_stream_conn_off_nid(codec);
        cs_8409_linein_stream_conn_off(codec);

        //setup_intmike_stream_off_nid(codec);
        cs_8409_intmike_stream_off_nid(codec);

        //setup_linein_stream_off_nid(codec);
        cs_8409_linein_stream_off_nid(codec);

        //setup_intmike_vol1(codec);
        cs_8409_intmike_volume_mute_nouse(codec);

        //setup_linein_vol1(codec);
        cs_8409_linein_volume_mute_nouse(codec);

        //setup_intmike_vol2(codec);
        cs_8409_intmike_volume_unmute_nouse(codec);

        //setup_linein_vol2(codec);
        cs_8409_linein_volume_unmute_nouse(codec);

        if (headset_on_boot)
        {
                // so the big question is what to do about unsolicited responses
                // should we disable them in this boot section
                // and if so when should we re-enable them
                // I suspect at some point the code for headset already plugged in
                // switches to unsolicited response code

                // so I think we need to enable unsol response at this stage and block it till end of this function
                // - because we seem to get an UNSOL response in the middle of this code
                spec->block_unsol = 1;

                // Im guessing the following code should be done explicitly
                // because we have not seen a cs42l83_read_status_and_clear_interrupt/cs42l83_disambiguate_ur_from_int

                // for some reason the stream id is set to 0 here
                cs43l83_headset_amp_format_setup(codec, 0, 0);

                //#2880: cs42l83_configure_int_mclk
                //#3152: cs42l83_power_onoff
                //#3216: cs42l83_configure_serial_port
                //#3376: cs42l83_output_set_input_sample_rate
                //#3504: cs42l83_setup_audio_output
                //#3680: cs42l83_buffers_onoff

                // this is essentially from cs42l83_headset_play_setup_on

                cs42l83_configure_int_mclk(codec);

                //cs42l83_headset_power_on_on_nouse(codec);
                cs42l83_power_onoff(codec, 1);

                cs42l83_configure_serial_port(codec);


                cs42l83_output_set_input_sample_rate(codec);

                cs42l83_setup_audio_output(codec);

                               // headset_setup_SPDIf_output(codec); - presumably if is SPDIF setup

                //cs42l83_headset_rcv_enable_on(codec);
                cs42l83_buffers_onoff(codec, 1);


                // so we seem to get an UNSOL response at this point
                // - Im thinking we need to store this response


                // and now turn off

                //#3698: cs42l83_buffers_onoff
                //#3714: cs42l83_headset_power_off

                cs42l83_buffers_onoff(codec, 0);

                cs42l83_power_onoff(codec, 0);

                cs_8409_headset_amp_format_setup_disable(codec, 1);


                // and back on again
                // we dont set stream id, do full TDM setup and not enable the pin
                // then set stream id, turn on pin but partial TDM setup
                cs43l83_headset_amp_format_setup(codec, 0, 1);
                cs43l83_headset_amp_format_setup(codec, 1, 0);

                //#3920: cs42l83_configure_int_mclk
                //#4192: cs42l83_power_onoff
                //#4256: cs42l83_configure_serial_port
                //#4416: cs42l83_output_set_input_sample_rate
                //#4544: cs42l83_setup_audio_output
                //#4720: cs42l83_buffers_onoff

                // this is essentially from cs42l83_headset_play_setup_on

                cs42l83_configure_int_mclk(codec);

                //cs42l83_headset_power_on_on_nouse(codec);
                cs42l83_power_onoff(codec, 1);

                cs42l83_configure_serial_port(codec);


                cs42l83_output_set_input_sample_rate(codec);

                cs42l83_setup_audio_output(codec);

                               // headset_setup_SPDIf_output(codec); - presumably if is SPDIF setup

                //cs42l83_headset_rcv_enable_on(codec);
                cs42l83_buffers_onoff(codec, 1);


                //#4738: cs42l83_headphone_sense

                // this may be the same as one of the multiple headphone sense calls seen if no headset plugged in

                retval = cs42l83_headphone_sense(codec);
                mycodec_info(codec, "cs_8409_boot_setup_real headphone sense 0x%x\n", retval);

                if ((retval & 0x80))
                {
                        dev_info(hda_codec_dev(codec), "cs_8409_boot_setup_real headphone still plugged in!!\n");

                        cs42l83_buffers_onoff(codec, 0);

                        cs42l83_power_onoff(codec, 0);

                        cs_8409_headset_amp_format_setup_disable(codec, 1);

                        cs_8409_intmike_volume_unmute_nouse(codec);

                        cs_8409_linein_volume_unmute_nouse(codec);

                        cs_8409_intmike_volume_unmute_nouse(codec);

                        cs_8409_linein_volume_unmute_nouse(codec);

                        cs_8409_inputs_power_nids_off(codec);


                        // so I think we need to try performing the unsol responses here
                        // - because we get a call to cs42l83_read_status_and_clear_interrupt/cs42l83_disambiguate_ur_from_int here
                        // well all the evidence is altho these routines are called they dont actually do anything
                        // - the cs_8409_read_status_and_clear_interrupt call does not see a TIP SENSE interrupt
                        // (cf actually plugging in headphones post-boot)
                        // - calling these routines does clear the interrupt - which may be its only function

                        // we need to update headset_phase so we dont ignore headset unsol responses in the following call
                        spec->headset_phase = 1;

                        // I think we need to block here - because clearing the interrupts causes interrupts!!
                        // this is similar to cs_8409_cs42l83_unsolicited_response where we block
                        // before calling the perform function
                        spec->block_unsol = 1;

                        cs_8409_perform_external_device_unsolicited_responses(codec);

                        spec->block_unsol = 0;

                }
                else
                {
                        dev_info(hda_codec_dev(codec), "cs_8409_boot_setup_real boot headphone REMOVED - UNIMPLEMENTED!!\n");
                }


                // so now just going to continue with the logged boot code
                // we get a lot of checks the headset is still plugged in
                // Im assuming if these detect the headset has been removed other things may happen
                // - this would likely be setting up the amps

                retval = cs42l83_headphone_sense(codec);
                mycodec_info(codec, "cs_8409_boot_setup_real headphone sense 0x%x\n", retval);

                if ((retval & 0x80))
                {
                }
                else
                {
                        dev_info(hda_codec_dev(codec), "cs_8409_boot_setup_real boot headphone REMOVED 2 - UNIMPLEMENTED!!\n");
                }

                retval = cs42l83_headphone_sense(codec);
                mycodec_info(codec, "cs_8409_boot_setup_real headphone sense 0x%x\n", retval);

                if ((retval & 0x80))
                {
                        cs_8409_intmike_volume_unmute(codec);

                        cs_8409_linein_volume_unmute(codec);
                }
                else
                {
                        dev_info(hda_codec_dev(codec), "cs_8409_boot_setup_real boot headphone REMOVED 3 - UNIMPLEMENTED!!\n");
                }

                retval = cs42l83_headphone_sense(codec);
                mycodec_info(codec, "cs_8409_boot_setup_real headphone sense 0x%x\n", retval);

                if ((retval & 0x80))
                {
                        //#5328: cs42l83_headset_button_detect_interrupts_off
                        //#5392: cs42l83_headset_set_hpout_clamp_disable

                        // these 2 functions seem to be this function
                        // - additional code is setting jack_present and an msleep
                        cs_8409_plugin_handle_detect(codec);
                }
                else
                {
                        dev_info(hda_codec_dev(codec), "cs_8409_boot_setup_real boot headphone REMOVED 4 - UNIMPLEMENTED!!\n");
                }

                retval = cs42l83_headphone_sense(codec);
                mycodec_info(codec, "cs_8409_boot_setup_real headphone sense 0x%x\n", retval);

                if ((retval & 0x80))
                {
                        // so there are 4 gpio status reads here
                        // why 4??
                        retval = read_gpio_status_check(codec);

                        retval = read_gpio_status_check(codec);

                        retval = read_gpio_status_check(codec);

                        retval = read_gpio_status_check(codec);

                        // why - this just sets nid 0x22 format???
                        cs_8409_intmike_format_setup_format_nouse(codec);
                        //cs_8409_really_update_stream_format(codec, 0x22, 1, 0, 0);

                        //cs_8409_linein_volume_setup_new(codec, 0x27)
                        cs_8409_linein_volume_setup(codec, 0x27);


                        cs_8409_linein_format_setup_disable(codec);

                        cs_8409_intmike_stream_conn_off(codec);

                        cs_8409_linein_stream_conn_off(codec);

                        cs_8409_intmike_stream_off_nid(codec);
                        cs_8409_linein_stream_off_nid(codec);

                        cs_8409_intmike_volume_mute(codec);
                        cs_8409_linein_volume_mute(codec);
                }
                else
                {
                        dev_info(hda_codec_dev(codec), "cs_8409_boot_setup_real boot headphone REMOVED 5 - UNIMPLEMENTED!!\n");
                }

		// we see a delay here - this is I think the equivalent of the 1800 msleep
		// in cs_8409_headset_plugin_event
		// should we just make it 1800??
		msleep(1500); // what we actually see is 1470

                // the cs_8409_plugin_complete_detect function seems to encapsulate what happens next
                // - this functions ends with initiating headset detection
                //#5551: cs42l83_headphone_sense
                //#5567: cs42l83_complete_jack_detect
                //#5631: cs42l83_power_hs_bias_on
                //#5727: cs42l83_enable_hs_auto_int_on
                //#5759: cs42l83_unplug_interrupt_setup
                //#5807: cs42l83_set_hpout_pulldown_off
                //#5839: cs42l83_headset_detect_on

                cs_8409_plugin_complete_detect(codec);

                spec->block_unsol = 1;

                // testing status checks to see if we get an interrupt
                // so at this point the status is still 0x27 - no interrupt
                // can we just use the msleep??
                retval = read_gpio_status_check(codec);

                msleep(1);

                // but here the status is 0x26 ie interrupt
                //retval = read_gpio_status_check(codec);

                // I think we need to block here - because clearing the interrupts causes interrupts!!
                // this is similar to cs_8409_cs42l83_unsolicited_response where we block
                // before calling the perform function

                // so next we should get some unsol responses
                //#5923: cs42l83_read_status_and_clear_interrupt
                //#6117: cs42l83_disambiguate_ur_from_int
                //#6165:  cs_8409_headset_type_detect_event
                //#6165: cs42l83_enable_hs_auto_int_off
                //#6197: cs42l83_headset_type
                //#6213: cs42l83_unplug_headset_detect_off
                //#6277: cs42l83_set_hpout_pulldown_onoff
                //#6309: cs42l83_set_hpout_clamp_enable
                //#6341: cs42l83_enable_hsbias_auto_clamp_on
                //#6373: cs42l83_enable_hsbias_auto_clamp_off
                //#6421: cs42l83_power_hs_bias_off
                //#6517: cs42l83_setup_button_detect
                //#6709: cs42l83_power_hs_bias_button_on
                //#6805: cs42l83_enable_hsbias_auto_clamp_off1

                cs_8409_perform_external_device_unsolicited_responses(codec);


                retval = read_gpio_status_check(codec);

                // so the delay here seems to be around 130 ms
                // with delay of 1 ms dont see any interrupts
                msleep(130);

                retval = read_gpio_status_check(codec);


                //#6857: cs42l83_read_status_and_clear_interrupt
                //#7051: cs42l83_disambiguate_ur_from_int
                // cs_8409_headset_button_detect_event
                //#7099: cs42l83_handle_button_detect
                //#7243: cs42l83_mike_connected

                // cs_8409_perform_external_device_unsolicited_responses then calls cs_8409_plugin_event_continued
                // - but here we have a divergence from plugin post-boot
                // fixed up cs_8409_plugin_event_continued to only do things for plugin post-boot
                // - at boot we drop back to here
                // NOTA BENE - MUST set up the button interrupts here now - otherwise buttons wont work

                cs_8409_perform_external_device_unsolicited_responses(codec);


                //#7553:  cs_8409_enable_headset_streaming
                //#7553: cs43l83_headset_amp_format_setup
                //#7417:  cs42l83_headset_play_setup_on
                //#7417: cs42l83_configure_int_mclk
                //#7689: cs42l83_power_onoff
                //#7753: cs42l83_configure_serial_port
                //#7913: cs42l83_output_set_input_sample_rate
                //#8041: cs42l83_setup_audio_output
                //#8217: cs42l83_buffers_onoff

                cs43l83_headset_amp_format_setup(codec, 1, 1);
                cs42l83_headset_play_setup_on(codec);

                // and yet again turn off
                //#8233: cs42l83_buffers_onoff
                //#8249: cs42l83_power_onoff
                //#8279: cs_8409_headset_amp_format_setup_disable

                cs42l83_buffers_onoff(codec, 0);
                cs42l83_power_onoff(codec, 0);
                cs_8409_headset_amp_format_setup_disable(codec, 1);


                // and back on again
                // we dont set stream id, do full TDM setup and not enable the pin
                // then set stream id, turn on pin but partial TDM setup
                cs43l83_headset_amp_format_setup(codec, 0, 1);
                cs43l83_headset_amp_format_setup(codec, 1, 0);


                //#8455:  cs42l83_headset_play_setup_on
                //#8455: cs42l83_configure_int_mclk
                //#8727: cs42l83_power_onoff
                //#8791: cs42l83_configure_serial_port
                //#8951: cs42l83_output_set_input_sample_rate
                //#9079: cs42l83_setup_audio_output
                //#9255: cs42l83_buffers_onoff

                cs42l83_headset_play_setup_on(codec);


                //#9273: cs42l83_headphone_sense

                retval = cs42l83_headphone_sense(codec);
                mycodec_info(codec, "cs_8409_boot_setup_real headphone sense 0x%x\n", retval);

                if ((retval & 0x80))
                {
                        //#9287: cs_8409_intmike_stream_conn_off_disable
                        //#9299: cs_8409_linein_stream_conn_off

                        cs_8409_intmike_stream_conn_off(codec);
                        cs_8409_linein_stream_conn_off(codec);

                        //       snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x02270600
                        //       snd_hda:     conv stream channel map 34 [('CHAN', 0), ('STREAMID', 0)]

                        //       snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x02370600
                        //       snd_hda:     conv stream channel map 35 [('CHAN', 0), ('STREAMID', 0)]

                        snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x02270600
                        snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x02370600


                        //#9324:  cs_8409_intmike_volume_setup
                        //#9357: cs_8409_intmike_format_setup_disable
                        //#9324:  cs_8409_linein_volume_setup
                        //#9401: cs_8409_linein_format_setup_disable
                        //#9412:  cs42l83_headset_mike_format_setup_enable
                        //#9451: cs42l83_input_set_output_sample_rate
                        //#9579: cs42l83_mike_setup_audio_input
                        //#9643: cs42l83_mike_enable

                        cs_8409_intmike_volume_setup(codec, 0x27);

                        cs_8409_intmike_format_setup_disable(codec);

                        cs_8409_linein_volume_setup(codec, 0x27);

                        cs_8409_linein_format_setup_disable(codec);


                        // as the following relates to the headset mike
                        // Im guessing we should only do it if we have a mike
                        // spec->have_mike should have been set above
                        // by the unsol response function cs_8409_headset_type_detect_event

                        if (spec->have_mike)
                        {

                                // this is part of cs_8409_enable_headset_mike_streaming

                                // whats missing is no actual cs42l83 power on calls
                                // or unmuting input

                                cs42l83_headset_mike_format_setup_enable(codec, 0, 1);

                                cs42l83_input_set_output_sample_rate(codec);

                                cs42l83_mike_setup_audio_input(codec);

                                cs42l83_mike_enable(codec);


                                // and disable it all!!
                                // this is part of cs_8409_disable_headset_mike_streaming
                                // as usual disabling this duplicate setup

                                //#9675: cs42l83_mike_disable
                                //#9705: cs42l83_headset_mike_format_setup_disable

                                //cs42l83_mike_disable(codec);

                                //cs42l83_headset_mike_format_setup_disable(codec);


                                //#9738:  cs42l83_headset_mike_format_setup_enable
                                //#9738:  cs42l83_headset_mike_format_setup_enable
                                //#9810: cs42l83_input_set_output_sample_rate
                                //#9938: cs42l83_mike_setup_audio_input
                                //#10002: cs42l83_mike_enable

                                // why duplicate setup - 1st dont set stream id/pin
                                // 2nd set stream id and pin
                                //cs42l83_headset_mike_format_setup_enable(codec, 0, 0);
                                //cs42l83_headset_mike_format_setup_enable(codec, 0, 1);

                                //cs42l83_input_set_output_sample_rate(codec);

                                //cs42l83_mike_setup_audio_input(codec);

                                //cs42l83_mike_enable(codec);

                                //// this doesnt make sense double read of nid 0x3c then double set??
                                //retval = snd_hda_codec_read_check(codec, 0x3c, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000020, 25649); // 0x03cf0700
                                //retval = snd_hda_codec_read_check(codec, 0x3c, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000020, 25650); // 0x03cf0700
                                //snd_hda_codec_write(codec, 0x3c, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000020); // 0x03c70720
                                ////       snd_hda:     60 ['AC_PINCTL_IN_EN']
                                //snd_hda_codec_write(codec, 0x3c, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000020); // 0x03c70720
                                ////       snd_hda:     60 ['AC_PINCTL_IN_EN']


                                // is this a good position to switch the inputs??
                                // just before enable buttons is where we switch inputs on plugin
                                // note that this is just telling Alsa the input source has changed
                                // - no changes to audio setup at all
                                switch_input_src(codec);


                                //#10040:  cs_8409_headset_mike_buttons_enable
                                //#10040: cs42l83_configure_headset_button_interrupts
                                //#10088: cs42l83_enable_hsbias_auto_clamp_off2
                                //#10136: cs42l83_enable_hsbias_auto_clamp_on3

                                cs_8409_headset_mike_buttons_enable(codec);


				// we get some calls to cs42l83_read_status_and_clear_interrupt/cs42l83_disambiguate_ur_from_int here
				// clear out any stored unsol responses

                                // I think we need to block here - because clearing the interrupts causes interrupts!!
                                // this is similar to cs_8409_cs42l83_unsolicited_response where we block
                                // before calling the perform function
                                spec->block_unsol = 1;

                                cs_8409_perform_external_device_unsolicited_responses(codec);

                                spec->block_unsol = 0;

                        }

		}
                else
                {
                        dev_info(hda_codec_dev(codec), "cs_8409_boot_setup_real boot headphone REMOVED 6 - UNIMPLEMENTED!!\n");
                }


                spec->block_unsol = 0;

                dev_info(hda_codec_dev(codec), "cs_8409_boot_setup_real boot CURRENT IMPLEMENTATION END!!\n");

        }
        else
        {

                // NOTE - OSX sets a stream format here but a null (ie 0) stream id
                //        on linux we set the OSX format - it will be updated with actual stream format later

                //setup_TDM_6462(codec);
                cs_8409_setup_TDM_amps12(codec, 1, 1);

                //setup_amps_6462(codec);
                cs_8409_setup_amps12(codec, 0);

                //setup_TDM_7472(codec);
                cs_8409_setup_TDM_amps34(codec,  1);

                //setup_amps_7472(codec);
                cs_8409_setup_amps34(codec, 0);

                //sync_converters(codec);
                cs_8409_sync_converters_on(codec, 1);


                //sync_converters1(codec);
                cs_8409_sync_converters_off(codec, 1);

                //amps_disable_6462(codec);
                cs_8409_disable_amps12(codec);

                //putative_tdm_disable_6462(codec);
                cs_8409_disable_TDM_amps12(codec);

                //amps_disable_7472(codec);
                cs_8409_disable_amps34(codec);

                //putative_tdm_disable_7472(codec);
                cs_8409_disable_TDM_amps34(codec);


                // I think Im going to disable the following as we appear to have a stream id here
                // but under linux we do not have a stream at all at this boot stage

                if (0)
                {

                        // this is not quite correct - cs_8409_setup_TDM_amps12 will write a null stream id etc
                        // but the actual logged version does not - although does update format
                        // this may be because Apple is caching the stream format/id similar to linux and
                        // at this point we have already set a null stream id - but because the above disable also
                        // cleared the format we get a re-setup of the the format
                        //putative_enable1_TDM_6462(codec);
                        cs_8409_setup_TDM_amps12(codec, 1, 1);

                        //amps_disable2_6462(codec);
                        cs_8409_disable_amps12(codec);

                        // see above notes for putative_enable1_TDM_6462
                        //putative_enable1_TDM_7472(codec);
                        cs_8409_setup_TDM_amps34(codec, 1);

                        //amps_disable2_7472(codec);
                        cs_8409_disable_amps34(codec);

                        // so this does not set the channel id for node 0x03 to 0x2 but cs_8409_sync_converters_on does
                        // is this significant??
                        // does suggest this function reads the initial stream id then rewrites at the end
                        //sync_converters2(codec);
                        cs_8409_sync_converters_on(codec, 1);


                        // so this also not quite same - we actually have a stream id here on OSX
                        // but at the boot stage dont think we have this in linux
                        //enable2_TDM2_6462(codec);
                        cs_8409_setup_TDM_amps12(codec, 1, 1);


                        //amps_enable2_6462(codec);
                        cs_8409_setup_amps12(codec, 0);

                        // see above
                        //enable2_TDM2_7472(codec);
                        cs_8409_setup_TDM_amps34(codec, 1);

                        //amps_enable2_7472(codec);
                        cs_8409_setup_amps34(codec, 0);

                        //sync_converters3(codec);
                        cs_8409_sync_converters_on(codec, 1);


                        // I dont get this - sync_converters3 sets the stream id/channel id to non-zero
                        // but here when we read the stream id/channel id its 0??
                        //sync_converters4(codec);
                        cs_8409_sync_converters_off(codec, 1);

                        //amps_disable3_6462(codec);
                        cs_8409_disable_amps12(codec);

                        //putative_disable3_TDM_6462(codec);
                        cs_8409_disable_TDM_amps12(codec);

                        //amps_disable3_7472(codec);
                        cs_8409_disable_amps34(codec);

                        //putative_disable3_TDM_7472(codec);
                        cs_8409_disable_TDM_amps34(codec);
                }


                // this is best guess what these volume functions are doing
                // as from the log there is no change in output volume or muting
                // - but if already unmuted thats what you would expect

                //setup_mic_vol2(codec);

                //setup_intmike_vol3(codec);
                cs_8409_intmike_volume_unmute_nouse(codec);

                //setup_linein_vol3(codec);
                cs_8409_linein_volume_unmute_nouse(codec);


                //setup_mic_vol3(codec);

                //setup_intmike_vol4(codec);
                cs_8409_intmike_volume_unmute_nouse(codec);

                //setup_linein_vol4(codec);
                cs_8409_linein_volume_unmute_nouse(codec);


                //setup_mic_vol3(codec);
                //setup_input_power_nids_off(codec);
                cs_8409_inputs_power_nids_off(codec);


                //read_gpio_status1(codec);

                //read_gpio_status2(codec);

                //read_gpio_status3(codec);

                // why 3 reads here - they seem to return the exact same data each time
                retval = read_gpio_status_check(codec);

                retval = read_gpio_status_check(codec);

                retval = read_gpio_status_check(codec);


                //cs42l83_headphone_sense1(codec);
                retval = cs42l83_headphone_sense(codec);
                mycodec_dbg(codec, "cs_8409_boot_setup_real headphone sense 1 0x%x\n", retval);


                //setup_mic_vol4(codec);

                //setup_intmike_vol5(codec);
                cs_8409_intmike_volume_unmute_nouse(codec);

                //setup_linein_vol5(codec);
                cs_8409_linein_volume_unmute_nouse(codec);

                //setup_mic_vol5(codec);

                //setup_intmike_vol6(codec);
                cs_8409_intmike_volume_unmute_nouse(codec);

                //setup_linein_vol6(codec);
                cs_8409_linein_volume_unmute_nouse(codec);

                //cs42l83_headphone_sense2(codec);
                retval = cs42l83_headphone_sense(codec);
                mycodec_dbg(codec, "cs_8409_boot_setup_real headphone sense 2 0x%x\n", retval);


                //cs42l83_headphone_sense3(codec);
                retval = cs42l83_headphone_sense(codec);
                mycodec_dbg(codec, "cs_8409_boot_setup_real headphone sense 3 0x%x\n", retval);

                //setup_intmike_nid1(codec);
                //cs_8409_intmike_format_setup_format_nouse(codec);
                //cs_8409_really_update_stream_format(codec, 0x22, 1, 0, 0);
                cs_8409_really_update_stream_format(codec, spec->intmike_adc_nid, 1, 0, 0);

                //setup_linein_vol7(codec);
                cs_8409_linein_volume_setup(codec, 0x27);

                //setup_linein_nid1(codec);
                cs_8409_linein_format_setup_disable(codec);

                //setup_intmike_stream_conn_off_nid1(codec);
                cs_8409_intmike_stream_conn_off(codec);

                //setup_linein_stream_conn_off_nid1(codec);
                cs_8409_linein_stream_conn_off(codec);

                //setup_intmike_stream_off_nid1(codec);
                cs_8409_intmike_stream_off_nid(codec);

                //setup_linein_stream_off_nid1(codec);
                cs_8409_linein_stream_off_nid(codec);


                //setup_intmike_vol10(codec);
                //cs_8409_volume_set(codec, 0x22, 0x33);
                cs_8409_volume_set(codec, spec->intmike_adc_nid, 0x33);

                //setup_linein_vol10(codec);
                //cs_8409_volume_set(codec, 0x23, 0x33);
                cs_8409_volume_set(codec, spec->linein_amp_nid, 0x33);
        }

        mycodec_info(codec, "command cs_8409_boot_setup_real end\n");

        return 0;
}



static void cs_8409_play_real(struct hda_codec *codec)
{
        int retval;
        //struct cs_spec *spec = codec->spec;

        //cs_8409_play_data(codec);

        mycodec_info(codec, "command cs_8409_play_real start");

        retval = snd_hda_codec_read_check(codec, 0x00, 0, AC_VERB_PARAMETERS, 0x00000000, 0x10138409, 1); // 0x000f0000

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);


        play_setup_TDM_amps12(codec, 1);

        play_setup_amps12(codec);


        play_setup_TDM_amps34(codec);

        play_setup_amps34(codec);


        play_sync_converters_on(codec);

        mycodec_info(codec, "command cs_8409_play_real end");

}




static void cs_8409_amps_disable_streaming(struct hda_codec *codec)
{
        //int retval;
        mycodec_info(codec, "cs_8409_amps_disable_streaming start\n");

        playstop_sync_converters_off(codec);

        playstop_disable_amps12(codec);

        playstop_disable_TDM_amps12(codec);

        playstop_disable_amps34(codec);

        playstop_disable_TDM_amps34(codec);

        // for some reason Apple duplicates the amp disable here??

        playstop_disable_amps12(codec);

        playstop_disable_amps34(codec);


        mycodec_info(codec, "cs_8409_amps_disable_streaming end\n");
}

static void cs_8409_playstop_real(struct hda_codec *codec)
{
        //int retval;
        //struct cs_spec *spec = codec->spec;

        mycodec_info(codec, "command cs_8409_playstop_real start");

        //cs_8409_playstop_data(codec);

        cs_8409_amps_disable_streaming(codec);


        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        // weird - why set the inputs to powered off when stop playing??
        cs_8409_inputs_power_nids_off(codec);


        mycodec_info(codec, "command cs_8409_playstop_real end");
}



static void cs_8409_capture_real(struct hda_codec *codec)
{
        int retval;
        //struct cs_spec *spec = codec->spec;

        //cs_8409_capture_data(codec);

        mycodec_info(codec, "command cs_8409_capture_real start");

        retval = snd_hda_codec_read_check(codec, 0x00, 0, AC_VERB_PARAMETERS, 0x00000000, 0x10138409, 1); // 0x000f0000

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);


        // NOTE - there are big ordering issues here
        //        - here we setup the speaker output before the internal mike
        //        - this maybe because Quicktime defaults to enabling play when recording
        //        unfortunately looks as tho linux tends to open the capture stream before the playback stream
        //        - so going to ignore this here


        cs_8409_inputs_power_nids_on(codec);

        //cs_8409_intmike_format_setup_format(codec);
        cs_8409_intmike_format_setup_enable(codec, 0x4031, 0);

        cs_8409_intmike_volume_setup(codec, 0x27);
        cs_8409_intmike_stream_on_nid(codec);

        cs_8409_intmike_volume_unmute(codec);
        cs_8409_linein_volume_unmute(codec);

        // so here we get AMP_GAIN_MUTE setups but nothing changes
        // - so either this is a volume update with no change or unmute with no change
        // - which to do with??
        //cs_8409_intmike_volume_setup - (no change)
        //cs_8409_linein_volume_setup - (no change)


        mycodec_info(codec, "command cs_8409_capture_real end");

}

static void cs_8409_intmike_stream_reset_nid_on(struct hda_codec *codec)
{
        int retval;

        struct cs_spec *spec = codec->spec;

	// OK dont get this  - we turn the stream back on for the internal mike
	// - but assume pin is OK??
	// now think these 2 functions are resetting to original state - which happens
	// to be stream on for intmike and stream off for linein
	// NOT PROPERLY FUNCTIONAL YET!!!!!

//      retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 23); // 0x022f0500
        hda_set_node_power_state(codec, spec->intmike_adc_nid, AC_PWRST_D0);

        snd_hda_codec_write(codec, spec->intmike_adc_nid, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000010); // 0x02270610
        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000010); // 0x02270610
//      snd_hda:     conv stream channel map 34 [('CHAN', 0), ('STREAMID', 1)]

}

static void cs_8409_linein_stream_reset_nid_off(struct hda_codec *codec)
{
        int retval;

        struct cs_spec *spec = codec->spec;

	// OK dont get this  - we turn the stream off for the linein
	// - but assume pin is OK??

//      retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 25); // 0x023f0500
        hda_set_node_power_state(codec, spec->linein_amp_nid, AC_PWRST_D0);

        snd_hda_codec_write(codec, spec->linein_amp_nid, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x02370600
        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x02370600
//      snd_hda:     conv stream channel map 35 [('CHAN', 0), ('STREAMID', 0)]

}


static void cs_8409_capturestop_real(struct hda_codec *codec)
{
        //int retval;
        struct cs_spec *spec = codec->spec;

        mycodec_info(codec, "command cs_8409_capturestop_real start");

        //cs_8409_capturestop_data(codec);


        cs_8409_intmike_stream_conn_off(codec);
        cs_8409_linein_stream_conn_off(codec);

        // this I think is re-setting to pre-capture state
        // THIS NEEDS FIXING!!!
        cs_8409_intmike_stream_reset_nid_on(codec);
        cs_8409_linein_stream_reset_nid_off(codec);


        cs_8409_intmike_volume_set(codec, 0x27);
        cs_8409_intmike_volume_mute(codec);

	// we also reset the pin - however no change to volume or unmute 
	// so cant say if should just set unmute or set volume to 0
	// just choosing one
	//cs_8409_volume_set(codec, 0x44, 0x00);
	cs_8409_volume_set(codec, spec->intmike_nid, 0x00);


        cs_8409_intmike_format_setup_disable(codec);


        cs_8409_linein_volume_set(codec, 0x27);
        cs_8409_linein_volume_mute(codec);

	// we also reset the pin - however no change to volume or unmute 
	// so cant say if should just set unmute or set volume to 0
	// just choosing one
	//cs_8409_volume_set(codec, 0x45, 0x00);
	cs_8409_volume_set(codec, spec->linein_nid, 0x00);


        cs_8409_linein_format_setup_disable(codec);


        cs_8409_inputs_power_nids_off(codec);


        // using Quicktime we get a play disable when we stop recording
        //cs_8409_sync_converters_off
        //cs_8409_disable_amps12
        //cs_8409_disable_TDM_amps12
        //cs_8409_disable_amps34
        //cs_8409_disable_TDM_amps34
        //cs_8409_disable_amps12
        //cs_8409_disable_amps34


        mycodec_info(codec, "command cs_8409_capturestop_real end");
}


// this is the function which handles unsolicited responses
// - which seem to be enabled by default on the 8409 and set to be from GPIO pin 1
// which seems to be handling the cs42l83

static int cs_8409_read_status_and_clear_interrupt(struct hda_codec *codec);
static int cs42l83_disambiguate_ur_from_int(struct hda_codec *codec);
static void cs_8409_interrupt_action(struct hda_codec *codec, int int_response);

static void cs_8409_external_device_unsolicited_response(struct hda_codec *codec)
{
        int retval;
        int retval_int;
        int ret_disambig;
        int int_response;
        int int_masked;
        int intcnt = 0;

        retval = read_gpio_status_check(codec);

        if ((retval & 0x01) == 0x01)
        {
                mycodec_info(codec, "cs_8409_external_device_unsolicited_response - interrupt clear\n");
                return;
        }

        mycodec_info(codec, "cs_8409_external_device_unsolicited_response - interrupt set\n");

        // so retval_int 

        retval_int = cs_8409_read_status_and_clear_interrupt(codec);

        ret_disambig = cs42l83_disambiguate_ur_from_int(codec);

        // move prints to after so not spaced by other prints

        mycodec_info(codec, "cs_8409_external_device_unsolicited_response - UNSOL interrupt 0x%08x\n",retval_int);

        mycodec_info(codec, "cs_8409_external_device_unsolicited_response - UNSOL disambig  0x%08x\n",ret_disambig);

        // determine masked interrupts

        int_masked = (ret_disambig & retval_int);

        mycodec_info(codec, "cs_8409_external_device_unsolicited_response - UNSOL masked    0x%08x\n",int_masked);

        // determine unmasked interrupts

        int_response = ((~ret_disambig) & retval_int);

        mycodec_info(codec, "cs_8409_external_device_unsolicited_response - UNSOL unmasked  0x%08x\n",int_response);

        intcnt = hweight_long(int_response);

        mycodec_info(codec, "cs_8409_interrupt_action - number interrupt actions %d\n", intcnt);


        // do we call a mapping function here??

        if (int_response != 0)
                cs_8409_interrupt_action(codec, int_response);
        else
                mycodec_info(codec, "cs_8409_external_device_unsolicited_response - UNSOL NO unmasked interrupt\n");


        return;
}


static int cs42l83_read_status_and_clear_interrupt(struct hda_codec *codec);

static int cs_8409_read_status_and_clear_interrupt(struct hda_codec *codec)
{
        int retval = 0;
        int retint = 0;
        int last_retint = 0;
        int loopmax = 11;
        int loopcnt = 0;

        mycodec_info(codec, "cs_8409_read_status_and_clear_interrupt start\n");

        retval = read_gpio_status_check(codec);

        if ((retval & 0x01) == 0x01)
        {
                mycodec_info(codec, "cs_8409_read_status_and_clear_interrupt - interrupt %d clear\n",loopcnt);
                return 0;
        }

        // so this function causes an unsol response because of clearing the interrupt
        // what this means is we need to add a check in the unsol response callbacks
        // to ignore GPIO 1 changes from 0 to 1 - 1 seems to be the default
        // and a 1 to 0 transition means interrupt has been triggered

        while (1)
        {

                retint = cs42l83_read_status_and_clear_interrupt(codec);

                mycodec_info(codec, "cs_8409_read_status_and_clear_interrupt - UNSOL status 0x%08x\n",retint);

                retval = read_gpio_status_check(codec);

                if (loopcnt >= loopmax)
                {
                        dev_info(hda_codec_dev(codec), "cs_8409_read_status_and_clear_interrupt - ERROR - max count exceeded\n");
                        break;
                }

                loopcnt++;

                if ((retval & 0x01) == 0x01)
                {
                        mycodec_info(codec, "cs_8409_read_status_and_clear_interrupt - interrupt %d clear\n",loopcnt);
                        break;
                }

                last_retint = retint;

                // IOSleep(10);
                //usleeprange(8000,12000);
                msleep(10);

        }

        mycodec_info(codec, "cs_8409_read_status_and_clear_interrupt 0x%08x end\n",retint);

        return retint;
}

static int cs42l83_read_status_and_clear_interrupt(struct hda_codec *codec)
{
        int retval;
        int retval_det1;
        int retval_det2;
        int retval_cdc;

        // AppleHDATDM_CS42L83::readStatusAndClearInterrupt

        // so I think Ive finally figured whats going on with interrupts and the 8409
        // cs42l83 interrupts trigger a state change on GPIO pin 1 which is set to
        // trigger an Unsolicited Response (UR) (enableGPIforUR function)
        // so we get a UR from high(1) (default) to low(0) when the interrupt is set
        // plus a UR from low(0) to high(1) when the interrupt is cleared
        // interrupt clearing seems to be triggered by reading registers in this routine (hence the name)
        // Im now pretty certain 0x1b7b and 0x1b7c indicate which interrupt of
        // 0x1b79 and 0x1b7a (Detect Interrupt Mask 1 and Detect Interrupt Mask 2)
        // was triggered

        // Im suspecting the 0x1b7b (maybe 0x1b7c) which are undocumented
        // - the other registers seem to be flagged as status registers
        // 0x1b7b is listed in figure 4-45 as an interrupt register but otherwise undocumented!!

        // moved to above
        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        // note that a lot of i2cPagedRead followed by i2cPagedWrite are likely AppleHDATDMDevice::maskWriteReg
        // ie read from register and mask of bits and set certain bits without affecting others
        // we do not know the mask being used from the HDA commands!!

        // finally know what ASP refers to in lot of Cirrus docs - Audio Serial Port

        // register 0x1b7b - this is undocumented for 42l42 but labelled in fig 4-45 as Interrupt
        //                   Detect Interrupt 1 Status
        //                   value 0x40 (TIP_SENSE_PLUG interrupt from 0xa0 TIP_SENSE_PLUG unmasked)
        // register 0x1b7c - this is undocumented for 42l42 (reserved)
        //                   Detect Interrupt 2 Status
        //                   value 0x00 (none ie inverse of 0xff state of 0x1b7a)
        // register 0x1308 - Codec Interrupt Status
        //                   value 0x01 - Headset disabled, Powered down
        // register 0x1301 - ADC Overflow Interrupt Status
        // register 0x1302 - Mixer Interrupt Status
        // register 0x1303 - SRC Interrupt Status
        // register 0x1304 - ASP RX Interrupt Status
        // register 0x1305 - ASP TX Interrupt Status
        // register 0x130b - SRC Partial Lock Interrupt Status
        // register 0x130d - VP Monitor Interrupt Status
        // register 0x130e - PLL Lock Interrupt Status
        // register 0x130f - Tip/Ring Sense Plug/Unplug Interrupt Status
        //                   value 0x00

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7b00 i2c data 0x7b40
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7c00 i2c data 0x7c00
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0800 i2c data 0x0801
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0100 i2c data 0x0100
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0200 i2c data 0x0200
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0300 i2c data 0x030c
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0400 i2c data 0x0400
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0500 i2c data 0x0500
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0b00 i2c data 0x0b60
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0d00 i2c data 0x0d01
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0e00 i2c data 0x0e00
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0f00 i2c data 0x0f00

        mycodec_info(codec, "cs42l83_read_status_and_clear_interrupt start\n");

        // note that these functions contain power on/power off calls

        retval_det1 = cs_8409_vendor_i2cRead(codec, 0x90, 0x1b7b, 1); // snd_hda

        retval_det2 = cs_8409_vendor_i2cRead(codec, 0x90, 0x1b7c, 1); // snd_hda

        retval_cdc = cs_8409_vendor_i2cRead(codec, 0x90, 0x1308, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1301, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1302, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1303, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1304, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x1305, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x130b, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x130d, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x130e, 1); // snd_hda

        cs_8409_vendor_i2cRead(codec, 0x90, 0x130f, 1); // snd_hda

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        mycodec_info(codec, "cs42l83_read_status_and_clear_interrupt end\n");

        retval = 0;
        retval = ((retval_det1 & 0xff) << 16) | ((retval_det2 & 0xff) << 8) | (retval_cdc & 0xff);

        return retval;
}

static int cs42l83_disambiguate_ur_from_int(struct hda_codec *codec)
{
        int retval_det1;
        int retval_det2;
        int retval_cdc;
        int retval;

        // from AppleHDAFunctionGroupCS8409::externalDeviceUnsolicitedResponse

        // AppleHDATDM_CS42L83::disambiguateURfromINT

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        // register 0x1b79 - Detect Interrupt Mask 1
        //                   value 0xa0 TIP_SENSE_PLUG unmasked
        // register 0x1b7a - Detect Interrupt Mask 2
        //                   value 0xff all masked
        // register 0x131b - Codec Interrupt Mask
        //                   value 0x3 all masked

        mycodec_info(codec, "cs42l83_disambiguate_ur_from_int start\n");

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7900 i2c data 0x79a0
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x1b lo 0x7a00 i2c data 0x7aff
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x1b00 i2c data 0x1b03

        retval_det1 = cs_8409_vendor_i2cRead(codec, 0x90, 0x1b79, 1); // snd_hda

        retval_det2 = cs_8409_vendor_i2cRead(codec, 0x90, 0x1b7a, 1); // snd_hda

        retval_cdc = cs_8409_vendor_i2cRead(codec, 0x90, 0x131b, 1); // snd_hda

        mycodec_info(codec, "cs42l83_disambiguate_ur_from_int end\n");

        // there is a bunch of code here presumably figuring out what happened

        retval = 0;
        retval = ((retval_det1 & 0xff) << 16) | ((retval_det2 & 0xff) << 8) | (retval_cdc & 0xff);
        return retval;

}


static void cs42l83_set_power_state_on(struct hda_codec *codec, int instate)
{
        int retval;
        int loopcnt;

        mycodec_info(codec, "cs42l83_set_power_state_on start\n");

        // likely in AppleHDATDM_CS42L83::enable
        // (only place AppleHDATDM_CS42L83::setPowerState is called from is AppleHDATDM_CS42L83::enable)
        // AppleHDATDM_CS42L83::setPowerState

        // register 0x1101 - Power Down Control 1
        // register 0x130b - SRC Partial Lock Interrupt Status

        // seems to me this powers on either the input path ie mike (instate=1)
        // or output path ie headphones (instate=0)

        // I think that the use of cs_8409_vendor_i2cWriteMask means that we can
        // call this function multiple times and set both input and output power on
        // because only the bits in the mask are affected

//      codec headphone (digital in/audio out)

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x11 lo 0x0100 i2c data 0x01fe
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x019e i2c data 0x009e
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0b00 i2c data 0x0b60
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x11 lo 0x0100 i2c data 0x019e
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x0196 i2c data 0x0096

//      codec capture (audio in/digital out)

//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x11 lo 0x0100 i2c data 0x0196
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x0116 i2c data 0x0016
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x13 lo 0x0b00 i2c data 0x0b24
//      snd_hda i2cPagedRead  i2c address 0x90 i2c reg hi 0x11 lo 0x0100 i2c data 0x0116
//      snd_hda i2cPagedWrite i2c address 0x90 i2c reg hi 0x11 lo 0x0112 i2c data 0x0012


        if (instate)
        {
                // power setup for codec (0x01) and output (0x80)

                // this converts 0xfe to 0x7e (or 0x96 to 0x16)
                cs_8409_vendor_i2cWriteMask(codec, 0x90, 0x1101, 0x81, 0x0, 1); // snd_hda

                loopcnt = 0;
                while (loopcnt < 0x14)
                {
                        retval = cs_8409_vendor_i2cRead(codec, 0x90, 0x130b, 1); // snd_hda
                        if ((retval & 0x1) == 0x1)
                                break;
                        loopcnt++;
                        // IOSleep(2);
                        msleep(2);
                }

                // power setup for ADC (0x04)

                // this converts 0x7e to 0x7a (or 0x16 to 0x12)
                cs_8409_vendor_i2cWriteMask(codec, 0x90, 0x1101, 0x04, 0x0, 1); // snd_hda
        }
        else
        {
                // power setup for codec (0x01), input (0x40) and mixer (0x20)

                //cs_8409_vendor_i2cRead(codec, 0x90, 0x1101, 1); // snd_hda
                //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1101, 0x009e, 1); // snd_hda

                // this converts 0xfe to 0x9e
                cs_8409_vendor_i2cWriteMask(codec, 0x90, 0x1101, 0x61, 0x0, 1); // snd_hda

                loopcnt = 0;
                while (loopcnt < 0x14)
                {
                        retval = cs_8409_vendor_i2cRead(codec, 0x90, 0x130b, 1); // snd_hda
                        if ((retval & 0x4) == 0x4)
                                break;
                        loopcnt++;
                        // IOSleep(2);
                        msleep(2);
                }

                // power setup for headphone (0x08)

                //cs_8409_vendor_i2cRead(codec, 0x90, 0x1101, 1); // snd_hda
                //cs_8409_vendor_i2cWrite(codec, 0x90, 0x1101, 0x0096, 1); // snd_hda

                // this converts 0x9e to 0x96
                cs_8409_vendor_i2cWriteMask(codec, 0x90, 0x1101, 0x08, 0x0, 1); // snd_hda

        }

        mycodec_info(codec, "cs42l83_set_power_state_on end\n");
}

static void cs42l83_headset_amp_setup_TDM_sample_rate(struct hda_codec *codec)
{

//      snd_hda: # AppleHDATDMBusManagerCS8409::setSampleRate: 
        //snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0001, 0x0200, 0xffff, 0x00000200, 0, 3892 ); // coef write mask 3892
        //snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0008, 0x0042, 0xffff, 0x00000040, 0, 3898 ); // coef write mask 3898
        //snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0007, 0x10ff, 0xffff, 0x000010ff, 0, 3904 ); // coef write mask 3904

        // we need to use proper masked versions here - in particular for register 1 which seems to be enabling the Audio Serial Port
        // for the subsystems and bits 0x7f need to pass thro here

        snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0001, 0x0200, 0x0380, 0x00000200, 0, 0 ); // coef write mask 25

        snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0008, 0x0042, 0x0007, 0x00000040, 0, 0 ); // coef write mask 3898
        snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0007, 0x10ff, 0x01ff, 0x000010ff, 0, 0 ); // coef write mask 3904

}

static void cs42l83_headset_amp_setup_TDM_proper(struct hda_codec *codec, int full)
{
        //int retval;
        int ret_coef0 = 0;
        int new_coef0 = 0;
        int ret_coef1 = 0;
        int new_coef1 = 0;
        int ret_coef71 = 0;
        int new_coef71 = 0;


        if (full)
        {
                ret_coef1 = snd_hda_coef_item_check(codec, 0, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000200, 0 ); //   coef read 3810
                new_coef1 = (ret_coef1 & 0xffff); // not clear what this is setting - no difference between read and write so far
                                        // however if used in different places the actual value may be different
                myprintk_dbg("snd_hda_intel: masked cs42l83_headset_amp_setup_TDM_proper coef 0x01 update 0x%04x 0x%04x \n", ret_coef1, new_coef1);

                //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, 0x0200, 0x00000000, 3814 ); //   coef write 3814
                snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, new_coef1, 0x00000000, 3814 ); //   coef write 3814
        }

        snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0015, 0xaaaa, 0xffff, 0x0000aaaa, 0, 0 ); // coef write mask 3819
        snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0014, 0x0100, 0xffff, 0x00000000, 0, 0 ); // coef write mask 3825

//      snd_hda: # AppleHDATDMBusManagerCS8409::setupTDMPath: 
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0029, 0x0000, 0x00008000, 0 ); //   coef read 3832
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0029, 0x0800, 0x00000000, 0 ); //   coef write 3836
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002a, 0x0000, 0x00008000, 0 ); //   coef read 3840
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x002a, 0x0820, 0x00000000, 0 ); //   coef write 3844

        if (full)
        {
                ret_coef0 = snd_hda_coef_item_check(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 0 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 3848
                snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0xb000, 0x00000000, 0 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 3852
                snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0007, 0x0000, 0x000028ff, 0 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 3856
                snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0007, 0x10ff, 0x00000000, 0 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 3860
                snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0xb000, 0x00000000, 0 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 3864
                // NOTA BENE - here we update from 0x9000 to 0xb000 - which is then never removed - even after unplugging headphones!!
                new_coef0 = ret_coef0 | 0x2000;
                snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, new_coef0, 0x00000000, 0 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 76

        //      snd_hda: # AppleHDATDMBusManagerCS8409::setupTDMPath: 
                snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0006, 0x8000, 0xffff, 0x00008000, 0, 0 ); // coef write mask 3868
                snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0008, 0x0040, 0xffff, 0x00000000, 0, 0 ); // coef write mask 3874

        //      snd_hda: # AppleHDATDMBusManagerCS8409::setupTDMPath: 
        //      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0082, 0xa801, 0xffff, 0x00000001, 0, 3880 ); // coef write mask 3880
                snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0082, 0xa800, 0x0000, 0x00000001, 0xa801, 0 ); // coef write mask 3880

                snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0002, 0x0280, 0xffff, 0x00000280, 0, 0 ); // coef write mask 3886

                cs42l83_headset_amp_setup_TDM_sample_rate(codec);

                ret_coef1 = snd_hda_coef_item_check(codec, 0, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000200, 0 ); //   coef read 3910

                new_coef1 = (ret_coef1 & 0xffff) | 0x40;
                myprintk_dbg("snd_hda_intel: masked cs42l83_headset_amp_setup_TDM_proper coef 0x01 update 0x%04x 0x%04x \n", ret_coef1, new_coef1);

                //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, 0x0240, 0x00000000, 3914 ); //   coef write 3914
                snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, new_coef1, 0x00000000, 0 ); //   coef write 3914
        }


//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: AppleHDATDMBusManagerCS8409::tdmInUse:
        //snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00008800, 3918 ); //   coef read 3918

        tdm_in_use(codec, 1);

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: 
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006c, 0x001f, 0x00000000, 0 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 3987


        ret_coef71 = snd_hda_coef_item_check(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x00000000, 0 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef read 3991

        new_coef71 = (ret_coef71 & 0xffff) | 0x800f;
        myprintk_dbg("snd_hda_intel: masked play_setup_TDM_proper_full_headphone coef 0x71 update 0x%04x 0x%04x \n", ret_coef71, new_coef71);

        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x800f, 0x00000000, 3995 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 3995
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, new_coef71, 0x00000000, 0 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 3995


        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00b6 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  write verb 3998

}

static void cs43l83_headset_amp_format_setup(struct hda_codec *codec, int set_stream_id, int full)
{
        int retval;

        //snd_hda_codec_write(codec, 0x0a, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004031); // 0x00a24031
//      snd_hda:     stream format 10 [('CHAN', 2), ('RATE', 44100), ('BITS', 24), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        if (set_stream_id)
        {
                //snd_hda_codec_write(codec, 0x0a, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000010); // 0x00a70610
        //      snd_hda:     conv stream channel map 10 [('CHAN', 0), ('STREAMID', 1)]

                // using the stored stream parameters update nid 0x1a stream parameters
                // we have limited the allowed formats so should only have working formats here
                cs_8409_really_update_stream_format(codec, 0x0a, 1, 2, 0);
        } else {
               snd_hda_codec_write(codec, 0x0a, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00a70600
        }

        //cs42l83_headset_amp_setup_TDM_proper_full(codec);
        cs42l83_headset_amp_setup_TDM_proper(codec, full);


        retval = snd_hda_codec_read_check(codec, 0x2c, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 0); // 0x02cf0700

        snd_hda_codec_write(codec, 0x2c, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x000000c0); // 0x02c707c0
//      snd_hda:     44 ['AC_PINCTL_OUT_EN', 'AC_PINCTL_HP_EN']

}

static void cs_8409_headset_amp_disable_TDM_proper(struct hda_codec *codec, int full)
{
        int retval;
        int ret_coef1 = 0;
        int new_coef1 = 0;
        int ret_coef71 = 0;
        int new_coef71 = 0;

        // AppleHDATDMBusManagerCS8409::disableTDMPath
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0029, 0x0000, 0x00000800, 0 ); //   coef read 2411
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0029, 0x8800, 0x00000000, 0 ); //   coef write 2415
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x002a, 0x0000, 0x00000820, 0 ); //   coef read 2419
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x002a, 0x8820, 0x00000000, 0 ); //   coef write 2423

        if (full)
        {
                // AppleHDATDMBusManagerCS8409::disableTDMPath
        //      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0082, 0x0001, 0xffff, 0x0000a801, 0, 2185 ); // coef write mask 2185
                snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0082, 0x0000, 0xa800, 0x0000a801, 0x0001, 0 ); // coef write mask 2185

                // AppleHDATDMBusManagerCS8409::disableTDMPath
                ret_coef1 = snd_hda_coef_item_check(codec, 0, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000240, 0 ); // AppleHDATDMBusManagerCS8409::disableTDMPath  coef read 2191

                new_coef1 = (ret_coef1 & 0xffbf); // clear our 0x40 bit
                myprintk_dbg("snd_hda_intel: masked cs42l83_headset_amp_disable_TDM_proper coef 0x01 update 0x%04x 0x%04x \n", ret_coef1, new_coef1);

                //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, 0x0200, 0x00000000, 2195 ); // AppleHDATDMBusManagerCS8409::disableTDMPath  coef write 2195
                snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, new_coef1, 0x00000000, 0 ); // AppleHDATDMBusManagerCS8409::disableTDMPath  coef write 2195
        }

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: AppleHDATDMBusManagerCS8409::tdmInUse:
        //snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00008800, 2427 ); //   coef read 2427

        tdm_in_use(codec, 301);

        if (full)
        {
                snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x00000000, 0 ); //   coef write 2452

                snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00000000);
        }
        else
        {

        //      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: 
                snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006c, 0x001f, 0x00000000, 0 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 2624

                ret_coef71 = snd_hda_coef_item_check(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x0000800f, 0 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef read 2628

                new_coef71 = (ret_coef71 & 0xffff); // why doesnt this really disable this here??
                myprintk_dbg("snd_hda_intel: masked cs42l83_headset_amp_disable_TDM_proper coef 0x71 update 0x%04x 0x%04x \n", ret_coef71, new_coef71);

                snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x800f, 0x00000000, 0 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 2632

                snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00b6 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  write verb 2635

        }

}

static void cs_8409_headset_amp_format_setup_disable(struct hda_codec *codec, int full)
{
        int retval;

        cs_8409_headset_amp_disable_TDM_proper(codec, full);

        // note this means the cached stream data in the hda_cvt_setup struct will now be inconsistent
        // we need to ensure any further stream format re-update MUST be a forced update
        // still not clear if should be calling eg __snd_hda_codec_cleanup_stream

        snd_hda_codec_write(codec, 0x0a, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00a70600
//      snd_hda:     conv stream channel map 10 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_codec_write(codec, 0x0a, 0, AC_VERB_SET_STREAM_FORMAT, 0x00000000); // 0x00a20000
//      snd_hda:     stream format 10 [('CHAN', 1), ('RATE', 48000), ('BITS', 8), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        retval = snd_hda_codec_read_check(codec, 0x2c, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000040, 0); // 0x02cf0700

        snd_hda_codec_write(codec, 0x2c, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x02c70700
//      snd_hda:     44 []

}


static void cs42l83_headset_mike_format_setup_enable(struct hda_codec *codec, int nullformat, int full)
{
        int retval = 0;
        int ret_coef71 = 0;
        int new_coef71 = 0;

        //snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004031); // 0x01a24031
//      snd_hda:     stream format 26 [('CHAN', 2), ('RATE', 44100), ('BITS', 24), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        //snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000010); // 0x01a70610
//      snd_hda:     conv stream channel map 26 [('CHAN', 0), ('STREAMID', 1)]

        if (nullformat)
        {
                // note that 0x4031 is Apples fixed format - but this is for plugin stage when we have
                // not defined any format yet so just use it - we overwrite below when actually play
                snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004031); // 0x01a24031
                if (full)
                        snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000010); // 0x01a70610
        }
        else
        {
                if (full)
                        cs_8409_really_update_stream_format(codec, 0x1a, 1, 2, 0);
                else
                        cs_8409_really_update_stream_format(codec, 0x1a, 1, 0, 0);
        }

        snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0012, 0xaccc, 0xffff, 0x0000cccc, 0, 0 ); // coef write mask 12272
        snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0011, 0x0001, 0xffff, 0x00000000, 0, 0 ); // coef write mask 12278

//      snd_hda: # AppleHDATDMBusManagerCS8409::setupTDMPath: 
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0049, 0x0000, 0x00008000, 0 ); //   coef read 12285
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0049, 0x0800, 0x00000000, 0 ); //   coef write 12289
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004a, 0x0000, 0x00008000, 0 ); //   coef read 12293
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x004a, 0x0820, 0x00000000, 0 ); //   coef write 12297

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: AppleHDATDMBusManagerCS8409::tdmInUse:
        //snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00008800, 12301 ); //   coef read 12301

        tdm_in_use(codec, 201);

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: 
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006c, 0x001f, 0x00000000, 0 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 12370

        ret_coef71 = snd_hda_coef_item_check(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x0000800f, 0 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef read 12374

        new_coef71 = (ret_coef71 & 0xffff);
        myprintk_dbg("snd_hda_intel: masked cs42l83_headset_mike_format_setup_enable coef 0x71 update 0x%04x 0x%04x \n", ret_coef71, new_coef71);

        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x800f, 0x00000000, 0 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 12378

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00b6 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  write verb 12381

        if (full)
        {

                retval = snd_hda_codec_read_check(codec, 0x3c, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 0); // 0x03cf0700

                snd_hda_codec_write(codec, 0x3c, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000020); // 0x03c70720
        //      snd_hda:     60 ['AC_PINCTL_IN_EN']
        }

}

static void cs42l83_headset_mike_format_setup_disable(struct hda_codec *codec)
{
        int retval = 0;
        int ret_coef71 = 0;
        int new_coef71 = 0;

//      snd_hda: # AppleHDATDMBusManagerCS8409::disableTDMPath: 
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0049, 0x0000, 0x00000800, 0 ); //   coef read 13141
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0049, 0x8800, 0x00000000, 0 ); //   coef write 13145
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004a, 0x0000, 0x00000820, 0 ); //   coef read 13149
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x004a, 0x8820, 0x00000000, 0 ); //   coef write 13153

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: AppleHDATDMBusManagerCS8409::tdmInUse:
        //snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00008800, 13157 ); //   coef read 13157

        tdm_in_use(codec, 202);

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: 
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006c, 0x001f, 0x00000000, 0 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 13226

        ret_coef71 = snd_hda_coef_item_check(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x0000800f, 0 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef read 13230

        new_coef71 = (ret_coef71 & 0xffff);
        myprintk_dbg("snd_hda_intel: masked cs42l83_headset_mike_format_setup_disable coef 0x71 update 0x%04x 0x%04x \n", ret_coef71, new_coef71);

        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x800f, 0x00000000, 13234 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 13234
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, new_coef71, 0x00000000, 0 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 13234

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00b6 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  write verb 13237


        // note this means the cached stream data in the hda_cvt_setup struct will now be inconsistent
        // we need to ensure any further stream format re-update MUST be a forced update
        // still not clear if should be calling eg __snd_hda_codec_cleanup_stream

        snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x01a70600
//      snd_hda:     conv stream channel map 26 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_STREAM_FORMAT, 0x00000000); // 0x01a20000
//      snd_hda:     stream format 26 [('CHAN', 1), ('RATE', 48000), ('BITS', 8), ('RATE_MUL', 1), ('RATE_DIV', 1)]


        retval = snd_hda_codec_read_check(codec, 0x3c, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000020, 0); // 0x03cf0700

        snd_hda_codec_write(codec, 0x3c, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x03c70700
//      snd_hda:     60 []

}

// NOTE - the following routines NOT fixed up yet - currently not used!!

static void cs42l83_headset_mike_format_setup_enable1(struct hda_codec *codec)
{
        //int retval = 0;

        //snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004031); // 0x01a24031
//      snd_hda:     stream format 26 [('CHAN', 2), ('RATE', 44100), ('BITS', 24), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        cs_8409_really_update_stream_format(codec, 0x1a, 1, 0, 0);

        snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0012, 0xaccc, 0xffff, 0x0000accc, 0, 0 ); // coef write mask 13249
        snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0011, 0x0001, 0xffff, 0x00000001, 0, 0 ); // coef write mask 13255

//      snd_hda: # AppleHDATDMBusManagerCS8409::setupTDMPath: 
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0049, 0x0000, 0x00008800, 0 ); //   coef read 13262
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0049, 0x0800, 0x00000000, 0 ); //   coef write 13266
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004a, 0x0000, 0x00008820, 0 ); //   coef read 13270
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x004a, 0x0820, 0x00000000, 0 ); //   coef write 13274

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: AppleHDATDMBusManagerCS8409::tdmInUse:
        //snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00008800, 13278 ); //   coef read 13278

        tdm_in_use(codec, 203);

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: 
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006c, 0x001f, 0x00000000, 0 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 13347

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x0000800f, 0 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef read 13351
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x800f, 0x00000000, 0 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 13355

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00b6 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  write verb 13358

}

static void cs42l83_headset_mike_format_setup_enable1a(struct hda_codec *codec)
{
        //int retval = 0;

        snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004031); // 0x01a24031
//      snd_hda:     stream format 26 [('CHAN', 2), ('RATE', 44100), ('BITS', 24), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0012, 0xaccc, 0xffff, 0x0000accc, 0, 0 ); // coef write mask 13249
        snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0011, 0x0001, 0xffff, 0x00000001, 0, 0 ); // coef write mask 13255

//      snd_hda: # AppleHDATDMBusManagerCS8409::setupTDMPath: 
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0049, 0x0000, 0x00008800, 0 ); //   coef read 13262
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0049, 0x0800, 0x00000000, 0 ); //   coef write 13266
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004a, 0x0000, 0x00008820, 0 ); //   coef read 13270
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x004a, 0x0820, 0x00000000, 0 ); //   coef write 13274

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: AppleHDATDMBusManagerCS8409::tdmInUse:
        //snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00008800, 13278 ); //   coef read 13278

        tdm_in_use(codec, 203);

}

static void cs42l83_headset_mike_format_setup_enable1b(struct hda_codec *codec)
{
        int retval = 0;

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301

        snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004031); // 0x01a24031
//      snd_hda:     stream format 26 [('CHAN', 2), ('RATE', 44100), ('BITS', 24), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000010); // 0x01a70610
//      snd_hda:     conv stream channel map 26 [('CHAN', 0), ('STREAMID', 1)]

        snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0012, 0xaccc, 0xffff, 0x0000accc, 0, 0 ); // coef write mask 13368
        snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0011, 0x0001, 0xffff, 0x00000001, 0, 0 ); // coef write mask 13374

//      snd_hda: # AppleHDATDMBusManagerCS8409::setupTDMPath: 
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0049, 0x0000, 0x00000800, 0 ); //   coef read 13381
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0049, 0x0800, 0x00000000, 0 ); //   coef write 13385
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004a, 0x0000, 0x00000820, 0 ); //   coef read 13389
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x004a, 0x0820, 0x00000000, 0 ); //   coef write 13393

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: AppleHDATDMBusManagerCS8409::tdmInUse:
        //snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00008800, 13397 ); //   coef read 13397

        tdm_in_use(codec, 204);

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: 
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006c, 0x001f, 0x00000000, 0 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 13466
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x0000800f, 0 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef read 13470
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x800f, 0x00000000, 0 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 13474

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00b6 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  write verb 13477

        retval = snd_hda_codec_read_check(codec, 0x3c, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 0); // 0x03cf0700

        snd_hda_codec_write(codec, 0x3c, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000020); // 0x03c70720
//      snd_hda:     60 ['AC_PINCTL_IN_EN']

}

// NOTE - end of unfixed routines


static void cs42l83_headset_amp_disable_and_mike_disable_TDM_proper(struct hda_codec *codec)
{
        //int retval = 0;
        int ret_coef1 = 0;
        int new_coef1 = 0;
        int ret_coef71 = 0;
        int new_coef71 = 0;

//      snd_hda: # AppleHDATDMBusManagerCS8409::disableTDMPath: 
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0049, 0x0000, 0x00000800, 0 ); //   coef read 10459
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0049, 0x8800, 0x00000000, 0 ); //   coef write 10463
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x004a, 0x0000, 0x00000820, 0 ); //   coef read 10467
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x004a, 0x8820, 0x00000000, 0 ); //   coef write 10471

        // this section is actually disabling the headset amp TDM setup

//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0082, 0x5400, 0xffff, 0x0000fc00, 0, 10475 ); // coef write mask 10475
        snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0082, 0x0000, 0xa800, 0x0000fc00, 0x5400, 0 ); // coef write mask 10475

        ret_coef1 = snd_hda_coef_item_check(codec, 0, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000260, 0 ); // AppleHDATDMBusManagerCS8409::disableTDMPath  coef read 10481

        new_coef1 = (ret_coef1 & 0xffbf);
        myprintk_dbg("snd_hda_intel: masked cs42l83_headset_amp_disable_and_mike_disable_TDM_proper coef 0x01 update 0x%04x 0x%04x \n", ret_coef1, new_coef1);

        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, 0x0220, 0x00000000, 10485 ); // AppleHDATDMBusManagerCS8409::disableTDMPath  coef write 10485
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, new_coef1, 0x00000000, 0 ); // AppleHDATDMBusManagerCS8409::disableTDMPath  coef write 10485

        // end of section disabling the headset amp TDM setup


//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: AppleHDATDMBusManagerCS8409::tdmInUse:
        //snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00000800, 10489 ); //   coef read 10489

        tdm_in_use(codec, 401);

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: 
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006c, 0x001f, 0x00000000, 0 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 10494


        ret_coef71 = snd_hda_coef_item_check(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x0000c00f, 0 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef read 10498

        new_coef71 = (ret_coef71 & 0xffff); // I dont get this - it doesnt seem to change this at all - but this is for output 0x800f (headphones) or 0x400f (amps)
        myprintk_dbg("snd_hda_intel: masked cs42l83_headset_amp_disable_and_mike_disable_TDM_proper coef 0x71 update 0x%04x 0x%04x \n", ret_coef71, new_coef71);

        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0xc00f, 0x00000000, 10502 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 10502
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, new_coef71, 0x00000000, 0 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 10502


        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00b6 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  write verb 10505

}

static void cs42l83_headset_amp_disable_and_mike_format_setup_disable(struct hda_codec *codec)
{
        int retval = 0;

        cs42l83_headset_amp_disable_and_mike_disable_TDM_proper(codec);

        // note this means the cached stream data in the hda_cvt_setup struct will now be inconsistent
        // we need to ensure any further stream format re-update MUST be a forced update
        // still not clear if should be calling eg __snd_hda_codec_cleanup_stream

        snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x01a70600
//      snd_hda:     conv stream channel map 26 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_STREAM_FORMAT, 0x00000000); // 0x01a20000
//      snd_hda:     stream format 26 [('CHAN', 1), ('RATE', 48000), ('BITS', 8), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        retval = snd_hda_codec_read_check(codec, 0x3c, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000020, 0); // 0x03cf0700
        snd_hda_codec_write(codec, 0x3c, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x03c70700
//      snd_hda:     60 []

}


static void cs_8409_linein_format_setup_enable(struct hda_codec *codec)
{
        int retval;
        int ret_coef9 = 0;
        int new_coef9 = 0;

        struct cs_spec *spec = codec->spec;

        // theres some weird issue here
        // index 0x0009 has bit 0x0080 set only after an unplug event with headset with mike
        // but then never seems to be turned off!!!

        // 0x45 -> 0x23 is line input


        // now updated to not write the Apple format but use my format setting routines
        // (remember we have limited the allowed formats to acceptable ones)
        // note that apparently we can set the format with the nid powered down but for setting the
        // stream id the nid has to be powered up
        // we may wish to ignore the power down here - because we reactivate the nid only a few steps
        // later

        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004033); // 0x02324033
//      snd_hda:     stream format 35 [('CHAN', 4), ('RATE', 44100), ('BITS', 24), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 10555); // 0x023f0500
        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x02370500
        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000030, 10558); // 0x023f0500
        hda_set_node_power_state(codec, spec->linein_amp_nid, AC_PWRST_D0);

        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000012); // 0x02370612
//      snd_hda:     conv stream channel map 35 [('CHAN', 2), ('STREAMID', 1)]


        // using the stored stream parameters update nid 0x23 stream parameters
        // we have limited the allowed formats so should only have working formats here
        //cs_8409_really_update_stream_format(codec, 0x23, 1, 1, 0);
        cs_8409_really_update_stream_format(codec, spec->linein_amp_nid, 1, 1, 0);


        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x02370503
        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 10561); // 0x023f0500
        hda_set_node_power_state(codec, spec->linein_amp_nid, AC_PWRST_D3);


//      snd_hda: # AppleHDAWidgetCS8409::setConnectionSelect: 
        ret_coef9 = snd_hda_coef_item_check(codec, 0, CS8409_VENDOR_NID, 0x0009, 0x0000, 0x000000b3, 0 ); // AppleHDAWidgetCS8409::setConnectionSelect  coef read 10563
        //new_coef9 = ret_coef9 | 0x80; // I dont get this bit set - see above
        new_coef9 = ret_coef9 | spec->reg9_linein_dmic_mo; // I dont get this bit set - see above
        myprintk_dbg("snd_hda_intel: masked cs_8409_linein_format_setup_enable coef 0x09 update 0x%04x 0x%04x \n", ret_coef9, new_coef9);
        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0009, 0x00b3, 0x00000000, 10567 ); // AppleHDAWidgetCS8409::setConnectionSelect  coef write 10567
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0009, new_coef9, 0x00000000, 0 ); // AppleHDAWidgetCS8409::setConnectionSelect  coef write 10567
        //snd_hda_codec_write(codec, 0x23, 0, AC_VERB_SET_CONNECT_SEL, 0x00000000); // 0x02370100
        snd_hda_codec_write(codec, spec->linein_amp_nid, 0, AC_VERB_SET_CONNECT_SEL, 0x00000000); // 0x02370100

}

static void cs_8409_linein_stream_on_nid(struct hda_codec *codec)
{
        int retval;
        int reg_coef82 = 0;
        int new_coef82 = 0;

        struct cs_spec *spec = codec->spec;

        reg_coef82 = snd_hda_coef_item_check(codec, 0, CS8409_VENDOR_NID, 0x0082, 0x0000, 0x00005401, 0 ); //   coef read 10584

        //new_coef82 = (reg_coef82 | 0x2);
        new_coef82 = (reg_coef82 | spec->reg82_linein_dmic_scl);
        myprintk_dbg("snd_hda_intel: masked cs_8409_linein_stream_on_nid coef 0x82 update 0x%04x 0x%04x \n", reg_coef82, new_coef82);

        //snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0082, 0x5403, 0x00000000, 10588 ); //   coef write 10588
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0082, new_coef82, 0x00000000, 10588 ); //   coef write 10588

        //retval = snd_hda_codec_read_check(codec, 0x45, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 0); // 0x045f0700
        retval = snd_hda_codec_read_check(codec, spec->linein_nid, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 0); // 0x045f0700

        snd_hda_codec_write(codec, spec->linein_nid, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000020); // 0x04570720

        //snd_hda_codec_write(codec, 0x45, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000020); // 0x04570720
//      snd_hda:     69 ['AC_PINCTL_IN_EN']

}

static void cs_8409_intmike_stream_conn_off_disable(struct hda_codec *codec)
{
        int retval;

        struct cs_spec *spec = codec->spec;

        // more weird issue here
        // index 0x0009 has bit 0x0100 set only after an unplug event with headset with mike
        // it is reset

        // 0x44 -> 0x22 is internal (I think) mike input (macbook pro)

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301

        retval = snd_hda_codec_read_check(codec, spec->intmike_adc_nid, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000000, 0); // 0x022f0600
        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000000, 0); // 0x022f0600
//      snd_hda:     conv stream channel map 34 [('CHAN', 0), ('STREAMID', 0)]

        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 10596); // 0x022f0500
        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x02270500
        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000030, 10599); // 0x022f0500
        hda_set_node_power_state(codec, spec->intmike_adc_nid, AC_PWRST_D0);

        snd_hda_codec_write(codec, spec->intmike_adc_nid, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x02270600
        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x02270600
//      snd_hda:     conv stream channel map 34 [('CHAN', 0), ('STREAMID', 0)]

        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x02270503
        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 10602); // 0x022f0500
        hda_set_node_power_state(codec, spec->intmike_adc_nid, AC_PWRST_D3);

        // this is NOT from setConnectionSelect - unknown where from
        // very not clear what this does - it appears as part of the multiple disable/enables
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0009, 0x01b3, 0xffff, 0x000000b3, 0, 10604 ); // coef write mask 10604
        snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0009, 0x0100, 0x0000, 0x000000b3, 0x01b3, 0 ); // coef write mask 10604

}


static void cs_8409_intmike_stream_conn_off_enable(struct hda_codec *codec)
{
        int retval;

        struct cs_spec *spec = codec->spec;

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301

        retval = snd_hda_codec_read_check(codec, spec->intmike_adc_nid, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000000, 0); // 0x022f0600
        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000000, 0); // 0x022f0600
//      snd_hda:     conv stream channel map 34 [('CHAN', 0), ('STREAMID', 0)]

        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 10676); // 0x022f0500
        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x02270500
        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000030, 10679); // 0x022f0500
        hda_set_node_power_state(codec, spec->intmike_adc_nid, AC_PWRST_D0);

        snd_hda_codec_write(codec, spec->intmike_adc_nid, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x02270600
        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x02270600
//      snd_hda:     conv stream channel map 34 [('CHAN', 0), ('STREAMID', 0)]

        //snd_hda_codec_write(codec, 0x22, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x02270503
        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 10682); // 0x022f0500
        hda_set_node_power_state(codec, spec->intmike_adc_nid, AC_PWRST_D3);

        // this is NOT from setConnectionSelect - unknown where from
        // very not clear what this does - it appears as part of the multiple disable/enables
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0009, 0x00b3, 0xffff, 0x000001b3, 0, 10684 ); // coef write mask 10684
        snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0009, 0x0000, 0x0100, 0x000001b3, 0x00b3, 0 ); // coef write mask 10684

}


static void cs_8409_intmike_linein_resetup(struct hda_codec *codec)
{
        struct cs_spec *spec = codec->spec;

        // for some very strange reason we setup a 4 channel format after unplug of headset with mike

        //cs_8409_intmike_format_setup_format33(codec);

        cs_8409_intmike_format_setup_enable(codec, 0x4033, 1);

        cs_8409_intmike_volume_setup(codec, 0x27);

        cs_8409_intmike_stream_on_nid(codec);

        cs_8409_linein_format_setup_enable(codec);

        cs_8409_linein_volume_setup(codec, 0x27);

        cs_8409_linein_stream_on_nid(codec);


        cs_8409_intmike_stream_conn_off_disable(codec);

        cs_8409_linein_stream_conn_off(codec);

        cs_8409_intmike_stream_off_nid(codec);

        cs_8409_linein_stream_off_nid(codec);


        //cs_8409_intmike_format_setup_format_nouse(codec);
        //cs_8409_really_update_stream_format(codec, 0x22, 1, 0, 0);
        cs_8409_really_update_stream_format(codec, spec->intmike_adc_nid, 1, 0, 0);

        cs_8409_linein_volume_setup(codec, 0x27);

        cs_8409_linein_format_setup_disable(codec);


        cs_8409_intmike_stream_conn_off_enable(codec);

        cs_8409_linein_stream_conn_off(codec);

        cs_8409_intmike_stream_off_nid(codec);

        cs_8409_linein_stream_off_nid(codec);


        cs_8409_intmike_volume_mute(codec);

        cs_8409_linein_volume_mute(codec);

        cs_8409_intmike_volume_unmute(codec);

        cs_8409_linein_volume_unmute(codec);

        cs_8409_inputs_power_nids_off(codec);

}


// this is where we need to decode the actions to be taken
// note that the button interrupts are undocumented for the cs42l42 (reserved)
// not yet clear which one is up and which one is down!!
// so after button detect 0x1b7b is 0x14 and 0x1b7c is 0x0a
// for 0x1b7b 0x14 are reserved bits for cs42l42 - but the 0x04 only seen on detection
// actual button presses are 0x01, 0x02 and button release 0x10
// for 0x1b7c 0x02 is a short release for buttons, 0x08 is reserved
// the mask bits for 0x1b7a seem to be 0xe7 for buttons defining 0x08 as the button detect interrupt
// (0x1b79 is mask, 0x1b7b status; 0x1b7a is mask, 0x1b7c is presumed status, 0x131b is mask, 0x1308 status)
#define TIP_SENSE_PLUG 0x400000
#define TIP_SENSE_UNPLUG 0x200000
#define BUTTON_DOWN_PRESS 0x10000
#define BUTTON_UP_PRESS 0x20000
#define BUTTON_RELEASE 0x100000
// pressing the play/pause button on earbuds yields 0x100 on down and 0x200 on up
#define BUTTON_TOGGLE_DOWN_PRESS 0x100
#define BUTTON_TOGGLE_UP_PRESS 0x200
#define BUTTON_DETECT_MAIN 0x1800  // we only see 0x800 but the mask allows for these 2 bits
#define BUTTON_DETECT 0x40
#define MIKE_CONNECT 0x02
#define BUTTONS (BUTTON_UP_PRESS | BUTTON_DOWN_PRESS | BUTTON_TOGGLE_UP_PRESS | BUTTON_TOGGLE_DOWN_PRESS)
#define HSDET_AUTO_DONE 0x02
#define PDN_DONE 0x01

static void cs_8409_headset_plugin_event(struct hda_codec *codec);
static void cs_8409_headset_unplug_event(struct hda_codec *codec);
static void cs_8409_headset_type_detect_event(struct hda_codec *codec);
static int cs_8409_set_power_state(struct hda_codec *codec, int power_state);
static void cs_8409_enable_headset_streaming(struct hda_codec *codec);
static void cs_8409_headset_button_detect_event(struct hda_codec *codec);
static void cs_8409_headset_button_event(struct hda_codec *codec, int buttons);
static void cs_8409_plugin_event_continued(struct hda_codec *codec);


static void cs_8409_interrupt_action(struct hda_codec *codec, int int_response)
{
        int retval;
        int headset_state;
        struct cs_spec *spec = codec->spec;

        if ((int_response & TIP_SENSE_PLUG) == TIP_SENSE_PLUG)
        {
                dev_info(hda_codec_dev(codec), "cs_8409_interrupt_action - plug in\n");
                cs_8409_headset_plugin_event(codec);
        }
        else if ((int_response & TIP_SENSE_UNPLUG) == TIP_SENSE_UNPLUG)
        {
                dev_info(hda_codec_dev(codec), "cs_8409_interrupt_action - unplug\n");
                cs_8409_headset_unplug_event(codec);
        }
        else if ((int_response & HSDET_AUTO_DONE) == HSDET_AUTO_DONE)
        {
                dev_info(hda_codec_dev(codec), "cs_8409_interrupt_action - headset detected\n");

                cs_8409_headset_type_detect_event(codec);

                // and this is where life gets really complicated
                // if we have a mike we do a button detect - but that leads to an unsolicited response
                // so we only continue here I think if we dont have a mike
                if (!(spec->have_mike))
                {
                        cs_8409_plugin_event_continued(codec);
                }
        }
        // not clear what test is here - but this should check what we see - one button interrupt seems to be activated
        // when doing the button detect
        // not sure what the exact button interrupt is - we get 0x140800
        // so the button detect interrupt is 0x0800 - the 0x140000 are actual button interrupts (undocumented for cs42l42)
        else if (int_response & BUTTON_DETECT_MAIN)
        {
                dev_info(hda_codec_dev(codec), "cs_8409_interrupt_action - buttons detected\n");
                cs_8409_headset_button_detect_event(codec);

        }
        else if (((int_response & BUTTON_UP_PRESS) == BUTTON_UP_PRESS) ||
                 ((int_response & BUTTON_DOWN_PRESS) == BUTTON_DOWN_PRESS) ||
                 ((int_response & BUTTON_TOGGLE_UP_PRESS) == BUTTON_TOGGLE_UP_PRESS) ||
                 ((int_response & BUTTON_TOGGLE_DOWN_PRESS) == BUTTON_TOGGLE_DOWN_PRESS))
        {
                dev_info(hda_codec_dev(codec), "cs_8409_interrupt_action - button event on \n");
                cs_8409_headset_button_event(codec, int_response);

        }
        else if (((int_response & BUTTON_RELEASE) == BUTTON_RELEASE))
        {
                dev_info(hda_codec_dev(codec), "cs_8409_interrupt_action - button event off \n");
                cs_8409_headset_button_event(codec, int_response);

        }
        else if ((int_response & PDN_DONE) == PDN_DONE)
        {
                dev_info(hda_codec_dev(codec), "cs_8409_interrupt_action - power down\n");
        }
        else
        {
                dev_info(hda_codec_dev(codec), "cs_8409_interrupt_action - UNKNOWN INTERRUPT 0x%08x\n", int_response);
        }

}


static void cs42l83_headset_play_setup_on(struct hda_codec *codec);
static void cs_8409_headset_streaming_preplay(struct hda_codec *codec);
static void cs_8409_intmike_linein_disable(struct hda_codec *codec);
static void cs_8409_headset_mike_streaming_preplay(struct hda_codec *codec, int nullformat);
static void cs_8409_headset_mike_buttons_enable(struct hda_codec *codec);


static void cs_8409_plugin_event_continued(struct hda_codec *codec)
{
        struct cs_spec *spec = codec->spec;
        int headset_plugged_in = 0;
        int retval = 0;

        mycodec_info(codec, "cs_8409_plugin_event_continued start\n");

        // 0 is power state - 0 is powered on +ve powered/powering down
        // headset_plugged_in indicates if headset still plugged in or not
        headset_plugged_in = cs_8409_set_power_state(codec, 0);

        mycodec_info(codec, "cs_8409_plugin_event_continued headset_plugged_in %d\n", headset_plugged_in);

        if (headset_plugged_in)
        {
                // now handle plugin while playing
                if (spec->playing)
                {

                        cs_8409_amps_disable_streaming(codec);


                        cs_8409_enable_headset_streaming(codec);


                        // the following is just cs_8409_enable_headset_streaming
                        //cs43l83_headset_amp_format_setup(codec);
                        //mycodec_info(codec, "cs42l83_headset_play_setup_on\n");
                        //cs42l83_headset_play_setup_on(codec);
                        // power on audio output
                        //cs42l83_set_power_state_on(codec, 0);
                        //cs42l83_headset_enable_on(codec);

                        // so OSX now does another one of its enable off/enable on - ignoring

                        //cs_8409_headset_enable_off(codec);
                        //cs42l83_power_off_codec_output_off(codec);
                        //headphone_play_stop_buffers_off(codec);
                        //headphone_play_stop_power_off(codec);
                        //headphone_play_stop_headphone_format_setup_disable(codec);

                        //cs_8409_enable_headset_streaming(codec);

                        // we need to reset formats here - so we follow the same path as a simple amp
                        // or headphone play ie after the pre-prepare we force a reset of the
                        // of the stream format

                        // using explicit nid here!!
                        //cs_8409_reset_stream_format(codec, 0xa, 1, 1);

                }
                else
                {

                        // try removing this - we still do a partial setup when actually play on OSX
                        // and if we stop play then do another play we do a full setup
                        // - why not just enable when we play??
                        // in any case we initially made this a full setup and it worked
                        //cs_8409_headset_streaming_preplay(codec);

                        // so now think on OSX we pre-setup the headphone and mike here
                        // when we dont know if we will be playing or capturing
                        // in particular realised that cs42l83_configure_serial_port is only called
                        // for the headphone setup - but it sets both primary ASP (Audio Serial Port)
                        // transmit and receive frequencies - which would seem to be important for
                        // capturing!!

                        //spec->headset_presetup_done = 1;

                }

                // NOTA BENE - no concept/implementation of plugging in while capturing!!

                mycodec_info(codec, "cs_8409_plugin_event_continued headset_phase %d\n", spec->headset_phase);

                // this event now gets called if boot with headset plugged in
                // but from this point the boot phase setup is different
		// -  now a headset_phase of 1 indicates booted with headset plugged in
                // - headset phase of 2 or more means post boot headset plugin
		if (spec->headset_phase >= 2)
                {

                        // ensure the intmike/linein nids are powered off
                        cs_8409_inputs_power_nids_off(codec);


                        retval = cs42l83_headphone_sense(codec);

                        mycodec_info(codec, "cs_8409_plugin_event_continued headphone sense 0x%x\n", retval);

                        if (!(retval & 0x80))
                        {
                                dev_info(hda_codec_dev(codec), "cs_8409_plugin_event_continued JACK DISCONNECT NOT IMPLEMENTED!!\n");
                        }

                        if (spec->have_mike)
                        {
                                if (spec->capturing)
                                {
                                        dev_info(hda_codec_dev(codec), "cs_8409_plugin_event_continued PLUGIN WHILE CAPTURING NOT IMPLEMENTED!!\n");
                                }

                                // this is just calling this routine
                                //cs_8409_headset_mike_setup_nouse

                                cs_8409_intmike_linein_disable(codec);

                                // is this a good position to switch the inputs??
                                switch_input_src(codec);

                                // confirmed that if do a second recording we get a full setup as for playing above
                                // - so why not just enable when we capture??
                                // (only plausible reason so far is to reduce setup time because of the long time
                                //  to send the i2c commands??)
                                // NOTE - this is complicated because on OSX it appears the headphone setup is always
                                //        done - even if just capturing
                                //        going with OSX way and doing the headphone setup as well

                                // so this is a problem - at this point we dont have a stream
                                // so our format is null
                                // what to do??
                                // now moving all this setup into the actual capture setup
                                // - as did with the play setup

                                //cs_8409_headset_mike_streaming_preplay(codec, 1);

                                //spec->headset_presetup_done = 1;


                                cs_8409_headset_mike_buttons_enable(codec);

                        }
                }

        }
        else
               {} // headset unplugged - should be handled by the unplug interrupt

        mycodec_info(codec, "cs_8409_plugin_event_continued end\n");
}

static void cs_8409_plugin_complete_detect(struct hda_codec *codec);


static void cs_8409_headset_plugin_event(struct hda_codec *codec)
{
        int retval;
        struct cs_spec *spec = codec->spec;

        mycodec_info(codec, "cs_8409_headset_plugin_event pre  plugin handle_detect\n");

        cs_8409_plugin_handle_detect(codec);

        mycodec_info(codec, "cs_8409_headset_plugin_event post plugin handle_detect\n");


        //retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 1066); // 0x001f0500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        // this seems to be here but no idea where coming from
        retval = read_gpio_status_check(codec);

        // then call setTimer to initiate function after a time period

        msleep(1800);

        //retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000000, 1069); // 0x001f0500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);


        mycodec_info(codec, "cs_8409_headset_plugin_event pre  plugin complete_detect\n");

        cs_8409_plugin_complete_detect(codec);

        mycodec_info(codec, "cs_8409_headset_plugin_event post plugin complete_detect\n");

        spec->headset_phase = 3;

}

static void cs_8409_plugin_handle_detect(struct hda_codec *codec)
{
        //int retval;
        struct cs_spec *spec = codec->spec;

        // now think this is AppleHDAMikeyInternalCS8409::handleJackDetectUR

        // this is a pre-value - indicates we have had a jack detect
        // but set to 1 when have checked with cs42l83_headphone_sense for headset
        // at the moment not used
        spec->jack_present = 2;

        cs42l83_headset_button_detect_interrupts_off(codec);

        cs42l83_headset_set_hpout_clamp_disable(codec);

        // IOSleep(1) here
        msleep(1);
}

static void cs_8409_plugin_complete_detect(struct hda_codec *codec)
{
        int retval;
        struct cs_spec *spec = codec->spec;

        // so AppleHDAMikeyInternalCS8409::generalTimerCallback calls AppleHDAMikeyInternalCS8409::completeJackDetectUR
        // AppleHDAMikeyInternalCS8409::generalTimerCallback is set as a timer callback in the AppleHDAMikeyInternal::init
        // using the IOTimerEventSource::timerEventSource function

        // this is AppleHDAMikeyInternalCS8409::completeJackDetectUR
        // its first call is to AppleHDATDM_Codec::getHeadphonePinSense
        // which if returns 0 in the bool arg jumps to AppleHDAMikeyInternalCS8409::handleJackDisconnectUR
        // - which does the disconnect

        mycodec_info(codec, "cs_8409_plugin_complete_detect start\n");

        // so thats weird - the first call is a power call which doesnt seem to exist in the log
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        retval = cs42l83_headphone_sense(codec);

        mycodec_info(codec, "cs_8409_plugin_complete_detect headphone sense 0x%x\n", retval);

        if ((retval & 0x80))
        {
                mycodec_info(codec, "cs_8409_plugin_complete_detect headphone sensed\n");

                spec->jack_present = 1;

                spec->headset_enable = 1;

                cs42l83_complete_jack_detect(codec);

                cs42l83_power_hs_bias_on(codec);

                // this seems to be setting an interrupt on 0x131b for headset detect
                // - but there doesnt seem to be a delay anywhere here
                // so it must be immediately triggered

                cs42l83_enable_hs_auto_int_on(codec);


                cs42l83_unplug_interrupt_setup(codec);


                cs42l83_set_hpout_pulldown_off(codec);

                cs42l83_headset_detect_on(codec);
                //cs42l83_headset_detect_onoff(codec, 1);

        }
        else
        {
                mycodec_info(codec, "cs_8409_plugin_complete_detect headphone NOT sensed\n");

                spec->jack_present = 0;
                spec->headset_enable = 0;

                // AppleHDAMikeyInternalCS8409::handleJackDisconnectUR

                dev_info(hda_codec_dev(codec), "cs_8409_plugin_complete_detect no headphone UNIMPLEMENTED!!\n");
        }

        mycodec_info(codec, "cs_8409_plugin_complete_detect end\n");
}



static void cs_8409_headset_type_detect_event(struct hda_codec *codec)
{
        int retval;
        int retstate;
        int flag = 1;
        int headset_type = 0;
        struct cs_spec *spec = codec->spec;

        // this is AppleHDAMikeyInternalCS8409::handleTypeDetectUR
        // dont yet see the path to call this - Im guessing from some messaging call

        mycodec_info(codec, "cs_8409_headset_type_detect_event start\n");

        // I think we get to here if have either an unplug event or headset detect event
        // - in both cases we need to turn off the headset detect interrupt
        // and unset for headset detect

        //plugin_enable_hs_auto_int_off(codec);
        cs42l83_enable_hs_auto_int_off(codec);

        //headset_type = plugin_headset_type(codec);
        headset_type = cs42l83_headset_type(codec);

        // we then have options based on the headset type
        headset_type = headset_type & 0x3;

        // types are 0x00 (1), 0x01 (2), 0x02 (3) and 0x3 (4)
        // type 1 Pin 1 Left, Pin 2 Right, Pin 3 Gnd, Pin 4 Mic
        // type 2 Pin 1 Left, Pin 2 Right, Pin 3 Mic, Pin 4 Gnd
        // type 3 Pin 1 Left, Pin 2 Right, Pin 3 Gnd, Pin 4 Gnd
        // type 4 Optical!!

        mycodec_info(codec, "cs_8409_headset_type_detect_event headset type %d\n", headset_type);

        if (headset_type == 0x00 && flag == 0)
        {
                // 0x74df1

                // if ?? goto 0x74ee2

                // if ?? goto 0x751e8

                        // 0x74e42

                        //plugin_headset_detect_off(codec);

                        // IOSleep(250);

                        // possible AppleHDAMikeyInternalCS8409::handleJackDetectUR

                        // goto 0x7546d
                        // IOLog()
                        // goto 0x75198
                        // return

                // else

                        // 0x751e8

                        //retval = plugin_headphone_sense1(codec);

                        // if dont sense headphone guess we do AppleHDAMikeyInternalCS8409::handleJackDisconnectUR

                        //if (!(retval & 0x80))
                        //{
                        //        // AppleHDAMikeyInternalCS8409::handleJackDisconnectUR
                        //        goto 0x74ee2
                        //}

                        // error!!
        }

        if (headset_type == 0x00)
        {
                // 0x74df1
                // goto 0x74ee2
                spec->headset_type = 1;
                spec->have_mike = 1;
                dev_info(hda_codec_dev(codec), "cs_8409_headset_type_detect_event headset has mike!!\n");
        }
        else if (headset_type == 0x01)
        {
                // 0x74e98
                // insert Mikey event 0xfe
                // goto 0x74ee2
                spec->headset_type = 2;
                spec->have_mike = 1;
                dev_info(hda_codec_dev(codec), "cs_8409_headset_type_detect_event headset has mike!!\n");
                }
        else if (headset_type == 0x02)
        {
                // 0x74eb9
                // goto 0x74ee2
                spec->headset_type = 3;
                dev_info(hda_codec_dev(codec), "cs_8409_headset_type_detect_event headset does not have mike!!\n");
        }
        else if (headset_type == 0x03)
        {
                // this is SPDIF!!
                // 0x74ec3
                // insert Mikey event 0xfc
                spec->headset_type = 4;
                dev_info(hda_codec_dev(codec), "cs_8409_headset_type_detect_event headset does not have mike!!\n");
        }

        // 0x74ee2

        cs42l83_headset_detect_off(codec);
        //cs42l83_headset_detect_onoff(codec, 0);

        cs42l83_set_hpout_pulldown_on(codec);

        // IOSleep(1);
        msleep(1);

        // 0x74ff1

        cs42l83_set_hpout_clamp_enable(codec);

        // IOSleep(1);
        msleep(1);


        if (spec->have_mike)
        {

                cs42l83_enable_hsbias_auto_clamp_on(codec);

                cs42l83_enable_hsbias_auto_clamp_off(codec);

                // I dont see a difference in these 2 functions
                //cs42l83_power_hs_bias_off1(codec);
                cs42l83_power_hs_bias_off(codec);

                // difference from no mike headphones

                cs42l83_setup_button_detect(codec);

                cs42l83_power_hs_bias_button_on(codec);

                cs42l83_enable_hsbias_auto_clamp_off1(codec);

        }
        else
        {
                // goto 0x75a02

                // 0x750a2

                cs42l83_headset_mike_detect_off(codec);

                cs42l83_power_hs_bias_off(codec);
        }


        // 0x75149

        // there is a call to dispatchStatelessTagToEngines which is likely what initiates the stream setup etc


        // 0x7546d

        // 0x75198

        // there is an unknown call here - possible setPowerState
        // cannot figure out if this is doing anything - none of the functions seem to fit the log
        // so now think this function isnt really doing anything
        // and the setPowerState is from some other function call path ie the result
        // of dispatchStatelessTagToEngines


        // exit routine after this

        mycodec_info(codec, "cs_8409_headset_type_detect_event end\n");
}


static int cs_8409_set_power_state(struct hda_codec *codec, int power_state)
{
        int retval = 0;
        int retstate = 0;
        int flag = 0;

        mycodec_info(codec, "cs_8409_set_power_state start\n");

        // this is likely AppleHDAMikeyInternalCS8409::setPowerState as there is
        // a pin sense and handleJackDisconnectUR in AppleHDAMikeyInternalCS8409::setPowerState
        // in fact all AppleHDAMikeyInternalCS8409::setPowerState does is check the headphone sense
        // and then either do a handleJackDisconnectUR or handleJackDetectUR

        if (flag)
        {
                // check for headphone whatever power state of HDA is

                retval = cs42l83_headphone_sense(codec);

                // if sense headphone guess we do AppleHDAMikeyInternalCS8409::handleJackDetectUR

                if ((retval & 0x80))
                {
                        // AppleHDAMikeyInternalCS8409::handleJackDetectUR
                        dev_info(hda_codec_dev(codec), "cs_8409_set_power_state JACK DETECT NOT IMPLEMENTED!!\n");
                }

                retstate = 0;
        }
        else
        {
                // only check for headphone if HDA powered up
                if (power_state == 0)
                {
                        retval = cs42l83_headphone_sense(codec);

                        // if dont sense headphone guess we do AppleHDAMikeyInternalCS8409::handleJackDisconnectUR

                        if (!(retval & 0x80))
                        {
                                // AppleHDAMikeyInternalCS8409::handleJackDisconnectUR
                                dev_info(hda_codec_dev(codec), "cs_8409_headset_type_detect JACK DISCONNECT NOT IMPLEMENTED!!\n");
                                retstate = 0;
                        }
                        else
                                retstate = 1;
                }
        }

        mycodec_info(codec, "cs_8409_set_power_state end\n");

        return retstate;
}


static void cs_8409_headset_button_detect_event(struct hda_codec *codec)
{
        int ret_button;
        int ret_mike;
        struct cs_spec *spec = codec->spec;

        mycodec_info(codec, "cs_8409_headset_button_detect_event start\n");

        // this returns significant state - headphone sense (shift 16), and 2 reads from register 0x1b78 (second one shifted 8)
        ret_button = cs42l83_handle_button_detect(codec);

        mycodec_info(codec, "cs_8409_headset_button_detect_event button data 0x%08x\n", ret_button);

        if ((ret_button & BUTTON_DETECT) == BUTTON_DETECT)
        {
                mycodec_info(codec, "cs_8409_headset_button_detect_event HAVE BUTTON\n");
                spec->have_buttons = 1;
        }

        // this is a read from same register 0x1b78 - which seems to contain both senses
        // button sense 0x40 (assumed) and mike sense 0x02 - known but undocumented
        // do we do anything with this??
        // we have aleady set have_mike prior to this
        // could log an error here
        ret_mike = cs42l83_mike_connected(codec);

        mycodec_info(codec, "cs_8409_headset_button_detect_event mike data 0x%08x\n", ret_mike);

        if ((ret_mike & MIKE_CONNECT) != MIKE_CONNECT)
                dev_err(hda_codec_dev(codec), "ERROR - has mike but mike not connected - not analyzed!!\n");


        // this continues the plugin event
        cs_8409_plugin_event_continued(codec);


        mycodec_info(codec, "cs_8409_headset_button_detect_event end\n");
}

static void cs_8409_headset_button_event(struct hda_codec *codec, int buttons)
{
        mycodec_info(codec, "cs_8409_headset_button_event  buttons 0x%08x\n", buttons);
}


static void cs_8409_intmike_linein_disable(struct hda_codec *codec)
{

        cs_8409_intmike_stream_conn_off(codec);

        cs_8409_linein_stream_conn_off(codec);

        cs_8409_intmike_stream_off_nid(codec);

        cs_8409_linein_stream_off_nid(codec);

        cs_8409_intmike_volume_setup(codec, 0x27);

        cs_8409_intmike_format_setup_disable(codec);

        cs_8409_linein_volume_setup(codec, 0x27);

        cs_8409_linein_format_setup_disable(codec);

}

static void cs_8409_headset_mike_streaming_preplay(struct hda_codec *codec, int nullformat)
{

        // confirmed that if do a second recording we get a full setup as for playing
        // - so why not just enable when we capture??
        // (only plausible reason so far is to reduce setup time because of the long time
        //  to send the i2c commands??)
        // NOTE - this is complicated because on OSX it appears the headphone setup is always
        //        done - even if just capturing
        //        going with OSX way and doing the headphone setup as well

        //cs42l83_headset_mike_format_setup_enable(codec, nullformat, 1);

        //cs42l83_input_set_output_sample_rate(codec);

        //cs42l83_mike_setup_audio_input(codec);

        //cs42l83_mike_enable(codec);


        // yet again the usual disable/second enable

        //cs42l83_mike_disable(codec);

        //cs42l83_headset_mike_format_setup_disable(codec);


        // cs42l83_headset_mike_format_setup_enable1(codec);

        // cs42l83_headset_mike_format_setup_enable1a(codec);

        // cs42l83_headset_mike_format_setup_enable1b(codec);

        // cs42l83_input_set_output_sample_rate1(codec);

        // cs42l83_input_setup_audio_input(codec);

        // cs42l83_mike_enable(codec);


        //cs42l83_headset_mike_pin_enable(codec);

}

static void cs_8409_headset_mike_buttons_enable(struct hda_codec *codec)
{

        cs42l83_configure_headset_button_interrupts(codec);

        cs42l83_enable_hsbias_auto_clamp_off2(codec);

        cs42l83_enable_hsbias_auto_clamp_on3(codec);

}

static void cs_8409_headset_plugin_preplay_unused1(struct hda_codec *codec)
{

        // these occur for headset with mike but seem to be triggered by
        // by something - maybe volume control??
        // dont know where coming from - ignoring for now

        //plugin3_set_power_state_on(codec);

        //plugin3_headphone_play_start_headset_enable_on(codec);


        //plugin3_headphone_sense3(codec);

        //plugin3_headphone_sense4(codec);


        //plugin3_headphone_format_setup_enable2(codec);

}

static void cs_8409_headset_plugin_preplay_unused2(struct hda_codec *codec)
{
        // these occur for headset with mike but seem to be triggered by
        // by something - this is definitely after an interrupt - but
        // no interrupt triggered
        // dont know where coming from - ignoring for now

        //plugin3_headset_enable_off(codec);

        //plugin3_power_off_codec_output_off(codec);

        //plugin3_buffers_off1(codec);

        //plugin3_headphone_format_setup_disable1(codec);

        //plugin3_headset_enable_off1(codec);

        //plugin3_power_off_codec_output_off1(codec);

}


static void cs_8409_unplug_handle_disconnect(struct hda_codec *codec);

static void cs_8409_headset_unplug_event(struct hda_codec *codec)
{
        int retval;
        struct cs_spec *spec = codec->spec;

        mycodec_info(codec, "cs_8409_headset_unplug_event start\n");

        // Im guessing we are ensuring headphone is unplugged here
        // what to do if not!!
        retval = cs42l83_headphone_sense(codec);

        if ((retval & 0x80))
        {
                dev_info(hda_codec_dev(codec), "cs_8409_headset_unplug_event headphone still sensed - NOT HANDLED!!!\n");
        }
        else
        {
                mycodec_info(codec, "cs_8409_headset_unplug_event headphone not sensed - OK\n");

                cs_8409_unplug_handle_disconnect(codec);
        }

        mycodec_info(codec, "cs_8409_headset_unplug_event end\n");
}

static void cs_8409_unplug_handle_disconnect(struct hda_codec *codec)
{
        int retval;
        struct cs_spec *spec = codec->spec;

        mycodec_info(codec, "cs_8409_unplug_handle_disconnect start\n");


        cs42l83_plugin_interrupt_setup(codec);

        cs42l83_enable_hs_auto_int_off(codec);

        cs42l83_headset_detect2_off(codec);


        if (spec->have_mike)
        {
                cs42l83_power_hs_bias_off(codec);

                cs42l83_enable_hsbias_auto_clamp_off3(codec);

                cs42l83_disable_button_interrupts(codec);
        }


        // Im guessing we are ensuring headphone is unplugged here
        // what to do if not!!
        retval = cs42l83_headphone_sense(codec);

        if ((retval & 0x80))
        {
                dev_err(hda_codec_dev(codec), "cs_8409_unplug_handle_disconnect headphone still sensed - NOT HANDLED!!!\n");
        }
        else
        {
                mycodec_info(codec, "cs_8409_unplug_handle_disconnect headphone not sensed - OK\n");

                if (spec->playing)
                {
                        mycodec_info(codec, "cs_8409_unplug_handle_disconnect playing 1 start\n");

                        cs42l83_headset_enable_off(codec);

                        cs42l83_power_off_codec_output(codec);

                        //unplug23_buffers_off(codec);
                        cs42l83_buffers_onoff(codec, 0);

                        if ((spec->have_mike))
                                cs_8409_headset_amp_format_setup_disable(codec, 0);
                        else
                        {
                                cs42l83_power_onoff(codec, 0);

                                cs_8409_headset_amp_format_setup_disable(codec, 1);
                        }


                        cs42l83_headset_enable_off(codec);

                        //unplug23_power_off_codec_output1(codec);
                        cs42l83_power_off_codec_output(codec);

                        mycodec_info(codec, "cs_8409_unplug_handle_disconnect playing 1 end\n");
                }

                // this is done if playing or not??
                // - changing - only setup amps if still playing

                if (spec->playing)
                {
                        mycodec_info(codec, "cs_8409_unplug_handle_disconnect playing 2 start\n");

                        //unplug23_play_setup_TDM_6462(struct hda_codec *codec)

                        //play_setup_TDM_amps12_debug(codec, 1);
                        play_setup_TDM_amps12(codec, 1);

                        //unplug23_setup_amps_6462(struct hda_codec *codec)

                        play_setup_amps12(codec);

                        //unplug23_play_setup_TDM_7472(struct hda_codec *codec)

                        play_setup_TDM_amps34(codec);

                        //unplug23_play_setup_amps_7472(struct hda_codec *codec)

                        play_setup_amps34(codec);

                        //unplug23_sync_converters_on(struct hda_codec *codec)

                        play_sync_converters_on(codec);

                        mycodec_info(codec, "cs_8409_unplug_handle_disconnect playing 2 end\n");
                }

                // more duplicated disable/enables

                //unplug_sync_converters_off(codec);
                //unplug_disable_amps_6462(codec);
                //unplug_disable_TDM_6462(codec);
                //unplug_disable_amps_7472(codec);
                //unplug_disable_TDM_7472(codec);

                //unplug_setup_TDM2_6462(codec);
                //unplug_setup_amps1_6462(codec);
                //unplug_setup_TDM2_7472(codec);
                //unplug_setup_amps1_7472(codec);
                //unplug_sync_converters2_on(codec);


                if (!(spec->have_mike))
                {
                        cs_8409_inputs_power_nids_off(codec);
                }

                // and another headphone sense

                retval = cs42l83_headphone_sense(codec);

                if ((retval & 0x80))
                {
                        dev_err(hda_codec_dev(codec), "cs_8409_unplug_handle_disconnect headphone sensed again - NOT HANDLED!!!\n");
                }
                else
                {
                        mycodec_info(codec, "cs_8409_unplug_handle_disconnect headset not sensed - OK\n");


                        if (spec->have_mike)
                        {
                                mycodec_info(codec, "cs_8409_unplug_handle_disconnect headset have mike start\n");

                                //unplug23_mike_disable(codec);

                                cs42l83_mike_disable(codec);

                                //unplug23_power_on_off(codec);

                                cs42l83_power_onoff(codec, 0);

                                //unplug23_headset_amp_disable_and_mike_format_setup_disable(codec);

                                cs42l83_headset_amp_disable_and_mike_format_setup_disable(codec);

                                // is this a good position to switch the inputs??
                                switch_input_src(codec);

                                //unplug23_intmike_linein_resetup(codec);

                                cs_8409_intmike_linein_resetup(codec);

                                mycodec_info(codec, "cs_8409_unplug_handle_disconnect headset have mike end\n");
                        }

                        if (spec->playing)
                        {
                                if (!(spec->have_mike))
                                {
                                        cs_8409_inputs_power_nids_off(codec);
                                }
                        }

                        if (spec->have_mike)
                                cs_8409_inputs_power_nids_off(codec);


                        mycodec_info(codec, "cs_8409_unplug_handle_disconnect headset disable start\n");

                        cs42l83_unplug_headset_detect_off(codec);

                        mycodec_info(codec, "cs_8409_unplug_handle_disconnect headset disable 1\n");

                        cs42l83_headset_switch_control(codec);

                        mycodec_info(codec, "cs_8409_unplug_handle_disconnect headset disable end\n");
                }

        }

        mycodec_info(codec, "cs_8409_unplug_handle_disconnect headset about to reset vars\n");

        // and reset all headset variables

        spec->jack_present = 0;

        spec->headset_type = 0;

        spec->have_mike = 0;

        spec->have_buttons = 0;

        spec->headset_play_format_setup_needed = 1;
        spec->headset_capture_format_setup_needed = 1;

        spec->headset_presetup_done = 0;

        mycodec_info(codec, "cs_8409_unplug_handle_disconnect jack_present %d\n", spec->jack_present);

        mycodec_info(codec, "cs_8409_unplug_handle_disconnect end\n");
}

static void cs42l83_headset_play_setup_on(struct hda_codec *codec)
{

        // this is the function AppleHDATDM_CS42L83::enable for turning on headset for play


        // the following section is often done pre-play

        cs42l83_configure_int_mclk(codec);

        //cs42l83_headset_power_on_on_nouse(codec);
        cs42l83_power_onoff(codec, 1);

        cs42l83_configure_serial_port(codec);


        // the following section always done before play

        cs42l83_output_set_input_sample_rate(codec);

        cs42l83_setup_audio_output(codec);

               // headset_setup_SPDIf_output(codec); - presumably if is SPDIF setup

        //cs42l83_headset_rcv_enable_on(codec);
        cs42l83_buffers_onoff(codec, 1);

}


static void cs42l83_headset_disable(struct hda_codec *codec, int full)
{
        myprintk("snd_hda_intel: cs42l83_headset_disable start\n");

        cs42l83_headset_enable_off(codec);

        myprintk("snd_hda_intel: cs42l83_power_off_codec_output start\n");

        cs42l83_power_off_codec_output(codec);

        myprintk("snd_hda_intel: cs42l83_power_off_codec_output end\n");

        if (full)
        {
                myprintk("snd_hda_intel: cs42l83_headset_rcv_enable_off start\n");

                cs42l83_headset_rcv_enable_off(codec);

                myprintk("snd_hda_intel: cs42l83_headset_rcv_enable_off end\n");
                myprintk("snd_hda_intel: cs42l83_headset_power_off start\n");

                cs42l83_headset_power_off(codec);

                myprintk("snd_hda_intel: cs42l83_headset_power_off end\n");
        }

        myprintk("snd_hda_intel: cs42l83_headset_disable end\n");
}


static void cs_8409_headset_streaming_preplay(struct hda_codec *codec)
{
        //int retval;

        // this code performed on plugin even if not playing
        // the usual enable/disable multiple times

        //plugin3_headphone_format_setup_enable(codec);
        cs43l83_headset_amp_format_setup(codec, 1, 1);

        //plugin3_configure_int_mclk(codec);
        cs42l83_configure_int_mclk(codec);

        //plugin3_power_on_on(codec);
        cs42l83_power_onoff(codec, 1);

        //plugin3_configure_serial_port(codec);
        cs42l83_configure_serial_port(codec);

        //plugin3_set_sample_rate(codec);
        cs42l83_output_set_input_sample_rate(codec);

        //plugin3_setup_audio_output(codec);
        cs42l83_setup_audio_output(codec);

        //plugin3_buffers_on(codec);
        cs42l83_buffers_onoff(codec, 1);


        // ignoring the disable

        //plugin3_buffers_off(codec);
        //cs42l83_buffers_onoff(codec, 0);

        //plugin3_power_on_off(codec);
        //cs42l83_headset_power_off(codec);

        //plugin3_headphone_format_setup_disable(codec);
        //cs_8409_headset_amp_format_setup_disable(codec, 1);


        //plugin3_headphone_format_setup_enable1(codec);

        //plugin3_headphone_format_setup_enable1a(codec);

        //plugin3_configure_int_mclk1(codec);

        //plugin3_power_on_on2(codec);

        //plugin3_configure_serial_port1(codec);

        //plugin3_set_sample_rate1(codec);

        //plugin3_setup_audio_output1(codec);

        //plugin3_buffers_on1(codec);

}


static void cs_8409_enable_headset_streaming(struct hda_codec *codec)
{
        //int retval;

        mycodec_info(codec, "cs_8409_enable_headset_streaming start\n");

        // debug status check - 0x27 here
        read_gpio_status_check(codec);

        // dont really have any idea how to get to here
        // Im guessing from messaging

        //play_format_setup_headphone(codec);
        cs43l83_headset_amp_format_setup(codec, 1, 1);

        cs42l83_headset_play_setup_on(codec);

        // power on audio output
        cs42l83_set_power_state_on(codec, 0);

        cs42l83_headset_enable_on(codec);

        mycodec_info(codec, "cs_8409_enable_headset_streaming end\n");

}

static void cs_8409_disable_headset_streaming(struct hda_codec *codec)
{
        //int retval;

        mycodec_info(codec, "snd_hda_intel: cs_8409_disable_headset_streaming start\n");

        // why do we do the headphone disable/poweroff codec output twice??
        // but we do - repeatedly seen in logs

        cs42l83_headset_disable(codec, 1);

        //playstop_headset_amp_format_setup_disable_headphone(codec);
        cs_8409_headset_amp_format_setup_disable(codec, 1);

        cs42l83_headset_disable(codec, 0);

        mycodec_info(codec, "snd_hda_intel: cs_8409_disable_headset_streaming end\n");
}


static void cs_8409_headplay_real(struct hda_codec *codec)
{
        //int retval;
        struct cs_spec *spec = codec->spec;

        mycodec_info(codec, "cs_8409_headplay_real start\n");

        if (spec->headset_enable == 0)
        {
                mycodec_info(codec, "cs_8409_headplay_real enable 0\n");
                //cs_8409_headplay_real1(codec);
        }
        else if (spec->headset_enable == 1)
        {
                mycodec_info(codec, "cs_8409_headplay_real enable 1\n");
                //cs_8409_headplay_real1(codec);
                cs_8409_enable_headset_streaming(codec);
                //spec->headset_enable = 2;
        }
        else if (spec->headset_enable == 2)
        {
                mycodec_info(codec, "cs_8409_headplay_real enable 2\n");
                //cs_8409_headplay_real2(codec);
        }

        mycodec_info(codec, "cs_8409_headplay_real end\n");
}


static void cs_8409_headplaystop_real(struct hda_codec *codec)
{
        //int retval;

        mycodec_info(codec, "cs_8409_headplaystop_real start\n");

        cs_8409_disable_headset_streaming(codec);

        mycodec_info(codec, "cs_8409_headplaystop_real end\n");
}

static void cs_8409_enable_headset_mike_streaming(struct hda_codec *codec)
{
        //int retval;

        mycodec_info(codec, "cs_8409_enable_headset_mike_streaming start\n");

        // debug status check - 0x27 here
        read_gpio_status_check(codec);

        // dont really have any idea how to get to here
        // Im guessing from messaging


        // NOTE - there are big ordering issues here
        //        - here we setup the headphone output before the mike
        //        - this maybe because Quicktime defaults to enabling play when recording
        //        unfortunately looks as tho linux tends to open the capture stream before the playback stream
        //        - so going to ignore this here

        // this sets up the headphones
        // note this only does a partial headset amp setup compared to a base headset play
        // power on audio output
        //cs42l83_set_power_state_on(codec, 0);
        //cs42l83_headset_enable_on(codec);

        //retval = cs42l83_headphone_sense(codec);
        //mycodec_info(codec, "cs_8409_enable_headset_mike_streaming headphone sense 0x%x\n", retval);
        //if (!(retval & 0x80))
        //{
        //        dev_info(hda_codec_dev(codec), "cs_8409_enable_headset_mike_streaming headphone NOT PLUGGED IN UNIMPLEMENTED!!\n");
        //}
        //retval = cs42l83_headphone_sense(codec);
        //mycodec_info(codec, "cs_8409_enable_headset_mike_streaming headphone sense 0x%x\n", retval);
        //if (!(retval & 0x80))
        //{
        //        dev_info(hda_codec_dev(codec), "cs_8409_enable_headset_mike_streaming headphone NOT PLUGGED IN UNIMPLEMENTED!!\n");
        //}

        ////cs43l83_headset_amp_format_setup_partial
        //cs43l83_headset_amp_format_setup(codec, 0);


        cs42l83_headset_mike_format_setup_enable(codec, 0, 1);

        cs42l83_input_set_output_sample_rate(codec);

        cs42l83_mike_setup_audio_input(codec);

        cs42l83_mike_enable(codec);


        // power on the codec/audio input
        cs42l83_set_power_state_on(codec, 1);

        // unmute audio input
        cs42l83_headset_mike_adc_unmutevol(codec, 1);


        // for partial setup only
        //cs42l83_headset_mike_pin_enable(codec);
        //cs42l83_headset_mike_format_setup_enable(codec, 0, 1);


        // this is all done in the capture hook after this call
        //read_gpio_status
        //read_gpio_status
        //cs42l83_read_status_and_clear_interrupt
        //read_gpio_status
        //cs42l83_disambiguate_ur_from_int
        //read_gpio_status
        //read_gpio_status
        //read_gpio_status
        //cs42l83_read_status_and_clear_interrupt
        //read_gpio_status
        //cs42l83_disambiguate_ur_from_int
        //read_gpio_status

        mycodec_info(codec, "cs_8409_enable_headset_mike_streaming end\n");
}

static void cs_8409_disable_headset_mike_streaming(struct hda_codec *codec)
{
        //int retval;

        mycodec_info(codec, "snd_hda_intel: cs_8409_disable_headset_mike_streaming start\n");


        // NOTE - there are big ordering issues here
        //        although here the mike is turned off before the headphone output

        // mute ADC
        cs42l83_headset_mike_adc_unmutevol(codec, 0);

        cs42l83_power_off_codec_input(codec);

        cs42l83_mike_disable(codec);

        cs42l83_headset_mike_format_setup_disable(codec);

        // and duplicate the above!!
        cs42l83_headset_mike_adc_unmutevol(codec, 0);
        cs42l83_power_off_codec_input(codec);


        // the following is disabling the headphone component
        // - assuming this is done by the playback hooks

        //cs42l83_headset_enable_off
        //cs42l83_power_off_codec_output
        //cs42l83_buffers_onoff
        //cs42l83_headset_power_off
        //cs_8409_headset_amp_disable_TDM_proper (full)
        //cs_8409_headset_amp_format_setup_disable
        //cs42l83_headset_enable_off
        //cs42l83_power_off_codec_output

        //cs_8409_external_device_unsolicited_response
        //cs_8409_read_status_and_clear_interrupt
        //read_gpio_status
        //read_gpio_status
        //cs42l83_read_status_and_clear_interrupt
        //read_gpio_status
        //cs42l83_disambiguate_ur_from_int
        //read_gpio_status


        // and re-enabling the headphone component?????
        // igoring all the following for the moment

        // note there was a 7 second delay here - this is recextstop2/2c

        //cs43l83_headset_amp_format_setup (full)
        //cs42l83_configure_int_mclk
        //cs42l83_power_onoff
        //cs42l83_configure_serial_port
        //cs42l83_output_set_input_sample_rate
        //cs42l83_setup_audio_output
        //cs42l83_buffers_onoff
        //cs42l83_set_power_state_on
        //cs42l83_headset_enable_on

        //cs_8409_external_device_unsolicited_response
        //cs_8409_read_status_and_clear_interrupt
        //read_gpio_status
        //read_gpio_status
        //cs42l83_read_status_and_clear_interrupt
        //read_gpio_status
        //cs42l83_read_status_and_clear_interrupt
        //read_gpio_status
        //cs42l83_disambiguate_ur_from_int
        //read_gpio_status
        //cs_8409_external_device_unsolicited_response (continued)
        //cs_8409_read_status_and_clear_interrupt
        //read_gpio_status
        //read_gpio_status
        //cs42l83_read_status_and_clear_interrupt
        //read_gpio_status
        //cs42l83_disambiguate_ur_from_int
        //read_gpio_status


        // then re-disabling!!

        // note there was a 5 second delay here - this is recextstop3

        //cs42l83_headset_enable_off
        //cs42l83_power_off_codec_output
        //cs42l83_headset_rcv_enable_off
        //cs42l83_headset_power_off
        //cs_8409_headset_amp_disable_TDM_proper - full
        //cs42l83_headset_enable_off
        //cs42l83_power_off_codec_output

        //cs_8409_external_device_unsolicited_response
        //cs_8409_read_status_and_clear_interrupt
        //read_gpio_status
        //read_gpio_status
        //cs42l83_read_status_and_clear_interrupt
        //read_gpio_status
        //cs42l83_disambiguate_ur_from_int
        //read_gpio_status

        mycodec_info(codec, "snd_hda_intel: cs_8409_disable_headset_mike_streaming end\n");
}

static void cs_8409_headcapture_real(struct hda_codec *codec)
{
        //int retval;
        struct cs_spec *spec = codec->spec;

        mycodec_info(codec, "cs_8409_headcapture_real start\n");

        if (spec->headset_enable == 0)
        {
                mycodec_info(codec, "cs_8409_headcapture_real enable 0\n");
                //cs_8409_headcapture_real1(codec);
        }
        else if (spec->headset_enable == 1)
        {
                mycodec_info(codec, "cs_8409_headcapture_real enable 1\n");
                //cs_8409_headcapture_real1(codec);
                hda_check_power_state(codec, 0x1a, 11);
                hda_check_power_state(codec, 0x3c, 11);
                cs_8409_enable_headset_mike_streaming(codec);
                hda_check_power_state(codec, 0x1a, 12);
                hda_check_power_state(codec, 0x3c, 12);
                //spec->headset_enable = 2;
        }
        else if (spec->headset_enable == 2)
        {
                mycodec_info(codec, "cs_8409_headcapture_real enable 2\n");
                //cs_8409_headcapture_real2(codec);
        }

        mycodec_info(codec, "cs_8409_headcapture_real end\n");
}


static void cs_8409_headcapturestop_real(struct hda_codec *codec)
{
        //int retval;

        mycodec_info(codec, "cs_8409_headcapturestop_real start\n");

        cs_8409_disable_headset_mike_streaming(codec);

        mycodec_info(codec, "cs_8409_headcapturestop_real end\n");
}

