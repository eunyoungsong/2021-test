
//=========================logger.h
#ifndef __LOGGER_H__
#define __LOGGER_H__ 1

#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstdarg>
#include <ctime>
#include <sstream>
#include <cstring>
#include <cstdio>

#define LOG_LEVEL_OFF 0
#define LOG_LEVEL_FATAL 10
#define LOG_LEVEL_ERROR 20
#define LOG_LEVEL_WARN 30
#define LOG_LEVEL_INFO 40
#define LOG_LEVEL_DEBUG 50
#define LOG_LEVEL_TRACE 60
#define LOG_LEVEL_ALL 100

#define __LOG_FILE__ "../log/log_test_07.txt"
#define fatal(str, ...) writeLog(__FUNCTION__, __LINE__, LOG_LEVEL_FATAL, str, __VA_ARGS__)
#define error(str, ...) writeLog(__FUNCTION__, __LINE__, LOG_LEVEL_ERROR, str, __VA_ARGS__)
#define warn(str, ...) writeLog(__FUNCTION__, __LINE__, LOG_LEVEL_WARN, str, __VA_ARGS__)
#define info(str, ...) writeLog(__FUNCTION__, __LINE__, LOG_LEVEL_INFO, str, __VA_ARGS__)
#define debug(str, ...) writeLog(__FUNCTION__, __LINE__, LOG_LEVEL_DEBUG, str, __VA_ARGS__)
#define trace(str, ...) writeLog(__FUNCTION__, __LINE__, LOG_LEVEL_TRACE, str, __VA_ARGS__)


using namespace std;

class Logger {
private:
    int logLevel;
    bool isOutput;
    string getTimestamp();
    
public:
    Logger();
    Logger(int level);
    void writeLog(const char *funcName, int line, int level, const char *str, ...);
};

static Logger log;

#endif

//=========================logger.cpp
//#include "logger.h"

Logger::Logger()
{
    this->logLevel = LOG_LEVEL_ERROR;
}

Logger::Logger(int level)
{
    this->logLevel = level;
}

string Logger::getTimestamp()
{
    string result;
    time_t currentSec = time(NULL);
    tm *t = localtime(&currentSec);
    ostringstream oss;

    switch(t->tm_mon)
    {
        case(0): result = "Jan"; break;
        case(1): result = "Feb"; break;
        case(2): result = "Mar"; break;
        case(3): result = "Apr"; break;
        case(4): result = "May"; break;
        case(5): result = "Jun"; break;
        case(6): result = "Jul"; break;
        case(7): result = "Aug"; break;
        case(8): result = "Sep"; break;
        case(9): result = "Oct"; break;
        case(10): result = "Nov"; break;
        case(11): result = "Dec"; break;
    }

    oss.clear();
    oss << " " << setfill('0') << setw(2) << t->tm_mday << " " << t->tm_year+1900;
    oss << " " << setfill('0') << setw(2) << t->tm_hour;
    oss << ":" << setfill('0') << setw(2) << t->tm_min;
    oss << ":" << setfill('0') << setw(2) << t->tm_sec << '\0';

    result = result + oss.str();

    return result;
}

void Logger::writeLog(const char *funcName, int line, int lv, const char *str, ...)
{
    FILE *fp = NULL;
    fp = fopen(__LOG_FILE__, "a");

    if(fp == NULL)
    {
        puts("fail to open file pointer");
        return;
    }

    char *result = NULL;
    char level[10];

    switch(lv)
    {
        case(LOG_LEVEL_FATAL): strcpy(level, "[FATAL]"); break;
        case(LOG_LEVEL_ERROR): strcpy(level, "[ERROR]"); break;
        case(LOG_LEVEL_WARN): strcpy(level, "[WARN] "); break;
        case(LOG_LEVEL_INFO): strcpy(level, "[INFO] "); break;
        case(LOG_LEVEL_DEBUG): strcpy(level, "[DEBUG]"); break;
        case(LOG_LEVEL_TRACE): strcpy(level, "[TRACE]"); break;
    }
    
    result = (char*)malloc(sizeof(char)*(21+strlen(funcName)+strlen(str)+30));
    sprintf(result, "%s %s [%s:%d] : %s\n", level, getTimestamp().c_str(), funcName, line, str);

    va_list args;

    va_start(args, str);
    vfprintf(fp, result, args);
    va_end(args);

    va_start(args, str);
    if(this->logLevel >= lv)
    {
        vprintf(result, args);
    }
    va_end(args);

    if(result != NULL)
    {
        free(result);
    }
    if(fp != NULL)
    {
        fclose(fp);
    }

    return;
}

//=========================main
//#include "logger.h"
int main()
{
    Logger test(LOG_LEVEL_WARN);
    test.fatal("fatal", 1);
    test.error("error", 1);
    test.warn("warn", 1);
    test.info("info", 1);
    test.debug("debug", 1);
    test.trace("trace", 1);
    return 0;
}