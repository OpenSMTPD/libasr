lib_LTLIBRARIES = libasr.la

libasr_la_SOURCES =	asr.c asr_debug.c asr_utils.c getaddrinfo_async.c	\
			gethostnamadr_async.c getnameinfo_async.c		\
			getnetnamadr_async.c res_search_async.c res_send_async.c

#openbsd-compat
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/arc4random.c
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/fgetln.c
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/res_hnok.c
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/res_random.c
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/strlcat.c
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/strlcpy.c
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/strsep.c
libasr_la_SOURCES +=	$(top_srcdir)/openbsd-compat/strtonum.c

include_HEADERS =	asr.h

libasr_la_CPPFLAGS =	-I$(top_srcdir)/src -I$(top_srcdir)/openbsd-compat

libasr_la_CFLAGS=	-DASR_OPT_THREADSAFE=0

libasr_la_LDFLAGS=	-version-info 0:2:0 -lcrypto

libasr_MANPAGES=	asr_run.3.out
libasr_MANPAGES_IN=	asr_run.3

EXTRA_DIST =		asr_private.h $(libasr_MANPAGES_IN)

$(libasr_MANPAGES): $(libasr_MANPAGES_IN)
	manpage=`echo $@ | sed 's/\.out$$//'`; \
	if test "$(MANTYPE)" = "man"; then \
		$(CAT) $${manpage} | $(AWK) -f $(top_srcdir)/mk/mdoc2man.awk > $@; \
	else \
		$(CAT) $${manpage} > $@; \
	fi

install-exec-hook: $(libasr_MANPAGES)
	$(MKDIR_P) $(DESTDIR)$(mandir)/$(mansubdir)3
	$(INSTALL) -m 644 asr_run.3.out		$(DESTDIR)$(mandir)/$(mansubdir)3/asr_run.3
	rm	asr_run.3.out
