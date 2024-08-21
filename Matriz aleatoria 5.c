#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TAM 5
#define NUM_CINCOS 10

int main()
{
    srand(time(NULL));

    int mat[TAM][TAM] = {0};
    int lin, col, cont = 0;

    for (lin = 0; lin < TAM; lin++)
    {
        for (col = 0; col < TAM; col++)
        {
            mat[lin][col] = 0;
        }
    }

    while (cont < NUM_CINCOS)
    {
        lin = rand() % TAM;
        col = rand() % TAM;
        if (mat[lin][col] == 0)
        {
            mat[lin][col] = 5;
            cont++;
        }
    }

    for (lin = 0; lin < TAM; lin++)
    {
        for (col = 0; col < TAM; col++)
        {
            printf("%i", mat[lin][col]);
        }
        printf("\n");
    }

    return 0;
}
