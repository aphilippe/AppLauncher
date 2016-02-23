#ifndef IPathValidador_h
#define IPathValidador_h

#include <vector>

#include "FileSystem/Entities/Validators/ValidatorBrokenRules.h"
#include "FileSystem/FileSystem.h"
#include "FileSystem/Entities/Path.h"

namespace clt { namespace filesystem { namespace entities { namespace validators {

class IPathValidator {;;
public:
	virtual bool isPathValid(const Path& path, std::vector<ValidatorBrokenRules> & brokenRules) const = 0;
};

} } } }
#endif /* IPathValidador_h */
