#pragma once
#include "FileSystem/FileSystem.h"

namespace clt { namespace filesystem { namespace factories {

	class FileSystemFactory {
	public:
		clt::filesystem::FileSystem* newFileSystem();
	};

} } }