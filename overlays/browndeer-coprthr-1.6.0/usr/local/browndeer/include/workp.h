/* workp.h
 *
 * Copyright (c) 2009-2012 Brown Deer Technology, LLC.  All Rights Reserved.
 *
 * This software was developed by Brown Deer Technology, LLC.
 * For more information contact info@browndeertechnology.com
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License version 3 (LGPLv3)
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* DAR */

#ifndef _workp_h
#define _workp_h

#include <stdint.h>

#ifndef min
#define min(a,b) ((a<b)?a:b)
#endif

struct workp_entry {
	unsigned int ndr_dim;
	unsigned int ndr_gtdoff[3];
	unsigned int ndr_gtdsz[3];
	unsigned int ndr_ltdsz[3];
	unsigned int ndp_blk_first[3];
	unsigned int ndp_blk_end[3];
	unsigned int ndp_ltd0[3];
};


#if !defined(__xcl_kcall__) && !defined(__xcl_kthr__)

#include <pthread.h>

#define mutex_t pthread_mutex_t
#define mutex_init pthread_mutex_init
#define mutex_lock pthread_mutex_lock
#define mutex_unlock pthread_mutex_unlock
#define mutex_destroy pthread_mutex_destroy


struct workp {
	int flags;
	mutex_t mtx;
	unsigned int n;
	unsigned int nxt;
};

__inline static
struct workp* workp_alloc( unsigned int n ) 
{
	struct workp* wp = (struct workp*)
		malloc( sizeof(struct workp) + n * sizeof(struct workp_entry) );
	wp->n = n;
	return(wp);
}

__inline static
void workp_free( struct workp* wp ) { free(wp); }

__inline static 
struct workp* workp_init( struct workp* wp ) 
{
	wp->flags = 0;
	mutex_init(&wp->mtx,0);
	wp->nxt = 0;
}

__inline static 
struct workp_entry* __workp_part( struct workp* wp) 
{ return( (struct workp_entry*)((char*)wp + sizeof(struct workp)) ); }

__inline static
struct workp_entry* workp_get_entry( struct workp* wp, unsigned int idx )
{ return((idx<wp->n)? __workp_part(wp) + idx : 0 ); }

__inline static 
int workp_set_entry( 
	struct workp* wp, unsigned int idx, struct workp_entry* e ) 
{
	if (idx<wp->n) {
		memcpy(__workp_part(wp) + idx, e, sizeof(struct workp_entry) );
		return(0);
	} else return(-1);
}

__inline static 
void workp_reset( struct workp* wp )
{ wp->nxt = 0; }

__inline static 
struct workp_entry* workp_nxt_entry( struct workp* wp )
{ return( (wp->nxt<wp->n)? __workp_part(wp) + wp->nxt++ : 0 ); }

__inline static 
unsigned int workp_genpart( 
	struct workp* wp, struct workp_entry* e0 )
{
	int i;
	unsigned int n = wp->n;
	unsigned int delta = e0->ndp_blk_end[0] - e0->ndp_blk_first[0];
	unsigned int alpha = delta/n;
	unsigned int beta = delta%n;

	printcl( CL_DEBUG "delta alpha beta %d %d %d\n",delta,alpha,beta);

	struct workp_entry* e = workp_get_entry(wp,0);

	for(i=0; i<n; i++) {

		switch(e0->ndr_dim) {

			case 3:
				e[i].ndr_gtdoff[2] = e0->ndr_gtdoff[2];
				e[i].ndr_gtdsz[2] = e0->ndr_gtdsz[2];
				e[i].ndr_ltdsz[2] = e0->ndr_ltdsz[2];
				e[i].ndp_blk_first[2] = e0->ndp_blk_first[2];
				e[i].ndp_blk_end[2] = e0->ndp_blk_end[2];
				e[i].ndp_ltd0[2] = e0->ndp_ltd0[2];

			case 2:
				e[i].ndr_gtdoff[1] = e0->ndr_gtdoff[1];
				e[i].ndr_gtdsz[1] = e0->ndr_gtdsz[1];
				e[i].ndr_ltdsz[1] = e0->ndr_ltdsz[1];
				e[i].ndp_blk_first[1] = e0->ndp_blk_first[1];
				e[i].ndp_blk_end[1] = e0->ndp_blk_end[1];
				e[i].ndp_ltd0[1] = e0->ndp_ltd0[1];

			case 1:
				e[i].ndr_gtdoff[0] = e0->ndr_gtdoff[0];
				e[i].ndr_gtdsz[0] = e0->ndr_gtdsz[0];
				e[i].ndr_ltdsz[0] = e0->ndr_ltdsz[0];
				e[i].ndp_blk_first[0] 
					= (i==0)? e0->ndp_blk_first[0] : e[i-1].ndp_blk_end[0];
				e[i].ndp_blk_end[0] 
					= e0->ndp_blk_first[0]+alpha*(i+1)+min(i+1,beta);
				e[i].ndp_ltd0[0] = e0->ndp_ltd0[0];

			default:
				e[i].ndr_dim = e0->ndr_dim;

		}

	}

	return( (alpha==0)? beta : n );

}

#define workp_lock(wp) mutex_lock(&(wp)->mtx)
#define workp_unlock(wp) mutex_unlock(&(wp)->mtx)

#define report_workp_entry( level, e ) do { \
   switch((e)->ndr_dim) { \
   case 3: \
      printcl( level \
         "XXX %d {%d %d %d} {%d %d %d} {%d %d %d} {%d %d %d} {%d %d %d}" \
         " {%d %d %d}", \
         (e)->ndr_dim, \
         (e)->ndr_gtdoff[0],(e)->ndr_gtdoff[1],(e)->ndr_gtdoff[2], \
         (e)->ndr_gtdsz[0],(e)->ndr_gtdsz[1],(e)->ndr_gtdsz[2], \
         (e)->ndr_ltdsz[0],(e)->ndr_ltdsz[1],(e)->ndr_ltdsz[2], \
         (e)->ndp_blk_first[0],(e)->ndp_blk_first[1],(e)->ndp_blk_first[2], \
         (e)->ndp_blk_end[0],(e)->ndp_blk_end[1],(e)->ndp_blk_end[2], \
         (e)->ndp_ltd0[0],(e)->ndp_ltd0[1],(e)->ndp_ltd0[2] ); \
      break; \
   case 2: \
      printcl( level \
         "XXX %d {%d %d} {%d %d} {%d %d} {%d %d} {%d %d} {%d %d}", \
         (e)->ndr_dim, \
         (e)->ndr_gtdoff[0],(e)->ndr_gtdoff[1], \
         (e)->ndr_gtdsz[0],(e)->ndr_gtdsz[1], \
         (e)->ndr_ltdsz[0],(e)->ndr_ltdsz[1], \
         (e)->ndp_blk_first[0],(e)->ndp_blk_first[1], \
         (e)->ndp_blk_end[0],(e)->ndp_blk_end[1], \
         (e)->ndp_ltd0[0],(e)->ndp_ltd0[1] ); \
      break; \
   case 1: \
      printcl( CL_DEBUG \
         "XXX %d {%d} {%d} {%d} {%d} {%d} {%d}", \
         (e)->ndr_dim, \
         (e)->ndr_gtdoff[0], \
         (e)->ndr_gtdsz[0], \
         (e)->ndr_ltdsz[0], \
         (e)->ndp_blk_first[0], \
         (e)->ndp_blk_end[0], \
         (e)->ndp_ltd0[0] ); \
   } \
	} while(0)

#endif

#endif

