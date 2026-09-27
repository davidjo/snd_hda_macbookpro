# snd_hda_macbookpro

Linux kernel driver for Apple MacBooks with the Cirrus Logic CS8409 audio chip (A1708, MacBookPro13,x, MacBookPro14,x, etc.).

Fork of [davidjo/snd_hda_macbookpro](https://github.com/davidjo/snd_hda_macbookpro) patched to compile and work on Linux 7.0 and 6.17+.

Upstream fails to compile on modern kernels because of ALSA API changes (like `.free` and `patch_ops` being removed) and crashes with a GP fault on Ubuntu/Mint due to an 8-byte struct offset mismatch. This fork fixes both issues.

## Install (DKMS)

Prerequisites (Ubuntu / Debian / Mint):
```bash
sudo apt install git gcc make patch wget dkms linux-headers-$(uname -r)
```

Clone and install:
```bash
git clone https://github.com/duzelli/snd_hda_macbookpro.git
cd snd_hda_macbookpro
sudo ./install.cirrus.driver.sh -i
sudo reboot
```

## Volume slider crackling / static fix

On these MacBooks, the CS8409 has fixed hardware gain and volume is meant to be handled in software. By default PulseAudio tries to adjust hardware volume registers while playing and uses timer-based scheduling, which causes static/crackling when moving the volume slider.

To fix it:

1. In `/usr/share/pulseaudio/alsa-mixer/paths/analog-output.conf.common`, find `[Element PCM]` and change `volume = merge` to `volume = ignore`:
```ini
[Element PCM]
switch = mute
volume = ignore
```

2. In `/etc/pulse/default.pa`, change:
```text
load-module module-udev-detect
```
to:
```text
load-module module-udev-detect tsched=0
```

3. In `/etc/modprobe.d/cs8409.conf`, add power-saving options:
```text
options snd_hda_intel index=0,1
options snd_hda_intel model=imac
options snd_hda_intel power_save=0 power_save_controller=N
```

4. Restart PulseAudio:
```bash
systemctl --user restart pulseaudio
```

## Uninstall

```bash
sudo ./install.cirrus.driver.sh -r
```

---

## Original hardware notes (from David)

- Primary audio should be set to Analogue Stereo Output in Settings.
- The hardware device sound format is limited to 2/4 channel 44.1 kHz S24_LE / S32_LE.
- NOTA BENE: The direct hardware device (`hw:0,0`) has NO volume control, playing directly to it will be very loud.
- Works with MAX98706, SSM3515, and TAS5764L amplifiers.
