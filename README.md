
WORK IN PROGRESS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

###################################################################
#Format an 8GB SD card with 256MB FAT32 'BOOT' and 7GB 'ext4 rootfs
####################################################################
sudo gparted

####################################################################
#Get the distributions
####################################################################

wget http://releases.linaro.org/14.05/ubuntu/trusty-images/nano/linaro-trusty-nano-20140522-661.tar.gz
wget http://downloads.parallella.org/boot/boot-e16-7z020-v01-140528.tgz

####################################################################
#Insert SD card into your regular computer and copy files sd card
####################################################################

sudo tar -zxvf linaro-trusty-nano-20140522-661.tar.gz
cd binary
sudo rsync -a --progress ./ /media/aolofsson/rootfs
tar -zxvf boot-e16-7z020-v01-140528.tgz -C /media/aolofsson/BOOT

####################################################################
#Set up network interface (with sd card still inserted)
####################################################################
sudo emacs /media/aolofsson/rootfs/etc/network/interfaces

auto lo
iface lo inet loopback

auto eth0
iface eth0 inet dhcp

#allow-hotplug wlan0
#iface wlan0 inet dhcp

####################################################################
#Enable devtmpfs
####################################################################
cd /media/aolofsson/rootfs/dev
sudo su
mknod -m 660 mmcblk0 b 179 0
mknod -m 660 mmcblk0p1 b 179 1
mknod -m 660 mmcblk0p2 b 179 2

#sudo mount   mmcblk0p1 /mnt
#sudo dtc -I dtb -O dts -o devicetree.dts /mnt/devicetree.dtb
#sudo emacs devicetree.dts
#sudo dtc -I dts -O dtb -o /mnt/devicetree.dtb devicetree.dts

####################################################################
#Create the tty node for initial setup
####################################################################
#cd /media/aolofsson/rootfs/dev
#sudo su
#mknod ttyPS0 c 251 0
#mknod fb0 c 29 0
#mkdir dri 
#mknod dri/card0 c 226 0
#mknod dri/controlD64 c 226 64

####################################################################
#Unmounting card
####################################################################
sudo sync
umount /media/aolofsson/rootfs/
umount /media/aolofsson/BOOT

####################################################################
#Boot board (screen attached)
####################################################################
su linaro
sudo apt-get update

####################################################################
#SSH into board from other computer for ease of use
####################################################################
ssh linaro@192.168.1.121 #password 'linaro'

####################################################################
#Installing a windows manager
####################################################################
sudo apt-get install lxde
sudo apt-get install xfce4
#sudo nano /etc/xdg/lxsession/LXDE/autostart
#(Append these line to the bottom of the file)
#     @feh --bg-fill /home/linaro/background.png

#Desktop-Session Settings: Enable notification, mount helper, volume control
#xfce4-settings-manager

####################################################################
#First screen
####################################################################

#You should see logs of boot messages and a minimal login prompt
#Login with "user=linaro, password=linaro"
 
####################################################################
#Enable ssh
####################################################################

sudo apt-get update
sudo apt-get install openssh-server

####################################################################
#Installing minimal graphical desktop
####################################################################

sudo apt-get install lxde
sudo apt-get install xfce4
sudo apt-get install xserver-xorg-video-modesetting

####################################################################
#Weird Edits to fix issues???
####################################################################

#Not sure why the pin is not working?
sudo chmod u+s `which ping`

#Working around bug with this package.
sudo emacs /var/lib/dpkg/info/libpam-systemd:armhf.postinst
     #comment out the following line. FIX THIS!
     "#invoke-rc.d systemd-logind start || exit $?"

#Working around slow boot time without ethernet connected
sudo emacs /etc/init/failsafe.conf
    #Change the timeout value from 60 seconds to make boot faster
    #in case there is no cable inserted.Note: FIX THIS!

#Trying to improve firefox stability
In firefox:
  about:config
     webgl.disabled=true
     webgl.disable0-extensions=true
     layers.use-depracated-textures=false
     browser.cache.disk.enable=false
     mousewheel.acceleration.start=2

####################################################################
#Second Login
####################################################################
(login with screen connected, or through ssh)

####################################################################
#More configurations
####################################################################
#less tcsh emacs vim ftp wget synaptic tkcvs fake-hwclock unzip feh lsb-release  build-essential git curl m4 flex bison gawk ethtool iperf ifplugd network-manager xutils-dev device-tree-compiler usbutils firefox smplayer evince  gimp 

#"Must haves"
sudo apt-get install less tcsh emacs vim ftp wget synaptic tkcvs
sudo apt-get install fake-hwclock unzip feh lsb-release

#Compiling/Building
sudo apt-get install build-essential git curl m4 flex bison gawk

#Networking
sudo apt-get install ethtool iperf ifplugd
sudo apt-get install network-manager

#Linux Tools
sudo apt-get install xutils-dev device-tree-compiler usbutils

#Media
sudo apt-get install firefox 
sudo apt-get install smplayer
suto apt-get install evince
sudo apt-get install gimp

#Programming
sudo apt-get install octave
sudo apt-get install scratch

#Scientific
sudo apt-get install python-numpy python-scipy python-matplotlib ipython ipython-notebook python-pandas python-sympy python-nose
sudo apt-get install r-base

