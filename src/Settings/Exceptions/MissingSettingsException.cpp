#include "MissingSettingsException.h"
#include <sstream>

using settings::exceptions::MissingSettingsException;

MissingSettingsException::MissingSettingsException(const std::string& missingSetting)
{
	std::ostringstream stringStream;

	stringStream << "Please set the folowin settings" << std::endl
		<< "\t - " << missingSetting << std::endl;
	this->setMessage(stringStream.str());
}


MissingSettingsException::~MissingSettingsException()
{
}
