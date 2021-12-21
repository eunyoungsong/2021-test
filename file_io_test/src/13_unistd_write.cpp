/* 저수준 입출력 함수를 이용한 파일 처리 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   
#include <string.h>    
#include <fcntl.h>     
#include <unistd.h>   

int main(){

    int fd = open("../txt/test.txt", O_RDWR, 0644);
    
    if(fd < 0){
        printf("파일 생성 실패\n");
        return 1;
    }
    
    // 문자 입력받기
    char str[10] = {0, };
    printf("TEXT : ");
    fscanf(stdin, "%s", str);

    // 입력 받은 문자열 확인하기
    printf("입력 받은 문자열 : %s\n", str);

    // 파일에 입력 받은 문자열 넣기
    write(fd, str, strlen(str));

    // 파일닫기
    close(fd);

    printf("=================완료=================\n");

    return 0;
}