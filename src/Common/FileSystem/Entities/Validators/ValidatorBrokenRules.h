#pragma once
#include <string>

namespace clt { namespace filesystem { namespace entities { namespace validators {

class ValidatorBrokenRules
{
public:
	ValidatorBrokenRules(const std::string & string);
	virtual ~ValidatorBrokenRules();

	std::string getDescription() const;

private:
	std::string _description;
};

} } } }