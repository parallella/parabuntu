/* clmulti_array_example.cpp 
 * 
 * This is a simple exmaple for Parallella showing the use of the C++
 * clmulti_array<> container that extends the BOOST multi_array class
 * to support device-shareable memory allocation.
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
#include <clmulti_array.h>

int main()
{
   cl_uint n = 1024;

	// use default contexts, if no ACCELERATOR use CPU 
   CLCONTEXT* cp = (stdacc)? stdacc : stdcpu;

   unsigned int devnum = 0;

   cl_kernel krn = clsym(cp,0,"matvecmult_kern",0);

   // allocate matrix and vectors using clmulti_array 
	typedef clmulti_array<cl_float,1> array1_t;
	typedef clmulti_array<cl_float,2> array2_t;
	array2_t aa(boost::extents[n][n]);
	array1_t b(boost::extents[n]);
	array1_t c(boost::extents[n]);

   // initialize matrix a[] and vector b[], zero c[] 
   for(int i=0;i<n;i++) for(int j=0;j<n;j++) aa[i][j] = 1.1f*i*j;
   for(int i=0;i<n;i++) b[i] = 2.2f*i;
   for(int i=0;i<n;i++) c[i] = 0.0f;

   // attach the vectors to the STDCL context 
   aa.clmattach(cp);
   b.clmattach(cp);
   c.clmattach(cp);

   // define the computational domain and workgroup size 
   clndrange_t ndr = clndrange_init1d( 0, n, 16);

   // non-blocking sync vectors a and b to device memory (copy to GPU)
   aa.clmsync(cp,devnum,CL_MEM_DEVICE|CL_EVENT_NOWAIT);
   b.clmsync(cp,devnum,CL_MEM_DEVICE|CL_EVENT_NOWAIT);

   // set the kernel arguments
   clarg_set(cp,krn,0,n);
   aa.clarg_set_global(cp,krn,1);
   b.clarg_set_global(cp,krn,2);
   c.clarg_set_global(cp,krn,3);

   // non-blocking fork of the OpenCL kernel to execute on the GPU
   clfork(cp,devnum,krn,&ndr,CL_EVENT_NOWAIT);

   // non-blocking sync vector c to host memory (copy back to host)
   c.clmsync(cp,0,CL_MEM_HOST|CL_EVENT_NOWAIT);

   // force execution of operations in command queue, non-blocking call
   clflush(cp,devnum,0);

   // block on completion of all operations in the command queue
   clwait(cp,devnum,CL_ALL_EVENT);

   for(int i=0;i<n;i++) printf("%f %f\n",b[i],c[i]);


   ///////////////////////////////////////////////////////////
   ///// now resize the vectors by adding some more values ...
   ///////////////////////////////////////////////////////////
  
	n *= 3;
 
   // OPTIONAL: for better performance, detach containers from STDCL context
   aa.clmdetach();
   b.clmdetach();
   c.clmdetach();


   // increase size of vectors three-fold 
   // ... note that *all* boost multi_array operations are valid
	aa.resize(boost::extents[n][n]);
	b.resize(boost::extents[n]);
	c.resize(boost::extents[n]);
   for(int i=0;i<n;i++) for(int j=0;j<n;j++) aa[i][j] = 1.1f*i*j;
   for(int i=0;i<n;i++) b[i] = 2.2f*i;
   for(int i=0;i<n;i++) c[i] = 0.0f;


   // OPTIONAL: ... if you dettached the containers, you must re-attach them
   aa.clmattach(cp);
   b.clmattach(cp);
   c.clmattach(cp);


   // now follow same steps used above to sync memory, execute kernel, etc.

   aa.clmsync(cp,devnum,CL_MEM_DEVICE|CL_EVENT_NOWAIT);
   b.clmsync(cp,devnum,CL_MEM_DEVICE|CL_EVENT_NOWAIT);

   clndrange_t ndr_threefold = clndrange_init1d( 0, n, 64);
   
   clarg_set(cp,krn,0,n);
   aa.clarg_set_global(cp,krn,1);
   b.clarg_set_global(cp,krn,2);
   c.clarg_set_global(cp,krn,3);

   clfork(cp,devnum,krn,&ndr_threefold,CL_EVENT_NOWAIT);

   c.clmsync(cp,0,CL_MEM_HOST|CL_EVENT_NOWAIT);

	clflush(cp,devnum,0);

   clwait(cp,devnum,CL_ALL_EVENT);

   for(int i=0;i<n;i++) printf("%f %f\n",b[i],c[i]);

}
