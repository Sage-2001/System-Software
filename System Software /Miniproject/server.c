#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/ip.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include "./Helpers/jargans.h"

int main(){
    int socketFD = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFD == -1)
    {
        perror("failed to create socket\n");
        exit(1);
    }

    struct sockaddr_in client_address;
    client_address.sin_addr.s_addr = htonl(INADDR_ANY);
    client_address.sin_family = AF_INET;
    client_address.sin_port = htons(PORT);

    int bindStat = bind(socketFD, (struct sockaddr *) &client_address, sizeof(client_address));
    if (bindStat == -1)
    {
        perror("failed to bind socket\n");
        exit(1);
    }
    int listenStat = listen(socketFD, 10);
    if (listenStat == -1)
    {
        perror("Failed to listen for incoming request\n");
        exit(1);
    }

    while (1)
    {
        int clientSize = (int)sizeof(client_address);
        int clientconnFD = accept(socketFD, (struct sockaddr *) &client_address, &clientSize);
        if (clientconnFD == -1)
        {
            perror("Connection is not accepted");
            exit(1);
        }
        else
        {
            if (!fork())
            {
                close(socketFD);
                //make a function which will call controller
                //they are divided into 3 parts admin student client they are going to come in controller

                printf("Done successfully");
            }
            else
            {
                close(clientconnFD);
            }
        }
    }
    close(socketFD);
    return 0;
}