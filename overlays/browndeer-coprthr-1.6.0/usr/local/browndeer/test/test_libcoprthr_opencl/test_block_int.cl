
/* 1=2-1 */
__kernel void
test_block_1_1_kern(
	__global int* a0,
	__global int* b0,
	__local int* c0
)
{
	int i;
	uint gtid = get_global_id(0);
	uint ltid = get_local_id(0);
	size_t lsz = get_local_size(0);
	c0[ltid] = a0[gtid] + 0;
	barrier(CLK_LOCAL_MEM_FENCE);
	int tmp0 = 0;
	for(i=0;i<lsz;i++) tmp0 += c0[i];
	tmp0 -= 5*c0[ltid];
	b0[gtid] = (0+1)*(+tmp0);
}

/* 2=3-1 */
__kernel void
test_block_1_2_kern(
	__global int* a0,
	__global int* b0,
	__global int* b1,
	__local int* c0
)
{
	int i;
	uint gtid = get_global_id(0);
	uint ltid = get_local_id(0);
	size_t lsz = get_local_size(0);
	c0[ltid] = a0[gtid] + 0;
	barrier(CLK_LOCAL_MEM_FENCE);
	int tmp0 = 0;
	for(i=0;i<lsz;i++) tmp0 += c0[i];
	tmp0 -= 5*c0[ltid];
	b0[gtid] = (0+1)*(+tmp0);
	b1[gtid] = (1+1)*(+tmp0);
}

/* 1=3-2 */
__kernel void
test_block_2_1_kern(
	__global int* a0,
	__global int* a1,
	__global int* b0,
	__local int* c0,
	__local int* c1
)
{
	int i;
	uint gtid = get_global_id(0);
	uint ltid = get_local_id(0);
	size_t lsz = get_local_size(0);
	c0[ltid] = a0[gtid] + 0;
	c1[ltid] = a1[gtid] + 1;
	barrier(CLK_LOCAL_MEM_FENCE);
	int tmp0 = 0;
	int tmp1 = 0;
	for(i=0;i<lsz;i++) tmp0 += c0[i];
	for(i=0;i<lsz;i++) tmp1 += c1[i];
	tmp0 -= 5*c0[ltid];
	tmp1 -= 5*c1[ltid];
	b0[gtid] = (0+1)*(+tmp0+tmp1);
}

/* 3=4-1 */
__kernel void
test_block_1_3_kern(
	__global int* a0,
	__global int* b0,
	__global int* b1,
	__global int* b2,
	__local int* c0
)
{
	int i;
	uint gtid = get_global_id(0);
	uint ltid = get_local_id(0);
	size_t lsz = get_local_size(0);
	c0[ltid] = a0[gtid] + 0;
	barrier(CLK_LOCAL_MEM_FENCE);
	int tmp0 = 0;
	for(i=0;i<lsz;i++) tmp0 += c0[i];
	tmp0 -= 5*c0[ltid];
	b0[gtid] = (0+1)*(+tmp0);
	b1[gtid] = (1+1)*(+tmp0);
	b2[gtid] = (2+1)*(+tmp0);
}

/* 2=4-2 */
__kernel void
test_block_2_2_kern(
	__global int* a0,
	__global int* a1,
	__global int* b0,
	__global int* b1,
	__local int* c0,
	__local int* c1
)
{
	int i;
	uint gtid = get_global_id(0);
	uint ltid = get_local_id(0);
	size_t lsz = get_local_size(0);
	c0[ltid] = a0[gtid] + 0;
	c1[ltid] = a1[gtid] + 1;
	barrier(CLK_LOCAL_MEM_FENCE);
	int tmp0 = 0;
	int tmp1 = 0;
	for(i=0;i<lsz;i++) tmp0 += c0[i];
	for(i=0;i<lsz;i++) tmp1 += c1[i];
	tmp0 -= 5*c0[ltid];
	tmp1 -= 5*c1[ltid];
	b0[gtid] = (0+1)*(+tmp0+tmp1);
	b1[gtid] = (1+1)*(+tmp0+tmp1);
}

/* 1=4-3 */
__kernel void
test_block_3_1_kern(
	__global int* a0,
	__global int* a1,
	__global int* a2,
	__global int* b0,
	__local int* c0,
	__local int* c1,
	__local int* c2
)
{
	int i;
	uint gtid = get_global_id(0);
	uint ltid = get_local_id(0);
	size_t lsz = get_local_size(0);
	c0[ltid] = a0[gtid] + 0;
	c1[ltid] = a1[gtid] + 1;
	c2[ltid] = a2[gtid] + 2;
	barrier(CLK_LOCAL_MEM_FENCE);
	int tmp0 = 0;
	int tmp1 = 0;
	int tmp2 = 0;
	for(i=0;i<lsz;i++) tmp0 += c0[i];
	for(i=0;i<lsz;i++) tmp1 += c1[i];
	for(i=0;i<lsz;i++) tmp2 += c2[i];
	tmp0 -= 5*c0[ltid];
	tmp1 -= 5*c1[ltid];
	tmp2 -= 5*c2[ltid];
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2);
}

/* 4=5-1 */
__kernel void
test_block_1_4_kern(
	__global int* a0,
	__global int* b0,
	__global int* b1,
	__global int* b2,
	__global int* b3,
	__local int* c0
)
{
	int i;
	uint gtid = get_global_id(0);
	uint ltid = get_local_id(0);
	size_t lsz = get_local_size(0);
	c0[ltid] = a0[gtid] + 0;
	barrier(CLK_LOCAL_MEM_FENCE);
	int tmp0 = 0;
	for(i=0;i<lsz;i++) tmp0 += c0[i];
	tmp0 -= 5*c0[ltid];
	b0[gtid] = (0+1)*(+tmp0);
	b1[gtid] = (1+1)*(+tmp0);
	b2[gtid] = (2+1)*(+tmp0);
	b3[gtid] = (3+1)*(+tmp0);
}

