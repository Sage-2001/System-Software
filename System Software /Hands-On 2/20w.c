/*
============================================================================
Name : 20_w.c
Author : Somya Malgudi
Description : Write two programs so that both can communicate by FIFO 
	-Use one way communication. Write end of one way communication
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