
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "coprthr.h"
#include "test.h"

#define SIZE 256

char src[] = \
	"__kernel void\n" \
	"my_kern( int* a, int* b, int* c, int* d) {\n" \
	"	int gtid = get_global_id(0);\n" \
	"	int go = 0;\n" \
	"	do {\n" \
	"		go = d[gtid];\n" \
	"	} while(go==0);\n" \
	"	c[gtid] = a[gtid]+b[gtid];\n" \
	"}\n";

int main()
{
	int i;

	int dd = coprthr_dopen(COPRTHR_DEVICE_X86_64,COPRTHR_O_STREAM);

	printf("dd=%d\n",dd);

	coprthr_program_t prg = coprthr_dcompile(dd,src,sizeof(src),"",0);
	coprthr_kernel_t krn = coprthr_getsym(prg,"my_kern");

	printf("prg=%p krn=%p\n",prg,krn);

	int* a = (int*)malloc(SIZE*sizeof(int));
	int* b = (int*)malloc(SIZE*sizeof(int));
	int* c = (int*)malloc(SIZE*sizeof(int));
	int* d = (int*)malloc(SIZE*sizeof(int));

	for(i=0; i<SIZE; i++) {
		a[i] = 1 * i;
		b[i] = 2 * i;
		c[i] = 0;
		d[i] = 0;
	}
	
	coprthr_mem_t mema = coprthr_dmalloc(dd,SIZE*sizeof(int),0);
	coprthr_mem_t memb = coprthr_dmalloc(dd,SIZE*sizeof(int),0);
	coprthr_mem_t memc = coprthr_dmalloc(dd,SIZE*sizeof(int),0);
	coprthr_mem_t memd = coprthr_dmalloc(dd,SIZE*sizeof(int),0);

	coprthr_event_t ev[10];

	ev[0] = coprthr_dwrite(dd,mema,0,a,SIZE*sizeof(float),COPRTHR_E_NOWAIT);
	ev[1] = coprthr_dwrite(dd,memb,0,b,SIZE*sizeof(float),COPRTHR_E_NOWAIT);
	ev[2] = coprthr_dwrite(dd,memc,0,c,SIZE*sizeof(float),COPRTHR_E_NOWAIT);
	ev[3] = coprthr_dwrite(dd,memd,0,d,SIZE*sizeof(float),COPRTHR_E_NOWAIT);

	for(i=0;i<4;i++) 
		coprthr_dwaitev(dd,ev[i]);

	unsigned int nargs = 4;
	void* args[] = { &mema, &memb, &memc, &memd };
	unsigned int nthr = SIZE;

	ev[4] = coprthr_dexec(dd,krn,nargs,args,nthr,0,COPRTHR_E_NOWAIT);

	ev[5] = coprthr_dread(dd,memc,0,c,SIZE*sizeof(float),COPRTHR_E_NOWAIT);

	for(i=0; i<SIZE; i++) d[i] = 1;
	coprthr_dwrite(dd,memd,0,d,SIZE*sizeof(float),COPRTHR_E_NOW);

	for(i=4;i<6;i++) 
		coprthr_dwaitev(dd,ev[i]);

	for(i=0; i<SIZE; i++) 
		printf("%d + %d = %d\n",a[i],b[i],c[i]);

	coprthr_dfree(dd,mema);	
	coprthr_dfree(dd,memb);	
	coprthr_dfree(dd,memc);	

	free(a);
	free(b);
	free(c);

	coprthr_dclose(dd);
}

