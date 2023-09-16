#!/bin/bash

# NOTA BENE - this script should be run as root

path="$(pwd)"
echo "Current path is: $path"

UNAME_V=$(uname -v)

#UNAME_R=$(uname -r)
UNAME_R=$1 # From DKMS

kernel_version=$(echo -n $UNAME_R | cut -d '-' -f1)  #ie 5.2.7

echo "Kernel version $kernel_version (from '$UNAME_R'; '$UNAME_V') on $(uname -r)"

major_version=$(echo $kernel_version | cut -d '.' -f1)
minor_version=$(echo $kernel_version | cut -d '.' -f2)
major_minor=${major_version}${minor_version}

revision=$(echo -n $UNAME_R | cut -d '.' -f3)
revpart1=$(echo $revision | cut -d '-' -f1)
revpart2=$(echo $revision | cut -d '-' -f2)
revpart3=$(echo $revision | cut -d '-' -f3)


isdebian=0
isfedora=0
isarch=0
isvoid=0
if [ -d /usr/src/linux-headers-${UNAME} ]; then
	# Debian Based Distro
	isdebian=1
	:
elif [ -d /usr/src/kernels/${UNAME} ]; then
	# Fedora Based Distro
	isfedora=1
	:
elif [ -d /usr/lib/modules/${UNAME} ]; then
	# Arch Based Distro
	isarch=1
	:
elif [ -d /usr/src/kernel-headers-${UNAME} ]; then
	# Void Linux
	isvoid=1
	:
else
	echo "linux kernel headers not found:"
	echo "Debian (eg Ubuntu): /usr/src/linux-headers-${UNAME}"
	echo "Fedora: /usr/src/kernels/${UNAME}"
	echo "Arch: /usr/lib/modules/${UNAME}"
	echo "Void: /usr/src/kernel-headers-${UNAME}"
	echo "assuming the linux kernel headers package is not installed"
	echo "please install the appropriate linux kernel headers package:"
	echo "Debian/Ubuntu: sudo apt install linux-headers-${UNAME}"
	echo "Fedora: sudo dnf install kernel-headers"
	echo "Arch (also Manjaro): Linux: sudo pacman -S linux-headers"
	echo "Void Linux: xbps-install -S linux-headers"

	exit 1

fi


# note that the udpate_dir definition below relies on a symbolic link of /lib to /usr/lib on Arch

build_dir='build'
update_dir="/lib/modules/${UNAME_R}/updates"
patch_dir='patch_cirrus'
hda_dir="$build_dir/hda-$kernel_version"

[[ ! -d $update_dir ]] && mkdir $update_dir
[[ ! -d $build_dir ]] && mkdir $build_dir
[[ -d $hda_dir ]] && rm -rf $hda_dir

# fedora doesnt seem to install patch by default so need to explicitly install it
if [ $isfedora -ge 1 ]; then
	echo Ensure the patch package is installed
	echo dnf install wget make gcc kernel-devel patch
fi

# we need to handle Ubuntu based distributions eg Mint here
isubuntu=0
if [ `grep '^NAME=' /etc/os-release | grep -c Ubuntu` -eq 1 ]; then
	isubuntu=1
fi
if [  `grep '^NAME=' /etc/os-release | grep -c "Linux Mint"`  -eq 1 ]; then
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

	set +e

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

	set -e

	[[ $? -ne 0 ]] && echo "kernel could not be downloaded...exiting" && exit

	tar --strip-components=3 -xvf $build_dir/linux-$kernel_version.tar.xz --directory=build/ linux-$kernel_version/sound/pci/hda

fi

mv build/hda $hda_dir

mv $hda_dir/Makefile $hda_dir/Makefile.orig

# define the ubuntu/mainline versions that work at the moment
# for ubuntu allow a range of revisions that work
current_major=5
current_minor=19
current_minor_ubuntu=15
current_rev_ubuntu=47
latest_rev_ubuntu=71

