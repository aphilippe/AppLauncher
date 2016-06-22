#pragma once
#include "Core/Exceptions/Exception.h"

namespace settings {
	namespace exceptions {

		class MissingSettingsException : public core::Exception
		{
		public:
			MissingSettingsException(const std::string& missingSetting);
			virtual ~MissingSettingsException();
		};

	}
}