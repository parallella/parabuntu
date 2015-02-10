/* bdt_nbody.cpp
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

#include <unistd.h>
#include <algorithm>
#include <cstring>
#include <math.h> 
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <sys/time.h>


#ifdef ENABLE_CL
#include<CL/cl.h>
#include "stdcl.h"
#include "nbody_kern.clh"
#endif

#include "Timer.h"
#include "nbody.h"

#ifndef DISABLE_DISPLAY
#include<GL/glut.h>
#include "nbody_display.h"
#endif



CLCONTEXT* cp = 0; /* selects CL context */

int devnum = 0;

void (*iterate)(
   int nburst, int nparticle, int nthread,
   cl_float gdt, cl_float es,
   cl_float* pp, cl_float* vv
) = 0;

struct iterate_args_struct iterate_args = __init_iterate_args();

char* cldevstr;
int nstep = 0;
int nburst = DEFAULT_NBURST;
int step_count = 0;
float gflops;

cl_kernel k_nbody;
cl_kernel krn2;

/*
 * main program
 */

int main(int argc, char** argv)
{

	Setup(0);

	int nparticle = DEFAULT_NPARTICLE;

	int i,j,k;
	int step = 0;
	int n;

	int nthread = DEFAULT_NTHREAD;
	int nb = DEFAULT_NBLOCK;

	int use_cpu = 0;

	int dump_results = 0;
   int use_display = 1;

	float stime = 0.0;
	float gdt = G_CONSTANT*DEFAULT_DT;
	float es = DEFAULT_ES;
	float time;
	float tmpx,tmpy,tmpz;

	float* pp = 0;
	float* vv = 0;

	FILE* fp;

	printf(
		"\nRunning bdt_nbody"
		" - a simple GPU-accelerated NBody Simulation.\n"
		"Copyright (c) 2008-2009 Brown Deer Technology, LLC. "
		" All Rights Reserved.\n"
		"This program is free software distributed under GPLv3.\n\n"
	);

	i = 1;
	while (i < argc) {

      if (!strcmp(argv[i],"--cpu")) use_cpu = 1;

#ifdef ENABLE_BROOK
      else if (!strcmp(argv[i],"--gpu-br")) use_gpu_br = 1;
#endif

#ifdef ENABLE_CL
      else if (!strcmp(argv[i],"--cl-device")) {
			++i;
			if (!strncmp(argv[i],"gpu",3)) cp = stdgpu;
			else if (!strncmp(argv[i],"cpu",3)) cp = stdcpu;
		}
#endif

		else if (!strcmp(argv[i],"--display")) use_display = 1;
		else if (!strcmp(argv[i],"--no-display")) use_display = 0;
		else if (!strcmp(argv[i],"--devnum")) devnum = atoi(argv[++i]);
		else if (!strcmp(argv[i],"--nstep")) nstep = atoi(argv[++i]);
		else if (!strcmp(argv[i],"--nburst")) nburst = atoi(argv[++i]);
		else if (!strcmp(argv[i],"--nblock")) nb = atoi(argv[++i]);
		else if (!strcmp(argv[i],"--nthread")) nthread = atoi(argv[++i]);
		else if (!strcmp(argv[i],"--nparticle")) nparticle = atoi(argv[++i]);
		else if (!strcmp(argv[i],"-D")) dump_results = 1;
		else {
			fprintf(stderr,"unrecognized option: %s\n",argv[i]);
			exit(1);
		}
		++i;
	}

   if (nparticle%16) {
      fprintf( stderr, "nparticle must be multiple of 16, stopping.\n"); 
      exit(1);
   }

	if (!use_display && nstep == 0) nstep = DEFAULT_NSTEP;

   if (nstep%nburst) {
      fprintf( stderr, "nstep must be multiple of nburst, stopping.\n"); 
      exit(1);
   }

	gdt = G_CONSTANT*DEFAULT_DT;

	printf(
		"nstep=%d nburst=%d nparticle=%d gdt=%e\n",
		nstep,nburst,nparticle,gdt
	);


#ifdef ENABLE_CL
	if (!cp) {
		if (clgetndev(stdgpu)) cp = stdgpu;
		else if (clgetndev(stdcpu)) cp = stdcpu;
	}
	iterate = (cp)? iterate_cl : iterate_cpu;

   struct clstat_info stat_info;
   struct cldev_info* dev_info 
		= (struct cldev_info*)malloc(clgetndev(cp)*sizeof(struct cldev_info));

   clstat(cp,&stat_info);
   clgetdevinfo(cp,dev_info);
	clfreport_devinfo(stdout,1,dev_info);

	cldevstr = (char*)malloc(64);
	if (dev_info->dev_type == CL_DEVICE_TYPE_GPU) {
		snprintf(cldevstr,64,"GPU/OpenCL %s",dev_info->dev_name);
	} else if (dev_info->dev_type == CL_DEVICE_TYPE_CPU) {
		snprintf(cldevstr,64,"CPU/OpenCL %s",dev_info->dev_name);
	} else strncpy(cldevstr,"???",3);

#ifdef __FreeBSD__
	void* hcl = clopen(cp,"nbody_kern.cl",CLLD_NOW);
	k_nbody = clsym(cp,hcl,"nbody_kern",0);
	krn2 = clsym(cp,hcl,"copy_kern",0);
#else
	k_nbody = clsym(cp,0,"nbody_kern",0);
	krn2 = clsym(cp,0,"copy_kern",0);
#endif

#endif

#ifdef DISABLE_DISPLAY
	use_display = 0;
#endif

   if(use_display) {
#ifndef DISABLE_DISPLAY
        glutInit(&argc, argv);
        glutInitWindowPosition(100,10);
        glutInitWindowSize(600,600);
        glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE );
        glutCreateWindow("Brown Deer Technology nbody simulation");
        display_init();
        glutDisplayFunc(displayfunc);
        glutReshapeFunc(reShape);
        glutIdleFunc(idle);
        glutKeyboardFunc(keyboardFunc);
#endif
	}


	if (cp) {
		pp = (cl_float*)clmalloc(cp,sizeof(cl_float)*4*nparticle,0);
		vv = (cl_float*)clmalloc(cp,sizeof(cl_float)*4*nparticle,0);
	}

	if (pp == 0 || vv == 0 ) {
		fprintf(stderr,"memory allocation failed.  Terminating...\n");
		exit(-1);
	}


	Setup(0);

   float s = 100.0f;

   nbody_init( nparticle, pp, vv );

	iterate_args.nburst = nburst; // 10;
	iterate_args.nparticle = nparticle;
	iterate_args.nthread = nthread;
	iterate_args.gdt = gdt;
	iterate_args.es = es;
	iterate_args.pp = pp;
	iterate_args.vv = vv;

   if(use_display) {

#ifndef DISABLE_DISPLAY
        glutMainLoop();
#endif

   } else {

		for(int step = 0; step < nstep; step += nburst) {

			iterate_cl( nburst, nparticle, nthread, gdt, es, pp, vv);

			if (step_count == 0) printf("%s %f GFLOPS\n",cldevstr,gflops);	

		}

		float tmp = 0.0f;
		int i;
  	   for(i=0; i < nparticle; ++i) {
  	     	tmp += pp[__index_x(i)]*pp[__index_x(i)];
  	     	tmp += pp[__index_y(i)]*pp[__index_y(i)];
  	     	tmp += pp[__index_z(i)]*pp[__index_z(i)];
  	   }
  	   printf("[%d] checksum=%e\n",getpid(),tmp);

	}



