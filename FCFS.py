def fcfs(processes):
    n = len(processes)
    queue = []
    current_time = 0

    for process in processes:
        queue.append(process)

    while queue:
        current_process = queue.pop(0)
        start_time = max(current_time, current_process['arrival_time'])
        current_process['start_time'] = start_time
        current_time = start_time + current_process['burst_time']
        current_process['completion_time'] = current_time
        current_process['turnaround_time'] = current_process['completion_time'] - current_process['arrival_time']
        current_process['waiting_time'] = current_process['turnaround_time'] - current_process['burst_time']
        current_process['response_time'] = current_process['start_time'] - current_process['arrival_time']

    total_waiting_time = sum(process['waiting_time'] for process in processes)
    total_turnaround_time = sum(process['turnaround_time'] for process in processes)
    total_completion_time = sum(process['completion_time'] for process in processes)
    total_response_time = sum(process['response_time'] for process in processes)

    average_waiting_time = total_waiting_time / n
    average_turnaround_time = total_turnaround_time / n
    average_completion_time = total_completion_time / n
    average_response_time = total_response_time / n

    print("Process\t  Arrival Time\t  Burst Time\t  Completion Time\t  Turnaround Time\t  Waiting Time\t  Response Time")
    for process in processes:
        print(f"{process['id']}\t\t\t\t{process['arrival_time']}\t\t\t\t{process['burst_time']}\t\t\t\t{process['completion_time']}\t\t\t\t\t{process['turnaround_time']}\t\t\t\t\t{process['waiting_time']}\t\t\t\t{process['response_time']}")

    print(f"\nAverage Waiting Time: {average_waiting_time}")
    print(f"Average Turnaround Time: {average_turnaround_time}")
    print(f"Average Completion Time: {average_completion_time}")
    print(f"Average Response Time: {average_response_time}")


# Example usage
processes = [
    {'id': 1, 'arrival_time': 0, 'burst_time': 8},
    {'id': 2, 'arrival_time': 1, 'burst_time': 4},
    {'id': 3, 'arrival_time': 2, 'burst_time': 9},
    {'id': 4, 'arrival_time': 3, 'burst_time': 5},
    {'id': 5, 'arrival_time': 4, 'burst_time': 2}
]

fcfs(processes)
