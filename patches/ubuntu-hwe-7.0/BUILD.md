# Building the CS8409 driver for Ubuntu HWE 7.0

## Verified environment

- Hardware: Apple iMac18,2 (2017)
- Audio codec: Cirrus Logic CS8409
- Distribution: Zorin OS 18.1 Education
- Kernel: 7.0.0-42-generic
- Ubuntu source package: linux-hwe-7.0 7.0.0-42.42~24.04.1
- Upstream repository: davidjo/snd_hda_macbookpro
- Base commit: 89b22ff

## Prerequisites

This procedure requires:

- The matching Ubuntu HWE kernel source, including Ubuntu's distribution patches
- Kernel headers for the running kernel
- GCC, make, patch and standard Linux build tools
- The upstream snd_hda_macbookpro repository
- The additional Linux 7.0 compatibility patch included in this directory

The tested kernel source package is:

**linux-hwe-7.0 7.0.0-42.42~24.04.1**

Its source tree must contain `sound/hda/`.

Do not substitute unmodified kernel.org sources. Ubuntu HWE includes distribution-specific changes.

The source package can be obtained through Ubuntu's source-package infrastructure. The exact retrieval and extraction procedure has not yet been independently documented in this guide.

## Obtaining the Ubuntu HWE source

Download the matching Ubuntu source package from Ubuntu's source-package archive.

For the tested kernel, the required files are:

- `linux-hwe-7.0_7.0.0.orig.tar.gz`
- `linux-hwe-7.0_7.0.0-42.42~24.04.1.diff.gz`
- `linux-hwe-7.0_7.0.0-42.42~24.04.1.dsc`

Place all three files in the same directory.

Extract the source package with:

    dpkg-source -x linux-hwe-7.0_7.0.0-42.42~24.04.1.dsc linux-7.0

This extracts the original source and applies the Ubuntu distribution patches.

The resulting source tree should contain:

    linux-7.0/sound/hda/

Use this source tree when following the build instructions below.

The package download URLs and availability have not yet been independently verified.

## Preparing the build directory

Run these commands from the root of the cloned `snd_hda_macbookpro` repository.

Replace `/path/to/ubuntu-kernel-source` with the actual location of the prepared Ubuntu HWE source tree.

    mkdir -p build-hwe

    cp -a /path/to/ubuntu-kernel-source/sound/hda build-hwe/

    cp -a makefiles/. build-hwe/hda/

    cp -a patch_cirrus/*.h build-hwe/hda/codecs/cirrus/

## Applying the patches

Apply the upstream CS8409 patches first:

    patch -d build-hwe/hda -p1 < patch_cs8409.c.diff

    patch -d build-hwe/hda -p1 < patch_cs8409.h.diff

Then apply the additional Linux 7.0 compatibility patch:

    patch -d build-hwe/hda -p1 < patches/ubuntu-hwe-7.0/linux-7.0-cs8409-header.patch

All three patches must apply successfully before building.

## Building the driver

Change to the prepared HDA directory:

    cd build-hwe/hda

Build the kernel modules:

    make -C /lib/modules/$(uname -r)/build M="$PWD" CFLAGS_MODULE="-DAPPLE_PINSENSE_FIXUP -DAPPLE_CODECS -DCONFIG_SND_HDA_RECONFIG=1 -Wno-unused-variable -Wno-unused-function" -j2 modules

The expected CS8409 module is:

    codecs/cirrus/snd-hda-codec-cs8409.ko

## Verifying the build

Inspect the generated module:

    modinfo codecs/cirrus/snd-hda-codec-cs8409.ko

Confirm that its `vermagic` matches the running kernel.

A successful compilation does not, by itself, establish that the driver works on the target hardware.

## Verified results

On an Apple iMac18,2 running Zorin OS 18.1 Education with kernel 7.0.0-42-generic:

- Internal speaker playback works through ALSA.
- Internal speaker playback works through the desktop audio system.
- Audio remains functional after reboot.
- The module can be rebuilt from a clean copy of the matching Ubuntu HWE source.
- The rebuilt module and the previously working module have identical `.text` sections.

The clean rebuild was not independently installed or hardware-tested.

## Limitations

The following have not yet been verified:

- Internal microphone
- Headphone and headset microphone functionality
- Suspend and resume
- Other Apple hardware models
- Future Linux kernel versions
- Automatic DKMS rebuilding

This is a verified configuration for the specified hardware and kernel, not a claim of general Linux 7.x compatibility.

## Installation and recovery

This guide covers **building only**.

It does not install, replace or load kernel modules.

Kernel-module installation can affect system stability. A tested recovery procedure and backup of the original driver are recommended before attempting installation.

The original Linux driver should be preserved.

## Upstream contribution

This compatibility work is based on the Apple CS8409 implementation from:

https://github.com/davidjo/snd_hda_macbookpro

The additional patch restores definitions and declarations required to build against the tested Ubuntu HWE 7.0 source.

The goal is to make this configuration reproducible while preserving compatibility with existing upstream-supported kernels.
