/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * HD audio interface patch for Cirrus Logic CS8409 HDA bridge chip
 *
 * Copyright (C) 2021 Cirrus Logic, Inc. and
 *                    Cirrus Logic International Semiconductor Ltd.
 */

#ifndef __CS8409_PATCH_H
#define __CS8409_PATCH_H

#include <linux/pci.h>
#include <sound/tlv.h>
#include <linux/workqueue.h>
#include <sound/hda_codec.h>
#include "hda_local.h"
#include "hda_auto_parser.h"
#include "hda_jack.h"
#include "hda_generic.h"

//#ifdef APPLE_CODECS
//#include <linux/ctype.h>
//#include <linux/timer.h>
//#include <linux/bitops.h>
//#endif

/* CS8409 Specific Definitions */

enum cs8409_pins {
	CS8409_PIN_ROOT,		// nid 0x00
	CS8409_PIN_AFG,			// nid 0x01
	CS8409_PIN_ASP1_OUT_A,		// nid 0x02
	CS8409_PIN_ASP1_OUT_B,		// nid 0x03
	CS8409_PIN_ASP1_OUT_C,		// nid 0x04
	CS8409_PIN_ASP1_OUT_D,		// nid 0x05
	CS8409_PIN_ASP1_OUT_E,		// nid 0x06
	CS8409_PIN_ASP1_OUT_F,		// nid 0x07
	CS8409_PIN_ASP1_OUT_G,		// nid 0x08
	CS8409_PIN_ASP1_OUT_H,		// nid 0x09
	CS8409_PIN_ASP2_OUT_A,		// nid 0x0a
	CS8409_PIN_ASP2_OUT_B,		// nid 0x0b
	CS8409_PIN_ASP2_OUT_C,		// nid 0x0c
	CS8409_PIN_ASP2_OUT_D,		// nid 0x0d
	CS8409_PIN_ASP2_OUT_E,		// nid 0x0e
	CS8409_PIN_ASP2_OUT_F,		// nid 0x0f
	CS8409_PIN_ASP2_OUT_G,		// nid 0x10
	CS8409_PIN_ASP2_OUT_H,		// nid 0x11
	CS8409_PIN_ASP1_IN_A,		// nid 0x12
	CS8409_PIN_ASP1_IN_B,		// nid 0x13
	CS8409_PIN_ASP1_IN_C,		// nid 0x14
	CS8409_PIN_ASP1_IN_D,		// nid 0x15
	CS8409_PIN_ASP1_IN_E,		// nid 0x16
	CS8409_PIN_ASP1_IN_F,		// nid 0x17
	CS8409_PIN_ASP1_IN_G,		// nid 0x18
	CS8409_PIN_ASP1_IN_H,		// nid 0x19
	CS8409_PIN_ASP2_IN_A,		// nid 0x1a
	CS8409_PIN_ASP2_IN_B,		// nid 0x1b
	CS8409_PIN_ASP2_IN_C,		// nid 0x1c
	CS8409_PIN_ASP2_IN_D,		// nid 0x1d
	CS8409_PIN_ASP2_IN_E,		// nid 0x1e
	CS8409_PIN_ASP2_IN_F,		// nid 0x1f
	CS8409_PIN_ASP2_IN_G,		// nid 0x20
	CS8409_PIN_ASP2_IN_H,		// nid 0x21
	CS8409_PIN_DMIC1,		// nid 0x22
	CS8409_PIN_DMIC2,		// nid 0x23
	CS8409_PIN_ASP1_TRANSMITTER_A,	// nid 0x24
	CS8409_PIN_ASP1_TRANSMITTER_B,	// nid 0x25
	CS8409_PIN_ASP1_TRANSMITTER_C,	// nid 0x26
	CS8409_PIN_ASP1_TRANSMITTER_D,	// nid 0x27
	CS8409_PIN_ASP1_TRANSMITTER_E,	// nid 0x28
	CS8409_PIN_ASP1_TRANSMITTER_F,	// nid 0x29
	CS8409_PIN_ASP1_TRANSMITTER_G,	// nid 0x2a
	CS8409_PIN_ASP1_TRANSMITTER_H,	// nid 0x2b
	CS8409_PIN_ASP2_TRANSMITTER_A,	// nid 0x2c
	CS8409_PIN_ASP2_TRANSMITTER_B,	// nid 0x2d
	CS8409_PIN_ASP2_TRANSMITTER_C,	// nid 0x2e
	CS8409_PIN_ASP2_TRANSMITTER_D,	// nid 0x2f
	CS8409_PIN_ASP2_TRANSMITTER_E,	// nid 0x30
	CS8409_PIN_ASP2_TRANSMITTER_F,	// nid 0x31
	CS8409_PIN_ASP2_TRANSMITTER_G,	// nid 0x32
	CS8409_PIN_ASP2_TRANSMITTER_H,	// nid 0x33
	CS8409_PIN_ASP1_RECEIVER_A,	// nid 0x34
	CS8409_PIN_ASP1_RECEIVER_B,	// nid 0x35
	CS8409_PIN_ASP1_RECEIVER_C,	// nid 0x36
	CS8409_PIN_ASP1_RECEIVER_D,	// nid 0x37
	CS8409_PIN_ASP1_RECEIVER_E,	// nid 0x38
	CS8409_PIN_ASP1_RECEIVER_F,	// nid 0x39
	CS8409_PIN_ASP1_RECEIVER_G,	// nid 0x3a
	CS8409_PIN_ASP1_RECEIVER_H,	// nid 0x3b
	CS8409_PIN_ASP2_RECEIVER_A,	// nid 0x3c
	CS8409_PIN_ASP2_RECEIVER_B,	// nid 0x3d
	CS8409_PIN_ASP2_RECEIVER_C,	// nid 0x3e
	CS8409_PIN_ASP2_RECEIVER_D,	// nid 0x3f
	CS8409_PIN_ASP2_RECEIVER_E,	// nid 0x40
	CS8409_PIN_ASP2_RECEIVER_F,	// nid 0x41
	CS8409_PIN_ASP2_RECEIVER_G,	// nid 0x42
	CS8409_PIN_ASP2_RECEIVER_H,	// nid 0x43
	CS8409_PIN_DMIC1_IN,		// nid 0x44
	CS8409_PIN_DMIC2_IN,		// nid 0x45
	CS8409_PIN_BEEP_GEN,		// nid 0x46
	CS8409_PIN_VENDOR_WIDGET	// nid 0x47
};

