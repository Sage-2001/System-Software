/*
 ============================================================================
Name :  Q1c.c
Author : Somya Malgudi
Description : Create the following types of a files using system call   c. FIFO (mkfifo Library Function or mknod system call)
Date: Aug 4, 2023
============================================================================	
*/
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
    const char *fifopath = "./fifopipe";
    int  x= mkfifo(fifopath,0640);
    return 0;
}