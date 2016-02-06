#pragma once

#include "FileSystem/Entities/Path.h"
#include "FileSystem/FileSystem.h"
#include <memory>

namespace clt { namespace filesystem { namespace entities {

	class Executable
	{
	public:
		Executable(const Path & path, std::unique_ptr<clt::filesystem::FileSystem> fileSystem);
		virtual ~Executable();
		
		void execute();
		
		const Path& getPath() const;
		
	private:
		Path _path;
		std::unique_ptr<clt::filesystem::FileSystem> _fileSystem;
	};

} } }