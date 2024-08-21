#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    int a = 0, b = 0, c = 0;

    printf("Digite o valor de a: ");
    scanf("%i", &a);
    printf("Digite o valor de b: ");
    scanf("%i", &b);
    if (b < a)
    {
        c = a;
        a = b;
        b = c;
        c = 0;
    }
    else
    {
        c = 0;
    }

    while (a > 0)
    {
        c = c + b;
        a--;
    }

    printf("%i", c);

    return 0;
}
