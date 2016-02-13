#ifndef IPathValidador_h
#define IPathValidador_h

#include "FileSystem/Entities/Path.h"

namespace clt { namespace filesystem { namespace entities { namespace validators {

class IPathValidator {
public:
	virtual bool isPathValid(const Path& path) const = 0;
};

} } } }
#endif /* IPathValidador_h */
