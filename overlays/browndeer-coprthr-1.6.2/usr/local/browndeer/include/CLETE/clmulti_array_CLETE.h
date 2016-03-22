/* clmulti_array_CLETE.h
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

/* This is a derivative work based on PETE-2.1.0, produced in compliance
 * with the original ACL license reproduced below, and which should not be
 * confused with the original software.
 */

// ACL:license
// ----------------------------------------------------------------------
// This software and ancillary information (herein called "SOFTWARE")
// called PETE (Portable Expression Template Engine) is
// made available under the terms described here.  The SOFTWARE has been
// approved for release with associated LA-CC Number LA-CC-99-5.
// 
// Unless otherwise indicated, this SOFTWARE has been authored by an
// employee or employees of the University of California, operator of the
// Los Alamos National Laboratory under Contract No.  W-7405-ENG-36 with
// the U.S. Department of Energy.  The U.S. Government has rights to use,
// reproduce, and distribute this SOFTWARE. The public may copy, distribute,
// prepare derivative works and publicly display this SOFTWARE without 
// charge, provided that this Notice and any statement of authorship are 
// reproduced on all copies.  Neither the Government nor the University 
// makes any warranty, express or implied, or assumes any liability or 
// responsibility for the use of this SOFTWARE.
// 
// If SOFTWARE is modified to produce derivative works, such modified
// SOFTWARE should be clearly marked, so as not to confuse it with the
// version available from LANL.
// 
// For more information about PETE, send e-mail to pete@acl.lanl.gov,
// or visit the PETE web page at http://www.acl.lanl.gov/pete/.
// ----------------------------------------------------------------------
// ACL:license
// ----------------------------------------------------------------------
// $RCSfile: Eval.h,v $   $Author: swhaney $
// $Revision: 1.11 $   $Date: 2000/01/04 01:39:17 $
// ----------------------------------------------------------------------

/* DAR */

#ifndef _CLMULTI_ARRAY_CLETE_H
#define _CLMULTI_ARRAY_CLETE_H

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stdcl.h>
using namespace std;

#include <stdcl.h>
#include <clmulti_array.h>

#include "CLETE/PETE.h"
#include "CLETE/clmulti_array_Operators.h"
#include "CLETE/PrintType.h"
#include "CLETE/PrintF.h"

#include <cmath>

#if defined(__CLVECTOR_FULLAUTO_STDACC)
#define __CLCONTEXT stdacc
#define __WGSIZE 16
#elif defined(__CLVECTOR_FULLAUTO_STDCPU)
#define __CLCONTEXT stdcpu
#define __WGSIZE 16
#elif defined(__CLVECTOR_FULLAUTO_STDGPU)
#define __CLCONTEXT stdgpu
#define __WGSIZE 64
#else
#define __CLCONTEXT stdgpu
#define __WGSIZE 64
#endif

#define clete_expr auto

//-----------------------------------------------------------------------------
// We need to specialize CreateLeaf<T> for our class, so that operators
// know what to stick in the leaves of the expression tree.
//-----------------------------------------------------------------------------

template<class T, std::size_t D>
struct CreateLeaf<clmulti_array<T, D> >
{
  typedef Reference<clmulti_array<T, D> > Leaf_t;
  inline static
  Leaf_t make(const clmulti_array<T, D>& a) { return Leaf_t(a); }
};

//-----------------------------------------------------------------------------
// EvalLeaf1 is used to evaluate expression with vectors.
// (It's already defined for Scalar values.)
//-----------------------------------------------------------------------------

template<class T>
struct LeafFunctor<clmulti_array<T, 1>, EvalLeaf1>
{
  typedef T Type_t;
  inline static
  Type_t apply(const clmulti_array<T, 1>& m, const EvalLeaf1& f)
  {
    return m[f.val1()];
  }
};


template<class T>
struct LeafFunctor<clmulti_array<T, 1>, EvalLeaf2>
{
  typedef T Type_t;
  inline static
  Type_t apply(const clmulti_array<T, 1>& m, const EvalLeaf2 &f)
  {
    return m[f.val1()];
  }
};

template<class T>
struct LeafFunctor<clmulti_array<T, 2>, EvalLeaf2>
{
  typedef T Type_t;
  inline static
  Type_t apply(const clmulti_array<T, 2>& m, const EvalLeaf2 &f)
  {
    return m[f.val1()][f.val2()];
  }
};




template<class T>
struct LeafFunctor<clmulti_array<T, 1>, EvalLeaf3>
{
  typedef T Type_t;
  inline static
  Type_t apply(const clmulti_array<T, 1>& m, const EvalLeaf3 &f)
  {
    return m[f.val1()];
  }
};

