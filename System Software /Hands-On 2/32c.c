/*
============================================================================
Name : 32_c.c
Author : Prashant Jain
Description : Write a program to implement semaphore to protect 
	any critical section.
	c. protect multiple pseudo resources ( may be two) using 
	counting semaphore
============================================================================
*/
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *__buf;
};

int main() {
    char *file = "ticket.txt";
    int fd = open(file, O_CREAT | O_RDONLY, 0777);
    if (fd == -1) {
        perror("Failed to open file");
        exit(1);
    }

    key_t key = ftok(".", 'a');
    if (key == -1) {
        perror("Failed to get key");
        exit(1);
    }

    int id = semget(key, 1, IPC_CREAT | IPC_EXCL | 0666);
    if (id == -1) {
        id = semget(key, 1, 0);
    } else {
        union semun sem;
        sem.val = 2;
        if (semctl(id, 0, SETVAL, sem) == -1) {
            perror("Failed to initialize Semaphore");
            exit(1);
        }
    }

    struct sembuf op;
    op.sem_num = 0;
    op.sem_op = -1;
    op.sem_flg = SEM_UNDO;

    printf("Press enter to enter into critical section\n");
    getchar();

    int status = semop(id, &op, 1);
    if (status == -1) {
        perror("Failed to lock for some reason");
        exit(1);
    }

    printf("Obtained the lock\n");

    char buf[100];
    ssize_t bytesRead = read(fd, buf, sizeof(buf) - 1);
    if (bytesRead == -1) {
        perror("Failed to read from file");
        exit(1);
    }
    buf[bytesRead] = '\0';

    printf("Data is: %s\n", buf);

    printf("Press enter to release lock\n");
    getchar();

    op.sem_op = 1;
    status = semop(id, &op, 1);
    if (status == -1) {
        perror("Failed to unlock for some reason but IPC_UNDO must have taken care of it");
        exit(1);
    }

    close(fd);

    return 0;
}
