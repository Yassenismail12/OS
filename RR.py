from collections import deque

def round_robin_scheduling(processes, time_slice):
    queue = deque(processes)
    while queue:
        process = queue.popleft()
        print(f"Executing process {process} for time quantum {time_slice}")
        if process <= time_slice:
            print(f"Process {process} completed.")
        else:
            print(f"Time quantum {time_slice} expired for process {process}.")
            queue.append(process - time_slice)

processes = [20, 15, 10, 5]  
time_slice = 10  

round_robin_scheduling(processes, time_slice)
