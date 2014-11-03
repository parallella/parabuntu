
#include <stdio.h>

void foo(void* (*v_args) [] ) 
{
	void*** p = (void***)v_args;
	int i;
	for(i=0;i<3;i++)
		printf("%p\n",p[0][i]); 
//	for(i=0;i<2;i++)
//		printf("%p\n",p[1][i]); 
}


int main() 
{

	float a,b,c;
	float d,e;

	void* args1[] = { &a, &b, &c };
	void* args2[] = { &d, &e };

	printf("%p %p %p %p %p\n",&a,&b,&c,&d,&e);

	void** v_args[] = { (void**)&args1, (void**)&args2 };

	void** p_args1 = (void**)&args1;
	void** p_args2 = (void**)&args2;

//	foo( v_args );
///	foo( &p_args1 );
	foo( &args1 );

     return 0;
}