/* 3=5-2 */
__kernel void
test_block_2_3_kern(
	__global int* a0,
	__global int* a1,
	__global int* b0,
	__global int* b1,
	__global int* b2,
	__local int* c0,
	__local int* c1
)
{
	int i;
	uint gtid = get_global_id(0);
	uint ltid = get_local_id(0);
	size_t lsz = get_local_size(0);
	c0[ltid] = a0[gtid] + 0;
	c1[ltid] = a1[gtid] + 1;
	barrier(CLK_LOCAL_MEM_FENCE);
	int tmp0 = 0;
	int tmp1 = 0;
	for(i=0;i<lsz;i++) tmp0 += c0[i];
	for(i=0;i<lsz;i++) tmp1 += c1[i];
	tmp0 -= 5*c0[ltid];
	tmp1 -= 5*c1[ltid];
	b0[gtid] = (0+1)*(+tmp0+tmp1);
	b1[gtid] = (1+1)*(+tmp0+tmp1);
	b2[gtid] = (2+1)*(+tmp0+tmp1);
}

/* 2=5-3 */
__kernel void
test_block_3_2_kern(
	__global int* a0,
	__global int* a1,
	__global int* a2,
	__global int* b0,
	__global int* b1,
	__local int* c0,
	__local int* c1,
	__local int* c2
)
{
	int i;
	uint gtid = get_global_id(0);
	uint ltid = get_local_id(0);
	size_t lsz = get_local_size(0);
	c0[ltid] = a0[gtid] + 0;
	c1[ltid] = a1[gtid] + 1;
	c2[ltid] = a2[gtid] + 2;
	barrier(CLK_LOCAL_MEM_FENCE);
	int tmp0 = 0;
	int tmp1 = 0;
	int tmp2 = 0;
	for(i=0;i<lsz;i++) tmp0 += c0[i];
	for(i=0;i<lsz;i++) tmp1 += c1[i];
	for(i=0;i<lsz;i++) tmp2 += c2[i];
	tmp0 -= 5*c0[ltid];
	tmp1 -= 5*c1[ltid];
	tmp2 -= 5*c2[ltid];
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2);
	b1[gtid] = (1+1)*(+tmp0+tmp1+tmp2);
}

/* 1=5-4 */
__kernel void
test_block_4_1_kern(
	__global int* a0,
	__global int* a1,
	__global int* a2,
	__global int* a3,
	__global int* b0,
	__local int* c0,
	__local int* c1,
	__local int* c2,
	__local int* c3
)
{
	int i;
	uint gtid = get_global_id(0);
	uint ltid = get_local_id(0);
	size_t lsz = get_local_size(0);
	c0[ltid] = a0[gtid] + 0;
	c1[ltid] = a1[gtid] + 1;
	c2[ltid] = a2[gtid] + 2;
	c3[ltid] = a3[gtid] + 3;
	barrier(CLK_LOCAL_MEM_FENCE);
	int tmp0 = 0;
	int tmp1 = 0;
	int tmp2 = 0;
	int tmp3 = 0;
	for(i=0;i<lsz;i++) tmp0 += c0[i];
	for(i=0;i<lsz;i++) tmp1 += c1[i];
	for(i=0;i<lsz;i++) tmp2 += c2[i];
	for(i=0;i<lsz;i++) tmp3 += c3[i];
	tmp0 -= 5*c0[ltid];
	tmp1 -= 5*c1[ltid];
	tmp2 -= 5*c2[ltid];
	tmp3 -= 5*c3[ltid];
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2+tmp3);
}

/* 5=6-1 */
__kernel void
test_block_1_5_kern(
	__global int* a0,
	__global int* b0,
	__global int* b1,
	__global int* b2,
	__global int* b3,
	__global int* b4,
	__local int* c0
)
{
	int i;
	uint gtid = get_global_id(0);
	uint ltid = get_local_id(0);
	size_t lsz = get_local_size(0);
	c0[ltid] = a0[gtid] + 0;
	barrier(CLK_LOCAL_MEM_FENCE);
	int tmp0 = 0;
	for(i=0;i<lsz;i++) tmp0 += c0[i];
	tmp0 -= 5*c0[ltid];
	b0[gtid] = (0+1)*(+tmp0);
	b1[gtid] = (1+1)*(+tmp0);
	b2[gtid] = (2+1)*(+tmp0);
	b3[gtid] = (3+1)*(+tmp0);
	b4[gtid] = (4+1)*(+tmp0);
}

/* 4=6-2 */
__kernel void
test_block_2_4_kern(
	__global int* a0,
	__global int* a1,
	__global int* b0,
	__global int* b1,
	__global int* b2,
	__global int* b3,
	__local int* c0,
	__local int* c1
)
{
	int i;
	uint gtid = get_global_id(0);
	uint ltid = get_local_id(0);
	size_t lsz = get_local_size(0);
	c0[ltid] = a0[gtid] + 0;
	c1[ltid] = a1[gtid] + 1;
	barrier(CLK_LOCAL_MEM_FENCE);
	int tmp0 = 0;
	int tmp1 = 0;
	for(i=0;i<lsz;i++) tmp0 += c0[i];
	for(i=0;i<lsz;i++) tmp1 += c1[i];
	tmp0 -= 5*c0[ltid];
	tmp1 -= 5*c1[ltid];
	b0[gtid] = (0+1)*(+tmp0+tmp1);
	b1[gtid] = (1+1)*(+tmp0+tmp1);
	b2[gtid] = (2+1)*(+tmp0+tmp1);
	b3[gtid] = (3+1)*(+tmp0+tmp1);
}