cleanup:

#ifdef ENABLE_CL

#ifdef __FreeBSD__
	clclose(cp,hcl);
#endif

	if (pp) clfree(pp);
	if (vv) clfree(vv);
#else
	if (pp) free(pp);
	if (vv) free(vv);
#endif

   return(0);

}


void iterate_cpu(
   int nburst, int nparticle, int dummy,
   float gdt, float es,
   float* pp, float* vv
)
{

	Start(0);

	for(int burst = 0; burst<nburst; burst++) {

	for(int i=0; i< nparticle; i++) {

		float x = pp[__index_x(i)];
		float y = pp[__index_y(i)];
		float z = pp[__index_z(i)];
	
		float tmp = x;
	
		float vx = vv[__index_x(i)];
		float vy = vv[__index_y(i)];
		float vz = vv[__index_z(i)];
		
		float ax = 0.0;
		float ay = 0.0;
		float az = 0.0;

		for(int j=0; j<nparticle; j++) {

			float x2 = pp[__index_x(j)];
			float y2 = pp[__index_y(j)];
			float z2 = pp[__index_z(j)];
			float m2 = pp[__index_m(j)];
		
			float dx = x2 - x;
			float dy = y2 - y;
			float dz = z2 - z;
	
			float r = dx*dx + dy*dy + dz*dz;
			r += es;
			r = 1.0f/sqrt(r);
			r *= r*r;
			float f = m2 * r;

			if (i==j) f = 0.0;
	
			ax += f*dx;
			ay += f*dy;
			az += f*dz;
	
		}

		x += vx * gdt + 0.5f*gdt*gdt*ax;
		y += vy * gdt + 0.5f*gdt*gdt*ay;;
		z += vz * gdt + 0.5f*gdt*gdt*az;;
	
		vx += ax * gdt;
		vy += ay * gdt;
		vz += az * gdt;

		pp[__index_x(i)] = x;
		pp[__index_y(i)] = y;
		pp[__index_z(i)] = z;
	
		vv[__index_x(i)] = vx;
		vv[__index_y(i)] = vy;
		vv[__index_z(i)] = vz;

	}

	}

	Stop(0);
	double time = GetElapsedTime(0); 
	step_count += nburst;

	if (time > 5.0) {	
	gflops = __gflops(time,step_count,nparticle);
		Reset(0);
		step_count = 0;
	}

}

