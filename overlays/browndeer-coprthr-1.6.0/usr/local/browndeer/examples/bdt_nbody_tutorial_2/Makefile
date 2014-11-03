### Makefile for N-Body program
NAME = nbody2

prefix=/usr/local/browndeer
exec_prefix=${prefix}

OPENCL_INCS = -I/home/linaro/bdt-code/stable-1.6/coprthr/include
OPENCL_LIBS = -L/home/linaro/bdt-code/stable-1.6/coprthr/src/libocl -locl

STDCL_INCS = -I${prefix}/include
STDCL_LIBS = -L${exec_prefix}/lib -lstdcl

INCS = $(OPENCL_INCS) $(STDCL_INCS)
LIBS = $(OPENCL_LIBS) $(STDCL_LIBS)

OBJS = nbody_init.o nbody_output.o

all: $(NAME).x

$(NAME).x: $(NAME).o $(OBJS)
	$(CC) $(CFLAGS) $(INCS) -o $(NAME).x $(NAME).o $(OBJS) $(LIBS)

.SUFFIXES:
.SUFFIXES: .c .o

.c.o:
	$(CC) $(CFLAGS) $(INCS) -c $<

clean:
	rm -f *.o

distclean: clean
	rm -f *.x

