
#ifndef _esdk_missing_h
#define _esdk_missing_h

__inline __attribute__((always_inline))
void* e_address_from_coreid( e_coreid_t coreid, const void* ptr);

__inline __attribute__((always_inline))
void* e_address_from_coreid( e_coreid_t coreid, const void* ptr)
{
	unsigned uptr;

	if (((unsigned) ptr) & 0xfff00000) {
		uptr = (unsigned) ptr;
	} else {
        uptr = (unsigned) ptr;
        uptr = (coreid << 20) | uptr;
	}

   return (void*) uptr;
}

#endif

