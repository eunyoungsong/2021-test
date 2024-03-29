/* Canonical 입력(read)처리 예제 */

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>     // bzero ...
#include <fcntl.h>      // open ...
#include <stdlib.h>     // exit ...
#include <unistd.h>     // read, write ...
#include <termios.h>    // tcgetattr ...

//  Baudrate 설정은 <asm/termbits.h>에 정의되어 있다.
//  <asm/termbits.h>는 <termios.h>에서 include된다.
#define BAUDRATE B38400
#define MODEMDEVICE "/dev/ttyS1" // 포트 장치 파일을 바꾼다. COM1="/dev/ttyS1, COM2="/dev/ttyS2
#define _POSIX_SOURCE 1 // POSIX 호환 소스

#define FALSE 0
#define TRUE 1

volatile int STOP01=FALSE; // 변수를 최적화에서 제외하여 항상 메모리에 접근하도록 만듦

int main(){

    int fd,c, res;
    struct termios oldtio,newtio;
    char buf[255];

    /* 읽기/쓰기 모드로 모뎀 장치를 연다.(O_RDWR)
    데이터 전송 시에 <CTRL>-C 문자가 오면 프로그램이 종료되지 않도록
    하기 위해 controlling tty가 안되도록 한다.(O_NOCTTY)
    */
    fd = open(MODEMDEVICE, O_RDWR | O_NOCTTY );
    if (fd < 0){
        perror(MODEMDEVICE);
        exit(-1);
    }

    tcgetattr(fd,&oldtio); /* save current serial port settings */
    bzero(&newtio, sizeof(newtio)); /* clear struct for new port settings */

    /*
    BAUDRATE: 전송 속도. cfsetispeed() 및 cfsetospeed() 함수로도 세팅 가능
    CRTSCTS : 하드웨어 흐름 제어. (시리얼 케이블이 모든 핀에 연결되어 있는
                    경우만 사용하도록 한다. Serial-HOWTO의 7장을 참조할 것.)
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

    /*
    Raw output.
    */
    newtio.c_oflag = 0;

    /*
    ICANON   : canonical 입력을 가능하게 한다.
    disable all echo functionality, and don't send signals to calling program
    */
    newtio.c_lflag = ICANON;

    /*
    모든 제어 문자들을 초기화한다.
    디폴트 값은 <termios.h> 헤더 파일에서 찾을 수 있다.
    */
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

    /*
    이제 modem 라인을 초기화하고 포트 세팅을 마친다.
    */
    tcflush(fd, TCIFLUSH);
    tcsetattr(fd,TCSANOW,&newtio);

    /*
    터미널 세팅이 끝났고, 이제는 입력을 처리한다.
    이 예제에서는 한 줄의 맨 첫 문자를 'z'로 했을 때 프로그램을
    종료한다.
    */

    /* 종료 조건(STOP==TRUE)가 될 때까지 루프 */
    /* read()는 라인 종료 문자가 나올 때까지 255 문자를 넘어가더라도 block 된다. 
    read 하고자 하는 문자 개수가 입력 가능한 문자 개수보다 적은 경우에는
    또 한번의 read를 하여 나머지를 읽어낼 수 있다.
    res는 read에 의해서 실제로 읽혀진 문자의 개수를 갖게 된다. */
        
    while (STOP01==FALSE) {

        /* 
        Canonical 입력 처리에서 처리할 수 있는 최대 길이의 문자는 255개
        (<linux/limits.h> 혹은 <posix1_lim.h>에 정의됨) 로서
        버퍼의 최대 길이는 255로 제한된다.
        */
        res = read(fd,buf,255);
        buf[res]=0;             /* set end of string, so we can printf */
        printf(":%s:%d\n", buf, res);
        if (buf[0]=='z'){
            STOP01=TRUE;
        }

    }

    // restore the old port settings
    // 모뎀 라인을 초기화하고 포트 setting을 마친다. 
    tcsetattr(fd,TCSANOW,&oldtio);
}

// 출처 : https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=dog9230&logNo=35543543