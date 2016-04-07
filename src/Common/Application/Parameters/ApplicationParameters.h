#pragma once

#include <string>

namespace application { namespace parameters {

	class ApplicationParameters
	{
	public:
		ApplicationParameters(const std::string & executablePath, const std::string & backupParametersFilePath);
		virtual ~ApplicationParameters();

		std::string getExecutablePath();
		std::string getBackupParametersFilePath();

	private:
		std::string _executablePath;
		std::string _backupParametersFilePath;
	};

} }