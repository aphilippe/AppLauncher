#include "Executable.h"
#include "FileSystem/Operations/IExecutableLauncher.h"

using namespace clt::filesystem::operations;
using namespace clt::filesystem::entities;
using namespace clt::filesystem::entities::validators;

Executable::Executable(const Path & path, std::shared_ptr<IExecutableLauncher> launcher, const IPathValidator & validator) : _path(path), _launcher(launcher)
{
	if (!validator.isPathValid(path)) {
		// TODO: real exception
		throw "invalid path";
	}
}

Executable::~Executable()
{
}

void
Executable::execute() {
	_launcher->execute(_path);
}

const Path&
Executable::getPath() const
{
	return _path;
}