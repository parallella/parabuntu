#!/usr/bin/perl

for($c=0;$c<10;++$c) {
	for($a=1;$a<$c;++$a) {
		$b=$c-$a;
		printf "\n/* $b=$c-$a */\n";
		printf "__kernel void\n";
		printf "test_fa1_".$a."_".$b."_kern(\n";
		for($i=0;$i<$a;++$i) {
			printf "\t__global int* a$i,\n"
		}
		for($j=0;$j<$b;++$j) {
			printf "\t__global int* b$j";
			if ($j < $b-1) { printf ","; }
			printf "\n";
		}
		printf ")\n";
		printf "{\n";
		printf "\tuint gtid = get_global_id(0);\n";
		for($i=0;$i<$a;++$i) {
			printf "\tint tmp$i = a$i\[gtid] + $i;\n";
		}
		printf "barrier(CLK_LOCAL_MEM_FENCE);";
		for($j=0;$j<$b;++$j) {
			printf "\tb$j\[gtid] = ($j+1)*(";
			for($i=0;$i<$a;++$i) {
				for($i=0;$i<$a;++$i) {
					printf "+";
					printf "tmp$i"
				}
			}
			printf ");\n"
		}
		printf "}\n";
	} 
}