enum cs8409_coefficient_index_registers {
	CS8409_DEV_CFG1,		// reg 0x00
	CS8409_DEV_CFG2,		// reg 0x01
	CS8409_DEV_CFG3,		// reg 0x02
	CS8409_ASP1_CLK_CTRL1,		// reg 0x03
	CS8409_ASP1_CLK_CTRL2,		// reg 0x04
	CS8409_ASP1_CLK_CTRL3,		// reg 0x05
	CS8409_ASP2_CLK_CTRL1,		// reg 0x06
	CS8409_ASP2_CLK_CTRL2,		// reg 0x07
	CS8409_ASP2_CLK_CTRL3,		// reg 0x08
	CS8409_DMIC_CFG,		// reg 0x09
	CS8409_BEEP_CFG,		// reg 0x0a
	ASP1_RX_NULL_INS_RMV,		// reg 0x0b
	ASP1_Rx_RATE1,			// reg 0x0c
	ASP1_Rx_RATE2,			// reg 0x0d
	ASP1_Tx_NULL_INS_RMV,		// reg 0x0e
	ASP1_Tx_RATE1,			// reg 0x0f
	ASP1_Tx_RATE2,			// reg 0x10
	ASP2_Rx_NULL_INS_RMV,		// reg 0x11
	ASP2_Rx_RATE1,			// reg 0x12
	ASP2_Rx_RATE2,			// reg 0x13
	ASP2_Tx_NULL_INS_RMV,		// reg 0x14
	ASP2_Tx_RATE1,			// reg 0x15
	ASP2_Tx_RATE2,			// reg 0x16
	ASP1_SYNC_CTRL,			// reg 0x17
	ASP2_SYNC_CTRL,			// reg 0x18
	ASP1_A_TX_CTRL1,		// reg 0x19
	ASP1_A_TX_CTRL2,		// reg 0x1a
	ASP1_B_TX_CTRL1,		// reg 0x1b
	ASP1_B_TX_CTRL2,		// reg 0x1c
	ASP1_C_TX_CTRL1,		// reg 0x1d
	ASP1_C_TX_CTRL2,		// reg 0x1e
	ASP1_D_TX_CTRL1,		// reg 0x1f
	ASP1_D_TX_CTRL2,		// reg 0x20
	ASP1_E_TX_CTRL1,		// reg 0x21
	ASP1_E_TX_CTRL2,		// reg 0x22
	ASP1_F_TX_CTRL1,		// reg 0x23
	ASP1_F_TX_CTRL2,		// reg 0x24
	ASP1_G_TX_CTRL1,		// reg 0x25
	ASP1_G_TX_CTRL2,		// reg 0x26
	ASP1_H_TX_CTRL1,		// reg 0x27
	ASP1_H_TX_CTRL2,		// reg 0x28
	ASP2_A_TX_CTRL1,		// reg 0x29
	ASP2_A_TX_CTRL2,		// reg 0x2a
	ASP2_B_TX_CTRL1,		// reg 0x2b
	ASP2_B_TX_CTRL2,		// reg 0x2c
	ASP2_C_TX_CTRL1,		// reg 0x2d
	ASP2_C_TX_CTRL2,		// reg 0x2e
	ASP2_D_TX_CTRL1,		// reg 0x2f
	ASP2_D_TX_CTRL2,		// reg 0x30
	ASP2_E_TX_CTRL1,		// reg 0x31
	ASP2_E_TX_CTRL2,		// reg 0x32
	ASP2_F_TX_CTRL1,		// reg 0x33
	ASP2_F_TX_CTRL2,		// reg 0x34
	ASP2_G_TX_CTRL1,		// reg 0x35
	ASP2_G_TX_CTRL2,		// reg 0x36
	ASP2_H_TX_CTRL1,		// reg 0x37
	ASP2_H_TX_CTRL2,		// reg 0x38
	ASP1_A_RX_CTRL1,		// reg 0x39
	ASP1_A_RX_CTRL2,		// reg 0x3a
	ASP1_B_RX_CTRL1,		// reg 0x3b
	ASP1_B_RX_CTRL2,		// reg 0x3c
	ASP1_C_RX_CTRL1,		// reg 0x3d
	ASP1_C_RX_CTRL2,		// reg 0x3e
	ASP1_D_RX_CTRL1,		// reg 0x3f
	ASP1_D_RX_CTRL2,		// reg 0x40
	ASP1_E_RX_CTRL1,		// reg 0x41
	ASP1_E_RX_CTRL2,		// reg 0x42
	ASP1_F_RX_CTRL1,		// reg 0x43
	ASP1_F_RX_CTRL2,		// reg 0x44
	ASP1_G_RX_CTRL1,		// reg 0x45
	ASP1_G_RX_CTRL2,		// reg 0x46
	ASP1_H_RX_CTRL1,		// reg 0x47
	ASP1_H_RX_CTRL2,		// reg 0x48
	ASP2_A_RX_CTRL1,		// reg 0x49
	ASP2_A_RX_CTRL2,		// reg 0x4a
	ASP2_B_RX_CTRL1,		// reg 0x4b
	ASP2_B_RX_CTRL2,		// reg 0x4c
	ASP2_C_RX_CTRL1,		// reg 0x4d
	ASP2_C_RX_CTRL2,		// reg 0x4e
	ASP2_D_RX_CTRL1,		// reg 0x4f
	ASP2_D_RX_CTRL2,		// reg 0x50
	ASP2_E_RX_CTRL1,		// reg 0x51
	ASP2_E_RX_CTRL2,		// reg 0x52
	ASP2_F_RX_CTRL1,		// reg 0x53
	ASP2_F_RX_CTRL2,		// reg 0x54
	ASP2_G_RX_CTRL1,		// reg 0x55
	ASP2_G_RX_CTRL2,		// reg 0x56
	ASP2_H_RX_CTRL1,		// reg 0x57
	ASP2_H_RX_CTRL2,		// reg 0x58
	CS8409_I2C_ADDR,		// reg 0x59
	CS8409_I2C_DATA,		// reg 0x5a
	CS8409_I2C_CTRL,		// reg 0x5b
	CS8409_I2C_STS,			// reg 0x5c
	CS8409_I2C_QWRITE,		// reg 0x5d
	CS8409_I2C_QREAD,		// reg 0x5e
	CS8409_SPI_CTRL,		// reg 0x5f
	CS8409_SPI_TX_DATA,		// reg 0x60
	CS8409_SPI_RX_DATA,		// reg 0x61
	CS8409_SPI_STS,			// reg 0x62
	CS8409_PFE_COEF_W1, 		// reg 0x63	/* Parametric filter engine coefficient write 1*/
	CS8409_PFE_COEF_W2,		// reg 0x64
	CS8409_PFE_CTRL1,		// reg 0x65
	CS8409_PFE_CTRL2,		// reg 0x66
	CS8409_PRE_SCALE_ATTN1,		// reg 0x67
	CS8409_PRE_SCALE_ATTN2,		// reg 0x68
	CS8409_PFE_COEF_MON1,		// reg 0x69	/* Parametric filter engine coefficient monitor 1*/
	CS8409_PFE_COEF_MON2,		// reg 0x6a
	CS8409_ASP1_INTRN_STS,		// reg 0x6b
	CS8409_ASP2_INTRN_STS,		// reg 0x6c
	CS8409_ASP1_RX_SCLK_COUNT,	// reg 0x6d
	CS8409_ASP1_TX_SCLK_COUNT,	// reg 0x6e
	CS8409_ASP2_RX_SCLK_COUNT,	// reg 0x6f
	CS8409_ASP2_TX_SCLK_COUNT,	// reg 0x70
	CS8409_ASP_UNS_RESP_MASK,	// reg 0x71
	CS8409_LOOPBACK_CTRL = 0x80,
	CS8409_PAD_CFG_SLW_RATE_CTRL = 0x82,	/* Pad Config and Slew Rate Control (CIR = 0x0082) */
};

