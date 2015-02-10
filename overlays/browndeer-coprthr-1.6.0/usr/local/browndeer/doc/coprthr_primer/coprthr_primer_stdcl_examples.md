# More STDCL Examples

This section contains more examples designed to explain special behaviors or
 special features as opposed to typical use cases for "ordinary" STDCL code. The
 hello STDCL code example contains almost everything the average programmer
 needs to use the STDCL interface. 
Please note that some of these examples will not work with Windows 7. The 
examples that rely on CLETE will not work since templated metaprogramming can be 
problematic with the MSVS interpretation of the C++ standard. However, with this 
release support for the C++ containers clvector and clmulti_array now work, and 
those examples are now provided under the msvs2010/examples/ directory. 


## clopen_example - Managing OpenCL Kernel Code

STDCL provides different ways to manage OpenCL kernel code. The examples in
 clopen_example/ demonstrate the functionality. First we need some kernel code
 to use, and so we will start with a simple outer product kernel with macro
 defining a coefficient to included in the operation. In the kernel code below,
 note that if COEF is note defined it will be set to 1.

~~~
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
~~~

In the first example of the use of clopen() the simplest use case is shown. The 
file outerprod.cl is assumed to be available in the run directory for
 just-in-time (JIT) compilation. In the host code below, clopen() is given the
 filename containing the kernel code, which it will open and compile, returning
 a handle to the result in a manner patterned after the Linux dynamic loader
 call dlopen(). The kernel program is compiled and built immediately, and a
 subsequent call to clsym() returns the actual kernel object o opaque type
 cl_kernel, ready to use in subsequent OpenCL calls.

~~~
/* clopen_example1.c */

#include <stdio.h>
#include <stdcl.h>

int main()
{
   cl_uint n = 1024;

   /* use default contexts, if no GPU use CPU */
   CLCONTEXT* cp = (stdgpu)? stdgpu : stdcpu;

   unsigned int devnum = 0;

   /******************************************************************
    *** this example requires the .cl file to be available at run-time
    ******************************************************************/

   void* clh = clopen(cp,"outerprod.cl",CLLD_NOW);
   cl_kernel krn = clsym(cp,clh,"outerprod_kern",0);

   if (!krn) { fprintf(stderr,"error: no OpenCL kernel\n"); exit(-1); }

   /* allocate OpenCL device-sharable memory */
   cl_float* a = (float*)clmalloc(cp,n*sizeof(cl_float),0);
   cl_float* b = (float*)clmalloc(cp,n*sizeof(cl_float),0);
   cl_float* c = (float*)clmalloc(cp,n*sizeof(cl_float),0);

   /* initialize vectors a[] and b[], zero c[] */
   int i;
   for(i=0;i<n;i++) a[i] = 1.1f*i;
   for(i=0;i<n;i++) b[i] = 2.2f*i;
   for(i=0;i<n;i++) c[i] = 0.0f;

   /* non-blocking sync vectors a and b to device memory (copy to GPU)*/
   clmsync(cp,devnum,a,CL_MEM_DEVICE|CL_EVENT_WAIT);
   clmsync(cp,devnum,b,CL_MEM_DEVICE|CL_EVENT_WAIT);

   /* define the computational domain and workgroup size */
   clndrange_t ndr = clndrange_init1d( 0, n, 64);

   /* set the kernel arguments */
   clarg_set_global(cp,krn,0,a);
   clarg_set_global(cp,krn,1,b);
   clarg_set_global(cp,krn,2,c);

   /* non-blocking fork of the OpenCL kernel to execute on the GPU */
   clfork(cp,devnum,krn,&ndr,CL_EVENT_NOWAIT);

   /* block on completion of operations in command queue */
   clwait(cp,devnum,CL_ALL_EVENT);

   /* non-blocking sync vector c to host memory (copy back to host) */
   clmsync(cp,0,c,CL_MEM_HOST|CL_EVENT_NOWAIT);

   /* block on completion of operations in command queue */
   clwait(cp,devnum,CL_ALL_EVENT);

   for(i=0;i<n;i++) printf("%d %f %f %f\n",i,a[i],b[i],c[i]);

   clfree(a);
   clfree(b);
   clfree(c);

   clclose(cp,clh);
}
~~~

