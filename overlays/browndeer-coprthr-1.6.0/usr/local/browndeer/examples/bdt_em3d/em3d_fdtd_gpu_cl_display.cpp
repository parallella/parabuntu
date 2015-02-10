/* em3d_fdtd_gpu_cl_display.c
 *
 * Copyright (c) 2008 Brown Deer Technology, LLC.  All Rights Reserved.
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
#include <math.h> 
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <sys/time.h>
#include <assert.h>

#include<GL/glut.h>

#include "stdcl.h"

#include "Timer.h"
#include "em3d.h"


#define HX  0
#define HY  1
#define HZ  2

#define EX 0
#define EY 1
#define EZ 2


#ifndef max
#define max(a,b) ((a<b)?b:a)
#endif
#ifndef min
#define min(a,b) ((a>b)?b:a)
#endif

void display_init();
void idle();
void reShape(int w,int h);
void displayfunc();
void keyboardFunc(unsigned char key, int mouseX, int mouseY);


inline
void shuffle(int n,float* data)
{
   int k;
   float tmp[1024];
   for(k=0;k<n; k++) {
      tmp[k*4+0] = data[k];
      tmp[k*4+1] = data[n+k];
      tmp[k*4+2] = data[2*n+k];
      tmp[k*4+3] = data[3*n+k];
   }
   memcpy(data,tmp,sizeof(float)*4*n);
}


inline
void unshuffle(int n,float* data)
{
   int k;
   float tmp[1024];
   for(k=0;k<n; k++) {
      tmp[0*n+k] = data[k*4];
      tmp[1*n+k] = data[k*4+1];
      tmp[2*n+k] = data[k*4+2];
      tmp[3*n+k] = data[k*4+3];
   }
   memcpy(data,tmp,sizeof(float)*4*n);
}

float __dt;
int __nx,__ny,__nz;
int __nxyz;
int __nstep;
int __nburst;
int __step;
float __t0;
clndrange_t* p_ndr = 0;
clndrange_t* p_ndr2 = 0;
clndrange_t* p_ndr4 = 0;
clndrange_t* p_ndr_slice = 0;
cl_kernel k_hcomp = (cl_kernel)0;
cl_kernel k_ecomp = (cl_kernel)0;
cl_kernel k_slice = (cl_kernel)0;

cl_float* s_hxyz = 0;
cl_float* s_sss = 0;

cl_float* slice = 0;
char* cldevstr;

int devnum = 0;

void
iterate_gpu_cl_display(
	int argc, char** argv,
	int nstep, int nburst, float t0, float dt,
	int nx, int ny, int nz, int nb, int nt,
	float ax, float ay, float az,
	float bx, float by, float bz,
	float* hx, float* hy, float* hz,
	float* ex, float* ey, float* ez
)
{
	int timing = 1;

	if (nb>1) { nb=1; fprintf(stderr,"forcing nb=1\n"); }

	int step,burst;
	int i,j,k;

	int nz4 = nz/4;
	int nyz = ny*nz;
	int nyz4 = ny*nz4;
	int nxyz = nx*ny*nz;
	int nxyz4 = nx*ny*nz/4;

	float t;


	printf("iterate_cl %f\n",dt);


	s_hxyz = (cl_float*)clmalloc(stdgpu,3*sizeof(cl_float4)*nxyz4,0);
   s_sss = (cl_float*)clmalloc(stdgpu,3*sizeof(cl_float4)*nxyz4,0);
   slice = (cl_float*)clmalloc(stdgpu,sizeof(cl_float4)*nx*ny,0);


   for(i=0;i<nx;i++) for(j=0;j<ny;j++) {
      shuffle(nz4,hx+i*nyz+j*nz);
      shuffle(nz4,hy+i*nyz+j*nz);
      shuffle(nz4,hz+i*nyz+j*nz);
      shuffle(nz4,ex+i*nyz+j*nz);
      shuffle(nz4,ey+i*nyz+j*nz);
      shuffle(nz4,ez+i*nyz+j*nz);
   }


   for(i=0;i<nx;i++) for(j=0;j<ny;j++) {
		memcpy(s_hxyz+3*(i*nyz+j*nz)+HX*nz,hx+i*nyz+j*nz,sizeof(float)*nz);
		memcpy(s_hxyz+3*(i*nyz+j*nz)+HY*nz,hy+i*nyz+j*nz,sizeof(float)*nz);
		memcpy(s_hxyz+3*(i*nyz+j*nz)+HZ*nz,hz+i*nyz+j*nz,sizeof(float)*nz);
	}

   for(i=0;i<nx;i++) for(j=0;j<ny;j++) {
		memcpy(s_sss+3*(i*nyz+j*nz)+EX*nz,ex+i*nyz+j*nz,sizeof(float)*nz);
		memcpy(s_sss+3*(i*nyz+j*nz)+EY*nz,ey+i*nyz+j*nz,sizeof(float)*nz);
		memcpy(s_sss+3*(i*nyz+j*nz)+EZ*nz,ez+i*nyz+j*nz,sizeof(float)*nz);
	}


	struct clstat_info stat_info;
	struct cldev_info* dev_info 
		= (struct cldev_info*)malloc(clgetndev(stdgpu)*sizeof(struct cldev_info));

	clstat(stdgpu,&stat_info);
	clgetdevinfo(stdgpu,dev_info);

	cldevstr = (char*)malloc(64);
	snprintf(cldevstr,64,"GPU/OpenCL %s",dev_info->dev_name);

   void* hcl = clopen(stdgpu,"em3d_fdtd_gpu_kern.cl",0);

   k_hcomp = clsym(stdgpu,hcl,"hcomp_kern",0);
   k_ecomp = clsym(stdgpu,hcl,"ecomp_kern",0);
   k_slice = clsym(stdgpu,hcl,"slice_kern",0);


	cl_float4 aa = (cl_float4){ax,ay,az,0.0f};
	cl_float4 bb = (cl_float4){bx,by,bz,0.0f};

   int nb1 = nb+1;
   int nb3 = nb1*nb1*nb1;

   uint ns = nt*nb+1;
   uint ns2 = ns*ns;
   uint ns3 = ns2*ns;

	printf("ns3 = %d\n",ns3);

	uint nt3 = 4; // nt*nt*nt;

	int iz4 = nz4/2;

	long long stime,etime;

	clndrange_t ndr = clndrange_init3d(0,nx,1, 0,ny,1, 0,nz4,64);
	clndrange_t ndr2 = clndrange_init3d(0,nx,1, 0,ny/2,1, 0,nz4,64);
	clndrange_t ndr4 = clndrange_init3d(0,nx,1, 0,ny/4,1, 0,nz4,64);
	clndrange_t ndr_slice = clndrange_init2d(0,nx,nt, 0,ny,nt );
	p_ndr = &ndr;
	p_ndr2 = &ndr2;
	p_ndr4 = &ndr4;
	p_ndr_slice = &ndr_slice;

	clmsync(stdgpu,devnum,s_hxyz,CL_MEM_DEVICE|CL_EVENT_NOWAIT);
	clmsync(stdgpu,devnum,s_sss,CL_MEM_DEVICE|CL_EVENT_NOWAIT);

   clarg_set(stdgpu,k_hcomp,1,nx);
   clarg_set(stdgpu,k_hcomp,2,ny);
   clarg_set(stdgpu,k_hcomp,3,nz4);
   clarg_set(stdgpu,k_hcomp,4,bb);
   clarg_set_global(stdgpu,k_hcomp,5,s_hxyz);
   clarg_set_global(stdgpu,k_hcomp,6,s_sss);


   clarg_set(stdgpu,k_ecomp,1,nx);
   clarg_set(stdgpu,k_ecomp,2,ny);
   clarg_set(stdgpu,k_ecomp,3,nz4);
   clarg_set(stdgpu,k_ecomp,4,aa);
	clarg_set_global(stdgpu,k_ecomp,5,s_hxyz);
	clarg_set_global(stdgpu,k_ecomp,6,s_sss);


//	cl_int iz = nz4/2;
	cl_int iy = ny/2;
   clarg_set(stdgpu,k_slice,0,nx);
   clarg_set(stdgpu,k_slice,1,ny);
   clarg_set(stdgpu,k_slice,2,nz4);
//   clarg_set(stdgpu,k_slice,3,iz4);
   clarg_set(stdgpu,k_slice,3,iy);
   clarg_set_global(stdgpu,k_slice,5,slice);



	printf("XXX compare local mem %d avail, %d needed\n",
		dev_info->dev_local_mem_sz,8*ns3*sizeof(cl_float4));

	__nx=nx; __ny=ny; __nz = nz;
	__nxyz = nx*ny*nz;
	__dt = dt;
	__nstep = nstep;
	__nburst = nburst;
	__step = nburst;
	__t0 = t0;

        glutInit(&argc,argv);
        glutInitWindowPosition(100,10);
        glutInitWindowSize(512,512);
        glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE );
        glutCreateWindow(
				"Brown Deer Technology 3D Electromagnetic FDTD Simulation");
        display_init();
        glutDisplayFunc(displayfunc);
        glutReshapeFunc(reShape);
        glutIdleFunc(idle);
        glutKeyboardFunc(keyboardFunc);
        glutMainLoop();


	clclose(stdgpu,hcl);

   for(i=0;i<nx;i++) for(j=0;j<ny;j++) {
		memcpy(hx+i*nyz+j*nz,s_hxyz+3*(i*nyz+j*nz)+HX*nz,sizeof(float)*nz);
		memcpy(hy+i*nyz+j*nz,s_hxyz+3*(i*nyz+j*nz)+HY*nz,sizeof(float)*nz);
		memcpy(hz+i*nyz+j*nz,s_hxyz+3*(i*nyz+j*nz)+HZ*nz,sizeof(float)*nz);
	}

   for(i=0;i<nx;i++) for(j=0;j<ny;j++) {
		memcpy(ex+i*nyz+j*nz,s_sss+6*(i*nyz+j*nz)+EX*nz,sizeof(float)*nz);
		memcpy(ey+i*nyz+j*nz,s_sss+6*(i*nyz+j*nz)+EY*nz,sizeof(float)*nz);
		memcpy(ez+i*nyz+j*nz,s_sss+6*(i*nyz+j*nz)+EZ*nz,sizeof(float)*nz);
	}


   for(i=0;i<nx;i++) for(j=0;j<ny;j++) {
      unshuffle(nz4,hx+i*nyz+j*nz);
      unshuffle(nz4,hy+i*nyz+j*nz);
      unshuffle(nz4,hz+i*nyz+j*nz);
      unshuffle(nz4,ex+i*nyz+j*nz);
      unshuffle(nz4,ey+i*nyz+j*nz);
      unshuffle(nz4,ez+i*nyz+j*nz);
   }

	if (s_hxyz) clfree(s_hxyz);
	if (s_sss) clfree(s_sss);
	if (slice) clfree(slice);

}




/*
 * GL display 
 */ 

