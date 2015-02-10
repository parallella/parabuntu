# Overview of Libraries and Tools

The CO-PRocessing THReads (COPRTHR) SDK provides libraries and tools for
 developing applications that target the multi-threaded co-processing
 parallelism of modern
 multi-core and many-core processors. This includes heterogeneous CPU/GPU hybrid
 systems and other emerging processor architectures. The COPRTHR SDK leverages
 upon OpenCL and may be used to develop OpenCL enabled applications. The range
 of hardware supported by the SDK is limited only by the availability of a
 suitable OpenCL implementation, and includes support for processors from AMD,
 Intel, and Nvidia. For architectures and operating systems for which a vendor
 implementation of OpenCL is not available, COPRTHR provides an open-source
 OpenCL implementation for multi-core x86, ARM and Epiphany processors. 
 The primary
 operating system supported by the SDK is Linux. However, limited support is
 provided for Windows 7 and FreeBSD-8. 
 The software stack for COPRTHR is shown
 in the figure below along with additional 3rd-party software that the SDK
 supports. 

![COPRTHR SDK Software Stack](COPRTHR_SDK_software_stack.png "COPRTHR SDK Software Stack")

## STDCL

The STandarD Compte Layer (STDCL) is a powerful API built on top of 
OpenCL that is much easier to use than OpenCL itself. STDCL (STandarD Compute 
Layer) has been developed as an API for OpenCL applications in order to simplify 
application development and introduce more intuitive programming semantics. 
STDCL is designed in a style inspired by conventional UNIX APIs for C 
programming, and may be used directly in C/C++ applications, with additional 
support for Fortran through direct API bindings.

The STDCL API provides support for default compute contexts, an integrated
 dynamic CL program loader, memory management, kernel management, and scheduling
 for asynchronous operations. Environment variables provide run-time control
 over certain aspects of the API including the prioritized selection of
 platforms and the management of co-processing resources across multiple
 processes. This support is especially useful in providing transparent support
 for MPI-based parallelism on multi-GPU systems.

STDCL replaces tedious low-level OpenCL host calls with semantics that better 
address the real programming requirements for application developers. At the 
same time, the API does not inhibit direct access to OpenCL host calls and data 
structures for the infrequent cases where they are actually needed.

## clcc

The SDK provides an offline compiler and linker for multi-vendor 
multi-device cross-compilation that employs a real compilation model. This is 
achieved by defining extensions to the standard ELF sections of an ordinary 
object file or executable capable of representing OpenCL kernel programs in 
source and binary form. These sections are capable of supporting the full range 
of cross-compilation that a programmer will encounter when developing 
applications designed to utilize co-processing devices. 
The offline compiler and linker are designed to behave the way a programmer
would expect them to behave and fit seamlessly into the normal GCC-type
workflow employed by serious programmers developing serious applications.

## libclelf

The ELF extensions for OpenCL (CL-ELF) are formally implemented withing the
library libclelf which is use by the offline compiler and linker to create
cross-compiled linkable object files. The dynamic loader that is provided as
part of the STDCL implementation uses this same library to load the correct
source or binary kernel for use within an application. 

## libocl

The SDK includes an OpenCL loader that is 
backward compatible with the conventional libOpenCL ICD loader. The purpose of 
libocl.so, which may be aliased to libOpenCL.so, is to provide a much greater 
set of capabilities than what is provided with the standard loader. Among these 
capabilities are more sensible system configuraton and resource management 
options, as well as the creation of custom contexts based on the hardware that 
is actually installed on a given system. OpenCL platform configuration issues 
are more reliably addressed by the user or system administrator, and not the 
application developer.  Additionally, libocl provides extensible hooks and
accounting support, as well as direct support for CLRPC.


## libcoprthr

The SDK includes an open source OpenCL implementation for 
x86, ARM and Epiphany multi-core 
processors. This implementation can be useful on architectures and operating 
systems for which no vendor provided OpenCL implementation is available. 
Additionally, this implementation has proven to yield faster benchmarks than 
vendor provided x86 implementions on certain real-world HPC benchmarks.

## libclrpc/clrpcd

The SDK includes a Compute Layer Remote Procedure Call (CLRPC) implementation
that consists of a client-side RPC OpenCL implementation, libclrpc, and 
a CLRPC server, clrpcd, that is used to export local OpenCL implementations
over a network.  CLRPC allows OpenCL host applications to access networked
compute devices.