/* 3=6-3 */
__kernel void
test_block_3_3_kern(
	__global int* a0,
	__global int* a1,
	__global int* a2,
	__global int* b0,
	__global int* b1,
	__global int* b2,
	__local int* c0,
	__local int* c1,
	__local int* c2
)
{
	int i;
	uint gtid = get_global_id(0);
	uint ltid = get_local_id(0);
	size_t lsz = get_local_size(0);
	c0[ltid] = a0[gtid] + 0;
	c1[ltid] = a1[gtid] + 1;
	c2[ltid] = a2[gtid] + 2;
	barrier(CLK_LOCAL_MEM_FENCE);
	int tmp0 = 0;
	int tmp1 = 0;
	int tmp2 = 0;
	for(i=0;i<lsz;i++) tmp0 += c0[i];
	for(i=0;i<lsz;i++) tmp1 += c1[i];
	for(i=0;i<lsz;i++) tmp2 += c2[i];
	tmp0 -= 5*c0[ltid];
	tmp1 -= 5*c1[ltid];
	tmp2 -= 5*c2[ltid];
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2);
	b1[gtid] = (1+1)*(+tmp0+tmp1+tmp2);
	b2[gtid] = (2+1)*(+tmp0+tmp1+tmp2);
}

/* 2=6-4 */
__kernel void
test_block_4_2_kern(
	__global int* a0,
	__global int* a1,
	__global int* a2,
	__global int* a3,
	__global int* b0,
	__global int* b1,
	__local int* c0,
	__local int* c1,
	__local int* c2,
	__local int* c3
)
{
	int i;
	uint gtid = get_global_id(0);
	uint ltid = get_local_id(0);
	size_t lsz = get_local_size(0);
	c0[ltid] = a0[gtid] + 0;
	c1[ltid] = a1[gtid] + 1;
	c2[ltid] = a2[gtid] + 2;
	c3[ltid] = a3[gtid] + 3;
	barrier(CLK_LOCAL_MEM_FENCE);
	int tmp0 = 0;
	int tmp1 = 0;
	int tmp2 = 0;
	int tmp3 = 0;
	for(i=0;i<lsz;i++) tmp0 += c0[i];
	for(i=0;i<lsz;i++) tmp1 += c1[i];
	for(i=0;i<lsz;i++) tmp2 += c2[i];
	for(i=0;i<lsz;i++) tmp3 += c3[i];
	tmp0 -= 5*c0[ltid];
	tmp1 -= 5*c1[ltid];
	tmp2 -= 5*c2[ltid];
	tmp3 -= 5*c3[ltid];
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2+tmp3);
	b1[gtid] = (1+1)*(+tmp0+tmp1+tmp2+tmp3);
}

/* 1=6-5 */
__kernel void
test_block_5_1_kern(
	__global int* a0,
	__global int* a1,
	__global int* a2,
	__global int* a3,
	__global int* a4,
	__global int* b0,
	__local int* c0,
	__local int* c1,
	__local int* c2,
	__local int* c3,
	__local int* c4
)
{
	int i;
	uint gtid = get_global_id(0);
	uint ltid = get_local_id(0);
	size_t lsz = get_local_size(0);
	c0[ltid] = a0[gtid] + 0;
	c1[ltid] = a1[gtid] + 1;
	c2[ltid] = a2[gtid] + 2;
	c3[ltid] = a3[gtid] + 3;
	c4[ltid] = a4[gtid] + 4;
	barrier(CLK_LOCAL_MEM_FENCE);
	int tmp0 = 0;
	int tmp1 = 0;
	int tmp2 = 0;
	int tmp3 = 0;
	int tmp4 = 0;
	for(i=0;i<lsz;i++) tmp0 += c0[i];
	for(i=0;i<lsz;i++) tmp1 += c1[i];
	for(i=0;i<lsz;i++) tmp2 += c2[i];
	for(i=0;i<lsz;i++) tmp3 += c3[i];
	for(i=0;i<lsz;i++) tmp4 += c4[i];
	tmp0 -= 5*c0[ltid];
	tmp1 -= 5*c1[ltid];
	tmp2 -= 5*c2[ltid];
	tmp3 -= 5*c3[ltid];
	tmp4 -= 5*c4[ltid];
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4);
}

/* 6=7-1 */
__kernel void
test_block_1_6_kern(
	__global int* a0,
	__global int* b0,
	__global int* b1,
	__global int* b2,
	__global int* b3,
	__global int* b4,
	__global int* b5,
	__local int* c0
)
{
	int i;
	uint gtid = get_global_id(0);
	uint ltid = get_local_id(0);
	size_t lsz = get_local_size(0);
	c0[ltid] = a0[gtid] + 0;
	barrier(CLK_LOCAL_MEM_FENCE);
	int tmp0 = 0;
	for(i=0;i<lsz;i++) tmp0 += c0[i];
	tmp0 -= 5*c0[ltid];
	b0[gtid] = (0+1)*(+tmp0);
	b1[gtid] = (1+1)*(+tmp0);
	b2[gtid] = (2+1)*(+tmp0);
	b3[gtid] = (3+1)*(+tmp0);
	b4[gtid] = (4+1)*(+tmp0);
	b5[gtid] = (5+1)*(+tmp0);
}

/* 5=7-2 */
__kernel void
test_block_2_5_kern(
	__global int* a0,
	__global int* a1,
	__global int* b0,
	__global int* b1,
	__global int* b2,
	__global int* b3,
	__global int* b4,
	__local int* c0,
	__local int* c1
)
{
	int i;
	uint gtid = get_global_id(0);
	uint ltid = get_local_id(0);
	size_t lsz = get_local_size(0);
	c0[ltid] = a0[gtid] + 0;
	c1[ltid] = a1[gtid] + 1;
	barrier(CLK_LOCAL_MEM_FENCE);
	int tmp0 = 0;
	int tmp1 = 0;
	for(i=0;i<lsz;i++) tmp0 += c0[i];
	for(i=0;i<lsz;i++) tmp1 += c1[i];
	tmp0 -= 5*c0[ltid];
	tmp1 -= 5*c1[ltid];
	b0[gtid] = (0+1)*(+tmp0+tmp1);
	b1[gtid] = (1+1)*(+tmp0+tmp1);
	b2[gtid] = (2+1)*(+tmp0+tmp1);
	b3[gtid] = (3+1)*(+tmp0+tmp1);
	b4[gtid] = (4+1)*(+tmp0+tmp1);
}

