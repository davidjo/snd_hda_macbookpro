/* SPDX-License-Identifier: GPL-2.0 */
#ifndef PATCH_CIRRUS_EARPODS_H
#define PATCH_CIRRUS_EARPODS_H

/* Values at interrupt_action(), after the existing hardware interrupt mask.
 * Correlated with labeled Apple EarPods captures on MacBookPro14,1.
 * No Linux/ALSA dependencies: this same decoder is exercised in userspace.
 */
enum earpods_action {
	EARPODS_NONE,
	EARPODS_VOLUMEUP,
	EARPODS_VOLUMEDOWN,
	EARPODS_PLAYPAUSE,
	EARPODS_BLOCKED,
};

static unsigned int earpods_decode(unsigned int *held, unsigned int status,
				  int ready)
{
	unsigned int action;

	/* Plug, unplug, detection and power interrupts never produce actions. */
	if (!ready || (status & 0x00600000U)) {
		*held = EARPODS_NONE;
		return EARPODS_NONE;
	}

	/* Detection/power changes cannot re-arm a button that is still held. */
	if (status & 0x00001803U) {
		if (*held || (status & 0x00130300U))
			*held = EARPODS_BLOCKED;
		return EARPODS_NONE;
	}

	if (status == 0x00100000U) {
		if (*held == EARPODS_VOLUMEUP || *held == EARPODS_VOLUMEDOWN ||
		    *held == EARPODS_BLOCKED)
			*held = EARPODS_NONE;
		return EARPODS_NONE;
	}
	if (status == 0x00000200U) {
		if (*held == EARPODS_PLAYPAUSE || *held == EARPODS_BLOCKED)
			*held = EARPODS_NONE;
		return EARPODS_NONE;
	}

	switch (status) {
	case 0x00020000U: action = EARPODS_VOLUMEUP; break;
	case 0x00010000U: action = EARPODS_VOLUMEDOWN; break;
	case 0x00000100U: action = EARPODS_PLAYPAUSE; break;
	default:
		/* Suppress an ambiguous button sequence until a clean release. */
		if (status & 0x00130300U)
			*held = EARPODS_BLOCKED;
		return EARPODS_NONE;
	}

	if (*held != EARPODS_NONE) {
		if (*held != action)
			*held = EARPODS_BLOCKED;
		return EARPODS_NONE;
	}
	*held = action;
	return action;
}
#endif