#ifdef ENABLE_CL

cl_float* pp2 = 0;
cl_float* pp3 = 0;

void iterate_cl(
   int nburst, int nparticle, int nthread,
   float gdt, float es,
   float* pp, float* vv
)
{

	double time_old = GetElapsedTime(0);

	if (pp2==0) pp2 = (cl_float*)clmalloc(cp,sizeof(cl_float)*4*nparticle,0);
	if (pp3==0) pp3 = (cl_float*)clmalloc(cp,sizeof(cl_float)*4*nparticle,0);


//	int n = nparticle;
//	int n = nparticle/4;
	int n = nparticle/2;

	clndrange_t ndr = clndrange_init1d(0,n,nthread);
	clndrange_t ndr2 = clndrange_init1d(0,nparticle,nthread);
	clarg_set(cp,k_nbody,0,n);
	clarg_set(cp,k_nbody,1,gdt);
	clarg_set(cp,k_nbody,2,es);
	clarg_set_global(cp,k_nbody,4,(cl_float4*)vv);

	clarg_set(cp,krn2,0,nparticle);
	clarg_set_global(cp,krn2,1,pp);
	clarg_set_global(cp,krn2,2,pp2);

	clmsync(cp,devnum,pp,CL_MEM_DEVICE|CL_EVENT_NOWAIT);
	clmsync(cp,devnum,vv,CL_MEM_DEVICE|CL_EVENT_NOWAIT);
	clwait(cp,devnum,CL_MEM_EVENT);
	Start(0); 

//	for(int burst = 0; burst<nburst; burst+=2) {
	for(int burst = 0; burst<nburst; burst++) {

		clarg_set_global(cp,k_nbody,3,pp2);
		clarg_set_global(cp,k_nbody,5,pp);
		clfork(cp,devnum,k_nbody,&ndr,CL_EVENT_NOWAIT);

//		clfork(cp,devnum,krn2,&ndr2,CL_EVENT_NOWAIT);
	clmcopy(cp,devnum,pp2,pp,CL_EVENT_NOWAIT); // XXX

//		clarg_set_global(cp,k_nbody,3,pp);
//		clarg_set_global(cp,k_nbody,5,pp2);
//		clfork(cp,devnum,k_nbody,&ndr,CL_EVENT_NOWAIT);

	}

//	clwait(cp,devnum,CL_KERNEL_EVENT);
//	Stop(0);

//	clmsync(cp,devnum,pp2,CL_MEM_HOST|CL_EVENT_NOWAIT);
	clmsync(cp,devnum,pp,CL_MEM_HOST|CL_EVENT_NOWAIT);
	clmsync(cp,devnum,vv,CL_MEM_HOST|CL_EVENT_NOWAIT);

	clwait(cp,devnum,CL_ALL_EVENT);

	Stop(0);

//		float tmp = 0.0f;
//		int i;
//      for(i=0; i < nparticle; ++i) {
//         tmp += pp[__index_x(i)]*pp[__index_x(i)];
//         tmp += pp[__index_y(i)]*pp[__index_y(i)];
//         tmp += pp[__index_z(i)]*pp[__index_z(i)];
//      }
//      printf("[%d] checksum=%e\n",getpid(),tmp);

	double time = GetElapsedTime(0);

	step_count += nburst;

	if (time > 2.0) {	
		gflops = __gflops(time,step_count,nparticle);
		Reset(0);
		step_count = 0;
	}

//	clfree(pp2);

}

#endif

