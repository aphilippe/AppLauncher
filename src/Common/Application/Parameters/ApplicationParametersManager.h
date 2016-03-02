#pragma once

#include <memory>

#include "Application/Parameters/ApplicationParametersBuilder.h"
#include "Application/Parameters/ApplicationParameters.h"

namespace application {
	namespace parameters {

class ApplicationParametersManager
{
public:
	ApplicationParametersManager(std::unique_ptr<ApplicationParametersBuilder> builder);
	virtual ~ApplicationParametersManager();

	void start(char* argv[]);
	ApplicationParameters& getParameters() const;


private:
	std::unique_ptr<ApplicationParametersBuilder> _builder;
	std::unique_ptr<ApplicationParameters> _parameters;

};

} }