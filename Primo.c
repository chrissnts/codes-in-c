#include <stdio.h>

int main()
{
    int n, d, primo;

    d = 2;
    primo = 1;

    printf("me da um numero inteiro positivo ai filhote, marcha :\n ");
    scanf("%d", &n);

    if (n <= 1)
        primo = 0;

    while (primo == 1 && d <= n / 2)
    {
        if (n % d == 0)
            primo = 0;
        d ++;
    }

    if (primo == 1)
        printf("%d é primo meofi, rai dento caba \n", n);

    else
        printf(" %d nao é primo, é cumpixa\n", n);

    return 0;
}
