#include <stdio.h>

#define MAX_PROCESSES 10

// Structure to represent a process
typedef struct {
    int process_id;
    int burst_time;
} Process;

// Function to simulate Multilevel Queue Scheduling
void multilevel_queue_scheduling(Process processes[], int num_processes) {
    int quantum1 = 5; // Time quantum for Queue 1
    int quantum2 = 10; // Time quantum for Queue 2

    int queue1[MAX_PROCESSES];
    int queue2[MAX_PROCESSES];
    int queue3[MAX_PROCESSES];
    int front1 = -1, rear1 = -1;
    int front2 = -1, rear2 = -1;
    int front3 = -1, rear3 = -1;

    // Enqueue process into Queue 1
    void enqueue_queue1(int process_id) {
        if (rear1 == MAX_PROCESSES - 1) {
            printf("Queue 1 is full, cannot enqueue process %d\n", process_id);
            return;
        }
        if (front1 == -1)
            front1 = 0;
        rear1++;
        queue1[rear1] = process_id;
    }

    // Enqueue process into Queue 2
    void enqueue_queue2(int process_id) {
        if (rear2 == MAX_PROCESSES - 1) {
            printf("Queue 2 is full, cannot enqueue process %d\n", process_id);
            return;
        }
        if (front2 == -1)
            front2 = 0;
        rear2++;
        queue2[rear2] = process_id;
    }

    // Enqueue process into Queue 3
    void enqueue_queue3(int process_id) {
        if (rear3 == MAX_PROCESSES - 1) {
            printf("Queue 3 is full, cannot enqueue process %d\n", process_id);
            return;
        }
        if (front3 == -1)
            front3 = 0;
        rear3++;
        queue3[rear3] = process_id;
    }

    // Dequeue process from Queue 1
    int dequeue_queue1() {
        if (front1 == -1 || front1 > rear1) {
            printf("Queue 1 is empty, cannot dequeue process\n");
            return -1;
        }
        int process_id = queue1[front1];
        front1++;
        return process_id;
    }

    // Dequeue process from Queue 2
    int dequeue_queue2() {
        if (front2 == -1 || front2 > rear2) {
            printf("Queue 2 is empty, cannot dequeue process\n");
            return -1;
        }
        int process_id = queue2[front2];
        front2++;
        return process_id;
    }

    // Dequeue process from Queue 3
    int dequeue_queue3() {
        if (front3 == -1 || front3 > rear3) {
            printf("Queue 3 is empty, cannot dequeue process\n");
            return -1;
        }
        int process_id = queue3[front3];
        front3++;
        return process_id;
    }

    // Simulate execution of process
    void execute_process(int process_id, int burst_time) {
        printf("Executing process %d with burst time %d\n", process_id, burst_time);
    }

    // Multilevel Queue Scheduling logic
    void schedule_processes() {
        int i;
        // Execute processes in Queue 1
        for (i = front1; i <= rear1; i++) {
            int process_id = dequeue_queue1();
            Process process = processes[process_id];
            execute_process(process.process_id, process.burst_time);
        }

        // Execute processes in Queue 2
        for (i = front2; i <= rear2; i++) {
            int process_id = dequeue_queue2();
            Process process = processes[process_id];
            execute_process(process.process_id, process.burst_time);
        }

        // Execute processes in Queue 3
        for (i = front3; i <= rear3; i++) {
            int process_id = dequeue_queue3();
            Process process = processes[process_id];
            execute_process(process.process_id, process.burst_time);
        }
    }

    // Enqueue processes into appropriate queues based on their burst time
    void enqueue_processes() {
        int i;
        for (i = 0; i < num_processes; i++) {
            Process process = processes[i];
            if (process.burst_time <= quantum1)
                enqueue_queue1(process.process_id);
            else if (process.burst_time <= quantum2)
                enqueue_queue2(process.process_id);
            else
                enqueue_queue3(process.process_id);
        }
    }

    // Display the contents of each queue
    void display_queues() {
        printf("Queue 1: ");
        for (int i = front1; i <= rear1; i++)
            printf("%d ", queue1[i]);
        printf("\n");

        printf("Queue 2: ");
        for (int i = front2; i <= rear2; i++)
            printf("%d ", queue2[i]);
        printf("\n");

        printf("Queue 3: ");
        for (int i = front3; i <= rear3; i++)
            printf("%d ", queue3[i]);
        printf("\n");
    }

    printf("Initial Process Queue:\n");
    display_queues();

    enqueue_processes();

    printf("\nProcess Queue after Enqueuing Processes:\n");
    display_queues();

    schedule_processes();
}

int main() {
    // Example processes
    Process processes[] = {
        {0, 8},
        {1, 12},
        {2, 4},
        {3, 6},
        {4, 10}
    };
    int num_processes = sizeof(processes) / sizeof(Process);

    multilevel_queue_scheduling(processes, num_processes);

    return 0;
}
