#!/bin/bash
set -e

rm -rf browndeer &&
cp -r /usr/local/browndeer . &&
cd browndeer/examples &&
make &&
echo Verify results manually &&
exit 0

echo FAIL
exit 1
