
#include <stdcl.h>

/* 1=2-1 */
__kernel void
test_arg_1_1_kern(
	__global int2* a0,
	__global int2* b0
)
{
	int2 za = __builtin_vector_int2(2,3);
	uint gtid = get_global_id(0);
	int2 tmp0 = a0[gtid] + 0 + za;
	b0[gtid] = (0+1)*(+tmp0);
}

/* 2=3-1 */
__kernel void
test_arg_1_2_kern(
	__global int2* a0,
	__global int2* b0,
	__global int2* b1
)
{
	int2 za = __builtin_vector_int2(2,3);
	uint gtid = get_global_id(0);
	int2 tmp0 = a0[gtid] + 0 + za;
	b0[gtid] = (0+1)*(+tmp0);
	b1[gtid] = (1+1)*(+tmp0);
}

/* 1=3-2 */
__kernel void
test_arg_2_1_kern(
	__global int2* a0,
	__global int2* a1,
	__global int2* b0
)
{
	int2 za = __builtin_vector_int2(2,3);
	uint gtid = get_global_id(0);
	int2 tmp0 = a0[gtid] + 0 + za;
	int2 tmp1 = a1[gtid] + 1 + za;
	b0[gtid] = (0+1)*(+tmp0+tmp1);
}

/* 3=4-1 */
__kernel void
test_arg_1_3_kern(
	__global int2* a0,
	__global int2* b0,
	__global int2* b1,
	__global int2* b2
)
{
	int2 za = __builtin_vector_int2(2,3);
	uint gtid = get_global_id(0);
	int2 tmp0 = a0[gtid] + 0 + za;
	b0[gtid] = (0+1)*(+tmp0);
	b1[gtid] = (1+1)*(+tmp0);
	b2[gtid] = (2+1)*(+tmp0);
}

/* 2=4-2 */
__kernel void
test_arg_2_2_kern(
	__global int2* a0,
	__global int2* a1,
	__global int2* b0,
	__global int2* b1
)
{
	int2 za = __builtin_vector_int2(2,3);
	uint gtid = get_global_id(0);
	int2 tmp0 = a0[gtid] + 0 + za;
	int2 tmp1 = a1[gtid] + 1 + za;
	b0[gtid] = (0+1)*(+tmp0+tmp1);
	b1[gtid] = (1+1)*(+tmp0+tmp1);
}

/* 1=4-3 */
__kernel void
test_arg_3_1_kern(
	__global int2* a0,
	__global int2* a1,
	__global int2* a2,
	__global int2* b0
)
{
	int2 za = __builtin_vector_int2(2,3);
	uint gtid = get_global_id(0);
	int2 tmp0 = a0[gtid] + 0 + za;
	int2 tmp1 = a1[gtid] + 1 + za;
	int2 tmp2 = a2[gtid] + 2 + za;
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2);
}

/* 4=5-1 */
__kernel void
test_arg_1_4_kern(
	__global int2* a0,
	__global int2* b0,
	__global int2* b1,
	__global int2* b2,
	__global int2* b3
)
{
	int2 za = __builtin_vector_int2(2,3);
	uint gtid = get_global_id(0);
	int2 tmp0 = a0[gtid] + 0 + za;
	b0[gtid] = (0+1)*(+tmp0);
	b1[gtid] = (1+1)*(+tmp0);
	b2[gtid] = (2+1)*(+tmp0);
	b3[gtid] = (3+1)*(+tmp0);
}

/* 3=5-2 */
__kernel void
test_arg_2_3_kern(
	__global int2* a0,
	__global int2* a1,
	__global int2* b0,
	__global int2* b1,
	__global int2* b2
)
{
	int2 za = __builtin_vector_int2(2,3);
	uint gtid = get_global_id(0);
	int2 tmp0 = a0[gtid] + 0 + za;
	int2 tmp1 = a1[gtid] + 1 + za;
	b0[gtid] = (0+1)*(+tmp0+tmp1);
	b1[gtid] = (1+1)*(+tmp0+tmp1);
	b2[gtid] = (2+1)*(+tmp0+tmp1);
}

