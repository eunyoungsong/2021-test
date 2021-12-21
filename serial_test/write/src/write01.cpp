// 1. 데이터 보내기
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/stat.h>

/* Baudrate 설정은 <asm/termbits.h>에 정의되어 있다.
/* <asm/termbits.h>는 <termios.h>에서 include된다. */
#define BAUDRATE B9600
#define MODEMDEVICE "/dev/ttyS1"
#define CONTENTS "z\n" // \x04 : EOT
#define CONSIZE strlen(CONTENTS)

#define _POSIX_SOURCE 1 

#define FALSE 0
#define TRUE 1


int main(){
    int fd, c, res;
    struct termios oldtio, newtio;

    fd = open(MODEMDEVICE, O_RDWR|O_NOCTTY );
    if (fd < 0) {
        perror(MODEMDEVICE);
        exit(-1);
    }

    tcgetattr(fd, &oldtio); /* save current serial port settings */
    bzero(&newtio, sizeof(newtio)); /* clear struct for new port settings */

    /*while
    BAUDRATE: 전송 속도. cfsetispeed() 및 cfsetospeed() 함수로도 세팅 가능
    CRTSCTS : 하드웨어 흐름 제어.
            (시리얼 케이블이 모든 핀에 연결되어 있는 경우만 사용하도록 한다. Serial-HOWTO의 7장을 참조할 것.)
    CS8     : 8N1 (8bit, no parity, 1 stopbit)
    CLOCAL  : Local connection. 모뎀 제어를 하지 않는다.
    CREAD   : 문자 수신을 가능하게 한다.
    */
    newtio.c_cflag = BAUDRATE | CRTSCTS | CS8 | CLOCAL | CREAD;

    /*
    IGNPAR   : Parity 에러가 있는 문자 바이트를 무시한다.
    ICRNL    : CR 문자를 NL 문자로 변환 처리한다.
    (이 설정을 안하면 다른 컴퓨터는 CR 문자를 한 줄의 종료문자로 인식하지 않을 수 있다.)
    */
    newtio.c_iflag = IGNPAR | ICRNL;
    newtio.c_oflag = 0;

    /*
    ICANON   : canonical 입력을 가능하게 한다.
    disable all echo functionality, and don't send signals to calling program
    */
    newtio.c_lflag = ICANON;

    newtio.c_cc[VINTR]    = 0;     /* Ctrl-c */
    newtio.c_cc[VQUIT]    = 0;     /* Ctrl-\ */
    newtio.c_cc[VERASE]   = 0;     /* del */
    newtio.c_cc[VKILL]    = 0;     /* @ */
    newtio.c_cc[VEOF]     = 4;     /* Ctrl-d */
    newtio.c_cc[VTIME]    = 0;     /* inter-character timer unused */
    newtio.c_cc[VMIN]     = 1;     /* blocking read until 1 character arrives */
    newtio.c_cc[VSWTC]    = 0;     /* '\0' */
    newtio.c_cc[VSTART]   = 0;     /* Ctrl-q */
    newtio.c_cc[VSTOP]    = 0;     /* Ctrl-s */
    newtio.c_cc[VSUSP]    = 1;     /* Ctrl-z */
    newtio.c_cc[VEOL]     = 0;     /* '\0' */
    newtio.c_cc[VREPRINT] = 0;     /* Ctrl-r */
    newtio.c_cc[VDISCARD] = 0;     /* Ctrl-u */
    newtio.c_cc[VWERASE]  = 0;     /* Ctrl-w */
    newtio.c_cc[VLNEXT]   = 0;     /* Ctrl-v */
    newtio.c_cc[VEOL2]    = 0;     /* '\0' */

    /*
    이제 modem 라인을 초기화하고 포트 세팅을 마친다.
    */
    tcflush(fd, TCIFLUSH);
    tcsetattr(fd, TCSANOW, &newtio);

    /*
    터미널 세팅이 끝났고, 이제는 입력을 처리한다.
    */

    res = write(fd, CONTENTS, CONSIZE);
    //res = write(fd, CONTENTS, strlen(CONTENTS)+1);
    close(fd);

    int con_size = sizeof(CONTENTS);
    printf("CONTENTS SIZE : %d\n", con_size);
   

    /* restore the old port settings */
    tcsetattr(fd, TCSANOW, &oldtio);
   

}