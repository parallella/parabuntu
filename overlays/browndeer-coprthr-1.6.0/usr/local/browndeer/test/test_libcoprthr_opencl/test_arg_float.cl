
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

/* 5=6-1 */
__kernel void
test_arg_1_5_kern(
	__global float* a0,
	__global float* b0,
	__global float* b1,
	__global float* b2,
	__global float* b3,
	__global float* b4
)
{
	uint gtid = get_global_id(0);
	float tmp0 = a0[gtid] + 0.1f;
	b0[gtid] = (0.0f+1.1f)*(+tmp0);
	b1[gtid] = (1.0f+1.1f)*(+tmp0);
	b2[gtid] = (2.0f+1.1f)*(+tmp0);
	b3[gtid] = (3.0f+1.1f)*(+tmp0);
	b4[gtid] = (4.0f+1.1f)*(+tmp0);
}

/* 4=6-2 */
__kernel void
test_arg_2_4_kern(
	__global float* a0,
	__global float* a1,
	__global float* b0,
	__global float* b1,
	__global float* b2,
	__global float* b3
)
{
	uint gtid = get_global_id(0);
	float tmp0 = a0[gtid] + 0.1f;
	float tmp1 = a1[gtid] + 1.1f;
	b0[gtid] = (0.0f+1.1f)*(+tmp0+tmp1);
	b1[gtid] = (1.0f+1.1f)*(+tmp0+tmp1);
	b2[gtid] = (2.0f+1.1f)*(+tmp0+tmp1);
	b3[gtid] = (3.0f+1.1f)*(+tmp0+tmp1);
}

/* 3=6-3 */
__kernel void
test_arg_3_3_kern(
	__global float* a0,
	__global float* a1,
	__global float* a2,
	__global float* b0,
	__global float* b1,
	__global float* b2
)
{
	uint gtid = get_global_id(0);
	float tmp0 = a0[gtid] + 0.1f;
	float tmp1 = a1[gtid] + 1.1f;
	float tmp2 = a2[gtid] + 2.1f;
	b0[gtid] = (0.0f+1.1f)*(+tmp0+tmp1+tmp2);
	b1[gtid] = (1.0f+1.1f)*(+tmp0+tmp1+tmp2);
	b2[gtid] = (2.0f+1.1f)*(+tmp0+tmp1+tmp2);
}

/* 2=6-4 */
__kernel void
test_arg_4_2_kern(
	__global float* a0,
	__global float* a1,
	__global float* a2,
	__global float* a3,
	__global float* b0,
	__global float* b1
)
{
	uint gtid = get_global_id(0);
	float tmp0 = a0[gtid] + 0.1f;
	float tmp1 = a1[gtid] + 1.1f;
	float tmp2 = a2[gtid] + 2.1f;
	float tmp3 = a3[gtid] + 3.1f;
	b0[gtid] = (0.0f+1.1f)*(+tmp0+tmp1+tmp2+tmp3);
	b1[gtid] = (1.0f+1.1f)*(+tmp0+tmp1+tmp2+tmp3);
}

/* 1=6-5 */
__kernel void
test_arg_5_1_kern(
	__global float* a0,
	__global float* a1,
	__global float* a2,
	__global float* a3,
	__global float* a4,
	__global float* b0
)
{
	uint gtid = get_global_id(0);
	float tmp0 = a0[gtid] + 0.1f;
	float tmp1 = a1[gtid] + 1.1f;
	float tmp2 = a2[gtid] + 2.1f;
	float tmp3 = a3[gtid] + 3.1f;
	float tmp4 = a4[gtid] + 4.1f;
	b0[gtid] = (0.0f+1.1f)*(+tmp0+tmp1+tmp2+tmp3+tmp4);
}

