/* stdcl_host.h
 *
 * Copyright (c) 2009 Brown Deer Technology, LLC.  All Rights Reserved.
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

#ifndef _STDCL_H
#error Do not include stdcl_host.h directly, include stdcl.h instead.
#endif

#ifndef _STDCL_HOST_H
#define _STDCL_HOST_H

#ifndef __STDCL__
#define __STDCL__
#endif

#ifdef _WIN64
#include "fix_windows.h"
#else
#define LIBSTDCL_API
#include <sys/queue.h>
#endif

#include <string.h>
#include <stdio.h>

#include <CL/cl.h>
#include <CL/cl_gl.h>


#define cl_float4_x(f) (((cl_float*)&(f))[0])
#define cl_float4_y(f) (((cl_float*)&(f))[1])
#define cl_float4_z(f) (((cl_float*)&(f))[2])
#define cl_float4_w(f) (((cl_float*)&(f))[3])


#include "clcontext.h"
#include "clinit.h"
#include "clsched.h"
#include "clmalloc.h"
#include "clfcn.h"
#include "clarg.h"
#include "clerror.h"



typedef struct clndrange_struct clndrange_t;

#define clndrange_init1d(gto0,gt0,lt0) \
	{ 1, gto0,0,0,0, gt0,0,0,0, lt0,0,0,0 }
#define clndrange_init2d(gto0,gt0,lt0,gto1,gt1,lt1) \
	{ 2, gto0,gto1,0,0, gt0,gt1,0,0, lt0,lt1,0,0 }
#define clndrange_init3d(gto0,gt0,lt0, gto1,gt1,lt1, gto2,gt2,lt2) \
	{ 3, gto0,gto1,gto2,0, gt0,gt1,gt2,0, lt0,lt1,lt2,0 }
#define clndrange_init4d(gto0,gt0,lt0,gto1,gt1,lt1,gto2,gt2,lt2,gto3,gt3,lt3) \
	{ 4, gto0,gto1,gto2,gto3, gt0,gt1,gt2,gt3, lt0,lt1,lt2,lt3 }


#define clndrange_set1d(ndr,gto0,gt0,lt0) do { \
	ndr.dim = 1; \
	ndr.gtid_offset[0]=gto0; ndr.gtid_offset[1]=0; \
	ndr.gtid_offset[2]=0; ndr.gtid_offset[3]=0; \
	ndr.gtid[0]=gt0; ndr.gtid[1]=0; \
	ndr.gtid[2]=0; ndr.gtid[3]=0; \
	ndr.ltid[0]=lt0; ndr.ltid[1]=0; \
	ndr.ltid[2]=0; ndr.ltid[3]=0; \
} while(0)

#define clndrange_set2d(ndr,gto0,gt0,lt0,gto1,gt1,lt1) do { \
	ndr.dim = 2; \
	ndr.gtid_offset[0]=gto0; ndr.gtid_offset[1]=gto1; \
	ndr.gtid_offset[2]=0; ndr.gtid_offset[3]=0; \
	ndr.gtid[0]=gt0; ndr.gtid[1]=gt1; \
	ndr.gtid[2]=0; ndr.gtid[3]=0; \
	ndr.ltid[0]=lt0; ndr.ltid[1]=lt1; \
	ndr.ltid[2]=0; ndr.ltid[3]=0; \
} while(0)

#define clndrange_set3d(ndr,gto0,gt0,lt0,gto1,gt1,lt1,gto2,gt2,lt2) do { \
	ndr.dim = 3; \
	ndr.gtid_offset[0]=gto0; ndr.gtid_offset[1]=gto1; \
	ndr.gtid_offset[2]=gto2; ndr.gtid_offset[3]=0; \
	ndr.gtid[0]=gt0; ndr.gtid[1]=gt1; \
	ndr.gtid[2]=gt2; ndr.gtid[3]=0; \
	ndr.ltid[0]=lt0; ndr.ltid[1]=lt1; \
	ndr.ltid[2]=lt2; ndr.ltid[3]=0; \
} while(0)

#define clndrange_set4d(ndr,gto0,gt0,lt0,gto1,gt1,lt1,gto2,gt2,lt2, \
	gto3,gt3,lt3) do { \
	ndr.dim = 4; \
	ndr.gtid_offset[0]=gto0; ndr.gtid_offset[1]=gto1; \
	ndr.gtid_offset[2]=gto2; ndr.gtid_offset[3]=gto3; \
	ndr.gtid[0]=gt0; ndr.gtid[1]=gt1; \
	ndr.gtid[2]=gt2; ndr.gtid[3]=gt3; \
	ndr.ltid[0]=lt0; ndr.ltid[1]=lt1; \
	ndr.ltid[2]=lt2; ndr.ltid[3]=lt3; \
} while(0)




/*
 * CL kernel arguments
 */

