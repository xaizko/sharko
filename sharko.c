#include <stdio.h>
#include <stdlib.h>
#include <pty.h>
#include <unistd.h>

static int32_t masterfd;
int main() {

    if (forkpty(&masterfd, NULL, NULL, NULL) == 0) {
	execlp("/usr/bin/bash", "bash", NULL);
	perror("execlp");
	exit(1);
    }

    return 0;
}
