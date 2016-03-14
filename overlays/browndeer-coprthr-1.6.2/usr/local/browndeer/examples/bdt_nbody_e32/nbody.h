/* nbody.h
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

#ifndef _NBODY_H
#define _NBODY_H

#include<CL/cl.h>

//#define DEFAULT_NPARTICLE 8192
#define DEFAULT_NPARTICLE 16384

#define DEFAULT_NSTEP 200
#define DEFAULT_NBURST 2
#define DEFAULT_NTHREAD 64
#define DEFAULT_NBLOCK 1

#define G_CONSTANT 1.0
#define DEFAULT_DT (float)1e-4
#define DEFAULT_ES (float)1e-2

#define ZOOM 0.1

#define FLOPS_PER_INTERACTION 20

#define __gflops(time,steps,nparticle) \
	(((float)steps * (float)nparticle*(float)nparticle * FLOPS_PER_INTERACTION) / time / 1e9)


//#define __index(i,e) ( 16*(i/4) + 4*e + (i%4) )
#define __index(i,e) (4*(i)+(e))

#define __index_x(i) __index(i,0)
#define __index_y(i) __index(i,1)
#define __index_z(i) __index(i,2)
#define __index_m(i) __index(i,3)


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


int nbody_init( int n, cl_float* pp, cl_float* vv );

void iterate_cpu(
   int nburst, int nparticle, int dummy,
   float gdt, float es,
   float* pp, float* vv
);

void iterate_cl(
   int nburst, int nparticle, int nthread,
   float gdt, float es,
   float* pp, float* vv
);

#endif

