#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int deadline;
    int profit;
} Job;

// Comparator: sort by profit descending
int compareJobs(const void *a, const void *b) {
    return ((Job *)b)->profit - ((Job *)a)->profit;
}

// Main job sequencing function
void jobSequencing(int deadline[], int profit[], int n, int *jobCount, int *totalProfit) {
    Job jobs[n];
    int maxDeadline = 0;

    // Fill job structs and find max deadline
    for (int i = 0; i < n; i++) {
        jobs[i].deadline = deadline[i];
        jobs[i].profit = profit[i];
        if (deadline[i] > maxDeadline)
            maxDeadline = deadline[i];
    }

    // Sort jobs by profit descending
    qsort(jobs, n, sizeof(Job), compareJobs);

    // Slots to track used deadlines (1-based index)
    int slots[maxDeadline + 1];
    for (int i = 0; i <= maxDeadline; i++)
        slots[i] = -1;

    *jobCount = 0;
    *totalProfit = 0;

    // Schedule jobs greedily
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j >= 1; j--) {
            if (slots[j] == -1) {
                slots[j] = jobs[i].profit;
                *jobCount += 1;
                *totalProfit += jobs[i].profit;
                break;
            }
        }
    }
}

int main() {
    int deadline[] = {2, 1, 2, 1, 3};
    int profit[] = {100, 19, 27, 25, 15};
    int n = sizeof(deadline) / sizeof(deadline[0]);

    int jobCount = 0, totalProfit = 0;

    jobSequencing(deadline, profit, n, &jobCount, &totalProfit);

    printf("Jobs Scheduled: %d\n", jobCount);
    printf("Total Profit: %d\n", totalProfit);

    return 0;
}
