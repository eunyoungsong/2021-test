// 순환큐(Circular QUEUE)
#pragma once
#include <stdio.h>
#include <string.h>

namespace sm
{

class ex_circular_queue_t {

    private:
        int queue[5+1];
        int front_p;
        int back_p;
        int capacity;

    public:

        ex_circular_queue_t() { 
            front_p = 0;
            back_p = 0;
            capacity = (sizeof(queue)/sizeof(int))-1;
        }

        int size() const {

            if (front_p == back_p){
                return 0;
            }

            if (back_p < front_p) {
                return ( ((capacity+1)-front_p) + back_p);
            }
            else {
                return (back_p-front_p);
            }
        
       
        }

        void push(const int n)
        {
            if (capacity <= size())
            {
                throw "pull";
            }

            queue[back_p] = n;
            
            if (back_p==capacity) {
                back_p = 0;
            }
            else {
                back_p += 1;
            }

        }

        void pop()
        {
            if (size() == 0){
                throw "empty";
            }
            else
            {
                if (front_p==capacity) {
                    front_p = 0;
                }
                else {
                    front_p += 1;
                }
               
            }
        }

        int front()
        {
            if (size() == 0){
                return -1;
            }
            else
            {
                return queue[front_p];
            }
        }

        int back()
        {   
            if (size() == 0){
                return -1;
            }
            else
            {
                return queue[back_p-1];
            }
        }

        bool empty()
        {
            return 0 == size();
        }


/*
        int push(const int n)
        {

            if (capacity <= size())
            {
                return -2;
            }

            back_p = back_p % capacity ;
            queue[back_p] = n ;
            back_p += 1 ;

        }
        
        int pop()
        {
            int pop = 0;
            if (size() == 0){
               return -1;
            }
            else
            {
                front_p = front_p % capacity;  
                back_p = back_p % capacity;
                pop = queue[front_p];
                front_p += 1;

                return pop; 
            }
        }

        int front()
        {
            if (size() == 0){
                return -1;
            }
            else
            {
                front_p = front_p % capacity;
                return queue[front_p];
            }
        }

        int back()
        {   
            if (size() == 0){
                return -1;
            }
            else
            {
                back_p = back_p % capacity;
                return queue[back_p-1];
            }
        }
*/


    };

}