In example 2, we make use of the macro COEF to modify the outer product
 calculation so as to multiple the result by a fixed constant value. In order to
 do this we replace the previous clopen() and clsym() calls with the code shown
 below. Notice the flag CLLD_NOBUILD. This flag tells clopen() to defer the
 compilation and build. Then we call clbuild() which allows us to pass in
 arbitrary compiler options that will be used in the compilation of the kernel
 code. In this example we define the macro COEF to the value 2. The effect is
 that our code will now calculate the outer product and multiply it elementwise
 by 2. 

~~~
 ...
   /******************************************************************
    *** this example requires the .cl file to be available at run-time
    *** and shows how to pass compiler options to the OCL compiler
    ******************************************************************/

   void* clh = clopen(cp,"outerprod.cl",CLLD_NOBUILD);
   clbuild(cp,clh,"-D COEF=2", 0);
   cl_kernel krn = clsym(cp,clh,"outerprod_kern",0);
 ...
~~~

The final example only works on Linux and FreeBSD. (Apologies are extended to 
Windows developers.) In this example we show how to create single executables 
which eliminate the requirement to drag around .cl files with your application. 
This example requires the use of the tool clld to embed OpenCL kernel code 
directly into an ELF object that may be linked into the final executable. The 
code below again replaces the clopen()/clsym() calls. Notice that instead of 
passing a filename to clopen(), that argument is now set to 0 (NULL). When this 
is done, clopen() will return a handle to the OpenCL kernel code embeded within 
the executable, which will be compiled and built. The clsym() is then used as 
before to get the desired kernel.

~~~
 ...
   /*********************************************************************
    *** This example requires .cl file to be linked into the executable
    *** using clld.  Note that clopen is called without a filename.
    *********************************************************************/

   void* clh = clopen(cp,0,CLLD_NOW);
   cl_kernel krn = clsym(cp,clh,"outerprod_three_kern",0);
 ...
~~~

In order to differentiate this example from previous examples, we will embed the 
specialized kernel code shown below which merely calculates the outer product 
multiplied by a factor of 3. 

~~~
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
~~~

So how is this OpenCL kernel code embedded into the executable? Examine the
 Makefile. The key step is

~~~
clld --cl-source outerprod_three.cl
~~~

which generates the file out_clld.o that contains the OpenCL kernel source
 embedded as an ELF object. Then this object file is linked in to the executable
 just like any other object file. Its possible to see that the executable has
 embedded OpenCL kernel code by using the command readelf to examine the added
 ELF sections,

readelf -S clopen_example3.x

If you compare the output to a typical executable you will find 5 sections not 
normally found in executables, namely, 

~~~
.clprgs, .cltexts, .clprgb, .cltextb, and .clstrtab
~~~

These sections are used to embed the OpenCL kernel code so that clopen() can
 find and build the programs.



## Managing OpenCL Kernel Code ELIMINATED

New to this release is a feature of the clcc compiler tools that allows
strong binding of kernel symbols using a standard compilation model.
This completely eliminates the management of program and kernel objects.

Given the same outer product kernel used in the previous example,

~~~
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
~~~

we can compile the code using clcc using the options to cause strong symbol
binding in the compiled object code,

	clcc -j -k -c outerprod.cl

which will produce the file `outerprod.o`.  The host code is now modified as
shown below.

~~~
/* example_strong_binding.c */

#include <stdio.h>
#include <stdcl.h>

