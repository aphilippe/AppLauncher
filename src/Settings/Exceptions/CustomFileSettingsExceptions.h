#ifndef CUSTOMFILESETTINGSEXCEPTIONS_H
#define CUSTOMFILESETTINGSEXCEPTIONS_H

#include "Core/Exceptions/Exception.h"

namespace settings { namespace exceptions {

class DuplicateLabelCustomFileSettingsException : public core::Exception
{
public:
    DuplicateLabelCustomFileSettingsException(const std::string& label);
    virtual ~DuplicateLabelCustomFileSettingsException() {}
};

}}

#endif // CUSTOMFILESETTINGSEXCEPTIONS_H
