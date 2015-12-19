#pragma once
#include "FileSystem/Path/FilePath.h"

namespace filesystem {

	class File
	{
	public:
		File(const FilePath & path);
		virtual ~File();

		virtual FilePath path();

	private:
		FilePath _path;
	};

}

