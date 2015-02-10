NAME = clmulti_array_example

prefix=/usr/local/browndeer
exec_prefix=${prefix}

OPENCL_INCS = -I/home/parallella/coprthr/include
OPENCL_LIBS = -L/home/parallella/coprthr/src/libocl -locl

STDCL_INCS = -I${prefix}/include
STDCL_LIBS = -L${exec_prefix}/lib -lstdcl

INCS = $(STDCL_INCS) $(OPENCL_INCS)
LIBS = $(STDCL_LIBS) $(OPENCL_LIBS)

CXXFLAGS += -O3

OBJS = ocl_kernels.o

all: $(NAME).x

$(NAME).x: $(NAME).o $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCS) -o $(NAME).x $(NAME).o $(OBJS) $(LIBS)

ocl_kernels.o: 
	clcc -o ocl_kernels.o matvecmult.cl

.SUFFIXES:
.SUFFIXES: .cpp .o

.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCS) -c $<

clean:
	rm -f *.o

distclean: clean
	rm -f *.x

