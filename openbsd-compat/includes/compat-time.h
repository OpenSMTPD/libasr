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

#ifndef timersub
#define timersub(a, b, result)                                  \
   do {                                                         \
      (result)->tv_sec = (a)->tv_sec - (b)->tv_sec;             \
      (result)->tv_usec = (a)->tv_usec - (b)->tv_usec;          \
      if ((result)->tv_usec < 0) {                              \
         --(result)->tv_sec;                                    \
         (result)->tv_usec += 1000000;                          \
      }                                                         \
   } while (0)
#endif

#ifndef timespeccmp
#define timespeccmp(a, b, cmp)                                  \
        (((a)->tv_sec == (b)->tv_sec) ?                         \
         ((a)->tv_nsec cmp (b)->tv_nsec) :                      \
         ((a)->tv_sec cmp (b)->tv_sec))
#endif

#ifndef timespecsub
#define timespecsub(a, b, result)                               \
   do {                                                         \
      (result)->tv_sec = (a)->tv_sec - (b)->tv_sec;             \
      (result)->tv_nsec = (a)->tv_nsec - (b)->tv_nsec;          \
      if ((result)->tv_nsec < 0) {                              \
         --(result)->tv_sec;                                    \
         (result)->tv_nsec += 1000000000L;                      \
      }                                                         \
   } while (0)
#endif


#ifndef HAVE_CLOCK_GETTIME
int clock_gettime(clockid_t clk_id, struct timespec *tp);
#endif
