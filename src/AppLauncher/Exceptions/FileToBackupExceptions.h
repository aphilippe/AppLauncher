#pragma once

#include "Core/Exceptions/Exception.h"
#include "FileSystem/Path.h"

namespace launcher { namespace exceptions {

	class FileToBackupInvalidPathException : public core::Exception
	{
	public:
		FileToBackupInvalidPathException(const file_system::Path& path);
		virtual ~FileToBackupInvalidPathException() {}
	};


	class FileToBackupInvalidPermissionException : public core::Exception
	{
	public:
		FileToBackupInvalidPermissionException(const file_system::Path& path);
		virtual ~FileToBackupInvalidPermissionException(){}
	};


	class FileToBackupNotAFileException : public core::Exception
	{
	public:
		FileToBackupNotAFileException(const file_system::Path& path);
		virtual ~FileToBackupNotAFileException() {}
	};


	class FileToBackupNotNotfoundException : public core::Exception
	{
	public:
		FileToBackupNotNotfoundException(const file_system::Path& path);
		virtual ~FileToBackupNotNotfoundException() {}
	};

	class FileToBackupEmptyLabelExcetion : public core::Exception
	{
	public:
		FileToBackupEmptyLabelExcetion(const file_system::Path& path);
		virtual ~FileToBackupEmptyLabelExcetion() {}
	};
} }