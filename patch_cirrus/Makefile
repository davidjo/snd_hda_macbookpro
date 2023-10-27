ifdef PATCH_CIRRUS
snd-hda-codec-cirrus-objs :=	patch_cirrus.o
obj-$(CONFIG_SND_HDA_CODEC_CIRRUS) += snd-hda-codec-cirrus.o
else
snd-hda-codec-cs8409-objs :=    patch_cs8409.o patch_cs8409-tables.o
obj-$(CONFIG_SND_HDA_CODEC_CS8409) += snd-hda-codec-cs8409.o
endif
