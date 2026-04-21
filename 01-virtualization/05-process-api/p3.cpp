// p3.cpp: calling fork(), wait(), and exec() system calls
#include <cstdio> // for printf()
#include <cstdlib> // for exit()
#include <unistd.h> // for fork(), exec(), and getpid()
#include <string>
#include <sys/wait.h> // for wait()

int main(int argc, char* argv[]) {
    printf("hello world from process %d\n", getpid());
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process
        printf("hello world, I'm child (pid %d)\n", getpid());
        char* myargs[3];
        myargs[0] = strdup("wc"); // program: "wc" (word count)
        myargs[1] = strdup("p3.cpp"); // argument: file to count
        myargs[2] = NULL;
        execvp(myargs[0], myargs); // run wc on p3.cpp
        printf("this shouldn't print out");
    } else {
        // parent process
        int rc_wait = wait(NULL); // wait for the child process to finish
        printf("hellow world, I'm parent of %d (rc_wait: %d) (pid: %d)\n", rc, rc_wait, getpid());
    }

    return 0;
}   