template<class T>
struct LeafFunctor<clmulti_array<T, 2>, EvalLeaf3>
{
  typedef T Type_t;
  inline static
  Type_t apply(const clmulti_array<T, 2>& m, const EvalLeaf3 &f)
  {
    return m[f.val1()][f.val2()];
  }
};

template<class T>
struct LeafFunctor<clmulti_array<T, 3>, EvalLeaf3>
{
  typedef T Type_t;
  inline static
  Type_t apply(const clmulti_array<T, 3>& m, const EvalLeaf3 &f)
  {
    return m[f.val1()][f.val2()][f.val3()];
  }
};




template<class T>
struct LeafFunctor<clmulti_array<T, 1>, EvalLeaf4>
{
  typedef T Type_t;
  inline static
  Type_t apply(const clmulti_array<T, 1>& m, const EvalLeaf4 &f)
  {
    return m[f.val1()];
  }
};

template<class T>
struct LeafFunctor<clmulti_array<T, 2>, EvalLeaf4>
{
  typedef T Type_t;
  inline static
  Type_t apply(const clmulti_array<T, 2>& m, const EvalLeaf4 &f)
  {
    return m[f.val1()][f.val2()];
  }
};

template<class T>
struct LeafFunctor<clmulti_array<T, 3>, EvalLeaf4>
{
  typedef T Type_t;
  inline static
  Type_t apply(const clmulti_array<T, 3>& m, const EvalLeaf4 &f)
  {
    return m[f.val1()][f.val2()][f.val3()];
  }
};

template<class T>
struct LeafFunctor<clmulti_array<T, 4>, EvalLeaf4>
{
  typedef T Type_t;
  inline static
  Type_t apply(const clmulti_array<T, 4>& m, const EvalLeaf4 &f)
  {
    return m[f.val1()][f.val2()][f.val3()][f.val4()];
  }
};



template<class T>
struct LeafFunctor<clmulti_array<T, 1>, SizeLeaf1>
{
  typedef bool Type_t;
  inline static
  bool apply(const clmulti_array<T, 1>& m, const SizeLeaf1& s) 
  {
    return s(m.shape()[0]);
  }
};

template<class T>
struct LeafFunctor<clmulti_array<T, 1>, SizeLeaf2>
{
  typedef bool Type_t;
  inline static
  bool apply(const clmulti_array<T, 1>& m, const SizeLeaf2& s) 
  {
    return s(m.shape()[0]);
  }
};

template<class T>
struct LeafFunctor<clmulti_array<T, 1>, SizeLeaf3>
{
  typedef bool Type_t;
  inline static
  bool apply(const clmulti_array<T, 1>& m, const SizeLeaf3& s) 
  {
    return s(m.shape()[0]);
  }
};

template<class T>
struct LeafFunctor<clmulti_array<T, 1>, SizeLeaf4>
{
  typedef bool Type_t;
  inline static
  bool apply(const clmulti_array<T, 1>& m, const SizeLeaf4& s) 
  {
    return s(m.shape()[0]);
  }
};


template<class T>
struct LeafFunctor<clmulti_array<T, 2>, SizeLeaf2>
{
  typedef bool Type_t;
  inline static
  bool apply(const clmulti_array<T, 2>& m, const SizeLeaf2& s) 
  {
    return s(m.shape()[0],m.shape()[1]);
  }
};

template<class T>
struct LeafFunctor<clmulti_array<T, 2>, SizeLeaf3>
{
  typedef bool Type_t;
  inline static
  bool apply(const clmulti_array<T, 2>& m, const SizeLeaf3& s) 
  {
    return s(m.shape()[0],m.shape()[1]);
  }
};

template<class T>
struct LeafFunctor<clmulti_array<T, 2>, SizeLeaf4>
{
  typedef bool Type_t;
  inline static
  bool apply(const clmulti_array<T, 2>& m, const SizeLeaf4& s) 
  {
    return s(m.shape()[0],m.shape()[1]);
  }
};


template<class T>
struct LeafFunctor<clmulti_array<T, 3>, SizeLeaf3>
{
  typedef bool Type_t;
  inline static
  bool apply(const clmulti_array<T, 3>& m, const SizeLeaf3& s) 
  {
    return s(m.shape()[0],m.shape()[1],m.shape()[2]);
  }
};

template<class T>
struct LeafFunctor<clmulti_array<T, 3>, SizeLeaf4>
{
  typedef bool Type_t;
  inline static
  bool apply(const clmulti_array<T, 3>& m, const SizeLeaf4& s) 
  {
    return s(m.shape()[0],m.shape()[1],m.shape()[2]);
  }
};


template<class T>
struct LeafFunctor<clmulti_array<T, 4>, SizeLeaf4>
{
  typedef bool Type_t;
  inline static
  bool apply(const clmulti_array<T, 4>& m, const SizeLeaf4& s) 
  {
    return s(m.shape()[0],m.shape()[1],m.shape()[2],m.shape()[3]);
  }
};


