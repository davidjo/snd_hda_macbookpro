#!/bin/bash

# Prepare the exact Ubuntu HWE sound/hda source for install.cirrus.driver.sh.
set -euo pipefail

kernel_release=${1:?Usage: $0 <kernel-release>}
[[ $kernel_release =~ ^[[:alnum:].+_-]+$ ]] || { echo "Invalid kernel release: $kernel_release" >&2; exit 1; }
kernel_version=${kernel_release%%-*}
major_minor=${kernel_version%.*}
package_version=$(dpkg-query -W -f='${Version}' "linux-image-$kernel_release")
package_core=${package_version%%~*}

ubuntu_codename=$(. /etc/os-release; printf '%s' "${UBUNTU_CODENAME:-${VERSION_CODENAME:-}}")
[[ -n $ubuntu_codename ]] || { echo 'Ubuntu release codename is unavailable' >&2; exit 1; }

source_dir=${CS8409_SOURCE_DIR:-/usr/src}
source_repo=${CS8409_SOURCE_REPO:-/var/cache/snd_hda_macbookpro/linux-ubuntu-$ubuntu_codename}
source_url="https://git.launchpad.net/~ubuntu-kernel/ubuntu/+source/linux/+git/$ubuntu_codename"
archive="$source_dir/linux-source-$kernel_version.tar.bz2"
stamp="$source_dir/.linux-source-$kernel_version.ubuntu-version"

if [[ -f $archive && -f $stamp && $(cat "$stamp") == "$package_version" ]]; then
    echo "Using cached Ubuntu HWE source for $kernel_release ($package_version)"
    exit 0
fi

mkdir -p "$source_dir" "$source_repo"
if [[ ! -d $source_repo/.git ]]; then
    git -C "$source_repo" init -q
    git -C "$source_repo" remote add origin "$source_url"
fi

tag_prefix="Ubuntu-hwe-$major_minor-$package_core"
source_tag="$tag_prefix"
if [[ $package_version == *~* ]]; then
    source_tag="${tag_prefix}_${package_version#*~}"
fi

if ! git -c safe.directory="$source_repo" -C "$source_repo" rev-parse -q --verify "refs/tags/$source_tag" >/dev/null; then
    git -c safe.directory="$source_repo" -C "$source_repo" fetch --depth 1 origin "refs/tags/$source_tag:refs/tags/$source_tag" || {
        echo "No matching Ubuntu source tag for $kernel_release ($package_version)" >&2
        exit 1
    }
fi

temporary_archive=$(mktemp "$source_dir/.linux-source-$kernel_version.XXXXXX")
trap 'rm -f "$temporary_archive"' EXIT
git -c safe.directory="$source_repo" -C "$source_repo" archive --format=tar \
    --prefix="linux-source-$kernel_version/" "$source_tag" sound/hda |
    bzip2 -c > "$temporary_archive"
tar -tjf "$temporary_archive" "linux-source-$kernel_version/sound/hda/codecs/cirrus/cs8409.c" >/dev/null
mv -f "$temporary_archive" "$archive"
printf '%s\n' "$package_version" > "$stamp"
echo "Prepared Ubuntu HWE source $source_tag for $kernel_release"
