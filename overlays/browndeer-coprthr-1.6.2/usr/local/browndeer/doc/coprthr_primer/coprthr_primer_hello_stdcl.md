# Hello STDCL

As with most programming, its best to begin with a hello world example that
captures the most important aspects of the API. This section will
describe a hello STDCL program that provides everything a programmer needs to
know to get started with the interface. A basic understanding of OpenCL is
helpful, but may not be necessary. The example will perform an (unoptimized)
matrix-vector product on a GPU.

First we need kernel code to define the algorithm that will run on the GPU.
This code will be stored in the file matvecmult.cl and compiled at run-time
using the just-in-time (JIT) compilation model of OpenCL. The kernel is
executed for each thread in the workgroup spanning the execution range which
consists of each element in the output vector.

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

Next, we need host-code to run on the CPU and manage the execution on the GPU.
The host code below contains everything needed to executute the above kernel.
By using STDCL this program is many times smaller than what would be required
to use OpenCL directly, and its also a lot simpler based on the use of better
syntax and semantics.

~~~
/* hello_stdcl.c */

#include <stdio.h>
#include <stdcl.h>

int main()
{
   stdcl_init(); /* requred for Windows only, Linux and FreeBSD will ignore this call */

   cl_uint n = 64;

   /* use default contexts, if no GPU use CPU */
   CLCONTEXT* cp = (stdgpu)? stdgpu : stdcpu;

   unsigned int devnum = 0;

   void* clh = clopen(cp,"matvecmult.cl",CLLD_NOW);
   cl_kernel krn = clsym(cp,clh,"matvecmult_kern",0);

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
   clndrange_t ndr = clndrange_init1d( 0, n, 64);

   /* non-blocking sync vectors a and b to device memory (copy to GPU) */
   clmsync(cp,devnum,aa,CL_MEM_DEVICE|CL_EVENT_NOWAIT);
   clmsync(cp,devnum,b,CL_MEM_DEVICE|CL_EVENT_NOWAIT);

   /* set the kernel arguments */
   clarg_set(cp,krn,0,n);
   clarg_set_global(cp,krn,1,aa);
   clarg_set_global(cp,krn,2,b);
   clarg_set_global(cp,krn,3,c);

   /* non-blocking fork of the OpenCL kernel to execute on the GPU */
   clfork(cp,devnum,krn,&ndr,CL_EVENT_NOWAIT);

   /* non-blocking sync vector c to host memory (copy back to host) */
   clmsync(cp,0,c,CL_MEM_HOST|CL_EVENT_NOWAIT);

   /* force execution of operations in command queue (non-blocking call) */
   clflush(cp,devnum,0);

   /* block on completion of operations in command queue */
   clwait(cp,devnum,CL_ALL_EVENT);

   for(i=0;i<n;i++) printf("%d %f %f\n",i,b[i],c[i]);

   clfree(aa);
   clfree(b);
   clfree(c);

   clclose(cp,clh);
}
~~~

Walking through the code with brevity, the steps are as follows: 
Select a context, using GPU if available, otherwise use CPU as a fallback.
Open the file containing the kernel code and build/compile it. Get a handle to
the kernel we want to execute.  Allocate device-sharable memory (using
semantics for allocating memory established decades ago - no membuffers to
worry about). Initialize/zero our input/output data.  Create our "N-dimension
range" over which the kernel will be executed - here N is 1024 and we use a
workgroup size of 64.  Transfer the input matrix and vector to the GPU using
the semantics of a memory sync to the device (non-blocking).  Next, fork the
kernel execution on the GPU (non-blocking), passing the kernel arguments
directly to the new clforka() call that will set the arguments automatically,
and then bring the results back to the host using another memory sync, but this
time we "sync to host" (both calls non-blocking).  At this point, depending on
the underlying OpenCL implementation, nothing may have actually happened, but
calling clflush() will get everything on the device going.  At this point we
(cl)wait for all of our non-blocking calls to finish.  All that is left is to
print the results and cleanup the allocations we created.

