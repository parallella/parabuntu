
# CLRPC: OpenCL Remote Procedure Calls {#clrpc}

## Overview of OpenCL Remote Procedure Calls (RPC)

CLRPC provides an OpenCL Remote Procedure Call (RPC) implementation that allows
OpenCL host calls to be executed on remote platforms.  By design this may
require no changes at all to the host application when using the OpenCL loader
provided with the COPRTHR SDK.  For more complex and specialized applications,
client host code can be linked directly with libclrpc and a few extensions are
provided for specifying the remote CLRPC server or servers tht the application
should be connected to.

At the present time many of the complex OpenCL semantics have been tested,
e.g., `clEnqueueMapBuffer()`, that prove challenging to execute using RPC.
However, the user is cautioned that not all such complex scenarios have been
fully tested.  For the most typical scenarios the behavior using CLRPC should
be consistent with that of a local platform implementation.

An obvious question with CLRPC is whether the compute performance of an
accelerator can be accessed over an ordinary network without being undermined
by bandwidth issues.  There is no magic to be found and, much like the early
issues with the PCIe bus transfers dominating any theoretical performance gains
from a GPU, the network latency and bandwidth must be addressed in order to
successfully utilize CLRPC.  Fortunately many examples of use cases can be
identified where the use of remote compute devices can be made ot perform with
an overal advantage in terms of reduced time-to-solution for the compute task
at hand.


## Setting up a CLRPC Server: `clrpcd`

The COPRTHR SDK provides a basic OpenCL server `clrpcd` that may 
be used for exporting the OpenCL support available on a platform over a network.
The server will use the libocl loader to to access the available OpenCL libraries
on the platform.  The usage of `clrpcd` as as follows:

	clrpcd [-a address] [-p port]

Options:

-a address
	: Specify address the server should listen on.

-p
	: Specify the port the server should listen on.

By default the server will bind to `127.0.0.1` port `2112`.
These defaults may be overiden with the command line options as shown.  
The following example shows how to run the server such that it will listen on a
platforms external IP address to export the OpenCL platforms over a network,

	clrpcd -a 192.168.1.5

**Note:** in order to properly function it is necessary to ensure that the
chosen port is open.  The server will export the available OpenCL platforms
using RPC.  At present support may be expected for most of the OpenCL 1.1
standard.

When setting up a CLRPC server it can be useful to enable verbose debugging
output to monitor the operation of `clrpcd`.  This can be done by simply
running the server through the debug interface provided with the COPRTHR SDK,

	cldebug -- clrpcd -a 192.168.1.5 


## Accessing Remote CLRPC Servers From OpenCL

The easiest and most powerful way in which to access OpenCL platforms that have
been exported over a network is to use the features of the OpenCL loader
(`libocl`) provided with the COPRTHR SDK.  Specifically, one or more CLRPC
servers may be specified in an `ocl.conf` file used by `libocl` to setup the
platforms presented to an OpenCL appliation.  The following is an example of a
`clrpc` section that could be added to an ocl.conf file in order to connect to
the CLPRC server setup as described above,

~~~~~~~
clrpc = {
	enable = "yes";
	servers = {
		{ url="192.168.1.5:2112" }
	}
};
~~~~~~~

The *clrpc* section of an `ocl.conf` file can define multiple server
connections.  For more details on the `libocl` loader and `ocl.conf` files, see
the section on [Precise Platform Configuration: `ocl.conf` files](#oclconf).
This raises an important issue that must be resolved in the host application
when multiple server connections are defined: *exactly how should the
application select the correct platform to use?*  This issue goes deeper than
CLRPC and exposes a problem with the OpenCL approach to the concept of a
"platform" that may be decribed as the vendor platform barrier.  A more
complete discussion of this issue is provided below along with a solution
through the use of the STDCL context `stdnpu` that includes all networked
devices.  The simple answer to question stated above is that one must still
select a single platform, whether local or remote, based on the name of the
platform, and construct an OpenCL context and get device IDs as one is normally
required to do in OpenCL.  If one wants to use multiple CLRPC servers this
would then mean managing multiple platforms at the application level.  As an
alternative, the introduction of a more precise mechanism for specifying OpenCL
platforms (`ocl.conf`) to be presented to an allication using the `libocl`
loader can be used for controlling individual CLRPC server that an application
uses.  Fortunately STDCL provides a better way provided (`stdnpu`).


## OpenCL Extensions for More Control

For some specialized applications it may be desireable to link to the
`libclrpc` OpenCL implementation directly and set the remote CLRPC server
connections from within a client application, by passing entirely the use of an
OpenCL platform loader.  For this purpose, extensions are provided for defining
CLRPC server connections prior to the OpenCL call `clGetPlatformIDs()`.  

The following example shows the current API extension.  However **please note**
that these extensions are not fully developed and should be expected to be
changed in subsequented releases.  The are described here only because they may
be of interest for early experimentation by developers.  Programmers are
strongly encouraged to use the method described above involving the use of
`ocf.conf` files for defining connections to CLRPC servers.

~~~~~~~
#include "CL/cl.h"
#include "clrpcd.h"

int main() 
{

	clrpc_server_info servers[] = {
		{ "192.168.1.5", 2112 },
		{ "192.168.1.6", 2112 },
		{ "192.168.1.7", 2114 },
	};

	if ( clrpc_connect(3,servers) )
		fprintf(stderr,"clrpc_connect() returned an error\n");

	...

	clGetPlatformIDs( ... );

}
~~~~~~~

Note that the CLRPC servers *must* be defined prior to the `clGetPlatformIDs()`
call.  (This requirement should make sense upon consideration of the purpose of
the `clGetPlatformIDs` call.)


## A STDCL Context for All Networked Devices: `stdnpu`

One problem with CLRPC that stems from the design of OpenCL itself is that
each CLRPC server will export one or more OpenCL "platforms" which are 
in all practical terms not interoperable in any way.  This is the platform
wall, an unfortunate design choice that was unncessary.  

The STDCL context stdnpu resloves this issue by creating a super-context
that will consist of all networked devices regardless of platform.  This
makes the use of networked devices in code already designed for multiple
devices as simple as replacing, e.g., stdgpu with stdnpu.


