#include "EnclosureLexer_pch.h"
#include "TestLexer.h"

#include "Lexer/Log.h"


namespace Lexer {

	void Init()
	{
		Log::Init();
		LEXER_INFO("Success.");
	}

}
