/*Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls*/

#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<fcntl.h>

int main(){

    while (1)
    {
        char buf;
        int fdr = read(0,&buf,1);

        if(fdr==0) break;
        int fdw = write(1,&buf,1);
    }

    return 0;
}
