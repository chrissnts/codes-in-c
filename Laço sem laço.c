#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100

int incrementa(int val, int val2)
{
    if (val <= val2)
    {
        printf("%i ", val);
        return incrementa(val + 1, val2);
    }
    return 0;
}

int main()
{
    int val, val2;

    printf("\nDigite um valor inicial:\n");
    scanf("%i", &val);
    printf("\nDigite um valor final:\n");
    scanf("\n%i", &val2);

    incrementa(val, val2);

    return 0;
}