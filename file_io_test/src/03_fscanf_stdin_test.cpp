#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

int main(void){
    
    FILE *fp = NULL;
    char str[10] = {0, };

    fp = fopen("../txt/test.txt", "w"); // 쓰기모드

    // 예외검사
    if(fp == NULL){
        printf("파일열기 실패\n");
        return 1;
    }

    printf("문자열을 입력하세요 : ");
    // stdin 매크로를 활용하여 사용자가 입력한 value을 변수에 저장
    fscanf(stdin, "%s", str);

    // 입력 받은 문자열 확인하기
    printf("입력 받은 문자열 : %s\n", str);

    // 파일에 입력 받은 문자열 넣기
    fprintf(fp, "%s\n", str);

    fclose(fp);

    printf("=================완료=================\n");
    return 0;
}