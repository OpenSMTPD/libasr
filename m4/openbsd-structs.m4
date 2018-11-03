AC_DEFUN([OPENBSD_CHECK_STRUCTS], [
	AC_CHECK_MEMBERS([struct sockaddr.sa_len], , ,
		[ #include <netdb.h>
	          #include <netinet/in.h>
		  #include <sys/socket.h> ]
	)
	AC_CHECK_MEMBERS([struct sockaddr_storage.ss_len], , ,
		[ #include <netdb.h>
	          #include <netinet/in.h>
		  #include <sys/socket.h> ]
	)
	AC_CHECK_MEMBERS([struct sockaddr_in.sin_len], , ,
		[ #include <netdb.h>
	          #include <netinet/in.h>
		  #include <sys/socket.h> ]
	)
	AC_CHECK_MEMBERS([struct sockaddr_in6.sin6_len], , ,
		[ #include <netdb.h>
	          #include <netinet/in.h>
		  #include <sys/socket.h> ]
	)
])
