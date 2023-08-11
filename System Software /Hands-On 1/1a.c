#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
    
    const char *source = "./1";
    const char *softlinkpath = "./SoftLink";

    int x = symlink(source,softlinkpath);
    return 0;
}