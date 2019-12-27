snd-hda-codec-cirrus-objs :=	patch_cirrus.o
obj-$(CONFIG_SND_HDA_CODEC_CIRRUS) += snd-hda-codec-cirrus.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) clean

install:
	cp snd-hda-codec-cirrus.ko /lib/modules/$(shell uname -r)/updates/snd-hda-codec-cirrus.ko
	depmod -a
