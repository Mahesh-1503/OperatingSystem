#include <stdio.h>

int main() {
    int n, i; // Number of processes and loop variable
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[100], bt[100], wt[100], tat[100]; // Arrival Time, Burst Time, Waiting Time, Turnaround Time
    int cur = 0; // Current time

    // Input arrival and burst times
    for (i = 0; i < n; i++) {
        printf("Enter AT and BT for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    int twt = 0, ttat = 0; // Total Waiting Time and Turnaround Time
    printf("\nP\tAT\tBT\tWT\tTAT\n");

    for (i = 0; i < n; i++) {
        if (cur < at[i]) cur = at[i]; // Wait if process arrives later
        
        wt[i] = cur - at[i];
        tat[i] = wt[i] + bt[i];

        twt += wt[i];
        ttat += tat[i];

        printf("%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i]);

        cur += bt[i];
    }

    // Average waiting and turnaround times
    printf("\nAvg WT: %.2f\n", (float)twt / n);
    printf("Avg TAT: %.2f\n", (float)ttat / n);

    return 0;
}

