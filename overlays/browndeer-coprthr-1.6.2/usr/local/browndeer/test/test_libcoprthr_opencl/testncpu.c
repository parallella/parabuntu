
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
do { fprintf(stderr,"error code %d\n",err); exit(line); } while(0)

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
__exit(-1,__LINE__);
}
}

cl_uint nplatforms;
cl_platform_id* platforms;

if (err=clGetPlatformIDs(0,0,&nplatforms)) __exit(err,__LINE__);

if (nplatforms == 0) __exit(-1,__LINE__);

platforms = (cl_platform_id*)malloc(nplatforms*sizeof(cl_platform_id));

if (!platforms) __exit(-1,__LINE__);

if (err=clGetPlatformIDs(nplatforms,platforms,0)) __exit(err,__LINE__);

char buf[256];

cl_uint ndev = 0;
if (err=clGetDeviceIDs(platforms[0],CL_DEVICE_TYPE_CPU,0,0,&ndev)) 
__exit(err,__LINE__);

cl_device_id* devices = (cl_device_id*)malloc(ndev*sizeof(cl_device_id));

if (!devices) __exit(-1,__LINE__);

if (err=clGetDeviceIDs(platforms[0],CL_DEVICE_TYPE_CPU,ndev,devices,0)) 
__exit(err,__LINE__);

printf("NUMBER OF DEVICES %d\n",ndev);

cl_context_properties ctxprop[3] = {
(cl_context_properties)CL_CONTEXT_PLATFORM,
(cl_context_properties)platforms[0],
(cl_context_properties)0
};

cl_context ctx = clCreateContext(ctxprop,ndev,devices,0,0,&err);
if (err) __exit(err,__LINE__);

cl_command_queue cmdq0 = clCreateCommandQueue(ctx,devices[0],0,&err);
if (err) __exit(err,__LINE__);
cl_command_queue cmdq1 = clCreateCommandQueue(ctx,devices[1],0,&err);
if (err) __exit(err,__LINE__);

int* aa0 = (int*)malloc(size*sizeof(int));
if (!aa0) __exit(-1,__LINE__);
int* bb0 = (int*)malloc(size*sizeof(int));
if (!bb0) __exit(-1,__LINE__);
int* aa1 = (int*)malloc(size*sizeof(int));
if (!aa1) __exit(-1,__LINE__);
int* bb1 = (int*)malloc(size*sizeof(int));
if (!bb1) __exit(-1,__LINE__);
for(i=0;i<size;i++) { 
aa0[i] = i+13*0; bb0[i] = 0; 
aa1[i] = i+13*1; bb1[i] = 0; 
}

int* cc0 = (int*)malloc(size*sizeof(int));
if (!cc0) __exit(-1,__LINE__);
int* dd0 = (int*)malloc(size*sizeof(int));
if (!dd0) __exit(-1,__LINE__);
int* cc1 = (int*)malloc(size*sizeof(int));
if (!cc1) __exit(-1,__LINE__);
int* dd1 = (int*)malloc(size*sizeof(int));
if (!dd1) __exit(-1,__LINE__);
for(i=0;i<size;i++) { 
cc0[i] = i+13*0; dd0[i] = 0; 
cc1[i] = i+13*1; dd1[i] = 0; 
}

cl_mem bufa0 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,size*sizeof(int),aa0,&err);
if (err) __exit(err,__LINE__);
cl_mem bufb0 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,size*sizeof(int),bb0,&err);
if (err) __exit(err,__LINE__);
cl_mem bufa1 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,size*sizeof(int),aa1,&err);
if (err) __exit(err,__LINE__);
cl_mem bufb1 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,size*sizeof(int),bb1,&err);
if (err) __exit(err,__LINE__);
cl_mem bufc0 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,size*sizeof(int),cc0,&err);
if (err) __exit(err,__LINE__);
cl_mem bufd0 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,size*sizeof(int),dd0,&err);
if (err) __exit(err,__LINE__);
cl_mem bufc1 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,size*sizeof(int),cc1,&err);
if (err) __exit(err,__LINE__);
cl_mem bufd1 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,size*sizeof(int),dd1,&err);
if (err) __exit(err,__LINE__);



