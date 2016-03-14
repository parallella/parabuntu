
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "coprthr.h"
#include "test.h"

#define SIZE 16

char src[] = \
	"__kernel void\n" \
	"my_kern( float* a, float* b, float* c) {\n" \
	"	int gtid = get_global_id(0);\n" \
	"	c[gtid] = a[gtid]+b[gtid];\n" \
	"}\n";

int main()
{
	int i;

	int dd = coprthr_dopen(TEST_COPRTHR_DEVICE,COPRTHR_O_STREAM);

	printf("dd=%d\n",dd);

	coprthr_program_t prg = coprthr_dcompile(dd,src,sizeof(src),"",0);
	coprthr_kernel_t krn = coprthr_getsym(prg,"my_kern");

	printf("prg=%p krn=%p\n",prg,krn);

	float* a = (float*)malloc(SIZE*sizeof(float));
	float* b = (float*)malloc(SIZE*sizeof(float));
	float* c = (float*)malloc(SIZE*sizeof(float));

	for(i=0; i<SIZE; i++) {
		a[i] = 1.0f * i;
		b[i] = 2.0f * i;
		c[i] = 0.0f;
	}
	
	coprthr_mem_t mema = coprthr_dmalloc(dd,SIZE*sizeof(float),0);
	coprthr_mem_t memb = coprthr_dmalloc(dd,SIZE*sizeof(float),0);
	coprthr_mem_t memc = coprthr_dmalloc(dd,SIZE*sizeof(float),0);

	coprthr_dwrite(dd,mema,0,a,SIZE*sizeof(float),COPRTHR_E_WAIT);
	coprthr_dwrite(dd,memb,0,b,SIZE*sizeof(float),COPRTHR_E_WAIT);
	coprthr_dwrite(dd,memc,0,c,SIZE*sizeof(float),COPRTHR_E_WAIT);

	unsigned int nargs = 3;
	void* args[] = { &mema, &memb, &memc };
	unsigned int nthr = SIZE;

	coprthr_dexec(dd,krn,nargs,args,nthr,0,COPRTHR_E_WAIT);

	coprthr_dcopy(dd,memc,0,memb,0,SIZE*sizeof(float),COPRTHR_E_WAIT);

	coprthr_dread(dd,memc,0,c,SIZE*sizeof(float),COPRTHR_E_WAIT);

	for(i=0; i<SIZE; i++) 
		printf("%f + %f = %f\n",a[i],b[i],c[i]);

	coprthr_dfree(dd,mema);	
	coprthr_dfree(dd,memb);	
	coprthr_dfree(dd,memc);	

	free(a);
	free(b);
	free(c);

	coprthr_dclose(dd);
}

