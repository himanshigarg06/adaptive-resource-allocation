let processCount = 0;

function addProcess() {
    processCount++;
    const container = document.getElementById("process-container");

    container.insertAdjacentHTML("beforeend", `
        <div class="row mt-2">
            <div class="col-4">
                <input id="arrival${processCount}" type="number" class="form-control" placeholder="Arrival Time">
            </div>
            <div class="col-4">
                <input id="burst${processCount}" type="number" class="form-control" placeholder="Burst Time">
            </div>
            <div class="col-4">
                <input disabled value="P${processCount}" class="form-control">
            </div>
        </div>
    `);
}

async function runSimulation() {
    let processes = [];

    for (let i = 1; i <= processCount; i++) {
        let arrival = document.getElementById("arrival" + i).value;
        let burst = document.getElementById("burst" + i).value;

        if (arrival === "" || burst === "") continue;

        processes.push({
            pid: i,
            arrival: parseInt(arrival),
            burst: parseInt(burst)
        });
    }

    // Call backend (compiled C++ exe)
    const response = await fetch("http://localhost:5000/run", {
        method: "POST",
        headers: {"Content-Type": "application/json"},
        body: JSON.stringify(processes)
    });

    const result = await response.text();
    document.getElementById("output").textContent = result;
}
