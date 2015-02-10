/* sl_engine.h
 *
 * Copyright (c) 2009-2013 Brown Deer Technology, LLC.  All Rights Reserved.
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

#ifndef _sl_engine_h
#define _sl_engine_h

#include <sys/types.h>
#include <stdint.h>
#include <setjmp.h>

#ifdef __xcl_kcall__
typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long int ulong;
typedef char char2[2];
typedef char char4[4];
typedef uchar uchar2[2];
typedef uchar uchar4[4];
typedef int int2[2];
typedef int int4[4];
typedef uint uint2[2];
typedef uint uint4[4];
typedef long long2[2];
typedef ulong ulong2[2];
typedef float float2[2];
typedef float float4[4];
typedef double double2[2];
#endif

#include "workp.h"

//#if defined (ENABLE_MIC_CROSS_COMPILE)
#if defined(__MIC__)
#define MAX_NUM_THR  16
#else
#define MAX_NUM_THR  64
#endif

#define BLK_LOCAL_MEM_SZ 32768

#define THR_STACK_SZ 262144
#define THR_STACK_MASK (~(THR_STACK_SZ-1))
#define __fp() __builtin_frame_address(0)
#define __get_thr_data() (struct thr_data*)(((intptr_t)__fp())&THR_STACK_MASK)

struct engine_data { 
   int engid; 
   void* funcp;
   void* callp;
   uint32_t* pr_arg_off;
   void* pr_arg_buf;
   int thr_runc;
};

struct thr_data {
   int vcid;
   jmp_buf* engine_jbufp;
   jmp_buf* this_jbufp;
   jmp_buf* next_jbufp;
   struct workp_entry* we;
   uint32_t blkidx[3];
   uint32_t gtdidx[3];
   uint32_t ltdidx[3];
};

#ifdef __xcl_kthr__

static __inline unsigned int get_work_dim()
{ return((__get_thr_data())->we->ndr_dim); }

static __inline size_t get_num_groups(uint d)
{  
   size_t g = (__get_thr_data())->we->ndr_gtdsz[d];
   size_t l = (__get_thr_data())->we->ndr_ltdsz[d];
   return(g/l);
}

static __inline size_t get_group_id(uint d)
{ return((__get_thr_data())->blkidx[d]); }
   
static __inline size_t get_global_size(uint d)
{ return((__get_thr_data())->we->ndr_gtdsz[d]); }
   
static __inline unsigned int get_global_id(unsigned int d)
{ return((unsigned int)(__get_thr_data())->gtdidx[d]); }

static __inline size_t get_local_size(uint d)
{ return((__get_thr_data())->we->ndr_ltdsz[d]); }

static __inline size_t get_local_id(uint d)
{ return((__get_thr_data())->ltdidx[d]); }

#define barrier(flags) do { \
   struct thr_data* data = __get_thr_data();\
   if (!(setjmp(*(data->this_jbufp))))\
      longjmp(*(data->next_jbufp),flags);\
} while(0)

#endif

#if !defined(__xcl_kcall__) && !defined(__xcl_kthr__)

static void* sl_engine( void* p );

void* sl_engine_startup( void* p );

void* sl_engine_klaunch( int engid_base, int ne, struct workp* wp, 
	struct cmdcall_arg* argp );

int sl_engine_ready();

#endif

#endif

