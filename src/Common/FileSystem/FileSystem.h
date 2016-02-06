#pragma once

#include <memory>

#include "FileSystem/Entities/Path.h"
#include "FileSystem/Operations/IExecutableLauncher.h"

namespace clt { namespace filesystem {

	class FileSystem
	{
	public:
		FileSystem(std::unique_ptr<operations::IExecutableLauncher> executableLauncher);
		virtual ~FileSystem();

		virtual void execute(const clt::filesystem::entities::Path& path);
		//virtual AccessPermission getAccessPermission(const clt::filesystem::entities::Path& path) = 0;

	private:
		std::unique_ptr<clt::filesystem::operations::IExecutableLauncher> _executableLauncher;
	};

} }