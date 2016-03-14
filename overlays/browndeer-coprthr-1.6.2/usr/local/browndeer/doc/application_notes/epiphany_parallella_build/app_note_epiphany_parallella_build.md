% Application Note: Building COPRTHR SDK for Epiphany/Parallella Platforms
% Copyright (c) 2013-2014 Brown Deer Technology, LLC
% *Verbatim copying and distribution of this entire document is
  permitted in any medium, provided this notice is preserved.*


# Overview

The COPRTHR^&#174;^ SDK provides tools and libraries supporting Parallella
and the Epiphany co-processor
including STDCL^&#174;^, baseline OpenCL^&#8482;^ support, and compiler
tools supporting a standard compilation model and workflow.
This Application Note provides details specific to the Parallella platform for
the installation of the COPRTHR SDK.  The installation instructions require the
version 1.6 of the COPRTHR SDK ("Freewill" release) and version 5 of the eSDK
later than the 5.13.7.17 update.

&nbsp; 

----------


# Installation

The following instructions describe the installation of the COPRTHR SDK v1.6 on
Parallella using either a pre-compiled distribution or building directly from
source.

## Pre-requisites

The following packages must be installed prior to the installation of the
COPRTHR SDK. Note that the standard Linux distribution of libelf is *NOT* a
substitute for the package listed below:

libelf-0.8.13.tar.gz (www.mr511.de/software/libelf-0.8.13.tar.gz)

libevent-2.0.18-stable.tar.gz (github.com/downloads/libevent/libevent/libevent-2.0.18-stable.tar.gz)

libconfig-1.4.8.tar.gz (www.hyperrealm.com/libconfig/libconfig-1.4.8.tar.gz)

In addition, the current Ubuntu image may not have the following packages
installed. If you find this to be the case, they can be built in this order
using the following packages.

m4-1.4.16.tar.gz (http://ftp.gnu.org/gnu/m4/)

flex-2.5.35.tar.gz (http://flex.sourceforge.net/)

bison-2.5.tar.gz (http://ftp.gnu.org/gnu/bison/)

All of these packages are easily built by unpacking the package and typing

	] ./configure
	] sudo make install

These packages reflect the versions that have been used across multiple
platforms. Packages available via apt-get may work just fine, but this has not
yet been tested.

## Installing pre-compiled package

First obtain the correct pre-compiled package for Parallella
(`coprthr-1.6.0-parallella.tgz`)
from the 
[COPRTHR download page]
(http://www.browndeertechnology.com/coprthr_download.htm).

Unpacking this file will produce the directory `browndeer/`. Do *NOT* cd into
the directory. As root, run the uninstall script to remove any previous
installation,

	sudo ./browndeer/scripts/uninstall_coprthr_parallella.sh

Then, as root, run the install script,

	sudo ./browndeer/scripts/install_coprthr_parallella.sh

After installing the COPRTHR SDK, it is very important to update the `.bashrc`
file for *both root and user* to add the required paths in order for the
software to operate properly,

~~~~~~~
export PATH=/usr/local/browndeer/bin:$PATH
export LD_LIBRARY_PATH=/usr/local/browndeer/lib:/usr/local/lib:$LD_LIBRARY_PATH
~~~~~~~

## Build from source

Download the source code from github (github.com/browndeer/coprthr) using the
latest release update for version 1.6 or the stable-1.6 branch and then build
using the following steps for Parallella:

	./configure –enable-epiphany --disable-clete
	make
	sudo make install

After installing the COPRTHR SDK, it is very important to update the `.bashrc`
file for *both root and user* to add the required paths in order for the
software to operate properly,

~~~~~~~
export PATH=/usr/local/browndeer/bin:$PATH
export LD_LIBRARY_PATH=/usr/local/browndeer/lib:/usr/local/lib:$LD_LIBRARY_PATH
~~~~~~~

----------

&nbsp;


# Testing

The easiest way to test the installation and get started is to create a work
directory and copy the `examples/` and `test/` directories installed with the
SDK,

	mkdir work
	cp –R /usr/local/browndeer/examples ./work
	cp –R /usr/local/browndeer/test ./work

Then cd into ./work/test and as root run the quicktest,

	cd ./work/test
	su
	make quicktest

If these tests do not all indicate `[pass]` then something is wrong. Typical
problems are forgetting to correctly update and source `.bashrc` files and also
attempting to run the test as a user (incorrect) and not root (correct).

Note that the test `test_stdcl_ndev_float4` for `stddev 1` is expected to fail
on this platform and this is not a cause for concern.

----------

&nbsp;


# More Information

More information specific to programming Epiphany/Parallella can be found in
the Appliction Note
[Programming Parallella Using STDCL](http://www.browndeertechnology.com/docs/app_note_programming_parallella_using_stdcl.pdf).
More information on the COPRTHR SDK and the STDCL API may be found in the
[COPRTHR Primer](http://www.browndeertechnology.com/docs/coprthr_primer-1.6.0.pdf)
and the
[STDCL API Reference](http://www.browndeertechnology.com/docs/stdcl_api_ref.pdf).


----------

Document revision 1.6.0.0