/* 4=7-3 */
__kernel void
test_block_3_4_kern(
	__global int* a0,
	__global int* a1,
	__global int* a2,
	__global int* b0,
	__global int* b1,
	__global int* b2,
	__global int* b3,
	__local int* c0,
	__local int* c1,
	__local int* c2
)
{
	int i;
	uint gtid = get_global_id(0);
	uint ltid = get_local_id(0);
	size_t lsz = get_local_size(0);
	c0[ltid] = a0[gtid] + 0;
	c1[ltid] = a1[gtid] + 1;
	c2[ltid] = a2[gtid] + 2;
	barrier(CLK_LOCAL_MEM_FENCE);
	int tmp0 = 0;
	int tmp1 = 0;
	int tmp2 = 0;
	for(i=0;i<lsz;i++) tmp0 += c0[i];
	for(i=0;i<lsz;i++) tmp1 += c1[i];
	for(i=0;i<lsz;i++) tmp2 += c2[i];
	tmp0 -= 5*c0[ltid];
	tmp1 -= 5*c1[ltid];
	tmp2 -= 5*c2[ltid];
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2);
	b1[gtid] = (1+1)*(+tmp0+tmp1+tmp2);
	b2[gtid] = (2+1)*(+tmp0+tmp1+tmp2);
	b3[gtid] = (3+1)*(+tmp0+tmp1+tmp2);
}

/* 3=7-4 */
__kernel void
test_block_4_3_kern(
	__global int* a0,
	__global int* a1,
	__global int* a2,
	__global int* a3,
	__global int* b0,
	__global int* b1,
	__global int* b2,
	__local int* c0,
	__local int* c1,
	__local int* c2,
	__local int* c3
)
{
	int i;
	uint gtid = get_global_id(0);
	uint ltid = get_local_id(0);
	size_t lsz = get_local_size(0);
	c0[ltid] = a0[gtid] + 0;
	c1[ltid] = a1[gtid] + 1;
	c2[ltid] = a2[gtid] + 2;
	c3[ltid] = a3[gtid] + 3;
	barrier(CLK_LOCAL_MEM_FENCE);
	int tmp0 = 0;
	int tmp1 = 0;
	int tmp2 = 0;
	int tmp3 = 0;
	for(i=0;i<lsz;i++) tmp0 += c0[i];
	for(i=0;i<lsz;i++) tmp1 += c1[i];
	for(i=0;i<lsz;i++) tmp2 += c2[i];
	for(i=0;i<lsz;i++) tmp3 += c3[i];
	tmp0 -= 5*c0[ltid];
	tmp1 -= 5*c1[ltid];
	tmp2 -= 5*c2[ltid];
	tmp3 -= 5*c3[ltid];
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2+tmp3);
	b1[gtid] = (1+1)*(+tmp0+tmp1+tmp2+tmp3);
	b2[gtid] = (2+1)*(+tmp0+tmp1+tmp2+tmp3);
}

/* 2=7-5 */
__kernel void
test_block_5_2_kern(
	__global int* a0,
	__global int* a1,
	__global int* a2,
	__global int* a3,
	__global int* a4,
	__global int* b0,
	__global int* b1,
	__local int* c0,
	__local int* c1,
	__local int* c2,
	__local int* c3,
	__local int* c4
)
{
	int i;
	uint gtid = get_global_id(0);
	uint ltid = get_local_id(0);
	size_t lsz = get_local_size(0);
	c0[ltid] = a0[gtid] + 0;
	c1[ltid] = a1[gtid] + 1;
	c2[ltid] = a2[gtid] + 2;
	c3[ltid] = a3[gtid] + 3;
	c4[ltid] = a4[gtid] + 4;
	barrier(CLK_LOCAL_MEM_FENCE);
	int tmp0 = 0;
	int tmp1 = 0;
	int tmp2 = 0;
	int tmp3 = 0;
	int tmp4 = 0;
	for(i=0;i<lsz;i++) tmp0 += c0[i];
	for(i=0;i<lsz;i++) tmp1 += c1[i];
	for(i=0;i<lsz;i++) tmp2 += c2[i];
	for(i=0;i<lsz;i++) tmp3 += c3[i];
	for(i=0;i<lsz;i++) tmp4 += c4[i];
	tmp0 -= 5*c0[ltid];
	tmp1 -= 5*c1[ltid];
	tmp2 -= 5*c2[ltid];
	tmp3 -= 5*c3[ltid];
	tmp4 -= 5*c4[ltid];
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4);
	b1[gtid] = (1+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4);
}

/* 1=7-6 */
__kernel void
test_block_6_1_kern(
	__global int* a0,
	__global int* a1,
	__global int* a2,
	__global int* a3,
	__global int* a4,
	__global int* a5,
	__global int* b0,
	__local int* c0,
	__local int* c1,
	__local int* c2,
	__local int* c3,
	__local int* c4,
	__local int* c5
)
{
	int i;
	uint gtid = get_global_id(0);
	uint ltid = get_local_id(0);
	size_t lsz = get_local_size(0);
	c0[ltid] = a0[gtid] + 0;
	c1[ltid] = a1[gtid] + 1;
	c2[ltid] = a2[gtid] + 2;
	c3[ltid] = a3[gtid] + 3;
	c4[ltid] = a4[gtid] + 4;
	c5[ltid] = a5[gtid] + 5;
	barrier(CLK_LOCAL_MEM_FENCE);
	int tmp0 = 0;
	int tmp1 = 0;
	int tmp2 = 0;
	int tmp3 = 0;
	int tmp4 = 0;
	int tmp5 = 0;
	for(i=0;i<lsz;i++) tmp0 += c0[i];
	for(i=0;i<lsz;i++) tmp1 += c1[i];
	for(i=0;i<lsz;i++) tmp2 += c2[i];
	for(i=0;i<lsz;i++) tmp3 += c3[i];
	for(i=0;i<lsz;i++) tmp4 += c4[i];
	for(i=0;i<lsz;i++) tmp5 += c5[i];
	tmp0 -= 5*c0[ltid];
	tmp1 -= 5*c1[ltid];
	tmp2 -= 5*c2[ltid];
	tmp3 -= 5*c3[ltid];
	tmp4 -= 5*c4[ltid];
	tmp5 -= 5*c5[ltid];
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4+tmp5);
}

