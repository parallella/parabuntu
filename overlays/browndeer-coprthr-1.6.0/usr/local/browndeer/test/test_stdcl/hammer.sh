#!/bin/sh

for((i=0;$i<100000;i++))
do
./getndev.x --gpu
done

