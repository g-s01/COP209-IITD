#include <sys/ipc.h>
#include <sys/msg.h> 
#include <stdlib.h>
#include "common.h"

void MessageQueueAffirmation() {
    print("Message Queue created");
}

struct MessageQueue {
    int msqid;
};

void InitMessageQueue() {
    struct MessageQueue IpcMessageQueue;
    IpcMessageQueue.msqid = msgget(IPC_PRIVATE, IPC_CREAT | 0666);
    if (IpcMessageQueue.msqid == -1) {
        perror("Failed to create message queue");
        exit(EXIT_FAILURE);
    }

    MessageQueueAffirmation();
}