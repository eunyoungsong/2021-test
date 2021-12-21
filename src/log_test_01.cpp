#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main(){

    time_t t1, t2;
    time(&t1);
    printf("%s", ctime(&t1));

    for(int i=1; i<6; i++){
        int sum = 0;
        sum += i;
        printf("%d\n", sum);
        sleep(1);
    }

    time(&t2);
    printf("%s", ctime(&t2));

    printf("============================\n");
    return 0;
}