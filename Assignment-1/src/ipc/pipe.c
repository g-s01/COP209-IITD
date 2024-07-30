#include "common.h"
#include <stdlib.h>

void PipeAffirmation() {
    print("Pipe created");
}

struct Pipe {
    int fd[2];
};

void InitPipe() {
    struct Pipe IpcPipe;
    if (pipe(IpcPipe.fd) == -1) {
        perror("Failed to create pipe");
        exit(EXIT_FAILURE);
    }

    PipeAffirmation();
}