/* CS42L42 Specific Definitions */

#define CS8409_MAX_CODECS			8
#define CS42L42_VOLUMES				(4U)
#define CS42L42_HP_VOL_REAL_MIN			(-63)
#define CS42L42_HP_VOL_REAL_MAX			(0)
#define CS42L42_AMIC_VOL_REAL_MIN		(-97)
#define CS42L42_AMIC_VOL_REAL_MAX		(12)
#define CS42L42_REG_HS_VOL_CHA			(0x2301)
#define CS42L42_REG_HS_VOL_CHB			(0x2303)
#define CS42L42_REG_HS_VOL_MASK			(0x003F)
#define CS42L42_REG_AMIC_VOL			(0x1D03)
#define CS42L42_REG_AMIC_VOL_MASK		(0x00FF)
#define CS42L42_HSDET_AUTO_DONE			(0x02)
#define CS42L42_HSTYPE_MASK			(0x03)
#define CS42L42_JACK_INSERTED			(0x0C)
#define CS42L42_JACK_REMOVED			(0x00)
#define CS42L42_I2C_TIMEOUT_US			(20000)
#define CS42L42_I2C_SLEEP_US			(2000)
#define CS42L42_PDN_TIMEOUT_US			(250000)
#define CS42L42_PDN_SLEEP_US			(2000)

