#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fread_binary(){

    FILE *fp = NULL;
    int data[5];

    fp = fopen("../txt/hello.txt", "rb"); // 이진자료 읽기모드

    if(fp == NULL){
        printf("파일열기 실패\n");
        return 1;
    }

    // fread : 이진파일 읽기
    fread(data, sizeof(int), 5, fp);

    for(int i=0; i<5; i++){
        printf("%d ", data[i]);
    }

    fclose(fp);

    printf("\n=================완료=================\n");

    return 0;
