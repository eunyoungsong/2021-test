// 큐(QUEUE) : 선입선출 (클래스 버전)
#include <catch2/catch.hpp>

#include "../src/my_circular_queue.hpp"

TEST_CASE("Circular Queue test", "[single-file]")
{
    sm::circular_queue_t cq;

    REQUIRE(cq.empty()==1);
    REQUIRE(cq.front()==-1);
    REQUIRE(cq.back()==-1);
    REQUIRE(cq.size()==0);

    REQUIRE(cq.push(1)==0);
    REQUIRE(cq.empty()==0);
    REQUIRE(cq.front()==1);
    REQUIRE(cq.back()==1);
    REQUIRE(cq.size()==1);

    REQUIRE(cq.push(2)==0);
    REQUIRE(cq.empty()==0);
    REQUIRE(cq.front()==1);
    REQUIRE(cq.back()==2);
    REQUIRE(cq.size()==2);

    REQUIRE(cq.pop()==1);
    REQUIRE(cq.empty()==0);
    REQUIRE(cq.front()==2);
    REQUIRE(cq.back()==2);
    REQUIRE(cq.size()==1);

    REQUIRE(cq.pop()==2);
    REQUIRE(cq.empty()==1);
    REQUIRE(cq.front()==-1);
    REQUIRE(cq.back()==-1);
    REQUIRE(cq.size()==0);

    for(int i=3; i<=7; i++){
        REQUIRE(cq.push(i)==0);
    }
    REQUIRE(cq.empty()==0);
    REQUIRE(cq.front()==3);
    REQUIRE(cq.back()==7);
    REQUIRE(cq.size()==5);

    REQUIRE(cq.push(8)==-2);

    REQUIRE(cq.pop()==3);
    REQUIRE(cq.pop()==4);
    REQUIRE(cq.pop()==5);
    REQUIRE(cq.pop()==6);
    REQUIRE(cq.pop()==7);

    REQUIRE(cq.empty()==1);
    REQUIRE(cq.front()==-1);
    REQUIRE(cq.back()==-1);
    REQUIRE(cq.size()==0);


}
