
#include <stdio.h>

int main()
{
	int sum = 0;
	int a,b,A,B,N;

	N = 128;
	A = 1;
	B = 1;

	for(a=0;a<A;a++)
	for(b=0;b<B;b++)
	sum += (b+1)*( N*(N-1)/2 + 14*a*N );

	printf(" %d %d %d\n",A,B,sum);

}

