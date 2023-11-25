/*
 ============================================================================
Name :  Q3.c
Author : Somya Malgudi
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: Aug 4, 2023
============================================================================	
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
    mode_t mode = S_IRUSR| S_IWUSR| S_IRGRP| S_IROTH;
    int fd = creat("create_file",mode);

    printf("File created with descriptor: %d\n", fd);
    return 0;
};