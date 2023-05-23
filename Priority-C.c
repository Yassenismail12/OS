#include <stdio.h>

// Structure to represent a process
struct Process {
    int id;           // Process ID
    int burst_time;   // Burst time of the process
    int priority;     // Priority of the process
};

// Function to execute Priority Scheduling algorithm
void priorityScheduling(struct Process processes[], int n) {
    int total_time = 0;
    
    // Calculate total time required for all processes
    for (int i = 0; i < n; i++) {
        total_time += processes[i].burst_time;
    }
    
    // Sort the processes based on priority (ascending order)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                // Swap processes
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
    
    // Execute processes in priority order
    for (int i = 0; i < n; i++) {
        printf("Executing process %d for burst time %d\n", processes[i].id, processes[i].burst_time);
        
        // Update total_time and burst_time
        total_time -= processes[i].burst_time;
        processes[i].burst_time = 0;
        
        // Print completion message
        printf("Process %d completed.\n", processes[i].id);
        
        // Break the loop if all processes completed
        if (total_time == 0) {
            break;
        }
    }
}

int main() {
    // Create an array of processes
    struct Process processes[] = {
        {1, 10, 3},
        {2, 5, 2},
        {3, 8, 1},
        {4, 3, 4}
    };
    
    int n = sizeof(processes) / sizeof(processes[0]);
    
    // Execute Priority Scheduling algorithm
    priorityScheduling(processes, n);
    
    return 0;
}
