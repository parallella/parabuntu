/* cmdcall.h
 *
 * Copyright (c) 2009-2010 Brown Deer Technology, LLC.  All Rights Reserved.
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

#ifndef _cmdcall
#define _cmdcall

#include <stdlib.h>
#include <stdint.h>
//#include "printcl.h"

#include "coprthr_sched.h"

#define CLCMD_OFFSET (__CL_COMMAND_NDRANGE_KERNEL - 1)
#define CLCMD_NUM 17

struct coprthr_device;
typedef void*(*cmdcall_t)(struct coprthr_device* dev, void* cmd_argp);

struct _coprthr_ksyms_struct;

struct cmdcall_arg { 
	
	unsigned int flags;

	union {

		struct {
			struct coprthr_kernel* krn;

			void* ksym;
			void* kcall;
			struct _coprthr_ksyms_struct* ksyms;
			unsigned int narg;
			size_t arg_buf_sz;
			unsigned int* arg_kind;
   		size_t* arg_sz;
			uint32_t* pr_arg_off;
			void* pr_arg_buf;

			unsigned int work_dim;
			size_t global_work_offset[3];
			size_t global_work_size[3];
			size_t local_work_size[3];

			size_t global_work_size0[3];

			struct cmdcall_arg* nxt_argp;

		} k;

		struct {
			void* dst;
			void* src;
			size_t dst_offset;
			size_t src_offset;
			size_t len;
			size_t dst_origin[3];
			size_t src_origin[3];
			size_t region[3];
			void* row_pitch;
			void* slice_pitch;
		} m;

	}; 
};

#define CMDCALL_ARG_K	0x1
#define CMDCALL_ARG_M	0x2

#define __init_cmdcall_arg(p) do { \
	bzero(p,sizeof(struct cmdcall_arg)); \
	} while(0)

#define __free_cmdcall_arg(p) do { \
	if ((p->flags)&CMDCALL_ARG_K) { \
   __free(p->pr_arg_off); \
	__free(p->pr_arg_buf); \
	} else if ((p->flags)&CMDCALL_ARG_M) { \
	__free(p->row_pitch); \
	__free(p->slice_pitch); \
	} \
	} while(0)

#define __clone(dst,src,n,typ) do { \
   dst = (typ*)malloc(n*sizeof(typ)); \
   memcpy(dst,src,n*sizeof(typ)); \
   } while(0)

#define __test_flags(f,g) ( (f) & (g) )

unsigned int __get_global_id(unsigned int dim);


#endif

