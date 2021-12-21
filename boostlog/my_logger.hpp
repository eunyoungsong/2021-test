#include <iostream>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <fstream>

#include <netinet/in.h>
#include <arpa/inet.h>
#include <pcap.h>
#include <cstdlib>
#include <signal.h>
#include <fcntl.h>

#include <sys/epoll.h>
#include <sys/socket.h>

#include <unordered_map>


#pragma warning(push)
#pragma warning(disable:4819)
#   include <boost/shared_ptr.hpp>
#   include <boost/date_time/posix_time/posix_time_types.hpp>
#   include <boost/log/trivial.hpp>
#   include <boost/log/core.hpp>
#   include <boost/log/expressions.hpp>
#   include <boost/log/sources/logger.hpp>
#   include <boost/log/utility/setup/file.hpp>
#   include <boost/log/utility/setup/console.hpp>
#   include <boost/log/utility/setup/common_attributes.hpp>
#   include <boost/log/support/date_time.hpp>
#   include <boost/log/sinks/sync_frontend.hpp>
#   include <boost/log/sinks/text_file_backend.hpp>
#   include <boost/log/sinks/text_ostream_backend.hpp>
#   include <boost/log/attributes/named_scope.hpp>

#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/sources/severity_feature.hpp>
#include <boost/filesystem.hpp>

#pragma warning(pop)
#pragma warning(disable:4503)

/*
class Logger
{
public:
    boost::log::sources::severity_logger<boost::log::trivial::severity_level> lg;

    void init_log();

    void Trace(std::string msg);
    void Debug(std::string msg);
    void Info(std::string msg);
    void Warning(std::string msg);
    void Error(std::string msg);
    void Fatal(std::string msg);
};
*/

inline void init_log()
{
    /* init boost log */
    boost::log::add_common_attributes(); // enables timestamps and such
    boost::log::core::get()->add_global_attribute("Scope", boost::log::attributes::named_scope());
    boost::log::core::get()->set_filter( boost::log::trivial::severity >= boost::log::trivial::debug); // 레벨 설정 

    /* log formatter:
     * [TimeStamp] [ThreadId] [Severity Level] [Scope] Log message
     */
    auto fmtTimeStamp = boost::log::expressions::format_date_time<boost::posix_time::ptime>("TimeStamp", "%Y-%m-%d %H:%M:%S.%f");
    auto fmtThreadId = boost::log::expressions::attr<boost::log::attributes::current_thread_id::value_type>("ThreadID");
    auto fmtSeverity = boost::log::expressions::attr<boost::log::trivial::severity_level>("Severity");
    auto fmtScope = boost::log::expressions::format_named_scope
    (   "Scope",
        boost::log::keywords::format = "%n(%f:%l)",
        boost::log::keywords::iteration = boost::log::expressions::reverse,
        boost::log::keywords::depth = 2
    );

    boost::log::formatter logFmt = boost::log::expressions::format("[%1%] (%2%) [%3%] [%4%] %5%")
        % fmtTimeStamp % fmtThreadId % fmtSeverity % fmtScope % boost::log::expressions::smessage;

    //boost::log::formatter logFmt = boost::log::expressions::format("[%1%] (%2%) [%3%] %4%")
    //    % fmtTimeStamp % fmtThreadId % fmtSeverity % boost::log::expressions::smessage;

    /* console sink */
    auto consoleSink = boost::log::add_console_log(std::clog);
    consoleSink->set_formatter(logFmt);

    /* fs sink */
    auto fsSink = boost::log::add_file_log
    (
        boost::log::keywords::file_name = "../async_test/log/%Y-%m-%d_%H-%M.log",
        boost::log::keywords::rotation_size = 10 * 1024 * 1024,
        boost::log::keywords::min_free_space = 30 * 1024 * 1024,
        boost::log::keywords::time_based_rotation = boost::log::sinks::file::rotation_at_time_point(0, 0, 0),
        boost::log::keywords::open_mode = std::ios_base::app        // app: 각 삽입 전에 스트림의 끝에 검색을 지정합니다. 
    ); 
    fsSink->set_formatter(logFmt);
    fsSink->locked_backend()->auto_flush(true); // 자동 버퍼 플러시 수행 

}

/*
void Test(void)
{
    BOOST_LOG_FUNCTION();
    BOOST_LOG_TRIVIAL(info) << "Info Log in Test()";
}
*/

/*
void Logger::Trace(std::string msg)
{
    BOOST_LOG_TRIVIAL(trace) << msg;
}
void Logger::Debug(std::string msg)
{
    BOOST_LOG_TRIVIAL(debug) << msg;
}
void Logger::Info(std::string msg)
{
    BOOST_LOG_TRIVIAL(info) << msg;
}
void Logger::Warning(std::string msg)
{
    BOOST_LOG_TRIVIAL(warning) << msg;
}
void Logger::Error(std::string msg)
{
    BOOST_LOG_TRIVIAL(error) << msg;
}
void Logger::Fatal(std::string msg)
{
    BOOST_LOG_TRIVIAL(fatal) << msg;
}
*/