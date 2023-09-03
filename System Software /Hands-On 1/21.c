// 21. Write a program, call fork and print the parent and child process id.
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    if(!fork()){
        printf("Child id is %d\n",getppid());
    }
    else{
        printf("Parent id is %d\n",getpid());
    }
    return 0;
}