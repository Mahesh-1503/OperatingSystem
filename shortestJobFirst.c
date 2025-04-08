#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[100], bt[100], wt[100], tat[100], temp_bt[100];
    int total_wt = 0, total_tat = 0;

    // Input Arrival and Burst Times
    for (i = 0; i < n; i++) {
        printf("Enter AT and BT for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        temp_bt[i] = bt[i]; // Copy for sorting
    }

    // Sorting processes by Burst Time (Shortest Job First)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                // Swap Burst Time
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap Arrival Time
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
            }
        }
    }

    // Calculate Waiting Time and Turnaround Time
    wt[0] = 0; // First process has 0 waiting time
    tat[0] = bt[0];

    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
    }

    // Display Results
    printf("\nP\tAT\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage WT: %.2f\n", (float)total_wt / n);
    printf("Average TAT: %.2f\n", (float)total_tat / n);

    return 0;
}

