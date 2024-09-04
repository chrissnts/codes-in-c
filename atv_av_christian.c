#include <stdio.h>
#include <stdlib.h>

// Christian info24 atividade avaliativa;

int azul ( int dias)
{
    int preco;

    preco = dias * 10;

    if (dias >= 5)
    {
        preco = preco * (5/100);
    }
    else if( dias > 15)
    {
        preco = preco * (10/100);
    }

    return preco;
}

int main()
{
    int cor, dias = 0;
    int quantidade = 0;
    int preco;

    while (1)
    {
        printf("\nQual cor deseja?\n");
        printf("\n1 - Azul\n");
        printf("\n2 - Verde\n");
        printf("\n3 - Laranja\n");
        printf("\n4 - Vermelho\n");
        printf("\n0 - Sair e mostrar valor final\n");
        scanf("%i", &cor);
        printf("\nQuantos dias deseja alocar?\n");
        scanf("%i", &dias);

        switch (cor)
        {
            case 1:
            preco = azul(dias);
            printf("\nPreco = %i", preco);
            break;
              
                
        }
    }

    return 0;
}
