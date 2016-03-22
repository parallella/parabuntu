
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "coprthr.h"
#include "coprthr_thread.h"
#include "test.h"

#define SIZE 256

/*
char src[] = \
	"__kernel void\n" \
	"my_kern( int* a, int* b, int* c) {\n" \
	"	int gtid = get_global_id(0);\n" \
	"	c[gtid] = a[gtid]+b[gtid];\n" \
	"}\n";
*/
char src[] = \
	"int read_h( int* p) { return p[1]; }\n" \
	"void coprthr_mutex_lock( void* p_mtx ) { while(read_h(p_mtx)); e_mutex_lock(p_mtx); }\n" \
	"void coprthr_mutex_unlock( void* p_mtx) { e_mutex_unlock(p_mtx); }\n" \
	"__kernel void\n" \
	"my_kern( int* a, int* b, int* c) {\n" \
	"	int gtid = get_global_id(0);\n" \
	"	e_mutex_t* mtx = 0x80807f90;\n" \
	"	//mtx->m = 777;\n" \
	"	//e_mutex_init(mtx,MUTEXATTR_DEFAULT);\n" \
	"	//e_mutex_lock(mtx);\n" \
	"	coprthr_mutex_lock(mtx);\n" \
	"	//e_mutex_lock(mtx);\n" \
	"	int k = c[0];\n" \
	"	k = k + gtid;\n" \
	"	c[gtid] = c[0] = k;\n" \
	"	coprthr_mutex_unlock(mtx);\n" \
	"	//e_mutex_unlock(mtx);\n" \
	"}\n";

int main()
{
	int i;

//	int dd = coprthr_dopen(COPRTHR_DEVICE_X86_64,COPRTHR_O_STREAM);
	int dd = coprthr_dopen(TEST_COPRTHR_DEVICE,COPRTHR_O_STREAM);

	printf("dd=%d\n",dd);

	coprthr_program_t prg = coprthr_compile(dd,src,sizeof(src),"",0);
	coprthr_kernel_t krn = coprthr_sym(prg,"my_kern");

	printf("prg=%p krn=%p\n",prg,krn);

	int* a = (int*)malloc(SIZE*sizeof(int));
	int* b = (int*)malloc(SIZE*sizeof(int));
	int* c = (int*)malloc(SIZE*sizeof(int));

	for(i=0; i<SIZE; i++) {
		a[i] = 1 * i;
		b[i] = 2 * i;
		c[i] = 1;
	}
	
	coprthr_mem_t mema = coprthr_dmalloc(dd,SIZE*sizeof(int),0);
	coprthr_mem_t memb = coprthr_dmalloc(dd,SIZE*sizeof(int),0);
	coprthr_mem_t memc = coprthr_dmalloc(dd,SIZE*sizeof(int),0);

	coprthr_dwrite(dd,mema,a,SIZE*sizeof(int),COPRTHR_E_NOWAIT);
	coprthr_dwrite(dd,memb,b,SIZE*sizeof(int),COPRTHR_E_NOWAIT);
	coprthr_dwrite(dd,memc,c,SIZE*sizeof(int),COPRTHR_E_NOWAIT);

	coprthr_dwait(dd);

fprintf(stderr,"dwrites completed\n"); fflush(stderr);

/* XXX test seeding a value in core local memory */
//	e_write_word( dev, 0, 32768-128, 555)

/*
	coprthr_dev_t dev = coprthr_getdev(1,0);
	coprthr_mem_t p_mtx 
		= coprthr_devmemalloc(dev,0,1,0,COPRTHR_DEVMEM_TYPE_MUTEX);
	printf( "p_mtx=%p (%ld)\n",p_mtx);
	printf( "(size %ld)\n",coprthr_devmemsize(p_mtx));
*/
        coprthr_mutex_attr_t mtxattr;
        coprthr_mutex_attr_init(&mtxattr);
        coprthr_mutex_attr_setdevice(&mtxattr,dd);

        coprthr_mutex_t mtx,mtx2,mtx3;
        __check( coprthr_mutex_init(&mtx,&mtxattr) );
        __check( coprthr_mutex_init(&mtx2,&mtxattr) );
        __check( coprthr_mutex_init(&mtx3,&mtxattr) );

        __check( coprthr_mutex_attr_destroy(&mtxattr) );


	fprintf(stderr,"host acquires lock...\n"); fflush(stderr);
	coprthr_mutex_lock(&mtx);
	fprintf(stderr,"host has lock\n"); fflush(stderr);

	unsigned int nargs = 3;
	void* args[] = { &mema, &memb, &memc };
	unsigned int nthr = SIZE;

	coprthr_dexec(dd,krn,nargs,args,nthr,COPRTHR_E_NOWAIT);

//	coprthr_dcopy(dd,memc,memb,SIZE*sizeof(int),COPRTHR_E_WAIT);
//
//	coprthr_kernel_t v_krn[] = { krn, krn };
//	unsigned int v_nargs[] = { nargs, nargs };
//	void** v_args[] = { args, args };
//	unsigned int v_nthr[] = { nthr, nthr };
//
//	coprthr_dnexec(dd,1,v_krn,v_nargs,v_args,v_nthr,COPRTHR_E_WAIT);

	fprintf(stderr,"sleep for 3 sec ...\n");

	sleep(3);

	for(i=0; i<SIZE; i++) { c[i] = 1000; }
	coprthr_dwrite(dd,memc,c,SIZE*sizeof(int),COPRTHR_E_NOW);
	
	fprintf(stderr,"host releasing lock...\n"); fflush(stderr);
	coprthr_mutex_unlock(&mtx);
	fprintf(stderr,"host has released lock\n"); fflush(stderr);

	coprthr_dwait(dd);

	coprthr_dread(dd,memc,c,SIZE*sizeof(int),COPRTHR_E_NOWAIT);

	coprthr_dwait(dd);

	for(i=0; i<SIZE; i++) 
		printf("%d + %d = %d\n",a[i],b[i],c[i]);

//	coprthr_dev_t dev = coprthr_getdev(1,0);
//	coprthr_mem_t p_mtx 
//		= coprthr_devmemalloc(dev,0,1,0,COPRTHR_DEVMEM_TYPE_MUTEX);
//	printf( "p_mtx=%p (%ld)\n",p_mtx);
//	printf( "(size %ld)\n",coprthr_devmemsize(p_mtx));

//        __check( coprthr_mutex_destroy(&mtx) );

	coprthr_dfree(dd,mema);	
	coprthr_dfree(dd,memb);	
	coprthr_dfree(dd,memc);	

	free(a);
	free(b);
	free(c);

	coprthr_dclose(dd);
}

