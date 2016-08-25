#pragma once

#include "Core/Exceptions/Exception.h"
#include "FileSystem/Path.h"

namespace launcher {
	namespace exceptions {
		class FileToRestoreInvalidPathException : public core::Exception
		{
		public:
			FileToRestoreInvalidPathException(const file_system::Path& path);
			virtual ~FileToRestoreInvalidPathException() {}
		};


		class FileToRestoreInvalidPermissionException : public core::Exception
		{
		public:
			FileToRestoreInvalidPermissionException(const file_system::Path& path);
			virtual ~FileToRestoreInvalidPermissionException() {}
		};


		class FileToRestoreNotAFileException : public core::Exception
		{
		public:
			FileToRestoreNotAFileException(const file_system::Path& path);
			virtual ~FileToRestoreNotAFileException() {}
		};


		class FileToRestoreNotNotfoundException : public core::Exception
		{
		public:
			FileToRestoreNotNotfoundException(const file_system::Path& path);
			virtual ~FileToRestoreNotNotfoundException() {}
		};

	}
}