template<class T, std::size_t D>
struct LeafFunctor<clmulti_array<T, D>, PrintTmpLeaf>
{
  typedef std::string Type_t;
  inline static
  std::string apply(
		const clmulti_array<T, D> & v, const PrintTmpLeaf & p
  ) 
  {
    return "tmp" + tostr(p((intptr_t)&v));
  }
};


template<class T, std::size_t D>
struct LeafFunctor<clmulti_array<T, D>*, PtrListLeaf>
{
  typedef std::list<const void*> Type_t;
  inline static
  Type_t apply(
		clmulti_array<T, D>* const & ptr, const PtrListLeaf & plist
  )
  {
    return Type_t(1,ptr);
  }
};


template<class T, std::size_t D>
struct LeafFunctor<clmulti_array<T, D>*, RefListLeaf>
{
  typedef std::list<Ref> Type_t;
  inline static
  Type_t apply(clmulti_array<T, D>* const & ptr, const RefListLeaf &r)
  {
    return Type_t(1,Ref(
		ptr,0,ptr->origin(),D,
		PrintF<clmulti_array<T,D> >::type_str(),
		PrintF<clmulti_array<T,D> >::arg_str(tostr(r((intptr_t)ptr))),
		PrintF<clmulti_array<T,D> >::tmp_decl_str(tostr(r((intptr_t)ptr))),
		PrintF<clmulti_array<T,D> >::tmp_ref_str(tostr(r((intptr_t)ptr))),
		PrintF<clmulti_array<T,D> >::store_str(tostr(r((intptr_t)ptr))) ));
  }
};


template<class T, std::size_t D>
struct LeafFunctor<clmulti_array<T, D>, AddressOfLeaf>
{
  typedef clmulti_array<T, D>* Type_t;
  inline static
  Type_t apply(const clmulti_array<T, D>& m, const AddressOfLeaf & f)
  {
    return Type_t(&m);
  }
};


template<class T, std::size_t D>
struct LeafFunctor<clmulti_array<T, D>, IAddressOfLeaf>
{
  typedef intptr_t Type_t;
  inline static
  Type_t apply(const clmulti_array<T, D>& m, const IAddressOfLeaf & f)
  {
    return Type_t((intptr_t)&m);
  }
};


template < class T, std::size_t D >
struct PrintF< clmulti_array<T, D> > {

   inline static std::string type_str() 
   { return "__global " + PrintType<T>::type_str() + "*"; }

   inline static std::string arg_str( std::string x) 
   { return "a" + x; }

   inline static std::string tmp_decl_str( std::string x )
   { return PrintType<T>::type_str() + " tmp" + x + " = a" + x; }

   inline static std::string tmp_ref_str( std::string x )
   { return "tmp" + x; }

   inline static std::string store_str( std::string x )
   { return "a" + x; }

};

/* 
template < class T >
struct PrintF< clmulti_array<T, 2> > {

   inline static std::string type_str() 
   { return "__global " + PrintType<T>::type_str() + "*"; }

   inline static std::string arg_str( std::string x) 
   { return "a" + x; }

   inline static std::string tmp_decl_str( std::string x )
   { return PrintType<T>::type_str() + " tmp" + x + " = a" + x; }

   inline static std::string tmp_ref_str( std::string x )
   { return "tmp" + x; }

   inline static std::string store_str( std::string x )
   { return "a" + x; }

};
*/


//static inline void log_kernel( std::string& srcstr )
//{
//   if (__log_automatic_kernels_filename) {
//      std::ofstream ofs(
//         __log_automatic_kernels_filename,
//         std::ios_base::out|std::ios_base::app);
//      ofs<<srcstr<<"\n";
//      ofs.close();
//	}
//}

//// XXX use macros as workaround for incorrect behavior of gcc 4.1 -DAR

#define log_kernel(srcstr) do { \
   if (__log_automatic_kernels_filename) { \
      std::ofstream ofs( \
         __log_automatic_kernels_filename, \
         std::ios_base::out|std::ios_base::app); \
      ofs<<srcstr<<"\n"; \
      ofs.close(); \
	} \
   } while (0)




/* this is where the real magic happens ... the evaluate functions */

