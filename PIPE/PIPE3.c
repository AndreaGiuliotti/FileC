#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char *argv[])
{
    int pid;
    int canale[2];
    pipe(canale);

    pid = fork();
    if(pid==0)
    {
        close(canale[0]);
        int n;
        printf("Inserisci un numero : ");
        scanf("%d",&n);
        write(canale[1],&n,sizeof(n));
        exit(0);
    }

    pid = fork();
    if(pid==0){
        close(canale[1]);
        int quadrato;
        read(canale[0],(void *)&quadrato,sizeof(quadrato));
        quadrato *= quadrato;
        printf("FIGLIO : il quadrato del numero inserito è : %d\n",quadrato);
        exit(0);
    }

    wait(&pid);
    wait(&pid);

    return 0;
}