#!/usr/bin/perl
# 
# Copyright (c) 2009-2010 Brown Deer Technology, LLC.  All Rights Reserved.
#
# This software was developed by Brown Deer Technology, LLC.
# For more information contact info@browndeertechnology.com
#
# This program is free software: you can redistribute it and/or modify it
# under the terms of the GNU Lesser General Public License version 3 (LGPLv3)
# as published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

# DAR #

$size = 128;
$bsize = 4;
$clfile = 'test_arg_float.cl';
$testprefix = 'test_arg_';

printf "\n";
printf "#include <stdio.h>\n";
printf "#include <stdlib.h>\n";
printf "#include <math.h>\n";
printf "#include <fcntl.h>\n";
printf "#include <sys/stat.h>\n";
printf "#include <sys/mman.h>\n";
printf "\n";
printf "#include \"CL/cl.h\"\n";
printf "\n";
printf "#define SIZE $size\n";
printf "#define BLOCKSIZE $bsize\n";
printf "\n";
printf "#define __mapfile(file,filesz,pfile) do { \\\n";
printf "int fd = open(file,O_RDONLY); \\\n";
printf "struct stat fst; fstat(fd,&fst); \\\n";
printf "if (fst.st_size == 0 || !S_ISREG(fst.st_mode)) { \\\n";
printf "fprintf(stderr,\"error: open failed on '%s'\\n\",file); \\\n";
printf "pfile=0; \\\n";
printf "} else { \\\n";
printf "filesz = fst.st_size; \\\n";
printf "pfile = mmap(0,filesz,PROT_READ,MAP_PRIVATE,fd,0); \\\n";
printf "} \\\n";
printf "close(fd); \\\n";
printf "} while(0);\n";
printf "\n";
printf "#define __exit(err,line) \\\n";
printf "do { fprintf(\"error code %d\\n\",err); exit(line); } while(0)\n";
printf "\n";
printf "int main( int argc, char** argv )\n";
printf "{\n";
printf "int i,j;\n";
printf "cl_uint err; \n";
printf "\n";

printf "size_t size = SIZE;\n";
printf "size_t blocksize = BLOCKSIZE;\n";
printf "\n";
printf "i=1;\n";
printf "char* arg;\n";
printf "while(i<argc) {\n";
printf "arg=argv[i++];\n";
printf "if (!strncmp(arg,\"--size\",6)) size = atoi(argv[i++]);\n";
printf "else if (!strncmp(arg,\"--blocksize\",11)) blocksize = atoi(argv[i++]);\n";
printf "else {\n";
printf "fprintf(stderr,\"unrecognized option '%s'\\n\",arg);\n";
printf "exit(-1);\n";
printf "}\n";
printf "}\n";
printf "\n";

printf "cl_uint nplatforms;\n";
printf "cl_platform_id* platforms;\n";
printf "\n";
printf "if (clGetPlatformIDs(0,0,&nplatforms)) exit(__LINE__);\n";
printf "\n";
printf "if (nplatforms == 0) exit(__LINE__);\n";
printf "\n";
printf "platforms = (cl_platform_id*)malloc(nplatforms*sizeof(cl_platform_id));\n";
printf "\n";
printf "if (!platforms) exit(__LINE__);\n";
printf "\n";
printf "if (clGetPlatformIDs(nplatforms,platforms,0)) exit(__LINE__);\n";
printf "\n";
printf "char buf[256];\n";
printf "\n";
printf "cl_uint ndev = 0;\n";
printf "if (clGetDeviceIDs(platforms[0],CL_DEVICE_TYPE_CPU,0,0,&ndev)) \n";
printf "exit(__LINE__);\n";
printf "\n";
printf "cl_device_id* devices = (cl_device_id*)malloc(ndev*sizeof(cl_device_id));\n";
printf "\n";
printf "if (!devices) exit(__LINE__);\n";
printf "\n";
printf "if (clGetDeviceIDs(platforms[0],CL_DEVICE_TYPE_CPU,ndev,devices,0)) \n";
printf "exit(__LINE__);\n";
printf "\n";
printf "cl_context_properties ctxprop[3] = {\n";
printf "(cl_context_properties)CL_CONTEXT_PLATFORM,\n";
printf "(cl_context_properties)platforms[0],\n";
printf "(cl_context_properties)0\n";
printf "};\n";
printf "\n";
printf "cl_context ctx = clCreateContext(ctxprop,ndev,devices,0,0,&err);\n";
printf "if (err) exit(__LINE__);\n";
printf "\n";
printf "cl_command_queue cmdq = clCreateCommandQueue(ctx,devices[0],0,&err);\n";
printf "if (err) exit(__LINE__);\n";