/* 2=5-3 */
__kernel void
test_arg_3_2_kern(
	__global int2* a0,
	__global int2* a1,
	__global int2* a2,
	__global int2* b0,
	__global int2* b1
)
{
	int2 za = __builtin_vector_int2(2,3);
	uint gtid = get_global_id(0);
	int2 tmp0 = a0[gtid] + 0 + za;
	int2 tmp1 = a1[gtid] + 1 + za;
	int2 tmp2 = a2[gtid] + 2 + za;
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2);
	b1[gtid] = (1+1)*(+tmp0+tmp1+tmp2);
}

/* 1=5-4 */
__kernel void
test_arg_4_1_kern(
	__global int2* a0,
	__global int2* a1,
	__global int2* a2,
	__global int2* a3,
	__global int2* b0
)
{
	int2 za = __builtin_vector_int2(2,3);
	uint gtid = get_global_id(0);
	int2 tmp0 = a0[gtid] + 0 + za;
	int2 tmp1 = a1[gtid] + 1 + za;
	int2 tmp2 = a2[gtid] + 2 + za;
	int2 tmp3 = a3[gtid] + 3 + za;
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2+tmp3);
}

/* 5=6-1 */
__kernel void
test_arg_1_5_kern(
	__global int2* a0,
	__global int2* b0,
	__global int2* b1,
	__global int2* b2,
	__global int2* b3,
	__global int2* b4
)
{
	int2 za = __builtin_vector_int2(2,3);
	uint gtid = get_global_id(0);
	int2 tmp0 = a0[gtid] + 0 + za;
	b0[gtid] = (0+1)*(+tmp0);
	b1[gtid] = (1+1)*(+tmp0);
	b2[gtid] = (2+1)*(+tmp0);
	b3[gtid] = (3+1)*(+tmp0);
	b4[gtid] = (4+1)*(+tmp0);
}

/* 4=6-2 */
__kernel void
test_arg_2_4_kern(
	__global int2* a0,
	__global int2* a1,
	__global int2* b0,
	__global int2* b1,
	__global int2* b2,
	__global int2* b3
)
{
	int2 za = __builtin_vector_int2(2,3);
	uint gtid = get_global_id(0);
	int2 tmp0 = a0[gtid] + 0 + za;
	int2 tmp1 = a1[gtid] + 1 + za;
	b0[gtid] = (0+1)*(+tmp0+tmp1);
	b1[gtid] = (1+1)*(+tmp0+tmp1);
	b2[gtid] = (2+1)*(+tmp0+tmp1);
	b3[gtid] = (3+1)*(+tmp0+tmp1);
}

/* 3=6-3 */
__kernel void
test_arg_3_3_kern(
	__global int2* a0,
	__global int2* a1,
	__global int2* a2,
	__global int2* b0,
	__global int2* b1,
	__global int2* b2
)
{
	int2 za = __builtin_vector_int2(2,3);
	uint gtid = get_global_id(0);
	int2 tmp0 = a0[gtid] + 0 + za;
	int2 tmp1 = a1[gtid] + 1 + za;
	int2 tmp2 = a2[gtid] + 2 + za;
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2);
	b1[gtid] = (1+1)*(+tmp0+tmp1+tmp2);
	b2[gtid] = (2+1)*(+tmp0+tmp1+tmp2);
}

/* 2=6-4 */
__kernel void
test_arg_4_2_kern(
	__global int2* a0,
	__global int2* a1,
	__global int2* a2,
	__global int2* a3,
	__global int2* b0,
	__global int2* b1
)
{
	int2 za = __builtin_vector_int2(2,3);
	uint gtid = get_global_id(0);
	int2 tmp0 = a0[gtid] + 0 + za;
	int2 tmp1 = a1[gtid] + 1 + za;
	int2 tmp2 = a2[gtid] + 2 + za;
	int2 tmp3 = a3[gtid] + 3 + za;
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2+tmp3);
	b1[gtid] = (1+1)*(+tmp0+tmp1+tmp2+tmp3);
}

