
static int tdm_in_use(struct hda_codec *codec, int where_flag)
{
        int coef_ret = 0;
        int coef_idx = 0;

        // re-implementation of AppleHDATDMBusManagerCS8409::tdmInUse
	dev_info(hda_codec_dev(codec), "command tdmInUse start %d\n", where_flag);

        // note on OSX the coef get functions returns a status value with read value stored in passed address
        // on linux it seems -1 is an error return

        coef_ret = cs_8409_vendor_coef_get(codec, 0x19);

        //if (coef_ret == -1) error;

        coef_idx = 0x1a;

        do {

                if ((short)coef_ret >= 0) {
	            dev_info(hda_codec_dev(codec), "command tdmInUse 1 end %d\n", where_flag);
                    return 1;
                }

                coef_ret = cs_8409_vendor_coef_get(codec, coef_idx);

                //if (coef_ret == -1) error;

                coef_idx++;

        } while (coef_idx <= 0x57);

	dev_info(hda_codec_dev(codec), "command tdmInUse 0 end %d\n", where_flag);

        return 0;

}

static void init_for_node_vendor(struct hda_codec *codec)
{
	int retval;
        int coef_idx = 0x1a;
        //int coef_ret = 0;

	// this is AppleHDAFunctionGroupCS8409::initForNodeID

	dev_info(hda_codec_dev(codec), "command init_for_node_vendor start\n");

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

        // this is determineSpeakerID
        // this does not make sense - this just checks a GPIO pin??

        // this is call AppleHDAFunctionGroup::setGPIOEnable in determineSpeakerID
        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_MASK, 0x00000004); // 0x00171604
//      snd_hda:     gpio enable 1 0x04

        //retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_GPIO_DATA, 0x00000000, 0x00000004, 1672); // 0x001f1500
        retval = snd_hda_codec_read(codec, codec->core.afg, 0, AC_VERB_GET_GPIO_DATA, 0x00000000); // 0x001f1500
	dev_info(hda_codec_dev(codec), "command init_for_node_vendor gpio data 0x%08x\n", retval);
//      snd_hda:     gpio data 1 0x04

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

	dev_info(hda_codec_dev(codec), "command init_for_node_vendor end\n");

}

static void setup_gpio_set_20(struct hda_codec *codec)
{

        // plausibly AppleHDAFunctionGroupExternalControl_GPIO::publicSetExternalControlState(bool)

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DIRECTION, 0x00000022); // 0x00171722
//      snd_hda:     gpio direction 1 0x22 in in out in in in out in
        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_DATA, 0x00000022); // 0x00171522
//      snd_hda:     gpio data 1 0x22
        snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_GPIO_MASK, 0x00000027); // 0x00171627
//      snd_hda:     gpio enable 1 0x27

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000003); // 0x00170503
        //hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);

}


static int read_gpio_status_check(struct hda_codec *codec)
{
        int retval;

        // plausibly  AppleHDAFunctionGroupCS8409::readStatusAndClearInterrupt

        // should these be done powered down??
        // lets check power state here

        //retval = snd_hda_codec_read_check(codec, codec->core.afg, 0, AC_VERB_GET_GPIO_DATA, 0x00000000, 0x00000027, 11915); // 0x001f1500
        retval = snd_hda_codec_read(codec, codec->core.afg, 0, AC_VERB_GET_GPIO_DATA, 0x00000000); // 0x001f1500
//      snd_hda:     gpio data 1 0x27

	dev_info(hda_codec_dev(codec), "command read_gpio_status_check %x\n", retval);

        return retval;
}


static void setup_amps_reset_i2c(struct hda_codec *codec)
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


