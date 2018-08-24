#!/bin/bash
set -e
set -o pipefail
set -u

mkdir -p ${top}/out

UBUNTU_URL="http://cdimage.ubuntu.com/ubuntu-base/releases/bionic/release/ubuntu-base-18.04.1-base-armhf.tar.gz"
UBUNTU_TARBALL_NAME=ubuntu_base.tgz

root_mnt=${top}/mnt/rootfs
boot_mnt=${top}/mnt/boot
root_image=${top}/out/root.image
boot_image=${top}/out/boot.image
ubuntu_tarball=${top}/${UBUNTU_TARBALL_NAME}
image_file=${top}/out/image
# Offsets and sizes hardcoded. See fdisk-cmd.txt
image_size=3600
boot_offset=$[2048*512]
boot_size=$[102400*512*2]
root_offset=$[206848*512]
root_size=$[3582976*512*2]
