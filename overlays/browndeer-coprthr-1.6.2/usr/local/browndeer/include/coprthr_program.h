/* coprthr_program.h
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

#ifndef _coprthr_program_h
#define _coprthr_program_h

#include <sys/queue.h>
#include <pthread.h>

#include "cpuset_type.h"
#include "cmdcall.h"

#define CLARG_KIND_UNDEFINED	0x000
#define CLARG_KIND_VOID       0x001
#define CLARG_KIND_DATA       0x002
#define CLARG_KIND_GLOBAL     0x004
#define CLARG_KIND_LOCAL      0x008
#define CLARG_KIND_CONSTANT   0x010
#define CLARG_KIND_SAMPLER    0x020
#define CLARG_KIND_IMAGE2D    0x040
#define CLARG_KIND_IMAGE3D    0x080

#define CLSYM_KIND_


/* kernel */

struct _coprthr_ksyms_struct {
	int flags;
	void* kthr;
	void* kthr2;
	void* kcall;
	void* kcall2;
	void* kcall3;
};


//#define __coprthr_init_kernel(imp) do { \
//	(imp) = (struct coprthr_kernel*)malloc(sizeof(struct coprthr_kernel)); \
//	} while(0)

//#define __coprthr_free_kernel(imp) do { \
//	__free((imp)); \
//	} while(0)


/* program */

#define __nkernels_in_program(prg) (prg->nkrn)

struct coprthr_program {

	/* these could use a custom allocator that kept prg contiguous */
	size_t prg_sz;
	size_t prg_alloc_sz;

	size_t src_sz;
	char* src;

	size_t bin_sz;
	char* bin;
	int bin_stat;
	char* build_opt;
	char* build_log;

	unsigned int nclsym;
	struct clsymtab_entry* clsymtab;
	struct clargtab_entry* clargtab;
	char* clstrtab;

	unsigned int nkrn;
	char** kname;
	unsigned int* knarg;
	size_t* karg_buf_sz;
	unsigned int** karg_kind;
	size_t** karg_sz;
	uint32_t** karg_off;

	void* dlh;
	char* dlfile;
	struct _coprthr_ksyms_struct* v_ksyms;

	void* info;
	size_t* ksu;
	void* kbin;
	char* kbinfile;

};

//typedef struct coprthr1_program coprthr_program;

//coprthr_program_t __coprthr_prg_pack( coprthr_program_t prg, size_t sz )
//{
//	/* pack into continugous memory allocation */
//}
//
//coprthr_program_t coprthr_ld( const char* path, int flags );
//
//int coprthr_prg_write( const char* path, coprthr_program_t prg, int flags );



struct coprthr_kernel {
	struct coprthr_program* prg1;
	unsigned int knum;

	uint32_t* arg_off;
	size_t arg_buf_sz;
	void* arg_buf;
};

/* XXX temp hack -DAR */
#define __CL_INVALID_MEM_OBJECT                       -38
#define __CL_INVALID_ARG_VALUE                        -50
#define __CL_INVALID_ARG_SIZE                         -51

#endif

