#!/bin/bash
set -e
set -o pipefail
set -u

LINARO_URL="http://releases.linaro.org/15.06/ubuntu/vivid-images/nano/linaro-vivid-nano-20150618-705.tar.gz"
LINARO_TARBALL_NAME=linaro-nano.tgz

cleanup () {
	echo Cleaning up
	rm -f ${rootmnt}/usr/sbin/policy-rc.d
	rm -f ${rootmnt}/etc/resolv.conf
	rm -f ${rootmnt}/qemu-arm-static
	umount ${rootmnt}/proc || true
	umount ${rootmnt}/sys || true
	umount ${rootmnt}/tmp || true
	umount ${rootmnt}/dev/pts || true
	umount ${rootmnt} || true
	#umount ${bootmnt} || true
	sync

	zerofree -v ${rootdev} || true

	sync

	[ x"${bootdev}" != x ] && losetup -d ${bootdev}
	[ x"${rootdev}" != x ] && losetup -d ${rootdev}
}

script=$(readlink -f "$0")
top=$(dirname "$script")
rootmnt=${top}/mnt/rootfs
bootmnt=${top}/mnt/boot
bootdev=
rootdev=
linaro_tarball=${top}/${LINARO_TARBALL_NAME}
image_size=3600
image_file=${top}/out/image

trap 'cleanup' EXIT

cd $top

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
rm -rf ${top}/out

echo Creating image file
mkdir ${top}/out
dd if=/dev/zero of=${image_file} bs=1M count=${image_size}

echo Creating partition table
fdisk < ${top}/fdisk-cmd.txt ${image_file}

echo Setting up loopback
# Offset and size hardcoded. See fdisk-cmd.txt
bootdev=$(losetup -o $[2048*512]   --sizelimit $[102400*512*2]  -f --show ${image_file})
rootdev=$(losetup -o $[206848*512] --sizelimit $[3582976*512*2] -f --show ${image_file})

echo Creating filesystems
mkfs.vfat -n BOOT   ${bootdev}
mkfs.ext4 -L rootfs ${rootdev}

echo Mounting filesystems
# Wait w/ bootfs. Many combos
mount ${rootdev} ${rootmnt}
#umount ${bootmnt}

echo Unpacking linaro tarball
tar xfzp ${linaro_tarball} -C ${rootmnt} --strip-components 1

echo Applying overlays
#TODO: Use tarballs (for owner/group)?
for d in $(ls ${top}/overlays | sort -g); do
	echo Applying overlay $d
	rsync -ap --no-owner --no-group ${top}/overlays/$d/ ${rootmnt}
done

find ${rootmnt} -name ".gitkeep" -delete

echo Running scripts
for s in $(ls ${top}/scripts | sort -g); do
	echo Running $s
	${top}/scripts/$s
done


echo Preparing ARM qemu bootstrap

echo Bind mounting proc sys and pts in chroot
mount --bind /proc    ${rootmnt}/proc
mount --bind /sys     ${rootmnt}/sys
mount --bind /dev/pts ${rootmnt}/dev/pts

echo Mounting tmp in chroot
mount none -t tmpfs -o size=104857600 ${rootmnt}/tmp

echo Copying qemu-arm-static
cp $(which qemu-arm-static) ${rootmnt}

echo Creating resolv.conf
cat << EOF > ${rootmnt}/etc/resolv.conf
nameserver 8.8.8.8
nameserver 8.8.4.4
EOF

echo Configuring chroot apt to not start/restart services
#https://wiki.debian.org/chroot
cat > ${rootmnt}/usr/sbin/policy-rc.d <<EOF
#!/bin/sh
exit 101
EOF
chmod a+x ${rootmnt}/usr/sbin/policy-rc.d


# Assume ischroot works
# See: https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=685034

echo Copying arm bootstrap files
cp ${top}/run-arm.sh ${rootmnt}/tmp
cp -r packages.basic.txt ${rootmnt}/tmp

echo Copying tests
#TODO: Move to Parallella overlay?
cp -r tests ${rootmnt}/home/parallella/

echo Starting ARM chroot
chroot ${rootmnt} ./tmp/run-arm.sh
#chroot ${rootmnt}

echo Done