/* 6=7-1 */
__kernel void
test_arg_1_6_kern(
	__global float* a0,
	__global float* b0,
	__global float* b1,
	__global float* b2,
	__global float* b3,
	__global float* b4,
	__global float* b5
)
{
	uint gtid = get_global_id(0);
	float tmp0 = a0[gtid] + 0.1f;
	b0[gtid] = (0.0f+1.1f)*(+tmp0);
	b1[gtid] = (1.0f+1.1f)*(+tmp0);
	b2[gtid] = (2.0f+1.1f)*(+tmp0);
	b3[gtid] = (3.0f+1.1f)*(+tmp0);
	b4[gtid] = (4.0f+1.1f)*(+tmp0);
	b5[gtid] = (5.0f+1.1f)*(+tmp0);
}

/* 5=7-2 */
__kernel void
test_arg_2_5_kern(
	__global float* a0,
	__global float* a1,
	__global float* b0,
	__global float* b1,
	__global float* b2,
	__global float* b3,
	__global float* b4
)
{
	uint gtid = get_global_id(0);
	float tmp0 = a0[gtid] + 0.1f;
	float tmp1 = a1[gtid] + 1.1f;
	b0[gtid] = (0.0f+1.1f)*(+tmp0+tmp1);
	b1[gtid] = (1.0f+1.1f)*(+tmp0+tmp1);
	b2[gtid] = (2.0f+1.1f)*(+tmp0+tmp1);
	b3[gtid] = (3.0f+1.1f)*(+tmp0+tmp1);
	b4[gtid] = (4.0f+1.1f)*(+tmp0+tmp1);
}

/* 4=7-3 */
__kernel void
test_arg_3_4_kern(
	__global float* a0,
	__global float* a1,
	__global float* a2,
	__global float* b0,
	__global float* b1,
	__global float* b2,
	__global float* b3
)
{
	uint gtid = get_global_id(0);
	float tmp0 = a0[gtid] + 0.1f;
	float tmp1 = a1[gtid] + 1.1f;
	float tmp2 = a2[gtid] + 2.1f;
	b0[gtid] = (0.0f+1.1f)*(+tmp0+tmp1+tmp2);
	b1[gtid] = (1.0f+1.1f)*(+tmp0+tmp1+tmp2);
	b2[gtid] = (2.0f+1.1f)*(+tmp0+tmp1+tmp2);
	b3[gtid] = (3.0f+1.1f)*(+tmp0+tmp1+tmp2);
}

/* 3=7-4 */
__kernel void
test_arg_4_3_kern(
	__global float* a0,
	__global float* a1,
	__global float* a2,
	__global float* a3,
	__global float* b0,
	__global float* b1,
	__global float* b2
)
{
	uint gtid = get_global_id(0);
	float tmp0 = a0[gtid] + 0.1f;
	float tmp1 = a1[gtid] + 1.1f;
	float tmp2 = a2[gtid] + 2.1f;
	float tmp3 = a3[gtid] + 3.1f;
	b0[gtid] = (0.0f+1.1f)*(+tmp0+tmp1+tmp2+tmp3);
	b1[gtid] = (1.0f+1.1f)*(+tmp0+tmp1+tmp2+tmp3);
	b2[gtid] = (2.0f+1.1f)*(+tmp0+tmp1+tmp2+tmp3);
}

/* 2=7-5 */
__kernel void
test_arg_5_2_kern(
	__global float* a0,
	__global float* a1,
	__global float* a2,
	__global float* a3,
	__global float* a4,
	__global float* b0,
	__global float* b1
)
{
	uint gtid = get_global_id(0);
	float tmp0 = a0[gtid] + 0.1f;
	float tmp1 = a1[gtid] + 1.1f;
	float tmp2 = a2[gtid] + 2.1f;
	float tmp3 = a3[gtid] + 3.1f;
	float tmp4 = a4[gtid] + 4.1f;
	b0[gtid] = (0.0f+1.1f)*(+tmp0+tmp1+tmp2+tmp3+tmp4);
	b1[gtid] = (1.0f+1.1f)*(+tmp0+tmp1+tmp2+tmp3+tmp4);
}

