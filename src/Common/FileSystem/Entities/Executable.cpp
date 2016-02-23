#include "Executable.h"
#include "FileSystem/Operations/IExecutableLauncher.h"
#include "FileSystem/Entities/Exceptions/InvalidExecutablePathException.h"

using namespace clt::filesystem::operations;
using namespace clt::filesystem::entities;
using namespace clt::filesystem::entities::validators;
using namespace clt::filesystem::entities::exceptions;

Executable::Executable(const Path & path, std::shared_ptr<IExecutableLauncher> launcher, const IPathValidator & validator) : _path(path), _launcher(launcher)
{
	std::vector<ValidatorBrokenRules> brokenRules;
	if (!validator.isPathValid(path, brokenRules)) {
		// TODO: real exception
		throw InvalidExecutablePathException(brokenRules);
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