static int cs_8409_boot_setup_real(struct hda_codec *codec)
{
        int retval;

        //struct cs_spec *spec = codec->spec;
        //hda_nid_t beep_nid = spec->beep_nid;

	dev_info(hda_codec_dev(codec), "command cs_8409_boot_setup_real start\n");


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


        //setup_jack_pin_config(codec);

        enable_i2c(codec);

        enable_GPIforUR(codec);

        external_control_GPIO(codec);

        //putative_setup_mic(codec);

        external_control_GPIO2_clear_2(codec);

        external_control_GPIO2_set_2(codec);

        //putative_setup_mic2(codec);

        //putative_setup_mic3(codec);

        //putative_setup_mic4(codec);



        //setup_amps_reset(codec);
	setup_amps_reset_i2c(codec);


        //read_gpio_status(codec);

        retval = read_gpio_status_check(codec);


        //putative_setup_mic5(codec);

        //setup_jack_nids(codec);

        //setup_jack_nids2(codec);

        //setup_jack_vol1(codec);

        //setup_jack_vol2(codec);


        setup_TDM_6462(codec);

        setup_amps_6462(codec);

        setup_TDM_7472(codec);

        setup_amps_7472(codec);

        sync_converters(codec);


        sync_converters1(codec);

        amps_disable_6462(codec);

        putative_tdm_disable_6462(codec);

        amps_disable_7472(codec);

        putative_tdm_disable_7472(codec);


        putative_enable1_TDM_6462(codec);

        amps_disable2_6462(codec);

        putative_enable1_TDM_7472(codec);

        amps_disable2_7472(codec);

        sync_converters2(codec);


        enable2_TDM2_6462(codec);

        amps_enable2_6462(codec);

        enable2_TDM2_7472(codec);

        amps_enable2_7472(codec);

        sync_converters3(codec);


        sync_converters4(codec);

        amps_disable3_6462(codec);

        putative_disable3_TDM_6462(codec);

        amps_disable3_7472(codec);

        putative_disable3_TDM_7472(codec);


        //setup_mic_vol2(codec);

        //setup_mic_vol3(codec);


        //read_gpio_status1(codec);

        //read_gpio_status2(codec);

        //read_gpio_status3(codec);

        // why 3 reads here - they seem to return the exact same data each time
        retval = read_gpio_status_check(codec);

        retval = read_gpio_status_check(codec);

        retval = read_gpio_status_check(codec);


        //setup_mic3(codec);

        //setup_mic_vol4(codec);

        //setup_mic_vol5(codec);

        //setup_mic4(codec);

        //setup_mic5(codec);

        //setup_mic_vol6(codec);

        //setup_mic7(codec);

        //setup_mic_vol7(codec);


	dev_info(hda_codec_dev(codec), "command cs_8409_boot_setup_real end\n");

	return 0;
}


static void play_setup_amp(struct hda_codec *codec, int amp_address, int amp_volume)
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
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0015, 0x0001, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0016, 0x0000, 0); // snd_hda
        cs_8409_vendor_i2cWrite(codec, amp_address, 0x0018, 0x0000, 0); // snd_hda
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


static void play_setup_TDM_sample_rate(struct hda_codec *codec)
{
//      snd_hda: # AppleHDATDMBusManagerCS8409::setupTDMPath:
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000200, 16 ); //   coef read 16
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, 0x0200, 0x00000000, 20 ); //   coef write 20

//      snd_hda: # AppleHDATDMBusManagerCS8409::setSampleRate:
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0001, 0x0200, 0x00000200, 25 ); // coef write mask 25
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0005, 0x0001, 0x00000001, 31 ); // coef write mask 31
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0004, 0x08ff, 0x000008ff, 37 ); // coef write mask 37
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0001, 0x0200, 0xundef, 0x00000200, 25 ); // coef write mask 25
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0005, 0x0001, 0xundef, 0x00000001, 31 ); // coef write mask 31
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0004, 0x08ff, 0xundef, 0x000008ff, 37 ); // coef write mask 37
}

static void play_setup_TDM_proper_amps12(struct hda_codec *codec)
{
//      snd_hda: # AppleHDATDMBusManagerCS8409::setupTDMPath: 
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00008800, 44 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 44
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0019, 0x0800, 0x00000000, 48 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 48
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001a, 0x0000, 0x00008820, 52 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 52
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001a, 0x0820, 0x00000000, 56 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 56

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0000, 0x0000, 0x00009000, 60 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 60
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0xb000, 0x00000000, 64 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 64
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0004, 0x0000, 0x000008ff, 68 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 68
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0004, 0x08ff, 0x00000000, 72 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 72
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0000, 0x9000, 0x00000000, 76 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 76

        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0003, 0x8000, 0x00008000, 80 ); // coef write mask 80
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0005, 0x0001, 0x00000001, 86 ); // coef write mask 86
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0082, 0x5401, 0x00000001, 92 ); // coef write mask 92
        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0002, 0x0280, 0x00000280, 98 ); // coef write mask 98
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0003, 0x8000, 0xundef, 0x00008000, 80 ); // coef write mask 80
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0005, 0x0001, 0xundef, 0x00000001, 86 ); // coef write mask 86
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0082, 0x5401, 0xundef, 0x00000001, 92 ); // coef write mask 92
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0002, 0x0280, 0xundef, 0x00000280, 98 ); // coef write mask 98

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000200, 104 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef read 104
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, 0x0220, 0x00000000, 108 ); // AppleHDATDMBusManagerCS8409::setupTDMPath  coef write 108

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: AppleHDATDMBusManagerCS8409::tdmInUse:
        //snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00000800, 112 ); //   coef read 112

        tdm_in_use(codec, 1);

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: 
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006b, 0x001f, 0x00000000, 117 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 117
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x00000000, 121 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef read 121
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x400f, 0x00000000, 125 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 125

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00b6 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  write verb 128
}

