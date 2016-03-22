/* outerprod_three.cl */

__kernel void outerprod_three_kern( 
   __global float* a, 
	__global float* b, 
	__global float* c 
) 
{ 
   int i = get_global_id(0); 
   c[i] = 3.0f * a[i] * b[i];
}

