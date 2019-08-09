#!/bin/bash
set -e
set -o pipefail
set -u

script=$(readlink -f "$0")
top=$(dirname "$script")
cd ${top}

. ${top}/settings.inc.sh

if [ $# -ne 2 ]; then
	echo usage: $0 BOOT_TARBALL IMAGE_NAME
	exit 1
fi

boot_dev=

boot_tarball=$1
image_file=$2

if ! [ -f $boot_tarball ]; then
	echo $0: No such file: $boot_tarball
	exit 1
fi

cleanup () {
	echo Cleaning up

	umount ${boot_mnt} || true
	[ x"${boot_dev}" != x ] && losetup -d ${boot_dev}

	sync
}
trap 'cleanup; exit 1' EXIT

echo Creating image file
mkdir -p ${top}/out
rm -f ${image_file} ${image_file}.gz
truncate -s ${image_size}M ${image_file}

echo Creating partition table
fdisk < ${top}/fdisk-cmd.txt ${image_file}

echo Setting up loopback for boot
boot_dev=$(losetup -o ${boot_offset} --sizelimit ${boot_size} -f --show ${image_file})

echo Creating boot filesystem
mkfs.vfat -n BOOT ${boot_dev}

echo Mounting bootfs
mount ${boot_dev} ${boot_mnt}

echo Unpacking boot tarball
tar xf ${boot_tarball} -C ${boot_mnt} --no-same-owner --no-same-permissions --strip-components=2

umount ${boot_mnt}
[ x"${boot_dev}" != x ] && losetup -d ${boot_dev}

echo Copying rootfs image
gunzip -c ${root_image}.gz | dd of=${image_file} seek=$[${root_offset}/512] bs=512

trap - EXIT

echo Compressing image
gzip ${image_file}

echo Wrote image to ${image_file}.gz

sync

echo Done
