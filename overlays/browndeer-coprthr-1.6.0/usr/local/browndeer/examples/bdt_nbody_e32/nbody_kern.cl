
#include <stdcl.h>

__kernel void
copy_kern(
	int n,
	__global float4* b,
	__global float4* a
)
{
	int gti = get_global_id(0);

		b[gti] = a[gti];

}

__kernel void
nbody_kern(
	int n,
	float dt,
	float eps,
	__global float4* pp,
	__global float4* vv,
	__global float4* ppo
)
{
	const float4 zero4 = __builtin_vector_float4(0.0f,0.0f,0.0f,0.0f);
	const float4 invtwo4 = __builtin_vector_float4(0.5f,0.5f,0.5f,0.5f);
	const float4 dt4 = __builtin_vector_float4(dt,dt,dt,0.0f);

	int gti = 2*get_global_id(0);

	int ti = get_local_id(0);

	float4 p0 = ppo[gti+0];
	float4 p1 = ppo[gti+1];

	float4 a0 = zero4;
	float4 a1 = zero4;

	int i;

	n *= 2;

	for(i=0;i<n;i++) {

		// loop within block accumulating acceleration of particles 

			float4 p2 = ppo[i+0];

			float4 dp = p2 - p0;	
			float invr = rsqrt(dp.x*dp.x + dp.y*dp.y + dp.z*dp.z + eps);
			a0 += (p2.w * invr*invr*invr)*dp;
			dp = p2 - p1;
			invr = rsqrt(dp.x*dp.x + dp.y*dp.y + dp.z*dp.z + eps);
			a1 += (p2.w * invr*invr*invr)*dp;

	}

	// update position and velocity

	float4 v0 = vv[gti+0];
	float4 v1 = vv[gti+1];
   p0 += dt4*v0 + invtwo4*dt4*dt4*a0;
   p1 += dt4*v1 + invtwo4*dt4*dt4*a1;
   v0 += dt4*a0;
   v1 += dt4*a1;
	pp[gti+0] = p0;
	pp[gti+1] = p1;
	vv[gti+0] = v0;
	vv[gti+1] = v1;

	return;

}



