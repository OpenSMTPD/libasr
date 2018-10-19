AC_DEFUN([OPENBSD_CHECK_FUNCTIONS], [
    AC_CHECK_FUNCS(     \
        clock_gettime	\
        explicit_bzero  \
        fgetln		\
        freezero        \
        getline		\
        reallocarray    \
        recallocarray   \
        strlcat         \
        strlcpy         \
	strsep		\
        strtonum
    )
])
