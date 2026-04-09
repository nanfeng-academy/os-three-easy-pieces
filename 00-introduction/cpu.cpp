// cpu.cpp: a simple program that uses the CPU and prints a string
// Compile: gcc -std=c++17 -o cpu cpu.cpp
// Example usage: ./cpu hello
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>
#include "common.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: cpu <string>\n");
        return 1;
    }
    char *str = argv[1];
    while (1) {
        Spin(1);
        printf("%s\n", str);
    }
    return 0;
}
