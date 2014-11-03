/* nbody.c version #1 */
#include <stdcl.h>

void nbody_init( int n, cl_float4* pos, cl_float4* vel );
void nbody_output( int n, cl_float4* pos, cl_float4* vel);

int main(int argc, char** argv) 
{

   int step,burst;

   int nparticle = 8192; /* MUST be a nice power of two for simplicity */
   int nparticle2 = nparticle/2;
   int nstep = 500;
   int nburst = 20; /* MUST divide the value of nstep without remainder */
   int nthread = 64; /* chosen for ATI Radeon HD 5870 */

   float dt = 0.0001;
   float eps = 0.0001;
   cl_float4* pos1 = (cl_float4*)clmalloc(stdgpu,nparticle*sizeof(cl_float4),0);
   cl_float4* pos1a = (cl_float4*)clmalloc(stdgpu,nparticle2*sizeof(cl_float4),0);
   cl_float4* pos1b = (cl_float4*)clmalloc(stdgpu,nparticle2*sizeof(cl_float4),0);
   cl_float4* pos2a = (cl_float4*)clmalloc(stdgpu,nparticle2*sizeof(cl_float4),0);
   cl_float4* pos2b = (cl_float4*)clmalloc(stdgpu,nparticle2*sizeof(cl_float4),0);
   cl_float4* vel = (cl_float4*)clmalloc(stdgpu,nparticle*sizeof(cl_float4),0);
   cl_float4* vela = (cl_float4*)clmalloc(stdgpu,nparticle2*sizeof(cl_float4),0);
   cl_float4* velb = (cl_float4*)clmalloc(stdgpu,nparticle2*sizeof(cl_float4),0);

   nbody_init(nparticle,pos1,vel);

   memcpy(pos1a,pos1,nparticle2*sizeof(cl_float4));
   memcpy(pos1b,pos1+nparticle2,nparticle2*sizeof(cl_float4));
   memcpy(vela,vel,nparticle2*sizeof(cl_float4));
   memcpy(velb,vel+nparticle2,nparticle2*sizeof(cl_float4));

   void* h = clopen(stdgpu,"nbody2_kern.cl",CLLD_NOW);
   cl_kernel krn = clsym(stdgpu,h,"nbody2_kern",CLLD_NOW);

   clndrange_t ndr2 = clndrange_init1d(0,nparticle2,nthread);

   clarg_set(stdgpu,krn,0,dt);
   clarg_set(stdgpu,krn,1,eps);
   clarg_set_local(stdgpu,krn,5,nthread*sizeof(cl_float4));

   clmsync(stdgpu,0,pos1a,CL_MEM_DEVICE|CL_EVENT_NOWAIT);
   clmsync(stdgpu,0,pos1b,CL_MEM_DEVICE|CL_EVENT_NOWAIT);
   clmsync(stdgpu,0,vela,CL_MEM_DEVICE|CL_EVENT_NOWAIT);
 
   clmsync(stdgpu,1,pos1a,CL_MEM_DEVICE|CL_EVENT_NOWAIT);
   clmsync(stdgpu,1,pos1b,CL_MEM_DEVICE|CL_EVENT_NOWAIT);
   clmsync(stdgpu,1,velb,CL_MEM_DEVICE|CL_EVENT_NOWAIT);

   for(step=0; step<nstep; step+=nburst) {

      for(burst=0; burst<nburst; burst+=2) {

         clarg_set_global(stdgpu,krn,2,pos1a);
         clarg_set_global(stdgpu,krn,3,pos2a);
         clarg_set_global(stdgpu,krn,4,vela);
         clarg_set_global(stdgpu,krn,6,pos1b);
         clfork(stdgpu,0,krn,&ndr2,CL_EVENT_NOWAIT);

         clarg_set_global(stdgpu,krn,2,pos1b);
         clarg_set_global(stdgpu,krn,3,pos2b);
         clarg_set_global(stdgpu,krn,4,velb);
         clarg_set_global(stdgpu,krn,6,pos1a);
         clfork(stdgpu,1,krn,&ndr2,CL_EVENT_NOWAIT);

         clmsync(stdgpu,0,pos2a,CL_MEM_HOST|CL_EVENT_NOWAIT);
         clmsync(stdgpu,1,pos2b,CL_MEM_HOST|CL_EVENT_NOWAIT);

         clflush(stdgpu,0,0);
         clflush(stdgpu,1,0);

         clwait(stdgpu,0,CL_KERNEL_EVENT|CL_MEM_EVENT);
         clwait(stdgpu,1,CL_KERNEL_EVENT|CL_MEM_EVENT);

         clmsync(stdgpu,0,pos2b,CL_MEM_DEVICE|CL_EVENT_NOWAIT);
         clmsync(stdgpu,1,pos2a,CL_MEM_DEVICE|CL_EVENT_NOWAIT);

         clarg_set_global(stdgpu,krn,2,pos2a);
         clarg_set_global(stdgpu,krn,3,pos1a);
         clarg_set_global(stdgpu,krn,4,vela);
         clarg_set_global(stdgpu,krn,6,pos2b);
         clfork(stdgpu,0,krn,&ndr2,CL_EVENT_NOWAIT);

         clarg_set_global(stdgpu,krn,2,pos2b);
         clarg_set_global(stdgpu,krn,3,pos1b);
         clarg_set_global(stdgpu,krn,4,velb);
         clarg_set_global(stdgpu,krn,6,pos2a);
         clfork(stdgpu,1,krn,&ndr2,CL_EVENT_NOWAIT);

         clmsync(stdgpu,0,pos1a,CL_MEM_HOST|CL_EVENT_NOWAIT);
         clmsync(stdgpu,1,pos1b,CL_MEM_HOST|CL_EVENT_NOWAIT);

         clflush(stdgpu,0,0);
         clflush(stdgpu,1,0);

         clwait(stdgpu,0,CL_KERNEL_EVENT|CL_MEM_EVENT);
         clwait(stdgpu,1,CL_KERNEL_EVENT|CL_MEM_EVENT);


         clmsync(stdgpu,0,pos1b,CL_MEM_DEVICE|CL_EVENT_WAIT);
         clmsync(stdgpu,1,pos1a,CL_MEM_DEVICE|CL_EVENT_WAIT);

      }

      clflush(stdgpu,0,0);
      clflush(stdgpu,1,0);

      clwait(stdgpu,0,CL_MEM_EVENT);
      clwait(stdgpu,1,CL_MEM_EVENT);

   }

   memcpy(pos1, pos1a, nparticle2*sizeof(cl_float4));
   memcpy(pos1+nparticle2, pos1b, nparticle2*sizeof(cl_float4));

   nbody_output(nparticle,pos1,vel);

   clclose(stdgpu,h);

   clfree(pos1);
   clfree(pos1a);
   clfree(pos1b);
   clfree(pos2a);
   clfree(pos2b);
   clfree(vel);
   clfree(vela);
   clfree(velb);  

}

