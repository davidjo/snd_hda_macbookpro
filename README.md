# snd_hda_macbookpro

Raw patch files for experimenting with sound on MacBookPro 14,3 running Ubuntu 18.04.
Last kernel tested was 4.15.0-54.

This gives me sound on a MacBookPro 14,3 if given sound at 44.1 kHz, 24 bit (S24_LE) 2 or 4 channel
(which is the format set by OSX) using aplay.
It is from a log of the hda commands sent by the OSX kernel.
Useful info was taken from kernel bugs 110561 and 195671.

This may work for a MacBookPro 13,2 or 13,3 given the very similar hardware.


This is NOT a working sound system for linux - at the moment it is a simple replay
of the hda commands.

BUGS:
This is a replay of the OSX commands - this means it does not test status returns
- see cs_8409_vendor_i2cRead and cs_8409_vendor_i2cWrite for attempts at code to replace
to the i2cReads, i2cWrites with correct status checks - very untested.

There is no volume control - at the moment the volume is hard coded into the output amplifiers
to be relatively quiet while testing because first tests lead to very loud distorted sound.
(To change see amp register 0x2d setting in lines similar to
 snd_hda_coef_item(codec, 1, CS8409_VENDOR_NID, 0x005d, 0x2d6f, 0x00000000, 7145 ); // i2cWrite  coef write 
 0x6f is low - OSX value is (loud) 0x2d01 cf. low volume 0x2d6f).

Power down/sleep completely unknown and untested.

The hda auto config is force updated to just deal with speaker output, all other nodes disabled.


Comments on what OSX seems to be doing.

The 8409 seems to be acting as a simple digital transformation system for speaker sound.
The incoming bit stream is converted to a TDM digital stream and sent to the amplifiers which
do the actual digital analogue conversion.
No processing is done by the 8409 - no parameters are set on the hda output nodes except that
the output node pins (0x24, 0x25) are set to output.
(The node chain is 0x02 -> 0x24, 0x03 -> 0x25 with 0x02 1st 2 channels, 0x03 2nd 2 channels).
All I2C programming and TDM setup is done via the vendor node 0x47 using coef index/coef proc writes/reads.
The MAX98706 amp programming is consistent with the MAX98372 documentation.
It appears the amps programming is fixed so eg gain control is not done on the amps either.

So I think Apple performs all input processing (conversion, volume etc) at higher CoreAudio levels
which ends up as 44.1 kHz, 24 bit 4 channel audio which is output by the 8409 with no additional processing.


Issues:

Because the format is fixed at 44.1 kHz, 24 bit 4 channel and the format is set by undocumented vendor node
commands its not clear if other formats can be supported in the 8409 itself.
I have little knowledge of Alsa so my assumption is at the moment it does not do software processing and only
hardware processing can be changed which in this case is nothing.
So the Alsa device would have to be set to this fixed format and then eg pulseaudio used to do volume processing etc.
so far I do not know how to set this up.
