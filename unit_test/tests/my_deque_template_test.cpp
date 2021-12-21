// 데큐(DEQUE)
#include <stdexcept>
#include <iostream>
#include <catch2/catch.hpp>

#include "../src/my_deque_template.hpp"

TEST_CASE("Template version Deque test", "[single-file]")
{
    sm::deque_tt<int> de;

    try
    {
        try {
            de.front();
        }
        catch (std::out_of_range& e) {
            std::cerr << e.what() << std::endl;
        }
        try
        {
            de.back();
        }
        catch(std::out_of_range& e)
        {
            std::cerr << e.what() << std::endl;
        }

            
        REQUIRE(de.empty());
        REQUIRE(de.deque_size()==(size_t)0);

        de.push_front(1);
        REQUIRE(de.front()==1);
        REQUIRE(de.back()==1);
        REQUIRE(!de.empty());
        REQUIRE(de.deque_size()==(size_t)1);

        de.push_back(2);
        REQUIRE(de.front()==1);
        REQUIRE(de.back()==2);
        REQUIRE(!de.empty());
        REQUIRE(de.deque_size()==(size_t)2);

        de.push_back(3);
        REQUIRE(de.front()==1);
        REQUIRE(de.back()==3);
        REQUIRE(!de.empty());
        REQUIRE(de.deque_size()==(size_t)3);

        de.push_front(4);
        REQUIRE(de.front()==4);
        REQUIRE(de.back()==3);
        REQUIRE(!de.empty());
        REQUIRE(de.deque_size()==(size_t)4);

        REQUIRE(de.pop_front()==4);
        REQUIRE(de.front()==1);
        REQUIRE(de.back()==3);
        REQUIRE(!de.empty());
        REQUIRE(de.deque_size()==(size_t)3);

        REQUIRE(de.pop_back()==3);
        REQUIRE(de.front()==1);
        REQUIRE(de.back()==2);
        REQUIRE(!de.empty());
        REQUIRE(de.deque_size()==(size_t)2);

        REQUIRE(de.pop_back()==2);
        REQUIRE(de.front()==1);
        REQUIRE(de.back()==1);
        REQUIRE(!de.empty());
        REQUIRE(de.deque_size()==(size_t)1);

        REQUIRE(de.pop_back()==1);
        try {
            de.front();
        }
        catch (std::out_of_range& e) {
            std::cerr << e.what() << std::endl;
        }
        try
        {
            de.back();
        }
        catch(std::exception& e)
        {
            printf("%s", e.what());
        }
        REQUIRE(de.empty());
        REQUIRE(de.deque_size()==(size_t)0);

        for(int i=1; i<250; i++){
            de.push_front(i);
        }

        REQUIRE(!de.empty());
        REQUIRE(de.front()==249);
        REQUIRE(de.back()==1);
        REQUIRE(de.deque_size()==(size_t)249);

        de.push_front(250);
        REQUIRE(de.front()==249);
        
        for(int i=250; i<=500; i++){
            de.push_back(i);
        }
        REQUIRE(!de.empty());
        REQUIRE(de.front()==249);
        REQUIRE(de.back()==500);
        REQUIRE(de.deque_size()==(size_t)500);

        de.push_back(501);
        REQUIRE(de.back()==500);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
