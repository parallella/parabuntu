/* Combiners.h
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
// $RCSfile: Combiners.h,v $   $Author: sa_smith $
// $Revision: 1.8 $   $Date: 2000/08/03 00:12:18 $
// ----------------------------------------------------------------------

/* DAR */

#ifndef _COMBINERS_H
#define _COMBINERS_H

///////////////////////////////////////////////////////////////////////////////
//
// WARNING: THIS FILE IS FOR INTERNAL PETE USE. DON'T INCLUDE IT YOURSELF
//
///////////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------------
//
// CLASS NAMES
//   Combine1<A,Op,Tag>
//   Combine2<A,B,Op,Tag>
//   Combine3<A,B,C,Op,Tag>
//
// DESCRIPTION
//   A,B, and C are the types of the combined arguments
//   Op is the type of the operator from the expression tree
//   Tag is the tag type which selects the type of combiner operation
//
//   Users create their own combiner operations by specializing these
//   three structs for a particular user defined tag.  A typical example
//   might be an operation that compares the domains of all the leaves in
//   an expression.
//
//   Combine1 requires the user to define:
//      typedef ... Type_t;
//         - the return type of the combination
//      static Type_t combine(const A &a, const Op &op, const Tag &t) {}
//         - a function that combines a
//
//   Combine2 requires the user to define:
//      typedef ... Type_t;
//         - the return type of the combination
//      static Type_t combine(const A &a, const B &b, const Op &op, 
//         const Tag &t) {}
//         - a function that combines a and b
//
//   Combine3 requires the user to define:
//      typedef ... Type_t;
//         - the return type of the combination
//      static Type_t combine(const A &a, const B &b, const C &c,
//         const const Op &op, const Tag &t) {}
//         - a function that combines a and b and c
//
//   The default actions for combiners are:
//
//      Combine1 - returns the arguments
//      Combine2 - no default action... the user must define this at least
//      Combine3 - uses Combine2 to combine a and b and combine that with c
//
//-----------------------------------------------------------------------------

template<class A, class Op, class Tag>
struct Combine1
{
  typedef A Type_t;
  inline static
  Type_t combine(const A &a, const Op &, const Tag &) { return a; }
};

template<class A, class B, class Op, class Tag>
struct Combine2
{
  // no default action.  It's an error to not specialize this struct.
};

template<class A,class B,class C,class Op,class Tag>
struct Combine3
{
  typedef typename Combine2<A, B, Op, Tag>::Type_t Type1_t;
  typedef typename Combine2<Type1_t, C, Op, Tag>::Type_t Type_t;
  inline static
  Type_t combine(const A& a,const B& b,const C& c,const Op& op,const Tag& t)
  {
    return
      Combine2<Type1_t, C,
      Op, Tag>::combine(Combine2<A, B, Op, Tag>::combine(a,b,op,t),c,op,t);
  }
};

//-----------------------------------------------------------------------------
//
// FUNCTION NAME
//   peteCombine()
//
// DESCRIPTION
//   These functions provide a simple user interface to PETE's CombineN
//   functors.  For example:
//
//   peteCombine(a, b, op, tag);
//
//   is a synonym for:
//
//   Combine2<A, B, Op, Tag>::combine(a, b, op, tag);
//
//-----------------------------------------------------------------------------

template<class A, class Op, class Tag>
inline typename Combine1<A, Op, Tag>::Type_t
peteCombine(const A &a, const Op &op, const Tag &t)
{
  return Combine1<A, Op, Tag>::combine(a, op, t);
}

template<class A, class B, class Op, class Tag>
inline typename Combine2<A, B, Op, Tag>::Type_t
peteCombine(const A &a, const B &b, const Op &op, const Tag &t)
{
  return Combine2<A, B, Op, Tag>::combine(a, b, op, t);
}

