#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int pid;
    int btime;
    int wtime;
} Process;

int main() {
    int i, j, n, total_waiting_time = 0, total_turnaround_time = 0, total_burst_time = 0;
    Process *p, temp;

    printf("\n Shortest Job First Scheduling\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Allocate memory for processes
    p = (Process*)malloc(n * sizeof(Process));

    printf("\nEnter the burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &p[i].btime);
        p[i].pid = i + 1;
        p[i].wtime = 0;
        total_burst_time += p[i].btime;
    }

    // Sort processes based on burst time using Bubble Sort
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (p[j].btime > p[j + 1].btime) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    printf("\nProcess Scheduling\n");
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++) {
        total_waiting_time += p[i].wtime;
        total_turnaround_time += (p[i].wtime + p[i].btime);

        printf("%d\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].btime, p[i].wtime, (p[i].wtime + p[i].btime));

        // Update waiting time for the next process
        p[i + 1].wtime = p[i].wtime + p[i].btime;
    }

    printf("\nTotal Waiting Time: %d\n", total_waiting_time);
    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Total Turnaround Time: %d\n", total_turnaround_time);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);

    free(p); // Release allocated memory

    return 0;
}
