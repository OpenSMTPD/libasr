# $Id: configure.ac,v 1.519 2013/03/22 01:49:15 dtucker Exp $
#
# Copyright (c) 1999-2004 Damien Miller
#
# Permission to use, copy, modify, and distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
#
# THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
# WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
# ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
# WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
# ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
# OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

#
# 3.1.3 Standard configure.ac Layout
#
# https://www.gnu.org/software/autoconf/manual/autoconf-2.69/html_node/Autoconf-Input-Layout.html
#

#
# AUTOCONF REQUIREMENTS
#
AC_PREREQ(2.69)

#
# AC_INIT
#
AC_INIT([libasr],
	[portable],
	[bugs@opensmtpd.org])
AM_INIT_AUTOMAKE([foreign subdir-objects])
LT_INIT

#
# PACKAGE INFORMATION
#
AC_LANG([C])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADER([config.h])
AC_CANONICAL_HOST
AC_C_BIGENDIAN

#
# CHECKS FOR PROGRAMS
#
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LIBTOOL

#
# CHECKS FOR LIBRARIES
#

#
# CHECKS FOR HEADERS
#
OPENBSD_CHECK_HEADERS
AC_CHECK_HEADERS(
  arpa/nameser_compat.h
)

#
# CHECKS FOR TYPES
#
OPENBSD_CHECK_TYPES

#
# CHECKS FOR STRUCTURES
#
OPENBSD_CHECK_STRUCTS

#
# CHECKS FOR COMPILER CHARACTERISTICS
#

#
# CHECKS FOR LIBRARY FUNCTIONS
#
OPENBSD_CHECK_FUNCTIONS

#
# CHECKS FOR SYSTEM SERVICES
#

#
# libasr specific checks.
#

# This ought to be part of the generic compat library, but we don't want to force
# linking against other libs (-lresolv for instance) in all cases.
# It has to be improved at some point.
#
AC_DEFUN([LIBASR_CHECK_EXPLICIT_BZERO], [AC_LANG_PROGRAM([[
    #include <string.h>
    ]], [[
    char c;
    explicit_bzero((void *)&c, 1);
    ]])
])
AC_MSG_CHECKING([if explicit_bzero() will build])
AC_LINK_IFELSE(
    [ LIBASR_CHECK_EXPLICIT_BZERO ],
    [ AC_MSG_RESULT([yes])
      AC_DEFINE([HAVE_EXPLICIT_BZERO], [1], [Have explicit_bzero()])],
    [ AC_MSG_RESULT([no])
      ])

AC_DEFUN([LIBASR_CHECK_CLOCK_GETTIME], [AC_LANG_PROGRAM([[
    #include <time.h>
    ]], [[
    clock_gettime(0, NULL);
    ]])
])
AC_MSG_CHECKING([if clock_gettime() will build])
AC_LINK_IFELSE(
    [ LIBASR_CHECK_CLOCK_GETTIME ],
    [ AC_MSG_RESULT([yes])
      AC_DEFINE([HAVE_CLOCK_GETTIME], [1], [Have clock_gettime()])],
    [ AC_MSG_RESULT([no])
      saved_LIBS="$LIBS"
      LIBS="$LIBS -lrt"
      AC_MSG_CHECKING([if clock_gettime() will build with -lrt])
      AC_LINK_IFELSE(
          [ LIBASR_CHECK_CLOCK_GETTIME ],
          [ AC_MSG_RESULT([yes])
            AC_DEFINE([HAVE_CLOCK_GETTIME], [1], [Have clock_gettime()])],
          [ LIBS="$saved_LIBS"
            AC_MSG_RESULT([no])])
      ])

AC_DEFUN([LIBASR_CHECK_RES_HNOK], [AC_LANG_PROGRAM([[
    #include <sys/types.h>
    #include <netinet/in.h>
    #include <arpa/nameser.h>
    #include <resolv.h>
    ]], [[
    res_hnok("");
    ]])
])
AC_MSG_CHECKING([if res_hnok() will build])
AC_LINK_IFELSE(
    [ LIBASR_CHECK_RES_HNOK ],
    [ AC_MSG_RESULT([yes])
      AC_DEFINE([HAVE_RES_HNOK], [1], [Have res_hnok()])],
    [ AC_MSG_RESULT([no])
      saved_LIBS="$LIBS"
      LIBS="$LIBS -lresolv"
      AC_MSG_CHECKING([if res_hnok() will build with -lresolv])
      AC_LINK_IFELSE(
          [ LIBASR_CHECK_RES_HNOK ],
          [ AC_MSG_RESULT([yes])
            AC_DEFINE([HAVE_RES_HNOK], [1], [Have res_hnok()])],
          [ LIBS="$saved_LIBS"
            AC_MSG_RESULT([no])])
      ])

