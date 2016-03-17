
TESTS = test_stdcl 

ifneq (make,)
MAKE = make
endif

ifeq (1,1)
TESTS += test_libcoprthr_opencl
endif

#ifeq (1,1)
#TESTS += test_libcoprthr-e
#endif

##### DO NOT EDIT BELOW THIS LINE #####

SUBDIRS = 
SUBDIRS += $(TESTS)

#export TOPDIR = $(CURDIR)

all: $(SUBDIRS) 

.PHONY: subdirs $(SUBDIRS) clean test quicktest

subdirs: $(SUBDIRS)

$(SUBDIRS):
	echo $(MAKECMDGOALS)
#	make -C $@ $(MAKEFLAGS) $(MAKECMDGOALS)
	$(MAKE) -C $@ $(MAKECMDGOALS)

clean: subdirs
#	make $(MAKEFLAGS) $(MAKECMDGOALS)

distclean: 
#distclean: subdirs
#	make -C ./test_libcoprthr $(MAKECMDGOALS)

test: subdirs
#	make -C ./test $(MAKEFLAGS) $(MAKECMDGOALS)

quicktest: subdirs
#	make -C ./test $(MAKEFLAGS) $(MAKECMDGOALS)

