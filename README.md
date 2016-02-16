Description
===========

libasr is a free, simple and portable asynchronous resolver library.

It allows to run dns queries and perform hostname resolutions in a fully
asynchronous fashion.  The implementation is thread-less, fork-less, and
does not make use of signals or other "tricks" that might get in the
developer's way.  The API was initially developed for the OpenBSD
operating system, where it is natively supported.

This library is intended to bring this interface to other systems. It is
originally provided as a support library for the portable version of the
OpenSMTPD daemon, but it can be used in any other contexts.  It is known
to work on the following systems:

* Linux
* FreeBSD
* NetBSD
* DragonFly
* MacOSX

The primary source of information about libasr is the [github repository][1].

[1]: http://github.com/OpenSMTPD/libasr


Installation
============

Get the source
--------------

You can get the latest sources from github:

    git clone git://github.com/OpenSMTPD/libasr.git

Tarballs for development snapshots and official releases are available
on the [OpenSMTPD website][2].

[2]: http://www.opensmtpd.org/archives/

Build
-----

All you should need is working C compiler, a C library and the autotools
([autoconf],[automake],[libtool]).  Build and install using the following
commands:

    ./bootstrap # only if building from git sources
    ./configure
    make
    sudo make install

[autoconf]: http://www.gnu.org/software/autoconf/
[automake]: http://www.gnu.org/software/automake/
[libtool]: http://www.gnu.org/software/libtool/

Documentation
=============

For documentation on using the API, please refer to the [OpenBSD manpages][3].
Note that unlike the native OpenBSD implementation, this version is not currently
thread-safe.

[3]: http://www.openbsd.org/cgi-bin/man.cgi/OpenBSD-current/man3/asr_run.3


Contact
=======

For now, please use the [OpenSMTPD mailing list][4] for questions related to
libasr.  You can also get in touch with libasr developers on the "Official"
IRC channel for the OpenSMTPD project at:

    #OpenSMTPD @ irc.freenode.net

Bug reports must be filed on the [project's issue tracker][5].

[4]: http://www.opensmtpd.org/list.html
[5]: http://github.com/OpenSMTPD/libasr/issues
