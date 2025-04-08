#include <stdio.h>

int fifoPageReplacement(int pages[], int n, int capacity) {
    int frame[capacity], i, j, index = 0, pageFaults = 0;
    for (i = 0; i < capacity; i++) frame[i] = -1;  

    for (i = 0; i < n; i++) {
        int found = 0;
        for (j = 0; j < capacity; j++) 
            if (frame[j] == pages[i]) { found = 1; break; }  

        if (!found) {
            frame[index] = pages[i];
            index = (index + 1) % capacity;
            pageFaults++;
        }
    }
    return pageFaults;
}

int main() {
    int pages[] = {0, 2, 1, 6, 4, 0, 1, 0, 3, 1, 2, 1};
    printf("Page Faults: %d\n", fifoPageReplacement(pages, sizeof(pages) / sizeof(pages[0]), 3));
    return 0;
}

