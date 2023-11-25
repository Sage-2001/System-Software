/*
============================================================================
Name : 16.c
Author : Somya Malgudi
Description : Write a program to send and receive data from parent to 
	child vice versa. Use two way communication.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
int main(){
    int fd[2];
    int fd2[2];

    if (pipe(fd) < 0)
    {
        perror("Pipe error");
    }

    if (pipe(fd2) < 0)
    {
        perror("Pipe error");
    }
    
    char g[100],f[100],b[100],d[100];

    if(!fork()){
        close(fd[1]);
        read(fd[0],f,sizeof(g));
        printf("the child has the data: %s \n",f);

        close(fd2[0]);
        printf("enter the string to be sended to parent\n");
        scanf("%[^\n]%*c", b); 
        write(fd2[1],b,sizeof(b));
    }
    else{
        close(fd[0]);
        printf("enter the string to be sended to child\n");
        scanf("%[^\n]%*c", g); 
        write(fd[1],g,sizeof(g));

        close(fd2[1]);
        read(fd2[0],f,sizeof(b));
        printf("the child has the data: %s \n",f);
    }

    return 0; 
}