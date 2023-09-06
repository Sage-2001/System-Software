// 25. Write a program to create three child processes. The parent should wait for a particular child (use
// waitpid system call).

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>

int main(){
    int arr[3];
    pid_t x;
    
    if(!fork())
    {
        printf("Child process 1 with PID %d\n", getpid());
    }
    else
    {
        if (!fork())
        {
            x = getpid(); // Set x to the PID of the second child
            printf("Child process 2 with PID %d\n", getpid());
        }
        else
        {
            if (!fork())
            {
                printf("Child process 3 with PID %d\n", getpid());
            }
            else
            {
                printf("Parent process with PID %d\n", getpid());
            }
        }
    }

    int status;
    pid_t waited_pid;

    if (getpid() != x) { // Only the parent process should execute this
        waited_pid = waitpid(x, &status, 0); 
                
        if (waited_pid == -1) {
            perror("Waitpid failed\n");
            exit(1);
        }
                
        if (WIFEXITED(status)) {
            printf("Parent: Child with PID %d exited with status %d\n", waited_pid, WEXITSTATUS(status));
        }
    }
    
    return 0;
}
