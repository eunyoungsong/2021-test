#include <iostream>

#include <boost/log/common.hpp>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/setup/formatter_parser.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/severity_feature.hpp>
#include <boost/log/sources/record_ostream.hpp>

#include <boost/log/attributes.hpp>

using namespace std;

namespace logging = boost::log;
namespace expr = boost::log::expressions;
namespace attrs = boost::log::attributes;
namespace src = boost::log::sources;
namespace keywords = boost::log::keywords;

enum severity_level
{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL
};

BOOST_LOG_INLINE_GLOBAL_LOGGER_DEFAULT(my_logger, src::severity_logger_mt< severity_level> )

// The formatting logic for the severity level
template< typename CharT, typename TraitsT >
inline std::basic_ostream< CharT, TraitsT > &operator << ( std::basic_ostream< CharT, TraitsT >& strm, severity_level lvl )
{
    static const char* const str[] =
    {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR",
        "CRITICAL"
    };
    if (static_cast< std::size_t >(lvl) < (sizeof(str) / sizeof(*str)))
        strm << str[lvl];
    else
        strm << static_cast< int >(lvl);
    return strm;
}

void init() {
    // logging::register_simple_formatter_factory< severity_level >("Severity");
    logging::add_file_log(
            keywords::file_name = "blop.log",
            keywords::auto_flush = true,
            keywords::open_mode = (std::ios::out | std::ios::app),
            keywords::format = "%TimeStamp% [%Uptime%] (%LineID%) <%Severity%>: %Message%"
            );
    logging::add_common_attributes();
    logging::core::get()->add_global_attribute("Uptime", attrs::timer());
}

int main(int argc, const char *argv[]) {
    init();
    src::severity_logger_mt< severity_level > lg = my_logger::get();
    BOOST_LOG_SEV(lg, DEBUG) << "A debug severity message";
    BOOST_LOG_SEV(lg, INFO) << "An informational severity message";
    BOOST_LOG_SEV(lg, WARNING) << "A warning severity message";
    BOOST_LOG_SEV(lg, ERROR) << "An error severity message";
    BOOST_LOG_SEV(lg, CRITICAL) << "A critical severity message";
    return 0;
}