int main()
{
   cl_uint n = 1024;

   /* use default contexts, if no GPU use CPU */
   CLCONTEXT* cp = (stdgpu)? stdgpu : stdcpu;

   unsigned int devnum = 0;

   /* allocate OpenCL device-sharable memory */
   cl_float* a = (float*)clmalloc(cp,n*sizeof(cl_float),0);
   cl_float* b = (float*)clmalloc(cp,n*sizeof(cl_float),0);
   cl_float* c = (float*)clmalloc(cp,n*sizeof(cl_float),0);

   /* initialize vectors a[] and b[], zero c[] */
   int i;
   for(i=0;i<n;i++) a[i] = 1.1f*i;
   for(i=0;i<n;i++) b[i] = 2.2f*i;
   for(i=0;i<n;i++) c[i] = 0.0f;

   /* non-blocking sync vectors a and b to device memory (copy to GPU)*/
   clmsync(cp,devnum,a,CL_MEM_DEVICE|CL_EVENT_WAIT);
   clmsync(cp,devnum,b,CL_MEM_DEVICE|CL_EVENT_WAIT);

   /* define the computational domain and workgroup size */
   clndrange_t ndr = clndrange_init1d( 0, n, 64);

   /* non-blocking fork of the OpenCL kernel to execute on the GPU */
   clforka(cp,devnum,outerprod_kern,&ndr,CL_EVENT_NOWAIT,a,b,c);

   /* block on completion of operations in command queue */
   clwait(cp,devnum,CL_ALL_EVENT);

   /* non-blocking sync vector c to host memory (copy back to host) */
   clmsync(cp,0,c,CL_MEM_HOST|CL_EVENT_NOWAIT);

   /* block on completion of operations in command queue */
   clwait(cp,devnum,CL_ALL_EVENT);

   for(i=0;i<n;i++) printf("%d %f %f %f\n",i,a[i],b[i],c[i]);

   clfree(a);
   clfree(b);
   clfree(c);

   clclose(cp,clh);
}
~~~

Note that the clopen() and clsym() calls are eliminated and the symbol `krn` is replaced with the actual symbol from the kernel source code, `outerprod_kern`.

The host code is compiled using,

	gcc example_strong_binding.c outerprod.o

and the resulting executable will simple work, no management of OpenCL
programs or kernels, all of that management is eliminated.


## image2d_example - Using Texture Memory for Fast Lookup Tables

The following example demonstrates a non-trivial situation where one wishes to 
use texture memory to create fast lookup tables used by an OpenCL kernel. This 
is supported with STDCL using clmalloc() and clmctl(). The latter call can be 
used to manipulate a memory allocation created by clmalloc() and is patterned 
after the UNIX ioctl() call insofar as it is intended to be a generic utility to 
avoid the proliferation of specialized calls within the STDCL interface. The use 
of texture memory from within OpenCL remains somewhat clumsy from an HPC 
perspective, but the performance benefits it very attractive. The method for 
using texture memory with STDCL retains some of the awkward semantics of OpenCL, 
but introduces nothing further. 

The kernel code below shows the use of a simple table to create a specialized 
matrix-vector multiply operation. The calculation is a normal matrix-vector 
multiple, however, in the summation a coefficient is introduced that depends on 
the indices i and j which are used to lookup a coefficient in a 24 x 24 table 
stored as a read only image2d_t type memory.

~~~
/* matvecmult_special.cl */

__kernel void matvecmult_special_kern(
   uint n,
   __global float* aa,
   __global float* b,
   __global float* c,
   __read_only image2d_t table
)
{
   const sampler_t sampler0
      = CLK_NORMALIZED_COORDS_FALSE | CLK_ADDRESS_NONE | CLK_FILTER_NEAREST;

   int i = get_global_id(0);
   int j;
   float tmp = 0.0f;
   for(j=0;j<n;j++) {
      int ri = i%24;
      int rj = j%24;
      float4 coef = read_imagef(table, sampler0, (int2)(ri,rj));
      tmp += coef.x * aa[i*n+j] * b[j];
   }
   c[i] = tmp;
}
~~~

