parallella-ubuntu
=================

Official Ubuntu distro for Parallella.

=================

For now,we are simply using the latest ubuntu-desktop distribution from Linaro.

1.) To download the Linaro Ubuntu distribution:

> wget http://releases.linaro.org/12.11/ubuntu/precise-images/ubuntu-desktop/linaro-precise-ubuntu-desktop-20121124-560.tar.gz

2.) To uncompress and copy root file system to an SD card

> sudo tar --strip-components=3 -C /media/rootfs -xzpf linaro-precise-ubuntu-desktop-20121124-560.tar.gz binary/boot/filesystem.dir

> ls /media/rootfs/
bin/  boot/  dev/  etc/  home/  lib/  lost+found/  media/  mnt/ opt/
proc/  root/  run/  sbin/  selinux/  srv/  sys/  tmp/  usr/  var/

