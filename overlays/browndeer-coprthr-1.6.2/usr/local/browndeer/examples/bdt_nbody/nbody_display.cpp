/* nbody_display.cpp
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
#include <unistd.h>

#include<GL/glut.h>

#ifdef ENABLE_CL
#include "stdcl.h"
#endif

#include "Timer.h"

#include "nbody.h"


void iterate_cpu(
   int nburst, int nparticle, int dummy,
   float gdt, float es,
   float* pp, float* vv
);

#ifdef ENABLE_CL
void iterate_cpu_cl(
   int nburst, int nparticle, int nthread,
   float gdt, float es,
   float* pp, float* vv
);
#endif


extern char* cldevstr;
extern int nstep;
extern int nburst;
extern int step_count;
extern float gflops;

int screen_width;
int screen_height;
unsigned char* bmp = 0;
char devstr[64];
int display_step = 0;


/* 
 * OpenGL display functions
 */

extern char _binary_bdt_bmp_start[];

void display_init() 
{
	int i;
    glClearColor(0.0 ,0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

	unsigned char header[54];
	memcpy(header,_binary_bdt_bmp_start,54);
	if(header[0]=='B' && header[1]=='M') {
		int offset = *(unsigned int*)(header+10);
		int w = *(int*)(header+18);
		int h = *(int*)(header+22);
		int b = (int)header[28];
		bmp = (unsigned char*)malloc(w*h*3);
		memcpy(bmp,_binary_bdt_bmp_start+offset,w*h*3);
	}

//	FILE* fp = fopen("bdt.bmp","rb");
//	unsigned char header[54];
//	fread(header,54,1,fp);
//	if(header[0]=='B' && header[1]=='M') {
//		int offset = *(unsigned int*)(header+10);
//		int w = *(int*)(header+18);
//		int h = *(int*)(header+22);
//		int b = (int)header[28];
//		bmp = (unsigned char*)malloc(w*h*3);
//		fseek(fp,offset,SEEK_SET);
//		fread(bmp,w*h*3,1,fp);
//		fclose(fp);
//	}


	if (iterate==iterate_cpu) { 
		strncpy(devstr,"CPU",64);
	} else if (iterate==iterate_cl) {
		if (cldevstr) strncpy(devstr,cldevstr,64);
	}


}

void idle()
{ glutPostRedisplay(); }


void reShape(int w,int h)
{
	screen_width = w;
	screen_height = h;
    glViewport(0,0,w,h);
    glViewport(0,0,w,h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluPerspective(45.0f,w/h,1.0f,1000.0f);
    gluLookAt (0.0, 0.0, -2.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0);
}


void displayfunc()
{
	int i;

    glClearColor(0.0 ,0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);

    glPointSize(1.0);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glEnable(GL_BLEND);
    glDepthMask(GL_FALSE);

    glColor3f(1.0f,1.0f,1.0f);


	int nparticle = iterate_args.nparticle;
	float* pos = (float*)iterate_args.pp;


    //Calling kernel for calculatig subsequent positions

	
	if (iterate) iterate(
		iterate_args.nburst,
		iterate_args.nparticle,
		iterate_args.nthread,
		iterate_args.gdt,
		iterate_args.es,
		iterate_args.pp,
		iterate_args.vv
	);


    glBegin(GL_POINTS);
    for(i=0; i < nparticle; ++i) {
        glVertex3d(
			ZOOM*pos[__index_x(i)],
			ZOOM*pos[__index_y(i)],
			ZOOM*pos[__index_z(i)]
			);
    }
    glEnd();

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
	glPopMatrix();

    glFlush();
    glutSwapBuffers();

	display_step += nburst;

	if (nstep > 0 && display_step >= nstep) {

		float tmp = 0.0f;
    	for(i=0; i < nparticle; ++i) {
			tmp += pos[__index_x(i)]*pos[__index_x(i)];
			tmp += pos[__index_y(i)]*pos[__index_y(i)];
			tmp += pos[__index_z(i)]*pos[__index_z(i)];
		}

		printf("[%d] checksum=%e\n",getpid(),tmp);

		exit(0);

	}

}

void
keyboardFunc(unsigned char key, int x, int y)
{
	switch(key) {

		case 'c':
			iterate = iterate_cpu;
			strncpy(devstr,"CPU",64);
			step_count = 0;
			gflops = 0.0;
			break;

#ifdef ENABLE_CL
		case 'C':
			iterate = iterate_cl;
			strncpy(devstr,cldevstr,64);
			step_count = 0;
			gflops = 0.0;
			break;
#endif

		case 'q':
		case 'Q':
			// nbody_cleanup();
			exit(0);
			
        default:
            break;
    }
}


