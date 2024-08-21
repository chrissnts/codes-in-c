#include <stdio.h>
#include <math.h>

int main()
{
    float preço, porcent, desconto;

    printf("Digite o preço do item: \n");
    scanf("%f", &preço);
    if ( preço >= 1)
    {
        printf("Digite a porcentagem do desconto: \n");
        scanf("%f", &porcent);

        if ( porcent >= 1)
        {
            (desconto = (porcent * preço )/ 100);

            preço = (preço - desconto);

            printf("\nValor de desconto: %2.f\n Valor total: %2.f", desconto, preço);
        
        }else
        printf("\nNúmero Inválido.");
    }else
    {
        printf("\nNúmero Inválido.");
    }
    
    return 0;
}
    
