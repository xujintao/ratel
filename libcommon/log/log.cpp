#include "log.h"
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/thread/thread.hpp>
#include <boost/log/core.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/common.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/sinks.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/setup/formatter_parser.hpp>
#include <boost/log/utility/empty_deleter.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/severity_feature.hpp>
#include <fstream>

namespace logging = boost::log;
namespace attrs = boost::log::attributes;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;
namespace expr = boost::log::expressions;
namespace keywords = boost::log::keywords;


BOOST_LOG_INLINE_GLOBAL_LOGGER_DEFAULT(my_logger, src::severity_logger_mt<severity_level>)

namespace common {

std::ostream& operator<< (std::ostream& strm, severity_level level)
{
    static std::array<std::string, 7> aLevel = {
    "trace",
    "debug",
    "info",
    "warning",
    "error",
    "fatal",
    "report"
    };

    if (static_cast<std::size_t>(level) < aLevel.size())
        strm << aLevel[level];
    else
        strm << static_cast<int>(level);
    return strm;
}

void InitLog() {
    typedef sinks::synchronous_sink<sinks::text_file_backend> FileSink;
    typedef sinks::synchronous_sink<sinks::text_ostream_backend> StreamSink;

    // init sink1  
    auto backend1 = boost::make_shared<sinks::text_file_backend>(
        keywords::open_mode = std::ios::app,
        keywords::file_name = "ratel.%Y-%m-%d.%N.log",
        keywords::rotation_size = 10 * 1024 * 1024,
        keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0),
        keywords::min_free_space = 30 * 1024 * 1024);
    backend1->auto_flush(true);
    auto sink1 = boost::make_shared<FileSink>(backend1);
    sink1->set_formatter(
        expr::format("[%1%]<%2%>(%3%): %4%")
        % expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d %H:%M:%S")
        % expr::attr<severity_level>("Severity")
        % expr::attr<attrs::current_thread_id::value_type >("ThreadID")
        % expr::smessage
    );
    //sink1->set_filter(expr::attr<severity_level>("Severity") >= warning);
    logging::core::get()->add_sink(sink1);

#ifdef DEBUG
    // init sink2 
    boost::shared_ptr<sinks::text_ostream_backend> backend2 = boost::make_shared<sinks::text_ostream_backend>();
    backend2->add_stream(
        boost::shared_ptr<std::ostream>(&std::clog, logging::empty_deleter()));
    backend2->auto_flush(true);
    boost::shared_ptr<StreamSink> sink2(new StreamSink(backend2));
    sink2->set_formatter(
        expr::format("[%1%]: %2%")
        % expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d %H:%M:%S")
        % expr::smessage
    );
    //sink2->set_filter(expr::attr<severity_level>("Severity") == report);
    logging::core::get()->add_sink(sink2);
#endif

    logging::add_common_attributes();
    logging::core::get()->add_global_attribute("ThreadID", attrs::current_thread_id());
}

int Log(severity_level level, const char* fmt, ...)
{
    int ret;
    char str[1024] = { 0 };
    va_list ap;
    va_start(ap, fmt);
    ret = vsprintf(str, fmt, ap);
    BOOST_LOG_SEV(my_logger::get(), level) << str;
    return ret;
}

}