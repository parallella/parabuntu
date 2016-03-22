/* coprthr_sched.h 
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

#ifndef _coprthr_sched_h
#define _coprthr_sched_h

#include <sys/queue.h>
#include <pthread.h>

#define COPRTHR_E_WAIT          0x0001
#define COPRTHR_E_NOWAIT        0x0002
#define COPRTHR_E_NOW           0x0004

#define COPRTHR_E_IMMEDIATE	COPRTHR_E_NOW
#define COPRTHR_E_DIRECT	COPRTHR_E_NOW


struct coprthr_event {
	struct coprthr_device* dev;
	pthread_mutex_t mtx;
	pthread_cond_t sig;
	unsigned int nfunc;
	struct cmdcall_arg* cmd_argp;
	TAILQ_ENTRY(coprthr_event) cmds;
	int cmd;
	int cmd_stat;
   unsigned long tm_queued;
   unsigned long tm_submit;
   unsigned long tm_start;
   unsigned long tm_end;
};

#if defined(__FreeBSD__)
#define PTHREAD_MUTEX_ERRORCHECK_NP PTHREAD_MUTEX_ERRORCHECK
#endif

#define __coprthr_init_event(ev) do { \
	pthread_mutexattr_t attr; \
	int attrtype = PTHREAD_MUTEX_ERRORCHECK_NP; \
	pthread_mutexattr_init(&attr); \
	pthread_mutexattr_settype(&attr,attrtype); \
	pthread_mutex_init(&((ev)->mtx),&attr); \
	pthread_cond_init(&((ev)->sig),0); \
	pthread_mutex_unlock(&((ev)->mtx)); \
	(ev)->cmd_argp = 0; \
	} while(0)

#define __coprthr_free_event(ev) do { \
	pthread_cond_destroy(&((ev)->sig)); \
	pthread_mutex_destroy(&((ev)->mtx)); \
	__free((ev)->cmd_argp); \
	} while(0)



struct coprthr_command_queue {
   pthread_t td;
   pthread_mutex_t mtx;
   pthread_cond_t sig;
   unsigned int qstat;
   struct coprthr_event* cmd_submitted;
   struct coprthr_event* cmd_running;
   TAILQ_HEAD(tailhead_cmds_queued,coprthr_event) cmds_queued;
   TAILQ_HEAD(tailhead_cmds_complete,coprthr_event) cmds_complete;
};

#define __coprthr_init_command_queue(cmdq) do { \
   pthread_mutex_init(&(cmdq)->mtx,0); \
   pthread_cond_init(&(cmdq)->sig,0); \
   (cmdq)->qstat = 0; \
   (cmdq)->cmd_submitted = (struct coprthr_event*)0; \
   (cmdq)->cmd_running = (struct coprthr_event*)0; \
   TAILQ_INIT(&(cmdq)->cmds_queued); \
   TAILQ_INIT(&(cmdq)->cmds_complete); \
   } while(0)

#define __coprthr_free_command_queue(cmdq) do { \
   pthread_cond_destroy(&(cmdq)->sig); \
   pthread_mutex_destroy(&(cmdq)->mtx); \
	__free(cmdq); \
   } while(0)


/* command execution status */
#define __CL_COMPLETE                                 0x0
#define __CL_RUNNING                                  0x1
#define __CL_SUBMITTED                                0x2
#define __CL_QUEUED                                   0x3


#endif

