#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void wno(int tno){
    FILE *file = fopen("ticket.txt","w");
    if(file == NULL){
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "%d",tno);
    fclose(file);
}

int main(){
    int tno;
    printf("Enter the initial ticket number: ");
    scanf("%d",&tno);

    wno(tno);
    printf("Ticket number written successfully.\n");
    return 0;
}