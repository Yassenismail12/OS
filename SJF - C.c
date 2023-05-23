#include <stdio.h>

void sjf_scheduling(int processes[], int n, int burst_times[]) {
    int completion_times[n];
    int waiting_times[n];
    int turnaround_times[n];

    // Initialize arrays
    for (int i = 0; i < n; i++) {
        completion_times[i] = 0;
        waiting_times[i] = 0;
        turnaround_times[i] = 0;
    }

    int total_time = 0;
    int completed_processes = 0;

    // Find the process with the shortest burst time
    while (completed_processes < n) {
        int shortest_job = -1;
        int shortest_burst = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (burst_times[i] > 0 && burst_times[i] < shortest_burst) {
                shortest_burst = burst_times[i];
                shortest_job = i;
            }
        }

        // Update completion time and increment total time
        completion_times[shortest_job] = total_time + shortest_burst;
        total_time += shortest_burst;
        burst_times[shortest_job] = 0;
        completed_processes++;
    }

    // Calculate waiting and turnaround times
    for (int i = 0; i < n; i++) {
        turnaround_times[i] = completion_times[i];
        waiting_times[i] = turnaround_times[i] - burst_times[i];
    }

    // Print results
    printf("Process\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, burst_times[i], completion_times[i], waiting_times[i], turnaround_times[i]);
    }
}

int main() {
    int n;  // Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n];
    int burst_times[n];

    printf("Enter the burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burst_times[i]);
        processes[i] = i + 1;
    }

    sjf_scheduling(processes, n, burst_times);

    return 0;
}
