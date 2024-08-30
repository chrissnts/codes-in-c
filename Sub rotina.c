#include <stdio.h>

void adicao()
{
    float a, b;
    printf("Digite dois números: ");
    scanf("%f %f", &a, &b);
    printf("Resultado da adição: %.2f\n", a + b);
}

void subtracao()
{
    float a, b;
    printf("Digite dois números: ");
    scanf("%f %f", &a, &b);
    printf("Resultado da subtração: %.2f\n", a - b);
}

void multiplicacao()
{
    float a, b;
    printf("Digite dois números: ");
    scanf("%f %f", &a, &b);
    printf("Resultado da multiplicação: %.2f\n", a * b);
}

void divisao()
{
    float a, b;
    printf("Digite dois números: ");
    scanf("%f %f", &a, &b);
    if (b != 0)
    {
        printf("Resultado da divisão: %.2f\n", a / b);
    }
    else
    {
        printf("Divisão por zero\n");
    }
}

int main()
{
    int opcao;

    while (1)
    {

        printf("Escolha uma operação:\n");
        printf("1. Adição\n");
        printf("2. Subtração\n");
        printf("3. Multiplicação\n");
        printf("4. Divisão\n");
        printf("0. Sair\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao);

        if (opcao == 0)
        {
            printf("Saindo...\n");
            break;
        }

        switch (opcao)
        {
        case 1:
            adicao();
            break;
        case 2:
            subtracao();
            break;
        case 3:
            multiplicacao();
            break;
        case 4:
            divisao();
            break;
        default:
            printf("Opção inválida!\n");
        }
    }

    return 0;
}
