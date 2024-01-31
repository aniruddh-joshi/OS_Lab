#include<stdio.h>

#define MAX_PARTITIONS 5

// Function to allocate memory using First Fit
int firstFit(int partition[], int m, int processSize) {
    for (int i = 0; i < m; i++) {
        if (partition[i] >= processSize) {
            partition[i] -= processSize;
            return i; // Return the index of allocated partition
        }
    }
    return -1; // If no suitable partition is found
}

// Function to display partition details
void displayPartitions(int partition[], int m) {
    printf("Partitions: ");
    for (int i = 0; i < m; i++) {
        printf("%d ", partition[i]);
    }
    printf("\n");
}

int main() {
    int partitions[MAX_PARTITIONS];
    int m, n; // m = number of partitions, n = number of processes

    printf("Enter the number of partitions: ");
    scanf("%d", &m);

    printf("Enter the size of each partition:\n");
    for (int i = 0; i < m; i++) {
        printf("Partition %d: ", i + 1);
        scanf("%d", &partitions[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the size of each process:\n");
    for (int i = 0; i < n; i++) {
        int processSize;
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize);

        int allocatedPartitionIndex = firstFit(partitions, m, processSize);

        if (allocatedPartitionIndex != -1) {
            printf("Process %d allocated to Partition %d\n", i + 1, allocatedPartitionIndex + 1);
        } else {
            printf("Process %d cannot be allocated\n", i + 1);
        }

        displayPartitions(partitions, m);
    }

    return 0;
}
