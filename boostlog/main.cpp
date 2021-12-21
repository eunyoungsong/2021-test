#include "exception.hpp"
#include "include.hpp"
#include "my_epoll.hpp"
#include "my_logger.hpp"
#include "my_manager.hpp"
#include "my_option.hpp"
#include "my_socket.hpp"

SocketManager manager;

void SignalCallbackHandler(int signal);

int main(const int argc, const char * argv[])
{
    /* 로그객체 생성 */
    init_log();
    BOOST_LOG_NAMED_SCOPE("main");
    BOOST_LOG_TRIVIAL(trace) << "Strart main.";

    /* 시그널 설정 */
    signal(SIGINT, SignalCallbackHandler);    

    try
    {   
        /* 옵션설정 */
        BOOST_LOG_TRIVIAL(trace) << "Try to options.";

        OptionParser optparser;
        Options_t opt = optparser.parse(argc, argv);

        /* 프로그램 실행 */
        BOOST_LOG_TRIVIAL(trace) << "Try to process.";
        //SocketManager manager;  
        manager.Process(opt);

    }
    catch(const std::exception& e)
    {
        /* 에러처리 */
        std::cerr << e.what() << '\n';
        BOOST_LOG_TRIVIAL(error) << "main exception.";
        return 1;
    }
    
    return 0;
}

// ctrl c
void SignalCallbackHandler(int signal)
{
    //BOOST_LOG_FUNCTION();
    BOOST_LOG_TRIVIAL(debug) << "Singnal Callback().";
    manager.Close_all();
    
    if (signal == SIGINT)
		manager.StopWorking();
    
    BOOST_LOG_TRIVIAL(debug) << "Exit the program.";
    exit(0);
}
