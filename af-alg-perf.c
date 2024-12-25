#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <linux/if_alg.h>

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;
    int tfm_fd = socket(AF_ALG, SOCK_SEQPACKET, 0);
    if (-1 == tfm_fd)
    {
        printf("socket(): %s\n", strerror(errno));
        return 0;
    }

    struct sockaddr_alg sa = {0};
    sa.salg_family = AF_ALG;
    memcpy(sa.salg_type, "acomp", strlen("acomp"));
    memcpy(sa.salg_name, "deflate", strlen("deflate"));

    if (-1 == bind(tfm_fd, (struct sockaddr *)&sa, sizeof(sa)))
    {
        printf("bind() error: %d, %s\n", errno, strerror(errno));
    }

    close(tfm_fd);

    return 0;
}
