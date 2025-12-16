// Dynamic quantum adjustment based on process behaviour
// CPU-bound processes get larger quantum to reduce context switches

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "process.h"

void adjustQuantum(Process &p) {
    if (p.isIOBound)
        p.quantum = 3;   // I/O-bound → short burst
    else
        p.quantum = 8;   // CPU-bound → long burst
}

void applyAgeing(Process &p) {
    if (p.waitingTime > 5) {
        p.priority++;
        p.waitingTime = 0;
    }
}

#endif
