#pragma once

#include "Core/Exceptions/Exception.h"
#include "FileSystem/Path.h"

namespace launcher { namespace exceptions {

	class BackupFolderInvalidPermissionException : public core::Exception
	{
	public:
		BackupFolderInvalidPermissionException(const file_system::Path& path);
		virtual ~BackupFolderInvalidPermissionException(){}
	};


	class BackupFolderNotAFolderException : public core::Exception
	{
	public:
		BackupFolderNotAFolderException(const file_system::Path& path);
		virtual ~BackupFolderNotAFolderException() {}
	};


	class BackuFolderpNotFoundException : public core::Exception
	{
	public:
		BackuFolderpNotfoundException(const file_system::Path& path);
		virtual ~BackuFolderpNotfoundException() {}
	};
} }