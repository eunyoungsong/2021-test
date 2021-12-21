// 덱(DEQUE)

#pragma once

#include <stdio.h>
#include <string.h>

#include <stdexcept>

namespace sm
{

template<typename T>
class deque_tt {

    private :
        T deque[500];
        int front_p;
        int back_p;
        size_t size;

    public :

    deque_tt() {
        this->front_p = 250;
        this->back_p = 250;
        this->size = (size_t)0;
    }

    void push_front(const T n) {
        if (front_p == 0) {
            throw std::out_of_range("push_front(): front point at limit");
        }
        front_p -= 1;
        deque[front_p] = n;
        size += 1;
    }


    void push_back(const T n) {
        if (back_p == 500) {
            throw std::out_of_range("push_back(): back point at limit");
        }
        deque[back_p] = n;
        back_p += 1;
        size += 1;
    }


    T pop_front() {
        T pop;
        if (size == (size_t)0) {
            throw std::out_of_range("pop_front(): no daa exists.");
        }
        else {
            pop = deque[front_p];
            front_p = front_p + 1;
            size -= 1;
            return pop;
        }
    }


    T pop_back() {        
        T pop;
        if (size == (size_t)0) {
            throw std::out_of_range("pop_back(): no daa exists.");
        }
        else {
            back_p = back_p - 1;
            pop = deque[back_p];
            size -= 1;
            return pop;
        }
    }


    T front() {
        if (size == (size_t)0) {
            throw std::out_of_range("front(): no daa exists.");
        }
        else {
            return deque[front_p];
        }
    }


    T back() {
        if (size == (size_t)0) {
            throw std::out_of_range("back(): no daa exists.");
        }
        else {
            return deque[back_p - 1];
        }
    }


    bool empty() {
        if (size == (size_t)0) {
            return true;
        }
        else {
            return false;
        }
    }


    size_t deque_size() {
        return size;
    }

};

}