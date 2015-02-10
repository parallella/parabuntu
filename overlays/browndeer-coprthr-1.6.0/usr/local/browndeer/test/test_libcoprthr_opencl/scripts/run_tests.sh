#!/bin/bash

run_test() {
	printf "%-68s" "$1 $2 $3"
	$1 --size $2 --blocksize $3 >& /dev/null
	if [ $? -eq 0 ]; then
		printf "%10s\n" "[pass]"
	else 
		printf "%10s\n" "[failed]"
	fi;
}

echo -e "\nRUNNING TESTS ...";

for t in $*; do

run_test ./$t 128 1
run_test ./$t 128 2
run_test ./$t 128 4
run_test ./$t 128 8
run_test ./$t 128 16
run_test ./$t 128 32

run_test ./$t 256 1
run_test ./$t 256 2
run_test ./$t 256 4
run_test ./$t 256 8
run_test ./$t 256 16
run_test ./$t 256 32

run_test ./$t  65536  1
run_test ./$t  65536  2
run_test ./$t  65536  4
run_test ./$t  65536  8
run_test ./$t  65536  16
run_test ./$t  65536  32

run_test ./$t  1048576  1
run_test ./$t  1048576  2
run_test ./$t  1048576  4
run_test ./$t  1048576  8
run_test ./$t  1048576  16
run_test ./$t  1048576  32

done

echo -e "... TESTS COMPLETE.";

