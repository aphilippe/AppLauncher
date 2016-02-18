#include "WindowsExecutablePathValidator.h"

using namespace clt::filesystem;
using namespace clt::filesystem::entities;
using namespace clt::filesystem::entities::validators;

bool clt::filesystem::entities::validators::WindowsExecutablePathValidator::isPathValid(const Path & path) const
{
	return path.exists() 
		&& !path.isDirectory()
		&& path.isExecutable();
}
