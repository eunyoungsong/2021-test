/* 문자열에서 파일경로/이름 추출하기 */
#include <stdio.h>
#include <string.h>

#include <time.h>
#include <unistd.h>

int main()
{
    char string[100];
    char fname[100];
    char title[100];
    char title2[100];
    char ext[100];
    char *pos;

    strcpy(string, "../log/log_test_04/2021_8_23_15_4_47.txt");
    pos = strrchr(string, '//'); // strrchr : 문자열의 뒤에서 앞으로 이동하며 '/' 검색, 이스케이프 시퀀스 문자이므로 반드시 연속해서 두개 사용 
    *pos = '\0';                 // 검색된 위치에 널문자를 대입하여 string을 파일의 경로 문자열로 저장
    printf("파일경로 : %s\n", string);

    strcpy(string, "../log/log_test_04/2021_8_23_15_4_47.txt");
    pos = strrchr(string, '//'); 
    strcpy(fname, pos+1);
    printf("파일이름 : %s\n", fname);

    strcpy(title, fname);
    pos = strchr(title, '.'); // strchr : 문자열 내에 일치하는 문자가 있는지 검사하는 함수
    *pos = '\0';
    printf("파일제목 : %s\n", title);


    // 내가 찾던 제목!!!
    strcpy(title2, fname);
    pos = strrchr(title2, '_'); 
    *pos = '\0';
    printf("파일제목 : %s\n", title2);


    pos = strchr(fname, '.'); 
    strcpy(ext, pos+1);
    printf("파일확장자 : %s\n", ext);


    return 0;
}
