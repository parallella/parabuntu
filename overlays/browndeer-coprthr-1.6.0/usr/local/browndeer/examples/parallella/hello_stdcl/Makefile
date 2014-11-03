NAME = hello_stdcl

prefix=/usr/local/browndeer
exec_prefix=${prefix}

OPENCL_INCS = -I/home/linaro/bdt-code/stable-1.6/coprthr/include
OPENCL_LIBS = -L/home/linaro/bdt-code/stable-1.6/coprthr/src/libocl -locl

STDCL_INCS = -I${prefix}/include
STDCL_LIBS = -L${exec_prefix}/lib -lstdcl

INCS = $(OPENCL_INCS) $(STDCL_INCS)
LIBS = $(OPENCL_LIBS) $(STDCL_LIBS) 

F90 = gfortran44

CCFLAGS += -O3
F90FLAGS = 

BUILD_OS = $(shell uname -s)

ifeq ($(BUILD_OS),Linux)
OBJS += ocl_kernels.o
endif

all: $(NAME).x 

$(NAME).x: $(NAME).o $(OBJS) 
	$(CC) $(CCFLAGS) $(INCS) -o $(NAME).x $(NAME).o $(OBJS) $(LIBS) 

ocl_kernels.o: matvecmult.cl
	clcc -c -o ocl_kernels.o matvecmult.cl

fortran: $(OBJS) 
	$(F90) $(F90FLAGS) $(INCS) -o $(NAME)_fortran.x $(NAME)_fortran.f90 \
		$(OBJS) $(LIBS)

.SUFFIXES:
.SUFFIXES: .c .o

.c.o:
	$(CC) $(CCFLAGS) $(INCS) -c $<

clean:
	rm -f *.o 

distclean: clean 
	rm -f *.x
