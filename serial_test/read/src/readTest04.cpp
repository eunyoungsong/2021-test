// 3. 에코 기능 구현하기
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
#define MODEMDEVICE "/dev/ttyS0"
#define BUFSIZE 255

#define _POSIX_SOURCE 1
#define FALSE 0
#define TRUE 1

//volatile int STOP=FALSE;

int main(){

    int STOP=FALSE;
    int fd, c, res;
    struct termios oldtio, newtio;

    fd = open(MODEMDEVICE, O_RDWR | O_NOCTTY );
    if (fd < 0) {
        perror(MODEMDEVICE);
        exit(-1);
    }

    tcgetattr(fd, &oldtio); /* save current serial port settings */
    bzero(&newtio, sizeof(newtio)); /* clear struct for new port settings */

    newtio.c_cflag = BAUDRATE | CRTSCTS | CS8 | CLOCAL | CREAD;
    newtio.c_iflag = IGNPAR | ICRNL;
    newtio.c_oflag = 0;
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
    newtio.c_cc[VSUSP]    = 0;     /* Ctrl-z */
    newtio.c_cc[VEOL]     = 0;     /* '\0' */
    newtio.c_cc[VREPRINT] = 0;     /* Ctrl-r */
    newtio.c_cc[VDISCARD] = 0;     /* Ctrl-u */
    newtio.c_cc[VWERASE]  = 0;     /* Ctrl-w */
    newtio.c_cc[VLNEXT]   = 0;     /* Ctrl-v */
    newtio.c_cc[VEOL2]    = 0;     /* '\0' */

    tcflush(fd, TCIFLUSH);
    tcsetattr(fd, TCSANOW, &newtio);

    /*
    터미널 세팅이 끝났고, 이제는 입력을 처리한다.
    이 예제에서는 한 줄의 맨 첫 문자를 'z'로 했을 때 프로그램을 종료한다.
    */

    while (STOP==FALSE) {

        char buf[BUFSIZE] = {0, };
        res = 0;
        
        /* 
        Canonical 입력 처리에서 처리할 수 있는 최대 길이의 문자는 255개
        (<linux/limits.h> 혹은 <posix1_lim.h>에 정의됨) 로서
        버퍼의 최대 길이는 255로 제한된다.
        */
        res = read(fd, buf, BUFSIZE);
        buf[res]=0;
        printf("%s", buf);

        write(fd, buf, strlen(buf));
        //write(fd, "\n", 1);

        if (buf[0]=='z'){
            STOP=TRUE;
        }

    }

    /* restore the old port settings */
    tcsetattr(fd, TCSANOW, &oldtio);
    close(fd);
    
}