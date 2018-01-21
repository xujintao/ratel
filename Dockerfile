FROM ubuntu:14.04
MAINTAINER xujintao <xujintao@126.com>

# prepare runtime
RUN echo "===>update apt source" && apt-get -y update && \
    echo "===>install boost.log" && apt-get -y install libboost-log1.54.0 && \
    echo "===>install boost.system" && apt-get -y install libboost-system1.54.0 && \
    echo "===>install boost.thread" && apt-get -y install libboost-thread1.54.0 && \
    echo "===>install boost.filesystem" && apt-get -y install libboost-filesystem1.54.0 && \
    echo "===>clean tmp files" && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/temp/*

# host dir -> container dir
ADD ./build/* /opt/www/ratel/

ENTRYPOINT exec /opt/www/ratel/restart.sh