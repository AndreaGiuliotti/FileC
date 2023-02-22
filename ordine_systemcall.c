#include <stdio.h>
#include <unistd.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void swap(int argc, char *argv[])
{
    for(int i = 0; i<argc;i++){
        for(int j = 2; j<(argc-i-1); j++){

        }
    }
}

int main(int argc, char **argv[])
{
    swap(argc,argv);

    int fd = 0;
    if(open(argv[1],O_WRONLY) == -1){
        printf("File di partenza non esistente.\n");
        exit(1);
    }
    else{
        fd = open(argv[1],O_WRONLY);
    }

    for(int k = 2; k<argv; k++)
    {
        write(fd, argv[k], sizeof(argv[K]));
        write(fd,'\n',1);
        printf("%s\n",argv[k]);
    }
    
    return 0;
}