#include <stdio.h>
#include <stdlib.h>

#define LIN 2
#define COL2 4
#define COL 50

int main()
{
    int i, j, k;
    char aluno[LIN][COL];
    float nota[LIN][COL2], media[LIN], soma, aux;

    for (i = 0; i < LIN; i++)
    {
        soma = 0;
        printf("\nDigite o nome do aluno [%i]: ", i + 1);
        gets(aluno[i]);
        fflush(stdin);

        for (j = 0; j < COL2; j++)
        {
            do
            {
                printf("\nNota [%i]: ", j + 1);
                scanf("%f", &nota[i][j]);
                fflush(stdin);
            } while (nota[i][j] < 0 || nota[i][j] > 10);

            soma += nota[i][j];
        }

        for (j = 0; j < COL2 - 1; j++)
        {
            for (k = 0; k < COL2 - j - 1; k++)
            {
                if (nota[i][k] > nota[i][k + 1])
                {
                    aux = nota[i][k];
                    nota[i][k] = nota[i][k + 1];
                    nota[i][k + 1] = aux;
                }
            }
        }

        media[i] = soma / COL2;
        printf("\n");
    }

    printf("\n --RELATÓRIO FINAL-- \n");

    for (i = 0; i < LIN; i++)
    {
        printf("Aluno [%i]: %s\n", i + 1, aluno[i]);
        printf("\nNotas em ordem crescente: ");
        for (j = 0; j < COL2; j++)
        {
            printf("%.2f, ", nota[i][j]);
        }
        printf("\nMedia: %.2f\n", media[i]);

        if (media[i] >= 7)
        {
            printf("Situacao: Aprovado\n\n");
        }
        else
        {
            printf("Situacao: Reprovado\n\n");
        }
    }

    return 0;
}
