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

#
# CHECKS FOR TYPES
#
OPENBSD_CHECK_TYPES

#
# CHECKS FOR STRUCTURES
#

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
# libasr specific checks
#
AC_CHECK_FUNCS(		\
    __res_hnok		\
    __res_randomid	\
)
AS_IF([test "x$ac_cv_func___res_hnok" == "xno"], [
    AC_SEARCH_LIBS([__res_hnok], [resolv])
])
AS_IF([test "x$ac_cv_func___res_randomid" == "xno"], [
    AC_SEARCH_LIBS([__res_randomid], [resolv])
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
