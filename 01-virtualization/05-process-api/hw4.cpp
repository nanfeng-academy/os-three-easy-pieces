// hw4.cpp: homework 4
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
        
        if (fork() == 0) {
            // Grandchild process
            std::cout << "Grandchild process: PID = " << getpid() << std::endl;
            execl("/bin/pwd", "pwd", NULL); // Execute 'pwd' command

            perror("execl failed"); // If execl returns, it must have failed
            return 1; // Exit with error code
        } else {
            // Child process continues
            wait(NULL); // Wait for the grandchild process to finish
        }

        execl("/bin/ls", "ls", "-l", NULL); // Execute 'ls -l' command

        perror("execl failed"); // If execl returns, it must have failed
        return 1; // Exit with error code
    } else {
        // Parent process
        std::cout << "Parent process: PID = " << getpid() << ", waiting for child..." << std::endl;
        wait(NULL); // Wait for the child process to finish
        std::cout << "Child process has finished. Parent exiting." << std::endl;
    }
    return 0; // Exit parent process
    
}   