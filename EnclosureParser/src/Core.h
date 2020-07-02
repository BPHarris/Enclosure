/**
 * @file    Core.h
 * @brief   EnclosureParser core defines
 * 
 * @author  BP Harris
 * @date    July 2020
 */

#pragma once


/* SharedLib/DLL declspecs */
#ifdef ENC_PLATFORM_WINDOWS
	#ifdef ENC_BUILD_DLL
		#define PARSER_API __declspec(dllexport)
	#else
		#define PARSER_API __declspec(dllimport)
	#endif // ENC_BUILD_DLL
#elif defined ENC_PLATFORM_LINUX
	#define PARSER_API __attribute__ ((visibility ("default")))
#else
	#error EnclosureParser only supports Windows/Linux, thus far.
#endif // ENC_PLATFORM_WINDOWS
