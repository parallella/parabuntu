# Parallella Image scripts

## TODO

- TEST
- ??? Add bitstream scripts to flow

## Requirements

The scripts require qemu-arm-static and binfmt being set up properly.

```sh
sudo apt-get update
sudo apt-get install qemu binfmt-support qemu binfmt-support qemu-user-static
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


