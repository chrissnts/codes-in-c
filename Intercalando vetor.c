#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10
#define TAMC 20

int main()
{
    srand (time(NULL));
    
    int vetA[TAM], vetB[TAM], vetC[TAMC];
    int i, j;
    
    // Criando vetor A, preenchendo com aleatorios.
    printf("\nVetores em A:");
    for (i = 0; i < TAM; i++)
    {  
        vetA[i] = 1 + rand()%50;
        printf("[%i]", vetA[i]);
    }
    
    // Criando vetor B, preenchendo com aleatorios.
    printf("\nVetores em B:");
    for (i = 0; i < TAM; i ++) 
    {
        vetB[i] = 1 + rand()%50;
        printf("[%i]", vetB[i]);
    } 
    
    // Armazenando em C o valores dos 2 vetores.
    for ( i = 0; i < TAMC; i++)
    {
        vetC[2*i] = vetA[i];
        vetC[2*i +1] = vetB[i];
    }
    
    // Imprimindo valores de C com A e B intercalados;
    printf("\nVetores em C intercalando A e B:");
    
    printf("\n[");
    for(i = 0; i < TAMC; i++)
    {   
        printf(" %i", vetC[i]);
    }
    printf("]\n");
    
    return 0;
}
