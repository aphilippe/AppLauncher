#pragma once
#include <string>

namespace settings { namespace domain {

class Settings
{
public:
	Settings(const std::string& executablPath);
	virtual ~Settings();

	std::string getExecutablePath() const;

private:
	std::string _executablePath;
};

} }