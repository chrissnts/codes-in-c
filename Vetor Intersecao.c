#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

int main()
{
    int vet[TAM], vet2[TAM];
    int i, j, k, ja_impresso = 0;

    srand(time(NULL));

    for (i = 0; i < TAM; i++)
    {
        vet[i] = 1 + rand() % 10;
        vet2[i] = 1 + rand() % 10;
    }

    printf("\nVetor A: ");
    for (i = 0; i < TAM; i++)
    {
        printf("[%i]", vet[i]);
    }

    printf("\nVetor B: ");
    for (i = 0; i < TAM; i++)
    {
        printf("[%i]", vet2[i]);
    }

    printf("\nIntersecao: [");

    for (i = 0; i < TAM; i++)
    {
        for (j = 0; j < TAM; j++)
        {
            if (vet[i] == vet2[j])
            {
                ja_impresso = 0;

                for (k = 0; k < i; k++)
                {
                    if (vet[k] == vet[i])
                    {
                        ja_impresso = 1;
                        break;
                    }
                }
                if (!ja_impresso)
                {
                    printf("[%i]", vet[i]);
                    break;
                }
            }
        }
    }
    printf("]");

    return 0;
}
