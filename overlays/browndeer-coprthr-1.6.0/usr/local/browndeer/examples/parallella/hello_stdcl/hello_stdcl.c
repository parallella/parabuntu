/* hello_stdcl.c 
 *
 * This is a simple STDCL example for Parallella that performs a
 * matrix-vector multiplication on the Epiphany processor.
 * 
 * THIS FILE ONLY is placed in the public domain by Brown Deer Technology, LLC.
 * in January 2013. No copyright is claimed, and you may use it for any purpose
 * you like. There is ABSOLUTELY NO WARRANTY for any purpose, expressed or
 * implied, and any warranty of any kind is explicitly disclaimed.  This
 * statement applies ONLY TO THE COMPUTER SOURCE CODE IN THIS FILE and does
 * not extend to any other software, source code, documentation, or any other
 * materials in which it may be included, or with which it is co-distributed.
 */

/* DAR */

#include <stdio.h>
#include <stdcl.h>

int main()
{
   cl_uint n = 16;

	/* use default contexts, if no ACCELERATOR use CPU */
   CLCONTEXT* cp = (stdacc)? stdacc : stdcpu;

   unsigned int devnum = 0;

   cl_kernel krn = clsym(cp,0,"matvecmult_kern",0);

   /* allocate OpenCL device-sharable memory */
   cl_float* aa = (float*)clmalloc(cp,n*n*sizeof(cl_float),0);
   cl_float* b = (float*)clmalloc(cp,n*sizeof(cl_float),0);
   cl_float* c = (float*)clmalloc(cp,n*sizeof(cl_float),0);

   /* initialize vectors a[] and b[], zero c[] */
   int i,j; 
   for(i=0;i<n;i++) for(j=0;j<n;j++) aa[i*n+j] = 1.1f*i*j;
   for(i=0;i<n;i++) b[i] = 2.2f*i;
   for(i=0;i<n;i++) c[i] = 0.0f;

   /* define the computational domain and workgroup size */
   clndrange_t ndr = clndrange_init1d( 0, n, 16);

   /* non-blocking sync vectors a and b to device memory (copy to GPU)*/
   clmsync(cp,devnum,aa,CL_MEM_DEVICE|CL_EVENT_NOWAIT);
   clmsync(cp,devnum,b,CL_MEM_DEVICE|CL_EVENT_NOWAIT);

   /* non-blocking fork of the OpenCL kernel to execute on the GPU */
   clforka(cp,devnum,krn,&ndr,CL_EVENT_NOWAIT,n,aa,b,c);

   /* non-blocking sync vector c to host memory (copy back to host) */
   clmsync(cp,devnum,c,CL_MEM_HOST|CL_EVENT_NOWAIT);

   /* force execution of operations in command queue (non-blocking call) */
   clflush(cp,devnum,0);

   /* block on completion of operations in command queue */
   clwait(cp,devnum,CL_ALL_EVENT);

   for(i=0;i<n;i++) printf("%d %f %f\n",i,b[i],c[i]);

   clfree(aa);
   clfree(b);
   clfree(c);

}
