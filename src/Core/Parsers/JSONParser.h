#pragma once

#include "Core/DataObject.h"

namespace core {
	namespace parsers {

	class JSONParser
	{
	public:
		JSONParser();
		virtual ~JSONParser();

		core::DataObject parse();
	};

}}