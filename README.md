[![Build Status](https://travis-ci.org/xujintao/ratel.svg?branch=master)](https://travis-ci.org/xujintao/ratel)

Ratel is a api server solution using c/c++. It is based on spawn-fcgi, fastcgi, fastcgi++ and many other libraries which can achieve through github.

## Library

* [spawn-fcgi](https://github.com/lighttpd/spawn-fcgi)  
ratel/app use this as main entry.

* [fcgi or fastcgi](https://github.com/LuaDist/fcgi)  
A blocking fastcgi based network library

* [fastcgi++](https://github.com/eddic/fastcgipp)  
A non-blocking fastcgi based network library with c++14, which means our compiler must be support c++14.
One receiver-thread(as producer) accept request asynchronously, and push all request to a container 
which other multi-thread(act as consumer) pull from and handle.

* [Ratel.log]
features:
1. The log module in ratel is based on Boost.log.
2. Instead of verboss "<<", it use printf-style syntax, which means we can log like this:
```
Log(info, "Num:%d, note:%s", 1, "hey guys");
```

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