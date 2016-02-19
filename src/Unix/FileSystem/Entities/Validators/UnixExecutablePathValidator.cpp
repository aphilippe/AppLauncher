#include "UnixExecutablePathValidator.h"

using namespace clt::filesystem::entities;
using namespace clt::filesystem::entities::validators;

bool
UnixExecutablePathValidator::isPathValid(const Path& path) const {
//TODO: must be a file with executable right
	return path.exists()
		&& !path.isDirectory()
		&& path.isExecutable();
}