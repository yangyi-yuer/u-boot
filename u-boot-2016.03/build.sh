#!/bin/bash

set -e

CPU_JOB_NUM=$(grep processor /proc/cpuinfo | awk '{field=$NF};END{print field+1}')
ROOT_DIR=$(pwd)
CUR_DIR=${ROOT_DIR##*/}

if [ $# -ne 0 ];then
	echo "Clean Configuration File..."
	make distclean

	echo "Clean Obj..."
	make clean

	echo "Load Configuration File..."
	make itop4412_defconfig
fi

echo "make..."
make -j$CPU_JOB_NUM
if [ $? -ne 0 ];then
	echo "======================================="
	echo "======= build u-boot failed!!! ========"
	echo "======================================="
	exit 1
fi

cd ./sdtool && ./sdtool.sh mkuboot ../u-boot.bin
cd -
