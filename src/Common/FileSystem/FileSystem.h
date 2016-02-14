#pragma once

#include <memory>

#include "FileSystem/Entities/Path.h"
#include "FileSystem/Operations/IExecutableLauncher.h"
#include "FileSystem/Operations/IFileInformationReader.h"

namespace clt { namespace filesystem {

	/*enum AccessPermission {
		Read = 1 <<	0,
		Right = 1 << 1,
		Execute = 1 << 2
	};

	inline AccessPermission operator|(AccessPermission a, AccessPermission b)
	{
		return static_cast<AccessPermission>(static_cast<int>(a) | static_cast<int>(b));
	}*/

	class FileSystem
	{
	public:
		FileSystem(std::unique_ptr<operations::IExecutableLauncher> executableLauncher, std::unique_ptr<operations::IFileInformationReader> fileInformationReader);
		FileSystem(FileSystem* otherSystem) {};
		virtual ~FileSystem();

		virtual void execute(const clt::filesystem::entities::Path& path) const;

		virtual bool pathExists(const clt::filesystem::entities::Path& path) const;
		virtual bool pathIsDirectory(const clt::filesystem::entities::Path& path) const;

	private:
		std::unique_ptr<clt::filesystem::operations::IExecutableLauncher> _executableLauncher;
		std::unique_ptr<clt::filesystem::operations::IFileInformationReader> _fileInformationReader;
	};

} }