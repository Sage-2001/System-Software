/*
============================================================================
Name : 19.c
Author : Somya Malgudi
Description : Create a FIFO file by
	a. mknod command
	b. mkfifo command
	c. use strace command to find out, which command 
	   (mknod or mkfifo) is better.
	c. mknod system call
	d. mkfifo library function
============================================================================
*/

#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdlib.h>

int main(){
    int stat = mkfifo("mkfifo",0777);
    if (stat == -1)
    {
        perror("Fifo creation failed");
        exit(1);
    }
    else
    {
        printf("Fifo successfull\n");
    }
    
    stat = mknod("mknod", S_IFIFO, 0);
	if(stat == -1) {
        perror("FiFO creation using mknod failed\n");
        exit(1);
    } else {
        printf("mknod FIFO Success!!!");
    }

}