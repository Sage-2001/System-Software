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
    fcntl(fd, F_SETLKW, &lock);
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
    write_lock(fd);
    printf("Inside Critical Section\n");
    int record_num;
    printf("Enter the record number to update: ");
    scanf("%d", &record_num);
    
    struct Record r1;
    r1.id = record_num;

    printf("Enter a new name: ");
    scanf("%s", r1.name);

    lseek(fd, sizeof(struct Record) * (record_num - 1), SEEK_SET);
    ssize_t bw = write(fd, &r1, sizeof(struct Record));
    
    unlock(fd);

    printf("Updated record successfully\n");

    lseek(fd, 0, SEEK_SET);
    printf("Records in the file:\n");
    for (int i = 0; i < 3; i++) {
        struct Record r;
        ssize_t br = read(fd, &r, sizeof(struct Record));
        if (br == sizeof(struct Record)) {
            printf("Record %d: ID: %d, Name: %s\n", i + 1, r.id, r.name);
        }
    }

    close(fd);
    return 0;
}
