#!/usr/bin/perl
# 
# Copyright (c) 2009-2012 Brown Deer Technology, LLC.  All Rights Reserved.
#
# This software was developed by Brown Deer Technology, LLC.
# For more information contact info@browndeertechnology.com
#
# This program is free software: you can redistribute it and/or modify it
# under the terms of the GNU Lesser General Public License version 3 (LGPLv3)
# as published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

# DAR #

for($c=0;$c<10;++$c) {
	for($a=1;$a<$c;++$a) {
		$b=$c-$a;
		printf "\n/* $b=$c-$a */\n";
		printf "__kernel void\n";
		printf "test_arg_".$a."_".$b."_kern(\n";
		for($i=0;$i<$a;++$i) {
			printf "\t__global uint* a$i,\n"
		}
		for($j=0;$j<$b;++$j) {
			printf "\t__global uint* b$j";
			if ($j < $b-1) { printf ","; }
			printf "\n";
		}
		printf ")\n";
		printf "{\n";
		printf "\tuint gtid = get_global_id(0);\n";
		for($i=0;$i<$a;++$i) {
			printf "\tuint tmp$i = a$i\[gtid] + $i;\n";
		}
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

