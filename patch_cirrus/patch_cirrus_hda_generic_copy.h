
/* playback mute control with the software mute bit check */
static void sync_auto_mute_bits(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
	struct hda_gen_spec *spec = codec->spec;

	if (spec->auto_mute_via_amp) {
		hda_nid_t nid = get_amp_nid(kcontrol);
		bool enabled = !((spec->mute_bits >> nid) & 1);
		ucontrol->value.integer.value[0] &= enabled;
		ucontrol->value.integer.value[1] &= enabled;
	}
}


static int hda_gen_mixer_mute_put(struct snd_kcontrol *kcontrol,
				  struct snd_ctl_elem_value *ucontrol)
{
	sync_auto_mute_bits(kcontrol, ucontrol);
	return snd_hda_mixer_amp_switch_put(kcontrol, ucontrol);
}


/*
 * Bound mute controls
 */
#define AMP_VAL_IDX_SHIFT	19
#define AMP_VAL_IDX_MASK	(0x0f<<19)

static int hda_gen_bind_mute_get(struct snd_kcontrol *kcontrol,
				 struct snd_ctl_elem_value *ucontrol)
{
	struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
	unsigned long pval;
	int err;

	mutex_lock(&codec->control_mutex);
	pval = kcontrol->private_value;
	kcontrol->private_value = pval & ~AMP_VAL_IDX_MASK; /* index 0 */
	err = snd_hda_mixer_amp_switch_get(kcontrol, ucontrol);
	kcontrol->private_value = pval;
	mutex_unlock(&codec->control_mutex);
	return err;
}

static int hda_gen_bind_mute_put(struct snd_kcontrol *kcontrol,
				 struct snd_ctl_elem_value *ucontrol)
{
	struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
	unsigned long pval;
	int i, indices, err = 0, change = 0;

	sync_auto_mute_bits(kcontrol, ucontrol);

	mutex_lock(&codec->control_mutex);
	pval = kcontrol->private_value;
	indices = (pval & AMP_VAL_IDX_MASK) >> AMP_VAL_IDX_SHIFT;
	for (i = 0; i < indices; i++) {
		kcontrol->private_value = (pval & ~AMP_VAL_IDX_MASK) |
			(i << AMP_VAL_IDX_SHIFT);
		err = snd_hda_mixer_amp_switch_put(kcontrol, ucontrol);
		if (err < 0)
			break;
		change |= err;
	}
	kcontrol->private_value = pval;
	mutex_unlock(&codec->control_mutex);
	return err < 0 ? err : change;
}


enum {
	HDA_CTL_WIDGET_VOL,
	HDA_CTL_WIDGET_MUTE,
	HDA_CTL_BIND_MUTE,
};


static const struct snd_kcontrol_new control_templates[] = {
	HDA_CODEC_VOLUME(NULL, 0, 0, 0),
	/* only the put callback is replaced for handling the special mute */
	{
		.iface = SNDRV_CTL_ELEM_IFACE_MIXER,
		.subdevice = HDA_SUBDEV_AMP_FLAG,
		.info = snd_hda_mixer_amp_switch_info,
		.get = snd_hda_mixer_amp_switch_get,
		.put = hda_gen_mixer_mute_put, /* replaced */
		.private_value = HDA_COMPOSE_AMP_VAL(0, 3, 0, 0),
	},
	{
		.iface = SNDRV_CTL_ELEM_IFACE_MIXER,
		.info = snd_hda_mixer_amp_switch_info,
		.get = hda_gen_bind_mute_get,
		.put = hda_gen_bind_mute_put, /* replaced */
		.private_value = HDA_COMPOSE_AMP_VAL(0, 3, 0, 0),
	},
};


/* add the powersave loopback-list entry */
static int add_loopback_list(struct hda_gen_spec *spec, hda_nid_t mix, int idx)
{
	struct hda_amp_list *list;

	list = snd_array_new(&spec->loopback_list);
	if (!list)
		return -ENOMEM;
	list->nid = mix;
	list->dir = HDA_INPUT;
	list->idx = idx;
	spec->loopback.amplist = spec->loopback_list.list;
	return 0;
}


static int is_input_pin(struct hda_codec *codec, hda_nid_t nid)
{
	unsigned int pincap = snd_hda_query_pin_caps(codec, nid);
	return (pincap & AC_PINCAP_IN) != 0;
}



//static int create_in_jack_mode(struct hda_codec *codec, hda_nid_t pin)
//{
//	struct hda_gen_spec *spec = codec->spec;
//	struct snd_kcontrol_new *knew;
//	char name[SNDRV_CTL_ELEM_ID_NAME_MAXLEN];
//	unsigned int defcfg;
//
//	if (pin == spec->hp_mic_pin)
//		return 0; /* already done in create_out_jack_mode() */
//
//	/* no jack mode for fixed pins */
//	defcfg = snd_hda_codec_get_pincfg(codec, pin);
//	if (snd_hda_get_input_pin_attr(defcfg) == INPUT_PIN_ATTR_INT)
//		return 0;
//
//	/* no multiple vref caps? */
//	if (get_in_jack_num_items(codec, pin) <= 1)
//		return 0;
//
//	get_jack_mode_name(codec, pin, name, sizeof(name));
//	knew = snd_hda_gen_add_kctl(spec, name, &in_jack_mode_enum);
//	if (!knew)
//		return -ENOMEM;
//	knew->private_value = pin;
//	return 0;
//}


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

	codec_dbg(codec, "%s path: depth=%d '%s'\n", pfx, path->depth, buf);
}


