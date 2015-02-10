
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "coprthr.h"
#include "test.h"

#define SIZE 256

char src_add[] = \
	"__kernel void\n" \
	"my_kern( float* a, float* b, float* c) {\n" \
	"	int gtid = get_global_id(0);\n" \
	"	c[gtid] = a[gtid]+b[gtid];\n" \
	"}\n";

char src_sub[] = \
	"__kernel void\n" \
	"my_kern( float* a, float* b, float* c) {\n" \
	"	int gtid = get_global_id(0);\n" \
	"	c[gtid] = a[gtid]-b[gtid];\n" \
	"}\n";

int main()
{
	int i;

	int dd = coprthr_dopen(TEST_COPRTHR_DEVICE,COPRTHR_O_STREAM);

	printf("dd=%d\n",dd);

	coprthr_program_t prg_add 
		= coprthr_dcompile(dd,src_add,sizeof(src_add),0,0);
	coprthr_kernel_t krn_add = coprthr_getsym(prg_add,"my_kern");

	coprthr_program_t prg_sub 
		= coprthr_dcompile(dd,src_sub,sizeof(src_sub),0,0);
	coprthr_kernel_t krn_sub = coprthr_getsym(prg_sub,"my_kern");

	printf("prg_add=%p krn_add=%p\n",prg_add,krn_add);
	printf("prg_sub=%p krn_sub=%p\n",prg_sub,krn_sub);

	size_t size = SIZE;
	size_t size2 = SIZE/2;

	float* a = (float*)malloc(size*sizeof(float));
	float* b = (float*)malloc(size*sizeof(float));
	float* c = (float*)malloc(size*sizeof(float));

	for(i=0; i<SIZE; i++) {
		a[i] = 1.0f * i;
		b[i] = 2.0f * i;
		c[i] = 0.0f;
	}
	
	coprthr_mem_t mema1 = coprthr_dmalloc(dd,size2*sizeof(float),0);
	coprthr_mem_t memb1 = coprthr_dmalloc(dd,size2*sizeof(float),0);
	coprthr_mem_t memc1 = coprthr_dmalloc(dd,size2*sizeof(float),0);

	coprthr_mem_t mema2 = coprthr_dmalloc(dd,size2*sizeof(float),0);
	coprthr_mem_t memb2 = coprthr_dmalloc(dd,size2*sizeof(float),0);
	coprthr_mem_t memc2 = coprthr_dmalloc(dd,size2*sizeof(float),0);

	coprthr_dwrite(dd,mema1,0,a,size2*sizeof(float),COPRTHR_E_WAIT);
	coprthr_dwrite(dd,memb1,0,b,size2*sizeof(float),COPRTHR_E_WAIT);
	coprthr_dwrite(dd,memc1,0,c,size2*sizeof(float),COPRTHR_E_WAIT);

	coprthr_dwrite(dd,mema2,0,a+size2,size2*sizeof(float),COPRTHR_E_WAIT);
	coprthr_dwrite(dd,memb2,0,b+size2,size2*sizeof(float),COPRTHR_E_WAIT);
	coprthr_dwrite(dd,memc2,0,c+size2,size2*sizeof(float),COPRTHR_E_WAIT);

	unsigned int nargs = 3;
	void* args_add[] = { &mema1, &memb1, &memc1 };
	void* args_sub[] = { &mema2, &memb2, &memc2 };
	unsigned int nthr = size2;

	coprthr_kernel_t v_krn[] = { krn_add, krn_sub };
	unsigned int v_nargs[] = { nargs, nargs };
	void** v_args[] = { args_add, args_sub };
	unsigned int v_nthr[] = { nthr, nthr };

	coprthr_dnexec(dd,2,v_krn,v_nargs,v_args,v_nthr,0,COPRTHR_E_WAIT);

	coprthr_dread(dd,memc1,0,c,size2*sizeof(float),COPRTHR_E_WAIT);
	coprthr_dread(dd,memc2,0,c+size2,size2*sizeof(float),COPRTHR_E_WAIT);

	for(i=0; i<SIZE; i++) 
		printf("%f + %f = %f\n",a[i],b[i],c[i]);

	coprthr_dfree(dd,mema1);	
	coprthr_dfree(dd,memb1);	
	coprthr_dfree(dd,memc1);	

	coprthr_dfree(dd,mema2);	
	coprthr_dfree(dd,memb2);	
	coprthr_dfree(dd,memc2);	

	free(a);
	free(b);
	free(c);

	coprthr_dclose(dd);
}

