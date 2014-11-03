
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
