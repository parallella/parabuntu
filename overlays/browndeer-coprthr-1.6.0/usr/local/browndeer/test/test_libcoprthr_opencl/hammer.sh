#!/bin/sh

for((i=0;$i<1000;i++))
do
./test_arg_int.x --size 128 --blocksize 4
done

