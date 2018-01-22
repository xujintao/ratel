[![Build Status](https://travis-ci.org/xujintao/ratel.svg?branch=master)](https://travis-ci.org/xujintao/ratel)

Ratel is a api server solution using c/c++. It is based on spawn-fcgi, fastcgi, fastcgi++, boost and many other libraries which can achieve through github.

## Library

* [spawn-fcgi](https://github.com/lighttpd/spawn-fcgi)  
ratel/app fork process via spawn-fcgi.

* [fcgi or fastcgi](https://github.com/LuaDist/fcgi)  
A blocking fastcgi based network library. Because of the feature of blocking, Ratel discard, and here just take it to compare with the next non-blocking network library.

* [fastcgi++](https://github.com/eddic/fastcgipp)  
A non-blocking fastcgi based network library with c++14, which means our compiler must be support c++14. One receiver-thread(as producer) accept request asynchronously, 
and push all request to a container which other multi-thread(act as consumer) pull from and handle.

* log  
1.The log module in ratel is based on [boost.log](http://www.boost.org/doc/libs/1_54_0/libs/log/doc/html/index.html), and version must be at least 1.54.0.  
2.Instead of verboss "<<", it use printf-style syntax, which means we can log like this:  
```
Log(info, "Num:%d, note:%s", 1, "log here");
```

* [jsoncpp](https://github.com/open-source-parsers/jsoncpp)  
Before jsoncpp, i tried [boost.ptree](http://www.boost.org/doc/libs/1_54_0/doc/html/property_tree.html) and [rapidJson](https://github.com/Tencent/rapidjson). However boost.ptree [does not conform to JSON standard](https://svn.boost.org/trac10/ticket/9721#no2) and rapidJson is extremely clunky to use. As for jsoncpp, the fact that [Serialize UTF-8 string with Unicode escapes #687](https://github.com/open-source-parsers/jsoncpp/pull/687) since v1.8.4 seems to be useless. So, here i will stay with v1.8.3 until it makes some change.

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
# install package centos-release-scl-rh available in CentOS repository:
$ sudo yum install centos-release-scl-rh

# 2. Install the collection:
$ sudo yum install devtoolset-7-gcc devtoolset-7-gcc-c++ devtoolset-7-gdb

# 3. Start using software collections:
#$ scl enable devtoolset-7 bash
$ source /opt/rh/devtoolset-7/enable

# 4. The default boost from yum is 1.53.0, we have to download 1.54.0 and build.
$ cd ~
$ wget -q https://sourceforge.net/projects/boost/files/boost/1.54.0/boost_1_54_0.tar.gz
$ tar -xzf boost_1_54_0.tar.gz
$ cd boost_1_54_0
$ ./bootstrap.sh
$ ./b2 -d0 --with-log --with-thread --with-system --with-filesystem
$ cp -drf boost /usr/include
$ cp -drf stage/lib* /usr/lib64
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