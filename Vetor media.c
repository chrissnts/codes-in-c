#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

int main ()
{

    float valor, vet[TAM],media;
    int i;

    for (i = 0; i < TAM; i ++)
    {
        printf("Digite o %i valor: ", i+1);
        scanf("%f", &vet[i]);
        media += vet[i];
    }
    media = (media/10);
    printf("Media = %2.f", media);
    

    return 0;
}
