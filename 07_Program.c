#include<stdio.h>
#include<conio.h>

int max[100][100];
int alloc[100][100];
int need[100][100];
int avail[100];
int n, r;

void input();
void show();
void calculate();

int main() {
    printf("********** Banker's Algorithm ************\n");
    input();
    show();
    calculate();
    getch();
    return 0;
}

void input() {
    int i, j;
    printf("Enter the number of Processes: ");
    scanf("%d", &n);
    printf("Enter the number of resource instances: ");
    scanf("%d", &r);

    printf("Enter the Max Matrix\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the Allocation Matrix\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter the available Resources\n");
    for (j = 0; j < r; j++) {
        scanf("%d", &avail[j]);
    }
}

void show() {
    int i, j;
    printf("\nProcess\tAllocation\tMax\tAvailable\n");

    for (i = 0; i < n; i++) {
        printf("P%d\t", i + 1);

        for (j = 0; j < r; j++) {
            printf("%d ", alloc[i][j]);
        }

        printf("\t");

        for (j = 0; j < r; j++) {
            printf("%d ", max[i][j]);
        }

        printf("\t");

        if (i == 0) {
            for (j = 0; j < r; j++)
                printf("%d ", avail[j]);
        }

        printf("\n");
    }
}

void calculate() {
    int finish[100], c1 = 0;
    int safe[100];
    int i, j;

    for (i = 0; i < n; i++) {
        finish[i] = 0;
    }

    while (c1 < n) {
        int flag = 0;

        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int c = 0;

                for (j = 0; j < r; j++) {
                    if (need[i][j] <= avail[j]) {
                        c++;

                        if (c == r) {
                            for (int k = 0; k < r; k++) {
                                avail[k] += alloc[i][j];
                            }

                            finish[i] = 1;
                            safe[c1] = i;
                            c1++;
                            flag = 1;
                        }
                    }
                }
            }
        }

        if (!flag) {
            printf("\nSystem is in unsafe state\n");
            return;
        }
    }

    printf("\nThe system is in safe state\nSafe Sequence: ");
    
    for (i = 0; i < n - 1; i++) {
        printf("P%d -> ", safe[i]);
    }
    printf("P%d\n", safe[n - 1]);
}
