def priority_scheduling(processes):
    processes.sort(key=lambda x: x['priority'])  # Sort processes based on priority

    current_time = 0
    ready_queue = []
    completed_processes = []

    while processes or ready_queue:
        # Add processes to ready_queue whose arrival time is less than or equal to the current_time
        for process in processes:
            if process['arrival_time'] <= current_time:
                ready_queue.append(process)
        processes = [p for p in processes if p['arrival_time'] > current_time]

        if not ready_queue:
            current_time += 1
            continue

        # Sort ready_queue based on priority (higher priority first)
        ready_queue.sort(key=lambda x: x['priority'], reverse=True)

        # Execute process with highest priority from ready_queue
        current_process = ready_queue.pop(0)
        burst_time = current_process['burst_time']

        # Execute the process for its burst time
        current_time += burst_time

        if burst_time > 0:
            current_process['burst_time'] -= burst_time
            ready_queue.append(current_process)

        if current_process['burst_time'] == 0:
            completed_processes.append(current_process)

    # Calculate waiting time for each completed process
    for process in completed_processes:
        process['waiting_time'] = process['completion_time'] - process['arrival_time'] - process['burst_time']

    # Calculate average waiting time
    total_waiting_time = sum(process['waiting_time'] for process in completed_processes)
    average_waiting_time = total_waiting_time / len(completed_processes)

    return completed_processes, average_waiting_time


# Example usage
processes = [
    {'arrival_time': 0, 'burst_time': 5, 'priority': 2},
    {'arrival_time': 1, 'burst_time': 3, 'priority': 1},
    {'arrival_time': 2, 'burst_time': 6, 'priority': 3},
    {'arrival_time': 4, 'burst_time': 2, 'priority': 4},
    {'arrival_time': 5, 'burst_time': 4, 'priority': 1}
]

completed_processes, average_waiting_time = priority_scheduling(processes)

print("Completed Processes:")
for process in completed_processes:
    print(process)

print("Average Waiting Time:", average_waiting_time)
