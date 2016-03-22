
This example shows how to use the device lock feature in STDCL.

The idea is that by setting the environment variables,
	STDGPU_MAX_NDEV=1
	STDGPU_LOCK=31415
when each MPI proc is run, the STDCL layer will provide stdgpu 
with one GPU no matter how many are available on the platform.

Further, with all MPI processes running with the same "lock" number (which
is completely arbitrary), they will enter into a mutual locking scheme
where by each MPI proc will be provided exclusive use of a unique GPU.

The GPUs are handed out until none are left, at which point the stdgpu
context will be NULL for the unlucky MPI processes who are late.

The result of all this is that the application simply runs assuming it
is using devnum 0 and need not take any action to ensure that it has
the right GPU.  The STDCL interface makes sure wveryone has a unique GPU
which is what the parallel application wants.


