/* e32pth_if_needham.h
 *
 * Copyright (c) 2012 Brown Deer Technology, LLC.  All Rights Reserved.
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

#ifndef _E32PTH_IF_NEEDHAM_H
#define _E32PTH_IF_NEEDHAM_H

#include <sys/types.h>
#include <stdint.h>

#ifndef __always_inline
#define __always_inline __inline __attribute__((__always_inline__))
#endif

#include "e32_config_needham.h"
#include "e32pth_mem_if_needham.h"

volatile extern struct core_local_data_struct core_local_data;

//#define _ENABLE_BARRIER_TRACE 0 
//#define _ENABLE_BARRIER_TRACE 1
//#define _ENABLE_BARRIER_TRACE 2
#define _ENABLE_BARRIER_TRACE 3 /* no halt */


#if defined(__coprthr_host__)
#elif defined(__coprthr_device__)
#include <e_coreid.h>
#include <e_common.h>
#include <e_dma.h>
#include <string.h>
#else
#error must be compiled with either __coprthr_host__ or __coprthr_device__
#endif

//typedef unsigned long size_t;
typedef unsigned char uchar;
typedef unsigned int uint;

#if defined(__xcl_kcall__)
/* XXX this brings in the vec types.  temporary soln. improve it. -DAR */
#include <CL/cl.h>
typedef unsigned char uchar;
typedef unsigned int uint;
typedef cl_char2 char2;
typedef cl_char4 char4;
typedef cl_uchar2 uchar2;
typedef cl_uchar4 uchar4;
typedef cl_int2 int2;
typedef cl_int4 int4;
typedef cl_uint2 uint2;
typedef cl_uint4 uint4;
typedef cl_long2 long2;
typedef cl_ulong2 ulong2;
typedef cl_float2 float2;
typedef cl_float4 float4;
typedef cl_double2 double2;
#endif


struct core_control_struct {
   e32_int_t ready[E32_NCORES];
   e32_int_t run[E32_NCORES];
   e32_int_t retval[E32_NCORES];
   e32_ptr_t callp[E32_NCORES];
};

typedef struct core_local_data_struct* threadspec_t;

struct core_local_data_struct {
   int coreID;
   int corenum;
   int row;
   int col;
   int count;
	volatile int sigb;
	int* psigb_prev;
	int* psigb_next;
	volatile void* recvaddr;
	volatile threadspec_t thrs_self;
	volatile threadspec_t thrs_prev[2];
	volatile threadspec_t thrs_next[2];
};

struct thr_data_struct {
   uint32_t blkidx[3];
   uint32_t gtdidx[3];
   uint32_t ltdidx[3];
};


#if defined(__xcl_kcall__) || defined(__xcl_kthr__) || defined(__coprthr_device__)

volatile extern struct core_local_data_struct core_local_data;
volatile extern e32_workp_entry_t core_we;
volatile extern struct thr_data_struct thr_data;

#endif

#define __KCALL_DECLS(sym) extern __XCL_func_##sym##_t sym;
#define __KCALL_ATTRIBUTES
#define __KCALL_PRE void* arg_buf = e32_kdata_ptr_arg_buf; ++e32_ctrl_run[core_local_data.corenum];
#define __KCALL_POST --e32_ctrl_run[core_local_data.corenum];
#define __kcall_thr_ptr(sym) &sym
#define __kcall_arg(t,n) *(t*)(arg_buf + e32_kdata_ptr_arg_off[n])

#ifdef __xcl_kthr__

static __inline unsigned int get_work_dim()
{ return( we_ndr_dim(core_we)); }

static __inline size_t get_num_groups(uint d)
{ return( we_ndr_gtdsz(core_we,d)/we_ndr_ltdsz(core_we,d) ); }

static __inline size_t get_group_id(uint d)
{ return( thr_data.blkidx[d] ); }

static __inline size_t get_global_size(uint d)
{ return( we_ndr_gtdsz(core_we,d) ); }

static __inline unsigned int get_global_id(unsigned int d)
{ return( thr_data.gtdidx[d] ); }

static __inline size_t get_local_size(uint d)
{ return( we_ndr_ltdsz(core_we,d) ); }

static __inline size_t get_local_id(uint d)
{ return( thr_data.ltdidx[d] ); }

#endif


#if defined(__coprthr_host__)

#elif defined(__coprthr_device__)

#ifdef _ENABLE_BARRIER_TRACE
#define __save_run() \
	int save_run = e32_ctrl_run[core_local_data.corenum]; do {} while(0)
#define __set_run(n) \
	e32_ctrl_run[core_local_data.corenum] = n; do {} while(0)
#define __restore_run() \
	do { e32_ctrl_run[core_local_data.corenum] = save_run; } while(0)
#define __trace_point(n) \
	do { \
		e32_ctrl_run[core_local_data.corenum] = 100 + core_local_data.sigb; \
		if (_ENABLE_BARRIER_TRACE < n) for(;;); \
	}while(0)
#else
#define __save_run()
#define __restore_run()
#define __trace_point(n)
#endif

//#define XXX_RUN 0x7f90
//#define XXX_DEBUG 0x7f94
//#define XXX_INFO 0x7f98

/*
__always_inline void barrier( int flags);
__always_inline void barrier( int flags)
{
//	int* xxx_info = (int*)XXX_INFO;
	__save_run(); 
	__trace_point(1);
//	*xxx_info = 2001;
	if (core_local_data.corenum==0) { 
		*core_local_data.psigb_next = 1; 
		while (core_local_data.sigb==0); 
	} else { 
		while (core_local_data.sigb==0); 
		*core_local_data.psigb_next = 1; 
	} 
	__trace_point(2); 
//	*xxx_info = 2002;
	if (core_local_data.corenum==0) { 
		*core_local_data.psigb_next = 0; 
		while (core_local_data.sigb); 
	} else { 
		while (core_local_data.sigb); 
		*core_local_data.psigb_next = 0; 
	} 
//	*xxx_info = 2003;
	__trace_point(3); 
	__restore_run(); 
}
*/
#define __volatile_int( val ) ( *(volatile int*)&(val) )
#define __barrier_top() do { \
   if ( core_local_data.corenum==0) { \
      while ( __volatile_int(*core_local_data.psigb_next) ); \
      *core_local_data.psigb_next = 1; \
      while ( __volatile_int(core_local_data.sigb)==0); \
   } else { \
      while ( __volatile_int(core_local_data.sigb)==0); \
      while ( __volatile_int(*core_local_data.psigb_next) ); \
      *core_local_data.psigb_next = 1; \
   } \
   } while(0)

#define __barrier_bottom() do { \
   if (core_local_data.corenum==0) { \
      *core_local_data.psigb_next = 0; \
      while ( __volatile_int(core_local_data.sigb) ); \
   } else { \
      while ( __volatile_int(core_local_data.sigb) ); \
      *core_local_data.psigb_next = 0; \
   } \
   } while(0)

__inline __attribute__((always_inline)) void
barrier( int kind )
{
//   if ((kind)&XCL_MEM_FENCE) while(__volatile_int(core_local_data.recvaddr));
   __barrier_top();
   __barrier_bottom();
}



#define __halt(val) do { \
	e32_ctrl_run[core_local_data.corenum] = val; \
	for(;;); \
	} while(0)	

#else
#error must be compiled with either __coprthr_host__ or __coprthr_device__
#endif


#endif

