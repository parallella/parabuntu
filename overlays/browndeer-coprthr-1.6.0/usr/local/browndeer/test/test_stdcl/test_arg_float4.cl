
/* 1=2-1 */

#include <stdcl.h>
__kernel void
test_arg_1_1_kern(
	__global float4* a0,
	__global float4* b0
)
{
	float4 za = __builtin_vector_float4(0.75f,0.5f,0.25f,0.33f);
	uint gtid = get_global_id(0);
	float4 tmp0 = a0[gtid] + 0.1f + za;
	b0[gtid] = (0.0f+1.1f)*(+tmp0);
}

/* 2=3-1 */

#include <stdcl.h>
__kernel void
test_arg_1_2_kern(
	__global float4* a0,
	__global float4* b0,
	__global float4* b1
)
{
	float4 za = __builtin_vector_float4(0.75f,0.5f,0.25f,0.33f);
	uint gtid = get_global_id(0);
	float4 tmp0 = a0[gtid] + 0.1f + za;
	b0[gtid] = (0.0f+1.1f)*(+tmp0);
	b1[gtid] = (1.0f+1.1f)*(+tmp0);
}

/* 1=3-2 */

#include <stdcl.h>
__kernel void
test_arg_2_1_kern(
	__global float4* a0,
	__global float4* a1,
	__global float4* b0
)
{
	float4 za = __builtin_vector_float4(0.75f,0.5f,0.25f,0.33f);
	uint gtid = get_global_id(0);
	float4 tmp0 = a0[gtid] + 0.1f + za;
	float4 tmp1 = a1[gtid] + 1.1f + za;
	b0[gtid] = (0.0f+1.1f)*(+tmp0+tmp1);
}

/* 3=4-1 */

#include <stdcl.h>
__kernel void
test_arg_1_3_kern(
	__global float4* a0,
	__global float4* b0,
	__global float4* b1,
	__global float4* b2
)
{
	float4 za = __builtin_vector_float4(0.75f,0.5f,0.25f,0.33f);
	uint gtid = get_global_id(0);
	float4 tmp0 = a0[gtid] + 0.1f + za;
	b0[gtid] = (0.0f+1.1f)*(+tmp0);
	b1[gtid] = (1.0f+1.1f)*(+tmp0);
	b2[gtid] = (2.0f+1.1f)*(+tmp0);
}

/* 2=4-2 */

#include <stdcl.h>
__kernel void
test_arg_2_2_kern(
	__global float4* a0,
	__global float4* a1,
	__global float4* b0,
	__global float4* b1
)
{
	float4 za = __builtin_vector_float4(0.75f,0.5f,0.25f,0.33f);
	uint gtid = get_global_id(0);
	float4 tmp0 = a0[gtid] + 0.1f + za;
	float4 tmp1 = a1[gtid] + 1.1f + za;
	b0[gtid] = (0.0f+1.1f)*(+tmp0+tmp1);
	b1[gtid] = (1.0f+1.1f)*(+tmp0+tmp1);
}

/* 1=4-3 */

#include <stdcl.h>
__kernel void
test_arg_3_1_kern(
	__global float4* a0,
	__global float4* a1,
	__global float4* a2,
	__global float4* b0
)
{
	float4 za = __builtin_vector_float4(0.75f,0.5f,0.25f,0.33f);
	uint gtid = get_global_id(0);
	float4 tmp0 = a0[gtid] + 0.1f + za;
	float4 tmp1 = a1[gtid] + 1.1f + za;
	float4 tmp2 = a2[gtid] + 2.1f + za;
	b0[gtid] = (0.0f+1.1f)*(+tmp0+tmp1+tmp2);
}

/* 4=5-1 */

#include <stdcl.h>
__kernel void
test_arg_1_4_kern(
	__global float4* a0,
	__global float4* b0,
	__global float4* b1,
	__global float4* b2,
	__global float4* b3
)
{
	float4 za = __builtin_vector_float4(0.75f,0.5f,0.25f,0.33f);
	uint gtid = get_global_id(0);
	float4 tmp0 = a0[gtid] + 0.1f + za;
	b0[gtid] = (0.0f+1.1f)*(+tmp0);
	b1[gtid] = (1.0f+1.1f)*(+tmp0);
	b2[gtid] = (2.0f+1.1f)*(+tmp0);
	b3[gtid] = (3.0f+1.1f)*(+tmp0);
}

/* 3=5-2 */

#include <stdcl.h>
__kernel void
test_arg_2_3_kern(
	__global float4* a0,
	__global float4* a1,
	__global float4* b0,
	__global float4* b1,
	__global float4* b2
)
{
	float4 za = __builtin_vector_float4(0.75f,0.5f,0.25f,0.33f);
	uint gtid = get_global_id(0);
	float4 tmp0 = a0[gtid] + 0.1f + za;
	float4 tmp1 = a1[gtid] + 1.1f + za;
	b0[gtid] = (0.0f+1.1f)*(+tmp0+tmp1);
	b1[gtid] = (1.0f+1.1f)*(+tmp0+tmp1);
	b2[gtid] = (2.0f+1.1f)*(+tmp0+tmp1);
}

/* 2=5-3 */

#include <stdcl.h>
__kernel void
test_arg_3_2_kern(
	__global float4* a0,
	__global float4* a1,
	__global float4* a2,
	__global float4* b0,
	__global float4* b1
)
{
	float4 za = __builtin_vector_float4(0.75f,0.5f,0.25f,0.33f);
	uint gtid = get_global_id(0);
	float4 tmp0 = a0[gtid] + 0.1f + za;
	float4 tmp1 = a1[gtid] + 1.1f + za;
	float4 tmp2 = a2[gtid] + 2.1f + za;
	b0[gtid] = (0.0f+1.1f)*(+tmp0+tmp1+tmp2);
	b1[gtid] = (1.0f+1.1f)*(+tmp0+tmp1+tmp2);
}

/* 1=5-4 */

#include <stdcl.h>
__kernel void
test_arg_4_1_kern(
	__global float4* a0,
	__global float4* a1,
	__global float4* a2,
	__global float4* a3,
	__global float4* b0
)
{
	float4 za = __builtin_vector_float4(0.75f,0.5f,0.25f,0.33f);
	uint gtid = get_global_id(0);
	float4 tmp0 = a0[gtid] + 0.1f + za;
	float4 tmp1 = a1[gtid] + 1.1f + za;
	float4 tmp2 = a2[gtid] + 2.1f + za;
	float4 tmp3 = a3[gtid] + 3.1f + za;
	b0[gtid] = (0.0f+1.1f)*(+tmp0+tmp1+tmp2+tmp3);
}
