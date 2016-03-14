#!/usr/bin/perl

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
printf "int main()\n";
printf "{\n";
printf "int i;\n";
printf "cl_uint err; \n";
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
printf "float* aa$c = (float*)malloc(2048*sizeof(int));\n";
printf "if (!aa$c) exit(__LINE__);\n";
printf "float* bb$c = (float*)malloc(2048*sizeof(int));\n";
printf "if (!bb$c) exit(__LINE__);\n";
}


printf "for(i=0;i<2048;i++) { \n";
for($c=0;$c<10-2;++$c) {
printf "aa".$c."[i] = i*1.1f+13.1f*".$c."; bb".$c."[i] = 0; \n";
}
printf "}\n";


for($c=0;$c<10-2;++$c) {
printf "cl_mem bufa$c = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,2048*sizeof(float),aa$c,&err);\n";
printf "if (err) exit(__LINE__);\n";
printf "cl_mem bufb$c = clCreateBuffer(ctx,CL_MEM_USE_HOST_PTR,2048*sizeof(float),bb$c,&err);\n";
printf "if (err) exit(__LINE__);\n";
}

printf "size_t file_sz;\n";
printf "void* pfile;\n";
printf "__mapfile(\"test_faf_wb.cl\",file_sz,pfile);\n";

printf "cl_program prg=clCreateProgramWithSource(\n";
printf "ctx,1,(const char**)&pfile,&file_sz,&err);\n";
printf "if (err) exit(__LINE__);\n";

printf "if (clBuildProgram(prg,ndev,devices,0,0,0)) exit(__LINE__);\n";

printf "size_t gws1[] = { 128 };\n";
printf "size_t lws1[] = { 4 };\n";
printf "cl_event ev[10];\n";
printf "cl_kernel krn;\n";
printf "float sum,sum_correct;\n";
printf "float tol = 1.0e-6;\n";

for($c=0;$c<10;++$c) {
   for($a=1;$a<$c;++$a) {
      $b=$c-$a;

printf "krn = clCreateKernel(prg,\"test_fa1_".$a."_".$b."_kern\",&err);\n";
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
printf "if (clEnqueueReadBuffer(cmdq,bufb$j,CL_TRUE,0,128*sizeof(float),bb$j,0,0,&ev[1+$j])) \n";
printf "exit(__LINE__);\n";
}

printf "if (clWaitForEvents(1+$b,ev)) exit(__LINE__);\n";

$sum_correct = 0;
for($i=0;$i<$a;++$i) {
for($j=0;$j<$b;++$j) {
#$sum_correct += ($j+1)*( 128*(128-1)/2 + 14*$i*128 );
$sum_correct += ($j+1.1)*( (128*(128-1)*1.1)/2 + (1+13.1)*$i*128 + 0.1*128);
}}
printf "sum_correct = ".$sum_correct.";\n";

printf "sum = 0;\n";
for($j=0;$j<$b;++$j) {
printf "for(i=0;i<128;i++) sum += bb".$j."[i];\n";
}
printf "printf(\"(%%e) sum ".$a." ".$b." %%e\\n\",sum_correct,sum);\n";
printf "printf(\"%%e \\n\",fabs((sum-sum_correct)/sum_correct));\n";
#printf "if (sum != sum_correct) exit(__LINE__);\n";
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

