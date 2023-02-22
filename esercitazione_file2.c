#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 100

int conta_stringhe(FILE *fp, char nome_file[])
{
    fp = fopen(nome_file, "r");
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
    int controllo;
    FILE *f1;
    if ((f1 = fopen("file.txt", "r")) == NULL)
    {
        printf("Primo file non esistente.\n");
        return -1;
    }
    else
    {
        controllo = conta_stringhe(f1, "file.txt");
        if (controllo == -1)
        {
            printf("Primo file non accettabile.\n");
            return -1;
        }
    }

    FILE *f2;
    if ((f2 = fopen("file2.txt", "r")) == NULL)
    {
        printf("Secondo file non esistente.\n");
        return -1;
    }
    else
    {
        controllo = conta_stringhe(f1, "file2.txt");
        if (controllo == -1)
        {
            printf("Secondo file non accettabile.\n");
            return -1;
        }
    }

    FILE *file_risultato;
    if ((file_risultato = fopen("file_risultato.txt", "r+")) == NULL)
    {
        printf("Terzo file non esistente.\n");
        return -1;
    }

    char S1[DIM], S2[DIM];
    char supporto[DIM];

    while (!feof(f1))
    {
        rewind(f2);
        fscanf(f1, "%s", S1);
        strcpy(supporto,S1);
        while (!feof(f2))
        {
            fscanf(f2, "%s", S2);
            //se la stringa del primo file è più piccola della stringa del secondo file, strcmp restituisce un numero minore di 0
            if (strcmp(S1, S2) < 0 && strcmp(supporto,S1)<0)
            {
                //la stringa di supporto va svuotata, altrimenti i caratteri si sovrappongono
                strcpy(supporto,"");
                strcpy(supporto, S1);
            }

            //se la stringa del primo file è più piccola della stringa del secondo file, strcmp restituisce un numero minore di 0
            else if (strcmp(supporto, S2) > 0 && strcmp(supporto,S2)<0)
            {
                //la stringa di supporto va svuotata, altrimenti i caratteri si sovrappongono
                strcpy(supporto,"");
                strcpy(supporto, S2);
            }
        }
    }

    fprintf(file_risultato, "La stringa più corta è : %s.\n", supporto);
    fclose(f1);
    fclose(f2);
    fclose(file_risultato);
    return 0;
}