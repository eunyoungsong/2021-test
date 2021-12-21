// 큐(QUEUE) : 선입선출 (구조체 버전)

#include <catch2/catch.hpp>
#include <memory.h>

#include "../src/my_queue_struct.h"

TEST_CASE("Struct version Queue test", "[single-file]")
{
    queue_t s1;
    sq_clear(&s1);
    sq_push(&s1, 1);
    REQUIRE(sq_front(&s1)==1);
    REQUIRE(sq_back(&s1)==1);
    REQUIRE(sq_empty(&s1)==0);
    REQUIRE(sq_size(&s1)==1);
    sq_push(&s1, 2);
    REQUIRE(sq_empty(&s1) == 0);
    REQUIRE(sq_size(&s1) == 2);
    REQUIRE(sq_front(&s1) == 1);
    REQUIRE(sq_back(&s1) == 2);
    sq_push(&s1, 3);
    REQUIRE(sq_empty(&s1) == 0);
    REQUIRE(sq_size(&s1) == 3);
    REQUIRE(sq_pop(&s1) == 1);
    REQUIRE(sq_size(&s1) == 2);
    REQUIRE(sq_empty(&s1) == 0);
    REQUIRE(sq_pop(&s1) == 2);
    REQUIRE(sq_pop(&s1) == 3);
    REQUIRE(sq_empty(&s1) == 1);
    REQUIRE(sq_size(&s1) == 0);
}
