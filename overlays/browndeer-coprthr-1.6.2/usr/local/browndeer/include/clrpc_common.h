
#ifndef _CLRPC_COMMON_H
#define _CLRPC_COMMON_H

#ifdef WIN32
#include <winsock2.h>
#include <windows.h>
#else
#include <sys/socket.h>
#include <signal.h>
#include <unistd.h>
#include <netdb.h>
#endif

#include <sys/queue.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "event2/event-config.h"
#include "event2/buffer.h"
#include "event2/event.h"
#include "event2/event_compat.h"
#include "event2/http.h"
#include "event2/http_compat.h"
#include "event2/http_struct.h"
#include "event2/rpc.h"
#include "event2/rpc.h"
#include "event2/rpc_struct.h"
#include "event2/tag.h"
#include "event2/thread.h"
#include "event2/bufferevent.h"

#include "printcl.h"

typedef int64_t clrpc_int;
typedef int64_t clrpc_int64;
typedef uint64_t clrpc_uint;
typedef uint64_t clrpc_uint64;
typedef uint64_t clrpc_bool;

typedef uint64_t clrpc_ptr;
typedef struct { clrpc_ptr local, remote; } clrpc_dptr;

typedef clrpc_dptr _clrpc_platform_id;
typedef struct _dummy_platform_id* clrpc_platform_id;

typedef int64_t clrpc_device_type;

typedef int64_t clrpc_platform_info;
typedef int64_t clrpc_device_info;
typedef int64_t clrpc_context_info;
typedef int64_t clrpc_command_queue_info;
typedef int64_t clrpc_mem_info;
typedef int64_t clrpc_event_info;
typedef int64_t clrpc_profiling_info;
typedef int64_t clrpc_program_info;
typedef int64_t clrpc_program_build_info;
typedef int64_t clrpc_kernel_info;

typedef clrpc_dptr _clrpc_device_id;
typedef struct _dummy_device_id* clrpc_device_id;

typedef clrpc_dptr _clrpc_context;
typedef struct _dummy_context* clrpc_context;

typedef clrpc_dptr _clrpc_command_queue;
typedef struct _dummy_command_queue* clrpc_command_queue;

typedef int64_t clrpc_command_queue_properties;
typedef int64_t clrpc_mem_flags;
typedef int64_t clrpc_map_flags;

typedef clrpc_dptr _clrpc_event;
typedef struct _dummy_event* clrpc_event;

typedef clrpc_dptr _clrpc_program;
typedef struct _dummy_program* clrpc_program;

typedef clrpc_dptr _clrpc_kernel;
typedef struct _dummy_kernel* clrpc_kernel;


typedef struct {
   const char* address;
   ev_uint16_t port;
} clrpc_server_info;


extern evutil_socket_t pair[2];
extern struct event_base *global_base;

//int get_socket_port(evutil_socket_t fd);

//struct evconnlistener;
//struct sockaddr;
//int get_listener_addr(struct evconnlistener *lev,
//    struct sockaddr *sa, ev_socklen_t *socklen);

//struct evrpc_pool*
//rpc_pool_with_connection(const char* address, ev_uint16_t port);


#define CLRPC_HEADER(fname) EVRPC_HEADER(_clrpc_##fname, \
	_clrpc_##fname##_request, _clrpc_##fname##_reply)

#define CLRPC_GENERATE(fname) EVRPC_GENERATE(_clrpc_##fname, \
	_clrpc_##fname##_request,_clrpc_##fname##_reply)

#define CLRPC_REGISTER(fname) EVRPC_REGISTER(base,_clrpc_##fname, \
	_clrpc_##fname##_request,_clrpc_##fname##_reply,_clrpc_##fname##_svrcb,0)

#define CLRPC_MAKE_REQUEST_NOWAIT(fname, request, reply)  do { \
	EVRPC_MAKE_REQUEST(_clrpc_##fname, \
		clrpc_pool, request, reply, _clrpc_##fname##_clicb, 0 ); \
	} while(0)

