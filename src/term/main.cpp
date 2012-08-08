#include <iostream>

#include <termios.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

using namespace std;

int main(int argc, char *argv[]) {
    // setup serial port
    if(argc != 2) {
        cerr << "Usage " << argv[0] << ": serialPortDevice" << endl;
        return 0;
    }
    int serialFd = open(argv[1], O_RDWR | O_NOCTTY);
    assert(serialFd >= 0);
    struct termios tio;
    memset(&tio, 0, sizeof(tio));
    tio.c_iflag = 0;
    tio.c_oflag = 0;
    tio.c_cflag = CS8|CREAD|CLOCAL;
    tio.c_lflag = 0;
    tio.c_cc[VMIN] = 1;
    tio.c_cc[VTIME] = 0;
    //cfsetospeed(&tio, B57600);
    //cfsetispeed(&tio, B57600);
    cfsetospeed(&tio, B9600);
    cfsetispeed(&tio, B9600);
    tcsetattr(serialFd, TCSAFLUSH, &tio);

    char buf[256];
    int ret;
    while((ret = read(serialFd, buf, sizeof(buf)-1)) > 0) {        
        buf[ret] = '\0';
        printf("%s", buf);
        fflush(stdout);
        if(buf[ret-1] == '\n')
            break;
    }

    write(serialFd, "100 90\n", strlen("100 90\n"));

    while((ret = read(serialFd, buf, sizeof(buf)-1)) > 0) {        
        buf[ret] = '\0';
        printf("%s", buf);
        fflush(stdout);
    }


    return 0;
}
