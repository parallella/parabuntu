NAME = bdt_nbody

### uncomment to disable GL display and use --no-display to run program
DISABLE_DISPLAY = 1

prefix=/usr/local/browndeer
exec_prefix=${prefix}

OPENCL_INCS = -I/home/linaro/bdt-code/stable-1.6/coprthr/include
OPENCL_LIBS = -L/home/linaro/bdt-code/stable-1.6/coprthr/src/libocl -locl

STDCL_INCS = -I${prefix}/include
STDCL_LIBS = -L${exec_prefix}/lib -lstdcl

INCS = $(OPENCL_INCS) $(STDCL_INCS)
LIBS = $(OPENCL_LIBS) $(STDCL_LIBS)

CLSRC = nbody_kern.cl

DEFS += -DENABLE_CL

OBJS = Timer.o nbody_init.o

BUILD_OS = $(shell uname -s)

ifeq ($(BUILD_OS),Linux)
OBJS += ocl_kernels.o
endif

ANNOUNCEMENT = "\a\n\n*****PLEASE NOTE *****\n\nMake sure "$(LIBSTDCL_ROOT)"/lib \nis added to LD_LIBRARY_PATH\n\n"

ifeq ($(DISABLE_DISPLAY),1)
DEFS += -DDISABLE_DISPLAY
else
OBJS += nbody_display.o bdt_bmp.o
LIBS += -L/usr/lib64 -lglut -lGLEW
#LIBS += -L/usr/local/atistream/lib/x86_64  -lglut -lGLEW
endif

CXXFLAGS += -O3

all: $(NAME).x
	@echo -e $(ANNOUNCEMENT)

$(NAME).x: $(NAME).o $(OBJS) 
	$(CXX) $(CXXFLAGS) $(INCS) -o $(NAME).x $(NAME).o $(OBJS) $(LIBS)

ocl_kernels.o: $(CLSRC)
	clcc -o ocl_kernels.o $(STDCL_INCS) $(CLSRC)

bdt_bmp.o:
	objcopy -I binary -O elf64-x86-64 -B i386 bdt.bmp bdt_bmp.o

.SUFFIXES:
.SUFFIXES: .br .cpp .o

.cpp.o:
	$(CXX) $(CXXFLAGS) $(DEFS) $(INCS) -c $<


clean:
	rm -f *.o 

distclean: clean
	rm -f *.x

