#include "UserParameterRepository.h"

#include "Core/DataObject.h"
#include "UserParameter/DataAccess/IUserParameterDAO.h"
#include "UserParameter/Domain/UserParameter.h"
#include "UserParameter/Factories/UserParameterFactory.h"
#include "UserParameter/Domain/UserParameterFile.h"

using userparameter::repositories::UserParameterRepository;
using userparameter::dataaccess::IUserParameterDAO;
using userparameter::domain::UserParameter;
using userparameter::domain::UserParameterFile;
using userparameter::factories::UserParameterFactory;

UserParameterRepository::UserParameterRepository(std::unique_ptr<IUserParameterDAO> userParameterDao) :
	_dao(std::move(userParameterDao))
{
}


UserParameterRepository::~UserParameterRepository()
{
}

std::unique_ptr<UserParameter>
UserParameterRepository::getUserParameter(const UserParameterFile& file)
{
	UserParameterFactory factory;

	core::DataObject dto = _dao->get(file.getPath());
	std::unique_ptr<UserParameter> parameter = factory.createUserParameter(dto);
	return std::move(parameter);
}
