
// Monitoring Module
// Continuously observes process execution state
// Displays remaining CPU burst, allocated frames, and page fault count
// Helps the decision module take real-time adaptive actions
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