static void play_setup_TDM_amps12(struct hda_codec *codec, int setrate)
{
        int retval;

        // this seems to be setup for node 0x02 chain - which seems to use node 0x24 and amps 0x64 and 0x62 (or 0x28 0x2a)

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004033); // 0x00224033
//      snd_hda:     stream format 2 [('CHAN', 4), ('RATE', 44100), ('BITS', 24), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000010); // 0x00270610
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 1)]

        if (setrate)
                play_setup_TDM_sample_rate(codec);


        play_setup_TDM_proper_amps12(codec);


        // enable output node 0x24

        //retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 132); // 0x024f0700
        retval = snd_hda_codec_read(codec, 0x24, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000); // 0x024f0700
        snd_hda_codec_write(codec, 0x24, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000040); // 0x02470740
//      snd_hda:     36 ['AC_PINCTL_OUT_EN']

}


static void play_setup_amps12(struct hda_codec *codec)
{
        if (codec->core.subsystem_id == 0x106b3900) {
		// use reduced volume - from 0x01 to 0x30 - now passing as argument
                play_setup_amp(codec, 0x64, 0x30);
                play_setup_amp(codec, 0x62, 0x30);
        }
        else if (codec->core.subsystem_id == 0x106b3300) {
                //setup_node_alpha_ssm3(codec);
        }
        else {
                printk("snd_hda_intel: UNKNOWN subsystem id 0x%08x",codec->core.subsystem_id);
        }
}


static void play_setup_TDM_proper_amps34(struct hda_codec *codec)
{
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001b, 0x0000, 0x00008840, 1407 ); //   coef read 1407
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001b, 0x0840, 0x00000000, 1411 ); //   coef write 1411
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001c, 0x0000, 0x00008860, 1415 ); //   coef read 1415
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001c, 0x0860, 0x00000000, 1419 ); //   coef write 1419

        // the following actually reads from 0x19 to 0x57 in a loop if the snd_hda_coef_item returns 0 till the read value
        // does not have the word sign bit set (ie 0x8000) or finish all 0x57

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: AppleHDATDMBusManagerCS8409::tdmInUse:
        //snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00000800, 1423 ); //   coef read 1423

        tdm_in_use(codec, 2);

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: 
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006b, 0x001f, 0x00000000, 1428 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 1428
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x0000400f, 1432 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef read 1432
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x400f, 0x00000000, 1436 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 1436

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00b6 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  write verb 1439

}

static void play_setup_TDM_amps34(struct hda_codec *codec)
{
        int retval;

        // this seems to be setup for node 0x03 chain - which seems to use node 0x25 and amps 0x74 and 0x72 (or 0x2c and 0x2e)

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_STREAM_FORMAT, 0x00004033); // 0x00324033
//      snd_hda:     stream format 3 [('CHAN', 4), ('RATE', 44100), ('BITS', 24), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000012); // 0x00370612
//      snd_hda:     conv stream channel map 3 [('CHAN', 2), ('STREAMID', 1)]


        play_setup_TDM_proper_amps34(codec);


        // enable output on node 0x25

        //retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000000, 1443); // 0x025f0700
        retval = snd_hda_codec_read(codec, 0x25, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000); // 0x025f0700
        snd_hda_codec_write(codec, 0x25, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000040); // 0x02570740
//      snd_hda:     37 ['AC_PINCTL_OUT_EN']

}


static void play_setup_amps34(struct hda_codec *codec)
{
        if (codec->core.subsystem_id == 0x106b3900) {
		// use reduced volume - from 0x01 to 0x30 - now passing as argument
                play_setup_amp(codec, 0x74, 0x30);
                play_setup_amp(codec, 0x72, 0x30);
        }
        else if (codec->core.subsystem_id == 0x106b3300) {
                //setup_node_alpha_ssm3(codec);
        }
        else {
                printk("snd_hda_intel: UNKNOWN subsystem id 0x%08x",codec->core.subsystem_id);
        }
}

static void play_sync_converters_on(struct hda_codec *codec)
{
        int retval;

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
        retval = snd_hda_codec_read(codec, 0x02, 0, AC_VERB_GET_CONV, 0x00000000); // 0x002f0600
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 1)]

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00270600
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]


        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0001, 0x00000000, 2716 ); // coef write mask 2716
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0001, 0xundef, 0x00000000, 2716 ); // coef write mask 2716


