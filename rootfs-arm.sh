#!/bin/bash
set -e
set -o pipefail
set -u

cleanup () {
	echo arm cleanup
}

script=$(readlink -f "$0")
top=$(dirname "$script")

trap 'cleanup' EXIT

cd $top

export LC_ALL=C
export DEBIAN_FRONTEND=noninteractive

echo Installing local deb packages
apt-get install -yy multiarch-support
dpkg -i /tmp/deb-pkgs/*.deb

echo fixing libelf symlink for coprthr
#HACK HACK HACK
(cd /usr/lib/arm-linux-gnueabihf/ && ln -sf libelf.so.0.8.13 libelf.so)

echo Updating packages
apt-get update -yy || true

# Set Zonedata so the interactive prompt won't pop up while installing packages
sudo ln -fs /usr/share/zoneinfo/US/Eastern /etc/localtime
sudo dpkg-reconfigure -f noninteractive tzdata

echo Upgrading packages
apt-get dist-upgrade -yy
apt-get upgrade -yy

apt-get install -yy $(cat ${top}/packages.basic.txt | grep -v "^#" | sed 's,\s\s*,\n,g' | grep -v "^\s*$" | xargs echo)
# TODO: Can we install from apt now?
#dpkg -i $(ls packages | grep -v -- "-dbg_")

apt-get clean

echo Removing generated host SSH keys
rm -fr /etc/ssh/*key*

echo Copying skel to parallella user
cp -r /etc/skel/. /home/parallella/

echo Add user group
useradd parallella
addgroup parallella adm
addgroup parallella sudo

echo Fixing user permissions
chown -R parallella:parallella /home/parallella
chown -R root:root /root

echo Setting parallella user password to "parallella"
echo parallella:parallella | chpasswd

echo Set bash to default shell
echo "dash dash/sh boolean false" | debconf-set-selections
DEBIAN_FRONTEND=noninteractive dpkg-reconfigure dash

sync
