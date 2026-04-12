// threads.cpp: a simple example of using multi-threads in C++
#include <cstdio> // Standard Input and Output (C++ header)
#include <cstdlib> // Standard Library (C++ header)
#include <pthread.h> // POSIX threads library
#include "common.h"

volatile int counter = 0; // a shared variable that will be accessed by multiple threads
int loops;

void *worker(void *arg) {
    for (int i = 0; i < loops; i++) {
        counter++; // increment the shared variable
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number of loops>\n", argv[0]);
        exit(1);
    }
    loops = atoi(argv[1]); // convert the command-line argument to an integer
    pthread_t p1, p2;
    printf("Initial value of counter: %d\n", counter); // print the initial value of the counter

    pthread_create(&p1, NULL, worker, NULL); // create the first thread that runs the worker function
    pthread_create(&p2, NULL, worker, NULL); // create the second thread
    pthread_join(p1, NULL); // wait for the first thread to finish
    pthread_join(p2, NULL); // wait for the second thread to finish
    printf("Final counter value: %d\n", counter); // print the final value of the counter
    return 0;
}