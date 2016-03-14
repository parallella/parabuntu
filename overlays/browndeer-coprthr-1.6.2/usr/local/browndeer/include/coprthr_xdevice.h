
#ifndef _coprthr_xdevice_h
#define _coprthr_xdevice_h

//#if defined(__coprthr_device__)

//#if defined(__x86_64__)
//#warning __x86_64__ defined
//#elif defined(__i386__)
//#warning __i386__ defined
//#elif defined(__arm__)
//#warning __arm__ defined
//#elif defined(__epiphany__)
//#warning __epiphany__ defined
//#else
//#error no supported architecture 
//#endif

#if defined(__x86_64__) || defined(__i386__) || defined(__arm__) 

#include <pthread.h>

inline 
void coprthr_mutex_lock( void* p_mtx )
{ pthread_mutex_lock((pthread_mutex_t*)p_mtx); }

inline
void coprthr_mutex_unlock( void* p_mtx)
{ pthread_mutex_unlock((pthread_mutex_t*)p_mtx); }

#elif defined(__epiphany__)

#ifdef __cplusplus
extern "C" {
#endif
#include <e-lib.h>
#ifdef __cplusplus
}
#endif

#warning __epiphany__ defined

int __attribute__((noinline)) readi( int* p) { return p[0]; }

int __attribute__((noinline)) read_h( int* p) { return p[1]; }

void coprthr_mutex_lock( void* p_mtx ) 
{ while(read_h(p_mtx)); e_mutex_lock( 0,0, p_mtx); }

void coprthr_mutex_unlock( void* p_mtx) 
{ e_mutex_unlock(0,0,p_mtx); }

#else

#error no supported architecture 

#endif

#define coprthr_get_thread_index() get_global_id(0)

//#endif

#endif

