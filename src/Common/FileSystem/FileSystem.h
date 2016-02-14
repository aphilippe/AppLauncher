#pragma once

#include <memory>

#include "FileSystem/Entities/Path.h"
#include "FileSystem/Operations/IExecutableLauncher.h"
#include "FileSystem/Operations/IPathInformationReader.h"

namespace clt { namespace filesystem {

	class FileSystem
	{
	public:
		FileSystem(std::unique_ptr<operations::IExecutableLauncher> executableLauncher, std::unique_ptr<operations::IPathInformationReader> fileInformationReader);
		FileSystem(FileSystem* otherSystem) {};
		virtual ~FileSystem();

		virtual void execute(const clt::filesystem::entities::Path& path) const;

		virtual bool pathExists(const clt::filesystem::entities::Path& path) const;
		virtual bool pathIsDirectory(const clt::filesystem::entities::Path& path) const;

	private:
		std::unique_ptr<clt::filesystem::operations::IExecutableLauncher> _executableLauncher;
		std::unique_ptr<clt::filesystem::operations::IPathInformationReader> _fileInformationReader;
	};

} }