/* 1=6-5 */
__kernel void
test_arg_5_1_kern(
	__global int2* a0,
	__global int2* a1,
	__global int2* a2,
	__global int2* a3,
	__global int2* a4,
	__global int2* b0
)
{
	int2 za = __builtin_vector_int2(2,3);
	uint gtid = get_global_id(0);
	int2 tmp0 = a0[gtid] + 0 + za;
	int2 tmp1 = a1[gtid] + 1 + za;
	int2 tmp2 = a2[gtid] + 2 + za;
	int2 tmp3 = a3[gtid] + 3 + za;
	int2 tmp4 = a4[gtid] + 4 + za;
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4);
}

/* 6=7-1 */
__kernel void
test_arg_1_6_kern(
	__global int2* a0,
	__global int2* b0,
	__global int2* b1,
	__global int2* b2,
	__global int2* b3,
	__global int2* b4,
	__global int2* b5
)
{
	int2 za = __builtin_vector_int2(2,3);
	uint gtid = get_global_id(0);
	int2 tmp0 = a0[gtid] + 0 + za;
	b0[gtid] = (0+1)*(+tmp0);
	b1[gtid] = (1+1)*(+tmp0);
	b2[gtid] = (2+1)*(+tmp0);
	b3[gtid] = (3+1)*(+tmp0);
	b4[gtid] = (4+1)*(+tmp0);
	b5[gtid] = (5+1)*(+tmp0);
}

/* 5=7-2 */
__kernel void
test_arg_2_5_kern(
	__global int2* a0,
	__global int2* a1,
	__global int2* b0,
	__global int2* b1,
	__global int2* b2,
	__global int2* b3,
	__global int2* b4
)
{
	int2 za = __builtin_vector_int2(2,3);
	uint gtid = get_global_id(0);
	int2 tmp0 = a0[gtid] + 0 + za;
	int2 tmp1 = a1[gtid] + 1 + za;
	b0[gtid] = (0+1)*(+tmp0+tmp1);
	b1[gtid] = (1+1)*(+tmp0+tmp1);
	b2[gtid] = (2+1)*(+tmp0+tmp1);
	b3[gtid] = (3+1)*(+tmp0+tmp1);
	b4[gtid] = (4+1)*(+tmp0+tmp1);
}

/* 4=7-3 */
__kernel void
test_arg_3_4_kern(
	__global int2* a0,
	__global int2* a1,
	__global int2* a2,
	__global int2* b0,
	__global int2* b1,
	__global int2* b2,
	__global int2* b3
)
{
	int2 za = __builtin_vector_int2(2,3);
	uint gtid = get_global_id(0);
	int2 tmp0 = a0[gtid] + 0 + za;
	int2 tmp1 = a1[gtid] + 1 + za;
	int2 tmp2 = a2[gtid] + 2 + za;
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2);
	b1[gtid] = (1+1)*(+tmp0+tmp1+tmp2);
	b2[gtid] = (2+1)*(+tmp0+tmp1+tmp2);
	b3[gtid] = (3+1)*(+tmp0+tmp1+tmp2);
}

/* 3=7-4 */
__kernel void
test_arg_4_3_kern(
	__global int2* a0,
	__global int2* a1,
	__global int2* a2,
	__global int2* a3,
	__global int2* b0,
	__global int2* b1,
	__global int2* b2
)
{
	int2 za = __builtin_vector_int2(2,3);
	uint gtid = get_global_id(0);
	int2 tmp0 = a0[gtid] + 0 + za;
	int2 tmp1 = a1[gtid] + 1 + za;
	int2 tmp2 = a2[gtid] + 2 + za;
	int2 tmp3 = a3[gtid] + 3 + za;
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2+tmp3);
	b1[gtid] = (1+1)*(+tmp0+tmp1+tmp2+tmp3);
	b2[gtid] = (2+1)*(+tmp0+tmp1+tmp2+tmp3);
}

