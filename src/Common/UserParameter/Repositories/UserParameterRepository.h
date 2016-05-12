#pragma once

#include <memory>

namespace userparameter { namespace dataaccess {
	class IUserParameterDAO;
} }
namespace userparameter { namespace domain {
		class UserParameter;
		class UserParameterFile;
} }

namespace userparameter { namespace repositories { 
class UserParameterRepository
{
public:
	UserParameterRepository(std::unique_ptr<userparameter::dataaccess::IUserParameterDAO> userParameterDao);
	virtual ~UserParameterRepository();

	std::unique_ptr<userparameter::domain::UserParameter> getUserParameter(const userparameter::domain::UserParameterFile & file);

private:
	std::unique_ptr<userparameter::dataaccess::IUserParameterDAO> _dao;
};

}}