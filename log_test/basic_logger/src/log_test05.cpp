/* 분마다 새로운 로그파일 생성하기 */
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h> //access함수

int main()
{

    time_t t1, t2;
    time(&t1);
    struct tm * lt = localtime(&t1);

/*
    // curreunt time 구해서 파일이름에 넣기
    sprintf(fname,  "../log/log_test_05/%d_%d_%d_%d_%d.txt",
            lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday, lt->tm_hour, lt->tm_min);
        
    // 파일명 존재 확인
    char title[100]={0}; // 비교를 위한 변수(분까지의 파일명)
    char *pos; // 파일명을 찾기 위한 포인터변수
    char * path = "../log/log_test_04/*.txt";
    int mode = F_OK;
    
    if(access(path, mode) == 0){
        printf("파일존재\n");
    }else{
        // 파일존재하지않음
        printf("파일존재하지않음\n");
        // 새로운 파일 생성
        // 로그찍기
    }
 */ 

    // 로그찍기
    char fname[512] = {0};
    sprintf(fname,  "../log/log_test05/%d_%d_%d_%d_%d.txt",
            lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday, lt->tm_hour, lt->tm_min);
    
    FILE *fp = NULL;
    fp = fopen(fname, "a");
    if(fp == NULL){
        printf("파일열기 실패\n");
        return 1;
    }

    char times[512];
    memset(times, 0, sizeof(times));

    sprintf(times,  "%s", ctime(&t1));
    fprintf(fp, "시작-%s", times);

    for(int i=1; i<6; i++){
        int sum = 0;
        sum += i;
        printf("%d\n", sum);
        sleep(1);
    }

    // 종료 time 가져오기
    time(&t2);
    struct tm * lt2 = localtime(&t2); 
    memset(times, 0, sizeof(times));

    sprintf(times, "%s", ctime(&t2));
    fprintf(fp, "종료-%s", times);
    fclose(fp);


    printf("완료\n");
    return 0;
}
