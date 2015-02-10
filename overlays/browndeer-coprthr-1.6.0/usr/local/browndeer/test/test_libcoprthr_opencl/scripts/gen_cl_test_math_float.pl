#!/usr/bin/perl
# 
# Copyright (c) 2009-2010 Brown Deer Technology, LLC.  All Rights Reserved.
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

### unary float *(float)
@builtins_unary_f_f = qw(
	acos acosh acospi asin asinh asinpi atan atanh atanpi
	cbrt ceil cos cosh cospi
	erfc erf exp exp2 exp10 expm1
	fabs floor
	lgamma log log2 log10 log1p logb
	rint round rsqrt
	sin sinh sinpi sqrt
);

### unary int *(float)
@builtins_unary_i_f = qw( ilogb );

### binary float *(float,float)
@builtins_binary_f_ff = qw(
	atan2 atan2pi
	copysign
	fdim fmax fmin fmod
	hypot
	nextafter
	pow powr
	remainder
);

### binary float *(float,int)
@builtins_binary_f_fi = qw(
	ldexp pown rootn
);

### trinary float *(float,float,float)
@builtins_trinary_f_fff = qw(
   fma mad
);


foreach $f (@builtins_unary_f_f) {
	printf "\n/* $f */\n";
	printf "__kernel void\n";
	printf "test_math_".$f."_kern(\n";
	printf "\t__global float* a0,\n";
	printf "\t__global float* b0";
	printf ")\n";
	printf "{\n";
	printf "\tuint gtid = get_global_id(0);\n";
	printf "\tfloat tmp0 = a0\[gtid];\n";
	printf "\tb0\[gtid] = $f(tmp0);\n";
	printf "}\n";
}

foreach $f (@builtins_unary_i_f) {
	printf "\n/* $f */\n";
	printf "__kernel void\n";
	printf "test_math_".$f."_kern(\n";
	printf "\t__global float* a0,\n";
	printf "\t__global int* b0";
	printf ")\n";
	printf "{\n";
	printf "\tuint gtid = get_global_id(0);\n";
	printf "\tfloat tmp0 = a0\[gtid];\n";
	printf "\tb0\[gtid] = ".$f."(tmp0);\n";
	printf "}\n";
}

foreach $f (@builtins_binary_f_ff) {
	printf "\n/* $f */\n";
	printf "__kernel void\n";
	printf "test_math_".$f."_kern(\n";
	printf "\t__global float* a0,\n";
	printf "\t__global float* a1,\n";
	printf "\t__global float* b0";
	printf ")\n";
	printf "{\n";
	printf "\tuint gtid = get_global_id(0);\n";
	printf "\tfloat tmp0 = a0\[gtid];\n";
	printf "\tfloat tmp1 = a1\[gtid];\n";
	printf "\tb0\[gtid] = $f(tmp0,tmp1);\n";
	printf "}\n";
}

foreach $f (@builtins_binary_f_fi) {
	printf "\n/* $f */\n";
	printf "__kernel void\n";
	printf "test_math_".$f."_kern(\n";
	printf "\t__global float* a0,\n";
	printf "\t__global int* a1,\n";
	printf "\t__global float* b0";
	printf ")\n";
	printf "{\n";
	printf "\tuint gtid = get_global_id(0);\n";
	printf "\tfloat tmp0 = a0\[gtid];\n";
	printf "\tint tmp1 = a1\[gtid];\n";
	printf "\tb0\[gtid] = $f(tmp0,tmp1);\n";
	printf "}\n";
}

foreach $f (@builtins_trinary_f_fff) {
	printf "\n/* $f */\n";
	printf "__kernel void\n";
	printf "test_math_".$f."_kern(\n";
	printf "\t__global float* a0,\n";
	printf "\t__global float* a1,\n";
	printf "\t__global float* a2,\n";
	printf "\t__global float* b0";
	printf ")\n";
	printf "{\n";
	printf "\tuint gtid = get_global_id(0);\n";
	printf "\tfloat tmp0 = a0\[gtid];\n";
	printf "\tfloat tmp1 = a1\[gtid];\n";
	printf "\tfloat tmp2 = a2\[gtid];\n";
	printf "\tb0\[gtid] = $f(tmp0,tmp1,tmp2);\n";
	printf "}\n";
}