int step_count;
float gflops;

int screen_width;
int screen_height;
unsigned char* bmp = 0;
unsigned char* bmp_slice = 0;
char devstr[64];

void display_init()
{
   int i;
    glClearColor(0.0 ,0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

   FILE* fp = fopen("bdt.bmp","rb");
   unsigned char header[54];
   fread(header,54,1,fp);
   if(header[0]=='B' && header[1]=='M') {
      int offset = *(unsigned int*)(header+10);
      int w = *(int*)(header+18);
      int h = *(int*)(header+22);
      int b = (int)header[28];
      bmp = (unsigned char*)malloc(w*h*3);
      fseek(fp,offset,SEEK_SET);
      fread(bmp,w*h*3,1,fp);
      fclose(fp);
   }

   bmp_slice = (unsigned char*)malloc(__nx*__ny*16*3*4);

	if (cldevstr) strncpy(devstr,cldevstr,64);

}


void idle()
{ glutPostRedisplay(); }


void reShape(int w,int h)
{
   screen_width = w;
   screen_height = h;
    glViewport(0,0,w,h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluPerspective(45.0f,w/h,1.0f,1000.0f);
    gluLookAt (0.0, 0.0, -2.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0);
}

#define __red(x) ((x<0.4)? (x/0.4)*0.901961 : (x<0.8)? 0.901961 : 0.901961 + ((x-0.901961)/0.098039)*0.098039)

void displayfunc()
{
	unsigned char jet_colormap[64*3] = { 
		0,0,143, 0,0,159, 0,0,175, 0,0,191, 0,0,207, 0,0,223,
		0,0,239, 0,0,255, 0,15,255, 0,31,255, 0,47,255, 0,63,255,
		0,79,255, 0,95,255, 0,111,255, 0,127,255, 0,143,255,
		0,159,25, 0,175,255, 0,191,255, 0,207,255, 0,223,255,
		0,239,255, 0,255,255, 15,255,239, 31,255,223, 47,255,207,
		63,255,191, 79,255,175, 95,255,159, 111,255,143, 127,255,127,
		143,255,111, 159,255,95, 175,255,79, 191,255,63, 207,255,47,
		223,255,31, 239,255,15, 255,255,0, 255,239,0, 255,223,0,
		255,207,0, 255,191,0, 255,175,0, 255,159,0, 255,143,0,
		255,127,0, 255,111,0, 255,95,0, 255,79,0, 255,63,0,
		255,47,0, 255,31,0, 255,15,0, 255,0,0, 239,0,0, 223,0,0,
		207,0,0, 191,0,0, 175,0,0, 159,0,0, 143,0,0, 127,0,0 };

   int i,j,k;

    glClearColor(0.0 ,0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);

    glPointSize(1.0);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glEnable(GL_BLEND);
    glDepthMask(GL_FALSE);

    glColor3f(1.0f,1.0f,1.0f);

		Start(0);
		int burst;

		float omega = 2.0*M_PI*FREQUENCY;
		cl_float4 src0 = (cl_float4){0.0f,0.0f,omega,0.0f};
      cl_float4 src1 = (cl_float4){0.0f,1.0f,omega,0.0f};

		for(burst = 0; burst < __nburst; burst++ ) {

      	float t = __t0 + __dt*(float)(__step+burst);
			cl_float4_x(src1) = t;

			clarg_set(stdgpu,k_hcomp,0,src0);
			clfork(stdgpu,devnum,k_hcomp,p_ndr4,CL_EVENT_NOWAIT);

			clarg_set(stdgpu,k_ecomp,0,src1);	
			clfork(stdgpu,devnum,k_ecomp,p_ndr4,CL_EVENT_NOWAIT);

		}
		clwait(stdgpu,devnum,CL_KERNEL_EVENT);
		Stop(0);
		double time = GetElapsedTime(0);
		gflops = __gflops(time,__nburst,__nxyz);
		Reset(0);

		__step += __nburst;

		int offset = 0;
   	clarg_set(stdgpu,k_slice,4,offset);
   	clarg_set_global(stdgpu,k_slice,6,s_sss);
		clfork(stdgpu,devnum,k_slice,p_ndr_slice,CL_EVENT_NOWAIT);
		clmsync(stdgpu,devnum,slice,CL_MEM_HOST);
		clwait(stdgpu,devnum,CL_KERNEL_EVENT|CL_MEM_EVENT);

//	for(i=0;i<__nx;i++) printf("%f ",slice[4*i*__ny+0]);
//	printf("\n");

		int nxy = __nx*__ny;
		float pmax0 = slice[0], pmin0 = slice[0];
		float pmax1 = slice[1], pmin1 = slice[1];
		float pmax2 = slice[2], pmin2 = slice[2];
		float pmax3 = slice[3], pmin3 = slice[3];
		for(i=0;i<nxy*4; i+=4) {
			pmax0 = max(pmax0,slice[i]);
			pmax1 = max(pmax1,slice[i+1]);
			pmax2 = max(pmax2,slice[i+2]);
			pmax3 = max(pmax3,slice[i+3]);
		}

int zoom2 = 2;
int zoom4 = 4;

		float* pf = slice;
   	unsigned char* p0 = bmp_slice;
   	unsigned char* p1 = bmp_slice+nxy*3*16;
   	unsigned char* p2 = bmp_slice+nxy*6*16;
   	unsigned char* p3 = bmp_slice+nxy*9*16;
   	for(int i=0; i<__nx; i++) {
			for(k=0;k<zoom4;k++) {
				float* pf2 = pf;
   			for(int j=0; j<__ny; j++) {
      			float tmp0 = (*(pf2));
      			float tmp1 = (*(pf2+1));
      			float tmp2 = (*(pf2+2));
      			float tmp3 = (*(pf2+3));
					pf2+=4;
//					unsigned char ctmp = 3*(unsigned char)(tmp0*63.0);
					unsigned char ctmp = 3*(unsigned char)(tmp0*192.0);
					for(int l=0;l<zoom4;l++) {
      				*(p0++) = (unsigned char)(int)jet_colormap[ctmp+2];
      				*(p0++) = (unsigned char)(int)jet_colormap[ctmp+1];
      				*(p0++) = (unsigned char)(int)jet_colormap[ctmp+0];
					}
   			}
			}
			pf += __ny*4;
		}

   char text[80];

   snprintf(text,80,"%s %f GFLOPS",devstr,gflops);

   glRasterPos2i(0,0);

   glPushMatrix();
   glLoadIdentity();
   gluOrtho2D(0,1,0,1);
   glRasterPos2f(0,1.0-15.0/(float)screen_height);
   for(i=0;i<strnlen(text,80);i++)
      glutBitmapCharacter(GLUT_BITMAP_8_BY_13,text[i]);
   glRasterPos2f(1.0-112.0/(float)screen_width,0);
   glDrawPixels(112,48,GL_BGR,GL_UNSIGNED_BYTE,bmp);

   glRasterPos2f(
		0.5-(float)(zoom2*__ny)/(float)screen_width,
		0.5-(float)(zoom2*__nx)/(float)screen_height
	);
   glDrawPixels(zoom4*__nx,zoom4*__ny,GL_BGR,GL_UNSIGNED_BYTE,bmp_slice);


   glPopMatrix();

	if (__step >= __nstep) {
		__step = 0;

		int nxyz4 = __nxyz/4;
		bzero(s_hxyz,3*sizeof(cl_float4)*nxyz4);
		bzero(s_sss,3*sizeof(cl_float4)*nxyz4);

		clmsync(stdgpu,devnum,s_hxyz,CL_MEM_DEVICE|CL_EVENT_NOWAIT);
		clmsync(stdgpu,devnum,s_sss,CL_MEM_DEVICE|CL_EVENT_NOWAIT);

		clwait(stdgpu,devnum,CL_MEM_EVENT);
	}

    glFlush();
    glutSwapBuffers();
}



void
keyboardFunc(unsigned char key, int x, int y)
{
   switch(key) {

      case 'q':
      case 'Q':
         // nbody_cleanup();
         exit(0);

        default:
            break;
    }
}

