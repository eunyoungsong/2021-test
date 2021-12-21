// 큐(QUEUE) : 선입선출 (클래스 버전)
#include <iostream>
#include <catch2/catch.hpp>
#include "../src/ex_circular_queue.hpp"

TEST_CASE("EX Circular Queue test", "[single-file]")
{
    sm::ex_circular_queue_t cq;

    try
    {
        REQUIRE(cq.empty()==1);
        REQUIRE(cq.front()==-1);
        REQUIRE(cq.back()==-1);
        REQUIRE(cq.size()==0);

        cq.push(1);
        REQUIRE(cq.empty()==0);
        REQUIRE(cq.front()==1);
        REQUIRE(cq.back()==1);
        REQUIRE(cq.size()==1);

        cq.push(2);
        REQUIRE(cq.empty()==0);
        REQUIRE(cq.front()==1);
        REQUIRE(cq.back()==2);
        REQUIRE(cq.size()==2);

        cq.pop();
        REQUIRE(cq.empty()==0);
        REQUIRE(cq.front()==2);
        REQUIRE(cq.back()==2);
        REQUIRE(cq.size()==1);

        cq.pop();
        REQUIRE(cq.empty()==1);
        REQUIRE(cq.front()==-1);
        REQUIRE(cq.back()==-1);
        REQUIRE(cq.size()==0);

        for(int i=3; i<=7; i++){
            cq.push(i);
        }
        REQUIRE(cq.empty()==0);
        REQUIRE(cq.front()==3);
        REQUIRE(cq.back()==7);
        REQUIRE(cq.size()==5);

        try
        {
             cq.push(8);
        }
        catch(const char *ex)
        {
            std::cerr << ex << " ex1" << '\n';
        }
        
       

        cq.pop();
        cq.pop();
        cq.pop();
        cq.pop();
        cq.pop();

        REQUIRE(cq.empty()==1);
        REQUIRE(cq.front()==-1);
        REQUIRE(cq.back()==-1);
        REQUIRE(cq.size()==0);  

        cq.pop();

    }
    catch(const char *ex)
    {
        std::cerr << ex << " ex1" << '\n';
    }
  



}