/* 7=8-1 */
__kernel void
test_block_1_7_kern(
	__global int* a0,
	__global int* b0,
	__global int* b1,
	__global int* b2,
	__global int* b3,
	__global int* b4,
	__global int* b5,
	__global int* b6,
	__local int* c0
)
{
	int i;
	uint gtid = get_global_id(0);
	uint ltid = get_local_id(0);
	size_t lsz = get_local_size(0);
	c0[ltid] = a0[gtid] + 0;
	barrier(CLK_LOCAL_MEM_FENCE);
	int tmp0 = 0;
	for(i=0;i<lsz;i++) tmp0 += c0[i];
	tmp0 -= 5*c0[ltid];
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
test_block_2_6_kern(
	__global int* a0,
	__global int* a1,
	__global int* b0,
	__global int* b1,
	__global int* b2,
	__global int* b3,
	__global int* b4,
	__global int* b5,
	__local int* c0,
	__local int* c1
)
{
	int i;
	uint gtid = get_global_id(0);
	uint ltid = get_local_id(0);
	size_t lsz = get_local_size(0);
	c0[ltid] = a0[gtid] + 0;
	c1[ltid] = a1[gtid] + 1;
	barrier(CLK_LOCAL_MEM_FENCE);
	int tmp0 = 0;
	int tmp1 = 0;
	for(i=0;i<lsz;i++) tmp0 += c0[i];
	for(i=0;i<lsz;i++) tmp1 += c1[i];
	tmp0 -= 5*c0[ltid];
	tmp1 -= 5*c1[ltid];
	b0[gtid] = (0+1)*(+tmp0+tmp1);
	b1[gtid] = (1+1)*(+tmp0+tmp1);
	b2[gtid] = (2+1)*(+tmp0+tmp1);
	b3[gtid] = (3+1)*(+tmp0+tmp1);
	b4[gtid] = (4+1)*(+tmp0+tmp1);
	b5[gtid] = (5+1)*(+tmp0+tmp1);
}

/* 5=8-3 */
__kernel void
test_block_3_5_kern(
	__global int* a0,
	__global int* a1,
	__global int* a2,
	__global int* b0,
	__global int* b1,
	__global int* b2,
	__global int* b3,
	__global int* b4,
	__local int* c0,
	__local int* c1,
	__local int* c2
)
{
	int i;
	uint gtid = get_global_id(0);
	uint ltid = get_local_id(0);
	size_t lsz = get_local_size(0);
	c0[ltid] = a0[gtid] + 0;
	c1[ltid] = a1[gtid] + 1;
	c2[ltid] = a2[gtid] + 2;
	barrier(CLK_LOCAL_MEM_FENCE);
	int tmp0 = 0;
	int tmp1 = 0;
	int tmp2 = 0;
	for(i=0;i<lsz;i++) tmp0 += c0[i];
	for(i=0;i<lsz;i++) tmp1 += c1[i];
	for(i=0;i<lsz;i++) tmp2 += c2[i];
	tmp0 -= 5*c0[ltid];
	tmp1 -= 5*c1[ltid];
	tmp2 -= 5*c2[ltid];
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2);
	b1[gtid] = (1+1)*(+tmp0+tmp1+tmp2);
	b2[gtid] = (2+1)*(+tmp0+tmp1+tmp2);
	b3[gtid] = (3+1)*(+tmp0+tmp1+tmp2);
	b4[gtid] = (4+1)*(+tmp0+tmp1+tmp2);
}

/* 4=8-4 */
__kernel void
test_block_4_4_kern(
	__global int* a0,
	__global int* a1,
	__global int* a2,
	__global int* a3,
	__global int* b0,
	__global int* b1,
	__global int* b2,
	__global int* b3,
	__local int* c0,
	__local int* c1,
	__local int* c2,
	__local int* c3
)
{
	int i;
	uint gtid = get_global_id(0);
	uint ltid = get_local_id(0);
	size_t lsz = get_local_size(0);
	c0[ltid] = a0[gtid] + 0;
	c1[ltid] = a1[gtid] + 1;
	c2[ltid] = a2[gtid] + 2;
	c3[ltid] = a3[gtid] + 3;
	barrier(CLK_LOCAL_MEM_FENCE);
	int tmp0 = 0;
	int tmp1 = 0;
	int tmp2 = 0;
	int tmp3 = 0;
	for(i=0;i<lsz;i++) tmp0 += c0[i];
	for(i=0;i<lsz;i++) tmp1 += c1[i];
	for(i=0;i<lsz;i++) tmp2 += c2[i];
	for(i=0;i<lsz;i++) tmp3 += c3[i];
	tmp0 -= 5*c0[ltid];
	tmp1 -= 5*c1[ltid];
	tmp2 -= 5*c2[ltid];
	tmp3 -= 5*c3[ltid];
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2+tmp3);
	b1[gtid] = (1+1)*(+tmp0+tmp1+tmp2+tmp3);
	b2[gtid] = (2+1)*(+tmp0+tmp1+tmp2+tmp3);
	b3[gtid] = (3+1)*(+tmp0+tmp1+tmp2+tmp3);
}

