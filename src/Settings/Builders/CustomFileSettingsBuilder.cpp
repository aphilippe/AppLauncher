#include "CustomFileSettingsBuilder.h"

using settings::builders::CustomFileSettingsBuilder;
using settings::domain::CustomFileSettings;

CustomFileSettings CustomFileSettingsBuilder::build()
{
	return settings::domain::CustomFileSettings("plop");
}