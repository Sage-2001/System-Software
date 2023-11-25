/*
 ============================================================================
Name :  Q15.c
Author : Somya Malgudi
Description : Write a program to display the environmental variable of the user (use environ).
Date: Aug 23, 2023
============================================================================	
*/

#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<fcntl.h>

int main(int argc, char* argv[], char* envp[]){
	
	for(int i = 0; envp[i] != NULL; i++){
		printf("%s\n", envp[i]);
	}
	return 0;
}