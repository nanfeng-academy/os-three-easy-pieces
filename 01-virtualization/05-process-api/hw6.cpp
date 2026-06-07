// hw6.cpp: homework 6
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
        
        sleep(2); // Simulate some work in the child process
        std::cout << "Child process is exiting." << std::endl;

    } else {
        // Parent process
        std::cout << "Parent process: PID = " << getpid() << ", waiting for child..." << std::endl;
        
        int status;
        pid_t ret = waitpid(pid, &status, 0); // wait for the specific child process to finish
        // waitpid(pid, &status, 0) waits for the child process with the specified PID to finish
        // useful when there are multiple child processes and you want to wait for a specific one
        
        std::cout << "waitpid returned: " << ret << std::endl;

        if (WIFEXITED(status)) {
            std::cout << "Child exited with status: " << WEXITSTATUS(status) << std::endl;
        } 
        
        std::cout << "Child process has finished. Parent exiting." << std::endl;
    }
    return 0; // Exit parent process
}