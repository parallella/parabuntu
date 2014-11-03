// clete_clvector_example.cpp

#include <iostream>
using namespace std;

#include "Timer.h"

///////////////////////////////////////////////////////////////////////////////
// #define __CLVECTOR_FULLAUTO to enable CLETE automatic GPU acceleration
// for pure SIMD operations on clvector data objects.
//
// Set the environmaent variable COPRTHR_LOG_AUTOKERN to see the automatically
// generated OpenCL kernels used to execute the computation on GPU.
//
// With the #define commented out standard expression-templating is used
// to efficiently execute the computation on the CPU.
//////////////////////////////////////////////////////////////////////////////

#include <stdcl.h>
#define __CLVECTOR_FULLAUTO
#include <clvector.h>

int main()
{
	Setup(0);
	Reset(0);

	int n = 1048576;

	clvector<float> a,b,c,d,e;

	for (int i=0; i<n; ++i) {
		a.push_back(1.1f*i);
		b.push_back(2.2f*i);
		c.push_back(3.3f*i);
		d.push_back(1.0f*i);
		e.push_back(0.0f);
	}

	Start(0);
	for(int iter=0; iter<10; iter++) {
		e = a + b + 2112.0f * b + sqrt(d) - a*b*c*d + c*sqrt(a) + a*cos(c);
		a = a + log(fabs(e));
	}
	Stop(0);
	double t = GetElapsedTime(0);

	for (int i=n-10; i<n; ++i) {
		cout << " a(" << i << ") = " << a[i]
				<< " b(" << i << ") = " << b[i]
				<< " c(" << i << ") = " << c[i]
				<< " d(" << i << ") = " << d[i]
				<< " e(" << i << ") = " << e[i]
				<< endl;
	}

	printf("compute time %f (sec)\n",t);
	
}

