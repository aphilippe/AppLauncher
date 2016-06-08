#pragma once

#include "Settings/DataAccess/CustomFileSettingsDAO.h"

namespace settings {
	namespace dataaccess {

	class ConcreteCustomFileSettingsDAO : public CustomFileSettingsDAO
	{
	public:
		ConcreteCustomFileSettingsDAO();
		virtual ~ConcreteCustomFileSettingsDAO();
	};

} }