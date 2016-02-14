#pragma once

#include <memory>
#include "FileSystem/Entities/Validators/IPathValidator.h"

namespace  clt { namespace filesystem { namespace entities { namespace validators {
	class WindowsExecutablePathValidator : public IPathValidator
	{
	public:
		// Inherited via IPathValidator
		virtual bool isPathValid(const Path & path, const clt::filesystem::FileSystem & fileSystem) const override;
	};

} } } }