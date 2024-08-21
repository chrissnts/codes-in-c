#include <stdio.h>

int main()
{
    float form, raio;

    printf("\nDigite o raio de uma esfera:");
    scanf("%f", &raio);
    if( raio >= 0)
    {
        form = (4.0/3.0) * 3.14 * raio * raio * raio;
        printf("\nVolume: %f\n ", form);

    }
    else
    {
        printf("\nNúmero Inválido.");
    }

    return 0;
}