/* 2=7-5 */
__kernel void
test_arg_5_2_kern(
	__global int2* a0,
	__global int2* a1,
	__global int2* a2,
	__global int2* a3,
	__global int2* a4,
	__global int2* b0,
	__global int2* b1
)
{
	int2 za = __builtin_vector_int2(2,3);
	uint gtid = get_global_id(0);
	int2 tmp0 = a0[gtid] + 0 + za;
	int2 tmp1 = a1[gtid] + 1 + za;
	int2 tmp2 = a2[gtid] + 2 + za;
	int2 tmp3 = a3[gtid] + 3 + za;
	int2 tmp4 = a4[gtid] + 4 + za;
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4);
	b1[gtid] = (1+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4);
}

/* 1=7-6 */
__kernel void
test_arg_6_1_kern(
	__global int2* a0,
	__global int2* a1,
	__global int2* a2,
	__global int2* a3,
	__global int2* a4,
	__global int2* a5,
	__global int2* b0
)
{
	int2 za = __builtin_vector_int2(2,3);
	uint gtid = get_global_id(0);
	int2 tmp0 = a0[gtid] + 0 + za;
	int2 tmp1 = a1[gtid] + 1 + za;
	int2 tmp2 = a2[gtid] + 2 + za;
	int2 tmp3 = a3[gtid] + 3 + za;
	int2 tmp4 = a4[gtid] + 4 + za;
	int2 tmp5 = a5[gtid] + 5 + za;
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4+tmp5);
}

/* 7=8-1 */
__kernel void
test_arg_1_7_kern(
	__global int2* a0,
	__global int2* b0,
	__global int2* b1,
	__global int2* b2,
	__global int2* b3,
	__global int2* b4,
	__global int2* b5,
	__global int2* b6
)
{
	int2 za = __builtin_vector_int2(2,3);
	uint gtid = get_global_id(0);
	int2 tmp0 = a0[gtid] + 0 + za;
	b0[gtid] = (0+1)*(+tmp0);
	b1[gtid] = (1+1)*(+tmp0);
	b2[gtid] = (2+1)*(+tmp0);
	b3[gtid] = (3+1)*(+tmp0);
	b4[gtid] = (4+1)*(+tmp0);
	b5[gtid] = (5+1)*(+tmp0);
	b6[gtid] = (6+1)*(+tmp0);
}

/* 6=8-2 */
__kernel void
test_arg_2_6_kern(
	__global int2* a0,
	__global int2* a1,
	__global int2* b0,
	__global int2* b1,
	__global int2* b2,
	__global int2* b3,
	__global int2* b4,
	__global int2* b5
)
{
	int2 za = __builtin_vector_int2(2,3);
	uint gtid = get_global_id(0);
	int2 tmp0 = a0[gtid] + 0 + za;
	int2 tmp1 = a1[gtid] + 1 + za;
	b0[gtid] = (0+1)*(+tmp0+tmp1);
	b1[gtid] = (1+1)*(+tmp0+tmp1);
	b2[gtid] = (2+1)*(+tmp0+tmp1);
	b3[gtid] = (3+1)*(+tmp0+tmp1);
	b4[gtid] = (4+1)*(+tmp0+tmp1);
	b5[gtid] = (5+1)*(+tmp0+tmp1);
}

