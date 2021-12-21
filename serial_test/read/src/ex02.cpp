/* Non-Canonical 입력(read)처리 예제 */
//------------------------------------------------------------------------------
//  Non-Canonical 입력 처리 모드에서는 입력이 한 줄 단위로 처리되지 않는다.
//  erase, kill, delete 등의 입력 처리도 수행되지 않는다.
//  newtio.c_cc[VTIME]과 newtio.c_cc[VMIN]을 수정하여 위 네 가지 방식을 테스트 할 수 있다. 
//------------------------------------------------------------------------------
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>     // bzero ...
#include <fcntl.h>      // open ...
#include <stdlib.h>     // exit ...
#include <unistd.h>     // read, write ...
#include <termios.h>    // tcgetattr ...

#define BAUDRATE B38400
#define MODEMDEVICE "/dev/ttyS1"
#define _POSIX_SOURCE 1
#define FALSE 0
#define TRUE 1

volatile int STOP02=FALSE;

int main(){

    int fd,c, res;
    struct termios oldtio,newtio;
    char buf[255];

    fd = open(MODEMDEVICE, O_RDWR | O_NOCTTY );
    if (fd < 0) {perror(MODEMDEVICE); exit(-1); }

    tcgetattr(fd,&oldtio); /* 현재 설정을 oldtio에 저장 */
    
    bzero(&newtio, sizeof(newtio));
    newtio.c_cflag = BAUDRATE | CRTSCTS | CS8 | CLOCAL | CREAD;
    newtio.c_iflag = IGNPAR;
    newtio.c_oflag = 0;

    /* set input mode (non-canonical, no echo,...) */
    newtio.c_lflag = 0;

    newtio.c_cc[VTIME]    = 0;   // 문자 사이의 timer를 disable
    newtio.c_cc[VMIN]     = 5;   // 최소 5 문자 받을 때까진 blocking

    tcflush(fd, TCIFLUSH);
    tcsetattr(fd,TCSANOW,&newtio);

    while (STOP02==FALSE) {              // loop for input
        res = read(fd,buf,255);          // 최소 5 문자를 받으면 리턴
        buf[res]=0;                      // '\0' 종료 문자열(printf를 하기 위해)
        printf(":%s:%d\n", buf, res);
        
        if (buf[0]=='z') STOP02=TRUE;
    }

    tcsetattr(fd,TCSANOW,&oldtio);
}