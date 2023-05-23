class Process:
    def __init__(self, name, priority, burst_time):
        self.name = name
        self.priority = priority
        self.burst_time = burst_time

def multilevel_queue_scheduling(processes):
    num_queues = 3  # Number of priority queues
    queues = [[] for _ in range(num_queues)]  # Initialize empty queues
    
    for process in processes:
        priority = process.priority
        queues[priority].append(process)  # Assign process to the appropriate queue based on priority
    
    while True:
        for i in range(num_queues):
            if queues[i]:  # Check if queue is not empty
                current_process = queues[i][0]  # Get the process at the front of the queue
                print("Executing process:", current_process.name)
                current_process.burst_time -= 1  # Execute the process by reducing its burst time
                
                if current_process.burst_time == 0:  # Process has completed execution
                    queues[i].pop(0)  # Remove the completed process from the queue
                elif i < num_queues - 1:  # Move the process to a lower priority queue
                    queues[i+1].append(queues[i].pop(0))
                    
                if not any(queues):  # Check if all queues are empty
                    return

# Example usage
processes = [
    Process("P1", 0, 5),
    Process("P2", 1, 3),
    Process("P3", 2, 2),
    Process("P4", 0, 4),
    Process("P5", 1, 1)
]

multilevel_queue_scheduling(processes)