/* 1=7-6 */
__kernel void
test_arg_6_1_kern(
	__global float* a0,
	__global float* a1,
	__global float* a2,
	__global float* a3,
	__global float* a4,
	__global float* a5,
	__global float* b0
)
{
	uint gtid = get_global_id(0);
	float tmp0 = a0[gtid] + 0.1f;
	float tmp1 = a1[gtid] + 1.1f;
	float tmp2 = a2[gtid] + 2.1f;
	float tmp3 = a3[gtid] + 3.1f;
	float tmp4 = a4[gtid] + 4.1f;
	float tmp5 = a5[gtid] + 5.1f;
	b0[gtid] = (0.0f+1.1f)*(+tmp0+tmp1+tmp2+tmp3+tmp4+tmp5);
}

/* 7=8-1 */
__kernel void
test_arg_1_7_kern(
	__global float* a0,
	__global float* b0,
	__global float* b1,
	__global float* b2,
	__global float* b3,
	__global float* b4,
	__global float* b5,
	__global float* b6
)
{
	uint gtid = get_global_id(0);
	float tmp0 = a0[gtid] + 0.1f;
	b0[gtid] = (0.0f+1.1f)*(+tmp0);
	b1[gtid] = (1.0f+1.1f)*(+tmp0);
	b2[gtid] = (2.0f+1.1f)*(+tmp0);
	b3[gtid] = (3.0f+1.1f)*(+tmp0);
	b4[gtid] = (4.0f+1.1f)*(+tmp0);
	b5[gtid] = (5.0f+1.1f)*(+tmp0);
	b6[gtid] = (6.0f+1.1f)*(+tmp0);
}

/* 6=8-2 */
__kernel void
test_arg_2_6_kern(
	__global float* a0,
	__global float* a1,
	__global float* b0,
	__global float* b1,
	__global float* b2,
	__global float* b3,
	__global float* b4,
	__global float* b5
)
{
	uint gtid = get_global_id(0);
	float tmp0 = a0[gtid] + 0.1f;
	float tmp1 = a1[gtid] + 1.1f;
	b0[gtid] = (0.0f+1.1f)*(+tmp0+tmp1);
	b1[gtid] = (1.0f+1.1f)*(+tmp0+tmp1);
	b2[gtid] = (2.0f+1.1f)*(+tmp0+tmp1);
	b3[gtid] = (3.0f+1.1f)*(+tmp0+tmp1);
	b4[gtid] = (4.0f+1.1f)*(+tmp0+tmp1);
	b5[gtid] = (5.0f+1.1f)*(+tmp0+tmp1);
}

/* 5=8-3 */
__kernel void
test_arg_3_5_kern(
	__global float* a0,
	__global float* a1,
	__global float* a2,
	__global float* b0,
	__global float* b1,
	__global float* b2,
	__global float* b3,
	__global float* b4
)
{
	uint gtid = get_global_id(0);
	float tmp0 = a0[gtid] + 0.1f;
	float tmp1 = a1[gtid] + 1.1f;
	float tmp2 = a2[gtid] + 2.1f;
	b0[gtid] = (0.0f+1.1f)*(+tmp0+tmp1+tmp2);
	b1[gtid] = (1.0f+1.1f)*(+tmp0+tmp1+tmp2);
	b2[gtid] = (2.0f+1.1f)*(+tmp0+tmp1+tmp2);
	b3[gtid] = (3.0f+1.1f)*(+tmp0+tmp1+tmp2);
	b4[gtid] = (4.0f+1.1f)*(+tmp0+tmp1+tmp2);
}

