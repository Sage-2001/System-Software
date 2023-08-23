/*Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<time.h>

int main() {
    char buf[1024];

    printf("Enter file name: ");
    scanf("%[^\n]", buf);

    struct stat file_details;

    if (stat(buf, &file_details) == -1) {
        printf("Error opening file\n");
    } else {
        printf("File details: \n");
        printf("Inode number: %ld\n", file_details.st_ino);
        printf("Number of hard links: %ld\n", file_details.st_nlink);
        printf("Owner User ID: %ld\n", file_details.st_uid);
        printf("Owner Group ID: %ld\n", file_details.st_gid);
        printf("Size: %ld bytes\n", file_details.st_size);
        printf("Block size: %ld bytes\n", file_details.st_blksize);
        printf("Number of blocks: %ld\n", file_details.st_blocks);
        printf("Time of last access: %s", ctime(&file_details.st_atime));
        printf("Time of last modification: %s", ctime(&file_details.st_mtime));
        printf("Time of last change: %s", ctime(&file_details.st_ctime));
    }
    return 0;
}
