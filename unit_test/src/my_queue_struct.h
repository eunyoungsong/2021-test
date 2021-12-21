// 큐(QUEUE) : 선입선출 (구조체 버전)

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

    struct queue_t{
        int queue[100 + 1];
        int front_p;
        int back_p;
    };

    void sq_push(struct queue_t* s, const int n);
    void sq_clear(struct queue_t* s);
    int sq_pop(struct queue_t* s);
    int sq_front(const struct queue_t* s);
    int sq_back(const struct queue_t* s);
    int sq_empty(const struct queue_t* s);
    int sq_size(const struct queue_t* s);
    
#ifdef __cplusplus
}
#endif

