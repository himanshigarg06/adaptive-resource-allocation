const logs = [
    "[TIME 0] Running Process P1 | Quantum: 8",
    "[MEM] High PFF → +2 frames",
    "[MON] PID: 1 | Remaining Burst: 17 | Frames: 6 | Page Faults: 8",
    "",
    "[TIME 8] Running Process P2 | Quantum: 3",
    "[MON] PID: 2 | Remaining Burst: 12 | Frames: 4 | Page Faults: 2",
    "",
    "[TIME 11] Running Process P3 | Quantum: 8",
    "[MEM] Low PFF → -1 frame",
    "[MON] PID: 3 | Remaining Burst: 22 | Frames: 3 | Page Faults: 1",
    "",
    "[DONE] Process P2 completed"
];

let index = 0;
const logBox = document.getElementById("simulation-log");

function printLog() {
    if (index < logs.length) {
        logBox.textContent += logs[index] + "\n";
        index++;
        setTimeout(printLog, 700);
    }
}

window.onload = () => {
    logBox.textContent = "";
    printLog();
};