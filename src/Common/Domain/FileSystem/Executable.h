#pragma once

#include "Domain/FileSystem/Path.h"

namespace filesystem {

	class Executable
	{
	public:
		Executable(const Path & path);
		virtual ~Executable();
		
		void execute();
		
	private:
		Path _path;
	};

}