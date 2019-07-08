

// this sets the power state of the AFG node - ie node 0x1
// this calls hda_sync_power_state
//hda_set_power_state(codec, AC_PWRST_D0);

// this checks the node has reached the requested power state
//state = hda_sync_power_state(codec, fg, power_state);
//


// pigs need local definition as this is a static local function

/*
 * wait until the state is reached, returns the current state
 */
static unsigned int hda_sync_power_state_8409(struct hda_codec *codec,
                                         hda_nid_t fg,
                                         unsigned int power_state)
{
        unsigned long end_time = jiffies + msecs_to_jiffies(500);
        unsigned int state, actual_state;
	dev_info(hda_codec_dev(codec), "hda_sync_power_state_8409 to 0x%04x\n",power_state);

        for (;;) {
                state = snd_hda_codec_read(codec, fg, 0,
                                           AC_VERB_GET_POWER_STATE, 0);
                if (state & AC_PWRST_ERROR)
                        break;
                actual_state = (state >> 4) & 0x0f;
                if (actual_state == power_state)
                        break;
                if (time_after_eq(jiffies, end_time))
                        break;
                /* wait until the codec reachs to the target state */
                msleep(1);
        }
	dev_info(hda_codec_dev(codec), "hda_sync_power_state_8409 power state 0x%04x\n",state);
        return state;
}

// pigs - need my own power state
// Apple seems to set node 0x01 - the AFG - primarily
// hda_set_power_state sets all nodes to the required power state
// so apparently node 0x01 does not have the power capability - but is powerable!!
// if we wish to use this for all nodes then need to check for this
static unsigned int hda_set_node_power_state(struct hda_codec *codec, hda_nid_t nid, unsigned int power_state)
{
        unsigned int wcaps = get_wcaps(codec, nid);
        unsigned int state = power_state;
	unsigned int current_state;
	dev_info(hda_codec_dev(codec), "hda_set_node_power_state     power %d\n",power_state);
        state = snd_hda_codec_read(codec, nid, 0, AC_VERB_GET_POWER_STATE, 0);
        if (!(state & AC_PWRST_ERROR)) {
	        if (state != power_state) {
        	        if (nid == 0x01 || (wcaps & AC_WCAP_POWER)) {
                	        if (nid != 0x01 && codec->power_filter) {
                        	        state = codec->power_filter(codec, nid, power_state);
                        	        // ah - this is for preventing a node from being turned off
                        	        // we are not in AC_PWRST_D3 but we are requesting AC_PWRST_D3
                        	        // (Im assuming we assume if not in AC_PWRST_D3 we are in AC_PWRST_D0
                        	        if (state != power_state && power_state == AC_PWRST_D3)
						{}
                        	        else
                                	        snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_POWER_STATE, power_state);
                	        }
                	        else
                        	        snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_POWER_STATE, power_state);

	        	        state = hda_sync_power_state_8409(codec, nid, power_state);
		        }
			else
				dev_info(hda_codec_dev(codec), "hda_set_node_power_state no power cap!!\n");
		}
	}
	else {
		dev_info(hda_codec_dev(codec), "hda_set_node_power_state ERROR!! 0x%04x\n",state);
	}
	dev_info(hda_codec_dev(codec), "hda_set_node_power_state end power %d\n",state);

        return state;
}

static unsigned int hda_set_node_power_state_simple(struct hda_codec *codec, hda_nid_t nid, unsigned int power_state)
{
        unsigned int state = power_state;
	unsigned int current_state;
	dev_info(hda_codec_dev(codec), "hda_set_node_power_state_simple     power %d\n",power_state);
        state = snd_hda_codec_read(codec, nid, 0, AC_VERB_GET_POWER_STATE, 0);
        if (!(state & AC_PWRST_ERROR)) {
	        if (state != power_state) {
                        snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_POWER_STATE, power_state);
	                state = hda_sync_power_state_8409(codec, nid, power_state);
	        }
	}
	dev_info(hda_codec_dev(codec), "hda_set_node_power_state_simple end power %d\n",state);

        return state;
}


