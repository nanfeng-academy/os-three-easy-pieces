// mem.cpp: a program that accesses memory
#include <unistd.h> // Unix Standard
#include <stdio.h> // Standard Input and Output (C header)
#include <stdlib.h> // Standard Library (C header)
#include "common.h"

int main(int argc, char *argv[]) {
    int *p = (int *)malloc(sizeof(int)); // allocate memory for an integer
    assert(p != NULL);  // check that malloc succeeded
    // getpid() returns the process ID of the calling process, 
    //      which is useful for distinguishing output from different processes when running multiple instances of this program.
    printf("(%d) address pointed to by p: %p\n", getpid(), p); // print the address pointed to by p
    *p = 0; // initialize the integer pointed to by p to 0
    while (1) {
        Spin(1);
        *p = *p + 1;
        printf("(%d) p: %d\n", getpid(), *p);
    }
    return 0;
}