
/* 1=2-1 */

#include <stdcl.h>
__kernel void
test_arg_1_1_kern(
	__global int4* a0,
	__global int4* b0
)
{
	int4 za = __builtin_vector_int4(0,1,2,3);
	uint gtid = get_global_id(0);
	int4 tmp0 = a0[gtid] + 0 + za;
	b0[gtid] = (0+1)*(+tmp0);
}

/* 2=3-1 */

#include <stdcl.h>
__kernel void
test_arg_1_2_kern(
	__global int4* a0,
	__global int4* b0,
	__global int4* b1
)
{
	int4 za = __builtin_vector_int4(0,1,2,3);
	uint gtid = get_global_id(0);
	int4 tmp0 = a0[gtid] + 0 + za;
	b0[gtid] = (0+1)*(+tmp0);
	b1[gtid] = (1+1)*(+tmp0);
}

/* 1=3-2 */

#include <stdcl.h>
__kernel void
test_arg_2_1_kern(
	__global int4* a0,
	__global int4* a1,
	__global int4* b0
)
{
	int4 za = __builtin_vector_int4(0,1,2,3);
	uint gtid = get_global_id(0);
	int4 tmp0 = a0[gtid] + 0 + za;
	int4 tmp1 = a1[gtid] + 1 + za;
	b0[gtid] = (0+1)*(+tmp0+tmp1);
}

/* 3=4-1 */

#include <stdcl.h>
__kernel void
test_arg_1_3_kern(
	__global int4* a0,
	__global int4* b0,
	__global int4* b1,
	__global int4* b2
)
{
	int4 za = __builtin_vector_int4(0,1,2,3);
	uint gtid = get_global_id(0);
	int4 tmp0 = a0[gtid] + 0 + za;
	b0[gtid] = (0+1)*(+tmp0);
	b1[gtid] = (1+1)*(+tmp0);
	b2[gtid] = (2+1)*(+tmp0);
}

/* 2=4-2 */

#include <stdcl.h>
__kernel void
test_arg_2_2_kern(
	__global int4* a0,
	__global int4* a1,
	__global int4* b0,
	__global int4* b1
)
{
	int4 za = __builtin_vector_int4(0,1,2,3);
	uint gtid = get_global_id(0);
	int4 tmp0 = a0[gtid] + 0 + za;
	int4 tmp1 = a1[gtid] + 1 + za;
	b0[gtid] = (0+1)*(+tmp0+tmp1);
	b1[gtid] = (1+1)*(+tmp0+tmp1);
}

/* 1=4-3 */

#include <stdcl.h>
__kernel void
test_arg_3_1_kern(
	__global int4* a0,
	__global int4* a1,
	__global int4* a2,
	__global int4* b0
)
{
	int4 za = __builtin_vector_int4(0,1,2,3);
	uint gtid = get_global_id(0);
	int4 tmp0 = a0[gtid] + 0 + za;
	int4 tmp1 = a1[gtid] + 1 + za;
	int4 tmp2 = a2[gtid] + 2 + za;
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2);
}

/* 4=5-1 */

#include <stdcl.h>
__kernel void
test_arg_1_4_kern(
	__global int4* a0,
	__global int4* b0,
	__global int4* b1,
	__global int4* b2,
	__global int4* b3
)
{
	int4 za = __builtin_vector_int4(0,1,2,3);
	uint gtid = get_global_id(0);
	int4 tmp0 = a0[gtid] + 0 + za;
	b0[gtid] = (0+1)*(+tmp0);
	b1[gtid] = (1+1)*(+tmp0);
	b2[gtid] = (2+1)*(+tmp0);
	b3[gtid] = (3+1)*(+tmp0);
}

/* 3=5-2 */

#include <stdcl.h>
__kernel void
test_arg_2_3_kern(
	__global int4* a0,
	__global int4* a1,
	__global int4* b0,
	__global int4* b1,
	__global int4* b2
)
{
	int4 za = __builtin_vector_int4(0,1,2,3);
	uint gtid = get_global_id(0);
	int4 tmp0 = a0[gtid] + 0 + za;
	int4 tmp1 = a1[gtid] + 1 + za;
	b0[gtid] = (0+1)*(+tmp0+tmp1);
	b1[gtid] = (1+1)*(+tmp0+tmp1);
	b2[gtid] = (2+1)*(+tmp0+tmp1);
}

/* 2=5-3 */

#include <stdcl.h>
__kernel void
test_arg_3_2_kern(
	__global int4* a0,
	__global int4* a1,
	__global int4* a2,
	__global int4* b0,
	__global int4* b1
)
{
	int4 za = __builtin_vector_int4(0,1,2,3);
	uint gtid = get_global_id(0);
	int4 tmp0 = a0[gtid] + 0 + za;
	int4 tmp1 = a1[gtid] + 1 + za;
	int4 tmp2 = a2[gtid] + 2 + za;
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2);
	b1[gtid] = (1+1)*(+tmp0+tmp1+tmp2);
}

/* 1=5-4 */

#include <stdcl.h>
__kernel void
test_arg_4_1_kern(
	__global int4* a0,
	__global int4* a1,
	__global int4* a2,
	__global int4* a3,
	__global int4* b0
)
{
	int4 za = __builtin_vector_int4(0,1,2,3);
	uint gtid = get_global_id(0);
	int4 tmp0 = a0[gtid] + 0 + za;
	int4 tmp1 = a1[gtid] + 1 + za;
	int4 tmp2 = a2[gtid] + 2 + za;
	int4 tmp3 = a3[gtid] + 3 + za;
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2+tmp3);
}