#define CLRPC_MAKE_REQUEST_WAIT(fname)  do { \
	struct cb_struct cbarg; \
	pthread_mutex_init(&cbarg.mtx,0); \
	pthread_cond_init(&cbarg.sig,0); \
	EVRPC_MAKE_REQUEST(_clrpc_##fname, \
		clrpc_pool, request, reply, _clrpc_##fname##_clicb, &cbarg ); \
	printcl( CL_DEBUG "CLRPC_MAKE_REQUEST: waiting ..."); \
	pthread_cond_wait(&cbarg.sig,&cbarg.mtx); \
	printcl( CL_DEBUG "CLRPC_MAKE_REQUEST: ... done waiting"); \
	pthread_mutex_destroy(&cbarg.mtx); \
	pthread_cond_destroy(&cbarg.sig); \
	} while(0);

#define CLRPC_MAKE_REQUEST_WAIT2(pool,fname)  do { \
	struct cb_struct cbarg; \
	pthread_mutex_init(&cbarg.mtx,0); \
   pthread_mutex_lock(&cbarg.mtx); \
	pthread_cond_init(&cbarg.sig,0); \
	clrpc_err = EVRPC_MAKE_REQUEST(_clrpc_##fname, \
		pool, request, reply, _clrpc_##fname##_clicb, &cbarg ); \
	if (clrpc_err) { \
		printcl( CL_ERR "CLRPC_MAKE_REQUEST: make request failed"); \
	} else { \
		printcl( CL_DEBUG "CLRPC_MAKE_REQUEST: waiting ..."); \
		pthread_cond_wait(&cbarg.sig,&cbarg.mtx); \
		printcl( CL_DEBUG "CLRPC_MAKE_REQUEST: ... done waiting"); \
		pthread_mutex_destroy(&cbarg.mtx); \
		pthread_cond_destroy(&cbarg.sig); \
		clrpc_err = cbarg.err; \
		if (clrpc_err) \
			printcl( CL_ERR "CLRPC_MAKE_REQUEST: error"); \
	} \
	} while(0);

#define CLRPC_INIT(fname) \
	int clrpc_err = 0; \
	struct _clrpc_##fname##_request* request = _clrpc_##fname##_request_new();\
	struct _clrpc_##fname##_reply* reply = _clrpc_##fname##_reply_new(); \
	do {} while(0)

#define CLRPC_FINAL(fname) \
	_clrpc_##fname##_request_free(request); \
	_clrpc_##fname##_reply_free(reply); \
	do {} while(0)

#define CLRPC_SVRCB_INIT(fname) \
	struct _clrpc_##fname##_request* request = rpc->request; \
	struct _clrpc_##fname##_reply* reply = rpc->reply; \
	do {} while(0)


#define CLRPC_ASSIGN(msg,basetype,mbr,val) do { \
	EVTAG_ASSIGN(msg, mbr, (clrpc_##basetype)val); \
	} while(0)

#define CLRPC_GET(msg,basetype,mbr,pval) do { \
	clrpc_##basetype tmp; \
	EVTAG_GET(msg,mbr,(void*)&tmp); \
	*pval = (cl_##basetype)tmp; \
	} while(0)

#define CLRPC_ASSIGN_WITH_LEN(msg,mbr,pval,len) do { \
	if (len) EVTAG_ASSIGN_WITH_LEN(msg,mbr,pval,len); \
	} while(0)

#define CLRPC_GET_WITH_LEN(msg,mbr,pval,plen) do { \
	EVTAG_GET_WITH_LEN(msg,mbr,(void*)pval,(void*)plen); \
	} while(0)

/* XXX this is messed up, no use of val -DAR */
#define CLRPC_ASSIGN_DPTR(msg,mbr,val) do { \
   struct dual_ptr* d; \
   EVTAG_GET(msg,mbr,&d); \
   EVTAG_ASSIGN(d,local,((clrpc_dptr*)val)->local); \
   EVTAG_ASSIGN(d,remote,((clrpc_dptr*)val)->remote); \
   } while(0)
#define CLRPC_ASSIGN_DPTR_FROM_OBJECT(msg,mbr,val) do { \
   struct dual_ptr* d; \
   EVTAG_GET(msg,mbr,&d); \
   EVTAG_ASSIGN(d,local,((_xobject_t*)val)->object->local); \
   EVTAG_ASSIGN(d,remote,((_xobject_t*)val)->object->remote); \
   } while(0)


#define CLRPC_ALLOC_DPTR_ARRAY(size,array) do { \
   int i; \
   for(i=0;i<size;i++) { \
      array[i] = (void*)calloc(1,sizeof(clrpc_dptr)); \
      ((clrpc_dptr*)array[i])->local = (clrpc_ptr)array[i]; \
      ((clrpc_dptr*)array[i])->remote = 0; \
      printcl( CL_DEBUG "dptr local [%d] = %p",i,array[i]); \
   } } while(0)