/* 5=8-3 */
__kernel void
test_arg_3_5_kern(
	__global int2* a0,
	__global int2* a1,
	__global int2* a2,
	__global int2* b0,
	__global int2* b1,
	__global int2* b2,
	__global int2* b3,
	__global int2* b4
)
{
	int2 za = __builtin_vector_int2(2,3);
	uint gtid = get_global_id(0);
	int2 tmp0 = a0[gtid] + 0 + za;
	int2 tmp1 = a1[gtid] + 1 + za;
	int2 tmp2 = a2[gtid] + 2 + za;
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2);
	b1[gtid] = (1+1)*(+tmp0+tmp1+tmp2);
	b2[gtid] = (2+1)*(+tmp0+tmp1+tmp2);
	b3[gtid] = (3+1)*(+tmp0+tmp1+tmp2);
	b4[gtid] = (4+1)*(+tmp0+tmp1+tmp2);
}

/* 4=8-4 */
__kernel void
test_arg_4_4_kern(
	__global int2* a0,
	__global int2* a1,
	__global int2* a2,
	__global int2* a3,
	__global int2* b0,
	__global int2* b1,
	__global int2* b2,
	__global int2* b3
)
{
	int2 za = __builtin_vector_int2(2,3);
	uint gtid = get_global_id(0);
	int2 tmp0 = a0[gtid] + 0 + za;
	int2 tmp1 = a1[gtid] + 1 + za;
	int2 tmp2 = a2[gtid] + 2 + za;
	int2 tmp3 = a3[gtid] + 3 + za;
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2+tmp3);
	b1[gtid] = (1+1)*(+tmp0+tmp1+tmp2+tmp3);
	b2[gtid] = (2+1)*(+tmp0+tmp1+tmp2+tmp3);
	b3[gtid] = (3+1)*(+tmp0+tmp1+tmp2+tmp3);
}

/* 3=8-5 */
__kernel void
test_arg_5_3_kern(
	__global int2* a0,
	__global int2* a1,
	__global int2* a2,
	__global int2* a3,
	__global int2* a4,
	__global int2* b0,
	__global int2* b1,
	__global int2* b2
)
{
	int2 za = __builtin_vector_int2(2,3);
	uint gtid = get_global_id(0);
	int2 tmp0 = a0[gtid] + 0 + za;
	int2 tmp1 = a1[gtid] + 1 + za;
	int2 tmp2 = a2[gtid] + 2 + za;
	int2 tmp3 = a3[gtid] + 3 + za;
	int2 tmp4 = a4[gtid] + 4 + za;
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4);
	b1[gtid] = (1+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4);
	b2[gtid] = (2+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4);
}

/* 2=8-6 */
__kernel void
test_arg_6_2_kern(
	__global int2* a0,
	__global int2* a1,
	__global int2* a2,
	__global int2* a3,
	__global int2* a4,
	__global int2* a5,
	__global int2* b0,
	__global int2* b1
)
{
	int2 za = __builtin_vector_int2(2,3);
	uint gtid = get_global_id(0);
	int2 tmp0 = a0[gtid] + 0 + za;
	int2 tmp1 = a1[gtid] + 1 + za;
	int2 tmp2 = a2[gtid] + 2 + za;
	int2 tmp3 = a3[gtid] + 3 + za;
	int2 tmp4 = a4[gtid] + 4 + za;
	int2 tmp5 = a5[gtid] + 5 + za;
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4+tmp5);
	b1[gtid] = (1+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4+tmp5);
}

/* 1=8-7 */
__kernel void
test_arg_7_1_kern(
	__global int2* a0,
	__global int2* a1,
	__global int2* a2,
	__global int2* a3,
	__global int2* a4,
	__global int2* a5,
	__global int2* a6,
	__global int2* b0
)
{
	int2 za = __builtin_vector_int2(2,3);
	uint gtid = get_global_id(0);
	int2 tmp0 = a0[gtid] + 0 + za;
	int2 tmp1 = a1[gtid] + 1 + za;
	int2 tmp2 = a2[gtid] + 2 + za;
	int2 tmp3 = a3[gtid] + 3 + za;
	int2 tmp4 = a4[gtid] + 4 + za;
	int2 tmp5 = a5[gtid] + 5 + za;
	int2 tmp6 = a6[gtid] + 6 + za;
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4+tmp5+tmp6);
}

