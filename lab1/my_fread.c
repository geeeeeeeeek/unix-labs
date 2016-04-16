//
// Created by Zhongyi Tong on 4/16/16.
//
#include "my_fread.h"

int offset = -1;
int size = 0;

int my_fread(int fd, void *buf, int BUFSIZE) {
    int remains = BUFSIZE;
    int rest;
    while (offset < 0 || remains > 0) {
        rest = size - offset;
        if (remains >= rest) {
            memcpy(buf, myBuf + offset, rest);
            size = read(fd, myBuf, MY_BUFSIZE);
            if (size > 0) {
                offset = 0;
                remains -= rest;
            } else {
                return size;
            }

        } else {
            memcpy(buf, myBuf + offset, remains);
            offset += remains;
            remains = 0;
        }
    }
    return BUFSIZE - remains;
}