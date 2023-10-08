/*
============================================================================
Name : 21a.c
Author : Somya Malgudi
Description : Write two programs so that both can communicate by 
	FIFO -Use two way communications.
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
    int fd2 = open("myfifo2",O_RDONLY);
	if(fd == -1 || fd2 == -1) {
		perror("Couldn't open");
		exit(1);
	}

	char buf[100] = "Hello how are you";
    write(fd,&buf,sizeof(buf));
	int c = read(fd2, &buf, 100);

	printf("Message is %d character long and it says: %s\n", c, buf);
	return 0;
}