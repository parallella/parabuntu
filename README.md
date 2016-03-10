# Parallella Image scripts

WORK IN PROGRESS  
THINGS ARE BROKEN  

## TODO

- Install modules to rootfs
- Install headers to rootfs
- TEST

## Flow

- Build bitstreams and place in fpga_bitfiles/  

### Optional

```sh
export PARALLELLA_LINUX=/path/to/parallella-linux
```

### Now do

```sh
./bootfs-and-kernel.sh
./rootfs.sh
./image.sh out/parallella_e16_headless_gpiose_7010_bootfs.tar.gz parallella_e16_headless_gpiose_7010.img
./image.sh out/parallella_e16_headless_gpiose_7020_bootfs.tar.gz parallella_e16_headless_gpiose_7020.img
```
