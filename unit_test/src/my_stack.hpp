// 스택 (CLASS버전)
#pragma once
#include <stdio.h>
#include <string.h>

namespace sm
{

class stack_t {

    private:
        int data[10000 + 1];
        int top;

    public:

        stack_t() {
            this->top = 0;
        }

    
        void push(const int value) {

            this->data[this->top] = value;
            this->top = this->top + 1;

        }

        int pop() {

            if (this->top == 0) {
                return -1;
            }
            else {
                int pop = 0;
                this->top = this->top - 1;
                pop = this->data[this->top];
                return pop;
            }

        }

        int get_top(const int index = 0) const {

            if (this->top == 0) {
                return -1;
            }
            else {
                return this->data[(this->top) - 1 - index];
            }

        }

        int size() const {

            return this->top;

        }


        int empty() const {

            if (this->top == 0) {
                return 1;
            }
            else {
                return 0;
            }

        }

    };

}