#Sound
#sudo apt-get install xfce4-mixer gstreamer0.10-alsa
sudo apt-get install alsa-base alsa-utils libasound2-plugins 

#For Demos
sudo apt-get install libdrm-dev libasound2-dev
sudo apt-get install libfluidsynth-dev fluidsynth fluid-soundfont-gm

#X11 package for xtemp
sudo apt-get install libx11-dev

#Camera
sudo apt-get install camorama

#Wifi
sudo apt-get install linux-firmware

#Screen sharing
sudo apt-get install tightvncserver

#Getting list of all packages
dpkg --get-selections > my.packages

####################################################################
#Recommended
####################################################################

#sudo aptitude install boinc-client boinc-manager
#sudo apt-get install libreoffice
#sudo apt-get install openvpn
#sudo apt-get install synergy
#sudo apt-get install vlc

####################################################################
#Purging bad packages
####################################################################
sudo apt-get purge chromium-browser xscreensaver

####################################################################
#Editing video config file
####################################################################
emacs /etc/X11/xorg.conf

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



####################################################################
#Editing audio config file
####################################################################
emacs ~/.asoundrc

pcm.!default {
 type rate
 slave {
  pcm "hw:0"
  rate 48000
 }
 converter "samplerate"
}

####################################################################
#Fix GCONF permission
####################################################################
sudo chown -R linaro:linaro ~/.gconf

####################################################################
#Speedup ssh 
####################################################################
sudo emacs /etc/ssh/sshd_config
Append this line to the bottom of the file. 
UseDNS no

####################################################################
#Change default shell to tcsh and change sh-->bash
####################################################################
sudo rm /bin/sh
sudo ln -s /bin/bash /bin/sh
sudo emacs /etc/passwd #change shell to tcsh for user linaro

####################################################################
#Customizing the ~/.cshrc
####################################################################

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

####################################################################
#Installing Epiphany SDK
####################################################################
sudo apt-get install libmpfr-dev libmpc-dev libgmp3-dev
sudo mkdir -p /opt/adapteva/
wget http://downloads.parallella.org/esdk/esdk.5.13.09.10_linux_armv7l.tgz
sudo tar xzf esdk.5.13.09.10_linux_armv7l.tgz -C /opt/adapteva/
sudo ln -sTf /opt/adapteva/esdk.5.13.09.10 /opt/adapteva/esdk
sudo ln -s /usr/lib/arm-linux-gnueabihf/libmpc.so.3.0.0 /usr/lib/arm-linux-gnueabihf/libmpc.so.2 #HACK!

#Adding esdk setup to .cshrc
echo 'setenv EPIPHANY_HOME      /opt/adapteva/esdk' >> ${HOME}/.cshrc
echo 'source ${EPIPHANY_HOME}/setup.csh' >> ${HOME}/.cshrc

#Adding esdk setup to .bashrc
echo 'EPIPHANY_HOME=/opt/adapteva/esdk' >> ${HOME}/.bashrc
echo '. ${EPIPHANY_HOME}/setup.sh' >> ${HOME}/.bashrc

####################################################################
#Installing COPRTHR Prerequisites
####################################################################

###libelf
wget www.mr511.de/software/libelf-0.8.13.tar.gz
tar -zxvf libelf-0.8.13.tar.gz
cd libelf-0.8.13
./configure
sudo make install
cd ../

##libevent
wget github.com/downloads/libevent/libevent/libevent-2.0.18-stable.tar.gz
tar -zxvf libevent-2.0.18-stable.tar.g
cd libevent-2.0.18-stable
./configure
sudo make install
cd ../

##libconfig
wget www.hyperrealm.com/libconfig/libconfig-1.4.8.tar.gz
tar -zxvf libconfig-1.4.8.tar.gz
cd libconfig-1.4.8
./configure
sudo make install
cd ../

####################################################################
#Setting up COPRTHR
####################################################################
wget http://www.browndeertechnology.com/code/coprthr-1.6.0-parallella.tgz
tar -zxvf coprthr-1.6.0-parallella.tgz
sudo ./browndeer/scripts/install_coprthr_parallella.sh

emacs ~/.bashrc

export PATH=/usr/local/browndeer/bin:$PATH
export LD_LIBRARY_PATH=/usr/local/browndeer/lib:/usr/local/lib:$LD_LIBRARY_PATH

sudo su
emacs ./bashrc
export PATH=/usr/local/browndeer/bin:$PATH
export LD_LIBRARY_PATH=/usr/local/browndeer/lib:/usr/local/lib:$LD_LIBRARY_PATH


####################################################################
#KNOWN ISSUES:
####################################################################
#firefox is not 100% stable, workaround:??
#slow boot with no network attached
#no uart by default
#wifi not working

####################################################################
#TESTS
####################################################################
#play video (sound, video)
#check bandwidth
#sound only comes out if you add and adjust sound icon on lxde menu bar
#installing cheese crashes the system

#Commented out the start condition in /etc/xdg/autostart/nm-applet

####################################################################
#MPI Installation from source
####################################################################
wget http://www.open-mpi.org/software/ompi/v1.8/downloads/openmpi-1.8.1.tar.gz
tar -zxvf openmpi-1.8.1.tar.gz
make all
make install

