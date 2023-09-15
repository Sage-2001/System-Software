// 15. Write a simple program to send some data from parent to the child process.

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
int main(){
    int fd[2];
    if (pipe(fd) < 0)
    {
        perror("Pipe error");
    }
    
    char g[100];

    if(!fork()){
        char f[100];
        close(fd[1]);
        read(fd[0],f,sizeof(g));
        printf("the child has the data: %s ",f);
    }
    else{
        close(fd[0]);
        printf("enter the string\n");
        scanf("%[^\n]%*c", g); 
        write(fd[1],g,sizeof(g));
    }

    return 0; 
}