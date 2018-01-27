#kill exist process
pid=`ps -ef | grep /opt/www/ratel/app.exe | grep -v grep | awk '{print $2}'`
if test -n "$pid";then kill -15 $pid;sleep 2;fi

#start
/opt/www/ratel/app.exe -a 127.0.0.1 -p 10000 -F 4

