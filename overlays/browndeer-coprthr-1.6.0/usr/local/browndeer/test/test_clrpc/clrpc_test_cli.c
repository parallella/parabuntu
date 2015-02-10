
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "CL/cl.h"
#include "clrpc.h"

typedef struct {
   void* _reserved;
   clrpc_dptr* obj;
   struct evrpc_pool* rpc_pool;
} _xobj_t;

static void
clrpc_client_test2(void)
{
	int err;

	int size = 1024;

	cl_uint nplatforms = 0;
	cl_platform_id* platforms = 0;
	cl_uint nplatforms_ret;

	clGetPlatformIDs(nplatforms,platforms,&nplatforms_ret);	

	printf(  "after call one i get nplatforms_ret = %d",
		nplatforms_ret);

	if (nplatforms_ret == 0) exit(1);

	nplatforms = nplatforms_ret;
	platforms = (cl_platform_id*)calloc(nplatforms,sizeof(cl_platform_id));

	clGetPlatformIDs(nplatforms,platforms,&nplatforms_ret);

	int i;
	for(i=0;i<nplatforms;i++) {
		clrpc_dptr* tmp = ((_xobj_t*)platforms[i])->obj;
		int is_rpc;
		if ( clGetPlatformInfo(platforms[i],999,sizeof(cl_int),&is_rpc,0)==CL_SUCCESS) {
			printf(  "platforms[%d] local=%p remote=%p\n",
				i,(void*)tmp->local,
				(void*)tmp->remote);
		} else {
			printf( "platforms[%d] not RPC\n",i);
		}
	}

	char buffer[1024];
	size_t sz;
	cl_platform_id rpc_platform = 0;
	for(i=0;i<nplatforms;i++) {
		clGetPlatformInfo(platforms[i],CL_PLATFORM_NAME,1023,buffer,&sz);
		printf(  "\n [%d] CL_PLATFORM_NAME|%ld:%s|\n",i,sz,buffer);
	}

int iplat;
for(iplat=0;iplat<nplatforms;iplat++) {

printf("\n******************\nTEST PLATFORM %d\n*************\n\n",iplat);

	cl_uint ndevices = 0;
	cl_device_id* devices = 0;
	cl_uint ndevices_ret;

	clGetDeviceIDs(platforms[iplat],CL_DEVICE_TYPE_ALL,
		ndevices,devices,&ndevices_ret);

	printf(  "after call one i get ndevices_ret = %d\n", ndevices_ret);

	if (ndevices_ret > 10) exit(-1);

	ndevices = ndevices_ret;
	devices = (cl_device_id*)calloc(ndevices,sizeof(cl_device_id));

	clGetDeviceIDs(platforms[iplat],CL_DEVICE_TYPE_ALL,
		ndevices,devices,&ndevices_ret);

	if (!ndevices_ret) {
		//printf("no devices, stopping.\n");
		//exit(1);
		printf("no devices, skipping.\n");
		continue;
	}

	for(i=0;i<ndevices;i++) {
		clrpc_dptr* tmp = ((_xobj_t*)devices[i])->obj;
		clGetDeviceInfo(devices[i],CL_DEVICE_NAME,1023,buffer,&sz);
		printf(  "CL_DEVICE_NAME |%s|\n",buffer);
		cl_platform_id tmpid;
		clGetDeviceInfo(devices[i],CL_DEVICE_PLATFORM,sizeof(tmpid),&tmpid,&sz);
		printf("%p\n",platforms[iplat]); fflush(stdout);
		printf("%p\n",tmpid); fflush(stdout);
		clGetPlatformInfo(tmpid,CL_PLATFORM_NAME,1023,buffer,&sz);
		printf(  "\n [%d] CL_PLATFORM_NAME|%ld:%s|\n",i,sz,buffer);
	}

	cl_context_properties ctxprop[] = { 
		CL_CONTEXT_PLATFORM, (cl_context_properties)platforms[iplat], 0 };

	printf("i am setting this: prop[%d] %p\n",iplat,platforms[iplat]);

	cl_context ctx = clCreateContext(ctxprop,ndevices,devices, 0,0,&err);

	cl_command_queue* cmdq 
		= (cl_command_queue*) calloc(ndevices,sizeof(cl_command_queue));

	for(i=0;i<ndevices;i++) {
		cmdq[i] = clCreateCommandQueue(ctx,devices[i],0,&err);
		printf( 	 "cmdq %d %p",i,cmdq[i]);
	}

	cl_mem a_buf = clCreateBuffer(ctx,CL_MEM_READ_WRITE,size*sizeof(int),
		0,&err);
	cl_mem b_buf = clCreateBuffer(ctx,CL_MEM_READ_WRITE,size*sizeof(int),
		0,&err);
	cl_mem c_buf = clCreateBuffer(ctx,CL_MEM_READ_WRITE,size*sizeof(int),
		0,&err);
	cl_mem d_buf = clCreateBuffer(ctx,CL_MEM_READ_WRITE,size*sizeof(int),
		0,&err);

	int* a = (int*)malloc(1024*sizeof(int));
	int* b = (int*)malloc(1024*sizeof(int));
	int* c = (int*)malloc(1024*sizeof(int));
	int* d = (int*)malloc(1024*sizeof(int));

	char* prgsrc[] = { 
		"__kernel void my_kern( int n, __global int* a, __global int* b )\n"
		" { int i = get_global_id(0); int tmp = 0; int j; for(j=0;j<n;j++) tmp += a[i] * a[j]; b[i] = tmp; }\n" 
	};
	size_t prgsrc_sz = strlen(prgsrc[0]) + 1;

	cl_program prg = clCreateProgramWithSource(ctx,1,
		(const char**)prgsrc,&prgsrc_sz,&err);

	clBuildProgram(prg,ndevices,devices,0,0,0);

	cl_kernel krn = clCreateKernel(prg,"my_kern",&err);

int idev;
for(idev=0;idev<ndevices;idev++) {
printf("\n******************\nTEST DEVICE %d(%d)\n*************\n\n",idev,iplat);

	for(i=0;i<size;i++) a[i] = i*10;
	for(i=0;i<size;i++) b[i] = i*10+1;
	for(i=0;i<size;i++) c[i] = 0;
	for(i=0;i<size;i++) d[i] = 0;

	cl_event ev[8];

	for(i=0;i<32;i++) printf("%d/",a[i]); printf("\n");
	for(i=0;i<32;i++) printf("%d/",b[i]); printf("\n");

	clEnqueueWriteBuffer(cmdq[idev],a_buf,CL_FALSE,0,size*sizeof(int),a,
		0,0,&ev[0]);
	clEnqueueWriteBuffer(cmdq[idev],b_buf,CL_FALSE,0,size*sizeof(int),b,
		1,ev,&ev[1]);
	clEnqueueWriteBuffer(cmdq[idev],c_buf,CL_FALSE,0,size*sizeof(int),c,
		2,ev,&ev[2]);
	clEnqueueWriteBuffer(cmdq[idev],d_buf,CL_FALSE,0,size*sizeof(int),d,
		3,ev,&ev[3]);

	size_t offset = 0; 
	size_t gwsz = 128;
	size_t lwsz = 16;

	clSetKernelArg(krn,0,sizeof(int),&size);
	clSetKernelArg(krn,1,sizeof(cl_mem),&a_buf);
	clSetKernelArg(krn,2,sizeof(cl_mem),&c_buf);
	clEnqueueNDRangeKernel(cmdq[idev],krn,1,&offset,&gwsz,&lwsz,4,ev,&ev[4]);

	clSetKernelArg(krn,1,sizeof(cl_mem),&b_buf);
	clSetKernelArg(krn,2,sizeof(cl_mem),&d_buf);
	clEnqueueNDRangeKernel(cmdq[idev],krn,1,&offset,&gwsz,&lwsz,5,ev,&ev[5]);

	clEnqueueReadBuffer(cmdq[idev],c_buf,CL_FALSE,0,size*sizeof(int),c,
		6,ev,&ev[6]);
	clEnqueueReadBuffer(cmdq[idev],d_buf,CL_FALSE,0,size*sizeof(int),d,
		7,ev,&ev[7]);

	clFlush(cmdq[idev]);

	clWaitForEvents(8,ev);

	for(i=0;i<32;i++) printf("%d/",c[i]); printf("\n");
	for(i=0;i<32;i++) printf("%d/",d[i]); printf("\n");

	for(i=0;i<8;i++) clReleaseEvent(ev[i]);

}

	clReleaseKernel(krn);

	clReleaseProgram(prg);

	clReleaseMemObject(a_buf);
	clReleaseMemObject(b_buf);
	clReleaseMemObject(c_buf);
	clReleaseMemObject(d_buf);

	clReleaseCommandQueue(cmdq[0]);
	clReleaseContext(ctx);

//	printf("sleeping ...\n");
//	sleep(1);

}

//	clrpc_final();

}


int
main(int argc, const char **argv)
{

	printf("hello world\n");

   clrpc_client_test2();

   return 0;
}

