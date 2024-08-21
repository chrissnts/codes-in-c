
#include <stdio.h>

int main()
{
    int num, uni, dez, cent;

    printf("Digite um número inteiro: \n");
    scanf("%i", &num);

    if ( num < 0 || num > 1000)
    {
        printf("\nNúmero Inválido.");
    }
    else
    {
        cent = num / 100;
        dez = num % 100 /10 ;
        uni = num % 100 % 10 ;

        if ( cent > 0 )
        {
            printf("\n %i = %i centenas, %i dezenas e %i unidades ", num, cent, dez, uni);
        }
        else
        {
            if (dez > 0)
            {
                printf("\n %i = %i dezenas e %i unidades ", num,dez, uni);
            }
            if ( uni > 0 && dez == 0)
            {
                printf("\n %i =  %i unidades ", num, uni);
            }
        }

    }
    return 0;
}
