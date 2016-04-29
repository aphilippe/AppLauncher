#include "UserParameterFactory.h"
#include "UserParameter/Domain/UserParameter.h"

using userparameter::factories::UserParameterFactory;

UserParameterFactory::UserParameterFactory()
{
}


UserParameterFactory::~UserParameterFactory()
{
}

std::unique_ptr<userparameter::domain::UserParameter> userparameter::factories::UserParameterFactory::createUserParameter(const core::DataObject & data)
{
	return std::unique_ptr<userparameter::domain::UserParameter>();
}
