#ifndef MONITOR_H
#define MONITOR_H

#include "process.h"
#include <iostream>
using namespace std;

void monitorProcess(Process &p) {
    cout << "   [MON] PID: " << p.pid
         << " | Remaining: " << p.remainingBurst
         << " | Frames: " << p.frames
         << " | PFF: " << p.pageFaults << "\n";
}

#endif

