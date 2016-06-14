#pragma once

#include "Settings/DataAccess/CustomFileSettingsDAO.h"

namespace settings {
	namespace dataaccess {

	class ConcreteCustomFileSettingsDAO : public CustomFileSettingsDAO
	{
	public:
		ConcreteCustomFileSettingsDAO();
		virtual ~ConcreteCustomFileSettingsDAO();

		// Inherited via CustomFileSettingsDAO
		virtual settings::domain::CustomFileSettings get() override;
	};

} }