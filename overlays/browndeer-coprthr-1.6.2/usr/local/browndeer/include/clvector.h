/* clvector.h
 *
 * Copyright (c) 2010-2011 Brown Deer Technology, LLC.  All Rights Reserved.
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

#ifndef __CLVECTOR_H
#define __CLVECTOR_H

//#include <string.h>
#include <stdio.h>
//#include <sys/queue.h>

#include <string>

#include <CL/cl.h>
#include <stdcl.h>
#include <clmalloc_allocator.h>

#include <vector>


#ifdef __cplusplus

#define __stdclpp__

//namespace stdclpp {

/***
 *** clvector
 ***/

template<class T>
class Expression;

/* address the difference in implementations -DAR */
#ifdef _WIN64
#define _clvector_ptr (this->_Myfirst)
#else
#define _clvector_ptr (this->_M_impl._M_start)
#endif

template < typename T, typename A = clmalloc_allocator<T> >
class clvector : public std::vector< T, clmalloc_allocator<T> >
{
	typedef clmalloc_allocator<T> allocator_t;

	public:

		clvector()
			: std::vector< T, clmalloc_allocator<T> >() {}

		clvector( size_t n, const T& value = T() )
			: std::vector< T, clmalloc_allocator<T> >( n, value ) {}

		template < class InputIterator >
		clvector( InputIterator first, InputIterator last )
			: std::vector< T, clmalloc_allocator<T> >( first, last ) {}

		void clmattach( CONTEXT* cp )
		{ if (_clvector_ptr) ::clmattach(cp, (void*)_clvector_ptr); }
		
		void clmdetach()
		{ if (_clvector_ptr) ::clmdetach((void*)_clvector_ptr); }
	
		void clmsync( CONTEXT* cp, unsigned int devnum, int flags = 0 )
		{ if (_clvector_ptr) ::clmsync(cp, devnum, (void*)_clvector_ptr, flags); }
	
		void clarg_set_global( CONTEXT* cp, cl_kernel krn, unsigned int argnum )
		{ 
			if (_clvector_ptr) 
				::clarg_set_global(cp, krn, argnum,(void*)_clvector_ptr); 
		}

		void* get_ptr() { return (void*)_clvector_ptr; }


  template<class RHS>
  clvector<T,A>& operator=(const Expression<RHS> &rhs);

	
};

#ifndef _WIN64
#include "CLETE/clvector_CLETE.h"
#endif

  template < typename T, typename A> template<class RHS>
  clvector<T,A>& clvector<T,A>::operator=(const Expression<RHS> &rhs)
  {
		assign(*this,rhs);

    return *this;
  }


//} //// namespace stdclpp

#endif //// ifdef __cplusplus

#endif

