#include <stdio.h>

int parouimpar(int val)
{
    if (val % 2 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int val;
    int res;

    printf("Digite um valor: ");
    scanf("%i", &val);
    res = parouimpar(val);
    if (res == 1)
    {
        printf("O numero %i e par.", val);
    }
    else if (res == 0)
    {
        printf("O numero %i e impar.", val);
    }
    return 0;
}
