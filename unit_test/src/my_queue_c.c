// 큐(QUEUE) : 선입선출 (버전1)

#include <stdio.h>
#include <string.h>

#include "my_queue_c.h"

// push 
void push(int queue[], int* back_p, int n) {

    queue[*back_p] = n;
    *back_p = *back_p + 1;

    }


// pop : 가장 처음 넣은 자료 삭제
int pop(int queue[], int* front_p, int* back_p) {

    int pop = 0;
    if (*back_p == 0) {
        return -1;
    }
    if (*front_p == *back_p) {
        return -1;
    }
    else {
        pop = queue[*front_p];
        queue[*front_p] = 0;
        *front_p += 1;
        if (*back_p == 1) {
            *back_p = 0;
        }
        return pop;
    }
    
}


// front : 현재 맨 앞에 있는 자료 반환 (삭제X, 확인만)
int front(int queue[], int* front_p, int* back_p) {

    if (*back_p == 0) {
        return -1;
    }
    if (*front_p == *back_p) {
        return -1;
    }
    else {
        return queue[*front_p];
    }
        
    }


// back : 현재 맨 뒤에 있는 자료 반환 (삭제X, 확인만)
int back(int queue[], int* front_p, int* back_p) {

    if (*back_p == 0) {
        return -1;
    }
    if (*front_p == *back_p) {
        return -1;
    }
    else {
        return queue[*back_p-1];
    }

}

// empty : 비어있으면 1, 비어있지않으면 0
int empty(int queue[], int* front_p, int* back_p) {

    if (*back_p == 0) {
        return 1;
    }
    if (*front_p == *back_p) {
        return 1;
    }
    else {
        return 0;
    }
     
}


// size
int size(int queue[], int* front_p, int* back_p) {

    return (*back_p) - (*front_p);

}


