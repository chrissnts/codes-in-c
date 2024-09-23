#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TURMAS 2
#define ALUNOS 4
#define CONCEITOS 4
#define NOME_DOSMELIANTES 50

int data_dia()
{
    int dia = 0;
    do
    {
        printf("Digite o dia (1-31): ");
        scanf("%d", &dia);

        if (dia < 1 || dia > 31)
        {
            printf("Dia invalido. Insira um valor entre 1 e 31.\n");
            continue;
        }
    } while (dia < 1 || dia > 31);

    return dia;
}

int data_mes()
{
    int mes = 0;
    do
    {
        printf("Digite o mes (1-12): ");
        scanf("%d", &mes);

        if (mes < 1 || mes > 12)
        {
            printf("Mes invalido. Insira um valor entre 1 e 12.\n");
            continue;
        }
    } while (mes < 1 || mes > 12);

    return mes;
}

int data_ano()
{
    int ano = 0;
    do
    {
        printf("Digite o ano (maior que 1900): ");
        scanf("%d", &ano);

        if (ano <= 1900)
        {
            printf("Ano invalido. Insira um valor maior que 1900.\n");
            continue;
        }
    } while (ano <= 1900);

    return ano;
}

int main()
{
 
    char alunos_turma1[ALUNOS][NOME_DOSMELIANTES];
    char conceitos_turma1[ALUNOS][CONCEITOS];
    int dias_turma1[ALUNOS], meses_turma1[ALUNOS], anos_turma1[ALUNOS];
    float coeficientes_turma1[ALUNOS];
    
    char alunos_turma2[ALUNOS][NOME_DOSMELIANTES];
    char conceitos_turma2[ALUNOS][CONCEITOS];
    int dias_turma2[ALUNOS], meses_turma2[ALUNOS], anos_turma2[ALUNOS];
    float coeficientes_turma2[ALUNOS];

    float media[TURMAS] = {0};

    float soma_total = 0;
    float maior_coeficiente = -1;
    char aluno_maior_coeficiente[NOME_DOSMELIANTES];

   
    for (int j = 0; j < ALUNOS; j++)
    {
        printf("Turma 1 - Digite o nome do aluno(a): ");
        fgets(alunos_turma1[j], NOME_DOSMELIANTES, stdin);
        alunos_turma1[j][strcspn(alunos_turma1[j], "\n")] = '\0';

        for (int k = 0; k < CONCEITOS; k++)
        {
            do
            {
                printf("Digite o conceito %d (A, B, C ou D) para o aluno(a) %s: ", k + 1, alunos_turma1[j]);
                scanf(" %c", &conceitos_turma1[j][k]);
                conceitos_turma1[j][k] = toupper(conceitos_turma1[j][k]);
            } while (conceitos_turma1[j][k] < 'A' || conceitos_turma1[j][k] > 'D');
        }

        printf("Digite a data de nascimento do aluno(a) %s:\n", alunos_turma1[j]);
        dias_turma1[j] = data_dia();
        meses_turma1[j] = data_mes();
        anos_turma1[j] = data_ano();

        do
        {
            printf("Digite o coeficiente de rendimento (0 a 10) do aluno(a) %s: ", alunos_turma1[j]);
            scanf("%f", &coeficientes_turma1[j]);
        } while (coeficientes_turma1[j] < 0 || coeficientes_turma1[j] > 10);
        getchar();  // Limpar o buffer de entrada
    }


    for (int j = 0; j < ALUNOS; j++)
    {
        printf("Turma 2 - Digite o nome do aluno(a): ");
        fgets(alunos_turma2[j], NOME_DOSMELIANTES, stdin);
        alunos_turma2[j][strcspn(alunos_turma2[j], "\n")] = '\0';

        for (int k = 0; k < CONCEITOS; k++)
        {
            do
            {
                printf("Digite o conceito %d (A, B, C ou D) para o aluno(a) %s: ", k + 1, alunos_turma2[j]);
                scanf(" %c", &conceitos_turma2[j][k]);
                conceitos_turma2[j][k] = toupper(conceitos_turma2[j][k]);
            } while (conceitos_turma2[j][k] < 'A' || conceitos_turma2[j][k] > 'D');
        }

        printf("Digite a data de nascimento do aluno(a) %s:\n", alunos_turma2[j]);
        dias_turma2[j] = data_dia();
        meses_turma2[j] = data_mes();
        anos_turma2[j] = data_ano();

        do
        {
            printf("Digite o coeficiente de rendimento (0 a 10) do aluno(a) %s: ", alunos_turma2[j]);
            scanf("%f", &coeficientes_turma2[j]);
        } while (coeficientes_turma2[j] < 0 || coeficientes_turma2[j] > 10);
        getchar();  
    }

    printf("\n---------------------------------------------\n");
    for (int j = 0; j < ALUNOS; j++)
    {
        printf("\nTurma 1 - Aluno: %s\n", alunos_turma1[j]);
        printf("Conceitos: ");
        for (int k = 0; k < CONCEITOS; k++)
        {
            printf("%c", conceitos_turma1[j][k]);
        }
        printf("\nData de Nascimento: %02d/%02d/%04d\n", dias_turma1[j], meses_turma1[j], anos_turma1[j]);
        printf("Coeficiente: %.2f\n", coeficientes_turma1[j]);
        media[0] += coeficientes_turma1[j];
        soma_total += coeficientes_turma1[j];

        if (coeficientes_turma1[j] > maior_coeficiente)
        {
            maior_coeficiente = coeficientes_turma1[j];
            strcpy(aluno_maior_coeficiente, alunos_turma1[j]);
        }
    }
    media[0] /= ALUNOS;   
    printf("\nCoeficiente medio da Turma 1: %.2f\n", media[0]);
    printf("\n---------------------------------------------\n");
    for (int j = 0; j < ALUNOS; j++)
    {
        printf("\nTurma 2 - Aluno: %s\n", alunos_turma2[j]);
        printf("Conceitos: ");
        for (int k = 0; k < CONCEITOS; k++)
        {
            printf("%c", conceitos_turma2[j][k]);
        }
        printf("\nData de Nascimento: %02d/%02d/%04d\n", dias_turma2[j], meses_turma2[j], anos_turma2[j]);
        printf("Coeficiente: %.2f\n", coeficientes_turma2[j]);
        media[1] += coeficientes_turma2[j];
        soma_total += coeficientes_turma2[j];

        if (coeficientes_turma2[j] > maior_coeficiente)
        {
            maior_coeficiente = coeficientes_turma2[j];
            strcpy(aluno_maior_coeficiente, alunos_turma2[j]);
        }
    }
    media[1] /= ALUNOS;
    printf("\nCoeficiente medio da Turma 2: %.2f\n", media[1]);
    printf("\n---------------------------------------------\n");
    printf("Coeficiente medio total: %.2f\n", soma_total / (TURMAS * ALUNOS));
    printf("Aluno(a) com o maior coeficiente: %s (%.2f)\n", aluno_maior_coeficiente, maior_coeficiente);
    printf("\n---------------------------------------------\n");

    return 0;
}
