#include <stdio.h>
#include <stdlib.h>

// Christian Alexssander Santos da Silva info24 atividade avaliativa;

float azul(int dias)
{
    float desconto = 0;
    float preco = 0;

    preco = dias * 10;

    if (dias > 15)
    {
        desconto = preco * 10 / 100;
    }
    else if (dias > 5)
    {
        desconto = preco * 5 / 100;
    }
    return preco - desconto;
}

float verde(int dias)
{
    if (dias > 10)
    {
        printf("\nImpossivel alocar mais de 10 dias.\n");
        return 0;
    }
    else
    {
        return dias * 15;
    }
}

float laranja(int dias)
{
    int diasextras;
    float preco;

    if (dias > 10)
    {
        diasextras = dias - 10;
        preco = (10 * 20) + (diasextras * 20 * 0.10);
    }
    else
    {
        preco = dias * 20;
    }
    return preco;
}

float vermelho(int dias)
{
    float preco;
    int diasextras;

    if (dias > 10)
    {
        diasextras = dias - 10;
        preco = (10 * 25) + (diasextras * 25 * 0.30);
    }
    else
    {
        preco = dias * 25;
    }
    return preco;
}

int main()
{
    int cor = 0, dias = 0, aux = 0, op = 0;
    float preco = 0, precofinal = 0;

    while (op == 0)
    {
        printf("\nEscolha uma opcao:\n");
        printf("\n1 - Azul (RS$ 10,00)\n");
        printf("\n2 - Verde (RS$ 15,00)\n");
        printf("\n3 - Laranja (RS$ 20,00)\n");
        printf("\n4 - Vermelho (RS$ 25,00)\n");
        printf("\n0 - Sair e mostrar valor final\n");
        scanf("%i", &cor);
        if (cor < 0 || cor > 4)
        {
            printf("\nOpcao invalida, tente novamente.\n");
            continue;
        }
        if (cor <= 4 && cor >= 1)
        {
            printf("\nQuantos dias deseja alocar?\n");
            scanf("%i", &dias);
            switch (cor)
            {
            case 1:
                preco = azul(dias);
                precofinal += preco;
                aux++;
                break;

            case 2:
                preco = verde(dias);
                precofinal += preco;
                if (preco != 0)
                {
                    aux++;
                }
                break;

            case 3:
                preco = laranja(dias);
                precofinal += preco;
                aux++;
                break;

            case 4:
                preco = vermelho(dias);
                precofinal += preco;
                aux++;
                break;
            }
        }
        else if (cor == 0)
        {
            if (precofinal == 0)
            {
                printf("\nNao comprou nenhuma cor. Tente novamente\n");
                continue;
            }
            else
            {
                printf("\nUsuario esta levando %i CD(S) por RS$ %.2f\n", aux, precofinal);
                printf("\nO que deseja fazer a seguir?\n");
                printf("\n1 - Continuar comprando\n");
                printf("\n2 - Zerar carrinho\n");
                printf("\n3 - Sair\n");
                scanf("%i", &op);
                if (op == 1)
                {
                    op = 0;
                }
                else if (op == 2)
                {
                    preco = 0;
                    precofinal = 0;
                    op = 0;
                    aux = 0;
                }
                else if (op == 3)
                {
                    printf("\nObrigado pela preferencia!\n");
                }
                else
                {
                    printf("\nOpcao invalida.\n");
                    cor = 0;
                }
            }
        }
    }
    return 0;
}
