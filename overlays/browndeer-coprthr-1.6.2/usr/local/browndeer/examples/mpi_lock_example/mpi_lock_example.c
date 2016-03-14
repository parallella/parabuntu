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

#ifdef __FreeBSD__
   void* clh = clopen(cp,"outerprod.cl",CLLD_NOW);
   cl_kernel krn = clsym(cp,clh,"outerprod_kern",0);
#else
   cl_kernel krn = clsym(cp,0,"outerprod_kern",0);
#endif

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

#ifdef __FreeBSD__
   clclose(cp,clh);
#endif

	MPI_Finalize();

}
