// 8. Write a program to open a file in read only mode, read line by line and display each line as it is read.
// Close the file when end of file is reached.

#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    if(argc!=2)
        {
            printf("Wrong number of arguments\n");
            return -1;
        }

    int fd_read = open(argv[1], O_RDONLY);
    ssize_t readb = 0;
    char buf[100];
    

    if (fd_read == -1)
    {
        printf("Error opening file");
    }
    
    while ((readb = read(fd_read,buf,sizeof(buf))) > 0)
    {
        for (ssize_t i = 0; i < readb; i++)
        {
            if (buf[i] != '\n')
            {
                printf("%c",buf[i]);
            }
            else{
                printf("\n");
            }
        }
    }

    int close_fd_read = close(fd_read);

    if (close_fd_read == -1)
    {
        printf("Error closing file");
    }
    
    return 0;
}