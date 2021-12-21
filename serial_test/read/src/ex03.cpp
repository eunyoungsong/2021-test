#include <stdio.h>
#include <strings.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BAUDRATE B2400
#define MODEMDEVICE "/dev/ttyS0"
#define _POSIX_SOURCE 1   

int main(){

    int fd, c, res;
    struct termios oldtio, newtio;   // USART 설정을 위한 구조체
    char buf[255];                   // 읽기 버퍼
    
    // O_RDWR   - 읽기 쓰기모드
    // O_NOCTTY - 터미널의 제어권을 주지 않는다.(Ctrl-C 방지)
    fd = open(MODEMDEVICE, O_RDWR | O_NOCTTY);
    
    //오류 검출
    if (fd <0){
        perror(MODEMDEVICE);
        exit(-1);
    }

    tcgetattr(fd,&oldtio); //기존 설정을 적용

    bzero(&newtio, sizeof(newtio)); //새 설정의 초기화

    newtio.c_iflag = IGNPAR | ICRNL; //패리티 오류 문자 무시. 캐리지리턴 변환처리.
    newtio.c_oflag = 0;
    newtio.c_lflag = 0;


    /* 제어 문자 초기화 */

        newtio.c_cc[VINTR]    = 0;     /* Ctrl-c */
        newtio.c_cc[VQUIT]    = 0;     /* Ctrl-\ */
        newtio.c_cc[VERASE]   = 0;     /* del */
        newtio.c_cc[VKILL]    = 0;     /* @ */
        newtio.c_cc[VEOF]     = 4;     /* Ctrl-d */
        newtio.c_cc[VTIME]    = 0;     /* inter-character timer unused */
        newtio.c_cc[VMIN]     = 0;     /* blocking read until 1 character arrives */
        newtio.c_cc[VSWTC]    = 0;     /* '\0' */
        newtio.c_cc[VSTART]   = 0;     /* Ctrl-q */
        newtio.c_cc[VSTOP]    = 0;     /* Ctrl-s */
        newtio.c_cc[VSUSP]    = 0;     /* Ctrl-z */
        newtio.c_cc[VEOL]     = 0;     /* '\0' */
        newtio.c_cc[VREPRINT] = 0;     /* Ctrl-r */
        newtio.c_cc[VDISCARD] = 0;     /* Ctrl-u */
        newtio.c_cc[VWERASE]  = 0;     /* Ctrl-w */
        newtio.c_cc[VLNEXT]   = 0;     /* Ctrl-v */
        newtio.c_cc[VEOL2]    = 0;     /* '\0' */

    tcflush(fd, TCIFLUSH);//데이터 청소

    tcsetattr(fd,TCSANOW,&newtio);//포트 초기화 및 설정 적용

       
        res = read(fd, buf, 255); // 버퍼에 읽어들인다. res에는 size가 반환된다.
        buf[res] = 0;           // 버퍼의 끝에 0
        printf("%s",buf);       // 화면에 출력.
    
    close(fd);

    tcsetattr(fd,TCSANOW,&oldtio);
}