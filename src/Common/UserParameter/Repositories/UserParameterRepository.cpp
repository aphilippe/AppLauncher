#include "UserParameterRepository.h"

#include "Core/DataObject.h"
#include "UserParameter/DataAccess/IUserParameterDAO.h"
#include "UserParameter/Domain/UserParameter.h"
#include "UserParameter/Factories/UserParameterFactory.h"

using userparameter::repositories::UserParameterRepository;
using userparameter::dataaccess::IUserParameterDAO;
using userparameter::domain::UserParameter;
using userparameter::factories::UserParameterFactory;

UserParameterRepository::UserParameterRepository(std::unique_ptr<IUserParameterDAO> userParameterDao) :
	_dao(std::move(userParameterDao))
{
}


UserParameterRepository::~UserParameterRepository()
{
}

std::unique_ptr<UserParameter>
UserParameterRepository::getUserParameter()
{
	UserParameterFactory factory;

	core::DataObject dto = _dao->get();
	std::unique_ptr<UserParameter> parameter = factory.createUserParameter(dto);
	return std::move(parameter);
}
