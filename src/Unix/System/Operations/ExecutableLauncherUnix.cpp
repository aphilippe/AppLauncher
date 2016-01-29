#include "ExecutableLauncherUnix.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>

using namespace clt::system::operations;

void ExecutableLauncherUnix::execute()
{
	pid_t cpid;
	
	cpid = fork();
	
	switch (cpid) {
		case -1: perror("fork");
			break;
			
		case 0:
			execl("", ""); /* this is the child */
			_exit(EXIT_FAILURE);
			break;
			
		default: waitpid(cpid, NULL, 0);
	}
}