/* 3=8-5 */
__kernel void
test_block_5_3_kern(
	__global int* a0,
	__global int* a1,
	__global int* a2,
	__global int* a3,
	__global int* a4,
	__global int* b0,
	__global int* b1,
	__global int* b2,
	__local int* c0,
	__local int* c1,
	__local int* c2,
	__local int* c3,
	__local int* c4
)
{
	int i;
	uint gtid = get_global_id(0);
	uint ltid = get_local_id(0);
	size_t lsz = get_local_size(0);
	c0[ltid] = a0[gtid] + 0;
	c1[ltid] = a1[gtid] + 1;
	c2[ltid] = a2[gtid] + 2;
	c3[ltid] = a3[gtid] + 3;
	c4[ltid] = a4[gtid] + 4;
	barrier(CLK_LOCAL_MEM_FENCE);
	int tmp0 = 0;
	int tmp1 = 0;
	int tmp2 = 0;
	int tmp3 = 0;
	int tmp4 = 0;
	for(i=0;i<lsz;i++) tmp0 += c0[i];
	for(i=0;i<lsz;i++) tmp1 += c1[i];
	for(i=0;i<lsz;i++) tmp2 += c2[i];
	for(i=0;i<lsz;i++) tmp3 += c3[i];
	for(i=0;i<lsz;i++) tmp4 += c4[i];
	tmp0 -= 5*c0[ltid];
	tmp1 -= 5*c1[ltid];
	tmp2 -= 5*c2[ltid];
	tmp3 -= 5*c3[ltid];
	tmp4 -= 5*c4[ltid];
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4);
	b1[gtid] = (1+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4);
	b2[gtid] = (2+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4);
}

/* 2=8-6 */
__kernel void
test_block_6_2_kern(
	__global int* a0,
	__global int* a1,
	__global int* a2,
	__global int* a3,
	__global int* a4,
	__global int* a5,
	__global int* b0,
	__global int* b1,
	__local int* c0,
	__local int* c1,
	__local int* c2,
	__local int* c3,
	__local int* c4,
	__local int* c5
)
{
	int i;
	uint gtid = get_global_id(0);
	uint ltid = get_local_id(0);
	size_t lsz = get_local_size(0);
	c0[ltid] = a0[gtid] + 0;
	c1[ltid] = a1[gtid] + 1;
	c2[ltid] = a2[gtid] + 2;
	c3[ltid] = a3[gtid] + 3;
	c4[ltid] = a4[gtid] + 4;
	c5[ltid] = a5[gtid] + 5;
	barrier(CLK_LOCAL_MEM_FENCE);
	int tmp0 = 0;
	int tmp1 = 0;
	int tmp2 = 0;
	int tmp3 = 0;
	int tmp4 = 0;
	int tmp5 = 0;
	for(i=0;i<lsz;i++) tmp0 += c0[i];
	for(i=0;i<lsz;i++) tmp1 += c1[i];
	for(i=0;i<lsz;i++) tmp2 += c2[i];
	for(i=0;i<lsz;i++) tmp3 += c3[i];
	for(i=0;i<lsz;i++) tmp4 += c4[i];
	for(i=0;i<lsz;i++) tmp5 += c5[i];
	tmp0 -= 5*c0[ltid];
	tmp1 -= 5*c1[ltid];
	tmp2 -= 5*c2[ltid];
	tmp3 -= 5*c3[ltid];
	tmp4 -= 5*c4[ltid];
	tmp5 -= 5*c5[ltid];
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4+tmp5);
	b1[gtid] = (1+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4+tmp5);
}

/* 1=8-7 */
__kernel void
test_block_7_1_kern(
	__global int* a0,
	__global int* a1,
	__global int* a2,
	__global int* a3,
	__global int* a4,
	__global int* a5,
	__global int* a6,
	__global int* b0,
	__local int* c0,
	__local int* c1,
	__local int* c2,
	__local int* c3,
	__local int* c4,
	__local int* c5,
	__local int* c6
)
{
	int i;
	uint gtid = get_global_id(0);
	uint ltid = get_local_id(0);
	size_t lsz = get_local_size(0);
	c0[ltid] = a0[gtid] + 0;
	c1[ltid] = a1[gtid] + 1;
	c2[ltid] = a2[gtid] + 2;
	c3[ltid] = a3[gtid] + 3;
	c4[ltid] = a4[gtid] + 4;
	c5[ltid] = a5[gtid] + 5;
	c6[ltid] = a6[gtid] + 6;
	barrier(CLK_LOCAL_MEM_FENCE);
	int tmp0 = 0;
	int tmp1 = 0;
	int tmp2 = 0;
	int tmp3 = 0;
	int tmp4 = 0;
	int tmp5 = 0;
	int tmp6 = 0;
	for(i=0;i<lsz;i++) tmp0 += c0[i];
	for(i=0;i<lsz;i++) tmp1 += c1[i];
	for(i=0;i<lsz;i++) tmp2 += c2[i];
	for(i=0;i<lsz;i++) tmp3 += c3[i];
	for(i=0;i<lsz;i++) tmp4 += c4[i];
	for(i=0;i<lsz;i++) tmp5 += c5[i];
	for(i=0;i<lsz;i++) tmp6 += c6[i];
	tmp0 -= 5*c0[ltid];
	tmp1 -= 5*c1[ltid];
	tmp2 -= 5*c2[ltid];
	tmp3 -= 5*c3[ltid];
	tmp4 -= 5*c4[ltid];
	tmp5 -= 5*c5[ltid];
	tmp6 -= 5*c6[ltid];
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4+tmp5+tmp6);
}

