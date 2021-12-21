// 큐(QUEUE) : 선입선출 (클래스 버전)
#include <catch2/catch.hpp>

#include "../src/my_queue_class.hpp"

TEST_CASE("Class version Queue test", "[single-file]")
{
    sm::queue_t q;
    REQUIRE(q.q_front()==-1);
    q.q_push(1);
    REQUIRE(q.q_front()==1);
    REQUIRE(q.q_back()==1);
    REQUIRE(q.q_empty()==0);
    REQUIRE(q.q_size()==1);
    q.q_push(2);
    REQUIRE(q.q_empty() == 0);
    REQUIRE(q.q_size() == 2);
    REQUIRE(q.q_front() == 1);
    REQUIRE(q.q_back() == 2);
    q.q_push(3);
    REQUIRE(q.q_empty() == 0);
    REQUIRE(q.q_size() == 3);
    REQUIRE(q.q_pop() == 1);
    REQUIRE(q.q_size() == 2);
    REQUIRE(q.q_empty() == 0);
    REQUIRE(q.q_pop() == 2);
    REQUIRE(q.q_pop() == 3);
    REQUIRE(q.q_empty() == 1);
    REQUIRE(q.q_size() == 0);

}
