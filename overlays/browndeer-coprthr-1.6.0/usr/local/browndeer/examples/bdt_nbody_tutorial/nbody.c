/* nbody.c version #1 */
#include <stdcl.h>

void nbody_init( int n, cl_float4* pos, cl_float4* vel );
void nbody_output( int n, cl_float4* pos, cl_float4* vel);

int main(int argc, char** argv) 
{

   int step,burst;

   int nparticle = 8192; /* MUST be a nice power of two for simplicity */
   int nstep = 500;
   int nburst = 20; /* MUST divide the value of nstep without remainder */
   int nthread = 64; /* chosen for ATI Radeon HD 5870 */

   float dt = 0.0001;
   float eps = 0.0001;
   cl_float4* pos1 = (cl_float4*)clmalloc(stdgpu,nparticle*sizeof(cl_float4),0);
   cl_float4* pos2 = (cl_float4*)clmalloc(stdgpu,nparticle*sizeof(cl_float4),0);
   cl_float4* vel = (cl_float4*)clmalloc(stdgpu,nparticle*sizeof(cl_float4),0);

   nbody_init(nparticle,pos1,vel);

   void* h = clopen(stdgpu,"nbody_kern.cl",CLLD_NOW);
   cl_kernel krn = clsym(stdgpu,h,"nbody_kern",CLLD_NOW);

   clndrange_t ndr = clndrange_init1d(0,nparticle,nthread);

   clarg_set(stdgpu,krn,0,dt);
   clarg_set(stdgpu,krn,1,eps);
   clarg_set_global(stdgpu,krn,4,vel);
   clarg_set_local(stdgpu,krn,5,nthread*sizeof(cl_float4));

	clmsync(stdgpu,0,pos1,CL_MEM_DEVICE|CL_EVENT_NOWAIT);
	clmsync(stdgpu,0,vel,CL_MEM_DEVICE|CL_EVENT_NOWAIT);

   for(step=0; step<nstep; step+=nburst) {

      for(burst=0; burst<nburst; burst+=2) {

         clarg_set_global(stdgpu,krn,2,pos1);
         clarg_set_global(stdgpu,krn,3,pos2);
         clfork(stdgpu,0,krn,&ndr,CL_EVENT_NOWAIT);

         clarg_set_global(stdgpu,krn,2,pos2);
         clarg_set_global(stdgpu,krn,3,pos1);
         clfork(stdgpu,0,krn,&ndr,CL_EVENT_NOWAIT);
      
      }

      clmsync(stdgpu,0,pos1,CL_MEM_HOST|CL_EVENT_NOWAIT);

      clwait(stdgpu,0,CL_KERNEL_EVENT|CL_MEM_EVENT);

   }

   nbody_output(nparticle,pos1,vel);

   clclose(stdgpu,h);

   clfree(pos1);
   clfree(pos2);
   clfree(vel);  
}

