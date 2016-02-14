#pragma once

#include "FileSystem/Operations/IFileInformationReader.h"

namespace clt { namespace filesystem { namespace operations {

	class WindowsFileInformationReader : public IFileInformationReader
	{
	public:
		WindowsFileInformationReader();
		virtual ~WindowsFileInformationReader();

		// Inherited via IFileInformationReader
		virtual bool exists(const clt::filesystem::entities::Path & path) const override;


		// Inherited via IFileInformationReader
		virtual bool isDirectory(const clt::filesystem::entities::Path & path) const override;

	};

} } }