/* Dell BULLSEYE / WARLOCK / CYBORG Specific Definitions */

#define CS42L42_I2C_ADDR			(0x48 << 1)
#define CS8409_CS42L42_RESET			GENMASK(5, 5) /* CS8409_GPIO5 */
#define CS8409_CS42L42_INT			GENMASK(4, 4) /* CS8409_GPIO4 */
#define CS8409_CS42L42_HP_PIN_NID		CS8409_PIN_ASP1_TRANSMITTER_A
#define CS8409_CS42L42_SPK_PIN_NID		CS8409_PIN_ASP2_TRANSMITTER_A
#define CS8409_CS42L42_AMIC_PIN_NID		CS8409_PIN_ASP1_RECEIVER_A
#define CS8409_CS42L42_DMIC_PIN_NID		CS8409_PIN_DMIC1_IN
#define CS8409_CS42L42_DMIC_ADC_PIN_NID		CS8409_PIN_DMIC1

/* Dolphin */

#define DOLPHIN_C0_I2C_ADDR			(0x48 << 1)
#define DOLPHIN_C1_I2C_ADDR			(0x49 << 1)
#define DOLPHIN_HP_PIN_NID			CS8409_PIN_ASP1_TRANSMITTER_A
#define DOLPHIN_LO_PIN_NID			CS8409_PIN_ASP1_TRANSMITTER_B
#define DOLPHIN_AMIC_PIN_NID			CS8409_PIN_ASP1_RECEIVER_A

#define DOLPHIN_C0_INT				GENMASK(4, 4)
#define DOLPHIN_C1_INT				GENMASK(0, 0)
#define DOLPHIN_C0_RESET			GENMASK(5, 5)
#define DOLPHIN_C1_RESET			GENMASK(1, 1)
#define DOLPHIN_WAKE				(DOLPHIN_C0_INT | DOLPHIN_C1_INT)

enum {
	CS8409_BULLSEYE,
	CS8409_WARLOCK,
	CS8409_CYBORG,
	CS8409_FIXUPS,
	CS8409_DOLPHIN,
	CS8409_DOLPHIN_FIXUPS,
};

enum {
	CS8409_CODEC0,
	CS8409_CODEC1
};

enum {
	CS42L42_VOL_ADC,
	CS42L42_VOL_DAC,
};