template<class A, class B, class C, class Op, class Tag>
inline typename Combine3<A, B, C, Op, Tag>::Type_t
peteCombine(const A &a, const B &b, const C &c, const Op &op, const Tag &t)
{
  return Combine3<A, B, C, Op, Tag>::combine(a, b, c, op, t);
}

//-----------------------------------------------------------------------------
//
// CLASS NAME
//   TreeCombine
//
// DESCRIPTION
//   This combiner is provided so that the user can write a functor
//   that modifies the leaves of an expression and use
//   ForEach<Expr,UserFunctor,TreeCombine> to get the entire expression
//   back with modified leaves.
//
//   This type of operation is useful when expressions are being
//   passed around.  For example, you might subset and expression and pass
//   that result to another function.  The type of expression tree that you
//   are passing has subsetted nodes, and could be a different type from the
//   original expression.
//
//-----------------------------------------------------------------------------

struct TreeCombine
{
  PETE_EMPTY_CONSTRUCTORS(TreeCombine)
};

template<class A, class Op>
struct Combine1<A, Op, TreeCombine >
{
  typedef UnaryNode<Op, A> Type_t;
  inline static
  Type_t combine(const A &a, const Op &op, const TreeCombine &t)
  {
    return Type_t(op, a);
  }
};

template<class A, class B, class Op>
struct Combine2<A, B, Op, TreeCombine >
{
  typedef BinaryNode<Op, A, B> Type_t;
  inline static
  Type_t combine(const A &a, const B &b, const Op &op, 
    const TreeCombine &t) 
  {
    return Type_t(op, a, b);
  }
};

template<class A, class B, class C, class Op>
struct Combine3<A, B, C, Op, TreeCombine >
{
  typedef TrinaryNode<Op, A, B, C> Type_t;
  inline static
  Type_t combine(const A &a, const B &b, const C &c, const Op &op,
    const TreeCombine &t) 
  {    
    return Type_t(op, a, b, c);
  }
};


//-----------------------------------------------------------------------------
//
// CLASS NAME
//   OpCombine
//
// DESCRIPTION
//   A combiner that uses the operations in the expression tree.
//
//-----------------------------------------------------------------------------

struct OpCombine
{
  PETE_EMPTY_CONSTRUCTORS(OpCombine)
};

template<class A,class Op>
struct Combine1<A, Op, OpCombine>
{
  typedef typename UnaryReturn<A, Op>::Type_t Type_t;
  inline static
  Type_t combine(A a, Op op, OpCombine) { return op(a); }
};

template<class A,class B,class Op>
struct Combine2<A, B, Op, OpCombine>
{
  typedef typename BinaryReturn<A, B, Op>::Type_t Type_t;
  inline static
  Type_t combine(A a, B b, Op op, OpCombine)
  {
    return op(a, b);
  }
};

template<class A,class B,class C,class Op>
struct Combine3<A, B, C, Op, OpCombine>
{
  typedef typename TrinaryReturn<A, B, C, Op>::Type_t Type_t;
  inline static
  Type_t combine(A a, B b, C c, Op op, OpCombine)
  {
    return op(a, b, c);
  }
};


//-----------------------------------------------------------------------------
//
// CLASS NAME
//   AndCombine
//
// DESCRIPTION
//   A handy combiner for extracting bool queries from expressions.
//
//-----------------------------------------------------------------------------

struct AndCombine
{
  PETE_EMPTY_CONSTRUCTORS(AndCombine)
};

template<class Op>
struct Combine2<bool, bool, Op, AndCombine>
{
  typedef bool Type_t;
  inline static
  Type_t combine(bool a, bool b, Op, AndCombine)
  {
    return (a && b);
  }
};


//-----------------------------------------------------------------------------
//
// CLASS NAME
//   OrCombine
//
// DESCRIPTION
//   A handy combiner for extracting bool queries from expressions.
//
//-----------------------------------------------------------------------------

struct OrCombine
{
  PETE_EMPTY_CONSTRUCTORS(OrCombine)
};

