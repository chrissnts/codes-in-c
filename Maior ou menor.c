#include <stdio.h>

int main()
{
    int a, b, c;
    int maiorvalor, menorvalor;

    printf("Digite o valor de a:");
    scanf("%i", &a);
    printf("Digite o valor de b:");
    scanf("%i", &b);
    printf("Digite o valor de c:");
    scanf("%i", &c);

    if ( a == b || b == c || c ==a)
    {
        printf("Numeros iguais.");
        return 0 ;
    }
    
    if (a > b && a > c && c > b)
    {
        maiorvalor = a;
        menorvalor = b;
    }
    else if (a > b && a > c && c < b )
    {
        maiorvalor = a;
        menorvalor = c;
    }

    if (b > a && b > c && a > c)
    {
        maiorvalor = b;
        menorvalor = c;
    }
    else if ( b > a && b > c && a < c)
    {
        maiorvalor = b;
        menorvalor = a;
    }

    if ( c > a && c > b && b > a)
    {
        maiorvalor = c;
        menorvalor = a;
    }
    else if ( c > a && c > b && b < a)
    {
        maiorvalor = c;
        menorvalor = b;
    }

    printf ("Maior valor = %i", maiorvalor);
    printf("\nMenor valor = %i", menorvalor);
   

    return 0;
}
