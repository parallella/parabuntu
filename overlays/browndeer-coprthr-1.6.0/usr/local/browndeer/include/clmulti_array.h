/* clmulti_array.h
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

#ifndef __CLMULTI_ARRAY_H
#define __CLMULTI_ARRAY_H

//#include <string.h>
#include <stdio.h>
//#include <sys/queue.h>

#include <string>

#include <stdcl.h>
#include <clmalloc_allocator.h>

#include <boost/multi_array.hpp>


#ifdef __cplusplus

#define __stdclpp__

/***
 *** clmulti_array
 ***/

template<class T>
class Expression;

template < typename T, std::size_t D >
class clmulti_array : public boost::multi_array< T, D, clmalloc_allocator<T> >
{
	typedef clmalloc_allocator<T> allocator_t;

	public:

  explicit clmulti_array() : boost::multi_array<T,D,allocator_t>() {}

  template <class ExtentList>
  explicit clmulti_array(
      ExtentList const& extents
#ifdef BOOST_NO_FUNCTION_TEMPLATE_ORDERING
      , typename mpl::if_<
      detail::multi_array::is_multi_array_impl<ExtentList>,
      int&,int>::type* = 0
#endif 
      ) : boost::multi_array<T,D,allocator_t>(extents) {}



		void clmattach( CONTEXT* cp )
		{ ::clmattach(cp, (void*)this->origin() ); }
		
		void clmdetach()
		{ ::clmdetach((void*)this->origin() ); }
	
		void clmsync( CONTEXT* cp, unsigned int devnum, int flags = 0 )
		{ ::clmsync(cp, devnum, (void*)this->origin(), flags); }
	
		void clarg_set_global( CONTEXT* cp, cl_kernel krn, unsigned int argnum )
		{ ::clarg_set_global(cp, krn, argnum, (void*)this->origin()); }

		void* get_ptr() { return (void*)this->origin(); }

  template<class RHS>
  clmulti_array<T,D>& operator=(const Expression<RHS> &rhs);

	
};

#ifndef _WIN64
#include "CLETE/clmulti_array_CLETE.h"
#endif

  template < typename T, std::size_t D >  template<class RHS>
  clmulti_array<T,D>& 
  clmulti_array<T,D>::operator=(const Expression<RHS> &rhs)
  {
		assign(*this,rhs);

    return *this;
  }


#endif //// ifdef __cplusplus

#endif