template<class T, class Op, class RHS>
inline void evaluate(
	clmulti_array<T, 1> &lhs, const Op &op, 
	const Expression<RHS> &rhs
)
{
  if (forEach(rhs, SizeLeaf1(lhs.size()), AndCombine())) {

#if defined(__CLMULTI_ARRAY_SEMIAUTO) || defined(__CLMULTI_ARRAY_FULLAUTO)

	typedef typename 
		ForEach<Expression<RHS>, AddressOfLeaf, TreeCombine >::Type_t New_t;

	New_t rhs2 = forEach(rhs,AddressOfLeaf(),TreeCombine());

	typedef std::list<Ref> rlist_t;

	intptr_t mask = ~((intptr_t)forEach(rhs,IAddressOfLeaf(),AndBitsCombine()) & (intptr_t)&lhs);
 
	rlist_t rlist = forEach(rhs2,RefListLeaf(mask),ListCombine<Ref>());

	rlist.sort(ref_is_ordered);
	rlist.unique(ref_is_equal);

	rlist_t rlista = rlist;
	rlista.push_back(
		Ref(&lhs,0,lhs.data(),
			PrintF< clmulti_array<T, 1> >::type_str(),
			PrintF< clmulti_array<T, 1> >::arg_str(tostr(mask & (intptr_t)&lhs)),
			PrintF< clmulti_array<T, 1> >::tmp_decl_str(tostr(mask & (intptr_t)&lhs)),
			PrintF< clmulti_array<T, 1> >::tmp_ref_str(tostr(mask & (intptr_t)&lhs)),
			PrintF< clmulti_array<T, 1> >::store_str(tostr(mask & (intptr_t)&lhs))
		)
	);
	rlista.sort(ref_is_ordered);
	rlista.unique(ref_is_equal);

	int size = lhs.size();
	size_t r = size;
	if (r%256 > 0) r += 256 - r%256;

	static cl_kernel krn = (cl_kernel)0;

	if (!krn) {

		std::string srcstr = "__kernel void\nkern(\n";

		int n = 0;	
		for( rlist_t::iterator it = rlista.begin(); it!=rlista.end(); it++,n++) {
			srcstr += (*it).type_str + " " + (*it).arg_str + ",\n";
	
		}
		srcstr += "int size\n";

		srcstr += "){\n";
		srcstr += "int gti = get_global_id(0);\n";

		if (size != r) srcstr += "if (gti<size) {\n";

		for( rlist_t::iterator it = rlist.begin(); it!=rlist.end(); it++,n++) {
			srcstr += (*it).tmp_decl_str;
			if ((*it).dim == 1) srcstr += "[gti]";
			srcstr += ";\n";
		}


		srcstr += PrintF< clmulti_array<T, 1> >::store_str(tostr(mask & (intptr_t)&lhs)) + "[gti] = ";

		std::string expr = forEach(rhs,PrintTmpLeaf(mask),PrintCombine());
		srcstr += expr + ";\n" ;
		
		if (size != r) srcstr += "}\n";

		srcstr += "}\n";

//		cout<<srcstr<<"\n";
		log_kernel(srcstr);

		void* clh = clsopen(__CLCONTEXT,srcstr.c_str(),CLLD_NOW);
		krn = clsym(__CLCONTEXT,clh,"kern",CLLD_NOW);
	}

	if (krn) {

		clndrange_t ndr = clndrange_init1d(0,r,__WGSIZE);

	int n = 0;	
	for( rlist_t::iterator it = rlista.begin(); it!=rlista.end(); it++,n++) {
		size_t sz = (*it).sz;
		if (sz > 0) {
			int dummy;
			clSetKernelArg(krn,n,sz,(*it).ptr);
		} else { 


#if defined(__CLMULTI_ARRAY_FULLAUTO)
			clmattach(__CLCONTEXT,(void*)(*it).memptr);
			clmsync(__CLCONTEXT,0,(void*)(*it).memptr,CL_MEM_DEVICE|CL_EVENT_NOWAIT);
#endif

			clarg_set_global(__CLCONTEXT,krn,n,(void*)(*it).memptr);
//			(*it).ptr->clarg_set_global(__CLCONTEXT,krn,n);

		}
	}

	clarg_set(__CLCONTEXT,krn,n,size);


		clfork(__CLCONTEXT,0,krn,&ndr,CL_EVENT_NOWAIT);

#if defined(__CLMULTI_ARRAY_FULLAUTO)

		clmsync(__CLCONTEXT,0,lhs.data(),CL_MEM_HOST|CL_EVENT_NOWAIT);

		clwait(__CLCONTEXT,0,CL_KERNEL_EVENT|CL_MEM_EVENT);

	n = 0;	
	for( rlist_t::iterator it = rlista.begin(); it!=rlista.end(); it++,n++) {
		size_t sz = (*it).sz;
		if (sz > 0) {
		} else { 

			clmdetach((void*)(*it).memptr);

		}
	}

#elif defined(__CLMULTI_ARRAY_SEMIAUTO)

		clwait(__CLCONTEXT,0,CL_KERNEL_EVENT);

#endif


	}


#else

      for (int i = 0; i < lhs.size(); ++i) {
          op(lhs[i], forEach(rhs, EvalLeaf1(i), OpCombine()));
        }

#endif


    } else {
      cerr << "Error: LHS and RHS don't conform." << endl;
      exit(1);
    }
}


