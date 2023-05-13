//#include <linux/ctype.h>
#include <linux/timer.h>
#include <linux/bitops.h>

#include <linux/version.h>

//#include "hda_generic.h"

//#include "patch_cs8409.h"



// define some explicit debugging print functions
// under flag control so can be easily turned off

#define TESTING 0


#ifdef MYSOUNDDEBUGFULL
#define mycodec_info(codec, fmt, args...) \
        dev_info(hda_codec_dev(codec), fmt, ##args)
#define mycodec_i2c_info(codec, fmt, args...) \
        dev_info(hda_codec_dev(codec), fmt, ##args)
#define mydev_info(codecdev, fmt, args...) \
        dev_info(codecdev, fmt, ##args)
#define mycodec_dbg(codec, fmt, args...) \
        dev_info(hda_codec_dev(codec), fmt, ##args)
#define myprintk_dbg(fmt, args...) \
        printk(fmt, ##args)
#define myprintk(fmt, args...) \
        printk(fmt, ##args)
#else
#define mycodec_dbg(...)
#define myprintk_dbg(...)
#ifdef MYSOUNDDEBUG
#define mycodec_info(codec, fmt, args...) \
        dev_info(hda_codec_dev(codec), fmt, ##args)
#define mycodec_i2c_info(codec, fmt, args...) \
        dev_info(hda_codec_dev(codec), fmt, ##args)
#define mydev_info(codecdev, fmt, args...) \
        dev_info(codecdev, fmt, ##args)
#define myprintk(fmt, args...) \
        printk(fmt, ##args)
#else
#define mycodec_info(...)
#define mycodec_i2c_info(...)
#define mydev_info(...)
#define myprintk(...)
#endif
#endif


/*

     info for enum for checking initial assignment

enum {
        AC_JACK_LINE_OUT,                 0x0
        AC_JACK_SPEAKER,                  0x1
        AC_JACK_HP_OUT,                   0x2
        AC_JACK_CD,                       0x3
        AC_JACK_SPDIF_OUT,                0x4
        AC_JACK_DIG_OTHER_OUT,            0x5
        AC_JACK_MODEM_LINE_SIDE,          0x6
        AC_JACK_MODEM_HAND_SIDE,          0x7
        AC_JACK_LINE_IN,                  0x8
        AC_JACK_AUX,                      0x9
        AC_JACK_MIC_IN,                   0xa
        AC_JACK_TELEPHONY,                0xb
        AC_JACK_SPDIF_IN,                 0xc
        AC_JACK_DIG_OTHER_IN,             0xd
        AC_JACK_OTHER = 0xf,              0xf
};
 */


/*

        it appears from the cs42l42 definitions in patch_cs8409.h that 
        each nid is associated with a specific Audio Serial Port

        nids as used in Apple
        output
        speaker       0x002 -> 0x024   CS8409_PIN_ASP1_OUT_A -> CS8409_PIN_ASP1_TRANSMITTER_A
        speaker       0x003 -> 0x025   CS8409_PIN_ASP1_OUT_B -> CS8409_PIN_ASP1_TRANSMITTER_B
        headphones    0x00a -> 0x02c   CS8409_PIN_ASP2_OUT_A -> CS8409_PIN_ASP2_TRANSMITTER_A
        input
        headset mike  0x03c -> 0x01a   CS8409_PIN_ASP2_RECEIVER_A -> CS8409_PIN_ASP2_IN_A
        macbook pros
        internal mike 0x044 -> 0x022   CS8409_PIN_DMIC1_IN -> CS8409_PIN_DMIC1
        linein        0x045 -> 0x023   CS8409_PIN_DMIC2_IN -> CS8409_PIN_DMIC2
        imacs
        linein        0x044 -> 0x022   CS8409_PIN_DMIC1_IN -> CS8409_PIN_DMIC1
        internal mike 0x045 -> 0x023   CS8409_PIN_DMIC2_IN -> CS8409_PIN_DMIC2

 */


/* CS8409 */
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 13, 0)
// for the moment leave my old definition names but map to the new module enum values
#define CS8409_IDX_DEV_CFG     CS8409_PIN_AFG
#define CS8409_VENDOR_NID      CS8409_PIN_VENDOR_WIDGET
#define CS8409_BEEP_NID        CS8409_PIN_BEEP_GEN
#else
#define CS8409_IDX_DEV_CFG     0x01
#define CS8409_VENDOR_NID      0x47
#define CS8409_BEEP_NID        0x46
#endif


#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 13, 0)

// nid devs based on Dell fixups
#define CS8409_CS42L83_HP_PIN_NID                       CS8409_PIN_ASP2_TRANSMITTER_A
#define CS8409_CS42L83_HP_MIC_PIN_NID                   CS8409_PIN_ASP2_RECEIVER_A
#define CS8409_CS42L83_MACBOOK_MIC_PIN_NID              CS8409_PIN_DMIC1_IN
#define CS8409_CS42L83_MACBOOK_LINEIN_PIN_NID           CS8409_PIN_DMIC2_IN
#define CS8409_CS42L83_IMAC_MIC_PIN_NID                 CS8409_PIN_DMIC2_IN
#define CS8409_CS42L83_IMAC_LINEIN_PIN_NID              CS8409_PIN_DMIC1_IN
#define CS8409_CS42L83_MACBOOK_LINEIN_ADC_PIN_NID       CS8409_PIN_DMIC2
#define CS8409_CS42L83_IMAC_LINEIN_ADC_PIN_NID          CS8409_PIN_DMIC1

// add in coding based on Dell fixups

#define CS42L83_I2C_ADDR	0x90	// for some reason given as (0x48 << 1)
#define CS8409_CS42L83_RESET	0x02	// gpio interrupt mask - see cs42l83_external_control_GPIO
#define CS8409_CS42L83_INT	0x01	// gpio interrupt mask

#else

#define CS8409_CS42L83_HP_PIN_NID                       0x2c
#define CS8409_CS42L83_HP_MIC_PIN_NID                   0x3c
#define CS8409_CS42L83_MACBOOK_MIC_PIN_NID              0x44
#define CS8409_CS42L83_MACBOOK_LINEIN_PIN_NID           0x45
#define CS8409_CS42L83_IMAC_MIC_PIN_NID                 0x45
#define CS8409_CS42L83_IMAC_LINEIN_PIN_NID              0x44
#define CS8409_CS42L83_MACBOOK_LINEIN_ADC_PIN_NID       0x23
#define CS8409_CS42L83_IMAC_LINEIN_ADC_PIN_NID          0x22

#endif


#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 13, 0)

// this is a list of i2c commands for init
static const struct cs8409_i2c_param cs42l83_init_reg_seq[] = {
	//{ 0x0000, 0x00 },
};

struct sub_codec cs8409_cs42l83_codec = {
        .addr = CS42L83_I2C_ADDR,
        .reset_gpio = CS8409_CS42L83_RESET,
        .irq_mask = CS8409_CS42L83_INT,
        .init_seq = cs42l83_init_reg_seq,
        .init_seq_num = ARRAY_SIZE(cs42l83_init_reg_seq),
        .hp_jack_in = 0,
        .mic_jack_in = 0,
        .linein_jack_in = 0,
        .force_status_change = 1,
        .paged = 1,
        .suspended = 1,
        .no_type_dect = 0,
};


// define the fixed stream format

const struct hda_pcm_stream cs42l83_apple_pcm_analog_playback = {
        .rates = SNDRV_PCM_RATE_44100, /* fixed rate */
};

const struct hda_pcm_stream cs42l83_apple_pcm_analog_capture = {
        .rates = SNDRV_PCM_RATE_44100, /* fixed rate */
};


#endif

/*

        register mask values collated from Microsoft cs4208_39.inf file plus the new Dell cs8409 module

        CS8409_DEV_CFG1,                // reg 0x00
               0xb008     +PLL1/2_EN, +I2C_EN - .inf file
               0xb000     +PLL1/2_EN          - .inf file
               0x9008     +PLL1_EN, +I2C_EN   - .inf file
               0x9000     +PLL1_EN            - .inf file
        CS8409_DEV_CFG2,                // reg 0x01
               0x0006     ASP1/2_EN = 0, ASP1/2_STP = 1
               0x0066     ASP1/2_EN = 1, ASP1/2_STP = 1
               0x0022     ASP1_EN = 1, ASP1_STP = 1 ?
               0x0044     ASP2_EN = 1, ASP2_STP = 1 ?
               0x0200     seen in Apple but unknown
        CS8409_DEV_CFG3,                // reg 0x02
               0x0a80     ASP1/2_BUS_IDLE=10, +GPIO_I2C
               0x0280     seen in Apple ASP1_BUS_IDLE=10?, +GPIO_I2C
        CS8409_ASP1_CLK_CTRL1,          // reg 0x03
               0x8000     ASP1: LCHI = 00h
        CS8409_ASP1_CLK_CTRL2,          // reg 0x04
               0x28ff     ASP1: MC/SC_SRCSEL=PLL1, LCPR=FFh
        CS8409_ASP1_CLK_CTRL3,          // reg 0x05
               0x0062     ASP1: MCEN=0, FSD=011, SCPOL_IN/OUT=0, SCDIV=1:4
               0b0110 0b0010
                          so FSD = 0x0060
               0x005a     ASP1: MCEN = 0, FSD = 010, SCPOL_IN/OUT = 1, SCDIV = 1:4
               0b0101 0b1010
                          so FSD = 0x0040, SCPOL_IN/OUT = 0x0010 or 0x0008?, SCDIV = 0x0002
               0x0001     seen in Apple but what bit is this?? MCEN??
        CS8409_ASP2_CLK_CTRL1,          // reg 0x06
               0x8000     ASP1: LCHI = 00h
        CS8409_ASP2_CLK_CTRL2,          // reg 0x07
               0x283f     ASP2: MC/SC_SRCSEL=PLL1, LCPR=3Fh
        CS8409_ASP2_CLK_CTRL3,          // reg 0x08
               0x805c     ASP2: 5050=1, MCEN=0, FSD=010, SCPOL_IN/OUT=1, SCDIV=1:16
               0b0101 0b1100
                          5050 = 0x8000?, FSD = 0x0040, SCPOL_IN/OUT = 0x0010 or 0x0008?, SCDIV=1:16 = 0x0004?
        CS8409_DMIC_CFG,                // reg 0x09
               0x0023     DMIC1_MO=10b, DMIC1/2_SR=1
               0x0033     seen in Apple
               0x00b3     seen in Apple
               0x01b3     seen in Apple
        CS8409_BEEP_CFG,                // reg 0x0a

        ASP2_Rx_NULL_INS_RMV,           // reg 0x11
               0x0001     seen in Apple
        ASP2_Rx_RATE1,                  // reg 0x12
               0xaccc     seen in Apple
        ASP2_Tx_NULL_INS_RMV,           // reg 0x14
               0x0100     seen in Apple
        ASP2_Tx_RATE1,                  // reg 0x15
               0xaaaa     seen in Apple
        ASP1_SYNC_CTRL,                 // reg 0x17
               0x0000     seen in Apple sync converters
               0x0001     seen in Apple sync converters
               0x0002     seen in Apple sync converters
               0x0003     seen in Apple sync converters
        ASP2_SYNC_CTRL,                 // reg 0x18
               0x0000     seen in Apple sync converters

        the following registers are defined per output nid
        from A to H for  nid 0x02 to 0x09 ASP1
        from A to H for  nid 0x0a to 0x11 ASP2
        the following registers are defined per input nid
        from A to H for  nid 0x12 to 0x19 ASP1
        from A to H for  nid 0x1a to 0x21 ASP2

        ASP1_A_TX_CTRL1                 // reg 0x19
               nide 0x02
               0x0800     seen in Apple - on
               0x8800     seen in Apple - off
        ASP1_A_TX_CTRL2                 // reg 0x1a
               nide 0x02
               0x0820     seen in Apple - on
               0x8820     seen in Apple - off
        ASP1_B_TX_CTRL1,                // reg 0x1b
               nide 0x03
               0x0840     seen in Apple - on
               0x8840     seen in Apple - off
        ASP1_B_TX_CTRL2,                // reg 0x1c
               nide 0x03
               0x0860     seen in Apple - on
               0x8860     seen in Apple - off

        ASP2_A_TX_CTRL1,                // reg 0x29
               nide 0x0a
               0x0800     seen in Apple - on
               0x8800     seen in Apple - off
        ASP2_A_TX_CTRL2,                // reg 0x2a
               nide 0x0a
               0x0820     seen in Apple - on
               0x8820     seen in Apple - off

        ASP2_A_RX_CTRL1,                // reg 0x49
               nide 0x1a
               0x0800     seen in Apple - on
               0x8800     seen in Apple - off
        ASP2_A_RX_CTRL2,                // reg 0x4a
               nide 0x1a
               0x0820     seen in Apple - on
               0x8820     seen in Apple - off

        CS8409_ASP1_INTRN_STS,          // reg 0x6b
               0x001f     seen in Apple
        CS8409_ASP2_INTRN_STS,          // reg 0x6c
               0x001f     seen in Apple

        CS8409_ASP_UNS_RESP_MASK,       // reg 0x71
               0x400f     seen in Apple
               0x800f     seen in Apple
               0xc00f     seen in Apple

        CS8409_PAD_CFG_SLW_RATE_CTRL    // reg 0x82
               it appears to contain 2 sort of separate items - the ASP1 and ASP2 enables and the DMIC1/DMIC2 SCL enables
               0xfc03     ASP1/2_xxx_EN=1, ASP1/2_MCLK_EN=0, DMIC1/2_SCL_EN=1 (was DMIC1_SCL_EN in comments but thinks thats wrong given below)
               0xfc01     (ASP1/2_xxx_EN = 1, ASP1/2_MCLK_EN = 0, DMIC1_SCL_EN = 1)
               0xff03     (ASP1/2_xxx_EN = 1, DMIC1/2_SCL_EN = 1)
               0xfd02     (ASP1/2_xxx_EN = 1, ASP1_MCLK_EN = 1, ASP2_MCLK_EN = 0, DMIC2_SCL_EN = 1)
               0xfe03     (ASP1/2_xxx_EN = 1, ASP1_MCLK_EN = 0, ASP2_MCLK_EN = 1, DMIC1/2_SCL_EN = 1)
                          so (ASP1_MCLK_EN is 0x0100 and ASP2_MCLK_EN is 0x0200)
               from the OSX codes we seem to have
               0xa800     ASP2_xxx_EN = 1, ASP1/2_MCLK_EN = 0
               0x5400     ASP1_xxx_EN = 1, ASP1/2_MCLK_EN = 0


 */

/*

        Interrupt analysis (mainly from cs42l42 manual)

        actual button presses are 0x01, 0x02 and button release 0x10
        for 0x1b7c 0x02 is a short release for buttons, 0x08 is reserved
        the mask bits for 0x1b7a seem to be 0xe7 for button detect defining 0x18 as the button detect interrupt(s)
        and 0xdc for actual button interrupts
        (0x1b79 is mask, 0x1b7b status; 0x1b7a is mask, 0x1b7c is presumed status, 0x131b is mask, 0x1308 status,
         0x1320 is mask, 0x130f status)

        0x1b79 Detect Interrupt Mask 1
               0x80     M_HSBIAS_SENSE
               0x40     M_TIP_SENSE_PLUG
	       0x20     M_TIP_SENSE_UNPLUG
        0x1b7b Detect Interrupt Status 1 - assumed - not documented in cs42l42 but listed in fig 4-45
               0x80     M_HSBIAS_SENSE - assumed
               0x40     M_TIP_SENSE_PLUG - assumed
	       0x20     M_TIP_SENSE_UNPLUG - assumed
        0x1b7a Detect Interrupt Mask 2 (Buttons)
               cs42l42 values documented:
               0x80     M_DETECT_TRUE_FALSE
               0x40     M_DETECT_FALSE_TRUE
               0x04     M_HSBIAS_HIZ
               0x02     M_SHORT_RELEASE
               0x01     M_SHORT_DETECTED
               OSX button masks seen are 0xff, 0xe7 and 0xdc
                        so for 0xe7 mask status bits are 0x18
                        so for 0xdc mask status bits are 0x23
                        bits 0x38 are not documented for cs42l42
               0xe7     is used for button detection
               0xdc     is used for button responses
        0x1b7c Detect Interrupt Status 2 (Buttons)
                        - cs42l42 documents a 0x130a as Detect Interrupt Status 2
                          no such register ever used on OSX
                          assuming this is a difference for the cs42l83
               0x80     M_DETECT_TRUE_FALSE
               0x40     M_DETECT_FALSE_TRUE
               0x04     M_HSBIAS_HIZ
               0x02     M_SHORT_RELEASE
               0x01     M_SHORT_DETECTED
               OSX status values seen
               0x0a     after 0xe7 mask set
               0x40     pre configure button response mask
               0x04     pre disable button interrupts
        0x1b78 Detect Status 2 - seems to be associated with buttons and/or mike
               0x02     HS_TRUE - cs42l42
               0x01     SHORT_TRUE - cs42l42
               OSX values seen
               0x40     button detect
               0x02     mike sense
               new values seen for imacs with non-Apple headsets
               0x20     button detect??
        0x131b Codec Interrupt Mask
               0x02     M_HSDET_AUTO_DONE
               0x01     M_PDN_DONE
        0x1308 Codec Interrupt Status
               0x02     M_HSDET_AUTO_DONE
               0x01     M_PDN_DONE
        0x1320 Tip/Ring Sense Plug/Unplug Interrupt Mask
               0x08     M_TS_UNPLUG
               0x04     M_TS_PLUG
               0x02     M_RS_UNPLUG
               0x01     M_RS_PLUG
        0x130f Tip/Ring Sense Plug/Unplug Interrupt Status
               0x08     M_TS_UNPLUG
               0x04     M_TS_PLUG
               0x02     M_RS_UNPLUG
               0x01     M_RS_PLUG

        register 0x1b7b:

        TIP_SENSE_PLUG 0x40
        TIP_SENSE_UNPLUG 0x20

        BUTTON_DOWN_PRESS 0x1
        BUTTON_UP_PRESS 0x2
        BUTTON_RELEASE 0x10

        BUTTONS (BUTTON_UP_PRESS | BUTTON_DOWN_PRESS)

        register 0x1b7c:

        BUTTON_DETECT_MAIN 0x18  // we only see 0x08 but the mask allows for these 2 bits

        register 0x1b78:

        BUTTON_DETECT_MASK 0x60 // now seen 2 bits used - plausibly depends if Apple with buttons (0x40) or non-Apple with buttons (0x20)
        BUTTON_DETECT1 0x40
        BUTTON_DETECT2 0x20
        MIKE_CONNECT 0x02

        register 0x131b:

        HSDET_AUTO_DONE 0x02
        PDN_DONE 0x01


 */



/*
 */

#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 13, 0)

struct unsol_item {
        struct list_head list;
        unsigned int idx;
        unsigned int res;
};

struct hda_cvt_setup_apple {
        hda_nid_t nid;
        u8 stream_tag;
        u8 channel_id;
        u16 format_id;
        unsigned char active;   /* cvt is currently used */
        unsigned char dirty;    /* setups should be cleared */
};

struct cs8409_apple_spec {
	struct hda_gen_spec gen;

	unsigned int gpio_mask;
	unsigned int gpio_dir;
	unsigned int gpio_data;
	unsigned int gpio_eapd_hp; /* EAPD GPIO bit for headphones */
	unsigned int gpio_eapd_speaker; /* EAPD GPIO bit for speakers */

	/* CS421x */
	unsigned int spdif_detect:1;
	unsigned int spdif_present:1;
	unsigned int sense_b:1;
	hda_nid_t vendor_nid;

        /* digital beep */
        hda_nid_t beep_nid;

	/* for MBP SPDIF control */
	int (*spdif_sw_put)(struct snd_kcontrol *kcontrol,
			    struct snd_ctl_elem_value *ucontrol);

	// so it appears we have "concurrency" in the linux HDA code
	// in that if unsolicited responses occur which perform extensive verbs
	// the hda verbs are intermixed with eg extensive start playback verbs
	// on OSX we appear to have blocks of verbs during which unsolicited responses
	// are logged but the unsolicited verbs occur after the verb block
	// this flag is used to flag such verb blocks and the list will store the
	// responses
	// we use a pre-allocated list - if we have more than 10 outstanding unsols
	// we will drop
	// not clear if mutexes would be the way to go
	int block_unsol;
	struct list_head unsol_list;
	struct unsol_item unsol_items_prealloc[10];
	int unsol_items_prealloc_used[10];

	// add in specific nids for the intmike and linein as they seem to swap
	// between macbook pros (14,3) and imacs (18,3)
	int intmike_nid;
	int linein_nid;
	int intmike_adc_nid;
	int linein_amp_nid;

	// the following flag bits also need swapping
	int reg9_intmike_dmic_mo;
	int reg9_linein_dmic_mo;
	int reg82_intmike_dmic_scl;
	int reg82_linein_dmic_scl;


        // add explicit stream format store entries as per hda_codec using a local definition
        // of hda_cvt_setup (which is local to hda_codec.c)
        // also use explicit nid versions
        // (except that means either need explicit functions for each nid or have to lookup
        //  nid each time want to use in a generic function with nid argument)
        struct hda_cvt_setup_apple nid_0x02;
        struct hda_cvt_setup_apple nid_0x03;
        struct hda_cvt_setup_apple nid_0x0a;
        struct hda_cvt_setup_apple nid_0x22;
        struct hda_cvt_setup_apple nid_0x23;
        struct hda_cvt_setup_apple nid_0x1a;


	// new item to deal with jack presence as Apple seems to have barfed
	// the HDA spec by using a separate headphone chip
	int jack_present;

	// save the type of headphone connected
	int headset_type;

	// if headphone has mike or not
	int have_mike;

	// if headphone has buttons or not
	int have_buttons;

        // current stream channel count
        int stream_channels;

	// set when playing for plug/unplug events while playing
	int playing;

	// set when capturing for plug/unplug events while capturing
	int capturing;

	// changing coding - OSX sets up the format on plugin
	// then does some minimal setup when start play
	// initial coding delayed any format setup till actually play
	// this works for no mike but not for mike - we need to initialize
	// the mike on plugin
	// this flag will be set when we have done the format setup
	// so know if need to do it on play or not
	// now need 2 flags - one for play and one for capture
	int headset_play_format_setup_needed;
	int headset_capture_format_setup_needed;

	int headset_presetup_done;


	int use_data;


	// this is new item for dealing with headset plugins
	// so can distinguish which phase we are in if have multiple interrupts
	// now primarily used to indicate if booted with headset plugged in
	int headset_phase;

	// another dirty hack item to manage the different headset enable codes
	int headset_enable;

	int play_init;
	int capture_init;

	// new item to limit times we redo unmute/play
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 8, 0)
	struct timespec64 last_play_time;
#else
	struct timespec last_play_time;
#endif
	// record the first play time - we have a problem there
	// some initial plays that I dont understand - so skip any setup
	// till sometime after the first play
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 8, 0)
	struct timespec64 first_play_time;
#else
	struct timespec first_play_time;
#endif

};
#endif


#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 13, 0)
#define cs8409_apple_spec cs8409_spec
#endif


// coding copied from hda_generic.c to print the nid path details


#define debug_badness(fmt, ...)                                         \
        mycodec_dbg(codec, fmt, ##__VA_ARGS__)

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 13, 0) && TESTING == 0

static void print_nid_path(struct hda_codec *codec,
			   const char *pfx, struct nid_path *path)
{
	char buf[40];
	char *pos = buf;
	int i;

	*pos = 0;
	for (i = 0; i < path->depth; i++)
		pos += scnprintf(pos, sizeof(buf) - (pos - buf), "%s%02x",
				 pos != buf ? ":" : "",
				 path->path[i]);

	mycodec_dbg(codec, "%s path: depth=%d '%s'\n", pfx, path->depth, buf);
}

#else

static void print_nid_path(struct hda_codec *codec,
			   const char *pfx, struct nid_path *path);

#endif


static inline void print_nid_path_idx(struct hda_codec *codec,
				      const char *pfx, int idx)
{
	struct nid_path *path;

	path = snd_hda_get_path_from_idx(codec, idx);
	if (path)
		print_nid_path(codec, pfx, path);
}

static void debug_show_configs(struct hda_codec *codec,
			       struct auto_pin_cfg *cfg)
{
	struct hda_gen_spec *spec = codec->spec;
	static const char * const lo_type[3] = { "LO", "SP", "HP" };
	int i;

        debug_badness("debug_show_configs start\n");

	debug_badness("multi_outs = %x/%x/%x/%x : %x/%x/%x/%x (type %s)\n",
		      cfg->line_out_pins[0], cfg->line_out_pins[1],
		      cfg->line_out_pins[2], cfg->line_out_pins[3],
		      spec->multiout.dac_nids[0],
		      spec->multiout.dac_nids[1],
		      spec->multiout.dac_nids[2],
		      spec->multiout.dac_nids[3],
		      lo_type[cfg->line_out_type]);
	for (i = 0; i < cfg->line_outs; i++)
		print_nid_path_idx(codec, "  out", spec->out_paths[i]);
	if (spec->multi_ios > 0)
		debug_badness("multi_ios(%d) = %x/%x : %x/%x\n",
			      spec->multi_ios,
			      spec->multi_io[0].pin, spec->multi_io[1].pin,
			      spec->multi_io[0].dac, spec->multi_io[1].dac);
	for (i = 0; i < spec->multi_ios; i++)
		print_nid_path_idx(codec, "  mio",
				   spec->out_paths[cfg->line_outs + i]);
	if (cfg->hp_outs)
		debug_badness("hp_outs = %x/%x/%x/%x : %x/%x/%x/%x\n",
		      cfg->hp_pins[0], cfg->hp_pins[1],
		      cfg->hp_pins[2], cfg->hp_pins[3],
		      spec->multiout.hp_out_nid[0],
		      spec->multiout.hp_out_nid[1],
		      spec->multiout.hp_out_nid[2],
		      spec->multiout.hp_out_nid[3]);
	for (i = 0; i < cfg->hp_outs; i++)
		print_nid_path_idx(codec, "  hp ", spec->hp_paths[i]);
	if (cfg->speaker_outs)
		debug_badness("spk_outs = %x/%x/%x/%x : %x/%x/%x/%x\n",
		      cfg->speaker_pins[0], cfg->speaker_pins[1],
		      cfg->speaker_pins[2], cfg->speaker_pins[3],
		      spec->multiout.extra_out_nid[0],
		      spec->multiout.extra_out_nid[1],
		      spec->multiout.extra_out_nid[2],
		      spec->multiout.extra_out_nid[3]);
	for (i = 0; i < cfg->speaker_outs; i++)
		print_nid_path_idx(codec, "  spk", spec->speaker_paths[i]);
	for (i = 0; i < 3; i++)
		print_nid_path_idx(codec, "  mix", spec->aamix_out_paths[i]);
        debug_badness("debug_show_configs end\n");
}

// attempt at an explicit setup ie not generic
//#include "patch_cirrus_explicit.h"


static void cs_8409_pcm_playback_pre_prepare_hook(struct hda_pcm_stream *hinfo, struct hda_codec *codec, 
                               unsigned int stream_tag, unsigned int format, struct snd_pcm_substream *substream,
                               int action);

// this is a copy from playback_pcm_prepare in hda_generic.c
// initially I needed to do the Apple setup BEFORE the snd_hda_multi_out_analog_prepare
// in order to overwrite the Apple setup with the actual format/stream id
// NOTA BENE - if playback_pcm_prepare is changed in hda_generic.c then
// those changes must be re-implemented here
// we need this order because snd_hda_multi_out_analog_prepare writes the
// the format and stream id's to the audio nodes
//// so far we have left the Apple setup of the nodes format and stream id's in
// now updated to set the actual format where Apple does the format/stream id setup
// Apples format is very specifically S24_3LE (24 bit), 4 channel, 44.1 kHz
// S24_3LE seems to be very difficult to create so best Ive done is
// S24_LE (24 in 32 bits) or S32_LE
// it seems the digital setup is able to handle this with the Apple TDM
// setup but if we use the normal prepare hook order this overrwites
// the node linux 0x2, 0x3 setup with the Apple setup which leads to noise
// (the HDA specs say the node format setup must match the data)
// if we do the Apple setup and then the snd_hda_multi_out_analog_prepare
// the nodes will have the slightly different but working format
// with proper update of stream format at same point as in Apple log we need to pass
// the actual playback format as passed to this routine to our new "hook"
// cs_8409_pcm_playback_pre_prepare_hook
// to define the cached format correctly in that routine
// so far my analysis is that hinfo stores the stream format in the kernel format style
// but what is passed to cs_8409_playback_pcm_prepare is the format in HDA style
// not yet figured how to convert from kernel format style to HDA style

static int cs_8409_playback_pcm_prepare(struct hda_pcm_stream *hinfo,
                                struct hda_codec *codec,
                                unsigned int stream_tag,
                                unsigned int format,
                                struct snd_pcm_substream *substream)
{
        struct hda_gen_spec *spec = codec->spec;
        int err;
        mycodec_dbg(codec, "cs_8409_playback_pcm_prepare\n");

        mycodec_dbg(codec, "cs_8409_playback_pcm_prepare: NID=0x%x, stream=0x%x, format=0x%x\n",
                  hinfo->nid, stream_tag, format);

        cs_8409_pcm_playback_pre_prepare_hook(hinfo, codec, stream_tag, format, substream,
                               HDA_GEN_PCM_ACT_PREPARE);

        // now dont think we need this - we now explicitly copy the 1st 2 channels to 2nd 2 channels
        // if given 2 channel input
        // plus all headset output is also explicitly being done
        // well thats unexpected - if we comment this we loose headphone output
        //err = snd_hda_multi_out_analog_prepare(codec, &spec->multiout,
        //                                       stream_tag, format, substream);
        err = 0;

	// we cant call directly as call_pcm_playback_hook is local to hda_generic.c
        //if (!err)
        //        call_pcm_playback_hook(hinfo, codec, substream,
        //                               HDA_GEN_PCM_ACT_PREPARE);
	// but its a trivial function - at least for the moment!!
	if (err)
                mycodec_dbg(codec, "cs_8409_playback_pcm_prepare err %d\n", err);
        if (!err)
                if (spec->pcm_playback_hook)
                        spec->pcm_playback_hook(hinfo, codec, substream, HDA_GEN_PCM_ACT_PREPARE);
        return err;
}


static void cs_8409_pcm_capture_pre_prepare_hook(struct hda_pcm_stream *hinfo, struct hda_codec *codec, 
                               unsigned int stream_tag, unsigned int format, struct snd_pcm_substream *substream,
                               int action);


// this is a copy from capture_pcm_prepare in hda_generic.c
// NOTA BENE - if capture_pcm_prepare is changed in hda_generic.c then
// those changes must be re-implemented here
static int cs_8409_capture_pcm_prepare(struct hda_pcm_stream *hinfo,
                               struct hda_codec *codec,
                               unsigned int stream_tag,
                               unsigned int format,
                               struct snd_pcm_substream *substream)
{
        struct cs8409_apple_spec *spec = codec->spec;

        mycodec_dbg(codec, "cs_8409_capture_pcm_prepare\n");

        mycodec_dbg(codec, "cs_8409_capture_pcm_prepare: NID=0x%x, stream=0x%x, format=0x%x\n",
                  hinfo->nid, stream_tag, format);


        cs_8409_pcm_capture_pre_prepare_hook(hinfo, codec, stream_tag, format, substream,
                              HDA_GEN_PCM_ACT_PREPARE);

	// we have a problem - this has to handle 2 different types of stream - the internal mike
	// and the external headset mike (cs42l83)


	// NOTE - the following snd_hda_codec_stream no longer do anything
	//        we have already set the stream data in the pre prepare hook
	//        - so as the format here is same (or at least should be!!) as that setup there is no format difference to that
	//        cached and snd_hda_coded_setup_stream does nothing

	if (hinfo->nid == spec->intmike_adc_nid)
	{

	// so this is getting stranger and stranger
	// the most valid recording is S24_3LE (0x4031) - except that the data we get out is S32_LE (low byte 0)
	// - so it doesnt play right - and it messes with arecords vumeter
	// (S32_LE is officially 0x4041 - but using that format doesnt seem to have valid data - audio very low)
	//// so now try forcing the format here to 0x4031
	//// well that fails miserably - the format mismatch stops data totally
	// it now appears we get the same data with either 0x4031 or 0x4041 - both are low volume
	// - however scaling (normalizing) in audacity we get the right sound with similar quality to OSX
	// so now think the low volume is right - and OSX must be scaling/processing the data in CoreAudio
	// (is the internal mike a fake 24 bits - ie its actually 16 bits but stuffed in the low end of the
	//  24 bits - hence low volume - preliminary scaling attempts in audacity suggest this might be true!!)

        snd_hda_codec_setup_stream(codec, hinfo->nid, stream_tag, 0, format);

	}
	else if (hinfo->nid == 0x1a)
	{

	// do we need a pre-prepare function??
	// maybe for this the external mike ie cs42l83 input

        snd_hda_codec_setup_stream(codec, hinfo->nid, stream_tag, 0, format);

	}
	else
		dev_info(hda_codec_dev(codec), "cs_8409_capture_pcm_prepare - UNIMPLEMENTED input nid 0x%x\n",hinfo->nid);

	// we cant call directly as call_pcm_capture_hook is local to hda_generic.c
        //call_pcm_capture_hook(hinfo, codec, substream,
        //                      HDA_GEN_PCM_ACT_PREPARE);
	// but its a trivial function - at least for the moment!!
	// note this hook if defined also needs to switch between the 2 versions of input!!
        if (spec->gen.pcm_capture_hook)
                spec->gen.pcm_capture_hook(hinfo, codec, substream, HDA_GEN_PCM_ACT_PREPARE);

        return 0;
}


// another copied routine as this is local to hda_jack.c
static struct hda_jack_tbl *
cs8409_any_jack_tbl_get_from_nid(struct hda_codec *codec, hda_nid_t nid)
{
        struct hda_jack_tbl *jack = codec->jacktbl.list;
        int i;

        if (!nid || !jack)
                return NULL;
        for (i = 0; i < codec->jacktbl.used; i++, jack++)
                if (jack->nid == nid)
                        return jack;
        return NULL;
}

// another copied routine as this is local to hda_jack.c
static struct hda_jack_tbl *
cs_8409_hda_jack_tbl_new(struct hda_codec *codec, hda_nid_t nid, int dev_id)
{
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 8, 0)
        struct hda_jack_tbl *jack = snd_hda_jack_tbl_get_mst(codec, nid, dev_id);
#else
        struct hda_jack_tbl *jack = snd_hda_jack_tbl_get(codec, nid);
#endif
        struct hda_jack_tbl *existing_nid_jack = cs8409_any_jack_tbl_get_from_nid(codec, nid);

        WARN_ON(dev_id != 0 && !codec->dp_mst);

        if (jack)
                return jack;
        jack = snd_array_new(&codec->jacktbl);
        if (!jack)
                return NULL;
        jack->nid = nid;
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 8, 0)
        jack->dev_id = dev_id;
#endif
        jack->jack_dirty = 1;
        if (existing_nid_jack) {
                jack->tag = existing_nid_jack->tag;

                /*
                 * Copy jack_detect from existing_nid_jack to avoid
                 * snd_hda_jack_detect_enable_callback_mst() making multiple
                 * SET_UNSOLICITED_ENABLE calls on the same pin.
                 */
                jack->jack_detect = existing_nid_jack->jack_detect;
        } else {
                jack->tag = codec->jacktbl.used;
        }
        //// use this to prevent AC_VERB_GET_PIN_SENSE (f09) verbs being sent - not seen in OSX logs
        // well it does but it also makes the jack seem permanently connected
        // now going with Dell style fixup
        //jack->phantom_jack = 1;
        return jack;
}

// another copied routine as this is local to hda_jack.c
static struct hda_jack_callback *
cs_8409_find_callback_from_list(struct hda_jack_tbl *jack,
                                hda_jack_callback_fn func)
{
        struct hda_jack_callback *cb;

        if (!func)
                return NULL;

        for (cb = jack->callback; cb; cb = cb->next) {
                if (cb->func == func)
                        return cb;
        }

        return NULL;
}

// quick debug callback list function
void cs_8409_dump_callback(struct hda_codec *codec)
{
        struct hda_jack_tbl *jack = codec->jacktbl.list;
        int i;
        struct hda_jack_callback *cb;

        for (i = 0; i < codec->jacktbl.used; i++, jack++) {
                for (cb = jack->callback; cb; cb = cb->next) {
		        printk("snd_hda_intel: cs_8409_dump_callback jack num %d nid 0x%02x tag 0x%08x func %pF\n",i,jack->nid,jack->tag,cb->func);
                }
        }

        return;
}

// copy of snd_hda_jack_detect_enable_callback code so doesnt send AC_VERB_SET_UNSOLICITED_ENABLE
// for Apple there are no AC_VERB_SET_UNSOLICITED_ENABLE verbs sent for 8409
// it appears unsolicited response is pre-enabled
// but we need to fix this to setup the callback on such responses
// note that the current (>5.13) callback does not have a tag argument
struct hda_jack_callback *
cs_8409_hda_jack_detect_enable_callback(struct hda_codec *codec, hda_nid_t nid, int dev_id, int tag,
				    hda_jack_callback_fn func)
{
	struct hda_jack_tbl *jack;
	struct hda_jack_callback *callback = NULL;
	int err;

        myprintk("snd_hda_intel: cs_8409_hda_jack_detect_enable_callback nid 0x%02x dev_id %d tag 0x%02x\n", nid, dev_id, tag);

	jack = cs_8409_hda_jack_tbl_new(codec, nid, dev_id);
	if (!jack)
		return ERR_PTR(-ENOMEM);

	callback = cs_8409_find_callback_from_list(jack, func);

	if (func && !callback) {
		callback = kzalloc(sizeof(*callback), GFP_KERNEL);
		if (!callback)
			return ERR_PTR(-ENOMEM);
		callback->func = func;
		callback->nid = jack->nid;
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 8, 0)
                callback->dev_id = jack->dev_id;
#endif
		callback->next = jack->callback;
		jack->callback = callback;
	}

	if (jack->jack_detect)
		return callback; /* already registered */
	jack->jack_detect = 1;
	// update the tag - linux code just counted the number of jacks set up
	// for a tag - now done in cs_8409_hda_jack_tbl_new
	// DANGEROUS - we do NOT check for unique tag here!!
	if (tag != 0)
		jack->tag = tag;
	if (codec->jackpoll_interval > 0)
		return callback; /* No unsol if we're polling instead */
	// apparently we dont need to send this
	//err = snd_hda_codec_write_cache(codec, nid, 0,
	//				 AC_VERB_SET_UNSOLICITED_ENABLE,
	//				 AC_USRSP_EN | jack->tag);
	//if (err < 0)
	//	return ERR_PTR(err);
	return callback;
}

// this is a copy of local routine call_jack_callback from hda_jack.c
static void cs_8409_apple_call_jack_callback(struct hda_codec *codec, unsigned int res,
                                             struct hda_jack_tbl *jack)
{
        struct hda_jack_callback *cb;

        for (cb = jack->callback; cb; cb = cb->next) {
		cb->jack = jack;
		cb->unsol_res = res;
                cb->func(codec, cb);
	}
        if (jack->gated_jack) {
                struct hda_jack_tbl *gated =
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 8, 0)
                        snd_hda_jack_tbl_get_mst(codec, jack->gated_jack, jack->dev_id);
#else
                        snd_hda_jack_tbl_get(codec, jack->gated_jack);
#endif
                if (gated) {
                        for (cb = gated->callback; cb; cb = cb->next) {
				cb->jack = jack;
				cb->unsol_res = res;
                                cb->func(codec, cb);
			}
                }
        }
}


#ifdef APPLE_CHANNEL_MAP
// new attempt to solve the channel map issue
static const struct snd_pcm_chmap_elem cs_8409_chmap[] = {
        { .channels = 2,
          .map = { SNDRV_CHMAP_FL, SNDRV_CHMAP_FR } },
        { .channels = 4,
          .map = { SNDRV_CHMAP_FL, SNDRV_CHMAP_RL,
                   SNDRV_CHMAP_FR, SNDRV_CHMAP_RR } },
        { }
};

// this adds controls which I have no idea what they do
static void cs_8409_add_chmap_ctls(struct hda_codec *codec)
{
        int err = 0;
        struct hda_pcm *pcm;

        mycodec_dbg(codec, "cs_8409_add_chmap_ctls enter");

        list_for_each_entry(pcm, &codec->pcm_list_head, list) {
                struct hda_pcm_stream *hinfo =
                        &pcm->stream[SNDRV_PCM_STREAM_PLAYBACK];
                struct snd_pcm_chmap *chmap;
                const struct snd_pcm_chmap_elem *elem;

		if (pcm != NULL) {
			mycodec_dbg(codec, "cs_8409_add_chmap_ctls pcm name %s", pcm->name);

			if (hinfo != NULL) {
				mycodec_dbg(codec, "cs_8409_add_chmap_ctls pcm hinfo OK");
                		elem = cs_8409_chmap;
                		if (hinfo->channels_max == 4) {
					mycodec_dbg(codec, "cs_8409_add_chmap_ctls pcm hinfo chan == 4");
                        		err = snd_pcm_add_chmap_ctls(pcm->pcm,
                                        		SNDRV_PCM_STREAM_PLAYBACK,
                                        		elem, hinfo->channels_max, 0, &chmap);
                        		if (err < 0)
						mycodec_dbg(codec, "cs_8409_add_chmap_ctls failed!");
                		}
			} else {
				mycodec_dbg(codec, "cs_8409_add_chmap_ctls pcm hinfo NULL");
			}
		} else {
			mycodec_dbg(codec, "cs_8409_add_chmap_ctls pcm NULL");
		}
        }

        mycodec_dbg(codec, "cs_8409_add_chmap_ctls exit");
}
#endif

#ifdef ADD_EXTENDED_VERB
static void cs_8409_set_extended_codec_verb(void);
#endif


static void cs_8409_dump_auto_config(struct hda_codec *codec, const char *label_string)
{
	struct cs8409_apple_spec *spec = codec->spec;
	//struct cs8409_spec *spec = codec->spec;
	int itm = 0;

        myprintk("snd_hda_intel: dump %s\n", label_string);

        // dump headphone config
        myprintk("snd_hda_intel: headphone config hp_jack_present %d\n",spec->gen.hp_jack_present);
        myprintk("snd_hda_intel: headphone config line_jack_present %d\n",spec->gen.line_jack_present);
        myprintk("snd_hda_intel: headphone config speaker_muted %d\n",spec->gen.speaker_muted);
        myprintk("snd_hda_intel: headphone config line_out_muted %d\n",spec->gen.line_out_muted);
        myprintk("snd_hda_intel: headphone config auto_mic %d\n",spec->gen.auto_mic);
        myprintk("snd_hda_intel: headphone config automute_speaker %d\n",spec->gen.automute_speaker);
        myprintk("snd_hda_intel: headphone config automute_lo %d\n",spec->gen.automute_lo);
        myprintk("snd_hda_intel: headphone config detect_hp %d\n",spec->gen.detect_hp);
        myprintk("snd_hda_intel: headphone config detect_lo %d\n",spec->gen.detect_lo);
        myprintk("snd_hda_intel: headphone config keep_vref_in_automute %d\n",spec->gen.keep_vref_in_automute);
        myprintk("snd_hda_intel: headphone config line_in_auto_switch %d\n",spec->gen.line_in_auto_switch);
        myprintk("snd_hda_intel: headphone config auto_mute_via_amp %d\n",spec->gen.auto_mute_via_amp);
        myprintk("snd_hda_intel: headphone config suppress_auto_mute %d\n",spec->gen.suppress_auto_mute);
        myprintk("snd_hda_intel: headphone config suppress_auto_mic %d\n",spec->gen.suppress_auto_mic);

        myprintk("snd_hda_intel: headphone config hp_mic %d\n",spec->gen.hp_mic);

        myprintk("snd_hda_intel: headphone config suppress_hp_mic_detect %d\n",spec->gen.suppress_hp_mic_detect);


        myprintk("snd_hda_intel: auto config pins line_outs %d\n", spec->gen.autocfg.line_outs);
        myprintk("snd_hda_intel: auto config pins line_outs 0x%02x\n", spec->gen.autocfg.line_out_pins[0]);
        myprintk("snd_hda_intel: auto config pins line_outs 0x%02x\n", spec->gen.autocfg.line_out_pins[1]);
        myprintk("snd_hda_intel: auto config pins speaker_outs %d\n", spec->gen.autocfg.speaker_outs);
        myprintk("snd_hda_intel: auto config pins speaker_outs 0x%02x\n", spec->gen.autocfg.speaker_pins[0]);
        myprintk("snd_hda_intel: auto config pins speaker_outs 0x%02x\n", spec->gen.autocfg.speaker_pins[1]);
        myprintk("snd_hda_intel: auto config pins hp_outs %d\n", spec->gen.autocfg.hp_outs);
        myprintk("snd_hda_intel: auto config pins hp_outs 0x%02x\n", spec->gen.autocfg.hp_pins[0]);
        myprintk("snd_hda_intel: auto config pins inputs %d\n", spec->gen.autocfg.num_inputs);

        for (itm = 0; itm < spec->gen.autocfg.num_inputs; itm++) {

                myprintk("snd_hda_intel: auto config pins inputs  pin 0x%02x\n", spec->gen.autocfg.inputs[itm].pin);
                myprintk("snd_hda_intel: auto config pins inputs type %d\n", spec->gen.autocfg.inputs[itm].type);
                myprintk("snd_hda_intel: auto config pins inputs is head set mic %d\n", spec->gen.autocfg.inputs[itm].is_headset_mic);
                myprintk("snd_hda_intel: auto config pins inputs is head phn mic %d\n", spec->gen.autocfg.inputs[itm].is_headphone_mic);
                myprintk("snd_hda_intel: auto config pins inputs is        boost %d\n", spec->gen.autocfg.inputs[itm].has_boost_on_pin);
        }

        myprintk("snd_hda_intel: auto config inputs num_adc_nids %d\n", spec->gen.num_adc_nids);
        for (itm = 0; itm < spec->gen.num_adc_nids; itm++) {
                myprintk("snd_hda_intel: auto config inputs adc_nids 0x%02x\n", spec->gen.adc_nids[itm]);
        }

        myprintk("snd_hda_intel: auto config multiout is num_dacs %d\n", spec->gen.multiout.num_dacs);
        for (itm = 0; itm < spec->gen.multiout.num_dacs; itm++) {
                myprintk("snd_hda_intel: auto config multiout is    dac_nids 0x%02x\n", spec->gen.multiout.dac_nids[itm]);
        }

        myprintk("snd_hda_intel: auto config multiout is      hp_nid 0x%02x\n", spec->gen.multiout.hp_nid);

        for (itm = 0; itm < ARRAY_SIZE(spec->gen.multiout.hp_out_nid); itm++) {
                if (spec->gen.multiout.hp_out_nid[itm])
                        myprintk("snd_hda_intel: auto config multiout is  hp_out_nid 0x%02x\n", spec->gen.multiout.hp_out_nid[itm]);
        }
        for (itm = 0; itm < ARRAY_SIZE(spec->gen.multiout.extra_out_nid); itm++) {
                if (spec->gen.multiout.extra_out_nid[itm])
                        myprintk("snd_hda_intel: auto config multiout is xtr_out_nid 0x%02x\n", spec->gen.multiout.extra_out_nid[itm]);
        }

        myprintk("snd_hda_intel: auto config multiout is dig_out_nid 0x%02x\n", spec->gen.multiout.dig_out_nid);
        myprintk("snd_hda_intel: auto config multiout is slv_dig_out %p\n", spec->gen.multiout.follower_dig_outs);

}


static void cs_8409_dump_path(struct nid_path *path)
{
        int i;
        int j;

        myprintk("snd_hda_intel: dump path\n");

        myprintk("snd_hda_intel: path %d: active %d pin_enabled %d pin_fixed %d stream_enabled %d\n", i, path->active, path->pin_enabled, path->pin_fixed, path->stream_enabled);
        myprintk("snd_hda_intel:     path %d: depth %d\n", i, path->depth);
        for(j=0; j < path->depth; j++) {
                        myprintk("snd_hda_intel:     path %d: path nid 0x%02x idx %d multi %d\n", j, path->path[j], path->idx[j], path->multi[j]);
        }
        for(j=0; j < NID_PATH_NUM_CTLS; j++) {
                        myprintk("snd_hda_intel:     ctl %d: path 0x%08x\n", j, path->ctls[j]);
        }

        myprintk("snd_hda_intel: dump path end\n");
}


// so now think multi in the path is different from multiout
// - now think its about if there are multiple connections as listed by AC_VERB_GET_CONNECT_LIST
// - still havent figured out idx tho

static void cs_8409_dump_paths(struct hda_codec *codec, const char *label_string)
{
	struct cs8409_apple_spec *spec = codec->spec;
	//struct cs8409_spec *spec = codec->spec;
        const struct nid_path *path;
        int i;
        int j;

        myprintk("snd_hda_intel: dump paths %s\n", label_string);

        snd_array_for_each(&spec->gen.paths, i, path) {
                myprintk("snd_hda_intel: path %d: active %d pin_enabled %d pin_fixed %d stream_enabled %d\n", i, path->active, path->pin_enabled, path->pin_fixed, path->stream_enabled);
                myprintk("snd_hda_intel:     path %d: depth %d\n", i, path->depth);
                for(j=0; j < path->depth; j++) {
                        myprintk("snd_hda_intel:     path %d: path nid 0x%02x idx %d multi %d\n", j, path->path[j], path->idx[j], path->multi[j]);
                }
                for(j=0; j < NID_PATH_NUM_CTLS; j++) {
                        myprintk("snd_hda_intel:     ctl %d: path 0x%08x\n", j, path->ctls[j]);
                }

        }

        myprintk("snd_hda_intel: dump paths end\n");
}



// renamed this function as we dont want it called on resume
// because we are using an explicit version of build controls we can add it there

static int cs_8409_apple_boot_init(struct hda_codec *codec)
{
	struct hda_pcm *info = NULL;
	struct hda_pcm_stream *hinfo = NULL;
	struct cs8409_apple_spec *spec = NULL;
	//struct snd_kcontrol *kctl = NULL;
	int pcmcnt = 0;
	int ret_unsol_enable = 0;

	// so apparently if we do not define a resume function
	// then this init function will be called on resume
	// is that what we want here??
	// NOTE this is called for either playback or capture

        myprintk("snd_hda_intel: cs_8409_apple_boot_init\n");

        //dump_stack();


        // NOTE that this function is called after the build pcm functions


	// dump the rates/format of the afg node
	// so analog_playback_stream is still NULL here - maybe only defined when doing actual playback
	// the info stream is now defined
	spec = codec->spec;
        hinfo = spec->gen.stream_analog_playback;
	if (hinfo != NULL)
	{
		mycodec_dbg(codec, "hinfo stream nid 0x%02x rates 0x%08x formats 0x%016llx\n",hinfo->nid,hinfo->rates,hinfo->formats);
	}
	else
		mycodec_dbg(codec, "hinfo stream NULL\n");

	// think this is what I need to fixup

        list_for_each_entry(info, &codec->pcm_list_head, list) {
                int stream;

                mycodec_dbg(codec, "cs_8409_apple_boot_init pcm %d\n",pcmcnt);

                for (stream = 0; stream < 2; stream++) {
                        struct hda_pcm_stream *hinfo = &info->stream[stream];

			mycodec_dbg(codec, "cs_8409_apple_boot_init info stream %d pointer %p\n",stream,hinfo);

			if (hinfo != NULL)
			{
				mycodec_dbg(codec, "cs_8409_apple_boot_init info stream %d nid 0x%02x rates 0x%08x formats 0x%016llx\n",stream,hinfo->nid,hinfo->rates,hinfo->formats);
				mycodec_dbg(codec, "cs_8409_apple_boot_init        stream substreams %d\n",hinfo->substreams);
				mycodec_dbg(codec, "cs_8409_apple_boot_init        stream channels min %d\n",hinfo->channels_min);
				mycodec_dbg(codec, "cs_8409_apple_boot_init        stream channels max %d\n",hinfo->channels_max);
				mycodec_dbg(codec, "cs_8409_apple_boot_init        stream maxbps %d\n",hinfo->maxbps);
			}
			else
				mycodec_dbg(codec, "cs_8409_apple_boot_init info stream %d NULL\n", stream);
		}
		pcmcnt++;
	}

	// update the streams specifically by nid
	// we seem to have only 1 stream here with the nid of 0x02
	// (I still dont really understand the linux generic coding here)
	// with capture devices we seem to get 2 pcm streams (0 and 1)
	// each pcm stream has an output stream (0) and an input stream (1)
	// the 1st pcm stream (0) is assigned nid 0x02 for output and nid 0x22 (macbook pro) for input (internal mike)
	// the 2nd pcm stream (1) has a dummy output stream and nid 0x1a for input (headset mike via cs42l83)
	// (NOTE this means the line input stream (0x45->0x23) (macbook pro) is not assigned currently ie not useable)

        list_for_each_entry(info, &codec->pcm_list_head, list) {
                int stream;

                for (stream = 0; stream < 2; stream++) {
                        struct hda_pcm_stream *hinfo = &info->stream[stream];

			if (hinfo != NULL)
			{
				if (stream == SNDRV_PCM_STREAM_PLAYBACK)
				{
					if (hinfo->nid == 0x02)
					{
						mycodec_dbg(codec, "cs_8409_apple_boot_init info playback stream %d pointer %p\n",stream,hinfo);
						// so now we need to force the rates and formats to the single one Apple defines ie 44.1 kHz and S24_LE
						// probably can leave S32_LE
						// we can still handle 2/4 channel (what about 1 channel?)
						hinfo->rates = SNDRV_PCM_RATE_44100;
						hinfo->formats = SNDRV_PCM_FMTBIT_S32_LE | SNDRV_PCM_FMTBIT_S24_LE;
						mycodec_dbg(codec, "playback info stream forced nid 0x%02x rates 0x%08x formats 0x%016llx\n",hinfo->nid,hinfo->rates,hinfo->formats);

						// update the playback function
						hinfo->ops.prepare = cs_8409_playback_pcm_prepare;
					}
				}
				else if (stream == SNDRV_PCM_STREAM_CAPTURE)
				{
					//if (hinfo->nid == 0x22)
					if (hinfo->nid == spec->intmike_adc_nid)
					{
						// this is the internal mike
						// this is a bit weird - the output nodes are id'ed by input pin nid
						// but the input nodes are done by the input (adc) nid - not the input pin nid
						mycodec_dbg(codec, "cs_8409_apple_boot_init info capture stream %d pointer %p\n",stream,hinfo);
						// so now we could force the rates and formats to the single one Apple defines ie 44.1 kHz and S24_LE
						// but this internal mike seems to be a standard HDA input setup so we could have any format here
						//hinfo->rates = SNDRV_PCM_RATE_44100;
						//hinfo->formats = SNDRV_PCM_FMTBIT_S32_LE | SNDRV_PCM_FMTBIT_S24_LE;
						hinfo->rates = SNDRV_PCM_RATE_44100;
						//hinfo->formats = SNDRV_PCM_FMTBIT_S24_3LE;
						hinfo->formats = SNDRV_PCM_FMTBIT_S32_LE | SNDRV_PCM_FMTBIT_S24_LE | SNDRV_PCM_FMTBIT_S24_3LE;
						//hinfo->maxbps = 24;
						mycodec_dbg(codec, "capture info stream forced nid 0x%02x rates 0x%08x formats 0x%016llx maxbps %d\n",hinfo->nid,hinfo->rates,hinfo->formats,hinfo->maxbps);
						// update the capture function
						hinfo->ops.prepare = cs_8409_capture_pcm_prepare;
					}
					else if (hinfo->nid == 0x1a)
					{
						// this is the external mike ie headset mike
						// this is a bit weird - the output nodes are id'ed by input pin nid
						// but the input nodes are done by the input (adc) nid - not the input pin nid
						mycodec_dbg(codec, "cs_8409_apple_boot_init info capture stream %d pointer %p\n",stream,hinfo);
						// so now we force the rates and formats to the single one Apple defines ie 44.1 kHz and S24_LE
						// - because this format is the one being returned by the cs42l83 which is setup by undocumented i2c commands
						hinfo->rates = SNDRV_PCM_RATE_44100;
						//hinfo->formats = SNDRV_PCM_FMTBIT_S24_LE;
						hinfo->formats = SNDRV_PCM_FMTBIT_S32_LE | SNDRV_PCM_FMTBIT_S24_LE | SNDRV_PCM_FMTBIT_S24_3LE;
						//hinfo->maxbps = 24;
						mycodec_dbg(codec, "capture info stream forced nid 0x%02x rates 0x%08x formats 0x%016llx maxbps %d\n",hinfo->nid,hinfo->rates,hinfo->formats,hinfo->maxbps);
						// update the capture function
						hinfo->ops.prepare = cs_8409_capture_pcm_prepare;
					}
					// still not sure what we do about the linein nid
					// is this bidirectional - because we have no lineout as far as I can see
				}
			}
			else
				mycodec_dbg(codec, "cs_8409_apple_boot_init info pcm stream %d NULL\n", stream);
		}
		pcmcnt++;
	}


	//list_for_each_entry(kctl, &codec->card->controls, list) {
	//}


#ifdef ADD_EXTENDED_VERB
	cs_8409_set_extended_codec_verb();
#endif

        myprintk("snd_hda_intel: end cs_8409_apple_boot_init\n");

	return 0;
}


static int cs_8409_apple_init(struct hda_codec *codec)
{
	struct hda_pcm *info = NULL;
	struct hda_pcm_stream *hinfo = NULL;
	struct cs8409_apple_spec *spec = NULL;
	//struct snd_kcontrol *kctl = NULL;
	int pcmcnt = 0;
	int ret_unsol_enable = 0;

	// not sure what the init function is supposed to be doing
	// its called in snd_hda_codec_build_controls
	// but also from the default resume function hda_call_codec_resume

	// so apparently if we do not define a resume function
	// then this init function will be called on resume
	// is that what we want here??
	// NOTE this is called for either playback or capture

	myprintk("snd_hda_intel: cs_8409_apple_init\n");

	//dump_stack();


	//if (spec->vendor_nid == CS420X_VENDOR_NID) {
	//	/* init_verb sequence for C0/C1/C2 errata*/
	//	snd_hda_sequence_write(codec, cs_errata_init_verbs);
	//	snd_hda_sequence_write(codec, cs_coef_init_verbs);
	//} else if (spec->vendor_nid == CS4208_VENDOR_NID) {
	//	snd_hda_sequence_write(codec, cs4208_coef_init_verbs);
	//}


	//// so it looks as tho we have an issue when using headsets
	//// - because the 8409 is totally messed up it does not switch the inputs
	//// when a headset is plugged in
	//// not sure about this here - maybe move to where disable internal mike nodes
	//if (spec->jack_present) {
	//}


	// so the following powers on all active nodes - but if we have just plugged
	// in a headset thats still the internal mike and amps

	// commenting this as we dont need it
	// it powers on the nids, plus updates the mute/volume
	// via path_power_update and activate_amp_in or activate_amp_out
	//snd_hda_gen_init(codec);


	// read UNSOL enable data to see what initial setup is
        //ret_unsol_enable = snd_hda_codec_read(codec, codec->core.afg, 0, AC_VERB_GET_UNSOLICITED_RESPONSE, 0);
	//mycodec_dbg(codec,"UNSOL event 0x01 boot setup is 0x%08x\n",ret_unsol_enable);
        //ret_unsol_enable = snd_hda_codec_read(codec, 0x47, 0, AC_VERB_GET_UNSOLICITED_RESPONSE, 0);
	//mycodec_dbg(codec,"UNSOL event 0x47 boot setup is 0x%08x\n",ret_unsol_enable);


	//if (spec->gpio_mask) {
	//	snd_hda_codec_write(codec, 0x01, 0, AC_VERB_SET_GPIO_MASK,
	//			    spec->gpio_mask);
	//	snd_hda_codec_write(codec, 0x01, 0, AC_VERB_SET_GPIO_DIRECTION,
	//			    spec->gpio_dir);
	//	snd_hda_codec_write(codec, 0x01, 0, AC_VERB_SET_GPIO_DATA,
	//			    spec->gpio_data);
	//}

	//if (spec->vendor_nid == CS420X_VENDOR_NID) {
	//	init_input_coef(codec);
	//	init_digital_coef(codec);
	//}


	myprintk("snd_hda_intel: end cs_8409_apple_init\n");

	return 0;
}

static int cs_8409_apple_suspend(struct hda_codec *codec)
{
        myprintk("snd_hda_intel: cs_8409_apple_suspend\n");
        // no additional code for this so just dummy it
        return 0;
}

static int cs_8409_apple_check_power_status(struct hda_codec *codec, hda_nid_t nid)
{
        myprintk("snd_hda_intel: cs_8409_apple_check_power_status\n");
        // no additional code for this so just dummy it
        return 0;
}


static int cs_8409_apple_build_controls(struct hda_codec *codec)
{
	int err;

	myprintk("snd_hda_intel: cs_8409_apple_build_controls\n");
	//dump_stack();



	// try here - its mainly dumping the pcms which have been built by now
	cs_8409_apple_boot_init(codec);

	// so if we have paths (active??) then snd_hda_gen_build_controls will add the end point
	// (ie adc input nid or output nid (often dac but just pass through for 8409) as jacks
	// if the nid has no PIN_SENSE then these will be phantom jacks (which means treated as always plugged in)

	err = snd_hda_gen_build_controls(codec);
	if (err < 0)
		return err;
	snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_BUILD);

	// this seems better as snd_hda_gen_build_controls does an hda_exec_init_verbs call
	// before calling the init patch_ops function
	// - on the other hand currently it is just dumping data doesnt actually do anything
	//cs_8409_apple_boot_init(codec);


	// before or after the snd_hda_apply_fixup??
	//cs_8409_add_chmap_ctls(codec);

	myprintk("snd_hda_intel: end cs_8409_apple_build_controls\n");
	return 0;
}

int cs_8409_apple_build_pcms(struct hda_codec *codec)
{
	int retval;
        struct hda_pcm *pcm;
	//struct cs8409_apple_spec *spec = codec->spec;
	//struct hda_pcm *info = NULL;
	//struct hda_pcm_stream *hinfo = NULL;


        myprintk("snd_hda_intel: cs_8409_apple_build_pcms\n");


        // so I dont get how this leads to the observed controls in pulse/alsa
        // so far snd_hda_gen_build_pcms seems to add channel maps of stereo and 2.1
        // - cant figure out where the surround is generated from
        // (also cant see any way to disable the 2.1 without explicit recoding)


        // to replace this with explicit code would require a lot of static function copying
        // from hda_generic.c (and maybe hda_codec.c)
        // current issue is the default code will add a 2.1 chmap for 4 channels - I want to remove that
	retval =  snd_hda_gen_build_pcms(codec);


        list_for_each_entry(pcm, &codec->pcm_list_head, list) {
                struct snd_pcm_chmap *chmap;
                //const struct snd_pcm_chmap_elem *elem;
		if (pcm != NULL) {
			myprintk("snd_hda_intel: cs_8409_apple_build_pcms name %s\n", pcm->name);
			if (pcm->stream[SNDRV_PCM_STREAM_PLAYBACK].chmap != NULL) {
                                const struct snd_pcm_chmap_elem *elem;
                                elem = &pcm->stream[SNDRV_PCM_STREAM_PLAYBACK].chmap[0];
				myprintk("snd_hda_intel: cs_8409_apple_build_pcms chmap chnls %d map %d %d\n", elem->channels, elem->map[0], elem->map[1]);
                                elem = &pcm->stream[SNDRV_PCM_STREAM_PLAYBACK].chmap[1];
				myprintk("snd_hda_intel: cs_8409_apple_build_pcms chmap chnls %d map %d %d %d %d\n", elem->channels, elem->map[0], elem->map[1], elem->map[2], elem->map[3]);
                        } else {
				myprintk("snd_hda_intel: cs_8409_apple_build_pcms chmap NULL\n");
                        }
	//		if (pcm->stream[SNDRV_PCM_STREAM_PLAYBACK].channels_max == 4) {
        //			myprintk("snd_hda_intel: cs_8409_apple_build_pcms - adding chmap OK\n");
	//			pcm->own_chmap = true;
	//			pcm->stream[SNDRV_PCM_STREAM_PLAYBACK].chmap = cs_8409_chmap;
	//		}
		}
	}

	// we still dont have the pcm streams defined by here
	// ah this is all done in snd_hda_codec_build_pcms
	// which calls this patch routine or snd_hda_gen_build_pcms
	// but the query supported pcms is only done after this
        myprintk("snd_hda_intel: end cs_8409_apple_build_pcms\n");
	return retval;
}


// copy of cs8409_fix_caps with debug prints
// - rather than adding the prints to the patch_cs8409.c routine
static void cs8409_fix_caps_debug(struct hda_codec *codec, unsigned int nid)
{
	int caps;

	/* CS8409 is simple HDA bridge and intended to be used with a remote
	 * companion codec. Most of input/output PIN(s) have only basic
	 * capabilities. Receive and Transmit NID(s) have only OUTC and INC
	 * capabilities and no presence detect capable (PDC) and call to
	 * snd_hda_gen_build_controls() will mark them as non detectable
	 * phantom jacks. However, a companion codec may be
	 * connected to these pins which supports jack detect
	 * capabilities. We have to override pin capabilities,
	 * otherwise they will not be created as input devices.
	 */
	caps = snd_hdac_read_parm(&codec->core, nid, AC_PAR_PIN_CAP);
	if (caps >= 0)
		snd_hdac_override_parm(&codec->core, nid, AC_PAR_PIN_CAP,
				       (caps | (AC_PINCAP_IMP_SENSE | AC_PINCAP_PRES_DETECT)));

	myprintk("snd_hda_intel: cs8409_fix_caps nid 0x%02x pcap  0x%08x :  0x%08x 0x%08x 0x%08x\n",nid,caps,AC_PINCAP_IMP_SENSE,AC_PINCAP_PRES_DETECT,AC_PINCAP_IMP_SENSE | AC_PINCAP_PRES_DETECT);
	myprintk("snd_hda_intel: cs8409_fix_caps nid 0x%02x wcap  0x%08x :  0x%08x\n",nid,get_wcaps(codec, nid),AC_WCAP_UNSOL_CAP);

	snd_hda_override_wcaps(codec, nid, (get_wcaps(codec, nid) | AC_WCAP_UNSOL_CAP));
}



// set up some local routines we can call in our main code to call the hda functions we need

void cs_8409_cs42l83_mark_jack(struct hda_codec *codec)
{
        struct hda_jack_tbl *event;

        mycodec_info(codec, "cs_8409_cs42l83_mark_jack\n");

        // this is how the Dell fixups do it
        // first explicitly get the jacktbl entry using the known jack nids
        // so can create the res data tag to pass to the standard snd_hda_jack_unsol_event
        // (minus actual GPIO etc data usually seen in the res)
        // - which then scans the jacktbl for the tag etc 
        // but primarily marks the jack as dirty prior to snd_hda_jack_report_sync call
        // plus calls the jack callbacks

        event = snd_hda_jack_tbl_get_mst(codec, CS8409_CS42L83_HP_PIN_NID, 0);

        // note that the only real functions of snd_hda_jack_unsol_event are to call the jack callbacks
        // and snd_hda_jack_report_sync
        // for Apple we have disabled power on/power off callbacks (power_save_node = 0)
        // so now only have call_hp_automute and call_mic_autoswitch to figure out
        // - currently call_hp_automute is disabled because of suppress_auto_mute

        if (event) {
                // now perform the functions of snd_hda_jack_unsol_event explicitly
                //snd_hda_jack_unsol_event(codec, (event->tag << AC_UNSOL_RES_TAG_SHIFT) & AC_UNSOL_RES_TAG);
                // ignoring key_report_jack at the moment
                event->jack_dirty = 1;
                //cs_8409_apple_call_jack_callback(codec, res, event);
                //snd_hda_jack_report_sync(codec);
        }

        // note that the Dell fixups do calls to snd_hda_jack_unsol_event for each jack nid
        // so we have multiple calls to snd_hda_jack_report_sync
        // so far looks as though this is OK as eventually snd_hda_jack_report_sync calls snd_kctl_jack_report
        // to update user side which first checks if stored data is same as updated data and if so does nothing
        //snd_hda_jack_report_sync(codec);

        mycodec_info(codec, "end cs_8409_cs42l83_mark_jack\n");
}


void cs_8409_cs42l83_jack_report_sync(struct hda_codec *codec)
{
        mycodec_info(codec, "cs_8409_cs42l83_jack_report_sync\n");
        snd_hda_jack_report_sync(codec);
}


// this function is for updating jacks when headphone is plugged in or unplugged
void cs_8409_cs42l83_jack_report_hp_update(struct hda_codec *codec, int plugin)
{
        mycodec_info(codec, "cs_8409_cs42l83_jack_report_hp_update: %s\n", (plugin?"plugin":"unplug"));

        snd_hda_jack_report_sync(codec);
}


static void cs_8409_cs42l83_unsol_event_handler(struct hda_codec *codec, unsigned int unsol_res);

// so I think this is what gets called for any unsolicited event - including jack plug events
// so anything we do to switch amp/headphone should be done from here

void cs_8409_cs42l83_jack_unsol_event(struct hda_codec *codec, unsigned int res)
{
        struct hda_jack_tbl *event;
        //int ret_unsol_enable = 0;
        //int tag = (res >> AC_UNSOL_RES_TAG_SHIFT) & 0x7f;
        int tag = (res & AC_UNSOL_RES_TAG) >> AC_UNSOL_RES_TAG_SHIFT;

	// so we have confirmed that these unsol responses are not in linux kernel interrupt state
	//if (in_interrupt())
	//	mycodec_info(codec, "cs_8409_cs42l83_unsol_event - INTERRUPT\n");
	//else
	//	mycodec_info(codec, "cs_8409_cs42l83_unsol_event - not interrupt\n");

        //// read UNSOL enable data to see what current setup is
        //ret_unsol_enable = snd_hda_codec_read(codec, codec->core.afg, 0, AC_VERB_GET_UNSOLICITED_RESPONSE, 0);
        //mycodec_dbg(codec,"UNSOL event 0x01 at unsol is 0x%08x\n",ret_unsol_enable);
        //ret_unsol_enable = snd_hda_codec_read(codec, 0x47, 0, AC_VERB_GET_UNSOLICITED_RESPONSE, 0);
        //mycodec_dbg(codec,"UNSOL event 0x47 at unsol is 0x%08x\n",ret_unsol_enable);

        // so it seems the low order byte of the res for the 8409 is a copy of the GPIO register state
        //// - except that we dont seem to pass this to the callback functions!! - well that was for linux kernel version 4

        codec_info(codec, "cs_8409_cs42l83_jack_unsol_event UNSOL 0x%08x tag 0x%02x\n",res,tag);


        // so now think we dont follow snd_hda_jack_unsol_event - that assumes multiple jacks (nids) from which we have
        // to find one from the tag - hence the use of the jacbktbl.used count for the tag
        // for Apple we have one tag because we have one jack and multiple nids
        // hda_generic implements a gated jack which maybe for handling the case of
        // 2 nids per jack (one for headphones and one for head mike)
        // (see path_realtek.c which seems to use that for hp nids with mic nids)
        // for the apple case even more problematic as we have more than 2 nids, one for headphone output, one for
        // headset input and one for linein input (currently have no idea how to handle lineout) all in same jack

        // so far it appears Apple enables speakers and disables intmike and linein with no headphone
        // intmike only enabled if perform capture
        // dont have any linein enable examples

        // now updating as per the Dell module - which looks up each jacktbl entry explicitly
        // not sure where to assign the jacktbl/event
        // standard snd_hda_jack_unsol_event does the lookup by tag here
        // Dell does it in the interrupt handler for the subcodec by reading/writing to the subcodec
        // it now seems we have only one jack nid to worry about so could find it here
        // currently going with doing it in cs_8409_cs42l83_mark_jack which we will call
        // from the appropriate place as called by the cs_8409_cs42l83_unsol_event_handler call chain



        // this likely was for kernel version 4 - all kernel 5 versions seem to pass res to call_jack_callback
        //// its the callback struct thats passed as an argument to the callback function
        //// so stuff the res data in the private_data member which seems to be used for such a purpose
        ////event->callback->private_data = res;

        // leave this as is even tho so far have only 1 tag so not really needed
        // so could just call the callback routine directly here
        // now removing this - the main callbacks are power up, power down and mic_autoswitch
        // at the moment we are ignoring any power up/down calls - everything is permanently powered on
        // we still have to deal with mic_autoswitch
        // we could do this in the new cs_8409_cs42l83_mark_jack function
        //cs_8409_apple_call_jack_callback(codec, res, event);


        cs_8409_cs42l83_unsol_event_handler(codec, res);


        // we seem to get a weird UNSOL interrupt during initialization - we want to skip the following
        if (((struct cs8409_spec*)(codec->spec))->headset_phase == 0)
               return;

        // this is the code that generates the AC_VERB_GET_PIN_SENSE (0xf09) verb
        // however if we define the jack as a phantom_jack we do not send the AC_VERB_GET_PIN_SENSE (0xf09) verb

        // NOTA BENE - this is a very significant routine which notifies user space of the
        // jack plug/unplug event
        // however now think we need to move the actual call to when we know we have a jack
        // (as per the Dell code to after the cs42l83 headphone sense)
        //snd_hda_jack_report_sync(codec);
}

// Im pretty convinced that Apple uses a timed event from the plugin event
// before performing further setup
// not clear how to set this up in linux
// timer might be way to go but there are some limitations on the timer function
// which is not clear is going to work here
// now think just using msleeps is the way to go - this is similar to code in patch_realtek.c
// for dealing with similar issues
//static struct timer_list cs_8409_hp_timer;

//static void cs_8409_hp_timer_callback(struct timer_list *tlist)
//{
//        myprintk("snd_hda_intel: cs_8409_hp_timer_callback\n");
//}

// have an explict one for 8409
// cs_free is just a definition
//#define cs_8409_apple_free		snd_hda_gen_free

void cs_8409_apple_free(struct hda_codec *codec)
{
#if 0
        struct cs8409_spec *spec = codec->spec;

        /* Cancel i2c clock disable timer, and disable clock if left enabled */
        cancel_delayed_work_sync(&spec->i2c_clk_work);
        cs8409_disable_i2c_clock(codec);
#endif

	//del_timer(&cs_8409_hp_timer);

	snd_hda_gen_free(codec);
}

//      jack handling analysis
//      now it appears that unsolicited events are assumed to be due to jack plug/unplug events
//      so the .unsol_event function is the primary handling function for this
//      and this does NOT appear to depend on PIN_SENSE capability
//      the PIN_SENSE capability seems to be ONLY needed for automute functionality
//      this includes enabling/disabling whether we see a Headphone entry in the settings sound dialog


static int cs_8409_apple_create_input_ctls_old(struct hda_codec *codec);

static int cs_8409_apple_create_input_ctls(struct hda_codec *codec);

static void cs_8409_cs42l83_callback(struct hda_codec *codec, struct hda_jack_callback *event);


static int cs_8409_apple_parse_auto_config(struct hda_codec *codec)
{
	struct cs8409_apple_spec *spec = codec->spec;
	int err;
	int i;

        myprintk("snd_hda_intel: cs_8409_apple_parse_auto_config\n");

	err = snd_hda_parse_pin_defcfg(codec, &spec->gen.autocfg, NULL, 0);
	if (err < 0)
		return err;

	err = snd_hda_gen_parse_auto_config(codec, &spec->gen.autocfg);
	if (err < 0)
		return err;

	// dump the actual auto config before mess with it
	cs_8409_dump_auto_config(codec, "post snd_hda_gen_parse_auto_config");


	// try and dump the nid paths to sort out how to set them
	debug_show_configs(codec, &spec->gen.autocfg);


	// dump the raw path storage
	cs_8409_dump_paths(codec, "post auto config");


	// this would be done in snd_hda_gen_parse_auto_config by check_auto_mute_availability
	// (also by pin power setup)
	// so now think we should NOT do this - we would need to add this per jack nid but we only
	// want to call cs_8409_cs42l83_callback once per unsol event
	//cs_8409_hda_jack_detect_enable_callback(codec, 0x01, 0, 0x37, cs_8409_cs42l83_callback);

	// debug dump of codec jack table callback functions
#ifdef MYSOUNDDEBUGFULL
	cs_8409_dump_callback(codec);
#else
#ifdef MYSOUNDDEBUG
	cs_8409_dump_callback(codec);
#endif
#endif

	// note that create_input_ctls is called towards the end of snd_hda_gen_parse_auto_config

	// it appears the auto config assumes that inputs are connected to ADCs
	// (not true for outputs)

	// according to the Dell version the issue is the 8409 nids have no pin sense capabilities
	// and they get set to phantom jacks - the Dell version fixes the 8409 inputs/outputs connected to the cs42l42 companion codec
	// with PIN SENSE and DETECT capabilities (cs8409_fix_caps) then uses the cs8409_cs42l42_exec_verb replacement
	// for the primary spec->exec_verb function to update the returns from the AC_VERB_GET_PIN_SENSE verb for those
	// nids with actual state from the companion codec
	// note this has no bearing on the auto config - its for handling the unsol events properly


#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 13, 0)
	// new routine to setup inputs - based on the hda_generic code
	cs_8409_apple_create_input_ctls_old(codec);
#else
	// as of 5.13 the definition of AUTO_CFG_MAX_INS has been increased to handle the 8409
	// so the above may not be needed
	// (without the above no input pins were recognised at all)
	// need to check if fixed other input definitions in cs_8409_apple_create_input_ctls
	// and redo the updated input definitions here
	cs_8409_apple_create_input_ctls(codec);
#endif


        // so do I keep this or not??
	/* keep the ADCs powered up when it's dynamically switchable */
	if (spec->gen.dyn_adc_switch) {
		unsigned int done = 0;
		for (i = 0; i < spec->gen.input_mux.num_items; i++) {
			int idx = spec->gen.dyn_adc_idx[i];
			if (done & (1 << idx))
				continue;
			snd_hda_gen_fix_pin_power(codec,
						  spec->gen.adc_nids[idx]);
			done |= 1 << idx;
		}
	}

        myprintk("snd_hda_intel: end cs_8409_apple_parse_auto_config\n");

	return 0;
}

// this is only needed if kernel is < 5.13
#if LINUX_VERSION_CODE < KERNEL_VERSION(5, 13, 0) || TESTING

// pigs - we need a lot of hda_generic local functions
#include "patch_cirrus_hda_generic_copy.h"

// so we need to hack this code because we have more adcs than AUTO_CFG_MAX_INS
// adcs (8) - actual number is 18
// no good way to do this - except to check connection list for each adc and
// see if connected to nid we are looking at
// so define new function

static int cs_8409_add_adc_nid(struct hda_codec *codec, hda_nid_t pin)
{
	struct hda_gen_spec *spec = codec->spec;
	hda_nid_t nid;
	hda_nid_t *adc_nids = spec->adc_nids;
	int max_nums = ARRAY_SIZE(spec->adc_nids);
	int nums = 0;
	int itm = 0;

        myprintk("snd_hda_intel: cs_8409_add_adc_nid pin 0x%x\n",pin);

	for_each_hda_codec_node(nid, codec) {
		unsigned int caps = get_wcaps(codec, nid);
		int type = get_wcaps_type(caps);
		int fndnid = 0;

		if (type != AC_WID_AUD_IN || (caps & AC_WCAP_DIGITAL))
			continue;

		//myprintk("snd_hda_intel: cs_8409_add_adc_nid nid 0x%x\n",nid);

		{
		const hda_nid_t *connptr = NULL;
		int num_conns = snd_hda_get_conn_list(codec, nid, &connptr);
		int i;
		fndnid = 0;
		for (i = 0; i < num_conns; i++) {
			//myprintk("snd_hda_intel: cs_8409_add_adc_nid %d 0x%x\n",num_conns,connptr[i]);
			if (connptr[i] == pin) {
				fndnid = nid;
			}
		}
		}
		if (fndnid == 0)
			continue;

		// save only 1st one we match
		if (spec->num_adc_nids+1 >= max_nums)
			break;
		adc_nids[spec->num_adc_nids] = nid;
		spec->num_adc_nids += 1;
		break;
	}


	mycodec_dbg(codec, "snd_hda_intel: cs_8409_add_adc_nid num nids %d\n",nums);

	for (itm = 0; itm < spec->num_adc_nids; itm++) {
		myprintk("snd_hda_intel: cs_8409_add_adc_nid 0x%02x\n", spec->adc_nids[itm]);
	}

	myprintk("snd_hda_intel: end cs_8409_add_adc_nid\n");

	return nums;
}



// copied from parse_capture_source in hda_generic.c
// we need this although not changed (apart from printks) because local to hda_generic.c

/* parse capture source paths from the given pin and create imux items */
static int cs_8409_parse_capture_source(struct hda_codec *codec, hda_nid_t pin,
				int cfg_idx, int num_adcs,
				const char *label, int anchor)
{
	struct hda_gen_spec *spec = codec->spec;
	struct hda_input_mux *imux = &spec->input_mux;
	int imux_idx = imux->num_items;
	bool imux_added = false;
	int c;

	myprintk("snd_hda_intel: cs_8409_parse_capture_source pin 0x%x\n",pin);

	for (c = 0; c < num_adcs; c++) {
		struct nid_path *path;
		hda_nid_t adc = spec->adc_nids[c];

		myprintk("snd_hda_intel: cs_8409_parse_capture_source pin 0x%x adc 0x%x check reachable\n",pin,adc);

		if (!is_reachable_path(codec, pin, adc))
			continue;
		myprintk("snd_hda_intel: cs_8409_parse_capture_source pin 0x%x adc 0x%x reachable\n",pin,adc);
		path = snd_hda_add_new_path(codec, pin, adc, anchor);
		if (!path)
			continue;
		print_nid_path(codec, "input", path);
		spec->input_paths[imux_idx][c] =
			snd_hda_get_path_idx(codec, path);

		if (!imux_added) {
			if (spec->hp_mic_pin == pin)
				spec->hp_mic_mux_idx = imux->num_items;
			spec->imux_pins[imux->num_items] = pin;
			snd_hda_add_imux_item(codec, imux, label, cfg_idx, NULL);
			imux_added = true;
			if (spec->dyn_adc_switch)
				spec->dyn_adc_idx[imux_idx] = c;
		}
	}

        myprintk("snd_hda_intel: end cs_8409_parse_capture_source\n");

	return 0;
}


#define CFG_IDX_MIX	99	/* a dummy cfg->input idx for stereo mix */

// copied from create_input_ctls in hda_generic.c

static int cs_8409_apple_create_input_ctls_old(struct hda_codec *codec)
{
	struct hda_gen_spec *spec = codec->spec;
	const struct auto_pin_cfg *cfg = &spec->autocfg;
	hda_nid_t mixer = spec->mixer_nid;
	int num_adcs = 0;
	int i, err;
	unsigned int val;

        myprintk("snd_hda_intel: cs_8409_apple_create_input_ctls_old\n");

	// we cannot do this
	//num_adcs = cs_8409_fill_adc_nids(codec);
	//if (num_adcs < 0)
	//	return 0;

	// clear out the auto config setup
	// hope that all_adcs is not different from adc_nids - doesnt seem to be for auto config only
	memset(spec->adc_nids, 0, sizeof(spec->adc_nids));
	memset(spec->all_adcs, 0, sizeof(spec->all_adcs));
	spec->num_adc_nids = 0;

	for (i = 0; i < cfg->num_inputs; i++) {
		hda_nid_t pin;
		int fndadc = 0;

		myprintk("snd_hda_intel: cs_8409_apple_create_input_ctls_old - input %d\n",i);

		pin = cfg->inputs[i].pin;
		if (!is_input_pin(codec, pin))
			continue;

		myprintk("snd_hda_intel: cs_8409_apple_create_input_ctls_old - input %d pin 0x%x\n",i,pin);

		// now scan all nodes for adc nodes and find one connected to this pin
		fndadc = cs_8409_add_adc_nid(codec, pin);
		if (!fndadc)
			continue;
	}

	num_adcs = spec->num_adc_nids;

	/* copy the detected ADCs to all_adcs[] */
	spec->num_all_adcs = spec->num_adc_nids;
	memcpy(spec->all_adcs, spec->adc_nids,  spec->num_adc_nids* sizeof(hda_nid_t));

	err = fill_input_pin_labels(codec);
	if (err < 0)
		return err;

	for (i = 0; i < cfg->num_inputs; i++) {
		hda_nid_t pin;
		int fndadc = 0;

		myprintk("snd_hda_intel: cs_8409_apple_create_input_ctls_old - input %d\n",i);

		pin = cfg->inputs[i].pin;
		if (!is_input_pin(codec, pin))
			continue;

		myprintk("snd_hda_intel: cs_8409_apple_create_input_ctls_old - input %d pin 0x%x\n",i,pin);

		//// now scan the adc nodes and find one connected to this pin
		//fndadc = cs_8409_add_adc_nid(codec, pin);
		//if (!fndadc)
		//	continue;

		val = PIN_IN;
		if (cfg->inputs[i].type == AUTO_PIN_MIC)
			val |= snd_hda_get_default_vref(codec, pin);

		myprintk("snd_hda_intel: cs_8409_apple_create_input_ctls_old - input %d pin 0x%x val 0x%x\n",i,pin,val);

		if (pin != spec->hp_mic_pin &&
		    !snd_hda_codec_get_pin_target(codec, pin))
			set_pin_target(codec, pin, val, false);

		myprintk("snd_hda_intel: cs_8409_apple_create_input_ctls_old - input %d pin 0x%x val 0x%x mixer 0x%x\n",i,pin,val,mixer);

		if (mixer) {
			if (is_reachable_path(codec, pin, mixer)) {
				err = new_analog_input(codec, i, pin,
						       spec->input_labels[i],
						       spec->input_label_idxs[i],
						       mixer);
				if (err < 0)
					return err;
			}
		}

		// so connections are from the adc nid to the input pin nid
		//{
		//const hda_nid_t conn[256];
		//const hda_nid_t *connptr = conn;
		//int num_conns = snd_hda_get_conn_list(codec, pin, &connptr);
		//int i;
		//myprintk("snd_hda_intel: cs_8409_apple_create_input_ctls_old pin 0x%x num conn %d\n",pin,num_conns);
		//for (i = 0; i < num_conns; i++) {
		//	myprintk("snd_hda_intel: cs_8409_apple_create_input_ctls_old pin 0x%x conn 0x%x\n",pin,conn[i]);
		//}
		//}


		// this is the problem routine - this loops over the adcs to do anything
		// so if num_adcs is 0 or none of the adc entries are used this does nothing

		err = cs_8409_parse_capture_source(codec, pin, i, num_adcs,
					   spec->input_labels[i], -mixer);
		if (err < 0)
			return err;

		// comment for the moment as needs lots of other functions
		//if (spec->add_jack_modes) {
		//	err = create_in_jack_mode(codec, pin);
		//	if (err < 0)
		//		return err;
		//}
	}

	/* add stereo mix when explicitly enabled via hint */
	if (mixer && spec->add_stereo_mix_input == HDA_HINT_STEREO_MIX_ENABLE) {
		err = cs_8409_parse_capture_source(codec, mixer, CFG_IDX_MIX, num_adcs,
					   "Stereo Mix", 0);
		if (err < 0)
			return err;
		else
			spec->suppress_auto_mic = 1;
	}

        myprintk("snd_hda_intel: end cs_8409_apple_create_input_ctls_old\n");

	return 0;
}

#endif

/* we still need some fixups with the new version
   as it doesnt seem to setup the inputs correctly
 */

// the culprit function seems to be check_dyn_adc_switch in hda_generic.c
// - it should reduce the adc_nids list down to the 2 connected input adcs - but it does not
// - its current implementation appears to have a fundamental flaw
// - it assumes adcs are in a non-null list that ends in null
// but the 8409 has a random non-null element in an essentially null list


static int cs_8409_apple_create_input_ctls(struct hda_codec *codec)
{
	struct hda_gen_spec *spec = codec->spec;
	const struct auto_pin_cfg *cfg = &spec->autocfg;
	hda_nid_t mixer = spec->mixer_nid;
	struct hda_input_mux *imux = &spec->input_mux;
	int num_adcs = 0;
	int err;
	unsigned int val;
	int i, n, nums;

	myprintk("snd_hda_intel: cs_8409_apple_create_input_ctls\n");

	// determine for which input items we have a non-zero adc
	nums = 0;
	for (i = 0; i < imux->num_items; i++) {
		for (n = 0; n < spec->num_adc_nids; n++) {
			if (spec->input_paths[i][n]) nums++;
		}
	}

	// this code essentially taken from check_dyn_adc_switch
	// reduce the adc_nids list to connected items
	if (nums != spec->num_adc_nids) {
		/* shrink the invalid adcs and input paths */
		printk("snd_hda_intel: hda_generic_check_dyn_adc_switch shrinking\n");
		nums = 0;
		for (i = 0; i < imux->num_items; i++) {
			for (n = 0; n < spec->num_adc_nids; n++) {
				if (spec->input_paths[i][n]) {
					struct nid_path *path = NULL;
					spec->adc_nids[nums] = spec->adc_nids[n];
					//invalidate_nid_path(codec, spec->input_paths[i][nums]);
					// this is explicit coding of simple function invalidate_nid_path from hda_generic.c
					path = snd_hda_get_path_from_idx(codec, spec->input_paths[i][nums]);
					if (path)
						memset(path, 0, sizeof(*path));
					spec->input_paths[i][nums] = spec->input_paths[i][n];
					spec->input_paths[i][n] = 0;
					nums++;
					// only store first non-zero path per adc
					break;
				}
			}
		}
		spec->num_adc_nids = nums;
	}

	for (n=0; n < spec->num_adc_nids; n++) {
		myprintk("snd_hda_intel: cs_8409_apple_create_input_ctls adc nid 0x%02x\n", spec->adc_nids[n]);
	}

	myprintk("snd_hda_intel: end cs_8409_apple_create_input_ctls\n");

	return 0;
}

/* do I need this for 8409 - I certainly need some gpio patching */
static void cs_8409_apple_fixup_gpio(struct hda_codec *codec,
                                     const struct hda_fixup *fix, int action)
{
       myprintk("snd_hda_intel: cs_8409_apple_fixup_gpio\n");

       // allowable states
       // HDA_FIXUP_ACT_PRE_PROBE,
       // HDA_FIXUP_ACT_PROBE,
       // HDA_FIXUP_ACT_INIT,
       // HDA_FIXUP_ACT_BUILD,
       // HDA_FIXUP_ACT_FREE,

       // so inspection suggests no eapd usage on macs - no 0xf0c or 0x70c commands sent

       if (action == HDA_FIXUP_ACT_PRE_PROBE) {
               //struct cs8409_apple_spec *spec = codec->spec;

               myprintk("snd_hda_intel: cs_8409_apple_fixup_gpio pre probe\n");

               //myprintk("fixup gpio hp=0x%x speaker=0x%x\n", hp_out_mask, speaker_out_mask);
               //spec->gpio_eapd_hp = hp_out_mask;
               //spec->gpio_eapd_speaker = speaker_out_mask;
               //spec->gpio_mask = 0xff;
               //spec->gpio_data =
               //  spec->gpio_dir =
               //  spec->gpio_eapd_hp | spec->gpio_eapd_speaker;
       }
       else if (action == HDA_FIXUP_ACT_PROBE) {
               myprintk("snd_hda_intel: cs_8409_apple_fixup_gpio probe\n");
       }
       else if (action == HDA_FIXUP_ACT_INIT) {
               myprintk("snd_hda_intel: cs_8409_apple_fixup_gpio init\n");
       }
       else if (action == HDA_FIXUP_ACT_BUILD) {
               myprintk("snd_hda_intel: cs_8409_apple_fixup_gpio build\n");
       }
       else if (action == HDA_FIXUP_ACT_FREE) {
               myprintk("snd_hda_intel: cs_8409_apple_fixup_gpio free\n");
       }
       myprintk("snd_hda_intel: end cs_8409_apple_fixup_gpio\n");
}


// this is from a previous 8409 fixup - remove when see what need to be replaced by

#ifdef APPLE_FIXUPS

/* CS8409 */
enum {
       CS8409_MBP131,
       CS8409_APPLE_GPIO_0,
       CS8409_MBP143,
       CS8409_APPLE_GPIO,
};

static const struct hda_model_fixup cs8409_apple_models[] = {
       { .id = CS8409_MBP131, .name = "mbp131" },
       { .id = CS8409_MBP143, .name = "mbp143" },
       {}
};


static const struct snd_pci_quirk cs8409_apple_fixup_tbl[] = {
       SND_PCI_QUIRK(0x106b, 0x3300, "MacBookPro 13,1", CS8409_MBP131),
       //SND_PCI_QUIRK(0x106b, 0x3600, "MacBookPro 14,2", CS8409_MBP143),
       SND_PCI_QUIRK(0x106b, 0x3900, "MacBookPro 14,3", CS8409_MBP143),
       //SND_PCI_QUIRK(0x106b, 0x0f00, "Imac 18,2", CS8409_MBP143),
       //SND_PCI_QUIRK(0x106b, 0x1000, "Imac 18,3", CS8409_MBP143),
       //SND_PCI_QUIRK(0x106b, 0x1000, "Imac 19,1", CS8409_MBP143),
       {} /* terminator */
};

static const struct hda_pintbl mbp131_pincfgs[] = {
       {} /* terminator */
};

static const struct hda_pintbl mbp143_pincfgs[] = {
       {} /* terminator */
};

static const struct hda_fixup cs8409_apple_fixups[] = {
       [CS8409_MBP131] = {
               .type = HDA_FIXUP_PINS,
               .v.pins = mbp131_pincfgs,
               .chained = true,
               .chain_id = CS8409_APPLE_GPIO_0,
       },
       [CS8409_APPLE_GPIO_0] = {
               .type = HDA_FIXUP_FUNC,
               .v.func = cs_8409_apple_fixup_gpio,
       },
       [CS8409_MBP143] = {
               .type = HDA_FIXUP_PINS,
               .v.pins = mbp143_pincfgs,
               .chained = true,
               .chain_id = CS8409_APPLE_GPIO,
       },
       [CS8409_APPLE_GPIO] = {
               .type = HDA_FIXUP_FUNC,
               .v.func = cs_8409_apple_fixup_gpio,
       },
};
#endif


// as per Apple we need to fix the pin config for the linein nid (it defaults as no conn, Line Out which messes the auto config)
// (assuming this swaps as nid swaps for macbook pro/imac)
// except define device as line in not mic in as per Apple, remove the 0x00000100 which is apparently AC_DEFCFG_MISC_NO_PRESENCE
// plus make it a jack like the other jack inputs (so 0x00800001 not 0x90a00101 as per Apple)

static const struct hda_pintbl macbook_pro_pincfgs[] = {
        { 0x45, 0x00800101 },
        { }
};
static const struct hda_pintbl imac_pincfgs[] = {
        { 0x44, 0x00800101 },
        { }
};


static void cs_8409_cs42l83_unsolicited_response(struct hda_codec *codec, unsigned int res);

static void cs_8409_cs42l83_callback(struct hda_codec *codec, struct hda_jack_callback *event)
{
        struct cs8409_apple_spec *spec = codec->spec;

        mycodec_info(codec, "cs_8409_cs42l83_callback %pF\n", cs_8409_cs42l83_callback);

	// for kernel version 4 we stored the unsol res data in private_data
	// - now its a separate entity
        ////cs_8409_cs42l83_unsol_event_handler(codec, event->private_data);

        cs_8409_cs42l83_unsol_event_handler(codec, event->unsol_res);

        mycodec_info(codec, "cs_8409_cs42l83_callback end\n");
}


static void cs_8409_cs42l83_unsol_event_handler(struct hda_codec *codec, unsigned int unsol_res)
{
	struct cs8409_apple_spec *spec = codec->spec;

	mycodec_info(codec, "cs_8409_cs42l83_unsol_event_handler\n");


	// print the stored unsol res which seems to be the GPIO pins state
	mycodec_info(codec, "cs_8409_cs42l83_unsol_event_handler - event unsol_res 0x%08x\n",unsol_res);

	cs_8409_cs42l83_unsolicited_response(codec, unsol_res);


	// now think timers not the way to go
	// patch_realtek.c has to deal with similar issues of plugin, headset detection
	// and just uses msleep calls
	//mod_timer(&cs_8409_hp_timer, jiffies + msecs_to_jiffies(250));

        // the delayed_work feature might be a way to go tho

        mycodec_info(codec, "cs_8409_cs42l83_unsol_event_handler end\n");
}


// we have 4 automute hooks
// void (*automute_hook)(struct hda_codec *codec);
// void (*hp_automute_hook)(struct hda_codec *codec, struct hda_jack_callback *cb);
// void (*line_automute_hook)(struct hda_codec *codec, struct hda_jack_callback *cb);
// void (*mic_autoswitch_hook)(struct hda_codec *codec, struct hda_jack_callback *cb);

static void cs_8409_automute(struct hda_codec *codec)
{
	struct cs8409_apple_spec *spec = codec->spec;
	dev_info(hda_codec_dev(codec), "cs_8409_automute called\n");
}

static int cs_8409_boot_setup(struct hda_codec *codec);


static void cs_8409_playback_pcm_hook(struct hda_pcm_stream *hinfo,
                                      struct hda_codec *codec,
                                      struct snd_pcm_substream *substream,
                                      int action);

static void cs_8409_capture_pcm_hook(struct hda_pcm_stream *hinfo,
                                     struct hda_codec *codec,
                                     struct snd_pcm_substream *substream,
                                     int action);

// new attempt if we decide to use the existing fixup mechanism to handle setup

#ifdef APPLE_FIXUPS
static int patch_cs8409_apple_nouse(struct hda_codec *codec)
{
	struct cs8409_apple_spec *spec = codec->spec;
	//struct cs8409_spec *spec = codec->spec;
        int err;
        int itm;

        snd_hda_pick_fixup(codec, cs8409_apple_models, cs8409_apple_fixup_tbl, cs8409_apple_fixups);

        mycodec_dbg(codec, "Picked ID=%d, VID=%08x, DEV=%08x\n", codec->fixup_id,
                         codec->bus->pci->subsystem_vendor,
                         codec->bus->pci->subsystem_device);

        snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);

        err = cs8409_apple_parse_auto_config(codec);
        if (err < 0) {
                cs8409_free(codec);
                return err;
        }

        snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);
        return 0;
}
#endif


