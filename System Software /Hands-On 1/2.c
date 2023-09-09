/*
 ============================================================================
Name :  Q2.c
Author : Somya Malgudi
Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory.
Date: Aug 4, 2023
============================================================================	
*/

#include<unistd.h>
#include<stdio.h>
int main(){
    while (1);
    return 0;
}

//just run this in background after compiling do ./a.out&
//then go to the proc directory and do ls go to the directory of this program and that is it