template<class T, class Op, class RHS>
inline void evaluate(
	clmulti_array<T, 2> &lhs, const Op &op, 
	const Expression<RHS> &rhs
)
{
  if (forEach(rhs, SizeLeaf2(lhs.shape()[0],lhs.shape()[1]), AndCombine())) {

#if defined(__CLMULTI_ARRAY_SEMIAUTO) || defined(__CLMULTI_ARRAY_FULLAUTO)

	typedef typename 
		ForEach<Expression<RHS>, AddressOfLeaf, TreeCombine >::Type_t New_t;

	New_t rhs2 = forEach(rhs,AddressOfLeaf(),TreeCombine());

	typedef std::list<Ref> rlist_t;

	intptr_t mask = ~((intptr_t)forEach(rhs,IAddressOfLeaf(),AndBitsCombine()) & (intptr_t)&lhs);
 
	rlist_t rlist = forEach(rhs2,RefListLeaf(mask),ListCombine<Ref>());

	rlist.sort(ref_is_ordered);
	rlist.unique(ref_is_equal);

	rlist_t rlista = rlist;
	rlista.push_back(
		Ref(&lhs,0,lhs.data(),2,
			PrintF< clmulti_array<T, 2> >::type_str(),
			PrintF< clmulti_array<T, 2> >::arg_str(tostr(mask & (intptr_t)&lhs)),
			PrintF< clmulti_array<T, 2> >::tmp_decl_str(tostr(mask & (intptr_t)&lhs)),
			PrintF< clmulti_array<T, 2> >::tmp_ref_str(tostr(mask & (intptr_t)&lhs)),
			PrintF< clmulti_array<T, 2> >::store_str(tostr(mask & (intptr_t)&lhs))
		)
	);
	rlista.sort(ref_is_ordered);
	rlista.unique(ref_is_equal);

	int size1 = lhs.shape()[0];
	int size2 = lhs.shape()[1];
	int size = size1*size2;
	int r = size;
	if (r%256 > 0) r += 256 - r%256;

	static cl_kernel krn = (cl_kernel)0;

	if (!krn) {

		std::string srcstr = "__kernel void\nkern(\n";

		int n = 0;	
		for( rlist_t::iterator it = rlista.begin(); it!=rlista.end(); it++,n++) {
			srcstr += (*it).type_str + " " + (*it).arg_str + ",\n";
	
		}
		srcstr += "int size, int size2\n";

		srcstr += "){\n";
		srcstr += "int gti = get_global_id(0);\n";
		srcstr += "int gti1 = gti/size2;\n";

		if (size != r) srcstr += "if (gti<size) {\n";

		for( rlist_t::iterator it = rlist.begin(); it!=rlist.end(); it++,n++) {
			srcstr += (*it).tmp_decl_str;
			switch( (*it).dim ) {
				case 2: srcstr += "[gti]"; break;
				case 1: srcstr += "[gti1]"; break;
				default: break;
			}
			srcstr += ";\n";
		}


		srcstr += PrintF< clmulti_array<T, 1> >::store_str(tostr(mask & (intptr_t)&lhs)) + "[gti] = ";

		std::string expr = forEach(rhs,PrintTmpLeaf(mask),PrintCombine());
		srcstr += expr + ";\n" ;
		
		if (size != r) srcstr += "}\n";

		srcstr += "}\n";

//		cout<<srcstr<<"\n";
		log_kernel(srcstr);

		void* clh = clsopen(__CLCONTEXT,srcstr.c_str(),CLLD_NOW);
		krn = clsym(__CLCONTEXT,clh,"kern",CLLD_NOW);
	}

	if (krn) {

		clndrange_t ndr = clndrange_init1d(0,r,__WGSIZE);

	int n = 0;	
	for( rlist_t::iterator it = rlista.begin(); it!=rlista.end(); it++,n++) {
		size_t sz = (*it).sz;
		if (sz > 0) {
			int dummy;
			clSetKernelArg(krn,n,sz,(*it).ptr);
		} else { 


#if defined(__CLMULTI_ARRAY_FULLAUTO)
			clmattach(__CLCONTEXT,(void*)(*it).memptr);
			clmsync(__CLCONTEXT,0,(void*)(*it).memptr,CL_MEM_DEVICE|CL_EVENT_NOWAIT);
#endif

			clarg_set_global(__CLCONTEXT,krn,n,(void*)(*it).memptr);
//			(*it).ptr->clarg_set_global(__CLCONTEXT,krn,n);

		}
	}

	clarg_set(__CLCONTEXT,krn,n,size);
	clarg_set(__CLCONTEXT,krn,n+1,size2);


		clfork(__CLCONTEXT,0,krn,&ndr,CL_EVENT_NOWAIT);

#if defined(__CLMULTI_ARRAY_FULLAUTO)

		clmsync(__CLCONTEXT,0,lhs.data(),CL_MEM_HOST|CL_EVENT_NOWAIT);

		clwait(__CLCONTEXT,0,CL_KERNEL_EVENT|CL_MEM_EVENT);

	n = 0;	
	for( rlist_t::iterator it = rlista.begin(); it!=rlista.end(); it++,n++) {
		size_t sz = (*it).sz;
		if (sz > 0) {
		} else { 

			clmdetach((void*)(*it).memptr);

		}
	}

#elif defined(__CLMULTI_ARRAY_SEMIAUTO)

		clwait(__CLCONTEXT,0,CL_KERNEL_EVENT);

#endif


	}


#else

      for (int i = 0; i < lhs.shape()[0]; ++i) 
      for (int j = 0; j < lhs.shape()[1]; ++j) {
          op(lhs[i][j], forEach(rhs, EvalLeaf2(i,j), OpCombine()));
        }

#endif


    } else {
      cerr << "Error: LHS and RHS don't conform." << endl;
      exit(1);
    }
}