#define CS42L42_ADC_VOL_OFFSET			(CS42L42_VOL_ADC)
#define CS42L42_DAC_CH0_VOL_OFFSET		(CS42L42_VOL_DAC)
#define CS42L42_DAC_CH1_VOL_OFFSET		(CS42L42_VOL_DAC + 1)

struct cs8409_i2c_param {
	unsigned int addr;
	unsigned int value;
};

struct cs8409_cir_param {
	unsigned int nid;
	unsigned int cir;
	unsigned int coeff;
};


#ifdef APPLE_CODECS
struct unsol_item {
        struct list_head list;
        unsigned int idx;
        unsigned int res;
};
#endif

struct sub_codec {
	struct hda_codec *codec;
	unsigned int addr;
	unsigned int reset_gpio;
	unsigned int irq_mask;
	const struct cs8409_i2c_param *init_seq;
	unsigned int init_seq_num;

	unsigned int hp_jack_in:1;
	unsigned int mic_jack_in:1;
#ifdef APPLE_CODECS
	unsigned int linein_jack_in:1;
#endif
	unsigned int force_status_change:1;
	unsigned int suspended:1;
	unsigned int paged:1;
	unsigned int last_page;
	unsigned int hsbias_hiz;
	unsigned int full_scale_vol:1;
	unsigned int no_type_dect:1;

	s8 vol[CS42L42_VOLUMES];
};

struct cs8409_spec {
	struct hda_gen_spec gen;
	struct hda_codec *codec;

	struct sub_codec *scodecs[CS8409_MAX_CODECS];
	unsigned int num_scodecs;

	unsigned int gpio_mask;
	unsigned int gpio_dir;
	unsigned int gpio_data;

	struct mutex i2c_mux;
	unsigned int i2c_clck_enabled;
	unsigned int dev_addr;
	struct delayed_work i2c_clk_work;

	unsigned int playback_started:1;
	unsigned int capture_started:1;
	unsigned int init_done:1;
	unsigned int build_ctrl_done:1;

#ifdef APPLE_CODECS

	// additional data for Apple 8409 system

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

	// new item to deal with jack presence as Apple (and now Dell) seems to have barfed
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
	// not really used now have analyzed interrupts properly
	int headset_phase;

	// another dirty hack item to manage the different headset enable codes
	int headset_enable;

	int play_init;
	int capture_init;


	// new item to limit times we redo unmute/play
	struct timespec64 last_play_time;
	// record the first play time - we have a problem there
	// some initial plays that I dont understand - so skip any setup
	// till sometime after the first play
	struct timespec64 first_play_time;


#endif


	/* verb exec op override */
	int (*exec_verb)(struct hdac_device *dev, unsigned int cmd, unsigned int flags,
			 unsigned int *res);
};

extern const struct snd_kcontrol_new cs42l42_dac_volume_mixer;
extern const struct snd_kcontrol_new cs42l42_adc_volume_mixer;

int cs42l42_volume_info(struct snd_kcontrol *kctrl, struct snd_ctl_elem_info *uinfo);
int cs42l42_volume_get(struct snd_kcontrol *kctrl, struct snd_ctl_elem_value *uctrl);
int cs42l42_volume_put(struct snd_kcontrol *kctrl, struct snd_ctl_elem_value *uctrl);

extern const struct hda_pcm_stream cs42l42_48k_pcm_analog_playback;
extern const struct hda_pcm_stream cs42l42_48k_pcm_analog_capture;
extern const struct snd_pci_quirk cs8409_fixup_tbl[];
extern const struct hda_model_fixup cs8409_models[];
extern const struct hda_fixup cs8409_fixups[];
extern const struct hda_verb cs8409_cs42l42_init_verbs[];
extern const struct hda_pintbl cs8409_cs42l42_pincfgs[];
extern const struct cs8409_cir_param cs8409_cs42l42_hw_cfg[];
extern const struct cs8409_cir_param cs8409_cs42l42_bullseye_atn[];
extern struct sub_codec cs8409_cs42l42_codec;

extern const struct hda_verb dolphin_init_verbs[];
extern const struct hda_pintbl dolphin_pincfgs[];
extern const struct cs8409_cir_param dolphin_hw_cfg[];
extern struct sub_codec dolphin_cs42l42_0;
extern struct sub_codec dolphin_cs42l42_1;

void cs8409_cs42l42_fixups(struct hda_codec *codec, const struct hda_fixup *fix, int action);
void dolphin_fixups(struct hda_codec *codec, const struct hda_fixup *fix, int action);

#endif