// go with Apple way??
// this always does a get with index 0 initially and terminates with a set to 0 finally

static inline unsigned int cs_8409_vendor_coef_get(struct hda_codec *codec, unsigned int idx)
{
        struct cs_spec *spec = codec->spec;
        unsigned int retval;
        snd_hda_codec_read(codec, spec->vendor_nid, 0,
                            AC_VERB_GET_COEF_INDEX, 0);
        snd_hda_codec_write(codec, spec->vendor_nid, 0,
                            AC_VERB_SET_COEF_INDEX, idx);
        retval = snd_hda_codec_read(codec, spec->vendor_nid, 0,
                                  AC_VERB_GET_PROC_COEF, 0);
        snd_hda_codec_write(codec, spec->vendor_nid, 0,
                            AC_VERB_SET_COEF_INDEX, 0);
        return retval;
}

static inline void cs_8409_vendor_coef_set(struct hda_codec *codec, unsigned int idx,
                                      unsigned int coef)
{
        struct cs_spec *spec = codec->spec;
        snd_hda_codec_read(codec, spec->vendor_nid, 0,
                            AC_VERB_GET_COEF_INDEX, 0);
        snd_hda_codec_write(codec, spec->vendor_nid, 0,
                            AC_VERB_SET_COEF_INDEX, idx);
        snd_hda_codec_write(codec, spec->vendor_nid, 0,
                            AC_VERB_SET_PROC_COEF, coef);
        snd_hda_codec_write(codec, spec->vendor_nid, 0,
                            AC_VERB_SET_COEF_INDEX, 0);
        // appears to return 0
}

static inline unsigned int cs_8409_vendor_coef_set_mask(struct hda_codec *codec, unsigned int idx,
                                      unsigned int coef, unsigned int mask)
{
        struct cs_spec *spec = codec->spec;
        unsigned int retval;
        unsigned int mask_coef;
        snd_hda_codec_read(codec, spec->vendor_nid, 0,
                            AC_VERB_GET_COEF_INDEX, 0);
        snd_hda_codec_write(codec, spec->vendor_nid, 0,
                            AC_VERB_SET_COEF_INDEX, idx);
        retval = snd_hda_codec_read(codec, spec->vendor_nid, 0,
                                  AC_VERB_GET_PROC_COEF, 0);
        snd_hda_codec_write(codec, spec->vendor_nid, 0,
                            AC_VERB_SET_COEF_INDEX, idx);
	//mask_coef = (retval & ~mask) | coef;
        snd_hda_codec_write(codec, spec->vendor_nid, 0,
                            AC_VERB_SET_PROC_COEF, coef);
        snd_hda_codec_write(codec, spec->vendor_nid, 0,
                            AC_VERB_SET_COEF_INDEX, 0);
        // appears to return 0
        // lets return the read value for checking
        return retval;
}

static inline void cs_8409_vendor_enableI2Cclock(struct hda_codec *codec, unsigned int flag)
{

	unsigned int retval = 0;
	unsigned int newval = 0;

	// note that apple returns the status value with data value in returned parameter 
	// snd_hda_codec_read just returns value - not sure what happens about errors
	// looks as tho its assumed -1 is not a valid return value
	// ah yes - because max val is 16 bit quantity

	retval = cs_8409_vendor_coef_get(codec, 0x0);
	//if (retval == -1)

	if (retval == -1)
		return;

	newval = retval;
	if (flag)
		newval |= 0x8;
	else
		newval = (retval & 0xfffffff7);

	cs_8409_vendor_coef_set(codec, 0x0, newval);

}


