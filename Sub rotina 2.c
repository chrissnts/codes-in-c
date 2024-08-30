#include <stdio.h>

float adicao(float a, float b)
{
    return a + b;
}

float subtracao(float a, float b)
{
    return a - b;
}

float multiplicacao(float a, float b)
{
    return a * b;
}

float divisao(float a, float b)
{
    if (b != 0)
    {
        return a / b;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int opcao;
    float num1, num2, resultado;

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

        if (opcao >= 1 && opcao <= 4)
        {
            printf("Digite dois números: ");
            scanf("%f %f", &num1, &num2);
        }

        switch (opcao)
        {

        case 1:
            resultado = adicao(num1, num2);
            printf("Resultado da adição: %.2f\n", resultado);
            break;
        case 2:
            resultado = subtracao(num1, num2);
            printf("Resultado da subtração: %.2f\n", resultado);
            break;
        case 3:
            resultado = multiplicacao(num1, num2);
            printf("Resultado da multiplicação: %.2f\n", resultado);
            break;
        case 4:
            resultado = divisao(num1, num2);
            if (resultado != -1)
            {
                printf("Resultado da divisão: %.2f\n", resultado);
            }
            else
            {
                printf("Divisão por zero!\n");
            }
            break;

        default:
            printf("Opção inválida!\n");
        }
    }

    return 0;
}
