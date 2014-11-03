PROG = clopen_example1.x clopen_example2.x clopen_example3.x

prefix=/usr/local/browndeer
exec_prefix=${prefix}

OPENCL_INCS = -I/home/linaro/bdt-code/stable-1.6/coprthr/include
OPENCL_LIBS = -L/home/linaro/bdt-code/stable-1.6/coprthr/src/libocl -locl

STDCL_INCS = -I${prefix}/include
STDCL_LIBS = -L${exec_prefix}/lib -lstdcl

INCS = $(OPENCL_INCS) $(STDCL_INCS)
LIBS = $(OPENCL_LIBS) $(STDCL_LIBS)

#LIBS += -lssl -L/usr/local/lib 

CCFLAGS += -O3

all: $(PROG)

clopen_example1.x: clopen_example1.o 
	$(CC) $(CCFLAGS) $(INCS) -o clopen_example1.x clopen_example1.o $(LIBS)

clopen_example2.x: clopen_example2.o 
	$(CC) $(CCFLAGS) $(INCS) -o clopen_example2.x clopen_example2.o $(LIBS)

clopen_example3.x: clopen_example3.o outerprod_three.o
	$(CC) $(CCFLAGS) $(INCS) -o clopen_example3.x clopen_example3.o $(LIBS) \
		outerprod_three.o

outerprod_three.o: outerprod_three.cl
	clcc -c outerprod_three.cl 

.SUFFIXES:
.SUFFIXES: .c .o

.c.o:
	$(CC) $(CCFLAGS) $(INCS) -c $<

clean:
	rm -f *.o

distclean: clean
	rm -f *.x