/* 8=9-1 */
__kernel void
test_block_1_8_kern(
	__global int* a0,
	__global int* b0,
	__global int* b1,
	__global int* b2,
	__global int* b3,
	__global int* b4,
	__global int* b5,
	__global int* b6,
	__global int* b7,
	__local int* c0
)
{
	int i;
	uint gtid = get_global_id(0);
	uint ltid = get_local_id(0);
	size_t lsz = get_local_size(0);
	c0[ltid] = a0[gtid] + 0;
	barrier(CLK_LOCAL_MEM_FENCE);
	int tmp0 = 0;
	for(i=0;i<lsz;i++) tmp0 += c0[i];
	tmp0 -= 5*c0[ltid];
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
test_block_2_7_kern(
	__global int* a0,
	__global int* a1,
	__global int* b0,
	__global int* b1,
	__global int* b2,
	__global int* b3,
	__global int* b4,
	__global int* b5,
	__global int* b6,
	__local int* c0,
	__local int* c1
)
{
	int i;
	uint gtid = get_global_id(0);
	uint ltid = get_local_id(0);
	size_t lsz = get_local_size(0);
	c0[ltid] = a0[gtid] + 0;
	c1[ltid] = a1[gtid] + 1;
	barrier(CLK_LOCAL_MEM_FENCE);
	int tmp0 = 0;
	int tmp1 = 0;
	for(i=0;i<lsz;i++) tmp0 += c0[i];
	for(i=0;i<lsz;i++) tmp1 += c1[i];
	tmp0 -= 5*c0[ltid];
	tmp1 -= 5*c1[ltid];
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
test_block_3_6_kern(
	__global int* a0,
	__global int* a1,
	__global int* a2,
	__global int* b0,
	__global int* b1,
	__global int* b2,
	__global int* b3,
	__global int* b4,
	__global int* b5,
	__local int* c0,
	__local int* c1,
	__local int* c2
)
{
	int i;
	uint gtid = get_global_id(0);
	uint ltid = get_local_id(0);
	size_t lsz = get_local_size(0);
	c0[ltid] = a0[gtid] + 0;
	c1[ltid] = a1[gtid] + 1;
	c2[ltid] = a2[gtid] + 2;
	barrier(CLK_LOCAL_MEM_FENCE);
	int tmp0 = 0;
	int tmp1 = 0;
	int tmp2 = 0;
	for(i=0;i<lsz;i++) tmp0 += c0[i];
	for(i=0;i<lsz;i++) tmp1 += c1[i];
	for(i=0;i<lsz;i++) tmp2 += c2[i];
	tmp0 -= 5*c0[ltid];
	tmp1 -= 5*c1[ltid];
	tmp2 -= 5*c2[ltid];
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2);
	b1[gtid] = (1+1)*(+tmp0+tmp1+tmp2);
	b2[gtid] = (2+1)*(+tmp0+tmp1+tmp2);
	b3[gtid] = (3+1)*(+tmp0+tmp1+tmp2);
	b4[gtid] = (4+1)*(+tmp0+tmp1+tmp2);
	b5[gtid] = (5+1)*(+tmp0+tmp1+tmp2);
}

/* 5=9-4 */
__kernel void
test_block_4_5_kern(
	__global int* a0,
	__global int* a1,
	__global int* a2,
	__global int* a3,
	__global int* b0,
	__global int* b1,
	__global int* b2,
	__global int* b3,
	__global int* b4,
	__local int* c0,
	__local int* c1,
	__local int* c2,
	__local int* c3
)
{
	int i;
	uint gtid = get_global_id(0);
	uint ltid = get_local_id(0);
	size_t lsz = get_local_size(0);
	c0[ltid] = a0[gtid] + 0;
	c1[ltid] = a1[gtid] + 1;
	c2[ltid] = a2[gtid] + 2;
	c3[ltid] = a3[gtid] + 3;
	barrier(CLK_LOCAL_MEM_FENCE);
	int tmp0 = 0;
	int tmp1 = 0;
	int tmp2 = 0;
	int tmp3 = 0;
	for(i=0;i<lsz;i++) tmp0 += c0[i];
	for(i=0;i<lsz;i++) tmp1 += c1[i];
	for(i=0;i<lsz;i++) tmp2 += c2[i];
	for(i=0;i<lsz;i++) tmp3 += c3[i];
	tmp0 -= 5*c0[ltid];
	tmp1 -= 5*c1[ltid];
	tmp2 -= 5*c2[ltid];
	tmp3 -= 5*c3[ltid];
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2+tmp3);
	b1[gtid] = (1+1)*(+tmp0+tmp1+tmp2+tmp3);
	b2[gtid] = (2+1)*(+tmp0+tmp1+tmp2+tmp3);
	b3[gtid] = (3+1)*(+tmp0+tmp1+tmp2+tmp3);
	b4[gtid] = (4+1)*(+tmp0+tmp1+tmp2+tmp3);
}

/* 4=9-5 */
__kernel void
test_block_5_4_kern(
	__global int* a0,
	__global int* a1,
	__global int* a2,
	__global int* a3,
	__global int* a4,
	__global int* b0,
	__global int* b1,
	__global int* b2,
	__global int* b3,
	__local int* c0,
	__local int* c1,
	__local int* c2,
	__local int* c3,
	__local int* c4
)
{
	int i;
	uint gtid = get_global_id(0);
	uint ltid = get_local_id(0);
	size_t lsz = get_local_size(0);
	c0[ltid] = a0[gtid] + 0;
	c1[ltid] = a1[gtid] + 1;
	c2[ltid] = a2[gtid] + 2;
	c3[ltid] = a3[gtid] + 3;
	c4[ltid] = a4[gtid] + 4;
	barrier(CLK_LOCAL_MEM_FENCE);
	int tmp0 = 0;
	int tmp1 = 0;
	int tmp2 = 0;
	int tmp3 = 0;
	int tmp4 = 0;
	for(i=0;i<lsz;i++) tmp0 += c0[i];
	for(i=0;i<lsz;i++) tmp1 += c1[i];
	for(i=0;i<lsz;i++) tmp2 += c2[i];
	for(i=0;i<lsz;i++) tmp3 += c3[i];
	for(i=0;i<lsz;i++) tmp4 += c4[i];
	tmp0 -= 5*c0[ltid];
	tmp1 -= 5*c1[ltid];
	tmp2 -= 5*c2[ltid];
	tmp3 -= 5*c3[ltid];
	tmp4 -= 5*c4[ltid];
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4);
	b1[gtid] = (1+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4);
	b2[gtid] = (2+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4);
	b3[gtid] = (3+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4);
}

