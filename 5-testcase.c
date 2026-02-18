#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        close(fd[1]);   // Close write end
        char buf[50];
        read(fd[0], buf, sizeof(buf));
        printf("Child received: %s\n", buf);
        close(fd[0]);
    } else {
        close(fd[0]);   // Close read end
        write(fd[1], "Hello Child", 12);
        close(fd[1]);
    }
    return 0;
}

fifo

Sender.c
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    mkfifo("myfifo", 0666);
    int fd = open("myfifo", O_WRONLY);
    write(fd, "Hello FIFO", 11);
    close(fd);
}
🔹 Receiver.c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char buf[50];
    int fd = open("myfifo", O_RDONLY);
    read(fd, buf, sizeof(buf));
    printf("Received: %s\n", buf);
    close(fd);
}
