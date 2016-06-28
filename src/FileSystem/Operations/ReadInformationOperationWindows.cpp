#include "ReadInformationOperation.h"

#ifdef WIN32

#include <Windows.h>
#include "Shlwapi.h"

using file_system::operations::ReadInformationOperation;

using file_system::Path;

bool ReadInformationOperation::exists(const Path & path) const
{
	return PathFileExists(path.stringValue().c_str());
}

bool ReadInformationOperation::isDirectory(const Path & path) const
{
	if (!this->exists(path))
	{
		return false;
	}
	return PathIsDirectory(path.stringValue().c_str());
}

bool ReadInformationOperation::isFile(const Path & path) const
{
	if (!this->exists(path))
	{
		return false;
	}
	return !PathIsDirectory(path.stringValue().c_str());
}

bool ReadInformationOperation::isExecutable(const Path & path) const
{
	SHFILEINFOA sfi = { 0 };
	DWORD_PTR hr = SHGetFileInfo((LPCTSTR)path.stringValue().c_str(),
		-1,
		&sfi,
		sizeof(sfi),
		SHGFI_EXETYPE);

	return hr != 0;
}

#endif