#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

int main()
{
    int vet[TAM];
    int i, j, aux, cont = 0;
    int inicio = 0, fim = TAM - 1, meio;
    int valor_procurado = 70;

    srand(time(NULL));

    printf("Vetor normal: ");
    for (i = 0; i < TAM; i++)
    {
        vet[i] = 1 + rand() % 100;
        printf("[%i]", vet[i]);
    }
    printf("\n");

    // Vetor crescente
    for (i = 0; i < TAM; i++)
    {
        for (j = 0; j < TAM - i - 1; j++)
        {
            if (vet[j] > vet[j + 1])
            {
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
        }
    }
    printf("Vetor decrescente: ");
    for (i = 0; i < TAM; i++)
    {

        printf("[%i]", vet[i]);
    }

    while (inicio <= fim)
    {

        meio = inicio + (fim - inicio) / 2;

        if (vet[meio] == valor_procurado)
        {
            printf("\nValor %i encontrado no índice %d\n", valor_procurado, meio);
            cont++;
            break;
        }
        if (vet[meio] < valor_procurado)
        {
            inicio = meio + 1; // Ajusta o início para a metade direita
        }
        else
        {
            fim = meio - 1; // Ajusta o fim para a metade esquerda
        }
    }

    if (cont == 0)
    {
        printf("\nValor %i não encontrado\n", valor_procurado);
    }

    return 0;
}
