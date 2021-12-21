/* 프로그램 실행종료 로그파일 생성하기 */
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

int main(){

    FILE *fp = NULL;
    fp = fopen("../log/log_test03.txt", "a");

    if(fp == NULL){
        printf("파일열기 실패\n");
        return 1;
    }


    time_t t1, t2;
    time(&t1);
    struct tm * lt = localtime(&t1); 
    char times[512];
    memset(times, 0, sizeof(times));

    sprintf(times,  "%d년 %d월 %d일 %d시 %d분 %d초",
            lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
    fprintf(fp, "%s - 시작\n", times);


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

    sprintf(times,  "%d년 %d월 %d일 %d시 %d분 %d초",
            lt2->tm_year+1900, lt2->tm_mon+1, lt2->tm_mday, lt2->tm_hour, lt2->tm_min, lt2->tm_sec);

    fprintf(fp, "%s - 종료\n", times);
    fclose(fp);

    printf("완료\n");
    return 0;
}