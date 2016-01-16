#pragma once
#include "FileSystem/Path/IPath.h"


namespace filesystem {

	class FolderPath : public IPath
	{
	public:
		FolderPath(const std::string & value);
		virtual ~FolderPath();

		// Inherited via IPath
		virtual std::string value() override;
	private:
		std::string _value;
	};

}