/*
 ============================================================================
Name :  Q20.c
Author : Somya Malgudi
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: Sep 1, 2023
============================================================================	
*/
#include<stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
int main(){
    printf("The priority of current process is: %d\n", getpriority(PRIO_PROCESS,0));
    nice(-4);
    setpriority(PRIO_PROCESS,0,5);
    printf("The priority of current process is: %d\n", getpriority(PRIO_PROCESS,0));
    return 0;
}