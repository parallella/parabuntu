
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

#include "CL/cl.h"

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

size_t size = SIZE;
size_t blocksize = BLOCKSIZE;

i=1;
char* arg;
while(i<argc) {
arg=argv[i++];
if (!strncmp(arg,"--size",6)) size = atoi(argv[i++]);
else if (!strncmp(arg,"--blocksize",11)) blocksize = atoi(argv[i++]);
else {
fprintf(stderr,"unrecognized option ''\n",arg);
exit(-1);
}
}

cl_uint nplatforms;
cl_platform_id* platforms;

if (clGetPlatformIDs(0,0,&nplatforms)) exit(__LINE__);

if (nplatforms == 0) exit(__LINE__);

platforms = (cl_platform_id*)malloc(nplatforms*sizeof(cl_platform_id));

if (!platforms) exit(__LINE__);

if (clGetPlatformIDs(nplatforms,platforms,0)) exit(__LINE__);

char buf[256];

cl_uint ndev = 0;
if (clGetDeviceIDs(platforms[0],CL_DEVICE_TYPE_CPU,0,0,&ndev)) 
exit(__LINE__);

cl_device_id* devices = (cl_device_id*)malloc(ndev*sizeof(cl_device_id));

if (!devices) exit(__LINE__);

if (clGetDeviceIDs(platforms[0],CL_DEVICE_TYPE_CPU,ndev,devices,0)) 
exit(__LINE__);

cl_context_properties ctxprop[3] = {
(cl_context_properties)CL_CONTEXT_PLATFORM,
(cl_context_properties)platforms[0],
(cl_context_properties)0
};

cl_context ctx = clCreateContext(ctxprop,ndev,devices,0,0,&err);
if (err) exit(__LINE__);

