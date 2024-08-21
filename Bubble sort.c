Novidade! Atalhos do teclado … Os atalhos de teclado do Drive foram atualizados para oferecer navegação por letras iniciais
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5

int main()
{
    int vetA[TAM];
    int i, j, aux;

    srand(time(NULL));

    printf("Vetor normal: ");
    for (i = 0; i < TAM; i++)
    {
        vetA[i] = 50 + rand() % 51;
        printf("[%i]", vetA[i]);
    }
    printf("\n");

    
    printf("Vetor decrescente:");
    for (i = 0; i < TAM; i++)
    {
        for (j = 0; j < TAM - i - 1; j++)
        {
            if (vetA[j] < vetA[j + 1])
            {

                aux = vetA[j];
                vetA[j] = vetA[j + 1];
                vetA[j + 1] = aux;
            }
        }
    }

    for (i = 0; i < TAM; i++)
    {
        printf("[%i]", vetA[i]);
    }

    return 0;
}
