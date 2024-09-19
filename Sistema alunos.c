#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TURMAS 2
#define ALUNOS 4
#define CONCEITOS 4
#define NOME_DOSMELIANTES 50

void datadecria(int dia, int mes, int ano)
{
    do
    {
        printf("Digite o dia (1-31): ");
        scanf("%d", &dia);

    } while (dia < 1 || dia > 31);

    do
    {
        printf("Digite o mês (1-12): ");
        scanf("%d", &mes);
    } while (mes < 1 || mes > 12);

    do
    {
        printf("Digite o ano: ");
        scanf("%d", &ano);
    } while (ano < 1900);
}

int main ()
{
    char alunos[TURMAS][ALUNOS][NOME_DOSMELIANTES];
    char conceitos[TURMAS][ALUNOS][CONCEITOS];
    int dias[TURMAS][ALUNOS];
    int meses[TURMAS][ALUNOS];
    int anos[TURMAS][ALUNOS];
    float coeficientes[TURMAS][ALUNOS];
    float media[TURMAS] = {0};

    float soma_total = 0;
    float maior_coeficiente = -1;
    char aluno_maior_coeficiente[NOME_DOSMELIANTES];

    for (int i = 0; i < TURMAS; i++)
    {
        for (int j = 0; j < ALUNOS; j++)
        {
            printf("Digite o nome do aluno [%d, %d]: ", i + 1, j + 1);
            fgets(alunos[i][j], NOME_DOSMELIANTES, stdin);
            alunos[i][j][strcspn(alunos[i][j], "\n")] = '\0';

            for (int k = 0; k < CONCEITOS; k++)
            {
                do
                {
                    printf("Digite o conceito %d (A, B, C ou D) para o aluno %s: ", k + 1, alunos[i][j]);
                    scanf(" %c", &conceitos[i][j][k]);
                    conceitos[i][j][k] = toupper(conceitos[i][j][k]);
                } while (conceitos[i][j][k] < 'A' || conceitos[i][j][k] > 'D');
            }

            int dia, mes, ano;
            printf("Digite a data de nascimento do aluno %s:\n", alunos[i][j]);
            datadecria(dia, mes, ano);

            dias[i][j] = dia;
            meses[i][j] = mes;
            anos[i][j] = ano;

            do
            {
                printf("Digite o coeficiente de rendimento (0 a 10) do aluno %s: ", alunos[i][j]);
                scanf("%f", &coeficientes[i][j]);
            } while (coeficientes[i][j] < 0 || coeficientes[i][j] > 10);
            getchar();
        }
    }

    for (int i = 0; i < TURMAS; i++)
    {
        printf("\nTurma %d:\n", i + 1);
        for (int j = 0; j < ALUNOS; j++)
        {
            printf("Aluno: %s\n", alunos[i][j]);
            printf("Conceitos: ");
            for (int k = 0; k < CONCEITOS; k++)
            {
                printf("%c", conceitos[i][j][k]);
            }

            printf("\nData de Nascimento: %02d/%02d/%04d\n", dias[i][j], meses[i][j], anos[i][j]);
            printf("Coeficiente: %.2f\n", coeficientes[i][j]);

            media[i] += coeficientes[i][j];
            soma_total += coeficientes[i][j];

            if (coeficientes[i][j] > maior_coeficiente)
            {
                maior_coeficiente = coeficientes[i][j];
                strcpy(aluno_maior_coeficiente, alunos[i][j]);
            }
        }
        media[i] /= ALUNOS;
        printf("Coeficiente médio da turma %d: %.2f\n", i + 1, media[i]);
    }

    printf("Coeficiente médio total: %.2f\n", soma_total / (TURMAS * ALUNOS));
    printf("Aluno com o maior coeficiente: %s (%.2f)\n", aluno_maior_coeficiente, maior_coeficiente);

    return 0;
}
