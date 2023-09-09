/*
 ============================================================================
Name :  Q1b.c
Author : Somya Malgudi
Description : Create the following types of a files using system call  b. hard link (link system call)
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
    
    const char *source = "./1";
    const char *HardLInk = "./HardLink";
    int x = link(source,HardLInk);
    return 0;
}