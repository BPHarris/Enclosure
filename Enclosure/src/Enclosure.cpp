/**
 * @file    Enclosure.cpp
 * @brief   Enclosure compiler entry point.
 * 
 * @author  BP Harris
 * @date    July 2020
 */

#include "Enclosure_pch.h"

#include "Lexer.h"
#include "Parser.h"


int main(int argc, char** argv)
{
	Lexer::Init();
	Parser::Init();

	while (true);

	return 0;
}
