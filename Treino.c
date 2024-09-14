#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TAM 100

int main()
{
    // strlen - tamanho da string;
    // strcmp - compara qual string maior retornando 0 ou menor que 0 (strncmp pega ate tal numero);
    // strcpy - copia a string (strncpy copia ate tal numero );
    // strcat - concatena a string 1 com a string 2 (strncat concactena ate tal numero);

    char word[TAM], word2[TAM], word3[TAM];
    int tam, tam2, tam3;

    printf("\nEnter a word:\n");
    fflush(stdin);
    gets(word);
    tam = strlen(word);

    printf("\nEnter a word 2:\n");
    fflush(stdin);
    gets(word2);
    tam2 = strlen(word2);

    printf("\nEnter a word 3:\n");
    fflush(stdin);
    gets(word3);
    tam3 = strlen(word3);

    if (tam < tam2 && tam2 < tam3)
    {
        strcat(word, " - ");
        strcat(word, word2);
        strcat(word, " - ");
        strcat(word, word3);
        printf("\n%s\n", word);
    }
    else if (tam < tam2 && tam3 < tam2)
    {
        strcat(word, " - ");
        strcat(word, word3);
        strcat(word, " - ");
        strcat(word, word2);
        printf("\n%s\n", word);
    }
    else if (tam < tam2 && tam2 > tam3)
    {
        strcat(word, " - ");
        strcat(word, word3);
        strcat(word, " - ");
        strcat(word, word2);
        printf("\n%s\n", word);
    }
    else if (tam2 < tam && tam < tam3)
    {
        strcat(word2, " - ");
        strcat(word2, word);
        strcat(word2, " - ");
        strcat(word2, word3);
        printf("\n%s\n", word2);
    }
    else if (tam < tam2 && tam3 < tam3)
    {
        strcat(word3, " - ");
        strcat(word3, word);
        strcat(word3, " - ");
        strcat(word3, word2);
        printf("\n%s\n", word3);
    }
    else if (tam2 < tam && tam2 < tam3)
    {
        strcat(word2, " - ");
        strcat(word2, word3);
        strcat(word2, " - ");
        strcat(word2, word);
        printf("\n%s\n", word2);
    }
    else if (tam2 < tam && tam2 > tam3)
    {
        strcat(word3, " - ");
        strcat(word3, word2);
        strcat(word3, " - ");
        strcat(word3, word);
        printf("\n%s\n", word3);
    }

    return 0;
}
