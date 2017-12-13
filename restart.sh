#kill exist process
pid=`ps -ef | grep ./app.exe | grep -v grep | awk '{print $2}'`
if test -n "$pid";then kill -15 $pid;sleep 2;fi

#cp app.exe and *.so to current path
cp -f -T ./app/Debug/app ./app.exe
cp -f ./*/Debug/*.so ./

#start
./app.exe -a 127.0.0.1 -p 10008 -F 4
