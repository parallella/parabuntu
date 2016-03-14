/* clfcn.h
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

#ifndef _CLFCN_H
#define _CLFCN_H

#ifndef __STDCL__
#error Do not include clfcn.h directly, include stdcl.h instead.
#endif

#include <CL/cl.h>
#include <sys/queue.h>

#include "clcontext.h"
#include "clinit.h"


#define CLLD_DEFAULT	0	
#define CLLD_LAZY		1
#define CLLD_NOW 		2
#define CLLD_NOBUILD	4
#define CLLD_GLOBAL	8


struct _prgs_struct {
	LIST_ENTRY(_prgs_struct) prgs_list;
	const char* fname;
	size_t len;
#ifdef _WIN64
	FILE* fp;
#else
	int fd;
#endif
	void* ptr;
	unsigned int refc;

	unsigned int nbin;
	char** bin;
	size_t* bin_sz;

};


struct _krntab_struct {
	char kname[256];
	cl_uint nargs;
	cl_uint refc;
	cl_context kctx;
	cl_program kprg;
};


struct _txt_struct {
	LIST_ENTRY(_txt_struct) txt_list;
	struct _prgs_struct* prgs;
//	cl_program prg;
	cl_uint nprg;
	cl_program* xxxprg;
	cl_uint nkrn;
	cl_kernel* krn;
	struct _krntab_struct* krntab;
};


#ifdef __cplusplus
extern "C" {
#endif

LIBSTDCL_API void* clload( CONTEXT* cp, void* ptr, size_t sz, int flags );
LIBSTDCL_API void* clloadb( CONTEXT* cp, int nbin, char** bin, size_t* bin_sz, 
	int flags );
LIBSTDCL_API void* clbuild( CONTEXT* cp, void* handle, char* options, 
	int flags );
LIBSTDCL_API void* clopen( CONTEXT* cp, const char* fname, int flags );
LIBSTDCL_API void* clsopen( CONTEXT* cp, const char* srcstr, int flags );
LIBSTDCL_API cl_kernel clsym( CONTEXT* cp, void* handle, const char* sname, 
	int flags );
LIBSTDCL_API int clclose(CONTEXT* cp, void* handle);
LIBSTDCL_API char* clerror(void);

#ifdef __cplusplus
}
#endif

#endif

