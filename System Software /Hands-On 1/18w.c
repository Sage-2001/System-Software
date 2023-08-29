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

struct Record {
    int id;
    char name[50];
};

int main(){
    int fd = open("18.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (fd == -1){
        perror("Error opening file");
        return 1;
    }
    int n;
    printf("Enter 1 to create 3 dummy records or 2 to update a record\n");
    scanf("%d",&n);
    if(n == 1){
        struct Record records[3];

        records[0].id = 1;
        strcpy(records[0].name, "Somya");

        records[1].id = 2;
        strcpy(records[1].name, "Shanky");

        records[2].id = 3;
        strcpy(records[2].name, "Johnson");


        printf("Please wait.\n");
        write_lock(fd);
        printf("Writing records into file.\n");
        for (int i = 0; i < 3; i++) {
            ssize_t bw = write(fd, &records[i], sizeof(struct Record));
            if (bw != sizeof(struct Record)) {
                perror("Cannot write into memory");
                close(fd);
                return 1;
            }
        }
        printf("Records written successfully.\n");


        printf("Press Enter to exit Critical Section\n");
        getchar(); // Wait for Enter key
        unlock(fd);


        lseek(fd, 0, SEEK_SET);
        printf("Records in the file:\n");
        for (int i = 0; i < 3; i++) {
            struct Record r;
            ssize_t br = read(fd, &r, sizeof(struct Record));
            if (br == sizeof(struct Record)) {
                printf("Record %d: ID: %d, Name: %s\n", i + 1, r.id, r.name);
            }
        }
    }



    if(n==2){
        printf("Please wait.\n");
        write_lock(fd);
        printf("Inside Critical Section\n");
        int record_num;
        printf("Enter the record number to update: ");
        scanf(" %d", &record_num);
        struct Record r1;
        r1.id = record_num;

        printf("Enter a new name: \n");
        scanf(" %[^\n]", r1.name);

        lseek(fd, sizeof(struct Record) * (record_num - 1), SEEK_SET);
        ssize_t bw = write(fd, &r1, sizeof(struct Record));

        printf("Updated record successfully. Enter to exit Critical Section...");
        getchar(); // Wait for Enter key
        getchar();
        unlock(fd);
    }
    close(fd);
    return 0;
}
