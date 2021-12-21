#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

int fread_test(void){
    
    FILE *fp = NULL;
    char buffer[10] = {0, };

    fp = fopen("../txt/hello.txt", "r");

    // 예외검사
    if(fp == NULL){
        printf("파일열기 실패\n");
        return 1;
    }

    // fread : txt파일에서 버퍼크기만큼 1번 value을 읽음
    fread(buffer, sizeof(buffer), 1, fp);

    // 읽어온 문자열 출력
    printf("%s\n", buffer);

    // 파일 포인터 닫기
    fclose(fp);

    printf("=================완료=================\n");
    return 0;
}