// for Apple we need multiple versions because so far macbook pro and imacs use different nids
static int cs8409_cs42l83_macbook_exec_verb(struct hdac_device *dev, unsigned int cmd, unsigned int flags,
                                            unsigned int *res)
{
        struct hda_codec *codec = container_of(dev, struct hda_codec, core);
        struct cs8409_apple_spec *spec = codec->spec;
        //struct cs8409_spec *spec = codec->spec;
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 13, 0)
        struct sub_codec *cs42l83 = spec->scodecs[CS8409_CODEC0];
#endif

        unsigned int nid = ((cmd >> 20) & 0x07f);
        unsigned int verb = ((cmd >> 8) & 0x0fff);

        /* CS8409 pins have no AC_PINSENSE_PRESENCE
	 * capabilities. We have to intercept 2 calls for pins 0x24 and 0x34
         * and return correct pin sense values for read_pin_sense() call from
         * hda_jack based on CS42L42 jack detect status.
         */
#ifdef APPLE_PINSENSE_FIXUP
        switch (nid) {
        case CS8409_CS42L83_HP_PIN_NID:
                if (verb == AC_VERB_GET_PIN_SENSE) {
                        *res = (cs42l83->hp_jack_in) ? AC_PINSENSE_PRESENCE : 0;
                        return 0;
                }
                break;
        case CS8409_CS42L83_HP_MIC_PIN_NID:
                if (verb == AC_VERB_GET_PIN_SENSE) {
                        *res = (cs42l83->mic_jack_in) ? AC_PINSENSE_PRESENCE : 0;
                        return 0;
                }
        case CS8409_CS42L83_MACBOOK_LINEIN_PIN_NID:
                if (verb == AC_VERB_GET_PIN_SENSE) {
                        *res = (cs42l83->linein_jack_in) ? AC_PINSENSE_PRESENCE : 0;
                        return 0;
                }
                break;
        default:
                break;
        }
