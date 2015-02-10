

#ifndef _CLRPC_H
#define _CLRPC_H

#include <CL/cl.h>

#define __CLRPC_TYPES

//#include "util.h"
#include "clrpc_common.h"

//int clrpc_init( unsigned int nserver, clrpc_server_info* );
int clrpc_init();
int clrpc_connect( unsigned int nserver, clrpc_server_info* );
int clrpc_final( void );

cl_int 
clrpc_clGetPlatformIDs( cl_uint nplatforms,
	cl_platform_id* platforms, cl_uint* nplatforms_ret);

cl_int
clrpc_clGetPlatformInfo(cl_platform_id platform, cl_platform_info param_name,
	size_t param_sz, void *param_val, size_t *param_sz_ret);

cl_int
clrpc_clGetDeviceIDs( cl_platform_id platform, cl_device_type devtype,
   cl_uint ndevices, cl_device_id* devices, cl_uint* ndevices_ret);
   
cl_int
clrpc_clGetDeviceInfo(cl_device_id device, cl_device_info param_name,
	size_t param_sz, void *param_val, size_t *param_sz_ret);

cl_context
clrpc_clCreateContext( const cl_context_properties* prop, cl_uint ndev,
   const cl_device_id* devices, 
	void (*pfn_notify) (const char*, const void*, size_t, void*), 
	void* user_data, cl_int* err_ret );

cl_int
clrpc_clGetContextInfo(cl_context context, cl_context_info param_name,
	size_t param_sz, void *param_val, size_t *param_sz_ret);

cl_int
clrpc_clReleaseContext( cl_context context );

cl_command_queue
clrpc_clCreateCommandQueue( cl_context context, cl_device_id device,
   cl_command_queue_properties prop, cl_int* err_ret );

cl_int
clrpc_clReleaseCommandQueue( cl_command_queue command_queue );

cl_mem
clrpc_clCreateBuffer(cl_context context, cl_mem_flags flags, size_t size,
   void *host_ptr, cl_int* err_ret );

cl_int
clrpc_clReleaseMemObject( cl_mem memobj );

cl_int
clrpc_clEnqueueReadBuffer(cl_command_queue command_queue, cl_mem buffer,
	cl_bool blocking_read, size_t offset, size_t cb, void *ptr,
	cl_uint num_events_in_wait_list, const cl_event *event_wait_list,
	cl_event *event);

cl_int 
clrpc_clEnqueueWriteBuffer( cl_command_queue command_queue, cl_mem buffer,
	cl_bool blocking_write, size_t offset, size_t cb, const void *ptr,
	cl_uint num_events_in_wait_list, const cl_event *event_wait_list,
	cl_event *event );

cl_int
clrpc_clReleaseEvent( cl_event event );

cl_program 
clrpc_clCreateProgramWithSource( cl_context context, cl_uint count,
	const char **strings, const size_t *lengths, cl_int *errcode_ret);

cl_int
clrpc_clGetProgramInfo(cl_program program, cl_program_info param_name,
	size_t param_sz, void *param_val, size_t *param_sz_ret);

cl_int
clrpc_clBuildProgram( cl_program program, cl_uint num_devices,
	const cl_device_id *device_list, const char *options,
	void (CL_CALLBACK *pfn_notify)(cl_program program, void *user_data),
	void *user_data);

cl_int
clrpc_clReleaseProgram( cl_program program );

cl_kernel 
clrpc_clCreateKernel(cl_program program, const char *kernel_name, 
	cl_int *err_ret);

cl_int
clrpc_clGetKernelInfo(cl_kernel kernel, cl_kernel_info param_name,
	size_t param_sz, void *param_val, size_t *param_sz_ret);

cl_int
clrpc_clReleaseKernel( cl_kernel kernel );

cl_int
clrpc_clSetKernelArg( cl_kernel kernel, cl_uint arg_index, size_t arg_size,
	const void *arg_value);

cl_int
clrpc_clEnqueueNDRangeKernel ( cl_command_queue command_queue, cl_kernel kernel,
   cl_uint work_dim, const size_t* global_work_offset, 
	const size_t* global_work_size, const size_t* local_work_size,
   cl_uint num_events_in_wait_list, const cl_event *event_wait_list,
   cl_event* event);

cl_int
clrpc_clFlush( cl_command_queue command_queue );

cl_int 
clrpc_clWaitForEvents(cl_uint num_events, const cl_event* event_list);

#endif

