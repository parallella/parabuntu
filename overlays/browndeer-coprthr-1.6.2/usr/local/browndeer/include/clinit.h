/* clinit.h
 *
 * Copyright (c) 2009-2011 Brown Deer Technology, LLC.  All Rights Reserved.
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

#ifndef _CLINIT_H
#define _CLINIT_H

#ifndef __STDCL__
#error Do not include clinit.h directly, include stdcl.h instead.
#endif

#include <string.h>
#include <stdio.h>

#ifdef _WIN64
#include "fix_windows.h"
#else
#define LIBSTDCL_API 
#include <sys/queue.h>
#if defined(__ANDROID__)
#include <libelf/libelf.h>
#else
#include <elf.h>
#endif
#endif


#include <CL/cl.h>

#ifndef _WIN64
//#include "../libclelf/clelf.h"
#include "clelf.h"
#endif

#include "clcontext.h"


extern struct clelf_sect_struct* _proc_clelf_sect;


extern LIBSTDCL_API CONTEXT* stddev;
extern LIBSTDCL_API CONTEXT* stdcpu;
extern LIBSTDCL_API CONTEXT* stdgpu;
extern LIBSTDCL_API CONTEXT* stdrpu;
extern LIBSTDCL_API CONTEXT* stdacc;
extern LIBSTDCL_API CONTEXT* stdnpu;

extern char* __log_automatic_kernels_filename;

#ifdef __cplusplus
extern "C" {
#endif

extern void _assert_proto_stub(void);
#ifdef _WIN64
LIBSTDCL_API void _libstdcl_init();
#define stdcl_init() _libstdcl_init()
#else 
#define stdcl_init()
#endif


#ifdef __cplusplus
}
#endif


#endif

