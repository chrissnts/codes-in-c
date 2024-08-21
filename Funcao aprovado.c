#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Criando função "Aprovado";
int aprovado(float val, float val2, float val3, float val4)
{
    float media;
    media = (val + val2 + val3 + val4) / 4;
    if (media >= 4 && media <= 5.9)
    {
        return 0;
    }
    else if (media < 4)
    {
        return -1;
    }
    else if (media >= 6)
    {
        return 1;
    }
}
// Função main para colocar função em pratica;
int main()
{
    float val, val2, val3, val4;
    int media;

    printf("Digite as 4 notas de geografia: ");
    scanf("%f %f %f %f", &val, &val2, &val3, &val4);
    // Chamar função;
    media = aprovado(val, val2, val3, val4);
    // Comparação de returns;
    if (media == 1)
    {
        printf("Aprovado.\n");
    }
    else if (media == -1)
    {
        printf("Reprovado.\n");
    }
    else if (media == 0)
    {
        printf("Em recupercao.\n");
    }
    return 0;
}
