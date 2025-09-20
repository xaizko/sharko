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

    bool running = true;

    fd_set fdset;
    while(running) {
	FD_ZERO(&fdset); // zero out set
	FD_SET(masterfd, &fdset); // watch masterfd for reading

	select(masterfd + 1, &fdset, NULL, NULL, NULL); // wait until reading

	// FD_ISSET lets you know there is data to be read
	if (FD_ISSET(masterfd, &fdset)) {
	    //readfrompty();
	}
    }

    return 0;
}
