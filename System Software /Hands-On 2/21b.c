/*
============================================================================
Name : 21b.c
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
	int fd = open("myfifo",O_RDONLY);
    int fd2 = open("myfifo2",O_WRONLY);
	if(fd == -1 || fd2 == -1) {
		perror("Couldn't open");
		exit(1);
	}

	char buf[100];
    int c = read(fd,&buf,sizeof(buf));
    printf("Message is %d character long and it says: %s\n", c, buf);
    char buf2[100] = "I am fine thank you";
	write(fd2, &buf2, 100);
	return 0;
}