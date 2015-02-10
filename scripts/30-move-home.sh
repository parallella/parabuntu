#!/bin/bash
set -e

mkdir -p mnt/rootfs/home/parallella || echo "$0: Fail" && exit 1

# Hackish way to make sure we don't overwrite any files on overlay.
find mnt/rootfs/home/parallella -exec touch '{}' ';'
mv -u mnt/rootfs/home/linaro/* mnt/rootfs/home/parallella/ || echo "$0: Fail" && exit 1
mv -u mnt/rootfs/home/linaro/.* mnt/rootfs/home/parallella/ || echo "$0: Fail" && exit 1

rmdir mnt/rootfs/home/linaro || echo "$0: Fail" && exit 1

