#include "Executable.h"
#include "FileSystem/Operations/ExecuteOperation.h"

using launcher::domain::Executable;
using file_system::operations::ExecuteOperation;

Executable::Executable(const file_system::Path& path)
	: _path(path)
{
}


Executable::~Executable()
{
}

void Executable::execute()
{
	ExecuteOperation operation;
	operation.execute(_path);
}
