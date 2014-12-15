lib_LTLIBRARIES = libasr.la

libasr_la_SOURCES =	asr.c asr_debug.c asr_utils.c getaddrinfo_async.c	\
			gethostnamadr_async.c getnameinfo_async.c		\
			getnetnamadr_async.c res_search_async.c res_send_async.c

#openbsd-compat
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/fgetln.c
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/log.c
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/res_hnok.c
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/strlcat.c
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/strlcpy.c
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/strsep.c
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/strtonum.c
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/xmalloc.c

include_HEADERS =	asr.h

libasr_la_CPPFLAGS =	-I$(top_srcdir)/src -I$(top_srcdir)/openbsd-compat

libasr_la_CFLAGS=	-DASR_OPT_THREADSAFE=0

libasr_la_LDFLAGS=	-release 0.9.0 -version-info 0:0:0

EXTRA_DIST =		asr_private.h
