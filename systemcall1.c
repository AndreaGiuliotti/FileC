#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd;

    if((fd = open(argv[1],O_RDONLY))==-1)
    {
        printf("File inserito non presente.\n");
        return -1;
    }
    else{
        fd = open(argv[1],O_RDONLY);
    }

    char buffer[1024];
    int nread;
    while((nread = read(fd,&buffer,sizeof(buffer)))>0)
    {
        write(1,&buffer,sizeof(buffer));
    }
    
    close(fd);
}