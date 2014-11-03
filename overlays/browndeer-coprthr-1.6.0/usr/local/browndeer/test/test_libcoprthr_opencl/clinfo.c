
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>
#include <CL/cl.h>

#define CHECK_ERROR( call ) do { \
	int rc; \
	if ( rc=call) { \
		fprintf(stderr,"[%d] clinfo: ERROR %d reported from '%s'\n",pid,rc,#call); \
		exit(1); \
	} } while(0)

struct cldev_info {
   cl_device_type dev_type;
   cl_uint dev_vendor_id;
   cl_uint dev_max_core;
   cl_uint dev_max_wi_dim;
   size_t dev_max_wi_sz[4]; /* XXX is this large enough? -DAR */
   cl_uint dev_max_wi_sz_is_symmetric; /* default should be 1 */
   size_t dev_max_wg_sz;
   cl_uint dev_pref_vec_char;
   cl_uint dev_pref_vec_short;
   cl_uint dev_pref_vec_int;
   cl_uint dev_pref_vec_long;
   cl_uint dev_pref_vec_float;
   cl_uint dev_pref_vec_double;
   cl_uint dev_max_freq;
   cl_bitfield dev_addr_bits;
   cl_ulong dev_global_mem_sz;
   cl_ulong dev_max_mem_alloc_sz;
   cl_bool dev_img_sup;
   cl_uint dev_max_img_args_r;
   cl_uint dev_max_img_args_w;
   size_t dev_img2d_max_width;
   size_t dev_img2d_max_height;
   size_t dev_img3d_max_width;
   size_t dev_img3d_max_height;
   size_t dev_img3d_max_depth;
   cl_uint dev_max_samplers;
   size_t dev_max_param_sz;
   cl_uint dev_mem_base_addr_align;
   char dev_name[256];
   char dev_vendor[256];
   char dev_version[256];
   char dev_drv_version[256];
   cl_ulong dev_local_mem_sz;
};

int clgetdevinfo( cl_device_id* d, struct cldev_info* di);
void clfreport_devinfo( FILE* fp, size_t ndev, struct cldev_info* info );


int main() 
{

	int err;

	pid_t pid = getpid();

	printf("[%d] clinfo: report OpenCL platform and device information: ",pid); fflush(stdout);

	system("hostname -i");

	int i,j;
	char buf[1024];

	cl_uint nplatforms = 0;

	CHECK_ERROR( clGetPlatformIDs(0,0,&nplatforms) );
	printf("[%d] nplatforms%d\n",pid,nplatforms);

	if (!nplatforms) {
		printf("[%d] clinfo: No platforms found\n",pid);
		exit(0);
	} else {
		printf("[%d] clinfo: Number of platforms found = %d\n",pid,nplatforms);
	}

	cl_platform_id* platforms 
		= (cl_platform_id*)calloc(nplatforms,sizeof(cl_platform_id));

	CHECK_ERROR( clGetPlatformIDs(nplatforms,platforms,0) );

	for(i=0;i<nplatforms;i++) {

		printf("[%d] clinfo: platform %d:\n",pid,i);

		CHECK_ERROR( 
			clGetPlatformInfo(platforms[i],CL_PLATFORM_PROFILE,1024,&buf,0) );
		printf("[%d] clinfo: CL_PLATFORM_PROFILE = %s\n",pid,buf);	

		CHECK_ERROR( 
			clGetPlatformInfo(platforms[i],CL_PLATFORM_VERSION,1024,&buf,0) );
		printf("[%d] clinfo: CL_PLATFORM_VERSION = %s\n",pid,buf);	

		CHECK_ERROR( 
			clGetPlatformInfo(platforms[i],CL_PLATFORM_NAME,1024,&buf,0) );
		printf("[%d] clinfo: CL_PLATFORM_NAME = %s\n",pid,buf);	

		CHECK_ERROR( 
			clGetPlatformInfo(platforms[i],CL_PLATFORM_VENDOR,1024,&buf,0) );
		printf("[%d] clinfo: CL_PLATFORM_VENDOR = %s\n",pid,buf);	

		CHECK_ERROR( 
			clGetPlatformInfo(platforms[i],CL_PLATFORM_EXTENSIONS,1024,&buf,0) );
		printf("[%d] clinfo: CL_PLATFORM_EXTENSIONS = %s\n",pid,buf);	

		cl_uint ndev = 0;
		CHECK_ERROR(
			clGetDeviceIDs(platforms[i],CL_DEVICE_TYPE_ALL,0,0,&ndev) );

		if (ndev) {

			printf("[%d] clinfo: Number of devices found for this platform = %d\n",pid, ndev);

			cl_device_id* devices 
				= (cl_device_id*)calloc(ndev,sizeof(cl_device_id));

			CHECK_ERROR(
				clGetDeviceIDs(platforms[i],CL_DEVICE_TYPE_ALL,ndev,devices,0) );

			struct cldev_info devinfo;

			for(j=0;j<ndev;j++) {

				clgetdevinfo( &devices[j], &devinfo);
				clfreport_devinfo( stdout, 1, &devinfo );

			}

			cl_context_properties ctxprop[] = {
				CL_CONTEXT_PLATFORM, (cl_context_properties)platforms[i], 0
			};

			cl_context ctx = clCreateContext(ctxprop,ndev,devices,0,0,&err);
			printf("[%d] clinfo: clCreateContext %p (%d)\n",pid,ctx,err);

			cl_command_queue* cmdq = (cl_command_queue*)calloc(ndev,sizeof(cl_command_queue));
			for(j=0;j<ndev;j++) {
				cmdq[j] = clCreateCommandQueue(ctx,devices[j],0,&err);
				printf("[%d] clinfo: clCreateCommandQueue [%d] %p (%d)\n",pid,j,cmdq[j],err);
			}

			for(j=0;j<ndev;j++) 
				clReleaseCommandQueue(cmdq[j]);

			clReleaseContext(ctx);

			if (cmdq) free(cmdq);

			if (devices) free(devices);

		} else {

			printf("[%d] clinfo: No devices found for this platform\n",pid);

		}

	}

	return(0);

}


