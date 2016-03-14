/* outerprod.cl */

#ifndef COEF
#define COEF 1
#endif

__kernel void outerprod_kern( 
   __global float* a, 
	__global float* b, 
	__global float* c 
) 
{ 
   int i = get_global_id(0); 
   c[i] = COEF * a[i] * b[i];
}

