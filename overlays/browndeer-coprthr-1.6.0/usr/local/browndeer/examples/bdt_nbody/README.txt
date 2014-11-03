
This is a simple N-Body demo used to simulate the dynamics of stars in
a galaxy subject to gravitational force.  The program includes an OpenGL
display of the particles.

To build, type:

	make

To run, type:

	./bdt_nbody.x 

The following options are supported:

	--devnum <device-number>

	--nburst <number-of-steps-between-re-display>

	--nthread <number-of-threads-in-workgroup>

	--nparticle <number-of-particles>

Notes:

The number of particles must be divisible by number of threads in workgroup,
and your hardware may place further constraints on both numbers.  

Peak performance on AMD Cypress and Cayman cards has been achieved with
--nparticle 196608 --nthread 256 --nburst 2

If you have multiple GPUs and try to use device number > 0 make sure you
have set the env var DISPLAY=:0 , this is a very common mistake

If you are using Nvidia hardware, make sure you have set the env var STDGPU
as shown,

	export STDGPU="nplatform_name=nvidia"

this is another common problem.


-DAR


