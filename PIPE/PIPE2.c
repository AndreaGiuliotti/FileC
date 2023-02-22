#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv)
{

    int canale1[2], canale2[2];
    int array[] = {526, 478, 985};
    int pid, somma = 0;

    pipe(canale1);
    pipe(canale2);

    pid = fork();

    if (pid == 0)
    {
        close(canale1[1]);
        close(canale2[0]);
        int numeri[3];
        read(canale1[0], numeri, sizeof(numeri));
        for (int i = 0; i < 3; i++)
        {
            somma += numeri[i];
        }
        write(canale2[1], &somma, sizeof(somma));
        exit(0);
    }

    close(canale1[0]);
    close(canale2[1]);
    write(canale1[1], array, sizeof(array));
    wait(&pid);
    read(canale2[0], (void *)&somma, sizeof(somma));
    printf("Somma : %d\n", somma);

    return 0;
}