// 21. Write a program, call fork and print the parent and child process id.
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    if(!fork()){
        printf("Parent id is %d\n",getpid());
    }
    else{
        printf("Child id is %d\n",getppid());
    }
    return 0;
}