/* check whether the given two widgets can be connected */
static bool is_reachable_path(struct hda_codec *codec,
			      hda_nid_t from_nid, hda_nid_t to_nid)
{
	if (!from_nid || !to_nid)
		return false;
	return snd_hda_get_conn_index(codec, to_nid, from_nid, true) >= 0;
}


/* fill the label for each input at first */
static int fill_input_pin_labels(struct hda_codec *codec)
{
	struct hda_gen_spec *spec = codec->spec;
	const struct auto_pin_cfg *cfg = &spec->autocfg;
	int i;

	for (i = 0; i < cfg->num_inputs; i++) {
		hda_nid_t pin = cfg->inputs[i].pin;
		const char *label;
		int j, idx;

		if (!is_input_pin(codec, pin))
			continue;

		label = hda_get_autocfg_input_label(codec, cfg, i);
		idx = 0;
		for (j = i - 1; j >= 0; j--) {
			if (spec->input_labels[j] &&
			    !strcmp(spec->input_labels[j], label)) {
				idx = spec->input_label_idxs[j] + 1;
				break;
			}
		}

		spec->input_labels[i] = label;
		spec->input_label_idxs[i] = idx;
	}

	return 0;
}

/* Parse the codec tree and retrieve ADCs */
static int fill_adc_nids(struct hda_codec *codec)
{
	struct hda_gen_spec *spec = codec->spec;
	hda_nid_t nid;
	hda_nid_t *adc_nids = spec->adc_nids;
	int max_nums = ARRAY_SIZE(spec->adc_nids);
	int nums = 0;

	for_each_hda_codec_node(nid, codec) {
		unsigned int caps = get_wcaps(codec, nid);
		int type = get_wcaps_type(caps);

		if (type != AC_WID_AUD_IN || (caps & AC_WCAP_DIGITAL))
			continue;
		adc_nids[nums] = nid;
		if (++nums >= max_nums)
			break;
	}
	spec->num_adc_nids = nums;

	codec_dbg(codec, "fill_adc_nids num nids %d\n",nums);

	/* copy the detected ADCs to all_adcs[] */
	spec->num_all_adcs = nums;
	memcpy(spec->all_adcs, spec->adc_nids, nums * sizeof(hda_nid_t));

	return nums;
}


#define update_pin_ctl(codec, pin, val) \
	snd_hda_codec_write_cache(codec, pin, 0, \
				   AC_VERB_SET_PIN_WIDGET_CONTROL, val)

/* set the pinctl target value and write it if requested */
static void set_pin_target(struct hda_codec *codec, hda_nid_t pin,
			   unsigned int val, bool do_write)
{
	if (!pin)
		return;
	val = snd_hda_correct_pin_ctl(codec, pin, val);
	snd_hda_codec_set_pin_target(codec, pin, val);
	if (do_write)
		update_pin_ctl(codec, pin, val);
}



/* nid, dir and idx */
#define AMP_VAL_COMPARE_MASK	(0xffff | (1U << 18) | (0x0f << 19))

/* check whether the given ctl is already assigned in any path elements */
static bool is_ctl_used(struct hda_codec *codec, unsigned int val, int type)
{
	struct hda_gen_spec *spec = codec->spec;
	const struct nid_path *path;
	int i;

	val &= AMP_VAL_COMPARE_MASK;
	snd_array_for_each(&spec->paths, i, path) {
		if ((path->ctls[type] & AMP_VAL_COMPARE_MASK) == val)
			return true;
	}
	return false;
}

/* check whether a control with the given (nid, dir, idx) was assigned */
static bool is_ctl_associated(struct hda_codec *codec, hda_nid_t nid,
			      int dir, int idx, int type)
{
	unsigned int val = HDA_COMPOSE_AMP_VAL(nid, 3, idx, dir);
	return is_ctl_used(codec, val, type);
}


/* return true if either a volume or a mute amp is found for the given
 * aamix path; the amp has to be either in the mixer node or its direct leaf
 */
