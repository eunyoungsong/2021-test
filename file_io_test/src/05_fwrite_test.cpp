#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h>


int fwrite_test(){
    
    FILE *fp = NULL;
    char *s1 = "test";

    fp = fopen("../txt/hello.txt", "w");

    // 예외검사
    if(fp == NULL){
        printf("파일열기 실패\n");
        return 1;
    }

    // fwrite : 문자열의 길이만큼 1번 파일에 저장
    fwrite(s1, strlen(s1), 1, fp);

    // stdout : 표준 출력에 문자열 출력
    fwrite(s1, strlen(s1), 1, stdout);

    fclose(fp);

    printf("=================완료=================\n");

    return 0;
}