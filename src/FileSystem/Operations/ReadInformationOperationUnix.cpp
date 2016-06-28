#include "ReadInformationOperation.h"

#ifdef linux

#include <unistd.h>
#include <sys/stat.h>

using file_system::operations::ReadInformationOperation;

using file_system::Path;

bool ReadInformationOperation::exists(const Path & path) const
{
	return access(path.getValue().c_str(), F_OK) == 0;
}

bool ReadInformationOperation::isDirectory(const Path & path) const
{
	if (!this->exists(path))
	{
		return false;
	}
	struct stat st_buf;
	stat(path.getValue().c_str(), &st_buf);

	return S_ISDIR(st_buf.st_mode);
}

bool ReadInformationOperation::isFile(const Path & path) const
{
	if (!this->exists(path))
	{
		return false;
	}
	struct stat st_buf;
	stat(path.getValue().c_str(), &st_buf);

	return !S_ISDIR(st_buf.st_mode);
}

bool ReadInformationOperation::isExecutable(const Path & path) const
{
	struct stat  st;

	if (stat(path.getValue().c_str(), &st) < 0)
		return false;

	return (st.st_mode & S_IEXEC) != 0;
}


#endif