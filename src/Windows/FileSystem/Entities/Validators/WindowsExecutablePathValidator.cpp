#include "WindowsExecutablePathValidator.h"

using namespace clt::filesystem;
using namespace clt::filesystem::entities;
using namespace clt::filesystem::entities::validators;

bool clt::filesystem::entities::validators::WindowsExecutablePathValidator::isPathValid(const Path & path, const clt::filesystem::FileSystem & fileSystem) const
{
	// TODO: path must exist, be a file and with .exe extension
	return fileSystem.pathExists(path) 
		&& !fileSystem.pathIsDirectory(path);
}
