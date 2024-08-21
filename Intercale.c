#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5

int main()
{
    int vetA[TAM], vetB[TAM], vetC[10] = {0};
    int i;

    srand(time(NULL));

    for (i = 0; i < TAM; i++)
    {
        vetA[i] = 1 + rand() % 10;
        printf("[%i]", vetA[i]);
    }
    printf("\n");

    for (i = 0; i < TAM; i++)
    {
        vetB[i] = 1 + rand() % 10;
        printf("[%i]", vetB[i]);
    }
    printf("\n");

    for (i = 0; i < TAM; i++)
    {
        vetC[2 * i] = vetA[i];
        vetC[2 * i + 1] = vetB[i];
    }

    printf("vetC: ");
    for (i = 0; i < TAM * 2; i++)
    {
        printf("[%i]", vetC[i]);
    }

    printf("\n");
    return 0;
}
