dnl
dnl nanosleep()
dnl
AC_DEFUN([OBSD_NEED_NANOSLEEP], [
    AC_SEARCH_LIBS([nanosleep], [rt posix4],
        [AC_DEFINE([HAVE_NANOSLEEP], [1], [Some systems put nanosleep outside of libc])])
])

dnl
dnl clock_gettime()
dnl
AC_DEFUN([OBSD_NEED_CLOCK_GETTIME], [
    AC_SEARCH_LIBS([clock_gettime], [rt],
        [AC_DEFINE([HAVE_CLOCK_GETTIME], [1], [Have clock_gettime])])
])
