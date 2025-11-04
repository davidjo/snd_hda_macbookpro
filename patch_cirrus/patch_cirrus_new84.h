

// as of kernel 6.8 we need prototype definitions for non-static functions
// (in addition to actual definitions)


// definitions for patch_cirrus_new84.h


void snd_hda_coef_item(struct hda_codec *codec, u16 write_flag, hda_nid_t nid, u32 idx, u32 param, u32 retdata, int srcidx);

int snd_hda_coef_item_check(struct hda_codec *codec, u16 write_flag, hda_nid_t nid, u32 idx, u32 param, u32 retdata, int srcidx);

void snd_hda_coef_item_masked(struct hda_codec *codec, u16 write_flag, hda_nid_t nid, u32 idx, u32 param, u32 mask, u32 retdata, u32 srcval, int srcidx);

void snd_hda_double_reset(struct hda_codec *codec);

void cs_8409_play_setup(struct hda_codec *codec);

void cs_8409_play_cleanup(struct hda_codec *codec);

void cs_8409_capture_setup(struct hda_codec *codec);

void cs_8409_capture_cleanup(struct hda_codec *codec);

void cs_8409_headplay_setup(struct hda_codec *codec);

void cs_8409_headplay_cleanup(struct hda_codec *codec);

void cs_8409_headcapture_setup(struct hda_codec *codec);

void cs_8409_headcapture_cleanup(struct hda_codec *codec);



// this sets the power state of the AFG node - ie node 0x1
// this calls hda_sync_power_state
//hda_set_power_state(codec, AC_PWRST_D0);

// this checks the node has reached the requested power state
//state = hda_sync_power_state(codec, nid, power_state);
//


// pigs need local definition as this is a static local function

/*
 * wait until the state is reached, returns the current state
 */
static unsigned int hda_sync_power_state_8409(struct hda_codec *codec,
                                         hda_nid_t nid,
                                         unsigned int power_state)
{
        unsigned long end_time = jiffies + msecs_to_jiffies(500);
        unsigned int state, actual_state;
	mycodec_info(codec, "hda_sync_power_state_8409 to 0x%04x\n",power_state);

        for (;;) {
                state = snd_hda_codec_read(codec, nid, 0,
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
	mycodec_info(codec, "hda_sync_power_state_8409 power state 0x%04x\n",state);
        return state;
}

// pigs - need my own power state
// Apple seems to set node 0x01 - the AFG - primarily
// hda_set_power_state sets all nodes to the required power state
// so apparently node 0x01 does not have the power capability - but is powerable!!
// if we wish to use this for all nodes then need to check for this

static unsigned int hda_set_node_power_state_dbg(struct hda_codec *codec, hda_nid_t nid, unsigned int power_state, bool dbgflg)
{
        unsigned int wcaps = get_wcaps(codec, nid);
        unsigned int state = power_state;
	//unsigned int current_state;
	if (dbgflg) { mycodec_info(codec, "hda_set_node_power_state  nid 0x%02x power %d\n",nid,power_state); }
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
		dev_info(hda_codec_dev(codec), "hda_set_node_power_state ERROR!! nid 0x%02x 0x%04x\n",nid, state);
	}
	if (dbgflg) { mycodec_info(codec, "hda_set_node_power_state end power %d\n",state); }

        return state;
}

static unsigned int hda_set_node_power_state(struct hda_codec *codec, hda_nid_t nid, unsigned int power_state)
{
        return hda_set_node_power_state_dbg(codec, nid, power_state, 0);
}

static unsigned int hda_set_node_power_state_simple(struct hda_codec *codec, hda_nid_t nid, unsigned int power_state)
{
        unsigned int state = power_state;
	//unsigned int current_state;
	mycodec_info(codec, "hda_set_node_power_state_simple     power %d\n",power_state);
        state = snd_hda_codec_read(codec, nid, 0, AC_VERB_GET_POWER_STATE, 0);
        if (!(state & AC_PWRST_ERROR)) {
	        if (state != power_state) {
                        snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_POWER_STATE, power_state);
	                state = hda_sync_power_state_8409(codec, nid, power_state);
	        }
	}
	mycodec_info(codec, "hda_set_node_power_state_simple end power %d\n",state);

        return state;
}


static void hda_check_power_state(struct hda_codec *codec, hda_nid_t nid, int flagint)
{
        unsigned int state;
        state = snd_hda_codec_read(codec, nid, 0, AC_VERB_GET_POWER_STATE, 0);
	mycodec_info(codec, "hda_check_power_state nid 0x%02x power 0x%04x %d\n", nid, state, flagint);
}


// go with Apple way??
// this always does a get with index 0 initially and terminates with a set to 0 finally

static inline unsigned int cs_8409_vendor_coef_get(struct hda_codec *codec, unsigned int idx)
{
        struct cs8409_apple_spec *spec = codec->spec;
        unsigned int retval;
        snd_hda_codec_read(codec, CS8409_VENDOR_NID, 0,
                            AC_VERB_GET_COEF_INDEX, 0);
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0,
                            AC_VERB_SET_COEF_INDEX, idx);
        retval = snd_hda_codec_read(codec, CS8409_VENDOR_NID, 0,
                                  AC_VERB_GET_PROC_COEF, 0);
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0,
                            AC_VERB_SET_COEF_INDEX, 0);
        return retval;
}

static inline void cs_8409_vendor_coef_set(struct hda_codec *codec, unsigned int idx,
                                      unsigned int coef)
{
        struct cs8409_apple_spec *spec = codec->spec;
        snd_hda_codec_read(codec, CS8409_VENDOR_NID, 0,
                            AC_VERB_GET_COEF_INDEX, 0);
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0,
                            AC_VERB_SET_COEF_INDEX, idx);
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0,
                            AC_VERB_SET_PROC_COEF, coef);
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0,
                            AC_VERB_SET_COEF_INDEX, 0);
        // appears to return 0
}

