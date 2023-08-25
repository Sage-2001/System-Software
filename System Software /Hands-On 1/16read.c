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

void read_lock(int fd){
    struct flock lock;
    lock.l_type = F_RDLCK;
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
    printf("Before Read Critical Section\n");

    read_lock(fd);
    printf("Inside Read Critical Section\n");
    char buf[100];
    printf("Press Enter to exit Critical Section\n");
    scanf("%[^\n]%*c", buf); 
    ssize_t msg = read(fd,buf,sizeof(buf) -1);
    if(msg > 0){
        buf[msg] = '\0';
        printf("Read content: %s\n",buf);
    }
    unlock(fd);

    close(fd);
    return 0;
}