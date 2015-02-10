#!/bin/bash
set -e

cat << EOF >> mnt/rootfs/home/parallella/.bashrc

# Browndeer COPRTHR
export PATH=/usr/local/browndeer/bin:$PATH
export LD_LIBRARY_PATH=/usr/local/browndeer/lib:$LD_LIBRARY_PATH
export MANPATH=/usr/local/browndeer/man:$MANPATH

EOF

