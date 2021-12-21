//#pragma warning (disable:4996)
// 덱(DEQUE)
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int push_front(char str[], int deque[], int* size, int* front_p, int n) {

    if (*front_p == -1) {
        return -2;
    }
    *front_p -= 1;
    deque[*front_p] = n;
    *size += 1;
    return -2;

}


int push_back(char str[], int deque[], int* size, int* back_p, int n) {

    if (*back_p == 501) {
        return -2;
    }
    deque[*back_p] = n;
    *back_p += 1;
    *size += 1;
    return -2;

}


int pop_front(char str[], int deque[], int* size, int* front_p) {

    int pop = 0;

    if (*size == 0) {
        return -1;
    }
    else {
        pop = deque[*front_p];
        *front_p = *front_p + 1;
        *size -= 1;
        return pop;
    }

}


int pop_back(char str[], int deque[], int* size, int* back_p) {

    int pop = 0;

    if (*size == 0) {
        return -1;
    }
    else {
        *back_p = *back_p - 1;
        pop = deque[*back_p];
        *size -= 1;
        return pop;
    }

}


int front(char str[], int deque[], int* size, int* front_p) {

    if (*size == 0) {
        return -1;
    }
    else {
        return deque[*front_p];
    }

}


int back(char str[], int deque[], int* size, int* back_p) {

    if (*size == 0) {
        return -1;
    }
    else {
        return deque[*back_p - 1];
    }

}

// empty : 비어있으면 1, 비어있지않으면 0
int empty(int* size) {

    if (*size == 0) {
        return 1;
    }
    else {
        return 0;
    }

}


int deque_size(int* size) {

    return *size;

}


int main() {

    int a = 0;
    char input[10000] = {};
    int result = 0;

    int deque[500 + 1] = { 0, };
    int front_p = 250;
    int back_p = 250;
    int size = 0;

    scanf("%d", &a);

    for (int i = 0; i < a; i++) {

        scanf("%s", input);

        if (!strcmp(input, "push_back")) {
            int n = 0;
            scanf("%d", &n);
            result = push_back(input, deque, &size, &back_p, n);
        }
        else if (!strcmp(input, "push_front")) {
            int n = 0;
            scanf("%d", &n);
            result = push_front(input, deque, &size, &front_p, n);
        }
        else if (!strcmp(input, "pop_front")) {
            result = pop_front(input, deque, &size, &front_p);
        }
        else if (!strcmp(input, "pop_back")) {
            result = pop_back(input, deque, &size, &back_p);
        }
        else if (!strcmp(input, "front")) {
            result = front(input, deque, &size, &front_p);
        }
        else if (!strcmp(input, "back")) {
            result = back(input, deque, &size, &back_p);
        }
        else if (!strcmp(input, "empty")) {
            result = empty(&size);
        }
        else if (!strcmp(input, "size")) {
            result = deque_size(&size);
        }

        if (result != -2) {
            printf("%d\n", result);
        }

    }

    return 0;
}
