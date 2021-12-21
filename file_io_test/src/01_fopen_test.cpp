/* 표준 입출력 함수를 이용한 파일 처리 */

#define _CRT_SECURE_NO_WARNINGS // fopen 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>  // fopen, fgets, flcose 함수가 선언된 헤더 파일

// 예제출처 https://dojang.io/mod/page/view.php?id=610

int main(void){
    
    FILE * fp = NULL;

    // 파일이 존재해야함
    fp = fopen("../txt/hello.txt", "r");

    // 예외검사 
    if(fp == NULL){
        printf("파일열기 실패\n");
        return 1;
    }else {
        printf("파일열기 성공\n");
    }

    fclose(fp);

    printf("=================완료=================\n");

    return 0;
}