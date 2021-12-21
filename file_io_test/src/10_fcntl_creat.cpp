/* 저수준 입출력 함수를 이용한 파일 처리 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   
#include <string.h>    
#include <fcntl.h>     
#include <unistd.h>   

int creatTest(){

    /* 파일 생성 creat */
    // 파일 존재시 파일 내용을 모두 삭제하고 새로운 파일 생성
    int fd = creat("../txt/test.txt", 0644);

    if(fd < 0){
        printf("파일 생성 실패\n");
        return 1;
    }

    const char *temp = "creat\n";
    write(fd, temp, strlen(temp));
    close(fd);

    printf("파일 생성 성공\n");
    printf("=================완료=================\n");

    return 0;
}