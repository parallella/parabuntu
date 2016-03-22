/* nbody_output.c */

#include <stdio.h>
#include <stdcl.h>

//#define cl_float4_x(f) (((cl_float*)&(f))[0])

void nbody_output( int n, cl_float4* pos, cl_float4* vel )
{

   int i;

   cl_float4 center = (cl_float4){0.0f,0.0f,0.0f,0.0f};

   for(i=0;i<n;i++) {

      cl_float4_x(center) += cl_float4_x(pos[i]);
      cl_float4_y(center) += cl_float4_y(pos[i]);
      cl_float4_z(center) += cl_float4_z(pos[i]);
      cl_float4_w(center) += cl_float4_w(pos[i]);

//printf("%d: {%e,%e,%e}\n",
//      i,cl_float4_x(pos[i]),cl_float4_y(pos[i]),cl_float4_z(pos[i]) );

   }

   cl_float4_x(center) /= n;
   cl_float4_y(center) /= n;
   cl_float4_z(center) /= n;
   cl_float4_w(center) /= n;

   printf("center => {%e,%e,%e}\n",
      cl_float4_x(center),cl_float4_y(center),cl_float4_z(center) );



}

