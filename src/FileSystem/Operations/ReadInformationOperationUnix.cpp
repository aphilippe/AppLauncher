#include "ReadInformationOperation.h"

#ifndef WIN32  

#include <unistd.h>
#include <sys/stat.h>

using file_system::operations::ReadInformationOperation;

using file_system::Path;


bool ReadInformationOperation::isExecutable(const Path & path) const
{
	struct stat  st;

	if (stat(path.stringValue().c_str(), &st) < 0)
		return false;

	return (st.st_mode & S_IEXEC) != 0;
}

#endif