#endif

        return spec->exec_verb(dev, cmd, flags, res);
}

static int cs8409_cs42l83_imac_exec_verb(struct hdac_device *dev, unsigned int cmd, unsigned int flags,
                                         unsigned int *res)
{
        struct hda_codec *codec = container_of(dev, struct hda_codec, core);
        struct cs8409_apple_spec *spec = codec->spec;
        //struct cs8409_spec *spec = codec->spec;
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 13, 0)
        struct sub_codec *cs42l83 = spec->scodecs[CS8409_CODEC0];
#endif

        unsigned int nid = ((cmd >> 20) & 0x07f);
        unsigned int verb = ((cmd >> 8) & 0x0fff);

        /* CS8409 pins have no AC_PINSENSE_PRESENCE
	 * capabilities. We have to intercept 2 calls for pins 0x24 and 0x34
         * and return correct pin sense values for read_pin_sense() call from
         * hda_jack based on CS42L42 jack detect status.
         */
#ifdef APPLE_PINSENSE_FIXUP
        switch (nid) {
        case CS8409_CS42L83_HP_PIN_NID:
                if (verb == AC_VERB_GET_PIN_SENSE) {
                        *res = (cs42l83->hp_jack_in) ? AC_PINSENSE_PRESENCE : 0;
                        return 0;
                }
                break;
        case CS8409_CS42L83_HP_MIC_PIN_NID:
                if (verb == AC_VERB_GET_PIN_SENSE) {
                        *res = (cs42l83->mic_jack_in) ? AC_PINSENSE_PRESENCE : 0;
                        return 0;
                }
                break;
        case CS8409_CS42L83_IMAC_LINEIN_PIN_NID:
                if (verb == AC_VERB_GET_PIN_SENSE) {
                        *res = (cs42l83->linein_jack_in) ? AC_PINSENSE_PRESENCE : 0;
                        return 0;
                }
                break;
        default:
                break;
        }
