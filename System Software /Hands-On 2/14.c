// 14. Write a simple program to create a pipe, write to the pipe, read from pipe and display on
// the monitor.

#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main(){
    int fd[2];
    if (pipe(fd) < 0)
    {
        perror("Pipe error");
    }
    
    char g[100];
    printf("enter the string\n");
    scanf("%[^\n]%*c", g); 

    write(fd[1],g,sizeof(g));

    char f[100];
    read(fd[0],f,sizeof(g));

    printf("%s ",f);
    return 0; 
}