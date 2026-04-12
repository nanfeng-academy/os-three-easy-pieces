// io.cpp: a program to demonstrate input and output in C++
#include <cstdio> // for printf and scanf
#include <unistd.h> // Unix Standard---for getpid
#include <assert.h> // for assert
#include <fcntl.h> // File Control---for open
#include <sys/types.h> // System Data Types---for open

int main(int argc, char *argv[]) {
    int fd = open("/tmp/file", O_WRONLY|O_CREAT|O_TRUNC, S_IRWXU); // file descriptor for writing to a file, create it if it doesn't exist, and truncate it if it does
    assert(fd != -1); // check if the file was opened successfully
    int rc = write(fd, "Hello, World!\n", 14); // write a string to the file
    assert(rc == 14); // check if the write was successful
    close(fd); // close the file descriptor
    return 0;
}