#endif

        return spec->exec_verb(dev, cmd, flags, res);
}

static int cs8409_cs42l83_exec_verb(struct hdac_device *dev, unsigned int cmd, unsigned int flags,
                                    unsigned int *res)
{
        struct hda_codec *codec = container_of(dev, struct hda_codec, core);
        struct cs8409_apple_spec *spec = codec->spec;
        //struct cs8409_spec *spec = codec->spec;
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 13, 0)
        struct sub_codec *cs42l83 = spec->scodecs[CS8409_CODEC0];
#endif

        unsigned int nid = ((cmd >> 20) & 0x07f);
        unsigned int verb = ((cmd >> 8) & 0x0fff);

	// we have confirmed this is being called
	//myprintk("snd_hda_intel: cs 8409 exec verb 0x%04x 0x%x\n", nid, verb);

#ifdef APPLE_PINSENSE_FIXUP
        // or we could have a single function and the following
        if (nid == CS8409_CS42L83_HP_PIN_NID) {
		//myprintk("snd_hda_intel: cs 8409 exec verb 0x%04x 0x%x\n", nid, verb);
                if (verb == AC_VERB_GET_PIN_SENSE) {
			//myprintk("snd_hda_intel: cs 8409 exec verb pin sense 0x%04x %d\n", nid, cs42l83->hp_jack_in);
                        //*res = (cs42l83->hp_jack_in) ? AC_PINSENSE_PRESENCE : 0;
                        // initially use my jack_present flag integer
			myprintk("snd_hda_intel: cs 8409 exec verb pin sense 0x%04x %d\n", nid, spec->jack_present);
                        *res = (spec->jack_present) ? AC_PINSENSE_PRESENCE : 0;
                        return 0;
                }
        } else if (nid == CS8409_CS42L83_HP_MIC_PIN_NID) {
		//myprintk("snd_hda_intel: cs 8409 exec verb 0x%04x 0x%x\n", nid, verb);
                if (verb == AC_VERB_GET_PIN_SENSE) {
			//myprintk("snd_hda_intel: cs 8409 exec verb pin sense 0x%04x %d\n", nid, cs42l83->mic_jack_in);
                        //*res = (cs42l83->mic_jack_in) ? AC_PINSENSE_PRESENCE : 0;
                        // initially use my jack_present flag integer
			myprintk("snd_hda_intel: cs 8409 exec verb pin sense 0x%04x %d\n", nid, spec->jack_present);
                        *res = (spec->jack_present) ? AC_PINSENSE_PRESENCE : 0;
                        return 0;
                }
        } else if (nid == spec->linein_nid) {
                //myprintk("snd_hda_intel: cs 8409 exec verb 0x%04x 0x%x\n", nid, verb);
                if (verb == AC_VERB_GET_PIN_SENSE) {
                        //myprintk("snd_hda_intel: cs 8409 exec verb pin sense 0x%04x %d\n", nid, cs42l83->linein_jack_in);
                        //*res = (cs42l83->linein_jack_in) ? AC_PINSENSE_PRESENCE : 0;
                        // initially use my jack_present flag integer
                        myprintk("snd_hda_intel: cs 8409 exec verb pin sense 0x%04x %d\n", nid, spec->jack_present);
                        *res = (spec->jack_present) ? AC_PINSENSE_PRESENCE : 0;
                        return 0;
                }
        }
