/* clexec.h
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

#ifndef _CLEXEC_H
#define _CLEXEC_H

#ifndef _STDCL_H
#error Do not include clexec.h directly, include stdcl.h instead.
#endif

#define _clexec(cp,devnum,p_ndr,ksym,flags,...) do { \
	extern void* _CLkv8##ksym[]; \
	cl_kernel* pkrn = (cl_kernel*)&_CLkv8##ksym[cp->context_id]; \
	if (*pkrn==0) *pkrn = clsym(cp,0,#ksym,CLLD_NOW); \
	clforka(cp,devnum,*pkrn,p_ndr,flags,__VA_ARGS__); \
	} while(0)

#define clexec(cp,devnum,p_ndr,ksym,...) \
	_clexec(cp,devnum,p_ndr,ksym,CL_EVENT_NOWAIT,__VA_ARGS__)

#define clexecb(cp,devnum,p_ndr,ksym,...) \
	_clexec(cp,devnum,p_ndr,ksym,CL_EVENT_WAIT,__VA_ARGS__)

#endif

