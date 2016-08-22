#pragma once
#include "FileSystem/Path.h"

namespace file_system { namespace operations {

class ExecuteOperation
{
public:
	ExecuteOperation() {};
	virtual ~ExecuteOperation() {};

	void execute(const file_system::Path& path);
};

} }
