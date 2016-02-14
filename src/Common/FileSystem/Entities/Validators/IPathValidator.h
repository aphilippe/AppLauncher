#ifndef IPathValidador_h
#define IPathValidador_h

#include "FileSystem/FileSystem.h"
#include "FileSystem/Entities/Path.h"

namespace clt { namespace filesystem { namespace entities { namespace validators {

class IPathValidator {
public:
	virtual bool isPathValid(const Path& path) const = 0;

	//TODO: get reasons of failure
};

} } } }
#endif /* IPathValidador_h */
