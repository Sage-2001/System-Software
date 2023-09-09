/*
 ============================================================================
Name :  Q1a.c
Author : Somya Malgudi
Description : Create the following types of a files using system call a. soft link (symlink system call)
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
    const char *softlinkpath = "./SoftLink";

    int x = symlink(source,softlinkpath);
    return 0;
}