size_t file_sz;
void* pfile;
__mapfile("test_special.cl",file_sz,pfile);
cl_program prg=clCreateProgramWithSource(
ctx,1,(const char**)&pfile,&file_sz,&err);
if (err) __exit(err,__LINE__);
if (clBuildProgram(prg,ndev,devices,0,0,0)) exit(__LINE__);
size_t gws1[] = { size };
size_t lws1[] = { blocksize };
cl_event ev0[4];
cl_event ev1[4];
cl_kernel krn0,krn1;
int sum,sum_correct;

/* use cmdq0 */

krn0 = clCreateKernel(prg,"test_arg_1_1_kern",&err);
if (err) __exit(err,__LINE__);
if (err=clSetKernelArg(krn0,0,sizeof(cl_mem),&bufa0)) __exit(err,__LINE__);
if (err=clSetKernelArg(krn0,1,sizeof(cl_mem),&bufb0)) __exit(err,__LINE__);
if (err=clEnqueueNDRangeKernel(cmdq0,krn0,1,0,gws1,lws1,0,0,&ev0[0])) 
__exit(err,__LINE__);
if (err=clEnqueueReadBuffer(cmdq0,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev0[1+0])) 
__exit(err,__LINE__);
if (err=clWaitForEvents(1+1,ev0)) __exit(err,__LINE__);
sum_correct = 0;
for(i=0;i<1;++i)
for(j=0;j<1;++j)
sum_correct += (j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
printf("(%d) sum 1 1 %d\n",sum_correct,sum);
if (sum != sum_correct) __exit(err,__LINE__);
if (err=clReleaseEvent(ev0[0])) __exit(err,__LINE__);
if (err=clReleaseEvent(ev0[1])) __exit(err,__LINE__);
if (err=clReleaseKernel(krn0)) __exit(err,__LINE__);


/* use cmdq1 */

krn1 = clCreateKernel(prg,"test_arg_1_2_kern",&err);
if (err) __exit(err,__LINE__);
if (err=clSetKernelArg(krn1,0,sizeof(cl_mem),&bufc0)) __exit(err,__LINE__);
if (err=clSetKernelArg(krn1,1,sizeof(cl_mem),&bufd0)) __exit(err,__LINE__);
if (err=clSetKernelArg(krn1,2,sizeof(cl_mem),&bufd1)) __exit(err,__LINE__);
if (err=clEnqueueNDRangeKernel(cmdq1,krn1,1,0,gws1,lws1,0,0,&ev1[0])) 
__exit(err,__LINE__);
if (err=clEnqueueReadBuffer(cmdq1,bufd0,CL_TRUE,0,size*sizeof(int),dd0,0,0,&ev1[1+0])) 
__exit(err,__LINE__);
if (err=clEnqueueReadBuffer(cmdq1,bufd1,CL_TRUE,0,size*sizeof(int),dd1,0,0,&ev1[1+1])) 
__exit(err,__LINE__);
if (err=clWaitForEvents(1+2,ev1)) __exit(err,__LINE__);
sum_correct = 0;
for(i=0;i<1;++i)
for(j=0;j<2;++j)
sum_correct += (j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += dd0[i];
for(i=0;i<size;i++) sum += dd1[i];
printf("(%d) sum 1 2 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);
if (err=clReleaseEvent(ev1[0])) __exit(err,__LINE__);
if (err=clReleaseEvent(ev1[1])) __exit(err,__LINE__);
if (err=clReleaseEvent(ev1[2])) __exit(err,__LINE__);
if (err=clReleaseKernel(krn1)) __exit(err,__LINE__);


/* inerlace both computations */

krn0 = clCreateKernel(prg,"test_arg_1_1_kern",&err);
if (err) __exit(err,__LINE__);
krn1 = clCreateKernel(prg,"test_arg_1_2_kern",&err);
if (err) __exit(err,__LINE__);
if (err=clSetKernelArg(krn0,0,sizeof(cl_mem),&bufa0)) __exit(err,__LINE__);
if (err=clSetKernelArg(krn0,1,sizeof(cl_mem),&bufb0)) __exit(err,__LINE__);
if (err=clSetKernelArg(krn1,0,sizeof(cl_mem),&bufc0)) __exit(err,__LINE__);
if (err=clSetKernelArg(krn1,1,sizeof(cl_mem),&bufd0)) __exit(err,__LINE__);
if (err=clSetKernelArg(krn1,2,sizeof(cl_mem),&bufd1)) __exit(err,__LINE__);
if (err=clEnqueueNDRangeKernel(cmdq0,krn0,1,0,gws1,lws1,0,0,&ev0[0])) 
__exit(err,__LINE__);
if (err=clEnqueueNDRangeKernel(cmdq1,krn1,1,0,gws1,lws1,0,0,&ev1[0])) 
__exit(err,__LINE__);
if (err=clEnqueueReadBuffer(cmdq0,bufb0,CL_TRUE,0,size*sizeof(int),bb0,0,0,&ev0[1+0])) 
__exit(err,__LINE__);
if (err=clEnqueueReadBuffer(cmdq1,bufd0,CL_TRUE,0,size*sizeof(int),dd0,0,0,&ev1[1+0])) 
__exit(err,__LINE__);
if (err=clEnqueueReadBuffer(cmdq1,bufd1,CL_TRUE,0,size*sizeof(int),dd1,0,0,&ev1[1+1])) 
__exit(err,__LINE__);

if (err=clWaitForEvents(1+1,ev0)) __exit(err,__LINE__);
if (err=clWaitForEvents(1+2,ev1)) __exit(err,__LINE__);

sum_correct = 0;
for(i=0;i<1;++i)
for(j=0;j<1;++j)
sum_correct += (j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += bb0[i];
printf("(%d) sum 1 1 %d\n",sum_correct,sum);
if (sum != sum_correct) __exit(err,__LINE__);

sum_correct = 0;
for(i=0;i<1;++i)
for(j=0;j<2;++j)
sum_correct += (j+1)*( size*(size-1)/2 + 14*i*size );
sum = 0;
for(i=0;i<size;i++) sum += dd0[i];
for(i=0;i<size;i++) sum += dd1[i];
printf("(%d) sum 1 2 %d\n",sum_correct,sum);
if (sum != sum_correct) exit(__LINE__);

if (err=clReleaseEvent(ev0[0])) __exit(err,__LINE__);
if (err=clReleaseEvent(ev0[1])) __exit(err,__LINE__);
if (err=clReleaseKernel(krn0)) __exit(err,__LINE__);
if (err=clReleaseEvent(ev1[0])) __exit(err,__LINE__);
if (err=clReleaseEvent(ev1[1])) __exit(err,__LINE__);
if (err=clReleaseEvent(ev1[2])) __exit(err,__LINE__);
if (err=clReleaseKernel(krn1)) __exit(err,__LINE__);



if (clReleaseProgram(prg)) exit(__LINE__);
if (clReleaseMemObject(bufa0)) exit(__LINE__);
if (clReleaseMemObject(bufb0)) exit(__LINE__);
if (clReleaseMemObject(bufa1)) exit(__LINE__);
if (clReleaseMemObject(bufb1)) exit(__LINE__);
if (clReleaseCommandQueue(cmdq0)) exit(__LINE__);
if (clReleaseCommandQueue(cmdq1)) exit(__LINE__);
if (clReleaseContext(ctx)) exit(__LINE__);
printf("done!\n");
return(0);
}

