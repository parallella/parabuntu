
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <CL/cl.h>

#include "nbody.h"

#define frand() (rand()/(cl_float)RAND_MAX)

int nbody_init( int n, cl_float* pp, cl_float* vv )
{
	int i;

	printf("nbody_init %d\n",n); fflush(stdout);

	cl_float a1,a2,a3,a4,a5,a6,a7,a8;
	cl_float cmr[3];
	cl_float cmrdot[3];

	cl_float alphas = 2.0;
	cl_float body1 = 5.0;
	cl_float bodyn = 1.0;

	cl_float twopi = 6.283185307;

	cl_float alpha1 = alphas - 1.0;
	cl_float fm1 = 1.0/pow(body1,alpha1);
	cl_float fmn = (fm1 - 1.0/pow(bodyn,alpha1))/((cl_float)n - 1.0);
	cl_float zmass = 0.0;
	cl_float coef = 1.0/alpha1;

	for(i=0;i<n;i++) {
		cl_float fmi = fm1 - (cl_float)(i-1)*fmn;
		pp[__index_m(i)] = 1.0/pow(fmi,coef);
		zmass += pp[__index_m(i)];
	}


	cl_float zmbar1 = zmass/(cl_float)n;
	for(i=0;i<n;i++) pp[__index_m(i)] /= zmbar1;
	zmass = (cl_float)n;

	cmr[0] = cmr[1] = cmr[2] = 0.0f;
	cmrdot[0] = cmrdot[1] = cmrdot[2] = 0.0f;

	cl_float ri;
	for(i=0;i<n;i++) {

		cl_float tmp;
		do {
			a1 = frand();
			ri = 1.0/sqrt((pow(a1,(-0.6666667))-1.0));
		} while (ri > 10.0);

		a2 = frand();
		a3 = frand();
		pp[__index_z(i)] = (1.0 - 2.0*a2)*ri;
		pp[__index_x(i)] = sqrt(ri*ri 
			- pp[__index_z(i)]*pp[__index_z(i)])*cos(twopi*a3);
		pp[__index_y(i)] = sqrt(ri*ri 
			- pp[__index_z(i)]*pp[__index_z(i)])*sin(twopi*a3);

		do {
			a4 = frand();
			a5 = frand();
			a6 = a4*a4*pow((1.0-a4*a4),3.5);
		} while (0.1*a5 > a6);

		a8 = a4*sqrt(2.0)/pow((1.0 + ri*ri),0.25);
		a6 = frand();
		a7 = frand();
	
		vv[__index_z(i)] = (1.0 - 2.0*a6)*a8;
		vv[__index_x(i)] = sqrt(a8*a8 
			- vv[__index_z(i)]*vv[__index_z(i)])*cos(twopi*a7);
		vv[__index_y(i)] = sqrt(a8*a8 
			- vv[__index_z(i)]*vv[__index_z(i)])*sin(twopi*a7);
		vv[__index_m(i)] = 0.0f;

		cmr[0] += pp[__index_m(i)] * pp[__index_x(i)];
		cmr[1] += pp[__index_m(i)] * pp[__index_y(i)];
		cmr[2] += pp[__index_m(i)] * pp[__index_z(i)];
		cmrdot[0] += pp[__index_m(i)] * pp[__index_x(i)];
		cmrdot[1] += pp[__index_m(i)] * pp[__index_y(i)];
		cmrdot[2] += pp[__index_m(i)] * pp[__index_z(i)];

	}

//printf("%f %f %f %f %f %f\n",cmr[0],cmr[1],cmr[2],cmrdot[0],cmrdot[1],cmrdot[2]);

	a1 = 1.5*twopi/16.0;
	a2 = sqrt(zmass/a1);
	for(i=0;i<n;i++) {

		pp[__index_x(i)] -= cmr[0]/zmass;
		pp[__index_y(i)] -= cmr[1]/zmass;
		pp[__index_z(i)] -= cmr[2]/zmass;
		vv[__index_x(i)] -= cmrdot[0]/zmass;
		vv[__index_y(i)] -= cmrdot[1]/zmass;
		vv[__index_z(i)] -= cmrdot[2]/zmass;
		pp[__index_x(i)] *= a1;
		pp[__index_y(i)] *= a1;
		pp[__index_z(i)] *= a1;
		vv[__index_x(i)] *= a2;
		vv[__index_y(i)] *= a2;
		vv[__index_z(i)] *= a2;
	}

//	for(i=0;i<n;i++) {
//		printf("%d %e %e %e %e %e %e\n",
//			i,pp[4*i+0],pp[4*i+1],pp[4*i+2],vv[4*i+0],vv[4*i+1],vv[4*i+2]);
//	}

	cl_float ppmin = pp[0];	
	cl_float ppmax = pp[0];	
	for(i=0;i<n;i++) ppmin = (ppmin<pp[__index_x(i)])? ppmin:pp[__index_x(i)];
	for(i=0;i<n;i++) ppmin = (ppmin<pp[__index_y(i)])? ppmin:pp[__index_y(i)];
	for(i=0;i<n;i++) ppmin = (ppmin<pp[__index_z(i)])? ppmin:pp[__index_z(i)];
	for(i=0;i<n;i++) ppmax = (ppmax>pp[__index_x(i)])? ppmax:pp[__index_x(i)];
	for(i=0;i<n;i++) ppmax = (ppmax>pp[__index_y(i)])? ppmax:pp[__index_y(i)];
	for(i=0;i<n;i++) ppmax = (ppmax>pp[__index_z(i)])? ppmax:pp[__index_z(i)];

}
