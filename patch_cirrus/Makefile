ifdef PATCH_CIRRUS
snd-hda-codec-cirrus-objs :=	patch_cirrus.o
obj-$(CONFIG_SND_HDA_CODEC_CIRRUS) += snd-hda-codec-cirrus.o
else
snd-hda-codec-cs8409-objs :=    patch_cs8409.o patch_cs8409-tables.o
obj-$(CONFIG_SND_HDA_CODEC_CS8409) += snd-hda-codec-cs8409.o
endif


# debug build flags
#KBUILD_EXTRA_CFLAGS = "-DCONFIG_SND_DEBUG=1 -DMYSOUNDDEBUGFULL -DAPPLE_PINSENSE_FIXUP -DAPPLE_CODECS -DCONFIG_SND_HDA_RECONFIG=1 -Wno-unused-variable -Wno-unused-function"
# normal build flags
KBUILD_EXTRA_CFLAGS = "-DAPPLE_PINSENSE_FIXUP -DAPPLE_CODECS -DCONFIG_SND_HDA_RECONFIG=1 -Wno-unused-variable -Wno-unused-function"


ifdef KVER
KDIR := /lib/modules/$(KVER)
else
KDIR := /lib/modules/$(shell uname -r)
endif

all:
	make -C $(KDIR)/build CFLAGS_MODULE=$(KBUILD_EXTRA_CFLAGS) M=$(shell pwd) modules
clean:
	make -C $(KDIR)/build M=$(shell pwd) clean

install:
ifdef PATCH_CIRRUS
	#cp snd-hda-codec-cirrus.ko $(KDIR)/updates
	make INSTALL_MOD_DIR=updates -C $(KDIR)/build M=$(shell pwd) CONFIG_MODULE_SIG_ALL=n modules_install
else
	#cp snd-hda-codec-cs8409.ko $(KDIR)/updates
	make INSTALL_MOD_DIR=updates -C $(KDIR)/build M=$(shell pwd) CONFIG_MODULE_SIG_ALL=n modules_install
endif
	depmod -a
