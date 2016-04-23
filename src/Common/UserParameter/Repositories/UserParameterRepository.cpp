#include "UserParameterRepository.h"

#include "UserParameter/DataAccess/IUserParameterDAO.h"
#include "UserParameter/DataAccess/UserParameterDTO.h"
#include "UserParameter/Domain/UserParameter.h"

using userparameter::repositories::UserParameterRepository;
using userparameter::dataaccess::IUserParameterDAO;
using userparameter::dataaccess::UserParameterDTO;
using userparameter::domain::UserParameter;

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
	std::unique_ptr<UserParameterDTO> dto(_dao->get());
	return std::make_unique<UserParameter>(dto->getBackupFolder(), dto->getFiles());
}
