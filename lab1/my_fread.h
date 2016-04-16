//
// Created by Zhongyi Tong on 4/16/16.
//

#ifndef LAB1_MY_FREAD_H
#define LAB1_MY_FREAD_H

#endif //LAB1_MY_FREAD_H

#include <unistd.h>
#include <memory.h>

#define MY_BUFSIZE 32768


extern int offset;
extern int size;
char myBuf[MY_BUFSIZE];

int my_fread(int fd, void *buf, int BUFSIZE);
