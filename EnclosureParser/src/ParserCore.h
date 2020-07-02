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
	#endif
#endif

#ifdef ENC_PLATFORM_LINUX
	#define PARSER_API __attribute__ ((visibility ("default")))
#endif

#ifndef PARSER_API
	#error EnclosureParser only supports Windows/Linux, thus far.
#endif
