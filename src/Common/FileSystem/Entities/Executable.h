#pragma once

#include "FileSystem/Entities/Path.h"
#include "FileSystem/Entities/Validators/IPathValidator.h"
#include <memory>

namespace clt { namespace filesystem {
	namespace operations {
		class IExecutableLauncher;
	}
	namespace entities {

	class Executable
	{
	public:
		Executable(const Path & path, 
			std::shared_ptr<clt::filesystem::operations::IExecutableLauncher> launcher, 
			const clt::filesystem::entities::validators::IPathValidator & validator);

		virtual ~Executable();
		
		void execute();
		
		const Path& getPath() const;
		
	private:
		Path _path;
		std::shared_ptr<clt::filesystem::operations::IExecutableLauncher> _launcher;
	};

} } }