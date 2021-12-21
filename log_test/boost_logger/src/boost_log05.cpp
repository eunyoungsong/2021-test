/* 4 단계 : logger 객체 사용하기 */
#include <boost/move/utility.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/sources/global_logger_storage.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

namespace logging = boost::log;
namespace src = boost::log::sources;
namespace keywords = boost::log::keywords;

BOOST_LOG_INLINE_GLOBAL_LOGGER_DEFAULT(my_logger, src::logger_mt) 

void logging_function() 
{ 
	src::logger_mt& lg = my_logger::get(); 
	BOOST_LOG(lg) << "Greetings from the global logger!";
} 
	
int main(int, char*[]) 
{ 
	logging::add_file_log("../../boost_logger/log/log05.log"); 
	logging::add_common_attributes(); 

	return 0; 
}