iscurrent=0
if [ $isubuntu -ge 1 ]; then
	if [ $major_version -gt $current_major ]; then
		iscurrent=2
	elif [ $major_version -eq $current_major -a $minor_version -gt $current_minor_ubuntu ]; then
		iscurrent=2
	elif [ $major_version -eq $current_major -a $minor_version -eq $current_minor_ubuntu -a $revpart2 -gt $latest_rev_ubuntu ]; then
		iscurrent=2
	elif [ $major_version -eq $current_major -a $minor_version -eq $current_minor_ubuntu -a $revpart2 -gt $current_rev_ubuntu ]; then
		iscurrent=1
	elif [ $major_version -eq $current_major -a $minor_version -eq $current_minor_ubuntu -a $revpart2 -eq $current_rev_ubuntu ]; then
		iscurrent=1
	else
		iscurrent=-1
	fi
else
	if [ $major_version -gt $current_major ]; then
		iscurrent=2
	elif [ $major_version -eq $current_major -a $minor_version -gt $current_minor ]; then
		iscurrent=2
	elif [ $major_version -eq $current_major -a $minor_version -eq $current_minor ]; then
		iscurrent=1
	else
		iscurrent=-1
	fi
fi

if [ $iscurrent -gt 1 ]; then
	echo "Kernel version later than implemented version - there may be build problems"
fi

if [ $major_version -eq 5 -a $minor_version -lt 13 ]; then
	#mv $hda_dir/patch_cirrus.c $hda_dir/patch_cirrus.c.orig
	cd $hda_dir; patch -b -p2 <../../patch_patch_cirrus.c.diff
	cd ../..
	cp $patch_dir/Makefile $patch_dir/patch_cirrus_* $hda_dir/
else
	if [ $isubuntu -ge 1 ]; then

		#mv $hda_dir/patch_cs8409.c $hda_dir/patch_cs8409.c.orig
		#mv $hda_dir/patch_cs8409.h $hda_dir/patch_cs8409.h.orig
		cd $hda_dir; patch -b -p2 <../../patch_patch_cs8409.c.diff
		cd ../..

		if [ $iscurrent -ge 0 ]; then
			cd $hda_dir; patch -b -p2 <../../patch_patch_cs8409.h.diff
			cd ../..
		else
			cd $hda_dir; patch -b -p2 <../../patches/patch_patch_cs8409.h.ubuntu.pre51547.diff
			cd ../..
		fi

		cp $patch_dir/Makefile $patch_dir/patch_cirrus_* $hda_dir/

		if [ $iscurrent -ge 0 ]; then
			cd $hda_dir; patch -b -p2 <../../patch_patch_cirrus_apple.h.diff
			cd ../..
		fi

	else
		#mv $hda_dir/patch_cs8409.c $hda_dir/patch_cs8409.c.orig
		#mv $hda_dir/patch_cs8409.h $hda_dir/patch_cs8409.h.orig
		cd $hda_dir; patch -b -p2 <../../patch_patch_cs8409.c.diff
		cd ../..

		if [ $iscurrent -ge 0 ]; then
			cd $hda_dir; patch -b -p2 <../../patch_patch_cs8409.h.diff
			cd ../..
		else
			cd $hda_dir; patch -b -p2 <../../patches/patch_patch_cs8409.h.main.pre519.diff
			cd ../..
		fi

		cp $patch_dir/Makefile $patch_dir/patch_cirrus_* $hda_dir/

		if [ $iscurrent -ge 0 ]; then
			cd $hda_dir; patch -b -p2 <../../patch_patch_cirrus_apple.h.diff
			cd ../..
		fi

	fi
fi


pushd $hda_dir

if [ $major_version -eq 5 -a $minor_version -lt 13 ]; then

	make PATCH_CIRRUS=1 KVER=$UNAME_R
	output=$hda_dir/snd-hda-codec-cirrus.ko


else

	make KVER=$UNAME_R
	output=$hda_dir/snd-hda-codec-cs8409.ko

fi 

popd

echo "Copying $output to $path"
cp $output $path
