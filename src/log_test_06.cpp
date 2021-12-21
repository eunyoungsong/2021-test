/* 로그파일 내용 형식 맞춰주기 */
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h> 

int main()
{
    time_t t1, t2;
    time(&t1);
    struct tm * lt = localtime(&t1);

    char fname[512] = {0};
    sprintf(fname,  "../log/log_test_06.txt");
    
    FILE *fp = NULL;
    fp = fopen(fname, "a");
    if(fp == NULL){
        printf("파일열기 실패\n");
        return 1;
    }

    char times[512];
    memset(times, 0, sizeof(times));

    //sprintf(times,  "%s", ctime(&t1));
    sprintf(times,  "%d %02d %02d - %02d : %02d : %02d",
            lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
    fprintf(fp, "[] %s - start\n", times); // 로그찍기

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

    //sprintf(times, "%s", ctime(&t2));
    sprintf(times,  "%d %02d %02d - %02d : %02d : %02d",
            lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
    fprintf(fp, "[] %s - end\n", times); // 로그찍기
    fclose(fp);

    printf("완료\n");
    return 0;
}
