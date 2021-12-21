/* 저수준 입출력 함수를 이용한 파일 처리 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   
#include <string.h>    
#include <fcntl.h>     
#include <unistd.h>   

int readTest(){

    int fd = open("../txt/test.txt", O_RDWR, 0644);
    char buffer[20] = {0, };

    if( 0 < fd ){
        read(fd, buffer, 50);
        close(fd);
    }else{
        printf("실패\n");
    }

    printf("%s\n", buffer); // 제대로 읽었는지 확인을 위한 출력
    printf("=================완료=================\n");

    return 0;
}