#pragma once
#include <string>
// Folder Path : 
// File Path : FolderPath + File
// File : Name + extension
// Executable : File + isExecutable

// create interface Path -> FolderPath, FilePath
class IPath
{
public:

	virtual std::string value() = 0;
};

