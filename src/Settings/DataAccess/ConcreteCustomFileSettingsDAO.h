#pragma once

#include "Settings/DataAccess/CustomFileSettingsDAO.h"

namespace settings {
	namespace dataaccess {

	class ConcreteCustomFileSettingsDAO : public CustomFileSettingsDAO
	{
	public:
		ConcreteCustomFileSettingsDAO(const std::string& filePath);
		virtual ~ConcreteCustomFileSettingsDAO();

		// Inherited via CustomFileSettingsDAO
		virtual settings::domain::CustomFileSettings get() override;
		
	private:
		std::string _filePath;
	};

} }