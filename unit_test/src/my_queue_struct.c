// 큐(QUEUE) : 선입선출 (구조체 버전)

#include <stdio.h>
#include <string.h>

#include "my_queue_struct.h"


void sq_clear(struct queue_t* s){
    memset(s, 0, sizeof(*s));
}

void sq_push(struct queue_t* s, const int n) {

    s->queue[s->back_p] = n;
    s->back_p = s->back_p + 1;
    
}


int sq_pop(struct queue_t* s) {

    int pop = 0;
    if (s->back_p == 0) {
        return -1;
    }
    if (s->front_p == s->back_p) {
        return -1;
    }
    else {
        pop = s->queue[s->front_p];
        s->queue[s->front_p] = 0;
        s->front_p += 1;
        if (s->back_p == 1) {
            s->back_p = 0;
        }
        return pop;
    }
    
}


int sq_front(const struct queue_t* s) {

    if (s->back_p == 0) {
        return -1;
    }
    if (s->front_p == s->back_p) {
        return -1;
    }
    else {
        return s->queue[s->front_p];
    }
        
    }


int sq_back(const struct queue_t* s) {

    if (s->back_p == 0) {
        return -1;
    }
    if (s->front_p == s->back_p) {
        return -1;
    }
    else {
        return s->queue[s->back_p-1];
    }

}


int sq_empty(const struct queue_t* s) {

    if (s->back_p == 0) {
        return 1;
    }
    if (s->front_p == s->back_p) {
        return 1;
    }
    else {
        return 0;
    }
     
}


int sq_size(const struct queue_t* s) {

    return (s->back_p) - (s->front_p);

}

