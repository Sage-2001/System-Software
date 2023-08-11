#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
    
    const char *source = "./1";
    const char *HardLInk = "./HardLink";
    int x = link(source,HardLInk);
    return 0;
}