The host code below shows how one can allocate memory of OpenCL image2d_t type 
using the standard clmalloc() call along with performing modifications to the 
allocation using a call to clmctl(). The critical code is highlighted in red. 
The memory is allocated using a standard clmalloc() call with the flag 
CL_MEM_DETACHED. Using this flag is key since it prevents the memory from being 
attached to the CL context, allowing us to manipulate the allocation a bit 
first. We then call clmctl() with the operation CL_MCTL_IMAGE2D causing clmctl 
to perform an operation on the allocation so as to "mark" it as memory of type 
image2d_t. The arguments after the operation specification set the shape of the 
memory allocation, in this case its a 24 x 24 table. The final step is to attach 
the memory to our CL context, stdgpu in this case. The table can then be used as 
a kernel argument like any other global memory allocation, and the kernel can 
access the memory as read only image_t type.

~~~
/* image2d_example.c */

#include <stdio.h>
#include <stdcl.h>

int main()
{
   cl_uint n = 1024;

   /* use default contexts, if no GPU use CPU */
   CLCONTEXT* cp = (stdgpu)? stdgpu : stdcpu;

   unsigned int devnum = 0;

   void* clh = clopen(cp,"matvecmult_special.cl",CLLD_NOW);
   cl_kernel krn = clsym(cp,clh,"matvecmult_special_kern",0);

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

   clclose(cp,clh);
}
~~~


## mpi_lock_example - Transparent Multi-GPU Device Management

The STDCL interface now provides run-time inter-process device management,
 whereby environment variables can be used to create platform behaviors for
 typical multi-GPU (or multi-device in general) use cases. A typical example is
 assigning one GPU to each MPI process on a multi-GPU platform. It is certainly
 possible to have the MPI processes work out for themselves who should be using
 a particular device on a node with multiple devices, such a solution is
 inelegant. STDCL provides a better way. Assume we have a platform with 2 GPUs
 per node and we intend to launch 2 MPI processes per node. We would like each
 MPI process to have its own GPU. To achieve this simply set the environment
 variables,

	export STDGPU_MAX_NDEV=1;

	export STDGPU_LOCK=31415;

and ensure that these environment variables are exported by mpirun. (Use the -x 
option.) Note that there is nothing special about the number "31415" - the lock 
ID can be whatever you like. The effect of these environment variables is that 
when the default context stdgpu is created for each process it will only contain 
one GPU even though two are available on the node. Further, the common lock 
value used by each MPI process ensures that each processes will be provided a 
unique GPU, i.e., the processes will not share the same device. This is despite 
the fact that each MPI process "thinks" that it is using devnum 0 and makes no 
effort in its code to try to discern which device on the platform it should use. 

The example code uses the same outerprod.cl kernel code used in the
 clopen_example, which will not be repeated here. The host code is shown below,
 wherein MPI code has been added so as to allow the outer product of two vectors
 two be distributed across multiple MPI processes, each performing the
 calculation on a GPU provided to it exclusively. Notice that no where in the
 code is there an effort to determine which GPU should be used on a multi-GPU
 platform. For every processes, devnum=0.

~~~
/* mpi_lock_example.c */

#include <stdio.h>
#include <stdcl.h>
#include <mpi.h>

