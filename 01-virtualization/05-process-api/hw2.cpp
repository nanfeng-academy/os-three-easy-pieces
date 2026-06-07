// hm2.cpp: homework 2
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    // open a file before fork
    // O_CREAT: create the file if it does not exist
    // O_RDWR: open the file for reading and writing
    // O_WRONLY: open the file for writing only
    // O_TRUNC: truncate the file to zero length if it already exists
    // 0644: file permissions (owner can read/write, group can read, others can read)
    int fd = open("hw2.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd < 0) {
        fprintf(stderr, "open failed\n");
        exit(1);
    }

    printf("file opened successfully, file descriptor (fd) = %d\n", fd);
    printf("Forking a new process...\n");

    pid_t rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child process
        printf("I'm the child process (pid: %d)\n", getpid());
        // write to the file in the child process
        const char* msg = "Hello from the child process!\n";
        write(fd, msg, strlen(msg));
    } else {
        // parent process
        printf("I'm the parent process (pid: %d)\n", getpid());
        // write to the file in the parent process
        const char* msg = "Hello from the parent process!\n";
        write(fd, msg, strlen(msg));
        close(fd); // close the file descriptor in the parent process
    }

    // fd is shared between the parent and child processes, so both can write to the same file
    // close(fd) will make reference count of the file descriptor decrease by 1, 
    // but the file will not be closed until both processes close it.
    // if reference count is 0, the file will be closed and the file descriptor will be released.

    return 0;
}