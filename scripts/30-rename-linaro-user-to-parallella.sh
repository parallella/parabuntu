#!/bin/bash
set -e
set -o pipefail
set -u

[ -d mnt/rootfs/home/parallella ] || mv mnt/rootfs/home/linaro mnt/rootfs/home/parallella
sed -i 's/linaro/parallella/g' mnt/rootfs/etc/{group,shadow,passwd}
