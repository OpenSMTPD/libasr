SUBDIRS =		src

ACLOCAL_AMFLAGS =	-I m4

TESTS=			tests/asr_simple
check_PROGRAMS=		${TESTS}

tests_asr_simple_SOURCES=	tests/asr_simple.c
tests_asr_simple_LDADD=		src/libasr.la
