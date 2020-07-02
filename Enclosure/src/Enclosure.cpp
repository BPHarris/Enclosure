/**
 * @file    Enclosure.cpp
 * @brief   Enclosure compiler entry point.
 * 
 * @author  BP Harris
 * @date    July 2020
 */

#include "Enclosure_pch.h"


namespace Lexer {

    __declspec(dllimport) void Lex();

}

namespace Parser {

	__declspec(dllimport) void Parse();

}


int main(int argc, char** argv)
{
	Lexer::Lex();
	return 0;
}
