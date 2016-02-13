#pragma once

#include "FileSystem/Entities/Validators/IPathValidator.h"

namespace  clt { namespace filesystem { namespace entities { namespace validators {
	class WindowsExecutablePathValidator : public IPathValidator
	{
	public:
		// Inherited via IPathValidator
		virtual bool isPathValid(const Path & path) const override;

	};

} } } }