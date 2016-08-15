#pragma once
#include "Core/Exceptions/Exception.h"
#include "FileSystem/Path.h"

namespace file_system { namespace exceptions {
	class CopyOperationSourceNotAFileException : core::Exception
	{
	public:
		CopyOperationSourceNotAFileException(const file_system::Path& path);
		virtual ~CopyOperationSourceNotAFileException() {};
	};

	class CopyOperationDestinationNotAFolderException : core::Exception
	{
	public:
		CopyOperationDestinationNotAFolderException(const file_system::Path& path);
		virtual ~CopyOperationDestinationNotAFolderException() {};
	};

} }