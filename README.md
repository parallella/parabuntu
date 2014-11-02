# Parallella Ubuntu Image Creation 

**TODO: We need to remove generated SSH host certificates after we are done**

This is work in progress. The goal is to automate as much as possible. 


### 1. Clone the repository
[TODO: Move over to official parallella github eventually]  
```
git clone git@github.com/olajep/parallella-ubuntu workspace --branch 14.10-wip-dont-pull
export WORKSPACE=$(readlink -e workspace)
cd $WORKSPACE
```

For all commands issued on PC it is assumed that `$WORKSPACE` is the current working directory.


### 2. Format a blank SD Card

```
sudo gparted
```

* Create a 100 MiB FAT32 partition named 'BOOT'
* Create an 3700 MiB EXT4 partition named 'rootfs' (so the image fits in a 4GB SD card)
* Apply changes
* Set 'boot' flag for 'BOOT' partition. (Might not be necessary). 

### 3. Download Ubuntu distribution

```
wget http://releases.linaro.org/14.10/ubuntu/trusty-images/nano/linaro-trusty-nano-20141024-684.tar.gz
```

### [FIXME] 4. Download firmware files for BOOT partition
```
wget http://downloads.parallella.org/boot/TBD
```

### 5. Mount partitions
```
mkdir -p mnt/{boot,rootfs}
sudo mount /dev/mmcblk0p1 mnt/boot
sudo mount /dev/mmcblk0p2 mnt/rootfs
```

### 6. Copy files to SD card

```
sudo tar --strip-components 1 -xvzpf linaro-trusty-nano-20141024-684.tar.gz -C mnt/rootfs/
```

[FIXME]  
```
tar -zxvf boot-e16-7z020-v01-140528.tgz -C mnt/boot
```
### 7. rsync overlay over rootfs
```
sudo rsync --verbose -ap overlay/rootfs/ mnt/rootfs/
```

### 8. Enable devtmpfs and make SD card accessible from Parallella
```
sudo ./scripts/10-create-device-files.sh
```

### 9. Fix file permissions
Currently only ping & ping6 setuid
```
sudo ./scripts/20-fix-permissions.sh
```
[TODO] Do we need to add `/dev/dri` and `/dev/input` ???

### [TODO] 10. Copy kernel modules over
TODO. Might be a good idea to integrate parallella-root-image.git into this...  

### 11. Unmount uSD card from host computer

```
sync
sudo umount mnt/rootfs
sudo umount mnt/boot
```

### [TODO] Boot with QEMU instead 


### 12. First boot (with screen/keyboard/mouse or serial port attached)

* User=linaro
* Password=linaro


### 13. Basic setup

#### Make sure we'll get the latest packages available
```
sudo apt-get update
```

#### Install ssh

```
sudo apt-get install ssh
```

#### Fix time
```
sudo apt-get install fake-hwclock ntp
```

#### Set up mDNS
```
sudo apt-get install avahi-daemon
```

#### Reboot

Reboot so we get sane time.


### 13. Copy package files over to Parallella from 2nd computer
```
scp -r packages-basic.txt packages linaro@linaro-nano.local:~
```

### 14. SSH into Parallella from 2nd computer

```
ssh linaro@linaro-nano.local
```

### 15. Install basic packages
```
sudo apt-get install -y $(cat packages-basic.txt | grep -v "^#" | sed 's,\s\s*,\n,g' | grep -v "^\s*$)
sudo dpkg -i $(ls packages | grep -v -dbg_)
```

### 16. Remove packages
Try to keep the minimal image minimal.

```
rm -rf packages*
```

### 16. Fix annoying Ubuntu shell defaults

```
#Replace dash default shell with bash
echo "dash dash/sh boolean false" | sudo debconf-set-selections
sudo -E DEBIAN_FRONTEND=noninteractive dpkg-reconfigure dash
```

### 17. Sync the file system and power off the board
```
sync
shutdown -h now
```

Remove power.


### 15. Create minimal headless Parallella backup image (from host)

[TODO] Don't we want same rootfs for everything? Easier maintenance. We could just disable X/LXDE autostart as final step in headless. 

Insert micro-sd card into external host
```
sudo dd if=/dev/mmcblk0 of=<headless.img> bs=4M
```

### 16. Reboot the Parallella (ssh into computer or use as regular desktop)

### 17. Install desktop packages


### 17. Install a windows manager
```
sudo apt-get install lxde 
sudo apt-get install xinit
```

### 19. Install other essential Packages

