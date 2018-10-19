/*
 * Copyright (c) 2018 Eric Faurot <eric@openbsd.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef SA_LEN
#  if defined(HAVE_STRUCT_SOCKADDR_SA_LEN)
#    define SA_LEN(x)  ((x)->sa_len)
#  else
#    define SA_LEN(x)  ((x)->sa_family == AF_INET6 ? \
        sizeof(struct sockaddr_in6) : \
        sizeof(struct sockaddr_in))
#  endif
#endif

#ifndef SS_LEN
#  if defined(HAVE_STRUCT_SOCKADDR_SS_LEN)
#    define SS_LEN(x)  ((x)->ss_len)
#  else
#    define SS_LEN(x)  ((x)->ss_family == AF_INET6 ? \
        sizeof(struct sockaddr_in6) : \
        sizeof(struct sockaddr_in))
#  endif
#endif
