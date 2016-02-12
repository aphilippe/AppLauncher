#ifndef UnixExecutablePathValidator_hpp
#define UnixExecutablePathValidator_hpp

#include <stdio.h>
#include "FileSystem/Entities/IPathValidator.h"

namespace clt { namespace filesystem { namespace entities { namespace validator {
	
	class UnixExecutablePathValidator : public IPathValidator {
	public:
		bool isPathValid(const Path& path) const override;
	};
	
} } } }

#endif /* UnixExecutablePathValidator_hpp */