template<class T, class Op, class RHS>
inline void evaluate(
	clmulti_array<T, 3> &lhs, const Op &op, 
	const Expression<RHS> &rhs
)
{
  if (forEach(rhs, SizeLeaf3(lhs.shape()[0],lhs.shape()[1],lhs.shape()[2]), AndCombine())) {

#if defined(__CLMULTI_ARRAY_SEMIAUTO) || defined(__CLMULTI_ARRAY_FULLAUTO)

	typedef typename 
		ForEach<Expression<RHS>, AddressOfLeaf, TreeCombine >::Type_t New_t;

	New_t rhs2 = forEach(rhs,AddressOfLeaf(),TreeCombine());

	typedef std::list<Ref> rlist_t;

	intptr_t mask = ~((intptr_t)forEach(rhs,IAddressOfLeaf(),AndBitsCombine()) & (intptr_t)&lhs);
 
	rlist_t rlist = forEach(rhs2,RefListLeaf(mask),ListCombine<Ref>());

	rlist.sort(ref_is_ordered);
	rlist.unique(ref_is_equal);

	rlist_t rlista = rlist;
	rlista.push_back(
		Ref(&lhs,0,lhs.data(),3,
			PrintF< clmulti_array<T, 3> >::type_str(),
			PrintF< clmulti_array<T, 3> >::arg_str(tostr(mask & (intptr_t)&lhs)),
			PrintF< clmulti_array<T, 3> >::tmp_decl_str(tostr(mask & (intptr_t)&lhs)),
			PrintF< clmulti_array<T, 3> >::tmp_ref_str(tostr(mask & (intptr_t)&lhs)),
			PrintF< clmulti_array<T, 3> >::store_str(tostr(mask & (intptr_t)&lhs))
		)
	);
	rlista.sort(ref_is_ordered);
	rlista.unique(ref_is_equal);

	int size1 = lhs.shape()[0];
	int size2 = lhs.shape()[1];
	int size3 = lhs.shape()[2];
	int size = size1*size2*size3;
	int r = size;
	if (r%256 > 0) r += 256 - r%256;

	static cl_kernel krn = (cl_kernel)0;

	if (!krn) {

		std::string srcstr = "__kernel void\nkern(\n";

		int n = 0;	
		for( rlist_t::iterator it = rlista.begin(); it!=rlista.end(); it++,n++) {
			srcstr += (*it).type_str + " " + (*it).arg_str + ",\n";
	
		}
		srcstr += "int size, int size2, int size3\n";

		srcstr += "){\n";
		srcstr += "int gti = get_global_id(0);\n";
		srcstr += "int gti1 = gti/size2/size3;\n";
		srcstr += "int gti2 = gti/size3;\n";

		if (size != r) srcstr += "if (gti<size) {\n";

		for( rlist_t::iterator it = rlist.begin(); it!=rlist.end(); it++,n++) {
			srcstr += (*it).tmp_decl_str;
			switch( (*it).dim ) {
				case 3: srcstr += "[gti]"; break;
				case 2: srcstr += "[gti2]"; break;
				case 1: srcstr += "[gti1]"; break;
				default: break;
			}
			srcstr += ";\n";
		}


		srcstr += PrintF< clmulti_array<T, 1> >::store_str(tostr(mask & (intptr_t)&lhs)) + "[gti] = ";

		std::string expr = forEach(rhs,PrintTmpLeaf(mask),PrintCombine());
		srcstr += expr + ";\n" ;
		
		if (size != r) srcstr += "}\n";

		srcstr += "}\n";

//		cout<<srcstr<<"\n";
		log_kernel(srcstr);

		void* clh = clsopen(__CLCONTEXT,srcstr.c_str(),CLLD_NOW);
		krn = clsym(__CLCONTEXT,clh,"kern",CLLD_NOW);
	}

	if (krn) {

		clndrange_t ndr = clndrange_init1d(0,r,__WGSIZE);

	int n = 0;	
	for( rlist_t::iterator it = rlista.begin(); it!=rlista.end(); it++,n++) {
		size_t sz = (*it).sz;
		if (sz > 0) {
			int dummy;
			clSetKernelArg(krn,n,sz,(*it).ptr);
		} else { 


#if defined(__CLMULTI_ARRAY_FULLAUTO)
			clmattach(__CLCONTEXT,(void*)(*it).memptr);
			clmsync(__CLCONTEXT,0,(void*)(*it).memptr,CL_MEM_DEVICE|CL_EVENT_NOWAIT);
#endif

			clarg_set_global(__CLCONTEXT,krn,n,(void*)(*it).memptr);
//			(*it).ptr->clarg_set_global(__CLCONTEXT,krn,n);

		}
	}

	clarg_set(__CLCONTEXT,krn,n,size);
	clarg_set(__CLCONTEXT,krn,n+1,size2);
	clarg_set(__CLCONTEXT,krn,n+2,size3);


		clfork(__CLCONTEXT,0,krn,&ndr,CL_EVENT_NOWAIT);

#if defined(__CLMULTI_ARRAY_FULLAUTO)

		clmsync(__CLCONTEXT,0,lhs.data(),CL_MEM_HOST|CL_EVENT_NOWAIT);

		clwait(__CLCONTEXT,0,CL_KERNEL_EVENT|CL_MEM_EVENT);

	n = 0;	
	for( rlist_t::iterator it = rlista.begin(); it!=rlista.end(); it++,n++) {
		size_t sz = (*it).sz;
		if (sz > 0) {
		} else { 

			clmdetach((void*)(*it).memptr);

		}
	}

#elif defined(__CLMULTI_ARRAY_SEMIAUTO)

		clwait(__CLCONTEXT,0,CL_KERNEL_EVENT);

#endif


	}


#else

      for (int i = 0; i < lhs.shape()[0]; ++i) 
      for (int j = 0; j < lhs.shape()[1]; ++j) 
      for (int k = 0; k < lhs.shape()[2]; ++k) {
          op(lhs[i][j][k], forEach(rhs, EvalLeaf3(i,j,k), OpCombine()));
        }

#endif


    } else {
      cerr << "Error: LHS and RHS don't conform." << endl;
      exit(1);
    }
}


