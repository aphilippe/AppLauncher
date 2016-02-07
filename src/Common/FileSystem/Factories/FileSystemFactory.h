#pragma once
#include <memory>
#include "FileSystem/FileSystem.h"

namespace clt { namespace filesystem { namespace factories {

	class FileSystemFactory {
	public:
		std::unique_ptr<clt::filesystem::FileSystem> createFileSystem();
	};

} } }