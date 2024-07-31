#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "ipc/pipe.c"
#include "ipc/fifo.c"
#include "ipc/message-queue.c"
#include "common.h"

void* IpcPipe() {
    InitPipe();
    return NULL;
}

void* IpcFIFO() {
    InitFifo();
    return NULL;
}

void* IpcMessageQueue() {
    InitMessageQueue();
    return NULL;
}

int main() {
    pthread_t pipeThread, fifoThread, messageQueueThread;

    /*
        Create threads for different IPC mechanisms
    */ 
    if (pthread_create(&pipeThread, NULL, IpcPipe, NULL) != 0) {
        perror("Failed to create pipeThread");
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&fifoThread, NULL, IpcFIFO, NULL) != 0) {
        perror("Failed to create fifoThread");
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&messageQueueThread, NULL, IpcMessageQueue, NULL) != 0) {
        perror("Failed to create messageQueueThread");
        exit(EXIT_FAILURE);
    }

    /*
        Wait for all threads to finish
    */ 
    pthread_join(pipeThread, NULL);
    pthread_join(fifoThread, NULL);
    pthread_join(messageQueueThread, NULL);

    return 0;
}