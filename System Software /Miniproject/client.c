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

    struct sockaddr_in server_address;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    int connectionStat = connect(socketFD, (struct sockaddr *) &server_address,sizeof(server_address));
    if (connectionStat == -1)
    {
        perror("socket connection error");
        exit(1);
    }

    Welcome;
    int ch;
    scanf("%d", &ch);
    
    while (1)
    {
        switch (ch)
        {
        case 1:
            {
                char buf[] = "admin";
                write(socketFD, &buf,sizeof(buf));
                break;
            }

        case 2:
            {
                char buf[] = "faculty";
                write(socketFD, &buf,sizeof(buf));
                break;
            }


        case 3:
            {
                char buf[] = "student";
                write(socketFD, &buf,sizeof(buf));
                break;
            }
        
        default:
            "Invalid Choice";
            exit(1);
            break;
        }
    }
    close(socketFD);
    return 0;
}