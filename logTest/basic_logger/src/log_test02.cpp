#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

int main(){

    FILE *fp = NULL;
    fp = fopen("../log/log_test02.txt", "a");

    if(fp == NULL){
        printf("파일열기 실패\n");
        return 1;
    }


    time_t t1, t2;
    time(&t1); // 현재시각
    char times[512];
    memset(times, 0, sizeof(times));

    sprintf(times,  "%s", ctime(&t1));
    fprintf(fp, "%s", times);

    for(int i=1; i<6; i++){
        int sum = 0;
        sum += i;
        printf("%d\n", sum);
        sleep(1);
    }


    // 종료 time 가져오기
    time(&t2);
    memset(times, 0, sizeof(times));

    sprintf(times, "%s", ctime(&t2));
    fprintf(fp, "%s", times);
    fclose(fp);

    printf("완료\n");
    return 0;
}