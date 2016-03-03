#pragma once

#include <memory>

#include "Application/Parameters/ApplicationParametersBuilder.h"
#include "Application/Parameters/ApplicationParameters.h"
#include "Application/Parameters/ApplicationParametersReader.h"

namespace application {
	namespace parameters {

class ApplicationParametersManager
{
public:
	ApplicationParametersManager(std::unique_ptr<ApplicationParametersBuilder> builder,	std::unique_ptr<ApplicationParametersReader> reader);
	virtual ~ApplicationParametersManager();

	void start(int argc, char* argv[]);
	ApplicationParameters& getParameters() const;


private:
	std::unique_ptr<ApplicationParametersBuilder> _builder;
	std::unique_ptr<ApplicationParameters> _parameters;
	std::unique_ptr<ApplicationParametersReader> _reader;

};

} }