#define CLRPC_ASSIGN_DPTR_ARRAY(msg,size,array) do { \
   int i; \
   struct dual_ptr* d; \
   for(i=0;i<size;i++) { \
      d = EVTAG_ARRAY_ADD(msg, array); \
      EVTAG_ASSIGN(d,local,((clrpc_dptr*)array[i])->local); \
      EVTAG_ASSIGN(d,remote,((clrpc_dptr*)array[i])->remote); \
   } } while(0)
#define CLRPC_ASSIGN_DPTR_ARRAY_FROM_OBJECT(msg,size,mbr,array) do { \
   int i; \
   struct dual_ptr* d; \
   for(i=0;i<size;i++) { \
      d = EVTAG_ARRAY_ADD(msg, mbr); \
      EVTAG_ASSIGN(d,local,((_xobject_t*)array[i])->object->local); \
      EVTAG_ASSIGN(d,remote,((_xobject_t*)array[i])->object->remote); \
   } } while(0)

#define CLRPC_ASSIGN_DPTR_ARRAY2(msg,size,array) do { \
   int i; \
   struct dual_ptr* d; \
   for(i=0;i<size;i++) { \
      d = EVTAG_ARRAY_ADD(msg,array); \
      EVTAG_ASSIGN(d,local,(*(clrpc_dptr**)array[i])->local); \
      EVTAG_ASSIGN(d,remote,(*(clrpc_dptr**)array[i])->remote); \
   } } while(0)

#define CLRPC_GET_DPTR_ARRAY(msg,size,array) do { \
   int i; \
   struct dual_ptr* d; \
   for(i=0;i<size;i++) { \
      EVTAG_ARRAY_GET(msg, array, i, &d); \
      EVTAG_GET(d,local,&((clrpc_dptr*)array[i])->local); \
      EVTAG_GET(d,remote,&((clrpc_dptr*)array[i])->remote); \
   } } while(0)

#define CLRPC_DPTR_ARRAY_COPY(msg_src,msg_dst,size,array) do { \
	int i; \
	struct dual_ptr* d; \
	for(i=0;i<size;i++) { \
		EVTAG_ARRAY_GET(msg_src, array,i,&d); \
		clrpc_ptr local,remote; \
		EVTAG_GET(d,local,&local); \
		EVTAG_GET(d,remote,&remote); \
		d = EVTAG_ARRAY_ADD(msg_dst, array); \
		EVTAG_ASSIGN(d, local, local); \
		EVTAG_ASSIGN(d, remote, remote); \
	} } while(0);

#define CLRPC_DPTR_ARRAY_SET_LOCAL(size,array) do { \
   int i; \
   for(i=0;i<size;i++) \
      array[i].local[i] = &array[i].local[i]; \
   } while(0);

#define CLRPC_DPTR_ARRAY_SET_REMOTE(msg,size,array,vals) do { \
	int i; \
	struct dual_ptr* d; \
	for(i=0;i<size;i++) { \
		EVTAG_ARRAY_GET(msg, array,i,&d); \
		EVTAG_ASSIGN(d, remote, (clrpc_ptr)vals[i]); \
	} } while(0);

/*
#define CLRPC_GET_DPTR_REMOTE(msg,basetype,mbr,pval) do { \
	struct dual_ptr* d; \
	EVTAG_GET(msg,mbr,&d); \
	CLRPC_GET(d,basetype,remote,pval); \
	} while(0)
*/

#define CLRPC_GET_DPTR_REMOTE(msg,basetype,mbr,pval) do { \
	struct dual_ptr* d; \
	EVTAG_GET(msg,mbr,&d); \
	EVTAG_GET(d,remote,(void*)pval); \
	} while(0)
	

#define CLRPC_GET(msg,basetype,mbr,pval) do { \
   clrpc_##basetype tmp; \
   EVTAG_GET(msg,mbr,(void*)&tmp); \
   *pval = (cl_##basetype)tmp; \
   } while(0)




#define CLRPC_UNBLOCK(parg) do { \
   struct cb_struct* cbarg = (struct cb_struct*)parg; \
   pthread_mutex_lock(&cbarg->mtx); \
   pthread_cond_signal(&cbarg->sig); \
   pthread_mutex_unlock(&cbarg->mtx); \
   } while(0)


#endif

