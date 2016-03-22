/* em.h
 *
 * Copyright (c) 2008-2009 Brown Deer Technology, LLC.  All Rights Reserved.
 *
 * This software was developed by Brown Deer Technology, LLC.
 * For more information contact info@browndeertechnology.com
 * 
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 3 as published by
 * the Free Software Foundation.
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

#ifndef _EM3D_H
#define _EM3D_H

#include<CL/cl.h>

#define DEFAULT_NSTEP 500
#define DEFAULT_NBURST 10
#define DEFAULT_NTHREAD 4
#define DEFAULT_NBLOCK 1

#define ZOOM 0.1

//#define FLOPS_PER_INTERACTION 72.0
#define FLOPS_PER_INTERACTION 36.0

#define FREQUENCY 10.0e9

#define __gflops(time,steps,n) \
	(((float)steps * (float)n * FLOPS_PER_INTERACTION) / time / 1e9)



struct iterate_args_struct {
	int nburst;
	int nparticle;
	int nthread;
	cl_float gdt;
	cl_float es;
	cl_float* pp;
	cl_float* vv;
};

#define __init_iterate_args() { 0,0,0, 0.0,0.0, 0,0}


extern void (*iterate)(
	int nburst, int nparticle, int nthread,
	cl_float gdt, cl_float es,
	cl_float* pp, cl_float* vv
);

extern struct iterate_args_struct iterate_args;


#endif

