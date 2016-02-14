#pragma once

#include <string>
#include "FileSystem/Entities/Path.h"

namespace clt { namespace filesystem { namespace factories {
	class EntityFactory {
	public:
		clt::filesystem::entities::Path createPath(const std::string & path) const;
	};

} } }