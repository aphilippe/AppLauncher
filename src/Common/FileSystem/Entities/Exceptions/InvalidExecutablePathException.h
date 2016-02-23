#pragma once

#include "FileSystem/Entities/Validators/ValidatorBrokenRules.h"
#include <vector>

namespace clt {
	namespace filesystem {
		namespace entities {
			namespace exceptions {

class InvalidExecutablePathException
{
public:
	InvalidExecutablePathException(const std::vector<clt::filesystem::entities::validators::ValidatorBrokenRules> & brokenRules);
	~InvalidExecutablePathException();

	std::string getDescription() const;

private:

	std::vector<clt::filesystem::entities::validators::ValidatorBrokenRules> _brokenRules;
};

			}
		}
	}
}