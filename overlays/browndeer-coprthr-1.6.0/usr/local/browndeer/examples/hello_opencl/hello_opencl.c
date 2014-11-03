/* hello_opencl.c */

#include <stdlib.h>
#include <stdio.h>
#include <CL/cl.h>

int main()
{ 
   int i,j;
   int err;
   char buffer[256];

   unsigned int n = 1024;

   cl_uint nplatforms;
   cl_platform_id* platforms;
   cl_platform_id platform;

   clGetPlatformIDs( 0,0,&nplatforms);
   platforms = (cl_platform_id*)malloc(nplatforms*sizeof(cl_platform_id));
   clGetPlatformIDs( nplatforms, platforms, 0);

   for(i=0; i<nplatforms; i++) {
      platform = platforms[i];
      clGetPlatformInfo(platforms[i],CL_PLATFORM_NAME,256,buffer,0);
      if (!strcmp(buffer,"coprthr-e")) break;
   }

   if (i<nplatforms) platform = platforms[i];
   else exit(1);

   cl_uint ndevices;
   cl_device_id* devices;
   cl_device_id dev;

   clGetDeviceIDs(platform,CL_DEVICE_TYPE_ACCELERATOR,0,0,&ndevices);
   devices = (cl_device_id*)malloc(ndevices*sizeof(cl_device_id));
   clGetDeviceIDs(platform, CL_DEVICE_TYPE_ACCELERATOR,ndevices,devices,0);

   if (ndevices) dev = devices[0];
   else exit(1);

   cl_context_properties ctxprop[3] = {
      (cl_context_properties)CL_CONTEXT_PLATFORM,
      (cl_context_properties)platform,
      (cl_context_properties)0
   };
   cl_context ctx = clCreateContext(ctxprop,1,&dev,0,0,&err);
   cl_command_queue cmdq = clCreateCommandQueue(ctx,dev,0,&err);

   size_t aa_sz = n*n*sizeof(float);
   size_t b_sz = n*sizeof(float);
   size_t c_sz = n*sizeof(float);

   float* aa = (float*)malloc(n*n*sizeof(float)); 
   float* b = (float*)malloc(n*sizeof(float));
   float* c = (float*)malloc(n*sizeof(float));

   for(i=0;i<n;i++) for(j=0;j<n;j++) aa[i*n+j] = 1.1f*i*j;
   for(i=0;i<n;i++) b[i] = 2.2f*i;
   for(i=0;i<n;i++) c[i] = 0.0f;

   cl_mem aa_buf = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,aa_sz,aa,&err);
   cl_mem b_buf = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,b_sz,b,&err);
   cl_mem c_buf = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,c_sz,c,&err);

   const char kernel_code[] = 
      "__kernel void matvecmult_kern(\n"
      "   uint n,__global float* aa,__global float* b,__global float* c )\n"
      "{\n"
      "   int i = get_global_id(0);\n"
      "   int j;\n"
      "   float tmp = 0.0f;\n"
      "   for(j=0;j<n;j++) tmp += aa[i*n+j] * b[j];\n"
      "   c[i] = aa[i*n+i];\n"
      "}\n";

	const char* src[1] = { kernel_code };
	size_t src_sz = sizeof(kernel_code);

   cl_program prg = clCreateProgramWithSource(ctx,1,(const char**)&src,&src_sz,&err);
   clBuildProgram(prg,1,&dev,0,0,0);
   cl_kernel krn = clCreateKernel(prg,"matvecmult_kern",&err);

   clSetKernelArg(krn,0,sizeof(cl_uint),&n);
   clSetKernelArg(krn,1,sizeof(cl_mem),&aa_buf);
   clSetKernelArg(krn,2,sizeof(cl_mem),&b_buf);
   clSetKernelArg(krn,3,sizeof(cl_mem),&c_buf);

   size_t gtdsz[] = { n };
   size_t ltdsz[] = { 16 };

   cl_event ev[10];
 
   clEnqueueNDRangeKernel(cmdq,krn,1,0,gtdsz,ltdsz,0,0,&ev[0]);
   clEnqueueReadBuffer(cmdq,c_buf,CL_TRUE,0,c_sz,c,0,0,&ev[1]);

   err = clWaitForEvents(2,ev);

   for(i=0;i<n;i++) printf("c[%d] %f\n",i,c[i]);
   printf("clWaitForEvents returned %d\n",err);

   clReleaseEvent(ev[1]);
   clReleaseEvent(ev[0]);
   clReleaseKernel(krn);
   clReleaseProgram(prg);
   clReleaseMemObject(aa_buf);
   clReleaseMemObject(b_buf);
   clReleaseMemObject(c_buf);
   clReleaseCommandQueue(cmdq);
   clReleaseContext(ctx);

   free(aa);
   free(b);
   free(c);

}