```
### "Must haves"
apt-get install less tcsh emacs nano ftp synaptic tkcvs wish screen putty
sudo apt-get install feh lsb-release
sudo apt-get install fake-hwclock ntp

### Compiling/Building
sudo apt-get install build-essential git curl m4 flex bison gawk pkg-config

### Ubuntu package tools
sudo apt-get install devscripts dpkg-dev

### Networking
sudo apt-get install ethtool iperf ifplugd
sudo apt-get install network-manager

### Linux Tools
sudo apt-get install xutils-dev device-tree-compiler usbutils

### Media
sudo apt-get install firefox 
sudo apt-get install smplayer
sudo apt-get install evince
sudo apt-get install gimp

### Programming
sudo apt-get install octave
sudo apt-get install scratch

### Scientific
sudo apt-get install python-numpy python-scipy python-matplotlib 
sudo apt-get install ipython ipython-notebook python-pandas python-sympy python-nose
sudo apt-get install r-base r-base-dev

### Erlang ###
sudo apt-get install erlang-mini

### Sound
sudo apt-get install gstreamer0.10-alsa alsa-base alsa-utils libasound2-plugins 

### For Demos
sudo apt-get install libdrm-dev libasound2-dev libx11-dev
sudo apt-get install libfluidsynth-dev fluidsynth fluid-soundfont-gm

### Camera
sudo apt-get install camorama guvcview

### Wifi
sudo apt-get install linux-firmware

### Screen sharing
sudo apt-get install tightvncserver
```
```
sudo apt-get install boinc-client boinc-manager
sudo apt-get install libreoffice
sudo apt-get install openvpn
sudo apt-get install synergy
sudo apt-get install vlc
```

### 20.  Install Erlang


### 21. Getting list of all packages installed
```
dpkg --get-selections > my.packages
```

### 22. Purging bad packages
TODO: ISTR I've seen a fix for pulseaudio. It was something with tsched... 
```
sudo apt-get purge xscreensaver pulseaudio
```

### 24. Create ~/.asoundrc config file

Longterm TODO: We shouldn't need to do this  

```
pcm.!default {
 type plug
 slave.pcm "softvol"
}

pcm.softvol {
 type softvol
 slave {
  pcm "dmixer"
 }
 control {
  name "PCM"
  card 0
 }
}

pcm.dmixer {
  type dmix
  ipc_key 1024
  slave {
  pcm "hw:0"
  period_time 0
  period_size 1024
  buffer_size 4096
  rate 48000
 }
 bindings {
  0 0
  1 1
 }
}

ctl.dmixer {
 type hw
 card 0
}
```

### 25. Fix GCONF permission
```
sudo chown -R linaro:linaro ~/.gconf
```

### 26. Trying to solve firefox instability problem

sudo emacs /etc/fstab
```
tmpfs /home/linaro/.cache tmpfs noatime,nodev,nosuid,size=64M 0 0

```
In firefox URL window: (about:config)
     webgl.disabled=true
     webgl.disable0-extensions=true
     layers.use-depracated-textures=false
     browser.cache.disk.enable=false
     mousewheel.acceleration.start=2

Creating Parallella background:
```
sudo emacs /etc/xdg/lxsession/LXDE/autostart
#add @feh --bg-fill /home/linaro/background.png
```

### 28. Customizing the ~/.cshrc

```
setenv HISTSIZE 1000
setenv EDITOR emacs
set history=2000
set savehist=40

setenv LS_COLORS 'no=00:fi=00:di=01;34:ln=01;36:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;35;01:su=37;41:sg=30;43:tw=30;42\
:ow=34;42:st=37;44:ex=01;31:*.tar=01;35:*.tgz=01;35:*.arj=01;35:*.taz=01;35:*.lzh=01;35:*.zip=01;35:*.z=01;35:*.Z=01;35:*.gz=01;35:*.bz2=\
01;35:*.deb=01;35:*.rpm=01;35:*.jar=01;35:*.jpg=01;35:*.jpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;3\
5:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.avi=01;35:*.fli=01;35:*.gl=01;35:*.\
dl=01;35:*.xcf=01;35:*.xwd=01;35:*.flac=01;35:*.mp3=01;35:*.mpc=01;35:*.ogg=01;35:*.wav=01;35:'

alias s         'source'
alias e         'emacs'
alias rm        'rm -i'
alias cp        'cp -i -p'
alias mv        'mv -i'
alias ls        'ls --color -p'
alias ll        'ls -ltr'
alias ps        'ps -e'
alias rsh       'rsh -X'
alias less      'less -X'
```