//      snd_hda: # AppleHDAFunctionGroupCS8409::syncConverters:
        //retval = snd_hda_codec_read_check(codec, 0x03, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000012, 2722); // 0x003f0600
        retval = snd_hda_codec_read(codec, 0x03, 0, AC_VERB_GET_CONV, 0x00000000); // 0x003f0600
//      snd_hda:     conv stream channel map 3 [('CHAN', 2), ('STREAMID', 1)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00370600
//      snd_hda:     conv stream channel map 3 [('CHAN', 0), ('STREAMID', 0)]


        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0003, 0x00000001, 2724 ); // coef write mask 2724
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0003, 0xundef, 0x00000001, 2724 ); // coef write mask 2724


        // and reset back to normal channel mapping

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000010); // 0x00270610
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 1)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000012); // 0x00370612
//      snd_hda:     conv stream channel map 3 [('CHAN', 2), ('STREAMID', 1)]


}


static void cs_8409_play_real(struct hda_codec *codec)
{
        int retval;
        //struct cs_spec *spec = codec->spec;

        //cs_8409_play_data(codec);

        printk("snd_hda_intel: command nid cs_8409_play_real start");

        retval = snd_hda_codec_read_check(codec, 0x00, 0, AC_VERB_PARAMETERS, 0x00000000, 0x10138409, 1); // 0x000f0000

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000); // 0x00170500
        hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);


        play_setup_TDM_amps12(codec, 1);

        play_setup_amps12(codec);


        play_setup_TDM_amps34(codec);

        play_setup_amps34(codec);


        play_sync_converters_on(codec);

        printk("snd_hda_intel: command nid cs_8409_play_real end");

}


static void playstop_disable_amp(struct hda_codec *codec, int amp_address)
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

static void playstop_sync_converters_off(struct hda_codec *codec)
{
        int retval;

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
        retval = snd_hda_codec_read(codec, 0x02, 0, AC_VERB_GET_CONV, 0x00000000); // 0x002f0600
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 1)]

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00270600
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0002, 0x00000003, 6 ); // coef write mask 6
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0002, 0xundef, 0x00000003, 6 ); // coef write mask 6

//      snd_hda: # AppleHDAFunctionGroupCS8409::syncConverters:
        //retval = snd_hda_codec_read_check(codec, 0x03, 0, AC_VERB_GET_CONV, 0x00000000, 0x00000012, 12); // 0x003f0600
        retval = snd_hda_codec_read(codec, 0x03, 0, AC_VERB_GET_CONV, 0x00000000); // 0x003f0600
//      snd_hda:     conv stream channel map 3 [('CHAN', 2), ('STREAMID', 1)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00370600
//      snd_hda:     conv stream channel map 3 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0000, 0x00000002, 14 ); // coef write mask 14
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0017, 0x0000, 0xundef, 0x00000002, 14 ); // coef write mask 14

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0017, 0x0000, 0x00000000, 20 ); //   coef read 20
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0018, 0x0000, 0x00000000, 24 ); //   coef read 24

        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0001, 0x0220, 0x00000220, 28 ); // coef write mask 28
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0001, 0x0220, 0xundef, 0x00000220, 28 ); // coef write mask 28

        // and reset back to normal channel mapping

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000010); // 0x00270610
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 1)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000012); // 0x00370612
//      snd_hda:     conv stream channel map 3 [('CHAN', 2), ('STREAMID', 1)]

}


static void playstop_disable_amps12(struct hda_codec *codec)
{
        if (codec->core.subsystem_id == 0x106b3900) {
                playstop_disable_amp(codec, 0x64);
                playstop_disable_amp(codec, 0x62);
        }
        else if (codec->core.subsystem_id == 0x106b3300) {
                //setup_node_alpha_ssm3(codec);
        }
        else {
                printk("snd_hda_intel: UNKNOWN subsystem id 0x%08x",codec->core.subsystem_id);
        }
}

static void playstop_disable_TDM_proper_amps12(struct hda_codec *codec)
{
        //int retval;

        // this seems to be setup for node 0x02 chain - which seems to use node 0x24 and amps 0x64 and 0x62 (or 0x28 and 0x2a)

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR:
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00000800, 341 ); //   coef read 341
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0019, 0x8800, 0x00000000, 345 ); //   coef write 345
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001a, 0x0000, 0x00000820, 349 ); //   coef read 349
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001a, 0x8820, 0x00000000, 353 ); //   coef write 353

        //      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR: AppleHDATDMBusManagerCS8409::tdmInUse:
        //snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0019, 0x0000, 0x00008800, 357 ); //   coef read 357
        //snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001a, 0x0000, 0x00008820, 361 ); //   coef read 361
        //snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001b, 0x0000, 0x00000840, 365 ); //   coef read 365

        tdm_in_use(codec, 30);

