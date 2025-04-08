#include <stdio.h>

void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n], i, j;  
    for (i = 0; i < n; i++) allocation[i] = -1;  

    for (i = 0; i < n; i++) {
        int worstIdx = -1;
        for (j = 0; j < m; j++) 
            if (blockSize[j] >= processSize[i] && (worstIdx == -1 || blockSize[j] > blockSize[worstIdx]))
                worstIdx = j;

        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        }
    }

    printf("Process\tSize\tBlock\n");
    for (i = 0; i < n; i++) 
        printf("%d\t%d\t%s\n", i + 1, processSize[i], allocation[i] != -1 ? "Allocated" : "Not Allocated");
}

int main() {
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    worstFit(blockSize, m, processSize, n);
    return 0;
}