### 29. [TODO] Fix when we have final. Installing Epiphany SDK
```
sudo apt-get install libmpfr-dev libmpc-dev libgmp3-dev
sudo mkdir -p /opt/adapteva/
wget http://downloads.parallella.org/esdk/esdk.5.13.09.10_linux_armv7l.tgz
sudo tar xzf esdk.5.13.09.10_linux_armv7l.tgz -C /opt/adapteva/
sudo ln -sTf /opt/adapteva/esdk.5.13.09.10 /opt/adapteva/esdk
sudo ln -s /usr/lib/arm-linux-gnueabihf/libmpc.so.3.0.0 /usr/lib/arm-linux-gnueabihf/libmpc.so.2 #HACK!
echo 'setenv EPIPHANY_HOME      /opt/adapteva/esdk' >> ${HOME}/.cshrc
echo 'source ${EPIPHANY_HOME}/setup.csh' >> ${HOME}/.cshrc
echo 'EPIPHANY_HOME=/opt/adapteva/esdk' >> ${HOME}/.bashrc
echo '. ${EPIPHANY_HOME}/setup.sh' >> ${HOME}/.bashrc
```    

### 30. Setup COPRTHR

### Install dependencies
This step is needed *only* if for some reason were unable to install the .deb packages in `packages`


[TODO]: Verify that this works
```
mkdir /var/tmp/builddeb
cd /var/tmp/builddeb
sudo apt-get build-dep libelf libelf-dev libevent libevent-dev libconfig libconfig-dev
sudo apt-get build-dep libelf libelf-dev libevent libevent-dev libconfig libconfig-dev
sudo apt-get --build source libelf libevent libconfig
sudo dpkg -i $(ls *.deb | grep -v "-dbg_")
```
Copy over .deb packages. We can probably use them throughout the Linaro 14.** series without any problems.
```
cd ~
rm -rf /var/tmp/builddeb
```

[TODO: We could put this in overlay]  
###Install parallella opencl package
wget http://www.browndeertechnology.com/code/coprthr-1.6.0-parallella.tgz
tar -zxvf coprthr-1.6.0-parallella.tgz
sudo ./browndeer/scripts/install_coprthr_parallella.sh

### Add paths to .bashrc
echo 'export PATH=/usr/local/browndeer/bin:$PATH' >> ~/.bashrc
echo 'export LD_LIBRARY_PATH=/usr/local/browndeer/lib:/usr/local/lib:$LD_LIBRARY_PATH' >> ~/.bashrc

### Add paths to root .bashrc
sudo su
echo 'export PATH=/usr/local/browndeer/bin:$PATH' >> ~/.bashrc
echo 'export LD_LIBRARY_PATH=/usr/local/browndeer/lib:/usr/local/lib:$LD_LIBRARY_PATH' >> ~/.bashrc

### Add paths to .cshrc
echo 'setenv PATH /usr/local/bin:$PATH' >> ~/.cshrc
echo 'setenv LD_LIBRARY_PATH /usr/local/browndeer/lib:/usr/local/lib:$LD_LIBRARY_PATH' >> ~/.cshrc

```

### 31. MPI Installation from source

[Longterm TODO: There's only 1.6 source packages so install from source for now]

```
wget http://www.open-mpi.org/software/ompi/v1.8/downloads/openmpi-1.8.1.tar.gz
tar -zxvf openmpi-1.8.1.tar.gz
cd openmpi-1.8.1
./configure --prefix=~/usr \
            --enable-mpirun-prefix-by-default \
            --enable-static 
make all
sudo make install
```

### 32. Backing up the complete file system
From Parallella:
```
sync
```

From regular computer:
```
sudo dd if=/dev/mmcblk0 of=my_backup.img bs=4M
```

### 33. Burning another card
Insert a new micro SD card into regular computer

Option#1: Copying the whole image
```
sudo dd bs=64k if=my_backup.img of=/dev/mmcblk0
```

Option#2: Copying the rootfs directory structure to the current directory (works in reverse as well)
```
sudo rsync -a --progress /media/aolofsson/rootfs ./
```

### Known Issues
* Firefox not 100% stable
* No serial port access with default Linux kernel.
* Start wireless with app with 'sudo nm-applet`
* Define a connection with 'sudo nm-connection-editor'-->disable all things ipv6

```
#sudo emacs /etc/NetworkManager/NetworkManger.conf
#comment out line "dns=dnsmasq"
```

### 99. Remove SSH host keys 
* Remove SSH host keys. Will result in SSH regenerates keys on reboot*
```
rm -rf mnt/rootfs/etc/ssh/ssh_host*
```
Verify that this line is present in mnt/rootfs/etc/rc.local
```
test -f /etc/ssh/ssh_host_dsa_key || dpkg-reconfigure openssh-server
```

