#!/bin/bash
set -e
rm -rf browndeer &&
cp -R /usr/local/browndeer/examples ./browndeer &&
cp -R /usr/local/browndeer/test ./browndeer &&
cd browndeer/test &&
make quicktest &&
echo Test returned ok but you should verify the results manually &&
exit 0

echo FAIL
exit 1
