; ModuleID = 'test_faf.cl'
target datalayout = "e-p:32:32:32-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-f80:128:128"
target triple = "amdil-pc-amdopencl"

%0 = type { i8*, i8*, i8*, i8*, i32 }

@sgv = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@fgv = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@lvgv = internal constant [0 x i8*] zeroinitializer ; <[0 x i8*]*> [#uses=1]
@sgv1 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@fgv2 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@lvgv3 = internal constant [0 x i8*] zeroinitializer ; <[0 x i8*]*> [#uses=1]
@sgv4 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@fgv5 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@lvgv6 = internal constant [0 x i8*] zeroinitializer ; <[0 x i8*]*> [#uses=1]
@sgv7 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@fgv8 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@lvgv9 = internal constant [0 x i8*] zeroinitializer ; <[0 x i8*]*> [#uses=1]
@sgv10 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@fgv11 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@lvgv12 = internal constant [0 x i8*] zeroinitializer ; <[0 x i8*]*> [#uses=1]
@sgv13 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@fgv14 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@lvgv15 = internal constant [0 x i8*] zeroinitializer ; <[0 x i8*]*> [#uses=1]
@sgv16 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@fgv17 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@lvgv18 = internal constant [0 x i8*] zeroinitializer ; <[0 x i8*]*> [#uses=1]
@sgv19 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@fgv20 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@lvgv21 = internal constant [0 x i8*] zeroinitializer ; <[0 x i8*]*> [#uses=1]
@sgv22 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@fgv23 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@lvgv24 = internal constant [0 x i8*] zeroinitializer ; <[0 x i8*]*> [#uses=1]
@sgv25 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@fgv26 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@lvgv27 = internal constant [0 x i8*] zeroinitializer ; <[0 x i8*]*> [#uses=1]
@sgv28 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@fgv29 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@lvgv30 = internal constant [0 x i8*] zeroinitializer ; <[0 x i8*]*> [#uses=1]
@sgv31 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@fgv32 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@lvgv33 = internal constant [0 x i8*] zeroinitializer ; <[0 x i8*]*> [#uses=1]
@sgv34 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@fgv35 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@lvgv36 = internal constant [0 x i8*] zeroinitializer ; <[0 x i8*]*> [#uses=1]
@sgv37 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@fgv38 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@lvgv39 = internal constant [0 x i8*] zeroinitializer ; <[0 x i8*]*> [#uses=1]
@sgv40 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@fgv41 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@lvgv42 = internal constant [0 x i8*] zeroinitializer ; <[0 x i8*]*> [#uses=1]
@sgv43 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@fgv44 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@lvgv45 = internal constant [0 x i8*] zeroinitializer ; <[0 x i8*]*> [#uses=1]
@sgv46 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@fgv47 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@lvgv48 = internal constant [0 x i8*] zeroinitializer ; <[0 x i8*]*> [#uses=1]
@sgv49 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@fgv50 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@lvgv51 = internal constant [0 x i8*] zeroinitializer ; <[0 x i8*]*> [#uses=1]
@sgv52 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@fgv53 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@lvgv54 = internal constant [0 x i8*] zeroinitializer ; <[0 x i8*]*> [#uses=1]
@sgv55 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@fgv56 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@lvgv57 = internal constant [0 x i8*] zeroinitializer ; <[0 x i8*]*> [#uses=1]
@sgv58 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@fgv59 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@lvgv60 = internal constant [0 x i8*] zeroinitializer ; <[0 x i8*]*> [#uses=1]
@sgv61 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@fgv62 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@lvgv63 = internal constant [0 x i8*] zeroinitializer ; <[0 x i8*]*> [#uses=1]
@sgv64 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@fgv65 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@lvgv66 = internal constant [0 x i8*] zeroinitializer ; <[0 x i8*]*> [#uses=1]
@sgv67 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@fgv68 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@lvgv69 = internal constant [0 x i8*] zeroinitializer ; <[0 x i8*]*> [#uses=1]
@sgv70 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@fgv71 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@lvgv72 = internal constant [0 x i8*] zeroinitializer ; <[0 x i8*]*> [#uses=1]
@sgv73 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@fgv74 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@lvgv75 = internal constant [0 x i8*] zeroinitializer ; <[0 x i8*]*> [#uses=1]
@sgv76 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@fgv77 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@lvgv78 = internal constant [0 x i8*] zeroinitializer ; <[0 x i8*]*> [#uses=1]
@sgv79 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@fgv80 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@lvgv81 = internal constant [0 x i8*] zeroinitializer ; <[0 x i8*]*> [#uses=1]
@sgv82 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@fgv83 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@lvgv84 = internal constant [0 x i8*] zeroinitializer ; <[0 x i8*]*> [#uses=1]
@sgv85 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@fgv86 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@lvgv87 = internal constant [0 x i8*] zeroinitializer ; <[0 x i8*]*> [#uses=1]
@sgv88 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@fgv89 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@lvgv90 = internal constant [0 x i8*] zeroinitializer ; <[0 x i8*]*> [#uses=1]
@sgv91 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@fgv92 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@lvgv93 = internal constant [0 x i8*] zeroinitializer ; <[0 x i8*]*> [#uses=1]
@sgv94 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@fgv95 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@lvgv96 = internal constant [0 x i8*] zeroinitializer ; <[0 x i8*]*> [#uses=1]
@sgv97 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@fgv98 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@lvgv99 = internal constant [0 x i8*] zeroinitializer ; <[0 x i8*]*> [#uses=1]
@sgv100 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@fgv101 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@lvgv102 = internal constant [0 x i8*] zeroinitializer ; <[0 x i8*]*> [#uses=1]
@sgv103 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@fgv104 = internal constant [1 x i8] zeroinitializer ; <[1 x i8]*> [#uses=1]
@lvgv105 = internal constant [0 x i8*] zeroinitializer ; <[0 x i8*]*> [#uses=1]
@llvm.global.annotations = appending global [36 x %0] [%0 { i8* bitcast (void (float addrspace(1)*, i32 addrspace(1)*)* @__OpenCL_test_fa1_1_1_kern_kernel to i8*), i8* getelementptr inbounds ([1 x i8]* @sgv, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @fgv, i32 0, i32 0), i8* bitcast ([0 x i8*]* @lvgv to i8*), i32 0 }, %0 { i8* bitcast (void (float addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*)* @__OpenCL_test_fa1_1_2_kern_kernel to i8*), i8* getelementptr inbounds ([1 x i8]* @sgv1, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @fgv2, i32 0, i32 0), i8* bitcast ([0 x i8*]* @lvgv3 to i8*), i32 0 }, %0 { i8* bitcast (void (float addrspace(1)*, float addrspace(1)*, i32 addrspace(1)*)* @__OpenCL_test_fa1_2_1_kern_kernel to i8*), i8* getelementptr inbounds ([1 x i8]* @sgv4, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @fgv5, i32 0, i32 0), i8* bitcast ([0 x i8*]* @lvgv6 to i8*), i32 0 }, %0 { i8* bitcast (void (float addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*)* @__OpenCL_test_fa1_1_3_kern_kernel to i8*), i8* getelementptr inbounds ([1 x i8]* @sgv7, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @fgv8, i32 0, i32 0), i8* bitcast ([0 x i8*]* @lvgv9 to i8*), i32 0 }, %0 { i8* bitcast (void (float addrspace(1)*, float addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*)* @__OpenCL_test_fa1_2_2_kern_kernel to i8*), i8* getelementptr inbounds ([1 x i8]* @sgv10, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @fgv11, i32 0, i32 0), i8* bitcast ([0 x i8*]* @lvgv12 to i8*), i32 0 }, %0 { i8* bitcast (void (float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, i32 addrspace(1)*)* @__OpenCL_test_fa1_3_1_kern_kernel to i8*), i8* getelementptr inbounds ([1 x i8]* @sgv13, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @fgv14, i32 0, i32 0), i8* bitcast ([0 x i8*]* @lvgv15 to i8*), i32 0 }, %0 { i8* bitcast (void (float addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*)* @__OpenCL_test_fa1_1_4_kern_kernel to i8*), i8* getelementptr inbounds ([1 x i8]* @sgv16, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @fgv17, i32 0, i32 0), i8* bitcast ([0 x i8*]* @lvgv18 to i8*), i32 0 }, %0 { i8* bitcast (void (float addrspace(1)*, float addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*)* @__OpenCL_test_fa1_2_3_kern_kernel to i8*), i8* getelementptr inbounds ([1 x i8]* @sgv19, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @fgv20, i32 0, i32 0), i8* bitcast ([0 x i8*]* @lvgv21 to i8*), i32 0 }, %0 { i8* bitcast (void (float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*)* @__OpenCL_test_fa1_3_2_kern_kernel to i8*), i8* getelementptr inbounds ([1 x i8]* @sgv22, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @fgv23, i32 0, i32 0), i8* bitcast ([0 x i8*]* @lvgv24 to i8*), i32 0 }, %0 { i8* bitcast (void (float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, i32 addrspace(1)*)* @__OpenCL_test_fa1_4_1_kern_kernel to i8*), i8* getelementptr inbounds ([1 x i8]* @sgv25, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @fgv26, i32 0, i32 0), i8* bitcast ([0 x i8*]* @lvgv27 to i8*), i32 0 }, %0 { i8* bitcast (void (float addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*)* @__OpenCL_test_fa1_1_5_kern_kernel to i8*), i8* getelementptr inbounds ([1 x i8]* @sgv28, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @fgv29, i32 0, i32 0), i8* bitcast ([0 x i8*]* @lvgv30 to i8*), i32 0 }, %0 { i8* bitcast (void (float addrspace(1)*, float addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*)* @__OpenCL_test_fa1_2_4_kern_kernel to i8*), i8* getelementptr inbounds ([1 x i8]* @sgv31, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @fgv32, i32 0, i32 0), i8* bitcast ([0 x i8*]* @lvgv33 to i8*), i32 0 }, %0 { i8* bitcast (void (float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*)* @__OpenCL_test_fa1_3_3_kern_kernel to i8*), i8* getelementptr inbounds ([1 x i8]* @sgv34, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @fgv35, i32 0, i32 0), i8* bitcast ([0 x i8*]* @lvgv36 to i8*), i32 0 }, %0 { i8* bitcast (void (float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*)* @__OpenCL_test_fa1_4_2_kern_kernel to i8*), i8* getelementptr inbounds ([1 x i8]* @sgv37, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @fgv38, i32 0, i32 0), i8* bitcast ([0 x i8*]* @lvgv39 to i8*), i32 0 }, %0 { i8* bitcast (void (float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, i32 addrspace(1)*)* @__OpenCL_test_fa1_5_1_kern_kernel to i8*), i8* getelementptr inbounds ([1 x i8]* @sgv40, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @fgv41, i32 0, i32 0), i8* bitcast ([0 x i8*]* @lvgv42 to i8*), i32 0 }, %0 { i8* bitcast (void (float addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*)* @__OpenCL_test_fa1_1_6_kern_kernel to i8*), i8* getelementptr inbounds ([1 x i8]* @sgv43, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @fgv44, i32 0, i32 0), i8* bitcast ([0 x i8*]* @lvgv45 to i8*), i32 0 }, %0 { i8* bitcast (void (float addrspace(1)*, float addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*)* @__OpenCL_test_fa1_2_5_kern_kernel to i8*), i8* getelementptr inbounds ([1 x i8]* @sgv46, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @fgv47, i32 0, i32 0), i8* bitcast ([0 x i8*]* @lvgv48 to i8*), i32 0 }, %0 { i8* bitcast (void (float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*)* @__OpenCL_test_fa1_3_4_kern_kernel to i8*), i8* getelementptr inbounds ([1 x i8]* @sgv49, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @fgv50, i32 0, i32 0), i8* bitcast ([0 x i8*]* @lvgv51 to i8*), i32 0 }, %0 { i8* bitcast (void (float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*)* @__OpenCL_test_fa1_4_3_kern_kernel to i8*), i8* getelementptr inbounds ([1 x i8]* @sgv52, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @fgv53, i32 0, i32 0), i8* bitcast ([0 x i8*]* @lvgv54 to i8*), i32 0 }, %0 { i8* bitcast (void (float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*)* @__OpenCL_test_fa1_5_2_kern_kernel to i8*), i8* getelementptr inbounds ([1 x i8]* @sgv55, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @fgv56, i32 0, i32 0), i8* bitcast ([0 x i8*]* @lvgv57 to i8*), i32 0 }, %0 { i8* bitcast (void (float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, i32 addrspace(1)*)* @__OpenCL_test_fa1_6_1_kern_kernel to i8*), i8* getelementptr inbounds ([1 x i8]* @sgv58, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @fgv59, i32 0, i32 0), i8* bitcast ([0 x i8*]* @lvgv60 to i8*), i32 0 }, %0 { i8* bitcast (void (float addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*)* @__OpenCL_test_fa1_1_7_kern_kernel to i8*), i8* getelementptr inbounds ([1 x i8]* @sgv61, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @fgv62, i32 0, i32 0), i8* bitcast ([0 x i8*]* @lvgv63 to i8*), i32 0 }, %0 { i8* bitcast (void (float addrspace(1)*, float addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*)* @__OpenCL_test_fa1_2_6_kern_kernel to i8*), i8* getelementptr inbounds ([1 x i8]* @sgv64, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @fgv65, i32 0, i32 0), i8* bitcast ([0 x i8*]* @lvgv66 to i8*), i32 0 }, %0 { i8* bitcast (void (float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*)* @__OpenCL_test_fa1_3_5_kern_kernel to i8*), i8* getelementptr inbounds ([1 x i8]* @sgv67, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @fgv68, i32 0, i32 0), i8* bitcast ([0 x i8*]* @lvgv69 to i8*), i32 0 }, %0 { i8* bitcast (void (float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*)* @__OpenCL_test_fa1_4_4_kern_kernel to i8*), i8* getelementptr inbounds ([1 x i8]* @sgv70, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @fgv71, i32 0, i32 0), i8* bitcast ([0 x i8*]* @lvgv72 to i8*), i32 0 }, %0 { i8* bitcast (void (float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*)* @__OpenCL_test_fa1_5_3_kern_kernel to i8*), i8* getelementptr inbounds ([1 x i8]* @sgv73, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @fgv74, i32 0, i32 0), i8* bitcast ([0 x i8*]* @lvgv75 to i8*), i32 0 }, %0 { i8* bitcast (void (float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*)* @__OpenCL_test_fa1_6_2_kern_kernel to i8*), i8* getelementptr inbounds ([1 x i8]* @sgv76, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @fgv77, i32 0, i32 0), i8* bitcast ([0 x i8*]* @lvgv78 to i8*), i32 0 }, %0 { i8* bitcast (void (float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, i32 addrspace(1)*)* @__OpenCL_test_fa1_7_1_kern_kernel to i8*), i8* getelementptr inbounds ([1 x i8]* @sgv79, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @fgv80, i32 0, i32 0), i8* bitcast ([0 x i8*]* @lvgv81 to i8*), i32 0 }, %0 { i8* bitcast (void (float addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*)* @__OpenCL_test_fa1_1_8_kern_kernel to i8*), i8* getelementptr inbounds ([1 x i8]* @sgv82, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @fgv83, i32 0, i32 0), i8* bitcast ([0 x i8*]* @lvgv84 to i8*), i32 0 }, %0 { i8* bitcast (void (float addrspace(1)*, float addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*)* @__OpenCL_test_fa1_2_7_kern_kernel to i8*), i8* getelementptr inbounds ([1 x i8]* @sgv85, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @fgv86, i32 0, i32 0), i8* bitcast ([0 x i8*]* @lvgv87 to i8*), i32 0 }, %0 { i8* bitcast (void (float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*)* @__OpenCL_test_fa1_3_6_kern_kernel to i8*), i8* getelementptr inbounds ([1 x i8]* @sgv88, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @fgv89, i32 0, i32 0), i8* bitcast ([0 x i8*]* @lvgv90 to i8*), i32 0 }, %0 { i8* bitcast (void (float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*)* @__OpenCL_test_fa1_4_5_kern_kernel to i8*), i8* getelementptr inbounds ([1 x i8]* @sgv91, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @fgv92, i32 0, i32 0), i8* bitcast ([0 x i8*]* @lvgv93 to i8*), i32 0 }, %0 { i8* bitcast (void (float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*)* @__OpenCL_test_fa1_5_4_kern_kernel to i8*), i8* getelementptr inbounds ([1 x i8]* @sgv94, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @fgv95, i32 0, i32 0), i8* bitcast ([0 x i8*]* @lvgv96 to i8*), i32 0 }, %0 { i8* bitcast (void (float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*)* @__OpenCL_test_fa1_6_3_kern_kernel to i8*), i8* getelementptr inbounds ([1 x i8]* @sgv97, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @fgv98, i32 0, i32 0), i8* bitcast ([0 x i8*]* @lvgv99 to i8*), i32 0 }, %0 { i8* bitcast (void (float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, i32 addrspace(1)*, i32 addrspace(1)*)* @__OpenCL_test_fa1_7_2_kern_kernel to i8*), i8* getelementptr inbounds ([1 x i8]* @sgv100, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @fgv101, i32 0, i32 0), i8* bitcast ([0 x i8*]* @lvgv102 to i8*), i32 0 }, %0 { i8* bitcast (void (float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, float addrspace(1)*, i32 addrspace(1)*)* @__OpenCL_test_fa1_8_1_kern_kernel to i8*), i8* getelementptr inbounds ([1 x i8]* @sgv103, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @fgv104, i32 0, i32 0), i8* bitcast ([0 x i8*]* @lvgv105 to i8*), i32 0 }], section "llvm.metadata" ; <[36 x %0]*> [#uses=0]

define void @__OpenCL_test_fa1_1_1_kern_kernel(float addrspace(1)* %a0, i32 addrspace(1)* %b0) nounwind {
entry:
  %a0.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %b0.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %gtid = alloca i32, align 4                     ; <i32*> [#uses=3]
  %tmp0 = alloca float, align 4                   ; <float*> [#uses=2]
  store float addrspace(1)* %a0, float addrspace(1)** %a0.addr
  store i32 addrspace(1)* %b0, i32 addrspace(1)** %b0.addr
  %call = call i32 @get_global_id(i32 0) nounwind ; <i32> [#uses=1]
  store i32 %call, i32* %gtid
  %tmp = load float addrspace(1)** %a0.addr       ; <float addrspace(1)*> [#uses=1]
  %tmp1 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx = getelementptr float addrspace(1)* %tmp, i32 %tmp1 ; <float addrspace(1)*> [#uses=1]
  %tmp2 = load float addrspace(1)* %arrayidx      ; <float> [#uses=1]
  %tmp3 = fadd float %tmp2, 0x3FB99999A0000000    ; <float> [#uses=1]
  store float %tmp3, float* %tmp0
  %tmp4 = load i32 addrspace(1)** %b0.addr        ; <i32 addrspace(1)*> [#uses=1]
  %tmp5 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx6 = getelementptr i32 addrspace(1)* %tmp4, i32 %tmp5 ; <i32 addrspace(1)*> [#uses=1]
  %tmp7 = load float* %tmp0                       ; <float> [#uses=1]
  %tmp8 = fmul float 0x3FF19999A0000000, %tmp7    ; <float> [#uses=1]
  %conv = fptosi float %tmp8 to i32               ; <i32> [#uses=1]
  store i32 %conv, i32 addrspace(1)* %arrayidx6
  br label %return

return:                                           ; preds = %entry
  ret void
}

declare i32 @get_global_id(i32) nounwind

define void @__OpenCL_test_fa1_1_2_kern_kernel(float addrspace(1)* %a0, i32 addrspace(1)* %b0, i32 addrspace(1)* %b1) nounwind {
entry:
  %a0.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %b0.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b1.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %gtid = alloca i32, align 4                     ; <i32*> [#uses=4]
  %tmp0 = alloca float, align 4                   ; <float*> [#uses=3]
  store float addrspace(1)* %a0, float addrspace(1)** %a0.addr
  store i32 addrspace(1)* %b0, i32 addrspace(1)** %b0.addr
  store i32 addrspace(1)* %b1, i32 addrspace(1)** %b1.addr
  %call = call i32 @get_global_id(i32 0) nounwind ; <i32> [#uses=1]
  store i32 %call, i32* %gtid
  %tmp = load float addrspace(1)** %a0.addr       ; <float addrspace(1)*> [#uses=1]
  %tmp1 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx = getelementptr float addrspace(1)* %tmp, i32 %tmp1 ; <float addrspace(1)*> [#uses=1]
  %tmp2 = load float addrspace(1)* %arrayidx      ; <float> [#uses=1]
  %tmp3 = fadd float %tmp2, 0x3FB99999A0000000    ; <float> [#uses=1]
  store float %tmp3, float* %tmp0
  %tmp4 = load i32 addrspace(1)** %b0.addr        ; <i32 addrspace(1)*> [#uses=1]
  %tmp5 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx6 = getelementptr i32 addrspace(1)* %tmp4, i32 %tmp5 ; <i32 addrspace(1)*> [#uses=1]
  %tmp7 = load float* %tmp0                       ; <float> [#uses=1]
  %tmp8 = fmul float 0x3FF19999A0000000, %tmp7    ; <float> [#uses=1]
  %conv = fptosi float %tmp8 to i32               ; <i32> [#uses=1]
  store i32 %conv, i32 addrspace(1)* %arrayidx6
  %tmp9 = load i32 addrspace(1)** %b1.addr        ; <i32 addrspace(1)*> [#uses=1]
  %tmp10 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx11 = getelementptr i32 addrspace(1)* %tmp9, i32 %tmp10 ; <i32 addrspace(1)*> [#uses=1]
  %tmp12 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp13 = fmul float 0x4000CCCCC0000000, %tmp12  ; <float> [#uses=1]
  %conv14 = fptosi float %tmp13 to i32            ; <i32> [#uses=1]
  store i32 %conv14, i32 addrspace(1)* %arrayidx11
  br label %return

return:                                           ; preds = %entry
  ret void
}

define void @__OpenCL_test_fa1_2_1_kern_kernel(float addrspace(1)* %a0, float addrspace(1)* %a1, i32 addrspace(1)* %b0) nounwind {
entry:
  %a0.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a1.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %b0.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %gtid = alloca i32, align 4                     ; <i32*> [#uses=4]
  %tmp0 = alloca float, align 4                   ; <float*> [#uses=2]
  %tmp1 = alloca float, align 4                   ; <float*> [#uses=2]
  store float addrspace(1)* %a0, float addrspace(1)** %a0.addr
  store float addrspace(1)* %a1, float addrspace(1)** %a1.addr
  store i32 addrspace(1)* %b0, i32 addrspace(1)** %b0.addr
  %call = call i32 @get_global_id(i32 0) nounwind ; <i32> [#uses=1]
  store i32 %call, i32* %gtid
  %tmp = load float addrspace(1)** %a0.addr       ; <float addrspace(1)*> [#uses=1]
  %tmp2 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx = getelementptr float addrspace(1)* %tmp, i32 %tmp2 ; <float addrspace(1)*> [#uses=1]
  %tmp3 = load float addrspace(1)* %arrayidx      ; <float> [#uses=1]
  %tmp4 = fadd float %tmp3, 0x3FB99999A0000000    ; <float> [#uses=1]
  store float %tmp4, float* %tmp0
  %tmp5 = load float addrspace(1)** %a1.addr      ; <float addrspace(1)*> [#uses=1]
  %tmp6 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx7 = getelementptr float addrspace(1)* %tmp5, i32 %tmp6 ; <float addrspace(1)*> [#uses=1]
  %tmp8 = load float addrspace(1)* %arrayidx7     ; <float> [#uses=1]
  %tmp9 = fadd float %tmp8, 0x3FF19999A0000000    ; <float> [#uses=1]
  store float %tmp9, float* %tmp1
  %tmp10 = load i32 addrspace(1)** %b0.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp11 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx12 = getelementptr i32 addrspace(1)* %tmp10, i32 %tmp11 ; <i32 addrspace(1)*> [#uses=1]
  %tmp13 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp14 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp15 = fadd float %tmp13, %tmp14              ; <float> [#uses=1]
  %tmp16 = fmul float 0x3FF19999A0000000, %tmp15  ; <float> [#uses=1]
  %conv = fptosi float %tmp16 to i32              ; <i32> [#uses=1]
  store i32 %conv, i32 addrspace(1)* %arrayidx12
  br label %return

return:                                           ; preds = %entry
  ret void
}

define void @__OpenCL_test_fa1_1_3_kern_kernel(float addrspace(1)* %a0, i32 addrspace(1)* %b0, i32 addrspace(1)* %b1, i32 addrspace(1)* %b2) nounwind {
entry:
  %a0.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %b0.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b1.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b2.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %gtid = alloca i32, align 4                     ; <i32*> [#uses=5]
  %tmp0 = alloca float, align 4                   ; <float*> [#uses=4]
  store float addrspace(1)* %a0, float addrspace(1)** %a0.addr
  store i32 addrspace(1)* %b0, i32 addrspace(1)** %b0.addr
  store i32 addrspace(1)* %b1, i32 addrspace(1)** %b1.addr
  store i32 addrspace(1)* %b2, i32 addrspace(1)** %b2.addr
  %call = call i32 @get_global_id(i32 0) nounwind ; <i32> [#uses=1]
  store i32 %call, i32* %gtid
  %tmp = load float addrspace(1)** %a0.addr       ; <float addrspace(1)*> [#uses=1]
  %tmp1 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx = getelementptr float addrspace(1)* %tmp, i32 %tmp1 ; <float addrspace(1)*> [#uses=1]
  %tmp2 = load float addrspace(1)* %arrayidx      ; <float> [#uses=1]
  %tmp3 = fadd float %tmp2, 0x3FB99999A0000000    ; <float> [#uses=1]
  store float %tmp3, float* %tmp0
  %tmp4 = load i32 addrspace(1)** %b0.addr        ; <i32 addrspace(1)*> [#uses=1]
  %tmp5 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx6 = getelementptr i32 addrspace(1)* %tmp4, i32 %tmp5 ; <i32 addrspace(1)*> [#uses=1]
  %tmp7 = load float* %tmp0                       ; <float> [#uses=1]
  %tmp8 = fmul float 0x3FF19999A0000000, %tmp7    ; <float> [#uses=1]
  %conv = fptosi float %tmp8 to i32               ; <i32> [#uses=1]
  store i32 %conv, i32 addrspace(1)* %arrayidx6
  %tmp9 = load i32 addrspace(1)** %b1.addr        ; <i32 addrspace(1)*> [#uses=1]
  %tmp10 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx11 = getelementptr i32 addrspace(1)* %tmp9, i32 %tmp10 ; <i32 addrspace(1)*> [#uses=1]
  %tmp12 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp13 = fmul float 0x4000CCCCC0000000, %tmp12  ; <float> [#uses=1]
  %conv14 = fptosi float %tmp13 to i32            ; <i32> [#uses=1]
  store i32 %conv14, i32 addrspace(1)* %arrayidx11
  %tmp15 = load i32 addrspace(1)** %b2.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp16 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx17 = getelementptr i32 addrspace(1)* %tmp15, i32 %tmp16 ; <i32 addrspace(1)*> [#uses=1]
  %tmp18 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp19 = fmul float 0x4008CCCCC0000000, %tmp18  ; <float> [#uses=1]
  %conv20 = fptosi float %tmp19 to i32            ; <i32> [#uses=1]
  store i32 %conv20, i32 addrspace(1)* %arrayidx17
  br label %return

return:                                           ; preds = %entry
  ret void
}

define void @__OpenCL_test_fa1_2_2_kern_kernel(float addrspace(1)* %a0, float addrspace(1)* %a1, i32 addrspace(1)* %b0, i32 addrspace(1)* %b1) nounwind {
entry:
  %a0.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a1.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %b0.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b1.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %gtid = alloca i32, align 4                     ; <i32*> [#uses=5]
  %tmp0 = alloca float, align 4                   ; <float*> [#uses=3]
  %tmp1 = alloca float, align 4                   ; <float*> [#uses=3]
  store float addrspace(1)* %a0, float addrspace(1)** %a0.addr
  store float addrspace(1)* %a1, float addrspace(1)** %a1.addr
  store i32 addrspace(1)* %b0, i32 addrspace(1)** %b0.addr
  store i32 addrspace(1)* %b1, i32 addrspace(1)** %b1.addr
  %call = call i32 @get_global_id(i32 0) nounwind ; <i32> [#uses=1]
  store i32 %call, i32* %gtid
  %tmp = load float addrspace(1)** %a0.addr       ; <float addrspace(1)*> [#uses=1]
  %tmp2 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx = getelementptr float addrspace(1)* %tmp, i32 %tmp2 ; <float addrspace(1)*> [#uses=1]
  %tmp3 = load float addrspace(1)* %arrayidx      ; <float> [#uses=1]
  %tmp4 = fadd float %tmp3, 0x3FB99999A0000000    ; <float> [#uses=1]
  store float %tmp4, float* %tmp0
  %tmp5 = load float addrspace(1)** %a1.addr      ; <float addrspace(1)*> [#uses=1]
  %tmp6 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx7 = getelementptr float addrspace(1)* %tmp5, i32 %tmp6 ; <float addrspace(1)*> [#uses=1]
  %tmp8 = load float addrspace(1)* %arrayidx7     ; <float> [#uses=1]
  %tmp9 = fadd float %tmp8, 0x3FF19999A0000000    ; <float> [#uses=1]
  store float %tmp9, float* %tmp1
  %tmp10 = load i32 addrspace(1)** %b0.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp11 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx12 = getelementptr i32 addrspace(1)* %tmp10, i32 %tmp11 ; <i32 addrspace(1)*> [#uses=1]
  %tmp13 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp14 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp15 = fadd float %tmp13, %tmp14              ; <float> [#uses=1]
  %tmp16 = fmul float 0x3FF19999A0000000, %tmp15  ; <float> [#uses=1]
  %conv = fptosi float %tmp16 to i32              ; <i32> [#uses=1]
  store i32 %conv, i32 addrspace(1)* %arrayidx12
  %tmp17 = load i32 addrspace(1)** %b1.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp18 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx19 = getelementptr i32 addrspace(1)* %tmp17, i32 %tmp18 ; <i32 addrspace(1)*> [#uses=1]
  %tmp20 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp21 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp22 = fadd float %tmp20, %tmp21              ; <float> [#uses=1]
  %tmp23 = fmul float 0x4000CCCCC0000000, %tmp22  ; <float> [#uses=1]
  %conv24 = fptosi float %tmp23 to i32            ; <i32> [#uses=1]
  store i32 %conv24, i32 addrspace(1)* %arrayidx19
  br label %return

return:                                           ; preds = %entry
  ret void
}

define void @__OpenCL_test_fa1_3_1_kern_kernel(float addrspace(1)* %a0, float addrspace(1)* %a1, float addrspace(1)* %a2, i32 addrspace(1)* %b0) nounwind {
entry:
  %a0.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a1.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a2.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %b0.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %gtid = alloca i32, align 4                     ; <i32*> [#uses=5]
  %tmp0 = alloca float, align 4                   ; <float*> [#uses=2]
  %tmp1 = alloca float, align 4                   ; <float*> [#uses=2]
  %tmp2 = alloca float, align 4                   ; <float*> [#uses=2]
  store float addrspace(1)* %a0, float addrspace(1)** %a0.addr
  store float addrspace(1)* %a1, float addrspace(1)** %a1.addr
  store float addrspace(1)* %a2, float addrspace(1)** %a2.addr
  store i32 addrspace(1)* %b0, i32 addrspace(1)** %b0.addr
  %call = call i32 @get_global_id(i32 0) nounwind ; <i32> [#uses=1]
  store i32 %call, i32* %gtid
  %tmp = load float addrspace(1)** %a0.addr       ; <float addrspace(1)*> [#uses=1]
  %tmp3 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx = getelementptr float addrspace(1)* %tmp, i32 %tmp3 ; <float addrspace(1)*> [#uses=1]
  %tmp4 = load float addrspace(1)* %arrayidx      ; <float> [#uses=1]
  %tmp5 = fadd float %tmp4, 0x3FB99999A0000000    ; <float> [#uses=1]
  store float %tmp5, float* %tmp0
  %tmp6 = load float addrspace(1)** %a1.addr      ; <float addrspace(1)*> [#uses=1]
  %tmp7 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx8 = getelementptr float addrspace(1)* %tmp6, i32 %tmp7 ; <float addrspace(1)*> [#uses=1]
  %tmp9 = load float addrspace(1)* %arrayidx8     ; <float> [#uses=1]
  %tmp10 = fadd float %tmp9, 0x3FF19999A0000000   ; <float> [#uses=1]
  store float %tmp10, float* %tmp1
  %tmp11 = load float addrspace(1)** %a2.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp12 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx13 = getelementptr float addrspace(1)* %tmp11, i32 %tmp12 ; <float addrspace(1)*> [#uses=1]
  %tmp14 = load float addrspace(1)* %arrayidx13   ; <float> [#uses=1]
  %tmp15 = fadd float %tmp14, 0x4000CCCCC0000000  ; <float> [#uses=1]
  store float %tmp15, float* %tmp2
  %tmp16 = load i32 addrspace(1)** %b0.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp17 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx18 = getelementptr i32 addrspace(1)* %tmp16, i32 %tmp17 ; <i32 addrspace(1)*> [#uses=1]
  %tmp19 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp20 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp21 = fadd float %tmp19, %tmp20              ; <float> [#uses=1]
  %tmp22 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp23 = fadd float %tmp21, %tmp22              ; <float> [#uses=1]
  %tmp24 = fmul float 0x3FF19999A0000000, %tmp23  ; <float> [#uses=1]
  %conv = fptosi float %tmp24 to i32              ; <i32> [#uses=1]
  store i32 %conv, i32 addrspace(1)* %arrayidx18
  br label %return

return:                                           ; preds = %entry
  ret void
}

define void @__OpenCL_test_fa1_1_4_kern_kernel(float addrspace(1)* %a0, i32 addrspace(1)* %b0, i32 addrspace(1)* %b1, i32 addrspace(1)* %b2, i32 addrspace(1)* %b3) nounwind {
entry:
  %a0.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %b0.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b1.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b2.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b3.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %gtid = alloca i32, align 4                     ; <i32*> [#uses=6]
  %tmp0 = alloca float, align 4                   ; <float*> [#uses=5]
  store float addrspace(1)* %a0, float addrspace(1)** %a0.addr
  store i32 addrspace(1)* %b0, i32 addrspace(1)** %b0.addr
  store i32 addrspace(1)* %b1, i32 addrspace(1)** %b1.addr
  store i32 addrspace(1)* %b2, i32 addrspace(1)** %b2.addr
  store i32 addrspace(1)* %b3, i32 addrspace(1)** %b3.addr
  %call = call i32 @get_global_id(i32 0) nounwind ; <i32> [#uses=1]
  store i32 %call, i32* %gtid
  %tmp = load float addrspace(1)** %a0.addr       ; <float addrspace(1)*> [#uses=1]
  %tmp1 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx = getelementptr float addrspace(1)* %tmp, i32 %tmp1 ; <float addrspace(1)*> [#uses=1]
  %tmp2 = load float addrspace(1)* %arrayidx      ; <float> [#uses=1]
  %tmp3 = fadd float %tmp2, 0x3FB99999A0000000    ; <float> [#uses=1]
  store float %tmp3, float* %tmp0
  %tmp4 = load i32 addrspace(1)** %b0.addr        ; <i32 addrspace(1)*> [#uses=1]
  %tmp5 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx6 = getelementptr i32 addrspace(1)* %tmp4, i32 %tmp5 ; <i32 addrspace(1)*> [#uses=1]
  %tmp7 = load float* %tmp0                       ; <float> [#uses=1]
  %tmp8 = fmul float 0x3FF19999A0000000, %tmp7    ; <float> [#uses=1]
  %conv = fptosi float %tmp8 to i32               ; <i32> [#uses=1]
  store i32 %conv, i32 addrspace(1)* %arrayidx6
  %tmp9 = load i32 addrspace(1)** %b1.addr        ; <i32 addrspace(1)*> [#uses=1]
  %tmp10 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx11 = getelementptr i32 addrspace(1)* %tmp9, i32 %tmp10 ; <i32 addrspace(1)*> [#uses=1]
  %tmp12 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp13 = fmul float 0x4000CCCCC0000000, %tmp12  ; <float> [#uses=1]
  %conv14 = fptosi float %tmp13 to i32            ; <i32> [#uses=1]
  store i32 %conv14, i32 addrspace(1)* %arrayidx11
  %tmp15 = load i32 addrspace(1)** %b2.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp16 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx17 = getelementptr i32 addrspace(1)* %tmp15, i32 %tmp16 ; <i32 addrspace(1)*> [#uses=1]
  %tmp18 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp19 = fmul float 0x4008CCCCC0000000, %tmp18  ; <float> [#uses=1]
  %conv20 = fptosi float %tmp19 to i32            ; <i32> [#uses=1]
  store i32 %conv20, i32 addrspace(1)* %arrayidx17
  %tmp21 = load i32 addrspace(1)** %b3.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp22 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx23 = getelementptr i32 addrspace(1)* %tmp21, i32 %tmp22 ; <i32 addrspace(1)*> [#uses=1]
  %tmp24 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp25 = fmul float 0x4010666660000000, %tmp24  ; <float> [#uses=1]
  %conv26 = fptosi float %tmp25 to i32            ; <i32> [#uses=1]
  store i32 %conv26, i32 addrspace(1)* %arrayidx23
  br label %return

return:                                           ; preds = %entry
  ret void
}

define void @__OpenCL_test_fa1_2_3_kern_kernel(float addrspace(1)* %a0, float addrspace(1)* %a1, i32 addrspace(1)* %b0, i32 addrspace(1)* %b1, i32 addrspace(1)* %b2) nounwind {
entry:
  %a0.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a1.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %b0.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b1.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b2.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %gtid = alloca i32, align 4                     ; <i32*> [#uses=6]
  %tmp0 = alloca float, align 4                   ; <float*> [#uses=4]
  %tmp1 = alloca float, align 4                   ; <float*> [#uses=4]
  store float addrspace(1)* %a0, float addrspace(1)** %a0.addr
  store float addrspace(1)* %a1, float addrspace(1)** %a1.addr
  store i32 addrspace(1)* %b0, i32 addrspace(1)** %b0.addr
  store i32 addrspace(1)* %b1, i32 addrspace(1)** %b1.addr
  store i32 addrspace(1)* %b2, i32 addrspace(1)** %b2.addr
  %call = call i32 @get_global_id(i32 0) nounwind ; <i32> [#uses=1]
  store i32 %call, i32* %gtid
  %tmp = load float addrspace(1)** %a0.addr       ; <float addrspace(1)*> [#uses=1]
  %tmp2 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx = getelementptr float addrspace(1)* %tmp, i32 %tmp2 ; <float addrspace(1)*> [#uses=1]
  %tmp3 = load float addrspace(1)* %arrayidx      ; <float> [#uses=1]
  %tmp4 = fadd float %tmp3, 0x3FB99999A0000000    ; <float> [#uses=1]
  store float %tmp4, float* %tmp0
  %tmp5 = load float addrspace(1)** %a1.addr      ; <float addrspace(1)*> [#uses=1]
  %tmp6 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx7 = getelementptr float addrspace(1)* %tmp5, i32 %tmp6 ; <float addrspace(1)*> [#uses=1]
  %tmp8 = load float addrspace(1)* %arrayidx7     ; <float> [#uses=1]
  %tmp9 = fadd float %tmp8, 0x3FF19999A0000000    ; <float> [#uses=1]
  store float %tmp9, float* %tmp1
  %tmp10 = load i32 addrspace(1)** %b0.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp11 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx12 = getelementptr i32 addrspace(1)* %tmp10, i32 %tmp11 ; <i32 addrspace(1)*> [#uses=1]
  %tmp13 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp14 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp15 = fadd float %tmp13, %tmp14              ; <float> [#uses=1]
  %tmp16 = fmul float 0x3FF19999A0000000, %tmp15  ; <float> [#uses=1]
  %conv = fptosi float %tmp16 to i32              ; <i32> [#uses=1]
  store i32 %conv, i32 addrspace(1)* %arrayidx12
  %tmp17 = load i32 addrspace(1)** %b1.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp18 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx19 = getelementptr i32 addrspace(1)* %tmp17, i32 %tmp18 ; <i32 addrspace(1)*> [#uses=1]
  %tmp20 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp21 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp22 = fadd float %tmp20, %tmp21              ; <float> [#uses=1]
  %tmp23 = fmul float 0x4000CCCCC0000000, %tmp22  ; <float> [#uses=1]
  %conv24 = fptosi float %tmp23 to i32            ; <i32> [#uses=1]
  store i32 %conv24, i32 addrspace(1)* %arrayidx19
  %tmp25 = load i32 addrspace(1)** %b2.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp26 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx27 = getelementptr i32 addrspace(1)* %tmp25, i32 %tmp26 ; <i32 addrspace(1)*> [#uses=1]
  %tmp28 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp29 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp30 = fadd float %tmp28, %tmp29              ; <float> [#uses=1]
  %tmp31 = fmul float 0x4008CCCCC0000000, %tmp30  ; <float> [#uses=1]
  %conv32 = fptosi float %tmp31 to i32            ; <i32> [#uses=1]
  store i32 %conv32, i32 addrspace(1)* %arrayidx27
  br label %return

return:                                           ; preds = %entry
  ret void
}

define void @__OpenCL_test_fa1_3_2_kern_kernel(float addrspace(1)* %a0, float addrspace(1)* %a1, float addrspace(1)* %a2, i32 addrspace(1)* %b0, i32 addrspace(1)* %b1) nounwind {
entry:
  %a0.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a1.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a2.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %b0.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b1.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %gtid = alloca i32, align 4                     ; <i32*> [#uses=6]
  %tmp0 = alloca float, align 4                   ; <float*> [#uses=3]
  %tmp1 = alloca float, align 4                   ; <float*> [#uses=3]
  %tmp2 = alloca float, align 4                   ; <float*> [#uses=3]
  store float addrspace(1)* %a0, float addrspace(1)** %a0.addr
  store float addrspace(1)* %a1, float addrspace(1)** %a1.addr
  store float addrspace(1)* %a2, float addrspace(1)** %a2.addr
  store i32 addrspace(1)* %b0, i32 addrspace(1)** %b0.addr
  store i32 addrspace(1)* %b1, i32 addrspace(1)** %b1.addr
  %call = call i32 @get_global_id(i32 0) nounwind ; <i32> [#uses=1]
  store i32 %call, i32* %gtid
  %tmp = load float addrspace(1)** %a0.addr       ; <float addrspace(1)*> [#uses=1]
  %tmp3 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx = getelementptr float addrspace(1)* %tmp, i32 %tmp3 ; <float addrspace(1)*> [#uses=1]
  %tmp4 = load float addrspace(1)* %arrayidx      ; <float> [#uses=1]
  %tmp5 = fadd float %tmp4, 0x3FB99999A0000000    ; <float> [#uses=1]
  store float %tmp5, float* %tmp0
  %tmp6 = load float addrspace(1)** %a1.addr      ; <float addrspace(1)*> [#uses=1]
  %tmp7 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx8 = getelementptr float addrspace(1)* %tmp6, i32 %tmp7 ; <float addrspace(1)*> [#uses=1]
  %tmp9 = load float addrspace(1)* %arrayidx8     ; <float> [#uses=1]
  %tmp10 = fadd float %tmp9, 0x3FF19999A0000000   ; <float> [#uses=1]
  store float %tmp10, float* %tmp1
  %tmp11 = load float addrspace(1)** %a2.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp12 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx13 = getelementptr float addrspace(1)* %tmp11, i32 %tmp12 ; <float addrspace(1)*> [#uses=1]
  %tmp14 = load float addrspace(1)* %arrayidx13   ; <float> [#uses=1]
  %tmp15 = fadd float %tmp14, 0x4000CCCCC0000000  ; <float> [#uses=1]
  store float %tmp15, float* %tmp2
  %tmp16 = load i32 addrspace(1)** %b0.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp17 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx18 = getelementptr i32 addrspace(1)* %tmp16, i32 %tmp17 ; <i32 addrspace(1)*> [#uses=1]
  %tmp19 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp20 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp21 = fadd float %tmp19, %tmp20              ; <float> [#uses=1]
  %tmp22 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp23 = fadd float %tmp21, %tmp22              ; <float> [#uses=1]
  %tmp24 = fmul float 0x3FF19999A0000000, %tmp23  ; <float> [#uses=1]
  %conv = fptosi float %tmp24 to i32              ; <i32> [#uses=1]
  store i32 %conv, i32 addrspace(1)* %arrayidx18
  %tmp25 = load i32 addrspace(1)** %b1.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp26 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx27 = getelementptr i32 addrspace(1)* %tmp25, i32 %tmp26 ; <i32 addrspace(1)*> [#uses=1]
  %tmp28 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp29 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp30 = fadd float %tmp28, %tmp29              ; <float> [#uses=1]
  %tmp31 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp32 = fadd float %tmp30, %tmp31              ; <float> [#uses=1]
  %tmp33 = fmul float 0x4000CCCCC0000000, %tmp32  ; <float> [#uses=1]
  %conv34 = fptosi float %tmp33 to i32            ; <i32> [#uses=1]
  store i32 %conv34, i32 addrspace(1)* %arrayidx27
  br label %return

return:                                           ; preds = %entry
  ret void
}

define void @__OpenCL_test_fa1_4_1_kern_kernel(float addrspace(1)* %a0, float addrspace(1)* %a1, float addrspace(1)* %a2, float addrspace(1)* %a3, i32 addrspace(1)* %b0) nounwind {
entry:
  %a0.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a1.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a2.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a3.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %b0.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %gtid = alloca i32, align 4                     ; <i32*> [#uses=6]
  %tmp0 = alloca float, align 4                   ; <float*> [#uses=2]
  %tmp1 = alloca float, align 4                   ; <float*> [#uses=2]
  %tmp2 = alloca float, align 4                   ; <float*> [#uses=2]
  %tmp3 = alloca float, align 4                   ; <float*> [#uses=2]
  store float addrspace(1)* %a0, float addrspace(1)** %a0.addr
  store float addrspace(1)* %a1, float addrspace(1)** %a1.addr
  store float addrspace(1)* %a2, float addrspace(1)** %a2.addr
  store float addrspace(1)* %a3, float addrspace(1)** %a3.addr
  store i32 addrspace(1)* %b0, i32 addrspace(1)** %b0.addr
  %call = call i32 @get_global_id(i32 0) nounwind ; <i32> [#uses=1]
  store i32 %call, i32* %gtid
  %tmp = load float addrspace(1)** %a0.addr       ; <float addrspace(1)*> [#uses=1]
  %tmp4 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx = getelementptr float addrspace(1)* %tmp, i32 %tmp4 ; <float addrspace(1)*> [#uses=1]
  %tmp5 = load float addrspace(1)* %arrayidx      ; <float> [#uses=1]
  %tmp6 = fadd float %tmp5, 0x3FB99999A0000000    ; <float> [#uses=1]
  store float %tmp6, float* %tmp0
  %tmp7 = load float addrspace(1)** %a1.addr      ; <float addrspace(1)*> [#uses=1]
  %tmp8 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx9 = getelementptr float addrspace(1)* %tmp7, i32 %tmp8 ; <float addrspace(1)*> [#uses=1]
  %tmp10 = load float addrspace(1)* %arrayidx9    ; <float> [#uses=1]
  %tmp11 = fadd float %tmp10, 0x3FF19999A0000000  ; <float> [#uses=1]
  store float %tmp11, float* %tmp1
  %tmp12 = load float addrspace(1)** %a2.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp13 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx14 = getelementptr float addrspace(1)* %tmp12, i32 %tmp13 ; <float addrspace(1)*> [#uses=1]
  %tmp15 = load float addrspace(1)* %arrayidx14   ; <float> [#uses=1]
  %tmp16 = fadd float %tmp15, 0x4000CCCCC0000000  ; <float> [#uses=1]
  store float %tmp16, float* %tmp2
  %tmp17 = load float addrspace(1)** %a3.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp18 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx19 = getelementptr float addrspace(1)* %tmp17, i32 %tmp18 ; <float addrspace(1)*> [#uses=1]
  %tmp20 = load float addrspace(1)* %arrayidx19   ; <float> [#uses=1]
  %tmp21 = fadd float %tmp20, 0x4008CCCCC0000000  ; <float> [#uses=1]
  store float %tmp21, float* %tmp3
  %tmp22 = load i32 addrspace(1)** %b0.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp23 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx24 = getelementptr i32 addrspace(1)* %tmp22, i32 %tmp23 ; <i32 addrspace(1)*> [#uses=1]
  %tmp25 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp26 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp27 = fadd float %tmp25, %tmp26              ; <float> [#uses=1]
  %tmp28 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp29 = fadd float %tmp27, %tmp28              ; <float> [#uses=1]
  %tmp30 = load float* %tmp3                      ; <float> [#uses=1]
  %tmp31 = fadd float %tmp29, %tmp30              ; <float> [#uses=1]
  %tmp32 = fmul float 0x3FF19999A0000000, %tmp31  ; <float> [#uses=1]
  %conv = fptosi float %tmp32 to i32              ; <i32> [#uses=1]
  store i32 %conv, i32 addrspace(1)* %arrayidx24
  br label %return

return:                                           ; preds = %entry
  ret void
}

define void @__OpenCL_test_fa1_1_5_kern_kernel(float addrspace(1)* %a0, i32 addrspace(1)* %b0, i32 addrspace(1)* %b1, i32 addrspace(1)* %b2, i32 addrspace(1)* %b3, i32 addrspace(1)* %b4) nounwind {
entry:
  %a0.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %b0.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b1.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b2.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b3.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b4.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %gtid = alloca i32, align 4                     ; <i32*> [#uses=7]
  %tmp0 = alloca float, align 4                   ; <float*> [#uses=6]
  store float addrspace(1)* %a0, float addrspace(1)** %a0.addr
  store i32 addrspace(1)* %b0, i32 addrspace(1)** %b0.addr
  store i32 addrspace(1)* %b1, i32 addrspace(1)** %b1.addr
  store i32 addrspace(1)* %b2, i32 addrspace(1)** %b2.addr
  store i32 addrspace(1)* %b3, i32 addrspace(1)** %b3.addr
  store i32 addrspace(1)* %b4, i32 addrspace(1)** %b4.addr
  %call = call i32 @get_global_id(i32 0) nounwind ; <i32> [#uses=1]
  store i32 %call, i32* %gtid
  %tmp = load float addrspace(1)** %a0.addr       ; <float addrspace(1)*> [#uses=1]
  %tmp1 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx = getelementptr float addrspace(1)* %tmp, i32 %tmp1 ; <float addrspace(1)*> [#uses=1]
  %tmp2 = load float addrspace(1)* %arrayidx      ; <float> [#uses=1]
  %tmp3 = fadd float %tmp2, 0x3FB99999A0000000    ; <float> [#uses=1]
  store float %tmp3, float* %tmp0
  %tmp4 = load i32 addrspace(1)** %b0.addr        ; <i32 addrspace(1)*> [#uses=1]
  %tmp5 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx6 = getelementptr i32 addrspace(1)* %tmp4, i32 %tmp5 ; <i32 addrspace(1)*> [#uses=1]
  %tmp7 = load float* %tmp0                       ; <float> [#uses=1]
  %tmp8 = fmul float 0x3FF19999A0000000, %tmp7    ; <float> [#uses=1]
  %conv = fptosi float %tmp8 to i32               ; <i32> [#uses=1]
  store i32 %conv, i32 addrspace(1)* %arrayidx6
  %tmp9 = load i32 addrspace(1)** %b1.addr        ; <i32 addrspace(1)*> [#uses=1]
  %tmp10 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx11 = getelementptr i32 addrspace(1)* %tmp9, i32 %tmp10 ; <i32 addrspace(1)*> [#uses=1]
  %tmp12 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp13 = fmul float 0x4000CCCCC0000000, %tmp12  ; <float> [#uses=1]
  %conv14 = fptosi float %tmp13 to i32            ; <i32> [#uses=1]
  store i32 %conv14, i32 addrspace(1)* %arrayidx11
  %tmp15 = load i32 addrspace(1)** %b2.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp16 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx17 = getelementptr i32 addrspace(1)* %tmp15, i32 %tmp16 ; <i32 addrspace(1)*> [#uses=1]
  %tmp18 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp19 = fmul float 0x4008CCCCC0000000, %tmp18  ; <float> [#uses=1]
  %conv20 = fptosi float %tmp19 to i32            ; <i32> [#uses=1]
  store i32 %conv20, i32 addrspace(1)* %arrayidx17
  %tmp21 = load i32 addrspace(1)** %b3.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp22 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx23 = getelementptr i32 addrspace(1)* %tmp21, i32 %tmp22 ; <i32 addrspace(1)*> [#uses=1]
  %tmp24 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp25 = fmul float 0x4010666660000000, %tmp24  ; <float> [#uses=1]
  %conv26 = fptosi float %tmp25 to i32            ; <i32> [#uses=1]
  store i32 %conv26, i32 addrspace(1)* %arrayidx23
  %tmp27 = load i32 addrspace(1)** %b4.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp28 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx29 = getelementptr i32 addrspace(1)* %tmp27, i32 %tmp28 ; <i32 addrspace(1)*> [#uses=1]
  %tmp30 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp31 = fmul float 0x4014666660000000, %tmp30  ; <float> [#uses=1]
  %conv32 = fptosi float %tmp31 to i32            ; <i32> [#uses=1]
  store i32 %conv32, i32 addrspace(1)* %arrayidx29
  br label %return

return:                                           ; preds = %entry
  ret void
}

define void @__OpenCL_test_fa1_2_4_kern_kernel(float addrspace(1)* %a0, float addrspace(1)* %a1, i32 addrspace(1)* %b0, i32 addrspace(1)* %b1, i32 addrspace(1)* %b2, i32 addrspace(1)* %b3) nounwind {
entry:
  %a0.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a1.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %b0.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b1.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b2.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b3.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %gtid = alloca i32, align 4                     ; <i32*> [#uses=7]
  %tmp0 = alloca float, align 4                   ; <float*> [#uses=5]
  %tmp1 = alloca float, align 4                   ; <float*> [#uses=5]
  store float addrspace(1)* %a0, float addrspace(1)** %a0.addr
  store float addrspace(1)* %a1, float addrspace(1)** %a1.addr
  store i32 addrspace(1)* %b0, i32 addrspace(1)** %b0.addr
  store i32 addrspace(1)* %b1, i32 addrspace(1)** %b1.addr
  store i32 addrspace(1)* %b2, i32 addrspace(1)** %b2.addr
  store i32 addrspace(1)* %b3, i32 addrspace(1)** %b3.addr
  %call = call i32 @get_global_id(i32 0) nounwind ; <i32> [#uses=1]
  store i32 %call, i32* %gtid
  %tmp = load float addrspace(1)** %a0.addr       ; <float addrspace(1)*> [#uses=1]
  %tmp2 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx = getelementptr float addrspace(1)* %tmp, i32 %tmp2 ; <float addrspace(1)*> [#uses=1]
  %tmp3 = load float addrspace(1)* %arrayidx      ; <float> [#uses=1]
  %tmp4 = fadd float %tmp3, 0x3FB99999A0000000    ; <float> [#uses=1]
  store float %tmp4, float* %tmp0
  %tmp5 = load float addrspace(1)** %a1.addr      ; <float addrspace(1)*> [#uses=1]
  %tmp6 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx7 = getelementptr float addrspace(1)* %tmp5, i32 %tmp6 ; <float addrspace(1)*> [#uses=1]
  %tmp8 = load float addrspace(1)* %arrayidx7     ; <float> [#uses=1]
  %tmp9 = fadd float %tmp8, 0x3FF19999A0000000    ; <float> [#uses=1]
  store float %tmp9, float* %tmp1
  %tmp10 = load i32 addrspace(1)** %b0.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp11 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx12 = getelementptr i32 addrspace(1)* %tmp10, i32 %tmp11 ; <i32 addrspace(1)*> [#uses=1]
  %tmp13 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp14 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp15 = fadd float %tmp13, %tmp14              ; <float> [#uses=1]
  %tmp16 = fmul float 0x3FF19999A0000000, %tmp15  ; <float> [#uses=1]
  %conv = fptosi float %tmp16 to i32              ; <i32> [#uses=1]
  store i32 %conv, i32 addrspace(1)* %arrayidx12
  %tmp17 = load i32 addrspace(1)** %b1.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp18 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx19 = getelementptr i32 addrspace(1)* %tmp17, i32 %tmp18 ; <i32 addrspace(1)*> [#uses=1]
  %tmp20 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp21 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp22 = fadd float %tmp20, %tmp21              ; <float> [#uses=1]
  %tmp23 = fmul float 0x4000CCCCC0000000, %tmp22  ; <float> [#uses=1]
  %conv24 = fptosi float %tmp23 to i32            ; <i32> [#uses=1]
  store i32 %conv24, i32 addrspace(1)* %arrayidx19
  %tmp25 = load i32 addrspace(1)** %b2.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp26 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx27 = getelementptr i32 addrspace(1)* %tmp25, i32 %tmp26 ; <i32 addrspace(1)*> [#uses=1]
  %tmp28 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp29 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp30 = fadd float %tmp28, %tmp29              ; <float> [#uses=1]
  %tmp31 = fmul float 0x4008CCCCC0000000, %tmp30  ; <float> [#uses=1]
  %conv32 = fptosi float %tmp31 to i32            ; <i32> [#uses=1]
  store i32 %conv32, i32 addrspace(1)* %arrayidx27
  %tmp33 = load i32 addrspace(1)** %b3.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp34 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx35 = getelementptr i32 addrspace(1)* %tmp33, i32 %tmp34 ; <i32 addrspace(1)*> [#uses=1]
  %tmp36 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp37 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp38 = fadd float %tmp36, %tmp37              ; <float> [#uses=1]
  %tmp39 = fmul float 0x4010666660000000, %tmp38  ; <float> [#uses=1]
  %conv40 = fptosi float %tmp39 to i32            ; <i32> [#uses=1]
  store i32 %conv40, i32 addrspace(1)* %arrayidx35
  br label %return

return:                                           ; preds = %entry
  ret void
}

define void @__OpenCL_test_fa1_3_3_kern_kernel(float addrspace(1)* %a0, float addrspace(1)* %a1, float addrspace(1)* %a2, i32 addrspace(1)* %b0, i32 addrspace(1)* %b1, i32 addrspace(1)* %b2) nounwind {
entry:
  %a0.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a1.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a2.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %b0.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b1.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b2.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %gtid = alloca i32, align 4                     ; <i32*> [#uses=7]
  %tmp0 = alloca float, align 4                   ; <float*> [#uses=4]
  %tmp1 = alloca float, align 4                   ; <float*> [#uses=4]
  %tmp2 = alloca float, align 4                   ; <float*> [#uses=4]
  store float addrspace(1)* %a0, float addrspace(1)** %a0.addr
  store float addrspace(1)* %a1, float addrspace(1)** %a1.addr
  store float addrspace(1)* %a2, float addrspace(1)** %a2.addr
  store i32 addrspace(1)* %b0, i32 addrspace(1)** %b0.addr
  store i32 addrspace(1)* %b1, i32 addrspace(1)** %b1.addr
  store i32 addrspace(1)* %b2, i32 addrspace(1)** %b2.addr
  %call = call i32 @get_global_id(i32 0) nounwind ; <i32> [#uses=1]
  store i32 %call, i32* %gtid
  %tmp = load float addrspace(1)** %a0.addr       ; <float addrspace(1)*> [#uses=1]
  %tmp3 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx = getelementptr float addrspace(1)* %tmp, i32 %tmp3 ; <float addrspace(1)*> [#uses=1]
  %tmp4 = load float addrspace(1)* %arrayidx      ; <float> [#uses=1]
  %tmp5 = fadd float %tmp4, 0x3FB99999A0000000    ; <float> [#uses=1]
  store float %tmp5, float* %tmp0
  %tmp6 = load float addrspace(1)** %a1.addr      ; <float addrspace(1)*> [#uses=1]
  %tmp7 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx8 = getelementptr float addrspace(1)* %tmp6, i32 %tmp7 ; <float addrspace(1)*> [#uses=1]
  %tmp9 = load float addrspace(1)* %arrayidx8     ; <float> [#uses=1]
  %tmp10 = fadd float %tmp9, 0x3FF19999A0000000   ; <float> [#uses=1]
  store float %tmp10, float* %tmp1
  %tmp11 = load float addrspace(1)** %a2.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp12 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx13 = getelementptr float addrspace(1)* %tmp11, i32 %tmp12 ; <float addrspace(1)*> [#uses=1]
  %tmp14 = load float addrspace(1)* %arrayidx13   ; <float> [#uses=1]
  %tmp15 = fadd float %tmp14, 0x4000CCCCC0000000  ; <float> [#uses=1]
  store float %tmp15, float* %tmp2
  %tmp16 = load i32 addrspace(1)** %b0.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp17 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx18 = getelementptr i32 addrspace(1)* %tmp16, i32 %tmp17 ; <i32 addrspace(1)*> [#uses=1]
  %tmp19 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp20 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp21 = fadd float %tmp19, %tmp20              ; <float> [#uses=1]
  %tmp22 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp23 = fadd float %tmp21, %tmp22              ; <float> [#uses=1]
  %tmp24 = fmul float 0x3FF19999A0000000, %tmp23  ; <float> [#uses=1]
  %conv = fptosi float %tmp24 to i32              ; <i32> [#uses=1]
  store i32 %conv, i32 addrspace(1)* %arrayidx18
  %tmp25 = load i32 addrspace(1)** %b1.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp26 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx27 = getelementptr i32 addrspace(1)* %tmp25, i32 %tmp26 ; <i32 addrspace(1)*> [#uses=1]
  %tmp28 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp29 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp30 = fadd float %tmp28, %tmp29              ; <float> [#uses=1]
  %tmp31 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp32 = fadd float %tmp30, %tmp31              ; <float> [#uses=1]
  %tmp33 = fmul float 0x4000CCCCC0000000, %tmp32  ; <float> [#uses=1]
  %conv34 = fptosi float %tmp33 to i32            ; <i32> [#uses=1]
  store i32 %conv34, i32 addrspace(1)* %arrayidx27
  %tmp35 = load i32 addrspace(1)** %b2.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp36 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx37 = getelementptr i32 addrspace(1)* %tmp35, i32 %tmp36 ; <i32 addrspace(1)*> [#uses=1]
  %tmp38 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp39 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp40 = fadd float %tmp38, %tmp39              ; <float> [#uses=1]
  %tmp41 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp42 = fadd float %tmp40, %tmp41              ; <float> [#uses=1]
  %tmp43 = fmul float 0x4008CCCCC0000000, %tmp42  ; <float> [#uses=1]
  %conv44 = fptosi float %tmp43 to i32            ; <i32> [#uses=1]
  store i32 %conv44, i32 addrspace(1)* %arrayidx37
  br label %return

return:                                           ; preds = %entry
  ret void
}

define void @__OpenCL_test_fa1_4_2_kern_kernel(float addrspace(1)* %a0, float addrspace(1)* %a1, float addrspace(1)* %a2, float addrspace(1)* %a3, i32 addrspace(1)* %b0, i32 addrspace(1)* %b1) nounwind {
entry:
  %a0.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a1.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a2.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a3.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %b0.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b1.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %gtid = alloca i32, align 4                     ; <i32*> [#uses=7]
  %tmp0 = alloca float, align 4                   ; <float*> [#uses=3]
  %tmp1 = alloca float, align 4                   ; <float*> [#uses=3]
  %tmp2 = alloca float, align 4                   ; <float*> [#uses=3]
  %tmp3 = alloca float, align 4                   ; <float*> [#uses=3]
  store float addrspace(1)* %a0, float addrspace(1)** %a0.addr
  store float addrspace(1)* %a1, float addrspace(1)** %a1.addr
  store float addrspace(1)* %a2, float addrspace(1)** %a2.addr
  store float addrspace(1)* %a3, float addrspace(1)** %a3.addr
  store i32 addrspace(1)* %b0, i32 addrspace(1)** %b0.addr
  store i32 addrspace(1)* %b1, i32 addrspace(1)** %b1.addr
  %call = call i32 @get_global_id(i32 0) nounwind ; <i32> [#uses=1]
  store i32 %call, i32* %gtid
  %tmp = load float addrspace(1)** %a0.addr       ; <float addrspace(1)*> [#uses=1]
  %tmp4 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx = getelementptr float addrspace(1)* %tmp, i32 %tmp4 ; <float addrspace(1)*> [#uses=1]
  %tmp5 = load float addrspace(1)* %arrayidx      ; <float> [#uses=1]
  %tmp6 = fadd float %tmp5, 0x3FB99999A0000000    ; <float> [#uses=1]
  store float %tmp6, float* %tmp0
  %tmp7 = load float addrspace(1)** %a1.addr      ; <float addrspace(1)*> [#uses=1]
  %tmp8 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx9 = getelementptr float addrspace(1)* %tmp7, i32 %tmp8 ; <float addrspace(1)*> [#uses=1]
  %tmp10 = load float addrspace(1)* %arrayidx9    ; <float> [#uses=1]
  %tmp11 = fadd float %tmp10, 0x3FF19999A0000000  ; <float> [#uses=1]
  store float %tmp11, float* %tmp1
  %tmp12 = load float addrspace(1)** %a2.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp13 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx14 = getelementptr float addrspace(1)* %tmp12, i32 %tmp13 ; <float addrspace(1)*> [#uses=1]
  %tmp15 = load float addrspace(1)* %arrayidx14   ; <float> [#uses=1]
  %tmp16 = fadd float %tmp15, 0x4000CCCCC0000000  ; <float> [#uses=1]
  store float %tmp16, float* %tmp2
  %tmp17 = load float addrspace(1)** %a3.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp18 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx19 = getelementptr float addrspace(1)* %tmp17, i32 %tmp18 ; <float addrspace(1)*> [#uses=1]
  %tmp20 = load float addrspace(1)* %arrayidx19   ; <float> [#uses=1]
  %tmp21 = fadd float %tmp20, 0x4008CCCCC0000000  ; <float> [#uses=1]
  store float %tmp21, float* %tmp3
  %tmp22 = load i32 addrspace(1)** %b0.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp23 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx24 = getelementptr i32 addrspace(1)* %tmp22, i32 %tmp23 ; <i32 addrspace(1)*> [#uses=1]
  %tmp25 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp26 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp27 = fadd float %tmp25, %tmp26              ; <float> [#uses=1]
  %tmp28 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp29 = fadd float %tmp27, %tmp28              ; <float> [#uses=1]
  %tmp30 = load float* %tmp3                      ; <float> [#uses=1]
  %tmp31 = fadd float %tmp29, %tmp30              ; <float> [#uses=1]
  %tmp32 = fmul float 0x3FF19999A0000000, %tmp31  ; <float> [#uses=1]
  %conv = fptosi float %tmp32 to i32              ; <i32> [#uses=1]
  store i32 %conv, i32 addrspace(1)* %arrayidx24
  %tmp33 = load i32 addrspace(1)** %b1.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp34 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx35 = getelementptr i32 addrspace(1)* %tmp33, i32 %tmp34 ; <i32 addrspace(1)*> [#uses=1]
  %tmp36 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp37 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp38 = fadd float %tmp36, %tmp37              ; <float> [#uses=1]
  %tmp39 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp40 = fadd float %tmp38, %tmp39              ; <float> [#uses=1]
  %tmp41 = load float* %tmp3                      ; <float> [#uses=1]
  %tmp42 = fadd float %tmp40, %tmp41              ; <float> [#uses=1]
  %tmp43 = fmul float 0x4000CCCCC0000000, %tmp42  ; <float> [#uses=1]
  %conv44 = fptosi float %tmp43 to i32            ; <i32> [#uses=1]
  store i32 %conv44, i32 addrspace(1)* %arrayidx35
  br label %return

return:                                           ; preds = %entry
  ret void
}

define void @__OpenCL_test_fa1_5_1_kern_kernel(float addrspace(1)* %a0, float addrspace(1)* %a1, float addrspace(1)* %a2, float addrspace(1)* %a3, float addrspace(1)* %a4, i32 addrspace(1)* %b0) nounwind {
entry:
  %a0.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a1.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a2.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a3.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a4.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %b0.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %gtid = alloca i32, align 4                     ; <i32*> [#uses=7]
  %tmp0 = alloca float, align 4                   ; <float*> [#uses=2]
  %tmp1 = alloca float, align 4                   ; <float*> [#uses=2]
  %tmp2 = alloca float, align 4                   ; <float*> [#uses=2]
  %tmp3 = alloca float, align 4                   ; <float*> [#uses=2]
  %tmp4 = alloca float, align 4                   ; <float*> [#uses=2]
  store float addrspace(1)* %a0, float addrspace(1)** %a0.addr
  store float addrspace(1)* %a1, float addrspace(1)** %a1.addr
  store float addrspace(1)* %a2, float addrspace(1)** %a2.addr
  store float addrspace(1)* %a3, float addrspace(1)** %a3.addr
  store float addrspace(1)* %a4, float addrspace(1)** %a4.addr
  store i32 addrspace(1)* %b0, i32 addrspace(1)** %b0.addr
  %call = call i32 @get_global_id(i32 0) nounwind ; <i32> [#uses=1]
  store i32 %call, i32* %gtid
  %tmp = load float addrspace(1)** %a0.addr       ; <float addrspace(1)*> [#uses=1]
  %tmp5 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx = getelementptr float addrspace(1)* %tmp, i32 %tmp5 ; <float addrspace(1)*> [#uses=1]
  %tmp6 = load float addrspace(1)* %arrayidx      ; <float> [#uses=1]
  %tmp7 = fadd float %tmp6, 0x3FB99999A0000000    ; <float> [#uses=1]
  store float %tmp7, float* %tmp0
  %tmp8 = load float addrspace(1)** %a1.addr      ; <float addrspace(1)*> [#uses=1]
  %tmp9 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx10 = getelementptr float addrspace(1)* %tmp8, i32 %tmp9 ; <float addrspace(1)*> [#uses=1]
  %tmp11 = load float addrspace(1)* %arrayidx10   ; <float> [#uses=1]
  %tmp12 = fadd float %tmp11, 0x3FF19999A0000000  ; <float> [#uses=1]
  store float %tmp12, float* %tmp1
  %tmp13 = load float addrspace(1)** %a2.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp14 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx15 = getelementptr float addrspace(1)* %tmp13, i32 %tmp14 ; <float addrspace(1)*> [#uses=1]
  %tmp16 = load float addrspace(1)* %arrayidx15   ; <float> [#uses=1]
  %tmp17 = fadd float %tmp16, 0x4000CCCCC0000000  ; <float> [#uses=1]
  store float %tmp17, float* %tmp2
  %tmp18 = load float addrspace(1)** %a3.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp19 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx20 = getelementptr float addrspace(1)* %tmp18, i32 %tmp19 ; <float addrspace(1)*> [#uses=1]
  %tmp21 = load float addrspace(1)* %arrayidx20   ; <float> [#uses=1]
  %tmp22 = fadd float %tmp21, 0x4008CCCCC0000000  ; <float> [#uses=1]
  store float %tmp22, float* %tmp3
  %tmp23 = load float addrspace(1)** %a4.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp24 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx25 = getelementptr float addrspace(1)* %tmp23, i32 %tmp24 ; <float addrspace(1)*> [#uses=1]
  %tmp26 = load float addrspace(1)* %arrayidx25   ; <float> [#uses=1]
  %tmp27 = fadd float %tmp26, 0x4010666660000000  ; <float> [#uses=1]
  store float %tmp27, float* %tmp4
  %tmp28 = load i32 addrspace(1)** %b0.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp29 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx30 = getelementptr i32 addrspace(1)* %tmp28, i32 %tmp29 ; <i32 addrspace(1)*> [#uses=1]
  %tmp31 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp32 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp33 = fadd float %tmp31, %tmp32              ; <float> [#uses=1]
  %tmp34 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp35 = fadd float %tmp33, %tmp34              ; <float> [#uses=1]
  %tmp36 = load float* %tmp3                      ; <float> [#uses=1]
  %tmp37 = fadd float %tmp35, %tmp36              ; <float> [#uses=1]
  %tmp38 = load float* %tmp4                      ; <float> [#uses=1]
  %tmp39 = fadd float %tmp37, %tmp38              ; <float> [#uses=1]
  %tmp40 = fmul float 0x3FF19999A0000000, %tmp39  ; <float> [#uses=1]
  %conv = fptosi float %tmp40 to i32              ; <i32> [#uses=1]
  store i32 %conv, i32 addrspace(1)* %arrayidx30
  br label %return

return:                                           ; preds = %entry
  ret void
}

define void @__OpenCL_test_fa1_1_6_kern_kernel(float addrspace(1)* %a0, i32 addrspace(1)* %b0, i32 addrspace(1)* %b1, i32 addrspace(1)* %b2, i32 addrspace(1)* %b3, i32 addrspace(1)* %b4, i32 addrspace(1)* %b5) nounwind {
entry:
  %a0.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %b0.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b1.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b2.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b3.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b4.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b5.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %gtid = alloca i32, align 4                     ; <i32*> [#uses=8]
  %tmp0 = alloca float, align 4                   ; <float*> [#uses=7]
  store float addrspace(1)* %a0, float addrspace(1)** %a0.addr
  store i32 addrspace(1)* %b0, i32 addrspace(1)** %b0.addr
  store i32 addrspace(1)* %b1, i32 addrspace(1)** %b1.addr
  store i32 addrspace(1)* %b2, i32 addrspace(1)** %b2.addr
  store i32 addrspace(1)* %b3, i32 addrspace(1)** %b3.addr
  store i32 addrspace(1)* %b4, i32 addrspace(1)** %b4.addr
  store i32 addrspace(1)* %b5, i32 addrspace(1)** %b5.addr
  %call = call i32 @get_global_id(i32 0) nounwind ; <i32> [#uses=1]
  store i32 %call, i32* %gtid
  %tmp = load float addrspace(1)** %a0.addr       ; <float addrspace(1)*> [#uses=1]
  %tmp1 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx = getelementptr float addrspace(1)* %tmp, i32 %tmp1 ; <float addrspace(1)*> [#uses=1]
  %tmp2 = load float addrspace(1)* %arrayidx      ; <float> [#uses=1]
  %tmp3 = fadd float %tmp2, 0x3FB99999A0000000    ; <float> [#uses=1]
  store float %tmp3, float* %tmp0
  %tmp4 = load i32 addrspace(1)** %b0.addr        ; <i32 addrspace(1)*> [#uses=1]
  %tmp5 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx6 = getelementptr i32 addrspace(1)* %tmp4, i32 %tmp5 ; <i32 addrspace(1)*> [#uses=1]
  %tmp7 = load float* %tmp0                       ; <float> [#uses=1]
  %tmp8 = fmul float 0x3FF19999A0000000, %tmp7    ; <float> [#uses=1]
  %conv = fptosi float %tmp8 to i32               ; <i32> [#uses=1]
  store i32 %conv, i32 addrspace(1)* %arrayidx6
  %tmp9 = load i32 addrspace(1)** %b1.addr        ; <i32 addrspace(1)*> [#uses=1]
  %tmp10 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx11 = getelementptr i32 addrspace(1)* %tmp9, i32 %tmp10 ; <i32 addrspace(1)*> [#uses=1]
  %tmp12 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp13 = fmul float 0x4000CCCCC0000000, %tmp12  ; <float> [#uses=1]
  %conv14 = fptosi float %tmp13 to i32            ; <i32> [#uses=1]
  store i32 %conv14, i32 addrspace(1)* %arrayidx11
  %tmp15 = load i32 addrspace(1)** %b2.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp16 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx17 = getelementptr i32 addrspace(1)* %tmp15, i32 %tmp16 ; <i32 addrspace(1)*> [#uses=1]
  %tmp18 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp19 = fmul float 0x4008CCCCC0000000, %tmp18  ; <float> [#uses=1]
  %conv20 = fptosi float %tmp19 to i32            ; <i32> [#uses=1]
  store i32 %conv20, i32 addrspace(1)* %arrayidx17
  %tmp21 = load i32 addrspace(1)** %b3.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp22 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx23 = getelementptr i32 addrspace(1)* %tmp21, i32 %tmp22 ; <i32 addrspace(1)*> [#uses=1]
  %tmp24 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp25 = fmul float 0x4010666660000000, %tmp24  ; <float> [#uses=1]
  %conv26 = fptosi float %tmp25 to i32            ; <i32> [#uses=1]
  store i32 %conv26, i32 addrspace(1)* %arrayidx23
  %tmp27 = load i32 addrspace(1)** %b4.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp28 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx29 = getelementptr i32 addrspace(1)* %tmp27, i32 %tmp28 ; <i32 addrspace(1)*> [#uses=1]
  %tmp30 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp31 = fmul float 0x4014666660000000, %tmp30  ; <float> [#uses=1]
  %conv32 = fptosi float %tmp31 to i32            ; <i32> [#uses=1]
  store i32 %conv32, i32 addrspace(1)* %arrayidx29
  %tmp33 = load i32 addrspace(1)** %b5.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp34 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx35 = getelementptr i32 addrspace(1)* %tmp33, i32 %tmp34 ; <i32 addrspace(1)*> [#uses=1]
  %tmp36 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp37 = fmul float 0x4018666660000000, %tmp36  ; <float> [#uses=1]
  %conv38 = fptosi float %tmp37 to i32            ; <i32> [#uses=1]
  store i32 %conv38, i32 addrspace(1)* %arrayidx35
  br label %return

return:                                           ; preds = %entry
  ret void
}

define void @__OpenCL_test_fa1_2_5_kern_kernel(float addrspace(1)* %a0, float addrspace(1)* %a1, i32 addrspace(1)* %b0, i32 addrspace(1)* %b1, i32 addrspace(1)* %b2, i32 addrspace(1)* %b3, i32 addrspace(1)* %b4) nounwind {
entry:
  %a0.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a1.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %b0.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b1.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b2.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b3.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b4.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %gtid = alloca i32, align 4                     ; <i32*> [#uses=8]
  %tmp0 = alloca float, align 4                   ; <float*> [#uses=6]
  %tmp1 = alloca float, align 4                   ; <float*> [#uses=6]
  store float addrspace(1)* %a0, float addrspace(1)** %a0.addr
  store float addrspace(1)* %a1, float addrspace(1)** %a1.addr
  store i32 addrspace(1)* %b0, i32 addrspace(1)** %b0.addr
  store i32 addrspace(1)* %b1, i32 addrspace(1)** %b1.addr
  store i32 addrspace(1)* %b2, i32 addrspace(1)** %b2.addr
  store i32 addrspace(1)* %b3, i32 addrspace(1)** %b3.addr
  store i32 addrspace(1)* %b4, i32 addrspace(1)** %b4.addr
  %call = call i32 @get_global_id(i32 0) nounwind ; <i32> [#uses=1]
  store i32 %call, i32* %gtid
  %tmp = load float addrspace(1)** %a0.addr       ; <float addrspace(1)*> [#uses=1]
  %tmp2 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx = getelementptr float addrspace(1)* %tmp, i32 %tmp2 ; <float addrspace(1)*> [#uses=1]
  %tmp3 = load float addrspace(1)* %arrayidx      ; <float> [#uses=1]
  %tmp4 = fadd float %tmp3, 0x3FB99999A0000000    ; <float> [#uses=1]
  store float %tmp4, float* %tmp0
  %tmp5 = load float addrspace(1)** %a1.addr      ; <float addrspace(1)*> [#uses=1]
  %tmp6 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx7 = getelementptr float addrspace(1)* %tmp5, i32 %tmp6 ; <float addrspace(1)*> [#uses=1]
  %tmp8 = load float addrspace(1)* %arrayidx7     ; <float> [#uses=1]
  %tmp9 = fadd float %tmp8, 0x3FF19999A0000000    ; <float> [#uses=1]
  store float %tmp9, float* %tmp1
  %tmp10 = load i32 addrspace(1)** %b0.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp11 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx12 = getelementptr i32 addrspace(1)* %tmp10, i32 %tmp11 ; <i32 addrspace(1)*> [#uses=1]
  %tmp13 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp14 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp15 = fadd float %tmp13, %tmp14              ; <float> [#uses=1]
  %tmp16 = fmul float 0x3FF19999A0000000, %tmp15  ; <float> [#uses=1]
  %conv = fptosi float %tmp16 to i32              ; <i32> [#uses=1]
  store i32 %conv, i32 addrspace(1)* %arrayidx12
  %tmp17 = load i32 addrspace(1)** %b1.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp18 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx19 = getelementptr i32 addrspace(1)* %tmp17, i32 %tmp18 ; <i32 addrspace(1)*> [#uses=1]
  %tmp20 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp21 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp22 = fadd float %tmp20, %tmp21              ; <float> [#uses=1]
  %tmp23 = fmul float 0x4000CCCCC0000000, %tmp22  ; <float> [#uses=1]
  %conv24 = fptosi float %tmp23 to i32            ; <i32> [#uses=1]
  store i32 %conv24, i32 addrspace(1)* %arrayidx19
  %tmp25 = load i32 addrspace(1)** %b2.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp26 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx27 = getelementptr i32 addrspace(1)* %tmp25, i32 %tmp26 ; <i32 addrspace(1)*> [#uses=1]
  %tmp28 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp29 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp30 = fadd float %tmp28, %tmp29              ; <float> [#uses=1]
  %tmp31 = fmul float 0x4008CCCCC0000000, %tmp30  ; <float> [#uses=1]
  %conv32 = fptosi float %tmp31 to i32            ; <i32> [#uses=1]
  store i32 %conv32, i32 addrspace(1)* %arrayidx27
  %tmp33 = load i32 addrspace(1)** %b3.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp34 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx35 = getelementptr i32 addrspace(1)* %tmp33, i32 %tmp34 ; <i32 addrspace(1)*> [#uses=1]
  %tmp36 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp37 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp38 = fadd float %tmp36, %tmp37              ; <float> [#uses=1]
  %tmp39 = fmul float 0x4010666660000000, %tmp38  ; <float> [#uses=1]
  %conv40 = fptosi float %tmp39 to i32            ; <i32> [#uses=1]
  store i32 %conv40, i32 addrspace(1)* %arrayidx35
  %tmp41 = load i32 addrspace(1)** %b4.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp42 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx43 = getelementptr i32 addrspace(1)* %tmp41, i32 %tmp42 ; <i32 addrspace(1)*> [#uses=1]
  %tmp44 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp45 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp46 = fadd float %tmp44, %tmp45              ; <float> [#uses=1]
  %tmp47 = fmul float 0x4014666660000000, %tmp46  ; <float> [#uses=1]
  %conv48 = fptosi float %tmp47 to i32            ; <i32> [#uses=1]
  store i32 %conv48, i32 addrspace(1)* %arrayidx43
  br label %return

return:                                           ; preds = %entry
  ret void
}

define void @__OpenCL_test_fa1_3_4_kern_kernel(float addrspace(1)* %a0, float addrspace(1)* %a1, float addrspace(1)* %a2, i32 addrspace(1)* %b0, i32 addrspace(1)* %b1, i32 addrspace(1)* %b2, i32 addrspace(1)* %b3) nounwind {
entry:
  %a0.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a1.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a2.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %b0.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b1.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b2.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b3.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %gtid = alloca i32, align 4                     ; <i32*> [#uses=8]
  %tmp0 = alloca float, align 4                   ; <float*> [#uses=5]
  %tmp1 = alloca float, align 4                   ; <float*> [#uses=5]
  %tmp2 = alloca float, align 4                   ; <float*> [#uses=5]
  store float addrspace(1)* %a0, float addrspace(1)** %a0.addr
  store float addrspace(1)* %a1, float addrspace(1)** %a1.addr
  store float addrspace(1)* %a2, float addrspace(1)** %a2.addr
  store i32 addrspace(1)* %b0, i32 addrspace(1)** %b0.addr
  store i32 addrspace(1)* %b1, i32 addrspace(1)** %b1.addr
  store i32 addrspace(1)* %b2, i32 addrspace(1)** %b2.addr
  store i32 addrspace(1)* %b3, i32 addrspace(1)** %b3.addr
  %call = call i32 @get_global_id(i32 0) nounwind ; <i32> [#uses=1]
  store i32 %call, i32* %gtid
  %tmp = load float addrspace(1)** %a0.addr       ; <float addrspace(1)*> [#uses=1]
  %tmp3 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx = getelementptr float addrspace(1)* %tmp, i32 %tmp3 ; <float addrspace(1)*> [#uses=1]
  %tmp4 = load float addrspace(1)* %arrayidx      ; <float> [#uses=1]
  %tmp5 = fadd float %tmp4, 0x3FB99999A0000000    ; <float> [#uses=1]
  store float %tmp5, float* %tmp0
  %tmp6 = load float addrspace(1)** %a1.addr      ; <float addrspace(1)*> [#uses=1]
  %tmp7 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx8 = getelementptr float addrspace(1)* %tmp6, i32 %tmp7 ; <float addrspace(1)*> [#uses=1]
  %tmp9 = load float addrspace(1)* %arrayidx8     ; <float> [#uses=1]
  %tmp10 = fadd float %tmp9, 0x3FF19999A0000000   ; <float> [#uses=1]
  store float %tmp10, float* %tmp1
  %tmp11 = load float addrspace(1)** %a2.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp12 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx13 = getelementptr float addrspace(1)* %tmp11, i32 %tmp12 ; <float addrspace(1)*> [#uses=1]
  %tmp14 = load float addrspace(1)* %arrayidx13   ; <float> [#uses=1]
  %tmp15 = fadd float %tmp14, 0x4000CCCCC0000000  ; <float> [#uses=1]
  store float %tmp15, float* %tmp2
  %tmp16 = load i32 addrspace(1)** %b0.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp17 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx18 = getelementptr i32 addrspace(1)* %tmp16, i32 %tmp17 ; <i32 addrspace(1)*> [#uses=1]
  %tmp19 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp20 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp21 = fadd float %tmp19, %tmp20              ; <float> [#uses=1]
  %tmp22 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp23 = fadd float %tmp21, %tmp22              ; <float> [#uses=1]
  %tmp24 = fmul float 0x3FF19999A0000000, %tmp23  ; <float> [#uses=1]
  %conv = fptosi float %tmp24 to i32              ; <i32> [#uses=1]
  store i32 %conv, i32 addrspace(1)* %arrayidx18
  %tmp25 = load i32 addrspace(1)** %b1.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp26 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx27 = getelementptr i32 addrspace(1)* %tmp25, i32 %tmp26 ; <i32 addrspace(1)*> [#uses=1]
  %tmp28 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp29 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp30 = fadd float %tmp28, %tmp29              ; <float> [#uses=1]
  %tmp31 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp32 = fadd float %tmp30, %tmp31              ; <float> [#uses=1]
  %tmp33 = fmul float 0x4000CCCCC0000000, %tmp32  ; <float> [#uses=1]
  %conv34 = fptosi float %tmp33 to i32            ; <i32> [#uses=1]
  store i32 %conv34, i32 addrspace(1)* %arrayidx27
  %tmp35 = load i32 addrspace(1)** %b2.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp36 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx37 = getelementptr i32 addrspace(1)* %tmp35, i32 %tmp36 ; <i32 addrspace(1)*> [#uses=1]
  %tmp38 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp39 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp40 = fadd float %tmp38, %tmp39              ; <float> [#uses=1]
  %tmp41 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp42 = fadd float %tmp40, %tmp41              ; <float> [#uses=1]
  %tmp43 = fmul float 0x4008CCCCC0000000, %tmp42  ; <float> [#uses=1]
  %conv44 = fptosi float %tmp43 to i32            ; <i32> [#uses=1]
  store i32 %conv44, i32 addrspace(1)* %arrayidx37
  %tmp45 = load i32 addrspace(1)** %b3.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp46 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx47 = getelementptr i32 addrspace(1)* %tmp45, i32 %tmp46 ; <i32 addrspace(1)*> [#uses=1]
  %tmp48 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp49 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp50 = fadd float %tmp48, %tmp49              ; <float> [#uses=1]
  %tmp51 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp52 = fadd float %tmp50, %tmp51              ; <float> [#uses=1]
  %tmp53 = fmul float 0x4010666660000000, %tmp52  ; <float> [#uses=1]
  %conv54 = fptosi float %tmp53 to i32            ; <i32> [#uses=1]
  store i32 %conv54, i32 addrspace(1)* %arrayidx47
  br label %return

return:                                           ; preds = %entry
  ret void
}

define void @__OpenCL_test_fa1_4_3_kern_kernel(float addrspace(1)* %a0, float addrspace(1)* %a1, float addrspace(1)* %a2, float addrspace(1)* %a3, i32 addrspace(1)* %b0, i32 addrspace(1)* %b1, i32 addrspace(1)* %b2) nounwind {
entry:
  %a0.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a1.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a2.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a3.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %b0.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b1.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b2.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %gtid = alloca i32, align 4                     ; <i32*> [#uses=8]
  %tmp0 = alloca float, align 4                   ; <float*> [#uses=4]
  %tmp1 = alloca float, align 4                   ; <float*> [#uses=4]
  %tmp2 = alloca float, align 4                   ; <float*> [#uses=4]
  %tmp3 = alloca float, align 4                   ; <float*> [#uses=4]
  store float addrspace(1)* %a0, float addrspace(1)** %a0.addr
  store float addrspace(1)* %a1, float addrspace(1)** %a1.addr
  store float addrspace(1)* %a2, float addrspace(1)** %a2.addr
  store float addrspace(1)* %a3, float addrspace(1)** %a3.addr
  store i32 addrspace(1)* %b0, i32 addrspace(1)** %b0.addr
  store i32 addrspace(1)* %b1, i32 addrspace(1)** %b1.addr
  store i32 addrspace(1)* %b2, i32 addrspace(1)** %b2.addr
  %call = call i32 @get_global_id(i32 0) nounwind ; <i32> [#uses=1]
  store i32 %call, i32* %gtid
  %tmp = load float addrspace(1)** %a0.addr       ; <float addrspace(1)*> [#uses=1]
  %tmp4 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx = getelementptr float addrspace(1)* %tmp, i32 %tmp4 ; <float addrspace(1)*> [#uses=1]
  %tmp5 = load float addrspace(1)* %arrayidx      ; <float> [#uses=1]
  %tmp6 = fadd float %tmp5, 0x3FB99999A0000000    ; <float> [#uses=1]
  store float %tmp6, float* %tmp0
  %tmp7 = load float addrspace(1)** %a1.addr      ; <float addrspace(1)*> [#uses=1]
  %tmp8 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx9 = getelementptr float addrspace(1)* %tmp7, i32 %tmp8 ; <float addrspace(1)*> [#uses=1]
  %tmp10 = load float addrspace(1)* %arrayidx9    ; <float> [#uses=1]
  %tmp11 = fadd float %tmp10, 0x3FF19999A0000000  ; <float> [#uses=1]
  store float %tmp11, float* %tmp1
  %tmp12 = load float addrspace(1)** %a2.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp13 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx14 = getelementptr float addrspace(1)* %tmp12, i32 %tmp13 ; <float addrspace(1)*> [#uses=1]
  %tmp15 = load float addrspace(1)* %arrayidx14   ; <float> [#uses=1]
  %tmp16 = fadd float %tmp15, 0x4000CCCCC0000000  ; <float> [#uses=1]
  store float %tmp16, float* %tmp2
  %tmp17 = load float addrspace(1)** %a3.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp18 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx19 = getelementptr float addrspace(1)* %tmp17, i32 %tmp18 ; <float addrspace(1)*> [#uses=1]
  %tmp20 = load float addrspace(1)* %arrayidx19   ; <float> [#uses=1]
  %tmp21 = fadd float %tmp20, 0x4008CCCCC0000000  ; <float> [#uses=1]
  store float %tmp21, float* %tmp3
  %tmp22 = load i32 addrspace(1)** %b0.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp23 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx24 = getelementptr i32 addrspace(1)* %tmp22, i32 %tmp23 ; <i32 addrspace(1)*> [#uses=1]
  %tmp25 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp26 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp27 = fadd float %tmp25, %tmp26              ; <float> [#uses=1]
  %tmp28 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp29 = fadd float %tmp27, %tmp28              ; <float> [#uses=1]
  %tmp30 = load float* %tmp3                      ; <float> [#uses=1]
  %tmp31 = fadd float %tmp29, %tmp30              ; <float> [#uses=1]
  %tmp32 = fmul float 0x3FF19999A0000000, %tmp31  ; <float> [#uses=1]
  %conv = fptosi float %tmp32 to i32              ; <i32> [#uses=1]
  store i32 %conv, i32 addrspace(1)* %arrayidx24
  %tmp33 = load i32 addrspace(1)** %b1.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp34 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx35 = getelementptr i32 addrspace(1)* %tmp33, i32 %tmp34 ; <i32 addrspace(1)*> [#uses=1]
  %tmp36 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp37 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp38 = fadd float %tmp36, %tmp37              ; <float> [#uses=1]
  %tmp39 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp40 = fadd float %tmp38, %tmp39              ; <float> [#uses=1]
  %tmp41 = load float* %tmp3                      ; <float> [#uses=1]
  %tmp42 = fadd float %tmp40, %tmp41              ; <float> [#uses=1]
  %tmp43 = fmul float 0x4000CCCCC0000000, %tmp42  ; <float> [#uses=1]
  %conv44 = fptosi float %tmp43 to i32            ; <i32> [#uses=1]
  store i32 %conv44, i32 addrspace(1)* %arrayidx35
  %tmp45 = load i32 addrspace(1)** %b2.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp46 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx47 = getelementptr i32 addrspace(1)* %tmp45, i32 %tmp46 ; <i32 addrspace(1)*> [#uses=1]
  %tmp48 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp49 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp50 = fadd float %tmp48, %tmp49              ; <float> [#uses=1]
  %tmp51 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp52 = fadd float %tmp50, %tmp51              ; <float> [#uses=1]
  %tmp53 = load float* %tmp3                      ; <float> [#uses=1]
  %tmp54 = fadd float %tmp52, %tmp53              ; <float> [#uses=1]
  %tmp55 = fmul float 0x4008CCCCC0000000, %tmp54  ; <float> [#uses=1]
  %conv56 = fptosi float %tmp55 to i32            ; <i32> [#uses=1]
  store i32 %conv56, i32 addrspace(1)* %arrayidx47
  br label %return

return:                                           ; preds = %entry
  ret void
}

define void @__OpenCL_test_fa1_5_2_kern_kernel(float addrspace(1)* %a0, float addrspace(1)* %a1, float addrspace(1)* %a2, float addrspace(1)* %a3, float addrspace(1)* %a4, i32 addrspace(1)* %b0, i32 addrspace(1)* %b1) nounwind {
entry:
  %a0.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a1.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a2.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a3.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a4.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %b0.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b1.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %gtid = alloca i32, align 4                     ; <i32*> [#uses=8]
  %tmp0 = alloca float, align 4                   ; <float*> [#uses=3]
  %tmp1 = alloca float, align 4                   ; <float*> [#uses=3]
  %tmp2 = alloca float, align 4                   ; <float*> [#uses=3]
  %tmp3 = alloca float, align 4                   ; <float*> [#uses=3]
  %tmp4 = alloca float, align 4                   ; <float*> [#uses=3]
  store float addrspace(1)* %a0, float addrspace(1)** %a0.addr
  store float addrspace(1)* %a1, float addrspace(1)** %a1.addr
  store float addrspace(1)* %a2, float addrspace(1)** %a2.addr
  store float addrspace(1)* %a3, float addrspace(1)** %a3.addr
  store float addrspace(1)* %a4, float addrspace(1)** %a4.addr
  store i32 addrspace(1)* %b0, i32 addrspace(1)** %b0.addr
  store i32 addrspace(1)* %b1, i32 addrspace(1)** %b1.addr
  %call = call i32 @get_global_id(i32 0) nounwind ; <i32> [#uses=1]
  store i32 %call, i32* %gtid
  %tmp = load float addrspace(1)** %a0.addr       ; <float addrspace(1)*> [#uses=1]
  %tmp5 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx = getelementptr float addrspace(1)* %tmp, i32 %tmp5 ; <float addrspace(1)*> [#uses=1]
  %tmp6 = load float addrspace(1)* %arrayidx      ; <float> [#uses=1]
  %tmp7 = fadd float %tmp6, 0x3FB99999A0000000    ; <float> [#uses=1]
  store float %tmp7, float* %tmp0
  %tmp8 = load float addrspace(1)** %a1.addr      ; <float addrspace(1)*> [#uses=1]
  %tmp9 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx10 = getelementptr float addrspace(1)* %tmp8, i32 %tmp9 ; <float addrspace(1)*> [#uses=1]
  %tmp11 = load float addrspace(1)* %arrayidx10   ; <float> [#uses=1]
  %tmp12 = fadd float %tmp11, 0x3FF19999A0000000  ; <float> [#uses=1]
  store float %tmp12, float* %tmp1
  %tmp13 = load float addrspace(1)** %a2.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp14 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx15 = getelementptr float addrspace(1)* %tmp13, i32 %tmp14 ; <float addrspace(1)*> [#uses=1]
  %tmp16 = load float addrspace(1)* %arrayidx15   ; <float> [#uses=1]
  %tmp17 = fadd float %tmp16, 0x4000CCCCC0000000  ; <float> [#uses=1]
  store float %tmp17, float* %tmp2
  %tmp18 = load float addrspace(1)** %a3.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp19 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx20 = getelementptr float addrspace(1)* %tmp18, i32 %tmp19 ; <float addrspace(1)*> [#uses=1]
  %tmp21 = load float addrspace(1)* %arrayidx20   ; <float> [#uses=1]
  %tmp22 = fadd float %tmp21, 0x4008CCCCC0000000  ; <float> [#uses=1]
  store float %tmp22, float* %tmp3
  %tmp23 = load float addrspace(1)** %a4.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp24 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx25 = getelementptr float addrspace(1)* %tmp23, i32 %tmp24 ; <float addrspace(1)*> [#uses=1]
  %tmp26 = load float addrspace(1)* %arrayidx25   ; <float> [#uses=1]
  %tmp27 = fadd float %tmp26, 0x4010666660000000  ; <float> [#uses=1]
  store float %tmp27, float* %tmp4
  %tmp28 = load i32 addrspace(1)** %b0.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp29 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx30 = getelementptr i32 addrspace(1)* %tmp28, i32 %tmp29 ; <i32 addrspace(1)*> [#uses=1]
  %tmp31 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp32 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp33 = fadd float %tmp31, %tmp32              ; <float> [#uses=1]
  %tmp34 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp35 = fadd float %tmp33, %tmp34              ; <float> [#uses=1]
  %tmp36 = load float* %tmp3                      ; <float> [#uses=1]
  %tmp37 = fadd float %tmp35, %tmp36              ; <float> [#uses=1]
  %tmp38 = load float* %tmp4                      ; <float> [#uses=1]
  %tmp39 = fadd float %tmp37, %tmp38              ; <float> [#uses=1]
  %tmp40 = fmul float 0x3FF19999A0000000, %tmp39  ; <float> [#uses=1]
  %conv = fptosi float %tmp40 to i32              ; <i32> [#uses=1]
  store i32 %conv, i32 addrspace(1)* %arrayidx30
  %tmp41 = load i32 addrspace(1)** %b1.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp42 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx43 = getelementptr i32 addrspace(1)* %tmp41, i32 %tmp42 ; <i32 addrspace(1)*> [#uses=1]
  %tmp44 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp45 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp46 = fadd float %tmp44, %tmp45              ; <float> [#uses=1]
  %tmp47 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp48 = fadd float %tmp46, %tmp47              ; <float> [#uses=1]
  %tmp49 = load float* %tmp3                      ; <float> [#uses=1]
  %tmp50 = fadd float %tmp48, %tmp49              ; <float> [#uses=1]
  %tmp51 = load float* %tmp4                      ; <float> [#uses=1]
  %tmp52 = fadd float %tmp50, %tmp51              ; <float> [#uses=1]
  %tmp53 = fmul float 0x4000CCCCC0000000, %tmp52  ; <float> [#uses=1]
  %conv54 = fptosi float %tmp53 to i32            ; <i32> [#uses=1]
  store i32 %conv54, i32 addrspace(1)* %arrayidx43
  br label %return

return:                                           ; preds = %entry
  ret void
}

define void @__OpenCL_test_fa1_6_1_kern_kernel(float addrspace(1)* %a0, float addrspace(1)* %a1, float addrspace(1)* %a2, float addrspace(1)* %a3, float addrspace(1)* %a4, float addrspace(1)* %a5, i32 addrspace(1)* %b0) nounwind {
entry:
  %a0.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a1.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a2.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a3.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a4.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a5.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %b0.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %gtid = alloca i32, align 4                     ; <i32*> [#uses=8]
  %tmp0 = alloca float, align 4                   ; <float*> [#uses=2]
  %tmp1 = alloca float, align 4                   ; <float*> [#uses=2]
  %tmp2 = alloca float, align 4                   ; <float*> [#uses=2]
  %tmp3 = alloca float, align 4                   ; <float*> [#uses=2]
  %tmp4 = alloca float, align 4                   ; <float*> [#uses=2]
  %tmp5 = alloca float, align 4                   ; <float*> [#uses=2]
  store float addrspace(1)* %a0, float addrspace(1)** %a0.addr
  store float addrspace(1)* %a1, float addrspace(1)** %a1.addr
  store float addrspace(1)* %a2, float addrspace(1)** %a2.addr
  store float addrspace(1)* %a3, float addrspace(1)** %a3.addr
  store float addrspace(1)* %a4, float addrspace(1)** %a4.addr
  store float addrspace(1)* %a5, float addrspace(1)** %a5.addr
  store i32 addrspace(1)* %b0, i32 addrspace(1)** %b0.addr
  %call = call i32 @get_global_id(i32 0) nounwind ; <i32> [#uses=1]
  store i32 %call, i32* %gtid
  %tmp = load float addrspace(1)** %a0.addr       ; <float addrspace(1)*> [#uses=1]
  %tmp6 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx = getelementptr float addrspace(1)* %tmp, i32 %tmp6 ; <float addrspace(1)*> [#uses=1]
  %tmp7 = load float addrspace(1)* %arrayidx      ; <float> [#uses=1]
  %tmp8 = fadd float %tmp7, 0x3FB99999A0000000    ; <float> [#uses=1]
  store float %tmp8, float* %tmp0
  %tmp9 = load float addrspace(1)** %a1.addr      ; <float addrspace(1)*> [#uses=1]
  %tmp10 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx11 = getelementptr float addrspace(1)* %tmp9, i32 %tmp10 ; <float addrspace(1)*> [#uses=1]
  %tmp12 = load float addrspace(1)* %arrayidx11   ; <float> [#uses=1]
  %tmp13 = fadd float %tmp12, 0x3FF19999A0000000  ; <float> [#uses=1]
  store float %tmp13, float* %tmp1
  %tmp14 = load float addrspace(1)** %a2.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp15 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx16 = getelementptr float addrspace(1)* %tmp14, i32 %tmp15 ; <float addrspace(1)*> [#uses=1]
  %tmp17 = load float addrspace(1)* %arrayidx16   ; <float> [#uses=1]
  %tmp18 = fadd float %tmp17, 0x4000CCCCC0000000  ; <float> [#uses=1]
  store float %tmp18, float* %tmp2
  %tmp19 = load float addrspace(1)** %a3.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp20 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx21 = getelementptr float addrspace(1)* %tmp19, i32 %tmp20 ; <float addrspace(1)*> [#uses=1]
  %tmp22 = load float addrspace(1)* %arrayidx21   ; <float> [#uses=1]
  %tmp23 = fadd float %tmp22, 0x4008CCCCC0000000  ; <float> [#uses=1]
  store float %tmp23, float* %tmp3
  %tmp24 = load float addrspace(1)** %a4.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp25 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx26 = getelementptr float addrspace(1)* %tmp24, i32 %tmp25 ; <float addrspace(1)*> [#uses=1]
  %tmp27 = load float addrspace(1)* %arrayidx26   ; <float> [#uses=1]
  %tmp28 = fadd float %tmp27, 0x4010666660000000  ; <float> [#uses=1]
  store float %tmp28, float* %tmp4
  %tmp29 = load float addrspace(1)** %a5.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp30 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx31 = getelementptr float addrspace(1)* %tmp29, i32 %tmp30 ; <float addrspace(1)*> [#uses=1]
  %tmp32 = load float addrspace(1)* %arrayidx31   ; <float> [#uses=1]
  %tmp33 = fadd float %tmp32, 0x4014666660000000  ; <float> [#uses=1]
  store float %tmp33, float* %tmp5
  %tmp34 = load i32 addrspace(1)** %b0.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp35 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx36 = getelementptr i32 addrspace(1)* %tmp34, i32 %tmp35 ; <i32 addrspace(1)*> [#uses=1]
  %tmp37 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp38 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp39 = fadd float %tmp37, %tmp38              ; <float> [#uses=1]
  %tmp40 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp41 = fadd float %tmp39, %tmp40              ; <float> [#uses=1]
  %tmp42 = load float* %tmp3                      ; <float> [#uses=1]
  %tmp43 = fadd float %tmp41, %tmp42              ; <float> [#uses=1]
  %tmp44 = load float* %tmp4                      ; <float> [#uses=1]
  %tmp45 = fadd float %tmp43, %tmp44              ; <float> [#uses=1]
  %tmp46 = load float* %tmp5                      ; <float> [#uses=1]
  %tmp47 = fadd float %tmp45, %tmp46              ; <float> [#uses=1]
  %tmp48 = fmul float 0x3FF19999A0000000, %tmp47  ; <float> [#uses=1]
  %conv = fptosi float %tmp48 to i32              ; <i32> [#uses=1]
  store i32 %conv, i32 addrspace(1)* %arrayidx36
  br label %return

return:                                           ; preds = %entry
  ret void
}

define void @__OpenCL_test_fa1_1_7_kern_kernel(float addrspace(1)* %a0, i32 addrspace(1)* %b0, i32 addrspace(1)* %b1, i32 addrspace(1)* %b2, i32 addrspace(1)* %b3, i32 addrspace(1)* %b4, i32 addrspace(1)* %b5, i32 addrspace(1)* %b6) nounwind {
entry:
  %a0.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %b0.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b1.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b2.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b3.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b4.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b5.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b6.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %gtid = alloca i32, align 4                     ; <i32*> [#uses=9]
  %tmp0 = alloca float, align 4                   ; <float*> [#uses=8]
  store float addrspace(1)* %a0, float addrspace(1)** %a0.addr
  store i32 addrspace(1)* %b0, i32 addrspace(1)** %b0.addr
  store i32 addrspace(1)* %b1, i32 addrspace(1)** %b1.addr
  store i32 addrspace(1)* %b2, i32 addrspace(1)** %b2.addr
  store i32 addrspace(1)* %b3, i32 addrspace(1)** %b3.addr
  store i32 addrspace(1)* %b4, i32 addrspace(1)** %b4.addr
  store i32 addrspace(1)* %b5, i32 addrspace(1)** %b5.addr
  store i32 addrspace(1)* %b6, i32 addrspace(1)** %b6.addr
  %call = call i32 @get_global_id(i32 0) nounwind ; <i32> [#uses=1]
  store i32 %call, i32* %gtid
  %tmp = load float addrspace(1)** %a0.addr       ; <float addrspace(1)*> [#uses=1]
  %tmp1 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx = getelementptr float addrspace(1)* %tmp, i32 %tmp1 ; <float addrspace(1)*> [#uses=1]
  %tmp2 = load float addrspace(1)* %arrayidx      ; <float> [#uses=1]
  %tmp3 = fadd float %tmp2, 0x3FB99999A0000000    ; <float> [#uses=1]
  store float %tmp3, float* %tmp0
  %tmp4 = load i32 addrspace(1)** %b0.addr        ; <i32 addrspace(1)*> [#uses=1]
  %tmp5 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx6 = getelementptr i32 addrspace(1)* %tmp4, i32 %tmp5 ; <i32 addrspace(1)*> [#uses=1]
  %tmp7 = load float* %tmp0                       ; <float> [#uses=1]
  %tmp8 = fmul float 0x3FF19999A0000000, %tmp7    ; <float> [#uses=1]
  %conv = fptosi float %tmp8 to i32               ; <i32> [#uses=1]
  store i32 %conv, i32 addrspace(1)* %arrayidx6
  %tmp9 = load i32 addrspace(1)** %b1.addr        ; <i32 addrspace(1)*> [#uses=1]
  %tmp10 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx11 = getelementptr i32 addrspace(1)* %tmp9, i32 %tmp10 ; <i32 addrspace(1)*> [#uses=1]
  %tmp12 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp13 = fmul float 0x4000CCCCC0000000, %tmp12  ; <float> [#uses=1]
  %conv14 = fptosi float %tmp13 to i32            ; <i32> [#uses=1]
  store i32 %conv14, i32 addrspace(1)* %arrayidx11
  %tmp15 = load i32 addrspace(1)** %b2.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp16 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx17 = getelementptr i32 addrspace(1)* %tmp15, i32 %tmp16 ; <i32 addrspace(1)*> [#uses=1]
  %tmp18 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp19 = fmul float 0x4008CCCCC0000000, %tmp18  ; <float> [#uses=1]
  %conv20 = fptosi float %tmp19 to i32            ; <i32> [#uses=1]
  store i32 %conv20, i32 addrspace(1)* %arrayidx17
  %tmp21 = load i32 addrspace(1)** %b3.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp22 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx23 = getelementptr i32 addrspace(1)* %tmp21, i32 %tmp22 ; <i32 addrspace(1)*> [#uses=1]
  %tmp24 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp25 = fmul float 0x4010666660000000, %tmp24  ; <float> [#uses=1]
  %conv26 = fptosi float %tmp25 to i32            ; <i32> [#uses=1]
  store i32 %conv26, i32 addrspace(1)* %arrayidx23
  %tmp27 = load i32 addrspace(1)** %b4.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp28 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx29 = getelementptr i32 addrspace(1)* %tmp27, i32 %tmp28 ; <i32 addrspace(1)*> [#uses=1]
  %tmp30 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp31 = fmul float 0x4014666660000000, %tmp30  ; <float> [#uses=1]
  %conv32 = fptosi float %tmp31 to i32            ; <i32> [#uses=1]
  store i32 %conv32, i32 addrspace(1)* %arrayidx29
  %tmp33 = load i32 addrspace(1)** %b5.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp34 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx35 = getelementptr i32 addrspace(1)* %tmp33, i32 %tmp34 ; <i32 addrspace(1)*> [#uses=1]
  %tmp36 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp37 = fmul float 0x4018666660000000, %tmp36  ; <float> [#uses=1]
  %conv38 = fptosi float %tmp37 to i32            ; <i32> [#uses=1]
  store i32 %conv38, i32 addrspace(1)* %arrayidx35
  %tmp39 = load i32 addrspace(1)** %b6.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp40 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx41 = getelementptr i32 addrspace(1)* %tmp39, i32 %tmp40 ; <i32 addrspace(1)*> [#uses=1]
  %tmp42 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp43 = fmul float 0x401C666660000000, %tmp42  ; <float> [#uses=1]
  %conv44 = fptosi float %tmp43 to i32            ; <i32> [#uses=1]
  store i32 %conv44, i32 addrspace(1)* %arrayidx41
  br label %return

return:                                           ; preds = %entry
  ret void
}

define void @__OpenCL_test_fa1_2_6_kern_kernel(float addrspace(1)* %a0, float addrspace(1)* %a1, i32 addrspace(1)* %b0, i32 addrspace(1)* %b1, i32 addrspace(1)* %b2, i32 addrspace(1)* %b3, i32 addrspace(1)* %b4, i32 addrspace(1)* %b5) nounwind {
entry:
  %a0.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a1.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %b0.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b1.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b2.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b3.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b4.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b5.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %gtid = alloca i32, align 4                     ; <i32*> [#uses=9]
  %tmp0 = alloca float, align 4                   ; <float*> [#uses=7]
  %tmp1 = alloca float, align 4                   ; <float*> [#uses=7]
  store float addrspace(1)* %a0, float addrspace(1)** %a0.addr
  store float addrspace(1)* %a1, float addrspace(1)** %a1.addr
  store i32 addrspace(1)* %b0, i32 addrspace(1)** %b0.addr
  store i32 addrspace(1)* %b1, i32 addrspace(1)** %b1.addr
  store i32 addrspace(1)* %b2, i32 addrspace(1)** %b2.addr
  store i32 addrspace(1)* %b3, i32 addrspace(1)** %b3.addr
  store i32 addrspace(1)* %b4, i32 addrspace(1)** %b4.addr
  store i32 addrspace(1)* %b5, i32 addrspace(1)** %b5.addr
  %call = call i32 @get_global_id(i32 0) nounwind ; <i32> [#uses=1]
  store i32 %call, i32* %gtid
  %tmp = load float addrspace(1)** %a0.addr       ; <float addrspace(1)*> [#uses=1]
  %tmp2 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx = getelementptr float addrspace(1)* %tmp, i32 %tmp2 ; <float addrspace(1)*> [#uses=1]
  %tmp3 = load float addrspace(1)* %arrayidx      ; <float> [#uses=1]
  %tmp4 = fadd float %tmp3, 0x3FB99999A0000000    ; <float> [#uses=1]
  store float %tmp4, float* %tmp0
  %tmp5 = load float addrspace(1)** %a1.addr      ; <float addrspace(1)*> [#uses=1]
  %tmp6 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx7 = getelementptr float addrspace(1)* %tmp5, i32 %tmp6 ; <float addrspace(1)*> [#uses=1]
  %tmp8 = load float addrspace(1)* %arrayidx7     ; <float> [#uses=1]
  %tmp9 = fadd float %tmp8, 0x3FF19999A0000000    ; <float> [#uses=1]
  store float %tmp9, float* %tmp1
  %tmp10 = load i32 addrspace(1)** %b0.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp11 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx12 = getelementptr i32 addrspace(1)* %tmp10, i32 %tmp11 ; <i32 addrspace(1)*> [#uses=1]
  %tmp13 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp14 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp15 = fadd float %tmp13, %tmp14              ; <float> [#uses=1]
  %tmp16 = fmul float 0x3FF19999A0000000, %tmp15  ; <float> [#uses=1]
  %conv = fptosi float %tmp16 to i32              ; <i32> [#uses=1]
  store i32 %conv, i32 addrspace(1)* %arrayidx12
  %tmp17 = load i32 addrspace(1)** %b1.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp18 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx19 = getelementptr i32 addrspace(1)* %tmp17, i32 %tmp18 ; <i32 addrspace(1)*> [#uses=1]
  %tmp20 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp21 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp22 = fadd float %tmp20, %tmp21              ; <float> [#uses=1]
  %tmp23 = fmul float 0x4000CCCCC0000000, %tmp22  ; <float> [#uses=1]
  %conv24 = fptosi float %tmp23 to i32            ; <i32> [#uses=1]
  store i32 %conv24, i32 addrspace(1)* %arrayidx19
  %tmp25 = load i32 addrspace(1)** %b2.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp26 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx27 = getelementptr i32 addrspace(1)* %tmp25, i32 %tmp26 ; <i32 addrspace(1)*> [#uses=1]
  %tmp28 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp29 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp30 = fadd float %tmp28, %tmp29              ; <float> [#uses=1]
  %tmp31 = fmul float 0x4008CCCCC0000000, %tmp30  ; <float> [#uses=1]
  %conv32 = fptosi float %tmp31 to i32            ; <i32> [#uses=1]
  store i32 %conv32, i32 addrspace(1)* %arrayidx27
  %tmp33 = load i32 addrspace(1)** %b3.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp34 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx35 = getelementptr i32 addrspace(1)* %tmp33, i32 %tmp34 ; <i32 addrspace(1)*> [#uses=1]
  %tmp36 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp37 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp38 = fadd float %tmp36, %tmp37              ; <float> [#uses=1]
  %tmp39 = fmul float 0x4010666660000000, %tmp38  ; <float> [#uses=1]
  %conv40 = fptosi float %tmp39 to i32            ; <i32> [#uses=1]
  store i32 %conv40, i32 addrspace(1)* %arrayidx35
  %tmp41 = load i32 addrspace(1)** %b4.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp42 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx43 = getelementptr i32 addrspace(1)* %tmp41, i32 %tmp42 ; <i32 addrspace(1)*> [#uses=1]
  %tmp44 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp45 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp46 = fadd float %tmp44, %tmp45              ; <float> [#uses=1]
  %tmp47 = fmul float 0x4014666660000000, %tmp46  ; <float> [#uses=1]
  %conv48 = fptosi float %tmp47 to i32            ; <i32> [#uses=1]
  store i32 %conv48, i32 addrspace(1)* %arrayidx43
  %tmp49 = load i32 addrspace(1)** %b5.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp50 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx51 = getelementptr i32 addrspace(1)* %tmp49, i32 %tmp50 ; <i32 addrspace(1)*> [#uses=1]
  %tmp52 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp53 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp54 = fadd float %tmp52, %tmp53              ; <float> [#uses=1]
  %tmp55 = fmul float 0x4018666660000000, %tmp54  ; <float> [#uses=1]
  %conv56 = fptosi float %tmp55 to i32            ; <i32> [#uses=1]
  store i32 %conv56, i32 addrspace(1)* %arrayidx51
  br label %return

return:                                           ; preds = %entry
  ret void
}

define void @__OpenCL_test_fa1_3_5_kern_kernel(float addrspace(1)* %a0, float addrspace(1)* %a1, float addrspace(1)* %a2, i32 addrspace(1)* %b0, i32 addrspace(1)* %b1, i32 addrspace(1)* %b2, i32 addrspace(1)* %b3, i32 addrspace(1)* %b4) nounwind {
entry:
  %a0.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a1.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a2.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %b0.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b1.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b2.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b3.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b4.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %gtid = alloca i32, align 4                     ; <i32*> [#uses=9]
  %tmp0 = alloca float, align 4                   ; <float*> [#uses=6]
  %tmp1 = alloca float, align 4                   ; <float*> [#uses=6]
  %tmp2 = alloca float, align 4                   ; <float*> [#uses=6]
  store float addrspace(1)* %a0, float addrspace(1)** %a0.addr
  store float addrspace(1)* %a1, float addrspace(1)** %a1.addr
  store float addrspace(1)* %a2, float addrspace(1)** %a2.addr
  store i32 addrspace(1)* %b0, i32 addrspace(1)** %b0.addr
  store i32 addrspace(1)* %b1, i32 addrspace(1)** %b1.addr
  store i32 addrspace(1)* %b2, i32 addrspace(1)** %b2.addr
  store i32 addrspace(1)* %b3, i32 addrspace(1)** %b3.addr
  store i32 addrspace(1)* %b4, i32 addrspace(1)** %b4.addr
  %call = call i32 @get_global_id(i32 0) nounwind ; <i32> [#uses=1]
  store i32 %call, i32* %gtid
  %tmp = load float addrspace(1)** %a0.addr       ; <float addrspace(1)*> [#uses=1]
  %tmp3 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx = getelementptr float addrspace(1)* %tmp, i32 %tmp3 ; <float addrspace(1)*> [#uses=1]
  %tmp4 = load float addrspace(1)* %arrayidx      ; <float> [#uses=1]
  %tmp5 = fadd float %tmp4, 0x3FB99999A0000000    ; <float> [#uses=1]
  store float %tmp5, float* %tmp0
  %tmp6 = load float addrspace(1)** %a1.addr      ; <float addrspace(1)*> [#uses=1]
  %tmp7 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx8 = getelementptr float addrspace(1)* %tmp6, i32 %tmp7 ; <float addrspace(1)*> [#uses=1]
  %tmp9 = load float addrspace(1)* %arrayidx8     ; <float> [#uses=1]
  %tmp10 = fadd float %tmp9, 0x3FF19999A0000000   ; <float> [#uses=1]
  store float %tmp10, float* %tmp1
  %tmp11 = load float addrspace(1)** %a2.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp12 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx13 = getelementptr float addrspace(1)* %tmp11, i32 %tmp12 ; <float addrspace(1)*> [#uses=1]
  %tmp14 = load float addrspace(1)* %arrayidx13   ; <float> [#uses=1]
  %tmp15 = fadd float %tmp14, 0x4000CCCCC0000000  ; <float> [#uses=1]
  store float %tmp15, float* %tmp2
  %tmp16 = load i32 addrspace(1)** %b0.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp17 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx18 = getelementptr i32 addrspace(1)* %tmp16, i32 %tmp17 ; <i32 addrspace(1)*> [#uses=1]
  %tmp19 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp20 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp21 = fadd float %tmp19, %tmp20              ; <float> [#uses=1]
  %tmp22 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp23 = fadd float %tmp21, %tmp22              ; <float> [#uses=1]
  %tmp24 = fmul float 0x3FF19999A0000000, %tmp23  ; <float> [#uses=1]
  %conv = fptosi float %tmp24 to i32              ; <i32> [#uses=1]
  store i32 %conv, i32 addrspace(1)* %arrayidx18
  %tmp25 = load i32 addrspace(1)** %b1.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp26 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx27 = getelementptr i32 addrspace(1)* %tmp25, i32 %tmp26 ; <i32 addrspace(1)*> [#uses=1]
  %tmp28 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp29 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp30 = fadd float %tmp28, %tmp29              ; <float> [#uses=1]
  %tmp31 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp32 = fadd float %tmp30, %tmp31              ; <float> [#uses=1]
  %tmp33 = fmul float 0x4000CCCCC0000000, %tmp32  ; <float> [#uses=1]
  %conv34 = fptosi float %tmp33 to i32            ; <i32> [#uses=1]
  store i32 %conv34, i32 addrspace(1)* %arrayidx27
  %tmp35 = load i32 addrspace(1)** %b2.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp36 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx37 = getelementptr i32 addrspace(1)* %tmp35, i32 %tmp36 ; <i32 addrspace(1)*> [#uses=1]
  %tmp38 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp39 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp40 = fadd float %tmp38, %tmp39              ; <float> [#uses=1]
  %tmp41 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp42 = fadd float %tmp40, %tmp41              ; <float> [#uses=1]
  %tmp43 = fmul float 0x4008CCCCC0000000, %tmp42  ; <float> [#uses=1]
  %conv44 = fptosi float %tmp43 to i32            ; <i32> [#uses=1]
  store i32 %conv44, i32 addrspace(1)* %arrayidx37
  %tmp45 = load i32 addrspace(1)** %b3.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp46 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx47 = getelementptr i32 addrspace(1)* %tmp45, i32 %tmp46 ; <i32 addrspace(1)*> [#uses=1]
  %tmp48 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp49 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp50 = fadd float %tmp48, %tmp49              ; <float> [#uses=1]
  %tmp51 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp52 = fadd float %tmp50, %tmp51              ; <float> [#uses=1]
  %tmp53 = fmul float 0x4010666660000000, %tmp52  ; <float> [#uses=1]
  %conv54 = fptosi float %tmp53 to i32            ; <i32> [#uses=1]
  store i32 %conv54, i32 addrspace(1)* %arrayidx47
  %tmp55 = load i32 addrspace(1)** %b4.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp56 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx57 = getelementptr i32 addrspace(1)* %tmp55, i32 %tmp56 ; <i32 addrspace(1)*> [#uses=1]
  %tmp58 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp59 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp60 = fadd float %tmp58, %tmp59              ; <float> [#uses=1]
  %tmp61 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp62 = fadd float %tmp60, %tmp61              ; <float> [#uses=1]
  %tmp63 = fmul float 0x4014666660000000, %tmp62  ; <float> [#uses=1]
  %conv64 = fptosi float %tmp63 to i32            ; <i32> [#uses=1]
  store i32 %conv64, i32 addrspace(1)* %arrayidx57
  br label %return

return:                                           ; preds = %entry
  ret void
}

define void @__OpenCL_test_fa1_4_4_kern_kernel(float addrspace(1)* %a0, float addrspace(1)* %a1, float addrspace(1)* %a2, float addrspace(1)* %a3, i32 addrspace(1)* %b0, i32 addrspace(1)* %b1, i32 addrspace(1)* %b2, i32 addrspace(1)* %b3) nounwind {
entry:
  %a0.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a1.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a2.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a3.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %b0.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b1.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b2.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b3.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %gtid = alloca i32, align 4                     ; <i32*> [#uses=9]
  %tmp0 = alloca float, align 4                   ; <float*> [#uses=5]
  %tmp1 = alloca float, align 4                   ; <float*> [#uses=5]
  %tmp2 = alloca float, align 4                   ; <float*> [#uses=5]
  %tmp3 = alloca float, align 4                   ; <float*> [#uses=5]
  store float addrspace(1)* %a0, float addrspace(1)** %a0.addr
  store float addrspace(1)* %a1, float addrspace(1)** %a1.addr
  store float addrspace(1)* %a2, float addrspace(1)** %a2.addr
  store float addrspace(1)* %a3, float addrspace(1)** %a3.addr
  store i32 addrspace(1)* %b0, i32 addrspace(1)** %b0.addr
  store i32 addrspace(1)* %b1, i32 addrspace(1)** %b1.addr
  store i32 addrspace(1)* %b2, i32 addrspace(1)** %b2.addr
  store i32 addrspace(1)* %b3, i32 addrspace(1)** %b3.addr
  %call = call i32 @get_global_id(i32 0) nounwind ; <i32> [#uses=1]
  store i32 %call, i32* %gtid
  %tmp = load float addrspace(1)** %a0.addr       ; <float addrspace(1)*> [#uses=1]
  %tmp4 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx = getelementptr float addrspace(1)* %tmp, i32 %tmp4 ; <float addrspace(1)*> [#uses=1]
  %tmp5 = load float addrspace(1)* %arrayidx      ; <float> [#uses=1]
  %tmp6 = fadd float %tmp5, 0x3FB99999A0000000    ; <float> [#uses=1]
  store float %tmp6, float* %tmp0
  %tmp7 = load float addrspace(1)** %a1.addr      ; <float addrspace(1)*> [#uses=1]
  %tmp8 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx9 = getelementptr float addrspace(1)* %tmp7, i32 %tmp8 ; <float addrspace(1)*> [#uses=1]
  %tmp10 = load float addrspace(1)* %arrayidx9    ; <float> [#uses=1]
  %tmp11 = fadd float %tmp10, 0x3FF19999A0000000  ; <float> [#uses=1]
  store float %tmp11, float* %tmp1
  %tmp12 = load float addrspace(1)** %a2.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp13 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx14 = getelementptr float addrspace(1)* %tmp12, i32 %tmp13 ; <float addrspace(1)*> [#uses=1]
  %tmp15 = load float addrspace(1)* %arrayidx14   ; <float> [#uses=1]
  %tmp16 = fadd float %tmp15, 0x4000CCCCC0000000  ; <float> [#uses=1]
  store float %tmp16, float* %tmp2
  %tmp17 = load float addrspace(1)** %a3.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp18 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx19 = getelementptr float addrspace(1)* %tmp17, i32 %tmp18 ; <float addrspace(1)*> [#uses=1]
  %tmp20 = load float addrspace(1)* %arrayidx19   ; <float> [#uses=1]
  %tmp21 = fadd float %tmp20, 0x4008CCCCC0000000  ; <float> [#uses=1]
  store float %tmp21, float* %tmp3
  %tmp22 = load i32 addrspace(1)** %b0.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp23 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx24 = getelementptr i32 addrspace(1)* %tmp22, i32 %tmp23 ; <i32 addrspace(1)*> [#uses=1]
  %tmp25 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp26 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp27 = fadd float %tmp25, %tmp26              ; <float> [#uses=1]
  %tmp28 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp29 = fadd float %tmp27, %tmp28              ; <float> [#uses=1]
  %tmp30 = load float* %tmp3                      ; <float> [#uses=1]
  %tmp31 = fadd float %tmp29, %tmp30              ; <float> [#uses=1]
  %tmp32 = fmul float 0x3FF19999A0000000, %tmp31  ; <float> [#uses=1]
  %conv = fptosi float %tmp32 to i32              ; <i32> [#uses=1]
  store i32 %conv, i32 addrspace(1)* %arrayidx24
  %tmp33 = load i32 addrspace(1)** %b1.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp34 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx35 = getelementptr i32 addrspace(1)* %tmp33, i32 %tmp34 ; <i32 addrspace(1)*> [#uses=1]
  %tmp36 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp37 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp38 = fadd float %tmp36, %tmp37              ; <float> [#uses=1]
  %tmp39 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp40 = fadd float %tmp38, %tmp39              ; <float> [#uses=1]
  %tmp41 = load float* %tmp3                      ; <float> [#uses=1]
  %tmp42 = fadd float %tmp40, %tmp41              ; <float> [#uses=1]
  %tmp43 = fmul float 0x4000CCCCC0000000, %tmp42  ; <float> [#uses=1]
  %conv44 = fptosi float %tmp43 to i32            ; <i32> [#uses=1]
  store i32 %conv44, i32 addrspace(1)* %arrayidx35
  %tmp45 = load i32 addrspace(1)** %b2.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp46 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx47 = getelementptr i32 addrspace(1)* %tmp45, i32 %tmp46 ; <i32 addrspace(1)*> [#uses=1]
  %tmp48 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp49 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp50 = fadd float %tmp48, %tmp49              ; <float> [#uses=1]
  %tmp51 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp52 = fadd float %tmp50, %tmp51              ; <float> [#uses=1]
  %tmp53 = load float* %tmp3                      ; <float> [#uses=1]
  %tmp54 = fadd float %tmp52, %tmp53              ; <float> [#uses=1]
  %tmp55 = fmul float 0x4008CCCCC0000000, %tmp54  ; <float> [#uses=1]
  %conv56 = fptosi float %tmp55 to i32            ; <i32> [#uses=1]
  store i32 %conv56, i32 addrspace(1)* %arrayidx47
  %tmp57 = load i32 addrspace(1)** %b3.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp58 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx59 = getelementptr i32 addrspace(1)* %tmp57, i32 %tmp58 ; <i32 addrspace(1)*> [#uses=1]
  %tmp60 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp61 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp62 = fadd float %tmp60, %tmp61              ; <float> [#uses=1]
  %tmp63 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp64 = fadd float %tmp62, %tmp63              ; <float> [#uses=1]
  %tmp65 = load float* %tmp3                      ; <float> [#uses=1]
  %tmp66 = fadd float %tmp64, %tmp65              ; <float> [#uses=1]
  %tmp67 = fmul float 0x4010666660000000, %tmp66  ; <float> [#uses=1]
  %conv68 = fptosi float %tmp67 to i32            ; <i32> [#uses=1]
  store i32 %conv68, i32 addrspace(1)* %arrayidx59
  br label %return

return:                                           ; preds = %entry
  ret void
}

define void @__OpenCL_test_fa1_5_3_kern_kernel(float addrspace(1)* %a0, float addrspace(1)* %a1, float addrspace(1)* %a2, float addrspace(1)* %a3, float addrspace(1)* %a4, i32 addrspace(1)* %b0, i32 addrspace(1)* %b1, i32 addrspace(1)* %b2) nounwind {
entry:
  %a0.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a1.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a2.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a3.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a4.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %b0.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b1.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b2.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %gtid = alloca i32, align 4                     ; <i32*> [#uses=9]
  %tmp0 = alloca float, align 4                   ; <float*> [#uses=4]
  %tmp1 = alloca float, align 4                   ; <float*> [#uses=4]
  %tmp2 = alloca float, align 4                   ; <float*> [#uses=4]
  %tmp3 = alloca float, align 4                   ; <float*> [#uses=4]
  %tmp4 = alloca float, align 4                   ; <float*> [#uses=4]
  store float addrspace(1)* %a0, float addrspace(1)** %a0.addr
  store float addrspace(1)* %a1, float addrspace(1)** %a1.addr
  store float addrspace(1)* %a2, float addrspace(1)** %a2.addr
  store float addrspace(1)* %a3, float addrspace(1)** %a3.addr
  store float addrspace(1)* %a4, float addrspace(1)** %a4.addr
  store i32 addrspace(1)* %b0, i32 addrspace(1)** %b0.addr
  store i32 addrspace(1)* %b1, i32 addrspace(1)** %b1.addr
  store i32 addrspace(1)* %b2, i32 addrspace(1)** %b2.addr
  %call = call i32 @get_global_id(i32 0) nounwind ; <i32> [#uses=1]
  store i32 %call, i32* %gtid
  %tmp = load float addrspace(1)** %a0.addr       ; <float addrspace(1)*> [#uses=1]
  %tmp5 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx = getelementptr float addrspace(1)* %tmp, i32 %tmp5 ; <float addrspace(1)*> [#uses=1]
  %tmp6 = load float addrspace(1)* %arrayidx      ; <float> [#uses=1]
  %tmp7 = fadd float %tmp6, 0x3FB99999A0000000    ; <float> [#uses=1]
  store float %tmp7, float* %tmp0
  %tmp8 = load float addrspace(1)** %a1.addr      ; <float addrspace(1)*> [#uses=1]
  %tmp9 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx10 = getelementptr float addrspace(1)* %tmp8, i32 %tmp9 ; <float addrspace(1)*> [#uses=1]
  %tmp11 = load float addrspace(1)* %arrayidx10   ; <float> [#uses=1]
  %tmp12 = fadd float %tmp11, 0x3FF19999A0000000  ; <float> [#uses=1]
  store float %tmp12, float* %tmp1
  %tmp13 = load float addrspace(1)** %a2.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp14 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx15 = getelementptr float addrspace(1)* %tmp13, i32 %tmp14 ; <float addrspace(1)*> [#uses=1]
  %tmp16 = load float addrspace(1)* %arrayidx15   ; <float> [#uses=1]
  %tmp17 = fadd float %tmp16, 0x4000CCCCC0000000  ; <float> [#uses=1]
  store float %tmp17, float* %tmp2
  %tmp18 = load float addrspace(1)** %a3.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp19 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx20 = getelementptr float addrspace(1)* %tmp18, i32 %tmp19 ; <float addrspace(1)*> [#uses=1]
  %tmp21 = load float addrspace(1)* %arrayidx20   ; <float> [#uses=1]
  %tmp22 = fadd float %tmp21, 0x4008CCCCC0000000  ; <float> [#uses=1]
  store float %tmp22, float* %tmp3
  %tmp23 = load float addrspace(1)** %a4.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp24 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx25 = getelementptr float addrspace(1)* %tmp23, i32 %tmp24 ; <float addrspace(1)*> [#uses=1]
  %tmp26 = load float addrspace(1)* %arrayidx25   ; <float> [#uses=1]
  %tmp27 = fadd float %tmp26, 0x4010666660000000  ; <float> [#uses=1]
  store float %tmp27, float* %tmp4
  %tmp28 = load i32 addrspace(1)** %b0.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp29 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx30 = getelementptr i32 addrspace(1)* %tmp28, i32 %tmp29 ; <i32 addrspace(1)*> [#uses=1]
  %tmp31 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp32 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp33 = fadd float %tmp31, %tmp32              ; <float> [#uses=1]
  %tmp34 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp35 = fadd float %tmp33, %tmp34              ; <float> [#uses=1]
  %tmp36 = load float* %tmp3                      ; <float> [#uses=1]
  %tmp37 = fadd float %tmp35, %tmp36              ; <float> [#uses=1]
  %tmp38 = load float* %tmp4                      ; <float> [#uses=1]
  %tmp39 = fadd float %tmp37, %tmp38              ; <float> [#uses=1]
  %tmp40 = fmul float 0x3FF19999A0000000, %tmp39  ; <float> [#uses=1]
  %conv = fptosi float %tmp40 to i32              ; <i32> [#uses=1]
  store i32 %conv, i32 addrspace(1)* %arrayidx30
  %tmp41 = load i32 addrspace(1)** %b1.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp42 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx43 = getelementptr i32 addrspace(1)* %tmp41, i32 %tmp42 ; <i32 addrspace(1)*> [#uses=1]
  %tmp44 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp45 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp46 = fadd float %tmp44, %tmp45              ; <float> [#uses=1]
  %tmp47 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp48 = fadd float %tmp46, %tmp47              ; <float> [#uses=1]
  %tmp49 = load float* %tmp3                      ; <float> [#uses=1]
  %tmp50 = fadd float %tmp48, %tmp49              ; <float> [#uses=1]
  %tmp51 = load float* %tmp4                      ; <float> [#uses=1]
  %tmp52 = fadd float %tmp50, %tmp51              ; <float> [#uses=1]
  %tmp53 = fmul float 0x4000CCCCC0000000, %tmp52  ; <float> [#uses=1]
  %conv54 = fptosi float %tmp53 to i32            ; <i32> [#uses=1]
  store i32 %conv54, i32 addrspace(1)* %arrayidx43
  %tmp55 = load i32 addrspace(1)** %b2.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp56 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx57 = getelementptr i32 addrspace(1)* %tmp55, i32 %tmp56 ; <i32 addrspace(1)*> [#uses=1]
  %tmp58 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp59 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp60 = fadd float %tmp58, %tmp59              ; <float> [#uses=1]
  %tmp61 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp62 = fadd float %tmp60, %tmp61              ; <float> [#uses=1]
  %tmp63 = load float* %tmp3                      ; <float> [#uses=1]
  %tmp64 = fadd float %tmp62, %tmp63              ; <float> [#uses=1]
  %tmp65 = load float* %tmp4                      ; <float> [#uses=1]
  %tmp66 = fadd float %tmp64, %tmp65              ; <float> [#uses=1]
  %tmp67 = fmul float 0x4008CCCCC0000000, %tmp66  ; <float> [#uses=1]
  %conv68 = fptosi float %tmp67 to i32            ; <i32> [#uses=1]
  store i32 %conv68, i32 addrspace(1)* %arrayidx57
  br label %return

return:                                           ; preds = %entry
  ret void
}

define void @__OpenCL_test_fa1_6_2_kern_kernel(float addrspace(1)* %a0, float addrspace(1)* %a1, float addrspace(1)* %a2, float addrspace(1)* %a3, float addrspace(1)* %a4, float addrspace(1)* %a5, i32 addrspace(1)* %b0, i32 addrspace(1)* %b1) nounwind {
entry:
  %a0.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a1.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a2.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a3.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a4.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a5.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %b0.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b1.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %gtid = alloca i32, align 4                     ; <i32*> [#uses=9]
  %tmp0 = alloca float, align 4                   ; <float*> [#uses=3]
  %tmp1 = alloca float, align 4                   ; <float*> [#uses=3]
  %tmp2 = alloca float, align 4                   ; <float*> [#uses=3]
  %tmp3 = alloca float, align 4                   ; <float*> [#uses=3]
  %tmp4 = alloca float, align 4                   ; <float*> [#uses=3]
  %tmp5 = alloca float, align 4                   ; <float*> [#uses=3]
  store float addrspace(1)* %a0, float addrspace(1)** %a0.addr
  store float addrspace(1)* %a1, float addrspace(1)** %a1.addr
  store float addrspace(1)* %a2, float addrspace(1)** %a2.addr
  store float addrspace(1)* %a3, float addrspace(1)** %a3.addr
  store float addrspace(1)* %a4, float addrspace(1)** %a4.addr
  store float addrspace(1)* %a5, float addrspace(1)** %a5.addr
  store i32 addrspace(1)* %b0, i32 addrspace(1)** %b0.addr
  store i32 addrspace(1)* %b1, i32 addrspace(1)** %b1.addr
  %call = call i32 @get_global_id(i32 0) nounwind ; <i32> [#uses=1]
  store i32 %call, i32* %gtid
  %tmp = load float addrspace(1)** %a0.addr       ; <float addrspace(1)*> [#uses=1]
  %tmp6 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx = getelementptr float addrspace(1)* %tmp, i32 %tmp6 ; <float addrspace(1)*> [#uses=1]
  %tmp7 = load float addrspace(1)* %arrayidx      ; <float> [#uses=1]
  %tmp8 = fadd float %tmp7, 0x3FB99999A0000000    ; <float> [#uses=1]
  store float %tmp8, float* %tmp0
  %tmp9 = load float addrspace(1)** %a1.addr      ; <float addrspace(1)*> [#uses=1]
  %tmp10 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx11 = getelementptr float addrspace(1)* %tmp9, i32 %tmp10 ; <float addrspace(1)*> [#uses=1]
  %tmp12 = load float addrspace(1)* %arrayidx11   ; <float> [#uses=1]
  %tmp13 = fadd float %tmp12, 0x3FF19999A0000000  ; <float> [#uses=1]
  store float %tmp13, float* %tmp1
  %tmp14 = load float addrspace(1)** %a2.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp15 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx16 = getelementptr float addrspace(1)* %tmp14, i32 %tmp15 ; <float addrspace(1)*> [#uses=1]
  %tmp17 = load float addrspace(1)* %arrayidx16   ; <float> [#uses=1]
  %tmp18 = fadd float %tmp17, 0x4000CCCCC0000000  ; <float> [#uses=1]
  store float %tmp18, float* %tmp2
  %tmp19 = load float addrspace(1)** %a3.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp20 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx21 = getelementptr float addrspace(1)* %tmp19, i32 %tmp20 ; <float addrspace(1)*> [#uses=1]
  %tmp22 = load float addrspace(1)* %arrayidx21   ; <float> [#uses=1]
  %tmp23 = fadd float %tmp22, 0x4008CCCCC0000000  ; <float> [#uses=1]
  store float %tmp23, float* %tmp3
  %tmp24 = load float addrspace(1)** %a4.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp25 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx26 = getelementptr float addrspace(1)* %tmp24, i32 %tmp25 ; <float addrspace(1)*> [#uses=1]
  %tmp27 = load float addrspace(1)* %arrayidx26   ; <float> [#uses=1]
  %tmp28 = fadd float %tmp27, 0x4010666660000000  ; <float> [#uses=1]
  store float %tmp28, float* %tmp4
  %tmp29 = load float addrspace(1)** %a5.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp30 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx31 = getelementptr float addrspace(1)* %tmp29, i32 %tmp30 ; <float addrspace(1)*> [#uses=1]
  %tmp32 = load float addrspace(1)* %arrayidx31   ; <float> [#uses=1]
  %tmp33 = fadd float %tmp32, 0x4014666660000000  ; <float> [#uses=1]
  store float %tmp33, float* %tmp5
  %tmp34 = load i32 addrspace(1)** %b0.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp35 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx36 = getelementptr i32 addrspace(1)* %tmp34, i32 %tmp35 ; <i32 addrspace(1)*> [#uses=1]
  %tmp37 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp38 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp39 = fadd float %tmp37, %tmp38              ; <float> [#uses=1]
  %tmp40 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp41 = fadd float %tmp39, %tmp40              ; <float> [#uses=1]
  %tmp42 = load float* %tmp3                      ; <float> [#uses=1]
  %tmp43 = fadd float %tmp41, %tmp42              ; <float> [#uses=1]
  %tmp44 = load float* %tmp4                      ; <float> [#uses=1]
  %tmp45 = fadd float %tmp43, %tmp44              ; <float> [#uses=1]
  %tmp46 = load float* %tmp5                      ; <float> [#uses=1]
  %tmp47 = fadd float %tmp45, %tmp46              ; <float> [#uses=1]
  %tmp48 = fmul float 0x3FF19999A0000000, %tmp47  ; <float> [#uses=1]
  %conv = fptosi float %tmp48 to i32              ; <i32> [#uses=1]
  store i32 %conv, i32 addrspace(1)* %arrayidx36
  %tmp49 = load i32 addrspace(1)** %b1.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp50 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx51 = getelementptr i32 addrspace(1)* %tmp49, i32 %tmp50 ; <i32 addrspace(1)*> [#uses=1]
  %tmp52 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp53 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp54 = fadd float %tmp52, %tmp53              ; <float> [#uses=1]
  %tmp55 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp56 = fadd float %tmp54, %tmp55              ; <float> [#uses=1]
  %tmp57 = load float* %tmp3                      ; <float> [#uses=1]
  %tmp58 = fadd float %tmp56, %tmp57              ; <float> [#uses=1]
  %tmp59 = load float* %tmp4                      ; <float> [#uses=1]
  %tmp60 = fadd float %tmp58, %tmp59              ; <float> [#uses=1]
  %tmp61 = load float* %tmp5                      ; <float> [#uses=1]
  %tmp62 = fadd float %tmp60, %tmp61              ; <float> [#uses=1]
  %tmp63 = fmul float 0x4000CCCCC0000000, %tmp62  ; <float> [#uses=1]
  %conv64 = fptosi float %tmp63 to i32            ; <i32> [#uses=1]
  store i32 %conv64, i32 addrspace(1)* %arrayidx51
  br label %return

return:                                           ; preds = %entry
  ret void
}

define void @__OpenCL_test_fa1_7_1_kern_kernel(float addrspace(1)* %a0, float addrspace(1)* %a1, float addrspace(1)* %a2, float addrspace(1)* %a3, float addrspace(1)* %a4, float addrspace(1)* %a5, float addrspace(1)* %a6, i32 addrspace(1)* %b0) nounwind {
entry:
  %a0.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a1.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a2.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a3.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a4.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a5.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a6.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %b0.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %gtid = alloca i32, align 4                     ; <i32*> [#uses=9]
  %tmp0 = alloca float, align 4                   ; <float*> [#uses=2]
  %tmp1 = alloca float, align 4                   ; <float*> [#uses=2]
  %tmp2 = alloca float, align 4                   ; <float*> [#uses=2]
  %tmp3 = alloca float, align 4                   ; <float*> [#uses=2]
  %tmp4 = alloca float, align 4                   ; <float*> [#uses=2]
  %tmp5 = alloca float, align 4                   ; <float*> [#uses=2]
  %tmp6 = alloca float, align 4                   ; <float*> [#uses=2]
  store float addrspace(1)* %a0, float addrspace(1)** %a0.addr
  store float addrspace(1)* %a1, float addrspace(1)** %a1.addr
  store float addrspace(1)* %a2, float addrspace(1)** %a2.addr
  store float addrspace(1)* %a3, float addrspace(1)** %a3.addr
  store float addrspace(1)* %a4, float addrspace(1)** %a4.addr
  store float addrspace(1)* %a5, float addrspace(1)** %a5.addr
  store float addrspace(1)* %a6, float addrspace(1)** %a6.addr
  store i32 addrspace(1)* %b0, i32 addrspace(1)** %b0.addr
  %call = call i32 @get_global_id(i32 0) nounwind ; <i32> [#uses=1]
  store i32 %call, i32* %gtid
  %tmp = load float addrspace(1)** %a0.addr       ; <float addrspace(1)*> [#uses=1]
  %tmp7 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx = getelementptr float addrspace(1)* %tmp, i32 %tmp7 ; <float addrspace(1)*> [#uses=1]
  %tmp8 = load float addrspace(1)* %arrayidx      ; <float> [#uses=1]
  %tmp9 = fadd float %tmp8, 0x3FB99999A0000000    ; <float> [#uses=1]
  store float %tmp9, float* %tmp0
  %tmp10 = load float addrspace(1)** %a1.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp11 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx12 = getelementptr float addrspace(1)* %tmp10, i32 %tmp11 ; <float addrspace(1)*> [#uses=1]
  %tmp13 = load float addrspace(1)* %arrayidx12   ; <float> [#uses=1]
  %tmp14 = fadd float %tmp13, 0x3FF19999A0000000  ; <float> [#uses=1]
  store float %tmp14, float* %tmp1
  %tmp15 = load float addrspace(1)** %a2.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp16 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx17 = getelementptr float addrspace(1)* %tmp15, i32 %tmp16 ; <float addrspace(1)*> [#uses=1]
  %tmp18 = load float addrspace(1)* %arrayidx17   ; <float> [#uses=1]
  %tmp19 = fadd float %tmp18, 0x4000CCCCC0000000  ; <float> [#uses=1]
  store float %tmp19, float* %tmp2
  %tmp20 = load float addrspace(1)** %a3.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp21 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx22 = getelementptr float addrspace(1)* %tmp20, i32 %tmp21 ; <float addrspace(1)*> [#uses=1]
  %tmp23 = load float addrspace(1)* %arrayidx22   ; <float> [#uses=1]
  %tmp24 = fadd float %tmp23, 0x4008CCCCC0000000  ; <float> [#uses=1]
  store float %tmp24, float* %tmp3
  %tmp25 = load float addrspace(1)** %a4.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp26 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx27 = getelementptr float addrspace(1)* %tmp25, i32 %tmp26 ; <float addrspace(1)*> [#uses=1]
  %tmp28 = load float addrspace(1)* %arrayidx27   ; <float> [#uses=1]
  %tmp29 = fadd float %tmp28, 0x4010666660000000  ; <float> [#uses=1]
  store float %tmp29, float* %tmp4
  %tmp30 = load float addrspace(1)** %a5.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp31 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx32 = getelementptr float addrspace(1)* %tmp30, i32 %tmp31 ; <float addrspace(1)*> [#uses=1]
  %tmp33 = load float addrspace(1)* %arrayidx32   ; <float> [#uses=1]
  %tmp34 = fadd float %tmp33, 0x4014666660000000  ; <float> [#uses=1]
  store float %tmp34, float* %tmp5
  %tmp35 = load float addrspace(1)** %a6.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp36 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx37 = getelementptr float addrspace(1)* %tmp35, i32 %tmp36 ; <float addrspace(1)*> [#uses=1]
  %tmp38 = load float addrspace(1)* %arrayidx37   ; <float> [#uses=1]
  %tmp39 = fadd float %tmp38, 0x4018666660000000  ; <float> [#uses=1]
  store float %tmp39, float* %tmp6
  %tmp40 = load i32 addrspace(1)** %b0.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp41 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx42 = getelementptr i32 addrspace(1)* %tmp40, i32 %tmp41 ; <i32 addrspace(1)*> [#uses=1]
  %tmp43 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp44 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp45 = fadd float %tmp43, %tmp44              ; <float> [#uses=1]
  %tmp46 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp47 = fadd float %tmp45, %tmp46              ; <float> [#uses=1]
  %tmp48 = load float* %tmp3                      ; <float> [#uses=1]
  %tmp49 = fadd float %tmp47, %tmp48              ; <float> [#uses=1]
  %tmp50 = load float* %tmp4                      ; <float> [#uses=1]
  %tmp51 = fadd float %tmp49, %tmp50              ; <float> [#uses=1]
  %tmp52 = load float* %tmp5                      ; <float> [#uses=1]
  %tmp53 = fadd float %tmp51, %tmp52              ; <float> [#uses=1]
  %tmp54 = load float* %tmp6                      ; <float> [#uses=1]
  %tmp55 = fadd float %tmp53, %tmp54              ; <float> [#uses=1]
  %tmp56 = fmul float 0x3FF19999A0000000, %tmp55  ; <float> [#uses=1]
  %conv = fptosi float %tmp56 to i32              ; <i32> [#uses=1]
  store i32 %conv, i32 addrspace(1)* %arrayidx42
  br label %return

return:                                           ; preds = %entry
  ret void
}

define void @__OpenCL_test_fa1_1_8_kern_kernel(float addrspace(1)* %a0, i32 addrspace(1)* %b0, i32 addrspace(1)* %b1, i32 addrspace(1)* %b2, i32 addrspace(1)* %b3, i32 addrspace(1)* %b4, i32 addrspace(1)* %b5, i32 addrspace(1)* %b6, i32 addrspace(1)* %b7) nounwind {
entry:
  %a0.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %b0.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b1.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b2.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b3.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b4.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b5.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b6.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b7.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %gtid = alloca i32, align 4                     ; <i32*> [#uses=10]
  %tmp0 = alloca float, align 4                   ; <float*> [#uses=9]
  store float addrspace(1)* %a0, float addrspace(1)** %a0.addr
  store i32 addrspace(1)* %b0, i32 addrspace(1)** %b0.addr
  store i32 addrspace(1)* %b1, i32 addrspace(1)** %b1.addr
  store i32 addrspace(1)* %b2, i32 addrspace(1)** %b2.addr
  store i32 addrspace(1)* %b3, i32 addrspace(1)** %b3.addr
  store i32 addrspace(1)* %b4, i32 addrspace(1)** %b4.addr
  store i32 addrspace(1)* %b5, i32 addrspace(1)** %b5.addr
  store i32 addrspace(1)* %b6, i32 addrspace(1)** %b6.addr
  store i32 addrspace(1)* %b7, i32 addrspace(1)** %b7.addr
  %call = call i32 @get_global_id(i32 0) nounwind ; <i32> [#uses=1]
  store i32 %call, i32* %gtid
  %tmp = load float addrspace(1)** %a0.addr       ; <float addrspace(1)*> [#uses=1]
  %tmp1 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx = getelementptr float addrspace(1)* %tmp, i32 %tmp1 ; <float addrspace(1)*> [#uses=1]
  %tmp2 = load float addrspace(1)* %arrayidx      ; <float> [#uses=1]
  %tmp3 = fadd float %tmp2, 0x3FB99999A0000000    ; <float> [#uses=1]
  store float %tmp3, float* %tmp0
  %tmp4 = load i32 addrspace(1)** %b0.addr        ; <i32 addrspace(1)*> [#uses=1]
  %tmp5 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx6 = getelementptr i32 addrspace(1)* %tmp4, i32 %tmp5 ; <i32 addrspace(1)*> [#uses=1]
  %tmp7 = load float* %tmp0                       ; <float> [#uses=1]
  %tmp8 = fmul float 0x3FF19999A0000000, %tmp7    ; <float> [#uses=1]
  %conv = fptosi float %tmp8 to i32               ; <i32> [#uses=1]
  store i32 %conv, i32 addrspace(1)* %arrayidx6
  %tmp9 = load i32 addrspace(1)** %b1.addr        ; <i32 addrspace(1)*> [#uses=1]
  %tmp10 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx11 = getelementptr i32 addrspace(1)* %tmp9, i32 %tmp10 ; <i32 addrspace(1)*> [#uses=1]
  %tmp12 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp13 = fmul float 0x4000CCCCC0000000, %tmp12  ; <float> [#uses=1]
  %conv14 = fptosi float %tmp13 to i32            ; <i32> [#uses=1]
  store i32 %conv14, i32 addrspace(1)* %arrayidx11
  %tmp15 = load i32 addrspace(1)** %b2.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp16 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx17 = getelementptr i32 addrspace(1)* %tmp15, i32 %tmp16 ; <i32 addrspace(1)*> [#uses=1]
  %tmp18 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp19 = fmul float 0x4008CCCCC0000000, %tmp18  ; <float> [#uses=1]
  %conv20 = fptosi float %tmp19 to i32            ; <i32> [#uses=1]
  store i32 %conv20, i32 addrspace(1)* %arrayidx17
  %tmp21 = load i32 addrspace(1)** %b3.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp22 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx23 = getelementptr i32 addrspace(1)* %tmp21, i32 %tmp22 ; <i32 addrspace(1)*> [#uses=1]
  %tmp24 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp25 = fmul float 0x4010666660000000, %tmp24  ; <float> [#uses=1]
  %conv26 = fptosi float %tmp25 to i32            ; <i32> [#uses=1]
  store i32 %conv26, i32 addrspace(1)* %arrayidx23
  %tmp27 = load i32 addrspace(1)** %b4.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp28 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx29 = getelementptr i32 addrspace(1)* %tmp27, i32 %tmp28 ; <i32 addrspace(1)*> [#uses=1]
  %tmp30 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp31 = fmul float 0x4014666660000000, %tmp30  ; <float> [#uses=1]
  %conv32 = fptosi float %tmp31 to i32            ; <i32> [#uses=1]
  store i32 %conv32, i32 addrspace(1)* %arrayidx29
  %tmp33 = load i32 addrspace(1)** %b5.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp34 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx35 = getelementptr i32 addrspace(1)* %tmp33, i32 %tmp34 ; <i32 addrspace(1)*> [#uses=1]
  %tmp36 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp37 = fmul float 0x4018666660000000, %tmp36  ; <float> [#uses=1]
  %conv38 = fptosi float %tmp37 to i32            ; <i32> [#uses=1]
  store i32 %conv38, i32 addrspace(1)* %arrayidx35
  %tmp39 = load i32 addrspace(1)** %b6.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp40 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx41 = getelementptr i32 addrspace(1)* %tmp39, i32 %tmp40 ; <i32 addrspace(1)*> [#uses=1]
  %tmp42 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp43 = fmul float 0x401C666660000000, %tmp42  ; <float> [#uses=1]
  %conv44 = fptosi float %tmp43 to i32            ; <i32> [#uses=1]
  store i32 %conv44, i32 addrspace(1)* %arrayidx41
  %tmp45 = load i32 addrspace(1)** %b7.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp46 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx47 = getelementptr i32 addrspace(1)* %tmp45, i32 %tmp46 ; <i32 addrspace(1)*> [#uses=1]
  %tmp48 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp49 = fmul float 0x4020333340000000, %tmp48  ; <float> [#uses=1]
  %conv50 = fptosi float %tmp49 to i32            ; <i32> [#uses=1]
  store i32 %conv50, i32 addrspace(1)* %arrayidx47
  br label %return

return:                                           ; preds = %entry
  ret void
}

define void @__OpenCL_test_fa1_2_7_kern_kernel(float addrspace(1)* %a0, float addrspace(1)* %a1, i32 addrspace(1)* %b0, i32 addrspace(1)* %b1, i32 addrspace(1)* %b2, i32 addrspace(1)* %b3, i32 addrspace(1)* %b4, i32 addrspace(1)* %b5, i32 addrspace(1)* %b6) nounwind {
entry:
  %a0.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a1.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %b0.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b1.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b2.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b3.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b4.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b5.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b6.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %gtid = alloca i32, align 4                     ; <i32*> [#uses=10]
  %tmp0 = alloca float, align 4                   ; <float*> [#uses=8]
  %tmp1 = alloca float, align 4                   ; <float*> [#uses=8]
  store float addrspace(1)* %a0, float addrspace(1)** %a0.addr
  store float addrspace(1)* %a1, float addrspace(1)** %a1.addr
  store i32 addrspace(1)* %b0, i32 addrspace(1)** %b0.addr
  store i32 addrspace(1)* %b1, i32 addrspace(1)** %b1.addr
  store i32 addrspace(1)* %b2, i32 addrspace(1)** %b2.addr
  store i32 addrspace(1)* %b3, i32 addrspace(1)** %b3.addr
  store i32 addrspace(1)* %b4, i32 addrspace(1)** %b4.addr
  store i32 addrspace(1)* %b5, i32 addrspace(1)** %b5.addr
  store i32 addrspace(1)* %b6, i32 addrspace(1)** %b6.addr
  %call = call i32 @get_global_id(i32 0) nounwind ; <i32> [#uses=1]
  store i32 %call, i32* %gtid
  %tmp = load float addrspace(1)** %a0.addr       ; <float addrspace(1)*> [#uses=1]
  %tmp2 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx = getelementptr float addrspace(1)* %tmp, i32 %tmp2 ; <float addrspace(1)*> [#uses=1]
  %tmp3 = load float addrspace(1)* %arrayidx      ; <float> [#uses=1]
  %tmp4 = fadd float %tmp3, 0x3FB99999A0000000    ; <float> [#uses=1]
  store float %tmp4, float* %tmp0
  %tmp5 = load float addrspace(1)** %a1.addr      ; <float addrspace(1)*> [#uses=1]
  %tmp6 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx7 = getelementptr float addrspace(1)* %tmp5, i32 %tmp6 ; <float addrspace(1)*> [#uses=1]
  %tmp8 = load float addrspace(1)* %arrayidx7     ; <float> [#uses=1]
  %tmp9 = fadd float %tmp8, 0x3FF19999A0000000    ; <float> [#uses=1]
  store float %tmp9, float* %tmp1
  %tmp10 = load i32 addrspace(1)** %b0.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp11 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx12 = getelementptr i32 addrspace(1)* %tmp10, i32 %tmp11 ; <i32 addrspace(1)*> [#uses=1]
  %tmp13 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp14 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp15 = fadd float %tmp13, %tmp14              ; <float> [#uses=1]
  %tmp16 = fmul float 0x3FF19999A0000000, %tmp15  ; <float> [#uses=1]
  %conv = fptosi float %tmp16 to i32              ; <i32> [#uses=1]
  store i32 %conv, i32 addrspace(1)* %arrayidx12
  %tmp17 = load i32 addrspace(1)** %b1.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp18 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx19 = getelementptr i32 addrspace(1)* %tmp17, i32 %tmp18 ; <i32 addrspace(1)*> [#uses=1]
  %tmp20 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp21 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp22 = fadd float %tmp20, %tmp21              ; <float> [#uses=1]
  %tmp23 = fmul float 0x4000CCCCC0000000, %tmp22  ; <float> [#uses=1]
  %conv24 = fptosi float %tmp23 to i32            ; <i32> [#uses=1]
  store i32 %conv24, i32 addrspace(1)* %arrayidx19
  %tmp25 = load i32 addrspace(1)** %b2.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp26 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx27 = getelementptr i32 addrspace(1)* %tmp25, i32 %tmp26 ; <i32 addrspace(1)*> [#uses=1]
  %tmp28 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp29 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp30 = fadd float %tmp28, %tmp29              ; <float> [#uses=1]
  %tmp31 = fmul float 0x4008CCCCC0000000, %tmp30  ; <float> [#uses=1]
  %conv32 = fptosi float %tmp31 to i32            ; <i32> [#uses=1]
  store i32 %conv32, i32 addrspace(1)* %arrayidx27
  %tmp33 = load i32 addrspace(1)** %b3.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp34 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx35 = getelementptr i32 addrspace(1)* %tmp33, i32 %tmp34 ; <i32 addrspace(1)*> [#uses=1]
  %tmp36 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp37 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp38 = fadd float %tmp36, %tmp37              ; <float> [#uses=1]
  %tmp39 = fmul float 0x4010666660000000, %tmp38  ; <float> [#uses=1]
  %conv40 = fptosi float %tmp39 to i32            ; <i32> [#uses=1]
  store i32 %conv40, i32 addrspace(1)* %arrayidx35
  %tmp41 = load i32 addrspace(1)** %b4.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp42 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx43 = getelementptr i32 addrspace(1)* %tmp41, i32 %tmp42 ; <i32 addrspace(1)*> [#uses=1]
  %tmp44 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp45 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp46 = fadd float %tmp44, %tmp45              ; <float> [#uses=1]
  %tmp47 = fmul float 0x4014666660000000, %tmp46  ; <float> [#uses=1]
  %conv48 = fptosi float %tmp47 to i32            ; <i32> [#uses=1]
  store i32 %conv48, i32 addrspace(1)* %arrayidx43
  %tmp49 = load i32 addrspace(1)** %b5.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp50 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx51 = getelementptr i32 addrspace(1)* %tmp49, i32 %tmp50 ; <i32 addrspace(1)*> [#uses=1]
  %tmp52 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp53 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp54 = fadd float %tmp52, %tmp53              ; <float> [#uses=1]
  %tmp55 = fmul float 0x4018666660000000, %tmp54  ; <float> [#uses=1]
  %conv56 = fptosi float %tmp55 to i32            ; <i32> [#uses=1]
  store i32 %conv56, i32 addrspace(1)* %arrayidx51
  %tmp57 = load i32 addrspace(1)** %b6.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp58 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx59 = getelementptr i32 addrspace(1)* %tmp57, i32 %tmp58 ; <i32 addrspace(1)*> [#uses=1]
  %tmp60 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp61 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp62 = fadd float %tmp60, %tmp61              ; <float> [#uses=1]
  %tmp63 = fmul float 0x401C666660000000, %tmp62  ; <float> [#uses=1]
  %conv64 = fptosi float %tmp63 to i32            ; <i32> [#uses=1]
  store i32 %conv64, i32 addrspace(1)* %arrayidx59
  br label %return

return:                                           ; preds = %entry
  ret void
}

define void @__OpenCL_test_fa1_3_6_kern_kernel(float addrspace(1)* %a0, float addrspace(1)* %a1, float addrspace(1)* %a2, i32 addrspace(1)* %b0, i32 addrspace(1)* %b1, i32 addrspace(1)* %b2, i32 addrspace(1)* %b3, i32 addrspace(1)* %b4, i32 addrspace(1)* %b5) nounwind {
entry:
  %a0.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a1.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a2.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %b0.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b1.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b2.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b3.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b4.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b5.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %gtid = alloca i32, align 4                     ; <i32*> [#uses=10]
  %tmp0 = alloca float, align 4                   ; <float*> [#uses=7]
  %tmp1 = alloca float, align 4                   ; <float*> [#uses=7]
  %tmp2 = alloca float, align 4                   ; <float*> [#uses=7]
  store float addrspace(1)* %a0, float addrspace(1)** %a0.addr
  store float addrspace(1)* %a1, float addrspace(1)** %a1.addr
  store float addrspace(1)* %a2, float addrspace(1)** %a2.addr
  store i32 addrspace(1)* %b0, i32 addrspace(1)** %b0.addr
  store i32 addrspace(1)* %b1, i32 addrspace(1)** %b1.addr
  store i32 addrspace(1)* %b2, i32 addrspace(1)** %b2.addr
  store i32 addrspace(1)* %b3, i32 addrspace(1)** %b3.addr
  store i32 addrspace(1)* %b4, i32 addrspace(1)** %b4.addr
  store i32 addrspace(1)* %b5, i32 addrspace(1)** %b5.addr
  %call = call i32 @get_global_id(i32 0) nounwind ; <i32> [#uses=1]
  store i32 %call, i32* %gtid
  %tmp = load float addrspace(1)** %a0.addr       ; <float addrspace(1)*> [#uses=1]
  %tmp3 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx = getelementptr float addrspace(1)* %tmp, i32 %tmp3 ; <float addrspace(1)*> [#uses=1]
  %tmp4 = load float addrspace(1)* %arrayidx      ; <float> [#uses=1]
  %tmp5 = fadd float %tmp4, 0x3FB99999A0000000    ; <float> [#uses=1]
  store float %tmp5, float* %tmp0
  %tmp6 = load float addrspace(1)** %a1.addr      ; <float addrspace(1)*> [#uses=1]
  %tmp7 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx8 = getelementptr float addrspace(1)* %tmp6, i32 %tmp7 ; <float addrspace(1)*> [#uses=1]
  %tmp9 = load float addrspace(1)* %arrayidx8     ; <float> [#uses=1]
  %tmp10 = fadd float %tmp9, 0x3FF19999A0000000   ; <float> [#uses=1]
  store float %tmp10, float* %tmp1
  %tmp11 = load float addrspace(1)** %a2.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp12 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx13 = getelementptr float addrspace(1)* %tmp11, i32 %tmp12 ; <float addrspace(1)*> [#uses=1]
  %tmp14 = load float addrspace(1)* %arrayidx13   ; <float> [#uses=1]
  %tmp15 = fadd float %tmp14, 0x4000CCCCC0000000  ; <float> [#uses=1]
  store float %tmp15, float* %tmp2
  %tmp16 = load i32 addrspace(1)** %b0.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp17 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx18 = getelementptr i32 addrspace(1)* %tmp16, i32 %tmp17 ; <i32 addrspace(1)*> [#uses=1]
  %tmp19 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp20 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp21 = fadd float %tmp19, %tmp20              ; <float> [#uses=1]
  %tmp22 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp23 = fadd float %tmp21, %tmp22              ; <float> [#uses=1]
  %tmp24 = fmul float 0x3FF19999A0000000, %tmp23  ; <float> [#uses=1]
  %conv = fptosi float %tmp24 to i32              ; <i32> [#uses=1]
  store i32 %conv, i32 addrspace(1)* %arrayidx18
  %tmp25 = load i32 addrspace(1)** %b1.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp26 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx27 = getelementptr i32 addrspace(1)* %tmp25, i32 %tmp26 ; <i32 addrspace(1)*> [#uses=1]
  %tmp28 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp29 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp30 = fadd float %tmp28, %tmp29              ; <float> [#uses=1]
  %tmp31 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp32 = fadd float %tmp30, %tmp31              ; <float> [#uses=1]
  %tmp33 = fmul float 0x4000CCCCC0000000, %tmp32  ; <float> [#uses=1]
  %conv34 = fptosi float %tmp33 to i32            ; <i32> [#uses=1]
  store i32 %conv34, i32 addrspace(1)* %arrayidx27
  %tmp35 = load i32 addrspace(1)** %b2.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp36 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx37 = getelementptr i32 addrspace(1)* %tmp35, i32 %tmp36 ; <i32 addrspace(1)*> [#uses=1]
  %tmp38 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp39 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp40 = fadd float %tmp38, %tmp39              ; <float> [#uses=1]
  %tmp41 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp42 = fadd float %tmp40, %tmp41              ; <float> [#uses=1]
  %tmp43 = fmul float 0x4008CCCCC0000000, %tmp42  ; <float> [#uses=1]
  %conv44 = fptosi float %tmp43 to i32            ; <i32> [#uses=1]
  store i32 %conv44, i32 addrspace(1)* %arrayidx37
  %tmp45 = load i32 addrspace(1)** %b3.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp46 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx47 = getelementptr i32 addrspace(1)* %tmp45, i32 %tmp46 ; <i32 addrspace(1)*> [#uses=1]
  %tmp48 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp49 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp50 = fadd float %tmp48, %tmp49              ; <float> [#uses=1]
  %tmp51 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp52 = fadd float %tmp50, %tmp51              ; <float> [#uses=1]
  %tmp53 = fmul float 0x4010666660000000, %tmp52  ; <float> [#uses=1]
  %conv54 = fptosi float %tmp53 to i32            ; <i32> [#uses=1]
  store i32 %conv54, i32 addrspace(1)* %arrayidx47
  %tmp55 = load i32 addrspace(1)** %b4.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp56 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx57 = getelementptr i32 addrspace(1)* %tmp55, i32 %tmp56 ; <i32 addrspace(1)*> [#uses=1]
  %tmp58 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp59 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp60 = fadd float %tmp58, %tmp59              ; <float> [#uses=1]
  %tmp61 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp62 = fadd float %tmp60, %tmp61              ; <float> [#uses=1]
  %tmp63 = fmul float 0x4014666660000000, %tmp62  ; <float> [#uses=1]
  %conv64 = fptosi float %tmp63 to i32            ; <i32> [#uses=1]
  store i32 %conv64, i32 addrspace(1)* %arrayidx57
  %tmp65 = load i32 addrspace(1)** %b5.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp66 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx67 = getelementptr i32 addrspace(1)* %tmp65, i32 %tmp66 ; <i32 addrspace(1)*> [#uses=1]
  %tmp68 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp69 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp70 = fadd float %tmp68, %tmp69              ; <float> [#uses=1]
  %tmp71 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp72 = fadd float %tmp70, %tmp71              ; <float> [#uses=1]
  %tmp73 = fmul float 0x4018666660000000, %tmp72  ; <float> [#uses=1]
  %conv74 = fptosi float %tmp73 to i32            ; <i32> [#uses=1]
  store i32 %conv74, i32 addrspace(1)* %arrayidx67
  br label %return

return:                                           ; preds = %entry
  ret void
}

define void @__OpenCL_test_fa1_4_5_kern_kernel(float addrspace(1)* %a0, float addrspace(1)* %a1, float addrspace(1)* %a2, float addrspace(1)* %a3, i32 addrspace(1)* %b0, i32 addrspace(1)* %b1, i32 addrspace(1)* %b2, i32 addrspace(1)* %b3, i32 addrspace(1)* %b4) nounwind {
entry:
  %a0.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a1.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a2.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a3.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %b0.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b1.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b2.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b3.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b4.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %gtid = alloca i32, align 4                     ; <i32*> [#uses=10]
  %tmp0 = alloca float, align 4                   ; <float*> [#uses=6]
  %tmp1 = alloca float, align 4                   ; <float*> [#uses=6]
  %tmp2 = alloca float, align 4                   ; <float*> [#uses=6]
  %tmp3 = alloca float, align 4                   ; <float*> [#uses=6]
  store float addrspace(1)* %a0, float addrspace(1)** %a0.addr
  store float addrspace(1)* %a1, float addrspace(1)** %a1.addr
  store float addrspace(1)* %a2, float addrspace(1)** %a2.addr
  store float addrspace(1)* %a3, float addrspace(1)** %a3.addr
  store i32 addrspace(1)* %b0, i32 addrspace(1)** %b0.addr
  store i32 addrspace(1)* %b1, i32 addrspace(1)** %b1.addr
  store i32 addrspace(1)* %b2, i32 addrspace(1)** %b2.addr
  store i32 addrspace(1)* %b3, i32 addrspace(1)** %b3.addr
  store i32 addrspace(1)* %b4, i32 addrspace(1)** %b4.addr
  %call = call i32 @get_global_id(i32 0) nounwind ; <i32> [#uses=1]
  store i32 %call, i32* %gtid
  %tmp = load float addrspace(1)** %a0.addr       ; <float addrspace(1)*> [#uses=1]
  %tmp4 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx = getelementptr float addrspace(1)* %tmp, i32 %tmp4 ; <float addrspace(1)*> [#uses=1]
  %tmp5 = load float addrspace(1)* %arrayidx      ; <float> [#uses=1]
  %tmp6 = fadd float %tmp5, 0x3FB99999A0000000    ; <float> [#uses=1]
  store float %tmp6, float* %tmp0
  %tmp7 = load float addrspace(1)** %a1.addr      ; <float addrspace(1)*> [#uses=1]
  %tmp8 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx9 = getelementptr float addrspace(1)* %tmp7, i32 %tmp8 ; <float addrspace(1)*> [#uses=1]
  %tmp10 = load float addrspace(1)* %arrayidx9    ; <float> [#uses=1]
  %tmp11 = fadd float %tmp10, 0x3FF19999A0000000  ; <float> [#uses=1]
  store float %tmp11, float* %tmp1
  %tmp12 = load float addrspace(1)** %a2.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp13 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx14 = getelementptr float addrspace(1)* %tmp12, i32 %tmp13 ; <float addrspace(1)*> [#uses=1]
  %tmp15 = load float addrspace(1)* %arrayidx14   ; <float> [#uses=1]
  %tmp16 = fadd float %tmp15, 0x4000CCCCC0000000  ; <float> [#uses=1]
  store float %tmp16, float* %tmp2
  %tmp17 = load float addrspace(1)** %a3.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp18 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx19 = getelementptr float addrspace(1)* %tmp17, i32 %tmp18 ; <float addrspace(1)*> [#uses=1]
  %tmp20 = load float addrspace(1)* %arrayidx19   ; <float> [#uses=1]
  %tmp21 = fadd float %tmp20, 0x4008CCCCC0000000  ; <float> [#uses=1]
  store float %tmp21, float* %tmp3
  %tmp22 = load i32 addrspace(1)** %b0.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp23 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx24 = getelementptr i32 addrspace(1)* %tmp22, i32 %tmp23 ; <i32 addrspace(1)*> [#uses=1]
  %tmp25 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp26 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp27 = fadd float %tmp25, %tmp26              ; <float> [#uses=1]
  %tmp28 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp29 = fadd float %tmp27, %tmp28              ; <float> [#uses=1]
  %tmp30 = load float* %tmp3                      ; <float> [#uses=1]
  %tmp31 = fadd float %tmp29, %tmp30              ; <float> [#uses=1]
  %tmp32 = fmul float 0x3FF19999A0000000, %tmp31  ; <float> [#uses=1]
  %conv = fptosi float %tmp32 to i32              ; <i32> [#uses=1]
  store i32 %conv, i32 addrspace(1)* %arrayidx24
  %tmp33 = load i32 addrspace(1)** %b1.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp34 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx35 = getelementptr i32 addrspace(1)* %tmp33, i32 %tmp34 ; <i32 addrspace(1)*> [#uses=1]
  %tmp36 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp37 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp38 = fadd float %tmp36, %tmp37              ; <float> [#uses=1]
  %tmp39 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp40 = fadd float %tmp38, %tmp39              ; <float> [#uses=1]
  %tmp41 = load float* %tmp3                      ; <float> [#uses=1]
  %tmp42 = fadd float %tmp40, %tmp41              ; <float> [#uses=1]
  %tmp43 = fmul float 0x4000CCCCC0000000, %tmp42  ; <float> [#uses=1]
  %conv44 = fptosi float %tmp43 to i32            ; <i32> [#uses=1]
  store i32 %conv44, i32 addrspace(1)* %arrayidx35
  %tmp45 = load i32 addrspace(1)** %b2.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp46 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx47 = getelementptr i32 addrspace(1)* %tmp45, i32 %tmp46 ; <i32 addrspace(1)*> [#uses=1]
  %tmp48 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp49 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp50 = fadd float %tmp48, %tmp49              ; <float> [#uses=1]
  %tmp51 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp52 = fadd float %tmp50, %tmp51              ; <float> [#uses=1]
  %tmp53 = load float* %tmp3                      ; <float> [#uses=1]
  %tmp54 = fadd float %tmp52, %tmp53              ; <float> [#uses=1]
  %tmp55 = fmul float 0x4008CCCCC0000000, %tmp54  ; <float> [#uses=1]
  %conv56 = fptosi float %tmp55 to i32            ; <i32> [#uses=1]
  store i32 %conv56, i32 addrspace(1)* %arrayidx47
  %tmp57 = load i32 addrspace(1)** %b3.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp58 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx59 = getelementptr i32 addrspace(1)* %tmp57, i32 %tmp58 ; <i32 addrspace(1)*> [#uses=1]
  %tmp60 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp61 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp62 = fadd float %tmp60, %tmp61              ; <float> [#uses=1]
  %tmp63 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp64 = fadd float %tmp62, %tmp63              ; <float> [#uses=1]
  %tmp65 = load float* %tmp3                      ; <float> [#uses=1]
  %tmp66 = fadd float %tmp64, %tmp65              ; <float> [#uses=1]
  %tmp67 = fmul float 0x4010666660000000, %tmp66  ; <float> [#uses=1]
  %conv68 = fptosi float %tmp67 to i32            ; <i32> [#uses=1]
  store i32 %conv68, i32 addrspace(1)* %arrayidx59
  %tmp69 = load i32 addrspace(1)** %b4.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp70 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx71 = getelementptr i32 addrspace(1)* %tmp69, i32 %tmp70 ; <i32 addrspace(1)*> [#uses=1]
  %tmp72 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp73 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp74 = fadd float %tmp72, %tmp73              ; <float> [#uses=1]
  %tmp75 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp76 = fadd float %tmp74, %tmp75              ; <float> [#uses=1]
  %tmp77 = load float* %tmp3                      ; <float> [#uses=1]
  %tmp78 = fadd float %tmp76, %tmp77              ; <float> [#uses=1]
  %tmp79 = fmul float 0x4014666660000000, %tmp78  ; <float> [#uses=1]
  %conv80 = fptosi float %tmp79 to i32            ; <i32> [#uses=1]
  store i32 %conv80, i32 addrspace(1)* %arrayidx71
  br label %return

return:                                           ; preds = %entry
  ret void
}

define void @__OpenCL_test_fa1_5_4_kern_kernel(float addrspace(1)* %a0, float addrspace(1)* %a1, float addrspace(1)* %a2, float addrspace(1)* %a3, float addrspace(1)* %a4, i32 addrspace(1)* %b0, i32 addrspace(1)* %b1, i32 addrspace(1)* %b2, i32 addrspace(1)* %b3) nounwind {
entry:
  %a0.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a1.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a2.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a3.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a4.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %b0.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b1.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b2.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b3.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %gtid = alloca i32, align 4                     ; <i32*> [#uses=10]
  %tmp0 = alloca float, align 4                   ; <float*> [#uses=5]
  %tmp1 = alloca float, align 4                   ; <float*> [#uses=5]
  %tmp2 = alloca float, align 4                   ; <float*> [#uses=5]
  %tmp3 = alloca float, align 4                   ; <float*> [#uses=5]
  %tmp4 = alloca float, align 4                   ; <float*> [#uses=5]
  store float addrspace(1)* %a0, float addrspace(1)** %a0.addr
  store float addrspace(1)* %a1, float addrspace(1)** %a1.addr
  store float addrspace(1)* %a2, float addrspace(1)** %a2.addr
  store float addrspace(1)* %a3, float addrspace(1)** %a3.addr
  store float addrspace(1)* %a4, float addrspace(1)** %a4.addr
  store i32 addrspace(1)* %b0, i32 addrspace(1)** %b0.addr
  store i32 addrspace(1)* %b1, i32 addrspace(1)** %b1.addr
  store i32 addrspace(1)* %b2, i32 addrspace(1)** %b2.addr
  store i32 addrspace(1)* %b3, i32 addrspace(1)** %b3.addr
  %call = call i32 @get_global_id(i32 0) nounwind ; <i32> [#uses=1]
  store i32 %call, i32* %gtid
  %tmp = load float addrspace(1)** %a0.addr       ; <float addrspace(1)*> [#uses=1]
  %tmp5 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx = getelementptr float addrspace(1)* %tmp, i32 %tmp5 ; <float addrspace(1)*> [#uses=1]
  %tmp6 = load float addrspace(1)* %arrayidx      ; <float> [#uses=1]
  %tmp7 = fadd float %tmp6, 0x3FB99999A0000000    ; <float> [#uses=1]
  store float %tmp7, float* %tmp0
  %tmp8 = load float addrspace(1)** %a1.addr      ; <float addrspace(1)*> [#uses=1]
  %tmp9 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx10 = getelementptr float addrspace(1)* %tmp8, i32 %tmp9 ; <float addrspace(1)*> [#uses=1]
  %tmp11 = load float addrspace(1)* %arrayidx10   ; <float> [#uses=1]
  %tmp12 = fadd float %tmp11, 0x3FF19999A0000000  ; <float> [#uses=1]
  store float %tmp12, float* %tmp1
  %tmp13 = load float addrspace(1)** %a2.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp14 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx15 = getelementptr float addrspace(1)* %tmp13, i32 %tmp14 ; <float addrspace(1)*> [#uses=1]
  %tmp16 = load float addrspace(1)* %arrayidx15   ; <float> [#uses=1]
  %tmp17 = fadd float %tmp16, 0x4000CCCCC0000000  ; <float> [#uses=1]
  store float %tmp17, float* %tmp2
  %tmp18 = load float addrspace(1)** %a3.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp19 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx20 = getelementptr float addrspace(1)* %tmp18, i32 %tmp19 ; <float addrspace(1)*> [#uses=1]
  %tmp21 = load float addrspace(1)* %arrayidx20   ; <float> [#uses=1]
  %tmp22 = fadd float %tmp21, 0x4008CCCCC0000000  ; <float> [#uses=1]
  store float %tmp22, float* %tmp3
  %tmp23 = load float addrspace(1)** %a4.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp24 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx25 = getelementptr float addrspace(1)* %tmp23, i32 %tmp24 ; <float addrspace(1)*> [#uses=1]
  %tmp26 = load float addrspace(1)* %arrayidx25   ; <float> [#uses=1]
  %tmp27 = fadd float %tmp26, 0x4010666660000000  ; <float> [#uses=1]
  store float %tmp27, float* %tmp4
  %tmp28 = load i32 addrspace(1)** %b0.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp29 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx30 = getelementptr i32 addrspace(1)* %tmp28, i32 %tmp29 ; <i32 addrspace(1)*> [#uses=1]
  %tmp31 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp32 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp33 = fadd float %tmp31, %tmp32              ; <float> [#uses=1]
  %tmp34 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp35 = fadd float %tmp33, %tmp34              ; <float> [#uses=1]
  %tmp36 = load float* %tmp3                      ; <float> [#uses=1]
  %tmp37 = fadd float %tmp35, %tmp36              ; <float> [#uses=1]
  %tmp38 = load float* %tmp4                      ; <float> [#uses=1]
  %tmp39 = fadd float %tmp37, %tmp38              ; <float> [#uses=1]
  %tmp40 = fmul float 0x3FF19999A0000000, %tmp39  ; <float> [#uses=1]
  %conv = fptosi float %tmp40 to i32              ; <i32> [#uses=1]
  store i32 %conv, i32 addrspace(1)* %arrayidx30
  %tmp41 = load i32 addrspace(1)** %b1.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp42 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx43 = getelementptr i32 addrspace(1)* %tmp41, i32 %tmp42 ; <i32 addrspace(1)*> [#uses=1]
  %tmp44 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp45 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp46 = fadd float %tmp44, %tmp45              ; <float> [#uses=1]
  %tmp47 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp48 = fadd float %tmp46, %tmp47              ; <float> [#uses=1]
  %tmp49 = load float* %tmp3                      ; <float> [#uses=1]
  %tmp50 = fadd float %tmp48, %tmp49              ; <float> [#uses=1]
  %tmp51 = load float* %tmp4                      ; <float> [#uses=1]
  %tmp52 = fadd float %tmp50, %tmp51              ; <float> [#uses=1]
  %tmp53 = fmul float 0x4000CCCCC0000000, %tmp52  ; <float> [#uses=1]
  %conv54 = fptosi float %tmp53 to i32            ; <i32> [#uses=1]
  store i32 %conv54, i32 addrspace(1)* %arrayidx43
  %tmp55 = load i32 addrspace(1)** %b2.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp56 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx57 = getelementptr i32 addrspace(1)* %tmp55, i32 %tmp56 ; <i32 addrspace(1)*> [#uses=1]
  %tmp58 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp59 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp60 = fadd float %tmp58, %tmp59              ; <float> [#uses=1]
  %tmp61 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp62 = fadd float %tmp60, %tmp61              ; <float> [#uses=1]
  %tmp63 = load float* %tmp3                      ; <float> [#uses=1]
  %tmp64 = fadd float %tmp62, %tmp63              ; <float> [#uses=1]
  %tmp65 = load float* %tmp4                      ; <float> [#uses=1]
  %tmp66 = fadd float %tmp64, %tmp65              ; <float> [#uses=1]
  %tmp67 = fmul float 0x4008CCCCC0000000, %tmp66  ; <float> [#uses=1]
  %conv68 = fptosi float %tmp67 to i32            ; <i32> [#uses=1]
  store i32 %conv68, i32 addrspace(1)* %arrayidx57
  %tmp69 = load i32 addrspace(1)** %b3.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp70 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx71 = getelementptr i32 addrspace(1)* %tmp69, i32 %tmp70 ; <i32 addrspace(1)*> [#uses=1]
  %tmp72 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp73 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp74 = fadd float %tmp72, %tmp73              ; <float> [#uses=1]
  %tmp75 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp76 = fadd float %tmp74, %tmp75              ; <float> [#uses=1]
  %tmp77 = load float* %tmp3                      ; <float> [#uses=1]
  %tmp78 = fadd float %tmp76, %tmp77              ; <float> [#uses=1]
  %tmp79 = load float* %tmp4                      ; <float> [#uses=1]
  %tmp80 = fadd float %tmp78, %tmp79              ; <float> [#uses=1]
  %tmp81 = fmul float 0x4010666660000000, %tmp80  ; <float> [#uses=1]
  %conv82 = fptosi float %tmp81 to i32            ; <i32> [#uses=1]
  store i32 %conv82, i32 addrspace(1)* %arrayidx71
  br label %return

return:                                           ; preds = %entry
  ret void
}

define void @__OpenCL_test_fa1_6_3_kern_kernel(float addrspace(1)* %a0, float addrspace(1)* %a1, float addrspace(1)* %a2, float addrspace(1)* %a3, float addrspace(1)* %a4, float addrspace(1)* %a5, i32 addrspace(1)* %b0, i32 addrspace(1)* %b1, i32 addrspace(1)* %b2) nounwind {
entry:
  %a0.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a1.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a2.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a3.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a4.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a5.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %b0.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b1.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b2.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %gtid = alloca i32, align 4                     ; <i32*> [#uses=10]
  %tmp0 = alloca float, align 4                   ; <float*> [#uses=4]
  %tmp1 = alloca float, align 4                   ; <float*> [#uses=4]
  %tmp2 = alloca float, align 4                   ; <float*> [#uses=4]
  %tmp3 = alloca float, align 4                   ; <float*> [#uses=4]
  %tmp4 = alloca float, align 4                   ; <float*> [#uses=4]
  %tmp5 = alloca float, align 4                   ; <float*> [#uses=4]
  store float addrspace(1)* %a0, float addrspace(1)** %a0.addr
  store float addrspace(1)* %a1, float addrspace(1)** %a1.addr
  store float addrspace(1)* %a2, float addrspace(1)** %a2.addr
  store float addrspace(1)* %a3, float addrspace(1)** %a3.addr
  store float addrspace(1)* %a4, float addrspace(1)** %a4.addr
  store float addrspace(1)* %a5, float addrspace(1)** %a5.addr
  store i32 addrspace(1)* %b0, i32 addrspace(1)** %b0.addr
  store i32 addrspace(1)* %b1, i32 addrspace(1)** %b1.addr
  store i32 addrspace(1)* %b2, i32 addrspace(1)** %b2.addr
  %call = call i32 @get_global_id(i32 0) nounwind ; <i32> [#uses=1]
  store i32 %call, i32* %gtid
  %tmp = load float addrspace(1)** %a0.addr       ; <float addrspace(1)*> [#uses=1]
  %tmp6 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx = getelementptr float addrspace(1)* %tmp, i32 %tmp6 ; <float addrspace(1)*> [#uses=1]
  %tmp7 = load float addrspace(1)* %arrayidx      ; <float> [#uses=1]
  %tmp8 = fadd float %tmp7, 0x3FB99999A0000000    ; <float> [#uses=1]
  store float %tmp8, float* %tmp0
  %tmp9 = load float addrspace(1)** %a1.addr      ; <float addrspace(1)*> [#uses=1]
  %tmp10 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx11 = getelementptr float addrspace(1)* %tmp9, i32 %tmp10 ; <float addrspace(1)*> [#uses=1]
  %tmp12 = load float addrspace(1)* %arrayidx11   ; <float> [#uses=1]
  %tmp13 = fadd float %tmp12, 0x3FF19999A0000000  ; <float> [#uses=1]
  store float %tmp13, float* %tmp1
  %tmp14 = load float addrspace(1)** %a2.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp15 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx16 = getelementptr float addrspace(1)* %tmp14, i32 %tmp15 ; <float addrspace(1)*> [#uses=1]
  %tmp17 = load float addrspace(1)* %arrayidx16   ; <float> [#uses=1]
  %tmp18 = fadd float %tmp17, 0x4000CCCCC0000000  ; <float> [#uses=1]
  store float %tmp18, float* %tmp2
  %tmp19 = load float addrspace(1)** %a3.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp20 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx21 = getelementptr float addrspace(1)* %tmp19, i32 %tmp20 ; <float addrspace(1)*> [#uses=1]
  %tmp22 = load float addrspace(1)* %arrayidx21   ; <float> [#uses=1]
  %tmp23 = fadd float %tmp22, 0x4008CCCCC0000000  ; <float> [#uses=1]
  store float %tmp23, float* %tmp3
  %tmp24 = load float addrspace(1)** %a4.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp25 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx26 = getelementptr float addrspace(1)* %tmp24, i32 %tmp25 ; <float addrspace(1)*> [#uses=1]
  %tmp27 = load float addrspace(1)* %arrayidx26   ; <float> [#uses=1]
  %tmp28 = fadd float %tmp27, 0x4010666660000000  ; <float> [#uses=1]
  store float %tmp28, float* %tmp4
  %tmp29 = load float addrspace(1)** %a5.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp30 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx31 = getelementptr float addrspace(1)* %tmp29, i32 %tmp30 ; <float addrspace(1)*> [#uses=1]
  %tmp32 = load float addrspace(1)* %arrayidx31   ; <float> [#uses=1]
  %tmp33 = fadd float %tmp32, 0x4014666660000000  ; <float> [#uses=1]
  store float %tmp33, float* %tmp5
  %tmp34 = load i32 addrspace(1)** %b0.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp35 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx36 = getelementptr i32 addrspace(1)* %tmp34, i32 %tmp35 ; <i32 addrspace(1)*> [#uses=1]
  %tmp37 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp38 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp39 = fadd float %tmp37, %tmp38              ; <float> [#uses=1]
  %tmp40 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp41 = fadd float %tmp39, %tmp40              ; <float> [#uses=1]
  %tmp42 = load float* %tmp3                      ; <float> [#uses=1]
  %tmp43 = fadd float %tmp41, %tmp42              ; <float> [#uses=1]
  %tmp44 = load float* %tmp4                      ; <float> [#uses=1]
  %tmp45 = fadd float %tmp43, %tmp44              ; <float> [#uses=1]
  %tmp46 = load float* %tmp5                      ; <float> [#uses=1]
  %tmp47 = fadd float %tmp45, %tmp46              ; <float> [#uses=1]
  %tmp48 = fmul float 0x3FF19999A0000000, %tmp47  ; <float> [#uses=1]
  %conv = fptosi float %tmp48 to i32              ; <i32> [#uses=1]
  store i32 %conv, i32 addrspace(1)* %arrayidx36
  %tmp49 = load i32 addrspace(1)** %b1.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp50 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx51 = getelementptr i32 addrspace(1)* %tmp49, i32 %tmp50 ; <i32 addrspace(1)*> [#uses=1]
  %tmp52 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp53 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp54 = fadd float %tmp52, %tmp53              ; <float> [#uses=1]
  %tmp55 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp56 = fadd float %tmp54, %tmp55              ; <float> [#uses=1]
  %tmp57 = load float* %tmp3                      ; <float> [#uses=1]
  %tmp58 = fadd float %tmp56, %tmp57              ; <float> [#uses=1]
  %tmp59 = load float* %tmp4                      ; <float> [#uses=1]
  %tmp60 = fadd float %tmp58, %tmp59              ; <float> [#uses=1]
  %tmp61 = load float* %tmp5                      ; <float> [#uses=1]
  %tmp62 = fadd float %tmp60, %tmp61              ; <float> [#uses=1]
  %tmp63 = fmul float 0x4000CCCCC0000000, %tmp62  ; <float> [#uses=1]
  %conv64 = fptosi float %tmp63 to i32            ; <i32> [#uses=1]
  store i32 %conv64, i32 addrspace(1)* %arrayidx51
  %tmp65 = load i32 addrspace(1)** %b2.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp66 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx67 = getelementptr i32 addrspace(1)* %tmp65, i32 %tmp66 ; <i32 addrspace(1)*> [#uses=1]
  %tmp68 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp69 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp70 = fadd float %tmp68, %tmp69              ; <float> [#uses=1]
  %tmp71 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp72 = fadd float %tmp70, %tmp71              ; <float> [#uses=1]
  %tmp73 = load float* %tmp3                      ; <float> [#uses=1]
  %tmp74 = fadd float %tmp72, %tmp73              ; <float> [#uses=1]
  %tmp75 = load float* %tmp4                      ; <float> [#uses=1]
  %tmp76 = fadd float %tmp74, %tmp75              ; <float> [#uses=1]
  %tmp77 = load float* %tmp5                      ; <float> [#uses=1]
  %tmp78 = fadd float %tmp76, %tmp77              ; <float> [#uses=1]
  %tmp79 = fmul float 0x4008CCCCC0000000, %tmp78  ; <float> [#uses=1]
  %conv80 = fptosi float %tmp79 to i32            ; <i32> [#uses=1]
  store i32 %conv80, i32 addrspace(1)* %arrayidx67
  br label %return

return:                                           ; preds = %entry
  ret void
}

define void @__OpenCL_test_fa1_7_2_kern_kernel(float addrspace(1)* %a0, float addrspace(1)* %a1, float addrspace(1)* %a2, float addrspace(1)* %a3, float addrspace(1)* %a4, float addrspace(1)* %a5, float addrspace(1)* %a6, i32 addrspace(1)* %b0, i32 addrspace(1)* %b1) nounwind {
entry:
  %a0.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a1.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a2.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a3.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a4.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a5.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a6.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %b0.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %b1.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %gtid = alloca i32, align 4                     ; <i32*> [#uses=10]
  %tmp0 = alloca float, align 4                   ; <float*> [#uses=3]
  %tmp1 = alloca float, align 4                   ; <float*> [#uses=3]
  %tmp2 = alloca float, align 4                   ; <float*> [#uses=3]
  %tmp3 = alloca float, align 4                   ; <float*> [#uses=3]
  %tmp4 = alloca float, align 4                   ; <float*> [#uses=3]
  %tmp5 = alloca float, align 4                   ; <float*> [#uses=3]
  %tmp6 = alloca float, align 4                   ; <float*> [#uses=3]
  store float addrspace(1)* %a0, float addrspace(1)** %a0.addr
  store float addrspace(1)* %a1, float addrspace(1)** %a1.addr
  store float addrspace(1)* %a2, float addrspace(1)** %a2.addr
  store float addrspace(1)* %a3, float addrspace(1)** %a3.addr
  store float addrspace(1)* %a4, float addrspace(1)** %a4.addr
  store float addrspace(1)* %a5, float addrspace(1)** %a5.addr
  store float addrspace(1)* %a6, float addrspace(1)** %a6.addr
  store i32 addrspace(1)* %b0, i32 addrspace(1)** %b0.addr
  store i32 addrspace(1)* %b1, i32 addrspace(1)** %b1.addr
  %call = call i32 @get_global_id(i32 0) nounwind ; <i32> [#uses=1]
  store i32 %call, i32* %gtid
  %tmp = load float addrspace(1)** %a0.addr       ; <float addrspace(1)*> [#uses=1]
  %tmp7 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx = getelementptr float addrspace(1)* %tmp, i32 %tmp7 ; <float addrspace(1)*> [#uses=1]
  %tmp8 = load float addrspace(1)* %arrayidx      ; <float> [#uses=1]
  %tmp9 = fadd float %tmp8, 0x3FB99999A0000000    ; <float> [#uses=1]
  store float %tmp9, float* %tmp0
  %tmp10 = load float addrspace(1)** %a1.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp11 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx12 = getelementptr float addrspace(1)* %tmp10, i32 %tmp11 ; <float addrspace(1)*> [#uses=1]
  %tmp13 = load float addrspace(1)* %arrayidx12   ; <float> [#uses=1]
  %tmp14 = fadd float %tmp13, 0x3FF19999A0000000  ; <float> [#uses=1]
  store float %tmp14, float* %tmp1
  %tmp15 = load float addrspace(1)** %a2.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp16 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx17 = getelementptr float addrspace(1)* %tmp15, i32 %tmp16 ; <float addrspace(1)*> [#uses=1]
  %tmp18 = load float addrspace(1)* %arrayidx17   ; <float> [#uses=1]
  %tmp19 = fadd float %tmp18, 0x4000CCCCC0000000  ; <float> [#uses=1]
  store float %tmp19, float* %tmp2
  %tmp20 = load float addrspace(1)** %a3.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp21 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx22 = getelementptr float addrspace(1)* %tmp20, i32 %tmp21 ; <float addrspace(1)*> [#uses=1]
  %tmp23 = load float addrspace(1)* %arrayidx22   ; <float> [#uses=1]
  %tmp24 = fadd float %tmp23, 0x4008CCCCC0000000  ; <float> [#uses=1]
  store float %tmp24, float* %tmp3
  %tmp25 = load float addrspace(1)** %a4.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp26 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx27 = getelementptr float addrspace(1)* %tmp25, i32 %tmp26 ; <float addrspace(1)*> [#uses=1]
  %tmp28 = load float addrspace(1)* %arrayidx27   ; <float> [#uses=1]
  %tmp29 = fadd float %tmp28, 0x4010666660000000  ; <float> [#uses=1]
  store float %tmp29, float* %tmp4
  %tmp30 = load float addrspace(1)** %a5.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp31 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx32 = getelementptr float addrspace(1)* %tmp30, i32 %tmp31 ; <float addrspace(1)*> [#uses=1]
  %tmp33 = load float addrspace(1)* %arrayidx32   ; <float> [#uses=1]
  %tmp34 = fadd float %tmp33, 0x4014666660000000  ; <float> [#uses=1]
  store float %tmp34, float* %tmp5
  %tmp35 = load float addrspace(1)** %a6.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp36 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx37 = getelementptr float addrspace(1)* %tmp35, i32 %tmp36 ; <float addrspace(1)*> [#uses=1]
  %tmp38 = load float addrspace(1)* %arrayidx37   ; <float> [#uses=1]
  %tmp39 = fadd float %tmp38, 0x4018666660000000  ; <float> [#uses=1]
  store float %tmp39, float* %tmp6
  %tmp40 = load i32 addrspace(1)** %b0.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp41 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx42 = getelementptr i32 addrspace(1)* %tmp40, i32 %tmp41 ; <i32 addrspace(1)*> [#uses=1]
  %tmp43 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp44 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp45 = fadd float %tmp43, %tmp44              ; <float> [#uses=1]
  %tmp46 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp47 = fadd float %tmp45, %tmp46              ; <float> [#uses=1]
  %tmp48 = load float* %tmp3                      ; <float> [#uses=1]
  %tmp49 = fadd float %tmp47, %tmp48              ; <float> [#uses=1]
  %tmp50 = load float* %tmp4                      ; <float> [#uses=1]
  %tmp51 = fadd float %tmp49, %tmp50              ; <float> [#uses=1]
  %tmp52 = load float* %tmp5                      ; <float> [#uses=1]
  %tmp53 = fadd float %tmp51, %tmp52              ; <float> [#uses=1]
  %tmp54 = load float* %tmp6                      ; <float> [#uses=1]
  %tmp55 = fadd float %tmp53, %tmp54              ; <float> [#uses=1]
  %tmp56 = fmul float 0x3FF19999A0000000, %tmp55  ; <float> [#uses=1]
  %conv = fptosi float %tmp56 to i32              ; <i32> [#uses=1]
  store i32 %conv, i32 addrspace(1)* %arrayidx42
  %tmp57 = load i32 addrspace(1)** %b1.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp58 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx59 = getelementptr i32 addrspace(1)* %tmp57, i32 %tmp58 ; <i32 addrspace(1)*> [#uses=1]
  %tmp60 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp61 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp62 = fadd float %tmp60, %tmp61              ; <float> [#uses=1]
  %tmp63 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp64 = fadd float %tmp62, %tmp63              ; <float> [#uses=1]
  %tmp65 = load float* %tmp3                      ; <float> [#uses=1]
  %tmp66 = fadd float %tmp64, %tmp65              ; <float> [#uses=1]
  %tmp67 = load float* %tmp4                      ; <float> [#uses=1]
  %tmp68 = fadd float %tmp66, %tmp67              ; <float> [#uses=1]
  %tmp69 = load float* %tmp5                      ; <float> [#uses=1]
  %tmp70 = fadd float %tmp68, %tmp69              ; <float> [#uses=1]
  %tmp71 = load float* %tmp6                      ; <float> [#uses=1]
  %tmp72 = fadd float %tmp70, %tmp71              ; <float> [#uses=1]
  %tmp73 = fmul float 0x4000CCCCC0000000, %tmp72  ; <float> [#uses=1]
  %conv74 = fptosi float %tmp73 to i32            ; <i32> [#uses=1]
  store i32 %conv74, i32 addrspace(1)* %arrayidx59
  br label %return

return:                                           ; preds = %entry
  ret void
}

define void @__OpenCL_test_fa1_8_1_kern_kernel(float addrspace(1)* %a0, float addrspace(1)* %a1, float addrspace(1)* %a2, float addrspace(1)* %a3, float addrspace(1)* %a4, float addrspace(1)* %a5, float addrspace(1)* %a6, float addrspace(1)* %a7, i32 addrspace(1)* %b0) nounwind {
entry:
  %a0.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a1.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a2.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a3.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a4.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a5.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a6.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %a7.addr = alloca float addrspace(1)*, align 4  ; <float addrspace(1)**> [#uses=2]
  %b0.addr = alloca i32 addrspace(1)*, align 4    ; <i32 addrspace(1)**> [#uses=2]
  %gtid = alloca i32, align 4                     ; <i32*> [#uses=10]
  %tmp0 = alloca float, align 4                   ; <float*> [#uses=2]
  %tmp1 = alloca float, align 4                   ; <float*> [#uses=2]
  %tmp2 = alloca float, align 4                   ; <float*> [#uses=2]
  %tmp3 = alloca float, align 4                   ; <float*> [#uses=2]
  %tmp4 = alloca float, align 4                   ; <float*> [#uses=2]
  %tmp5 = alloca float, align 4                   ; <float*> [#uses=2]
  %tmp6 = alloca float, align 4                   ; <float*> [#uses=2]
  %tmp7 = alloca float, align 4                   ; <float*> [#uses=2]
  store float addrspace(1)* %a0, float addrspace(1)** %a0.addr
  store float addrspace(1)* %a1, float addrspace(1)** %a1.addr
  store float addrspace(1)* %a2, float addrspace(1)** %a2.addr
  store float addrspace(1)* %a3, float addrspace(1)** %a3.addr
  store float addrspace(1)* %a4, float addrspace(1)** %a4.addr
  store float addrspace(1)* %a5, float addrspace(1)** %a5.addr
  store float addrspace(1)* %a6, float addrspace(1)** %a6.addr
  store float addrspace(1)* %a7, float addrspace(1)** %a7.addr
  store i32 addrspace(1)* %b0, i32 addrspace(1)** %b0.addr
  %call = call i32 @get_global_id(i32 0) nounwind ; <i32> [#uses=1]
  store i32 %call, i32* %gtid
  %tmp = load float addrspace(1)** %a0.addr       ; <float addrspace(1)*> [#uses=1]
  %tmp8 = load i32* %gtid                         ; <i32> [#uses=1]
  %arrayidx = getelementptr float addrspace(1)* %tmp, i32 %tmp8 ; <float addrspace(1)*> [#uses=1]
  %tmp9 = load float addrspace(1)* %arrayidx      ; <float> [#uses=1]
  %tmp10 = fadd float %tmp9, 0x3FB99999A0000000   ; <float> [#uses=1]
  store float %tmp10, float* %tmp0
  %tmp11 = load float addrspace(1)** %a1.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp12 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx13 = getelementptr float addrspace(1)* %tmp11, i32 %tmp12 ; <float addrspace(1)*> [#uses=1]
  %tmp14 = load float addrspace(1)* %arrayidx13   ; <float> [#uses=1]
  %tmp15 = fadd float %tmp14, 0x3FF19999A0000000  ; <float> [#uses=1]
  store float %tmp15, float* %tmp1
  %tmp16 = load float addrspace(1)** %a2.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp17 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx18 = getelementptr float addrspace(1)* %tmp16, i32 %tmp17 ; <float addrspace(1)*> [#uses=1]
  %tmp19 = load float addrspace(1)* %arrayidx18   ; <float> [#uses=1]
  %tmp20 = fadd float %tmp19, 0x4000CCCCC0000000  ; <float> [#uses=1]
  store float %tmp20, float* %tmp2
  %tmp21 = load float addrspace(1)** %a3.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp22 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx23 = getelementptr float addrspace(1)* %tmp21, i32 %tmp22 ; <float addrspace(1)*> [#uses=1]
  %tmp24 = load float addrspace(1)* %arrayidx23   ; <float> [#uses=1]
  %tmp25 = fadd float %tmp24, 0x4008CCCCC0000000  ; <float> [#uses=1]
  store float %tmp25, float* %tmp3
  %tmp26 = load float addrspace(1)** %a4.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp27 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx28 = getelementptr float addrspace(1)* %tmp26, i32 %tmp27 ; <float addrspace(1)*> [#uses=1]
  %tmp29 = load float addrspace(1)* %arrayidx28   ; <float> [#uses=1]
  %tmp30 = fadd float %tmp29, 0x4010666660000000  ; <float> [#uses=1]
  store float %tmp30, float* %tmp4
  %tmp31 = load float addrspace(1)** %a5.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp32 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx33 = getelementptr float addrspace(1)* %tmp31, i32 %tmp32 ; <float addrspace(1)*> [#uses=1]
  %tmp34 = load float addrspace(1)* %arrayidx33   ; <float> [#uses=1]
  %tmp35 = fadd float %tmp34, 0x4014666660000000  ; <float> [#uses=1]
  store float %tmp35, float* %tmp5
  %tmp36 = load float addrspace(1)** %a6.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp37 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx38 = getelementptr float addrspace(1)* %tmp36, i32 %tmp37 ; <float addrspace(1)*> [#uses=1]
  %tmp39 = load float addrspace(1)* %arrayidx38   ; <float> [#uses=1]
  %tmp40 = fadd float %tmp39, 0x4018666660000000  ; <float> [#uses=1]
  store float %tmp40, float* %tmp6
  %tmp41 = load float addrspace(1)** %a7.addr     ; <float addrspace(1)*> [#uses=1]
  %tmp42 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx43 = getelementptr float addrspace(1)* %tmp41, i32 %tmp42 ; <float addrspace(1)*> [#uses=1]
  %tmp44 = load float addrspace(1)* %arrayidx43   ; <float> [#uses=1]
  %tmp45 = fadd float %tmp44, 0x401C666660000000  ; <float> [#uses=1]
  store float %tmp45, float* %tmp7
  %tmp46 = load i32 addrspace(1)** %b0.addr       ; <i32 addrspace(1)*> [#uses=1]
  %tmp47 = load i32* %gtid                        ; <i32> [#uses=1]
  %arrayidx48 = getelementptr i32 addrspace(1)* %tmp46, i32 %tmp47 ; <i32 addrspace(1)*> [#uses=1]
  %tmp49 = load float* %tmp0                      ; <float> [#uses=1]
  %tmp50 = load float* %tmp1                      ; <float> [#uses=1]
  %tmp51 = fadd float %tmp49, %tmp50              ; <float> [#uses=1]
  %tmp52 = load float* %tmp2                      ; <float> [#uses=1]
  %tmp53 = fadd float %tmp51, %tmp52              ; <float> [#uses=1]
  %tmp54 = load float* %tmp3                      ; <float> [#uses=1]
  %tmp55 = fadd float %tmp53, %tmp54              ; <float> [#uses=1]
  %tmp56 = load float* %tmp4                      ; <float> [#uses=1]
  %tmp57 = fadd float %tmp55, %tmp56              ; <float> [#uses=1]
  %tmp58 = load float* %tmp5                      ; <float> [#uses=1]
  %tmp59 = fadd float %tmp57, %tmp58              ; <float> [#uses=1]
  %tmp60 = load float* %tmp6                      ; <float> [#uses=1]
  %tmp61 = fadd float %tmp59, %tmp60              ; <float> [#uses=1]
  %tmp62 = load float* %tmp7                      ; <float> [#uses=1]
  %tmp63 = fadd float %tmp61, %tmp62              ; <float> [#uses=1]
  %tmp64 = fmul float 0x3FF19999A0000000, %tmp63  ; <float> [#uses=1]
  %conv = fptosi float %tmp64 to i32              ; <i32> [#uses=1]
  store i32 %conv, i32 addrspace(1)* %arrayidx48
  br label %return

return:                                           ; preds = %entry
  ret void
}
