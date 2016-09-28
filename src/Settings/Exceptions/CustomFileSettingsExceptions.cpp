#include "CustomFileSettingsExceptions.h"
#include <sstream>

using settings::exceptions::DuplicateLabelCustomFileSettingsException;

DuplicateLabelCustomFileSettingsException::DuplicateLabelCustomFileSettingsException(const std::string& label)
{
    std::ostringstream stringStream;
    stringStream << "Duplicate label (" << label << ") in settings file" << std::endl;

    this->setMessage(stringStream.str());
}