#endif

        return spec->exec_verb(dev, cmd, flags, res);
}

static struct cs8409_apple_spec *cs8409_apple_alloc_spec(struct hda_codec *codec)
{
	struct cs8409_apple_spec *spec;

	spec = kzalloc(sizeof(*spec), GFP_KERNEL);
	if (!spec)
		return NULL;
	codec->spec = spec;
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 13, 0)
	spec->codec = codec;
#endif
	//spec->vendor_nid = vendor_nid;

	// this allows power control per nid - for Apple ignoring all power control for now
	// this removes eg power up/down on jack plugin/unplug
	//codec->power_save_node = 1;
	// looks like we need an explicit set - 1 maybe default
	codec->power_save_node = 0;
#if 0
        mutex_init(&spec->i2c_mux);
        INIT_DELAYED_WORK(&spec->i2c_clk_work, cs8409_disable_i2c_clock_worker);
#endif
	snd_hda_gen_spec_init(&spec->gen);

	return spec;
}

// for the moment split the new code into an include file

#include "patch_cirrus_new84.h"

static int cs_8409_apple_resume(struct hda_codec *codec)
{
        myprintk("snd_hda_intel: start cs_8409_apple_resume\n");
        cs_8409_boot_setup_real(codec);
        myprintk("snd_hda_intel: end cs_8409_apple_resume\n");
        return 0;
}

