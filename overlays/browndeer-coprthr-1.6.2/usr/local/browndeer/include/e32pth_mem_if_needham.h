/* e32pth_mem_if_needham.h
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

/***
 *** This is a very important file, do not modify it unless you know what
 *** you are doing.  Here the OpenCL control data structure layout are defined
 *** _explicitly_ using macros.  You CAN NOT replace this with a struct. -DAR
 ***/

/* DAR */

#ifndef _E32PTH_MEM_IF_NEEDHAM_H
#define _E32PTH_MEM_IF_NEEDHAM_H

#include <sys/types.h>
#include <stdint.h>

#include "e32_config_needham.h"

#if defined(__coprthr_host__)
#include "xxx.h"
#endif

#ifndef E32_DRAM_ZEROPAGE
#if defined(__coprthr_host__)
#include "xxx.h"
//#define E32_DRAM_ZEROPAGE  0x8e000000
//#define E32_DRAM_ZEROPAGE  0x8e002000
#define E32_DRAM_ZEROPAGE  0x8e100000
#elif defined(__coprthr_device__)
#define E32_DRAM_ZEROPAGE  0
#else
#error must be compiled with either __coprthr_host__ or __coprthr_device__
#endif
#endif


#if defined(__coprthr_host__)
#elif defined(__coprthr_device__)

#ifdef __cplusplus
extern "C" {
#endif
#include <e-lib.h>
#ifdef __cplusplus
}
#endif

#else
#error must be compiled with either __coprthr_host__ or __coprthr_device__
#endif


/***
 *** First we define the sizes of everything
 ***/

#define E32_INT_SZ 4
#define E32_PTR_SZ 4
#define E32_CHAR_SZ 1

#define E32_SZ_CTRL_READY (E32_NCORES * E32_INT_SZ)
#define E32_SZ_CTRL_RUN (E32_NCORES * E32_INT_SZ)
#define E32_SZ_CTRL_RETVAL (E32_NCORES * E32_INT_SZ)
#define E32_SZ_CTRL_CALLP (E32_NCORES * E32_PTR_SZ)
#define E32_SZ_CTRL ( \
	E32_SZ_CTRL_READY \
	+E32_SZ_CTRL_RUN \
	+E32_SZ_CTRL_RETVAL \
	+E32_SZ_CTRL_CALLP )

#define E32_SZ_COREMAP (E32_NCORES * E32_CHAR_SZ)

#define E32_SZ_THREADMAP (E32_NCORES * E32_CHAR_SZ)

#define E32_SZ_WE (19 * E32_INT_SZ)

#define E32_SZ_KDATA_FUNCP E32_PTR_SZ
#define E32_SZ_KDATA_NARG E32_INT_SZ
#define E32_SZ_KDATA_PTR_ARG_OFF E32_PTR_SZ
#define E32_SZ_KDATA_PTR_ARG_BUF E32_PTR_SZ
#define E32_SZ_KDATA ( \
	E32_SZ_KDATA_FUNCP \
	+ E32_SZ_KDATA_NARG \
	+ E32_SZ_KDATA_PTR_ARG_OFF \
	+ E32_SZ_KDATA_PTR_ARG_BUF )


/***
 *** Next we define the layout using a chain of definitions
 ***/

#define E32_ADDR_CTRL E32_DRAM_ZEROPAGE
#define E32_ADDR_CTRL_READY (E32_ADDR_CTRL)
#define E32_ADDR_CTRL_RUN (E32_ADDR_CTRL_READY + E32_SZ_CTRL_READY)
#define E32_ADDR_CTRL_RETVAL (E32_ADDR_CTRL_RUN + E32_SZ_CTRL_RUN)
#define E32_ADDR_CTRL_CALLP (E32_ADDR_CTRL_RETVAL + E32_SZ_CTRL_RETVAL)

#define E32_ADDR_COREMAP (E32_ADDR_CTRL + E32_SZ_CTRL)

#define E32_ADDR_THREADMAP (E32_ADDR_COREMAP + E32_SZ_COREMAP)

#define E32_ADDR_WE (E32_ADDR_THREADMAP + E32_SZ_THREADMAP)

