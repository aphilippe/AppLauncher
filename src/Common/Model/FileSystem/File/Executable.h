#pragma once

#include "FileSystem/File/File.h"

namespace filesystem {

	class Executable : public File
	{
	public:
		Executable(const FilePath & path);
		virtual ~Executable();
	};

}