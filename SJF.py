def sjf_scheduling(processes):
    # Sort the list of processes based on burst time in ascending order
    sorted_processes = sorted(processes, key=lambda x: x["burst_time"])

    current_time = 0
    completed_processes = []

    while sorted_processes:
        shortest_process = None
        for process in sorted_processes:
            if process["arrival_time"] <= current_time:
                if shortest_process is None or process["burst_time"] < shortest_process["burst_time"]:
                    shortest_process = process

        if shortest_process is None:
            current_time += 1
            continue

        completed_processes.append(shortest_process)
        current_time += shortest_process["burst_time"]
        sorted_processes.remove(shortest_process)

        for process in sorted_processes:
            process["burst_time"] -= shortest_process["burst_time"]

    # Calculate waiting time and turnaround time
    total_waiting_time = 0
    total_turnaround_time = 0

    for i, process in enumerate(completed_processes):
        waiting_time = sum(p["burst_time"] for p in completed_processes[:i])
        turnaround_time = waiting_time + process["burst_time"]

        process["waiting_time"] = waiting_time
        process["turnaround_time"] = turnaround_time

        total_waiting_time += waiting_time
        total_turnaround_time += turnaround_time

    # Calculate average waiting time and average turnaround time
    n = len(completed_processes)
    avg_waiting_time = total_waiting_time / n
    avg_turnaround_time = total_turnaround_time / n

    return completed_processes, avg_waiting_time, avg_turnaround_time

# Example usage:
processes = [
    {"arrival_time": 0, "burst_time": 5},
    {"arrival_time": 1, "burst_time": 3},
    {"arrival_time": 2, "burst_time": 8},
    {"arrival_time": 3, "burst_time": 6},
    {"arrival_time": 4, "burst_time": 4},
]

completed_processes, avg_waiting_time, avg_turnaround_time = sjf_scheduling(processes)

# Print the results
print("Process\tWaiting Time\tTurnaround Time")
for process in completed_processes:
    print(f"{process['arrival_time']}\t{process['waiting_time']}\t\t{process['turnaround_time']}")

print(f"\nAverage Waiting Time: {avg_waiting_time}")
print(f"Average Turnaround Time: {avg_turnaround_time}")
