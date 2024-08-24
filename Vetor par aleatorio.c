#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 20

int main()
{
    int vet[TAM], vetpar[0];
    int i;

    srand(time(NULL));

    for (i = 0; i < TAM; i++)
    {
        vet[i] = 1 + rand() % 100;
        if (vet[i] % 2 == 0)
        {
            vetpar[i] = vet[i];
            printf("[%i]", vetpar[i]);
        }
    }

    return 0;
}
