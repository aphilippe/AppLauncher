#include "WindowsExecutablePathValidator.h"

using namespace clt::filesystem;
using namespace clt::filesystem::entities;
using namespace clt::filesystem::entities::validators;

bool clt::filesystem::entities::validators::WindowsExecutablePathValidator::isPathValid(const Path & path, std::vector<ValidatorBrokenRules> & brokenRules) const
{
	if (!path.exists()) {
		brokenRules.push_back(ValidatorBrokenRules("Path does not exist"));
		return false;
	}

	if (path.isDirectory()) {
		brokenRules.push_back(ValidatorBrokenRules("The path is not a file"));
		return false;
	}

	if (!path.isExecutable()) {
		brokenRules.push_back(ValidatorBrokenRules("File at path is not executable"));
		return false;
	}

	return true;
}
