// 24. Write a program to create an orphan process.
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
int main(){
    int i;
    if(!fork()){
        sleep(20);
        printf("This is child process\n");
    }
    else{
        printf("This is parent process\n");
    }
}
//you can check using ps -eaf dfunct means that process is zombie