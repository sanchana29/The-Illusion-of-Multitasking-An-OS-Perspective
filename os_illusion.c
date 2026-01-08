#include <stdio.h>

typedef struct {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

int main() {
    int n = 3;

    Process p[3] = {
        {1, 4, 0, 0},
        {2, 3, 0, 0},
        {3, 5, 0, 0}
    };

    printf("Simulating CPU Scheduling (FCFS)\n");
    printf("Demonstrating the illusion of multitasking...\n\n");

    // Waiting time calculation
    p[0].waiting_time = 0;
    for (int i = 1; i < n; i++) {
        p[i].waiting_time = p[i - 1].waiting_time + p[i - 1].burst_time;
    }

    // Turnaround time calculation
    for (int i = 0; i < n; i++) {
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
    }

    // CPU Timeline with Context Switching
    int time = 0;
    printf("CPU Execution Timeline:\n\n");

    for (int i = 0; i < n; i++) {
        printf("Time %d -> %d : Process P%d is running\n",
               time, time + p[i].burst_time, p[i].pid);

        time += p[i].burst_time;

        if (i < n - 1) {
            printf("Context switch: CPU moving from P%d to P%d\n\n",
                   p[i].pid, p[i + 1].pid);
        }
    }

    // Final Table
    printf("\nProcess Details:\n");
    printf("PID\tBurst\tWaiting\tTurnaround\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t\t%d\n",
               p[i].pid,
               p[i].burst_time,
               p[i].waiting_time,
               p[i].turnaround_time);
    }

    printf("\nConclusion:\n");
    printf("The CPU executes one process at a time.\n");
    printf("Context switching creates the illusion of multitasking.\n");

    return 0;
}
