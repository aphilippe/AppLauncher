#pragma once

#include "FileSystem/Entities/Path.h"

namespace clt { namespace filesystem { namespace operations {

	class IFileInformationReader
	{
	public:
		IFileInformationReader() {};
		virtual ~IFileInformationReader() {};

		// Return if the file exists
		virtual bool exists(const clt::filesystem::entities::Path & path) const = 0;

		virtual bool isDirectory(const clt::filesystem::entities::Path & path) const = 0;
	};

} } }