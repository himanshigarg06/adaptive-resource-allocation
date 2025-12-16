#ifndef MEMORY_H
#define MEMORY_H

#include "process.h"
#include <iostream>
using namespace std;

void adjustFrames(Process &p) {
    int upperPFF = 7;
    int lowerPFF = 2;

    if (p.pageFaults > upperPFF) {
        p.frames += 2;
        cout << "   [MEM] P" << p.pid << " high PFF → +2 frames\n";
    }
    else if (p.pageFaults < lowerPFF && p.frames > 2) {
        p.frames -= 1;
        cout << "   [MEM] P" << p.pid << " low PFF → -1 frame\n";
    }
}

#endif
