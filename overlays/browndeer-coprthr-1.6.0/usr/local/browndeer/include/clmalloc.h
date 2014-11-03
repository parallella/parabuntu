/* clmalloc.h
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


#ifndef _CLMALLOC_H
#define _CLMALLOC_H

#ifndef __STDCL__
#error Do not include clmalloc.h directly, include stdcl.h instead.
#endif

#ifdef _WIN64
#include "fix_windows.h"
#else
#define LIBSTDCL_API 
#endif

#include <stdarg.h>

#include "clcontext.h"


#define CL_MEM_RO					0x00000001
#define CL_MEM_WO					0x00000002
#define CL_MEM_RW					0x00000003
#define CL_MEM_HOST				0x00000100
#define CL_MEM_DEVICE			0x00000200
#define CL_MEM_NOCOPY			0x00000400
#define CL_MEM_DETACHED			0x00001000
#define CL_MEM_NOFORCE			0x00002000
#define CL_MEM_IMAGE2D			0x00010000

#ifndef DISABLE_CLGL
#define CL_MEM_CLBUF				0x00100000
#define CL_MEM_GLBUF				0x00200000
#define CL_MEM_GLTEX2D			0x02000000
#define CL_MEM_GLTEX3D			0x04000000
#define CL_MEM_GLRBUF			0x08000000
#endif

#define CL_MCTL_GET_STATUS		1
#define CL_MCTL_GET_DEVNUM		2
#define CL_MCTL_SET_DEVNUM		3
#define CL_MCTL_MARK_CLEAN		4
#define CL_MCTL_SET_IMAGE2D	5
#define CL_MCTL_SET_USRFLAGS	6
#define CL_MCTL_CLR_USRFLAGS	7



#define CLMEM_MAGIC     0x19661971
struct _memd_struct {
   union {
      struct {
         LIST_ENTRY(_memd_struct) memd_list; // 8 
         unsigned int magic;						// 4 
         unsigned int flags;						// 4
         size_t sz,sz1,sz2;						// 24
//         cl_mem clbuf;
         cl_uint nclbuf;							// 4
         cl_mem* xxxclbuf;							// 8
         cl_mem* devbuf;							// 8
			int devnum;									// 4
			cl_image_format imgfmt;					// 8
			cl_mem_flags usrflags;					// 8
			void* _free_offset;
      };
      char __pad[128];
   };
};

/* XXX hardcoded to number of free bytes in memd -DAR */
#define MEMD_FREE_SZ	48


#ifdef __cplusplus
extern "C" {
#endif

static __inline__ 
size_t clsizeofmem(void* ptr) 
{
	intptr_t ptri = (intptr_t)ptr - sizeof(struct _memd_struct);
	struct _memd_struct* memd = (struct _memd_struct*)ptri;
   if (memd->magic != CLMEM_MAGIC) {
//		WARN(__FILE__,__LINE__,"clsizeofmem: bad ptr");
		fprintf(stderr,"warning: clsizeofmem: bad ptr\n");
		return(0);
	}
	return(memd->sz);
}


LIBSTDCL_API void* clmalloc(CONTEXT* cp, size_t size, int flag);
//LIBSTDCL_API void* clmalloc_img(CONTEXT* cp, size_t size, int flag);
//LIBSTDCL_API void clfree( void* ptr );
LIBSTDCL_API int clfree( void* ptr );
LIBSTDCL_API int clmattach( CONTEXT* cp, void* ptr );
LIBSTDCL_API int clmdetach( void* ptr );
//int clmctl( void* ptr, int op, int arg );
//int clmctl( void* ptr, int op, ... );
LIBSTDCL_API int clmctl_va( void* ptr, int op, va_list );

LIBSTDCL_API void* clmrealloc(CONTEXT* cp, void* ptr, size_t size, int flag);

LIBSTDCL_API cl_event clmsync(CONTEXT* cp, unsigned int devnum, void* ptr, int flags);

LIBSTDCL_API cl_event clmcopy(CONTEXT* cp, unsigned int devnum, 
	void* src, void* dst, int flags);

LIBSTDCL_API void* clmemptr( CONTEXT* CP, void* ptr );

#ifndef DISABLE_CLGL
LIBSTDCL_API void* clglmalloc(CONTEXT* cp, cl_GLuint glbufobj, cl_GLenum target, 
	cl_GLint miplevel, int flags );
LIBSTDCL_API cl_event clglmsync(CONTEXT* cp, unsigned int devnum, void* ptr, int flags);
#endif

static 
__inline__
int clmctl( void* ptr, int op, ... )
{ 
	va_list ap; 
	va_start(ap,op); 
	int rc = clmctl_va(ptr,op,ap); 
	va_end(ap); 
	return(rc);
}

static __inline int
__test_memd_magic(void* ptr) 
{
	intptr_t ptri = (intptr_t)ptr - sizeof(struct _memd_struct);
	struct _memd_struct* memd = (struct _memd_struct*)ptri;
	if (memd->magic == CLMEM_MAGIC) return(1);
	return(0);
}

#ifdef __cplusplus
}
#endif


#endif

