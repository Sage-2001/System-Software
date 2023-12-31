/*
============================================================================
Name : 27b.c
Author : Somya Malgudi
Description : Write a program to receive messages from the message queue.
	b. with IPC_NOWAIT as a flag
============================================================================
*/
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
    key_t key = ftok(".",'a');
    if(key == -1){
        perror("Failed to create a key");
        exit(1);
    }
    int id = msgget(key,IPC_CREAT|0777);
    if(id == -1){
        perror("Failed to create the message queue\n");
        exit(1);
    }

    struct msgbuf
    {
        long mtype;
        int num;
    };

    struct msgbuf msg;
    msg.mtype = 1;

    int status = msgrcv(id,&msg,sizeof(msg),msg.mtype,IPC_NOWAIT);
    if (status == -1)
    {
        perror("Failed to send the message\n");
        exit(1);
    }
    else    printf("Message recieved with number: %d ",msg.num);
    return 0;
}