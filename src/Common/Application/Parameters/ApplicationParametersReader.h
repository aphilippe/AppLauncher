#ifndef ApplicationParametersReader_hpp
#define ApplicationParametersReader_hpp

#include <stdio.h>
#include <functional>

namespace application { namespace parameters {

	class ApplicationParametersReader {
	public:
		void start(int argc, char* argv[]) const;
		
		void setOnExecutablePath(std::function<void (const std::string&)> func);
		void setOnBackupParametersFilePath(std::function<void (const std::string&)> func);
		
	private:
		std::function<void (const std::string&)> _onExecutablePath;
		std::function<void (const std::string&)> _onBackupParametersFilePath;
	};
	
} }

#endif /* ApplicationParametersReader_hpp */
