/* stdcl_kernel_openclcompat.h
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

#ifndef _STDCL_H
#error Do not include stdcl_kernel_openclcompat.h directly, include stdcl.h instead.
#endif

#ifndef _STDCL_KERNEL_OPENCLCOMPAT_H
#define _STDCL_KERNEL_OPENCLCOMPAT_H

#define __builtin_vector_char2(x,y)       (char2)(x,y)
#define __builtin_vector_char4(x,y,z,w)   (char4)(x,y,z,w)
#define __builtin_vector_uchar2(x,y)      (uchar2)(x,y)
#define __builtin_vector_uchar4(x,y,z,w)  (uchar4)(x,y,z,w)
#define __builtin_vector_int2(x,y)        (int2)(x,y)
#define __builtin_vector_int4(x,y,z,w)    (int4)(x,y,z,w)
#define __builtin_vector_uint2(x,y)       (uint2)(x,y)
#define __builtin_vector_uint4(x,y,z,w)   (uint4)(x,y,z,w)
#define __builtin_vector_float2(x,y)      (float2)(x,y)
#define __builtin_vector_float4(x,y,z,w)  (float4)(x,y,z,w)
#define __builtin_vector_double2(x,y)     (double2)(x,y)

#endif

