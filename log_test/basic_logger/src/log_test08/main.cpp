#include "logger.h"

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