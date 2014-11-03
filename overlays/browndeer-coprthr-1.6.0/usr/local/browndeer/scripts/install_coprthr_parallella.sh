#!/bin/bash

echo "installing files to /usr/local/browndeer"
test -d /usr/local/browndeer || install -m 755 -d /usr/local/browndeer
cp -Rf ./browndeer/* /usr/local/browndeer
chmod -R a+rX /usr/local/browndeer

echo "installing ICD file to /etc/OpenCL/vendors"
test -d /etc/OpenCL || install -m 755 -d /etc/OpenCL
test -d /etc/OpenCL/vendors || install -m 755 -d /etc/OpenCL/vendors
cp -f /usr/local/browndeer/icd/coprthr.icd /etc/OpenCL/vendors/coprthr.icd

echo "creating /var/clproc for accounting"
test -d /var/clproc || install -m 777 -d /var/clproc


