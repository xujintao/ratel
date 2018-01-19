#kill exist process
pid=`ps -ef | grep ./build/app.exe | grep -v grep | awk '{print $2}'`
if test -n "$pid";then kill -15 $pid;sleep 2;fi

#start
./build/app.exe -a 127.0.0.1 -p 10008 -F 4