cl_command_queue cmdq = clCreateCommandQueue(ctx,devices[0],0,&err);
if (err) exit(__LINE__);
int* aa0 = (int*)malloc(size*sizeof(int));
if (!aa0) exit(__LINE__);
int* bb0 = (int*)malloc(size*sizeof(int));
if (!bb0) exit(__LINE__);
int* aa1 = (int*)malloc(size*sizeof(int));
if (!aa1) exit(__LINE__);
int* bb1 = (int*)malloc(size*sizeof(int));
if (!bb1) exit(__LINE__);
int* aa2 = (int*)malloc(size*sizeof(int));
if (!aa2) exit(__LINE__);
int* bb2 = (int*)malloc(size*sizeof(int));
if (!bb2) exit(__LINE__);
int* aa3 = (int*)malloc(size*sizeof(int));
if (!aa3) exit(__LINE__);
int* bb3 = (int*)malloc(size*sizeof(int));
if (!bb3) exit(__LINE__);
int* aa4 = (int*)malloc(size*sizeof(int));
if (!aa4) exit(__LINE__);
int* bb4 = (int*)malloc(size*sizeof(int));
if (!bb4) exit(__LINE__);
int* aa5 = (int*)malloc(size*sizeof(int));
if (!aa5) exit(__LINE__);
int* bb5 = (int*)malloc(size*sizeof(int));
if (!bb5) exit(__LINE__);
int* aa6 = (int*)malloc(size*sizeof(int));
if (!aa6) exit(__LINE__);
int* bb6 = (int*)malloc(size*sizeof(int));
if (!bb6) exit(__LINE__);
int* aa7 = (int*)malloc(size*sizeof(int));
if (!aa7) exit(__LINE__);
int* bb7 = (int*)malloc(size*sizeof(int));
if (!bb7) exit(__LINE__);
for(i=0;i<size;i++) { 
aa0[i] = i+13*0; bb0[i] = 0; 
aa1[i] = i+13*1; bb1[i] = 0; 
aa2[i] = i+13*2; bb2[i] = 0; 
aa3[i] = i+13*3; bb3[i] = 0; 
aa4[i] = i+13*4; bb4[i] = 0; 
aa5[i] = i+13*5; bb5[i] = 0; 
aa6[i] = i+13*6; bb6[i] = 0; 
aa7[i] = i+13*7; bb7[i] = 0; 
}
cl_mem bufa0 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,size*sizeof(int),aa0,&err);
if (err) exit(__LINE__);
cl_mem bufb0 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,size*sizeof(int),bb0,&err);
if (err) exit(__LINE__);
cl_mem bufa1 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,size*sizeof(int),aa1,&err);
if (err) exit(__LINE__);
cl_mem bufb1 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,size*sizeof(int),bb1,&err);
if (err) exit(__LINE__);
cl_mem bufa2 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,size*sizeof(int),aa2,&err);
if (err) exit(__LINE__);
cl_mem bufb2 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,size*sizeof(int),bb2,&err);
if (err) exit(__LINE__);
cl_mem bufa3 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,size*sizeof(int),aa3,&err);
if (err) exit(__LINE__);
cl_mem bufb3 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,size*sizeof(int),bb3,&err);
if (err) exit(__LINE__);
cl_mem bufa4 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,size*sizeof(int),aa4,&err);
if (err) exit(__LINE__);
cl_mem bufb4 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,size*sizeof(int),bb4,&err);
if (err) exit(__LINE__);
cl_mem bufa5 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,size*sizeof(int),aa5,&err);
if (err) exit(__LINE__);
cl_mem bufb5 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,size*sizeof(int),bb5,&err);
if (err) exit(__LINE__);
cl_mem bufa6 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,size*sizeof(int),aa6,&err);
if (err) exit(__LINE__);
cl_mem bufb6 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,size*sizeof(int),bb6,&err);
if (err) exit(__LINE__);
cl_mem bufa7 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,size*sizeof(int),aa7,&err);
if (err) exit(__LINE__);
cl_mem bufb7 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,size*sizeof(int),bb7,&err);
if (err) exit(__LINE__);
size_t file_sz;
void* pfile;
__mapfile("test_block_int.cl",file_sz,pfile);
cl_program prg=clCreateProgramWithSource(
ctx,1,(const char**)&pfile,&file_sz,&err);
if (err) exit(__LINE__);
if (clBuildProgram(prg,ndev,devices,0,0,0)) exit(__LINE__);
size_t gws1[] = { size };
size_t lws1[] = { blocksize };
cl_event ev[10];
cl_kernel krn;
int sum,sum_correct;
krn = clCreateKernel(prg,"test_block_1_1_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,0+1+1,blocksize*sizeof(int),0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clWaitForEvents(1+1,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<1;++i)
for(j=0;j<1;++j)
sum_correct += (blocksize-5)*(j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
printf("(%d) sum 1 1 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_block_1_2_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,0+1+2,blocksize*sizeof(int),0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,size*sizeof(int),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clWaitForEvents(1+2,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<1;++i)
for(j=0;j<2;++j)
sum_correct += (blocksize-5)*(j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
printf("(%d) sum 1 2 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_block_2_1_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,0+2+1,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,1+2+1,blocksize*sizeof(int),0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clWaitForEvents(1+1,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<2;++i)
for(j=0;j<1;++j)
sum_correct += (blocksize-5)*(j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
printf("(%d) sum 2 1 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_block_1_3_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufb2)) exit(__LINE__);
if (clSetKernelArg(krn,0+1+3,blocksize*sizeof(int),0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,size*sizeof(int),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,size*sizeof(int),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clWaitForEvents(1+3,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<1;++i)
for(j=0;j<3;++j)
sum_correct += (blocksize-5)*(j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
for(i=0;i<size;i++) sum += bb2[i];
printf("(%d) sum 1 3 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_block_2_2_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,0+2+2,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,1+2+2,blocksize*sizeof(int),0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,size*sizeof(int),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clWaitForEvents(1+2,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<2;++i)
for(j=0;j<2;++j)
sum_correct += (blocksize-5)*(j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
printf("(%d) sum 2 2 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_block_3_1_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufa2)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,0+3+1,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,1+3+1,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,2+3+1,blocksize*sizeof(int),0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clWaitForEvents(1+1,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<3;++i)
for(j=0;j<1;++j)
sum_correct += (blocksize-5)*(j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
printf("(%d) sum 3 1 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_block_1_4_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufb2)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufb3)) exit(__LINE__);
if (clSetKernelArg(krn,0+1+4,blocksize*sizeof(int),0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,size*sizeof(int),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,size*sizeof(int),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb3,CL_TRUE,0,size*sizeof(int),bb3,0,0,&ev[1+3])) 
exit(__LINE__);
if (clWaitForEvents(1+4,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<1;++i)
for(j=0;j<4;++j)
sum_correct += (blocksize-5)*(j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
for(i=0;i<size;i++) sum += bb2[i];
for(i=0;i<size;i++) sum += bb3[i];
printf("(%d) sum 1 4 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseEvent(ev[4])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_block_2_3_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufb2)) exit(__LINE__);
if (clSetKernelArg(krn,0+2+3,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,1+2+3,blocksize*sizeof(int),0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,size*sizeof(int),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,size*sizeof(int),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clWaitForEvents(1+3,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<2;++i)
for(j=0;j<3;++j)
sum_correct += (blocksize-5)*(j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
for(i=0;i<size;i++) sum += bb2[i];
printf("(%d) sum 2 3 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_block_3_2_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufa2)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,0+3+2,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,1+3+2,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,2+3+2,blocksize*sizeof(int),0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,size*sizeof(int),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clWaitForEvents(1+2,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<3;++i)
for(j=0;j<2;++j)
sum_correct += (blocksize-5)*(j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
printf("(%d) sum 3 2 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_block_4_1_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufa2)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufa3)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,0+4+1,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,1+4+1,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,2+4+1,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,3+4+1,blocksize*sizeof(int),0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clWaitForEvents(1+1,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<4;++i)
for(j=0;j<1;++j)
sum_correct += (blocksize-5)*(j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
printf("(%d) sum 4 1 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_block_1_5_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufb2)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufb3)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufb4)) exit(__LINE__);
if (clSetKernelArg(krn,0+1+5,blocksize*sizeof(int),0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,size*sizeof(int),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,size*sizeof(int),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb3,CL_TRUE,0,size*sizeof(int),bb3,0,0,&ev[1+3])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb4,CL_TRUE,0,size*sizeof(int),bb4,0,0,&ev[1+4])) 
exit(__LINE__);
if (clWaitForEvents(1+5,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<1;++i)
for(j=0;j<5;++j)
sum_correct += (blocksize-5)*(j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
for(i=0;i<size;i++) sum += bb2[i];
for(i=0;i<size;i++) sum += bb3[i];
for(i=0;i<size;i++) sum += bb4[i];
printf("(%d) sum 1 5 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseEvent(ev[4])) exit(__LINE__);
if (clReleaseEvent(ev[5])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_block_2_4_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufb2)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufb3)) exit(__LINE__);
if (clSetKernelArg(krn,0+2+4,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,1+2+4,blocksize*sizeof(int),0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,size*sizeof(int),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,size*sizeof(int),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb3,CL_TRUE,0,size*sizeof(int),bb3,0,0,&ev[1+3])) 
exit(__LINE__);
if (clWaitForEvents(1+4,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<2;++i)
for(j=0;j<4;++j)
sum_correct += (blocksize-5)*(j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
for(i=0;i<size;i++) sum += bb2[i];
for(i=0;i<size;i++) sum += bb3[i];
printf("(%d) sum 2 4 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseEvent(ev[4])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_block_3_3_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufa2)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufb2)) exit(__LINE__);
if (clSetKernelArg(krn,0+3+3,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,1+3+3,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,2+3+3,blocksize*sizeof(int),0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,size*sizeof(int),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,size*sizeof(int),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clWaitForEvents(1+3,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<3;++i)
for(j=0;j<3;++j)
sum_correct += (blocksize-5)*(j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
for(i=0;i<size;i++) sum += bb2[i];
printf("(%d) sum 3 3 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_block_4_2_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufa2)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufa3)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,0+4+2,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,1+4+2,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,2+4+2,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,3+4+2,blocksize*sizeof(int),0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,size*sizeof(int),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clWaitForEvents(1+2,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<4;++i)
for(j=0;j<2;++j)
sum_correct += (blocksize-5)*(j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
printf("(%d) sum 4 2 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_block_5_1_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufa2)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufa3)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufa4)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,0+5+1,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,1+5+1,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,2+5+1,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,3+5+1,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,4+5+1,blocksize*sizeof(int),0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clWaitForEvents(1+1,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<5;++i)
for(j=0;j<1;++j)
sum_correct += (blocksize-5)*(j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
printf("(%d) sum 5 1 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_block_1_6_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufb2)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufb3)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufb4)) exit(__LINE__);
if (clSetKernelArg(krn,6,sizeof(cl_mem),&bufb5)) exit(__LINE__);
if (clSetKernelArg(krn,0+1+6,blocksize*sizeof(int),0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,size*sizeof(int),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,size*sizeof(int),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb3,CL_TRUE,0,size*sizeof(int),bb3,0,0,&ev[1+3])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb4,CL_TRUE,0,size*sizeof(int),bb4,0,0,&ev[1+4])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb5,CL_TRUE,0,size*sizeof(int),bb5,0,0,&ev[1+5])) 
exit(__LINE__);
if (clWaitForEvents(1+6,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<1;++i)
for(j=0;j<6;++j)
sum_correct += (blocksize-5)*(j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
for(i=0;i<size;i++) sum += bb2[i];
for(i=0;i<size;i++) sum += bb3[i];
for(i=0;i<size;i++) sum += bb4[i];
for(i=0;i<size;i++) sum += bb5[i];
printf("(%d) sum 1 6 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseEvent(ev[4])) exit(__LINE__);
if (clReleaseEvent(ev[5])) exit(__LINE__);
if (clReleaseEvent(ev[6])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_block_2_5_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufb2)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufb3)) exit(__LINE__);
if (clSetKernelArg(krn,6,sizeof(cl_mem),&bufb4)) exit(__LINE__);
if (clSetKernelArg(krn,0+2+5,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,1+2+5,blocksize*sizeof(int),0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,size*sizeof(int),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,size*sizeof(int),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb3,CL_TRUE,0,size*sizeof(int),bb3,0,0,&ev[1+3])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb4,CL_TRUE,0,size*sizeof(int),bb4,0,0,&ev[1+4])) 
exit(__LINE__);
if (clWaitForEvents(1+5,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<2;++i)
for(j=0;j<5;++j)
sum_correct += (blocksize-5)*(j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
for(i=0;i<size;i++) sum += bb2[i];
for(i=0;i<size;i++) sum += bb3[i];
for(i=0;i<size;i++) sum += bb4[i];
printf("(%d) sum 2 5 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseEvent(ev[4])) exit(__LINE__);
if (clReleaseEvent(ev[5])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_block_3_4_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufa2)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufb2)) exit(__LINE__);
if (clSetKernelArg(krn,6,sizeof(cl_mem),&bufb3)) exit(__LINE__);
if (clSetKernelArg(krn,0+3+4,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,1+3+4,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,2+3+4,blocksize*sizeof(int),0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,size*sizeof(int),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,size*sizeof(int),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb3,CL_TRUE,0,size*sizeof(int),bb3,0,0,&ev[1+3])) 
exit(__LINE__);
if (clWaitForEvents(1+4,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<3;++i)
for(j=0;j<4;++j)
sum_correct += (blocksize-5)*(j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
for(i=0;i<size;i++) sum += bb2[i];
for(i=0;i<size;i++) sum += bb3[i];
printf("(%d) sum 3 4 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseEvent(ev[4])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_block_4_3_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufa2)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufa3)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,6,sizeof(cl_mem),&bufb2)) exit(__LINE__);
if (clSetKernelArg(krn,0+4+3,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,1+4+3,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,2+4+3,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,3+4+3,blocksize*sizeof(int),0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,size*sizeof(int),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,size*sizeof(int),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clWaitForEvents(1+3,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<4;++i)
for(j=0;j<3;++j)
sum_correct += (blocksize-5)*(j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
for(i=0;i<size;i++) sum += bb2[i];
printf("(%d) sum 4 3 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_block_5_2_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufa2)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufa3)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufa4)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,6,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,0+5+2,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,1+5+2,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,2+5+2,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,3+5+2,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,4+5+2,blocksize*sizeof(int),0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,size*sizeof(int),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clWaitForEvents(1+2,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<5;++i)
for(j=0;j<2;++j)
sum_correct += (blocksize-5)*(j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
printf("(%d) sum 5 2 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_block_6_1_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufa2)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufa3)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufa4)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufa5)) exit(__LINE__);
if (clSetKernelArg(krn,6,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,0+6+1,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,1+6+1,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,2+6+1,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,3+6+1,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,4+6+1,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,5+6+1,blocksize*sizeof(int),0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clWaitForEvents(1+1,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<6;++i)
for(j=0;j<1;++j)
sum_correct += (blocksize-5)*(j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
printf("(%d) sum 6 1 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_block_1_7_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufb2)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufb3)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufb4)) exit(__LINE__);
if (clSetKernelArg(krn,6,sizeof(cl_mem),&bufb5)) exit(__LINE__);
if (clSetKernelArg(krn,7,sizeof(cl_mem),&bufb6)) exit(__LINE__);
if (clSetKernelArg(krn,0+1+7,blocksize*sizeof(int),0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,size*sizeof(int),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,size*sizeof(int),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb3,CL_TRUE,0,size*sizeof(int),bb3,0,0,&ev[1+3])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb4,CL_TRUE,0,size*sizeof(int),bb4,0,0,&ev[1+4])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb5,CL_TRUE,0,size*sizeof(int),bb5,0,0,&ev[1+5])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb6,CL_TRUE,0,size*sizeof(int),bb6,0,0,&ev[1+6])) 
exit(__LINE__);
if (clWaitForEvents(1+7,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<1;++i)
for(j=0;j<7;++j)
sum_correct += (blocksize-5)*(j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
for(i=0;i<size;i++) sum += bb2[i];
for(i=0;i<size;i++) sum += bb3[i];
for(i=0;i<size;i++) sum += bb4[i];
for(i=0;i<size;i++) sum += bb5[i];
for(i=0;i<size;i++) sum += bb6[i];
printf("(%d) sum 1 7 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseEvent(ev[4])) exit(__LINE__);
if (clReleaseEvent(ev[5])) exit(__LINE__);
if (clReleaseEvent(ev[6])) exit(__LINE__);
if (clReleaseEvent(ev[7])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_block_2_6_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufb2)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufb3)) exit(__LINE__);
if (clSetKernelArg(krn,6,sizeof(cl_mem),&bufb4)) exit(__LINE__);
if (clSetKernelArg(krn,7,sizeof(cl_mem),&bufb5)) exit(__LINE__);
if (clSetKernelArg(krn,0+2+6,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,1+2+6,blocksize*sizeof(int),0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,size*sizeof(int),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,size*sizeof(int),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb3,CL_TRUE,0,size*sizeof(int),bb3,0,0,&ev[1+3])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb4,CL_TRUE,0,size*sizeof(int),bb4,0,0,&ev[1+4])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb5,CL_TRUE,0,size*sizeof(int),bb5,0,0,&ev[1+5])) 
exit(__LINE__);
if (clWaitForEvents(1+6,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<2;++i)
for(j=0;j<6;++j)
sum_correct += (blocksize-5)*(j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
for(i=0;i<size;i++) sum += bb2[i];
for(i=0;i<size;i++) sum += bb3[i];
for(i=0;i<size;i++) sum += bb4[i];
for(i=0;i<size;i++) sum += bb5[i];
printf("(%d) sum 2 6 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseEvent(ev[4])) exit(__LINE__);
if (clReleaseEvent(ev[5])) exit(__LINE__);
if (clReleaseEvent(ev[6])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_block_3_5_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufa2)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufb2)) exit(__LINE__);
if (clSetKernelArg(krn,6,sizeof(cl_mem),&bufb3)) exit(__LINE__);
if (clSetKernelArg(krn,7,sizeof(cl_mem),&bufb4)) exit(__LINE__);
if (clSetKernelArg(krn,0+3+5,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,1+3+5,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,2+3+5,blocksize*sizeof(int),0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,size*sizeof(int),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,size*sizeof(int),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb3,CL_TRUE,0,size*sizeof(int),bb3,0,0,&ev[1+3])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb4,CL_TRUE,0,size*sizeof(int),bb4,0,0,&ev[1+4])) 
exit(__LINE__);
if (clWaitForEvents(1+5,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<3;++i)
for(j=0;j<5;++j)
sum_correct += (blocksize-5)*(j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
for(i=0;i<size;i++) sum += bb2[i];
for(i=0;i<size;i++) sum += bb3[i];
for(i=0;i<size;i++) sum += bb4[i];
printf("(%d) sum 3 5 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseEvent(ev[4])) exit(__LINE__);
if (clReleaseEvent(ev[5])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_block_4_4_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufa2)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufa3)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,6,sizeof(cl_mem),&bufb2)) exit(__LINE__);
if (clSetKernelArg(krn,7,sizeof(cl_mem),&bufb3)) exit(__LINE__);
if (clSetKernelArg(krn,0+4+4,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,1+4+4,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,2+4+4,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,3+4+4,blocksize*sizeof(int),0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,size*sizeof(int),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,size*sizeof(int),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb3,CL_TRUE,0,size*sizeof(int),bb3,0,0,&ev[1+3])) 
exit(__LINE__);
if (clWaitForEvents(1+4,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<4;++i)
for(j=0;j<4;++j)
sum_correct += (blocksize-5)*(j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
for(i=0;i<size;i++) sum += bb2[i];
for(i=0;i<size;i++) sum += bb3[i];
printf("(%d) sum 4 4 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseEvent(ev[4])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_block_5_3_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufa2)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufa3)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufa4)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,6,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,7,sizeof(cl_mem),&bufb2)) exit(__LINE__);
if (clSetKernelArg(krn,0+5+3,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,1+5+3,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,2+5+3,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,3+5+3,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,4+5+3,blocksize*sizeof(int),0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,size*sizeof(int),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,size*sizeof(int),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clWaitForEvents(1+3,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<5;++i)
for(j=0;j<3;++j)
sum_correct += (blocksize-5)*(j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
for(i=0;i<size;i++) sum += bb2[i];
printf("(%d) sum 5 3 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_block_6_2_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufa2)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufa3)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufa4)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufa5)) exit(__LINE__);
if (clSetKernelArg(krn,6,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,7,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,0+6+2,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,1+6+2,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,2+6+2,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,3+6+2,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,4+6+2,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,5+6+2,blocksize*sizeof(int),0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,size*sizeof(int),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clWaitForEvents(1+2,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<6;++i)
for(j=0;j<2;++j)
sum_correct += (blocksize-5)*(j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
printf("(%d) sum 6 2 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_block_7_1_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufa2)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufa3)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufa4)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufa5)) exit(__LINE__);
if (clSetKernelArg(krn,6,sizeof(cl_mem),&bufa6)) exit(__LINE__);
if (clSetKernelArg(krn,7,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,0+7+1,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,1+7+1,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,2+7+1,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,3+7+1,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,4+7+1,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,5+7+1,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,6+7+1,blocksize*sizeof(int),0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clWaitForEvents(1+1,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<7;++i)
for(j=0;j<1;++j)
sum_correct += (blocksize-5)*(j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
printf("(%d) sum 7 1 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_block_1_8_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufb2)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufb3)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufb4)) exit(__LINE__);
if (clSetKernelArg(krn,6,sizeof(cl_mem),&bufb5)) exit(__LINE__);
if (clSetKernelArg(krn,7,sizeof(cl_mem),&bufb6)) exit(__LINE__);
if (clSetKernelArg(krn,8,sizeof(cl_mem),&bufb7)) exit(__LINE__);
if (clSetKernelArg(krn,0+1+8,blocksize*sizeof(int),0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,size*sizeof(int),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,size*sizeof(int),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb3,CL_TRUE,0,size*sizeof(int),bb3,0,0,&ev[1+3])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb4,CL_TRUE,0,size*sizeof(int),bb4,0,0,&ev[1+4])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb5,CL_TRUE,0,size*sizeof(int),bb5,0,0,&ev[1+5])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb6,CL_TRUE,0,size*sizeof(int),bb6,0,0,&ev[1+6])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb7,CL_TRUE,0,size*sizeof(int),bb7,0,0,&ev[1+7])) 
exit(__LINE__);
if (clWaitForEvents(1+8,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<1;++i)
for(j=0;j<8;++j)
sum_correct += (blocksize-5)*(j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
for(i=0;i<size;i++) sum += bb2[i];
for(i=0;i<size;i++) sum += bb3[i];
for(i=0;i<size;i++) sum += bb4[i];
for(i=0;i<size;i++) sum += bb5[i];
for(i=0;i<size;i++) sum += bb6[i];
for(i=0;i<size;i++) sum += bb7[i];
printf("(%d) sum 1 8 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseEvent(ev[4])) exit(__LINE__);
if (clReleaseEvent(ev[5])) exit(__LINE__);
if (clReleaseEvent(ev[6])) exit(__LINE__);
if (clReleaseEvent(ev[7])) exit(__LINE__);
if (clReleaseEvent(ev[8])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_block_2_7_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufb2)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufb3)) exit(__LINE__);
if (clSetKernelArg(krn,6,sizeof(cl_mem),&bufb4)) exit(__LINE__);
if (clSetKernelArg(krn,7,sizeof(cl_mem),&bufb5)) exit(__LINE__);
if (clSetKernelArg(krn,8,sizeof(cl_mem),&bufb6)) exit(__LINE__);
if (clSetKernelArg(krn,0+2+7,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,1+2+7,blocksize*sizeof(int),0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,size*sizeof(int),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,size*sizeof(int),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb3,CL_TRUE,0,size*sizeof(int),bb3,0,0,&ev[1+3])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb4,CL_TRUE,0,size*sizeof(int),bb4,0,0,&ev[1+4])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb5,CL_TRUE,0,size*sizeof(int),bb5,0,0,&ev[1+5])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb6,CL_TRUE,0,size*sizeof(int),bb6,0,0,&ev[1+6])) 
exit(__LINE__);
if (clWaitForEvents(1+7,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<2;++i)
for(j=0;j<7;++j)
sum_correct += (blocksize-5)*(j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
for(i=0;i<size;i++) sum += bb2[i];
for(i=0;i<size;i++) sum += bb3[i];
for(i=0;i<size;i++) sum += bb4[i];
for(i=0;i<size;i++) sum += bb5[i];
for(i=0;i<size;i++) sum += bb6[i];
printf("(%d) sum 2 7 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseEvent(ev[4])) exit(__LINE__);
if (clReleaseEvent(ev[5])) exit(__LINE__);
if (clReleaseEvent(ev[6])) exit(__LINE__);
if (clReleaseEvent(ev[7])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_block_3_6_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufa2)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufb2)) exit(__LINE__);
if (clSetKernelArg(krn,6,sizeof(cl_mem),&bufb3)) exit(__LINE__);
if (clSetKernelArg(krn,7,sizeof(cl_mem),&bufb4)) exit(__LINE__);
if (clSetKernelArg(krn,8,sizeof(cl_mem),&bufb5)) exit(__LINE__);
if (clSetKernelArg(krn,0+3+6,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,1+3+6,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,2+3+6,blocksize*sizeof(int),0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,size*sizeof(int),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,size*sizeof(int),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb3,CL_TRUE,0,size*sizeof(int),bb3,0,0,&ev[1+3])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb4,CL_TRUE,0,size*sizeof(int),bb4,0,0,&ev[1+4])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb5,CL_TRUE,0,size*sizeof(int),bb5,0,0,&ev[1+5])) 
exit(__LINE__);
if (clWaitForEvents(1+6,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<3;++i)
for(j=0;j<6;++j)
sum_correct += (blocksize-5)*(j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
for(i=0;i<size;i++) sum += bb2[i];
for(i=0;i<size;i++) sum += bb3[i];
for(i=0;i<size;i++) sum += bb4[i];
for(i=0;i<size;i++) sum += bb5[i];
printf("(%d) sum 3 6 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseEvent(ev[4])) exit(__LINE__);
if (clReleaseEvent(ev[5])) exit(__LINE__);
if (clReleaseEvent(ev[6])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_block_4_5_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufa2)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufa3)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,6,sizeof(cl_mem),&bufb2)) exit(__LINE__);
if (clSetKernelArg(krn,7,sizeof(cl_mem),&bufb3)) exit(__LINE__);
if (clSetKernelArg(krn,8,sizeof(cl_mem),&bufb4)) exit(__LINE__);
if (clSetKernelArg(krn,0+4+5,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,1+4+5,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,2+4+5,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,3+4+5,blocksize*sizeof(int),0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,size*sizeof(int),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,size*sizeof(int),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb3,CL_TRUE,0,size*sizeof(int),bb3,0,0,&ev[1+3])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb4,CL_TRUE,0,size*sizeof(int),bb4,0,0,&ev[1+4])) 
exit(__LINE__);
if (clWaitForEvents(1+5,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<4;++i)
for(j=0;j<5;++j)
sum_correct += (blocksize-5)*(j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
for(i=0;i<size;i++) sum += bb2[i];
for(i=0;i<size;i++) sum += bb3[i];
for(i=0;i<size;i++) sum += bb4[i];
printf("(%d) sum 4 5 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseEvent(ev[4])) exit(__LINE__);
if (clReleaseEvent(ev[5])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_block_5_4_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufa2)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufa3)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufa4)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,6,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,7,sizeof(cl_mem),&bufb2)) exit(__LINE__);
if (clSetKernelArg(krn,8,sizeof(cl_mem),&bufb3)) exit(__LINE__);
if (clSetKernelArg(krn,0+5+4,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,1+5+4,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,2+5+4,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,3+5+4,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,4+5+4,blocksize*sizeof(int),0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,size*sizeof(int),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,size*sizeof(int),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb3,CL_TRUE,0,size*sizeof(int),bb3,0,0,&ev[1+3])) 
exit(__LINE__);
if (clWaitForEvents(1+4,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<5;++i)
for(j=0;j<4;++j)
sum_correct += (blocksize-5)*(j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
for(i=0;i<size;i++) sum += bb2[i];
for(i=0;i<size;i++) sum += bb3[i];
printf("(%d) sum 5 4 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseEvent(ev[4])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_block_6_3_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufa2)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufa3)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufa4)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufa5)) exit(__LINE__);
if (clSetKernelArg(krn,6,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,7,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,8,sizeof(cl_mem),&bufb2)) exit(__LINE__);
if (clSetKernelArg(krn,0+6+3,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,1+6+3,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,2+6+3,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,3+6+3,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,4+6+3,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,5+6+3,blocksize*sizeof(int),0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,size*sizeof(int),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,size*sizeof(int),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clWaitForEvents(1+3,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<6;++i)
for(j=0;j<3;++j)
sum_correct += (blocksize-5)*(j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
for(i=0;i<size;i++) sum += bb2[i];
printf("(%d) sum 6 3 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_block_7_2_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufa2)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufa3)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufa4)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufa5)) exit(__LINE__);
if (clSetKernelArg(krn,6,sizeof(cl_mem),&bufa6)) exit(__LINE__);
if (clSetKernelArg(krn,7,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,8,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,0+7+2,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,1+7+2,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,2+7+2,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,3+7+2,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,4+7+2,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,5+7+2,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,6+7+2,blocksize*sizeof(int),0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,size*sizeof(int),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clWaitForEvents(1+2,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<7;++i)
for(j=0;j<2;++j)
sum_correct += (blocksize-5)*(j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
printf("(%d) sum 7 2 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_block_8_1_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufa2)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufa3)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufa4)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufa5)) exit(__LINE__);
if (clSetKernelArg(krn,6,sizeof(cl_mem),&bufa6)) exit(__LINE__);
if (clSetKernelArg(krn,7,sizeof(cl_mem),&bufa7)) exit(__LINE__);
if (clSetKernelArg(krn,8,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,0+8+1,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,1+8+1,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,2+8+1,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,3+8+1,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,4+8+1,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,5+8+1,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,6+8+1,blocksize*sizeof(int),0)) exit(__LINE__);
if (clSetKernelArg(krn,7+8+1,blocksize*sizeof(int),0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clWaitForEvents(1+1,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<8;++i)
for(j=0;j<1;++j)
sum_correct += (blocksize-5)*(j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
printf("(%d) sum 8 1 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
if (clReleaseProgram(prg)) exit(__LINE__);
if (clReleaseMemObject(bufa0)) exit(__LINE__);
if (clReleaseMemObject(bufb0)) exit(__LINE__);
if (clReleaseMemObject(bufa1)) exit(__LINE__);
if (clReleaseMemObject(bufb1)) exit(__LINE__);
if (clReleaseMemObject(bufa2)) exit(__LINE__);
if (clReleaseMemObject(bufb2)) exit(__LINE__);
if (clReleaseMemObject(bufa3)) exit(__LINE__);
if (clReleaseMemObject(bufb3)) exit(__LINE__);
if (clReleaseMemObject(bufa4)) exit(__LINE__);
if (clReleaseMemObject(bufb4)) exit(__LINE__);
if (clReleaseMemObject(bufa5)) exit(__LINE__);
if (clReleaseMemObject(bufb5)) exit(__LINE__);
if (clReleaseMemObject(bufa6)) exit(__LINE__);
if (clReleaseMemObject(bufb6)) exit(__LINE__);
if (clReleaseMemObject(bufa7)) exit(__LINE__);
if (clReleaseMemObject(bufb7)) exit(__LINE__);
if (clReleaseCommandQueue(cmdq)) exit(__LINE__);
if (clReleaseContext(ctx)) exit(__LINE__);
printf("done!\n");
return(0);
}
