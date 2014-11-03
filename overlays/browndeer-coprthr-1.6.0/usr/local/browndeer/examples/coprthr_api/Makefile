### 
### Makefile for libcoprthr API tests
###

CCFLAGS += -g -O2

#INCS = -I.. -I../../../include
INCS = -I/usr/local/browndeer/include -I/usr/local/browndeer/include/coprthr
#LIBS = -L.. -lcoprthr
LIBS = -L/usr/local/browndeer/lib -lcoprthr

TARGET = test_stream_1.x test_stream_2.x test_stream_3.x test_stream_4.x \
	test_stream_7.x test_thread_1.x 

all: $(TARGET)

.PHONY: clean install uninstall $(SUBDIRS)

.SUFFIXES:
.SUFFIXES: .c .o .x

test_%.x: test_%.c
	$(CC) $(CCFLAGS) $(INCS) -o test_$*.x  test_$*.c $(LIBS)

.c.o:
	$(CC) $(CCFLAGS) $(DEFS) $(INCS) -c $<

clean: $(SUBDIRS)
	rm -f *.o 
	rm -f $(TARGET)

distclean: clean 


