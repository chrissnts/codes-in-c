#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TAM 100

int main()
{
    int valor;
    int reverso = 0;
    int i, digito;

    printf("\nDigite um valor:\n");
    scanf("%i", &valor);

    while (valor != 0) 
    {
        digito = valor % 10;       
        reverso = reverso * 10 + digito; 
        valor = valor / 10;       
    }
    printf("\nValor reverso = %i", reverso);
    return 0;
}