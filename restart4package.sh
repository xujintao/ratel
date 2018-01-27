#!/bin/bash
ratelfile=$1

# test file exist or not
if test -z "$ratelfile";then
    echo "try: <$0> <xxx.tar.gz>"
    exit
fi

# tar file
tar -xzvf $ratelfile -C /tmp
if [ $? -ne 0 ];then
    echo "$* failed, exit except..."
    exit
fi

#kill exist process
pid=`ps -ef | grep ./stable/app.exe | grep -v grep | awk '{print $2}'`
if test -n "$pid";then kill -15 $pid;sleep 2;fi

# move new file to stable
mv -fv /tmp/build/* ./stable

#start
./stable/app.exe -a 127.0.0.1 -p 10000 -F 4