New to this release is support for Fortran bindings to STDCL. Quite simply,
this allows nearly all of the functionality provided by STDCL to be available
to Fortran programmers, providing a simple powerful interface to OpenCL
programming from Fortran applications. The example below is nearly identical to
the hello STDCL example above, except it is written in Fortran. On detail to
note is that the opaque OpenCL and STDCL types, which are merely pointers in
practice, must be referenced directly and generically as C pointers since
Fortran does not support type alising. 

~~~
!!!! hello_stdcl.f90

program main

  use iso_c_binding
  use stdcl

  implicit none

  integer(C_INT) :: n = 64
  type(C_PTR) :: cp
  integer(C_INT) :: devnum = 0
  type(C_PTR) :: clh
  type(C_PTR) :: krn
  type(C_PTR) :: p_aa, p_b, p_c
  real(C_FLOAT), pointer :: aa(:,:), b(:), c(:)
  integer :: i,j
  type(clndrange_struct), target :: ndr
  integer(C_INT) :: rc
  type(C_PTR) :: ev

  !!!! use default contexts, if no GPU use CPU 
  if (C_ASSOCIATED(stdgpu)) then
    cp = stdgpu
  else
    cp = stdcpu
  endif

  !!!! build CL program, get kernel
  clh = clopen(cp,"matvecmult.cl"//C_NULL_CHAR,CLLD_NOW);
  krn = clsym(cp,clh,"matvecmult_kern"//C_NULL_CHAR,0);

  !!!! allocate OpenCL device-sharable memory, associate with fortran pointers
  p_aa = clmalloc(cp,int8(n*n*4),0);
  call C_F_POINTER(p_aa,aa,[n,n])

  p_b = clmalloc(cp,int8(n*4),0);
  call C_F_POINTER(p_b,b,[n])

  p_c = clmalloc(cp,int8(n*4),0);
  call C_F_POINTER(p_c,c,[n])

  !!!! initialize vectors a[] and b[], zero c[] 
  do i = 1,n
    do j = 1,n
      aa(i,j) = 1.1 * (i-1) * (j-1)
    end do
  end do

  do i = 1,n
    b(i) = 2.2 * (i-1)
  end do 

  do i = 1,n
    c(i) = 0.0
  end do 

  !!!! define the computational domain and workgroup size 
  ndr = clndrange_init1d( 0, n, 64)

  !!!! non-blocking sync vectors a and b to device memory (copy to GPU)
  ev = clmsync(cp,devnum,p_aa,CL_MEM_DEVICE+CL_EVENT_NOWAIT)
  ev = clmsync(cp,devnum,p_b,CL_MEM_DEVICE+CL_EVENT_NOWAIT)

  !!!! set the kernel arguments 
  rc = clarg_set(cp,krn,0,n);
  rc = clarg_set_global(cp,krn,1,p_aa);
  rc = clarg_set_global(cp,krn,2,p_b);
  rc = clarg_set_global(cp,krn,3,p_c);

  !!!! non-blocking fork of the OpenCL kernel to execute on the GPU 
  ev = clfork(cp,devnum,krn,C_LOC(ndr),CL_EVENT_NOWAIT)

  !!!! non-blocking sync vector c to host memory (copy back to host) 
  ev = clmsync(cp,0,p_c,CL_MEM_HOST+CL_EVENT_NOWAIT)

  !!!! force execution of operations in command queue (non-blocking call) 
  rc = clflush(cp,devnum,0)

  !!!! block on completion of operations in command queue 
  ev = clwait(cp,devnum,CL_ALL_EVENT)

  do i = 1,n
    write(*,*) i,b(i),c(i)
  end do

  rc = clfree(p_aa)
  rc = clfree(p_b)
  rc = clfree(p_c)

  rc = clclose(cp,clh)

end
~~~

