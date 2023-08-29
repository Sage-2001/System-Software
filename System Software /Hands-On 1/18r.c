#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>


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
    fcntl(fd, F_SETLKW, &lock);
}

struct Record 
{
    int id;
    char name[50];
};

int main(){
    const char* file_path = "18.txt";
    int fd = open(file_path, O_RDWR, 0666);
    if(fd == -1){
        printf("Error opening file");
        return 1;
    }

    
    printf("Please wait.\n");
    read_lock(fd);
    printf("Inside Critical Section\n");
    int record_num;
    printf("Enter the record number to see: ");
    scanf(" %d", &record_num);
    struct Record r1;
    r1.id = record_num;
    lseek(fd, sizeof(struct Record) * (record_num - 1), SEEK_SET);
    ssize_t br = read(fd, &r1, sizeof(struct Record));
    if (br == sizeof(struct Record)) {
        printf("Record %d: ID: %d, Name: %s\n", record_num , r1.id, r1.name);
    }
    printf("Enter to exit Critical Section...");
    getchar(); // Wait for Enter key
    getchar();
    unlock(fd);
    close(fd);
    return 0;
}
