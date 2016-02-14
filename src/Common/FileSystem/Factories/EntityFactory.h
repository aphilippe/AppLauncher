#pragma once

#include <string>
#include "FileSystem/Entities/Path.h"
#include "FileSystem/Entities/Executable.h"

namespace clt { namespace filesystem { namespace factories {
	class EntityFactory {
	public:
		clt::filesystem::entities::Path createPath(const std::string & path) const;
		clt::filesystem::entities::Executable createExecutable(const std::string & path) const;
	};

} } }