template<class Op>
struct Combine2<bool, bool, Op, OrCombine>
{
  typedef bool Type_t;
  inline static
  Type_t combine(bool a, bool b, Op, OrCombine)
  {
    return (a || b);
  }
};


//-----------------------------------------------------------------------------
//
// CLASS NAME
//   NullCombine
//
// DESCRIPTION
//   This combiner doesn't do anything. Used when the combination isn't meant
//   return anything since combiners cannot return void.
//
//-----------------------------------------------------------------------------

struct NullCombine
{
  PETE_EMPTY_CONSTRUCTORS(NullCombine)
};

template<class Op>
struct Combine2<int, int, Op, NullCombine>
{
  typedef int Type_t;
  inline static
  Type_t combine(int, int, Op, NullCombine)
  {
    return 0;
  }
};


//-----------------------------------------------------------------------------
//
// CLASS NAME
//   SumCombine
//
// DESCRIPTION
//   This combiner can be used to count things in expressions.
//
//-----------------------------------------------------------------------------

struct SumCombine
{
  PETE_EMPTY_CONSTRUCTORS(SumCombine)
};

template<class Op>
struct Combine2<int, int, Op, SumCombine>
{
  typedef int Type_t;
  inline static
  Type_t combine(int a, int b, Op, SumCombine)
  {
    return a + b;
  }
};


/***
 *** bitwise-and combiner
 ***/

struct AndBitsCombine
{
  PETE_EMPTY_CONSTRUCTORS(AndBitsCombine)
};

template<class Op>
struct Combine2<intptr_t, intptr_t, Op, AndBitsCombine>
{
  typedef intptr_t Type_t;
  inline static
  Type_t combine(intptr_t a, intptr_t b, Op, AndBitsCombine)
  {
    return (a & b);
  }
};


/***
 *** print combiner
 ***/

struct PrintCombine
{
  PETE_EMPTY_CONSTRUCTORS(PrintCombine)
};

template<class A,class Op>
struct Combine1<A, Op, PrintCombine>
{
  typedef std::string Type_t;
  inline static
  Type_t combine(A a, Op op, PrintCombine)
   { return Op::strexpr(a); }
};

template<class A,class B,class Op>
struct Combine2<A, B, Op, PrintCombine>
{
  typedef std::string Type_t;
  inline static
  Type_t combine(A a, B b, Op op, PrintCombine)
  {
    return Op::strexpr(a,b);
  }
};

template<class A,class B,class C,class Op>
struct Combine3<A, B, C, Op, PrintCombine>
{
  typedef std::string Type_t;
  inline static
  Type_t combine(A a, B b, C c, Op op, PrintCombine)
  {
    return Op::strexpr(a,b,c);
  }
};


/***
 *** list combiner
 ***/

template < class T >
struct ListCombine
{
   typedef T Type_t;
  PETE_EMPTY_CONSTRUCTORS(ListCombine)
};

template < class T >
template<class A,class Op>
struct Combine1<A, Op, ListCombine<T> >
{
  typedef typename std::list<T> Type_t;
  inline static
  Type_t combine(A a, Op op, ListCombine<T>)
   { return a; }
};

template<class T, class A,class B,class Op>
struct Combine2<A, B, Op, ListCombine<T> >
{
  typedef typename std::list<T> Type_t;
  inline static
  Type_t combine(A a, B b, Op op, ListCombine<T>)
  {
    a.splice(a.end(),b);
   return a;
  }
};

template < class T >
template<class A,class B,class C,class Op>
struct Combine3<A, B, C, Op, ListCombine<T> >
{
  typedef typename std::list<T> Type_t;
  inline static
  Type_t combine(A a, B b, C c, Op op, ListCombine<T>)
  {
    a.splice(a.end(),b);
    a.splice(a.end(),c);
   return a;
  }
};

#endif // _COMBINERS_H

