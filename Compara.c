#include <stdio.h>

int comparacao(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else if (a < b)
    {
        return b;
    }
} 
 
int main()
{
    int a, b;
    int res;

    printf("Digite o valor a: ");
    scanf("%i", &a);
    printf("Digite o valor b: ");
    scanf("%i", &b);
    res = comparacao(a, b);
    printf("O maior valor e: %i", res);
    return 0;
}
