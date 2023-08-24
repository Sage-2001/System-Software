// 17. Write a program to simulate online ticket reservation. Implement write lock
// Write a program to open a file, store a ticket number and exit. Write a separate program, to
// open the file, implement write lock, read the ticket number, increment the number and print
// the new ticket number then close the file.

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/file.h>

int readtno(){
    FILE *file = fopen("ticket.txt", "r");
    if(file == NULL){
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    int tno;
    fscanf(file,"%d",&tno);
    fclose(file);
    return tno;
}

void wno(int tno){
    FILE *file = fopen("ticket.txt","w");
    if(file == NULL){
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "%d", tno);
    fclose(file);
}

int main(){
    FILE *file = fopen("ticket.txt","r+");
    if(file == NULL){
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    flock(fileno(file),LOCK_EX);

    int ctno = readtno();
    int newtno = ctno+1;
    printf("Current ticket number: %d\n",ctno);
    printf("New ticket number: %d\n",newtno);
    wno(newtno);
    flock(fileno(file),LOCK_UN);
    printf("Ticket number updated successfully.\n");
    fclose(file);
    return 0;
}