#include "Executable.h"

using namespace clt::system::entities;

Executable::Executable(const Path & path, std::unique_ptr<clt::system::operations::IExecutableLauncher> launcher) : _path(path)
{
	_launcher = std::move(launcher);
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