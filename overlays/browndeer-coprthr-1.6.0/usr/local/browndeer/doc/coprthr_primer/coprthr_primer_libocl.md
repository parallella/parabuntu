
# libocl: An OpenCL Loader with Precision and Functionality

## A Replacement for the standard libOpenCL Loader

The 'libocl' library is a backward compatible replacement for the standard
Khronos OpenCL loader, and replaces the ICD platform enumeration 
with a more precise 
and flexible mechanism for defining platform policy and configuration.
In addition, 'libocl' provides features not found with standard OpenCL loaders.

In order to use 'libocl', the user can either modify the library that
applications
are linked against by simply changing '-lOpenCL' to '-locl'.
Alternatively, a soft link can be used to alias the library to the one that
a precompiled application expects to find, i.e.,

	link -s libocl.so libOpenCL.so

With this release, the libocl loader should support applications developed 
with the OpenCL 1.1 specification.


## Precise Platform Configuration: `ocl.conf` files {#oclconf}

The 'libocl' loader replaces the random enumeration of '.icd' files placed in 
the '/etc/OpenCL/vendors/' directory with a precise configuration file that 
may be set by the system admin and then overriden by any user following 
a well-defined ordering of search paths.

The following order for search paths provides for an increasingly specialized 
control over the OpenCL platform configuration that a given application sees.

	./ocl.conf
	./.ocl.conf
	$HOME/ocl.conf
	$HOME/.ocl.conf
	/etc/ocl.conf

The syntax of an 'ocl.conf' file is based on 'libconfig' which is used for
parsing the content.  This syntax provides a compact hierarchical structure
with C-like constructs.  For convenience ordinary C and shell syntax for
comments is respected, allowing the configuration file to be quickly modified to
enable/disable a given line or section.  

The primary section of an 'ocl.conf' file is the *platforms* section, and is
best illustrated by example.

~~~~~~~
platforms = (
	{ platform="coprthr"; lib="libcoprthr.so"; },
#	{ platform="nvidia"; lib="libcuda.so"; },
	{ platform="intel"; lib="libintelocl.so"; }
);
~~~~~~~

In this example, an application would see the OpenCL platforms *coprthr* and
*intel*, but the *nvidia* platform would not be seen since it is commented out.
In this way a system administrator or user can control the OpenCL platforms
presented to an application and not rely upon selection mechanisms, if any,
within an application.  This control replaces the technique of "hiding" `.icd`
files in `/etc/OpenCL/vendors/`, an option only open to users with root
permission.

If for whatever reason, the `libocl` loader cannot find an `ocl.file` on the
system, it will then use the `.icd` files found in `/etc/OpenCL/vendors/`.  As
an additional convenience, an ordered list of directories to search for `.icd`
files may be specified.  This resolves a common challenge faced by users
without root permission, being unable to modify files in the `/etc/` directory.
The syntax for specifying alternate ICD directories is,

~~~~~~~
icd_dirs = ( 
	"/etc/OpenCL/vendors/", 
	"/home/user/local/etc/OpenCL/vendors",
	"/home/user/icd"
);
~~~~~~~

## Remote CLRPC Servers

The `ocl.conf` file can be used to add platforms that have been exported over a network using CLRPC servers.
A detailed discusion of CLRPC is provided in the section on 
[CLRPC: OpenCL Remote Procedure Calls](#clrpc).
An example of a *clrpc* section in an `ocl.conf` file is shown below

~~~~~~~
clrpc = {
	enable = "yes";
	servers = (
		{ url="127.0.0.1:2112" },
		{ url="192.168.1.15:2112" },
#		{ url="192.168.1.16:2112" },
		{ url="10.1.2.3:2112" },
		{ url="10.1.2.3:2113" },
		{ url="10.1.2.3:2114" }
	);
};
~~~~~~~

The CLRPC servers will be checked for platforms by contacting a CLRPC server
listening at the specified address and port.  If no response is initially
received when contacted, the server is simply skipped.


## Hooks and Accounting

At present some functionality of the `libocl` loader will remain hidden to the
user, but it may still be of interest to understand what is going on behind the
scenes.  The OpenCL ICD specification for the loader defines a call vector
mechanism that forwards OpenCL host calls to the correct vendor platform
implementation.  Such a mechanism provides a perfect opportunity for call
interception, and the `libocl` loader exploits this to enable call tracing,
process accounting, and extensible pre- and post-call hooks.

This mechanism is presently used to provide the accounting information for the
`cltop` command.  The implementation of the `libocl` loader provides for
extensible pre- and post-call hooks that can, in principle, be extended for
advanced applications.  These hooks will be used in a future release to support
an integrated run-time debugger.

