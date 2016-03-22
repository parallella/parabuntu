/* coprthr_cc.h
 *
 * Copyright (c) 2013 Brown Deer Technology, LLC.  All Rights Reserved.
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

#ifndef _coprthr_cc_h
#define _coprthr_cc_h

#include "coprthr.h"
#include "coprthr_program.h"


/***
 *** typdefs for opaque types
 ***/

//typedef struct coprthr1_program* coprthr_program_t;
//typedef struct coprthr1_kernel* coprthr_kernel_t;

typedef struct coprthr_kernel* coprthr_symbol_t; /* alias */

#define COPRTHR_CC_TARGET_X86_64 "-mtarget=x86_64"
#define COPRTHR_CC_TARGET_I386 "-mtarget=i386"
#define COPRTHR_CC_TARGET_ARM32 "-mtarget=arm32"
#define COPRTHR_CC_TARGET_E32_EMEK "-mtarget=e32_emek"
#define COPRTHR_CC_TARGET_E32 "-mtarget=e32"
#define COPRTHR_CC_TARGET_ARM32_ANDROID "-mtarget=arm32_android"
#define COPRTHR_CC_TARGET_MIC "-mtarget=mic"

coprthr_program_t 
	coprthr_cc( const char* src, size_t len, const char* opt, char** log );

size_t coprthr_cc_write_bin( const char* path, coprthr_program_t prg, int flags );

coprthr_program_t coprthr_cc_read_bin( const char* path, int flags );


#endif

