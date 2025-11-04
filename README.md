# snd_hda_macbookpro

This is a kernel driver for sound on Macs with Cirrus 8409 HDA chips.
Sound output is now reasonably complete and integrated with Linux.
Sound input still needs work.


It will play audio through Internal speakers or headphones.

The primary audio should be set to  Analogue Stereo Output in the Settings Audio dialog.


Sound recording from internal mike and headset mike is not yet fully interfaced with Linux user side.

The recorded sound level is very low but this is the sound level as returned in OSX.
Amplification will be required eg using something like PulseEffects.


The hardware device sound format is limited to 2/4 channel 44.1 kHz S24_LE S32_LE.
As long as use the default device volume control, other formats, frequencies work.


NOTA BENE: The direct hardware device (hw:0,0) and plughw:0,0 device have NO volume control so will be VERY loud!


Currently this works with MAX98706, SSM3515 and TAS5764L amplifiers.
It will NOT work with other amplifiers as each amplifier requires specific programming.


Power down/sleep completely unknown and untested.
At the moment everything is permanently powered on.


The Apple speaker setup is 4 speakers as a left tweeter, left woofer, right tweeter and right woofer
so this is actually a classic HiFi stereo (ie 2 channel) speaker system.
(These names are listed in the layout files under AppleHDA.kext/Contents/Resources).

The channel order for Linux has been modified to left tweeter, right tweeter and left woofer, right woofer
as this fits in with the Linux way much better.

The driver also has been modified to duplicate a stereo sound source onto the second stereo channel so all
speakers are driven (this essentially replicates the snd_hda_multi_out_analog_prepare function).

This will not sound the same as Apple (which is known to be using specific digital filter effects in CoreAudio).

To create a more Apple-like sound requires creating eg an Alsa pseudo device to channel duplicate a stereo sound
and apply different digital filters to the tweeter and woofer channels.


NOTE. My primary testing kernel is now Ubuntu LTS 24.04 6.8.


NOTA BENE. As of linux kernel 6.17 the sound kernel source directory has been completely re-organized.
           The installation script now works for 6.17 kernel versions (and later when they arrive).
           The old installation script is now called install.cirrus.driver.pre617.sh.
           The new version of the install.cirrus.driver.sh script will detect your kernel version and exec
           the old installation script as needed.
           For older kernel version you can just run the old installation script directly
           ie install.cirrus.driver.pre617.sh.
           Note that for kernel version 6.17 new files and directories have been added to the repo
           rather than attempting to update the pre 6.17 versions (as the kernel source changes also
           involved name changes and the new files are more consistent with the new kernel names).

           DKMS for 6.17 is untested and highly likely wont work without changes.


The following installation setup provided by leifliddy.



Compiling and installing driver:
-------------

**fedora package install**
```
dnf install gcc kernel-devel make patch wget
```
**ubuntu package install**  
```
apt install gcc linux-headers-generic make patch wget
```
**arch package install**
```
pacman -S gcc linux-headers make patch wget
```
**void package install**
```
xbps-install -S gcc make linux-headers patch wget
```

**build driver**  
```
git clone https://github.com/davidjo/snd_hda_macbookpro.git
cd snd_hda_macbookpro/
#run the following command as root or with sudo
./install.cirrus.driver.sh
reboot
```
