// p1.cpp: a simple program to demonstrate calling fork of the process API in C++
#include <cstdio>
#include <cstdlib>
#include <unistd.h>

int main(int argc, char* argv[]) {
    printf("hello world (pid: %d)\n", (int) getpid());
    int rc = fork(); // create a new process by duplicating the current process, call once but returns twice
    printf("fork returned %d\n", rc);
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("hello, I am child (pid: %d)\n", (int) getpid());
    } else {
        printf("hello, I am parent of %d (pid: %d)\n", rc, (int) getpid());
    }
    return 0;
}