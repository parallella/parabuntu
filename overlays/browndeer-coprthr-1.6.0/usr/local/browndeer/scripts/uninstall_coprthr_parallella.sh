#!/bin/bash

if [ -e /usr/local/browndeer ]; then
	echo "removing /usr/local/browndeer";
	rm -R /usr/local/browndeer
fi;

if [ -e /etc/OpenCL/vendors/coprthr-e.icd ]; then
	echo "removing /etc/OpenCL/vendors/coprthr.icd";
	rm -R /etc/OpenCL/vendors/coprthr.icd
fi;

if [ -e /var/clproc ]; then
	echo "removing /var/clproc";
	rm -R /var/clproc
fi;

