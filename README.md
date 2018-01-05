[![Build Status](https://travis-ci.org/xujintao/ratel.svg?branch=master)](https://travis-ci.org/xujintao/ratel)

Ratel is a api server solution using c/c++. It is based on spawn-fcgi, fastcgi, fastcgi++ and many other libraries which can achieve through github.

## Library

* [spawn-fcgi](https://github.com/lighttpd/spawn-fcgi)  
ratel/app fork process via spawn-fcgi.

* [fcgi or fastcgi](https://github.com/LuaDist/fcgi)  
A blocking fastcgi based network library

* [fastcgi++](https://github.com/eddic/fastcgipp)  
A non-blocking fastcgi based network library with c++14, which means our compiler must be support c++14.
One receiver-thread(as producer) accept request asynchronously, and push all request to a container 
which other multi-thread(act as consumer) pull from and handle.

* log  
1.The log module in ratel is based on [Boost.log](http://www.boost.org/doc/libs/1_54_0/libs/log/doc/html/index.html), and version must be at least 1.54.0  
2.Instead of verboss "<<", it use printf-style syntax, which means we can log like this:  
```
Log(info, "Num:%d, note:%s", 1, "log here");
```

## Quick start
On Ubuntu 14.04, start with the following steps:
```sh
# 1. Add toolchain repo:
$ sudo apt-add-repository "ppa:ubuntu-toolchain-r/test"  
$ sudo apt-get update

# 2. Ubuntu 14.04 default boost repo version is 1.54.0:
$ sudo apt-get install gcc-7 g++-7 libboost-all-dev

# 3. Enable gcc:
$ sudo ln -s /usr/bin/gcc-7 /usr/bin/gcc -f
$ sudo ln -s /usr/bin/g++-7 /usr/bin/g++ -f
```

If CentOS7.4, you can get started in four easy steps:  
```sh
# 1. Install a package with repository for your system:
# On CentOS, install package centos-release-scl available in CentOS repository:
$ sudo yum install centos-release-scl

# On RHEL, enable RHSCL repository for you system:
$ sudo yum-config-manager --enable rhel-server-rhscl-7-rpms

# 2. Install the collection:
$ sudo yum install devtoolset-7-gcc devtoolset-7-gcc-c++ devtoolset-7-gdb

# 3. Start using software collections:
$ source /opt/rh/devtoolset-7/enable

# 4. Yet the default Boost repo version is 1.53.0, so download 1.54.0 and build.
$ ...
```

Then, clone and make like this:  
```sh
$ git clone https://github.com/xujintao/ratel
$ cd ratel
$ ./build.sh
$ ./restart.sh
```

## License

[MIT](https://github.com/xujintao/ratel/blob/master/LICENSE)