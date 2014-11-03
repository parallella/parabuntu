
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

int main( int argc, char** argv)
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
for(i=0;i<size;i++) { 
aa0[i] = i+13*0; bb0[i] = 0; 
aa1[i] = i+13*1; bb1[i] = 0; 
}
cl_mem bufa0 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,size*sizeof(int),aa0,&err);
if (err) exit(__LINE__);
cl_mem bufb0 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,size*sizeof(int),bb0,&err);
if (err) exit(__LINE__);
cl_mem bufa1 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,size*sizeof(int),aa1,&err);
if (err) exit(__LINE__);
cl_mem bufb1 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,size*sizeof(int),bb1,&err);
if (err) exit(__LINE__);
size_t file_sz;
void* pfile;
__mapfile("test_special.cl",file_sz,pfile);
cl_program prg=clCreateProgramWithSource(
ctx,1,(const char**)&pfile,&file_sz,&err);
if (err) exit(__LINE__);
if (clBuildProgram(prg,ndev,devices,0,0,0)) exit(__LINE__);
size_t gws1[] = { size };
size_t lws1[] = { blocksize };
cl_event ev[4];
cl_kernel krn;
int sum,sum_correct;
krn = clCreateKernel(prg,"test_arg_1_1_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clWaitForEvents(1+1,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<1;++i)
for(j=0;j<1;++j)
sum_correct += (j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
printf("(%d) sum 1 1 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_arg_1_2_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufb1)) exit(__LINE__);
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
sum_correct += (j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
for(i=0;i<size;i++) sum += bb1[i];
printf("(%d) sum 1 2 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_arg_2_1_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clWaitForEvents(1+1,ev)) exit(__LINE__);
sum_correct = 0;
for(i=0;i<2;++i)
for(j=0;j<1;++j)
sum_correct += (j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
printf("(%d) sum 2 1 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
if (clReleaseProgram(prg)) exit(__LINE__);
if (clReleaseMemObject(bufa0)) exit(__LINE__);
if (clReleaseMemObject(bufb0)) exit(__LINE__);
if (clReleaseMemObject(bufa1)) exit(__LINE__);
if (clReleaseMemObject(bufb1)) exit(__LINE__);
if (clReleaseCommandQueue(cmdq)) exit(__LINE__);
if (clReleaseContext(ctx)) exit(__LINE__);
printf("done!\n");
return(0);
}
