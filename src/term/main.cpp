/*
 * University of Illinois/NCSA
 * Open Source License
 *
 *  Copyright (c) 2012,The Board of Trustees of the University of
 *  Illinois.  All rights reserved.
 *
 *  Copyright (c) 2012 Sam King
 *
 *  Developed by:
 *
 *  Professor Sam King in the Department of Computer Science
 *  The University of Illinois at Urbana-Champaign
 *      http://www.cs.uiuc.edu/homes/kingst/Research.html
 *
 *       Permission is hereby granted, free of charge, to any person
 *       obtaining a copy of this software and associated
 *       documentation files (the "Software"), to deal with the
 *       Software without restriction, including without limitation
 *       the rights to use, copy, modify, merge, publish, distribute,
 *       sublicense, and/or sell copies of the Software, and to permit
 *       persons to whom the Software is furnished to do so, subject
 *       to the following conditions:
 *
 *          Redistributions of source code must retain the above
 *          copyright notice, this list of conditions and the
 *          following disclaimers.
 *
 *          Redistributions in binary form must reproduce the above
 *          copyright notice, this list of conditions and the
 *          following disclaimers in the documentation and/or other
 *          materials provided with the distribution.
 *
 *          Neither the names of Sam King, the University of Illinois,
 *          nor the names of its contributors may be used to endorse
 *          or promote products derived from this Software without
 *          specific prior written permission.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT.  IN NO EVENT SHALL THE CONTRIBUTORS OR COPYRIGHT
 *  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *  DEALINGS WITH THE SOFTWARE.
*/

// Run this program on your host to control the arduio via USB

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
