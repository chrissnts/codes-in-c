#include <stdio.h>

int main()
{
    int n = 0, i, k;
    float soma = 0;

    while (n <= 0)
    {
        printf("Digite o valor de n: \n");
        scanf("%i", &n);
    }

    i = 1;
    k = 1;

    while (i <= n)
    {
        soma += (1.0 / i * k);
        k *= -1;
        i++;
    }
    printf("O somatorio eh %f", soma);

    return 0;
}
