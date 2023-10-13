#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/ip.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include "jargans.h"

int main(){
    int socketFD = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFD == -1)
    {
        perror("failed to create socket\n");
        exit(1);
    }

    struct socketaddr_in server_address;
    client.sin_addr.s_addr = htonl(INADDR_ANY);
    client.sin_family = AF_INET;
    client.sin_port = htons(PORT);

    int connectionStat = connect(socketFD, (struct socketaddr *) &server_address,sizeof(server_address));
    if (connectionStat == -1)
    {
        perror("socket connection error");
        exit(1);
    }
    
    Welcome;
    int ch;
    scanf("%c", &ch);
    
    while (1)
    {
        char buf[100];
        switch (ch)
        {
        case 1:
            buf = "admin";
            write(socketFD, buf,sizeof(buf));
            break;

        case 2:
            buf = "faculty";
            write(socketFD, buf,sizeof(buf));
            break;

        case 3:
            buf = "student";
            write(socketFD, buf,sizeof(buf));
            break;
        
        default:
            "Invalid Choice";
            exit(1);
            break;
        }
    }
    return 0;
}