#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid;

    // Fork a child process
    child_pid = fork();

    if (child_pid < 0) {
        // Fork failed
        perror("Fork failed");
        return 1;
    } 
    else if (child_pid == 0) {
        // Child process
        printf("Child process: PID = %d\n", getpid());

        // Execute new program (ls -l)
        execl("/bin/ls", "ls", "-l", NULL);

        // If execl fails
        perror("execl failed");
        return 1;
    } 
    else {
        // Parent process
        printf("Parent process: PID = %d\n", getpid());

        // Wait for child to finish
        wait(NULL);

        printf("Child process finished.\n");
    }

    return 0;
}
