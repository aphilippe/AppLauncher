#pragma once

#include "System/Entities/Path.h"
#include "System/Operations/IExecutableLauncher.h"

namespace clt { namespace system { namespace entities {

	class Executable
	{
	public:
		Executable(const Path & path, std::unique_ptr<operations::IExecutableLauncher> launcher);
		virtual ~Executable();
		
		void execute();
		
	private:
		Path _path;
		std::unique_ptr<operations::IExecutableLauncher> _launcher;
	};

} } }