/* 프로그램 실행할때마다 새로운 로그파일 생성하기(파일명은 시간)*/
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

int main()
{
    time_t t1, t2;
    time(&t1);
    struct tm * lt = localtime(&t1);
    char fname[512];

    //sprintf(fname, "../log/log_test_04/test.txt");
    sprintf(fname,  "../log/log_test_04/%d_%d_%d_%d_%d_%d.txt",
            lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);

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