/* e32_opencl_ext.h
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


#ifndef _e32_opencl_ext_h
#define _e32_opencl_ext_h

#ifdef __cplusplus
extern "C" {
#endif
#include <e-lib.h>
#ifdef __cplusplus
}
#endif

#include <string.h>

//#include "e32pth_mem_if.h"

#include "esdk_missing.h"

#define E_ROWS_IN_CHIP 4
#define E_COLS_IN_CHIP 4
#define E_FIRST_CORE_ROW 32
#define E_FIRST_CORE_COL 8


#ifndef __always_inline
#define __always_inline __inline __attribute__((__always_inline__))
#endif

e_coreid_t __always_inline __corenum_to_coreid(unsigned int n);

e_coreid_t __always_inline 
__corenum_to_coreid(unsigned int n)
{
   unsigned int r = n / E_COLS_IN_CHIP;
   unsigned int c = n % E_COLS_IN_CHIP;
   unsigned int row = r + E_FIRST_CORE_ROW;
   unsigned int col = c + E_FIRST_CORE_COL;

   e_coreid_t coreid = (row << 6) | col;

   return coreid;
}

#define __volatile_int( val ) ( *(volatile int*)&(val) )
#define __test_bits(n,bits) ((n)&(bits))
#define __save_run() \
   int save_run = e32_ctrl_run[core_local_data.corenum]; do {} while(0)
#define __set_run(n) \
   e32_ctrl_run[core_local_data.corenum] = n; do {} while(0)
#define __restore_run() \
   do { e32_ctrl_run[core_local_data.corenum] = save_run; } while(0)

volatile extern struct core_local_data_struct core_local_data;
extern unsigned char coremap[];
extern unsigned char threadmap[];
volatile extern e32_workp_entry_t core_we;
volatile extern struct thr_data_struct thr_data;



/***** extensions are below *****/



/***
 *** extension flags
 ***/

#define XCL_NOWAIT       0x0001
#define XCL_NOFAIL       0x0002
#define XCL_MEM_DMA      0x0004
#define XCL_MEM_FENCE    0x0020


#if(0)
#if(0)
/***
 *** mutex builtin extensions
 ***/

typedef e_mutex_t mutex_t;
typedef e_mutexattr_t mutexattr_t;

__inline
int mutex_init( mutex_t* mutex, mutexattr_t* attr )
{ return e_mutex_init( mutex, attr ); }

__inline
int mutex_trylock( mutex_t* mutex)
{ return e_mutex_trylock( mutex ); }

__inline
int mutex_lock( mutex_t* mutex)
{ return e_mutex_lock( mutex ); }

__inline
int mutex_unlock( mutex_t *mutex)
{ return e_mutex_unlock( mutex ); }

__inline
int mutex_destroy( mutex_t* mutex )
{ return e_mutex_destroy( mutex ); }
#else
__inline
int mutex_init( unsigned row, unsigned col, mutex_t* mutex, mutexattr_t* attr )
{ e_mutex_init( row, col, mutex, attr ); }

__inline
int mutex_trylock( int row, int col, mutex_t* mutex)
{ return e_mutex_trylock( row, col, mutex ); }

__inline
int mutex_lock( int row, int col, mutex_t* mutex)
{ e_mutex_lock( row, col, mutex ); }

__inline
int mutex_unlock( int row, int col, mutex_t *mutex)
{ e_mutex_unlock( row, col, mutex ); }

//__inline
//int mutex_destroy( mutex_t* mutex )
//{ return e_mutex_destroy( mutex ); }
#endif
#endif


/***
 *** thread specification
 ***/

typedef struct core_local_data_struct* threadspec_t;

__always_inline threadspec_t get_thread_self();
__always_inline threadspec_t get_thread_prev( int d );
__always_inline threadspec_t get_thread_next( int d );
__always_inline threadspec_t get_thread( int d, unsigned int* ltid );

__always_inline threadspec_t
get_thread_self()
{ return core_local_data.thrs_self; }

__always_inline threadspec_t
get_thread_prev( int d )
{ return(core_local_data.thrs_prev[d]); }

__always_inline threadspec_t
get_thread_next( int d )
{ return(core_local_data.thrs_next[d]); }

__always_inline threadspec_t
get_thread( int dim, unsigned int* ltid )
{
	threadspec_t thrs;
	int m;

	if (dim == 1) {

		m = ltid[0];

	} else if ( dim == 2 ) {

		m = ltid[1] * we_ndr_ltdsz(core_we,0) + ltid[0];

	} else {

		thrs = (threadspec_t)0;

	}

	int n = (int)coremap[m];
	e_coreid_t coreid = __corenum_to_coreid(n);
	thrs = (threadspec_t)e_address_from_coreid( coreid, (void*)&core_local_data);

	return(thrs);
}



/***
 *** inter-thread synchronization
 ***/

typedef struct core_local_data_struct* threadspec_t;

__inline void barrier_thread_pair( int kind, threadspec_t thrs );
__inline __attribute__((always_inline)) void barrier_thread_all( int kind );

