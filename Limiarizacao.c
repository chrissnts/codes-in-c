#include <stdio.h>
#include <stdlib.h>


int limiarizacao(int **matriz, int N, int M, int T)
{
    int i, j;
    int fundo = 0;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            if (matriz[i][j] >= T)
            {
                matriz[i][j] = 255;
            }
            else
            {
                matriz[i][j] = 0;
                fundo++;
            }
        }
    }
    return fundo;
}


float calcula_porcentagem_fundo(int fundo, int total_pixels)
{
    return (fundo / (float)total_pixels) * 100;
}

int main()
{
    int N, M, T;
    int i, j;
    int fundo;
    float porcentagem_fundo;

    printf("\nDigite o valor para N:\n");
    scanf("%i", &N);

    printf("\nDigite o valor para M:\n");
    scanf("%i", &M);

    
    int total_pixels = N * M;

   
    int **matriz = (int **)calloc(N, sizeof(int *));
    for (i = 0; i < N; i++)
    {
        matriz[i] = (int *)calloc(M, sizeof(int));
    }

    printf("\nDigite o valor do limiar T:\n");
    scanf("%i", &T);


    printf("\nDigite os valores da matriz %ix%i:\n", N, M);
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            scanf("%i", &matriz[i][j]);
        }
    }


    fundo = limiarizacao(matriz, N, M, T);
    porcentagem_fundo = calcula_porcentagem_fundo(fundo, total_pixels);

  
    printf("\nMatriz limiarizada:\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            printf("%i ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n%.2f%% de fundo\n", porcentagem_fundo);

    
    for (i = 0; i < N; i++)
    {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
