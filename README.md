# Adaptive Resource Allocation in Multiprogramming Systems

## Project Overview
This project simulates how modern operating systems dynamically allocate
CPU time and memory based on real-time process behaviour.

Instead of using fixed scheduling and memory allocation, the system adapts
its decisions using continuous monitoring.

## Key Features
- Dynamic Round Robin CPU Scheduling
- CPU-bound and I/O-bound process classification
- Ageing to prevent starvation
- Working Set Model (WSM) for memory usage
- Page Fault Frequency (PFF) based frame allocation
- Continuous monitoring and logging
- Frontend page for visualization

## Simulation Visualization
The backend simulation runs as a C++ program and produces
execution logs in the terminal.

For demonstration purposes, the frontend includes a
visual simulation log that represents this backend execution
in a terminal-style interface. This helps in understanding
CPU scheduling and memory allocation behaviour visually.

## Technologies Used
- C++ (Backend simulation)
- HTML & CSS (Frontend visualization)
- Git & GitHub (Version control)

## How to Compile and Run
```bash
g++ main.cpp -o adaptive
./adaptive

Project Structure
.
├── main.cpp
├── process.h
├── scheduler.h
├── memory.h
├── monitor.h
├── frontend/
│   ├── index.html
│   └── style.css
├── README.md
└── .gitignore

