// 데큐(DEQUE)
#include <catch2/catch.hpp>

#include "../src/my_deque_class.hpp"

TEST_CASE("Class version Deque test", "[single-file]")
{
    sm::deque_t de;
    REQUIRE(de.front()==-1);
    REQUIRE(de.back()==-1);
    REQUIRE(de.empty()==1);
    REQUIRE(de.deque_size()==0);

    REQUIRE(de.push_front(1)==0);
    REQUIRE(de.front()==1);
    REQUIRE(de.back()==1);
    REQUIRE(de.empty()==0);
    REQUIRE(de.deque_size()==1);

    REQUIRE(de.push_back(2)==0);
    REQUIRE(de.front()==1);
    REQUIRE(de.back()==2);
    REQUIRE(de.empty()==0);
    REQUIRE(de.deque_size()==2);

    REQUIRE(de.push_back(3)==0);
    REQUIRE(de.front()==1);
    REQUIRE(de.back()==3);
    REQUIRE(de.empty()==0);
    REQUIRE(de.deque_size()==3);

    REQUIRE(de.push_front(4)==0);
    REQUIRE(de.front()==4);
    REQUIRE(de.back()==3);
    REQUIRE(de.empty()==0);
    REQUIRE(de.deque_size()==4);

    REQUIRE(de.pop_front()==4);
    REQUIRE(de.front()==1);
    REQUIRE(de.back()==3);
    REQUIRE(de.empty()==0);
    REQUIRE(de.deque_size()==3);

    REQUIRE(de.pop_back()==3);
    REQUIRE(de.front()==1);
    REQUIRE(de.back()==2);
    REQUIRE(de.empty()==0);
    REQUIRE(de.deque_size()==2);

    REQUIRE(de.pop_back()==2);
    REQUIRE(de.front()==1);
    REQUIRE(de.back()==1);
    REQUIRE(de.empty()==0);
    REQUIRE(de.deque_size()==1);

    REQUIRE(de.pop_back()==1);
    REQUIRE(de.front()==-1);
    REQUIRE(de.back()==-1);
    REQUIRE(de.empty()==1);
    REQUIRE(de.deque_size()==0);

    for(int i=1; i<250; i++){
        REQUIRE(de.push_front(i)==0);
    }

    REQUIRE(de.empty()==0);
    REQUIRE(de.front()==249);
    REQUIRE(de.back()==1);
    REQUIRE(de.deque_size()==249);

    REQUIRE(de.push_front(250)==-2);
    REQUIRE(de.front()==249);
    
    for(int i=250; i<=500; i++){
        REQUIRE(de.push_back(i)==0);
    }
    REQUIRE(de.empty()==0);
    REQUIRE(de.front()==249);
    REQUIRE(de.back()==500);
    REQUIRE(de.deque_size()==500);

    REQUIRE(de.push_back(501)==-2);
    REQUIRE(de.back()==500);

}
