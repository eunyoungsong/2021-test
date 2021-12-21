// 덱(DEQUE)
#include <stdio.h>
#include <string.h>
#pragma once

namespace sm
{

class deque_t {

    private :
        int deque[500];
        int front_p;
        int back_p;
        int size;

    public :

    deque_t() {
        this->front_p = 250;
        this->back_p = 250;
        this->size = 0;
    }

    int push_front(const int n) {

        if (front_p == 0) {
            return -2;
        }
        front_p -= 1;
        deque[front_p] = n;
        size += 1;
        return 0;

    }


    int push_back(const int n) {

        if (back_p == 500) {
            return -2;
        }
        deque[back_p] = n;
        back_p += 1;
        size += 1;
        return 0;

    }


    int pop_front() {

        int pop = 0;

        if (size == 0) {
            return -1;
        }
        else {
            pop = deque[front_p];
            front_p = front_p + 1;
            size -= 1;
            return pop;
        }

    }


    int pop_back() {

        int pop = 0;

        if (size == 0) {
            return -1;
        }
        else {
            back_p = back_p - 1;
            pop = deque[back_p];
            size -= 1;
            return pop;
        }

    }


    int front() {

        if (size == 0) {
            return -1;
        }
        else {
            return deque[front_p];
        }

    }


    int back() {

        if (size == 0) {
            return -1;
        }
        else {
            return deque[back_p - 1];
        }

    }

    int empty() {

        if (size == 0) {
            return 1;
        }
        else {
            return 0;
        }

    }


    int deque_size() {

        return size;

    }

};

}