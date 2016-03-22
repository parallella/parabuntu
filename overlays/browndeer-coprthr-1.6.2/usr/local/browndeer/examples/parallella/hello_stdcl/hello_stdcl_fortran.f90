!! hello_stdcl_fortran.f90
!!
!! This is a simple OpenCL example for Parallella that performs a
!! matrix-vector multiplication on the Epiphany processor.
!!
!! THIS FILE ONLY is placed in the public domain by Brown Deer Technology, LLC.
!! in January 2013. No copyright is claimed, and you may use it for any purpose
!! you like. There is ABSOLUTELY NO WARRANTY for any purpose, expressed or
!! implied, and any warranty of any kind is explicitly disclaimed.  This
!! statement applies ONLY TO THE COMPUTER SOURCE CODE IN THIS FILE and does
!! not extend to any other software, source code, documentation, or any other
!! materials in which it may be included, or with which it is co-distributed.
!!

!! DAR !!



	program main

	use iso_c_binding
	use stdcl

	implicit none

	integer(C_INT) :: n = 64
	type(C_PTR) :: cp
	integer(C_INT) :: devnum = 0
	type(C_PTR) :: clh
	type(C_PTR) :: krn
	type(C_PTR) :: p_aa, p_b, p_c
	real(C_FLOAT), pointer :: aa(:,:), b(:), c(:)
	integer :: i,j
	type(clndrange_struct), target :: ndr
	integer(C_INT) :: rc
	type(C_PTR) :: ev


	!!!! use default contexts, if no GPU use CPU 
	if (C_ASSOCIATED(stdacc)) then
		cp = stdacc
	else
		cp = stdcpu
	endif


	!!!! build CL program, get kernel
   krn = clsym(cp,C_NULL_PTR,"matvecmult_kern"//C_NULL_CHAR,0);


   !!!! allocate OpenCL device-sharable memory, associate with fortran pointers
   p_aa = clmalloc(cp,int8(n*n*4),0);
	call C_F_POINTER(p_aa,aa,[n,n])

   p_b = clmalloc(cp,int8(n*4),0);
	call C_F_POINTER(p_b,b,[n])

   p_c = clmalloc(cp,int8(n*4),0);
	call C_F_POINTER(p_c,c,[n])

   !!!! initialize vectors a[] and b[], zero c[] 
	do i = 1,n
		do j = 1,n
			aa(i,j) = 1.1 * (i-1) * (j-1)
		end do
	end do

	do i = 1,n
		b(i) = 2.2 * (i-1)
	end do 

	do i = 1,n
		c(i) = 0.0
	end do 


   !!!! define the computational domain and workgroup size 
   ndr = clndrange_init1d( 0, n, 16)


   !!!! non-blocking sync vectors a and b to device memory (copy to GPU)
   ev = clmsync(cp,devnum,p_aa,CL_MEM_DEVICE+CL_EVENT_NOWAIT)
   ev = clmsync(cp,devnum,p_b,CL_MEM_DEVICE+CL_EVENT_NOWAIT)


   !!!! set the kernel arguments 
   rc = clarg_set(cp,krn,0,n);
   rc = clarg_set_global(cp,krn,1,p_aa);
   rc = clarg_set_global(cp,krn,2,p_b);
   rc = clarg_set_global(cp,krn,3,p_c);


   !!!! non-blocking fork of the OpenCL kernel to execute on the GPU 
	ev = clfork(cp,devnum,krn,C_LOC(ndr),CL_EVENT_NOWAIT)


   !!!! non-blocking sync vector c to host memory (copy back to host) 
	ev = clmsync(cp,devnum,p_c,CL_MEM_HOST+CL_EVENT_NOWAIT)


   !!!! force execution of operations in command queue (non-blocking call) 
	rc = clflush(cp,devnum,0)


   !!!! block on completion of operations in command queue 
	ev = clwait(cp,devnum,CL_ALL_EVENT)

	do i = 1,n
		write(*,*) i,b(i),c(i)
	end do

   rc = clfree(p_aa)
   rc = clfree(p_b)
   rc = clfree(p_c)

	end

