/* PrintF.h
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

#ifndef _PRINTF_H
#define _PRINTF_H

#include <iostream>
#include <list>
#include <string>
#include <sstream>
using namespace std;

#include <stdcl.h>
//#include <clvector.h>

#include "CLETE/PrintType.h"

template <class T>
struct PrintF {

	inline static std::string type_str( std::string x ) 
	{ return "@arg-str-unknown@:" + x; }

	inline static std::string arg_str( std::string x ) 
	{ return "@arg-str-unknown@:" + x; }

	inline static std::string tmp_decl_str( std::string x ) 
	{ return "@tmp-decl-str-unknown@:" + x; }

	inline static std::string tmp_ref_str( std::string x ) 
	{ return "@tmp-ref-str-unknown@:" + x; }

	inline static std::string store_str( std::string x ) 
	{ return "@tmp-store-str-unknown@:" + x; }

};

template < class T > 
struct PrintF< Scalar<T> > { 

	inline static std::string type_str() 
	{ return PrintType<T>::type_str(); }

	inline static std::string arg_str( std::string x) 
	{ return "a" + x; }

	inline static std::string tmp_decl_str( std::string x ) 
	{ return PrintType<T>::type_str() + " tmp" + x + " = a" + x; }

	inline static std::string tmp_ref_str( std::string x ) 
	{ return "tmp" + x; }

	inline static std::string store_str( std::string x ) 
	{ return "a" + x; }

};


#endif

