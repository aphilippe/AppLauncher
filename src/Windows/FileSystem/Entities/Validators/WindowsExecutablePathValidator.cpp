#include "WindowsExecutablePathValidator.h"

using namespace clt::filesystem::entities;
using namespace clt::filesystem::entities::validators;

bool WindowsExecutablePathValidator::isPathValid(const Path & path) const
{
	// TODO: path must be a file and with executable rights
	return true;
}
