dnl
dnl missing defines
dnl
AC_DEFUN([OBSD_NEED_RESOLV_DEFINES], [
	AC_MSG_CHECKING([if RES_USE_EDNS0 is defined in resolv.h])
	AC_EGREP_CPP(HAVE_RES_USE_EDNS0, [
	    #include <sys/types.h>
	    #include <netinet/in.h>
	    #include <arpa/nameser.h>
	    #include <resolv.h>
	    #ifdef RES_USE_EDNS0
	    HAVE_RES_USE_EDNS0
	    #endif
	],
	[ AC_MSG_RESULT([yes]) ],
	[ AC_MSG_RESULT([no])
   	  AC_DEFINE([RES_USE_EDNS0], [0], [Defined to 0 if RES_USE_EDNS0 is not a supported resolver flag.]) ])

	AC_MSG_CHECKING([if RES_USE_DNSSEC is defined in resolv.h])
	AC_EGREP_CPP(HAVE_RES_USE_DNSSEC, [
	    #include <sys/types.h>
	    #include <netinet/in.h>
	    #include <arpa/nameser.h>
	    #include <resolv.h>
	    #ifdef RES_USE_DNSSEC
	    HAVE_RES_USE_DNSSEC
	    #endif
	],
	[ AC_MSG_RESULT([yes]) ],
	[ AC_MSG_RESULT([no])
   	  AC_DEFINE([RES_USE_DNSSEC], [0], [Defined to 0 if RES_USE_DNSSEC is not a supported resolver flag.]) ])
])


dnl
dnl  res_hnok()
dnl
AC_DEFUN([OBSD_TEST_PROG_RES_HNOK], [AC_LANG_PROGRAM([[
        #include <sys/types.h>
        #include <netinet/in.h>
        #include <arpa/nameser.h>
        #include <netdb.h>
        #include <resolv.h>
        ]], [[
	res_hnok("");
	]])
])

AC_DEFUN([OBSD_NEED_RES_HNOK], [
    AC_MSG_CHECKING([if res_hnok will link])
    AC_LINK_IFELSE(
        [ OBSD_TEST_PROG_RES_HNOK ],
	[ AC_MSG_RESULT([yes])
	  AC_DEFINE([HAVE_RES_HNOK], [1], [Have res_hnok()])],
	[ AC_MSG_RESULT([no])
	  saved_LIBS="$LIBS"
	  LIBS="$LIBS -lresolv"
	  AC_MSG_CHECKING([for res_hnok in -lresolv])
	  AC_LINK_IFELSE(
	      [ OBSD_TEST_PROG_RES_HNOK ],
	      [ AC_MSG_RESULT([yes])
		AC_DEFINE([HAVE_RES_HNOK], [1], [Have res_hnok()])],
	      [ LIBS="$saved_LIBS"
	        AC_MSG_RESULT([no])]) ])
])
