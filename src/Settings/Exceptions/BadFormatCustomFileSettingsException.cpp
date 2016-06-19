#include "BadFormatCustomFileSettingsException.h"

using settings::exceptions::BadFormatCustomFileSettingsException;
using core::Exception;
using std::string;

BadFormatCustomFileSettingsException::BadFormatCustomFileSettingsException(const string& filePath) 
	: Exception()
{
	this->setMessage(string("Error bad format for settings file at path : ") + filePath);
}


BadFormatCustomFileSettingsException::~BadFormatCustomFileSettingsException()
{
}