// define i2cRead and i2cWrite functions
// following Apple
static inline unsigned int cs_8409_vendor_i2cRead(struct hda_codec *codec, unsigned int i2c_address,
                                            unsigned int i2c_reg, unsigned int paged)
{
	// AppleHDAFunctionGroupCS8409::_i2cRead(bool, unsigned short, unsigned short, unsigned int*)
	// note that last argument is return data
	unsigned int i2c_reg_data;
	unsigned int retval;
	int rdcnt;

	hda_set_node_power_state(codec, CS8409_VENDOR_NID, AC_PWRST_D0);
	// exit on error

	snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
	// exit on error

	cs_8409_vendor_enableI2Cclock(codec, 0x1);


	cs_8409_vendor_coef_set(codec, 0x59, i2c_address);

	if (paged)
	{
		unsigned int retval1;

		cs_8409_vendor_coef_set(codec, 0x5d, i2c_reg >> 8);
sleep1:
		rdcnt = -8;

		retval1 = cs_8409_vendor_coef_get(codec, 0x5c);

		if (retval1 != -1)
		{
			retval1 &= 0x18;
			if (retval1 != 0x18)
			{
				if (rdcnt < 0)
				{
					rdcnt++;
					//sleep(0x2);
					goto sleep1;
				}
			}
		}
	}


	// so the i2c register is stored in the low byte of i2c_reg
	// shift it 8 bits to left for sending as coefficient data (16 bits)
	// hmm - why do I need a mask??
	// think either we mask here or in cs_8409_vendor_coef_set
	// Apple is using short ints so likely automasked
	i2c_reg_data = (i2c_reg << 8) & 0x0ffff;

	cs_8409_vendor_coef_set(codec, 0x5e, i2c_reg_data);
	//if (retval == -1)

	retval = cs_8409_vendor_coef_get(codec, 0x5c);
	//if (retval == -1)

sleep2:
	rdcnt = -8;

	retval = cs_8409_vendor_coef_get(codec, 0x5c);
	//if (retval == -1)

	if (retval != -1)
	{
		retval &= 0x18;
		if (retval != 0x18)
		{
			if (rdcnt < 0)
			{
				rdcnt++;
				// need 0x2 according to Apple
				usleep_range(2000,4000);
				goto sleep2;
			}
		}
	}

	// well thats interesting - looks as though the 16 bit return
	// has the register in bits 15-8 and the data in 7-0
	// probably should mask the data out
	retval = cs_8409_vendor_coef_get(codec, 0x5e);
	//if (retval == -1)

	cs_8409_vendor_enableI2Cclock(codec, 0x0);
	// exit on error

	hda_set_node_power_state(codec, CS8409_VENDOR_NID, AC_PWRST_D3);
	// exit on error

	return retval;

}

static inline void cs_8409_vendor_i2cWrite(struct hda_codec *codec, unsigned int i2c_address,
                                      unsigned int i2c_reg, unsigned int i2c_data, unsigned int paged)
{
	// AppleHDAFunctionGroupCS8409::_i2cWrite(bool, unsigned short, unsigned short, unsigned short)
	unsigned int retval;
	unsigned int i2c_reg_data;
	int rdcnt;

	hda_set_node_power_state(codec, CS8409_VENDOR_NID, AC_PWRST_D0);
	// exit on error

	snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
	// exit on error

	cs_8409_vendor_enableI2Cclock(codec, 0x1);


	cs_8409_vendor_coef_set(codec, 0x59, i2c_address);

	if (paged)
	{
		unsigned int retval1;

		cs_8409_vendor_coef_set(codec, 0x5d, i2c_reg >> 8);

		retval1 = cs_8409_vendor_coef_get(codec, 0x5c);

sleep1:
		rdcnt = -8;

		retval1 = cs_8409_vendor_coef_get(codec, 0x5c);

		if (retval1 != -1)
		{
			retval1 &= 0x18;
			if (retval1 != 0x18)
			{
				if (rdcnt < 0)
				{
					rdcnt++;
					//sleep(0x2);
					goto sleep1;
				}
			}
		}
	}


	// so the i2c register is stored in the low byte of i2c_reg
	// shift it 8 bits to left for sending as coefficient data (16 bits)
	// then or in the 8 byte data
	// mask here or in cs_8409_vendor_coef_set?
	i2c_reg_data = ((i2c_reg << 8) & 0x0ff00) | ( i2c_data & 0x0ff);

	cs_8409_vendor_coef_set(codec, 0x5d, i2c_reg_data);
	//if (retval == -1)


	retval = cs_8409_vendor_coef_get(codec, 0x5c);
	//if (retval == -1)

sleep2:
	rdcnt = -8;

	retval = cs_8409_vendor_coef_get(codec, 0x5c);
	//if (retval == -1)

	if (retval != -1)
	{
		retval &= 0x18;
		if (retval != 0x18)
		{
			if (rdcnt < 0)
			{
				rdcnt++;
				//sleep(0x2);
				goto sleep2;
			}
		}
	}

	cs_8409_vendor_enableI2Cclock(codec, 0x0);
	// exit on error

	hda_set_node_power_state(codec, CS8409_VENDOR_NID, AC_PWRST_D3);
	// exit on error

}


