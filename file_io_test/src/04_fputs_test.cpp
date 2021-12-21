#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 


int fputs_test(void){
    
    FILE *fp = NULL;

    fp = fopen("../txt/hello.txt", "w");

    // 예외검사
    if(fp == NULL){
        printf("파일열기 실패\n");
        return 1;
    }

    // fputs : 파일에 문자열 저장
    fputs("hello, world!\n", fp);

    // stdout : 표준 출력에 문자열 출력
    fputs("hello, world!!\n", stdout);

    fclose(fp);

    printf("=================완료=================\n");

    return 0;
}