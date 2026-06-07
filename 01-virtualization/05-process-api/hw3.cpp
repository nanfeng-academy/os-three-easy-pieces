// hw3.cpp: homework 3
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // will need some form of synchronization between the parent and child processes
    // for example, wait(), piples, shared memory, etc.

    int p[2]; // p[0]: read end, p[1]: write end

    // create a pipe before forking
    if (pipe(p) < 0) {
        perror("pipe");
        exit(1);
    }

    pid_t rc = fork();
    // after fork, both the parent and child processes will have access to the pipe: p[0] and p[1]

    if (rc < 0) {
        perror("fork");
        exit(1);
    } else if (rc == 0) { // child process
        close(p[0]); // close the read end, the child will only write to the pipe
        
        printf("hello\n");
        fflush(stdout); // ensure "hello" is printed before the child waits for input

        write(p[1], "ready", 5); // signal the parent that the child is ready
        close(p[1]); // close the write end of the pipe 
    } else { // parent process
        close(p[1]); // close the write end of the pipe, the parent will only read from the pipe
        char buf;
        read(p[0], &buf, 1); // wait for the child to signal that it's ready
        printf("goodbye\n");
        close(p[0]); // close the read end of the pipe
    }

    return 0;

}