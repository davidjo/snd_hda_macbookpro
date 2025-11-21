#!/bin/bash

# NOTA BENE - this script should be run as root

set -e

while [ $# -gt 0 ]
do
    case $1 in
    -i|--install) dkms_action='install';;
    -k|--kernel) UNAME=$2; [[ -z $UNAME ]] && echo '-k|--kernel must be followed by a kernel version' && exit 1;;
    -r|--remove) dkms_action='remove';;
    -u|--uninstall) dkms_action='remove';;
    (-*) echo "$0: error - unrecognized option $1" 1>&2; exit 1;;
    (*) break;;
    esac
    shift
done

UNAME=${1:-$(uname -r)}
kernel_version=$(echo $UNAME | cut -d '-' -f1)  #ie 5.2.7
major_version=$(echo $kernel_version | cut -d '.' -f1)
minor_version=$(echo $kernel_version | cut -d '.' -f2)
major_minor=${major_version}${minor_version}

revision=$(echo $UNAME | cut -d '.' -f3)
revpart1=$(echo $revision | cut -d '-' -f1)
revpart2=$(echo $revision | cut -d '-' -f2)
revpart3=$(echo $revision | cut -d '-' -f3)

if [ $major_version -lt 6 -o \( $major_version -eq 6 -a $minor_version -lt 17 \) ]; then

	exec ./install.cirrus.driver.pre617.sh "${@}"

fi


if [[ $dkms_action != '' ]]; then
	echo "WARNING: dkms is untested for 6.17 and likely wont work!!!"
	exit 1
fi

sed -i 's/^BUILT_MODULE_NAME\[0\].*$/BUILT_MODULE_NAME[0]="snd-hda-codec-cs8409"/' dkms.conf
PATCH_CIRRUS=false

if [[ $dkms_action == 'install' ]]; then
    bash dkms.sh
    # note that Ubuntu, Debian, Fedora and others (see dkms man page) install to updates/dkms
    # and ignore DEST_MODULE_LOCATION
    # we DO want updates so that the original module is not overwritten
    # (although the original module should be copied to under /var/lib/dkms if needed for other distributions)
    update_dir="/lib/modules/${UNAME}/updates"
    echo -e "\ncontents of $update_dir/dkms"
    ls -lA $update_dir/dkms
    exit
elif [[ $dkms_action == 'remove' ]]; then
    bash dkms.sh -r
    exit
fi

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

# note that the update_dir definition below relies on a symbolic link of /lib to /usr/lib on Arch
cur_dir=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd)
build_dir='build'
patch_dir="$cur_dir/patch_cirrus"
makefiles_dir="$cur_dir/makefiles"
hda_dir="$cur_dir/$build_dir/hda"
update_dir="/lib/modules/${UNAME}/updates"

[[ -d $hda_dir ]] && rm -rf $hda_dir
[[ ! -d $build_dir ]] && mkdir $build_dir

# fedora doesnt seem to install patch by default so need to explicitly install it
if [ $isfedora -ge 1 ]; then
	echo "Ensure the patch package is installed"
	[[ ! $(command -v patch) ]] && dnf install -y patch
fi

# we need to handle Ubuntu based distributions eg Mint here
isubuntu=0
if [ ($(grep '^NAME=' /etc/os-release | grep -c Ubuntu) -eq 1) || ($(grep '^NAME=' /etc/os-release | grep -c "Linux Mint") -eq 1) ]; then
	# Check whether kernel in use is official or not. Official kernels have the word generic in them
	if [[ $(uname -r | grep generic || true) = "" ]]
	then
		isubuntu=0
	else
		isubuntu=1
	fi
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

	tar --strip-components=2 -xvf /usr/src/linux-source-$kernel_version.tar.bz2 --directory=build/ linux-source-$kernel_version/sound/hda

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

		[[ $? -ne 0 ]] && echo "kernel could not be downloaded...exiting" && exit
	fi

	set -e

	tar --strip-components=2 -xvf $build_dir/linux-$kernel_version.tar.xz --directory=build/ linux-$kernel_version/sound/hda

fi


mv $hda_dir/Makefile $hda_dir/Makefile.orig
mv $hda_dir/common/Makefile $hda_dir/common//Makefile.orig
mv $hda_dir/codecs/Makefile $hda_dir/codecs//Makefile.orig
mv $hda_dir/codecs/cirrus/Makefile $hda_dir/codecs/cirrus//Makefile.orig

cp $makefiles_dir/Makefile $hda_dir
cp $makefiles_dir/Makefile_common $hda_dir/common/Makefile
cp $makefiles_dir/Makefile_codecs $hda_dir/codecs/Makefile
cp $makefiles_dir/Makefile_cirrus $hda_dir/codecs/cirrus/Makefile

# going with explicit file names now

cp $patch_dir/cirrus_apple.h $hda_dir/codecs/cirrus
cp $patch_dir/patch_cirrus_boot84.h $hda_dir/codecs/cirrus
cp $patch_dir/patch_cirrus_new84.h $hda_dir/codecs/cirrus
cp $patch_dir/patch_cirrus_real84.h $hda_dir/codecs/cirrus
cp $patch_dir/patch_cirrus_hda_generic_copy.h $hda_dir/codecs/cirrus
cp $patch_dir/patch_cirrus_real84_i2c.h $hda_dir/codecs/cirrus


pushd $hda_dir > /dev/null
# define the ubuntu/mainline versions that work at the moment
# for ubuntu allow a range of revisions that work
current_major=6
current_minor=17
current_minor_ubuntu=6
current_rev_ubuntu=6
latest_rev_ubuntu=6

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

if [ $major_version -eq 6 -a $minor_version -ge 17 ]; then
	if [ $isubuntu -ge 1 ]; then

		patch -b -p1 <../../patch_cs8409.c.diff

		if [ $iscurrent -ge 0 ]; then
			patch -b -p1 <../../patch_cs8409.h.diff
		else
			echo "Error: older version not implmented yet"
                        exit 1
		fi

	else
		patch -b -p1 <../../patch_cs8409.c.diff

		if [ $iscurrent -ge 0 ]; then
			patch -b -p1 <../../patch_cs8409.h.diff
		else
			echo "Error: older version not implmented yet"
                        exit 1
		fi

                # this just redos the above copies - why was it in??
		#cp $patch_dir/Makefile $patch_dir/patch_cirrus_* $hda_dir/

	fi
fi

popd > /dev/null

[[ ! $dkms_action == 'install' ]] && [[ ! -d $update_dir ]] && mkdir $update_dir

make KERNELRELEASE=$UNAME
make install KERNELRELEASE=$UNAME


echo -e "\ncontents of $update_dir"
ls -lA $update_dir
