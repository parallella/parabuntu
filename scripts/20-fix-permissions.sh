#!/bin/bash

set -e

fix_permissions () {
    chmod u+s mnt/rootfs/bin/ping &&
    chmod u+s mnt/rootfs/bin/ping6

    chown root:root mnt/rootfs/etc/{group,shadow,passwd}
    chmod 640 mnt/rootfs/etc/shadow
}

fix_permissions || echo "$0: Fail" && exit 1



