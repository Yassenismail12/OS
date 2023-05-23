#include <stdio.h>

void fcfs_scheduling(int processes[], int n) {
    int waiting_time[n], turnaround_time[n];
    
    waiting_time[0] = 0; // The first process has no waiting time
    
    // Calculate waiting time for each process
    for (int i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i - 1] + processes[i - 1];
    }
    
    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = waiting_time[i] + processes[i];
    }
    
    // Print the process details
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i, processes[i], waiting_time[i], turnaround_time[i]);
    }
}

int main() {
    int n; // Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int processes[n];
    
    // Input burst time for each process
    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i);
        scanf("%d", &processes[i]);
    }
    
    fcfs_scheduling(processes, n);
    
    return 0;
}
