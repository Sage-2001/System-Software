/*
 ============================================================================
Name :  Q22.c
Author : Somya Malgudi
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: Sep 3, 2023
============================================================================	
*/

#include<stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{

    int fd = open("22",O_RDWR | O_CREAT , S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if(!fork()){
        char buf[100];
        printf("enter the string in child process\n");
        scanf("%s",buf);
        write(fd,&buf,sizeof(buf));
        printf("writtern by child process\n");
        close(fd);
        getchar();
    }
    else{
        char buf[100];
        sleep(8);
        printf("enter the string in parent process\n");
        scanf("%s",buf);
        write(fd,&buf,sizeof(buf));
        printf("writtern by parent process\n");
        close(fd);
    }
    return 0;
}