# Same remark as above.
#
AC_DEFUN([LIBASR_CHECK_RES_RANDOMID], [AC_LANG_PROGRAM([[
    #include <sys/types.h>
    #include <netinet/in.h>
    #include <arpa/nameser.h>
    #include <resolv.h>
    ]], [[
    res_randomid();
    ]])
])
AC_MSG_CHECKING([if res_randomid() will build])
AC_LINK_IFELSE(
    [ LIBASR_CHECK_RES_RANDOMID ],
    [ AC_MSG_RESULT([yes])
      AC_DEFINE([HAVE_RES_RANDOMID], [1], [Have res_randomid()])],
    [ AC_MSG_RESULT([no])
      saved_LIBS="$LIBS"
      LIBS="$LIBS -lresolv"
      AC_MSG_CHECKING([if res_randomid() will build with -lresolv])
      AC_LINK_IFELSE(
          [ LIBASR_CHECK_RES_RANDOMID ],
          [ AC_MSG_RESULT([yes])
            AC_DEFINE([HAVE_RES_RANDOMID], [1], [Have res_randomid()])],
          [ LIBS="$saved_LIBS"
            AC_MSG_RESULT([no])])
      ])

##
AC_DEFUN([LIBASR_CHECK___P_TYPE], [AC_LANG_PROGRAM([[
    #include <sys/types.h>
    #include <netinet/in.h>
    #include <arpa/nameser.h>
    #include <resolv.h>
    ]], [[
    __p_type(0);
    ]])
])
AC_MSG_CHECKING([if __p_type() will build])
AC_LINK_IFELSE(
    [ LIBASR_CHECK___P_TYPE ],
    [ AC_MSG_RESULT([yes])
      AC_DEFINE([HAVE___P_TYPE], [1], [Have __p_type()])],
    [ AC_MSG_RESULT([no])
      saved_LIBS="$LIBS"
      LIBS="$LIBS -lresolv"
      AC_MSG_CHECKING([if __p_type() will build with -lresolv])
      AC_LINK_IFELSE(
          [ LIBASR_CHECK___P_TYPE ],
          [ AC_MSG_RESULT([yes])
            AC_DEFINE([HAVE___P_TYPE], [1], [Have __p_type()])],
          [ LIBS="$saved_LIBS"
            AC_MSG_RESULT([no])])
      ])

AC_DEFUN([LIBASR_CHECK___P_CLASS], [AC_LANG_PROGRAM([[
    #include <sys/types.h>
    #include <netinet/in.h>
    #include <arpa/nameser.h>
    #include <resolv.h>
    ]], [[
    __p_class(0);
    ]])
])
AC_MSG_CHECKING([if __p_class() will build])
AC_LINK_IFELSE(
    [ LIBASR_CHECK___P_CLASS ],
    [ AC_MSG_RESULT([yes])
      AC_DEFINE([HAVE___P_CLASS], [1], [Have __p_class()])],
    [ AC_MSG_RESULT([no])
      saved_LIBS="$LIBS"
      LIBS="$LIBS -lresolv"
      AC_MSG_CHECKING([if __p_class() will build with -lresolv])
      AC_LINK_IFELSE(
          [ LIBASR_CHECK___P_CLASS ],
          [ AC_MSG_RESULT([yes])
            AC_DEFINE([HAVE___P_CLASS], [1], [Have __p_class()])],
          [ LIBS="$saved_LIBS"
            AC_MSG_RESULT([no])])
      ])

#
# OUTPUT
#
AC_CONFIG_FILES([Makefile
		openbsd-compat/Makefile
		src/Makefile
		])
AC_CONFIG_COMMANDS([include-config],
		   [sh $srcdir/openbsd-compat/include-config $srcdir],
		   [srcdir=$srcdir])
AC_OUTPUT
