#pragma once

#include <memory>

namespace userparameter { namespace dataaccess { 
	class IUserParameterDAO;
} }

namespace userparameter { namespace repositories { 
class UserParameterRepository
{
public:
	UserParameterRepository(std::unique_ptr<userparameter::dataaccess::IUserParameterDAO> userParameterDao);
	virtual ~UserParameterRepository();

	//TODO: getUserParameter
	//TODO: manage cache

private:
	std::unique_ptr<userparameter::dataaccess::IUserParameterDAO> _dao;
};

}}