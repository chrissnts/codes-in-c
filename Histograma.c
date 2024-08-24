#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10
#define VALOR 10

int main()
{
    int vet[TAM];
    int counts[VALOR + 1] = {0};
    int i, j;

    srand(time(NULL));

    for (i = 0; i < TAM; i++)
    {
        vet[i] = 1 + rand() % VALOR;
    }

    printf("vet: ");
    for (i = 0; i < TAM; i++)
    {
        printf("[%i]", vet[i]);
    }
    printf("\n");

    for (i = 0; i < TAM; i++)
    {
        for (j = 0; j < TAM; j++)
        {
            if (vet[i] == vet[j])
            {

                counts[vet[i]]++;

                vet[j] = -1;
                break;
            }
        }
    }

    printf("Interseção: [");

    for (i = 1; i <= VALOR; i++)
    {
        if (counts[i] > 0)
        {
            printf("%i|", i);
        }
    }
    printf("]\n");

    printf("Histograma de Frequência:\n");
    for (i = 1; i <= VALOR; i++)
    {
        if (counts[i] > 0)
        {
            printf("%2d: ", i);

            for (int j = 0; j < counts[i]; j++)
            {
                printf("*");
            }

            printf(" (%d)\n", counts[i]);
        }
    }

    return 0;
}
