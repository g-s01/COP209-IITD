#include <sys/fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "common.h"

void FifoAffirmation() {
    print("FIFO created");
}

struct Fifo {
    int fd;
};

void InitFifo() {
    struct Fifo IpcFifo;
    if (mkfifo("fifo", 0666) == -1) {
        perror("Failed to create FIFO");
        exit(EXIT_FAILURE);
    }

    IpcFifo.fd = open("fifo", O_RDWR);
    if (IpcFifo.fd == -1) {
        perror("Failed to open FIFO");
        exit(EXIT_FAILURE);
    }

    FifoAffirmation();
}