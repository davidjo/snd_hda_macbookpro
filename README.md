# snd_hda_macbookpro

Last kernel tested was 4.15.0-54.

This is a working sound system for linux on a Macbook Pro 14,3.
The hardware device sound format is limited to 2/4 channel 44.1 kHz S24_LE S32_LE S24_3LE.
Alsa handles 2 channel input by copying onto node 0x3.
As long as use the default (pulse) device volume control, other formats, frequencies work.

NOTA BENE: Both the direct hardware device (hw:0,0) and the plughw:0,0 device have NO volume control so will be loud!

Now updated to allow output to headphones (not all headphones with mike implemented - testing was for
an Apple headset with mike plus no mike headset).
This is a 2 channel output using the 1st 2 channels of the stream if a 4 channel stream is sent.

NOTE that the headphone plugin/unplug events use unsolicited responses which under linux seem to be executed concurrently
with other commands.
I have implemented a blocking system to ensure the response verb blocks are done serially (which seems to be how OSX does this).
I do not know enough about the internals of the linux kernel module to know if there are better ways of doing this.
As these verb blocks last multiseconds using simple linux kernel mutex locks (as done in other parts of the sound module
for single commands) dont seem to be the right approach but I could be wrong.
There are still issues with concurrency to be handled eg if you plugin and quickly start something playing - the play setup
verbs still need to be delayed while the plugin block finishes.
Currently I just physically wait a few seconds after eg plugging in before starting to play.
Plugging while playing and then unplugging while playing is known to work.

Input nodes (internal mike, external mike, linein) now setup as per OSX ie using OSX format.
NOT linked to any actual input streams.
SPDIF not implemented.

Power down/sleep completely unknown and untested.


Macbook Pro 14,1 with SSM3515 amps is now complete but NOT tested at all.
I think I have identified the specific differences for amp setup to 14,3 and these
now implemented in the main boot and play code.


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

