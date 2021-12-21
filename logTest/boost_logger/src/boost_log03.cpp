/* 3 단계 : 기본적인 log 이상으로 나아가기 */
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>

namespace logging = boost::log;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;
namespace keywords = boost::log::keywords;

void init()
{
	logging::add_file_log("../../boost_logger/log/log03.log"); // text 파일로 저장 하는 sink

	logging::core::get()->set_filter
	(
		logging::trivial::severity >= logging::trivial::info
	);

}

int main()
{
	init();
	logging::add_common_attributes();

	using namespace logging::trivial;
	src::severity_logger< severity_level > lg;

	BOOST_LOG_SEV(lg, trace) << "A trace severity message ddd";
	BOOST_LOG_SEV(lg, debug) << "A debug severity message";
	BOOST_LOG_SEV(lg, info) << "An informational severity message";
	BOOST_LOG_SEV(lg, warning) << "A warning severity message";
	BOOST_LOG_SEV(lg, error) << "An error severity message";
	BOOST_LOG_SEV(lg, fatal) << "A fatal severity message";

	return true;
}