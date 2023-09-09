/*
 ============================================================================
Name :  Q5.c
Author : Somya Malgudi
Description : Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
Date: Aug 4, 2023
============================================================================	
*/

#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<fcntl.h>

int main(){
    int fd , count = 0;
    while (1)
    {
        if(count<5){
            fd = open("create_file", O_RDWR);
            count++;
            if (fd>=0)
            {
                printf("File opened with descriptor: %d\n", fd);
            }
            else{
                printf("File opening failed\n");
            }
        }
    }
    return 0;
}

//not you have to run this in background
// use ls-l to see the table