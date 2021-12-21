/* 저수준 입출력 함수를 이용한 파일 처리 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>      // printf()
#include <string.h>     // strlen()
#include <fcntl.h>      // open()
#include <unistd.h>     // write(), close()

int openTest(){

    /* 파일 오픈 OPEN */
    /*
        파일 존재시 오픈, 존재하지 않을 경우 에러

        O_RDONLY    : 읽기 전용으로 열기
        O_WRONLY    : 쓰기 전용으로. 열기
        O_RDWR      : 읽기 쓰기 모두 가능

        세가지 옵션 중 한개 필수

        O_CREAT     : 해당 파일이 없으면 생성
        O_EXCL      : O_CREAT를 사용했을 때 파일이 이미 있어도 열기 가능 

        등등 더 다양한 옵션 있음

        O_WRONLY|O_CREAT|O_EXCL : 함께 사용하면 파일 존재시 open 실패, 이전 파일 보존
    */

    int fd = open("../txt/test.txt", O_RDWR, 0644) ;
    
    if( 0 < fd ){
        const char *temp = "open";
        write(fd, temp, strlen(temp));
        printf("파일 열기 성공\n");

    }else{
        printf("파일 열기 실패\n");
    }

    close(fd);

    return 0;
}