#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "../src/my_stack.hpp"

TEST_CASE("Stack test", "[single-file]")
{
    sm::stack_t s1;
    s1.push(1);
    REQUIRE(s1.empty() == 0);
    REQUIRE(s1.size() == 1);
    REQUIRE(s1.get_top() == 1);
    s1.push(2);
    REQUIRE(s1.empty() == 0);
    REQUIRE(s1.size() == 2);
    REQUIRE(s1.get_top() == 2);
    REQUIRE(s1.get_top(1) == 1);
    s1.push(3);
    REQUIRE(s1.empty() == 0);
    REQUIRE(s1.size() == 3);
    REQUIRE(s1.get_top() == 3);
    REQUIRE(s1.get_top(1) == 2);
    REQUIRE(s1.get_top(2) == 1);
    
    
    REQUIRE(s1.pop() == 3);
    REQUIRE(s1.empty() == 0);
    REQUIRE(s1.size() == 2);

    REQUIRE(s1.pop() == 2);
    REQUIRE(s1.empty() == 0);
    REQUIRE(s1.size() == 1);

    REQUIRE(s1.pop() == 1);
    REQUIRE(s1.empty() == 1);
    REQUIRE(s1.size() == 0);
}
