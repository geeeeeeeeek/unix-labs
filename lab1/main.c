#include "timer.h"
#include "my_fread.h"
#include <stdlib.h>

int test_fread();

int test_read();

int test_write_without_flag();

int test_write_with_flag();

int test_my_fread();

int main(int argc, char **argv) {

//    test_read();

//    test_fread();

//    test_write_without_flag();

//    test_write_with_flag();

//    test_my_fread();

    return 0;
}

int test_read() {
    for (int BUFSIZE = 524288; BUFSIZE >= 2; BUFSIZE /= 2) {
        char buf[BUFSIZE];
        int fd = open("./data", O_RDONLY);

        int iterations = 0;
        timer_start();
        while (read(fd, buf, BUFSIZE) > 0) {
            iterations += 1;
        }
        timer_finish(BUFSIZE, iterations);

        memset(&buf, 0, BUFSIZE);
    }
    return 0;
}

int test_fread() {
    for (int BUFSIZE = 524288; BUFSIZE >= 2; BUFSIZE /= 2) {
        FILE *file = fopen("./data", "r");

        char buf[BUFSIZE];

        int iterations = 0;
        timer_start();
        while (fread(buf, BUFSIZE, 1, file) > 0) {
            iterations += 1;
        }
        timer_finish(BUFSIZE, iterations);

        memset(&buf, 0, BUFSIZE);
    }
    return 0;
}

int test_my_fread() {
    for (int BUFSIZE = 2; BUFSIZE <= 524288; BUFSIZE *= 2) {
        char buf[BUFSIZE];
        int fd = open("./data", O_RDONLY);

        offset = -1;
        size = 0;

        int iterations = 0;
        timer_start();
        while (my_fread(fd, buf, BUFSIZE) > 0) {
            iterations += 1;
        }
        timer_finish(BUFSIZE, iterations);

        memset(&buf, 0, BUFSIZE);
    }
    return 0;
}


int test_write_without_flag() {
    for (int BUFSIZE = 2; BUFSIZE <= 524288; BUFSIZE *= 2) {
        int FILESIZE = 326631424;
        char *buf = malloc(BUFSIZE);
        int wfd = open("./out", O_WRONLY | O_CREAT);

        int iterations = 0;
        int n;
        timer_start();
        while (FILESIZE > 0) {
            iterations += 1;
            n = (int) write(wfd, buf, BUFSIZE);
            FILESIZE -= n;
        }
        timer_finish(BUFSIZE, iterations);

        memset(buf, 0, BUFSIZE);
    }
    return 0;
}


int test_write_with_flag() {
    for (int BUFSIZE = 1024; BUFSIZE <= 524288; BUFSIZE *= 2) {
        int FILESIZE = 326631424;
        char *buf = malloc(BUFSIZE);
        int wfd = open("./out", O_WRONLY | O_CREAT | O_SYNC);

        int iterations = 0;
        int n;
        timer_start();
        while (FILESIZE > 0) {
            iterations += 1;
            n = (int) write(wfd, buf, BUFSIZE);
            FILESIZE -= n;
        }
        timer_finish(BUFSIZE, iterations);

        memset(buf, 0, BUFSIZE);
    }
    return 0;
}
