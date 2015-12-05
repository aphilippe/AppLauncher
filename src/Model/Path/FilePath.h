#pragma once
#include "Model/Path/IPath.h"
#include "Model/Path/FolderPath.h"

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

