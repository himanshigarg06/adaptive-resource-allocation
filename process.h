#ifndef PROCESS_H
#define PROCESS_H

#include <vector>
using namespace std;

class Process {
public:
    int pid;
    int totalBurst;
    int remainingBurst;
    bool isIOBound;

    int quantum;
    int priority;
    int waitingTime;

    int frames;
    int pageFaults;
    vector<int> workingSet;

    Process(int id, int burst, bool io) {
        pid = id;
        totalBurst = burst;
        remainingBurst = burst;
        isIOBound = io;

        quantum = 4;
        priority = 1;
        waitingTime = 0;

        frames = 4;
        pageFaults = 0;

        for(int i = 0; i < 5; i++)
            workingSet.push_back(rand() % 20);
    }
};

#endif
