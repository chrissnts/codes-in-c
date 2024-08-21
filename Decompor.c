#include <stdio.h>

int main()
{
    int a, num =0, cent, dez, unid, milhas; 

    while ( num <= 0)
    {
        printf("Digite um numero: \n ");
        scanf("%i", &num);
        
        milhas = num / 1000;
        cent = num % 1000 / 100;
        dez = num % 100 / 10;
        unid = num % 100 % 10;

        if ( milhas > 0 )
        {
            printf("%i = %i milhares, %i centenas, %i dezenas e %i unidades.", num, milhas, cent, dez, unid);
        }
        else if ( cent > 0 )
        {
            printf("%i = %i centenas, %i dezenas e %i unidades.", num, cent, dez, unid);
        }
        else if (dez > 0)
        {
            printf("%i = %i dezenas e %i unidades.", num, dez, unid);
        }
        else if ( unid > 0 && dez == 0)
        {
            printf("%i =  %i unidades.", num, unid);
        }
        


    }

    return 0;
}
