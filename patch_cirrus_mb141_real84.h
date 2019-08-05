
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


// cant decide if to have this at end or beginning
// I think end is better - also means dont have extra forward function definitions

static void cs_8409_boot_setup_real_ssm3(struct hda_codec *codec)
{

        // so now really dont know whay I skipped all this - maybe because they
        // almost entirely reads??
        // - except it does clear all the pin configs
        // plus does a DBL init

        int retval;

        dev_info(hda_codec_dev(codec), "command cs_8409_boot_setup_real_ssm3 start\n");

        // all evidence is this is identical to MB 14,3 version
        setup_reset_and_clear_ssm3(codec);
        //setup_reset_and_clear(codec);

        // read parameters from all nodes - excluding VirtualWidgets

        // the loop over node counts calls AppleHDAWidgetFactory::createAppleHDAWidget(DevIdStruct*)
        // which Im assuming calls the initForNodeID functions

        // all evidence is this is identical to MB 14,3 version
        init_read_all_nodes_ssm3(codec);
        //init_read_all_nodes(codec);

        // all evidence is this is identical to MB 14,3 version
        read_vendor_node_ssm3(codec);
        //read_vendor_node(codec);

        // all evidence is this is identical to MB 14,3 version
        init_read_coefs_ssm3(codec);
        //init_read_coefs(codec);


        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301

        // all evidence is this is identical to MB 14,3 version
        read_virtual_widgets_ssm3(codec);
        //read_virtual_widgets(codec);

        // all evidence is this is identical to MB 14,3 version
        //init_for_node_id_ssm3(codec);
        init_for_node_vendor(codec);

        // this is determineSpeakerID
        // this does not make sense - this just checks a GPIO pin??

        determine_speaker_id(codec, 0x8);

        determine_speaker_id(codec, 0xc);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);


        // all evidence is this is identical to MB 14,3 version
        enable_i2c_ssm3(codec);
        //enable_i2c(codec);

        // all evidence is this is identical to MB 14,3 version - except for the mask
        enable_GPIforUR(codec, 0xd);


        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001); // 0x04770301


        // all evidence is this is identical to MB 14,3 version - except for the mask
        //external_control_GPIO_ssm3(codec);

        external_control_GPIO(codec, 0xf);


        putative_setup_mic_ssm3(codec);


        //external_control_GPIO2_clear_2_ssm3(codec);
        //external_control_GPIO2_set_2_ssm3(codec);

        external_control_GPIO(codec, 0xf);


        putative_setup_mic2_ssm3(codec);


        //setup_amps_reset_ssm3(codec);

        setup_amps_reset_i2c_ssm3(codec);

        retval = read_gpio_status_check(codec);


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


        //read_gpio_status1_ssm3(codec);

        //read_gpio_status2_ssm3(codec);

        //read_gpio_status3_ssm3(codec);


	// why 3 reads here - they seem to return the exact same data each time
        retval = read_gpio_status_check(codec);

        retval = read_gpio_status_check(codec);

        retval = read_gpio_status_check(codec);


        setup_mic3_ssm3(codec);

        setup_mic_vol4_ssm3(codec);

        setup_mic_vol5_ssm3(codec);

        setup_mic4_ssm3(codec);

        setup_mic5_ssm3(codec);

        setup_mic_vol6_ssm3(codec);


        dev_info(hda_codec_dev(codec), "command cs_8409_boot_setup_real_ssm3 end\n");
}


static void play_setup_amp_ssm3(struct hda_codec *codec, int amp_address, int amp_volume)
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

        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0005, 0x0000, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0001, 0x0011, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0003, amp_volume, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0004, 0x0051, 1); // snd_hda
        cs_8409_vendor_i2cRead(codec, amp_address, 0x0002, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0002, 0x0032, 1); // snd_hda
        cs_8409_vendor_i2cRead(codec, amp_address, 0x0002, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0002, 0x0032, 1); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0000, 0x0000, 1); // snd_hda

}


static void cs_8409_play_real_ssm3(struct hda_codec *codec)
{
        int retval;
        //int retval1;
        //int retval2;

        printk("snd_hda_intel: command nid cs_8409_play_real_ssm3 start");


        retval = snd_hda_codec_read_check(codec, 0x00, 0, AC_VERB_PARAMETERS, 0x00000000, 0x10138409, 1); // 0x000f0000

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);


        //play_mic_fixup_ssm3(codec);


        // all evidence is this is identical to MB 14,3 version
        //play_setup_TDM_282a_ssm3(codec);

        play_setup_TDM_amps12(codec, 1);

        //play_setup_amps12_ssm3(codec);

        // we select the amp addresses in this function
        play_setup_amps12(codec);


        // all evidence is this is identical to MB 14,3 version
        //play_setup_TDM_2c2e_ssm3(codec);

        play_setup_TDM_amps34(codec);

        //play_setup_amps34_ssm3(codec);

        // we select the amp addresses in this function
        play_setup_amps34(codec);


        // all evidence is this is identical to MB 14,3 version
        //play_sync_converters_ssm3(codec);

        play_sync_converters_on(codec);


        printk("snd_hda_intel: command nid cs_8409_play_real_ssm3 end");

}


static void playstop_disable_amp_ssm3(struct hda_codec *codec, int amp_address)
{
        //int retval;

//      snd_hda: # i2cWrite: 
//      snd_hda i2cWrite      i2c address 0x2c i2c            reg 0x0001 i2c data 0x0001   reg anal: PowerControl            : PowerDown BVSenseOn

        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0000, 0x0001, 1); // snd_hda

}

static void cs_8409_playstop_real_ssm3(struct hda_codec *codec)
{
        //int retval;
        //struct cs_spec *spec = codec->spec;

        //cs_8409_playstop_data_ssm3(codec);

        printk("snd_hda_intel: command nid cs_8409_playstop_real_ssm3 start");

        playstop_sync_converters_off(codec);

        playstop_disable_amps12(codec);

        playstop_disable_TDM_amps12(codec);

        playstop_disable_amps34(codec);

        playstop_disable_TDM_amps34(codec);

        // for some reason Apple duplicates the amp disable here??

        playstop_disable_amps12(codec);

        playstop_disable_amps34(codec);


        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

        //retval = snd_hda_codec_read_check(codec, 0x22, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 1636); // 0x022f0500
        //retval = snd_hda_codec_read_check(codec, 0x23, 0, AC_VERB_GET_POWER_STATE, 0x00000000, 0x00000033, 1637); // 0x023f0500
        //hda_set_node_power_state(codec, 0x22, AC_PWRST_D3);
        //hda_set_node_power_state(codec, 0x23, AC_PWRST_D3);


        printk("snd_hda_intel: command nid cs_8409_playstop_real_ssm3 end");

}