int 
clgetdevinfo( cl_device_id* d, struct cldev_info* di)
{

   int i,err;

         err = clGetDeviceInfo(
            *d,CL_DEVICE_TYPE,
            sizeof(cl_device_type),&di->dev_type,0
         );

         err = clGetDeviceInfo(
            *d,CL_DEVICE_VENDOR_ID,
            sizeof(cl_uint),&di->dev_vendor_id,0
         );

         err = clGetDeviceInfo(
            *d,CL_DEVICE_MAX_COMPUTE_UNITS,sizeof(cl_uint),&di->dev_max_core,0
         );

         err = clGetDeviceInfo(
            *d,CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS,
            sizeof(cl_uint),&di->dev_max_wi_dim,0
         );

         assert(di->dev_max_wi_dim<=4);

         err = clGetDeviceInfo(
            *d,CL_DEVICE_MAX_WORK_ITEM_SIZES,
            di->dev_max_wi_dim*sizeof(size_t),di->dev_max_wi_sz,0
         );
         di->dev_max_wi_sz_is_symmetric=1;
         for(i=0;i<di->dev_max_wi_dim;i++)
            if(di->dev_max_wi_sz[0]!=di->dev_max_wi_sz[i])
               di->dev_max_wi_sz_is_symmetric=0;

         err = clGetDeviceInfo(
            *d,CL_DEVICE_MAX_WORK_GROUP_SIZE,
            sizeof(size_t),&di->dev_max_wg_sz,0
         );

         err = clGetDeviceInfo(
            *d,CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR,
            sizeof(cl_uint),&di->dev_pref_vec_char,0
         );
         err = clGetDeviceInfo(
            *d,CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT,
            sizeof(cl_uint),&di->dev_pref_vec_short,0
         );
         err = clGetDeviceInfo(
            *d,CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT,
            sizeof(cl_uint),&di->dev_pref_vec_int,0
         );
         err = clGetDeviceInfo(
            *d,CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG,
            sizeof(cl_uint),&di->dev_pref_vec_long,0
         );
         err = clGetDeviceInfo(
            *d,CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT,
            sizeof(cl_uint),&di->dev_pref_vec_float,0
         );
         err = clGetDeviceInfo(
            *d,CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE,
            sizeof(cl_uint),&di->dev_pref_vec_double,0
         );

         err = clGetDeviceInfo(
            *d,CL_DEVICE_MAX_CLOCK_FREQUENCY,
            sizeof(cl_uint),&di->dev_max_freq,0
         );

         err = clGetDeviceInfo(
            *d,CL_DEVICE_ADDRESS_BITS,
            sizeof(cl_bitfield),&di->dev_addr_bits,0
         );

         err = clGetDeviceInfo(
            *d,CL_DEVICE_GLOBAL_MEM_SIZE,
            sizeof(cl_ulong),&di->dev_global_mem_sz,0
         );
         err = clGetDeviceInfo(
            *d,CL_DEVICE_MAX_MEM_ALLOC_SIZE,
            sizeof(cl_ulong),&di->dev_max_mem_alloc_sz,0
         );


         /*
          * check image support
          */

         err = clGetDeviceInfo(
            *d,CL_DEVICE_IMAGE_SUPPORT,
            sizeof(cl_bool),&di->dev_img_sup,0
         );
         err = clGetDeviceInfo(
            *d,CL_DEVICE_MAX_READ_IMAGE_ARGS,
            sizeof(cl_uint),&di->dev_max_img_args_r,0
         );
         err = clGetDeviceInfo(
            *d,CL_DEVICE_MAX_WRITE_IMAGE_ARGS,
            sizeof(cl_uint),&di->dev_max_img_args_w,0
         );
         err = clGetDeviceInfo(
            *d,CL_DEVICE_IMAGE2D_MAX_WIDTH,
            sizeof(size_t),&di->dev_img2d_max_width,0
         );
         err = clGetDeviceInfo(
            *d,CL_DEVICE_IMAGE2D_MAX_HEIGHT,
            sizeof(size_t),&di->dev_img2d_max_height,0
         );
         err = clGetDeviceInfo(
            *d,CL_DEVICE_IMAGE2D_MAX_WIDTH,
            sizeof(size_t),&di->dev_img3d_max_width,0
         );
         err = clGetDeviceInfo(
            *d,CL_DEVICE_IMAGE2D_MAX_HEIGHT,
            sizeof(size_t),&di->dev_img3d_max_height,0
         );
         err = clGetDeviceInfo(
            *d,CL_DEVICE_IMAGE3D_MAX_DEPTH,
            sizeof(size_t),&di->dev_img3d_max_height,0
         );
         err = clGetDeviceInfo(
            *d,CL_DEVICE_MAX_SAMPLERS,
            sizeof(cl_uint),&di->dev_max_samplers,0
         );

         err = clGetDeviceInfo(
            *d,CL_DEVICE_MAX_PARAMETER_SIZE,
            sizeof(size_t),&di->dev_max_param_sz,0
         );

         err = clGetDeviceInfo(
            *d,CL_DEVICE_MEM_BASE_ADDR_ALIGN,
            sizeof(cl_uint),&di->dev_mem_base_addr_align,0
         );

         err = clGetDeviceInfo(*d,CL_DEVICE_NAME,256,di->dev_name,0);
         err = clGetDeviceInfo(*d,CL_DEVICE_VENDOR,256,di->dev_vendor,0);
         err = clGetDeviceInfo(*d,CL_DEVICE_VERSION,256,di->dev_version,0);
         err = clGetDeviceInfo(*d,CL_DRIVER_VERSION,256,di->dev_drv_version,0);

         err = clGetDeviceInfo(
            *d,CL_DEVICE_LOCAL_MEM_SIZE,
            sizeof(cl_ulong),&di->dev_local_mem_sz,0
         );

   return(0);
}

