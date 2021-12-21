#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    
    FILE *fp = NULL;

    fp = fopen("../txt/hello.txt", "wt");

    // 예외검사
    if(fp == NULL){
        printf("파일열기 실패\n");
        return 1;
    }

    // fprintf : 서식을 지정하여 파일에 텍스트 입력
    fprintf(fp, "%s %d\n", "Hello", 100);

    // stdout : 화면에 출력
    fprintf(stdout, "%s %d\n", "Hello", 100);
    
    fclose(fp);

    printf("=================완료=================\n");
    return 0;
}