#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex, wrt;
int read_count = 0, data = 1; // Shared data and reader count

// Reader Function
void *reader(void *arg) {
    int id = *(int *)arg;

    sem_wait(&mutex);
    read_count++;
    if (read_count == 1) sem_wait(&wrt); // First reader locks the resource
    sem_post(&mutex);

    printf("Reader %d read data: %d\n", id, data);
    sleep(1);

    sem_wait(&mutex);
    read_count--;
    if (read_count == 0) sem_post(&wrt); // Last reader unlocks the resource
    sem_post(&mutex);

    return NULL;
}

// Writer Function
void *writer(void *arg) {
    int id = *(int *)arg;

    sem_wait(&wrt); // Writer locks the resource
    data++;  // Modify shared resource
    printf("Writer %d wrote data: %d\n", id, data);
    sleep(1);
    sem_post(&wrt); // Writer unlocks the resource

    return NULL;
}

// Main Function
int main() {
    pthread_t r[5], w[3];
    int i, id[5] = {1, 2, 3, 4, 5};

    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    // Create Writer Threads
    for (i = 0; i < 3; i++) {
        pthread_create(&w[i], NULL, writer, &id[i]);
    }

    // Create Reader Threads
    for (i = 0; i < 5; i++) {
        pthread_create(&r[i], NULL, reader, &id[i]);
    }

    // Join Writer Threads
    for (i = 0; i < 3; i++) {
        pthread_join(w[i], NULL);
    }

    // Join Reader Threads
    for (i = 0; i < 5; i++) {
        pthread_join(r[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}

