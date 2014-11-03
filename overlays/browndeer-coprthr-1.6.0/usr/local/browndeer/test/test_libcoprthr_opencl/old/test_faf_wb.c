
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

#include "CL/cl.h"

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

int main()
{
int i;
cl_uint err; 

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
float* aa0 = (float*)malloc(2048*sizeof(int));
if (!aa0) exit(__LINE__);
float* bb0 = (float*)malloc(2048*sizeof(int));
if (!bb0) exit(__LINE__);
float* aa1 = (float*)malloc(2048*sizeof(int));
if (!aa1) exit(__LINE__);
float* bb1 = (float*)malloc(2048*sizeof(int));
if (!bb1) exit(__LINE__);
float* aa2 = (float*)malloc(2048*sizeof(int));
if (!aa2) exit(__LINE__);
float* bb2 = (float*)malloc(2048*sizeof(int));
if (!bb2) exit(__LINE__);
float* aa3 = (float*)malloc(2048*sizeof(int));
if (!aa3) exit(__LINE__);
float* bb3 = (float*)malloc(2048*sizeof(int));
if (!bb3) exit(__LINE__);
float* aa4 = (float*)malloc(2048*sizeof(int));
if (!aa4) exit(__LINE__);
float* bb4 = (float*)malloc(2048*sizeof(int));
if (!bb4) exit(__LINE__);
float* aa5 = (float*)malloc(2048*sizeof(int));
if (!aa5) exit(__LINE__);
float* bb5 = (float*)malloc(2048*sizeof(int));
if (!bb5) exit(__LINE__);
float* aa6 = (float*)malloc(2048*sizeof(int));
if (!aa6) exit(__LINE__);
float* bb6 = (float*)malloc(2048*sizeof(int));
if (!bb6) exit(__LINE__);
float* aa7 = (float*)malloc(2048*sizeof(int));
if (!aa7) exit(__LINE__);
float* bb7 = (float*)malloc(2048*sizeof(int));
if (!bb7) exit(__LINE__);
for(i=0;i<2048;i++) { 
aa0[i] = i*1.1f+13.1f*0; bb0[i] = 0; 
aa1[i] = i*1.1f+13.1f*1; bb1[i] = 0; 
aa2[i] = i*1.1f+13.1f*2; bb2[i] = 0; 
aa3[i] = i*1.1f+13.1f*3; bb3[i] = 0; 
aa4[i] = i*1.1f+13.1f*4; bb4[i] = 0; 
aa5[i] = i*1.1f+13.1f*5; bb5[i] = 0; 
aa6[i] = i*1.1f+13.1f*6; bb6[i] = 0; 
aa7[i] = i*1.1f+13.1f*7; bb7[i] = 0; 
}
cl_mem bufa0 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,2048*sizeof(float),aa0,&err);
if (err) exit(__LINE__);
cl_mem bufb0 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,2048*sizeof(float),bb0,&err);
if (err) exit(__LINE__);
cl_mem bufa1 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,2048*sizeof(float),aa1,&err);
if (err) exit(__LINE__);
cl_mem bufb1 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,2048*sizeof(float),bb1,&err);
if (err) exit(__LINE__);
cl_mem bufa2 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,2048*sizeof(float),aa2,&err);
if (err) exit(__LINE__);
cl_mem bufb2 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,2048*sizeof(float),bb2,&err);
if (err) exit(__LINE__);
cl_mem bufa3 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,2048*sizeof(float),aa3,&err);
if (err) exit(__LINE__);
cl_mem bufb3 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,2048*sizeof(float),bb3,&err);
if (err) exit(__LINE__);
cl_mem bufa4 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,2048*sizeof(float),aa4,&err);
if (err) exit(__LINE__);
cl_mem bufb4 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,2048*sizeof(float),bb4,&err);
if (err) exit(__LINE__);
cl_mem bufa5 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,2048*sizeof(float),aa5,&err);
if (err) exit(__LINE__);
cl_mem bufb5 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,2048*sizeof(float),bb5,&err);
if (err) exit(__LINE__);
cl_mem bufa6 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,2048*sizeof(float),aa6,&err);
if (err) exit(__LINE__);
cl_mem bufb6 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,2048*sizeof(float),bb6,&err);
if (err) exit(__LINE__);
cl_mem bufa7 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,2048*sizeof(float),aa7,&err);
if (err) exit(__LINE__);
cl_mem bufb7 = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,2048*sizeof(float),bb7,&err);
if (err) exit(__LINE__);
size_t file_sz;
void* pfile;
__mapfile("test_faf_wb.cl",file_sz,pfile);
cl_program prg=clCreateProgramWithSource(
ctx,1,(const char**)&pfile,&file_sz,&err);
if (err) exit(__LINE__);
if (clBuildProgram(prg,ndev,devices,0,0,0)) exit(__LINE__);
size_t gws1[] = { 128 };
size_t lws1[] = { 4 };
cl_event ev[10];
cl_kernel krn;
float sum,sum_correct;
float tol = 1.0e-6;
krn = clCreateKernel(prg,"test_fa1_1_1_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,128*sizeof(float),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clWaitForEvents(1+1,ev)) exit(__LINE__);
sum_correct = 9848.96;
sum = 0;
for(i=0;i<128;i++) sum += bb0[i];
printf("(%e) sum 1 1 %e\n",sum_correct,sum);
printf("%e \n",fabs((sum-sum_correct)/sum_correct));
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_fa1_1_2_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,128*sizeof(float),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,128*sizeof(float),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clWaitForEvents(1+2,ev)) exit(__LINE__);
sum_correct = 28651.52;
sum = 0;
for(i=0;i<128;i++) sum += bb0[i];
for(i=0;i<128;i++) sum += bb1[i];
printf("(%e) sum 1 2 %e\n",sum_correct,sum);
printf("%e \n",fabs((sum-sum_correct)/sum_correct));
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_fa1_2_1_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,128*sizeof(float),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clWaitForEvents(1+1,ev)) exit(__LINE__);
sum_correct = 21683.2;
sum = 0;
for(i=0;i<128;i++) sum += bb0[i];
printf("(%e) sum 2 1 %e\n",sum_correct,sum);
printf("%e \n",fabs((sum-sum_correct)/sum_correct));
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_fa1_1_3_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufb2)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,128*sizeof(float),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,128*sizeof(float),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,128*sizeof(float),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clWaitForEvents(1+3,ev)) exit(__LINE__);
sum_correct = 56407.68;
sum = 0;
for(i=0;i<128;i++) sum += bb0[i];
for(i=0;i<128;i++) sum += bb1[i];
for(i=0;i<128;i++) sum += bb2[i];
printf("(%e) sum 1 3 %e\n",sum_correct,sum);
printf("%e \n",fabs((sum-sum_correct)/sum_correct));
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_fa1_2_2_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,128*sizeof(float),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,128*sizeof(float),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clWaitForEvents(1+2,ev)) exit(__LINE__);
sum_correct = 63078.4;
sum = 0;
for(i=0;i<128;i++) sum += bb0[i];
for(i=0;i<128;i++) sum += bb1[i];
printf("(%e) sum 2 2 %e\n",sum_correct,sum);
printf("%e \n",fabs((sum-sum_correct)/sum_correct));
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_fa1_3_1_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufa2)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,128*sizeof(float),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clWaitForEvents(1+1,ev)) exit(__LINE__);
sum_correct = 35502.72;
sum = 0;
for(i=0;i<128;i++) sum += bb0[i];
printf("(%e) sum 3 1 %e\n",sum_correct,sum);
printf("%e \n",fabs((sum-sum_correct)/sum_correct));
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_fa1_1_4_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufb2)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufb3)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,128*sizeof(float),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,128*sizeof(float),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,128*sizeof(float),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb3,CL_TRUE,0,128*sizeof(float),bb3,0,0,&ev[1+3])) 
exit(__LINE__);
if (clWaitForEvents(1+4,ev)) exit(__LINE__);
sum_correct = 93117.44;
sum = 0;
for(i=0;i<128;i++) sum += bb0[i];
for(i=0;i<128;i++) sum += bb1[i];
for(i=0;i<128;i++) sum += bb2[i];
for(i=0;i<128;i++) sum += bb3[i];
printf("(%e) sum 1 4 %e\n",sum_correct,sum);
printf("%e \n",fabs((sum-sum_correct)/sum_correct));
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseEvent(ev[4])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_fa1_2_3_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufb2)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,128*sizeof(float),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,128*sizeof(float),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,128*sizeof(float),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clWaitForEvents(1+3,ev)) exit(__LINE__);
sum_correct = 124185.6;
sum = 0;
for(i=0;i<128;i++) sum += bb0[i];
for(i=0;i<128;i++) sum += bb1[i];
for(i=0;i<128;i++) sum += bb2[i];
printf("(%e) sum 2 3 %e\n",sum_correct,sum);
printf("%e \n",fabs((sum-sum_correct)/sum_correct));
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_fa1_3_2_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufa2)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,128*sizeof(float),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,128*sizeof(float),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clWaitForEvents(1+2,ev)) exit(__LINE__);
sum_correct = 103280.64;
sum = 0;
for(i=0;i<128;i++) sum += bb0[i];
for(i=0;i<128;i++) sum += bb1[i];
printf("(%e) sum 3 2 %e\n",sum_correct,sum);
printf("%e \n",fabs((sum-sum_correct)/sum_correct));
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_fa1_4_1_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufa2)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufa3)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,128*sizeof(float),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clWaitForEvents(1+1,ev)) exit(__LINE__);
sum_correct = 51307.52;
sum = 0;
for(i=0;i<128;i++) sum += bb0[i];
printf("(%e) sum 4 1 %e\n",sum_correct,sum);
printf("%e \n",fabs((sum-sum_correct)/sum_correct));
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_fa1_1_5_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufb2)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufb3)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufb4)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,128*sizeof(float),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,128*sizeof(float),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,128*sizeof(float),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb3,CL_TRUE,0,128*sizeof(float),bb3,0,0,&ev[1+3])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb4,CL_TRUE,0,128*sizeof(float),bb4,0,0,&ev[1+4])) 
exit(__LINE__);
if (clWaitForEvents(1+5,ev)) exit(__LINE__);
sum_correct = 138780.8;
sum = 0;
for(i=0;i<128;i++) sum += bb0[i];
for(i=0;i<128;i++) sum += bb1[i];
for(i=0;i<128;i++) sum += bb2[i];
for(i=0;i<128;i++) sum += bb3[i];
for(i=0;i<128;i++) sum += bb4[i];
printf("(%e) sum 1 5 %e\n",sum_correct,sum);
printf("%e \n",fabs((sum-sum_correct)/sum_correct));
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseEvent(ev[4])) exit(__LINE__);
if (clReleaseEvent(ev[5])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_fa1_2_4_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufb2)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufb3)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,128*sizeof(float),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,128*sizeof(float),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,128*sizeof(float),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb3,CL_TRUE,0,128*sizeof(float),bb3,0,0,&ev[1+3])) 
exit(__LINE__);
if (clWaitForEvents(1+4,ev)) exit(__LINE__);
sum_correct = 205004.8;
sum = 0;
for(i=0;i<128;i++) sum += bb0[i];
for(i=0;i<128;i++) sum += bb1[i];
for(i=0;i<128;i++) sum += bb2[i];
for(i=0;i<128;i++) sum += bb3[i];
printf("(%e) sum 2 4 %e\n",sum_correct,sum);
printf("%e \n",fabs((sum-sum_correct)/sum_correct));
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseEvent(ev[4])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_fa1_3_3_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufa2)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufb2)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,128*sizeof(float),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,128*sizeof(float),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,128*sizeof(float),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clWaitForEvents(1+3,ev)) exit(__LINE__);
sum_correct = 203333.76;
sum = 0;
for(i=0;i<128;i++) sum += bb0[i];
for(i=0;i<128;i++) sum += bb1[i];
for(i=0;i<128;i++) sum += bb2[i];
printf("(%e) sum 3 3 %e\n",sum_correct,sum);
printf("%e \n",fabs((sum-sum_correct)/sum_correct));
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_fa1_4_2_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufa2)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufa3)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,128*sizeof(float),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,128*sizeof(float),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clWaitForEvents(1+2,ev)) exit(__LINE__);
sum_correct = 149258.24;
sum = 0;
for(i=0;i<128;i++) sum += bb0[i];
for(i=0;i<128;i++) sum += bb1[i];
printf("(%e) sum 4 2 %e\n",sum_correct,sum);
printf("%e \n",fabs((sum-sum_correct)/sum_correct));
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_fa1_5_1_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufa2)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufa3)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufa4)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,128*sizeof(float),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clWaitForEvents(1+1,ev)) exit(__LINE__);
sum_correct = 69097.6;
sum = 0;
for(i=0;i<128;i++) sum += bb0[i];
printf("(%e) sum 5 1 %e\n",sum_correct,sum);
printf("%e \n",fabs((sum-sum_correct)/sum_correct));
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_fa1_1_6_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufb2)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufb3)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufb4)) exit(__LINE__);
if (clSetKernelArg(krn,6,sizeof(cl_mem),&bufb5)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,128*sizeof(float),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,128*sizeof(float),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,128*sizeof(float),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb3,CL_TRUE,0,128*sizeof(float),bb3,0,0,&ev[1+3])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb4,CL_TRUE,0,128*sizeof(float),bb4,0,0,&ev[1+4])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb5,CL_TRUE,0,128*sizeof(float),bb5,0,0,&ev[1+5])) 
exit(__LINE__);
if (clWaitForEvents(1+6,ev)) exit(__LINE__);
sum_correct = 193397.76;
sum = 0;
for(i=0;i<128;i++) sum += bb0[i];
for(i=0;i<128;i++) sum += bb1[i];
for(i=0;i<128;i++) sum += bb2[i];
for(i=0;i<128;i++) sum += bb3[i];
for(i=0;i<128;i++) sum += bb4[i];
for(i=0;i<128;i++) sum += bb5[i];
printf("(%e) sum 1 6 %e\n",sum_correct,sum);
printf("%e \n",fabs((sum-sum_correct)/sum_correct));
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseEvent(ev[4])) exit(__LINE__);
if (clReleaseEvent(ev[5])) exit(__LINE__);
if (clReleaseEvent(ev[6])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_fa1_2_5_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufb2)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufb3)) exit(__LINE__);
if (clSetKernelArg(krn,6,sizeof(cl_mem),&bufb4)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,128*sizeof(float),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,128*sizeof(float),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,128*sizeof(float),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb3,CL_TRUE,0,128*sizeof(float),bb3,0,0,&ev[1+3])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb4,CL_TRUE,0,128*sizeof(float),bb4,0,0,&ev[1+4])) 
exit(__LINE__);
if (clWaitForEvents(1+5,ev)) exit(__LINE__);
sum_correct = 305536;
sum = 0;
for(i=0;i<128;i++) sum += bb0[i];
for(i=0;i<128;i++) sum += bb1[i];
for(i=0;i<128;i++) sum += bb2[i];
for(i=0;i<128;i++) sum += bb3[i];
for(i=0;i<128;i++) sum += bb4[i];
printf("(%e) sum 2 5 %e\n",sum_correct,sum);
printf("%e \n",fabs((sum-sum_correct)/sum_correct));
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseEvent(ev[4])) exit(__LINE__);
if (clReleaseEvent(ev[5])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_fa1_3_4_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufa2)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufb2)) exit(__LINE__);
if (clSetKernelArg(krn,6,sizeof(cl_mem),&bufb3)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,128*sizeof(float),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,128*sizeof(float),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,128*sizeof(float),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb3,CL_TRUE,0,128*sizeof(float),bb3,0,0,&ev[1+3])) 
exit(__LINE__);
if (clWaitForEvents(1+4,ev)) exit(__LINE__);
sum_correct = 335662.08;
sum = 0;
for(i=0;i<128;i++) sum += bb0[i];
for(i=0;i<128;i++) sum += bb1[i];
for(i=0;i<128;i++) sum += bb2[i];
for(i=0;i<128;i++) sum += bb3[i];
printf("(%e) sum 3 4 %e\n",sum_correct,sum);
printf("%e \n",fabs((sum-sum_correct)/sum_correct));
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseEvent(ev[4])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_fa1_4_3_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufa2)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufa3)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,6,sizeof(cl_mem),&bufb2)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,128*sizeof(float),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,128*sizeof(float),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,128*sizeof(float),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clWaitForEvents(1+3,ev)) exit(__LINE__);
sum_correct = 293852.16;
sum = 0;
for(i=0;i<128;i++) sum += bb0[i];
for(i=0;i<128;i++) sum += bb1[i];
for(i=0;i<128;i++) sum += bb2[i];
printf("(%e) sum 4 3 %e\n",sum_correct,sum);
printf("%e \n",fabs((sum-sum_correct)/sum_correct));
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_fa1_5_2_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufa2)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufa3)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufa4)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,6,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,128*sizeof(float),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,128*sizeof(float),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clWaitForEvents(1+2,ev)) exit(__LINE__);
sum_correct = 201011.2;
sum = 0;
for(i=0;i<128;i++) sum += bb0[i];
for(i=0;i<128;i++) sum += bb1[i];
printf("(%e) sum 5 2 %e\n",sum_correct,sum);
printf("%e \n",fabs((sum-sum_correct)/sum_correct));
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_fa1_6_1_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufa2)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufa3)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufa4)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufa5)) exit(__LINE__);
if (clSetKernelArg(krn,6,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,128*sizeof(float),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clWaitForEvents(1+1,ev)) exit(__LINE__);
sum_correct = 88872.96;
sum = 0;
for(i=0;i<128;i++) sum += bb0[i];
printf("(%e) sum 6 1 %e\n",sum_correct,sum);
printf("%e \n",fabs((sum-sum_correct)/sum_correct));
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_fa1_1_7_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufb2)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufb3)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufb4)) exit(__LINE__);
if (clSetKernelArg(krn,6,sizeof(cl_mem),&bufb5)) exit(__LINE__);
if (clSetKernelArg(krn,7,sizeof(cl_mem),&bufb6)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,128*sizeof(float),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,128*sizeof(float),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,128*sizeof(float),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb3,CL_TRUE,0,128*sizeof(float),bb3,0,0,&ev[1+3])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb4,CL_TRUE,0,128*sizeof(float),bb4,0,0,&ev[1+4])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb5,CL_TRUE,0,128*sizeof(float),bb5,0,0,&ev[1+5])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb6,CL_TRUE,0,128*sizeof(float),bb6,0,0,&ev[1+6])) 
exit(__LINE__);
if (clWaitForEvents(1+7,ev)) exit(__LINE__);
sum_correct = 256968.32;
sum = 0;
for(i=0;i<128;i++) sum += bb0[i];
for(i=0;i<128;i++) sum += bb1[i];
for(i=0;i<128;i++) sum += bb2[i];
for(i=0;i<128;i++) sum += bb3[i];
for(i=0;i<128;i++) sum += bb4[i];
for(i=0;i<128;i++) sum += bb5[i];
for(i=0;i<128;i++) sum += bb6[i];
printf("(%e) sum 1 7 %e\n",sum_correct,sum);
printf("%e \n",fabs((sum-sum_correct)/sum_correct));
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseEvent(ev[4])) exit(__LINE__);
if (clReleaseEvent(ev[5])) exit(__LINE__);
if (clReleaseEvent(ev[6])) exit(__LINE__);
if (clReleaseEvent(ev[7])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_fa1_2_6_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufb2)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufb3)) exit(__LINE__);
if (clSetKernelArg(krn,6,sizeof(cl_mem),&bufb4)) exit(__LINE__);
if (clSetKernelArg(krn,7,sizeof(cl_mem),&bufb5)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,128*sizeof(float),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,128*sizeof(float),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,128*sizeof(float),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb3,CL_TRUE,0,128*sizeof(float),bb3,0,0,&ev[1+3])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb4,CL_TRUE,0,128*sizeof(float),bb4,0,0,&ev[1+4])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb5,CL_TRUE,0,128*sizeof(float),bb5,0,0,&ev[1+5])) 
exit(__LINE__);
if (clWaitForEvents(1+6,ev)) exit(__LINE__);
sum_correct = 425779.2;
sum = 0;
for(i=0;i<128;i++) sum += bb0[i];
for(i=0;i<128;i++) sum += bb1[i];
for(i=0;i<128;i++) sum += bb2[i];
for(i=0;i<128;i++) sum += bb3[i];
for(i=0;i<128;i++) sum += bb4[i];
for(i=0;i<128;i++) sum += bb5[i];
printf("(%e) sum 2 6 %e\n",sum_correct,sum);
printf("%e \n",fabs((sum-sum_correct)/sum_correct));
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseEvent(ev[4])) exit(__LINE__);
if (clReleaseEvent(ev[5])) exit(__LINE__);
if (clReleaseEvent(ev[6])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_fa1_3_5_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufa2)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufb2)) exit(__LINE__);
if (clSetKernelArg(krn,6,sizeof(cl_mem),&bufb3)) exit(__LINE__);
if (clSetKernelArg(krn,7,sizeof(cl_mem),&bufb4)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,128*sizeof(float),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,128*sizeof(float),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,128*sizeof(float),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb3,CL_TRUE,0,128*sizeof(float),bb3,0,0,&ev[1+3])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb4,CL_TRUE,0,128*sizeof(float),bb4,0,0,&ev[1+4])) 
exit(__LINE__);
if (clWaitForEvents(1+5,ev)) exit(__LINE__);
sum_correct = 500265.6;
sum = 0;
for(i=0;i<128;i++) sum += bb0[i];
for(i=0;i<128;i++) sum += bb1[i];
for(i=0;i<128;i++) sum += bb2[i];
for(i=0;i<128;i++) sum += bb3[i];
for(i=0;i<128;i++) sum += bb4[i];
printf("(%e) sum 3 5 %e\n",sum_correct,sum);
printf("%e \n",fabs((sum-sum_correct)/sum_correct));
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseEvent(ev[4])) exit(__LINE__);
if (clReleaseEvent(ev[5])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_fa1_4_4_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufa2)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufa3)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,6,sizeof(cl_mem),&bufb2)) exit(__LINE__);
if (clSetKernelArg(krn,7,sizeof(cl_mem),&bufb3)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,128*sizeof(float),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,128*sizeof(float),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,128*sizeof(float),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb3,CL_TRUE,0,128*sizeof(float),bb3,0,0,&ev[1+3])) 
exit(__LINE__);
if (clWaitForEvents(1+4,ev)) exit(__LINE__);
sum_correct = 485089.28;
sum = 0;
for(i=0;i<128;i++) sum += bb0[i];
for(i=0;i<128;i++) sum += bb1[i];
for(i=0;i<128;i++) sum += bb2[i];
for(i=0;i<128;i++) sum += bb3[i];
printf("(%e) sum 4 4 %e\n",sum_correct,sum);
printf("%e \n",fabs((sum-sum_correct)/sum_correct));
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseEvent(ev[4])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_fa1_5_3_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufa2)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufa3)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufa4)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,6,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clSetKernelArg(krn,7,sizeof(cl_mem),&bufb2)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,128*sizeof(float),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,128*sizeof(float),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,128*sizeof(float),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clWaitForEvents(1+3,ev)) exit(__LINE__);
sum_correct = 395740.8;
sum = 0;
for(i=0;i<128;i++) sum += bb0[i];
for(i=0;i<128;i++) sum += bb1[i];
for(i=0;i<128;i++) sum += bb2[i];
printf("(%e) sum 5 3 %e\n",sum_correct,sum);
printf("%e \n",fabs((sum-sum_correct)/sum_correct));
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_fa1_6_2_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufa2)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufa3)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufa4)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufa5)) exit(__LINE__);
if (clSetKernelArg(krn,6,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clSetKernelArg(krn,7,sizeof(cl_mem),&bufb1)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,128*sizeof(float),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,128*sizeof(float),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clWaitForEvents(1+2,ev)) exit(__LINE__);
sum_correct = 258539.52;
sum = 0;
for(i=0;i<128;i++) sum += bb0[i];
for(i=0;i<128;i++) sum += bb1[i];
printf("(%e) sum 6 2 %e\n",sum_correct,sum);
printf("%e \n",fabs((sum-sum_correct)/sum_correct));
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_fa1_7_1_kern",&err);
if (err) exit(__LINE__);
if (clSetKernelArg(krn,0,sizeof(cl_mem),&bufa0)) exit(__LINE__);
if (clSetKernelArg(krn,1,sizeof(cl_mem),&bufa1)) exit(__LINE__);
if (clSetKernelArg(krn,2,sizeof(cl_mem),&bufa2)) exit(__LINE__);
if (clSetKernelArg(krn,3,sizeof(cl_mem),&bufa3)) exit(__LINE__);
if (clSetKernelArg(krn,4,sizeof(cl_mem),&bufa4)) exit(__LINE__);
if (clSetKernelArg(krn,5,sizeof(cl_mem),&bufa5)) exit(__LINE__);
if (clSetKernelArg(krn,6,sizeof(cl_mem),&bufa6)) exit(__LINE__);
if (clSetKernelArg(krn,7,sizeof(cl_mem),&bufb0)) exit(__LINE__);
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,128*sizeof(float),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clWaitForEvents(1+1,ev)) exit(__LINE__);
sum_correct = 110633.6;
sum = 0;
for(i=0;i<128;i++) sum += bb0[i];
printf("(%e) sum 7 1 %e\n",sum_correct,sum);
printf("%e \n",fabs((sum-sum_correct)/sum_correct));
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_fa1_1_8_kern",&err);
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
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,128*sizeof(float),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,128*sizeof(float),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,128*sizeof(float),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb3,CL_TRUE,0,128*sizeof(float),bb3,0,0,&ev[1+3])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb4,CL_TRUE,0,128*sizeof(float),bb4,0,0,&ev[1+4])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb5,CL_TRUE,0,128*sizeof(float),bb5,0,0,&ev[1+5])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb6,CL_TRUE,0,128*sizeof(float),bb6,0,0,&ev[1+6])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb7,CL_TRUE,0,128*sizeof(float),bb7,0,0,&ev[1+7])) 
exit(__LINE__);
if (clWaitForEvents(1+8,ev)) exit(__LINE__);
sum_correct = 329492.48;
sum = 0;
for(i=0;i<128;i++) sum += bb0[i];
for(i=0;i<128;i++) sum += bb1[i];
for(i=0;i<128;i++) sum += bb2[i];
for(i=0;i<128;i++) sum += bb3[i];
for(i=0;i<128;i++) sum += bb4[i];
for(i=0;i<128;i++) sum += bb5[i];
for(i=0;i<128;i++) sum += bb6[i];
for(i=0;i<128;i++) sum += bb7[i];
printf("(%e) sum 1 8 %e\n",sum_correct,sum);
printf("%e \n",fabs((sum-sum_correct)/sum_correct));
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
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
krn = clCreateKernel(prg,"test_fa1_2_7_kern",&err);
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
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,128*sizeof(float),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,128*sizeof(float),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,128*sizeof(float),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb3,CL_TRUE,0,128*sizeof(float),bb3,0,0,&ev[1+3])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb4,CL_TRUE,0,128*sizeof(float),bb4,0,0,&ev[1+4])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb5,CL_TRUE,0,128*sizeof(float),bb5,0,0,&ev[1+5])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb6,CL_TRUE,0,128*sizeof(float),bb6,0,0,&ev[1+6])) 
exit(__LINE__);
if (clWaitForEvents(1+7,ev)) exit(__LINE__);
sum_correct = 565734.4;
sum = 0;
for(i=0;i<128;i++) sum += bb0[i];
for(i=0;i<128;i++) sum += bb1[i];
for(i=0;i<128;i++) sum += bb2[i];
for(i=0;i<128;i++) sum += bb3[i];
for(i=0;i<128;i++) sum += bb4[i];
for(i=0;i<128;i++) sum += bb5[i];
for(i=0;i<128;i++) sum += bb6[i];
printf("(%e) sum 2 7 %e\n",sum_correct,sum);
printf("%e \n",fabs((sum-sum_correct)/sum_correct));
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseEvent(ev[4])) exit(__LINE__);
if (clReleaseEvent(ev[5])) exit(__LINE__);
if (clReleaseEvent(ev[6])) exit(__LINE__);
if (clReleaseEvent(ev[7])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_fa1_3_6_kern",&err);
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
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,128*sizeof(float),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,128*sizeof(float),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,128*sizeof(float),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb3,CL_TRUE,0,128*sizeof(float),bb3,0,0,&ev[1+3])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb4,CL_TRUE,0,128*sizeof(float),bb4,0,0,&ev[1+4])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb5,CL_TRUE,0,128*sizeof(float),bb5,0,0,&ev[1+5])) 
exit(__LINE__);
if (clWaitForEvents(1+6,ev)) exit(__LINE__);
sum_correct = 697144.32;
sum = 0;
for(i=0;i<128;i++) sum += bb0[i];
for(i=0;i<128;i++) sum += bb1[i];
for(i=0;i<128;i++) sum += bb2[i];
for(i=0;i<128;i++) sum += bb3[i];
for(i=0;i<128;i++) sum += bb4[i];
for(i=0;i<128;i++) sum += bb5[i];
printf("(%e) sum 3 6 %e\n",sum_correct,sum);
printf("%e \n",fabs((sum-sum_correct)/sum_correct));
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseEvent(ev[4])) exit(__LINE__);
if (clReleaseEvent(ev[5])) exit(__LINE__);
if (clReleaseEvent(ev[6])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_fa1_4_5_kern",&err);
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
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,128*sizeof(float),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,128*sizeof(float),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,128*sizeof(float),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb3,CL_TRUE,0,128*sizeof(float),bb3,0,0,&ev[1+3])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb4,CL_TRUE,0,128*sizeof(float),bb4,0,0,&ev[1+4])) 
exit(__LINE__);
if (clWaitForEvents(1+5,ev)) exit(__LINE__);
sum_correct = 722969.6;
sum = 0;
for(i=0;i<128;i++) sum += bb0[i];
for(i=0;i<128;i++) sum += bb1[i];
for(i=0;i<128;i++) sum += bb2[i];
for(i=0;i<128;i++) sum += bb3[i];
for(i=0;i<128;i++) sum += bb4[i];
printf("(%e) sum 4 5 %e\n",sum_correct,sum);
printf("%e \n",fabs((sum-sum_correct)/sum_correct));
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseEvent(ev[4])) exit(__LINE__);
if (clReleaseEvent(ev[5])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_fa1_5_4_kern",&err);
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
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,128*sizeof(float),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,128*sizeof(float),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,128*sizeof(float),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb3,CL_TRUE,0,128*sizeof(float),bb3,0,0,&ev[1+3])) 
exit(__LINE__);
if (clWaitForEvents(1+4,ev)) exit(__LINE__);
sum_correct = 653286.4;
sum = 0;
for(i=0;i<128;i++) sum += bb0[i];
for(i=0;i<128;i++) sum += bb1[i];
for(i=0;i<128;i++) sum += bb2[i];
for(i=0;i<128;i++) sum += bb3[i];
printf("(%e) sum 5 4 %e\n",sum_correct,sum);
printf("%e \n",fabs((sum-sum_correct)/sum_correct));
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseEvent(ev[4])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_fa1_6_3_kern",&err);
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
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,128*sizeof(float),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,128*sizeof(float),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb2,CL_TRUE,0,128*sizeof(float),bb2,0,0,&ev[1+2])) 
exit(__LINE__);
if (clWaitForEvents(1+3,ev)) exit(__LINE__);
sum_correct = 508999.68;
sum = 0;
for(i=0;i<128;i++) sum += bb0[i];
for(i=0;i<128;i++) sum += bb1[i];
for(i=0;i<128;i++) sum += bb2[i];
printf("(%e) sum 6 3 %e\n",sum_correct,sum);
printf("%e \n",fabs((sum-sum_correct)/sum_correct));
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseEvent(ev[3])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_fa1_7_2_kern",&err);
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
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,128*sizeof(float),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb1,CL_TRUE,0,128*sizeof(float),bb1,0,0,&ev[1+1])) 
exit(__LINE__);
if (clWaitForEvents(1+2,ev)) exit(__LINE__);
sum_correct = 321843.2;
sum = 0;
for(i=0;i<128;i++) sum += bb0[i];
for(i=0;i<128;i++) sum += bb1[i];
printf("(%e) sum 7 2 %e\n",sum_correct,sum);
printf("%e \n",fabs((sum-sum_correct)/sum_correct));
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
if (clReleaseEvent(ev[0])) exit(__LINE__);
if (clReleaseEvent(ev[1])) exit(__LINE__);
if (clReleaseEvent(ev[2])) exit(__LINE__);
if (clReleaseKernel(krn)) exit(__LINE__);
krn = clCreateKernel(prg,"test_fa1_8_1_kern",&err);
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
if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) 
exit(__LINE__);
if (clEnqueueReadBuffer(cmdq,bufb0,CL_TRUE,0,128*sizeof(float),bb0,0,0,&ev[1+0])) 
exit(__LINE__);
if (clWaitForEvents(1+1,ev)) exit(__LINE__);
sum_correct = 134379.52;
sum = 0;
for(i=0;i<128;i++) sum += bb0[i];
printf("(%e) sum 8 1 %e\n",sum_correct,sum);
printf("%e \n",fabs((sum-sum_correct)/sum_correct));
if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);
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
