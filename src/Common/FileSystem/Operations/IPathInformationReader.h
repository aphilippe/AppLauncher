#pragma once

#include "FileSystem/Entities/Path.h"

namespace clt { namespace filesystem { namespace operations {

	class IPathInformationReader
	{
	public:
		IPathInformationReader() {};
		virtual ~IPathInformationReader() {};

		// Return if the file exists
		virtual bool exists(const clt::filesystem::entities::Path & path) const = 0;

		virtual bool isDirectory(const clt::filesystem::entities::Path & path) const = 0;

		virtual std::string getFileExtension(const clt::filesystem::entities::Path & path) const = 0;
	};

} } }