int main( int argc, char** argv )
{

   int procid, nproc;

   MPI_Init( &argc, &argv );
   MPI_Comm_rank( MPI_COMM_WORLD, &procid );
   MPI_Comm_size( MPI_COMM_WORLD, &nproc );

   cl_uint n = 64;


   /* use default contexts, if no GPU fail, need one GPU per MPI proc */
   CLCONTEXT* cp = (stdgpu)? stdgpu : 0;

   if (!cp) { fprintf(stderr,"error: no CL context\n"); exit(-1); }


   unsigned int devnum = 0; /* every MPI proc thinks its using devnum=0 */

   void* clh = clopen(cp,"outerprod.cl",CLLD_NOW);
   cl_kernel krn = clsym(cp,clh,"outerprod_kern",0);

   if (!krn) { fprintf(stderr,"error: no OpenCL kernel\n"); exit(-1); }

   /* allocate OpenCL device-sharable memory */
   cl_float* a = (float*)clmalloc(cp,n*sizeof(cl_float),0);
   cl_float* b = (float*)clmalloc(cp,n*sizeof(cl_float),0);
   cl_float* c = (float*)clmalloc(cp,n*sizeof(cl_float),0);

   /* initialize vectors a[] and b[], zero c[] */
   int i;
   for(i=0;i<n;i++) a[i] = 1.1f*(i+procid*n);
   for(i=0;i<n;i++) b[i] = 2.2f*(i+procid*n);
   for(i=0;i<n;i++) c[i] = 0.0f;

   /* non-blocking sync vectors a and b to device memory (copy to GPU)*/
   clmsync(cp,devnum,a,CL_MEM_DEVICE|CL_EVENT_WAIT);
   clmsync(cp,devnum,b,CL_MEM_DEVICE|CL_EVENT_WAIT);

   /* define the computational domain and workgroup size */
   clndrange_t ndr = clndrange_init1d( 0, n, 64);

   /* set the kernel arguments */
   clarg_set_global(cp,krn,0,a);
   clarg_set_global(cp,krn,1,b);
   clarg_set_global(cp,krn,2,c);

   /* non-blocking fork of the OpenCL kernel to execute on the GPU */
   clfork(cp,devnum,krn,&ndr,CL_EVENT_NOWAIT);

   /* block on completion of operations in command queue */
   clwait(cp,devnum,CL_ALL_EVENT);

   /* non-blocking sync vector c to host memory (copy back to host) */
   clmsync(cp,0,c,CL_MEM_HOST|CL_EVENT_NOWAIT);

   /* block on completion of operations in command queue */
   clwait(cp,devnum,CL_ALL_EVENT);


   /* now exchange results */
   float* d = (float*)malloc(nproc*n*sizeof(float));

   MPI_Allgather(c, n, MPI_FLOAT, d, n, MPI_FLOAT, MPI_COMM_WORLD);

   if (procid==0)
      for(i=0;i<nproc*n;i++) printf("%d %f\n",i,d[i]);

   free(d);

   clfree(a);
   clfree(b);
   clfree(c);

   clclose(cp,clh);

   MPI_Finalize();

}
~~~

The trick to allowing this simplicity in the host code is to simply set the
 correct environment variables when the job is run. As an example, the run
 script run_two_gpus.sh is shown below.

~~~
#!/bin/bash
export STDGPU_MAX_NDEV=1
export STDGPU_LOCK=31415
mpirun -x STDGPU_MAX_NDEV -x STDGPU_LOCK -np 2 ./mpi_lock_example.x 
rm -f /dev/shm/stdcl_ctx_lock*.31415
Notice that the last line in the script removes a file from /dev/shm (Linux
 shared memory). If your application crashes it may be necessary to remove the
 /dev/shm lock in order to re-run your job successfully.
~~~



## clvector - A C++ Container Using OpenCL Device-Sharable Memory

The SDTCL memory allocator clmalloc() can be combined with C++ container classes 
to allow for simple object-oriented data management on the host with seamless 
data transfer to OpenCL devices, e.g., GPU co-processors. The clvector container 
class inherits directly from STL vector, .i.e., it is not an attempt to recreate 
a vector class. Since the STL vector class can be templated to a user-defined 
memory allocator, the advantages of STDCL clmalloc() can be seen as compared to 
the OpenCL (micro) management of memory using membuffers. By design, clmalloc() 
follows the regular C semantics of memory allocation and can be used as a 
standard memory allocator. In addition to using a memory allocator for 
device-sharable memory, clvector adds a few methods to STL vector that may be 
used to enable the complete control over memory consistency provided by OpenCL. 
These additional methods are necessary because a distributed memory model was 
never envisioned when STL vector was designed.

