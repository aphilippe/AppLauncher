#pragma once
#include "FileSystem/Path/IPath.h"
#include "FileSystem/Path/FolderPath.h"

namespace filesystem {

	class FilePath : public IPath
	{
	public:
		FilePath(FolderPath folderPath);
		virtual ~FilePath();

	private:
		FolderPath _folderPath;
		// fileName : name + extension


		// Inherited via IPath
		virtual std::string value() override;

	};

}