/* 4=8-4 */
__kernel void
test_arg_4_4_kern(
	__global float* a0,
	__global float* a1,
	__global float* a2,
	__global float* a3,
	__global float* b0,
	__global float* b1,
	__global float* b2,
	__global float* b3
)
{
	uint gtid = get_global_id(0);
	float tmp0 = a0[gtid] + 0.1f;
	float tmp1 = a1[gtid] + 1.1f;
	float tmp2 = a2[gtid] + 2.1f;
	float tmp3 = a3[gtid] + 3.1f;
	b0[gtid] = (0.0f+1.1f)*(+tmp0+tmp1+tmp2+tmp3);
	b1[gtid] = (1.0f+1.1f)*(+tmp0+tmp1+tmp2+tmp3);
	b2[gtid] = (2.0f+1.1f)*(+tmp0+tmp1+tmp2+tmp3);
	b3[gtid] = (3.0f+1.1f)*(+tmp0+tmp1+tmp2+tmp3);
}

/* 3=8-5 */
__kernel void
test_arg_5_3_kern(
	__global float* a0,
	__global float* a1,
	__global float* a2,
	__global float* a3,
	__global float* a4,
	__global float* b0,
	__global float* b1,
	__global float* b2
)
{
	uint gtid = get_global_id(0);
	float tmp0 = a0[gtid] + 0.1f;
	float tmp1 = a1[gtid] + 1.1f;
	float tmp2 = a2[gtid] + 2.1f;
	float tmp3 = a3[gtid] + 3.1f;
	float tmp4 = a4[gtid] + 4.1f;
	b0[gtid] = (0.0f+1.1f)*(+tmp0+tmp1+tmp2+tmp3+tmp4);
	b1[gtid] = (1.0f+1.1f)*(+tmp0+tmp1+tmp2+tmp3+tmp4);
	b2[gtid] = (2.0f+1.1f)*(+tmp0+tmp1+tmp2+tmp3+tmp4);
}

/* 2=8-6 */
__kernel void
test_arg_6_2_kern(
	__global float* a0,
	__global float* a1,
	__global float* a2,
	__global float* a3,
	__global float* a4,
	__global float* a5,
	__global float* b0,
	__global float* b1
)
{
	uint gtid = get_global_id(0);
	float tmp0 = a0[gtid] + 0.1f;
	float tmp1 = a1[gtid] + 1.1f;
	float tmp2 = a2[gtid] + 2.1f;
	float tmp3 = a3[gtid] + 3.1f;
	float tmp4 = a4[gtid] + 4.1f;
	float tmp5 = a5[gtid] + 5.1f;
	b0[gtid] = (0.0f+1.1f)*(+tmp0+tmp1+tmp2+tmp3+tmp4+tmp5);
	b1[gtid] = (1.0f+1.1f)*(+tmp0+tmp1+tmp2+tmp3+tmp4+tmp5);
}

/* 1=8-7 */
__kernel void
test_arg_7_1_kern(
	__global float* a0,
	__global float* a1,
	__global float* a2,
	__global float* a3,
	__global float* a4,
	__global float* a5,
	__global float* a6,
	__global float* b0
)
{
	uint gtid = get_global_id(0);
	float tmp0 = a0[gtid] + 0.1f;
	float tmp1 = a1[gtid] + 1.1f;
	float tmp2 = a2[gtid] + 2.1f;
	float tmp3 = a3[gtid] + 3.1f;
	float tmp4 = a4[gtid] + 4.1f;
	float tmp5 = a5[gtid] + 5.1f;
	float tmp6 = a6[gtid] + 6.1f;
	b0[gtid] = (0.0f+1.1f)*(+tmp0+tmp1+tmp2+tmp3+tmp4+tmp5+tmp6);
}

/* 8=9-1 */
__kernel void
test_arg_1_8_kern(
	__global float* a0,
	__global float* b0,
	__global float* b1,
	__global float* b2,
	__global float* b3,
	__global float* b4,
	__global float* b5,
	__global float* b6,
	__global float* b7
)
{
	uint gtid = get_global_id(0);
	float tmp0 = a0[gtid] + 0.1f;
	b0[gtid] = (0.0f+1.1f)*(+tmp0);
	b1[gtid] = (1.0f+1.1f)*(+tmp0);
	b2[gtid] = (2.0f+1.1f)*(+tmp0);
	b3[gtid] = (3.0f+1.1f)*(+tmp0);
	b4[gtid] = (4.0f+1.1f)*(+tmp0);
	b5[gtid] = (5.0f+1.1f)*(+tmp0);
	b6[gtid] = (6.0f+1.1f)*(+tmp0);
	b7[gtid] = (7.0f+1.1f)*(+tmp0);
}

