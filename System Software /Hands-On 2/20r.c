/*
============================================================================
Name : 20_r.c
Author : Somya Malgudi
Description : Write two programs so that both can communicate by 
	FIFO -Use one way communication. Read End of one way communication.
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
	int fd = open("myfifo",O_RDONLY);
	if(fd == -1) {
		perror("Couldn't open");
		exit(1);
	}

	char buf[100];
	int c = read(fd, buf, 100);
	printf("Message is %d character long and it says: %s\n", c, buf);
	return 0;
}