/**
 * @file    Core.h
 * @brief   EnclosureLexer core defines
 * 
 * @author  BP Harris
 * @date    July 2020
 */

#pragma once


/* SharedLib/DLL declspecs */
#if defined ENC_PLATFORM_WINDOWS
	#ifdef ENC_BUILD_DLL
		#define LEXER_API __declspec(dllexport)
	#else
		#define LEXER_API __declspec(dllimport)
	#endif // ENC_BUILD_DLL
#elif defined ENC_PLATFORM_LINUX
	#define LEXER_API __attribute__ ((visibility ("default")))
#else
	#error EnclosureLexer only supports Windows/Linux, thus far.
#endif // ENC_PLATFORM_WINDOWS
