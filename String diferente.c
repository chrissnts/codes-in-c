#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 100
#define FOR 5

int main()
{
    int i, iguais = 0;
    int tam;
    char word[TAM], word2[TAM];

    for (i = 0; i < FOR; i++)
    {
        printf("Escreva primeira palavra: ");
        gets(word);
        __fpurge(stdin);

        printf("Escreva segunda palavra: ");
        gets(word2);
        __fpurge(stdin);

        if (word[i] == word2[i] )
        {
            printf("\nIguais.\n");
        }
        else
        {
            printf("\nDiferentes.\n");
        }
    }

    return 0;
}
