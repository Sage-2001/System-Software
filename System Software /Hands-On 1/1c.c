#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
    const char *fifopath = "./fifopipe";
    int  x= mkfifo(fifopath,0640);
    return 0;
}