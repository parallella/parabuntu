
/* 1=2-1 */
__kernel void
test_arg_1_1_kern(
	__global float* a0,
	__global float* b0
)
{
	uint gtid = get_global_id(0);
	float tmp0 = a0[gtid] + 0.1f;
	b0[gtid] = (0.0f+1.1f)*(+tmp0);
}

/* 2=3-1 */
__kernel void
test_arg_1_2_kern(
	__global float* a0,
	__global float* b0,
	__global float* b1
)
{
	uint gtid = get_global_id(0);
	float tmp0 = a0[gtid] + 0.1f;
	b0[gtid] = (0.0f+1.1f)*(+tmp0);
	b1[gtid] = (1.0f+1.1f)*(+tmp0);
}

/* 1=3-2 */
__kernel void
test_arg_2_1_kern(
	__global float* a0,
	__global float* a1,
	__global float* b0
)
{
	uint gtid = get_global_id(0);
	float tmp0 = a0[gtid] + 0.1f;
	float tmp1 = a1[gtid] + 1.1f;
	b0[gtid] = (0.0f+1.1f)*(+tmp0+tmp1);
}

/* 3=4-1 */
__kernel void
test_arg_1_3_kern(
	__global float* a0,
	__global float* b0,
	__global float* b1,
	__global float* b2
)
{
	uint gtid = get_global_id(0);
	float tmp0 = a0[gtid] + 0.1f;
	b0[gtid] = (0.0f+1.1f)*(+tmp0);
	b1[gtid] = (1.0f+1.1f)*(+tmp0);
	b2[gtid] = (2.0f+1.1f)*(+tmp0);
}

/* 2=4-2 */
__kernel void
test_arg_2_2_kern(
	__global float* a0,
	__global float* a1,
	__global float* b0,
	__global float* b1
)
{
	uint gtid = get_global_id(0);
	float tmp0 = a0[gtid] + 0.1f;
	float tmp1 = a1[gtid] + 1.1f;
	b0[gtid] = (0.0f+1.1f)*(+tmp0+tmp1);
	b1[gtid] = (1.0f+1.1f)*(+tmp0+tmp1);
}

/* 1=4-3 */
__kernel void
test_arg_3_1_kern(
	__global float* a0,
	__global float* a1,
	__global float* a2,
	__global float* b0
)
{
	uint gtid = get_global_id(0);
	float tmp0 = a0[gtid] + 0.1f;
	float tmp1 = a1[gtid] + 1.1f;
	float tmp2 = a2[gtid] + 2.1f;
	b0[gtid] = (0.0f+1.1f)*(+tmp0+tmp1+tmp2);
}

/* 4=5-1 */
__kernel void
test_arg_1_4_kern(
	__global float* a0,
	__global float* b0,
	__global float* b1,
	__global float* b2,
	__global float* b3
)
{
	uint gtid = get_global_id(0);
	float tmp0 = a0[gtid] + 0.1f;
	b0[gtid] = (0.0f+1.1f)*(+tmp0);
	b1[gtid] = (1.0f+1.1f)*(+tmp0);
	b2[gtid] = (2.0f+1.1f)*(+tmp0);
	b3[gtid] = (3.0f+1.1f)*(+tmp0);
}

/* 3=5-2 */
__kernel void
test_arg_2_3_kern(
	__global float* a0,
	__global float* a1,
	__global float* b0,
	__global float* b1,
	__global float* b2
)
{
	uint gtid = get_global_id(0);
	float tmp0 = a0[gtid] + 0.1f;
	float tmp1 = a1[gtid] + 1.1f;
	b0[gtid] = (0.0f+1.1f)*(+tmp0+tmp1);
	b1[gtid] = (1.0f+1.1f)*(+tmp0+tmp1);
	b2[gtid] = (2.0f+1.1f)*(+tmp0+tmp1);
}

/* 2=5-3 */
__kernel void
test_arg_3_2_kern(
	__global float* a0,
	__global float* a1,
	__global float* a2,
	__global float* b0,
	__global float* b1
)
{
	uint gtid = get_global_id(0);
	float tmp0 = a0[gtid] + 0.1f;
	float tmp1 = a1[gtid] + 1.1f;
	float tmp2 = a2[gtid] + 2.1f;
	b0[gtid] = (0.0f+1.1f)*(+tmp0+tmp1+tmp2);
	b1[gtid] = (1.0f+1.1f)*(+tmp0+tmp1+tmp2);
}

/* 1=5-4 */
__kernel void
test_arg_4_1_kern(
	__global float* a0,
	__global float* a1,
	__global float* a2,
	__global float* a3,
	__global float* b0
)
{
	uint gtid = get_global_id(0);
	float tmp0 = a0[gtid] + 0.1f;
	float tmp1 = a1[gtid] + 1.1f;
	float tmp2 = a2[gtid] + 2.1f;
	float tmp3 = a3[gtid] + 3.1f;
	b0[gtid] = (0.0f+1.1f)*(+tmp0+tmp1+tmp2+tmp3);
}
