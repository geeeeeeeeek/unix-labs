//
// Created by Zhongyi Tong on 4/16/16.
//

#ifndef LAB1_TIMER_H
#define LAB1_TIMER_H

#endif //LAB1_TIMER_H

#include <sys/times.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <stdio.h>

clock_t start, finish;
clock_t cstart, cfinish;
struct tms tmsstart;
struct tms tmsfinish;
long clktck;

void timer_start();

void timer_finish(int BUFSIZE, int iterations);