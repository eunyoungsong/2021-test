#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>


int fgets_test(void){
    
    FILE* fp = NULL;
    char buffer[10] = {0, };

    // txt파일 읽기 모드로 열기 
    fp = fopen("../txt/hello.txt", "r");

    // fgets : null을 포함한 지정한 버퍼의 크기만큼만 읽음
    // 하지만 txt파일에 줄바꿈(\n)이 있으면 버퍼의 크기와 상관없이 \n 문자열을 읽음
    fgets(buffer, sizeof(buffer), fp);

    // 읽어온 문자열 출력
    printf("%s\n", buffer);

    // 파일 포인터 닫기
    fclose(fp);

    printf("=================완료=================\n");
    return 0;
}