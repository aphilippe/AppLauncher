#include "InvalidExecutablePathException.h"

using namespace clt::filesystem::entities::exceptions;

InvalidExecutablePathException::InvalidExecutablePathException(const std::vector<clt::filesystem::entities::validators::ValidatorBrokenRules> & brokenRules) : _brokenRules(brokenRules)
{
}


InvalidExecutablePathException::~InvalidExecutablePathException()
{
}

std::string InvalidExecutablePathException::getDescription() const
{
	std::string description = "";
	for (auto it = _brokenRules.begin(); it != _brokenRules.end(); it++) {
		description.append(it->getDescription());
		description.append("\n");
	}

	return description;
}
