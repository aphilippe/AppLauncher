#include "Executable.h"

using namespace clt::filesystem;
using namespace clt::filesystem::entities;

Executable::Executable(const Path & path, std::unique_ptr<FileSystem> fileSystem) : _path(path)
{
	_fileSystem = std::move(fileSystem);
}

Executable::~Executable()
{
}

void
Executable::execute() {
	_fileSystem->execute(_path);
}

const Path&
Executable::getPath() const
{
	return _path;
}