for($c=0;$c<10-2;++$c) {
printf "float* aa$c = (float*)malloc(size*sizeof(int));\n";
printf "if (!aa$c) exit(__LINE__);\n";
printf "float* bb$c = (float*)malloc(size*sizeof(int));\n";
printf "if (!bb$c) exit(__LINE__);\n";
}


printf "for(i=0;i<size;i++) { \n";
for($c=0;$c<10-2;++$c) {
printf "aa".$c."[i] = i*1.1f+13.1f*".$c."; bb".$c."[i] = 0; \n";
}
printf "}\n";


for($c=0;$c<10-2;++$c) {
printf "cl_mem bufa$c = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,size*sizeof(float),aa$c,&err);\n";
printf "if (err) exit(__LINE__);\n";
printf "cl_mem bufb$c = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,size*sizeof(float),bb$c,&err);\n";
printf "if (err) exit(__LINE__);\n";
}

printf "size_t file_sz;\n";
printf "void* pfile;\n";
printf "__mapfile(\"$clfile\",file_sz,pfile);\n";

printf "cl_program prg=clCreateProgramWithSource(\n";
printf "ctx,1,(const char**)&pfile,&file_sz,&err);\n";
printf "if (err) exit(__LINE__);\n";

printf "if (clBuildProgram(prg,ndev,devices,0,0,0)) exit(__LINE__);\n";

printf "size_t gws1[] = { size };\n";
printf "size_t lws1[] = { blocksize };\n";
printf "cl_event ev[10];\n";
printf "cl_kernel krn;\n";
printf "float sum,sum_correct;\n";
printf "float tol = pow(10.0,-8+log10((float)size));\n";

for($c=0;$c<10;++$c) {
   for($a=1;$a<$c;++$a) {
      $b=$c-$a;

printf "krn = clCreateKernel(prg,\"$testprefix".$a."_".$b."_kern\",&err);\n";
printf "if (err) exit(__LINE__);\n";

for($i=0;$i<$a;++$i) {
printf "if (clSetKernelArg(krn,$i,sizeof(cl_mem),&bufa$i)) exit(__LINE__);\n";
}

for($j=0;$j<$b;++$j) {
$k = $a+$j;
printf "if (clSetKernelArg(krn,$k,sizeof(cl_mem),&bufb$j)) exit(__LINE__);\n";
}

printf "if (clEnqueueNDRangeKernel(cmdq,krn,1,0,gws1,lws1,0,0,&ev[0])) \n";
printf "exit(__LINE__);\n";

for($j=0;$j<$b;++$j) {
printf "if (clEnqueueReadBuffer(cmdq,bufb$j,CL_TRUE,0,size*sizeof(float),bb$j,0,0,&ev[1+$j])) \n";
printf "exit(__LINE__);\n";
}

printf "if (clWaitForEvents(1+$b,ev)) exit(__LINE__);\n";

printf "sum_correct = 0;\n";
printf "for(i=0;i<$a;++i)\n";
printf "for(j=0;j<$b;++j)\n";
printf "sum_correct += (j+1.1)*( (size*(size-1)*1.1)/2 + (1+13.1)*i*size + 0.1*size);\n";

printf "sum = 0;\n";
for($j=0;$j<$b;++$j) {
printf "for(i=0;i<size;i++) sum += bb".$j."[i];\n";
}
printf "printf(\"(%%e) sum ".$a." ".$b." %%e\",sum_correct,sum);\n";
printf "printf(\" relerr %%e (%%e)\\n\",fabs((sum-sum_correct)/sum_correct),tol);\n";
printf "if (fabs((sum-sum_correct)/sum_correct) > tol) exit(__LINE__);\n";

for($j=0;$j<$b+1;++$j) {
printf "if (clReleaseEvent(ev[$j])) exit(__LINE__);\n";
}

printf "if (clReleaseKernel(krn)) exit(__LINE__);\n";

}}

printf "if (clReleaseProgram(prg)) exit(__LINE__);\n";

for($c=0;$c<10-2;++$c) {
printf "if (clReleaseMemObject(bufa$c)) exit(__LINE__);\n";
printf "if (clReleaseMemObject(bufb$c)) exit(__LINE__);\n";
}

printf "if (clReleaseCommandQueue(cmdq)) exit(__LINE__);\n";
printf "if (clReleaseContext(ctx)) exit(__LINE__);\n";
printf "printf(\"done!\\n\");\n";
printf "return(0);\n";
printf "}\n";

