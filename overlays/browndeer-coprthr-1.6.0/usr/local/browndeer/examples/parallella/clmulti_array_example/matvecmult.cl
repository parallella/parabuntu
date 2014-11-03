/* matvecmult.cl */

__kernel void matvecmult_kern( 
   uint n, 
	__global float* aa, 
	__global float* b, 	
	__global float* c 
) 
{ 
   int i = get_global_id(0); 
   int j;
   float tmp = 0.0f;
   for(j=0;j<n;j++) tmp += aa[i*n+j] * b[j];
   c[i] = tmp;
}
