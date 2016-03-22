/* clcontext.h
 *
 * Copyright (c) 2009-2012 Brown Deer Technology, LLC.  All Rights Reserved.
 *
 * This software was developed by Brown Deer Technology, LLC.
 * For more information contact info@browndeertechnology.com
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License version 3 (LGPLv3)
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* DAR */

#ifndef _CLCONTEXT_H
#define _CLCONTEXT_H

#ifndef __STDCL__
#error Do not include clcontext.h directly, include stdcl.h instead.
#endif

#include <string.h>
#include <stdio.h>

#ifdef _WIN64
#include "fix_windows.h"
#else
#define LIBSTDCL_API 
#endif

#include <sys/queue.h>

#include <CL/cl.h>

#define CL_DEVICE_TYPE_RPU CL_DEVICE_TYPE_ACCELERATOR

struct _prgs_struct;
struct _txt_struct;
struct _memd_struct;

#define STDCL_EVENTLIST_MAX 1024

struct _event_list_struct {
	cl_uint nev;
	cl_uint ev_first;
	cl_uint ev_free;
	cl_event ev[STDCL_EVENTLIST_MAX];
};

struct _clcontext_ptr_struct {
	unsigned int context_id;
	char* platform_profile;
	char* platform_version;
	char* platform_name;
	char* platform_vendor;
	char* platform_extensions;
//	cl_context ctx;
	cl_uint nctx;
	cl_context* xxxctx;
	cl_uint devtyp;
	cl_uint impid;
	cl_uint ndev;
	cl_device_id* dev;
	cl_context* devctx;
	cl_uint* devctxi;
	cl_uint* dev_platform_code;
	cl_command_queue* cmdq;
	cl_uint nprg;
	cl_program* prg;
	cl_uint nkrn;
	cl_kernel** krn;

	/* XXX eventually cut this loose from vp, txt should be bound -DAR */
	LIST_HEAD(_prgs_listhead_struct, _prgs_struct) prgs_listhead;

	LIST_HEAD(_txt_listhead_struct, _txt_struct) txt_listhead;

	LIST_HEAD(_memd_listhead_struct, _memd_struct) memd_listhead;

//	cl_uint nkev;
//	cl_uint kev_first, kev_free;
//	cl_event kev[128];

	struct _event_list_struct* kev;

//	cl_uint nmev;
//	cl_uint mev_first, mev_free;
//	cl_event mev[128];

	struct _event_list_struct* mev;

//#ifdef ENABLE_CLEXPORT
//	cl_uint ndev_v;
//	pthread_t extd;
//	pthread_t imtd;
//#endif

};
typedef struct _clcontext_ptr_struct CLCONTEXT;

/*
#ifdef _WIN64 
typedef struct _clcontext_ptr_struct CLCONTEXT;
#define CONTEXT CLCONTEXT
#else
typedef struct _clcontext_ptr_struct CLCONTEXT;
#endif
*/

/*** XXX CONTEXT is used by WIN64 internals, so better to change to CLCONTEXT,
 *** thie define is to ease the transition, eventually remove -DAR 
 ***/
#define CONTEXT CLCONTEXT



struct clstat_info {
	cl_uint impid;
	cl_uint ndev;
	cl_uint nprg;
	cl_uint nkrn;
};


struct cldev_info {
	cl_device_type dev_type;
	cl_uint dev_vendor_id;
	cl_uint dev_max_core;
	cl_uint dev_max_wi_dim;
	size_t dev_max_wi_sz[4]; /* XXX is this large enough? -DAR */
	cl_uint dev_max_wi_sz_is_symmetric;	/* default should be 1 */
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

/* used by routines that must do lazy cmdq create on windows */
static __inline void __cmdq_create(CONTEXT* cp, cl_uint n)
{
	if (!cp->cmdq[n]) {
		int err;
//		cp->cmdq[n] = clCreateCommandQueue(cp->ctx,cp->dev[n],0,&err);
		cp->cmdq[n] = clCreateCommandQueue(cp->devctx[n],cp->dev[n],0,&err);
	}
}


extern LIBSTDCL_API CONTEXT* stddev;
extern LIBSTDCL_API CONTEXT* stdcpu;
extern LIBSTDCL_API CONTEXT* stdgpu;
extern LIBSTDCL_API CONTEXT* stdrpu;
extern LIBSTDCL_API CONTEXT* stdacc;

#ifdef __cplusplus
extern "C" {
#endif

//CONTEXT* clcontext_create( 
//	cl_platform_id platformid, int devtyp, size_t ndevmax, int flag
//);
LIBSTDCL_API CONTEXT* clcontext_create( const char* platform_name, int devtyp, size_t ndevmax, cl_context_properties* ctxprop_ext, int flag );

LIBSTDCL_API int clcontext_destroy( CONTEXT* cp);

LIBSTDCL_API cl_uint clgetndev( CONTEXT* cp );

LIBSTDCL_API int  clstat( CONTEXT* cp, struct clstat_info* info );

LIBSTDCL_API int  clgetdevinfo( CONTEXT* cp, struct cldev_info* info );

LIBSTDCL_API void  clfreport_devinfo( FILE* fp, size_t ndev, struct cldev_info* info );

LIBSTDCL_API CONTEXT* clcontext_create_stdnpu( const char* platform_name, int devtyp, size_t ndevmax, cl_context_properties* ctxprop_ext, int flag );


#ifdef __cplusplus
}
#endif

#endif

