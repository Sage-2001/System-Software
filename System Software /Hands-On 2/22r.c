/*
============================================================================
Name : 22_r.c
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
    int fd = open("myfifo",O_NONBLOCK | O_RDONLY);
    if (fd == -1)
    {
        perror("Couldn't open");
        exit(1);
    }
    fd_set readfd;
    FD_ZERO(&readfd);
    FD_SET(fd,&readfd);

    struct timeval time;
    time.tv_sec = 10;
    time.tv_usec = 0;
    char buf[100];

    int stat = select(fd+1,&readfd,NULL,NULL,&time);

    if (stat > 0)
    {
        read(fd,buf,100);
        printf("Message says: %s\n",buf);
    }
    else if(stat == 0){
        printf("No data received\n");
    }
    else{
        printf("Some Error occurred in select\n");
    }
    return 0;
    
}
