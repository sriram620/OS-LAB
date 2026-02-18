#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = fork();

    if (pid < 0) {
        printf("Fork Failed\n");
    }
    else if (pid == 0) {
        printf("Child Process\n");
    }
    else {
        printf("Parent Process\n");
    }
    return 0;
}
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Process ID: %d\n", getpid());
    return 0;
}
