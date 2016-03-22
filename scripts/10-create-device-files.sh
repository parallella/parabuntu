#!/bin/bash

set -e

rm_and_mknod () {
    rm -f $3 && mknod $@
}

create_devices () {
    rm_and_mknod -m 660 mnt/rootfs/dev/mmcblk0 b 179 0 &&
    rm_and_mknod -m 660 mnt/rootfs/dev/mmcblk0p1 b 179 1 &&
    rm_and_mknod -m 660 mnt/rootfs/dev/mmcblk0p2 b 179 2
}

if ! create_devices; then
	echo "$0: Fail"
	exit 1
fi
