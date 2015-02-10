
#ifndef _test_h
#define _test_h

#define __check( call ) do { \
        int err = call; \
        if (err) printf("error: %d %s: " #call "\n",err,strerror(err)); \
        } while(0)

#define TEST_COPRTHR_DEVICE COPRTHR_DEVICE_X86_64
//#define TEST_COPRTHR_DEVICE COPRTHR_DEVICE_E32

#endif


