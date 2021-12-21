// 3. 에코 기능 구현하기 : 따로 오픈하기  testing
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/stat.h>
//------------------------------------------------------------------------------ 
#define BAUDRATE B9600
#define MODEMDEVICE "/dev/ttyS1"
//#define CONTENTS "abcabcabc\n" // \x04 : EOT
//#define CONSIZE strlen(CONTENTS)
#define BUFSIZE 255
//------------------------------------------------------------------------------ 
#define _POSIX_SOURCE 1 
#define FALSE 0
#define TRUE 1

//volatile int STOP=FALSE;

int main(){
    
    int STOP=FALSE;
    int fd_tx = 0;
    struct termios oldtio, newtio;

    // TX OPEN
    fd_tx = open(MODEMDEVICE, O_RDWR|O_NOCTTY|O_NDELAY );
    if (fd_tx < 0) {
        printf( "TX Device OPEN FAIL\n");
        exit(-1);
    }

    tcgetattr(fd_tx, &oldtio); /* save current serial port settings */
    bzero(&newtio, sizeof(newtio)); /* clear struct for new port settings */


    /*
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
    tcflush(fd_tx, TCIFLUSH);
    tcsetattr(fd_tx, TCSANOW, &newtio);

    char buf_tx[BUFSIZE] = {0, };
    char buf_rx[BUFSIZE] = {0, };

    // while (w_STOP==FALSE) { 
    printf("CONTENTS IN : ");
    fscanf(stdin, "%s", buf_tx);

    // 데이터 보내기
    write(fd_tx, buf_tx, strlen(buf_tx));
    write(fd_tx, "\n", 1);

    // TX CLOSE
    close(fd_tx);

// ------------------------------------------------------------------------
    
    int fd_rx = 0;
    struct termios oldtio_r, newtio_r;

    // RX OPEN
    fd_rx = open(MODEMDEVICE, O_RDWR|O_NOCTTY );
    if (fd_rx < 0) {
        printf( "RX Device OPEN FAIL\n");
        exit(-1);
    }
    
    tcgetattr(fd_rx, &oldtio_r);
    bzero(&newtio_r, sizeof(newtio_r));

    newtio_r.c_cflag = BAUDRATE | CRTSCTS | CS8 | CLOCAL | CREAD;
    newtio_r.c_iflag = IGNPAR | ICRNL;
    newtio_r.c_oflag = 0;
    newtio_r.c_lflag = ICANON;

    newtio_r.c_cc[VINTR]    = 0;     /* Ctrl-c */
    newtio_r.c_cc[VQUIT]    = 0;     /* Ctrl-\ */
    newtio_r.c_cc[VERASE]   = 0;     /* del */
    newtio_r.c_cc[VKILL]    = 0;     /* @ */
    newtio_r.c_cc[VEOF]     = 4;     /* Ctrl-d */
    newtio_r.c_cc[VTIME]    = 0;     /* inter-character timer unused */
    newtio_r.c_cc[VMIN]     = 1;     /* blocking read until 1 character arrives */
    newtio_r.c_cc[VSWTC]    = 0;     /* '\0' */
    newtio_r.c_cc[VSTART]   = 0;     /* Ctrl-q */
    newtio_r.c_cc[VSTOP]    = 0;     /* Ctrl-s */
    newtio_r.c_cc[VSUSP]    = 1;     /* Ctrl-z */
    newtio_r.c_cc[VEOL]     = 0;     /* '\0' */
    newtio_r.c_cc[VREPRINT] = 0;     /* Ctrl-r */
    newtio_r.c_cc[VDISCARD] = 0;     /* Ctrl-u */
    newtio_r.c_cc[VWERASE]  = 0;     /* Ctrl-w */
    newtio_r.c_cc[VLNEXT]   = 0;     /* Ctrl-v */
    newtio_r.c_cc[VEOL2]    = 0;     /* '\0' */

    tcflush(fd_rx, TCIFLUSH);
    //tcgetattr(fd_rx, TCSANOW, &newtio_r);

   //while (test01_STOP==FALSE) { 
        // 데이터 읽어오기
        int res = 0;
        res = read(fd_rx, buf_rx, BUFSIZE);
        buf_rx[res]=0;
        printf("%s\n", buf_rx);

        //if (buf_rx[0]=='z'){
        //  test01_STOP=TRUE;
        //}
    //}
    
    // RX CLOSE
    close(fd_rx);

// ------------------------------------------------------------------------
/*
    char str;
    printf("RECEIVE CONTENTS : %s", str);
*/
    //int con_size = sizeof(CONTENTS);
    //printf("CONTENTS SIZE : %d\n", con_size);
   

    /* restore the old port settings */
    tcsetattr(fd_tx, TCSANOW, &oldtio);
    //tcgetattr(fd_rx, TCSANOW, &oldtio_r);
   
}