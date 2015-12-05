#pragma once
#include "Model/Path/FilePath.h"

class File
{
public:
	File(const FilePath & path);
	virtual ~File();

	virtual FilePath path();

private:
	FilePath _path;
};

