#!/bin/bash
# Script intended for chrooting into rootfs and fixing minor issues.
# instead of rerunning rootfs-arm.sh which takes a long time to run.
set -e
set -o pipefail
set -u

script=$(readlink -f "$0")
top=$(dirname "$script")
cd ${top}

. ${top}/settings.inc.sh

root_dev=

cleanup () {
	echo Cleaning up
	rm -f ${root_mnt}/usr/sbin/policy-rc.d
	rm -f ${root_mnt}/etc/resolv.conf
	rm -f ${root_mnt}/usr/bin/qemu-arm-static
	umount ${root_mnt}/proc || true
	umount ${root_mnt}/sys || true
	umount ${root_mnt}/tmp || true
	umount ${root_mnt}/dev/pts || true
	umount ${root_mnt} || true
	sync

	zerofree -v ${root_dev} || true

	sync

	[ x"${root_dev}" != x ] && losetup -d ${root_dev}
}

trap 'cleanup; exit 1' EXIT

unset LC_ALL
unset LC_TIME
export LC_ALL=C

if [ -f ${root_image}.gz ]; then
	echo Unpacking rootfs
	gunzip ${root_image}.gz
fi

if ! [ -f ${root_image} ]; then
	echo "No root image found ${root_image}"
	exit 1
fi

echo Setting up loopback
root_dev=$(losetup -o 0 --sizelimit ${root_size} -f --show ${root_image})

echo Mounting root filesystem
mount ${root_dev} ${root_mnt}

echo Preparing ARM qemu bootstrap

echo Bind mounting proc sys and pts in chroot
mount --bind /proc    ${root_mnt}/proc
mount --bind /sys     ${root_mnt}/sys
mount --bind /dev/pts ${root_mnt}/dev/pts

echo Mounting tmp in chroot
mount none -t tmpfs -o size=104857600 ${root_mnt}/tmp

echo Copying qemu-arm-static
cp $(which qemu-arm-static) ${root_mnt}/usr/bin/

echo Creating resolv.conf
cat << EOF > ${root_mnt}/etc/resolv.conf
nameserver 8.8.8.8
nameserver 8.8.4.4
EOF


echo Configuring chroot apt to not start/restart services
#https://wiki.debian.org/chroot
cat > ${root_mnt}/usr/sbin/policy-rc.d <<EOF
#!/bin/sh
exit 101
EOF
chmod a+x ${root_mnt}/usr/sbin/policy-rc.d

# Assume ischroot works
# See: https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=685034

echo Starting ARM chroot
#chroot ${root_mnt} ./tmp/rootfs-arm.sh
chroot ${root_mnt} || true

cleanup
trap - EXIT

echo Compressing root image
gzip ${root_image}

echo Done