static inline unsigned int cs_8409_vendor_coef_set_mask(struct hda_codec *codec, unsigned int idx,
                                      unsigned int coef, unsigned int mask, unsigned int srcval, int srcidx)
{
        // for the moment hackily add srcidx argument while debugging
        struct cs8409_apple_spec *spec = codec->spec;
        unsigned int retval;
        unsigned int mask_coef;
        snd_hda_codec_read(codec, CS8409_VENDOR_NID, 0,
                            AC_VERB_GET_COEF_INDEX, 0);
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0,
                            AC_VERB_SET_COEF_INDEX, idx);
        retval = snd_hda_codec_read(codec, CS8409_VENDOR_NID, 0,
                                  AC_VERB_GET_PROC_COEF, 0);
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0,
                            AC_VERB_SET_COEF_INDEX, idx);
        mask_coef = (retval & ~mask) | coef;
        if (srcval != 0)
        {
		if (srcidx != 0 && mask_coef != srcval)
			{ myprintk_dbg("snd_hda_intel: cs_8409_vendor_coef_set_mask 0x%04x 0x%04x: 0x%04x (0x%04x 0x%04x 0x%04x) 0x%04x != 0x%04x %d BAD",idx,coef,mask_coef,retval,coef,mask, mask_coef, srcval, srcidx); }
	        else
                        { myprintk_dbg("snd_hda_intel: cs_8409_vendor_coef_set_mask 0x%04x 0x%04x: 0x%04x (0x%04x 0x%04x 0x%04x) %d",idx,coef,mask_coef,retval,coef,mask,srcidx); }
        }
	else
	{
                //if (mask != 0xffff)
                myprintk_dbg("snd_hda_intel: cs_8409_vendor_coef_set_mask 0x%04x 0x%04x: 0x%04x (0x%04x 0x%04x 0x%04x) %d",idx,coef,mask_coef,retval,coef,mask,srcidx);
	}
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0,
                            AC_VERB_SET_PROC_COEF, mask_coef);
        snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0,
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
static unsigned int cs_8409_vendor_i2cRead(struct hda_codec *codec, unsigned int i2c_address,
                                            unsigned int i2c_reg, unsigned int paged)
{
	// AppleHDAFunctionGroupCS8409::_i2cRead(bool, unsigned short, unsigned short, unsigned int*)
	// note that last argument is return data
	unsigned int i2c_reg_data;
	unsigned int retval;
	int rdcnt;

        myprintk_dbg("snd_hda_intel: i2cRead 0x%04x 0x%04x: %d",i2c_address,i2c_reg,paged);

	hda_set_node_power_state_dbg(codec, codec->core.afg, AC_PWRST_D0, 0);
	// exit on error

	snd_hda_codec_write(codec, CS8409_VENDOR_NID, 0, AC_VERB_SET_PROC_STATE, 0x00000001);
	// exit on error

	cs_8409_vendor_enableI2Cclock(codec, 0x1);


	cs_8409_vendor_coef_set(codec, 0x59, i2c_address);

	if (paged)
	{
		unsigned int retval1;

		cs_8409_vendor_coef_set(codec, 0x5d, i2c_reg >> 8);

		rdcnt = -8;
sleep1:
		retval1 = cs_8409_vendor_coef_get(codec, 0x5c);

		if (retval1 != -1)
		{
			retval1 &= 0x18;
			if (retval1 != 0x18)
			{
				if (rdcnt < 0)
				{
					rdcnt++;
					// need 0x2 according to Apple
					usleep_range(2000,4000);
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

	rdcnt = -8;
sleep2:
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

        myprintk_dbg("snd_hda_intel: i2cRead 0x%04x 0x%04x:  0x%04x end",i2c_address,i2c_reg,retval);

	//hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);
	// exit on error

	return retval;

}

static unsigned int cs_8409_vendor_i2cWrite(struct hda_codec *codec, unsigned int i2c_address,
                                      unsigned int i2c_reg, unsigned int i2c_data, unsigned int paged)
{
	// AppleHDAFunctionGroupCS8409::_i2cWrite(bool, unsigned short, unsigned short, unsigned short)
	unsigned int retval;
	unsigned int i2c_reg_data;
	int rdcnt;

        myprintk_dbg("snd_hda_intel: i2cWrite 0x%04x 0x%04x: 0x%04x %d",i2c_address,i2c_reg,i2c_data,paged);

	hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D0);
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

		rdcnt = -8;
sleep1:
		retval1 = cs_8409_vendor_coef_get(codec, 0x5c);

		if (retval1 != -1)
		{
			retval1 &= 0x18;
			if (retval1 != 0x18)
			{
				if (rdcnt < 0)
				{
					rdcnt++;
					// need 0x2 according to Apple
					usleep_range(2000,4000);
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

	rdcnt = -8;
sleep2:
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

	cs_8409_vendor_enableI2Cclock(codec, 0x0);
	// exit on error

        myprintk_dbg("snd_hda_intel: i2cWrite 0x%04x 0x%04x: 0x%04x %d end",i2c_address,i2c_reg,i2c_data,paged);

	//hda_set_node_power_state(codec, codec->core.afg, AC_PWRST_D3);
	// exit on error

	return retval;
}

static unsigned int cs_8409_vendor_i2cWriteMask(struct hda_codec *codec, unsigned int i2c_address,
                                      unsigned int i2c_reg, unsigned int i2c_mask, unsigned int i2c_data, unsigned int paged)
{
        // masked version to emulate AppleHDATDMDevice::maskWriteReg(unsigned short, unsigned char, unsigned char)

        unsigned int retval;
        unsigned int mask_val;

        retval = cs_8409_vendor_i2cRead(codec, i2c_address, i2c_reg, paged);

	mask_val = (retval & ~i2c_mask);
	mask_val |= (i2c_data & i2c_mask);

        myprintk_dbg("snd_hda_intel: i2cWriteMask 0x%04x 0x%04x: 0x%04x (0x%04x 0x%04x 0x%04x)  %d",i2c_address,i2c_reg,mask_val,retval,i2c_data,i2c_mask,paged);

        retval = cs_8409_vendor_i2cWrite(codec, i2c_address, i2c_reg, mask_val, paged);

        return retval;
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


void snd_hda_coef_sequence(struct hda_codec *codec, const struct hda_coef *seq, char *prtstr);


void snd_hda_coef_item(struct hda_codec *codec, u16 write_flag, hda_nid_t nid, u32 idx, u32 param, u32 retdata, int srcidx)
{
        if (write_flag == 2)
	{
		// NOTA BENE - just for initial debugging differentiation - pass a mask of 0xffff for total overwrite
		// use snd_hda_coef_item_masked for actual masked setup
                unsigned int retreadval = cs_8409_vendor_coef_set_mask(codec, idx, param, 0xffff, 0, srcidx);
                if (retreadval != retdata)
		{
                        if (srcidx > 0)
                                codec_dbg(codec, "command BAD mask return value at %d: 0x%08x 0x%08x (0x%02x, 0x%04x, 0x%04x)\n",srcidx,retreadval,retdata,nid,idx,param);
                        //else
                        //        codec_dbg(codec, "command BAD mask return value: 0x%08x 0x%08x (0x%02x, 0x%04x, 0x%04x)\n",retreadval,retdata,nid,idx,param);
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
                                codec_dbg(codec, "command BAD      return value at %d: 0x%08x 0x%08x (0x%02x, 0x%04x, 0x%04x)\n",srcidx,retval,retdata,nid,idx,param);
                        //else
                        //        codec_dbg(codec, "command BAD      return value: 0x%08x 0x%08x (0x%02x, 0x%04x, 0x%04x)\n",retval,retdata,nid,idx,param);
		}
	}
}

// just create a special routine if we wish to return the actual value for the moment
int snd_hda_coef_item_check(struct hda_codec *codec, u16 write_flag, hda_nid_t nid, u32 idx, u32 param, u32 retdata, int srcidx)
{
        int retval = 0;

        if (write_flag == 2)
                codec_dbg(codec, "command BAD usage of snd_hda_coef_item_check %d\n", write_flag);
        else if (write_flag == 1)
                codec_dbg(codec, "command BAD usage of snd_hda_coef_item_check %d\n", write_flag);
        else
        {
                unsigned int retval1 = cs_8409_vendor_coef_get(codec, idx);
                if (retval1 != retdata)
		{
                        if (srcidx > 0)
                                codec_dbg(codec, "command BAD      return value at %d: 0x%08x 0x%08x (0x%02x, 0x%04x, 0x%04x)\n",srcidx,retval1,retdata,nid,idx,param);
                        //else
                        //        codec_dbg(codec, "command BAD      return value: 0x%08x 0x%08x (0x%02x, 0x%04x, 0x%04x)\n",retval1,retdata,nid,idx,param);
		}
                retval = retval1;
        }

        return retval;
}

void snd_hda_coef_item_masked(struct hda_codec *codec, u16 write_flag, hda_nid_t nid, u32 idx, u32 param, u32 mask, u32 retdata, u32 srcval, int srcidx)
{
        //int retval = 0;
        if (write_flag != 2)
                codec_dbg(codec, "command BAD usage of snd_hda_coef_item_masked %d\n", write_flag);
	else
	{
		unsigned int retreadval = cs_8409_vendor_coef_set_mask(codec, idx, param, mask, srcval, srcidx);
                if (retreadval != retdata)
		{
                        if (srcidx > 0)
                                codec_dbg(codec, "command BAD mask return value at %d: 0x%08x 0x%08x (0x%02x, 0x%04x, 0x%04x)\n",srcidx,retreadval,retdata,nid,idx,param);
                        //else
                        //        codec_dbg(codec, "command BAD mask return value: 0x%08x 0x%08x (0x%02x, 0x%04x, 0x%04x)\n",retreadval,retdata,nid,idx,param);
		}
	}
        //return retval;
}

void snd_hda_coef_sequence(struct hda_codec *codec, const struct hda_coef *seq, char *prtstr)
{
	mycodec_info(codec, "start snd_hda_coef_sequence %s\n",prtstr);
        for (; seq->nid; seq++)
        {
		snd_hda_coef_item(codec, seq->write, seq->nid, seq->idx, seq->param, seq->retdata, seq->srcidx);
        }
	mycodec_info(codec, "end   snd_hda_coef_sequence %s\n",prtstr);
}

static inline unsigned int snd_hda_codec_read_check(struct hda_codec *codec, hda_nid_t nid, int flags, unsigned int verb, unsigned int parm, unsigned int check_val, int srcidx)
{
	unsigned int retval;
	retval = snd_hda_codec_read(codec, nid, flags, verb, parm);

	if (retval == -1)
		return retval;

	if (srcidx > 0)
		if (retval != check_val)
			codec_dbg(codec, "command BAD read check return value at %d: 0x%08x 0x%08x (0x%02x, 0x%03x 0x%04x)\n",srcidx,retval,check_val,nid,verb,parm);

	return retval;
}

void snd_hda_double_reset(struct hda_codec *codec)
{
	mycodec_info(codec, "snd_hda_double_reset\n");
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
	//struct cs8409_apple_spec *spec = codec->spec;
        hda_nid_t nid;

	mycodec_info(codec, "start clear_pins\n");

        for_each_hda_codec_node(nid, codec)
                if (get_wcaps_type(get_wcaps(codec, nid)) == AC_WID_PIN) {
                	/* use read here for syncing after issuing each verb */
                	snd_hda_codec_read(codec, nid, 0, AC_VERB_SET_PIN_WIDGET_CONTROL, 0);
                }
	mycodec_info(codec, "end   clear_pins\n");
}


static void read_coefs_all_loop(struct hda_codec *codec)
{
	//struct cs8409_apple_spec *spec = codec->spec;
	int idx;
	mycodec_info(codec, "start read_coefs_all\n");
	for (idx = 0; idx < 130; idx++)
		{
		int retval = cs_8409_vendor_coef_get(codec, idx);
		mycodec_info(codec,"snd_hda_intel: read_coefs_all 0x%02x:  0x%08x\n",idx,retval);
		}
	mycodec_info(codec, "end   read_coefs_all\n");
}

// this is very hacky but until get more understanding of what we can do with the 8409 setup
// re-define these from hda_codec.c here
// NOTA BENE - need to check this is consistent with any hda_codec.c updates!!

/*
 * audio-converter setup caches
 */
struct hda_cvt_setup {
        hda_nid_t nid;
        u8 stream_tag;
        u8 channel_id;
        u16 format_id;
        unsigned char active;   /* cvt is currently used */
        unsigned char dirty;    /* setups should be cleared */
};

// we now setup our local cache data in the spec structure
// - cvt_setups is an opaque pointer type so we can see it here
// but we dont know how to access the data - except by re-defining hda_cvt_setup as above

/* get or create a cache entry for the given audio converter NID */
static struct hda_cvt_setup *
get_hda_cvt_setup_8409(struct hda_codec *codec, hda_nid_t nid)
{
        struct hda_cvt_setup *p;
        int i;

        snd_array_for_each(&codec->cvt_setups, i, p) {
                if (p->nid == nid)
                        return p;
        }
        p = snd_array_new(&codec->cvt_setups);
        if (p)
                p->nid = nid;
        return p;
}


// so we actually need both versions - one using the hda_cvt_setup struct
// and one using our local hda_cvt_setup_apple struct

static struct hda_cvt_setup_apple *
get_hda_cvt_setup_apple_8409(struct hda_codec *codec, hda_nid_t nid)
{
        struct cs8409_apple_spec *spec = codec->spec;

	switch (nid)
	{
		case 0x02:
			return &spec->nid_0x02;
		case 0x03:
			return &spec->nid_0x03;
		case 0x0a:
			return &spec->nid_0x0a;
		case 0x22:
			return &spec->nid_0x22;
		case 0x23:
			return &spec->nid_0x23;
		case 0x1a:
			return &spec->nid_0x1a;
		default:
	}

	codec_err(codec, "get_hda_cvt_setup_apple_8409: UNKNOWN NID!! 0x%02x\n", nid);

	return NULL;
}

static void cs_8409_dump_stream_format(struct hda_codec *codec, hda_nid_t nid)
{
        struct hda_cvt_setup_apple *p = NULL;
        int i;

	// use explicit search so we dont create one if doesnt exist

        for (i = 0; i < codec->cvt_setups.used; i++) {
                p = snd_array_elem(&codec->cvt_setups, i);
                if (p->nid == nid)
                        break;
        }

        if (p != NULL)
                { mycodec_dbg(codec, "cs_8409_dump_stream_format: NID=0x%x, codec cached values: stream=0x%x, channel=%d, format=0x%x\n", nid, p->stream_tag, p->channel_id, p->format_id); }
        else
                { mycodec_dbg(codec, "cs_8409_dump_stream_format: NID=0x%x, codec cached values: NULL\n", nid); }
}

static void cs_8409_reset_stream_format(struct hda_codec *codec, hda_nid_t nid, int format, int doreset)
{
        // note that this routine is currently not used

        // this resets the cached stream format so that next
        // stream setup will actually rewrite the stream format and stream id
        // or if doreset set it will perform the stream update now
        // also allow for only updating the stream format and not stream id

        // NOTE we now save the stream format in our local cache as the hda_codec cache
        //      is cleared at end of the prepare stage and we want to store it more permanently
        //      really only the stream id is variable

        struct hda_cvt_setup *p = NULL;
        struct hda_cvt_setup_apple *papl = NULL;
        u32 stream_tag_sv;
        int channel_id_sv;
        int format_id_sv;

        // problem - the get_hda_cvt_setup function is local to hda_codec - so need our own copy above

        papl = get_hda_cvt_setup_apple_8409(codec, nid);

        stream_tag_sv = papl->stream_tag;
        channel_id_sv = papl->channel_id;
        format_id_sv = papl->format_id;

	mycodec_info(codec, "cs_8409_reset_stream_format RESET for nid 0x%02x: 0x%08x id 0x%08x chan 0x%08x\n", nid, format_id_sv, stream_tag_sv, channel_id_sv);

        // snd_hda_codec_setup_stream uses a caching system so only sends verbs when a change occurs
        // we want to force a send here so need to clear the cached data

        p = get_hda_cvt_setup_8409(codec, nid);

        p->stream_tag = 0;
        p->channel_id = 0;
	if (format)
                p->format_id = 0;

        if (doreset)
                snd_hda_codec_setup_stream(codec, nid, stream_tag_sv, channel_id_sv, format_id_sv);

}

// so what do I want this to do
// the stream format will be stored in the hda_cvt_setup (at what stage is this valid??)
// - we want to remove the Apple specific stream format/channel setup
// and just call snd_hda_setup_stream - but we need the actual stream format for this
// - hopefully getting from the hda_cvt_setup struct
// unfortunately this idea of storing in the hda_cvt_setup table turns out to be not useful
// as at end of snd_hda_codec_prepare it clears out (ie zeros) all unused/inactive cache entries
// so we have to store in a separate cache using our own copied definition for hda_cvt_setup
// hda_cvt_setup_apple


// the following 2 functions are used in the sync converter functions
// where apple essentially disables streaming (set stream id to 0) updates some vendor nid parameters
// then restores streaming
// so we store the stream info in a local variable copy and set it to the unused stream id ie stream id of 0
// then cs_8409_update_from_save_stream_format sets it back to what it was
// note that the format is unchanged for these operations
// the main reason for doing it this way is because of the caching used in snd_hda_codec_setup_stream
// - if we just sent the hda verbs then the cached data in snd_hda_codec_setup_stream
// would be inconsistent with the actual state of streaming on the nid

static void cs_8409_save_and_clear_stream_format(struct hda_codec *codec, hda_nid_t nid, struct hda_cvt_setup *savep)
{
        struct hda_cvt_setup *p = NULL;
        u32 stream_tag_sv;
        int channel_id_sv;
        int format_id_sv;

        mycodec_dbg(codec, "cs_8409_save_and_clear_stream_format nid 0x%02x\n", nid);

        // use this to save the stream format and clear the stream id and channel

        p = get_hda_cvt_setup_8409(codec, nid);

        savep->stream_tag = p->stream_tag;
        savep->channel_id = p->channel_id;
        savep->format_id = p->format_id;

        snd_hda_codec_write(codec, nid, 0, AC_VERB_SET_CHANNEL_STREAMID, 0x00000000);
}

static void cs_8409_update_from_save_stream_format(struct hda_codec *codec, hda_nid_t nid, struct hda_cvt_setup *savep, int update_stream_id, int update_format_id)
{
        struct hda_cvt_setup *p = NULL;

        mycodec_dbg(codec, "cs_8409_update_from_save_stream_format nid 0x%02x\n", nid);

        // so this will ensure the format is re-updated

        p = get_hda_cvt_setup_8409(codec, nid);

        if (update_stream_id)
        {
                p->stream_tag = 0;
                p->channel_id = 0;
        }
        if (update_format_id)
                p->format_id = 0;

        mycodec_info(codec, "cs_8409_update_from_save_stream_format tag 0x%08x chnl 0x%08x fmt 0x%08x\n", savep->stream_tag, savep->channel_id, savep->format_id);

        snd_hda_codec_setup_stream(codec, nid, savep->stream_tag, savep->channel_id, savep->format_id);
}


// so these are the crucial routines for setting our local cached copy of the stream info (in the spec structure)
// we use a different struct definition (hda_cvt_setup_apple) to keep the re-definition of hda_cvt_setup more local
// note that this stream info is only stored once per stream prepare function call
//      and this routine always updates from that initial data

static void cs_8409_really_update_stream_format(struct hda_codec *codec, hda_nid_t nid, int update_format_id, int update_stream_id, unsigned int new_channel_id)
{
        struct hda_cvt_setup *p = NULL;
        struct hda_cvt_setup_apple *papl = NULL;
        u32 stream_tag_sv = 0;
        int channel_id_sv = 0;
        int format_id_sv = 0;

        mycodec_dbg(codec, "cs_8409_really_update_stream_format nid 0x%02x updfmt %d updstrmid %d nchnlid %d\n", nid, update_format_id, update_stream_id, new_channel_id);
        //dump_stack();

        // so here we take our local cached format and save locally, clear out the cached values
        // then call snd_hda_codec_setup_stream with the cached values
        // this will ensure we update the HDA with the stream format

        // maybe now we should just update from our local stored version??

        papl = get_hda_cvt_setup_apple_8409(codec, nid);

        if (papl != NULL)
        {
                stream_tag_sv = papl->stream_tag;
                channel_id_sv = papl->channel_id;
                format_id_sv = papl->format_id;
        }
        else
        {
                codec_err(codec, "cs_8409_really_update_stream_format bad nid 0x%02x FAIL!!\n", nid);
                return;
        }


        p = get_hda_cvt_setup_8409(codec, nid);

        mycodec_info(codec, "cs_8409_really_update_stream_format cached    tag 0x%08x chnl 0x%08x fmt 0x%08x\n", papl->stream_tag, papl->channel_id, papl->format_id);

        if (update_stream_id)
        {
                p->stream_tag = 0;
                p->channel_id = 0;
        }
        if (update_format_id)
                p->format_id = 0;

        mycodec_info(codec, "cs_8409_really_update_stream_format to update tag 0x%08x chnl 0x%08x fmt 0x%08x\n", p->stream_tag, p->channel_id, p->format_id);

        if (update_stream_id == 2)
                { mycodec_info(codec, "cs_8409_really_update_stream_format new       tag 0x%08x chnl 0x%08x fmt 0x%08x\n", stream_tag_sv, new_channel_id, format_id_sv); }
        else
                { mycodec_info(codec, "cs_8409_really_update_stream_format new       tag 0x%08x chnl 0x%08x fmt 0x%08x\n", stream_tag_sv, channel_id_sv, format_id_sv); }

        cs_8409_dump_stream_format(codec, nid);

        if (update_stream_id == 2)
            snd_hda_codec_setup_stream(codec, nid, stream_tag_sv, new_channel_id, format_id_sv);
        else
            snd_hda_codec_setup_stream(codec, nid, stream_tag_sv, channel_id_sv, format_id_sv);
}

// remove function from compile so get error when building if use it
#if 0
static void cs_8409_setup_stream_format(struct hda_codec *codec, hda_nid_t nid, unsigned int stream_tag, unsigned int format)
{
        struct hda_cvt_setup *p = NULL;

        // NOTE - this function should no longer be used

        mycodec_dbg(codec, "cs_8409_setup_stream_format nid 0x%02x\n",nid);

        cs_8409_dump_stream_format(codec, nid);

        // this functions sets up the cached stream - get_hda_cvt_setup_8409 creates a struct if not yet defined
        // NOTA BENE we do not do the update here - we are relying that this will be done by a call to
        // cs_8409_really_update_stream_format now we have set the format correctly

        p = get_hda_cvt_setup_8409(codec, nid);

        // NOTA BENE - we do not set the channel id here - this will be done by cs_8409_really_update_stream_format

        p->stream_tag = stream_tag;
        p->channel_id = 0;
        p->format_id = format;

        cs_8409_dump_stream_format(codec, nid);

        mycodec_dbg(codec, "end cs_8409_setup_stream_format\n");
}
#endif

static void cs_8409_store_stream_format(struct hda_codec *codec, hda_nid_t nid, unsigned int stream_tag, unsigned int format)
{
        struct hda_cvt_setup_apple *papl = NULL;

        mycodec_dbg(codec, "cs_8409_store_stream_format nid 0x%02x\n",nid);

        cs_8409_dump_stream_format(codec, nid);

        // this functions sets up our local cached stream save store
        // NOTA BENE we do not do the update here - we are relying that this will be done by a call to
        // cs_8409_really_update_stream_format now we have set the format correctly

        papl = get_hda_cvt_setup_apple_8409(codec, nid);

        if (papl != NULL)
        {
                // NOTA BENE - we do not set the channel id here - this will be done by cs_8409_really_update_stream_format

                papl->stream_tag = stream_tag;
                papl->channel_id = 0;
                papl->format_id = format;

                mycodec_info(codec, "cs_8409_store_stream_format cached    tag 0x%08x chnl 0x%08x fmt 0x%08x\n", papl->stream_tag, papl->channel_id, papl->format_id);
	}
	else
                codec_err(codec, "cs_8409_store_stream_format bad nid 0x%02x FAIL!!\n", nid);

        mycodec_dbg(codec, "end cs_8409_store_stream_format\n");
}


//int snd_hda_get_path_idx(struct hda_codec *codec, struct nid_path *path);

//static struct nid_path *get_input_path(struct hda_codec *codec, int adc_idx, int imux_idx)
//	return snd_hda_get_path_from_idx(codec, spec->input_paths[imux_idx][adc_idx]);

// modified from init_input_src to switch the inputs on headset plugin/unplug events
static void switch_input_src(struct hda_codec *codec)
{
	struct hda_gen_spec *spec = codec->spec;
	struct hda_input_mux *imux = &spec->input_mux;
	struct nid_path *path;
	int i, c, nums;
	mycodec_dbg(codec, "switch_input_src enter\n");

	nums = spec->num_adc_nids;

	mycodec_dbg(codec, "switch_input_src num adc nids %d %d\n",nums,spec->dyn_adc_switch);

	for (c = 0; c < nums; c++) {
		mycodec_dbg(codec, "switch_input_src num_items %d\n",imux->num_items);
		for (i = 0; i < imux->num_items; i++) {
			//path = get_input_path(codec, c, i);
	                path = snd_hda_get_path_from_idx(codec, spec->input_paths[i][c]);
			if (path) {
				int in;
				bool active = path->active;
				mycodec_dbg(codec, "switch_input_src path active %d\n",active);
				for (in = path->depth - 1; in >= 0; in--) {
					hda_nid_t tnid = path->path[in];
					mycodec_dbg(codec, "switch_input_src path nid %d: 0x%02x\n",in,tnid);
				}
				if (path->active) {
					mycodec_dbg(codec, "switch_input_src path nid 0x%02x deactivate\n",path->path[1]);
					snd_hda_activate_path(codec, path, false, false);
				} else {
					mycodec_dbg(codec, "switch_input_src path nid 0x%02x   activate\n",path->path[1]);
					snd_hda_activate_path(codec, path, true, false);
				}
			}
			else {
				mycodec_dbg(codec, "switch_input_src path NULL\n");
			}
		}
	}

	mycodec_dbg(codec, "switch_input_src exit\n");
}




static int read_gpio_status_check(struct hda_codec *codec);

#ifdef USE_DATA

#include "patch_cirrus_data84.h"

#include "patch_cirrus_plugin.h"

#include "patch_cirrus_headplay.h"

#include "patch_cirrus_unplug.h"

#include "patch_cirrus_plugin3.h"

#include "patch_cirrus_plugin23.h"

#include "patch_cirrus_mb141_data84.h"

#else

// error definitions
static void cs_8409_external_device_unsolicited_response_data(struct hda_codec *codec, unsigned int res)
{
	dev_err(hda_codec_dev(codec), "ERROR - to use data functions need to define USE_DATA\n");
}

static void cs_8409_boot_setup_data(struct hda_codec *codec)
{
	dev_err(hda_codec_dev(codec), "ERROR - to use data functions need to define USE_DATA\n");
}

static void cs_8409_play_data(struct hda_codec *codec)
{
	dev_err(hda_codec_dev(codec), "ERROR - to use data functions need to define USE_DATA\n");
}

//static void cs_8409_play_real(struct hda_codec *codec);

static void cs_8409_playstop_data(struct hda_codec *codec)
{
	dev_err(hda_codec_dev(codec), "ERROR - to use data functions need to define USE_DATA\n");
}

//static void cs_8409_playstop_real(struct hda_codec *codec);

static void cs_8409_headplay_data(struct hda_codec *codec)
{
	dev_err(hda_codec_dev(codec), "ERROR - to use data functions need to define USE_DATA\n");
}

//static void cs_8409_headplay_real(struct hda_codec *codec);

static void cs_8409_headplaystop_data(struct hda_codec *codec)
{
	dev_err(hda_codec_dev(codec), "ERROR - to use data functions need to define USE_DATA\n");
}

//static void cs_8409_headplaystop_real(struct hda_codec *codec);


static void cs_8409_boot_setup_data_ssm3(struct hda_codec *codec)
{
	dev_err(hda_codec_dev(codec), "ERROR - to use data functions need to define USE_DATA\n");
}

static void cs_8409_play_data_ssm3(struct hda_codec *codec)
{
	dev_err(hda_codec_dev(codec), "ERROR - to use data functions need to define USE_DATA\n");
}


#endif

#include "patch_cirrus_boot84.h"

#include "patch_cirrus_real84_i2c.h"

#include "patch_cirrus_real84.h"

// only needed if wish to test the version using the mb141 logs
// cs_8409_boot_setup_real now supposed to do both machines
//#include "patch_cirrus_mb141_real84.h"


// macbook pro subsystem ids
// 14,1 0x106b3300
// 14,2 0x106b3600
// 14,3 0x106b3900

// imac subsystem ids
// 18,1 0x106b0e00
// 18,2 0x106b0f00
// 18,3 0x106b1000
// 19,1 0x106b1000


static int cs_8409_data_config(struct hda_codec *codec);
static int cs_8409_real_config(struct hda_codec *codec);


static int cs_8409_boot_setup(struct hda_codec *codec)
{
	int err = 0;
        struct cs8409_apple_spec *spec = codec->spec;

        // so it appears we break up the subsystem_id into 2 parts
        // a codec vendor id (16 bits) and a subvendor id (8 bits) plus an assembly id
        // so here the codec vendor is 0x106b, the subvendor id is 0x39 and the assembly id is 0x00
        if (codec->core.subsystem_id == 0x106b3900) {
                if (spec->use_data) {
                        myprintk("snd_hda_intel: cs_8409_boot_setup pre cs_8409_data_config\n");

                        err = cs_8409_data_config(codec);

                        myprintk("snd_hda_intel: cs_8409_boot_setup post cs_8409_data_config\n");
                } else {
                        myprintk("snd_hda_intel: cs_8409_boot_setup pre cs_8409_real_config\n");

                        err = cs_8409_real_config(codec);

                        myprintk("snd_hda_intel: cs_8409_boot_setup post cs_8409_real_config\n");
                }
	}
        else if (codec->core.subsystem_id == 0x106b3300 || codec->core.subsystem_id == 0x106b3600) {
                if (spec->use_data) {
                        cs_8409_boot_setup_data_ssm3(codec);
		} else {
                        myprintk("snd_hda_intel: cs_8409_boot_setup pre cs_8409_real_config\n");
                        //cs_8409_boot_setup_real_ssm3(codec);
                        err = cs_8409_real_config(codec);
                }
        }
        else if (codec->core.subsystem_id == 0x106b1000 || codec->core.subsystem_id == 0x106b0f00 || codec->core.subsystem_id == 0x106b0e00) {
		if (spec->use_data) {
                        printk("snd_hda_intel: cs_8409_boot_setup pre data not implemented for subsystem id 0x%08x",codec->core.subsystem_id);
		} else {
                        err = cs_8409_real_config(codec);
		}
        }
        else {
                printk("snd_hda_intel: UNKNOWN subsystem id 0x%08x",codec->core.subsystem_id);
                err = -1;
        }

	return err;
}

void cs_8409_play_setup(struct hda_codec *codec)
{
        struct cs8409_apple_spec *spec = codec->spec;
        myprintk_dbg("snd_hda_intel: cs_8409_play_setup\n");
        if (codec->core.subsystem_id == 0x106b3900) {
		if (spec->use_data) {
                        //cs_8409_unmute_data(codec);
                        //cs_8409_volup_data(codec);
                        cs_8409_play_data(codec);
		} else {
		        cs_8409_play_real(codec);
                }
	}
        else if (codec->core.subsystem_id == 0x106b3300 || codec->core.subsystem_id == 0x106b3600) {
		if (spec->use_data) {
                        cs_8409_play_data_ssm3(codec);
		} else {
                        //cs_8409_play_real_ssm3(codec);
		        cs_8409_play_real(codec);
		}
	}
        else if (codec->core.subsystem_id == 0x106b1000 || codec->core.subsystem_id == 0x106b0f00 || codec->core.subsystem_id == 0x106b0e00) {
		if (spec->use_data) {
                        printk("snd_hda_intel: cs_8409_play_setup data not implemented for subsystem id 0x%08x",codec->core.subsystem_id);
		} else {
		        cs_8409_play_real(codec);
		}
        }
	else {
                printk("snd_hda_intel: UNKNOWN subsystem id 0x%08x",codec->core.subsystem_id);
	}
}

//static void cs_8409_playstop_data_ssm3(struct hda_codec *codec);
//static void cs_8409_playstop_real_ssm3(struct hda_codec *codec);

void cs_8409_play_cleanup(struct hda_codec *codec)
{
        struct cs8409_apple_spec *spec = codec->spec;
        myprintk_dbg("snd_hda_intel: cs_8409_play_cleanup\n");
        if (codec->core.subsystem_id == 0x106b3900) {
		if (spec->use_data) {
			cs_8409_playstop_data(codec);
		} else {
			cs_8409_playstop_real(codec);
                }
	}
        else if (codec->core.subsystem_id == 0x106b3300 || codec->core.subsystem_id == 0x106b3600) {
		if (spec->use_data) {
			//cs_8409_playstop_data_ssm3(codec);
		} else {
			//cs_8409_playstop_real_ssm3(codec);
			cs_8409_playstop_real(codec);
                }
	}
        else if (codec->core.subsystem_id == 0x106b1000 || codec->core.subsystem_id == 0x106b0f00 || codec->core.subsystem_id == 0x106b0e00) {
		if (spec->use_data) {
			printk("snd_hda_intel: cs_8409_play_cleanup data not implemented for subsystem id 0x%08x",codec->core.subsystem_id);
		} else {
			cs_8409_playstop_real(codec);
		}
        }
	else {
		printk("snd_hda_intel: UNKNOWN subsystem id 0x%08x",codec->core.subsystem_id);
	}

}


// NOTE - so far all systems use the same inputs for internal mike capturing - not sure if
// there are any subsystem_id differences

void cs_8409_capture_setup(struct hda_codec *codec)
{
        struct cs8409_apple_spec *spec = codec->spec;
        if (codec->core.subsystem_id == 0x106b3300 || codec->core.subsystem_id == 0x106b3600 || codec->core.subsystem_id == 0x106b3900
                || codec->core.subsystem_id == 0x106b1000 || codec->core.subsystem_id == 0x106b0f00 || codec->core.subsystem_id == 0x106b0e00) {
		if (spec->use_data) {
                        //cs_8409_capture_data(codec);
		} else {
                        //cs_8409_capture_real(codec);
		        cs_8409_capture_real(codec);
		}
	}
	else {
                printk("snd_hda_intel: UNKNOWN subsystem id 0x%08x",codec->core.subsystem_id);
	}
}


void cs_8409_capture_cleanup(struct hda_codec *codec)
{
        struct cs8409_apple_spec *spec = codec->spec;
        if (codec->core.subsystem_id == 0x106b3300 || codec->core.subsystem_id == 0x106b3600 || codec->core.subsystem_id == 0x106b3900
                || codec->core.subsystem_id == 0x106b1000 || codec->core.subsystem_id == 0x106b0f00 || codec->core.subsystem_id == 0x106b0e00) {
		if (spec->use_data) {
                       //cs_8409_capturestop_data(codec);
		} else {
                       //cs_8409_capturestop_real(codec);
                       cs_8409_capturestop_real(codec);
                }
	}
	else {
                printk("snd_hda_intel: UNKNOWN subsystem id 0x%08x",codec->core.subsystem_id);
	}

}

// routine to clear unsol list
static void cs_8409_clear_external_device_unsolicited_responses(struct hda_codec *codec)
{
	struct cs8409_apple_spec *spec = codec->spec;
	struct unsol_item *unsol_entry = NULL;
	struct unsol_item *unsol_temp = NULL;
	if (!list_empty(&spec->unsol_list)) {
		codec_info(codec, "cs_8409_clear_external_device_unsolicited_responses UNSOL start\n");
		list_for_each_entry_safe(unsol_entry, unsol_temp, &spec->unsol_list, list)
		{
			list_del_init(&unsol_entry->list);
			spec->unsol_items_prealloc_used[unsol_entry->idx] = 0;
			memset(unsol_entry, 0, sizeof(struct unsol_item));
		}
		codec_info(codec, "cs_8409_clear_external_device_unsolicited_responses UNSOL end\n");
	}
}

static void cs_8409_cs42l83_unsolicited_response_finalize(struct hda_codec *codec, unsigned int res);

static void cs_8409_perform_external_device_unsolicited_responses(struct hda_codec *codec)
{
	struct cs8409_apple_spec *spec = codec->spec;
	struct unsol_item *unsol_entry = NULL;
	struct unsol_item *unsol_temp = NULL;
	if (!list_empty(&spec->unsol_list)) {
		codec_info(codec, "cs_8409_perform_external_device_unsolicited_responses UNSOL start\n");
		list_for_each_entry_safe(unsol_entry, unsol_temp, &spec->unsol_list, list)
		{
			list_del_init(&unsol_entry->list);
			// pigs this gets complicated - these might issue other unsol responses
			cs_8409_cs42l83_unsolicited_response_finalize(codec, unsol_entry->res);
			spec->unsol_items_prealloc_used[unsol_entry->idx] = 0;
			memset(unsol_entry, 0, sizeof(struct unsol_item));
		}
		codec_info(codec, "cs_8409_perform_external_device_unsolicited_responses UNSOL end\n");
	}
}

static void cs_8409_cs42l83_unsolicited_response(struct hda_codec *codec, unsigned int res)
{
	struct cs8409_apple_spec *spec = codec->spec;

	// not clear if want to use the GPIO pins apparently passed in res to determine
	// if want to do interrupt checking here and if no interrupts then to do
	// some other unsolicited response function (not seen any such unsolicited responses yet)
	// without checking the unsolicited block status

	// now think dont need a list - we can only have 1 outstanding unsolicted interrupt request
	// we may get multiple unsolicited interrupt requests - but they all will have same GPIO status (0x26)
	// and we determine the exact interrupt by reading the cs42l83 registers - which we are trying to avoid
	// clashing with other verbs
	// it may be that we get multiple interrupt flags to handle when we do read - not seen so far

	if (spec->block_unsol)
	{
		int itm;
		int new_itm = -1;
		codec_info(codec, "cs_8409_cs42l83_unsolicited_response -     UNSOL BLOCKED\n");
		for (itm=0; itm<10; itm++)
			if (spec->unsol_items_prealloc_used[itm] == 0) { new_itm = itm; break; }
		if (new_itm < 0)
		{
			codec_info(codec, "cs_8409_cs42l83_unsolicited_response - IGNORING UNSOL RESPONSE!!\n");
			return;
		}
		spec->unsol_items_prealloc_used[new_itm] = 1;
		memset(&(spec->unsol_items_prealloc[new_itm]), 0, sizeof(struct unsol_item));
                spec->unsol_items_prealloc[new_itm].res = res;
                spec->unsol_items_prealloc[new_itm].idx = new_itm;
		list_add_tail(&(spec->unsol_items_prealloc[new_itm].list), &spec->unsol_list);
		codec_info(codec, "cs_8409_cs42l83_unsolicited_response - UNSOL response stored\n");
		return;
        }
        else
		codec_info(codec, "cs_8409_cs42l83_unsolicited_response - NOT UNSOL BLOCKED\n");

        // so it appears we need to block unsol responses while doing unsol responses
	// this is probably not the way to do this but still havent figured out how to use locking properly
	// as this needs to be interruptible because some of these functions take a long time
	// I think if we get here we cannot have been blocked so list maybe always empty
	// whats not clear is if list_for_each_entry_safe is safe for addition also
	spec->block_unsol = 1;

	cs_8409_cs42l83_unsolicited_response_finalize(codec, res);

	if (!list_empty(&spec->unsol_list))
	{
		mycodec_info(codec, "cs_8409_cs42l83_unsolicited_response - performing blocked responses start\n");
		cs_8409_perform_external_device_unsolicited_responses(codec);
		mycodec_info(codec, "cs_8409_cs42l83_unsolicited_response - performing blocked responses end\n");
	}

	spec->block_unsol = 0;
}

static void cs_8409_cs42l83_unsolicited_response_finalize(struct hda_codec *codec, unsigned int res)
{
	struct cs8409_apple_spec *spec = codec->spec;

	if (spec->use_data)
		cs_8409_external_device_unsolicited_response_data(codec, res);
	else
	{
		if (spec->headset_phase == 0)
		{
			mycodec_info(codec, "cs_8409_external_device_unsolicited_response_finalize - phase is 0 - skipping\n");
			return;
		}


		// note the data version will only play thro the headphones for a single time
		//cs_8409_external_device_unsolicited_response_data(codec, res);
		cs_8409_external_device_unsolicited_response(codec, 0, 1);
	}
}


static void cs_8409_headset_mike_setup_nouse(struct hda_codec *codec)
{
        struct cs8409_apple_spec *spec = codec->spec;

        cs_8409_intmike_linein_disable(codec);

	cs_8409_headset_mike_streaming_preplay(codec, 1);
	cs_8409_headset_mike_buttons_enable(codec);
}


void cs_8409_headplay_setup(struct hda_codec *codec)
{
        struct cs8409_apple_spec *spec = codec->spec;
        if (codec->core.subsystem_id == 0x106b3900) {
		if (spec->use_data) {
                        cs_8409_headplay_data(codec);
		} else {
		        cs_8409_headplay_real(codec);
                }
	}
        else if (codec->core.subsystem_id == 0x106b3300 || codec->core.subsystem_id == 0x106b3600) {
		if (spec->use_data) {
                        //cs_8409_play_data_ssm3(codec);
		} else {
                        //cs_8409_play_real_ssm3(codec);
		        cs_8409_headplay_real(codec);
		}
	}
        else if (codec->core.subsystem_id == 0x106b1000 || codec->core.subsystem_id == 0x106b0f00 || codec->core.subsystem_id == 0x106b0e00) {
		if (spec->use_data) {
                        printk("snd_hda_intel: cs_8409_headplay_setup data not implemented for subsystem id 0x%08x",codec->core.subsystem_id);
		} else {
                        cs_8409_headplay_real(codec);
		}
        }
	else {
                printk("snd_hda_intel: UNKNOWN subsystem id 0x%08x",codec->core.subsystem_id);
	}

        // decided this needs moving till all stream setup verbs done
        //spec->block_unsol = 0;

        //if (!list_empty(&spec->unsol_list))
        //{
        //        codec_info(codec, "cs_8409_headplay_setup - performing UNSOL responses\n");
        //        cs_8409_perform_external_device_unsolicited_responses(codec);
        //}
}


void cs_8409_headplay_cleanup(struct hda_codec *codec)
{
        struct cs8409_apple_spec *spec = codec->spec;
        if (codec->core.subsystem_id == 0x106b3900) {
		if (spec->use_data) {
                        cs_8409_headplaystop_data(codec);
		} else {
                        //cs_8409_headplaystop_data(codec);
		        cs_8409_headplaystop_real(codec);
                }
	}
        else if (codec->core.subsystem_id == 0x106b3300 || codec->core.subsystem_id == 0x106b3600) {
		if (spec->use_data) {
                        //cs_8409_play_data_ssm3(codec);
		} else {
                        //cs_8409_play_real_ssm3(codec);
		        cs_8409_headplaystop_real(codec);
		}
	}
        else if (codec->core.subsystem_id == 0x106b1000 || codec->core.subsystem_id == 0x106b0f00 || codec->core.subsystem_id == 0x106b0e00) {
		if (spec->use_data) {
                        printk("snd_hda_intel: cs_8409_headplay_cleanup data not implemented for subsystem id 0x%08x",codec->core.subsystem_id);
		} else {
                        cs_8409_headplaystop_real(codec);
		}
        }
	else {
                printk("snd_hda_intel: UNKNOWN subsystem id 0x%08x",codec->core.subsystem_id);
	}

        // decided this needs moving till all stream cleanup verbs done
        //spec->block_unsol = 0;

        //if (!list_empty(&spec->unsol_list))
        //{
        //        codec_info(codec, "cs_8409_headplay_cleanup - performing UNSOL responses\n");
        //        cs_8409_perform_external_device_unsolicited_responses(codec);
        //}
}


// NOTE - so far all systems use the same chip (cs42l83) for headset mike capturing - not sure if
// there are any subsystem_id differences

void cs_8409_headcapture_setup(struct hda_codec *codec)
{
        struct cs8409_apple_spec *spec = codec->spec;
        if (codec->core.subsystem_id == 0x106b3300 || codec->core.subsystem_id == 0x106b3600 || codec->core.subsystem_id == 0x106b3900
                || codec->core.subsystem_id == 0x106b1000 || codec->core.subsystem_id == 0x106b0f00 || codec->core.subsystem_id == 0x106b0e00) {
		if (spec->use_data) {
                        //cs_8409_headcapture_data(codec);
		} else {
		        cs_8409_headcapture_real(codec);
                }
	}
	else {
                printk("snd_hda_intel: UNKNOWN subsystem id 0x%08x",codec->core.subsystem_id);
	}

        // decided this needs moving till all stream setup verbs done
        //spec->block_unsol = 0;

        //if (!list_empty(&spec->unsol_list))
        //{
        //        codec_info(codec, "cs_8409_headcapture_setup - performing UNSOL responses\n");
        //        cs_8409_perform_external_device_unsolicited_responses(codec);
        //}
}


void cs_8409_headcapture_cleanup(struct hda_codec *codec)
{
        struct cs8409_apple_spec *spec = codec->spec;
        if (codec->core.subsystem_id == 0x106b3300 || codec->core.subsystem_id == 0x106b3600 || codec->core.subsystem_id == 0x106b3900
                || codec->core.subsystem_id == 0x106b1000 || codec->core.subsystem_id == 0x106b0f00 || codec->core.subsystem_id == 0x106b0e00) {
		if (spec->use_data) {
                        //cs_8409_capturestop_data(codec);
		} else {
                        //cs_8409_capturestop_real(codec);
		        cs_8409_headcapturestop_real(codec);
		}
	}
	else {
                printk("snd_hda_intel: UNKNOWN subsystem id 0x%08x",codec->core.subsystem_id);
	}

        // decided this needs moving till all stream cleanup verbs done
        //spec->block_unsol = 0;

        //if (!list_empty(&spec->unsol_list))
        //{
        //        codec_info(codec, "cs_8409_headcapturestop_cleanup - performing UNSOL responses\n");
        //        cs_8409_perform_external_device_unsolicited_responses(codec);
        //}
}


static void cs_8409_pcm_playback_pre_prepare_hook(struct hda_pcm_stream *hinfo, struct hda_codec *codec,
                               unsigned int stream_tag, unsigned int format, struct snd_pcm_substream *substream,
                               int action)
{
	struct cs8409_apple_spec *spec = codec->spec;

	if (action == HDA_GEN_PCM_ACT_PREPARE) {
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 8, 0)
		struct timespec64 curtim;
		ktime_get_real_ts64(&curtim);
#else
		struct timespec curtim;
		getnstimeofday(&curtim);
#endif
		spec->play_init_count++;
		myprintk("snd_hda_intel: command cs_8409_pcm_playback_pre_prepare_hook HOOK PREPARE init %d %d last %lld cur %lld",spec->play_init,spec->play_init_count,spec->last_play_time.tv_sec,curtim.tv_sec);
                //dump_stack();
		// for some reason this is being called twice within short time so setup is being done twice
		// with no intervening cleanup
		// which may be introducing glitches in the headset/headphone stream - which it is!!!
		// try suppressing any further calls
		// well great apparently its a feature this function can be called multiple times!!
		// looking at examples and Alsa driver docs it appears the idea of this function is to set
		// the stream parameters - so lets let it set the stream parameters every time
		// but only do the main apple setup once
		if (1) {
			struct hda_cvt_setup_apple *p = NULL;
			//int power_chk = 0;

			// in the new way we set the stream up here using the passed data
			// - this does not actually update the stream format here but sets the cached parameters
			// so the cs_8409_really_update_stream_format will cause the updates to occur
                        // note we explicitly set the channel id - dont see another way yet

                        //cs_8409_setup_stream_format(codec, 0x02, stream_tag, format);
                        cs_8409_store_stream_format(codec, 0x02, stream_tag, format);

                        //cs_8409_setup_stream_format(codec, 0x03, stream_tag, format);
                        cs_8409_store_stream_format(codec, 0x03, stream_tag, format);

                        //cs_8409_setup_stream_format(codec, 0x0a, stream_tag, format);
                        cs_8409_store_stream_format(codec, 0x0a, stream_tag, format);

                        // save number of actual stream channels
                        spec->stream_channels = substream->runtime->channels;

			hda_check_power_state(codec, 0x1a, 1);
			hda_check_power_state(codec, 0x3c, 1);
		}

		if (spec->play_init_count == 1) {
			struct hda_cvt_setup_apple *p = NULL;

			// for the moment have junky test here
			if (spec->jack_present)
			{
				// for the moment I think this works for both MB 14,1 and 14,3 - same hda and headphone chip
				// note that so far only the headphone chip seems to generate unsol responses usually
				spec->block_unsol = 1;
				// we need to split this to deal with capture only setup
				// and capture with play setup
				// note this does mean we setup the mike in a different order to OSX
				// if we are capturing with playing - because the capture setup seems to be done
				// first on Linux and we dont know at that stage if we will be playing
				if (spec->have_mike)
				{
					// actually we always need to do cs_8409_headplay_setup - here we are about to play
					// - what this possibly would allow is the apple way of doing a pre-setup
					// so here we would switch between doing a full setup or a partial setup
					if (spec->headset_play_format_setup_needed)
					{
						cs_8409_headplay_setup(codec);
						spec->headset_play_format_setup_needed = 0;
					}
					// we only setup capturing if we are actually doing capturing
					//if (spec->headset_capture_format_setup_needed)
					//{
					//	cs_8409_headcapture_setup(codec);
					//	spec->headset_capture_format_setup_needed = 0;
					//}
				}
				else
				{
					cs_8409_headplay_setup(codec);
				}
			}
			else {
			        cs_8409_play_setup(codec);
			}
			myprintk("snd_hda_intel: command cs_8409_pcm_playback_pre_prepare_hook setup play called");

			hda_check_power_state(codec, 0x1a, 2);
			hda_check_power_state(codec, 0x3c, 2);


			// I dont now understand how this worked - the codes above ALWAYS reset the stream format
			// to the OSX format
			// and unless I force a stream update here there will be a stream format difference
			// yet it appears it worked - even tho sometimes there was no format update after this routine
			// now I dont know why


			// so we need to force the stream to be re-set here
			// problem is it appears hda_codec caches the stream format and id and only updates if changed
			// and there doesnt seem to be a good way to force an update

			// this routine doesnt seem to be nid specific - so explicitly fix the known nids here
			// no longer needed now we set the stream format correctly above
			// so when snd_hda_multi_out_analog_prepare is called after this routine it should do nothing
			// as we will have cached and set the right format now

                        //cs_8409_reset_stream_format(codec, 0x02, 1, 0);

                        //cs_8409_reset_stream_format(codec, 0x03, 1, 0);

                        //cs_8409_reset_stream_format(codec, 0x0a, 1, 0);


			spec->playing = 0;


			spec->play_init = 1;
		}
	}
}


static void cs_8409_playback_pcm_hook(struct hda_pcm_stream *hinfo, struct hda_codec *codec, struct snd_pcm_substream *substream, int action)
{

	struct cs8409_apple_spec *spec = codec->spec;

	// so finally getting a handle on ordering here
	// we need to do the OSX setup in the OPEN section
	// as the generic hda format and stream setup is done BEFORE the PREPARE hook
	// (theres a good chance we only need to do this once at least as long as machine doesnt sleep)
	// (or we could just override the prepare function completely)
	// I now think the noise was caused by mis-match between the stream format and the nid setup format
	// (because the generic setup was done before the OSX setup and the actual streamed format is slightly different)
	// (the hda documentation says these really need to match)
	// It appears the 8409 setup can handle at least some differences in the stream format
	// as long as we set the nid to format the kernel is sending
	// certainly seems to handle S24_LE or S32_LE differences (OSX format is always S24_3LE)


	if (action == HDA_GEN_PCM_ACT_OPEN) {
		//struct hda_cvt_setup_apple *p = NULL;
		myprintk("snd_hda_intel: command cs_8409_playback_pcm_hook open");

		spec->play_init_count = 0;

		myprintk("snd_hda_intel: command cs_8409_playback_pcm_hook open end");
	} else if (action == HDA_GEN_PCM_ACT_PREPARE) {
		// so this comes AFTER the stream format, frequency setup verbs are sent for the pcm stream
		// note that this can be called multiple times apparently
		// not clear what if any the differences are for those multiple calls
		// - does mean we need to ensure we only do most operations once
		// (most of the work is done in the pre prepare function)
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 8, 0)
		struct timespec64 curtim;
		ktime_get_real_ts64(&curtim);
#else
		struct timespec curtim;
		getnstimeofday(&curtim);
#endif
		myprintk("snd_hda_intel: command cs_8409_playback_pcm_hook HOOK PREPARE init %d %d last %lld cur %lld",spec->play_init,spec->play_init_count,spec->last_play_time.tv_sec,curtim.tv_sec);
                //dump_stack();
		//int power_chk = 0;
		//power_chk = snd_hda_codec_read(codec, codec->core.afg, 0, AC_VERB_GET_POWER_STATE, 0);
		//myprintk("snd_hda_intel: command cs_8409_playback_pcm_hook power check 0x01 2 %d", power_chk);
		// this is where we need to finally unset the block_unsol
		// - which also means this is where we should check for unsolicited responses
		spec->block_unsol = 0;
		if (!list_empty(&spec->unsol_list))
		{
			codec_info(codec, "cs_8409_playback_pcm_hook - performing UNSOL responses\n");
			cs_8409_perform_external_device_unsolicited_responses(codec);
			//cs_8409_clear_external_device_unsolicited_responses(codec);
		}
		spec->playing = 1;
		myprintk("snd_hda_intel: command cs_8409_playback_pcm_hook HOOK PREPARE end");
	} else if (action == HDA_GEN_PCM_ACT_CLEANUP) {
		// so this also comes AFTER the stream format, frequency cleanup verbs are sent for the pcm stream
		int power_chk = 0;
		myprintk("snd_hda_intel: command cs_8409_playback_pcm_hook HOOK CLEANUP");
        	power_chk = snd_hda_codec_read(codec, codec->core.afg, 0, AC_VERB_GET_POWER_STATE, 0);
		myprintk("snd_hda_intel: command cs_8409_playback_pcm_hook power check 0x01 3 %d", power_chk);
		myprintk("snd_hda_intel: command cs_8409_playback_pcm_hook jack_present %d\n",spec->jack_present);
		// for the moment have junky test here
		if (spec->jack_present)
		{
			// for the moment I think this works for both MB 14,1 and 14,3 - same hda and headphone chip
			// note that so far only the headphone chip seems to generate unsol responses usually
			spec->block_unsol = 1;
			// so dont think need to anything about capturing here
			cs_8409_headplay_cleanup(codec);
			spec->headset_play_format_setup_needed = 1;
		}
                else
		        cs_8409_play_cleanup(codec);
		myprintk("snd_hda_intel: command cs_8409_playback_pcm_hook done play down");
		spec->block_unsol = 0;
		if (!list_empty(&spec->unsol_list))
		{
			codec_info(codec, "cs_8409_playback_pcm_hook - performing UNSOL responses\n");
			cs_8409_perform_external_device_unsolicited_responses(codec);
		}
		spec->play_init_count = 0;
		// not sure of this position yet
		spec->playing = 0;
        	power_chk = snd_hda_codec_read(codec, codec->core.afg, 0, AC_VERB_GET_POWER_STATE, 0);
		myprintk("snd_hda_intel: command cs_8409_playback_pcm_hook power check 0x01 4 %d", power_chk);
		myprintk("snd_hda_intel: command cs_8409_playback_pcm_hook HOOK CLEANUP end");
	} else if (action == HDA_GEN_PCM_ACT_CLOSE) {
		myprintk("snd_hda_intel: command cs_8409_playback_pcm_hook close");
		myprintk("snd_hda_intel: command cs_8409_playback_pcm_hook close end");
	}

}


static void cs_8409_pcm_capture_pre_prepare_hook(struct hda_pcm_stream *hinfo, struct hda_codec *codec,
                               unsigned int stream_tag, unsigned int format, struct snd_pcm_substream *substream,
                               int action)
{
	struct cs8409_apple_spec *spec = codec->spec;

	if (action == HDA_GEN_PCM_ACT_PREPARE) {
		spec->capture_init_count++;
		myprintk("snd_hda_intel: command cs_8409_pcm_capture_pre_prepare_hook HOOK PREPARE init %d %d",spec->capture_init,spec->capture_init_count);

		// for some reason this is being called twice within short time
		// well great apparently its a feature this function can be called multiple times!!
		// looking at examples and Alsa driver docs it appears the idea of this function is to set
		// the stream parameters - so lets let it set the stream parameters every time
		// but only do the main apple setup once

		// so the first action for internal mike recording (via Quicktime)
		// is a headphone sense
		// followed by amp setup for playing - is this just a feature of Quicktime??
		// maybe Quicktime just auto sets up play just in case
		// we dont seem to have a headphone sense if we have already plugged in the headset
		// not that we can do anything - except abort if no headset plugged in??

		//if (hinfo->nid == 0x22)
		//{
		//	int retval;
		//	retval = cs42l83_headphone_sense(codec);
		//}


		// I think this is the same for intmike or headset mike
		//cs_8409_setup_stream_format(codec, hinfo->nid, stream_tag, format);
		cs_8409_store_stream_format(codec, hinfo->nid, stream_tag, format);

		// ensure the setup is only done once
		if (spec->capture_init_count == 1) {

			// for the moment have junky test here
			if (spec->jack_present) {
				spec->block_unsol = 1;
				if (spec->have_mike)
				{
					// so it seems if we have a headset mike we always enable the
					// headphones even if just capturing
					if (spec->headset_play_format_setup_needed)
					{
						cs_8409_headplay_setup(codec);
						spec->headset_play_format_setup_needed = 0;
					}
					if (spec->headset_capture_format_setup_needed)
					{
						cs_8409_headcapture_setup(codec);
						spec->headset_capture_format_setup_needed = 0;
					}
				}
				// I think this is impossible - this would say we tried to capture
				// using a headset without mike
				// NOTE - still not fixed linein/lineout working - this may need
				// changing here
			}
			else
				cs_8409_capture_setup(codec);
		}

		myprintk("snd_hda_intel: command cs_8409_capture_pcm_hook setup capture called");

		spec->capturing = 0;


		spec->capture_init = 1;
	}
}

static void cs_8409_capture_pcm_hook(struct hda_pcm_stream *hinfo, struct hda_codec *codec, struct snd_pcm_substream *substream, int action)
{

        //struct cs8409_apple_spec *spec = codec->spec;

        struct cs8409_apple_spec *spec = NULL;

        myprintk_dbg("snd_hda_intel: command cs_8409_capture_pcm_hook HOOK init called");

        //dump_stack();

        myprintk_dbg("snd_hda_intel: command cs_8409_capture_pcm_hook HOOK init post stack");

        // - so this seems to be the critical issue - this can apparently be called with a NULL codec!!!
        // only thing to do seems to be to return!!
        if (codec == NULL) {
                struct hda_codec *badptr = NULL;
                printk("snd_hda_intel: command cs_8409_capture_pcm_hook HOOK init  - CODEC NULL");
                // so if we are here it looks as tho we have been called from call_hp_automute
                // - in which the codec is the 1st arg
                badptr = (struct hda_codec *) hinfo;
                spec = badptr->spec;
                printk("snd_hda_intel: cs_8409_capture_pcm_hook -  pcm_playback_hook %p", spec->gen.pcm_playback_hook);
                printk("snd_hda_intel: cs_8409_capture_pcm_hook -   pcm_capture_hook %p", spec->gen.pcm_capture_hook);
                printk("snd_hda_intel: cs_8409_capture_pcm_hook -   hp_automute_hook %p", spec->gen.hp_automute_hook);
                printk("snd_hda_intel: cs_8409_capture_pcm_hook - line_automute_hook %p", spec->gen.line_automute_hook);
                printk("snd_hda_intel: cs_8409_capture_pcm_hook - line_automute_hook %p", spec->gen.mic_autoswitch_hook);
                printk("snd_hda_intel: command cs_8409_capture_pcm_hook HOOK init  - CODEC NULL exit");
                return;
        }
        else
	{
                myprintk_dbg("snd_hda_intel: command cs_8409_capture_pcm_hook HOOK init  - CODEC NOT NULL");
	}

        //dump_stack();

        spec = codec->spec;


	// so now no setup is done here - we only check for unsolicited responses
	// - we do do cleanup for the CLEANUP action

	if (action == HDA_GEN_PCM_ACT_OPEN) {
		//struct hda_cvt_setup_apple *p = NULL;
		myprintk("snd_hda_intel: command cs_8409_capture_pcm_hook open");
		spec->capture_init_count = 0;

		myprintk("snd_hda_intel: command cs_8409_capture_pcm_hook open end");
	} else if (action == HDA_GEN_PCM_ACT_PREPARE) {
		// so this comes AFTER the stream format, frequency setup verbs are sent for the pcm stream
		// note that this can be called multiple times apparently
		// not clear what if any the differences are for those multiple calls
		// - does mean we need to ensure we only do most operations once
		// (most of the work is done in the pre prepare function)
		myprintk("snd_hda_intel: command cs_8409_capture_pcm_hook HOOK PREPARE init %d",spec->capture_init);
		// this is where we need to finally unset the block_unsol
		// - which also means this is where we should check for unsolicited responses
		spec->block_unsol = 0;
		if (!list_empty(&spec->unsol_list))
		{
			codec_info(codec, "cs_8409_capture_pcm_hook - performing UNSOL responses\n");
			cs_8409_perform_external_device_unsolicited_responses(codec);
		}
		spec->capturing = 1;
		myprintk("snd_hda_intel: command cs_8409_capture_pcm_hook HOOK PREPARE end");
	} else if (action == HDA_GEN_PCM_ACT_CLEANUP) {
		// so this also comes AFTER the stream format, frequency cleanup verbs are sent for the pcm stream
		int power_chk = 0;
		myprintk("snd_hda_intel: command cs_8409_capture_pcm_hook HOOK CLEANUP");
		power_chk = snd_hda_codec_read(codec, codec->core.afg, 0, AC_VERB_GET_POWER_STATE, 0);
		myprintk("snd_hda_intel: command cs_8409_capture_pcm_hook power check 0x01 3 %d", power_chk);
		myprintk("snd_hda_intel: command cs_8409_capture_pcm_hook jack_present %d\n",spec->jack_present);
		// for the moment have junky test here
		if (spec->jack_present)
		{
			// for the moment I think this works for both MB 14,1 and 14,3 - same hda and headphone chip
			// note that so far only the headphone chip seems to generate unsol responses usually
			spec->block_unsol = 1;
			if (spec->headset_capture_format_setup_needed == 0)
			{
				cs_8409_headcapture_cleanup(codec);
				spec->headset_capture_format_setup_needed = 1;
			}
			if (!spec->playing)
			{
				if (spec->headset_play_format_setup_needed == 0)
				{
					cs_8409_headplay_cleanup(codec);
					spec->headset_play_format_setup_needed = 1;
				}
			}
		}
                else
		        cs_8409_capture_cleanup(codec);
		myprintk("snd_hda_intel: command cs_8409_capture_pcm_hook done capture down");
		spec->block_unsol = 0;
		if (!list_empty(&spec->unsol_list))
		{
			codec_info(codec, "cs_8409_capture_pcm_hook - performing UNSOL responses\n");
			cs_8409_perform_external_device_unsolicited_responses(codec);
		}
		spec->capture_init_count = 0;
		// not sure of this position yet
		spec->capturing = 0;
		power_chk = snd_hda_codec_read(codec, codec->core.afg, 0, AC_VERB_GET_POWER_STATE, 0);
		myprintk("snd_hda_intel: command cs_8409_capture_pcm_hook power check 0x01 4 %d", power_chk);
		myprintk("snd_hda_intel: command cs_8409_capture_pcm_hook HOOK CLEANUP end");
	} else if (action == HDA_GEN_PCM_ACT_CLOSE) {
		myprintk("snd_hda_intel: command cs_8409_capture_pcm_hook close");
		myprintk("snd_hda_intel: command cs_8409_capture_pcm_hook close end");
	}

}


// this version runs all explicit commands as logged on OSX
static int cs_8409_data_config(struct hda_codec *codec)
{
	//struct cs8409_apple_spec *spec = codec->spec;
	//hda_nid_t beep_nid = spec->beep_nid;

	unsigned int tmpstate1 = -1;
	unsigned int tmpstate2 = -1;
	unsigned int tmpstate3 = -1;
	unsigned int tmpstate4 = -1;

	myprintk("snd_hda_intel: cs8409_data_config");


	cs_8409_boot_setup_data(codec);


	// check what power state of these nodes is - Apple does not do this
	tmpstate1 = hda_sync_power_state_8409(codec, 0x48, AC_PWRST_D0);
	tmpstate2 = hda_sync_power_state_8409(codec, 0x49, AC_PWRST_D0);
	tmpstate3 = hda_sync_power_state_8409(codec, 0x4a, AC_PWRST_D0);
	tmpstate4 = hda_sync_power_state_8409(codec, 0x4b, AC_PWRST_D0);

	myprintk("snd_hda_intel: cs8409_data_config power 0x48 %d 0x49 %d 0x4a %d 0x4b %d\n",tmpstate1,tmpstate2,tmpstate3,tmpstate4);


	myprintk("snd_hda_intel: cs8409_data_config end");

	return 0;
}


// this version runs the setup using functions based on the setup using the logged data
static int cs_8409_real_config(struct hda_codec *codec)
{
	//struct cs8409_apple_spec *spec = codec->spec;
	//hda_nid_t beep_nid = spec->beep_nid;

	unsigned int tmpstate1 = -1;
	unsigned int tmpstate2 = -1;
	unsigned int tmpstate3 = -1;
	unsigned int tmpstate4 = -1;

	myprintk("snd_hda_intel: cs8409_real_config");


	cs_8409_boot_setup_real(codec);


	// check what power state of these nodes is - Apple does not do this
	tmpstate1 = hda_sync_power_state_8409(codec, 0x48, AC_PWRST_D0);
	tmpstate2 = hda_sync_power_state_8409(codec, 0x49, AC_PWRST_D0);
	tmpstate3 = hda_sync_power_state_8409(codec, 0x4a, AC_PWRST_D0);
	tmpstate4 = hda_sync_power_state_8409(codec, 0x4b, AC_PWRST_D0);

	myprintk("snd_hda_intel: cs8409_real_config power 0x48 %d 0x49 %d 0x4a %d 0x4b %d\n",tmpstate1,tmpstate2,tmpstate3,tmpstate4);


	myprintk("snd_hda_intel: cs8409_real_config end");

	return 0;
}

