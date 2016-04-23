#include "UserParameterRepository.h"

#include "UserParameter/DataAccess/IUserParameterDAO.h"

using userparameter::repositories::UserParameterRepository;
using userparameter::dataaccess::IUserParameterDAO;

UserParameterRepository::UserParameterRepository(std::unique_ptr<userparameter::dataaccess::IUserParameterDAO> userParameterDao) :
	_dao(std::move(userParameterDao))
{
}


UserParameterRepository::~UserParameterRepository()
{
}