// this seems to be how to do a list of verbs
// there is command to do a sequence of these
// snd_hda_sequence_write
static const struct hda_verb cs8409_init_verbs[] = {
        //{0x01, AC_VERB_SET_POWER_STATE, 0x00}, /* AFG: D0 */
        //{0x24, AC_VERB_SET_PROC_STATE, 0x01},  /* VPW: processing on */
        {} /* terminator */
};

struct hda_coef {
        u16 write;
        hda_nid_t nid;
        u32 idx;
        u32 param;
        u32 retdata;
        int srcidx;
};

// new feature to do a sequence of coef read/writes
// (seems to be used a lot for cs8409)
// note that we ignore the return for gets for the moment!!
// ooh - new idea - save the logged return and check
static const struct hda_coef cs8409_init_coef[] = {
        //{0, 0x01, idx, 0x00, retdata, 0}, read
        //{1, 0x01, idx, param, dmydata, 0}, write
        //{2, 0x01, idx, param, retdata, 0}, write mask
};

void snd_hda_coef_item(struct hda_codec *codec, u16 write_flag, hda_nid_t nid, u32 idx, u32 param, u32 retdata, int srcidx)
{
        if (write_flag == 2)
	{
                unsigned int retval = cs_8409_vendor_coef_set_mask(codec, idx, param, 0);
                if (retval != retdata)
		{
                        if (srcidx > 0)
                                codec_dbg(codec, "command nid BAD mask return value at %d: 0x%08x 0x%08x\n",srcidx,retval,retdata);
                        else
                                codec_dbg(codec, "command nid BAD mask return value: 0x%08x 0x%08x\n",retval,retdata);
		}
	}
        else if (write_flag == 1)
                cs_8409_vendor_coef_set(codec, idx, param);
        else
	{
                unsigned int retval = cs_8409_vendor_coef_get(codec, idx);
                if (retval != retdata)
		{
                        if (srcidx > 0)
                                codec_dbg(codec, "command nid BAD      return value at %d: 0x%08x 0x%08x\n",srcidx,retval,retdata);
                        else
                                codec_dbg(codec, "command nid BAD      return value: 0x%08x 0x%08x\n",retval,retdata);
		}
	}
}

void snd_hda_coef_sequence(struct hda_codec *codec, const struct hda_coef *seq, char *prtstr)
{
	dev_info(hda_codec_dev(codec), "start snd_hda_coef_sequence %s\n",prtstr);
        for (; seq->nid; seq++)
        {
		snd_hda_coef_item(codec, seq->write, seq->nid, seq->idx, seq->param, seq->retdata, seq->srcidx);
        }
	dev_info(hda_codec_dev(codec), "end   snd_hda_coef_sequence %s\n",prtstr);
}

