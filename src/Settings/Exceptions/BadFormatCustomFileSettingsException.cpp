#include "BadFormatCustomFileSettingsException.h"
#include "RapidJSON/rapidjson.h"
#include <sstream>

using settings::exceptions::BadFormatCustomFileSettingsException;
using core::Exception;
using std::string;

BadFormatCustomFileSettingsException::BadFormatCustomFileSettingsException(const string& filePath, const std::string& description)
	: Exception()
{
	std::ostringstream stringStream;
	stringStream << "Error bad format for settings file at path : " << std::endl
		<< "\t - " << filePath << std::endl
		<< std::endl
		<< description << std::endl;
	this->setMessage(stringStream.str());
}


BadFormatCustomFileSettingsException::~BadFormatCustomFileSettingsException()
{
}