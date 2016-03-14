NAME = bdt_em3d

prefix=/usr/local/browndeer
exec_prefix=${prefix}

OPENCL_INCS = -I/home/parallella/coprthr/include
OPENCL_LIBS = -L/home/parallella/coprthr/src/libocl -locl

STDCL_INCS = -I${prefix}/include
STDCL_LIBS = -L${exec_prefix}/lib -lstdcl

INCS = $(OPENCL_INCS) $(STDCL_INCS)
LIBS = $(OPENCL_LIBS) $(STDCL_LIBS)

DEFS = -DENABLE_CL

OBJS = Timer.o em3d_fdtd_gpu_cl_display.o 


##### It should NOT be necessary to modify lines below #####
#LIBS += -lglut -lGLEW
LIBS += -L/usr/local/atistream/lib/x86_64  -lglut -lGLEW

CXXFLAGS += -O3

all: $(NAME).x 

$(NAME).x: $(NAME).o $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCS) -o $(NAME).x $(NAME).o $(OBJS) $(LIBS)

.SUFFIXES:
.SUFFIXES: .cpp .o

.cpp.o:
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $<

clean:
	rm -f *.o 
	rm -f *.ll

distclean: clean
	rm -f *.x
	rm -f *.vti

