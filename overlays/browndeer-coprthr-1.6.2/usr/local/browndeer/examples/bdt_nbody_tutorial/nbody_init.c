/* nbody_init.c */

#include <stdlib.h>

#include <stdcl.h>

#define frand() (rand()/(cl_float)RAND_MAX)

void nbody_init( int n, cl_float4* pos, cl_float4* vel )
{

   int i;

   srand(2112);

   for(i=0;i<n;i++) {
      pos[i] = (cl_float4){frand(),frand(),frand(),frand()};
      vel[i] = (cl_float4){0.0f,0.0f,0.0f,0.0f};
   }

   printf("last mass %e\n",cl_float4_w(pos[n-1]));

   printf("%e %e %e\n",cl_float4_x(pos[0]),cl_float4_y(pos[0]),cl_float4_z(pos[0]));

}