// note this must come after any function definitions used

static const struct hda_codec_ops cs_8409_apple_patch_ops = {
	.build_controls = cs_8409_apple_build_controls,
	.build_pcms = cs_8409_apple_build_pcms,
	.init = cs_8409_apple_init,
	.free = cs_8409_apple_free,
	.unsol_event = cs_8409_cs42l83_jack_unsol_event,
#ifdef CONFIG_PM
        .resume = cs_8409_apple_resume,
        .suspend = cs_8409_apple_suspend,
        .check_power_status = cs_8409_apple_check_power_status,
#endif
};

static int patch_cs8409_apple(struct hda_codec *codec)
{
        struct cs8409_apple_spec *spec;
        int err;
        int itm;
        int i;
        //hda_nid_t *dac_nids_ptr = NULL;
        const struct hda_pincfg *pin;
        int fixup_found = 0;

        int explicit = 0;

        //struct hda_pcm *info = NULL;
        //struct hda_pcm_stream *hinfo = NULL;

        myprintk("snd_hda_intel: Patching for CS8409 Apple - explicit %d\n", explicit);
        //mycodec_info(codec, "Patching for CS8409 Apple - %d\n", explicit);

        //dump_stack();

        spec = cs8409_apple_alloc_spec(codec);
        if (!spec)
                return -ENOMEM;


        spec->vendor_nid = CS8409_VENDOR_NID;

        spec->beep_nid = CS8409_BEEP_NID;

        spec->use_data = 0;


        // so it appears we need to explicitly apply pre probe fixups here
        // note that if the pinconfigs lists are empty the pin config fixup
        // is effectively ignored

        //myprintk("cs8409 - 1\n");
        //snd_hda_pick_fixup(codec, cs8409_apple_models, cs8409_apple_fixup_tbl, cs8409_apple_fixups);

        //mycodec_dbg(codec, "Picked ID=%d, VID=%08x, DEV=%08x\n", codec->fixup_id,
        //                 codec->bus->pci->subsystem_vendor,
        //                 codec->bus->pci->subsystem_device);

        //myprintk("cs8409 - 2\n");
        //snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);


        // check if we have an implementation for the current machine
        // probably should update the fixup tables and use those
        // for the moment just replicate the ifs being used
        // at the moment seem to get some crash if dont have a known subsystem id
        fixup_found = 0;
        if (codec->core.subsystem_id == 0x106b3900) {
                // macbook pro 14,3
                fixup_found = 1;
        }
        else if (codec->core.subsystem_id == 0x106b3300 || codec->core.subsystem_id == 0x106b3600) {
                // macbook pro 14,1?13,1, 14,2
                fixup_found = 1;
        }
        else if (codec->core.subsystem_id == 0x106b1000 || codec->core.subsystem_id == 0x106b0f00 || codec->core.subsystem_id == 0x106b0e00) {
                // imac 18,3, 19,1, 18,2, 18,1
                fixup_found = 1;
        }

        if (!fixup_found) {
		dev_err(hda_codec_dev(codec), "UNKNOWN subsystem id 0x%08x",codec->core.subsystem_id);
                return -ENODEV;
        }



        // the following coding is the HDA_FIXUP_ACT_PRE_PROBE phase


	//issue init verbs here
	//snd_hda_add_verbs(codec, cs8409_cs42l83_init_verbh);


#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 13, 0)

        // now going with the Dell way of handling PIN_SENSE for jack plug/unplug events so need this

        myprintk("snd_hda_intel: exec verb setup START\n");
        spec->exec_verb = codec->core.exec_verb;
        codec->core.exec_verb = cs8409_cs42l83_exec_verb;
/*
        if (codec->core.subsystem_id == 0x106b1000 || codec->core.subsystem_id == 0x106b0f00 || codec->core.subsystem_id == 0x106b0e00)
        {
                codec->core.exec_verb = cs8409_cs42l83_imac_exec_verb;
        }
        else:
        {
                codec->core.exec_verb = cs8409_cs42l83_macbook_exec_verb;
        }
 */
        myprintk("snd_hda_intel: exec verb setup DONE\n");

	spec->scodecs[CS8409_CODEC0] = &cs8409_cs42l83_codec;
	spec->num_scodecs = 1;
	spec->scodecs[CS8409_CODEC0]->codec = codec;

	//codec->patch_ops = cs8409_cs42l83_patch_ops;

        if (explicit)
               {
               //codec->patch_ops = cs_8409_apple_patch_ops_explicit;
               }
        else
               codec->patch_ops = cs_8409_apple_patch_ops;


	// not sure about these
        // the suppress_vmaster is likely reasonable as the Apple way has no dynamic volume controls on either the 8409 chip
        // or the amp/cs42l83 chips - the volume is set on boot to a fixed level and never changed
	spec->gen.suppress_auto_mute = 1;
	spec->gen.no_primary_hp = 1;
	spec->gen.suppress_vmaster = 1;

        // we probably also want to suppress auto mic
	spec->gen.suppress_auto_mic = 1;

	// dell GPIO pins are : /* GPIO 5 out, 3,4 in */
	// what is true is the cs8409 interrupt GPIO is pin 1
	// aah - the reset GPIO pin is 0x02
	spec->gpio_dir = spec->scodecs[CS8409_CODEC0]->reset_gpio;
	spec->gpio_data = 0;
	//spec->gpio_mask = 0x03f;
	if (codec->core.subsystem_id == 0x106b3900) {
		spec->gpio_mask = 0x07;
	}
	else if (codec->core.subsystem_id == 0x106b3300 || codec->core.subsystem_id == 0x106b3600) {
		spec->gpio_mask = 0x0f;
	}
        else if (codec->core.subsystem_id == 0x106b1000 || codec->core.subsystem_id == 0x106b0f00 || codec->core.subsystem_id == 0x106b0e00) {
		spec->gpio_mask = 0x0f;
	}
	else {
		dev_info(hda_codec_dev(codec), "UNKNOWN subsystem id 0x%08x",codec->core.subsystem_id);
	}


	// dell init : /* Basic initial sequence for specific hw configuration */
	//snd_hda_sequence_write(codec, cs8409_cs42l42_init_verbs);


        //snd_array_for_each(&codec->init_pins, i, pin) {
        //        hda_nid_t nid = pin->nid;
        //        u32 cfg = pin->cfg;
        //	myprintk("snd_hda_intel: print pincfg init    0x%02x: 0x%02x: 0x%08x\n", i, nid, cfg);
	//}
        //snd_array_for_each(&codec->driver_pins, i, pin) {
        //        hda_nid_t nid = pin->nid;
        //        u32 cfg = pin->cfg;
        //	myprintk("snd_hda_intel: print pincfg driver  0x%02x: 0x%02x: 0x%08x\n", i, nid, cfg);
	//}

        //for (i = 0; i < codec->core.num_nodes; i++)
        //	myprintk("snd_hda_intel: print wcaps pre  0x%02x 0x%08x\n", i, codec->wcaps[i]);


        // as per Apple we need to fix the pin config for the linein nid (it defaults as no conn, Line Out which messes the auto config)
        // (assuming this swaps as nid swaps for macbook pro/imac)
        // except define device as line in not mic in as per Apple plus make it a jack like
        // the other jack inputs (so 0x00800101 not 0x90a00101 as per Apple)

        //static const struct hda_pintbl macbook_pro_pincfgs[] = {
        //        { 0x45, 0x00800101 },
        //        { }
        //};
        //static const struct hda_pintbl imac_pincfgs[] = {
        //        { 0x44, 0x00800101 },
        //        { }
        //};


        // cs8409_fix_caps overrides the jack nid to AC_PINCAP_IMP_SENSE and AC_PINCAP_PRES_DETECT parameters
        // and adds AC_WCAP_UNSOL_CAP to the wcaps
        // - not sure we should do this for AC_WCAP_UNSOL_CAP for Apple
        // - but that depends on how we implement features
        // currently we re-write snd_hda_jack_detect_enable_callback_mst and remove the AC_VERB_SET_UNSOLICITED_ENABLE
        // setup (because we get unsol responses by default)
        // but new idea is could fixup the exec_verb replacement and skip any AC_VERB_SET_UNSOLICITED_ENABLE
        // commands received

#if 1
	// we have one jack but 2 nids to setup - one for output and one for input
	// the headphone output/input is same for both imac and macbook pros
	//cs8409_fix_caps(codec, CS8409_CS42L83_HP_PIN_NID);
	//cs8409_fix_caps(codec, CS8409_CS42L83_HP_MIC_PIN_NID);
	// version of cs8409_fix_caps with some debug prints
	cs8409_fix_caps_debug(codec, CS8409_CS42L83_HP_PIN_NID);
	cs8409_fix_caps_debug(codec, CS8409_CS42L83_HP_MIC_PIN_NID);

	// we also need to setup the linein nid (why is there no lineout??)
	// (note that the internal mike is permanent - on the other hand we do need to turn it off if headset with mike
	//  is plugged in???)
        if (codec->core.subsystem_id == 0x106b1000 || codec->core.subsystem_id == 0x106b0f00 || codec->core.subsystem_id == 0x106b0e00) {
		cs8409_fix_caps(codec, CS8409_CS42L83_IMAC_LINEIN_PIN_NID);
	} else {
		cs8409_fix_caps(codec, CS8409_CS42L83_MACBOOK_LINEIN_PIN_NID);
	}
#endif

        //for (i = 0; i < codec->core.num_nodes; i++)
        //	myprintk("snd_hda_intel: print wcaps post 0x%02x 0x%08x\n", i, codec->wcaps[i]);


        //if (codec->core.subsystem_id == 0x106b1000 || codec->core.subsystem_id == 0x106b0f00 || codec->core.subsystem_id == 0x106b0e00) {
        //       snd_hda_apply_pincfgs(codec, imac_pincfgs);
        //else
        //       snd_hda_apply_pincfgs(codec, macbook_pro_pincfgs);


        // note that the auto config doesnt issue any PIN_SENSE commands but it does use the PINCAP data
        // check_auto_mute_availability uses the PINCAP to determine if a nid can have a jack
        // via is_jack_detectable - however because suppress_automute is set to 1
        // check_auto_mute_availability exits before calling this function
        // maybe because check_auto_mic_availability is also called which also calls is_jack_detectable
        // and is not suppressed
        // so from this we can gather that all auto_mute/automute functionality must be handled explicitly
        // (and not from eg snd_hda_gen_hp_automute/snd_hda_gen_line_automute)
        // whereas auto_mic functionality is handled by the generic functions eg snd_hda_gen_mic_autoswitch


        // Analysis of jack reporting so far:
        // the default coding for generic jack reporting seems to be as follows:
        // the default snd_hda_jack_unsol_event sets jack_dirty to 1 for the jack entry for the nid
        // connected to the jack
        // calls any callbacks for jack events (as set by snd_hda_jack_detect_enable_callback_mst)
        // and then calls snd_hda_jack_report_sync
        // snd_hda_jack_report_sync is the critically important function
        // this function calls jack_detect_update which uses an AC_VERB_GET_PIN_SENSE verb to detect
        // current jack status then unsets jack_dirty to 0
        // then for all jacks the current pin sense state AND button state is reported to the user level
        // via snd_jack_report (a function of jack.c in core directory)
        // which updates user level with a snd_kctl_jack_report - a function of ctljack.c in core
        // which issues a snd_ctl_notify using SNDRV_CTL_EVENT_MASK_VALUE and the previously prepared
        // pin sense state AND button state



	// tip sense setups done here


#else
        if (explicit)
               {
               //codec->patch_ops = cs_8409_apple_patch_ops_explicit;
               }
        else
               codec->patch_ops = cs_8409_apple_patch_ops;
#endif

        // moved to post auto config

        //spec->gen.pcm_playback_hook = cs_8409_playback_pcm_hook;

        //spec->gen.pcm_capture_hook = cs_8409_capture_pcm_hook;

        //spec->gen.automute_hook = cs_8409_automute;

        //timer_setup(&cs_8409_hp_timer, cs_8409_hp_timer_callback, 0);


        // use this to cause unsolicited responses to be stored
        // but not run
        spec->block_unsol = 0;

        INIT_LIST_HEAD(&spec->unsol_list);

        for (itm=0; itm<10; itm++)
                { spec->unsol_items_prealloc_used[itm] = 0; }


        // for the moment set initial jack status to not present
        // we will detect if have jack plugged in on boot later
        spec->jack_present = 0;


        spec->headset_type = 0;

        spec->have_mike = 0;

        spec->have_buttons = 0;

        spec->playing = 0;
        spec->capturing = 0;

        spec->headset_play_format_setup_needed = 1;
        spec->headset_capture_format_setup_needed = 1;

        spec->headset_presetup_done = 0;


        // use this to distinguish which unsolicited phase we are in
        // for the moment - we only seem to get a tag of 0x37 and dont see any
        // different tags being setup in OSX logs
        spec->headset_phase = 0;

        spec->headset_enable = 0;


        // setup the intmike and linein nids
        // these are swapped between macbook pros and imacs
        if (codec->core.subsystem_id == 0x106b1000 || codec->core.subsystem_id == 0x106b0f00 || codec->core.subsystem_id == 0x106b0e00)
        {
                spec->intmike_nid = 0x45;
                spec->intmike_adc_nid = 0x23;
                spec->linein_nid = 0x44;
                spec->linein_amp_nid = 0x22;
        }
        else
        {
                spec->intmike_nid = 0x44;
                spec->intmike_adc_nid = 0x22;
                spec->linein_nid = 0x45;
                spec->linein_amp_nid = 0x23;
        }

        myprintk("snd_hda_intel: intmike_nid     is 0x%02x\n", spec->intmike_nid);
        myprintk("snd_hda_intel: intmike_acc_nid is 0x%02x\n", spec->intmike_adc_nid);


        // ASP is Audio Serial Port
        // DMIC is Digital Microphone Input
        //
        // so it appears that while the intmike/linein nid functions are swapped between macbook pro and imacs
        // the digital mike paths associated with the nids are fixed - which means the digital mike path
        // swaps between macbooks and imac
        // ie nid 0x44 -> 0x22 path 0x82 : 0x0001 ie DMIC1
        // ie nid 0x45 -> 0x23 path 0x82 : 0x0002 ie DMIC2

        // current status 0x82 reg:
        // macbook pro and imac use 0x5400 for speaker amps - ASP1 (nid indpendent??)
        // macbook pro and imac use 0xa800 for headset  amp - ASP2 (nid indpendent??)
        // macbook pro          use 0x0001 for internal mike? - DMIC1 (nid dependent)
        // macbook imac         use 0x0002 for internal mike? - DMIC2 (nid dependent)
        // macbook pro          use 0x0002 for linein? - DMIC2 (nid dependent)
        // macbook imac         use 0x0001 for linein? - DMIC1 (nid dependent)

        // headphone/headset output path
        // nid 0x0a -> 0x2c

        // headset mike path
        // nid 0x3c -> 0x1a

        // combining data from cs4208_...inf with new 8409 updates in patch_cirrus for DEL laptops
        // it seems reg 0x0009 is associated with the digital mikes
        // vendor reg 0x0009 - 0x0023 : DMIC1_MO=10b, DMIC1/2_SR=1
        //                   - 0x0003 : DMIC1_MO=00b, DMIC1/2_SR=1
        //                   - 0x0043 : DMIC2_MO=01b, DMIC1/2_SR=1
        //                   - 0x0083 : DMIC2_MO=10b, DMIC1/2_SR=1 - this is my guess
        // note that Apple also sets bit 0x0010 which so far is undocumented as is not consistent with above data
        //                   - 0x0033 : DMIC1_MO=11b, DMIC1/2_SR=1
        //                   - 0x0093 : DMIC2_MO=10b, DMIC1_MO=01b?, DMIC1/2_SR=1

        // it appears we need to swap a number of vendor node register fields because of the above path swap
        // vendor reg 0x0009 - associated with internal mike from macbook pros
        //      OSX function setConnectionSelect
        //      macbook pro init        0x0013 -> 0x0033 ie 0x0020 bit set
        //             imac init        0x0013 -> 0x0093 ie 0x0080 bit set
        if (codec->core.subsystem_id == 0x106b1000 || codec->core.subsystem_id == 0x106b0f00 || codec->core.subsystem_id == 0x106b0e00)
        {
                spec->reg9_intmike_dmic_mo = 0x0080;    // DMIC2_MO=10b
        }
        else
        {
                spec->reg9_intmike_dmic_mo = 0x0020;    // DMIC1_MO=10b
        }

        // vendor reg 0x0082 - this is a very complex reg
        //                   - it appears to contain 2 sort of separate items - the ASP1 and ASP2 enables and the DMIC1/DMIC2 SCL enables
        //                   - 0xfc03 : ASP1/2_xxx_EN=1, ASP1/2_MCLK_EN=0, DMIC1/2_SCL_EN=1 (was DMIC1_SCL_EN in comments but thinks thats wrong given below)
        //                   - 0xfc01 : (ASP1/2_xxx_EN = 1, ASP1/2_MCLK_EN = 0, DMIC1_SCL_EN = 1)
        //                   - 0xff03 : (ASP1/2_xxx_EN = 1, DMIC1/2_SCL_EN = 1)
        //                   - 0xfd02 : (ASP1/2_xxx_EN = 1, ASP2_MCLK_EN = 0, DMIC2_SCL_EN = 1)
        //                   - 0xfe03 : (ASP1/2_xxx_EN = 1, ASP1_MCLK_EN = 0, DMIC1/2_SCL_EN = 1)
        //                   - so (ASP1_MCLK_EN is 0x0100 and ASP2_MCLK_EN is 0x0200)
        //                   - from the OSX codes we seem to have
        //                   - 0xa800 : ASP2_xxx_EN = 1, ASP1/2_MCLK_EN = 0
        //                   - 0x5400 : ASP1_xxx_EN = 1, ASP1/2_MCLK_EN = 0

        // vendor reg 0x0082 - we need to update the DMIC bit fields but not the ASP bit fields for macbook/imac switch
        if (codec->core.subsystem_id == 0x106b1000 || codec->core.subsystem_id == 0x106b0f00 || codec->core.subsystem_id == 0x106b0e00)
        {
                spec->reg82_intmike_dmic_scl = 0x0002;   // DMIC2_SCL_EN
                spec->reg82_linein_dmic_scl = 0x0001;    // DMIC1_SCL_EN
        }
        else
        {
                spec->reg82_intmike_dmic_scl = 0x0001;   // DMIC1_SCL_EN
                spec->reg82_linein_dmic_scl = 0x0002;    // DMIC2_SCL_EN
        }


        // the jack detect enable callback can be either in PRE_PROBE or PROBE phase

        myprintk("snd_hda_intel: cs 8409 jack used %d\n",codec->jacktbl.used);

        // we need to figure out how to setup the jack detect callback
        // not clear what nid should be used - 0x01 or 0x47
        // added a tag argument because we seem to get a tag
        // so far the tag seems to be 0x37
        //cs_8409_hda_jack_detect_enable_callback(codec, 0x01, 0, 0x37, cs_8409_cs42l83_callback);

        //myprintk("snd_hda_intel: cs 8409 jack used callback %d\n",codec->jacktbl.used);


        //      cs8409_pinmux_init(codec);


        // so it appears we dont get interrupts in the auto config stage

       if (!explicit)
       {

              myprintk("snd_hda_intel: pre cs_8409_apple_parse_auto_config\n");

              err = cs_8409_apple_parse_auto_config(codec);
              if (err < 0)
                      goto error;

              myprintk("snd_hda_intel: post cs_8409_apple_parse_auto_config\n");

              cs_8409_dump_auto_config(codec, "post cs_8409_apple_parse_auto_config");
       }


       // dump the rates/format of the afg node
       // still havent figured out how the user space gets the allowed formats
       // ah - may have figured this
       // except that at this point this is NULL - we need to be after build pcms
       //info = spec->gen.pcm_rec[0];
       //if (info != NULL)
       //{
       //       hinfo = &(info->stream[SNDRV_PCM_STREAM_PLAYBACK]);
       //       if (hinfo != NULL)
       //              mycodec_dbg(codec, "playback info stream nid 0x%02x rates 0x%08x formats 0x%016llx\n",hinfo->nid,hinfo->rates,hinfo->formats);
       //       else
       //              mycodec_dbg(codec, "playback info stream NULL\n");
       //}
       //else
       //       mycodec_dbg(codec, "playback info NULL\n");


	// the following code would be the HDA_FIXUP_ACT_PROBE phase


        // new idea to try and use the gated/gating jack function as we have only one jack
        // and this seems to be what gating/gated jacks seem to be designed for



	// this is how to fix the format for the streams
	// dell : /* Fix Sample Rate to 48kHz */
	//spec->gen.stream_analog_playback = &cs42l83_apple_pcm_analog_playback;
	//spec->gen.stream_analog_capture = &cs42l83_apple_pcm_analog_capture;


	spec->gen.pcm_playback_hook = cs_8409_playback_pcm_hook;

	spec->gen.pcm_capture_hook = cs_8409_capture_pcm_hook;

	spec->gen.automute_hook = cs_8409_automute;


	// so this seems to be how we setup volume controls for the headphones
	// - but this sets up controls on the 8409 to directly update the cs42l42
	// - this is not how apple does things - all volume controls must occur
        // prior to this driver
        // the problem is this means we need some pulse/alsa configuration to setup
        // such controls

	// del : /* Set initial DMIC volume to -26 dB */
	//snd_hda_codec_amp_init_stereo(codec, CS8409_CS42L42_DMIC_ADC_PIN_NID,
        //                                      HDA_INPUT, 0, 0xff, 0x19);
	//snd_hda_gen_add_kctl(&spec->gen, "Headphone Playback Volume",
        //                        &cs42l42_dac_volume_mixer);
	//snd_hda_gen_add_kctl(&spec->gen, "Mic Capture Volume",
        //                        &cs42l42_adc_volume_mixer);


	// del : /* Disable Unsolicited Response during boot */
	//cs8409_enable_ur(codec, 0);


	snd_hda_codec_set_name(codec, "CS8409/CS42L83");


	myprintk("snd_hda_intel: cs 8409 jack used post %d\n",codec->jacktbl.used);

#ifdef MYSOUNDDEBUGFULL
	cs_8409_dump_callback(codec);
#else
#ifdef MYSOUNDDEBUG
	cs_8409_dump_callback(codec);
#endif
#endif



       err = cs_8409_boot_setup(codec);
       if (err < 0)
               goto error;

       // update the headset phase
       spec->headset_phase = 2;

       spec->play_init = 0;
       spec->capture_init = 0;

       // init the last play time
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 8, 0)
       ktime_get_real_ts64(&(spec->last_play_time));