template<class T, class Op, class RHS>
inline void evaluate(
	clmulti_array<T, 4> &lhs, const Op &op, 
	const Expression<RHS> &rhs
)
{
  if (forEach(rhs, SizeLeaf4(lhs.shape()[0],lhs.shape()[1],lhs.shape()[2],lhs.shape()[3]), AndCombine())) {

#if defined(__CLMULTI_ARRAY_SEMIAUTO) || defined(__CLMULTI_ARRAY_FULLAUTO)

	typedef typename 
		ForEach<Expression<RHS>, AddressOfLeaf, TreeCombine >::Type_t New_t;

	New_t rhs2 = forEach(rhs,AddressOfLeaf(),TreeCombine());

	typedef std::list<Ref> rlist_t;

	intptr_t mask = ~((intptr_t)forEach(rhs,IAddressOfLeaf(),AndBitsCombine()) & (intptr_t)&lhs);
 
	rlist_t rlist = forEach(rhs2,RefListLeaf(mask),ListCombine<Ref>());

	rlist.sort(ref_is_ordered);
	rlist.unique(ref_is_equal);

	rlist_t rlista = rlist;
	rlista.push_back(
		Ref(&lhs,0,lhs.data(),4,
			PrintF< clmulti_array<T, 4> >::type_str(),
			PrintF< clmulti_array<T, 4> >::arg_str(tostr(mask & (intptr_t)&lhs)),
			PrintF< clmulti_array<T, 4> >::tmp_decl_str(tostr(mask & (intptr_t)&lhs)),
			PrintF< clmulti_array<T, 4> >::tmp_ref_str(tostr(mask & (intptr_t)&lhs)),
			PrintF< clmulti_array<T, 4> >::store_str(tostr(mask & (intptr_t)&lhs))
		)
	);
	rlista.sort(ref_is_ordered);
	rlista.unique(ref_is_equal);

	int size1 = lhs.shape()[0];
	int size2 = lhs.shape()[1];
	int size3 = lhs.shape()[2];
	int size4 = lhs.shape()[3];
	int size = size1*size2*size3*size4;
	int r = size;
	if (r%256 > 0) r += 256 - r%256;

	static cl_kernel krn = (cl_kernel)0;

	if (!krn) {

		std::string srcstr = "__kernel void\nkern(\n";

		int n = 0;	
		for( rlist_t::iterator it = rlista.begin(); it!=rlista.end(); it++,n++) {
			srcstr += (*it).type_str + " " + (*it).arg_str + ",\n";
	
		}
		srcstr += "int size, int size2, int size3, int size4\n";

		srcstr += "){\n";
		srcstr += "int gti = get_global_id(0);\n";
		srcstr += "int gti1 = gti/size2/size3/size4;\n";
		srcstr += "int gti2 = gti/size3/size4;\n";
		srcstr += "int gti3 = gti/size4;\n";

		if (size != r) srcstr += "if (gti<size) {\n";

		for( rlist_t::iterator it = rlist.begin(); it!=rlist.end(); it++,n++) {
			srcstr += (*it).tmp_decl_str;
			switch( (*it).dim ) {
				case 4: srcstr += "[gti]"; break;
				case 3: srcstr += "[gti3]"; break;
				case 2: srcstr += "[gti2]"; break;
				case 1: srcstr += "[gti1]"; break;
				default: break;
			}
			srcstr += ";\n";
		}


		srcstr += PrintF< clmulti_array<T, 1> >::store_str(tostr(mask & (intptr_t)&lhs)) + "[gti] = ";

		std::string expr = forEach(rhs,PrintTmpLeaf(mask),PrintCombine());
		srcstr += expr + ";\n" ;
		
		if (size != r) srcstr += "}\n";

		srcstr += "}\n";

//		cout<<srcstr<<"\n";
		log_kernel(srcstr);

		void* clh = clsopen(__CLCONTEXT,srcstr.c_str(),CLLD_NOW);
		krn = clsym(__CLCONTEXT,clh,"kern",CLLD_NOW);
	}

	if (krn) {

		clndrange_t ndr = clndrange_init1d(0,r,__WGSIZE);

	int n = 0;	
	for( rlist_t::iterator it = rlista.begin(); it!=rlista.end(); it++,n++) {
		size_t sz = (*it).sz;
		if (sz > 0) {
			int dummy;
			clSetKernelArg(krn,n,sz,(*it).ptr);
		} else { 


#if defined(__CLMULTI_ARRAY_FULLAUTO)
			clmattach(__CLCONTEXT,(void*)(*it).memptr);
			clmsync(__CLCONTEXT,0,(void*)(*it).memptr,CL_MEM_DEVICE|CL_EVENT_NOWAIT);
#endif

			clarg_set_global(__CLCONTEXT,krn,n,(void*)(*it).memptr);
//			(*it).ptr->clarg_set_global(__CLCONTEXT,krn,n);

		}
	}

	clarg_set(__CLCONTEXT,krn,n,size);
	clarg_set(__CLCONTEXT,krn,n+1,size2);
	clarg_set(__CLCONTEXT,krn,n+2,size3);
	clarg_set(__CLCONTEXT,krn,n+3,size4);


		clfork(__CLCONTEXT,0,krn,&ndr,CL_EVENT_NOWAIT);

#if defined(__CLMULTI_ARRAY_FULLAUTO)

		clmsync(__CLCONTEXT,0,lhs.data(),CL_MEM_HOST|CL_EVENT_NOWAIT);

		clwait(__CLCONTEXT,0,CL_KERNEL_EVENT|CL_MEM_EVENT);

	n = 0;	
	for( rlist_t::iterator it = rlista.begin(); it!=rlista.end(); it++,n++) {
		size_t sz = (*it).sz;
		if (sz > 0) {
		} else { 

			clmdetach((void*)(*it).memptr);

		}
	}

#elif defined(__CLMULTI_ARRAY_SEMIAUTO)

		clwait(__CLCONTEXT,0,CL_KERNEL_EVENT);

#endif


	}


#else

      for (int i = 0; i < lhs.shape()[0]; ++i) 
      for (int j = 0; j < lhs.shape()[1]; ++j) 
      for (int k = 0; k < lhs.shape()[2]; ++k) 
      for (int l = 0; l < lhs.shape()[3]; ++l) {
          op(lhs[i][j][k][l], forEach(rhs, EvalLeaf4(i,j,k,l), OpCombine()));
        }

#endif


    } else {
      cerr << "Error: LHS and RHS don't conform." << endl;
      exit(1);
    }
}

#endif // _CLMULTI_ARRAY_CLETE_H

