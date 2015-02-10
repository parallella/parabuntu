#!/bin/bash

cd mnt/rootfs

rm -f md5sum.txt

cat << EOF > md5sum.txt
## This file contains the list of md5 checksums of all files on this
## medium.
##
## You can verify them automatically with the 'verify-checksums' boot parameter,
## or, manually with: 'md5sum -c md5sum.txt'.
##
##
EOF
find . -type f -exec md5sum '{}' ';' >> md5sum.txt || echo "$0: Fail" && exit 1
