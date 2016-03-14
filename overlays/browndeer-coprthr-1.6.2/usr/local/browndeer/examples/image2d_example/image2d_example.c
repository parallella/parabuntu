/* image2d_example.c */

#include <stdio.h>
#include <stdcl.h>

int main()
{
   cl_uint n = 1024;

	/* use default contexts, if no GPU use CPU */
   CLCONTEXT* cp = (stdgpu)? stdgpu : stdcpu;

   unsigned int devnum = 0;

#ifdef __FreeBSD__
   void* clh = clopen(cp,"matvecmult_special.cl",CLLD_NOW);
   cl_kernel krn = clsym(cp,clh,"matvecmult_special_kern",0);
#else
   cl_kernel krn = clsym(cp,0,"matvecmult_special_kern",0);
#endif

   /* allocate OpenCL device-sharable memory */
   cl_float* aa = (float*)clmalloc(cp,n*n*sizeof(cl_float),0);
   cl_float* b = (float*)clmalloc(cp,n*sizeof(cl_float),0);
   cl_float* c = (float*)clmalloc(cp,n*sizeof(cl_float),0);

   /* initialize vectors a[] and b[], zero c[] */
   int i,j; 
   for(i=0;i<n;i++) for(j=0;j<n;j++) aa[i*n+j] = 1.1f*i*j;
   for(i=0;i<n;i++) b[i] = 2.2f*i;
   for(i=0;i<n;i++) c[i] = 0.0f;


	/***
	 *** Create a image2d allocation to be used as a read-only table.
	 *** The table will consist of a 24x24 array of float coefficients.
	 *** The clmctl() call is used to set the type and shape of the table.
	 *** Note that we will only use the first component of the float4 elements.
	 ***/	
	cl_float4* table 
		= (cl_float4*)clmalloc(cp,24*24*sizeof(cl_float4),CL_MEM_DETACHED);
	clmctl(table,CL_MCTL_SET_IMAGE2D,24,24,0);
	clmattach(cp,table);

	/* initialize the table to some contrived values */
	for(i=0;i<24;i++) for(j=0;j<24;j++) table[i*24+j].x = 0.125f*(i-j);


   /* define the computational domain and workgroup size */
   clndrange_t ndr = clndrange_init1d( 0, n, 64);

   /* non-blocking sync vectors a and b to device memory (copy to GPU)*/
   clmsync(cp,devnum,aa,CL_MEM_DEVICE|CL_EVENT_NOWAIT);
   clmsync(cp,devnum,b,CL_MEM_DEVICE|CL_EVENT_NOWAIT);
   clmsync(cp,devnum,table,CL_MEM_DEVICE|CL_EVENT_NOWAIT);

   /* set the kernel arguments */
   clarg_set(cp,krn,0,n);
   clarg_set_global(cp,krn,1,aa);
   clarg_set_global(cp,krn,2,b);
   clarg_set_global(cp,krn,3,c);
   clarg_set_global(cp,krn,4,table);

   /* non-blocking fork of the OpenCL kernel to execute on the GPU */
   clfork(cp,devnum,krn,&ndr,CL_EVENT_NOWAIT);

   /* non-blocking sync vector c to host memory (copy back to host) */
   clmsync(cp,0,c,CL_MEM_HOST|CL_EVENT_NOWAIT);

   /* block on completion of operations in command queue */
   clwait(cp,devnum,CL_ALL_EVENT);

   for(i=0;i<n;i++) printf("%d %f %f\n",i,b[i],c[i]);

   clfree(aa);
   clfree(b);
   clfree(c);

#ifdef __FreeBSD__
	clclose(cp,clh);
#endif

}
