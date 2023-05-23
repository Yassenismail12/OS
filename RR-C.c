#include <stdio.h>

#define MAX_PROCESSES 100

void roundRobinScheduling(int processes[], int n, int timeSlice) {
    int remainingTime[MAX_PROCESSES];
    int i, currentTime = 0, completed = 0;

    // Copy burst times to remainingTime array
    for (i = 0; i < n; i++) {
        remainingTime[i] = processes[i];
    }

    while (completed != n) {
        for (i = 0; i < n; i++) {
            if (remainingTime[i] > 0) {
                if (remainingTime[i] <= timeSlice) {
                    currentTime += remainingTime[i];
                    printf("Process %d completed. Completion time: %d\n", i + 1, currentTime);
                    remainingTime[i] = 0;
                    completed++;
                } else {
                    currentTime += timeSlice;
                    remainingTime[i] -= timeSlice;
                    printf("Time quantum expired for process %d. Remaining time: %d\n", i + 1, remainingTime[i]);
                }
            }
        }
    }
}

int main() {
    int processes[MAX_PROCESSES];
    int n, timeSlice;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processes[i]);
    }

    printf("Enter the time quantum: ");
    scanf("%d", &timeSlice);

    roundRobinScheduling(processes, n, timeSlice);

    return 0;
}
