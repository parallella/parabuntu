## Parallella Ubuntu Image Creation 

### 1. Format a blank SD Card

```
sudo gparted
```

* Create a 256 MB FAT32 partition named 'BOOT'
* Create an EXT4 partition named 'rootfs' (ideally larger then 4GB)

### 2. Download Ubuntu distribution

```
wget http://releases.linaro.org/14.07/ubuntu/trusty-images/nano/linaro-trusty-nano-20140727-680.tar.gz
```

### 3. Download firmware files for BOOT partition
```
wget http://downloads.parallella.org/boot/boot-e16-7z020-v01-140528.tgz
```

### 4. Copy files to SD card

```
sudo tar -zxvf linaro-trusty-nano-20140522-661.tar.gz
cd binary
sudo rsync -a --progress ./ /media/aolofsson/rootfs
tar -zxvf boot-e16-7z020-v01-140528.tgz -C /media/aolofsson/BOOT
```

### 5. Configure ethernet configuraiton on sd-card from host computer

/media/$USER/rootfs/etc/network/interfaces:
```
auto lo
iface lo inet loopback

auto eth0
iface eth0 inet dhcp
```

### 6. Disable the auto-generation of rule for interface names

```
sudo mv /media/$USER/rootfs/lib/udev/rules.d/75-persistent-net-generator.rules /media/$USER/rootfs/lib/udev/rules.d/75-persistent-net-generator.rules.bak
```

### 7. Enable devtmpfs and make SD card accessible from Parallella
```
cd /media/$USER/rootfs/dev
sudo mknod -m 660 mmcblk0 b 179 0
sudo mknod -m 660 mmcblk0p1 b 179 1
sudo mknod -m 660 mmcblk0p2 b 179 2
```

### 8. Unmount uSD card from host computer

```
sync
umount /media/aolofsson/rootfs/
umount /media/aolofsson/BOOT
```

### 9. First boot (with screen/keyboard/mouse or serial port attached)

* User=linaro
* Password=linaro

### 10. Install ssh

```
sudo apt-get update
sudo apt-get install ssh
ifconfig
```

### 11. SSH into Parallella from 2nd computer

```
ssh linaro@<parallella-ip-address>
```

### 12. Fix issues with Ubuntu

Work around ping permision limitation:
```
sudo chmod u+s `which ping`
``` 

Ubuntu 14.04 packaging bug:
```
sudo emacs /var/lib/dpkg/info/libpam-systemd:armhf.postinst
#comment out the following line
#invoke-rc.d systemd-logind start || exit $?"
```

Slow boot time without ethernet cable:
```
sudo emacs /etc/init/failsafe.conf
#Change sleep values to 4 seconds (when there is no network detected)
```

### 13. Sync the file system and power off the board
```
sync
```
Remove power.

### 14. Create minimal headless Parallella backup image (from host)

Insert micro-sd card into external host
```
sudo dd if=/dev/mmcblk0 of=<headless.img> bs=4M
```

### 15. Reboot the Parallella (ssh into computer or use as regular desktop)


### 16. Install a windows manager
```
sudo apt-get install lxde 
sudo apt-get install xinit
```

### 18. Install other essential Packages

```
### "Must haves"
sudo apt-get install less tcsh emacs nano ftp synaptic tkcvs wish screen putty
sudo apt-get install feh lsb-release
sudo apt-get install fake-hwclock ntp

### Compiling/Building
sudo apt-get install build-essential git curl m4 flex bison gawk

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

### 19.  Install Erlang


### 20. Getting list of all packages installed
```
dpkg --get-selections > my.packages
```

### 21. Purging bad packages
```
sudo apt-get purge xscreensaver pulseaudio
```

### 22. Create xorg.conf file
```
sudo emacs /etc/X11/xorg.conf
```

xorg.conf:
```
Section "Device"
  Identifier "Card0"
  Driver "modesetting"
  Option "ShadowFB" "True"
  Option "SWCursor" "True"
  Option "HWCursor" "False"
EndSection
Section "Screen"
  Identifier "Screen0"
  Device "Card0"
  SubSection "Display"
#---- Uncomment your preferred mode ----
    #Modes "1920x1200"
    #Modes "1920x1080"
    #Modes "1280x720"
    #Modes "640x480"
  EndSubSection
EndSection
```


### 23. Create ~/.asoundrc config file

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

### 24. Fix GCONF permission
```
sudo chown -R linaro:linaro ~/.gconf
```

### 24. Trying to solve firefox instability problem

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

### 25. Fix annoying Ubuntu shell defaults

```
#Replace dash default shell with bash
sudo ln -sTf /bin/bash /bin/sh
##Edit password file and replace bash with tcsh
sudo emacs /etc/passwd
```

Edit /etc/apt/sources.list:
```
deb http://ports.ubuntu.com/ubuntu-ports/ trusty-updates main universe
deb-src http://ports.ubuntu.com/ubuntu-ports/ trusty-updates main universe
deb http://packages.erlang-solutions.com/ubuntu trusty contrib
```

### 26. Customizing the ~/.cshrc

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

### 27. Installing Epiphany SDK
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
Initialize the chip at boot, in `/etc/rc.local` add the following lines before `exit 0`:
```
export EPIPHANY_HOME=/opt/adapteva/esdk
export EPIPHANY_HDF=$EPIPHANY_HOME/bsps/current/platform.hdf
export LD_LIBRARY_PATH=$EPIPHANY_HOME/tools/host/lib
export PATH=$EPIPHANY_HOME/tools/host/bin:$EPIPHANY_HOME/tools/e-gnu/bin:$PATH
e-reset
```

### 28. Setup COPRTHR

```    
###Libelf prerequisite
wget www.mr511.de/software/libelf-0.8.13.tar.gz
tar -zxvf libelf-0.8.13.tar.gz
cd libelf-0.8.13
./configure
sudo make install
cd ../

###Libevent prerequisite
wget github.com/downloads/libevent/libevent/libevent-2.0.18-stable.tar.gz
tar -zxvf libevent-2.0.18-stable.tar.g
cd libevent-2.0.18-stable
./configure
sudo make install
cd ../

###Libconfig prerequisite
wget www.hyperrealm.com/libconfig/libconfig-1.4.8.tar.gz
tar -zxvf libconfig-1.4.8.tar.gz
cd libconfig-1.4.8
./configure
sudo make install
cd ../

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

### 29. MPI Installation from source
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

### 30. Backing up the complete file system
From Parallella:
```
sync
```
From regular computer:
```
sudo dd if=/dev/mmcblk0 of=my_backup.img bs=4M
```

### 31. Burning another card
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

