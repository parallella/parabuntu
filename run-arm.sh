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

echo Updating packages
apt-get update -yy || true
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

echo Fixing user permissions
chown -R parallella:parallella /home/parallella
chown -R root:root /root

echo Setting parallella user password to "parallella"
echo parallella:parallella | chpasswd

echo Set bash to default shell
echo "dash dash/sh boolean false" | debconf-set-selections
DEBIAN_FRONTEND=noninteractive dpkg-reconfigure dash
