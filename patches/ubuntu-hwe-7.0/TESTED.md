# CS8409 Apple iMac18,2 – Ubuntu HWE 7.0 compatibility

## Tested hardware
- Apple iMac18,2 (2017)
- Cirrus Logic CS8409
- PCI subsystem ID: 0x106b0f00

## Tested software
- Zorin OS 18.1 Education
- Kernel: 7.0.0-42-generic
- Ubuntu source package: linux-hwe-7.0 7.0.0-42.42~24.04.1
- Upstream repository: davidjo/snd_hda_macbookpro
- Base commit: 89b22ff

## Verified results
- Internal speakers work through ALSA.
- Internal speakers work through the desktop audio system.
- Audio continues working after reboot.
- Driver rebuild succeeds from clean Ubuntu HWE sources.
- Rebuilt and working modules have identical .text sections.

## Not yet verified
- Internal microphone
- Headphone jack and headset microphone
- Suspend/resume
- Other Apple hardware models
- Future kernel versions

## Compatibility changes
The existing upstream CS8409 patches were applied to the Ubuntu HWE
source tree, followed by linux-7.0-cs8409-header.patch.

The compatibility patch restores definitions and declarations needed
by the Ubuntu HWE 7.0 CS8409 implementation.

This is a tested configuration, not a claim of general Linux 7.x support.
