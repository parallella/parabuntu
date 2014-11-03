#!/bin/bash
set -e

make clean &&
make &&
mpirun ./hello &&
echo PASS &&
exit 0

echo FAIL
exit 1
