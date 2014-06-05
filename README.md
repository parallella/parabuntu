## Parallella Ubuntu Image Creation 

### 1. Format a blank SD Card

```
sudo gparted
```

* Create a 256 MB FAT32 partition named 'BOOT'
* Create a 4 GB+ EXT4 partition named 'rootfs'

### 2. Download Ubuntu distribution and BOOT files

```
wget http://releases.linaro.org/14.05/ubuntu/trusty-images/nano/linaro-trusty-nano-20140522-661.tar.gz
wget http://downloads.parallella.org/boot/boot-e16-7z020-v01-140528.tgz
```

### 3. Copy files to SD card

```
sudo tar -zxvf linaro-trusty-nano-20140522-661.tar.gz
cd binary
sudo rsync -a --progress ./ /media/aolofsson/rootfs
tar -zxvf boot-e16-7z020-v01-140528.tgz -C /media/aolofsson/BOOT
```

### 4. Set up network interface (with sd card still inserted)

```
sudo emacs /media/aolofsson/rootfs/etc/network/interfaces
```

interfaces:
```
auto lo
iface lo inet loopback
```

### 5. Enable devtmpfs
```
cd /media/aolofsson/rootfs/dev
sudo su
mknod -m 660 mmcblk0 b 179 0
mknod -m 660 mmcblk0p1 b 179 1
mknod -m 660 mmcblk0p2 b 179 2
```
### 6. Unmount uSD card
```
sudo sync
umount /media/aolofsson/rootfs/
umount /media/aolofsson/BOOT
```

### 7. First boot (with screen/keyboard/mouse attached)

* User=linaro
* Password=linaro

```
su linaro
sudo apt-get update
```

### 8. Install a windows manager
```
sudo apt-get install lxde
sudo apt-get install xfce4
sudo apt-get install xserver-xorg-video-modesetting
```

### 9. Enable ssh
```
sudo apt-get update
sudo apt-get install openssh-server
```

### 10. SSH into Parallella from 2nd computer
```
ssh linaro@<lan-ip-address>
```

### 11. Temporary edits

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

Slow boot time (timeout) without ethernet cable:
```
sudo emacs /etc/init/failsafe.conf
#Change sleep values to 4 seconds (in case no eth cable inserted)
```

DNS not working
```
sudo emacs /etc/NetworkManager/NetworkManger.conf
#comment out line "dns=dnsmasq"
```

Firefox stability issue(not solved!):
```
In firefox URL window: (about:config)
     webgl.disabled=true
     webgl.disable0-extensions=true
     layers.use-depracated-textures=false
     browser.cache.disk.enable=false
     mousewheel.acceleration.start=2
```

Creating Parallella background:
```
sudo emacs /etc/xdg/lxsession/LXDE/autostart
#add @feh --bg-fill /home/linaro/background.png
```

### 12. Essential Packages

```
### "Must haves"
sudo apt-get install less tcsh emacs vim ftp wget synaptic tkcvs
sudo apt-get install fake-hwclock unzip feh lsb-release

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
sudo apt-get install r-base

### Sound
sudo apt-get install xfce4-mixer gstreamer0.10-alsa
sudo apt-get install alsa-base alsa-utils libasound2-plugins 

### For Demos
sudo apt-get install libdrm-dev libasound2-dev libx11-dev
sudo apt-get install libfluidsynth-dev fluidsynth fluid-soundfont-gm

### Camera
sudo apt-get install camorama

### Wifi
sudo apt-get install linux-firmware

### Screen sharing
sudo apt-get install tightvncserver
```

### 13. Getting list of all packages installed
```
dpkg --get-selections > my.packages
```

### 14.  Recommended Packages (not in default)
```
sudo aptitude install boinc-client boinc-manager
sudo apt-get install libreoffice
sudo apt-get install openvpn
sudo apt-get install synergy
sudo apt-get install vlc
```

### 15. Purging bad packages
```
sudo apt-get purge chromium-browser xscreensaver
```

### 16. Create xorg.conf file
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


### 17. Create ~/.asoundrc config file

```
pcm.!default {
 type rate
 slave {
  pcm "hw:0"
  rate 48000
 }
 converter "samplerate"
}
```

### 18. Fix GCONF permission
```
sudo chown -R linaro:linaro ~/.gconf
```

### 19. Fix annoying Ubuntu shell defaults

```
sudo rm /bin/sh
sudo ln -s /bin/bash /bin/sh

##Edit password file and replace bash with tcsh
sudo emacs /etc/passwd
```

### 20. Customizing the ~/.cshrc

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

### 21. Installing Epiphany SDK
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

### 22. Setup COPRTHR

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

### 23. MPI Installation from source
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

### Known Issues
* Firefox not 100% stable
* No serial port access with default Linux kernel.
* Start wireless with app with 'sudo nm-applet`
* Define a connection with 'sudo nm-connection-editor'-->disable all things ipv6
