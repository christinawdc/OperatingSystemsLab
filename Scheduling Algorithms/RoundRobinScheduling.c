#include <stdio.h>

void calculateTimes(int burst_time[], int n, int quantum) {
    int waiting_time[n], turn_around_time[n];
    int remaining_time[n];
    int total_waiting_time = 0, total_turnaround_time = 0;
    int time = 0;  // Current time

    // Initialize remaining time with burst times
    for (int i = 0; i < n; i++) {
        remaining_time[i] = burst_time[i];
    }

    int remaining_processes = n;

    // Gantt Chart printing
    printf("\nGantt Chart:\n");
    printf("-----------------------------------------------------\n");
    printf("|");

    // Round Robin scheduling
    while (remaining_processes > 0) {
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                printf(" P%d |", i + 1); // Print process in Gantt chart
                if (remaining_time[i] > quantum) {
                    // Process gets fully executed in this time quantum
                    time += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    // Process completes execution
                    time += remaining_time[i];
                    waiting_time[i] = time - burst_time[i];
                    turn_around_time[i] = waiting_time[i] + burst_time[i];
                    remaining_time[i] = 0; // Process is complete
                    remaining_processes--; // One less process to handle
                }
            }
        }
    }
    printf("\n-----------------------------------------------------\n");
     
    // Printing process details
    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turn_around_time[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], waiting_time[i], turn_around_time[i]);
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_waiting_time / n);
    printf("\nAverage Turnaround Time: %.2f", (float)total_turnaround_time / n);
}

int main() {
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burst_time[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter Burst Time for Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d", &quantum);

    calculateTimes(burst_time, n, quantum);

    return 0;
}
