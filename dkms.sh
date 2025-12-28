#!/bin/bash

src_dir='/usr/src/snd_hda_macbookpro-0.1'
module_name='snd-hda-codec-cs8409'
dkms_name='snd_hda_macbookpro/0.1'
var_dkms_dir='/var/lib/dkms/snd_hda_macbookpro'
cur_dir=$(cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd)

# specify uninstall with the -r or -u argument
while getopts :ru arg
do
    case "${arg}" in
        r) dkms_remove=true;;
        u) dkms_remove=true;;
    esac
done

if [[ $dkms_remove = true ]]; then

    # we need this to ensure the original kernel module is restored
    # before we remove the whole /var/lib/dkms/snd_hda_macbookpro directory tree below
    # (which we dont need to do if we do the dkms remove)
    dkms remove $dkms_name

    # we dont need this if we do the above - the whole dkms module tree is removed by the above command
    # (in addition to restoring the original module)
    #[[ -e $var_dkms_dir ]] && rm -rf $var_dkms_dir && echo "removed $var_dkms_dir"

    # we do need to remove the symbolic link created manually below
    [[ -e $src_dir ]] && rm -f $src_dir && echo "removed $src_dir"

    exit 0
fi

pushd $cur_dir > /dev/null

# create the symbolic link for source dkms seems to require
[[ ! -e $src_dir ]] && ln -sfn $cur_dir $src_dir

# note that this will store the original base kernel module under  /var/lib/dkms
# and needs dkms remove to be called to restore that original module back to the base kernel modules
dkms install -c dkms.conf --force -m $dkms_name

popd > /dev/null
