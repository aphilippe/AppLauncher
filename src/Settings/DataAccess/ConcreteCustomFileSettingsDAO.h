#pragma once
#include <memory>

#include "Settings/DataAccess/CustomFileSettingsDAO.h"

namespace settings { namespace builders {
	class CustomFileSettingsBuilder;
}}

namespace settings {
	namespace dataaccess {

	class ConcreteCustomFileSettingsDAO : public CustomFileSettingsDAO
	{
	public:
		ConcreteCustomFileSettingsDAO(const std::string& filePath, std::unique_ptr<settings::builders::CustomFileSettingsBuilder> builder);
		virtual ~ConcreteCustomFileSettingsDAO();

		// Inherited via CustomFileSettingsDAO
		virtual settings::domain::CustomFileSettings get() override;
		
	private:
		std::string _filePath;
		std::unique_ptr<settings::builders::CustomFileSettingsBuilder> _builder;
	};

} }