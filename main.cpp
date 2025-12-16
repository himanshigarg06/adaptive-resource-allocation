#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#include <algorithm>   // REQUIRED for min()

#include "process.h"
#include "scheduler.h"
#include "memory.h"
#include "monitor.h"

using namespace std;

int main() {

    vector<Process> processes = {
        Process(1, 25, false),   // CPU-bound
        Process(2, 15, true),    // I/O-bound
        Process(3, 30, false),
        Process(4, 18, true)
    };

    queue<int> readyQueue;
    for (int i = 0; i < processes.size(); i++)
        readyQueue.push(i);

    int time = 0;

    cout << "\n=== Adaptive Resource Allocation Simulation ===\n";

    while (!readyQueue.empty()) {

        int idx = readyQueue.front();
        readyQueue.pop();

        Process &p = processes[idx];

        // Decision Module
        adjustQuantum(p);

        cout << "\n[TIME " << time << "] Running Process P"
             << p.pid << " | Quantum: " << p.quantum << endl;

        int execute = min(p.quantum, p.remainingBurst);
        p.remainingBurst -= execute;
        time += execute;

        // Simulate page faults
        p.pageFaults = rand() % 10;

        // Allocation Module
        adjustFrames(p);

        // Monitoring Module
        monitorProcess(p);


        // Ageing (anti-starvation)
        for (auto &other : processes) {
            if (other.pid != p.pid)
                other.waitingTime++;
            applyAgeing(other);
        }

        if (p.remainingBurst > 0)
            readyQueue.push(idx);
        else
            cout << "   [DONE] Process P" << p.pid << " completed\n";
    }

    cout << "\n=== Simulation Finished ===\n";
    return 0;
}
