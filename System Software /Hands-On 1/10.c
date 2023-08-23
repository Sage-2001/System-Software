/*Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    int fd = 0;
    char buf[1024], content[10];

    printf("Enter file name: ");
    scanf("%[^\n]%*c", buf);  // Use %*c to consume the newline character

    fd = open(buf, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd < 0) {
        printf("\nError opening file");
        return 1;  // Exit with an error code
    }

    printf("Enter 10-byte content: ");
    scanf("%[^\n]%*c", content);

    write(fd, content, 10);
    
    off_t lseek_op = lseek(fd, 10, SEEK_CUR);  // Use off_t for the return type of lseek

    if (lseek_op == -1) {
        perror("lseek");
        return 1;  // Exit with an error code
    }
    
    printf("lseek Output: %ld\n", lseek_op);  // Use %ld for off_t type

    printf("Enter 10-byte content: ");
    scanf("%[^\n]%*c", content);

    write(fd, content, 10);

    int fdclose = close(fd);
    if (fdclose < 0) {
        perror("close");
        return 1;  // Exit with an error code
    }

    return 0;  // Return 0 to indicate successful execution
}
