/* PrintType.h
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

#ifndef _PRINTTYPE_H
#define _PRINTTYPE_H

#include <iostream>
#include <list>
#include <string>
#include <sstream>
using namespace std;

#include <stdcl.h>
//#include <clvector.h>

typedef cl_int2 int2;
typedef cl_int4 int4;
typedef cl_float2 float2;
typedef cl_float4 float4;
template <class T>
struct PrintType {
   inline static std::string type_str() { return "-str-unknown@ "; }
};

// int

template <>
struct PrintType< int > {
   inline static std::string type_str() { return "int"; }
};

// int2

template <>
struct PrintType< int2 > {
   inline static std::string type_str() { return "int2"; }
};

// int4

template <>
struct PrintType< int4 > {
   inline static std::string type_str() { return "int4"; }
};

// float

template <>
struct PrintType< float > {
   inline static std::string type_str() { return "float"; }
};

// float2

template <>
struct PrintType< float2 > {
   inline static std::string type_str() { return "float2"; }
};

// float4

template <>
struct PrintType< float4 > {
   inline static std::string type_str() { return "float4"; }
};

// double

template <>
struct PrintType< double > {
   inline static std::string type_str() { return "double"; }
};

#endif
