#pragma once

#include <string>

namespace application { namespace parameters {

	class ApplicationParameters
	{
	public:
		ApplicationParameters(const std::string & executablePath);
		virtual ~ApplicationParameters();

		std::string getExecutablePath();

	private:
		std::string _executablePath;
	};

} }