The following example demonstrates the use of the clvector container class in a 
very simple example that calculates the outer product of two vectors. The
 example is not intended to demonstrate any performance advantage for executing
 this operation on a GPU, but rather is intended to demonstrate the use of the
 container in a very simple context. 

The OpenCL kernel code is copied here for convenience, but remains the same as 
that used in previous examples.

~~~
/* outerprod.cl */

__kernel void outerprod_kern(
   __global float* a,
   __global float* b,
   __global float* c
)
{
   int i = get_global_id(0);
   c[i] = a[i] * b[i];
}
~~~

The host code below shows the use of the clvector class in a simple example.

~~~
// clvector_example.cpp

#include <stdio.h>
#include <stdcl.h>
#include <clvector.h>

int main()
{
   stdcl_init(); /* requred for Windows only, Linux and FreeBSD will ignore this call */

   size_t n = 1024;

   // use default contexts, if no GPU use CPU
   CLCONTEXT* cp = (stdgpu)? stdgpu : stdcpu;
   unsigned int devnum = 0;

   void* clh = clopen(cp,"outerprod.cl",CLLD_NOW);
   cl_kernel krn = clsym(cp,clh,"outerprod_kern",0);

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
   clndrange_t ndr = clndrange_init1d( 0, n, 64);

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

   clndrange_t ndr_tenfold = clndrange_init1d( 0, n*10, 64);

   a.clarg_set_global(cp,krn,0);
   b.clarg_set_global(cp,krn,1);
   c.clarg_set_global(cp,krn,2);

   clfork(cp,devnum,krn,&ndr_tenfold,CL_EVENT_NOWAIT);

   c.clmsync(cp,0,CL_MEM_HOST|CL_EVENT_NOWAIT);

   clflush(cp,devnum,0);

   clwait(cp,devnum,CL_ALL_EVENT);

   for(int i=0;i<n*10;i++) printf("%f %f %f\n",a[i],b[i],c[i]);

   clclose(cp,clh);
}
~~~


## clmulti_array - Another C++ Container Using Device-Sharable Memory

As another example of a C++ container class using OpenCL device-sharable memory, 
boost::multi_array is used to create clmulti_array. This container inherits from 
the boost class and thus provides all of its functionality with the addition of 
using device-sharable memory for OpenCL devices. in the example code, a 
matrix-vector multiplication is carried out on the GPU where the data structures 
are manipulated on the host as data structures equivalent to 1D and 2D boost 
multi_arrays.

The kernel used here is the matrix-vector multiply kernel used in the Hello
 STDCL program, copied here for convenience.

~~~
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
~~~

The host code demonstrates how the containers can be manipulated on the host
 using the functionality of boost multi_array, while also providing the input
 and output data structures for the OpenCL kernels.

~~~
// clmulti_array_example.cpp

#include <stdio.h>
#include <stdcl.h>
#include <clmulti_array.h>

int main()
{
   stdcl_init(); /* requred for Windows only, Linux and FreeBSD will ignore this call */

   cl_uint n = 1024;

   // use default contexts, if no GPU use CPU
   CLCONTEXT* cp = (stdgpu)? stdgpu : stdcpu;
   unsigned int devnum = 0;

   void* clh = clopen(cp,"matvecmult.cl",CLLD_NOW);
   cl_kernel krn = clsym(cp,clh,"matvecmult_kern",0);

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
   clndrange_t ndr = clndrange_init1d( 0, n, 64);

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

   clclose(cp,clh);
}
~~~

## clvector and CLETE - GPU Acceleration with Little or No Effort

Notwithstanding vendor promotional material, GPU acceleration has remained
 difficult for average programmers and required learning alternative programming
 languages such as CUDA or OpenCL and re-working their code to introduce a
 programming model completely foreign to conventional C or C++. This reality
 hardly seems fair since it keeps GPU acceleration out of reach from the common
 programmer with no desire to exert any significant effort to rework their code. 

