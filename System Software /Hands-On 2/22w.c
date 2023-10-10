/*
============================================================================
Name : 22w.c
Author : Somya Malgudi
Description : Write a program to wait for data to be written into 
	FIFO within 10 seconds, use select system call with FIFO.
============================================================================
*/
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>         
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
	int fd = open("myfifo",O_WRONLY);
	if(fd == -1) {
		perror("Couldn't open");
		exit(1);
	}

	char buf[100];
	scanf("%[^\n]%*c", buf); 
	printf("Write is going to send data to read file\n");
	write(fd, &buf, sizeof(buf));
	return 0;
}