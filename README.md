Preliminary note
================

libasr is a FREE asynchronous DNS resolver.

libasr runs on top of the OpenBSD operating system but also has a portable
version that can build and run on several systems, including:

* Linux
* FreeBSD
* NetBSD
* DragonFly
* MacOSX

For more information:
* [libasr OpenBSD CVS repository](http://www.openbsd.org/cgi-bin/cvsweb/src/lib/libc/asr/)
* [libasr man pages](http://www.openbsd.org/cgi-bin/man.cgi?query=asr_run&sektion=0&manpath=OpenBSD+Current&format=html)


How to build, configure and use portable libasr
===============================================

Dependencies
------------

Portable libasr relies on:
* [openssl](http://www.openssl.org/)

and for the build:
* [autoconf](http://www.gnu.org/software/autoconf/)
* [automake](http://www.gnu.org/software/automake/)
* [libtool](http://www.gnu.org/software/libtool/)


Get the source
--------------

    git clone git://github.com/OpenSMTPD/libasr.git


Build
-----

    ./configure
    make


### Special notes for FreeBSD/DragonFlyBSD/Mac OS X:

Please launch configure with special directive about libevent directory:

#### FreeBSD:

    ./configure --with-libevent-dir=/usr/local

#### DragonFlyBSD:

    ./configure --with-libevent-dir=/usr/pkg

#### Mac OS X:

    ./configure --with-libevent-dir=/opt/local
    make CFLAGS="-DBIND_8_COMPAT=1"


Install
-------

    sudo make install