static bool look_for_mix_leaf_ctls(struct hda_codec *codec, hda_nid_t mix_nid,
				   hda_nid_t pin, unsigned int *mix_val,
				   unsigned int *mute_val)
{
	int idx, num_conns;
	const hda_nid_t *list;
	hda_nid_t nid;

	idx = snd_hda_get_conn_index(codec, mix_nid, pin, true);
	if (idx < 0)
		return false;

	*mix_val = *mute_val = 0;
	if (nid_has_volume(codec, mix_nid, HDA_INPUT))
		*mix_val = HDA_COMPOSE_AMP_VAL(mix_nid, 3, idx, HDA_INPUT);
	if (nid_has_mute(codec, mix_nid, HDA_INPUT))
		*mute_val = HDA_COMPOSE_AMP_VAL(mix_nid, 3, idx, HDA_INPUT);
	if (*mix_val && *mute_val)
		return true;

	/* check leaf node */
	num_conns = snd_hda_get_conn_list(codec, mix_nid, &list);
	if (num_conns < idx)
		return false;
	nid = list[idx];
	if (!*mix_val && nid_has_volume(codec, nid, HDA_OUTPUT) &&
	    !is_ctl_associated(codec, nid, HDA_OUTPUT, 0, NID_PATH_VOL_CTL))
		*mix_val = HDA_COMPOSE_AMP_VAL(nid, 3, 0, HDA_OUTPUT);
	if (!*mute_val && nid_has_mute(codec, nid, HDA_OUTPUT) &&
	    !is_ctl_associated(codec, nid, HDA_OUTPUT, 0, NID_PATH_MUTE_CTL))
		*mute_val = HDA_COMPOSE_AMP_VAL(nid, 3, 0, HDA_OUTPUT);

	return *mix_val || *mute_val;
}




/* add dynamic controls from template */
static struct snd_kcontrol_new *
add_control(struct hda_gen_spec *spec, int type, const char *name,
		       int cidx, unsigned long val)
{
	struct snd_kcontrol_new *knew;

	knew = snd_hda_gen_add_kctl(spec, name, &control_templates[type]);
	if (!knew)
		return NULL;
	knew->index = cidx;
	if (get_amp_nid_(val))
		knew->subdevice = HDA_SUBDEV_AMP_FLAG;
	knew->private_value = val;
	return knew;
}


static int add_control_with_pfx(struct hda_gen_spec *spec, int type,
				const char *pfx, const char *dir,
				const char *sfx, int cidx, unsigned long val)
{
	char name[SNDRV_CTL_ELEM_ID_NAME_MAXLEN];
	snprintf(name, sizeof(name), "%s %s %s", pfx, dir, sfx);
	if (!add_control(spec, type, name, cidx, val))
		return -ENOMEM;
	return 0;
}


#define add_pb_vol_ctrl(spec, type, pfx, val)			\
	add_control_with_pfx(spec, type, pfx, "Playback", "Volume", 0, val)
#define add_pb_sw_ctrl(spec, type, pfx, val)			\
	add_control_with_pfx(spec, type, pfx, "Playback", "Switch", 0, val)
#define __add_pb_vol_ctrl(spec, type, pfx, cidx, val)			\
	add_control_with_pfx(spec, type, pfx, "Playback", "Volume", cidx, val)
#define __add_pb_sw_ctrl(spec, type, pfx, cidx, val)			\
	add_control_with_pfx(spec, type, pfx, "Playback", "Switch", cidx, val)


/* create input playback/capture controls for the given pin */
static int new_analog_input(struct hda_codec *codec, int input_idx,
			    hda_nid_t pin, const char *ctlname, int ctlidx,
			    hda_nid_t mix_nid)
{
	struct hda_gen_spec *spec = codec->spec;
	struct nid_path *path;
	unsigned int mix_val, mute_val;
	int err, idx;

	if (!look_for_mix_leaf_ctls(codec, mix_nid, pin, &mix_val, &mute_val))
		return 0;

	path = snd_hda_add_new_path(codec, pin, mix_nid, 0);
	if (!path)
		return -EINVAL;
	print_nid_path(codec, "loopback", path);
	spec->loopback_paths[input_idx] = snd_hda_get_path_idx(codec, path);

	idx = path->idx[path->depth - 1];
	if (mix_val) {
		err = __add_pb_vol_ctrl(spec, HDA_CTL_WIDGET_VOL, ctlname, ctlidx, mix_val);
		if (err < 0)
			return err;
		path->ctls[NID_PATH_VOL_CTL] = mix_val;
	}

	if (mute_val) {
		err = __add_pb_sw_ctrl(spec, HDA_CTL_WIDGET_MUTE, ctlname, ctlidx, mute_val);
		if (err < 0)
			return err;
		path->ctls[NID_PATH_MUTE_CTL] = mute_val;
	}

	path->active = true;
	path->stream_enabled = true; /* no DAC/ADC involved */
	err = add_loopback_list(spec, mix_nid, idx);
	if (err < 0)
		return err;

	if (spec->mixer_nid != spec->mixer_merge_nid &&
	    !spec->loopback_merge_path) {
		path = snd_hda_add_new_path(codec, spec->mixer_nid,
					    spec->mixer_merge_nid, 0);
		if (path) {
			print_nid_path(codec, "loopback-merge", path);
			path->active = true;
			path->pin_fixed = true; /* static route */
			path->stream_enabled = true; /* no DAC/ADC involved */
			spec->loopback_merge_path =
				snd_hda_get_path_idx(codec, path);
		}
	}

	return 0;
}