static inline unsigned int snd_hda_codec_read_check(struct hda_codec *codec, hda_nid_t nid, int flags, unsigned int verb, unsigned int parm, unsigned int check_val, int srcidx)
{
	unsigned int retval;
	retval = snd_hda_codec_read(codec, nid, flags, verb, parm);

	if (retval == -1)
		return retval;

	if (retval != check_val)
        	codec_dbg(codec, "command nid BAD read check return value at %d: 0x%08x 0x%08x\n",srcidx,retval,check_val);

	return retval;
}

void snd_hda_double_reset(struct hda_codec *codec)
{
	dev_info(hda_codec_dev(codec), "snd_hda_double_reset\n");
	// still not clear if this does anything
	snd_hda_codec_write(codec, codec->core.afg, 0, 0xfff, 0);
	// so far the double reset seems to give bad results - lots of registers dont compare
	//snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_CODEC_RESET, 0);
	msleep(1);
	// apparently should use usleep_range for a few ms
	//usleep_range(1000,2000);
	//snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_CODEC_RESET, 0);
}


static void clear_pins(struct hda_codec *codec)
{
	//struct cs_spec *spec = codec->spec;
        hda_nid_t nid;

	dev_info(hda_codec_dev(codec), "start clear_pins\n");

        for_each_hda_codec_node(nid, codec)
                if (get_wcaps_type(get_wcaps(codec, nid)) == AC_WID_PIN) {
                	/* use read here for syncing after issuing each verb */
                	snd_hda_codec_read(codec, nid, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0);
                }
	dev_info(hda_codec_dev(codec), "end   clear_pins\n");
}


static void read_coefs_all_loop(struct hda_codec *codec)
{
	//struct cs_spec *spec = codec->spec;
	int idx;
	dev_info(hda_codec_dev(codec), "start read_coefs_all\n");
	for (idx = 0; idx < 130; idx++)
		{
		int retval = cs_8409_vendor_coef_get(codec, idx);
		dev_info(hda_codec_dev(codec),"snd_hda_intel: read_coefs_all 0x%02x:  0x%08x\n",idx,retval);
		}
	dev_info(hda_codec_dev(codec), "end   read_coefs_all\n");
}


#include "patch_cirrus_data84.h"


void cs_8409_playback_pcm_hook(struct hda_pcm_stream *hinfo, struct hda_codec *codec, struct snd_pcm_substream *substream, int action)
{

	struct cs_spec *spec = codec->spec;


	if (action == HDA_GEN_PCM_ACT_OPEN) {
		printk("snd_hda_intel: command nid cs_8409_playback_pcm_hook open");
		printk("snd_hda_intel: command nid end cs_8409_playback_pcm_hook");
	} else if (action == HDA_GEN_PCM_ACT_PREPARE) {
		struct timespec curtim;
		getnstimeofday(&curtim);
		printk("snd_hda_intel: command nid cs_8409_playback_pcm_hook prepare init %d last %ld cur %ld",spec->play_init,spec->last_play_time.tv_sec,curtim.tv_sec);
		// not clear if need to redo the setup eg if amps power themselves down or something - so far maybe not
		// and if do redo setup the sound transforms to noise in a few seconds for 2nd play
		// OSX does do this setup just before play when do first play - have not logged multiple plays
		// could be the unmute section causing the problem - not tested
		//if (!spec->play_init || curtim.tv_sec > (spec->last_play_time.tv_sec + 3600))
		if (!spec->play_init)
		{
			cs_8409_unmute(codec);
			//cs_8409_volup(codec);
			cs_8409_play(codec);
			spec->last_play_time.tv_sec = curtim.tv_sec;
			spec->play_init = 1;
		}

		// this is only input defined - see if turning off removes feedback
		printk("snd_hda_intel: command nid cs_8409_playback_pcm_hook clear nid 0x44");
		snd_hda_codec_write(codec, 0x44, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);

		printk("snd_hda_intel: command nid end cs_8409_playback_pcm_hook");
	}

}


