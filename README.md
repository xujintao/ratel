[![Build Status](https://travis-ci.org/xujintao/ratel.svg?branch=master)](https://travis-ci.org/xujintao/ratel)

Ratel is a api server solution using c/c++. It is based on spawn-fcgi, fastcgi, fastcgi++ and many other libraries which can achieve through github.

## Library

* [spawn-fcgi](https://github.com/lighttpd/spawn-fcgi)  
ratel use this as main entry.

* [fcgi or fastcgi](https://github.com/LuaDist/fcgi)  
when accept request, fcgi use blocking-io, which performance is worse.

* [fastcgi++](https://github.com/eddic/fastcgipp)  
epoll producer and multi-thread consumer makes it better.

## Quick start

Clone and make like this:
```sh
git clone https://github.com/xujintao/ratel
cd ratel
./build.sh
./restart.sh
```

## License

[MIT](https://github.com/xujintao/ratel/blob/master/LICENSE)