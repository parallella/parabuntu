
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
fprintf(stderr,"error: open failed on ''\n",file); \
pfile=0; \
} else { \
filesz = fst.st_size; \
pfile = mmap(0,filesz,PROT_READ,MAP_PRIVATE,fd,0); \
} \
close(fd); \
} while(0);

#define __exit(err,line) \
do { fprintf("error code 0\n",err); exit(line); } while(0)

int main( int argc, char** argv )
{
int i,j;
cl_uint err; 

CONTEXT* cp = 0;
unsigned int devnum = 0;
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

size_t size4 = size/4;
if (!cp) exit(__LINE__);
if (devnum >= clgetndev(cp)) exit(__LINE__);
int* aa0 = (int*)clmalloc(cp,size*sizeof(int),0);
if (!aa0) exit(__LINE__);
int* bb0 = (int*)clmalloc(cp,size*sizeof(int),0);
if (!bb0) exit(__LINE__);
int* aa1 = (int*)clmalloc(cp,size*sizeof(int),0);
if (!aa1) exit(__LINE__);
int* bb1 = (int*)clmalloc(cp,size*sizeof(int),0);
if (!bb1) exit(__LINE__);
int* aa2 = (int*)clmalloc(cp,size*sizeof(int),0);
if (!aa2) exit(__LINE__);
int* bb2 = (int*)clmalloc(cp,size*sizeof(int),0);
if (!bb2) exit(__LINE__);
int* aa3 = (int*)clmalloc(cp,size*sizeof(int),0);
if (!aa3) exit(__LINE__);
int* bb3 = (int*)clmalloc(cp,size*sizeof(int),0);
if (!bb3) exit(__LINE__);
for(i=0;i<size;i++) { 
aa0[i] = i+13*0; bb0[i] = 0; 
aa1[i] = i+13*1; bb1[i] = 0; 
aa2[i] = i+13*2; bb2[i] = 0; 
aa3[i] = i+13*3; bb3[i] = 0; 
}
void* clh = clopen(cp,"test_arg_int4.cl",CLLD_NOW);
cl_kernel krn;
clndrange_t ndr = clndrange_init1d(0,size4,blocksize);
cl_event ev[10];
int sum,sum_correct;
float tol = pow(10.0,-8+log10((float)size));
krn = clsym(cp,clh,"test_arg_1_1_kern",CLLD_NOW);
if (!krn) exit(__LINE__);
if (!clmsync(cp,devnum,aa0,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
clarg_set_global(cp,krn,0,aa0);
clarg_set_global(cp,krn,1,bb0);
if (!clfork(cp,devnum,krn,&ndr,CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,bb0,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
clwait(cp,devnum,CL_KERNEL_EVENT|CL_MEM_EVENT);
sum_correct = 0;
for(i=0;i<1;++i)
for(j=0;j<1;++j)
sum_correct += (j+1)*( size*(size-1)/2 + 14*i*size + 6*size/4 );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
printf("(%d) sum 1 1 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
krn = clsym(cp,clh,"test_arg_1_1_kern",CLLD_NOW);
if (!krn) exit(__LINE__);
if (!clmsync(cp,devnum,aa0,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clforka(cp,devnum,krn,&ndr,CL_EVENT_NOWAIT,aa0,bb0))
exit(__LINE__);
if (!clmsync(cp,devnum,bb0,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
clwait(cp,devnum,CL_KERNEL_EVENT|CL_MEM_EVENT);
sum_correct = 0;
for(i=0;i<1;++i)
for(j=0;j<1;++j)
sum_correct += (j+1)*( size*(size-1)/2 + 14*i*size + 6*size/4 );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
printf("(%d) sum 1 1 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
krn = clsym(cp,clh,"test_arg_1_2_kern",CLLD_NOW);
if (!krn) exit(__LINE__);
if (!clmsync(cp,devnum,aa0,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
clarg_set_global(cp,krn,0,aa0);
clarg_set_global(cp,krn,1,bb0);
clarg_set_global(cp,krn,2,bb1);
if (!clfork(cp,devnum,krn,&ndr,CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,bb0,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,bb1,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
clwait(cp,devnum,CL_KERNEL_EVENT|CL_MEM_EVENT);
sum_correct = 0;
for(i=0;i<1;++i)
for(j=0;j<2;++j)
sum_correct += (j+1)*( size*(size-1)/2 + 14*i*size + 6*size/4 );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
printf("(%d) sum 1 2 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
krn = clsym(cp,clh,"test_arg_1_2_kern",CLLD_NOW);
if (!krn) exit(__LINE__);
if (!clmsync(cp,devnum,aa0,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clforka(cp,devnum,krn,&ndr,CL_EVENT_NOWAIT,aa0,bb0,bb1))
exit(__LINE__);
if (!clmsync(cp,devnum,bb0,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,bb1,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
clwait(cp,devnum,CL_KERNEL_EVENT|CL_MEM_EVENT);
sum_correct = 0;
for(i=0;i<1;++i)
for(j=0;j<2;++j)
sum_correct += (j+1)*( size*(size-1)/2 + 14*i*size + 6*size/4 );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
printf("(%d) sum 1 2 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
krn = clsym(cp,clh,"test_arg_2_1_kern",CLLD_NOW);
if (!krn) exit(__LINE__);
if (!clmsync(cp,devnum,aa0,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,aa1,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
clarg_set_global(cp,krn,0,aa0);
clarg_set_global(cp,krn,1,aa1);
clarg_set_global(cp,krn,2,bb0);
if (!clfork(cp,devnum,krn,&ndr,CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,bb0,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
clwait(cp,devnum,CL_KERNEL_EVENT|CL_MEM_EVENT);
sum_correct = 0;
for(i=0;i<2;++i)
for(j=0;j<1;++j)
sum_correct += (j+1)*( size*(size-1)/2 + 14*i*size + 6*size/4 );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
printf("(%d) sum 2 1 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
krn = clsym(cp,clh,"test_arg_2_1_kern",CLLD_NOW);
if (!krn) exit(__LINE__);
if (!clmsync(cp,devnum,aa0,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,aa1,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clforka(cp,devnum,krn,&ndr,CL_EVENT_NOWAIT,aa0,aa1,bb0))
exit(__LINE__);
if (!clmsync(cp,devnum,bb0,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
clwait(cp,devnum,CL_KERNEL_EVENT|CL_MEM_EVENT);
sum_correct = 0;
for(i=0;i<2;++i)
for(j=0;j<1;++j)
sum_correct += (j+1)*( size*(size-1)/2 + 14*i*size + 6*size/4 );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
printf("(%d) sum 2 1 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
krn = clsym(cp,clh,"test_arg_1_3_kern",CLLD_NOW);
if (!krn) exit(__LINE__);
if (!clmsync(cp,devnum,aa0,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
clarg_set_global(cp,krn,0,aa0);
clarg_set_global(cp,krn,1,bb0);
clarg_set_global(cp,krn,2,bb1);
clarg_set_global(cp,krn,3,bb2);
if (!clfork(cp,devnum,krn,&ndr,CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,bb0,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,bb1,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,bb2,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
clwait(cp,devnum,CL_KERNEL_EVENT|CL_MEM_EVENT);
sum_correct = 0;
for(i=0;i<1;++i)
for(j=0;j<3;++j)
sum_correct += (j+1)*( size*(size-1)/2 + 14*i*size + 6*size/4 );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
for(i=0;i<size;i++) sum += bb2[i];
printf("(%d) sum 1 3 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
krn = clsym(cp,clh,"test_arg_1_3_kern",CLLD_NOW);
if (!krn) exit(__LINE__);
if (!clmsync(cp,devnum,aa0,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clforka(cp,devnum,krn,&ndr,CL_EVENT_NOWAIT,aa0,bb0,bb1,bb2))
exit(__LINE__);
if (!clmsync(cp,devnum,bb0,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,bb1,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,bb2,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
clwait(cp,devnum,CL_KERNEL_EVENT|CL_MEM_EVENT);
sum_correct = 0;
for(i=0;i<1;++i)
for(j=0;j<3;++j)
sum_correct += (j+1)*( size*(size-1)/2 + 14*i*size + 6*size/4 );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
for(i=0;i<size;i++) sum += bb2[i];
printf("(%d) sum 1 3 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
krn = clsym(cp,clh,"test_arg_2_2_kern",CLLD_NOW);
if (!krn) exit(__LINE__);
if (!clmsync(cp,devnum,aa0,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,aa1,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
clarg_set_global(cp,krn,0,aa0);
clarg_set_global(cp,krn,1,aa1);
clarg_set_global(cp,krn,2,bb0);
clarg_set_global(cp,krn,3,bb1);
if (!clfork(cp,devnum,krn,&ndr,CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,bb0,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,bb1,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
clwait(cp,devnum,CL_KERNEL_EVENT|CL_MEM_EVENT);
sum_correct = 0;
for(i=0;i<2;++i)
for(j=0;j<2;++j)
sum_correct += (j+1)*( size*(size-1)/2 + 14*i*size + 6*size/4 );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
printf("(%d) sum 2 2 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
krn = clsym(cp,clh,"test_arg_2_2_kern",CLLD_NOW);
if (!krn) exit(__LINE__);
if (!clmsync(cp,devnum,aa0,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,aa1,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clforka(cp,devnum,krn,&ndr,CL_EVENT_NOWAIT,aa0,aa1,bb0,bb1))
exit(__LINE__);
if (!clmsync(cp,devnum,bb0,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,bb1,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
clwait(cp,devnum,CL_KERNEL_EVENT|CL_MEM_EVENT);
sum_correct = 0;
for(i=0;i<2;++i)
for(j=0;j<2;++j)
sum_correct += (j+1)*( size*(size-1)/2 + 14*i*size + 6*size/4 );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
printf("(%d) sum 2 2 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
krn = clsym(cp,clh,"test_arg_3_1_kern",CLLD_NOW);
if (!krn) exit(__LINE__);
if (!clmsync(cp,devnum,aa0,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,aa1,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,aa2,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
clarg_set_global(cp,krn,0,aa0);
clarg_set_global(cp,krn,1,aa1);
clarg_set_global(cp,krn,2,aa2);
clarg_set_global(cp,krn,3,bb0);
if (!clfork(cp,devnum,krn,&ndr,CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,bb0,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
clwait(cp,devnum,CL_KERNEL_EVENT|CL_MEM_EVENT);
sum_correct = 0;
for(i=0;i<3;++i)
for(j=0;j<1;++j)
sum_correct += (j+1)*( size*(size-1)/2 + 14*i*size + 6*size/4 );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
printf("(%d) sum 3 1 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
krn = clsym(cp,clh,"test_arg_3_1_kern",CLLD_NOW);
if (!krn) exit(__LINE__);
if (!clmsync(cp,devnum,aa0,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,aa1,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,aa2,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clforka(cp,devnum,krn,&ndr,CL_EVENT_NOWAIT,aa0,aa1,aa2,bb0))
exit(__LINE__);
if (!clmsync(cp,devnum,bb0,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
clwait(cp,devnum,CL_KERNEL_EVENT|CL_MEM_EVENT);
sum_correct = 0;
for(i=0;i<3;++i)
for(j=0;j<1;++j)
sum_correct += (j+1)*( size*(size-1)/2 + 14*i*size + 6*size/4 );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
printf("(%d) sum 3 1 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
krn = clsym(cp,clh,"test_arg_1_4_kern",CLLD_NOW);
if (!krn) exit(__LINE__);
if (!clmsync(cp,devnum,aa0,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
clarg_set_global(cp,krn,0,aa0);
clarg_set_global(cp,krn,1,bb0);
clarg_set_global(cp,krn,2,bb1);
clarg_set_global(cp,krn,3,bb2);
clarg_set_global(cp,krn,4,bb3);
if (!clfork(cp,devnum,krn,&ndr,CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,bb0,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,bb1,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,bb2,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,bb3,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
clwait(cp,devnum,CL_KERNEL_EVENT|CL_MEM_EVENT);
sum_correct = 0;
for(i=0;i<1;++i)
for(j=0;j<4;++j)
sum_correct += (j+1)*( size*(size-1)/2 + 14*i*size + 6*size/4 );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
for(i=0;i<size;i++) sum += bb2[i];
for(i=0;i<size;i++) sum += bb3[i];
printf("(%d) sum 1 4 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
krn = clsym(cp,clh,"test_arg_1_4_kern",CLLD_NOW);
if (!krn) exit(__LINE__);
if (!clmsync(cp,devnum,aa0,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clforka(cp,devnum,krn,&ndr,CL_EVENT_NOWAIT,aa0,bb0,bb1,bb2,bb3))
exit(__LINE__);
if (!clmsync(cp,devnum,bb0,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,bb1,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,bb2,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,bb3,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
clwait(cp,devnum,CL_KERNEL_EVENT|CL_MEM_EVENT);
sum_correct = 0;
for(i=0;i<1;++i)
for(j=0;j<4;++j)
sum_correct += (j+1)*( size*(size-1)/2 + 14*i*size + 6*size/4 );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
for(i=0;i<size;i++) sum += bb2[i];
for(i=0;i<size;i++) sum += bb3[i];
printf("(%d) sum 1 4 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
krn = clsym(cp,clh,"test_arg_2_3_kern",CLLD_NOW);
if (!krn) exit(__LINE__);
if (!clmsync(cp,devnum,aa0,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,aa1,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
clarg_set_global(cp,krn,0,aa0);
clarg_set_global(cp,krn,1,aa1);
clarg_set_global(cp,krn,2,bb0);
clarg_set_global(cp,krn,3,bb1);
clarg_set_global(cp,krn,4,bb2);
if (!clfork(cp,devnum,krn,&ndr,CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,bb0,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,bb1,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,bb2,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
clwait(cp,devnum,CL_KERNEL_EVENT|CL_MEM_EVENT);
sum_correct = 0;
for(i=0;i<2;++i)
for(j=0;j<3;++j)
sum_correct += (j+1)*( size*(size-1)/2 + 14*i*size + 6*size/4 );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
for(i=0;i<size;i++) sum += bb2[i];
printf("(%d) sum 2 3 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
krn = clsym(cp,clh,"test_arg_2_3_kern",CLLD_NOW);
if (!krn) exit(__LINE__);
if (!clmsync(cp,devnum,aa0,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,aa1,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clforka(cp,devnum,krn,&ndr,CL_EVENT_NOWAIT,aa0,aa1,bb0,bb1,bb2))
exit(__LINE__);
if (!clmsync(cp,devnum,bb0,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,bb1,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,bb2,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
clwait(cp,devnum,CL_KERNEL_EVENT|CL_MEM_EVENT);
sum_correct = 0;
for(i=0;i<2;++i)
for(j=0;j<3;++j)
sum_correct += (j+1)*( size*(size-1)/2 + 14*i*size + 6*size/4 );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
for(i=0;i<size;i++) sum += bb2[i];
printf("(%d) sum 2 3 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
krn = clsym(cp,clh,"test_arg_3_2_kern",CLLD_NOW);
if (!krn) exit(__LINE__);
if (!clmsync(cp,devnum,aa0,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,aa1,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,aa2,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
clarg_set_global(cp,krn,0,aa0);
clarg_set_global(cp,krn,1,aa1);
clarg_set_global(cp,krn,2,aa2);
clarg_set_global(cp,krn,3,bb0);
clarg_set_global(cp,krn,4,bb1);
if (!clfork(cp,devnum,krn,&ndr,CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,bb0,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,bb1,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
clwait(cp,devnum,CL_KERNEL_EVENT|CL_MEM_EVENT);
sum_correct = 0;
for(i=0;i<3;++i)
for(j=0;j<2;++j)
sum_correct += (j+1)*( size*(size-1)/2 + 14*i*size + 6*size/4 );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
printf("(%d) sum 3 2 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
krn = clsym(cp,clh,"test_arg_3_2_kern",CLLD_NOW);
if (!krn) exit(__LINE__);
if (!clmsync(cp,devnum,aa0,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,aa1,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,aa2,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clforka(cp,devnum,krn,&ndr,CL_EVENT_NOWAIT,aa0,aa1,aa2,bb0,bb1))
exit(__LINE__);
if (!clmsync(cp,devnum,bb0,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,bb1,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
clwait(cp,devnum,CL_KERNEL_EVENT|CL_MEM_EVENT);
sum_correct = 0;
for(i=0;i<3;++i)
for(j=0;j<2;++j)
sum_correct += (j+1)*( size*(size-1)/2 + 14*i*size + 6*size/4 );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
printf("(%d) sum 3 2 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
krn = clsym(cp,clh,"test_arg_4_1_kern",CLLD_NOW);
if (!krn) exit(__LINE__);
if (!clmsync(cp,devnum,aa0,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,aa1,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,aa2,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,aa3,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
clarg_set_global(cp,krn,0,aa0);
clarg_set_global(cp,krn,1,aa1);
clarg_set_global(cp,krn,2,aa2);
clarg_set_global(cp,krn,3,aa3);
clarg_set_global(cp,krn,4,bb0);
if (!clfork(cp,devnum,krn,&ndr,CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,bb0,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
clwait(cp,devnum,CL_KERNEL_EVENT|CL_MEM_EVENT);
sum_correct = 0;
for(i=0;i<4;++i)
for(j=0;j<1;++j)
sum_correct += (j+1)*( size*(size-1)/2 + 14*i*size + 6*size/4 );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
printf("(%d) sum 4 1 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
krn = clsym(cp,clh,"test_arg_4_1_kern",CLLD_NOW);
if (!krn) exit(__LINE__);
if (!clmsync(cp,devnum,aa0,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,aa1,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,aa2,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clmsync(cp,devnum,aa3,CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
if (!clforka(cp,devnum,krn,&ndr,CL_EVENT_NOWAIT,aa0,aa1,aa2,aa3,bb0))
exit(__LINE__);
if (!clmsync(cp,devnum,bb0,CL_MEM_HOST|CL_EVENT_NOWAIT))
exit(__LINE__);
clwait(cp,devnum,CL_KERNEL_EVENT|CL_MEM_EVENT);
sum_correct = 0;
for(i=0;i<4;++i)
for(j=0;j<1;++j)
sum_correct += (j+1)*( size*(size-1)/2 + 14*i*size + 6*size/4 );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
printf("(%d) sum 4 1 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
printf("done!\n");
clclose(cp,clh);
return(0);
}
