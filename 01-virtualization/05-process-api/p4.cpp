// p4: process API with redirection of standard input and output
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child: redirect standard output to a file
        close(STDOUT_FILENO); // close standard output
        open("./p4.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR); // open file for writing

        // now exec "wc"
        char* myargs[3];
        myargs[0] = strdup("wc");
        myargs[1] = strdup("p4.cpp");
        myargs[2] = NULL;
        execvp(myargs[0], myargs);
        printf("this shouldn't print out");
    } else {
        // parent process
        int rc_wait = wait(NULL);
        printf("hello world, I'm parent of %d (rc_wait: %d) (pid: %d)\n", rc, rc_wait, getpid());
    }
    return 0;

}