/* clforka.h
 *
 * Copyright (c) 2011 Brown Deer Technology, LLC.  All Rights Reserved.
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

#ifndef _CLFORKA_H
#define _CLFORKA_H

#ifndef _STDCL_H
#error Do not include clforka.h directly, include stdcl.h instead.
#endif

#define __VA_NARGS__(...) __VANUMARGS(__VA_ARGS__,__VANUMARGS_RSEQ_N())

#define __VANUMARGS(...) __VANUMARGS_N(__VA_ARGS__)

#define __VANUMARGS_N( \
	_1, _2, _3, _4, _5, _6, _7, _8, _9, \
	_10, _11, _12, _13, _14, _15, _16, _17, _18, _19, \
	_20, _21, _22, _23, _24, _25, _26, _27, _28, _29, \
	_30, _31, _32, _33, _34, _35, _36, _37, _38, _39, \
	_40, _41, _42, _43, _44, _45, _46, _47, _48, _49, \
	_50, _51, _52, _53, _54, _55, _56, _57, _58, _59, \
	_60, _61, _62, _63, \
	N, ... ) N

#define __VANUMARGS_RSEQ_N() 63,62,61,60, \
	59,58,57,56,55,54,53,52,51,50, \
	49,48,47,46,45,44,43,42,41,40, \
	39,38,37,36,35,34,33,32,31,30, \
	29,28,27,26,25,24,23,22,21,20, \
	19,18,17,16,15,14,13,12,11,10, \
	9,8,7,6,5,4,3,2,1,0


#define __concat(func,nargs) func ## nargs

#define clforka( cp, devnum, krn, p_ndr, flags, ... ) ({ cl_event ev; do { \
	__clarg_set_(__VA_NARGS__(__VA_ARGS__)) \
		( cp, krn, 0, __VA_ARGS__); \
	ev = clfork(cp,devnum,krn,p_ndr,flags); \
} while(0); ev; })

#define __clarg_set_(nargs)__concat(__clarg_set,nargs)

#define __clarg_set1( cp, krn, n, a0 ) do { __clarg_set(cp,krn,n,a0); } while(0)

#define __clarg_set2(cp,krn,n,a0,a1) do { __clarg_set(cp,krn,n,a0);__clarg_set1(cp,krn,n+1,a1); } while(0)
#define __clarg_set3(cp,krn,n,a0,a1,a2) do { __clarg_set(cp,krn,n,a0);__clarg_set2(cp,krn,n+1,a1,a2); } while(0)
#define __clarg_set4(cp,krn,n,a0,a1,a2,a3) do { __clarg_set(cp,krn,n,a0);__clarg_set3(cp,krn,n+1,a1,a2,a3); } while(0)
#define __clarg_set5(cp,krn,n,a0,a1,a2,a3,a4) do { __clarg_set(cp,krn,n,a0);__clarg_set4(cp,krn,n+1,a1,a2,a3,a4); } while(0)
#define __clarg_set6(cp,krn,n,a0,a1,a2,a3,a4,a5) do { __clarg_set(cp,krn,n,a0);__clarg_set5(cp,krn,n+1,a1,a2,a3,a4,a5); } while(0)
#define __clarg_set7(cp,krn,n,a0,a1,a2,a3,a4,a5,a6) do { __clarg_set(cp,krn,n,a0);__clarg_set6(cp,krn,n+1,a1,a2,a3,a4,a5,a6); } while(0)
#define __clarg_set8(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7) do { __clarg_set(cp,krn,n,a0);__clarg_set7(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7); } while(0)
#define __clarg_set9(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8) do { __clarg_set(cp,krn,n,a0);__clarg_set8(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8); } while(0)
#define __clarg_set10(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9) do { __clarg_set(cp,krn,n,a0);__clarg_set9(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9); } while(0)
#define __clarg_set11(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10) do { __clarg_set(cp,krn,n,a0);__clarg_set10(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10); } while(0)
#define __clarg_set12(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11) do { __clarg_set(cp,krn,n,a0);__clarg_set11(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11); } while(0)
#define __clarg_set13(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12) do { __clarg_set(cp,krn,n,a0);__clarg_set12(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12); } while(0)
#define __clarg_set14(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13) do { __clarg_set(cp,krn,n,a0);__clarg_set13(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13); } while(0)
#define __clarg_set15(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14) do { __clarg_set(cp,krn,n,a0);__clarg_set14(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14); } while(0)
#define __clarg_set16(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15) do { __clarg_set(cp,krn,n,a0);__clarg_set15(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15); } while(0)
#define __clarg_set17(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16) do { __clarg_set(cp,krn,n,a0);__clarg_set16(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16); } while(0)
#define __clarg_set18(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17) do { __clarg_set(cp,krn,n,a0);__clarg_set17(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17); } while(0)
#define __clarg_set19(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18) do { __clarg_set(cp,krn,n,a0);__clarg_set18(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18); } while(0)
#define __clarg_set20(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19) do { __clarg_set(cp,krn,n,a0);__clarg_set19(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19); } while(0)
#define __clarg_set21(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20) do { __clarg_set(cp,krn,n,a0);__clarg_set20(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20); } while(0)
#define __clarg_set22(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21) do { __clarg_set(cp,krn,n,a0);__clarg_set21(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21); } while(0)
#define __clarg_set23(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22) do { __clarg_set(cp,krn,n,a0);__clarg_set22(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22); } while(0)
#define __clarg_set24(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23) do { __clarg_set(cp,krn,n,a0);__clarg_set23(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23); } while(0)
#define __clarg_set25(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24) do { __clarg_set(cp,krn,n,a0);__clarg_set24(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24); } while(0)
#define __clarg_set26(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25) do { __clarg_set(cp,krn,n,a0);__clarg_set25(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25); } while(0)
#define __clarg_set27(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26) do { __clarg_set(cp,krn,n,a0);__clarg_set26(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26); } while(0)
#define __clarg_set28(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27) do { __clarg_set(cp,krn,n,a0);__clarg_set27(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27); } while(0)
#define __clarg_set29(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28) do { __clarg_set(cp,krn,n,a0);__clarg_set28(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28); } while(0)
#define __clarg_set30(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29) do { __clarg_set(cp,krn,n,a0);__clarg_set29(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29); } while(0)
#define __clarg_set31(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30) do { __clarg_set(cp,krn,n,a0);__clarg_set30(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30); } while(0)
#define __clarg_set32(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31) do { __clarg_set(cp,krn,n,a0);__clarg_set31(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31); } while(0)
#define __clarg_set33(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32) do { __clarg_set(cp,krn,n,a0);__clarg_set32(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32); } while(0)
#define __clarg_set34(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33) do { __clarg_set(cp,krn,n,a0);__clarg_set33(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33); } while(0)
#define __clarg_set35(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34) do { __clarg_set(cp,krn,n,a0);__clarg_set34(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34); } while(0)
#define __clarg_set36(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35) do { __clarg_set(cp,krn,n,a0);__clarg_set35(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35); } while(0)
#define __clarg_set37(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36) do { __clarg_set(cp,krn,n,a0);__clarg_set36(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36); } while(0)
#define __clarg_set38(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37) do { __clarg_set(cp,krn,n,a0);__clarg_set37(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37); } while(0)
#define __clarg_set39(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38) do { __clarg_set(cp,krn,n,a0);__clarg_set38(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38); } while(0)
#define __clarg_set40(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39) do { __clarg_set(cp,krn,n,a0);__clarg_set39(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39); } while(0)
#define __clarg_set41(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40) do { __clarg_set(cp,krn,n,a0);__clarg_set40(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40); } while(0)
#define __clarg_set42(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41) do { __clarg_set(cp,krn,n,a0);__clarg_set41(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41); } while(0)
#define __clarg_set43(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42) do { __clarg_set(cp,krn,n,a0);__clarg_set42(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42); } while(0)
#define __clarg_set44(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43) do { __clarg_set(cp,krn,n,a0);__clarg_set43(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43); } while(0)
#define __clarg_set45(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44) do { __clarg_set(cp,krn,n,a0);__clarg_set44(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44); } while(0)
#define __clarg_set46(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45) do { __clarg_set(cp,krn,n,a0);__clarg_set45(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45); } while(0)
#define __clarg_set47(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46) do { __clarg_set(cp,krn,n,a0);__clarg_set46(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46); } while(0)
#define __clarg_set48(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47) do { __clarg_set(cp,krn,n,a0);__clarg_set47(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47); } while(0)
#define __clarg_set49(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48) do { __clarg_set(cp,krn,n,a0);__clarg_set48(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48); } while(0)
#define __clarg_set50(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49) do { __clarg_set(cp,krn,n,a0);__clarg_set49(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49); } while(0)
#define __clarg_set51(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50) do { __clarg_set(cp,krn,n,a0);__clarg_set50(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50); } while(0)
#define __clarg_set52(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51) do { __clarg_set(cp,krn,n,a0);__clarg_set51(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51); } while(0)
#define __clarg_set53(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52) do { __clarg_set(cp,krn,n,a0);__clarg_set52(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52); } while(0)
#define __clarg_set54(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53) do { __clarg_set(cp,krn,n,a0);__clarg_set53(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53); } while(0)
#define __clarg_set55(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54) do { __clarg_set(cp,krn,n,a0);__clarg_set54(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54); } while(0)
#define __clarg_set56(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55) do { __clarg_set(cp,krn,n,a0);__clarg_set55(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55); } while(0)
#define __clarg_set57(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56) do { __clarg_set(cp,krn,n,a0);__clarg_set56(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56); } while(0)
#define __clarg_set58(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57) do { __clarg_set(cp,krn,n,a0);__clarg_set57(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57); } while(0)
#define __clarg_set59(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58) do { __clarg_set(cp,krn,n,a0);__clarg_set58(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58); } while(0)
#define __clarg_set60(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59) do { __clarg_set(cp,krn,n,a0);__clarg_set59(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59); } while(0)
#define __clarg_set61(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60) do { __clarg_set(cp,krn,n,a0);__clarg_set60(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60); } while(0)
#define __clarg_set62(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61) do { __clarg_set(cp,krn,n,a0);__clarg_set61(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61); } while(0)
#define __clarg_set63(cp,krn,n,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62) do { __clarg_set(cp,krn,n,a0);__clarg_set62(cp,krn,n+1,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21,a22,a23,a24,a25,a26,a27,a28,a29,a30,a31,a32,a33,a34,a35,a36,a37,a38,a39,a40,a41,a42,a43,a44,a45,a46,a47,a48,a49,a50,a51,a52,a53,a54,a55,a56,a57,a58,a59,a60,a61,a62); } while(0)

#define __iftype_clarg_set(cp,krn,ia,a,t) \
	if (__builtin_types_compatible_p(typeof(a),t)) clarg_set(cp,krn,ia,(a)); \
	else if (__builtin_types_compatible_p(typeof(a),t*)) \
		clarg_set_global(cp,krn,ia,(t*)(intptr_t)(a));

#ifdef __cplusplus

inline static
void __clarg_set(CLCONTEXT* cp, cl_kernel krn, unsigned int ia, cl_int a)
{ ::clarg_set(cp,krn,ia,(a)); }
inline static
void __clarg_set( CLCONTEXT* cp, cl_kernel krn, unsigned int ia, cl_uint a)
{ ::clarg_set(cp,krn,ia,(a)); }
inline static
void __clarg_set( CLCONTEXT* cp, cl_kernel krn, unsigned int ia, cl_float a)
{ ::clarg_set(cp,krn,ia,(a)); }
inline static
void __clarg_set( CLCONTEXT* cp, cl_kernel krn, unsigned int ia, cl_int2 a)
{ ::clarg_set(cp,krn,ia,(a)); }
inline static
void __clarg_set( CLCONTEXT* cp, cl_kernel krn, unsigned int ia, cl_uint2 a)
{ ::clarg_set(cp,krn,ia,(a)); }
inline static
void __clarg_set( CLCONTEXT* cp, cl_kernel krn, unsigned int ia, cl_float2 a)
{ ::clarg_set(cp,krn,ia,(a)); }
inline static
void __clarg_set( CLCONTEXT* cp, cl_kernel krn, unsigned int ia, cl_int4 a)
{ ::clarg_set(cp,krn,ia,(a)); }
inline static
void __clarg_set( CLCONTEXT* cp, cl_kernel krn, unsigned int ia, cl_uint4 a)
{ ::clarg_set(cp,krn,ia,(a)); }
inline static
void __clarg_set( CLCONTEXT* cp, cl_kernel krn, unsigned int ia, cl_float4 a)
{ ::clarg_set(cp,krn,ia,(a)); }
inline static
void __clarg_set( CLCONTEXT* cp, cl_kernel krn, unsigned int ia, void* a)
{ ::clarg_set_global(cp,krn,ia,(a)); }

#else

#define __clarg_set(cp,krn,ia,a) \
({ \
__iftype_clarg_set(cp,krn,ia,a,cl_int) \
else __iftype_clarg_set(cp,krn,ia,a,cl_char) \
else __iftype_clarg_set(cp,krn,ia,a,cl_uchar) \
else __iftype_clarg_set(cp,krn,ia,a,cl_uint) \
else __iftype_clarg_set(cp,krn,ia,a,cl_float) \
else __iftype_clarg_set(cp,krn,ia,a,cl_double) \
else __iftype_clarg_set(cp,krn,ia,a,cl_int2) \
else __iftype_clarg_set(cp,krn,ia,a,cl_uint2) \
else __iftype_clarg_set(cp,krn,ia,a,cl_float2) \
else __iftype_clarg_set(cp,krn,ia,a,cl_double2) \
else __iftype_clarg_set(cp,krn,ia,a,cl_int4) \
else __iftype_clarg_set(cp,krn,ia,a,cl_uint4) \
else __iftype_clarg_set(cp,krn,ia,a,cl_float4) \
else { fprintf(stderr,"__clarg_set: unrecognized type\n"); exit(-1); } \
})

#endif

#endif

