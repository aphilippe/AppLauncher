#include "BadTypeCustomFileSettingsException.h"
#include <sstream>

using settings::exceptions::BadTypeCustomFileSettingsException;
using core::Exception;

BadTypeCustomFileSettingsException::BadTypeCustomFileSettingsException(const std::string& filePath, const std::string& keyPath, const std::string& formatWanted)
	: Exception()
{
	std::ostringstream stringStream;
	stringStream << "Error bad type for settings at path : " << std::endl
		<< "\t" << filePath << std::endl
		<< std::endl
		<< "\"" << keyPath << "\" "<< "should be \"" << formatWanted << "\"" << std::endl;
	this->setMessage(stringStream.str());
}


BadTypeCustomFileSettingsException::~BadTypeCustomFileSettingsException()
{
}