/* 3=9-6 */
__kernel void
test_block_6_3_kern(
	__global int* a0,
	__global int* a1,
	__global int* a2,
	__global int* a3,
	__global int* a4,
	__global int* a5,
	__global int* b0,
	__global int* b1,
	__global int* b2,
	__local int* c0,
	__local int* c1,
	__local int* c2,
	__local int* c3,
	__local int* c4,
	__local int* c5
)
{
	int i;
	uint gtid = get_global_id(0);
	uint ltid = get_local_id(0);
	size_t lsz = get_local_size(0);
	c0[ltid] = a0[gtid] + 0;
	c1[ltid] = a1[gtid] + 1;
	c2[ltid] = a2[gtid] + 2;
	c3[ltid] = a3[gtid] + 3;
	c4[ltid] = a4[gtid] + 4;
	c5[ltid] = a5[gtid] + 5;
	barrier(CLK_LOCAL_MEM_FENCE);
	int tmp0 = 0;
	int tmp1 = 0;
	int tmp2 = 0;
	int tmp3 = 0;
	int tmp4 = 0;
	int tmp5 = 0;
	for(i=0;i<lsz;i++) tmp0 += c0[i];
	for(i=0;i<lsz;i++) tmp1 += c1[i];
	for(i=0;i<lsz;i++) tmp2 += c2[i];
	for(i=0;i<lsz;i++) tmp3 += c3[i];
	for(i=0;i<lsz;i++) tmp4 += c4[i];
	for(i=0;i<lsz;i++) tmp5 += c5[i];
	tmp0 -= 5*c0[ltid];
	tmp1 -= 5*c1[ltid];
	tmp2 -= 5*c2[ltid];
	tmp3 -= 5*c3[ltid];
	tmp4 -= 5*c4[ltid];
	tmp5 -= 5*c5[ltid];
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4+tmp5);
	b1[gtid] = (1+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4+tmp5);
	b2[gtid] = (2+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4+tmp5);
}

/* 2=9-7 */
__kernel void
test_block_7_2_kern(
	__global int* a0,
	__global int* a1,
	__global int* a2,
	__global int* a3,
	__global int* a4,
	__global int* a5,
	__global int* a6,
	__global int* b0,
	__global int* b1,
	__local int* c0,
	__local int* c1,
	__local int* c2,
	__local int* c3,
	__local int* c4,
	__local int* c5,
	__local int* c6
)
{
	int i;
	uint gtid = get_global_id(0);
	uint ltid = get_local_id(0);
	size_t lsz = get_local_size(0);
	c0[ltid] = a0[gtid] + 0;
	c1[ltid] = a1[gtid] + 1;
	c2[ltid] = a2[gtid] + 2;
	c3[ltid] = a3[gtid] + 3;
	c4[ltid] = a4[gtid] + 4;
	c5[ltid] = a5[gtid] + 5;
	c6[ltid] = a6[gtid] + 6;
	barrier(CLK_LOCAL_MEM_FENCE);
	int tmp0 = 0;
	int tmp1 = 0;
	int tmp2 = 0;
	int tmp3 = 0;
	int tmp4 = 0;
	int tmp5 = 0;
	int tmp6 = 0;
	for(i=0;i<lsz;i++) tmp0 += c0[i];
	for(i=0;i<lsz;i++) tmp1 += c1[i];
	for(i=0;i<lsz;i++) tmp2 += c2[i];
	for(i=0;i<lsz;i++) tmp3 += c3[i];
	for(i=0;i<lsz;i++) tmp4 += c4[i];
	for(i=0;i<lsz;i++) tmp5 += c5[i];
	for(i=0;i<lsz;i++) tmp6 += c6[i];
	tmp0 -= 5*c0[ltid];
	tmp1 -= 5*c1[ltid];
	tmp2 -= 5*c2[ltid];
	tmp3 -= 5*c3[ltid];
	tmp4 -= 5*c4[ltid];
	tmp5 -= 5*c5[ltid];
	tmp6 -= 5*c6[ltid];
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4+tmp5+tmp6);
	b1[gtid] = (1+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4+tmp5+tmp6);
}

/* 1=9-8 */
__kernel void
test_block_8_1_kern(
	__global int* a0,
	__global int* a1,
	__global int* a2,
	__global int* a3,
	__global int* a4,
	__global int* a5,
	__global int* a6,
	__global int* a7,
	__global int* b0,
	__local int* c0,
	__local int* c1,
	__local int* c2,
	__local int* c3,
	__local int* c4,
	__local int* c5,
	__local int* c6,
	__local int* c7
)
{
	int i;
	uint gtid = get_global_id(0);
	uint ltid = get_local_id(0);
	size_t lsz = get_local_size(0);
	c0[ltid] = a0[gtid] + 0;
	c1[ltid] = a1[gtid] + 1;
	c2[ltid] = a2[gtid] + 2;
	c3[ltid] = a3[gtid] + 3;
	c4[ltid] = a4[gtid] + 4;
	c5[ltid] = a5[gtid] + 5;
	c6[ltid] = a6[gtid] + 6;
	c7[ltid] = a7[gtid] + 7;
	barrier(CLK_LOCAL_MEM_FENCE);
	int tmp0 = 0;
	int tmp1 = 0;
	int tmp2 = 0;
	int tmp3 = 0;
	int tmp4 = 0;
	int tmp5 = 0;
	int tmp6 = 0;
	int tmp7 = 0;
	for(i=0;i<lsz;i++) tmp0 += c0[i];
	for(i=0;i<lsz;i++) tmp1 += c1[i];
	for(i=0;i<lsz;i++) tmp2 += c2[i];
	for(i=0;i<lsz;i++) tmp3 += c3[i];
	for(i=0;i<lsz;i++) tmp4 += c4[i];
	for(i=0;i<lsz;i++) tmp5 += c5[i];
	for(i=0;i<lsz;i++) tmp6 += c6[i];
	for(i=0;i<lsz;i++) tmp7 += c7[i];
	tmp0 -= 5*c0[ltid];
	tmp1 -= 5*c1[ltid];
	tmp2 -= 5*c2[ltid];
	tmp3 -= 5*c3[ltid];
	tmp4 -= 5*c4[ltid];
	tmp5 -= 5*c5[ltid];
	tmp6 -= 5*c6[ltid];
	tmp7 -= 5*c7[ltid];
	b0[gtid] = (0+1)*(+tmp0+tmp1+tmp2+tmp3+tmp4+tmp5+tmp6+tmp7);
}
