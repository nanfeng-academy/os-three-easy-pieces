// hw8.cpp: homework 8
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[2]; // fd[0] for reading, fd[1] for writing
    pipe(fd); // Create a pipe

    pid_t p1 = fork(); // First child process
    
    if (p1 == 0) {
        // First child process (Producer)
        close(fd[0]); // Close the read end of the pipe
        
        const char* message = "Hello from the first child process!";
        write(fd[1], message, strlen(message) + 1); // Write message to the pipe

        close(fd[1]); // Close the write end of the pipe
        return 0; // Exit first child process
    }

    pid_t p2 = fork(); // Second child process

    if (p2 == 0) {
        // Second child process (Consumer)
        close(fd[1]); // Close the write end of the pipe
        
        char buffer[100];
        read(fd[0], buffer, sizeof(buffer)); // Read message from the pipe
        std::cout << "Second child process received message: " << buffer << std::endl;

        close(fd[0]); // Close the read end of the pipe
        return 0; // Exit second child process
    }

    close(fd[0]); // Close the read end of the pipe in the parent process
    close(fd[1]); // Close the write end of the pipe in the parent process
    wait(NULL); // Wait for the first child process to finish
    wait(NULL); // Wait for the second child process to finish
    std::cout << "Both child processes have finished. Parent exiting." << std::endl;
    return 0; // Exit parent process
}