/* 7=9-2 */
__kernel void
test_arg_2_7_kern(
	__global float* a0,
	__global float* a1,
	__global float* b0,
	__global float* b1,
	__global float* b2,
	__global float* b3,
	__global float* b4,
	__global float* b5,
	__global float* b6
)
{
	uint gtid = get_global_id(0);
	float tmp0 = a0[gtid] + 0.1f;
	float tmp1 = a1[gtid] + 1.1f;
	b0[gtid] = (0.0f+1.1f)*(+tmp0+tmp1);
	b1[gtid] = (1.0f+1.1f)*(+tmp0+tmp1);
	b2[gtid] = (2.0f+1.1f)*(+tmp0+tmp1);
	b3[gtid] = (3.0f+1.1f)*(+tmp0+tmp1);
	b4[gtid] = (4.0f+1.1f)*(+tmp0+tmp1);
	b5[gtid] = (5.0f+1.1f)*(+tmp0+tmp1);
	b6[gtid] = (6.0f+1.1f)*(+tmp0+tmp1);
}

/* 6=9-3 */
__kernel void
test_arg_3_6_kern(
	__global float* a0,
	__global float* a1,
	__global float* a2,
	__global float* b0,
	__global float* b1,
	__global float* b2,
	__global float* b3,
	__global float* b4,
	__global float* b5
)
{
	uint gtid = get_global_id(0);
	float tmp0 = a0[gtid] + 0.1f;
	float tmp1 = a1[gtid] + 1.1f;
	float tmp2 = a2[gtid] + 2.1f;
	b0[gtid] = (0.0f+1.1f)*(+tmp0+tmp1+tmp2);
	b1[gtid] = (1.0f+1.1f)*(+tmp0+tmp1+tmp2);
	b2[gtid] = (2.0f+1.1f)*(+tmp0+tmp1+tmp2);
	b3[gtid] = (3.0f+1.1f)*(+tmp0+tmp1+tmp2);
	b4[gtid] = (4.0f+1.1f)*(+tmp0+tmp1+tmp2);
	b5[gtid] = (5.0f+1.1f)*(+tmp0+tmp1+tmp2);
}

/* 5=9-4 */
__kernel void
test_arg_4_5_kern(
	__global float* a0,
	__global float* a1,
	__global float* a2,
	__global float* a3,
	__global float* b0,
	__global float* b1,
	__global float* b2,
	__global float* b3,
	__global float* b4
)
{
	uint gtid = get_global_id(0);
	float tmp0 = a0[gtid] + 0.1f;
	float tmp1 = a1[gtid] + 1.1f;
	float tmp2 = a2[gtid] + 2.1f;
	float tmp3 = a3[gtid] + 3.1f;
	b0[gtid] = (0.0f+1.1f)*(+tmp0+tmp1+tmp2+tmp3);
	b1[gtid] = (1.0f+1.1f)*(+tmp0+tmp1+tmp2+tmp3);
	b2[gtid] = (2.0f+1.1f)*(+tmp0+tmp1+tmp2+tmp3);
	b3[gtid] = (3.0f+1.1f)*(+tmp0+tmp1+tmp2+tmp3);
	b4[gtid] = (4.0f+1.1f)*(+tmp0+tmp1+tmp2+tmp3);
}

