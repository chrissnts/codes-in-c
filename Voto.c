#include <stdio.h>

int main()
{
    int idade;

    printf("Digite sua idade: \n");
    scanf("%i", &idade);
    if (idade <= 0)
    {
        printf("\nIdade inválida");
    }
    if (idade >= 16)
    {
        printf("\nPode votar");
    }
    else
    {
        printf("\nNão pode votar");
    }

    return 0;
}