#define __barrier_thread_pair_top( thrs ) do { \
   while (__volatile_int(thrs->sigb)); \
   thrs->sigb = (int)core_local_data.thrs_self; \
   while ( __volatile_int(core_local_data.sigb)==0); \
   } while(0)

#define __barrier_thread_pair_bottom( thrs ) do { \
   thrs->sigb = 0; \
   while ( __volatile_int(core_local_data.sigb) == (int)thrs); \
   } while(0)

__inline void 
barrier_thread_pair( int kind, threadspec_t thrs )
{
   __save_run();
   __set_run(301);
   __barrier_thread_pair_top( thrs );
   __set_run(302);
   __barrier_thread_pair_bottom( thrs );
   __restore_run();
}

#define __barrier_thread_all_top() do { \
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

#define __barrier_thread_all_bottom() do { \
   if (core_local_data.corenum==0) { \
      *core_local_data.psigb_next = 0; \
      while ( __volatile_int(core_local_data.sigb) ); \
   } else { \
      while ( __volatile_int(core_local_data.sigb) ); \
      *core_local_data.psigb_next = 0; \
   } \
   } while(0)

__inline __attribute__((always_inline)) void 
barrier_thread_all( int kind )
{
   if ((kind)&XCL_MEM_FENCE) while(__volatile_int(core_local_data.recvaddr));
   __barrier_thread_all_top();
   __barrier_thread_all_bottom();
}


/***
 *** memory operations
 ***/

#if(0)
__always_inline void mem_copy(void* dst, void* src, size_t len);

__always_inline
void mem_copy(e_tcb_t* tcb, void* dst, void* src, size_t len)
{
	unsigned int index, shift, stride, config;
	config = E_DMA_DOUBLE|E_DMA_MASTER|E_DMA_ENABLE;
	shift = config >> 5;
	stride = 0x10001 << shift;
	tcb->config = config;
	tcb->inner_stride = stride;
	tcb->count = 0x10000 | (len >> shift);
	tcb->outer_stride = stride;
	tcb->src_addr = src;
	tcb->dst_addr = dst;
	e_dma_start(E_DMA_0,tcb);
	while( e_sysreg_read(E_DMA0STATUS) & 0xf);
}

__always_inline void* memaddr( void* ptr, threadspec_t thrs, int flags);
__always_inline void* memcopy( void* dst, void* src, size_t n, int flags );
__always_inline void* memsync( void* ptr, size_t n, threadspec_t thrs,
   int flags );
__always_inline void* memsend(void* src, size_t n, threadspec_t thrs,
   int flags );
__always_inline void* memrecv(void* dst, size_t n, threadspec_t thrs,
   int flags );

__always_inline void*
memaddr( void* ptr, threadspec_t thrs, int flags)
{
   void* gptr =  e_address_from_coreid( thrs->coreID, ptr);

   return gptr;
}

__always_inline void*
memcopy( void* dst, void* src, size_t n, int flags )
{
   if (__test_bits(flags,XCL_MEM_DMA)) {

      int err = e_dma_copy(E_DMA_0,dst,src,n,E_ALIGN_AUTO);

      if (err) return((void*)-1);

      if (__test_bits(flags,XCL_NOWAIT))
         return(0);
      else
         while(e_dma_busy(E_DMA_0));

      return(dst);

   } else {

/*
      if (__test_bits(flags,XCL_NOWAIT) && !__test_bits(flags,XCL_NOFAIL))
         return(0);
      else
         return memcpy(dst,src,n);
*/

   }
}

__always_inline void*
memsync( void* ptr, size_t n, threadspec_t thrs, int flags )
{
   void* gptr =  e_address_from_coreid( thrs->coreID, ptr);

   return memcopy(gptr,ptr,n,flags&(XCL_NOWAIT|XCL_NOFAIL|XCL_MEM_DMA));
}

__always_inline void*
memsend(void* src, size_t n, threadspec_t thrs, int flags )
{
   while ( __volatile_int(thrs->recvaddr) ==0);

   void* gptr = e_address_from_coreid( thrs->coreID, (void*)thrs->recvaddr);

   memcopy(gptr,src,n,flags&(XCL_NOWAIT|XCL_NOFAIL|XCL_MEM_DMA));

   thrs->recvaddr = 0;

   return(src);
}

__always_inline void*
memrecv(void* dst, size_t n, threadspec_t thrs, int flags )
{
   core_local_data.recvaddr = dst;

   if (__test_bits(flags,XCL_NOWAIT)) {

		return 0;

	} else {

      while ( __volatile_int(core_local_data.recvaddr) );
   	return(dst);

	}
}

#endif


/***
 ***	misc builtins
 ***/

#define __halt(val) do { \
   e32_ctrl_run[core_local_data.corenum] = val; \
   for(;;); \
   } while(0)



/***** now undef macros we do not want people using *****/

#undef __volatile_int
#undef __test_bits
#undef __save_run
#undef __set_run
#undef __restore_run
#undef __barrier_thread_pair_top
#undef __barrier_thread_pair_bottom

#endif