/* 4=9-5 */
__kernel void
test_arg_5_4_kern(
	__global float* a0,
	__global float* a1,
	__global float* a2,
	__global float* a3,
	__global float* a4,
	__global float* b0,
	__global float* b1,
	__global float* b2,
	__global float* b3
)
{
	uint gtid = get_global_id(0);
	float tmp0 = a0[gtid] + 0.1f;
	float tmp1 = a1[gtid] + 1.1f;
	float tmp2 = a2[gtid] + 2.1f;
	float tmp3 = a3[gtid] + 3.1f;
	float tmp4 = a4[gtid] + 4.1f;
	b0[gtid] = (0.0f+1.1f)*(+tmp0+tmp1+tmp2+tmp3+tmp4);
	b1[gtid] = (1.0f+1.1f)*(+tmp0+tmp1+tmp2+tmp3+tmp4);
	b2[gtid] = (2.0f+1.1f)*(+tmp0+tmp1+tmp2+tmp3+tmp4);
	b3[gtid] = (3.0f+1.1f)*(+tmp0+tmp1+tmp2+tmp3+tmp4);
}

/* 3=9-6 */
__kernel void
test_arg_6_3_kern(
	__global float* a0,
	__global float* a1,
	__global float* a2,
	__global float* a3,
	__global float* a4,
	__global float* a5,
	__global float* b0,
	__global float* b1,
	__global float* b2
)
{
	uint gtid = get_global_id(0);
	float tmp0 = a0[gtid] + 0.1f;
	float tmp1 = a1[gtid] + 1.1f;
	float tmp2 = a2[gtid] + 2.1f;
	float tmp3 = a3[gtid] + 3.1f;
	float tmp4 = a4[gtid] + 4.1f;
	float tmp5 = a5[gtid] + 5.1f;
	b0[gtid] = (0.0f+1.1f)*(+tmp0+tmp1+tmp2+tmp3+tmp4+tmp5);
	b1[gtid] = (1.0f+1.1f)*(+tmp0+tmp1+tmp2+tmp3+tmp4+tmp5);
	b2[gtid] = (2.0f+1.1f)*(+tmp0+tmp1+tmp2+tmp3+tmp4+tmp5);
}

/* 2=9-7 */
__kernel void
test_arg_7_2_kern(
	__global float* a0,
	__global float* a1,
	__global float* a2,
	__global float* a3,
	__global float* a4,
	__global float* a5,
	__global float* a6,
	__global float* b0,
	__global float* b1
)
{
	uint gtid = get_global_id(0);
	float tmp0 = a0[gtid] + 0.1f;
	float tmp1 = a1[gtid] + 1.1f;
	float tmp2 = a2[gtid] + 2.1f;
	float tmp3 = a3[gtid] + 3.1f;
	float tmp4 = a4[gtid] + 4.1f;
	float tmp5 = a5[gtid] + 5.1f;
	float tmp6 = a6[gtid] + 6.1f;
	b0[gtid] = (0.0f+1.1f)*(+tmp0+tmp1+tmp2+tmp3+tmp4+tmp5+tmp6);
	b1[gtid] = (1.0f+1.1f)*(+tmp0+tmp1+tmp2+tmp3+tmp4+tmp5+tmp6);
}

/* 1=9-8 */
__kernel void
test_arg_8_1_kern(
	__global float* a0,
	__global float* a1,
	__global float* a2,
	__global float* a3,
	__global float* a4,
	__global float* a5,
	__global float* a6,
	__global float* a7,
	__global float* b0
)
{
	uint gtid = get_global_id(0);
	float tmp0 = a0[gtid] + 0.1f;
	float tmp1 = a1[gtid] + 1.1f;
	float tmp2 = a2[gtid] + 2.1f;
	float tmp3 = a3[gtid] + 3.1f;
	float tmp4 = a4[gtid] + 4.1f;
	float tmp5 = a5[gtid] + 5.1f;
	float tmp6 = a6[gtid] + 6.1f;
	float tmp7 = a7[gtid] + 7.1f;
	b0[gtid] = (0.0f+1.1f)*(+tmp0+tmp1+tmp2+tmp3+tmp4+tmp5+tmp6+tmp7);
}
