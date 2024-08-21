#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

int main ()
{

   ;
    int i, media, vet[TAM];
    int maior = 0, menor = 99999999;

    for (i = 0; i < TAM; i ++)
    {
        printf("Digite o %i valor: ", i+1);
        scanf("%i", &vet[i]);
        
        if (vet[i] < menor)
        {
            menor = vet[i];
            
        }
        if (vet[i] > maior)
        {
            maior = vet[i];
           
        } 
        
    
    }
    printf("maior = %i", maior);
    printf("\nmenor = %i", menor);
   
    

    return 0;
}
