/* clvector_example.cpp 
 * 
 * This is a simple example for Parallella using the C++ clvector<> 
 * container that extends STL vector to support device-sharable memory 
 * allocation.
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
#include <clvector.h>

int main()
{
   size_t n = 1024;

	// use default contexts, if no ACCELERATOR use CPU 
   CLCONTEXT* cp = (stdacc)? stdacc : stdcpu;

   unsigned int devnum = 0;

   cl_kernel krn = clsym(cp,0,"outerprod_kern",0);

   // allocate vectors using clvector 
   clvector<float> a,b,c;

   // initialize vectors a[] and b[], zero c[] 
   for(int i=0;i<n;i++) a.push_back(1.1f*i);
   for(int i=0;i<n;i++) b.push_back(2.2f*i);
   for(int i=0;i<n;i++) c.push_back(0.0f);

   // attach the vectors to the STDCL context 
   a.clmattach(cp);
   b.clmattach(cp);
   c.clmattach(cp);

   // define the computational domain and workgroup size 
   clndrange_t ndr = clndrange_init1d( 0, n, 16);

   // non-blocking sync vectors a and b to device memory (copy to GPU)
   a.clmsync(cp,devnum,CL_MEM_DEVICE|CL_EVENT_NOWAIT);
   b.clmsync(cp,devnum,CL_MEM_DEVICE|CL_EVENT_NOWAIT);

   // set the kernel arguments
   a.clarg_set_global(cp,krn,0);
   b.clarg_set_global(cp,krn,1);
   c.clarg_set_global(cp,krn,2);

   // non-blocking fork of the OpenCL kernel to execute on the GPU
   clfork(cp,devnum,krn,&ndr,CL_EVENT_NOWAIT);

   // non-blocking sync vector c to host memory (copy back to host)
   c.clmsync(cp,0,CL_MEM_HOST|CL_EVENT_NOWAIT);

   // force execution of operations in command queue, non-blocking call
   clflush(cp,devnum,0);

   // block on completion of all operations in the command queue
   clwait(cp,devnum,CL_ALL_EVENT);

   for(int i=0;i<n;i++) printf("%f %f %f\n",a[i],b[i],c[i]);


   ///////////////////////////////////////////////////////////
   ///// now resize the vectors by adding some more values ...
   ///////////////////////////////////////////////////////////
   
   // OPTIONAL: for better performance, detach vectors from STDCL context
   a.clmdetach();
   b.clmdetach();
   c.clmdetach();

   // increase size of vectors ten-fold 
   // ... note that *all* STL vector operations are valid
   for(int i=n;i<n*10;i++) a.push_back(6.6f*i);
   for(int i=n;i<n*10;i++) b.push_back(7.7f*i);
   for(int i=n;i<n*10;i++) c.push_back(0.0f);

   // OPTIONAL: ... and if you dettached the vectors, you must re-attach the
   a.clmattach(cp);
   b.clmattach(cp);
   c.clmattach(cp);

   // now follow same steps used above to sync memory, execute kernel, etc.

   a.clmsync(cp,devnum,CL_MEM_DEVICE|CL_EVENT_NOWAIT);
   b.clmsync(cp,devnum,CL_MEM_DEVICE|CL_EVENT_NOWAIT);

   clndrange_t ndr_tenfold = clndrange_init1d( 0, n*10, 16);
   
   a.clarg_set_global(cp,krn,0);
   b.clarg_set_global(cp,krn,1);
   c.clarg_set_global(cp,krn,2);

   clfork(cp,devnum,krn,&ndr_tenfold,CL_EVENT_NOWAIT);

   c.clmsync(cp,0,CL_MEM_HOST|CL_EVENT_NOWAIT);

	clflush(cp,devnum,0);

   clwait(cp,devnum,CL_ALL_EVENT);

   for(int i=0;i<n*10;i++) printf("%f %f %f\n",a[i],b[i],c[i]);
 
}
