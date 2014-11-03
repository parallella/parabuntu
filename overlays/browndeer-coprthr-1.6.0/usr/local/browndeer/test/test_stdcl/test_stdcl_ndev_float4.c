
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

#include "stdcl.h"

#define SIZE 128
#define BLOCKSIZE 4

#define __mapfile(file,filesz,pfile) do { \
int fd = open(file,O_RDONLY); \
struct stat fst; fstat(fd,&fst); \
if (fst.st_size == 0 || !S_ISREG(fst.st_mode)) { \
fprintf(stderr,"error: open failed on '%s'\n",file); \
pfile=0; \
} else { \
filesz = fst.st_size; \
pfile = mmap(0,filesz,PROT_READ,MAP_PRIVATE,fd,0); \
} \
close(fd); \
} while(0);

#define __exit(err,line) \
do { fprintf("error code %d\n",err); exit(line); } while(0)

int main( int argc, char** argv )
{
int i,j,n;
cl_uint err; 

CONTEXT* cp = 0;
unsigned int devnum = 0;;
size_t size = SIZE;
size_t blocksize = BLOCKSIZE;

i=1;
char* arg;
while(i<argc) {
arg=argv[i++];
if (!strncmp(arg,"--size",6)) size = atoi(argv[i++]);
else if (!strncmp(arg,"--blocksize",11)) blocksize = atoi(argv[i++]);
else if (!strncmp(arg,"--dev",6)) { cp = stddev; devnum = atoi(argv[i++]); }
else if (!strncmp(arg,"--cpu",6)) { cp = stdcpu; devnum = atoi(argv[i++]); }
else if (!strncmp(arg,"--gpu",6)) { cp = stdgpu; devnum = atoi(argv[i++]); }
else if (!strncmp(arg,"--acc",6)) { cp = stdacc; devnum = atoi(argv[i++]); }
else {
fprintf(stderr,"unrecognized option '%s'\n",arg);
exit(-1);
}
}

if (!cp) exit(__LINE__);
int ndev = devnum + 1;
if (ndev > clgetndev(cp)) exit(__LINE__);
size_t size4 = size/4;
size_t ns = ndev*size;
float** aa0 = (float**)malloc(ndev*sizeof(float*));
if (!aa0) exit(__LINE__);
float** bb0 = (float**)malloc(ndev*sizeof(float*));
if (!bb0) exit(__LINE__);
float** aa1 = (float**)malloc(ndev*sizeof(float*));
if (!aa1) exit(__LINE__);
float** bb1 = (float**)malloc(ndev*sizeof(float*));
if (!bb1) exit(__LINE__);
float** aa2 = (float**)malloc(ndev*sizeof(float*));
if (!aa2) exit(__LINE__);
float** bb2 = (float**)malloc(ndev*sizeof(float*));
if (!bb2) exit(__LINE__);
float** aa3 = (float**)malloc(ndev*sizeof(float*));
if (!aa3) exit(__LINE__);
float** bb3 = (float**)malloc(ndev*sizeof(float*));
if (!bb3) exit(__LINE__);
for(n=0;n<ndev;n++) {
aa0[n] = (float*)clmalloc(cp,size*sizeof(float),0);
if (!aa0[n]) exit(__LINE__);
bb0[n] = (float*)clmalloc(cp,size*sizeof(float),0);
if (!bb0[n]) exit(__LINE__);
aa1[n] = (float*)clmalloc(cp,size*sizeof(float),0);
if (!aa1[n]) exit(__LINE__);
bb1[n] = (float*)clmalloc(cp,size*sizeof(float),0);
if (!bb1[n]) exit(__LINE__);
aa2[n] = (float*)clmalloc(cp,size*sizeof(float),0);
if (!aa2[n]) exit(__LINE__);
bb2[n] = (float*)clmalloc(cp,size*sizeof(float),0);
if (!bb2[n]) exit(__LINE__);
aa3[n] = (float*)clmalloc(cp,size*sizeof(float),0);
if (!aa3[n]) exit(__LINE__);
bb3[n] = (float*)clmalloc(cp,size*sizeof(float),0);
if (!bb3[n]) exit(__LINE__);
}
for(n=0;n<ndev;n++) {
for(i=0;i<size;i++) { 
aa0[n][i] = (n*size+i)*1.1f+13.1f*0; bb0[n][i] = 0; 
aa1[n][i] = (n*size+i)*1.1f+13.1f*1; bb1[n][i] = 0; 
aa2[n][i] = (n*size+i)*1.1f+13.1f*2; bb2[n][i] = 0; 
aa3[n][i] = (n*size+i)*1.1f+13.1f*3; bb3[n][i] = 0; 
}
}
void* clh = clopen(cp,"test_arg_float4.cl",CLLD_NOW);
cl_kernel krn;
clndrange_t ndr = clndrange_init1d(0,size4,blocksize);
float sum,sum_correct;
float tol = pow(10.0,-8+log10((float)size));
krn = clsym(cp,clh,"test_arg_1_1_kern",CLLD_NOW);
if (!krn) exit(__LINE__);
for(n=0;n<ndev;n++) {
if (!clmsync(cp,n,aa0[n],CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
}
for(n=0;n<ndev;n++) {
clarg_set_global(cp,krn,0,aa0[n]);
clarg_set_global(cp,krn,1,bb0[n]);
if (!clfork(cp,n,krn,&ndr,CL_EVENT_NOWAIT))
exit(__LINE__);
}
for(n=0;n<ndev;n++) {
if (!clmsync(cp,n,bb0[n],CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
}
for(n=0;n<ndev;n++) {
clwait(cp,n,CL_KERNEL_EVENT|CL_MEM_EVENT);
}
sum_correct = 0;
for(i=0;i<1;++i)
for(j=0;j<1;++j)
sum_correct += (j+1.1)*( (ns*(ns-1)*1.1)/2 + (1+13.1)*i*ns + 0.1*ns + ns*0.4575);
sum = 0;
for(n=0;n<ndev;n++) {
for(i=0;i<size;i++) sum += bb0[n][i];
}
printf("(%e) sum 1 1 %e",sum_correct,sum);
printf(" relerr %e (%e)\n",fabs((sum-sum_correct)/sum_correct),tol);
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
krn = clsym(cp,clh,"test_arg_1_2_kern",CLLD_NOW);
if (!krn) exit(__LINE__);
for(n=0;n<ndev;n++) {
if (!clmsync(cp,n,aa0[n],CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
}
for(n=0;n<ndev;n++) {
clarg_set_global(cp,krn,0,aa0[n]);
clarg_set_global(cp,krn,1,bb0[n]);
clarg_set_global(cp,krn,2,bb1[n]);
if (!clfork(cp,n,krn,&ndr,CL_EVENT_NOWAIT))
exit(__LINE__);
}
for(n=0;n<ndev;n++) {
if (!clmsync(cp,n,bb0[n],CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,n,bb1[n],CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
}
for(n=0;n<ndev;n++) {
clwait(cp,n,CL_KERNEL_EVENT|CL_MEM_EVENT);
}
sum_correct = 0;
for(i=0;i<1;++i)
for(j=0;j<2;++j)
sum_correct += (j+1.1)*( (ns*(ns-1)*1.1)/2 + (1+13.1)*i*ns + 0.1*ns + ns*0.4575);
sum = 0;
for(n=0;n<ndev;n++) {
for(i=0;i<size;i++) sum += bb0[n][i];
for(i=0;i<size;i++) sum += bb1[n][i];
}
printf("(%e) sum 1 2 %e",sum_correct,sum);
printf(" relerr %e (%e)\n",fabs((sum-sum_correct)/sum_correct),tol);
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
krn = clsym(cp,clh,"test_arg_2_1_kern",CLLD_NOW);
if (!krn) exit(__LINE__);
for(n=0;n<ndev;n++) {
if (!clmsync(cp,n,aa0[n],CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,n,aa1[n],CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
}
for(n=0;n<ndev;n++) {
clarg_set_global(cp,krn,0,aa0[n]);
clarg_set_global(cp,krn,1,aa1[n]);
clarg_set_global(cp,krn,2,bb0[n]);
if (!clfork(cp,n,krn,&ndr,CL_EVENT_NOWAIT))
exit(__LINE__);
}
for(n=0;n<ndev;n++) {
if (!clmsync(cp,n,bb0[n],CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
}
for(n=0;n<ndev;n++) {
clwait(cp,n,CL_KERNEL_EVENT|CL_MEM_EVENT);
}
sum_correct = 0;
for(i=0;i<2;++i)
for(j=0;j<1;++j)
sum_correct += (j+1.1)*( (ns*(ns-1)*1.1)/2 + (1+13.1)*i*ns + 0.1*ns + ns*0.4575);
sum = 0;
for(n=0;n<ndev;n++) {
for(i=0;i<size;i++) sum += bb0[n][i];
}
printf("(%e) sum 2 1 %e",sum_correct,sum);
printf(" relerr %e (%e)\n",fabs((sum-sum_correct)/sum_correct),tol);
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
krn = clsym(cp,clh,"test_arg_1_3_kern",CLLD_NOW);
if (!krn) exit(__LINE__);
for(n=0;n<ndev;n++) {
if (!clmsync(cp,n,aa0[n],CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
}
for(n=0;n<ndev;n++) {
clarg_set_global(cp,krn,0,aa0[n]);
clarg_set_global(cp,krn,1,bb0[n]);
clarg_set_global(cp,krn,2,bb1[n]);
clarg_set_global(cp,krn,3,bb2[n]);
if (!clfork(cp,n,krn,&ndr,CL_EVENT_NOWAIT))
exit(__LINE__);
}
for(n=0;n<ndev;n++) {
if (!clmsync(cp,n,bb0[n],CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,n,bb1[n],CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,n,bb2[n],CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
}
for(n=0;n<ndev;n++) {
clwait(cp,n,CL_KERNEL_EVENT|CL_MEM_EVENT);
}
sum_correct = 0;
for(i=0;i<1;++i)
for(j=0;j<3;++j)
sum_correct += (j+1.1)*( (ns*(ns-1)*1.1)/2 + (1+13.1)*i*ns + 0.1*ns + ns*0.4575);
sum = 0;
for(n=0;n<ndev;n++) {
for(i=0;i<size;i++) sum += bb0[n][i];
for(i=0;i<size;i++) sum += bb1[n][i];
for(i=0;i<size;i++) sum += bb2[n][i];
}
printf("(%e) sum 1 3 %e",sum_correct,sum);
printf(" relerr %e (%e)\n",fabs((sum-sum_correct)/sum_correct),tol);
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
krn = clsym(cp,clh,"test_arg_2_2_kern",CLLD_NOW);
if (!krn) exit(__LINE__);
for(n=0;n<ndev;n++) {
if (!clmsync(cp,n,aa0[n],CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,n,aa1[n],CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
}
for(n=0;n<ndev;n++) {
clarg_set_global(cp,krn,0,aa0[n]);
clarg_set_global(cp,krn,1,aa1[n]);
clarg_set_global(cp,krn,2,bb0[n]);
clarg_set_global(cp,krn,3,bb1[n]);
if (!clfork(cp,n,krn,&ndr,CL_EVENT_NOWAIT))
exit(__LINE__);
}
for(n=0;n<ndev;n++) {
if (!clmsync(cp,n,bb0[n],CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,n,bb1[n],CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
}
for(n=0;n<ndev;n++) {
clwait(cp,n,CL_KERNEL_EVENT|CL_MEM_EVENT);
}
sum_correct = 0;
for(i=0;i<2;++i)
for(j=0;j<2;++j)
sum_correct += (j+1.1)*( (ns*(ns-1)*1.1)/2 + (1+13.1)*i*ns + 0.1*ns + ns*0.4575);
sum = 0;
for(n=0;n<ndev;n++) {
for(i=0;i<size;i++) sum += bb0[n][i];
for(i=0;i<size;i++) sum += bb1[n][i];
}
printf("(%e) sum 2 2 %e",sum_correct,sum);
printf(" relerr %e (%e)\n",fabs((sum-sum_correct)/sum_correct),tol);
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
krn = clsym(cp,clh,"test_arg_3_1_kern",CLLD_NOW);
if (!krn) exit(__LINE__);
for(n=0;n<ndev;n++) {
if (!clmsync(cp,n,aa0[n],CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,n,aa1[n],CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,n,aa2[n],CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
}
for(n=0;n<ndev;n++) {
clarg_set_global(cp,krn,0,aa0[n]);
clarg_set_global(cp,krn,1,aa1[n]);
clarg_set_global(cp,krn,2,aa2[n]);
clarg_set_global(cp,krn,3,bb0[n]);
if (!clfork(cp,n,krn,&ndr,CL_EVENT_NOWAIT))
exit(__LINE__);
}
for(n=0;n<ndev;n++) {
if (!clmsync(cp,n,bb0[n],CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
}
for(n=0;n<ndev;n++) {
clwait(cp,n,CL_KERNEL_EVENT|CL_MEM_EVENT);
}
sum_correct = 0;
for(i=0;i<3;++i)
for(j=0;j<1;++j)
sum_correct += (j+1.1)*( (ns*(ns-1)*1.1)/2 + (1+13.1)*i*ns + 0.1*ns + ns*0.4575);
sum = 0;
for(n=0;n<ndev;n++) {
for(i=0;i<size;i++) sum += bb0[n][i];
}
printf("(%e) sum 3 1 %e",sum_correct,sum);
printf(" relerr %e (%e)\n",fabs((sum-sum_correct)/sum_correct),tol);
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
krn = clsym(cp,clh,"test_arg_1_4_kern",CLLD_NOW);
if (!krn) exit(__LINE__);
for(n=0;n<ndev;n++) {
if (!clmsync(cp,n,aa0[n],CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
}
for(n=0;n<ndev;n++) {
clarg_set_global(cp,krn,0,aa0[n]);
clarg_set_global(cp,krn,1,bb0[n]);
clarg_set_global(cp,krn,2,bb1[n]);
clarg_set_global(cp,krn,3,bb2[n]);
clarg_set_global(cp,krn,4,bb3[n]);
if (!clfork(cp,n,krn,&ndr,CL_EVENT_NOWAIT))
exit(__LINE__);
}
for(n=0;n<ndev;n++) {
if (!clmsync(cp,n,bb0[n],CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,n,bb1[n],CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,n,bb2[n],CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,n,bb3[n],CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
}
for(n=0;n<ndev;n++) {
clwait(cp,n,CL_KERNEL_EVENT|CL_MEM_EVENT);
}
sum_correct = 0;
for(i=0;i<1;++i)
for(j=0;j<4;++j)
sum_correct += (j+1.1)*( (ns*(ns-1)*1.1)/2 + (1+13.1)*i*ns + 0.1*ns + ns*0.4575);
sum = 0;
for(n=0;n<ndev;n++) {
for(i=0;i<size;i++) sum += bb0[n][i];
for(i=0;i<size;i++) sum += bb1[n][i];
for(i=0;i<size;i++) sum += bb2[n][i];
for(i=0;i<size;i++) sum += bb3[n][i];
}
printf("(%e) sum 1 4 %e",sum_correct,sum);
printf(" relerr %e (%e)\n",fabs((sum-sum_correct)/sum_correct),tol);
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
krn = clsym(cp,clh,"test_arg_2_3_kern",CLLD_NOW);
if (!krn) exit(__LINE__);
for(n=0;n<ndev;n++) {
if (!clmsync(cp,n,aa0[n],CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,n,aa1[n],CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
}
for(n=0;n<ndev;n++) {
clarg_set_global(cp,krn,0,aa0[n]);
clarg_set_global(cp,krn,1,aa1[n]);
clarg_set_global(cp,krn,2,bb0[n]);
clarg_set_global(cp,krn,3,bb1[n]);
clarg_set_global(cp,krn,4,bb2[n]);
if (!clfork(cp,n,krn,&ndr,CL_EVENT_NOWAIT))
exit(__LINE__);
}
for(n=0;n<ndev;n++) {
if (!clmsync(cp,n,bb0[n],CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,n,bb1[n],CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,n,bb2[n],CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
}
for(n=0;n<ndev;n++) {
clwait(cp,n,CL_KERNEL_EVENT|CL_MEM_EVENT);
}
sum_correct = 0;
for(i=0;i<2;++i)
for(j=0;j<3;++j)
sum_correct += (j+1.1)*( (ns*(ns-1)*1.1)/2 + (1+13.1)*i*ns + 0.1*ns + ns*0.4575);
sum = 0;
for(n=0;n<ndev;n++) {
for(i=0;i<size;i++) sum += bb0[n][i];
for(i=0;i<size;i++) sum += bb1[n][i];
for(i=0;i<size;i++) sum += bb2[n][i];
}
printf("(%e) sum 2 3 %e",sum_correct,sum);
printf(" relerr %e (%e)\n",fabs((sum-sum_correct)/sum_correct),tol);
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
krn = clsym(cp,clh,"test_arg_3_2_kern",CLLD_NOW);
if (!krn) exit(__LINE__);
for(n=0;n<ndev;n++) {
if (!clmsync(cp,n,aa0[n],CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,n,aa1[n],CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,n,aa2[n],CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
}
for(n=0;n<ndev;n++) {
clarg_set_global(cp,krn,0,aa0[n]);
clarg_set_global(cp,krn,1,aa1[n]);
clarg_set_global(cp,krn,2,aa2[n]);
clarg_set_global(cp,krn,3,bb0[n]);
clarg_set_global(cp,krn,4,bb1[n]);
if (!clfork(cp,n,krn,&ndr,CL_EVENT_NOWAIT))
exit(__LINE__);
}
for(n=0;n<ndev;n++) {
if (!clmsync(cp,n,bb0[n],CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,n,bb1[n],CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
}
for(n=0;n<ndev;n++) {
clwait(cp,n,CL_KERNEL_EVENT|CL_MEM_EVENT);
}
sum_correct = 0;
for(i=0;i<3;++i)
for(j=0;j<2;++j)
sum_correct += (j+1.1)*( (ns*(ns-1)*1.1)/2 + (1+13.1)*i*ns + 0.1*ns + ns*0.4575);
sum = 0;
for(n=0;n<ndev;n++) {
for(i=0;i<size;i++) sum += bb0[n][i];
for(i=0;i<size;i++) sum += bb1[n][i];
}
printf("(%e) sum 3 2 %e",sum_correct,sum);
printf(" relerr %e (%e)\n",fabs((sum-sum_correct)/sum_correct),tol);
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
krn = clsym(cp,clh,"test_arg_4_1_kern",CLLD_NOW);
if (!krn) exit(__LINE__);
for(n=0;n<ndev;n++) {
if (!clmsync(cp,n,aa0[n],CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,n,aa1[n],CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,n,aa2[n],CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,n,aa3[n],CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
}
for(n=0;n<ndev;n++) {
clarg_set_global(cp,krn,0,aa0[n]);
clarg_set_global(cp,krn,1,aa1[n]);
clarg_set_global(cp,krn,2,aa2[n]);
clarg_set_global(cp,krn,3,aa3[n]);
clarg_set_global(cp,krn,4,bb0[n]);
if (!clfork(cp,n,krn,&ndr,CL_EVENT_NOWAIT))
exit(__LINE__);
}
for(n=0;n<ndev;n++) {
if (!clmsync(cp,n,bb0[n],CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
}
for(n=0;n<ndev;n++) {
clwait(cp,n,CL_KERNEL_EVENT|CL_MEM_EVENT);
}
sum_correct = 0;
for(i=0;i<4;++i)
for(j=0;j<1;++j)
sum_correct += (j+1.1)*( (ns*(ns-1)*1.1)/2 + (1+13.1)*i*ns + 0.1*ns + ns*0.4575);
sum = 0;
for(n=0;n<ndev;n++) {
for(i=0;i<size;i++) sum += bb0[n][i];
}
printf("(%e) sum 4 1 %e",sum_correct,sum);
printf(" relerr %e (%e)\n",fabs((sum-sum_correct)/sum_correct),tol);
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
printf("done!\n");
clclose(cp,clh);
return(0);
}