The example below combines CLETE (Compute Layer Expression Template Engine) with 
the clvector contain class described above to enable GPU acceleration with
 virtually no effort. The single burden on the programmer is that they must
 include a #define prior to including the clvector.h header. By defining the
 macro `__CLVECTOR_FULLAUTO`, C++ magic happens of the kind that only
 expression-templating can achieve. In the spirit of this example, being
 targeted toward programmers who really do not care how one accelerates code
 using a GPU, exactly how this works will not be explained here. (Its actually
 quite complicated.) All that will be described is the result. When the code
 below is compiled, it will be automatically instrumented and when run, it will
 automatically generate an OpenCL kernels and the computation inside the inner
 loop will be performed on the GPU, which is assumed to be available. What may
 at first glance appear to be a hack is actually quite robust, e.g., the
 expressions that can be evaluated may be of arbitrary size and contain any
 valid C++ operations. The usefulness of the technique is presently limited to
 pure SIMD operations on the elements of the containers. (This might be extended
 in the future.) The example below is self-contained. There is no corresponding
 OpenCL kernel code since none is required of the programmer. For the curious,
 you can see the auto-generated kernel code by setting the environment variable
 COPRTHR_LOG_AUTOKERN, in which case it will be written out to a file in the run
 directory.

~~~
// clete_clvector_example.cpp

#include <iostream>
using namespace std;

#include "Timer.h"

///////////////////////////////////////////////////////////////////////////////
// #define __CLVECTOR_FULLAUTO to enable CLETE automatic GPU acceleration
// for pure SIMD operations on clvector data objects.
//
// Set the environmaent variable COPRTHR_LOG_AUTOKERN to see the automatically
// generated OpenCL kernels used to execute the computation on GPU.
//
// With the #define commented out standard expression-templating is used
// to efficiently execute the computation on the CPU.
//////////////////////////////////////////////////////////////////////////////

#include <stdcl.h>
//#define __CLVECTOR_FULLAUTO
#include <clvector.h>

int main()
{
   Setup(0);
   Reset(0);

   int n = 1048576;

   clvector<float> a,b,c,d,e;

   for (int i=0; i<n; ++i) {
      a.push_back(1.1f*i);
      b.push_back(2.2f*i);
      c.push_back(3.3f*i);
      d.push_back(1.0f*i);
      e.push_back(0.0f);
   }

   Start(0);
   for(int iter=0; iter<10; iter++) {
      e = a + b + 2112.0f * b + sqrt(d) - a*b*c*d + c*sqrt(a) + a*cos(c);
      a = a + log(fabs(e));
   }
   Stop(0);
   double t = GetElapsedTime(0);

   for (int i=n-10; i<n; ++i) {
      cout << " a(" << i << ") = " << a[i]
            << " b(" << i << ") = " << b[i]
            << " c(" << i << ") = " << c[i]
            << " d(" << i << ") = " << d[i]
            << " e(" << i << ") = " << e[i]
            << endl;
   }

   printf("compute time %f (sec)\n",t);

}
~~~


## clmulti_array and CLETE - Another Example of Automatic GPU Acceleration

The example below is identical to the previous section, but in this case
 demonstrates that the same C++ magic trick can be peformed using clmulti_array.
 For help with the syntax, see the boost::multi_array documentation since
 clmulti_array inherits from this class and provides a superset of
 functionality.

~~~
// clete_clmulti_array_example.cpp

#include <iostream>
using namespace std;

#include "Timer.h"

///////////////////////////////////////////////////////////////////////////////
// #define __CLMULTI_ARRAY_FULLAUTO to enable CLETE automatic GPU acceleration
// for pure SIMD operations on clvector data objects.
//
// Set the environmaent variable COPRTHR_LOG_AUTOKERN to see the automatically
// generated OpenCL kernels used to execute the computation on GPU.
//
// With the #define commented out standard expression-templating is used
// to efficiently execute the computation on the CPU.
//////////////////////////////////////////////////////////////////////////////

