#pragma once

#include "System/Entities/Path.h"
#include "System/Operations/IExecutableLauncher.h"
#include <memory>

namespace clt { namespace system { namespace entities {

	class Executable
	{
	public:
		Executable(const Path & path, std::unique_ptr<operations::IExecutableLauncher> launcher);
		virtual ~Executable();
		
		void execute();
		
		const Path& getPath() const;
		
	private:
		Path _path;
		std::unique_ptr<operations::IExecutableLauncher> _launcher;
	};

} } }