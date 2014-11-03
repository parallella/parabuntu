#!/bin/bash

set -e

fix_permissions () {
    chmod u+s mnt/rootfs/bin/ping &&
    chmod u+s mnt/rootfs/bin/ping6
}

fix_permissions || echo "$0: Fail" && exit 1



