/* clmalloc_allocator.h
 *
 * Copyright (c) 2010 Brown Deer Technology, LLC.  All Rights Reserved.
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


#ifndef _CLMALLOC_ALLOCATOR_H
#define _CLMALLOC_ALLOCATOR_H

#include "stdcl.h"

template < class T > class clmalloc_allocator;

template <> class clmalloc_allocator<void>
{
	public:

		typedef void* pointer;
		typedef const void* const_pointer;
		typedef void value_type;

		template < class T2 > 
		struct rebind { typedef clmalloc_allocator<T2> other; };
};

template < class T > class clmalloc_allocator 
{
	public:

		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		typedef T* pointer;
		typedef const T* const_pointer;
		typedef T& reference;
		typedef const T& const_reference;
		typedef T value_type;

		template < class T2 > 
		struct rebind { typedef clmalloc_allocator<T2> other; };

		clmalloc_allocator() throw() {}

		clmalloc_allocator( const clmalloc_allocator& ) throw() {}
		
		template < class T2 > 
		clmalloc_allocator( const clmalloc_allocator<T2>& ) throw() {}

		~clmalloc_allocator() throw() {}

		pointer address( reference x) const { return &x; }

		const_pointer address( const_reference x) const { return &x; };

		pointer allocate( 
			size_type n, clmalloc_allocator<void>::const_pointer hint = 0 
		)
		{ return (pointer)::clmalloc(0,n * sizeof(value_type), CL_MEM_DETACHED); }

		void deallocate( pointer p, size_type )
		{ ::clfree((void*)(p)); }

		size_type max_size() const throw() { return (size_type)(~0); }

		void construct( pointer p, const T& val )
		{ ::new((void *)p) value_type(val); }

		void destroy(pointer p)
		{ p->~value_type(); }

};


template < class T1, class T2 >
bool operator==(const clmalloc_allocator<T1>&, const clmalloc_allocator<T2>&) throw()
{ return true; }


template < class T1, class T2 >
bool operator!=(const clmalloc_allocator<T1>&, const clmalloc_allocator<T2>&) throw()
{ return false; }
				

#endif


