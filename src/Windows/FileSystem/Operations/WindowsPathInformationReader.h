#pragma once

#include "FileSystem/Operations/IPathInformationReader.h"

namespace clt { namespace filesystem { namespace operations {

	class WindowsPathInformationReader : public IPathInformationReader
	{
	public:
		WindowsPathInformationReader();
		virtual ~WindowsPathInformationReader();

		// Inherited via IFileInformationReader
		virtual bool exists(const clt::filesystem::entities::Path & path) const override;

		virtual bool isDirectory(const clt::filesystem::entities::Path & path) const override;

		// Inherited via IFileInformationReader
		virtual std::string getFileExtension(const clt::filesystem::entities::Path & path) const override;

		bool isExecutable(const clt::filesystem::entities::Path & path) const override;
	};

} } }