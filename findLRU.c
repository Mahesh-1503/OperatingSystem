#include <stdio.h>

int findLRU(int time[], int capacity) {
    int i, pos = 0;
    for (i = 1; i < capacity; i++)
        if (time[i] < time[pos]) pos = i;
    return pos;
}

int lruPageReplacement(int pages[], int n, int capacity) {
    int frame[capacity], time[capacity], i, j, counter = 0, pageFaults = 0;
    for (i = 0; i < capacity; i++) frame[i] = -1;

    for (i = 0; i < n; i++) {
        int found = 0;
        for (j = 0; j < capacity; j++) 
            if (frame[j] == pages[i]) { found = 1; time[j] = counter++; break; }

        if (!found) {
            int pos = findLRU(time, capacity);
            frame[pos] = pages[i];
            time[pos] = counter++;
            pageFaults++;
        }
    }
    return pageFaults;
}

int main() {
    int pages[] = {0, 2, 1, 6, 4, 0, 1, 0, 3, 1, 2, 1};
    printf("Page Faults: %d\n", lruPageReplacement(pages, sizeof(pages) / sizeof(pages[0]), 3));
    return 0;
}

