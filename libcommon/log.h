#pragma once

#include <boost/log/sinks.hpp>  
#include <boost/log/sources/logger.hpp>  
#include <boost/log/utility/setup/common_attributes.hpp>  
#include <boost/log/utility/setup/common_attributes.hpp>  
#include <boost/log/utility/setup/formatter_parser.hpp>  
#include <boost/log/sources/severity_logger.hpp>  
#include <boost/log/sources/severity_feature.hpp>  
#include <fstream>  
namespace logging = boost::log;
namespace attrs = boost::log::attributes;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;
namespace expr = boost::log::expressions;
namespace keywords = boost::log::keywords;
enum sign_severity_level {
	trace,
	debug,
	info,
	warning,
	error,
	fatal,
	report
};
void InitLog();
BOOST_LOG_INLINE_GLOBAL_LOGGER_DEFAULT(my_logger, src::severity_logger_mt<sign_severity_level>)

//#define LOG(level) BOOST_LOG_SEV(my_logger, level)