/* 8=9-1 */
__kernel void
test_arg_1_8_kern(
	__global int2* a0,
	__global int2* b0,
	__global int2* b1,
	__global int2* b2,
	__global int2* b3,
	__global int2* b4,
	__global int2* b5,
	__global int2* b6,
	__global int2* b7
)
{
	int2 za = __builtin_vector_int2(2,3);
	uint gtid = get_global_id(0);
	int2 tmp0 = a0[gtid] + 0 + za;
	b0[gtid] = (0+1)*(+tmp0);
	b1[gtid] = (1+1)*(+tmp0);
	b2[gtid] = (2+1)*(+tmp0);
	b3[gtid] = (3+1)*(+tmp0);
	b4[gtid] = (4+1)*(+tmp0);
	b5[gtid] = (5+1)*(+tmp0);
	b6[gtid] = (6+1)*(+tmp0);
	b7[gtid] = (7+1)*(+tmp0);
}

/* 7=9-2 */
__kernel void
test_arg_2_7_kern(
	__global int2* a0,
	__global int2* a1,
	__global int2* b0,
	__global int2* b1,
	__global int2* b2,
	__global int2* b3,
	__global int2* b4,
	__global int2* b5,
	__global int2* b6
)
{
	int2 za = __builtin_vector_int2(2,3);
	uint gtid = get_global_id(0);
	int2 tmp0 = a0[gtid] + 0 + za;
	int2 tmp1 = a1[gtid] + 1 + za;
	b0[gtid] = (0+1)*(+tmp0+tmp1);
	b1[gtid] = (1+1)*(+tmp0+tmp1);
	b2[gtid] = (2+1)*(+tmp0+tmp1);
	b3[gtid] = (3+1)*(+tmp0+tmp1);
	b4[gtid] = (4+1)*(+tmp0+tmp1);
	b5[gtid] = (5+1)*(+tmp0+tmp1);
	b6[gtid] = (6+1)*(+tmp0+tmp1);
}

/* 6=9-3 */
__kernel void
test_arg_3_6_kern(
	__global int2* a0,
	__global int2* a1,
	__global int2* a2,
	__global int2* b0,
	__global int2* b1,
	__global int2* b2,
	__global int2* b3,
	__global int2* b4,
	__global int2* b5
)
{
	int2 za = __builtin_vector_int2(2,3);
	uint gtid = get_global_id(0);
	int2 tmp0 = a0[gtid] + 0 + za;
	int2 tmp1 = a1[gtid] + 1 + za;
	int2 tmp2 = a2[gtid] + 2 + za;
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2);
	b1[gtid] = (1+1)*(+tmp0+tmp1+tmp2);
	b2[gtid] = (2+1)*(+tmp0+tmp1+tmp2);
	b3[gtid] = (3+1)*(+tmp0+tmp1+tmp2);
	b4[gtid] = (4+1)*(+tmp0+tmp1+tmp2);
	b5[gtid] = (5+1)*(+tmp0+tmp1+tmp2);
}

/* 5=9-4 */
__kernel void
test_arg_4_5_kern(
	__global int2* a0,
	__global int2* a1,
	__global int2* a2,
	__global int2* a3,
	__global int2* b0,
	__global int2* b1,
	__global int2* b2,
	__global int2* b3,
	__global int2* b4
)
{
	int2 za = __builtin_vector_int2(2,3);
	uint gtid = get_global_id(0);
	int2 tmp0 = a0[gtid] + 0 + za;
	int2 tmp1 = a1[gtid] + 1 + za;
	int2 tmp2 = a2[gtid] + 2 + za;
	int2 tmp3 = a3[gtid] + 3 + za;
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2+tmp3);
	b1[gtid] = (1+1)*(+tmp0+tmp1+tmp2+tmp3);
	b2[gtid] = (2+1)*(+tmp0+tmp1+tmp2+tmp3);
	b3[gtid] = (3+1)*(+tmp0+tmp1+tmp2+tmp3);
	b4[gtid] = (4+1)*(+tmp0+tmp1+tmp2+tmp3);
}

