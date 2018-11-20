# Parallella Image scripts

## TODO

- TEST
- ??? Add bitstream scripts to flow

## Requirements

The scripts require qemu-arm-static and binfmt being set up properly.

```sh
sudo apt-get update
sudo apt-get install qemu binfmt-support qemu binfmt-support qemu-user-static
sudo apt-get install flex bison zerofree u-boot-tools
```

## Flow

- Build bitstreams and place in fpga_bitfiles/  

### Optional

```sh
export PARALLELLA_LINUX=/path/to/parallella-linux
```

- Build ESDK
- Build COPRTHR (if new release) and place in `overlays/`. Steps described below.

### Now do

```sh
./bootfs-and-kernel.sh
sudo ./rootfs.sh path/to/esdk-tarball.tar.gz
sudo ./image.sh out/parallella_e16_headless_gpiose_7010_bootfs.tar.gz parallella_e16_headless_gpiose_7010.img
sudo ./image.sh out/parallella_e16_headless_gpiose_7020_bootfs.tar.gz parallella_e16_headless_gpiose_7020.img
```

---

## Building coprthr

This step needs to be done on a Parallella board.

```
git clone https://github.com/parallella/coprthr --branch esdk-2016.3
cd coprthr
./configure --enable-epiphany
make
sudo make install
```

### Copy these files/directories to overlay

- /etc/ocl.conf
- /etc/OpenCL/
- /var/clproc (permission 1777)
- /usr/local/browndeer

## ESDK 
[adapteva/epiphany-sdk
](https://github.com/adapteva/epiphany-sdk/releases)

## Cross Compiler Toolchain
[GCC 6](https://releases.linaro.org/components/toolchain/binaries/latest-6/)

Set PATH for Toolchain: 

    export PATH=[**THE TOOLCHAIN PATH ON YOUR PC**]gcc-linaro-6.4.1-2018.05-x86_64_arm-linux-gnueabihf/bin:$PATH
    
GCC 7 works for generating kernel uImage, but it doesn't work for building tools/perf. Why we need tools/perf??
