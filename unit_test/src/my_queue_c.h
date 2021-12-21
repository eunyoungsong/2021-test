// 큐(QUEUE) : 선입선출 (버전1)

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif
    void push(int queue[], int* back_p, int n);
    int pop(int queue[], int* front_p, int* back_p);
    int front(int queue[], int* front_p, int* back_p);
    int back(int queue[], int* front_p, int* back_p);
    int empty(int queue[], int* front_p, int* back_p);
    int size(int queue[], int* front_p, int* back_p);
#ifdef __cplusplus
}
#endif

