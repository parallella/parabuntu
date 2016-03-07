#!/bin/bash
set -e

mkdir -p mnt/rootfs/home/parallella

# Hackish way to make sure we don't overwrite any files on overlay.
find mnt/rootfs/home/parallella -exec touch '{}' ';'
mv -u mnt/rootfs/home/linaro/* mnt/rootfs/home/parallella/ || true
mv -u mnt/rootfs/home/linaro/.* mnt/rootfs/home/parallella/ || true

if ! rmdir mnt/rootfs/home/linaro; then
	echo "$0: Fail"
	exit 1
fi