#else
       getnstimeofday(&(spec->last_play_time));
#endif

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 8, 0)
       ktime_get_real_ts64(&(spec->first_play_time));
#else
       getnstimeofday(&(spec->first_play_time));
#endif

       myprintk("snd_hda_intel: Post Patching for CS8409 Apple\n");
       //mycodec_info(codec, "Post Patching for CS8409 Apple\n");

       return 0;

 error:
       cs_8409_apple_free(codec);
       return err;
}

// new function to use "vendor" defined commands to run
// a specific code
// has to be here to use functions defined in patch_cirrus_new84.h

static unsigned int
cs_8409_extended_codec_verb(struct hda_codec *codec, hda_nid_t nid,
                                int flags,
                                unsigned int verb, unsigned int parm)
{
	//static inline unsigned int cs_8409_vendor_i2cRead(struct hda_codec *codec, unsigned int i2c_address,
	//                                    unsigned int i2c_reg, unsigned int paged)
	unsigned int retval1 = 0;
	unsigned int retval2 = 0;
	unsigned int retval3 = 0;
	unsigned int retval4 = 0;
	unsigned int retval = 0;

        myprintk("snd_hda_intel: cs_8409_extended_codec_verb nid 0x%02x flags 0x%x verb 0x%03x parm 0x%04x\n", nid, flags, verb, parm);

	if ((verb & 0x0ff8) == 0xf78)
	{
		retval1 = cs_8409_vendor_i2cWrite(codec, 0x64, 0x2d, parm, 0);
		retval2 = cs_8409_vendor_i2cWrite(codec, 0x62, 0x2d, parm, 0);
		retval3 = cs_8409_vendor_i2cWrite(codec, 0x74, 0x2d, parm, 0);
		retval4 = cs_8409_vendor_i2cWrite(codec, 0x72, 0x2d, parm, 0);

		myprintk("snd_hda_intel: cs_8409_extended_codec_verb wr ret 1 0x%x\n",retval1);
		myprintk("snd_hda_intel: cs_8409_extended_codec_verb wr ret 2 0x%x\n",retval2);
		myprintk("snd_hda_intel: cs_8409_extended_codec_verb wr ret 3 0x%x\n",retval3);
		myprintk("snd_hda_intel: cs_8409_extended_codec_verb wr ret 4 0x%x\n",retval4);
	}
	else if ((verb & 0x0ff8) == 0xff8)
	{
		retval1 = cs_8409_vendor_i2cRead(codec, 0x64, 0x2d, 0);
		retval2 = cs_8409_vendor_i2cRead(codec, 0x62, 0x2d, 0);
		retval3 = cs_8409_vendor_i2cRead(codec, 0x74, 0x2d, 0);
		retval4 = cs_8409_vendor_i2cRead(codec, 0x72, 0x2d, 0);

		myprintk("snd_hda_intel: cs_8409_extended_codec_verb rd ret 1 0x%x\n",retval1);
		myprintk("snd_hda_intel: cs_8409_extended_codec_verb rd ret 2 0x%x\n",retval2);
		myprintk("snd_hda_intel: cs_8409_extended_codec_verb rd ret 3 0x%x\n",retval3);
		myprintk("snd_hda_intel: cs_8409_extended_codec_verb rd ret 4 0x%x\n",retval4);
	}


	retval = retval1;

	return retval;
}

#ifdef ADD_EXTENDED_VERB
static void cs_8409_set_extended_codec_verb(void)
{
	snd_hda_set_extended_codec_verb(cs_8409_extended_codec_verb);
}
#endif


