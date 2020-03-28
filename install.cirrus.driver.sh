#!/bin/bash

kernel_version=$(uname -r | cut -d '-' -f1)  #ie 5.2.7
major_version=$(echo $kernel_version | cut -d '.' -f1)
minor_version=$(echo $kernel_version | cut -d '.' -f2)

build_dir='build'
update_dir="/lib/modules/$(uname -r)/updates"
patch_dir='patch_cirrus'
hda_dir="$build_dir/hda-$kernel_version"

[[ ! -d $update_dir ]] && mkdir $update_dir
[[ ! -d $build_dir ]] && mkdir $build_dir
[[ -d $hda_dir ]] && rm -rf $hda_dir

# attempt to download linux-x.x.x.tar.xz kernel
wget -c https://cdn.kernel.org/pub/linux/kernel/v$major_version.x/linux-$kernel_version.tar.xz -P $build_dir

if [[ $? -ne 0 ]]; then
   # if first attempt fails, attempt to download linux-x.x.tar.xz kernel
   kernel_version=$major_version.$minor_version
   wget -c https://cdn.kernel.org/pub/linux/kernel/v$major_version.x/linux-$kernel_version.tar.xz -P $build_dir
fi

[[ $? -ne 0 ]] && echo "kernel could not be downloaded...exiting" && exit

tar --strip-components=3 -xvf $build_dir/linux-$kernel_version.tar.xz linux-$kernel_version/sound/pci/hda --directory=build/
mv hda $hda_dir
mv $hda_dir/Makefile $hda_dir/Makefile.orig
mv $hda_dir/patch_cirrus.c $hda_dir/patch_cirrus.c.orig
cp $patch_dir/Makefile $patch_dir/patch_cirrus* $hda_dir/
[[ $major_version == '4' ]] && sed -i 's/^#include <sound\/hda_codec.h>$/#include "hda_codec.h"/' $hda_dir/patch_cirrus.c

# if kernel version is >= 5.5 then change
# event = snd_hda_jack_tbl_get_from_tag(codec, tag);
# to
# event = snd_hda_jack_tbl_get_from_tag(codec, tag, 0);
[[ $minor_version -ge '5' ]] && sed -i 's/event = snd_hda_jack_tbl_get_from_tag(codec, tag);/event = snd_hda_jack_tbl_get_from_tag(codec, tag, 0);/' $hda_dir/patch_cirrus.c

cd $hda_dir

make
make install

echo -e "\ncontents of $update_dir"
ls -lA $update_dir
