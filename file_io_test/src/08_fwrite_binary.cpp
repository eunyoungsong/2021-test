#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fwrite_binary(){

    FILE *fp = NULL;
    int data[5] = {1,2,3,4,5};

    fp = fopen("../txt/hello.txt", "wb"); // 파일 이진자료 쓰기

    if(fp == NULL){
        printf("파일열기 실패\n");
        return 1;
    }

    // fwrite : 이진파일 작성
    fwrite(data, sizeof(int), 5, fp);

    fclose(fp);

    printf("=================완료=================\n");

    return 0;
}