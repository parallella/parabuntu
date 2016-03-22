/* coprthr.h
 *
 * Copyright (c) 2013 Brown Deer Technology, LLC.  All Rights Reserved.
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

#ifndef _coprthr_h
#define _coprthr_h

#ifdef __coprthr_device__

#ifdef constant
#undef constant
#endif

#include "coprthr_xdevice.h"

#else

#include "coprthr_arch.h"
#include "coprthr_device.h"
#include "coprthr_mem.h"
#include "coprthr_program.h"
#include "coprthr_sched.h"


/***
 *** typdefs for opaque types
 ***/

typedef struct coprthr_device* coprthr_dev_t;
typedef struct coprthr_mem* coprthr_mem_t;
typedef struct coprthr_program* coprthr_program_t;
typedef struct coprthr_kernel* coprthr_kernel_t;
typedef struct coprthr_event* coprthr_event_t;


/***
 *** coprthr_dev API (low)
 ***/

#define COPRTHR_DEVMEM_TYPE_BUFFER		0x0001
#define COPRTHR_DEVMEM_TYPE_MUTEX		0x0002
#define COPRTHR_DEVMEM_TYPE_SIGNAL		0x0004
#define COPRTHR_DEVMEM_TYPE_REGISTER		0x0008
#define COPRTHR_DEVMEM_TYPE_FIFO		0x0010
#define COPRTHR_DEVMEM_TYPE_STACK		0x0020

#define COPRTHR_DEVMEM_PROT_ENABLED		0x0800
#define COPRTHR_DEVMEM_PROT_READ		(0x0100|COPRTHR_DEVMEM_PROT_ENABLED)
#define COPRTHR_DEVMEM_PROT_WRITE		(0x0200|COPRTHR_DEVMEM_PROT_ENABLED)

#define COPRTHR_DEVMEM_TYPEMASK			0x0ff
#define COPRTHR_DEVMEM_PROTMASK			0xf00

#define COPRTHR_DEVMEM_FIXED			0x1000

void* coprthr_devmemalloc( coprthr_dev_t dev, void* addr, size_t nmemb, 
	size_t size, int flags );

void coprthr_devmemfree( struct coprthr_device* dev, struct coprthr_mem* mem );

size_t coprthr_memsize( struct coprthr_mem* mem );
void* coprthr_memptr( struct coprthr_mem* mem, int flags );

size_t coprthr_devread( coprthr_dev_t dev, coprthr_mem_t mem, size_t offset,
	void* buf, size_t len, int flags);
size_t coprthr_devwrite( coprthr_dev_t dev, coprthr_mem_t mem, size_t offset,
	void* buf,
	size_t len, int flags);
size_t coprthr_devcopy( coprthr_dev_t dev, coprthr_mem_t mem_src, 
	size_t offset_src, coprthr_mem_t mem_dst, size_t offset_dst, size_t len, 
	int flags);
int coprthr_devexec( coprthr_dev_t dev, int nthr, 
	struct coprthr_kernel* krn1, unsigned int narg, void** args);

//int coprthr_devctl( int dd, int request, ... );

#define COPRTHR_DEVLOCK_NOWAIT		0x1
#define COPRTHR_DEVLOCK_NOINIT		0x2
#define COPRTHR_DEVUNLOCK_PERSIST	0x4

int coprthr_devlock( coprthr_dev_t dev, int flags );
int coprthr_devunlock( coprthr_dev_t dev, int flags );

void* coprthr_getdev( const char* path, int flags );

void* coprthr_devcompile( struct coprthr_device* dev, char* src, size_t len, char* opt, char** log );

//void* coprthr_devlink( struct coprthr_device* dev, struct coprthr_program* prg1, const char* kname);

void* coprthr_devlink( struct coprthr_device* dev, 
	struct coprthr_program* prg1, int flags );


/***
 *** coprthr API (direct)
 ***/

#define COPRTHR_DEVICE_X86_64 	((char*)COPRTHR_ARCH_ID_X86_64)
#define COPRTHR_DEVICE_I386 	((char*)COPRTHR_ARCH_ID_I386)
#define COPRTHR_DEVICE_ARM32 	((char*)COPRTHR_ARCH_ID_ARM32)
#define COPRTHR_DEVICE_E32_EMEK	((char*)COPRTHR_ARCH_ID_E32_EMEK)
#define COPRTHR_DEVICE_E32 	((char*)COPRTHR_ARCH_ID_E32)

#define COPRTHR_O_NONBLOCK	0x0001
#define COPRTHR_O_STREAM 	0x0010
#define COPRTHR_O_THREAD 	0x0020
#define COPRTHR_O_EXCLUSIVE 	0x0040

#define COPRTHR_O_DEFAULT COPRTHR_O_STREAM

int coprthr_dopen( const char* path, int flags);
int coprthr_dclose(int dd);

coprthr_program_t coprthr_dcompile( int dd, char* src, size_t len, char* opt,
	char** log );
//void* coprthr_link( int dd, struct coprthr_program* prg1, const char* kname);

//#define COPRTHR_E_WAIT 		0x0001
//#define COPRTHR_E_NOWAIT 	0x0002
//#define COPRTHR_E_NOW 		0x0004

#define COPRTHR_E_DEFAULT COPRTHR_E_NOWAIT

void* coprthr_dmalloc( int dd, size_t size, int flags );
void* coprthr_drealloc( int dd, void* dptr, size_t size, int flags );
void coprthr_dfree( int dd, void* dptr );
void* coprthr_dwrite(int dd, struct coprthr_mem* mem, size_t offset, void* ptr,
	size_t len, int flags);
void* coprthr_dread(int dd, struct coprthr_mem* mem, size_t offset, void* ptr,
	size_t len, int flags);
void* coprthr_dcopy(int dd, struct coprthr_mem* mem_src, size_t offset_src, 
	struct coprthr_mem* mem_dst, size_t offset_dst, size_t len, int flags);

int coprthr_dwaitev( int dd, struct coprthr_event* ev );

int coprthr_dwait( int dd );

coprthr_event_t coprthr_dexec( int dd, 
	coprthr_kernel_t krn, unsigned int nargs, void** args,
	unsigned int nthr, void* reserved, int flags );

coprthr_event_t coprthr_dnexec( int dd, unsigned int nkrn, 
	coprthr_kernel_t* v_krn, unsigned int* v_nargs, void*** v_args,
	unsigned int* v_nthr, void** v_reserved, int flags );

//int coprthr_kill( int dd, coprthr_event_t ev, int sig, int flags );

#define COPRTHR_S_EXECUTE	0x0001
#define COPRTHR_S_YIELD		0x0002
#define COPRTHR_S_SUSPEND	0x0004
#define COPRTHR_S_EXIT		0x0008

#define COPRTHR_S_PREEMPT	0x0100
#define COPRTHR_S_NOPREEMPT	0x0200
#define COPRTHR_S_CLEANUP	0x0400

//int coprthr_sched( int dd, coprthr_event_t ev, int action, ... );

#define COPRTHR_CTL_TESTSUP	10

void* coprthr_getsym( coprthr_program_t prg, const char* symbol );

#endif

#endif

