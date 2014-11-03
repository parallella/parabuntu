
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
int i,j,n;
cl_uint err; 

CONTEXT* cp = 0;
unsigned int ndev = 0;
size_t size = SIZE;
size_t blocksize = BLOCKSIZE;

i=1;
char* arg;
while(i<argc) {
arg=argv[i++];
if (!strncmp(arg,"--size",6)) size = atoi(argv[i++]);
else if (!strncmp(arg,"--blocksize",11)) blocksize = atoi(argv[i++]);
else if (!strncmp(arg,"--dev",6)) { cp = stddev; ndev = atoi(argv[i++]); }
else if (!strncmp(arg,"--cpu",6)) { cp = stdcpu; ndev = atoi(argv[i++]); }
else if (!strncmp(arg,"--gpu",6)) { cp = stdgpu; ndev = atoi(argv[i++]); }
else {
fprintf(stderr,"unrecognized option ''\n",arg);
exit(-1);
}
}

if (!cp) exit(__LINE__);
if (ndev > clgetndev(cp)) exit(__LINE__);

//// create array of arrays for each one based on ndev

int** aa0 = (int**)malloc(ndev*sizeof(int*));
int** aa1 = (int**)malloc(ndev*sizeof(int*));
int** aa2 = (int**)malloc(ndev*sizeof(int*));
int** aa3 = (int**)malloc(ndev*sizeof(int*));
int** aa4 = (int**)malloc(ndev*sizeof(int*));
int** aa5 = (int**)malloc(ndev*sizeof(int*));
int** aa6 = (int**)malloc(ndev*sizeof(int*));
int** aa7 = (int**)malloc(ndev*sizeof(int*));
int** bb0 = (int**)malloc(ndev*sizeof(int*));
int** bb1 = (int**)malloc(ndev*sizeof(int*));
int** bb2 = (int**)malloc(ndev*sizeof(int*));
int** bb3 = (int**)malloc(ndev*sizeof(int*));
int** bb4 = (int**)malloc(ndev*sizeof(int*));
int** bb5 = (int**)malloc(ndev*sizeof(int*));
int** bb6 = (int**)malloc(ndev*sizeof(int*));
int** bb7 = (int**)malloc(ndev*sizeof(int*));

for(n=0;n<ndev;n++) {
aa0[n] = (int*)clmalloc(cp,size*sizeof(int),0);
if (!aa0) exit(__LINE__);
bb0[n] = (int*)clmalloc(cp,size*sizeof(int),0);
if (!bb0) exit(__LINE__);
aa1[n] = (int*)clmalloc(cp,size*sizeof(int),0);
if (!aa1) exit(__LINE__);
bb1[n] = (int*)clmalloc(cp,size*sizeof(int),0);
if (!bb1) exit(__LINE__);
aa2[n] = (int*)clmalloc(cp,size*sizeof(int),0);
if (!aa2) exit(__LINE__);
bb2[n] = (int*)clmalloc(cp,size*sizeof(int),0);
if (!bb2) exit(__LINE__);
aa3[n] = (int*)clmalloc(cp,size*sizeof(int),0);
if (!aa3) exit(__LINE__);
bb3[n] = (int*)clmalloc(cp,size*sizeof(int),0);
if (!bb3) exit(__LINE__);
aa4[n] = (int*)clmalloc(cp,size*sizeof(int),0);
if (!aa4) exit(__LINE__);
bb4[n] = (int*)clmalloc(cp,size*sizeof(int),0);
if (!bb4) exit(__LINE__);
aa5[n] = (int*)clmalloc(cp,size*sizeof(int),0);
if (!aa5) exit(__LINE__);
bb5[n] = (int*)clmalloc(cp,size*sizeof(int),0);
if (!bb5) exit(__LINE__);
aa6[n] = (int*)clmalloc(cp,size*sizeof(int),0);
if (!aa6) exit(__LINE__);
bb6[n] = (int*)clmalloc(cp,size*sizeof(int),0);
if (!bb6) exit(__LINE__);
aa7[n] = (int*)clmalloc(cp,size*sizeof(int),0);
if (!aa7) exit(__LINE__);
bb7[n] = (int*)clmalloc(cp,size*sizeof(int),0);
if (!bb7) exit(__LINE__);
}

for(n=0;n<ndev;n++) { 
for(i=0;i<size;i++) { 
aa0[n][i] = n*size+i+13*0; bb0[n][i] = 0; 
aa1[n][i] = n*size+i+13*1; bb1[n][i] = 0; 
aa2[n][i] = n*size+i+13*2; bb2[n][i] = 0; 
aa3[n][i] = n*size+i+13*3; bb3[n][i] = 0; 
aa4[n][i] = n*size+i+13*4; bb4[n][i] = 0; 
aa5[n][i] = n*size+i+13*5; bb5[n][i] = 0; 
aa6[n][i] = n*size+i+13*6; bb6[n][i] = 0; 
aa7[n][i] = n*size+i+13*7; bb7[n][i] = 0; 
}
}


void* clh = clopen(cp,"test_arg_int.cl",CLLD_NOW);
cl_kernel krn;
clndrange_t ndr = clndrange_init1d(0,size,blocksize);
//cl_event ev[10];
int sum,sum_correct;
float tol = pow(10.0,-8+log10((float)size));





krn = clsym(cp,clh,"test_arg_1_1_kern",CLLD_NOW);
if (!krn) exit(__LINE__);

//// XXX loop over ndev
for(n=0;n<ndev;n++) {
if (!clmsync(cp,n,aa0[n],CL_MEM_DEVICE|CL_EVENT_NOWAIT))
exit(__LINE__);
}

for(n=0;n<ndev;n++) {
clarg_set_global(krn,0,aa0[n]);
clarg_set_global(krn,1,bb0[n]);
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

int ns = ndev*size;

sum_correct = 0;
for(i=0;i<1;++i)
for(j=0;j<1;++j)
//sum_correct += (j+1)*( size*(size-1)/2 + 14*i*size );
sum_correct += (j+1)*( ns*(ns-1)/2 + 14*i*ns );
sum = 0;
for(n=0;n<ndev;n++) {
for(i=0;i<size;i++) sum += bb0[n][i];
}
printf("(%d) sum 1 1 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);






printf("done!\n");
clclose(cp,clh);
return(0);
}
