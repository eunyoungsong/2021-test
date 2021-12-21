#include <catch2/catch.hpp>

#include "../src/my_queue_c.h"
//#include "../src/my_queue_struct.h"
//#include "../src/my_queue.hpp"

TEST_CASE("C version Queue test", "[single-file]")
{
    int queue[10000 + 1] = {0,};
    int front_p = 0;
    int back_p = 0;

    push(queue, &back_p, 1);
    REQUIRE(front(queue, &front_p, &back_p)==1);
    REQUIRE(back(queue, &front_p, &back_p)==1);
    REQUIRE(empty(queue, &front_p, &back_p)==0);
    REQUIRE(size(queue, &front_p, &back_p)==1);
    push(queue, &back_p, 2);
    REQUIRE(empty(queue, &front_p, &back_p) == 0);
    REQUIRE(size(queue, &front_p, &back_p) == 2);
    REQUIRE(front(queue, &front_p, &back_p) == 1);
    REQUIRE(back(queue, &front_p, &back_p) == 2);
    push(queue, &back_p, 3);
    REQUIRE(empty(queue, &front_p, &back_p) == 0);
    REQUIRE(size(queue, &front_p, &back_p) == 3);
    REQUIRE(pop(queue, &front_p, &back_p) == 1);
    REQUIRE(size(queue, &front_p, &back_p) == 2);
    REQUIRE(empty(queue, &front_p, &back_p) == 0);
    REQUIRE(pop(queue, &front_p, &back_p) == 2);
    REQUIRE(pop(queue, &front_p, &back_p) == 3);
    REQUIRE(empty(queue, &front_p, &back_p) == 1);
    REQUIRE(size(queue, &front_p, &back_p) == 0);
    

}


TEST_CASE("C struct version Queue test", "[single-file]")
{
}

TEST_CASE("C++ version Queue test", "[single-file]")
{
}
