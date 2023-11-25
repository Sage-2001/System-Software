/*
 ============================================================================
Name :  Q30.c
Author : Somya Malgudi
Description : Write a program to run a script at a specific time using a Daemon process
Date: Sep 9, 2023
============================================================================	
*/ 
#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<time.h>


int main(void)
{

    struct tm exectime;
    exectime.tm_hour = 10;
	exectime.tm_min = 1;
	exectime.tm_sec = 30;
	
	if(fork()==0){
		setsid();
		umask(0);
		chdir("/");
		while(1){
		    time_t timevalue = time(NULL);
		    struct tm* currtime = localtime(&timevalue);

		    if(currtime->tm_hour == exectime.tm_hour && currtime->tm_min == exectime.tm_min 
		    	&& currtime->tm_sec == exectime.tm_sec){


		    	printf("run your job");
		    
		    break;
		}
	}
	}else{
		exit(0);
	}
    return 0;
}