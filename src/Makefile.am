lib_LTLIBRARIES = libasr.la

libasr_la_SOURCES =	asr.c asr_debug.c asr_utils.c getaddrinfo_async.c	\
			gethostnamadr_async.c getnameinfo_async.c		\
			getnetnamadr_async.c res_search_async.c res_send_async.c

#openbsd-compat
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/arc4random.c
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/base64.c
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/bsd-closefrom.c
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/bsd-getpeereid.c
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/bsd-misc.c
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/bsd-waitpid.c
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/clock_gettime.c
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/entropy.c
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/explicit_bzero.c
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/fgetln.c
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/fmt_scaled.c
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/getopt.c
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/imsg.c
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/imsg-buffer.c
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/mktemp.c
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/pw_dup.c
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/reallocarray.c
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/setresguid.c
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/strlcat.c
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/strlcpy.c
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/strmode.c
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/strtonum.c
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/strsep.c
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/xmalloc.c

include_HEADERS =	asr.h

libasr_la_CPPFLAGS =	-I$(top_srcdir)/src -I$(top_srcdir)/openbsd-compat

libasr_la_CFLAGS=	-DASR_OPT_THREADSAFE=0

libasr_la_LDFLAGS=	-release 5.5.0 -version-info 0:0:0

EXTRA_DIST =		asr_private.h