static int cs_8409_explicit_config_nouse(struct hda_codec *codec)
{
	struct cs_spec *spec = codec->spec;
	hda_nid_t beep_nid = spec->beep_nid;

	unsigned int tmpstate1 = -1;
	unsigned int tmpstate2 = -1;
	unsigned int tmpstate3 = -1;
	unsigned int tmpstate4 = -1;

	printk("snd_hda_intel: cs8409_explicit_config");

	hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

	snd_hda_double_reset(codec);

	hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

	// so apple reads parameters from all nodes
	// but setting pin nodes SET_PIN_WIDGET_CONTROL to 0

	clear_pins(codec);

	dev_info(hda_codec_dev(codec),"snd_hda_intel: beep nid 0x%02x",beep_nid);

	//if (beep_nid == 0x46)
	//	snd_hda_codec_write(codec, beep_nid, 0, AC_VERB_SET_BEEP_CONTROL, 0);

	hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);

	snd_hda_codec_write(codec, 0x46, 0, AC_VERB_SET_BEEP_CONTROL, 0);

	// this sequentially reads a load of coeficients from the vendor node
        // note that all these reads are done without a AC_VERB_SET_PROC_STATE to 1
	read_coefs_all(codec);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);

	// Apple now reads from nodes outside the number of nodes defined!!
	// 0x48, 0x49, 0x4a, 0x4b
        read_hidden_feature_widgets(codec);

	// check what power state of these nodes is - Apple does not do this
	tmpstate1 = hda_sync_power_state_8409(codec, 0x48, AC_PWRST_D0);
	tmpstate2 = hda_sync_power_state_8409(codec, 0x49, AC_PWRST_D0);
	tmpstate3 = hda_sync_power_state_8409(codec, 0x4a, AC_PWRST_D0);
	tmpstate4 = hda_sync_power_state_8409(codec, 0x4b, AC_PWRST_D0);

	printk("snd_hda_intel: cs8409_explicit_config power 0x48 %d 0x49 %d 0x4a %d 0x4b %d\n",tmpstate1,tmpstate2,tmpstate3,tmpstate4);


	setup_node_alpha(codec);



	printk("snd_hda_intel: end cs8409_explicit_config");

	return 0;
}

// this version runs all explicit commands as logged on OSX
static int cs_8409_explicit_config(struct hda_codec *codec)
{
	struct cs_spec *spec = codec->spec;
	hda_nid_t beep_nid = spec->beep_nid;

	unsigned int tmpstate1 = -1;
	unsigned int tmpstate2 = -1;
	unsigned int tmpstate3 = -1;
	unsigned int tmpstate4 = -1;

	printk("snd_hda_intel: cs8409_explicit_config");

	setup_node_alpha_reset_and_clear(codec);

	// this sequentially reads a load of coeficients from the vendor node
        // note that all these reads are done without a AC_VERB_SET_PROC_STATE to 1
	read_coefs_all(codec);

        //snd_hda_codec_write(codec, codec->core.afg, 0, AC_VERB_SET_POWER_STATE, 0x00000000);

        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);

	// Apple now reads from nodes outside the number of nodes defined!!
	// 0x48, 0x49, 0x4a, 0x4b
        read_hidden_feature_widgets(codec);


	// check what power state of these nodes is - Apple does not do this
	tmpstate1 = hda_sync_power_state_8409(codec, 0x48, AC_PWRST_D0);
	tmpstate2 = hda_sync_power_state_8409(codec, 0x49, AC_PWRST_D0);
	tmpstate3 = hda_sync_power_state_8409(codec, 0x4a, AC_PWRST_D0);
	tmpstate4 = hda_sync_power_state_8409(codec, 0x4b, AC_PWRST_D0);

	printk("snd_hda_intel: cs8409_explicit_config power 0x48 %d 0x49 %d 0x4a %d 0x4b %d\n",tmpstate1,tmpstate2,tmpstate3,tmpstate4);

	setup_node_alpha(codec);

	// this is only input defined - see if turning off removes feedback
	snd_hda_codec_write(codec, 0x44, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0x00000000);


	printk("snd_hda_intel: end cs8409_explicit_config");

	return 0;
}
