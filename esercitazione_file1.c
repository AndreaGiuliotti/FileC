#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DIM 100

int conta_stringhe(FILE *fp)
{
    if ((fp = fopen("file.txt", "r")) == NULL)
    {
        return -2;
    }

    fp = fopen("file.txt", "r");
    char c;
    int conta = 0;

    while ((c = fgetc(fp)) != -1)
    {
        if (c == '\0')
        {
            conta++;
        }
    }

    if (conta > 100)
    {
        return -1;
    }
    else
    {
        return conta;
    }
    fclose(fp);
}

int main()
{
    FILE *fp;
    if ((fp = fopen("file.txt", "r")) == NULL)
    {
        printf("File non esistente.\n");
        return -1;
    }
    else
    {
        int controllo = conta_stringhe(fp);
        if (controllo == -1)
        {
            printf("File non accettabile.\n");
            return -1;
        }
    }

    fp = fopen("file.txt", "r");
    FILE *file_risultato;
    if ((file_risultato = fopen("file_risultato.txt", "r+")) == NULL)
    {
        printf("File non esistente.\n");
        return -1;
    }
    else
    {
        file_risultato = fopen("file_risultato.txt", "r+");
    }

    char s1[DIM];
    char supporto[DIM];
    while (!feof(fp))
    {
        fscanf(fp, "%s", s1);
        if (strcmp(s1, supporto) > 0)
        {
            strcpy(supporto, s1);
        }
    }

    fprintf(file_risultato, "La stringa più lunga è : %s.\n", supporto);
    fclose(fp);
    fclose(file_risultato);
    return 0;
}
