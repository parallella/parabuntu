#!/bin/bash
set -e
set -o pipefail
set -u

script=$(readlink -f "$0")
top=$(dirname "$script")
cd ${top}

. ${top}/settings.inc.sh

if [ $# -ne 1 ]; then
	echo usage: $0 ESDK_TARBALL
	exit 1
fi

esdk_tarball="$1"
esdk_name=$(echo $esdk_tarball | sed -e 's/\.t[a]\?[r]\?[.]\?[bgx]z[2]\?$//g' |
	xargs basename)
if ! [ -f ${esdk_tarball} ]; then
	echo $0: Not a file: ${esdk_tarball}
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

unset LC_ALL
unset LC_TIME

if ! [ -e ${linaro_tarball} ]; then
	echo Downloading linaro tarball
	wget ${LINARO_URL} -O ${linaro_tarball}
fi

echo Checking md5sums
if ! md5sum -c md5sum.txt; then
	echo md5sum fail
	exit 1
fi

echo Removing old rootfs image
rm -rf ${root_image}

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

echo Renaming linaro user to parallella
[ -d ${top}/mnt/rootfs/home/parallella ] || mv ${top}/mnt/rootfs/home/linaro ${top}/mnt/rootfs/home/parallella
sed -i 's/linaro/parallella/g' ${top}/mnt/rootfs/etc/{group,shadow,passwd}

echo Applying overlays
#TODO: Use tarballs (for owner/group)?
for d in $(ls ${top}/overlays | sort -g); do
	echo Applying overlay $d
	rsync -ap --no-owner --no-group ${top}/overlays/$d/ ${root_mnt}
done
find ${root_mnt} -name ".gitkeep" -delete

echo Extracting ESDK tarball to rootfs
mkdir -p ${root_mnt}/opt/adapteva
tar xf ${esdk_tarball} -C ${root_mnt}/opt/adapteva
chown -R root:root ${root_mnt}/opt/adapteva
if [ ${esdk_name} != "esdk" ]; then
	echo Symlinking esdk to ${esdk_name}
	(cd ${root_mnt}/opt/adapteva && rm -f esdk && ln -s ${esdk_name} esdk || exit 1)
fi

echo Copying kernel modules to rootfs
rsync -ap --no-owner --no-group  modules/ ${top}/mnt/rootfs/
echo Improving module source+build symlinks
(
	for d in ${top}/mnt/rootfs/lib/modules/*; do
		cd $d &&
		rm -f source build &&
		ln -sf /usr/src/parallella-linux source &&
		ln -sf /usr/src/parallella-linux build ||
		exit 1
	done
)

echo Copying kernel headers to rootfs
rsync -ap --no-owner --no-group  headers/ ${top}/mnt/rootfs/usr/

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
