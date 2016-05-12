#pragma once

#include "Core/DataObject.h"
class File;

namespace core {
	namespace parsers {

	class JSONParser
	{
	public:
		JSONParser();
		virtual ~JSONParser();

		core::DataObject parse(FILE* file);
	};

}}