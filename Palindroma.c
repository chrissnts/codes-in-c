#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 100

int main()
{
    int i, iguais = 0;
    int tam;
    char word[TAM], copy[TAM];

    printf("Escreva uma palavra: ");
    gets(word);
    __fpurge(stdin);

    while (word[tam] != '\0')
    {
        tam++;
    }
    printf("%i", tam);
    for (i = 0; i < tam; i++)
    {
        copy[i] = word[tam - 1];
        tam--;
    }

    for (i = 0; i < tam; i++)
    {
        if (copy[i] == word[i])
        {
            iguais++;
        }
    }

    if (iguais == tam)
    {
        printf("\nEh palindromo.\n");
    }
    else
    {
        printf("\nNao eh palindromo.\n");
    }

    return 0;
}
