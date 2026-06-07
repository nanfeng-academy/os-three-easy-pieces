// hw5: homework 5
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
        pid_t ret = wait(&status); // Wait for the child process to finish
        // wait(&status) is equivalent to waitpid(-1, &status, 0), which waits for any child process to finish
        
        std::cout << "Paren: wait returned: " << ret << std::endl;

        if (WIFEXITED(status)) {
            std::cout << "Child exited with status: " << WEXITSTATUS(status) << std::endl;
        } else if (WIFSIGNALED(status)) {
            std::cout << "Child was terminated by signal: " << WTERMSIG(status) << std::endl;
        } else {
            std::cout << "Child process ended with unknown status." << std::endl;
        }
        std::cout << "Child process has finished. Parent exiting." << std::endl;
    }
    return 0; // Exit parent process    
}