#pragma once
#include "FileSystem/Path.h"

namespace launcher { namespace domain {

class Executable
{
public:
	Executable(const file_system::Path& path);
	virtual ~Executable();

	void execute();

private:
	file_system::Path _path;
};

} }