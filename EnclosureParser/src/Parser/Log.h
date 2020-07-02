/**
 * @file    Log.h
 * @brief   Wrapper to spdlog for the parser
 *
 * @author  BP Harris
 * @date    July 2020
 */

#pragma once

#include "EnclosureParser_pch.h"
#include "ParserCore.h"

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"


#define PARSER_FATAL(...)    ::Log::ParserLog->fatal(__VA_ARGS__)		/**< Log from lexer at level fatal. */
#define PARSER_ERROR(...)    ::Log::ParserLog->error(__VA_ARGS__)		/**< Log from lexer at level error. */
#define PARSER_WARN(...)     ::Log::ParserLog->warn(__VA_ARGS__)		/**< Log from lexer at level warn. */
#define PARSER_INFO(...)     ::Log::ParserLog->info(__VA_ARGS__)		/**< Log from lexer at level info. */
#define PARSER_TRACE(...)    ::Log::ParserLog->trace(__VA_ARGS__)		/**< Log from lexer at level trace. */


namespace Log {

	/** The log console for parser output. */
	std::shared_ptr<spdlog::logger> ParserLog;


	/** Initialise the parser log console. */
	void Init()
	{
		spdlog::set_pattern("%^[%T] [%n] %v%$");

		ParserLog = spdlog::stdout_color_mt("EnclosureParser");
		ParserLog->set_level(spdlog::level::trace);
	}
}
