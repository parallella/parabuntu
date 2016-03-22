#!/bin/bash

export STDGPU_MAX_NDEV=1

export STDGPU_LOCK=31415

mpirun -x STDGPU_MAX_NDEV -x STDGPU_LOCK -np 3 ./mpi_lock_example.x 

rm -f /dev/shm/stdcl_ctx_lock*.31415

