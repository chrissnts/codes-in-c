#include <stdio.h>
#include <stdlib.h>

float adicao(float a, float b)
{
    float soma;

    scanf("%f %f", &a, &b);
    soma = a + b;

    return soma;
}

int main()
{

    double v1, v2;
    double soma;
    int op = 0;

    // Escolha a operação que o usuario quer
    do
    {
        printf("\nEscolha uma operacao:\n ");
        printf(" [1] Soma\n");
        printf("  [2] Subtracao\n");
        printf("  [3] Multiplicacao\n");
        printf("  [4] Divisao\n");
        scanf("%i", &op);

        // Fazer a operação
        switch (op)
        {
        case 1:

            printf("+----+----+----+----+----+\n ");
            printf("\nDigite o primeiro valor:");
            scanf("%f", &v1);
             printf("\nDigite o segundo valor:");
            scanf("%f", &v1);
            soma = adicao(v1, v2);
            printf("Adição = %f\n", soma);
            printf("+----+----+----+----+----+");

        case 2:

            printf("+----+----+----+----+----+\n ");

            printf("+----+----+----+----+----+");

        case 3:

            printf("+----+----+----+----+----+\n ");

            printf("+----+----+----+----+----+");

        case 4:

            printf("+----+----+----+----+----+\n ");

            printf("+----+----+----+----+----+");
        }

        if (op == 0)
        {
            printf("+----+----+----+----+----+\n ");

            printf("+----+----+----+----+----+");
            break;
        }
    } while (op != 0);

    return 0;
}
