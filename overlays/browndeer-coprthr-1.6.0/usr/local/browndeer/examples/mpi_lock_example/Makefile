NAME = mpi_lock_example

prefix=/usr/local/browndeer
exec_prefix=${prefix}

OPENCL_INCS = -I/home/parallella/coprthr/include
OPENCL_LIBS = -L/home/parallella/coprthr/src/libocl -locl

STDCL_INCS = -I${prefix}/include
STDCL_LIBS = -L${exec_prefix}/lib -lstdcl

INCS = $(OPENCL_INCS) $(STDCL_INCS)
LIBS = $(OPENCL_LIBS) $(STDCL_LIBS) 

CC = mpicc
CCFLAGS += -O3

BUILD_OS = $(shell uname -s)

ifeq ($(BUILD_OS),Linux)
OBJS += ocl_kernels.o
endif

all: $(NAME).x

$(NAME).x: $(NAME).o $(OBJS)
	$(CC) $(CCFLAGS) $(INCS) -o $(NAME).x $(NAME).o $(OBJS) $(LIBS)

ocl_kernels.o: outerprod.cl
	clcc -c -o ocl_kernels.o outerprod.cl

.SUFFIXES:
.SUFFIXES: .c .o

.c.o:
	$(CC) $(CCFLAGS) $(INCS) -c $<

clean:
	rm -f *.o

distclean: clean
	rm -f *.x

