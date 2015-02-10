/* bdt_em3d.cpp
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

#include <algorithm>
#include <cstring>
#include <math.h> 
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <sys/time.h>

#include "Timer.h"

#include "em3d.h"

#define DEFAULT_NX	64
#define DEFAULT_NY	64
#define DEFAULT_NZ	48

#define DEFAULT_NSTEP 1800
#define DEFAULT_NBURST 10
#define DEFAULT_NTHREAD 1
#define DEFAULT_NTHREAD_CPU 1
#define DEFAULT_NTHREAD_GPU 4
#define DEFAULT_NBLOCK 1

#define TOL 1.0/10000.0
#define CLAMP 1.0/10000000000.0
#define C1  1.0
//#define DEFAULT_DT 0.0001
#define DEFAULT_DT 0.00005


#define NX  36
#define NY  32
#define NZ  32


#define FREQUENCY 10.0e9
#define GUIDE_WIDTH 0.0229
#define GUIDE_HEIGHT 0.0102
//#define LENGTH_IN_WAVELENGTHS 4.0
#define LENGTH_IN_WAVELENGTHS 2.0
//#define CELLS_PER_WAVELENGTH 24.0
#define CELLS_PER_WAVELENGTH 16.0

#define LIGHT_SPEED 299792458.0
#define LIGHT_SPEED_SQUARED 89875517873681764.0
#define MU_0 1.256637061435917295385057353311801153678867759750042328e-6
#define EPSILON_0 8.8541878176203898505365630317107502606083701665994e-12




void initial_conditions(
	int nx, int ny, int nz,
	float* hx, float* hy, float* hz,
	float* ex, float* ey, float* ez
);

int write_vti( FILE* , int nx, int ny, int nz, float* q );


void iterate_gpu_cl_display(
	int argc, char** argv,
   int nstep, int nburst, float t0, float dt,
   int nx, int ny, int nz, int nb, int nt,
	float ax, float ay, float az,
	float bx, float by, float bz,
	float* hx, float* hy, float* hz,
	float* ex, float* ey, float* ez
);


int main(int argc, char** argv)
{
	int i,j,k;
	int step = 0;
	int n;

	int nstep = DEFAULT_NSTEP;
	int nburst = DEFAULT_NBURST;
	int nthread = DEFAULT_NTHREAD;
	int nblock = DEFAULT_NBLOCK;

	int nx = DEFAULT_NX;
	int ny = DEFAULT_NY;
	int nz = DEFAULT_NZ;

	int use_cpu_cl = 0;
	int use_gpu_cl = 1;
	int display_mode = 1;

	int dump_results = 0;

	float stime = 0.0;
	float time;
	float tmpx,tmpy,tmpz;

	float dt = DEFAULT_DT;


	FILE* fp;

	printf(
		"\nRunning bdt_em3d"
		" - a simple OpenCL 3D electromagnetic FDTD example.\n"
		"Copyright (c) 2009-2011 Brown Deer Technology, LLC. "
		" All Rights Reserved.\n"
		"This program is free software distributed under GPLv3.\n\n"
	);

   float lambda = LIGHT_SPEED/FREQUENCY;

	nx = 128; ny = 128; nz = 256;

	i = 1;
	while (i < argc) {

      if (!strcmp(argv[i],"--cpu-cl")) 
			{ use_cpu_cl = 1; nthread = DEFAULT_NTHREAD_CPU; }

      else if (!strcmp(argv[i],"--gpu-cl")) 
			{ use_gpu_cl = 1; nthread = DEFAULT_NTHREAD_GPU; } 

      else if (!strcmp(argv[i],"--display")) display_mode = 1;
      else if (!strcmp(argv[i],"--dump")) dump_results = 1;

		else if (!strcmp(argv[i],"--nstep")) nstep = atoi(argv[++i]);
		else if (!strcmp(argv[i],"--nburst")) nburst = atoi(argv[++i]);
//		else if (!strcmp(argv[i],"--nblock")) nblock = atoi(argv[++i]);
		else if (!strcmp(argv[i],"--nthread")) nthread = atoi(argv[++i]);
		else {
			fprintf(stderr,"unrecognized option: %s\n",argv[i]);
			exit(1);
		}
		++i;
	}

   if (nz%4) {
      fprintf( stderr, "nz must be multiple of 4, stopping.\n"); 
      exit(1);
   }

   if (nstep%nburst) {
      fprintf( stderr, "nstep must be multiple of nburst, stopping.\n"); 
      exit(1);
   }

	printf(
		"nstep=%d nburst=%d nx=%d ny=%d nz=%d dt=%e\n",
		nstep,nburst,nx,ny,nz,dt
	);

	int nyz = ny*nz;
	int nxyz = nx*ny*nz;

   float dx = (LENGTH_IN_WAVELENGTHS*lambda)/(1.0*nx);
   float dy = GUIDE_WIDTH/ny;
   float dz = GUIDE_HEIGHT/nz;

   dt = 1.0/(LIGHT_SPEED*sqrt(1.0/(dx*dx) + 1.0/(dy*dy) + 1.0/(dz*dz)));

   printf(
      "nstep=%d nburst=%d nx=%d ny=%d nz=%d dt=%e\n",
      nstep,nburst,nx,ny,nz,dt
   );

   float bx = dt/(MU_0*dx);
   float ax = dt/(EPSILON_0*dx);
   float by = dt/(MU_0*dy);
   float ay = dt/(EPSILON_0*dy);
   float bz = dt/(MU_0*dz);
   float az = dt/(EPSILON_0*dz);


	float* hx = (float*)calloc(nxyz,sizeof(float));
	float* hy = (float*)calloc(nxyz,sizeof(float));
	float* hz = (float*)calloc(nxyz,sizeof(float));
	float* ex = (float*)calloc(nxyz,sizeof(float));
	float* ey = (float*)calloc(nxyz,sizeof(float));
	float* ez = (float*)calloc(nxyz,sizeof(float));

	float* solnq = (float*)malloc(nxyz*sizeof(float));

	if (
		hx==0 || hy==0 || hz==0
		|| ex==0 || ey==0 || ez==0 
		|| solnq==0
	) {
		fprintf(stderr,"memory allocation failed\n");
		exit(-1);
	}


	Setup(0);


	if (use_gpu_cl && display_mode) {

		initial_conditions(nx,ny,nz,hx,hy,hz,ex,ey,ez);

//		Reset(0);
//		Start(0);
		iterate_gpu_cl_display( argc,argv,
			nstep,nburst,0.0f,dt,nx,ny,nz,nblock,nthread,
			ax,ay,az,bx,by,bz,
			hx,hy,hz, ex,ey,ez
		);
//		Stop(0);
//		time = GetElapsedTime(0); printf("%f sec\n",time);

   	if (dump_results) {
      	float tmpx,tmpy,tmpz;
      	for(i=0;i<nx;i++) for(j=0;j<ny;j++) for(k=0;k<nz;k++) {
         	tmpx = ex[i*nyz+j*nz+k];
         	tmpy = ey[i*nyz+j*nz+k];
         	tmpz = ez[i*nyz+j*nz+k];
        	 	solnq[i*ny*nz+j*nz+k] = fabs(tmpx+tmpy+tmpz)/3.0;

      	}
			fp=fopen("output_em3d_power_gpu_cl.vti","w");
	     	write_vti(fp,nx,ny,nz,solnq);
			fclose(fp);
  	}

	}


cleanup:

	if (hx) free(hx);
	if (hy) free(hy);
	if (hz) free(hz);

	if (ex) free(ex);
	if (ey) free(ey);
	if (ez) free(ez);

	if (solnq) free(solnq);

   return(0);

}



int 
write_vti( FILE* fp, int nx, int ny, int nz, float* q )
{

	float rmin = -1.0E-50;
	float rmax = +1.0E-50;
	for(int i=0; i<nx; i++) 
	for(int j=0; j<ny; j++) 
	for(int k=0; k<nz; k++) {
		rmin = std::min(rmin,q[i*nz*ny+j*nz+k]);
		rmax = std::max(rmax,q[i*nz*ny+j*nz+k]);
	}

	fprintf(fp,"<?xml version=\"1.0\"?>\n");
	fprintf(fp,"<VTKFile type=\"ImageData\" version=\"0.1\""
		" byte_order=\"LittleEndian\">\n");
	fprintf(fp,"<ImageData"
		" WholeExtent=\"0 %d 0 %d 0 %d\""
		" Origin=\"0 0 0\""
		" Spacing=\"1 1 1\">\n",nx-1,ny-1,nz-1);
	fprintf(fp,"<Piece Extent=\"0 %d 0 %d 0 %d\">\n",nx-1,ny-1,nz-1);
	fprintf(fp,"<PointData Scalars=\"ImageData\">\n");
	fprintf(fp,"<DataArray type=\"Float32\" Name=\"ImageFile\""
		" format=\"ascii\" RangeMin=\"%e\" RangeMax=\"%e\">\n",rmin,rmax);

	float sum = 0.0;
	for(int k=0; k<nz; k++) 
	for(int j=0; j<ny; j++) {
		for(int i=0; i<nx; i++) {
			fprintf(fp,"%e ",q[i*nz*ny+j*nz+k]);
		}
		fprintf(fp,"\n");
	}

	fprintf(fp,"</DataArray>\n");
	fprintf(fp,"</PointData>\n");
	fprintf(fp,"<CellData></CellData>\n");
	fprintf(fp,"</Piece>\n");
	fprintf(fp,"</ImageData>\n");
	fprintf(fp,"</VTKFile>\n");

	return(0);

}


void initial_conditions(
	int nx, int ny, int nz,
	float* hx, float* hy, float* hz,
	float* ex, float* ey, float* ez
)
{
	int i,j,k;
	int nyz = ny*nz;
	for(i=0;i<nx;i++) for(j=0;j<ny;j++) for(k=0;k<nz;k++) {
		hx[i*nyz+j*nz+k] = 0.0;
		hy[i*nyz+j*nz+k] = 0.0;
		hz[i*nyz+j*nz+k] = 0.0;
		ex[i*nyz+j*nz+k] = 0.0;
		ey[i*nyz+j*nz+k] = 0.0;
		ez[i*nyz+j*nz+k] = 0.0;

	}

}

