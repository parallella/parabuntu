#!/bin/bash

set -e


PARALLELLA_HW_REVISION=${PARALLELLA_HW_REVISION:-master}

CROSS_COMPILE=${CROSS_COMPILE:-arm-linux-gnueabihf-}

CONFIGURATIONS="\
parallella_e16_hdmi_gpiose_7010.bit.bin,zynq-parallella1-hdmi.dtb \
parallella_e16_hdmi_gpiose_7020.bit.bin,zynq-parallella1-hdmi.dtb \
parallella_e16_headless_gpiose_7010.bit.bin,zynq-parallella1-headless.dtb \
parallella_e16_headless_gpiose_7020.bit.bin,zynq-parallella1-headless.dtb \
parallella_e64_hdmi_gpiose_7020.bit.bin,zynq-parallella1-hdmi.dtb \
parallella_e64_headless_gpiose_7020.bit.bin,zynq-parallella1-headless.dtb"

check_toolchain () {
    if ! ( which ${CROSS_COMPILE}gcc \
        && which ${CROSS_COMPILE}as  \
        && which ${CROSS_COMPILE}ld ) ; then
        echo "Could not find cross toolchain"
        exit 1
    fi
}

download_fpga_bitfile () {
    mkdir -p fpga_bitfiles
    base_url=https://raw.githubusercontent.com/parallella/parallella-hw/$PARALLELLA_HW_REVISION/fpga/bitstreams
    #base_url=https://github.com/parallella/parallella-hw/blob/$PARALLELLA_HW_REVISION/fpga/bitstreams
    curl -s $base_url/$1 -o fpga_bitfiles/$1.tmp
    mv fpga_bitfiles/$1.tmp fpga_bitfiles/$1
}

download_fpga_bitfiles () {
    local IFS c

    echo Downloading bit files...
    (for c in $CONFIGURATIONS; do IFS=,; set $c; download_fpga_bitfile $1; done)
}

clone_kernel () {
    git clone https://github.com/parallella/parallella-linux.git
    PARALLELLA_LINUX=$(readlink -e parallella-linux)
}


# TODO
# $1 [in] bootargs
build_kernel () {
    local version jobs kernel_build_log

    version=$(basename $PARALLELLA_LINUX)
    jobs=$(echo $[ 1 + $( nproc || echo 1 ) ] )
    KERNEL_BUILD_DIR=$PWD/build/$version
    kernel_build_log=$PWD/build/$version.log

    mkdir -p $KERNEL_BUILD_DIR
    rm -f $kernel_build_log
    echo "Building kernel..."
    echo kernel: logfile $kernel_build_log
    (
        set -e
        helper () {
            echo kernel: make $2
            make -j $1 \
                O=$KERNEL_BUILD_DIR \
                ARCH=arm \
                CROSS_COMPILE=$CROSS_COMPILE \
                LOADADDR=0x8000 \
                $2 >> $kernel_build_log 2>&1
        }
        cd $PARALLELLA_LINUX
        make distclean
        helper 1 distclean
        helper 1 mrproper
        helper 1 parallella_defconfig
        helper $jobs ""
        helper $jobs modules
        helper 1 uImage
        helper 1 zynq-parallella1-headless.dtb
        helper 1 zynq-parallella1-hdmi.dtb
    ) && echo kernel: build OK

    echo kernel: build FAILED
    exit 1
}


build_boot_filesystem () {
    local bitfile dtb kernel name

    bitfile=$1
    dtb=$2
    kernel=uImage
    name=$(echo $bitfile | sed 's/\.bit\.bin//g')

    echo Building bootfs for $name

    rm -rf stage/$name
    mkdir -p stage/$name/boot

    cp fpga_bitfiles/$bitfile                   stage/$name/boot/parallella.bit.bin
    cp $KERNEL_BUILD_DIR/arch/arm/boot/$kernel  stage/$name/boot/uImage
    cp $KERNEL_BUILD_DIR/arch/arm/boot/dts/$dtb stage/$name/boot/devicetree.dtb

    echo "fpga_bitfile: $bitfile" >> stage/$name/boot/build-bootfs.log
    echo "kernel: $kernel" >> stage/$name/boot/build-bootfs.log
    echo "devicetree: $dtb" >> stage/$name/boot/build-bootfs.log

    (
        cd stage
        rm -f ${name}_bootfs.tar.gz
        tar cfz ${name}_bootfs.tar.gz -C $name .
    )
}

build_boot_filesystems () {
    local IFS c
    (for c in $CONFIGURATIONS; do IFS=,; set $c; build_boot_filesystem $1 $2; done)
    rm -rf out/*
    mkdir -p out
    cp stage/*.tar.gz out/
}

main () {

    # TODO: Exit immediately on any failure

    # TODO: Support command line arguments
    # --clean

    check_toolchain || exit 1

    download_fpga_bitfiles

    if [ "x" != "x$PARALLELLA_LINUX" ]; then
        if ! [ -d "$PARALLELLA_LINUX" ]; then
            echo "\$PARALLELLA_LINUX set but is not a directory."
            exit 1
        else
            echo "Skip downloading parallella-linux"
        fi
    else
        clone_kernel
    fi

    # TODO: Checkout right branch

    build_kernel || exit 1

    build_boot_filesystems
}


main $@



