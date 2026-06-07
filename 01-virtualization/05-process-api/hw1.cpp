// hw1.cpp: homework 1
#include <cstdio>
#include <cstdlib>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int x = 100;
    printf("before fork: x = %d\n", x);
    int rc = fork();
    printf("rc = %d\n", rc);

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        x += 100;
        printf("hello world, I'm child (pid %d) and x = %d\n", getpid(), x);
    } else {
        // parent process
        x -= 100;
        printf("hello world, I'm parent of %d (pid: %d) and x = %d\n", rc, getpid(), x);
    }

    return 0;

}
