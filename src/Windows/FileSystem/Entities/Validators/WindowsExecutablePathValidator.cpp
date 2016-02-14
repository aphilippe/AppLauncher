#include "WindowsExecutablePathValidator.h"

using namespace clt::filesystem;
using namespace clt::filesystem::entities;
using namespace clt::filesystem::entities::validators;

bool clt::filesystem::entities::validators::WindowsExecutablePathValidator::isPathValid(const Path & path) const
{
	// TODO: path must exist, be a file and with .exe extension
	return path.exists() 
		&& !path.isDirectory()
		&& path.getFileExtension() == ".exe";
}
