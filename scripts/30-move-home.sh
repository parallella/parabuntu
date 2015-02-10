#!/bin/bash
set -e

mv mnt/rootfs/home/{linaro,parallella} || echo "$0: Fail" && exit 1

