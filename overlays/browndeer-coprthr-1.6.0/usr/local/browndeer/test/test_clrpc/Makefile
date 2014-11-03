#
# Makefile for libclrpc
#

prefix=/usr/local/browndeer
exec_prefix=${prefix}

### this useless define is needed to silence useless autoconf warning
datarootdir=${prefix}/share

USE_OPENCL_INCLUDES = -I/home/linaro/bdt-code/stable-1.6/coprthr/include

#LIBELF_INC = -I/usr/local/include
#LIBELF_LIB = -L/usr/local/lib -lelf

### enable build of debug version if not already defined
#ifeq (,1)
#ENABLE_DEBUG_LIBCLRPC=1
#else
#ENABLE_DEBUG_LIBCLRPC=0
#endif


INSTALL_INCLUDE_DIR=${prefix}/include
#INSTALL_BIN_DIR=${exec_prefix}/bin
INSTALL_LIB_DIR=${exec_prefix}/lib
#INSTALL_MAN_DIR=${datarootdir}/man


############################################################################
##### DO NOT MODIFY BELOW THIS LINE UNLESS YOU KNOW WHAT YOU ARE DOING #####
############################################################################

DEFS = -DHAVE_CONFIG_H

#DEFS += -DXCL_REPORT

INCS += -I../../include $(USE_OPENCL_INCLUDES) -I../libocl 
INCS += -I$(INSTALL_INCLUDE_DIR)
INCS += -I/usr/local/include

LIBS += $(USE_OPENCL_LIBS)

#INCS += $(LIBELF_INC)
#LIBS += $(LIBELF_LIB)

ifeq (freebsd,$(patsubst freebsd%,freebsd,linux-gnu))
LIBS += -lpthread -lc -lrt 
else
LIBS += -lpthread -ldl -lrt 
endif

#LIBS += -levent -levent_pthreads -levent_pthreads

#OBJS = clrpc.gen.o 
#OBJS_D = $(subst .o,_d.o,$(OBJS)) 

HDRS = clrpc.h 


#INSTALL_INCS = $(HDRS)
#INSTALL_LIBS = libclrpc.so 
#INSTALL_BINS = clrpcd

CCFLAGS += -g -O2 -fPIC

#TARGET += libclrpc.so 
#LIB_OBJS += $(OBJS)
#LIB_OBJS_D += $(OBJS_D)

ifeq ($(ENABLE_DEBUG_LIBSTDCL),1)
TARGET += libclrpc_d.so 
INSTALL_LIBS += libclrpc_d.so
INSTALL_BINS += clrpcd_d
endif

TARGET = clrpc_test_cli clrpc_test_cli2


all: $(TARGET)

.PHONY: install uninstall clean distclean 

clrpc_test_cli: clrpc_test_cli.o
	$(CC) $(CCFLAGS) -o clrpc_test_cli clrpc_test_cli.o -L$(INSTALL_LIB_DIR)  -locl -lclrpc

clrpc_test_cli2: clrpc_test_cli2.o
	$(CC) $(CCFLAGS) -o clrpc_test_cli2 clrpc_test_cli2.o -L$(INSTALL_LIB_DIR)  -locl -lclrpc


.SUFFIXES:
.SUFFIXES: .c .o

.c.o: 
	$(CC) $(CCFLAGS) $(DEFS) $(INCS) -c $<

#%_d.o: 
#	$(CC) $(CCFLAGS) $(DEFS) -DXCL_REPORT $(INCS) -c $*.c -o $*_d.o

#%.3.gz:
#	-gzip -f -c $*.3 > $*.3.gz



install: $(INSTALL_INCS) $(INSTALL_LIBS) $(INSTALL_BINS)
#	test -d $(INSTALL_INCLUDE_DIR) || install -m 755 -d $(INSTALL_INCLUDE_DIR)
#	test -d $(INSTALL_LIB_DIR) || install -m 755 -d $(INSTALL_LIB_DIR)
#	test -d $(INSTALL_BIN_DIR) || install -m 755 -d $(INSTALL_BIN_DIR)
#	install -m 644 $(INSTALL_INCS) $(INSTALL_INCLUDE_DIR)
#	install -m 644 $(INSTALL_LIBS) $(INSTALL_LIB_DIR)
#	install -m 644 $(INSTALL_BINS) $(INSTALL_BIN_DIR)

uninstall: 
#	rm -f $(addprefix $(INSTALL_INC_DIR)/,$(INSTALL_INCS)) 
#	rm -f $(addprefix $(INSTALL_LIB_DIR)/,$(INSTALL_LIBS)) 
#	rm -f $(addprefix $(INSTALL_BIN_DIR)/,$(INSTALL_BINS)) 


clean:
	rm -f *.o *.so *.x
	rm -f $(TARGET)

distclean: clean

