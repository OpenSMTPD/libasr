lib_LTLIBRARIES = 	libasr.la

libasr_la_SOURCES  =	asr.c
libasr_la_SOURCES +=	asr_debug.c
libasr_la_SOURCES +=	asr_compat.c
libasr_la_SOURCES +=	asr_utils.c
libasr_la_SOURCES +=	getaddrinfo_async.c
libasr_la_SOURCES +=	gethostnamadr_async.c
libasr_la_SOURCES +=	getnameinfo_async.c
libasr_la_SOURCES +=	getnetnamadr_async.c
libasr_la_SOURCES +=	res_search_async.c
libasr_la_SOURCES +=	res_send_async.c

include_HEADERS =	asr.h

libasr_la_CPPFLAGS =	-I$(builddir)/../openbsd-compat/include
libasr_la_LIBADD =	$(builddir)/../openbsd-compat/libopenbsdcompat.a
libasr_la_LDFLAGS =	-version-info 0:3:0

EXTRA_DIST =		asr_compat.h
EXTRA_DIST +=		asr_private.h
