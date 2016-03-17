#!/bin/bash
set -e
set -o pipefail
set -u

cd mnt/rootfs/home/parallella
git clone https://github.com/adapteva/epiphany-examples.git --branch 2016.3
git clone https://github.com/parallella/parallella-examples.git
