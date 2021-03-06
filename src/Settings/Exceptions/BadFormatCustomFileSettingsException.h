#pragma once
#include "Core/Exceptions/Exception.h"

namespace settings { namespace exceptions {

class BadFormatCustomFileSettingsException : public core::Exception
{
public:
	BadFormatCustomFileSettingsException(const std::string& filePath, const std::string& description);
	virtual ~BadFormatCustomFileSettingsException();
};

} }