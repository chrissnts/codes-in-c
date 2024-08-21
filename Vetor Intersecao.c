Novidade! Atalhos do teclado … Os atalhos de teclado do Drive foram atualizados para oferecer navegação por letras iniciais
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

int main()
{
    int vet[TAM], vet2[TAM], vetinter[0];
    int i, j;

    srand(time(NULL));

    for (i = 0; i < TAM; i++)
    {
        vet[i] = 1 + rand() % 10;
        vet2[i] = 1 + rand() % 10;
    }

    for (i = 0; i < TAM; i++)
    {
        printf("[%i]", vet[i]);
    }

    for (i = 0; i < TAM; i++)
    {
        printf("[%i]", vet2[i]);
    }

    printf("Intersecao: [");

    for (i = 0; i < TAM; i++)
    {
        for (j = 0; j < TAM; j++)
        {
            if (vet[i] == vet2[j])
            {
                printf("%i ", vet[i]);
            }
        }
    }
    printf("]");

    return 0;
}
