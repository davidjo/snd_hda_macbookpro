# snd_hda_macbookpro

Last kernel tested was 4.15.0-54.

This is a working sound system for linux on a Macbook Pro 14,3.
The hardware device sound format is limited to 2/4 channel 44.1 kHz S24_LE S32_LE.
Alsa handles 2 channel input by copying onto node 0x3.
As long as use the default or plughw device volume control, other formats, frequencies work.

NOTA BENE: The direct hardware device (hw:0,0) has NO volume control so will be loud!

Power down/sleep completely unknown and untested.

The hda auto config is force updated to just deal with speaker output, all other nodes disabled.


Some initial coding exists for the Macbook Pro 14,1 with SSM3515 amps - not complete yet.


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

Because the format is fixed at 44.1 kHz, 24 bit (S24_3LE) 4 channel and the format is set by undocumented vendor node
commands its not clear if other formats can be supported in the 8409 itself.
It appears now that Apples set up can take eg S24_LE format and S32_LE format.
