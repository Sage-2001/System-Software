/*
 ============================================================================
Name :  Q21.c
Author : Somya Malgudi
Description : Write a program, call fork and print the parent and child process id.
Date: Sep 1, 2023
============================================================================	
*/
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