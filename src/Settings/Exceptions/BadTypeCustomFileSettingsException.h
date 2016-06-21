#pragma once
#include "Core/Exceptions/Exception.h"

namespace settings {
	namespace exceptions {

		class BadTypeCustomFileSettingsException : public core::Exception
		{
		public:
			BadTypeCustomFileSettingsException(const std::string& filePath, const std::string& keyPath, const std::string& formatWanted);
			virtual ~BadTypeCustomFileSettingsException();
		};

	}
}