void  
clfreport_devinfo( FILE* fp, size_t ndev, struct cldev_info* info )
{
   int i,n;
   struct cldev_info* di;

   if (info) for(n=0,di = info;n<ndev;n++,di++) {

      fprintf(fp,"clinfo: device %d:\n",n);

      fprintf(fp,"clinfo: CL_DEVICE_TYPE = ");
      if (di->dev_type&CL_DEVICE_TYPE_CPU) fprintf(fp," CPU");
      if (di->dev_type&CL_DEVICE_TYPE_GPU) fprintf(fp," GPU");
      if (di->dev_type&CL_DEVICE_TYPE_ACCELERATOR) fprintf(fp," ACCELERATOR");
      if (di->dev_type&CL_DEVICE_TYPE_DEFAULT) fprintf(fp," DEFAULT");
      fprintf(fp,"\n");

      fprintf(fp,"clinfo: CL_DEVICE_VENDOR_ID = %d\n",di->dev_vendor_id);
      fprintf(fp,"clinfo: CL_DEVICE_MAX_COMPUTE_UNITS = %d\n",di->dev_max_core);
      fprintf(fp,"clinfo: CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS = %d\n",
			di->dev_max_wi_dim);

      if (di->dev_max_wi_dim>0) {

         fprintf(fp,"clinfo: CL_DEVICE_MAX_WORK_ITEM_SIZES = ");

         if (di->dev_max_wi_sz_is_symmetric)
            fprintf(fp," %ld (symmetric)\n",di->dev_max_wi_sz[0]);
         else
            for(i=0;i<di->dev_max_wi_dim;i++)
               fprintf(fp," [%d]%ld\n",i,di->dev_max_wi_sz[i]);
      }

      fprintf(fp,"clinfo: CL_DEVICE_MAX_WORK_GROUP_SIZE = %ld\n",
			di->dev_max_wg_sz);
      fprintf( fp,"clinfo: CL_DEVICE_PREFERRED_VECTOR_WIDTH_CHAR = %d\n",
			di->dev_pref_vec_char);
	 	fprintf( fp,"clinfo: CL_DEVICE_PREFERRED_VECTOR_WIDTH_SHORT = %d\n",
         di->dev_pref_vec_short);
      fprintf( fp,"clinfo: CL_DEVICE_PREFERRED_VECTOR_WIDTH_INT = %d\n",
			di->dev_pref_vec_int);
      fprintf( fp,"clinfo: CL_DEVICE_PREFERRED_VECTOR_WIDTH_LONG = %d\n",
			di->dev_pref_vec_long);
      fprintf( fp,"clinfo: CL_DEVICE_PREFERRED_VECTOR_WIDTH_FLOAT = %d\n",
			di->dev_pref_vec_float);
      fprintf(
         fp,"clinfo: CL_DEVICE_PREFERRED_VECTOR_WIDTH_DOUBLE = %d\n",
         di->dev_pref_vec_double
      );
      fprintf(fp,"clinfo: CL_DEVICE_MAX_CLOCK_FREQUENCY = %d\n",
			di->dev_max_freq);

      fprintf(fp,"clinfo: CL_DEVICE_ADDRESS_BITS = 0x%x\n",
			(int)di->dev_addr_bits);

      fprintf(fp,"clinfo: CL_DEVICE_GLOBAL_MEM_SZ = %ld\n",
			di->dev_global_mem_sz);

      if (di->dev_img_sup) {
         fprintf(fp,"clinfo: CL_DEVICE_IMAGE_SUPPORT = true\n");
         fprintf( fp,"clinfo: CL_DEVICE_MAX_READ_IMAGE_ARGS = %d\n",
					di->dev_max_img_args_r);
         fprintf( fp,"clinfo: CL_DEVICE_MAX_WRITE_IMAGE_ARGS = %d\n",
				di->dev_max_img_args_w);
         fprintf( fp,"clinfo: CL_DEVICE_IMAGE2D_MAX_WIDTH = %ld\n",
				di->dev_img2d_max_width);
         fprintf( fp,"clinfo: CL_DEVICE_IMAGE2D_MAX_HEIGHT = %ld\n",
				di->dev_img2d_max_height);
         fprintf( fp,"clinfo: CL_DEVICE_IMAGE3D_MAX_WIDTH = %ld\n",
				di->dev_img3d_max_width);
         fprintf( fp,"clinfo: CL_DEVICE_IMAGE3D_MAX_HEIGHT = %ld\n",
				di->dev_img3d_max_height);
         fprintf(fp,"clinfo: CL_DEVICE_IMAGE3D_MAX_DEPTH = %ld\n",
				di->dev_img3d_max_depth);
      } else {
         fprintf(fp,"clinfo: CL_DEVICE_IMAGE_SUPPORT = false\n");
      }

      fprintf(fp,"clinfo: CL_DEVICE_MAX_PARAMETER_SIZE = %ld\n",
			di->dev_max_param_sz);
      fprintf( fp,"clinfo: CL_DEVICE_MEM_BASE_ADDRESS_ALIGN = %d\n",
			di->dev_mem_base_addr_align);

      fprintf(fp,"clinfo: CL_DEVICE_NAME = %s\n",di->dev_name);
      fprintf(fp,"clinfo: CL_DEVICE_VENDOR = %s\n",di->dev_vendor);
      fprintf(fp,"clinfo: CL_DEVICE_VERSION = %s\n",di->dev_version);
      fprintf(fp,"clinfo: CL_DRIVER_VERSION = %s\n",di->dev_drv_version);

      fprintf(fp,"clinfo: CL_DEVICE_LOCAL_MEM_SIZE = %ld\n",
			di->dev_local_mem_sz);

   }

}