/* 4=9-5 */
__kernel void
test_arg_5_4_kern(
	__global int2* a0,
	__global int2* a1,
	__global int2* a2,
	__global int2* a3,
	__global int2* a4,
	__global int2* b0,
	__global int2* b1,
	__global int2* b2,
	__global int2* b3
)
{
	int2 za = __builtin_vector_int2(2,3);
	uint gtid = get_global_id(0);
	int2 tmp0 = a0[gtid] + 0 + za;
	int2 tmp1 = a1[gtid] + 1 + za;
	int2 tmp2 = a2[gtid] + 2 + za;
	int2 tmp3 = a3[gtid] + 3 + za;
	int2 tmp4 = a4[gtid] + 4 + za;
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4);
	b1[gtid] = (1+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4);
	b2[gtid] = (2+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4);
	b3[gtid] = (3+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4);
}

/* 3=9-6 */
__kernel void
test_arg_6_3_kern(
	__global int2* a0,
	__global int2* a1,
	__global int2* a2,
	__global int2* a3,
	__global int2* a4,
	__global int2* a5,
	__global int2* b0,
	__global int2* b1,
	__global int2* b2
)
{
	int2 za = __builtin_vector_int2(2,3);
	uint gtid = get_global_id(0);
	int2 tmp0 = a0[gtid] + 0 + za;
	int2 tmp1 = a1[gtid] + 1 + za;
	int2 tmp2 = a2[gtid] + 2 + za;
	int2 tmp3 = a3[gtid] + 3 + za;
	int2 tmp4 = a4[gtid] + 4 + za;
	int2 tmp5 = a5[gtid] + 5 + za;
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4+tmp5);
	b1[gtid] = (1+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4+tmp5);
	b2[gtid] = (2+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4+tmp5);
}

/* 2=9-7 */
__kernel void
test_arg_7_2_kern(
	__global int2* a0,
	__global int2* a1,
	__global int2* a2,
	__global int2* a3,
	__global int2* a4,
	__global int2* a5,
	__global int2* a6,
	__global int2* b0,
	__global int2* b1
)
{
	int2 za = __builtin_vector_int2(2,3);
	uint gtid = get_global_id(0);
	int2 tmp0 = a0[gtid] + 0 + za;
	int2 tmp1 = a1[gtid] + 1 + za;
	int2 tmp2 = a2[gtid] + 2 + za;
	int2 tmp3 = a3[gtid] + 3 + za;
	int2 tmp4 = a4[gtid] + 4 + za;
	int2 tmp5 = a5[gtid] + 5 + za;
	int2 tmp6 = a6[gtid] + 6 + za;
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4+tmp5+tmp6);
	b1[gtid] = (1+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4+tmp5+tmp6);
}

/* 1=9-8 */
__kernel void
test_arg_8_1_kern(
	__global int2* a0,
	__global int2* a1,
	__global int2* a2,
	__global int2* a3,
	__global int2* a4,
	__global int2* a5,
	__global int2* a6,
	__global int2* a7,
	__global int2* b0
)
{
	int2 za = __builtin_vector_int2(2,3);
	uint gtid = get_global_id(0);
	int2 tmp0 = a0[gtid] + 0 + za;
	int2 tmp1 = a1[gtid] + 1 + za;
	int2 tmp2 = a2[gtid] + 2 + za;
	int2 tmp3 = a3[gtid] + 3 + za;
	int2 tmp4 = a4[gtid] + 4 + za;
	int2 tmp5 = a5[gtid] + 5 + za;
	int2 tmp6 = a6[gtid] + 6 + za;
	int2 tmp7 = a7[gtid] + 7 + za;
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4+tmp5+tmp6+tmp7);
}
