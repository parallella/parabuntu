/* clsched.h
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

#ifndef _CLSCHED_H
#define _CLSCHED_H

#ifndef __STDCL__
#error Do not include clsched.h directly, include stdcl.h instead.
#endif

#include <CL/cl.h>

#include "clcontext.h"

//#define CL_FAST      0x08
#define CL_FAST      0x0	/* XXX disables all use, this will be going away */

#define CL_EVENT_WAIT     	0x01
#define CL_EVENT_NOWAIT   	0x02
#ifdef ALLOW_DEPRECATED_FLAGS
#define CL_EVENT_RELEASE  	0x04
#endif
#define CL_EVENT_NORELEASE	0x08

#define CL_KERNEL_EVENT		0x10
#define CL_MEM_EVENT			0x20
#define CL_ALL_EVENT			(CL_KERNEL_EVENT|CL_MEM_EVENT)

struct clndrange_struct {
   size_t dim;
   size_t gtid_offset[4];
   size_t gtid[4];
   size_t ltid[4];
};


#ifdef __cplusplus
extern "C" {
#endif

LIBSTDCL_API cl_event clfork(CONTEXT* cp, cl_uint devnum, cl_kernel krn, struct clndrange_struct* ndr, int flags);

LIBSTDCL_API cl_event clwait(CONTEXT* cp, unsigned int devnum, int flags);
LIBSTDCL_API cl_event clwaitev(
   CONTEXT* cp, unsigned int devnum, const cl_event ev, int flags
);

LIBSTDCL_API int clflush(CONTEXT* cp, unsigned int devnum, int flags);

#ifdef __cplusplus
}
#endif

#endif

