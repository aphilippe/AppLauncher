#ifndef WIN32  

#include "ExecuteOperation.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>

using file_system::operations::ExecuteOperation;
using file_system::Path;

void ExecuteOperation::execute(const Path& path)
{
	pid_t cpid;

	cpid = fork();

	switch (cpid) {
	case -1: perror("fork");
		break;

	case 0:
		execl(path.stringValue().c_str(), path.stringValue().c_str(), NULL, NULL); /* this is the child */
		_exit(EXIT_FAILURE);
		break;

	default: waitpid(cpid, NULL, 0);
	}
}

#endif