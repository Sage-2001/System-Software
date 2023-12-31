/*
 ============================================================================
Name :  Q19.c
Author : Somya Malgudi
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: Sep 1, 2023
============================================================================	
*/
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int main(){
    clock_t t;
    t = clock();
    getpid();
    t = clock() - t;
    printf("time take in seconds to get getpid system calls is: %ld \n", t);
    return 0;
}