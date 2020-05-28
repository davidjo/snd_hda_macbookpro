# snd_hda_macbookpro

This is a kernel driver for sound on Macs with Cirrus 8409 HDA chips.
This is NOT a complete audio setup as yet and is still at a very alpha stage of development.

It will play audio through Internal speakers or headphones.

NEW: Sound recording from internal mike and headset mike now working.

NOTE NOTE!!!!!
The recorded sound level is very low but this is the sound level as returned in OSX.
Amplification will be required eg using something like PulseEffects.
NOTE NOTE!!!!!

The hardware device sound format is limited to 2/4 channel 44.1 kHz S24_LE S32_LE.
As long as use the default or plughw device volume control, other formats, frequencies work.

NOTA BENE: The direct hardware device (hw:0,0) has NO volume control so will be loud!

Currently this works with MAX98706 and SSM3515 amplifiers.
It will NOT work with other amplifiers (eg TAS5758L and TAS5764L as seen in ioreg dumps)
as each amplifier requires specific programming.


Power down/sleep completely unknown and untested.


Much more work is needed to correctly interface this kernel driver to the higher level
linux audio drivers eg pulse.

For example, the speakers are driven by a 4 channel audio stream which pulse wrongly
interprets as a 4 channel surround source.
(Note this means the Ubuntu speaker test does not work properly).
My interpretation is this is really a woofer/tweeter setup and we need specific
filters eg from PulseEffects to create a sound similar to that of OSX (which is known
to be using specific digital filter effects in CoreAudio).


NOTE. My primary testing kernel is now Ubuntu LTS 20.04 5.4.
      I have tested building for 5.5 but not 5.6.


The following installation setup provided by leifliddy.




Compiling and installing driver:
-------------

**fedora package install**
```
dnf install wget make gcc kernel-devel
```
**ubuntu package install**  
```
apt install wget make gcc linux-headers-generic
```
**arch package install**
```
pacman -S wget make gcc linux-headers
```

**build driver**  
```
git clone https://github.com/davidjo/snd_hda_macbookpro.git
cd snd_hda_macbookpro/
#run the following command as root or with sudo
./install.cirrus.driver.sh
reboot
```
