#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 


int fscanf_test(void){
    
    FILE *fp = NULL;
    char s1[10] = {0, };
    int num1 = 0;

    fp = fopen("../txt/hello.txt", "r");

    // 예외검사
    if(fp == NULL){
        printf("파일열기 실패\n");
        return 1;
    }

    // 서식을 지정하여 파일에서 문자열 읽기
    fscanf(fp, "%s %d", s1, &num1);

    printf("%s %d\n", s1, num1);

    fclose(fp);

    printf("=================완료=================\n");
    return 0;
}