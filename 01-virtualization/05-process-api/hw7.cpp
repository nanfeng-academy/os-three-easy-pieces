// hw7.cpp: homework 7
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    
    if (pid < 0) {
        std::cerr << "Fork failed!" << std::endl;
        return 1; // Exit with error code
    } else if (pid == 0) {
        // Child process
        std::cout << "Child process: PID = " << getpid() << std::endl;
        
        close(STDOUT_FILENO); // Close standard output in the child process

        printf("This will not be printed to the console because stdout is closed.\n");
        fflush(stdout); // Flush the output buffer to ensure the message is sent to the console (but it won't be printed because stdout is closed)
        
        std::cout << "C++ stream output will also not be printed to the console." << std::endl;
    } else {
        // Parent process
        std::cout << "Parent process: PID = " << getpid() << std::endl;
        sleep(2); // Simulate some work in the parent process

        std::cout << "Parent process still works" << std::endl;
    }
    return 0; // Exit parent process
}