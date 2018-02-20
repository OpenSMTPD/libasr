#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <asr.h>

int main() {
    struct asr_query *query;
    struct asr_result result;
    const char *hostname = "localhost";

    query = gethostbyname_async(hostname, NULL);
    asr_run_sync(query, &result);
    if (errno != 0) {
            printf("asr run error: %s\n", strerror(errno));
            return 1;
    }
    return 0;
}
