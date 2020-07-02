/**
 * @file    Log.h
 * @brief   Wrapper to spdlog for the lexer
 * 
 * @author  BP Harris
 * @date    July 2020
 */

#pragma once

#include "EnclosureLexer_pch.h"
#include "LexerCore.h"

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"


#define LEXER_FATAL(...)    ::Log::LexerLog->fatal(__VA_ARGS__)		/**< Log from lexer at level fatal. */
#define LEXER_ERROR(...)    ::Log::LexerLog->error(__VA_ARGS__)		/**< Log from lexer at level error. */
#define LEXER_WARN(...)     ::Log::LexerLog->warn(__VA_ARGS__)		/**< Log from lexer at level warn. */
#define LEXER_INFO(...)     ::Log::LexerLog->info(__VA_ARGS__)		/**< Log from lexer at level info. */
#define LEXER_TRACE(...)    ::Log::LexerLog->trace(__VA_ARGS__)		/**< Log from lexer at level trace. */


namespace Log {

	/** The log console for lexer output. */
	std::shared_ptr<spdlog::logger> LexerLog;


	/** Initialise the lexer log console. */
	void Init()
	{
		spdlog::set_pattern("%^[%T] [%n] %v%$");

		LexerLog = spdlog::stdout_color_mt("EnclosureLexer");
		LexerLog->set_level(spdlog::level::trace);
	}
}
