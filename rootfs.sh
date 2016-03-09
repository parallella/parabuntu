#!/bin/bash
set -e
set -o pipefail
set -u

script=$(readlink -f "$0")
top=$(dirname "$script")
cd ${top}

. ${top}/settings.inc.sh

if [ $# -ne 1 ]; then
	echo usage: $0 ESDK_PATH
	exit 1
fi

esdk_path=$(echo $1 | sed s,/*$,,g) # strip trailing /
esdk_name=$(basename ${esdk_path})
if ! [ -d ${esdk_path} ]; then
	echo $0: Not a directory: ${esdk_path}
	exit 1
fi

root_dev=

cleanup () {
	echo Cleaning up
	rm -f ${root_mnt}/usr/sbin/policy-rc.d
	rm -f ${root_mnt}/etc/resolv.conf
	rm -f ${root_mnt}/qemu-arm-static
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

unset LC_TIME
export LC_ALL="en_US.UTF-8"

if ! [ -e ${linaro_tarball} ]; then
	echo Downloading linaro tarball
	wget ${LINARO_URL} -O ${linaro_tarball}
fi

echo Checking md5sums
if ! md5sum -c md5sum.txt; then
	echo md5sum fail
	exit 1
fi

echo Removing old files
rm -rf ${top}/out/*

echo Creating rootfs image file
mkdir -p ${top}/out
# TODO: Can we create a sparse file instead?
dd if=/dev/zero of=${root_image} bs=1024 count=$[${root_size}/1024]

echo Setting up loopback
root_dev=$(losetup -o 0 --sizelimit ${root_size} -f --show ${root_image})

echo Creating filesystems
mkfs.ext4 -L root ${root_dev}

echo Mounting root filesystem
mount ${root_dev} ${root_mnt}

echo Unpacking linaro tarball
tar xfzp ${linaro_tarball} -C ${root_mnt} --strip-components 1

echo Applying overlays
#TODO: Use tarballs (for owner/group)?
for d in $(ls ${top}/overlays | sort -g); do
	echo Applying overlay $d
	rsync -ap --no-owner --no-group ${top}/overlays/$d/ ${root_mnt}
done

echo Copying ESDK to rootfs
mkdir -p ${root_mnt}/opt/adapteva
rsync -ap --no-owner --no-group ${esdk_path} ${root_mnt}/opt/adapteva/
if [ ${esdk_name} != "esdk" ]; then
	echo Symlinking esdk to ${esdk_name}
	(cd ${root_mnt}/opt/adapteva && ln -s ${esdk_name} esdk || exit 1)
fi

find ${root_mnt} -name ".gitkeep" -delete

echo Running scripts
for s in $(ls ${top}/scripts | sort -g); do
	echo Running $s
	${top}/scripts/$s
done


echo Preparing ARM qemu bootstrap

echo Bind mounting proc sys and pts in chroot
mount --bind /proc    ${root_mnt}/proc
mount --bind /sys     ${root_mnt}/sys
mount --bind /dev/pts ${root_mnt}/dev/pts

echo Mounting tmp in chroot
mount none -t tmpfs -o size=104857600 ${root_mnt}/tmp

echo Copying qemu-arm-static
cp $(which qemu-arm-static) ${root_mnt}

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

echo Copying arm bootstrap files
cp ${top}/rootfs-arm.sh ${root_mnt}/tmp
cp -r packages.basic.txt ${root_mnt}/tmp

echo Copying tests
#TODO: Move to Parallella overlay?
cp -r tests ${root_mnt}/home/parallella/

echo Starting ARM chroot
chroot ${root_mnt} ./tmp/rootfs-arm.sh
#chroot ${root_mnt}

cleanup
trap - EXIT

echo Done
