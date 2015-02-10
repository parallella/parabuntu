#!/bin/bash
set -e

# Test for presence of Zynq sysfs temperature sensors

[ -f /sys/bus/iio/devices/iio:device0/in_temp0_raw    ] &&
[ -f /sys/bus/iio/devices/iio:device0/in_temp0_offset ] &&
[ -f /sys/bus/iio/devices/iio:device0/in_temp0_scale  ] &&
echo PASS &&
exit 0

echo FAIL
exit 1


