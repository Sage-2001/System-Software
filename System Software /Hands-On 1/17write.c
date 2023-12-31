/*
 ============================================================================
Name :  Q17.c
Author : Somya Malgudi
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: Aug 24, 2023
============================================================================	
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>


void write_lock(int fd){
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    fcntl(fd,F_SETLKW,&lock);
}


void unlock(int fd){
    struct flock lock;
    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    fcntl(fd,F_SETLKW,&lock);
}

int main(){
    const char* file_path = "ticket.txt";
    int fd = open(file_path, O_RDWR, 0666);
    if(fd == -1){
        printf("Error opening file");
        return 1;
    }

    
    printf("Hello Please wait\n");

    write_lock(fd);
    printf("Inside CS\n");
    int tno;
    printf("Enter ticket number\n");
    scanf("%d", &tno); 
    write(fd,&tno,sizeof(int));
    unlock(fd);


    close(fd);
    return 0;
}