//      snd_hda: # AppleHDATDMBusManagerCS8409::configureTDMUR:
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x006b, 0x001f, 0x00000000, 370 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 370
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x0000400f, 374 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef read 374
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x400f, 0x00000000, 378 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  coef write 378

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00b6 ); // AppleHDATDMBusManagerCS8409::configureTDMUR  write verb 381
}


static void playstop_disable_TDM_amps12(struct hda_codec *codec)
{
        int retval;

        playstop_disable_TDM_proper_amps12(codec);


        // set to defaults and disable output

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00270600
//      snd_hda:     conv stream channel map 2 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_codec_write(codec, 0x02, 0, AC_VERB_SET_STREAM_FORMAT, 0x00000000); // 0x00220000
//      snd_hda:     stream format 2 [('CHAN', 1), ('RATE', 48000), ('BITS', 8), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        //retval = snd_hda_codec_read_check(codec, 0x24, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000040, 387); // 0x024f0700
        retval = snd_hda_codec_read(codec, 0x24, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000); // 0x024f0700
        snd_hda_codec_write(codec, 0x24, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x02470700
//      snd_hda:     36 []

}

static void playstop_disable_amps34(struct hda_codec *codec)
{
        if (codec->core.subsystem_id == 0x106b3900) {
                playstop_disable_amp(codec, 0x74);
                playstop_disable_amp(codec, 0x72);
        }
        else if (codec->core.subsystem_id == 0x106b3300) {
                //setup_node_alpha_ssm3(codec);
        }
        else {
                printk("snd_hda_intel: UNKNOWN subsystem id 0x%08x",codec->core.subsystem_id);
        }
}


static void playstop_disable_TDM_proper_amps34(struct hda_codec *codec)
{
        //int retval;

        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001b, 0x0000, 0x00000840, 694 ); //   coef read 694
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001b, 0x8840, 0x00000000, 698 ); //   coef write 698
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x001c, 0x0000, 0x00000860, 702 ); //   coef read 702
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x001c, 0x8860, 0x00000000, 706 ); //   coef write 706

        snd_hda_coef_item(codec, 2, CS8409_VENDOR_NID, 0x0082, 0x0001, 0x00005401, 710 ); // coef write mask 710
//      snd_hda_coef_item_masked(codec, 2, CS8409_VENDOR_NID, 0x0082, 0x0001, 0xundef, 0x00005401, 710 ); // coef write mask 710

        // AppleHDATDMBusManagerCS8409::setupTDMPath or AppleHDATDMBusManagerCS8409::disableTDMPath
        snd_hda_coef_item(codec, 0, CS8409_VENDOR_NID, 0x0001, 0x0000, 0x00000220, 716 ); //   coef read 716
        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0001, 0x0200, 0x00000000, 720 ); //   coef write 720

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


        snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x0071, 0x0000, 0x00000000, 977 ); //   coef write 977

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, 0x7f0, 0x00000000);

}

static void playstop_disable_TDM_amps34(struct hda_codec *codec)
{
        int retval;

        playstop_disable_TDM_proper_amps34(codec);


        // set to defaults and disable output

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000); // 0x00370600
//      snd_hda:     conv stream channel map 3 [('CHAN', 0), ('STREAMID', 0)]

        snd_hda_codec_write(codec, 0x03, 0, AC_VERB_SET_STREAM_FORMAT, 0x00000000); // 0x00320000
//      snd_hda:     stream format 3 [('CHAN', 1), ('RATE', 48000), ('BITS', 8), ('RATE_MUL', 1), ('RATE_DIV', 1)]

        //retval = snd_hda_codec_read_check(codec, 0x25, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000, 0x00000040, 986); // 0x025f0700
        retval = snd_hda_codec_read(codec, 0x25, 0, AC_VERB_GET_PIN_WIDGET_CONTROL, 0x00000000); // 0x025f0700
        snd_hda_codec_write(codec, 0x25, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000); // 0x02570700
//      snd_hda:     37 []

}


static void cs_8409_playstop_real(struct hda_codec *codec)
{
        //int retval;
        //struct cs_spec *spec = codec->spec;

        //cs_8409_playstop_data(codec);

        printk("snd_hda_intel: command nid cs_8409_playstop_real start");

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


        printk("snd_hda_intel: command nid cs_8409_playstop_real end");

}
