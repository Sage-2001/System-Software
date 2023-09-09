/*
 ============================================================================
Name :  Q23.c
Author : Somya Malgudi
Description : Write a program to create a Zombie state of the running program.
Date: Sep 3, 2023
============================================================================	
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
int main(){
    int i;
    if(!fork()){
        printf("This is child process\n");
        exit(0);
    }
    else{
        sleep(20);
        printf("This is parent process\n");
    }
}
//you can check using ps -eaf dfunct means that process is zombie