#ifdef __cplusplus

#ifdef _WIN64
template < typename T >
void clarg_set( CONTEXT* cp, cl_kernel krn, 
	unsigned int argnum, T arg)
{
	if (cp->nctx > 1) 
		for(int ictx=0; ictx < cp->nctx; ictx++) 
			clSetKernelArg(((cl_kernel*)krn)[ictx],argnum,sizeof(T),(void*)&arg);
	else 
		clSetKernelArg(krn,argnum,sizeof(T),(void*)&arg); 
}

#else

template < typename T >
void clarg_set( CONTEXT* cp __attribute__((__unused__)), cl_kernel krn, 
	unsigned int argnum, T arg)
{ 
	if (cp->nctx > 1) 
		for(int ictx=0; ictx < cp->nctx; ictx++) 
			clSetKernelArg(((cl_kernel*)krn)[ictx],argnum,sizeof(T),(void*)&arg); 
	else
		clSetKernelArg(krn,argnum,sizeof(T),(void*)&arg); 
}

#endif

#else

#define clarg_set(cp,krn,argnum,arg) do { \
	int ictx; \
	if (cp->nctx > 1) \
		for(ictx=0; ictx < cp->nctx; ictx++) \
			clSetKernelArg(((cl_kernel*)krn)[ictx],argnum,sizeof(typeof(arg)), \
				(void*)&arg); \
	else \
		clSetKernelArg(krn,argnum,sizeof(typeof(arg)),(void*)&arg); \
	} while(0)

#endif

#define clarg_set_local(cp,krn,argnum,arg) do { \
	int ictx; \
	if (cp->nctx > 1) \
		for(ictx=0; ictx < cp->nctx; ictx++) \
 			clSetKernelArg(((cl_kernel*)krn)[ictx],argnum,arg,0); \
	else \
 		clSetKernelArg(krn,argnum,arg,0); \
	} while(0)


#ifdef __cplusplus
extern "C" {
#endif


/*
 * CL kernel arguments
 */

/* for intrinsics need to test if this is included for C or C++ -DAR */

//#ifdef __cplusplus
//	
//inline template < typename T >
//void clarg_set( cl_kernel krn, unsigned int argnum, T arg) 
//{ clSetKernelArg(krn,argnum,sizeof(typeof(T)),(void*)&arg); }
//
//#else
//
//#define clarg_set(krn,argnum,arg) 
//	clSetKernelArg(krn,argnum,sizeof(typeof(arg)),(void*)&arg);
//
//#endif

/*
inline void clarg_set_global(cl_kernel krn, unsigned int argnum, void* arg)
{
	struct _memd_struct* memd
		= (struct _memd_struct*)((intptr_t)arg - sizeof(struct _memd_struct));
	clSetKernelArg(krn,argnum,sizeof(cl_mem),(void*)&memd->clbuf);
}

inline size_t xxx_clarg_set_global(
	CONTEXT* cp, cl_kernel krn, unsigned int argnum, void* arg
)
{ return(__clarg_set_global(cp,krn,argnum,arg)); }

inline void clarg_set_local(cl_kernel krn, unsigned int argnum, size_t arg)
{ clSetKernelArg(krn,argnum,arg,0); }
*/

#ifdef __cplusplus
}
#endif

#include "clforka.h"
#include "clexec.h"

#endif