#define E32_ADDR_KDATA (E32_ADDR_WE + E32_NCORES * E32_SZ_WE)
#define E32_ADDR_KDATA_FUNCP E32_ADDR_KDATA
#define E32_ADDR_KDATA_NARG (E32_ADDR_KDATA_FUNCP + E32_SZ_KDATA_FUNCP)
#define E32_ADDR_KDATA_PTR_ARG_OFF (E32_ADDR_KDATA_NARG + E32_SZ_KDATA_NARG)
#define E32_ADDR_KDATA_PTR_ARG_BUF \
	(E32_ADDR_KDATA_PTR_ARG_OFF + E32_SZ_KDATA_PTR_ARG_OFF)

#define E32_ZERO_PAGE_FREE (E32_ADDR_KDATA + E32_SZ_KDATA)


__inline static unsigned int ncores() { return E32_NCORES; }


/***
 *** Finally we define access methods that differ on host/device
 ***/

#if defined(__coprthr_host__)

typedef int32_t e32_int_t;
typedef uint32_t e32_uint_t;
typedef uint32_t e32_ptr_t;
typedef unsigned char e32_uchar_t;
typedef e32_uint_t e32_workp_entry_t[19];

/*
#define  __SCALAR_BUILTINS(name,NAME,elem_t,elem_sz) \
__inline static void e32_read_##name( elem_t* pval ) \
{ 	xxx_e_read_zeropage(E32_ADDR_##NAME, (void*)pval, elem_sz ); } \
__inline static void e32_write_##name( elem_t val ) \
{ 	elem_t tmp = val;  \
	xxx_e_write_zeropage(E32_ADDR_##NAME, (void*)&tmp, elem_sz ); } \

#define  __ARRAY_BUILTINS(name,NAME,elem_t,elem_sz,nlim) \
__inline static void e32_read_##name( elem_t* pval ) \
{ xxx_e_read_zeropage(E32_ADDR_##NAME, (void*)pval, elem_sz*nlim ); } \
__inline static void e32_write_##name( elem_t* pval ) \
{ xxx_e_write_zeropage(E32_ADDR_##NAME, (void*)pval, elem_sz*nlim ); } \
__inline static void e32_read_##name##_n( elem_t* pval, unsigned int n ) \
{ 	if (n < nlim) xxx_e_read_zeropage(E32_ADDR_##NAME + n*elem_sz, (void*)pval, elem_sz ); }\
__inline static void e32_write_##name##_n( elem_t val, unsigned int n ) \
{ 	elem_t tmp = val;  \
	if (n < nlim) xxx_e_write_zeropage(E32_ADDR_##NAME + n*elem_sz, (void*)&tmp, elem_sz ); }
*/
#define  __SCALAR_BUILTINS(name,NAME,elem_t,elem_sz) \
__inline static void e32_read_##name( elem_t* pval ) \
{ 	xxx_e_read_dram((void*)E32_ADDR_##NAME, (void*)pval, elem_sz ); } \
__inline static void e32_write_##name( elem_t val ) \
{ 	elem_t tmp = val;  \
	xxx_e_write_dram((void*)E32_ADDR_##NAME, (void*)&tmp, elem_sz ); } \

#define  __ARRAY_BUILTINS(name,NAME,elem_t,elem_sz,nlim) \
__inline static void e32_read_##name( elem_t* pval ) \
{ xxx_e_read_dram((void*)E32_ADDR_##NAME, (void*)pval, elem_sz*nlim ); } \
__inline static void e32_write_##name( elem_t* pval ) \
{ xxx_e_write_dram((void*)E32_ADDR_##NAME, (void*)pval, elem_sz*nlim ); } \
__inline static void e32_read_##name##_n( elem_t* pval, unsigned int n ) \
{ 	if (n < nlim) xxx_e_read_dram((void*)E32_ADDR_##NAME + n*elem_sz, (void*)pval, elem_sz ); }\
__inline static void e32_write_##name##_n( elem_t val, unsigned int n ) \
{ 	elem_t tmp = val;  \
	if (n < nlim) xxx_e_write_dram((void*)E32_ADDR_##NAME + n*elem_sz, (void*)&tmp, elem_sz ); }

__ARRAY_BUILTINS(ctrl_ready,CTRL_READY,e32_int_t,E32_INT_SZ,ncores())
__ARRAY_BUILTINS(ctrl_run,CTRL_RUN,e32_int_t,E32_INT_SZ,ncores())
__ARRAY_BUILTINS(ctrl_retval,CTRL_RETVAL,e32_int_t,E32_INT_SZ,ncores())
__ARRAY_BUILTINS(ctrl_callp,CTRL_CALLP,e32_ptr_t,E32_PTR_SZ,ncores())

__ARRAY_BUILTINS(coremap,COREMAP,e32_uchar_t,E32_CHAR_SZ,ncores())
__ARRAY_BUILTINS(threadmap,THREADMAP,e32_uchar_t,E32_CHAR_SZ,ncores())

/* XXX gcc complained about this but make sure it was not wrong -DAR */
__ARRAY_BUILTINS(we,WE,e32_uint_t,sizeof(e32_workp_entry_t),ncores())

__SCALAR_BUILTINS(kdata_funcp,KDATA_FUNCP,e32_ptr_t,E32_PTR_SZ)
__SCALAR_BUILTINS(kdata_narg,KDATA_NARG,e32_int_t,E32_INT_SZ)
__SCALAR_BUILTINS(kdata_ptr_arg_off,KDATA_PTR_ARG_OFF,e32_ptr_t,E32_PTR_SZ)
__SCALAR_BUILTINS(kdata_ptr_arg_buf,KDATA_PTR_ARG_BUF,e32_ptr_t,E32_PTR_SZ)

#define e32_init_we(symbol,we,size) do { \
	int i; \
	for(i=0;i<size;i++) { \
		symbol[i][0] = we[i].ndr_dim; \
		memcpy(&symbol[i][1],we[i].ndr_gtdoff,3*sizeof(e32_uint_t)); \
		memcpy(&symbol[i][4],we[i].ndr_gtdsz,3*sizeof(e32_uint_t)); \
		memcpy(&symbol[i][7],we[i].ndr_ltdsz,3*sizeof(e32_uint_t)); \
		memcpy(&symbol[i][10],we[i].ndp_blk_first,3*sizeof(e32_uint_t)); \
		memcpy(&symbol[i][13],we[i].ndp_blk_end,3*sizeof(e32_uint_t)); \
		memcpy(&symbol[i][16],we[i].ndp_ltd0,3*sizeof(e32_uint_t)); \
		switch (we[i].ndr_dim) { \
			case 1: symbol[i][8] = 1; symbol[i][11] = 0; symbol[i][14] = 1; \
			case 2: symbol[i][9] = 1; symbol[i][12] = 0; symbol[i][15] = 1; \
			default: break; \
		} \
	} } while(0)


#elif defined(__coprthr_device__)

typedef int e32_int_t;
typedef unsigned int e32_uint_t;
typedef void* e32_ptr_t;
typedef unsigned char e32_uchar_t;
typedef e32_uint_t e32_workp_entry_t[19];

#define __SCALAR(NAME,elem_t) (*(elem_t*)E32_ADDR_##NAME)
#define __ARRAY(NAME,elem_t) ((elem_t*)E32_ADDR_##NAME)

#define e32_ctrl_ready 	__ARRAY(CTRL_READY,e32_int_t)
#define e32_ctrl_run 	__ARRAY(CTRL_RUN,e32_int_t)
#define e32_ctrl_retval	__ARRAY(CTRL_RETVAL,e32_int_t)
#define e32_ctrl_callp 	__ARRAY(CTRL_CALLP,e32_ptr_t)

#define e32_coremap 				__ARRAY(COREMAP,e32_uchar_t)
#define e32_threadmap 			__ARRAY(THREADMAP,e32_uchar_t)

#define e32_we 					__ARRAY(WE,e32_workp_entry_t)

#define e32_kdata_funcp 		__SCALAR(KDATA_FUNCP,e32_ptr_t)
#define e32_kdata_narg 			__SCALAR(KDATA_NARG,e32_int_t)
#define e32_kdata_ptr_arg_off	__SCALAR(KDATA_PTR_ARG_OFF,e32_int_t*)
#define e32_kdata_ptr_arg_buf	__SCALAR(KDATA_PTR_ARG_BUF,e32_ptr_t)

#define we_ndr_dim(we) 				(we[0])
#define we_ndr_gtdoff(we,d) 		(we[1+d])
#define we_ndr_gtdsz(we,d) 		(we[4+d])
#define we_ndr_ltdsz(we,d) 		(we[7+d])
#define we_ndp_blk_first(we,d)	(we[10+d])
#define we_ndp_blk_end(we,d) 		(we[13+d])
#define we_ndp_ltd0(we,d) 			(we[16+d])

#define e32_inc_ctrl_run(n) \
	do { ++e32_ctrl_run[core_local_data.corenum] } while(0)
#define e32_dec_ctrl_run(n) \
	do { --e32_ctrl_run[core_local_data.corenum] } while(0)

#else
#error must be compiled with either __coprthr_host__ or __coprthr_device__
#endif

#endif

