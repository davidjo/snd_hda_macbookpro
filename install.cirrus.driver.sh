#!/bin/bash

# NOTA BENE - this script should be run as root

kernel_version=$(uname -r | cut -d '-' -f1)  #ie 5.2.7
major_version=$(echo $kernel_version | cut -d '.' -f1)
minor_version=$(echo $kernel_version | cut -d '.' -f2)
major_minor=${major_version}${minor_version}

revision=$(uname -r | cut -d '.' -f3)
revpart1=$(echo $revision | cut -d '-' -f1)
revpart2=$(echo $revision | cut -d '-' -f2)
revpart3=$(echo $revision | cut -d '-' -f3)


if [ $major_version == '4' ]; then
	echo "Kernel 4 versions no longer supported"
fi

if [ $major_version -eq 5 -a $minor_version -lt 8 ]; then
	echo "Kernel 5 versions less than 5.8 no longer supported"
fi


isdebian=0
isfedora=0
isarch=0
isvoid=0
if [ -d /usr/src/linux-headers-$(uname -r) ]; then
	# Debian Based Distro
	isdebian=1
	:
elif [ -d /usr/src/kernels/$(uname -r) ]; then
	# Fedora Based Distro
	isfedora=1
	:
elif [ -d /usr/lib/modules/$(uname -r) ]; then
	# Arch Based Distro
	isarch=1
	:
elif [ -d /usr/src/kernel-headers-$(uname -r) ]; then
	# Void Linux
	isvoid=1
	:
else
	echo "linux kernel headers not found:"
	echo "Debian (eg Ubuntu): /usr/src/linux-headers-$(uname -r)"
	echo "Fedora: /usr/src/kernels/$(uname -r)"
	echo "Arch: /usr/lib/modules/$(uname -r)"
	echo "Void: /usr/src/kernel-headers-$(uname -r)"
	echo "assuming the linux kernel headers package is not installed"
	echo "please install the appropriate linux kernel headers package:"
	echo "Debian/Ubuntu: sudo apt install linux-headers-$(uname -r)"
	echo "Fedora: sudo dnf install kernel-headers"
	echo "Arch (also Manjaro): Linux: sudo pacman -S linux-headers"
	echo "Void Linux: xbps-install -S linux-headers"

	exit 1

fi


# note that the udpate_dir definition below relies on a symbolic of /lib to /usr/lib on Arch

build_dir='build'
update_dir="/lib/modules/$(uname -r)/updates"
patch_dir='patch_cirrus'
hda_dir="$build_dir/hda-$kernel_version"

[[ ! -d $update_dir ]] && mkdir $update_dir
[[ ! -d $build_dir ]] && mkdir $build_dir
[[ -d $hda_dir ]] && rm -rf $hda_dir


# we need to handle Ubuntu based distributions eg Mint here
isubuntu=0
if [ `grep '^NAME=' /etc/os-release | grep -c Ubuntu` -eq 1 ]; then
	isubuntu=1
fi

if [ $isubuntu -ge 1 ]; then

	# NOTE for Ubuntu we need to use the distribution kernel sources as they seem
	# to be significantly modified from the mainline kernel sources generally with backports from later kernels
	# (so far the actual debian kernels seem to be close to mainline kernels)

	# NOTA BENE this will likely NOT work for Ubuntu hwe kernels which are even more highly
        #           modified with extensive backports from later kernel versions
        #           (and in any case there is no linux-source-... package for hwe kernels)

	if [ ! -e /usr/src/linux-source-$kernel_version.tar.bz2 ]; then

		echo "Ubuntu linux kernel source not found in /usr/src: /usr/src/linux-source-$kernel_version.tar.bz2"
		echo "assuming the linux kernel source package is not installed"
		echo "please install the linux kernel source package:"
		echo "sudo apt install linux-source-$kernel_version"
		echo "NOTE - This does not work for HWE kernels"

		exit 1

	fi

	tar --strip-components=3 -xvf /usr/src/linux-source-$kernel_version.tar.bz2 --directory=build/ linux-source-$kernel_version/sound/pci/hda

else

	# here we assume the distribution kernel source is essentially the mainline kernel source

	# attempt to download linux-x.x.x.tar.xz kernel
	wget -c https://cdn.kernel.org/pub/linux/kernel/v$major_version.x/linux-$kernel_version.tar.xz -P $build_dir

	if [[ $? -ne 0 ]]; then
		echo "Failed to download linux-$kernel_version.tar.xz"
		echo "Trying to download base kernel version linux-$major_version.$minor_version.tar.xz"
		echo "This may lead to build failures as too old"
		echo "If this is an Ubuntu-based distribution this almost certainly will fail to build"
		echo ""
   		# if first attempt fails, attempt to download linux-x.x.tar.xz kernel
   		kernel_version=$major_version.$minor_version
   		wget -c https://cdn.kernel.org/pub/linux/kernel/v$major_version.x/linux-$kernel_version.tar.xz -P $build_dir
	fi

	[[ $? -ne 0 ]] && echo "kernel could not be downloaded...exiting" && exit

	tar --strip-components=3 -xvf $build_dir/linux-$kernel_version.tar.xz --directory=build/ linux-$kernel_version/sound/pci/hda

fi

mv build/hda $hda_dir

mv $hda_dir/Makefile $hda_dir/Makefile.orig
if [ $major_version -eq 5 -a $minor_version -lt 13 ]; then
	#mv $hda_dir/patch_cirrus.c $hda_dir/patch_cirrus.c.orig
	cd $hda_dir; patch -b -p2 <../../patch_patch_cirrus.c.diff
	cd ../..
	cp $patch_dir/Makefile $patch_dir/patch_cirrus_* $hda_dir/
else
	#mv $hda_dir/patch_cs8409.c $hda_dir/patch_cs8409.c.orig
	#mv $hda_dir/patch_cs8409.h $hda_dir/patch_cs8409.h.orig
	cd $hda_dir; patch -b -p2 <../../patch_patch_cs8409.c.diff
	cd ../..
	cd $hda_dir; patch -b -p2 <../../patch_patch_cs8409.h.diff
	cd ../..
	cp $patch_dir/Makefile $patch_dir/patch_cirrus_* $hda_dir/
fi


cd $hda_dir


if [ $major_version -eq 5 -a $minor_version -lt 13 ]; then

	make PATCH_CIRRUS=1

	make install PATCH_CIRRUS=1

else

	make

	make install

fi

echo -e "\ncontents of $update_dir"
ls -lA $update_dir
