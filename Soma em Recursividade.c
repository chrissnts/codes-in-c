#include <stdio.h>
#include <stdlib.h>

int somar_elementos(int vet[], int i, int tam);

int main ()
{
    int i, tam;

    printf("\nDigite um tamanho para o vetor:\n");
    scanf("%i",&tam);
    int vet[tam];

    printf("\nDigite os valores para o vetor:\n");
    for (i = 0; i < tam; i++)
    {
        scanf("%i",&vet[i]);
    }
    int soma = somar_elementos(vet, 0, tam);
    
    printf("\nSoma de todos os valores do vetor: %i\n",soma);
    
}
int somar_elementos(int vet[], int i, int tam)
{
    if (i >= tam)
    {
        return 0;
    }

    return vet[i] + somar_elementos(vet, i+1, tam);
}