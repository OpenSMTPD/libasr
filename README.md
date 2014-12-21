Description
===========

libasr is a free, simple and portable asynchronous resolver library.

It allows to run dns queries and preform hostname resolutions in a fully
asynchronous fashion.  The implementation is thread-less, fork-less, and
does not make use of signals or other "tricks" that may get in the deve-
loper's way.  The API was initially developped for the OpenBSD operating
system, where it is natively supported.

This library is intended to bring this interface to other systems. It is
originally provided as a support library for the portable version of the
OpenSMTPD daemon, but it can be used in any other contexts.  It is known
to work on the following systems:

* Linux
* FreeBSD
* NetBSD
* DragonFly
* MacOSX


Installation
============

Dependencies
------------

There is no specific dependency except a working C compiler, a C library
and the autotools:

* [autoconf](http://www.gnu.org/software/autoconf/)
* [automake](http://www.gnu.org/software/automake/)
* [libtool](http://www.gnu.org/software/libtool/)


Get the source
--------------

You can get the latest sources from github:

    git clone git://github.com/OpenSMTPD/libasr.git

Tarballs for development snapshots and official releases are available at:

http://www.opensmtpd.org/archives/


Build
-----

    ./bootstrap # only if building from git sources
    ./configure
    make


Install
-------

    sudo make install


Documentation
=============

For documentation, please refer to the OpenBSD manpages:

http://www.openbsd.org/cgi-bin/man.cgi/OpenBSD-current/man3/asr_run.3

Note that unlike the native OpenBSD implementation, this version is not
thread-safe (yet).

