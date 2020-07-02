#include "EnclosureParser_pch.h"
#include "TestParser.h"

#include "Parser/Log.h"


namespace Parser {

	void Init()
	{
		Log::Init();
		PARSER_INFO("Success.");
	}

}
