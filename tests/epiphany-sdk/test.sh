#!/bin/bash
set -e

rm -rf epiphany-examples &&
git clone https://github.com/adapteva/epiphany-examples.git --branch 2016.11 &&
cd epiphany-examples &&
./scripts/build_and_test_all.sh &&
echo Verify results manually &&
exit 0

echo FAIL
exit 1
