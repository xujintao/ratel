FROM ubuntu:14.04
MAINTAINER xujintao <xujintao@126.com>

# prepare runtime
RUN echo "===>update apt source" && apt-get -y update && \
    echo "===>install boost" && apt-get -y install libboost-log1.54.0 \
                                                   libboost-system1.54.0 \
                                                   libboost-thread1.54.0 \
                                                   libboost-filesystem1.54.0 && \
    echo "===>clean tmp files" && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/temp/*

# host dir -> container dir
ADD ./build/* /opt/www/ratel/

ENTRYPOINT exec /opt/www/ratel/restart.sh