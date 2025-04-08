#include <stdio.h>

// Structure to hold process details
struct Process {
    int id;
    int burst_time;
    int priority;
};

// Function to sort processes based on priority (higher priority first)
void sortByPriority(struct Process proc[], int n) {
    int i, j;  // Declare variables outside loops
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (proc[i].priority < proc[j].priority) { 
                // Swap if priority of proc[j] is higher
                struct Process temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}

// Function to calculate waiting and turnaround times
void calculateTimes(struct Process proc[], int n) {
    int wait_time[n], turn_time[n];
    wait_time[0] = 0;  // First process has 0 waiting time

    int i;
    for (i = 1; i < n; i++) {
        wait_time[i] = wait_time[i - 1] + proc[i - 1].burst_time;
    }

    for (i = 0; i < n; i++) {
        turn_time[i] = wait_time[i] + proc[i].burst_time;
    }

    // Display results
    printf("\nProcess\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].id, proc[i].priority, proc[i].burst_time, wait_time[i], turn_time[i]);
    }
}

int main() {
    int n, i;  // Declare 'i' outside loops

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];

    // Taking input for processes
    for (i = 0; i < n; i++) {
        printf("Enter Burst Time and Priority for Process P%d: ", i + 1);
        scanf("%d %d", &proc[i].burst_time, &proc[i].priority);
        proc[i].id = i + 1;
    }

    // Sort processes by priority
    sortByPriority(proc, n);

    // Calculate and display times
    calculateTimes(proc, n);

    return 0;
}

