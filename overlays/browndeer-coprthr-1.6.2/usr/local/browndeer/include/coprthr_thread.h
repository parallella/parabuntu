/* coprthr_thread.h
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

#ifndef _coprthr_thread_h
#define _coprthr_thread_h

#include "coprthr_program.h"
#include "coprthr_mem.h"
#include "coprthr_sched.h"

/* XXX the typedefs should be gathered up somewhere */
typedef struct coprthr_kernel* coprthr_sym_t;

struct coprthr_td_attr {
	int detachstate;
	int initstate;
	int dd;
};
typedef struct coprthr_td_attr* coprthr_td_attr_t;
typedef struct coprthr_td_attr* coprthr_attr_t;

struct coprthr_td {
	struct coprthr_event ev;
	int detachstate;
	int initstate;
	int dd;
};
typedef struct coprthr_td* coprthr_td_t;
typedef struct coprthr_td* coprthr_t;

struct coprthr_mutex_attr {
	int dd;
};
typedef struct coprthr_mutex_attr* coprthr_mutex_attr_t;

struct coprthr_mutex {
	struct coprthr_mem mem;
	int dd;
};
typedef struct coprthr_mutex* coprthr_mutex_t;

struct coprthr_cond_attr {
	int dd;
};
typedef struct coprthr_cond_attr* coprthr_cond_attr_t;

struct coprthr_cond {
};
typedef struct coprthr_cond* coprthr_cond_t;


int coprthr_attr_init( coprthr_td_attr_t* attr );

int coprthr_attr_destroy( coprthr_td_attr_t* attr );

#define COPRTHR_A_CREATE_DETACHED 0
#define COPRTHR_A_CREATE_JOINABLE 0

#define COPRTHR_CREATE_DETACHED COPRTHR_A_CREATE_DETACHED
#define COPRTHR_CREATE_JOINABLE COPRTHR_A_CREATE_JOINABLE

int coprthr_attr_setdetachstate( coprthr_td_attr_t* attr, int state );

int coprthr_attr_setdevice( coprthr_td_attr_t* attr, int dd );

#define COPRTHR_A_CREATE_EXECUTE 0
#define COPRTHR_A_CREATE_SUSPEND 0
int coprthr_attr_setinit( coprthr_td_attr_t* attr, int action );

int coprthr_create( coprthr_td_t* td, coprthr_td_attr_t* attr, 
	coprthr_sym_t thr, void* arg );

int coprthr_ncreate( unsigned int nthr, coprthr_td_t* td,
	coprthr_td_attr_t* attr, coprthr_sym_t thrfunc, void* arg );

int coprthr_join( coprthr_td_t td, void** val );
int coprthr_join( coprthr_td_t td, void** val );


int coprthr_mutex_attr_init( coprthr_mutex_attr_t* mtxattr);
int coprthr_mutex_attr_destroy( coprthr_mutex_attr_t* mtxattr);
int coprthr_mutex_attr_setdevice( coprthr_mutex_attr_t* mtxattr, int dd );
int coprthr_mutex_init( coprthr_mutex_t* mtx, coprthr_mutex_attr_t* mtxattr );
int coprthr_mutex_destroy( coprthr_mutex_t* mtx );
int coprthr_mutex_lock( coprthr_mutex_t* mtx);
int coprthr_mutex_unlock( coprthr_mutex_t* mtx);

int coprthr_cond_attr_init( coprthr_cond_attr_t* condattr);
int coprthr_cond_attr_destroy( coprthr_cond_attr_t* condattr);
int coprthr_cond_attr_setdevice( coprthr_cond_attr_t* condattr, int dd);
int coprthr_cond_init( coprthr_cond_t* cond, coprthr_cond_attr_t* condattr);
int coprthr_cond_destroy( coprthr_cond_t* cond);
int coprthr_wait( coprthr_cond_t* cond, coprthr_mutex_t* mtx);
int coprthr_signal( coprthr_cond_t* cond);

int coprthr_kill( coprthr_td_t td, int sig );

#endif

