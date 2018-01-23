#!/bin/bash
#test devtoolset-7 env for docker
if [ -f /opt/rh/devtoolset-7/enable ];then
echo test /opt/rh/devtoolset-7/enable
source /opt/rh/devtoolset-7/enable
fi

# check container env 
gcc --version

# make
make -C ./libspawnfcgi clean
make -C ./libcommon clean
make -C ./libfcgi clean
make -C ./libfastcgipp clean
make -C ./app clean

make -C ./libspawnfcgi
make -C ./libcommon
make -C ./libfcgi 
make -C ./libfastcgipp
make -C ./app

# cp app.exe and *.so to build path
mkdir -p build
cp -f ./app/Debug/app ./build/app.exe
cp -f ./*/Debug/*.so ./build
