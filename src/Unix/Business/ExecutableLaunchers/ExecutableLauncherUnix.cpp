#include "ExecutableLauncherUnix.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>


void ExecutableLauncherUnix::start()
{
	pid_t cpid;
	
	cpid = fork();
	
	switch (cpid) {
		case -1: perror("fork");
			break;
			
		case 0:
			execl("path to executable", ""); /* this is the child */
			_exit(EXIT_FAILURE);
			break;
			
		default: waitpid(cpid, NULL, 0);
	}
}