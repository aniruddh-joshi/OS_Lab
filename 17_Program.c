#include<stdio.h>
#include<stdlib.h>

struct rr {
    int pno, btime, sbtime, wtime, lst;
} p[10];

int main() {
    int pp = -1, ts, flag, count, ptm = 0, i, n, twt = 0, totttime = 0;

    printf("\n Round Robin Scheduling............");
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the time slice: ");
    scanf("%d", &ts);
    printf("Enter the burst time:\n");

    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &p[i].btime);
        p[i].wtime = p[i].lst = 0;
        p[i].pno = i + 1;
        p[i].sbtime = p[i].btime;
    }

    printf("Scheduling....\n");

    do {
        flag = 0;

        for (i = 0; i < n; i++) {
            count = p[i].btime;

            if (count > 0) {
                flag = -1;
                count = (count >= ts) ? ts : count;

                printf("\n Process %d from %d to %d", p[i].pno, ptm, ptm + count);
                ptm += count;
                p[i].btime -= count;

                if (pp != i) {
                    pp = i;
                    p[i].wtime += ptm - p[i].lst - count;
                    p[i].lst = ptm;
                }
            }
        }

        if (flag == 0)
            break;

    } while (flag);

    printf("\n\nProcess\tTurnaround Time\n");

    for (i = 0; i < n; i++) {
        twt += p[i].wtime;
        totttime += p[i].lst;
        printf("%d\t%d\n", p[i].pno, p[i].lst);
    }

    printf("\nTotal Waiting Time: %d", twt);
    printf("\nAverage Waiting Time: %f", (float)twt / n);
    printf("\nTotal Turnaround Time: %d", totttime);
    printf("\nAverage Turnaround Time: %f", (float)totttime / n);

    return 0;
}
