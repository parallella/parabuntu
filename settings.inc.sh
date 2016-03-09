#!/bin/bash
set -e
set -o pipefail
set -u

mkdir -p ${top}/out

LINARO_URL="http://releases.linaro.org/15.06/ubuntu/vivid-images/nano/linaro-vivid-nano-20150618-705.tar.gz"
LINARO_TARBALL_NAME=linaro-nano.tgz

root_mnt=${top}/mnt/rootfs
boot_mnt=${top}/mnt/boot
root_image=${top}/out/root.image
boot_image=${top}/out/boot.image
linaro_tarball=${top}/${LINARO_TARBALL_NAME}
image_file=${top}/out/image
# Offsets and sizes hardcoded. See fdisk-cmd.txt
image_size=3600
boot_offset=$[2048*512]
boot_size=$[102400*512*2]
root_offset=$[206848*512]
root_size=$[3582976*512*2]
