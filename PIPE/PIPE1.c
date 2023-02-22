#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){


    int pid, nwrite, nread;
    int lettura_scrittura[2];
    char buffer[80];

    pipe(lettura_scrittura);

    pid = fork();

    if(pid == 0){
        close(lettura_scrittura[0]);
        char stringa[]="daje roma\n";
        nwrite = write(lettura_scrittura[1],stringa,strlen(stringa));
        exit(0);
    }
    close(lettura_scrittura[1]);
    wait(&pid);
    while((nread = read(lettura_scrittura[0],buffer,nwrite))!=0){
        write(1,buffer,nread);
    }
    exit(0);
}