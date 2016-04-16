//
// Created by Zhongyi Tong on 4/15/16.
//

#include <stdlib.h>
#include <string.h>
#include "timer.h"

void timer_start() {
    clktck = sysconf(_SC_CLK_TCK);

    start = clock();
    cstart = times(&tmsstart);
}

void timer_finish(int BUFSIZE, int iterations) {
    cfinish = times(&tmsfinish);
    finish = clock();

    int clocks = (int) (finish - start);
    double real = (cfinish - cstart) / (double) clktck;
    double user = (tmsfinish.tms_utime - tmsstart.tms_utime) / (double) clktck;
    double system = (tmsfinish.tms_stime - tmsstart.tms_stime) / (double) clktck;

    /* console friendly log */
//    printf("=== BUFSIZE %d ===\n", BUFSIZE);
//    printf("clocks: %d\n", clocks);
//    printf("real: %f\n", real);
//    printf("user: %f\n", user);
//    printf("system: %f\n", system);
//    printf("iterations: %d", iterations);
//    printf("\n");

    /* markdown table row */
    printf("|%d|%f|%f|%f|%d|%d|\n", BUFSIZE, real, user, system, clocks, iterations);
    memset(&tmsstart, 0, sizeof(struct tms));
    memset(&tmsfinish, 0, sizeof(struct tms));
}