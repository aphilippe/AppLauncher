#include "ValidatorBrokenRules.h"

using namespace clt::filesystem::entities::validators;

ValidatorBrokenRules::ValidatorBrokenRules(const std::string & description) : _description(description)
{
}


ValidatorBrokenRules::~ValidatorBrokenRules()
{
}

std::string ValidatorBrokenRules::getDescription() const
{
	return _description;
}
