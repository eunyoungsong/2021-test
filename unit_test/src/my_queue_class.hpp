// 큐(QUEUE) : 선입선출 (클래스 버전)
#pragma once
#include <stdio.h>
#include <string.h>

namespace sm
{

class queue_t {

    private:
        int queue[10];
        int front_p;
        int back_p;

    public:

        queue_t() {
            // 초기화
            this->front_p = 0;
            this->back_p = 0;
            memset(this->queue, 0, sizeof(this->queue));
        }

        void q_push(const int n) {
        
            this->queue[this->back_p] = n;
            this->back_p = this->back_p + 1;
            
        }

        int q_pop() {

            int pop = 0;
            if (this->back_p == 0) {
                return -1;
            }
            if (this->front_p == this->back_p) {
                return -1;
            }
            else {
                pop = this->queue[this->front_p];
                this->queue[this->front_p] = 0;
                this->front_p += 1;
                if (this->back_p == 1) {
                    this->back_p = 0;
                }
                return pop;
            }

        }


        int q_front() {

            if (this->back_p == 0) {
                return -1;
            }
            if (this->front_p == this->back_p) {
                return -1;
            }
            else {
                return this->queue[this->front_p];
            }
            
        }


        int q_back() {

            if (this->back_p == 0) {
                return -1;
            }
            if (this->front_p == this->back_p) {
                return -1;
            }
            else {
                return this->queue[this->back_p-1];
            }
            
        }


        int q_empty() {

            if (this->back_p == 0) {
                return 1;
            }
            if (this->front_p == this->back_p) {
                return 1;
            }
            else {
                return 0;
            }

        }


        int q_size() {

            return (this->back_p) - (this->front_p);

        }

    };

}