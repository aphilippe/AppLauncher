#pragma once
#include "FileSystem/Path.h"

namespace file_system { namespace factories {

class PathFactory
{
public:
	PathFactory();
	virtual ~PathFactory();

	file_system::Path createPath(const std::string& pathString);
};

} }