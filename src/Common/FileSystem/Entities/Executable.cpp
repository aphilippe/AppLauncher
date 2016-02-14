#include "Executable.h"

using namespace clt::filesystem;
using namespace clt::filesystem::entities;
using namespace clt::filesystem::entities::validators;

Executable::Executable(const Path & path, std::unique_ptr<FileSystem> fileSystem, const IPathValidator & validator) : _path(path)
{
	if (!validator.isPathValid(path)) {
		// TODO: real exception
		throw "invalid path";
	}
	
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