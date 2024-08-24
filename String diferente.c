#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 100
#define TAM2 1

int main()
{
    char word[TAM], word2[TAM];
    int tam1, tam2;
    int i, j, same = 0, aux = 1;

    printf("\nEnter a word:");
    gets(word);
    fflush(stdin);

    for (j = 0; j < TAM2; j++)
    {

        for (tam1 = 0; word[tam1] != '\0'; tam1++)
        {
        }
        printf("String 1 has length: [%i] ", tam1);

        printf("\nEnter a word:");
        gets(word2);
        fflush(stdin);

        for (tam2 = 0; word2[tam2] != '\0'; tam2++)
        {
        }
        printf("String 2 has length: [%i] ", tam2);

        if (tam1 != tam2)
        {
            printf("\nStrings different.\n");
        }
        else
        {
            for (i = 0; word[i] != '\0'; i++)
            {
                if (word[i] != word2[i])
                {
                    aux = 0;
                    break;
                }
            }
        }

        if (aux == 1)
        {
            printf("\nStrings are the same.\n");
        }
        else
        {
            printf("\nStrings are different.\n");
        }
    }

    return 0;
}
