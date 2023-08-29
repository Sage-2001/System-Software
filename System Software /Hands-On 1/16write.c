// 16. Write a program to perform mandatory locking.
// a. Implement write lock
// b. Implement read lock

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
    const char* file_path = "process.txt";
    int fd = open(file_path, O_RDWR| O_CREAT, 0666);
    if(fd == -1){
        printf("Error opening file");
        return 1;
    }

    printf("Before Write Critical Section\n");
    write_lock(fd);
    printf("Inside Write Critical Section\n");
    char buf[100];
    printf("Enter content\n");
    scanf("%[^\n]%*c", buf); 
    write(fd,buf,20);
    unlock(fd);


    close(fd);
    return 0;
}