# debug build flags
#KBUILD_EXTRA_CFLAGS = "-DCONFIG_SND_DEBUG=1 -DMYSOUNDDEBUGFULL -DAPPLE_PINSENSE_FIXUP -DAPPLE_CODECS -DCONFIG_SND_HDA_RECONFIG=1 -Wno-unused-variable -Wno-unused-function"
# normal build flags
KBUILD_EXTRA_CFLAGS = "-DAPPLE_PINSENSE_FIXUP -DAPPLE_CODECS -DCONFIG_SND_HDA_RECONFIG=1 -Wno-unused-variable -Wno-unused-function"


ifdef KERNELRELEASE
	KERNELDIR := /lib/modules/$(KERNELRELEASE)
else
	KERNELDIR := /lib/modules/$(shell uname -r)
endif

KERNELBUILD := $(KERNELDIR)/build

all:
	make -C $(KERNELBUILD) CFLAGS_MODULE=$(KBUILD_EXTRA_CFLAGS) M=$(shell pwd)/build/hda modules

clean:
	make -C $(KERNELBUILD) M=$(shell pwd)/build/hda clean

install:
	make INSTALL_MOD_DIR=updates -C $(KERNELBUILD) M=$(shell pwd)/build/hda CONFIG_MODULE_SIG_ALL=n modules_install
	depmod -a