#include <stdcl.h>
#define __CLMULTI_ARRAY_FULLAUTO
#include <clmulti_array.h>

int main()
{
   Setup(0);
   Reset(0);

   typedef clmulti_array< float, 1 > array1_t;
   typedef clmulti_array< float, 2 > array2_t;
   typedef clmulti_array< float, 3 > array3_t;
   typedef clmulti_array< float, 4 > array4_t;

   array1_t a(boost::extents[100]);
   array2_t b(boost::extents[100][30]);
   array3_t c(boost::extents[100][30][45]);
   array4_t d(boost::extents[100][30][45][60]);
   array4_t x(boost::extents[100][30][45][60]);

   for(int i = 0; i<100; i++) {
      a[i] = i;
      for(int j=0; j<30; j++) {
         b[i][j] = i*j;
         for(int k=0; k<45; k++) {
            c[i][j][k] = i+j+k;
            for(int l=0; l<60; l++) d[i][j][k][l] = i*j*k*l;
         }
      }
   }

   Start(0);
   for(int iter=0;iter<10;iter++) {
      x = a*b*c*d + sqrt(d) -81.0f + pow(c*d,0.33f);
      for(int i = 0; i<100; i++) a[i] = cos(x[i][0][0][0]);
   }
   Stop(0);
   double t = GetElapsedTime(0);

   for(int i=0;i<10;i++) cout<<i<<" "<<x[i][i][i][i]<<endl;

   cout<<"compute time "<<t<<" (sec)\n";

}
~~~


## clcontext_info_example

One nice feature of STDCL is that it provides default contexts that are ready to 
use by the programmer. In some cases, it might be interesting or useful to 
examine exactly what is contained in a give context. The following example 
exercises some utilty routines that can be used to query a CL context for a 
description of what they contain.

~~~
/* clcontext_info_example.c */

#include <stdio.h>
#include <stdcl.h>

int main()
{
   CLCONTEXT* cp;

   cp = stddev;

   if (cp) {
      printf("\n***** stddev:\n");
      int ndev = clgetndev(cp);

      struct clstat_info stat_info;
      clstat(cp,&stat_info);

      struct cldev_info* dev_info
         = (struct cldev_info*)malloc(ndev*sizeof(struct cldev_info));
      clgetdevinfo(cp,dev_info);

      clfreport_devinfo(stdout,ndev,dev_info);

      if (dev_info) free(dev_info);
   }


   cp = stdcpu;

   if (cp) {
      printf("\n***** stdcpu:\n");
      int ndev = clgetndev(cp);

      struct clstat_info stat_info;
      clstat(cp,&stat_info);

      struct cldev_info* dev_info
         = (struct cldev_info*)malloc(ndev*sizeof(struct cldev_info));
      clgetdevinfo(cp,dev_info);

      clfreport_devinfo(stdout,ndev,dev_info);

      if (dev_info) free(dev_info);
   }


   cp = stdgpu;

   if (cp) {
      printf("\n***** stdgpu:\n");
      int ndev = clgetndev(cp);

      struct clstat_info stat_info;
      clstat(cp,&stat_info);

      struct cldev_info* dev_info
         = (struct cldev_info*)malloc(ndev*sizeof(struct cldev_info));
      clgetdevinfo(cp,dev_info);

      clfreport_devinfo(stdout,ndev,dev_info);

      if (dev_info) free(dev_info);
   }

}
~~~


## bdt_nbody and bdt_em3d

The COPRTHR SDK example/ directory also contains two demo applications -
 bdt_nbody and bdt_em3d. The N-body demo (bdt_nbody) is very similar to the BDT
 NBody Tutorial, however, the source code is a bit more complex since it
 includes an OpenCL display and the kernel is optimized for performance. The 3D
 FDTD electromegnetic demo (bdt_em3d) also provides an OpenGL display. Note that
 due to the interaction with OpenGL, these examples sometimes have difficulty
 working properly. The issue is normally a problem with the installed OpenGL
 utility libraries.
