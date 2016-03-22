#!/bin/bash
dir=$(dirname $(grep -rl xadc /sys/bus/iio/devices/*/name))
raw_file=${dir}/in_temp0_raw
offset_file=${dir}/in_temp0_offset
scale_file=${dir}/in_temp0_scale

raw=`cat ${raw_file}`
offset=`cat ${offset_file}`
scale=`cat ${scale_file}`

c_temp=`echo "scale=1;(($raw + $offset) * $scale) / 1000" | bc`
f_temp=`echo "scale=1;(($c_temp * 9) / 5) + 32" | bc`

echo "Zynq Temp: $c_temp C / $f_temp F"
