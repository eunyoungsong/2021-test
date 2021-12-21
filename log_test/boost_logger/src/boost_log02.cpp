/* 2 단계 : 사고 심각도에 따라서 출력 할지 정하기 */
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

namespace logging = boost::log;

void init()
{
    /*
    logging::core::get()->set_filter
    (
        // info 이상의 경고만 출력 됨. 
        logging::trivial::severity >= logging::trivial::info
    );
    */
   
}

int main(int, char*[])
{
    init();

    using namespace boost::log::trivial;
	boost::log::sources::severity_logger< severity_level > lg;
    
    BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
    BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
    BOOST_LOG_TRIVIAL(info) << "An informational severity message";
    BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
    BOOST_LOG_TRIVIAL(error) << "An error severity message";
    //BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";
    BOOST_LOG_SEV(lg, fatal) << "fatal";

    return 0;
}